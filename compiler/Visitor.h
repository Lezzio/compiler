#pragma once


#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"


class  Visitor : public ifccBaseVisitor {
    
	public:
		virtual antlrcpp::Any visitAxiom(ifccParser::AxiomContext *context) override;

        virtual antlrcpp::Any visitProg(ifccParser::ProgContext *context) override;

        virtual antlrcpp::Any visitBlock(ifccParser::BlockContext *context) override;

        virtual antlrcpp::Any visitStatements(ifccParser::StatementsContext *context) override;

        virtual antlrcpp::Any visitStatement(ifccParser::StatementContext *context) override;

        virtual antlrcpp::Any visitDeclaration(ifccParser::DeclarationContext *context) override;

        virtual antlrcpp::Any visitAffectation(ifccParser::AffectationContext *context) override;

        virtual antlrcpp::Any visitRetcode(ifccParser::RetcodeContext *context) override;

        virtual antlrcpp::Any visitType(ifccParser::TypeContext *context) override;

};

