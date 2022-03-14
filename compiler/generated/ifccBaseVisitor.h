
// Generated from ifcc.g4 by ANTLR 4.9.2

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

  virtual antlrcpp::Any visitAffectation5(ifccParser::Affectation5Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffectation6(ifccParser::Affectation6Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRet1(ifccParser::Ret1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRet2(ifccParser::Ret2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultvariables(ifccParser::MultvariablesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(ifccParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryexpr(ifccParser::UnaryexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCharexpr(ifccParser::CharexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelationalexpr(ifccParser::RelationalexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBracketexpr(ifccParser::BracketexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarexpr(ifccParser::VarexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultplicationexpr(ifccParser::MultplicationexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdditiveexpr(ifccParser::AdditiveexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitsexpr(ifccParser::BitsexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstexpr(ifccParser::ConstexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqualityexpr(ifccParser::EqualityexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(ifccParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }


};

