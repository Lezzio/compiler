#include "ast.h"

string ExprVar::linearize(CFG * cfg)
{
    return varName;
}

string ExprConstant::linearize(CFG * cfg)
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
    string tempVar = cfg->create_new_tempvar(INT);
    string var1 = lExpr->linearize(cfg);
    string var2 = rExpr->linearize(cfg);
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

string ExprAdd::linearize(CFG * cfg)
{
    string tempVar = cfg->create_new_tempvar(INT);
    string var1 = lExpr->linearize(cfg);
    string var2 = rExpr->linearize(cfg);
    if(op == PLUS)
    {
        cfg->addInstruction(IRInstr::add, INT, {tempVar, var1, var2});
    } else {
        cfg->addInstruction(IRInstr::sub, INT, {tempVar, var1, var2});
    }
    return tempVar;
}

string ExprBits::linearize(CFG * cfg)
{
    string tempVar = cfg->create_new_tempvar(INT);
    string var1 = lExpr->linearize(cfg);
    string var2 = rExpr->linearize(cfg);
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

string ExprRelational::linearize(CFG * cfg)
{
    string tempVar = cfg->create_new_tempvar(INT);
    string var1 = lExpr->linearize(cfg);
    string var2 = rExpr->linearize(cfg);
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

string ExprEqual::linearize(CFG * cfg)
{
    string tempVar = cfg->create_new_tempvar(INT);
    string var1 = lExpr->linearize(cfg);
    string var2 = rExpr->linearize(cfg);
    if(op == EQUAL)
    {
        cfg->addInstruction(IRInstr::cmp_eq, INT, {tempVar, var1, var2});
    } else {
        cfg->addInstruction(IRInstr::cmp_neq, INT, {tempVar, var1, var2});
    }
    return tempVar;
}

string ExprUnary::linearize(CFG * cfg)
{
    string tempVar = cfg->create_new_tempvar(INT);
    string var2 = rExpr->linearize(cfg);
    if(op == NEG)
    {
        cfg->addInstruction(IRInstr::neg, INT, {tempVar, var1, var2});
    } else {
        cfg->addInstruction(IRInstr::not, INT, {tempVar, var1, var2});
    }
    return tempVar;
}

void Prog::linearize(){
    block->linearize();
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

void Affectation::linearize(CFG * cfg){
    string var1 = lExpr->linearize(cfg);
    string var2 = rExpr->linearize(cfg);

    cfg->addInstruction(IRInstr::copy, INT, {var1, var2});
    return var1;
}