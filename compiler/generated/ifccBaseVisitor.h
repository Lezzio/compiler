
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

  virtual antlrcpp::Any visitStatements1(ifccParser::Statements1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatements2(ifccParser::Statements2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement1(ifccParser::Statement1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement2(ifccParser::Statement2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement3(ifccParser::Statement3Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(ifccParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

<<<<<<< HEAD
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
=======
  virtual antlrcpp::Any visitAffectation1(ifccParser::Affectation1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffectation2(ifccParser::Affectation2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffectation3(ifccParser::Affectation3Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffectation4(ifccParser::Affectation4Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRet1(ifccParser::Ret1Context *ctx) override {
>>>>>>> 926982dc6434e97012ef64a66a1e344978a0bde7
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRet2(ifccParser::Ret2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(ifccParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }


};

