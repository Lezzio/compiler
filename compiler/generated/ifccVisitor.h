
// Generated from ifcc.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ifccParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ifccParser.
 */
class  ifccVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ifccParser.
   */
    virtual antlrcpp::Any visitAxiom(ifccParser::AxiomContext *context) = 0;

    virtual antlrcpp::Any visitProg(ifccParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitBlock(ifccParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitStatements1(ifccParser::Statements1Context *context) = 0;

    virtual antlrcpp::Any visitStatements2(ifccParser::Statements2Context *context) = 0;

    virtual antlrcpp::Any visitStatement1(ifccParser::Statement1Context *context) = 0;

    virtual antlrcpp::Any visitStatement2(ifccParser::Statement2Context *context) = 0;

    virtual antlrcpp::Any visitStatement3(ifccParser::Statement3Context *context) = 0;

    virtual antlrcpp::Any visitDeclaration(ifccParser::DeclarationContext *context) = 0;

<<<<<<< HEAD
    virtual antlrcpp::Any visitCas1(ifccParser::Cas1Context *context) = 0;

    virtual antlrcpp::Any visitCas2(ifccParser::Cas2Context *context) = 0;

    virtual antlrcpp::Any visitCas3(ifccParser::Cas3Context *context) = 0;

    virtual antlrcpp::Any visitCas4(ifccParser::Cas4Context *context) = 0;
=======
    virtual antlrcpp::Any visitAffectation1(ifccParser::Affectation1Context *context) = 0;

    virtual antlrcpp::Any visitAffectation2(ifccParser::Affectation2Context *context) = 0;

    virtual antlrcpp::Any visitAffectation3(ifccParser::Affectation3Context *context) = 0;

    virtual antlrcpp::Any visitAffectation4(ifccParser::Affectation4Context *context) = 0;

    virtual antlrcpp::Any visitRet1(ifccParser::Ret1Context *context) = 0;
>>>>>>> 926982dc6434e97012ef64a66a1e344978a0bde7

    virtual antlrcpp::Any visitRet2(ifccParser::Ret2Context *context) = 0;

    virtual antlrcpp::Any visitType(ifccParser::TypeContext *context) = 0;


};

