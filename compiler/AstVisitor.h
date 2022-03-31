#pragma once

#include "ast/ast.h"
#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"


class AstVisitor : public ifccBaseVisitor {
    
	public:

        virtual antlrcpp::Any visitAxiom(ifccParser::AxiomContext *context) override;

        virtual antlrcpp::Any visitProg(ifccParser::ProgContext *context) override;

        virtual antlrcpp::Any visitFunction(ifccParser::FunctionContext *context) override;

        virtual antlrcpp::Any visitBlock(ifccParser::BlockContext *context) override;

        virtual antlrcpp::Any visitStatement1(ifccParser::Statement1Context *context) override;

        virtual antlrcpp::Any visitStatement2(ifccParser::Statement2Context *context) override;

        virtual antlrcpp::Any visitStatement3(ifccParser::Statement3Context *context) override;

        virtual antlrcpp::Any visitStatement4(ifccParser::Statement4Context *context) override;

        virtual antlrcpp::Any visitStatement5(ifccParser::Statement5Context *context) override;

        virtual antlrcpp::Any visitStatement6(ifccParser::Statement6Context *context) override;

        virtual antlrcpp::Any visitStatement7(ifccParser::Statement7Context *context) override;

        virtual antlrcpp::Any visitParameters(ifccParser::ParametersContext *context) override;

        virtual antlrcpp::Any visitParameter(ifccParser::ParameterContext *context) override;

        virtual antlrcpp::Any visitDeclaration(ifccParser::DeclarationContext *context) override;

        virtual antlrcpp::Any visitAffectation1(ifccParser::Affectation1Context *context) override;

        virtual antlrcpp::Any visitAffectation2(ifccParser::Affectation2Context *context) override;

        virtual antlrcpp::Any visitRet1(ifccParser::Ret1Context *context) override;

        virtual antlrcpp::Any visitUnaryexpr(ifccParser::UnaryexprContext *context) override;

        virtual antlrcpp::Any visitCharexpr(ifccParser::CharexprContext *context) override;

        virtual antlrcpp::Any visitRelationalexpr(ifccParser::RelationalexprContext *context) override;

        virtual antlrcpp::Any visitBracketexpr(ifccParser::BracketexprContext *context) override;

        virtual antlrcpp::Any visitVarexpr(ifccParser::VarexprContext *context) override;

        virtual antlrcpp::Any visitMultplicationexpr(ifccParser::MultplicationexprContext *context) override;

        virtual antlrcpp::Any visitAdditiveexpr(ifccParser::AdditiveexprContext *context) override;

        virtual antlrcpp::Any visitBitsexpr(ifccParser::BitsexprContext *context) override;

        virtual antlrcpp::Any visitConstexpr(ifccParser::ConstexprContext *context) override;

        virtual antlrcpp::Any visitEqualityexpr(ifccParser::EqualityexprContext *context) override;

        virtual antlrcpp::Any visitType(ifccParser::TypeContext *context) override;

        virtual antlrcpp::Any visitIfBlock(ifccParser::IfBlockContext *context) override;

        virtual antlrcpp::Any visitElseBlock(ifccParser::ElseBlockContext *context) override;

        virtual antlrcpp::Any visitWhileBlock(ifccParser::WhileBlockContext *context) override;

        virtual antlrcpp::Any visitForBlock(ifccParser::ForBlockContext *context) override;

        virtual antlrcpp::Any visitFunctionexpr(ifccParser::FunctionexprContext *context) override;

        protected:

        bool checkConst(Expr * expr);
        int getConstValue(Expr * expr);


};