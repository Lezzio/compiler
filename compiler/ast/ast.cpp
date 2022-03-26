#include "ast.h"

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
    string tempVar = cfg->create_new_tempvar(INT);
    string constant = "$"+ to_string(value);
    cfg->addInstruction(IRInstr::ldconst, INT, {tempVar, constant});
    return tempVar;
}

string ExprMult::linearize(CFG * cfg)
{
    string var1 = lExpr->linearize(cfg);
    string var2 = rExpr->linearize(cfg);
    string tempVar = cfg->create_new_tempvar(INT);
    if(op == MULT)
    {
        cfg->addInstruction(IRInstr::mul, INT, {tempVar, var1, var2});
    } else if(op == DIV)
    {
        cfg->addInstruction(IRInstr::div, INT, {tempVar, var1, var2});
    } else 
    {
        cfg->addInstruction(IRInstr::mod, INT, {tempVar, var1, var2});
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
    string tempVar = cfg->create_new_tempvar(INT);
    if(op == PLUS)
    {
        cfg->addInstruction(IRInstr::add, INT, {tempVar, var1, var2});
    } else {
        cfg->addInstruction(IRInstr::sub, INT, {tempVar, var1, var2});
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
    string tempVar = cfg->create_new_tempvar(INT);
    if(op == OR)
    {
        cfg->addInstruction(IRInstr::orbit, INT, {tempVar, var1, var2});
    } else if(op == AND)
    {
        cfg->addInstruction(IRInstr::andbit, INT, {tempVar, var1, var2});
    } else 
    {
        cfg->addInstruction(IRInstr::xorbit, INT, {tempVar, var1, var2});
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
    string tempVar = cfg->create_new_tempvar(INT);
    if(op == GR)
    {
        cfg->addInstruction(IRInstr::cmp_lt, INT, {tempVar, var1, var2});
    } else if(op == GRE)
    {
        cfg->addInstruction(IRInstr::cmp_le, INT, {tempVar, var1, var2});
    } else if(op == LE)
    {
        cfg->addInstruction(IRInstr::cmp_gt, INT, {tempVar, var1, var2});
    } else {
         cfg->addInstruction(IRInstr::cmp_ge, INT, {tempVar, var1, var2});
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
    string tempVar = cfg->create_new_tempvar(INT);
    if(op == EQUAL)
    {
        cfg->addInstruction(IRInstr::cmp_eq, INT, {tempVar, var1, var2});
    } else {
        cfg->addInstruction(IRInstr::cmp_neq, INT, {tempVar, var1, var2});
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
    string tempVar = cfg->create_new_tempvar(INT);
    if(op == NEG)
    {
        cfg->addInstruction(IRInstr::neg, INT, {tempVar, var2});
    } else {
        cfg->addInstruction(IRInstr::note, INT, {tempVar, var2});
    }
    return tempVar;
}

ExprUnary::~ExprUnary(){
    delete (rExpr);
}

CFG* Prog::linearize(){
    CFG *cfg = new CFG(new SymbolTable(), "main");
    BasicBlock *bb = new BasicBlock(cfg, "main");
    cfg->add_bb(bb);
    block->linearize(cfg);
    return cfg;
}

Prog::~Prog(){
    delete (block);
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
    string var1 = lExpr->linearize(cfg);
    string var2 = rExpr->linearize(cfg);

    cfg->addInstruction(IRInstr::copy, INT, {var1, var2});
    return var1;
}

Affectation::~Affectation(){
    delete (lExpr);
    delete (rExpr);
}

string DecAffectation::linearize(CFG * cfg){
    string var1 = declaration->linearize(cfg);
    string var2 = rExpr->linearize(cfg);

    cfg->addInstruction(IRInstr::copy, INT, {var1, var2});
    return var1;
}

DecAffectation::~DecAffectation(){
    delete (declaration);
    delete (rExpr);
}

string Declaration::linearize(CFG * cfg){
    cfg->add_to_symbol_table(name, INT, DECLARED);
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
    cfg->addInstruction(IRInstr::ret, INT, {var1});
    return var1;
}

Return::~Return(){
    delete (expr);
}