#include "ast.h"

string ExprVar::linearize(CFG *cfg) {
    return varName;
}

string ExprConst::linearize(CFG *cfg) {
    string tempVar = cfg->create_new_tempvar(INT);
    string constant = "$" + to_string(value);
    cfg->addInstruction(IRInstr::ldconst, INT, {tempVar, constant});
    return tempVar;
}

string ExprChar::linearize(CFG *cfg) {
    string tempVar = cfg->create_new_tempvar(CHAR);
    string constant = "$" + to_string(value);
    cfg->addInstruction(IRInstr::ldconst, CHAR, {tempVar, constant});
    return tempVar;
}

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

ExprMult::~ExprMult() {
    delete (lExpr);
    delete (rExpr);
}

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

ExprAdd::~ExprAdd() {
    delete (lExpr);
    delete (rExpr);
}

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

ExprBits::~ExprBits() {
    delete (lExpr);
    delete (rExpr);
}

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

ExprRelational::~ExprRelational() {
    delete (lExpr);
    delete (rExpr);
}

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

ExprEqual::~ExprEqual() {
    delete (lExpr);
    delete (rExpr);
}

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

ExprUnary::~ExprUnary() {
    delete (rExpr);
}


void Block::addStatement(Statement *statement) {
    statements.push_back(statement);
}

void Block::linearize(CFG *cfg) {
    //CFG entering scope
    cfg->enteringScope();
    for (Statement *s: statements) {
        s->linearize(cfg);
    }
    //CFG exiting scope
    cfg->exitingScope();
}

Block::~Block() {
    for (Statement *s: statements) {
        delete (s);
    }
    statements.clear();
}

string Affectation::linearize(CFG *cfg) {
    string var1 = lExpr->linearize(cfg);
    string var2 = rExpr->linearize(cfg);

    TypeSymbol typeTmp = cfg->get_var_type(var1, cfg->getCurrentScope());

    cfg->addInstruction(IRInstr::copy, typeTmp, {var1, var2});
    return var1;
}

Affectation::~Affectation() {
    delete (lExpr);
    delete (rExpr);
}

string DecAffectation::linearize(CFG *cfg) {
    cout << " DEF AFFECTATION L " << endl;
    string var1 = declaration->linearize(cfg);
    cout << " POINT #1 " << endl;
    string var2 = rExpr->linearize(cfg);
    cout << " POINT #2 " << endl;

    TypeSymbol typeTmp = cfg->get_var_type(var1, cfg->getCurrentScope());
    cout << " POINT #3 " << endl;

    cfg->addInstruction(IRInstr::copy, typeTmp, {var1, var2});
    cout << " END DEF AFFECTATION L " << endl;
    return var1;
}

DecAffectation::~DecAffectation() {
    delete (declaration);
    delete (rExpr);
}

string Declaration::linearize(CFG *cfg) {
    cfg->add_to_symbol_table(name, type, DECLARED);
    return name;
}

void Declarations::addDeclaration(Declaration *declaration) {
    declarations.push_back(declaration);
}

string Declarations::linearize(CFG *cfg) {
    for (Declaration *d: declarations) {
        d->linearize(cfg);
    }
    return "";
}

Declarations::~Declarations() {
    for (Declaration *d: declarations) {
        delete (d);
    }
    declarations.clear();
}

string Return::linearize(CFG *cfg) {
    string var1 = expr->linearize(cfg);

    TypeSymbol typeTmp = cfg->get_var_type(var1, cfg->getCurrentScope());
    cfg->setReturnSymbol("!retvalue", cfg->getCurrentScope()); //TODO Return symbol

    cfg->addInstruction(IRInstr::ret, typeTmp, {"!retvalue", var1});
    return var1;
}

Return::~Return() {
    delete (expr);
}

InstructionIF::~InstructionIF() {
    delete (test);
    delete (trueCodeBlock);
    delete (falseCodeBlock);
}

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
    cout << "BB scope is " << cfg->current_bb->scope << endl;

    if (falseCodeBlock != nullptr) {
        cfg->add_bb(elseBB);
        cfg->current_bb->exit_true = endIfBB;
        falseCodeBlock->linearize(cfg);
    }

    cfg->add_bb(endIfBB);

    return "";
}

InstructionWhile::~InstructionWhile() {
    delete (test);
    delete (block);
}

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

InstructionFor::~InstructionFor() {
    delete (block);
    delete (init);
    delete (test);
    delete (update);
}

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
        cfg->add_bb(initForBB);
        //TODO CFG entering & exiting scope
        init->linearize(cfg);
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

string InstructionExpr::linearize(CFG *cfg) {
    string val = expr->linearize(cfg);
    return val;
}

string Parameter::linearize(CFG *cfg) {
    cfg->add_to_symbol_table(name, type, PARAMETER);
    return name;
}

void Parameters::addParameter(Parameter *parameter) {
    parameters.push_back(parameter);
}

string Parameters::linearize(CFG *cfg) {
    int position = 1;
    for (Parameter *p: parameters) {
        string name = p->linearize(cfg);
        cfg->setParametersPosition(name, position);
        position++;
    }
    return "";
}

Parameters::~Parameters() {
    for (Parameter *p: parameters) {
        delete (p);
    }
    parameters.clear();
}

Function::~Function() {
    delete (parameters);
    delete (block);
}

string Function::linearize(CFG *cfg) {
    cfg->setCurrentFunction(name);
    cfg->add_to_symbol_table(name, type, FUNCTION);

    auto *bb = new BasicBlock(cfg, cfg->new_BB_name());
    cfg->add_bb(bb);

    auto *returnBlock = new BasicBlock(cfg, cfg->new_BB_name());
    returnBlock->add_IRInstr(IRInstr::finret, INT, {"!retvalue"});
    cfg->return_bb = returnBlock;

    if (parameters != nullptr) {
        cout << "About to L parameters" << endl;
        parameters->linearize(cfg);
    }

    cout << "About to L block" << endl;
    block->linearize(cfg);
    return "";
}

ExprFunction::~ExprFunction() {
    for (Expr *e : parameters) {
        delete (e);
    }
    parameters.clear();
}

void ExprFunction::addParameter(Expr *expr) {
    parameters.push_back(expr);
}

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

    TypeSymbol typeFunc = cfg->get_var_type(varName, cfg->getCurrentScope());
    string tempVar = cfg->create_new_tempvar(typeFunc);

    cfg->addInstruction(IRInstr::call, typeFunc, {tempVar, varName});
    return tempVar;
}

vector<CFG *> Prog::linearize() {
    auto *symbolTable = new SymbolTable();

    symbolTable->defFunction("getchar@PLT", CHAR);
    symbolTable->defFunction("putchar@PLT", VOID);

    for (Function *f: functions) {
        CFG *cfg = new CFG(symbolTable, f->name);
        cout << "going to L function :" << f->name << endl;
        f->linearize(cfg);
        cout << "end L of function :" << f->name << endl;
        cfgs.push_back(cfg);
    }

    //symbolTable->print_dictionary();

    return cfgs;
}

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

void Prog::addFunction(Function *function) {
    functions.push_back(function);
}

string InstructionBreak::linearize(CFG * cfg){
    if(cfg->breakBBname.compare("")==0){
        cerr<<"ERROR: a Break statement can only be used in a loop" << endl;
        exit(1);
    }

    cfg->addInstruction(IRInstr::jmp, VOID, {cfg->breakBBname});
    return "";
}

string InstructionContinue::linearize(CFG * cfg){
    if(cfg->continueBBname.compare("")==0){
        cerr<<"ERROR: a Continue statement can only be used in a loop" << endl;
        exit(1);
    }

    cfg->addInstruction(IRInstr::jmp, VOID, {cfg->continueBBname});
    return "";
}