
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

    virtual antlrcpp::Any visitStatements(ifccParser::StatementsContext *context) = 0;

    virtual antlrcpp::Any visitStatement(ifccParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(ifccParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitCas1(ifccParser::Cas1Context *context) = 0;

    virtual antlrcpp::Any visitCas2(ifccParser::Cas2Context *context) = 0;

    virtual antlrcpp::Any visitCas3(ifccParser::Cas3Context *context) = 0;

    virtual antlrcpp::Any visitCas4(ifccParser::Cas4Context *context) = 0;

    virtual antlrcpp::Any visitRetcode(ifccParser::RetcodeContext *context) = 0;

    virtual antlrcpp::Any visitType(ifccParser::TypeContext *context) = 0;


};

