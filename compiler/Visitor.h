#pragma once

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include "ErrorManager.h"
#include "symbolTable/SymbolTable.h"

#include <string>
#include <queue> 
typedef struct Register {
    std::string name;
    bool used;
} Register;


class  Visitor : public ifccBaseVisitor {
    
	public:
        Visitor(SymbolTable * symbolTable);
        ~Visitor();

        virtual antlrcpp::Any visitAxiom(ifccParser::AxiomContext *context) override;

        virtual antlrcpp::Any visitProg(ifccParser::ProgContext *context) override;

        virtual antlrcpp::Any visitBlock(ifccParser::BlockContext *context) override;

        virtual antlrcpp::Any visitStatements1(ifccParser::Statements1Context *context) override;

        virtual antlrcpp::Any visitStatements2(ifccParser::Statements2Context *context) override;

        virtual antlrcpp::Any visitStatement1(ifccParser::Statement1Context *context) override;

        virtual antlrcpp::Any visitStatement2(ifccParser::Statement2Context *context) override;

        virtual antlrcpp::Any visitStatement3(ifccParser::Statement3Context *context) override;

        virtual antlrcpp::Any visitDeclaration(ifccParser::DeclarationContext *context) override;

        virtual antlrcpp::Any visitAffectation1(ifccParser::Affectation1Context *context) override;

        virtual antlrcpp::Any visitAffectation2(ifccParser::Affectation2Context *context) override;

        virtual antlrcpp::Any visitAffectation3(ifccParser::Affectation3Context *context) override;

        virtual antlrcpp::Any visitAffectation4(ifccParser::Affectation4Context *context) override;

        virtual antlrcpp::Any visitAffectation5(ifccParser::Affectation5Context *context) override;

        virtual antlrcpp::Any visitAffectation6(ifccParser::Affectation6Context *context) override;

        virtual antlrcpp::Any visitRet1(ifccParser::Ret1Context *context) override;

        virtual antlrcpp::Any visitRet2(ifccParser::Ret2Context *context) override;

        virtual antlrcpp::Any visitMultvariables(ifccParser::MultvariablesContext *context) override;

        virtual antlrcpp::Any visitVariable(ifccParser::VariableContext *context) override;

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



    private:
        Register edx;
        Register eax;
        SymbolTable *symbolTable;
        ErrorManager *errorManager;

};