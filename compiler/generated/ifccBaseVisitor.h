
// Generated from ifcc.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ifccVisitor.h"


/**
 * This class provides an empty implementation of ifccVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ifccBaseVisitor : public ifccVisitor {
public:

  virtual antlrcpp::Any visitAxiom(ifccParser::AxiomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(ifccParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatements(ifccParser::StatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(ifccParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(ifccParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCas1(ifccParser::Cas1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCas2(ifccParser::Cas2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCas3(ifccParser::Cas3Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCas4(ifccParser::Cas4Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRetcode(ifccParser::RetcodeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(ifccParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }


};

