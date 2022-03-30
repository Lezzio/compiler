#include "ast.h"

string Expr::getVarName(){
    return varName;
}

string ExprVar::linearize(CFG * cfg)
{
    return varName;
}

string ExprConst::linearize(CFG * cfg)
{
    string tempVar = cfg->create_new_tempvar(INT);
    string constant = "$"+ to_string(value);
    cfg->addInstruction(IRInstr::ldconst, INT, {tempVar, constant});
    return tempVar;
}

string ExprChar::linearize(CFG * cfg)
{
    string tempVar = cfg->create_new_tempvar(CHAR);
    string constant = "$"+ to_string(value);
    cfg->addInstruction(IRInstr::ldconst, CHAR, {tempVar, constant});
    return tempVar;
}

string ExprMult::linearize(CFG * cfg)
{
    string var1 = lExpr->linearize(cfg);
    string var2 = rExpr->linearize(cfg);

    TypeSymbol typeTmp;
    TypeSymbol t1 = cfg->get_var_type(var1);
    TypeSymbol t2 = cfg->get_var_type(var2);
    if(t1 == INT || t2 == INT){
        typeTmp = INT;
    } else {
        typeTmp = CHAR;
    }

    string tempVar = cfg->create_new_tempvar(typeTmp);
    if(op == MULT)
    {
        cfg->addInstruction(IRInstr::mul, typeTmp, {tempVar, var1, var2});
    } else if(op == DIV)
    {
        cfg->addInstruction(IRInstr::div, typeTmp, {tempVar, var1, var2});
    } else 
    {
        cfg->addInstruction(IRInstr::mod, typeTmp, {tempVar, var1, var2});
    }
    return tempVar;
}

ExprMult::~ExprMult(){
    delete (lExpr);
    delete (rExpr);
}

string ExprAdd::linearize(CFG * cfg)
{
    string var1 = lExpr->linearize(cfg);
    string var2 = rExpr->linearize(cfg);

    TypeSymbol typeTmp;
    TypeSymbol t1 = cfg->get_var_type(var1);
    TypeSymbol t2 = cfg->get_var_type(var2);
    if(t1 == INT || t2 == INT){
        typeTmp = INT;
    } else {
        typeTmp = CHAR;
    }

    string tempVar = cfg->create_new_tempvar(typeTmp);
    if(op == PLUS)
    {
        cfg->addInstruction(IRInstr::add, typeTmp, {tempVar, var1, var2});
    } else {
        cfg->addInstruction(IRInstr::sub, typeTmp, {tempVar, var1, var2});
    }
    return tempVar;
}

ExprAdd::~ExprAdd(){
    delete (lExpr);
    delete (rExpr);
}

string ExprBits::linearize(CFG * cfg)
{
    string var1 = lExpr->linearize(cfg);
    string var2 = rExpr->linearize(cfg);

    TypeSymbol typeTmp;
    TypeSymbol t1 = cfg->get_var_type(var1);
    TypeSymbol t2 = cfg->get_var_type(var2);
    if(t1 == INT || t2 == INT){
        typeTmp = INT;
    } else {
        typeTmp = CHAR;
    }

    string tempVar = cfg->create_new_tempvar(typeTmp);
    if(op == OR)
    {
        cfg->addInstruction(IRInstr::orbit, typeTmp, {tempVar, var1, var2});
    } else if(op == AND)
    {
        cfg->addInstruction(IRInstr::andbit, typeTmp, {tempVar, var1, var2});
    } else 
    {
        cfg->addInstruction(IRInstr::xorbit, typeTmp, {tempVar, var1, var2});
    }
    return tempVar;
}

ExprBits::~ExprBits(){
    delete (lExpr);
    delete (rExpr);
}

string ExprRelational::linearize(CFG * cfg)
{
    string var1 = lExpr->linearize(cfg);
    string var2 = rExpr->linearize(cfg);

    TypeSymbol typeTmp;
    TypeSymbol t1 = cfg->get_var_type(var1);
    TypeSymbol t2 = cfg->get_var_type(var2);
    if(t1 == INT || t2 == INT){
        typeTmp = INT;
    } else {
        typeTmp = CHAR;
    }

    string tempVar = cfg->create_new_tempvar(typeTmp);
    if(op == GR)
    {
        cfg->addInstruction(IRInstr::cmp_gt, typeTmp, {tempVar, var1, var2});
    } else if(op == GRE)
    {
        cfg->addInstruction(IRInstr::cmp_ge, typeTmp, {tempVar, var1, var2});
    } else if(op == LE)
    {
        cfg->addInstruction(IRInstr::cmp_lt, typeTmp, {tempVar, var1, var2});
    } else {
         cfg->addInstruction(IRInstr::cmp_le, typeTmp, {tempVar, var1, var2});
    }
    return tempVar;
}

ExprRelational::~ExprRelational(){
    delete (lExpr);
    delete (rExpr);
}

string ExprEqual::linearize(CFG * cfg)
{
    string var1 = lExpr->linearize(cfg);
    string var2 = rExpr->linearize(cfg);

    TypeSymbol typeTmp;
    TypeSymbol t1 = cfg->get_var_type(var1);
    TypeSymbol t2 = cfg->get_var_type(var2);
    if(t1 == INT || t2 == INT){
        typeTmp = INT;
    } else {
        typeTmp = CHAR;
    }

    string tempVar = cfg->create_new_tempvar(typeTmp);
    if(op == EQUAL)
    {
        cfg->addInstruction(IRInstr::cmp_eq, typeTmp, {tempVar, var1, var2});
    } else {
        cfg->addInstruction(IRInstr::cmp_neq, typeTmp, {tempVar, var1, var2});
    }
    return tempVar;
}

ExprEqual::~ExprEqual(){
    delete (lExpr);
    delete (rExpr);
}

string ExprUnary::linearize(CFG * cfg)
{
    string var2 = rExpr->linearize(cfg);

    TypeSymbol typeTmp;
    TypeSymbol t2 = cfg->get_var_type(var2);
    typeTmp = t2;

    string tempVar = cfg->create_new_tempvar(typeTmp);
    if(op == NEG)
    {
        cfg->addInstruction(IRInstr::neg, typeTmp, {tempVar, var2});
    } else {
        cfg->addInstruction(IRInstr::note, typeTmp, {tempVar, var2});
    }
    return tempVar;
}

ExprUnary::~ExprUnary(){
    delete (rExpr);
}



void Block::addStatement(Statement * statement)
{
    statements.push_back(statement);
}

void Block::linearize(CFG * cfg){
    for(Statement *s: statements){
        s->linearize(cfg);
    }
}

Block::~Block(){
    for(Statement *s: statements){
        delete (s);
    }
    statements.clear();
}

string Affectation::linearize(CFG * cfg){

    string right = rExpr->linearize(cfg);
    string leftName = lExpr->getVarName();

    if(true){
        string left = lExpr->linearize(cfg);
        //1. ldconst
        TypeSymbol typeTmp = cfg->get_var_type(left);
        int indexLeft = cfg->get_var_index(left);
        string tmpRbp = cfg->create_new_tempvar(typeTmp);
        
        cfg->addInstruction(IRInstr::ldconst, typeTmp, {tmpRbp, "$"+to_string(indexLeft)});
        //2. add
        cfg->addInstruction(IRInstr::add_lValue, typeTmp, {tmpRbp, "%rbp", tmpRbp});
        //3. wmem
        cfg->addInstruction(IRInstr::wmem, typeTmp, {tmpRbp, right});
        return left;
    }
    //Else case with lValue = Variable
    TypeSymbol typeTmp = cfg->get_var_type(leftName);
    //cout << "typeTmp : " << typeTmp << endl;
    cfg->addInstruction(IRInstr::copy, typeTmp, {leftName, right});
    return leftName;

}

Affectation::~Affectation(){
    delete (lExpr);
    delete (rExpr);
}

string DecAffectation::linearize(CFG * cfg){
    string var1 = declaration->linearize(cfg);
    string var2 = rExpr->linearize(cfg);

    TypeSymbol typeTmp = cfg->get_var_type(var1);

    cfg->addInstruction(IRInstr::copy, typeTmp, {var1, var2});
    return var1;
}

DecAffectation::~DecAffectation(){
    delete (declaration);
    delete (rExpr);
}

string Declaration::linearize(CFG * cfg){
    cfg->add_to_symbol_table(name, type, DECLARED);
    return name;
}

void Declarations::addDeclaration(Declaration *declaration){
    declarations.push_back(declaration);
}

string Declarations::linearize(CFG * cfg){
    for(Declaration *d: declarations){
        d->linearize(cfg);
    }
    return "";
}

Declarations::~Declarations(){
    for(Declaration *d: declarations){
        delete (d);
    }
    declarations.clear();
}

string Return::linearize(CFG * cfg){
    string var1 = expr->linearize(cfg);

    TypeSymbol typeTmp = cfg->get_var_type(var1);
    cfg->setReturnSymbol("!retvalue");

    cfg->addInstruction(IRInstr::ret, typeTmp, {"!retvalue", var1});
    return var1;
}

Return::~Return(){
    delete (expr);
}

InstructionIF::~InstructionIF(){
    delete (test);
    delete (trueCodeBlock);
    delete (falseCodeBlock);
}

string InstructionIF::linearize(CFG * cfg){
    string testVar = test->linearize(cfg);
    BasicBlock * testBB = cfg->current_bb;
    testBB->test_var_name = testVar;

    BasicBlock * thenBB = new BasicBlock(cfg, cfg->new_BB_name());

    BasicBlock * endIfBB = new BasicBlock(cfg,cfg->new_BB_name());
    endIfBB->exit_true = testBB->exit_true;
    endIfBB->exit_false = thenBB->exit_false;

    BasicBlock *elseBB = endIfBB;
    if(falseCodeBlock!=nullptr){
        elseBB = new BasicBlock(cfg, cfg->new_BB_name());
    }
    testBB->exit_true = thenBB;
    testBB->exit_false = elseBB;

    cfg->add_bb(thenBB);
    cfg->current_bb->exit_true = endIfBB;
    trueCodeBlock->linearize(cfg);

    if(falseCodeBlock!=nullptr){
        cfg->add_bb(elseBB);
        cfg->current_bb->exit_true = endIfBB;
        falseCodeBlock->linearize(cfg);
    }

    cfg->add_bb(endIfBB);
    return "";
}

InstructionWhile::~InstructionWhile()
{
    delete (test);
    delete (block);
}

string InstructionWhile::linearize(CFG * cfg)
{
    BasicBlock * beforeWhileBB = cfg->current_bb;
    BasicBlock * bodyBB = new BasicBlock(cfg, cfg->new_BB_name());
    BasicBlock * testBB = new BasicBlock(cfg, cfg->new_BB_name());
    BasicBlock * afterWhileBB = new BasicBlock(cfg, cfg->new_BB_name());

    beforeWhileBB->exit_true = testBB;
    cfg->add_bb(testBB);
    string testVar = test->linearize(cfg);
    testBB->test_var_name = testVar;

    testBB->exit_true = bodyBB;
    testBB->exit_false = afterWhileBB;

    cfg->add_bb(bodyBB);
    block->linearize(cfg);
    bodyBB->exit_true = testBB;
    bodyBB->exit_false = nullptr;

    cfg->add_bb(afterWhileBB);

    return "";
}

InstructionFor::~InstructionFor()
{
    delete (block);
    delete (init);
    delete (test);
    delete (update);
}

string InstructionFor::linearize(CFG * cfg)
{
    BasicBlock * beforeForBB = cfg->current_bb;

    BasicBlock * initForBB = new BasicBlock(cfg, cfg->new_BB_name());
    BasicBlock * testBB = new BasicBlock(cfg, cfg->new_BB_name());
    BasicBlock * updateBB = new BasicBlock(cfg, cfg->new_BB_name());
    BasicBlock * forBB = new BasicBlock(cfg, cfg->new_BB_name());
    BasicBlock * endforBB = new BasicBlock(cfg, cfg->new_BB_name());

    if(init != nullptr){
        beforeForBB->exit_true = initForBB;
        cfg->add_bb(initForBB);
        init->linearize(cfg);
        initForBB->exit_true = testBB;
    } else {
        beforeForBB->exit_true = testBB;
    }

    cfg->add_bb(testBB);
    string testVar = test->linearize(cfg);
    testBB->test_var_name = testVar;

    testBB->exit_true = forBB;
    testBB->exit_false = endforBB;

    cfg->add_bb(forBB);
    block->linearize(cfg);
    if(update != nullptr) {
         forBB->exit_true = updateBB;
         cfg->add_bb(updateBB);
         update->linearize(cfg);
         updateBB->exit_true = testBB;
    } else {
        forBB->exit_true = testBB;
    }
    forBB->exit_false = nullptr;

    cfg->add_bb(endforBB);

    return "";
}

string Parameter::linearize(CFG * cfg){
    cfg->add_to_symbol_table(name, type, PARAMETER);
    return name;
}

void Parameters::addParameter(Parameter *parameter){
    parameters.push_back(parameter);
}

string Parameters::linearize(CFG * cfg){
    int position = 1;
    for(Parameter *p: parameters){
        string name = p->linearize(cfg);
        cfg->setParametersPosition(name, position);
        position ++;
    }
    return "";
}

Parameters::~Parameters(){
    for(Parameter *p: parameters){
        delete (p);
    }
    parameters.clear();
}

Function::~Function(){
    delete (parameters);
    delete (block);
}

string Function::linearize(CFG * cfg){
    cfg->setCurrentFunction(name);
    cfg->add_to_symbol_table(name, type, FUNCTION);

    BasicBlock *bb = new BasicBlock(cfg, cfg->new_BB_name());
    cfg->add_bb(bb);

    BasicBlock *returnBlock = new BasicBlock(cfg, cfg->new_BB_name());
    returnBlock->add_IRInstr(IRInstr::finret, INT, {"!retvalue"});
    cfg->return_bb = returnBlock;

    if(parameters != nullptr){
        parameters->linearize(cfg);
    }

    block->linearize(cfg);

    return "";
}

vector<CFG*> Prog::linearize(){
    SymbolTable *symbolTable = new SymbolTable();

    for(Function * f: functions){
        CFG *cfg = new CFG(symbolTable, f->name);
        f->linearize(cfg);
        cfgs.push_back(cfg);
    }

    //symbolTable->print_dictionary();

    return cfgs;
}

Prog::~Prog(){
    for(Function *f : functions){
        delete(f);
    }
    functions.clear();
    for(CFG *cfg : cfgs){
        delete(cfg);
    }
    cfgs.clear();
}

void Prog::addFunction(Function * function){
    functions.push_back(function);
}