#include "ast/ast.h"
#include "AstVisitor.h"
#include <iostream>
using namespace std;

antlrcpp::Any AstVisitor::visitAxiom(ifccParser::AxiomContext *ctx)
{
    return visit(ctx->prog());
}

antlrcpp::Any AstVisitor::visitProg(ifccParser::ProgContext *context)
{
    Prog *prog = new Prog((Block *)visit(context->block()));

    return prog;
}

antlrcpp::Any AstVisitor::visitBlock(ifccParser::BlockContext *context)
{
    Block *block = new Block();
    for(const auto s : context->statement())
    {
        Statement *statement = (Statement *) visit(s);
        block->addStatement(statement);
    }
    return block;
}

antlrcpp::Any AstVisitor::visitStatement1(ifccParser::Statement1Context *context)
{
    return (Statement *) visit(context->declaration());
}

antlrcpp::Any AstVisitor::visitStatement2(ifccParser::Statement2Context *context)
{
    return (Statement *)visit(context->affectation());
}

antlrcpp::Any AstVisitor::visitStatement3(ifccParser::Statement3Context *context)
{
    return (Statement *)visit(context->retcode());
}

antlrcpp::Any AstVisitor::visitDeclaration(ifccParser::DeclarationContext *context)
{
    Declarations * declarations = new Declarations();
    string res = (string) visit(context->type()).as<string>();
    
    TypeSymbol t = INT;
    if(res=="char"){
        t = CHAR;
    }

    for(const auto var : context->VAR())
    {
        declarations->addDeclaration(new Declaration(var->getText(), t));
    }
    return (Statement *)declarations;
}

antlrcpp::Any AstVisitor::visitRet1(ifccParser::Ret1Context *context)
{
    ExprConst *exprConst = new ExprConst("", stoi(context->CONST()->getText()));
    Return *ret = new Return(exprConst);
    return (Statement *)ret;   
}

antlrcpp::Any AstVisitor::visitRet2(ifccParser::Ret2Context *context)
{
    ExprVar *exprVar = new ExprVar(context->VAR()->getText());
    Return *ret = new Return(exprVar);
    return (Statement *)ret;   
}

antlrcpp::Any AstVisitor::visitAffectation1(ifccParser::Affectation1Context *context)
{
    string res = (string) visit(context->type()).as<string>();
    
    TypeSymbol t = INT;
    if(res=="char"){
        t = CHAR;
    }

    Declaration *declaration = new Declaration(context->VAR()->getText(), t);
    Expr *expr = (Expr *)visit(context->expression());
    DecAffectation * decAffectation = new DecAffectation(declaration, expr);
    return (Statement *)decAffectation;
}

antlrcpp::Any AstVisitor::visitAffectation2(ifccParser::Affectation2Context *context)
{
    ExprVar *exprVar = new ExprVar(context->VAR()->getText());
    Expr *expr = (Expr *)visit(context->expression());
    Affectation* affectation = new Affectation(exprVar, expr);
    return (Statement *)affectation;
}

antlrcpp::Any AstVisitor::visitUnaryexpr(ifccParser::UnaryexprContext *context)
{
    Expr *expr = (Expr *) visit(context->expression());
    Operator op;
    if(context->op->getText() == "-"){
       op = NEG;
    } else {
       op = NOT;
    }
    ExprUnary *unary = new ExprUnary("",expr, op);
    return (Expr *)unary;
}

antlrcpp::Any AstVisitor::visitCharexpr(ifccParser::CharexprContext *context)
{
    string variable = context->CHARACTER()->getText();
    char character = variable.substr(1,2)[0];
    int value = (int) character;
    
    ExprChar *expr = new ExprChar("",value);
    return (Expr *)expr;
}

antlrcpp::Any AstVisitor::visitRelationalexpr(ifccParser::RelationalexprContext *context)
{
    Expr *lExpr = (Expr *) visit(context->expression(0));
    Expr *rExpr = (Expr *) visit(context->expression(1));
    Operator op;
    if (context->op->getText() == ">"){
        op = GR;

    } else if(context->op->getText() == ">="){
        op = GRE;
    
    }else if(context->op->getText() == "<"){
        op = LE;
    
    }else {     //if(context->op->getText() == "<=")
        op = LEE;
    }
    ExprRelational *rel = new ExprRelational("",lExpr, rExpr, op);
    return (Expr *)rel;
}

antlrcpp::Any AstVisitor::visitBracketexpr(ifccParser::BracketexprContext *context)
{
    return (Expr *)visit(context->expression());
}

antlrcpp::Any AstVisitor::visitVarexpr(ifccParser::VarexprContext *context)
{
    ExprVar * exprVar = new ExprVar(context->VAR()->getText());
    return (Expr *) exprVar;
}

antlrcpp::Any AstVisitor::visitMultplicationexpr(ifccParser::MultplicationexprContext *context)
{
    Expr *lExpr = (Expr *) visit(context->expression(0));
    Expr *rExpr = (Expr *) visit(context->expression(1));
    Operator op;
    if (context->op->getText() == "*"){
        op = MULT;

    } else if(context->op->getText() == ">="){
        op = DIV;
    
    }else {
        op = MOD;
    }
    ExprMult *mul = new ExprMult("",lExpr, rExpr, op);
    return (Expr *)mul;
}

antlrcpp::Any AstVisitor::visitAdditiveexpr(ifccParser::AdditiveexprContext *context)
{
    Expr *lExpr = (Expr *) visit(context->expression(0));
    Expr *rExpr = (Expr *) visit(context->expression(1));
    Operator op;
    if (context->op->getText() == "+"){
        op = PLUS;

    } else {
        op = MINUS;
    }
    ExprAdd *add = new ExprAdd("",lExpr, rExpr, op);
    return (Expr *)add;
}

antlrcpp::Any AstVisitor::visitBitsexpr(ifccParser::BitsexprContext *context){
    Expr *lExpr = (Expr *) visit(context->expression(0));
    Expr *rExpr = (Expr *) visit(context->expression(1));
    Operator op;
    if (context->op->getText() == "|"){
        op = OR;

    } else if(context->op->getText() == "&"){
        op = AND;
    
    }else {
        op = XOR;
    }
    ExprBits *bits = new ExprBits("",lExpr, rExpr, op);
    return (Expr *)bits;
}

antlrcpp::Any AstVisitor::visitConstexpr(ifccParser::ConstexprContext *context)
{
    int value = stoi(context->CONST()->getText()); 
    ExprConst* expr = new ExprConst("", value);

    return (Expr *) expr;
}

antlrcpp::Any AstVisitor::visitEqualityexpr(ifccParser::EqualityexprContext *context)
{
    Expr *lExpr = (Expr *) visit(context->expression(0));
    Expr *rExpr = (Expr *) visit(context->expression(1));
    Operator op;
    if (context->op->getText() == "=="){
        op = EQUAL;

    } else {
        op = NEQUAL;
    }
    ExprEqual *equal = new ExprEqual("",lExpr, rExpr, op);
    return (Expr *)equal;
}

antlrcpp::Any AstVisitor::visitType(ifccParser::TypeContext *context)
{
    string type = context->getText();
    return type;
}