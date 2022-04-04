#include "ast.h"

/**
 * @brief Method which linearize an expression which is a variable
 * 
 * @param cfg
 * @return string : the name of the variable expression
 */
string ExprVar::linearize(CFG *cfg) {
    return varName;
}

/**
 * @brief Method which linearize an expression which is a constant
 * 
 * @param cfg 
 * @return string : the name of the temporary variable just created
 */
string ExprConst::linearize(CFG *cfg) {
    string tempVar = cfg->create_new_tempvar(INT);
    string constant = "$" + to_string(value);
    cfg->addInstruction(IRInstr::ldconst, INT, {tempVar, constant});
    return tempVar;
}

/**
 * @brief Method which linearize une character expression (instance : char 'a')
 * 
 * @param cfg 
 * @return string : the name of the temporary variable just created
 */
string ExprChar::linearize(CFG *cfg) {
    string tempVar = cfg->create_new_tempvar(CHAR);
    string constant = "$" + to_string(value);
    cfg->addInstruction(IRInstr::ldconst, CHAR, {tempVar, constant});
    return tempVar;
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string ExprArray::linearize(CFG *cfg) {
    cfg->add_to_symbol_table(varName, type, DECLARED,size);
    return varName;
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string ExprLArray::linearize(CFG *cfg) {
    string var1 = this->position->linearize(cfg);
    int offset = -cfg->get_var_index(varName);
    string tmpVar = cfg->create_new_tempvar(INT64_T);
    
    TypeSymbol t1 = cfg->get_var_type(var1, cfg->getCurrentScope());
    if(t1 != INT64_T){
        cfg->addInstruction(IRInstr::cast, INT64_T, {var1});
    }

    cfg->addInstruction(IRInstr::ldconst, INT64_T, {tmpVar, "$"+to_string(offset)});
    cfg->addInstruction(IRInstr::add, INT64_T, {tmpVar, "%rbp", tmpVar});
    cfg->addInstruction(IRInstr::add, INT64_T, {tmpVar, var1, tmpVar});
    return tmpVar;
}

/**
 * @brief Destroy the Expr L Array:: Expr L Array object
 * 
 */
ExprLArray::~ExprLArray(){
    delete position;
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string ExprRArray::linearize(CFG *cfg) {
    string var1 = this->position->linearize(cfg);
    int offset = -cfg->get_var_index(varName);
    string tmpVar = cfg->create_new_tempvar(INT64_T);

    TypeSymbol t1 = cfg->get_var_type(var1, cfg->getCurrentScope());
    if(t1 != INT64_T){
        cfg->addInstruction(IRInstr::cast, INT64_T, {var1});
    }
    cfg->addInstruction(IRInstr::ldconst, INT64_T, {tmpVar, "$"+to_string(offset)});
    cfg->addInstruction(IRInstr::add, INT64_T, {tmpVar, "%rbp", tmpVar});
    cfg->addInstruction(IRInstr::add, INT64_T, {tmpVar, var1, tmpVar});

    string tmpVar2 = cfg->create_new_tempvar(INT64_T);
    cfg->addInstruction(IRInstr::rmem, INT64_T, {tmpVar2, tmpVar});
    return tmpVar2;
}

/**
 * @brief Destroy the Expr R Array:: Expr R Array object
 * 
 */
ExprRArray::~ExprRArray(){
    delete position;
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string ExprMult::linearize(CFG *cfg) {
    string var1 = lExpr->linearize(cfg);
    string var2 = rExpr->linearize(cfg);

    TypeSymbol typeTmp;
    TypeSymbol t1 = cfg->get_var_type(var1, cfg->getCurrentScope());
    TypeSymbol t2 = cfg->get_var_type(var2, cfg->getCurrentScope());
    if (t1 == INT || t2 == INT) {
        typeTmp = INT;
    } else {
        typeTmp = CHAR;
    }

    string tempVar = cfg->create_new_tempvar(typeTmp);
    if (op == MULT) {
        cfg->addInstruction(IRInstr::mul, typeTmp, {tempVar, var1, var2});
    } else if (op == DIV) {
        cfg->addInstruction(IRInstr::div, typeTmp, {tempVar, var1, var2});
    } else {
        cfg->addInstruction(IRInstr::mod, typeTmp, {tempVar, var1, var2});
    }
    return tempVar;
}

/**
 * @brief Destroy the Expr Mult:: Expr Mult object
 * 
 */
ExprMult::~ExprMult() {
    delete (lExpr);
    delete (rExpr);
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string ExprAdd::linearize(CFG *cfg) {
    string var1 = lExpr->linearize(cfg);
    string var2 = rExpr->linearize(cfg);

    TypeSymbol typeTmp;
    TypeSymbol t1 = cfg->get_var_type(var1, cfg->getCurrentScope());
    TypeSymbol t2 = cfg->get_var_type(var2, cfg->getCurrentScope());
    if (t1 == INT || t2 == INT) {
        typeTmp = INT;
    } else {
        typeTmp = CHAR;
    }

    string tempVar = cfg->create_new_tempvar(typeTmp);
    if (op == PLUS) {
        cfg->addInstruction(IRInstr::add, typeTmp, {tempVar, var1, var2});
    } else {
        cfg->addInstruction(IRInstr::sub, typeTmp, {tempVar, var1, var2});
    }
    return tempVar;
}

/**
 * @brief Destroy the Expr Add:: Expr Add object
 * 
 */
ExprAdd::~ExprAdd() {
    delete (lExpr);
    delete (rExpr);
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string ExprBits::linearize(CFG *cfg) {
    string var1 = lExpr->linearize(cfg);
    string var2 = rExpr->linearize(cfg);

    TypeSymbol typeTmp;
    TypeSymbol t1 = cfg->get_var_type(var1, cfg->getCurrentScope());
    TypeSymbol t2 = cfg->get_var_type(var2, cfg->getCurrentScope());
    if (t1 == INT || t2 == INT) {
        typeTmp = INT;
    } else {
        typeTmp = CHAR;
    }

    string tempVar = cfg->create_new_tempvar(typeTmp);
    if (op == OR) {
        cfg->addInstruction(IRInstr::orbit, typeTmp, {tempVar, var1, var2});
    } else if (op == AND) {
        cfg->addInstruction(IRInstr::andbit, typeTmp, {tempVar, var1, var2});
    } else {
        cfg->addInstruction(IRInstr::xorbit, typeTmp, {tempVar, var1, var2});
    }
    return tempVar;
}

/**
 * @brief Destroy the Expr Bits:: Expr Bits object
 * 
 */
ExprBits::~ExprBits() {
    delete (lExpr);
    delete (rExpr);
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string ExprRelational::linearize(CFG *cfg) {
    string var1 = lExpr->linearize(cfg);
    string var2 = rExpr->linearize(cfg);

    TypeSymbol typeTmp;
    TypeSymbol t1 = cfg->get_var_type(var1, cfg->getCurrentScope());
    TypeSymbol t2 = cfg->get_var_type(var2, cfg->getCurrentScope());
    if (t1 == INT || t2 == INT) {
        typeTmp = INT;
    } else {
        typeTmp = CHAR;
    }

    string tempVar = cfg->create_new_tempvar(typeTmp);
    if (op == GR) {
        cfg->addInstruction(IRInstr::cmp_gt, typeTmp, {tempVar, var1, var2});
    } else if (op == GRE) {
        cfg->addInstruction(IRInstr::cmp_ge, typeTmp, {tempVar, var1, var2});
    } else if (op == LE) {
        cfg->addInstruction(IRInstr::cmp_lt, typeTmp, {tempVar, var1, var2});
    } else {
        cfg->addInstruction(IRInstr::cmp_le, typeTmp, {tempVar, var1, var2});
    }
    return tempVar;
}

/**
 * @brief Destroy the Expr Relational:: Expr Relational object
 * 
 */
ExprRelational::~ExprRelational() {
    delete (lExpr);
    delete (rExpr);
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string ExprEqual::linearize(CFG *cfg) {
    string var1 = lExpr->linearize(cfg);
    string var2 = rExpr->linearize(cfg);

    TypeSymbol typeTmp;
    TypeSymbol t1 = cfg->get_var_type(var1, cfg->getCurrentScope());
    TypeSymbol t2 = cfg->get_var_type(var2, cfg->getCurrentScope());
    if (t1 == INT || t2 == INT) {
        typeTmp = INT;
    } else {
        typeTmp = CHAR;
    }

    string tempVar = cfg->create_new_tempvar(typeTmp);
    if (op == EQUAL) {
        cfg->addInstruction(IRInstr::cmp_eq, typeTmp, {tempVar, var1, var2});
    } else {
        cfg->addInstruction(IRInstr::cmp_neq, typeTmp, {tempVar, var1, var2});
    }
    return tempVar;
}

/**
 * @brief Destroy the Expr Equal:: Expr Equal object
 * 
 */
ExprEqual::~ExprEqual() {
    delete (lExpr);
    delete (rExpr);
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string ExprUnary::linearize(CFG *cfg) {
    string var2 = rExpr->linearize(cfg);

    TypeSymbol typeTmp;
    TypeSymbol t2 = cfg->get_var_type(var2, cfg->getCurrentScope());
    typeTmp = t2;

    string tempVar = cfg->create_new_tempvar(typeTmp);
    if (op == NEG) {
        cfg->addInstruction(IRInstr::neg, typeTmp, {tempVar, var2});
    } else {
        cfg->addInstruction(IRInstr::not_, typeTmp, {tempVar, var2});
    }
    return tempVar;
}

/**
 * @brief Destroy the Expr Unary:: Expr Unary object
 * 
 */
ExprUnary::~ExprUnary() {
    delete (rExpr);
}

/**
 * @brief 
 * 
 * @param statement 
 */
void Block::addStatement(Statement *statement) {
    statements.push_back(statement);
}

/**
 * @brief 
 * 
 * @param cfg 
 */
void Block::linearize(CFG *cfg) {
    //CFG entering scope
    cfg->enteringScope();
    for (Statement *s: statements) {
        s->linearize(cfg);
    }
    //CFG exiting scope
    cfg->exitingScope();
}

/**
 * @brief Destroy the Block:: Block object
 * 
 */
Block::~Block() {
    for (Statement *s: statements) {
        delete (s);
    }
    statements.clear();
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string Affectation::linearize(CFG *cfg) {
    string var1 = lExpr->linearize(cfg);
    string var2 = rExpr->linearize(cfg);

    TypeSymbol typeTmp = cfg->get_var_type(var1, cfg->getCurrentScope());

    cfg->addInstruction(IRInstr::copy, typeTmp, {var1, var2});
    return var1;
}

/**
 * @brief Destroy the Affectation:: Affectation object
 * 
 */
Affectation::~Affectation() {
    delete (lExpr);
    delete (rExpr);
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string ExprAffectation::linearize(CFG *cfg) {
    string var1 = lExpr->linearize(cfg);
    string var2 = rExpr->linearize(cfg);

    TypeSymbol typeTmp = cfg->get_var_type(var1, cfg->getCurrentScope());

    cfg->addInstruction(IRInstr::wmem, INT64_T, {var2, var1}); //TODO:Verify
    return var1;
}

/**
 * @brief Destroy the Expr Affectation:: Expr Affectation object
 * 
 */
ExprAffectation::~ExprAffectation() {
    delete (lExpr);
    delete (rExpr);
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string ArrayAffectation::linearize(CFG *cfg){
    arrayD->linearize(cfg);

    for(auto s : array_values){
        s->linearize(cfg);
    }

    return "";
}

/**
 * @brief 
 * 
 * @param statement 
 */
void ArrayAffectation::addStatement(ExprAffectation * statement){
    array_values.push_back(statement);
}

/**
 * @brief 
 * 
 * @param exprArray 
 */
void ArrayAffectation::setArray(ExprArray *exprArray){
    arrayD  = exprArray;
}

/**
 * @brief Destroy the Array Affectation:: Array Affectation object
 * 
 */
ArrayAffectation::~ArrayAffectation(){
    for(auto s : array_values){
        delete s;
    }
    array_values.clear();
    delete arrayD;
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string ExprDeclaration::linearize(CFG *cfg) {
    string var = expr->linearize(cfg);
    return var;
}

/**
 * @brief Destroy the Expr Declaration:: Expr Declaration object
 * 
 */
ExprDeclaration::~ExprDeclaration(){
    delete expr;
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string DecAffectation::linearize(CFG *cfg) {
    //cout << " DEF AFFECTATION L " << endl; debug
    string var1 = declaration->linearize(cfg);
    //cout << " POINT #1 " << endl; debug
    string var2 = rExpr->linearize(cfg);
    //cout << " POINT #2 " << endl; debug

    TypeSymbol typeTmp = cfg->get_var_type(var1, cfg->getCurrentScope());
    //cout << " POINT #3 " << endl; debug

    cfg->addInstruction(IRInstr::copy, typeTmp, {var1, var2});
    //cout << " END DEF AFFECTATION L " << endl; debug
    return var1;
}

/**
 * @brief Destroy the Dec Affectation:: Dec Affectation object
 * 
 */
DecAffectation::~DecAffectation() {
    delete (declaration);
    delete (rExpr);
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string Declaration::linearize(CFG *cfg) {
    cfg->add_to_symbol_table(name, type, DECLARED);
    return name;
}

/**
 * @brief 
 * 
 * @param declaration 
 */
void Declarations::addDeclaration(Declaration *declaration) {
    declarations.push_back(declaration);
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string Declarations::linearize(CFG *cfg) {
    for (Declaration *d: declarations) {
        d->linearize(cfg);
    }
    return "";
}

/**
 * @brief Destroy the Declarations:: Declarations object
 * 
 */
Declarations::~Declarations() {
    for (Declaration *d: declarations) {
        delete (d);
    }
    declarations.clear();
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string Return::linearize(CFG *cfg) {
    string var1 = expr->linearize(cfg);

    TypeSymbol typeTmp = cfg->get_var_type(var1, cfg->getCurrentScope());
    cfg->setReturnSymbol("!retvalue", cfg->getCurrentScope()); //TODO Return symbol

    cfg->addInstruction(IRInstr::ret, typeTmp, {"!retvalue", var1});
    return var1;
}

/**
 * @brief Destroy the Return:: Return object
 * 
 */
Return::~Return() {
    delete (expr);
}

/**
 * @brief Destroy the Instruction I F:: Instruction I F object
 * 
 */
InstructionIF::~InstructionIF() {
    delete (test);
    delete (trueCodeBlock);
    delete (falseCodeBlock);
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string InstructionIF::linearize(CFG *cfg) {

    string testVar = test->linearize(cfg);
    BasicBlock *testBB = cfg->current_bb;
    testBB->test_var_name = testVar;

    auto *thenBB = new BasicBlock(cfg, cfg->new_BB_name());

    auto *endIfBB = new BasicBlock(cfg, cfg->new_BB_name());
    endIfBB->exit_true = testBB->exit_true;
    endIfBB->exit_false = testBB->exit_false;

    BasicBlock *elseBB = endIfBB;
    if (falseCodeBlock != nullptr) {
        elseBB = new BasicBlock(cfg, cfg->new_BB_name());
        testBB->exit_false = elseBB;
    } else {
        testBB->exit_false = endIfBB;
    }
    testBB->exit_true = thenBB;

    cfg->add_bb(thenBB);
    cfg->current_bb->exit_true = endIfBB;

    trueCodeBlock->linearize(cfg);
    //cout << "BB scope is " << cfg->current_bb->scope << endl; debug

    if (falseCodeBlock != nullptr) {
        cfg->add_bb(elseBB);
        cfg->current_bb->exit_true = endIfBB;
        falseCodeBlock->linearize(cfg);
    }

    cfg->add_bb(endIfBB);

    return "";
}

/**
 * @brief Destroy the Instruction While:: Instruction While object
 * 
 */
InstructionWhile::~InstructionWhile() {
    delete (test);
    delete (block);
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string InstructionWhile::linearize(CFG *cfg) {

    BasicBlock *beforeWhileBB = cfg->current_bb;
    auto *bodyBB = new BasicBlock(cfg, cfg->new_BB_name());
    auto *testBB = new BasicBlock(cfg, cfg->new_BB_name());
    auto *afterWhileBB = new BasicBlock(cfg, cfg->new_BB_name());

    afterWhileBB->exit_true = beforeWhileBB->exit_true;
    afterWhileBB->exit_false = beforeWhileBB->exit_false;

    cfg->breakBBname = afterWhileBB->label;
    cfg->continueBBname = testBB->label;

    beforeWhileBB->exit_true = testBB;
    cfg->add_bb(testBB);
    testBB->exit_true = bodyBB;
    testBB->exit_false = afterWhileBB;
    string testVar = test->linearize(cfg);
    testBB->test_var_name = testVar;

    cfg->add_bb(bodyBB);
    bodyBB->exit_true = testBB;
    bodyBB->exit_false = nullptr;
    block->linearize(cfg); //1

    cfg->add_bb(afterWhileBB);
    cfg->breakBBname = "";
    cfg->continueBBname = "";

    return "";
}

/**
 * @brief Destroy the Instruction For:: Instruction For object
 * 
 */
InstructionFor::~InstructionFor() {
    delete (block);
    delete (init);
    delete (test);
    delete (update);
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string InstructionFor::linearize(CFG * cfg)
{
    BasicBlock * beforeForBB = cfg->current_bb;

    auto * initForBB = new BasicBlock(cfg, cfg->new_BB_name()); //getCurrentScope
    auto * testBB = new BasicBlock(cfg, cfg->new_BB_name());
    auto * updateBB = new BasicBlock(cfg, cfg->new_BB_name());
    auto * forBB = new BasicBlock(cfg, cfg->new_BB_name());
    auto * endforBB = new BasicBlock(cfg, cfg->new_BB_name());

    cfg->breakBBname = endforBB->label;
    if(update != nullptr) {
        cfg->continueBBname = updateBB->label;
    } else {
        cfg->continueBBname = testBB->label;
    }

    endforBB->exit_true = beforeForBB->exit_true;
    endforBB->exit_false = beforeForBB->exit_false;

    if(init != nullptr) {
        beforeForBB->exit_true = initForBB;
        //TODO Unit testing of the for loop init scope
        cfg->enteringScope();
        cfg->add_bb(initForBB);
        init->linearize(cfg);
        cfg->exitingScope();
        initForBB->exit_true = testBB;
    } else {
        beforeForBB->exit_true = testBB;
    }

    cfg->add_bb(testBB);
    testBB->exit_true = forBB;
    testBB->exit_false = endforBB;
    string testVar = test->linearize(cfg);
    testBB->test_var_name = testVar;

    cfg->add_bb(forBB);
    if(update != nullptr) {
        forBB->exit_true = updateBB;
        updateBB->exit_true = testBB;
    } else {
        forBB->exit_true = testBB;
    }
    forBB->exit_false = nullptr;
    block->linearize(cfg);
    if(update != nullptr) {
        cfg->add_bb(updateBB);
        update->linearize(cfg);
    }

    cfg->add_bb(endforBB);
    cfg->breakBBname = "";
    cfg->continueBBname = "";

    return "";
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string InstructionExpr::linearize(CFG *cfg) {
    string val = expr->linearize(cfg);
    return val;
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string Parameter::linearize(CFG *cfg) {
    cfg->add_to_symbol_table(name, type, PARAMETER);
    return name;
}

/**
 * @brief 
 * 
 * @param parameter 
 */
void Parameters::addParameter(Parameter *parameter) {
    parameters.push_back(parameter);
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string Parameters::linearize(CFG *cfg) {
    int position = 1;
    for (Parameter *p: parameters) {
        string name = p->linearize(cfg);
        cfg->setParametersPosition(name, position, cfg->getCurrentScope());
        position++;
    }
    return "";
}

/**
 * @brief Destroy the Parameters:: Parameters object
 * 
 */
Parameters::~Parameters() {
    for (Parameter *p: parameters) {
        delete (p);
    }
    parameters.clear();
}

/**
 * @brief Destroy the Function:: Function object
 * 
 */
Function::~Function() {
    delete (parameters);
    delete (block);
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string Function::linearize(CFG *cfg) {
    cfg->setCurrentFunction(name);
    cfg->add_to_symbol_table(name, type, FUNCTION);

    auto *bb = new BasicBlock(cfg, cfg->new_BB_name());
    cfg->add_bb(bb);

    auto *returnBlock = new BasicBlock(cfg, cfg->new_BB_name());
    returnBlock->add_IRInstr(IRInstr::finret, INT, {"!retvalue"});
    cfg->return_bb = returnBlock;

    if (parameters != nullptr) {
        //cout << "About to L parameters" << endl; debug
        parameters->linearize(cfg);
    }

    //cout << "About to L block" << endl; debug
    block->linearize(cfg);
    return "";
}

/**
 * @brief Destroy the Expr Function:: Expr Function object
 * 
 */
ExprFunction::~ExprFunction() {
    for (Expr *e : parameters) {
        delete (e);
    }
    parameters.clear();
}

/**
 * @brief 
 * 
 * @param expr 
 */
void ExprFunction::addParameter(Expr *expr) {
    parameters.push_back(expr);
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string ExprFunction::linearize(CFG *cfg) {
    int position = 1;
    for (Expr *e : parameters) {
        string var = e->linearize(cfg);
        TypeSymbol typeTmp = cfg->get_var_type(var, cfg->getCurrentScope());
        cfg->addInstruction(IRInstr::copy, typeTmp, {"param_reg", var, to_string(position)});
        position++;
    }

    if (!cfg->doesSymbolExist(varName, cfg->getCurrentScope())) {
        varName = varName + "@PLT";
    }

    cout << "ici1" << endl;
    TypeSymbol typeFunc = cfg->get_var_type(varName, cfg->getCurrentScope());
        cout << "ici2" << endl;
    string tempVar = cfg->create_new_tempvar(typeFunc);

    cfg->addInstruction(IRInstr::call, typeFunc, {tempVar, varName});
    return tempVar;
}

/**
 * @brief 
 * 
 * @return vector<CFG *> 
 */
vector<CFG *> Prog::linearize() {
    auto *symbolTable = new SymbolTable();

    symbolTable->defFunction("getchar@PLT", CHAR);
    symbolTable->defFunction("putchar@PLT", VOID);

    for (Function *f: functions) {
        CFG *cfg = new CFG(symbolTable, f->name);
        //cout << "going to L function :" << f->name << endl; debug
        f->linearize(cfg);
        //cout << "end L of function :" << f->name << endl; debug
        cfgs.push_back(cfg);
    }

    //symbolTable->print_dictionary();

    return cfgs;
}

/**
 * @brief Destroy the Prog:: Prog object
 * 
 */
Prog::~Prog() {
    for (Function *f : functions) {
        delete (f);
    }
    functions.clear();
    delete (cfgs[0]->getSymbolTable());
    for (CFG *cfg : cfgs) {
        delete (cfg);
    }
    cfgs.clear();
}

/**
 * @brief 
 * 
 * @param function 
 */
void Prog::addFunction(Function *function) {
    functions.push_back(function);
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string InstructionBreak::linearize(CFG * cfg){
    if(cfg->breakBBname.compare("")==0){
        cerr<<"ERROR: a Break statement can only be used in a loop" << endl;
        exit(1);
    }

    cfg->addInstruction(IRInstr::jmp, VOID, {cfg->breakBBname});
    return "";
}

/**
 * @brief 
 * 
 * @param cfg 
 * @return string 
 */
string InstructionContinue::linearize(CFG * cfg){
    if(cfg->continueBBname.compare("")==0){
        cerr<<"ERROR: a Continue statement can only be used in a loop" << endl;
        exit(1);
    }

    cfg->addInstruction(IRInstr::jmp, VOID, {cfg->continueBBname});
    return "";
}