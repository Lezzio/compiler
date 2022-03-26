#include "ast/ast.h"
#include "Visitor.h"
#include <iostream>
using namespace std;

antlrcpp::Any AstVisitor::visitAxiom(ifccParser::AxiomContext *ctx)
{
    return visit(ctx->prog());
}

antlrcpp::Any AstVisitor::visitProg(ifccParser::ProgContext *context)
{
    Prog *prog = new Prog((Block *)visit(ctx->block()));

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
    //TODO:
    return (Statement *)visit(context->affectation());
}

antlrcpp::Any AstVisitor::visitStatement3(ifccParser::Statement3Context *context)
{
    //TODO:
    return (Statement *)visit(context->retcode());
}

antlrcpp::Any AstVisitor::visitDeclaration(ifccParser::DeclarationContext *context)
{
    Declarations * declarations = new Declarations();
    for(const auto var : constext->VAR())
    {
        declarations->addDeclaration(new Declaration(var->getText()));
    }
    return (Statement *)declarations;
}

antlrcpp::Any AstVisitor::visitRet1(ifccParser::Ret1Context *context)
{
    
}

antlrcpp::Any AstVisitor::visitRet2(ifccParser::Ret2Context *context)
{
    
}


