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
    return (Statement *) visit(context->statement());
}

antlrcpp::Any AstVisitor::visitStatement2(ifccParser::Statement2Context *context)
{
    return (Statement *)visit(context->affectation());
}

antlrcpp::Any AstVisitor::visitStatement3(ifccParser::Statement3Context *context)
{
    //TODO:
    return visitChildren(context);
}

antlrcpp::Any AstVisitor::visitDeclaration(ifccParser::DeclarationContext *context)
{
    //TODO:
    return visitChildren(context);
}

