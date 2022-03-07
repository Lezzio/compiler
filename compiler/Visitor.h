#pragma once


#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"

#include <string>
typedef struct Register {
    std::string name;
    bool used;
} Register;

class  Visitor : public ifccBaseVisitor {
    
	public:

        Visitor();
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

        virtual antlrcpp::Any visitRet1(ifccParser::Ret1Context *context) override;

        virtual antlrcpp::Any visitRet2(ifccParser::Ret2Context *context) override;

        virtual antlrcpp::Any visitType(ifccParser::TypeContext *context) override;

    private:
        Register edx;
        Register eax;
        

};