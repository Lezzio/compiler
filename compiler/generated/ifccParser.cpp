
// Generated from ifcc.g4 by ANTLR 4.9.2


#include "ifccVisitor.h"

#include "ifccParser.h"


using namespace antlrcpp;
using namespace antlr4;

ifccParser::ifccParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ifccParser::~ifccParser() {
  delete _interpreter;
}

std::string ifccParser::getGrammarFileName() const {
  return "ifcc.g4";
}

const std::vector<std::string>& ifccParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ifccParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- AxiomContext ------------------------------------------------------------------

ifccParser::AxiomContext::AxiomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::ProgContext* ifccParser::AxiomContext::prog() {
  return getRuleContext<ifccParser::ProgContext>(0);
}


size_t ifccParser::AxiomContext::getRuleIndex() const {
  return ifccParser::RuleAxiom;
}


antlrcpp::Any ifccParser::AxiomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAxiom(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::AxiomContext* ifccParser::axiom() {
  AxiomContext *_localctx = _tracker.createInstance<AxiomContext>(_ctx, getState());
  enterRule(_localctx, 0, ifccParser::RuleAxiom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(22);
    prog();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgContext ------------------------------------------------------------------

ifccParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::ProgContext::INT() {
  return getToken(ifccParser::INT, 0);
}

ifccParser::BlockContext* ifccParser::ProgContext::block() {
  return getRuleContext<ifccParser::BlockContext>(0);
}


size_t ifccParser::ProgContext::getRuleIndex() const {
  return ifccParser::RuleProg;
}


antlrcpp::Any ifccParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ProgContext* ifccParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 2, ifccParser::RuleProg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(24);
    match(ifccParser::INT);
    setState(25);
    match(ifccParser::T__0);
    setState(26);
    match(ifccParser::T__1);
    setState(27);
    match(ifccParser::T__2);
    setState(28);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

ifccParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::StatementsContext* ifccParser::BlockContext::statements() {
  return getRuleContext<ifccParser::StatementsContext>(0);
}


size_t ifccParser::BlockContext::getRuleIndex() const {
  return ifccParser::RuleBlock;
}


antlrcpp::Any ifccParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::BlockContext* ifccParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 4, ifccParser::RuleBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(30);
    match(ifccParser::T__3);
    setState(31);
    statements();
    setState(32);
    match(ifccParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

ifccParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ifccParser::StatementsContext::getRuleIndex() const {
  return ifccParser::RuleStatements;
}

void ifccParser::StatementsContext::copyFrom(StatementsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Statements2Context ------------------------------------------------------------------

ifccParser::StatementContext* ifccParser::Statements2Context::statement() {
  return getRuleContext<ifccParser::StatementContext>(0);
}

ifccParser::StatementsContext* ifccParser::Statements2Context::statements() {
  return getRuleContext<ifccParser::StatementsContext>(0);
}

ifccParser::Statements2Context::Statements2Context(StatementsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::Statements2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitStatements2(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Statements1Context ------------------------------------------------------------------

ifccParser::StatementContext* ifccParser::Statements1Context::statement() {
  return getRuleContext<ifccParser::StatementContext>(0);
}

ifccParser::Statements1Context::Statements1Context(StatementsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::Statements1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitStatements1(this);
  else
    return visitor->visitChildren(this);
}
ifccParser::StatementsContext* ifccParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 6, ifccParser::RuleStatements);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(38);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementsContext *>(_tracker.createInstance<ifccParser::Statements1Context>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(34);
      statement();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementsContext *>(_tracker.createInstance<ifccParser::Statements2Context>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(35);
      statement();
      setState(36);
      statements();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

ifccParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ifccParser::StatementContext::getRuleIndex() const {
  return ifccParser::RuleStatement;
}

void ifccParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Statement3Context ------------------------------------------------------------------

ifccParser::RetcodeContext* ifccParser::Statement3Context::retcode() {
  return getRuleContext<ifccParser::RetcodeContext>(0);
}

ifccParser::Statement3Context::Statement3Context(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::Statement3Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitStatement3(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Statement1Context ------------------------------------------------------------------

ifccParser::DeclarationContext* ifccParser::Statement1Context::declaration() {
  return getRuleContext<ifccParser::DeclarationContext>(0);
}

ifccParser::Statement1Context::Statement1Context(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::Statement1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitStatement1(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Statement2Context ------------------------------------------------------------------

ifccParser::AffectationContext* ifccParser::Statement2Context::affectation() {
  return getRuleContext<ifccParser::AffectationContext>(0);
}

ifccParser::Statement2Context::Statement2Context(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::Statement2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitStatement2(this);
  else
    return visitor->visitChildren(this);
}
ifccParser::StatementContext* ifccParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 8, ifccParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(49);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ifccParser::Statement1Context>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(40);
      declaration();
      setState(41);
      match(ifccParser::T__5);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ifccParser::Statement2Context>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(43);
      affectation();
      setState(44);
      match(ifccParser::T__5);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ifccParser::Statement3Context>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(46);
      retcode();
      setState(47);
      match(ifccParser::T__5);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

ifccParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::TypeContext* ifccParser::DeclarationContext::type() {
  return getRuleContext<ifccParser::TypeContext>(0);
}

ifccParser::VariablesContext* ifccParser::DeclarationContext::variables() {
  return getRuleContext<ifccParser::VariablesContext>(0);
}


size_t ifccParser::DeclarationContext::getRuleIndex() const {
  return ifccParser::RuleDeclaration;
}


antlrcpp::Any ifccParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::DeclarationContext* ifccParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 10, ifccParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(51);
    type();
    setState(52);
    variables();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AffectationContext ------------------------------------------------------------------

ifccParser::AffectationContext::AffectationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ifccParser::AffectationContext::getRuleIndex() const {
  return ifccParser::RuleAffectation;
}

void ifccParser::AffectationContext::copyFrom(AffectationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Affectation3Context ------------------------------------------------------------------

std::vector<tree::TerminalNode *> ifccParser::Affectation3Context::VAR() {
  return getTokens(ifccParser::VAR);
}

tree::TerminalNode* ifccParser::Affectation3Context::VAR(size_t i) {
  return getToken(ifccParser::VAR, i);
}

ifccParser::Affectation3Context::Affectation3Context(AffectationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::Affectation3Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAffectation3(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Affectation2Context ------------------------------------------------------------------

ifccParser::TypeContext* ifccParser::Affectation2Context::type() {
  return getRuleContext<ifccParser::TypeContext>(0);
}

tree::TerminalNode* ifccParser::Affectation2Context::VAR() {
  return getToken(ifccParser::VAR, 0);
}

tree::TerminalNode* ifccParser::Affectation2Context::CONST() {
  return getToken(ifccParser::CONST, 0);
}

ifccParser::Affectation2Context::Affectation2Context(AffectationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::Affectation2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAffectation2(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Affectation1Context ------------------------------------------------------------------

ifccParser::TypeContext* ifccParser::Affectation1Context::type() {
  return getRuleContext<ifccParser::TypeContext>(0);
}

std::vector<tree::TerminalNode *> ifccParser::Affectation1Context::VAR() {
  return getTokens(ifccParser::VAR);
}

tree::TerminalNode* ifccParser::Affectation1Context::VAR(size_t i) {
  return getToken(ifccParser::VAR, i);
}

ifccParser::Affectation1Context::Affectation1Context(AffectationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::Affectation1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAffectation1(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Affectation6Context ------------------------------------------------------------------

tree::TerminalNode* ifccParser::Affectation6Context::VAR() {
  return getToken(ifccParser::VAR, 0);
}

ifccParser::ExpressionContext* ifccParser::Affectation6Context::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
}

ifccParser::Affectation6Context::Affectation6Context(AffectationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::Affectation6Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAffectation6(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Affectation5Context ------------------------------------------------------------------

ifccParser::TypeContext* ifccParser::Affectation5Context::type() {
  return getRuleContext<ifccParser::TypeContext>(0);
}

tree::TerminalNode* ifccParser::Affectation5Context::VAR() {
  return getToken(ifccParser::VAR, 0);
}

ifccParser::ExpressionContext* ifccParser::Affectation5Context::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
}

ifccParser::Affectation5Context::Affectation5Context(AffectationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::Affectation5Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAffectation5(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Affectation4Context ------------------------------------------------------------------

tree::TerminalNode* ifccParser::Affectation4Context::VAR() {
  return getToken(ifccParser::VAR, 0);
}

tree::TerminalNode* ifccParser::Affectation4Context::CONST() {
  return getToken(ifccParser::CONST, 0);
}

ifccParser::Affectation4Context::Affectation4Context(AffectationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::Affectation4Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAffectation4(this);
  else
    return visitor->visitChildren(this);
}
ifccParser::AffectationContext* ifccParser::affectation() {
  AffectationContext *_localctx = _tracker.createInstance<AffectationContext>(_ctx, getState());
  enterRule(_localctx, 12, ifccParser::RuleAffectation);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(78);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<ifccParser::Affectation1Context>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(54);
      type();
      setState(55);
      match(ifccParser::VAR);
      setState(56);
      match(ifccParser::T__6);
      setState(57);
      match(ifccParser::VAR);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<ifccParser::Affectation2Context>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(59);
      type();
      setState(60);
      match(ifccParser::VAR);
      setState(61);
      match(ifccParser::T__6);
      setState(62);
      match(ifccParser::CONST);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<ifccParser::Affectation3Context>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(64);
      match(ifccParser::VAR);
      setState(65);
      match(ifccParser::T__6);
      setState(66);
      match(ifccParser::VAR);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<ifccParser::Affectation4Context>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(67);
      match(ifccParser::VAR);
      setState(68);
      match(ifccParser::T__6);
      setState(69);
      match(ifccParser::CONST);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<ifccParser::Affectation5Context>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(70);
      type();
      setState(71);
      match(ifccParser::VAR);
      setState(72);
      match(ifccParser::T__6);
      setState(73);
      expression(0);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<ifccParser::Affectation6Context>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(75);
      match(ifccParser::VAR);
      setState(76);
      match(ifccParser::T__6);
      setState(77);
      expression(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RetcodeContext ------------------------------------------------------------------

ifccParser::RetcodeContext::RetcodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ifccParser::RetcodeContext::getRuleIndex() const {
  return ifccParser::RuleRetcode;
}

void ifccParser::RetcodeContext::copyFrom(RetcodeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Ret2Context ------------------------------------------------------------------

tree::TerminalNode* ifccParser::Ret2Context::RETURN() {
  return getToken(ifccParser::RETURN, 0);
}

tree::TerminalNode* ifccParser::Ret2Context::VAR() {
  return getToken(ifccParser::VAR, 0);
}

ifccParser::Ret2Context::Ret2Context(RetcodeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::Ret2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitRet2(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Ret1Context ------------------------------------------------------------------

tree::TerminalNode* ifccParser::Ret1Context::RETURN() {
  return getToken(ifccParser::RETURN, 0);
}

tree::TerminalNode* ifccParser::Ret1Context::CONST() {
  return getToken(ifccParser::CONST, 0);
}

ifccParser::Ret1Context::Ret1Context(RetcodeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::Ret1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitRet1(this);
  else
    return visitor->visitChildren(this);
}
ifccParser::RetcodeContext* ifccParser::retcode() {
  RetcodeContext *_localctx = _tracker.createInstance<RetcodeContext>(_ctx, getState());
  enterRule(_localctx, 14, ifccParser::RuleRetcode);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(84);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<RetcodeContext *>(_tracker.createInstance<ifccParser::Ret1Context>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(80);
      match(ifccParser::RETURN);
      setState(81);
      match(ifccParser::CONST);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<RetcodeContext *>(_tracker.createInstance<ifccParser::Ret2Context>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(82);
      match(ifccParser::RETURN);
      setState(83);
      match(ifccParser::VAR);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariablesContext ------------------------------------------------------------------

ifccParser::VariablesContext::VariablesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ifccParser::VariablesContext::getRuleIndex() const {
  return ifccParser::RuleVariables;
}

void ifccParser::VariablesContext::copyFrom(VariablesContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MultvariablesContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::MultvariablesContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

ifccParser::VariablesContext* ifccParser::MultvariablesContext::variables() {
  return getRuleContext<ifccParser::VariablesContext>(0);
}

ifccParser::MultvariablesContext::MultvariablesContext(VariablesContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::MultvariablesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitMultvariables(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::VariableContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

ifccParser::VariableContext::VariableContext(VariablesContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}
ifccParser::VariablesContext* ifccParser::variables() {
  VariablesContext *_localctx = _tracker.createInstance<VariablesContext>(_ctx, getState());
  enterRule(_localctx, 16, ifccParser::RuleVariables);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(90);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VariablesContext *>(_tracker.createInstance<ifccParser::MultvariablesContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(86);
      match(ifccParser::VAR);
      setState(87);
      match(ifccParser::T__7);
      setState(88);
      variables();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VariablesContext *>(_tracker.createInstance<ifccParser::VariableContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(89);
      match(ifccParser::VAR);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

ifccParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ifccParser::ExpressionContext::getRuleIndex() const {
  return ifccParser::RuleExpression;
}

void ifccParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnaryexprContext ------------------------------------------------------------------

ifccParser::ExpressionContext* ifccParser::UnaryexprContext::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
}

ifccParser::UnaryexprContext::UnaryexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::UnaryexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitUnaryexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CharexprContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::CharexprContext::CHARACTER() {
  return getToken(ifccParser::CHARACTER, 0);
}

ifccParser::CharexprContext::CharexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::CharexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitCharexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelationalexprContext ------------------------------------------------------------------

std::vector<ifccParser::ExpressionContext *> ifccParser::RelationalexprContext::expression() {
  return getRuleContexts<ifccParser::ExpressionContext>();
}

ifccParser::ExpressionContext* ifccParser::RelationalexprContext::expression(size_t i) {
  return getRuleContext<ifccParser::ExpressionContext>(i);
}

ifccParser::RelationalexprContext::RelationalexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::RelationalexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitRelationalexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BracketexprContext ------------------------------------------------------------------

ifccParser::ExpressionContext* ifccParser::BracketexprContext::expression() {
  return getRuleContext<ifccParser::ExpressionContext>(0);
}

ifccParser::BracketexprContext::BracketexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::BracketexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitBracketexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarexprContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::VarexprContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

ifccParser::VarexprContext::VarexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::VarexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitVarexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultplicationexprContext ------------------------------------------------------------------

std::vector<ifccParser::ExpressionContext *> ifccParser::MultplicationexprContext::expression() {
  return getRuleContexts<ifccParser::ExpressionContext>();
}

ifccParser::ExpressionContext* ifccParser::MultplicationexprContext::expression(size_t i) {
  return getRuleContext<ifccParser::ExpressionContext>(i);
}

ifccParser::MultplicationexprContext::MultplicationexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::MultplicationexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitMultplicationexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AdditiveexprContext ------------------------------------------------------------------

std::vector<ifccParser::ExpressionContext *> ifccParser::AdditiveexprContext::expression() {
  return getRuleContexts<ifccParser::ExpressionContext>();
}

ifccParser::ExpressionContext* ifccParser::AdditiveexprContext::expression(size_t i) {
  return getRuleContext<ifccParser::ExpressionContext>(i);
}

ifccParser::AdditiveexprContext::AdditiveexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::AdditiveexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAdditiveexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitsexprContext ------------------------------------------------------------------

std::vector<ifccParser::ExpressionContext *> ifccParser::BitsexprContext::expression() {
  return getRuleContexts<ifccParser::ExpressionContext>();
}

ifccParser::ExpressionContext* ifccParser::BitsexprContext::expression(size_t i) {
  return getRuleContext<ifccParser::ExpressionContext>(i);
}

ifccParser::BitsexprContext::BitsexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::BitsexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitBitsexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstexprContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::ConstexprContext::CONST() {
  return getToken(ifccParser::CONST, 0);
}

ifccParser::ConstexprContext::ConstexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::ConstexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitConstexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqualityexprContext ------------------------------------------------------------------

std::vector<ifccParser::ExpressionContext *> ifccParser::EqualityexprContext::expression() {
  return getRuleContexts<ifccParser::ExpressionContext>();
}

ifccParser::ExpressionContext* ifccParser::EqualityexprContext::expression(size_t i) {
  return getRuleContext<ifccParser::ExpressionContext>(i);
}

ifccParser::EqualityexprContext::EqualityexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::EqualityexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitEqualityexpr(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ExpressionContext* ifccParser::expression() {
   return expression(0);
}

ifccParser::ExpressionContext* ifccParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ifccParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  ifccParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, ifccParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(102);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::VAR: {
        _localctx = _tracker.createInstance<VarexprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(93);
        match(ifccParser::VAR);
        break;
      }

      case ifccParser::CONST: {
        _localctx = _tracker.createInstance<ConstexprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(94);
        match(ifccParser::CONST);
        break;
      }

      case ifccParser::CHARACTER: {
        _localctx = _tracker.createInstance<CharexprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(95);
        match(ifccParser::CHARACTER);
        break;
      }

      case ifccParser::T__12:
      case ifccParser::T__22: {
        _localctx = _tracker.createInstance<UnaryexprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(96);
        dynamic_cast<UnaryexprContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == ifccParser::T__12

        || _la == ifccParser::T__22)) {
          dynamic_cast<UnaryexprContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(97);
        expression(2);
        break;
      }

      case ifccParser::T__1: {
        _localctx = _tracker.createInstance<BracketexprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(98);
        match(ifccParser::T__1);
        setState(99);
        expression(0);
        setState(100);
        match(ifccParser::T__2);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(121);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(119);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultplicationexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(104);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(105);
          dynamic_cast<MultplicationexprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << ifccParser::T__8)
            | (1ULL << ifccParser::T__9)
            | (1ULL << ifccParser::T__10))) != 0))) {
            dynamic_cast<MultplicationexprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(106);
          expression(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AdditiveexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(107);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(108);
          dynamic_cast<AdditiveexprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ifccParser::T__11

          || _la == ifccParser::T__12)) {
            dynamic_cast<AdditiveexprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(109);
          expression(7);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BitsexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(110);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(111);
          dynamic_cast<BitsexprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << ifccParser::T__13)
            | (1ULL << ifccParser::T__14)
            | (1ULL << ifccParser::T__15))) != 0))) {
            dynamic_cast<BitsexprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(112);
          expression(6);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<RelationalexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(113);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(114);
          dynamic_cast<RelationalexprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << ifccParser::T__16)
            | (1ULL << ifccParser::T__17)
            | (1ULL << ifccParser::T__18)
            | (1ULL << ifccParser::T__19))) != 0))) {
            dynamic_cast<RelationalexprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(115);
          expression(5);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<EqualityexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(116);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(117);
          dynamic_cast<EqualityexprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ifccParser::T__20

          || _la == ifccParser::T__21)) {
            dynamic_cast<EqualityexprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(118);
          expression(4);
          break;
        }

        default:
          break;
        } 
      }
      setState(123);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

ifccParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::TypeContext::INT() {
  return getToken(ifccParser::INT, 0);
}


size_t ifccParser::TypeContext::getRuleIndex() const {
  return ifccParser::RuleType;
}


antlrcpp::Any ifccParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::TypeContext* ifccParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 20, ifccParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    match(ifccParser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool ifccParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 9: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ifccParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ifccParser::_decisionToDFA;
atn::PredictionContextCache ifccParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ifccParser::_atn;
std::vector<uint16_t> ifccParser::_serializedATN;

std::vector<std::string> ifccParser::_ruleNames = {
  "axiom", "prog", "block", "statements", "statement", "declaration", "affectation", 
  "retcode", "variables", "expression", "type"
};

std::vector<std::string> ifccParser::_literalNames = {
  "", "'main'", "'('", "')'", "'{'", "'}'", "';'", "'='", "','", "'*'", 
  "'/'", "'%'", "'+'", "'-'", "'|'", "'&'", "'^'", "'<'", "'<='", "'>='", 
  "'>'", "'=='", "'!='", "'!'", "'return'", "", "", "", "", "'int'"
};

std::vector<std::string> ifccParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "RETURN", "CONST", "COMMENT", "DIRECTIVE", "WS", 
  "INT", "VAR", "IDENT", "CHARACTER"
};

dfa::Vocabulary ifccParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ifccParser::_tokenNames;

ifccParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x22, 0x81, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x3, 0x2, 0x3, 0x2, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
       0x5, 0x5, 0x5, 0x29, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
       0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 
       0x34, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x51, 0xa, 0x8, 0x3, 0x9, 0x3, 
       0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x57, 0xa, 0x9, 0x3, 0xa, 0x3, 
       0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x5d, 0xa, 0xa, 0x3, 0xb, 0x3, 
       0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x69, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
       0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
       0x7, 0xb, 0x7a, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x7d, 0xb, 0xb, 0x3, 
       0xc, 0x3, 0xc, 0x3, 0xc, 0x2, 0x3, 0x14, 0xd, 0x2, 0x4, 0x6, 0x8, 
       0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x2, 0x8, 0x4, 0x2, 0xf, 0xf, 
       0x19, 0x19, 0x3, 0x2, 0xb, 0xd, 0x3, 0x2, 0xe, 0xf, 0x3, 0x2, 0x10, 
       0x12, 0x3, 0x2, 0x13, 0x16, 0x3, 0x2, 0x17, 0x18, 0x2, 0x88, 0x2, 
       0x18, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x6, 0x20, 
       0x3, 0x2, 0x2, 0x2, 0x8, 0x28, 0x3, 0x2, 0x2, 0x2, 0xa, 0x33, 0x3, 
       0x2, 0x2, 0x2, 0xc, 0x35, 0x3, 0x2, 0x2, 0x2, 0xe, 0x50, 0x3, 0x2, 
       0x2, 0x2, 0x10, 0x56, 0x3, 0x2, 0x2, 0x2, 0x12, 0x5c, 0x3, 0x2, 0x2, 
       0x2, 0x14, 0x68, 0x3, 0x2, 0x2, 0x2, 0x16, 0x7e, 0x3, 0x2, 0x2, 0x2, 
       0x18, 0x19, 0x5, 0x4, 0x3, 0x2, 0x19, 0x3, 0x3, 0x2, 0x2, 0x2, 0x1a, 
       0x1b, 0x7, 0x1f, 0x2, 0x2, 0x1b, 0x1c, 0x7, 0x3, 0x2, 0x2, 0x1c, 
       0x1d, 0x7, 0x4, 0x2, 0x2, 0x1d, 0x1e, 0x7, 0x5, 0x2, 0x2, 0x1e, 0x1f, 
       0x5, 0x6, 0x4, 0x2, 0x1f, 0x5, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x7, 
       0x6, 0x2, 0x2, 0x21, 0x22, 0x5, 0x8, 0x5, 0x2, 0x22, 0x23, 0x7, 0x7, 
       0x2, 0x2, 0x23, 0x7, 0x3, 0x2, 0x2, 0x2, 0x24, 0x29, 0x5, 0xa, 0x6, 
       0x2, 0x25, 0x26, 0x5, 0xa, 0x6, 0x2, 0x26, 0x27, 0x5, 0x8, 0x5, 0x2, 
       0x27, 0x29, 0x3, 0x2, 0x2, 0x2, 0x28, 0x24, 0x3, 0x2, 0x2, 0x2, 0x28, 
       0x25, 0x3, 0x2, 0x2, 0x2, 0x29, 0x9, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 
       0x5, 0xc, 0x7, 0x2, 0x2b, 0x2c, 0x7, 0x8, 0x2, 0x2, 0x2c, 0x34, 0x3, 
       0x2, 0x2, 0x2, 0x2d, 0x2e, 0x5, 0xe, 0x8, 0x2, 0x2e, 0x2f, 0x7, 0x8, 
       0x2, 0x2, 0x2f, 0x34, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x5, 0x10, 
       0x9, 0x2, 0x31, 0x32, 0x7, 0x8, 0x2, 0x2, 0x32, 0x34, 0x3, 0x2, 0x2, 
       0x2, 0x33, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x33, 0x2d, 0x3, 0x2, 0x2, 0x2, 
       0x33, 0x30, 0x3, 0x2, 0x2, 0x2, 0x34, 0xb, 0x3, 0x2, 0x2, 0x2, 0x35, 
       0x36, 0x5, 0x16, 0xc, 0x2, 0x36, 0x37, 0x5, 0x12, 0xa, 0x2, 0x37, 
       0xd, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x5, 0x16, 0xc, 0x2, 0x39, 0x3a, 
       0x7, 0x20, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0x9, 0x2, 0x2, 0x3b, 0x3c, 
       0x7, 0x20, 0x2, 0x2, 0x3c, 0x51, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 
       0x5, 0x16, 0xc, 0x2, 0x3e, 0x3f, 0x7, 0x20, 0x2, 0x2, 0x3f, 0x40, 
       0x7, 0x9, 0x2, 0x2, 0x40, 0x41, 0x7, 0x1b, 0x2, 0x2, 0x41, 0x51, 
       0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x7, 0x20, 0x2, 0x2, 0x43, 0x44, 
       0x7, 0x9, 0x2, 0x2, 0x44, 0x51, 0x7, 0x20, 0x2, 0x2, 0x45, 0x46, 
       0x7, 0x20, 0x2, 0x2, 0x46, 0x47, 0x7, 0x9, 0x2, 0x2, 0x47, 0x51, 
       0x7, 0x1b, 0x2, 0x2, 0x48, 0x49, 0x5, 0x16, 0xc, 0x2, 0x49, 0x4a, 
       0x7, 0x20, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x9, 0x2, 0x2, 0x4b, 0x4c, 
       0x5, 0x14, 0xb, 0x2, 0x4c, 0x51, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 
       0x7, 0x20, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0x9, 0x2, 0x2, 0x4f, 0x51, 
       0x5, 0x14, 0xb, 0x2, 0x50, 0x38, 0x3, 0x2, 0x2, 0x2, 0x50, 0x3d, 
       0x3, 0x2, 0x2, 0x2, 0x50, 0x42, 0x3, 0x2, 0x2, 0x2, 0x50, 0x45, 0x3, 
       0x2, 0x2, 0x2, 0x50, 0x48, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4d, 0x3, 0x2, 
       0x2, 0x2, 0x51, 0xf, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x7, 0x1a, 0x2, 
       0x2, 0x53, 0x57, 0x7, 0x1b, 0x2, 0x2, 0x54, 0x55, 0x7, 0x1a, 0x2, 
       0x2, 0x55, 0x57, 0x7, 0x20, 0x2, 0x2, 0x56, 0x52, 0x3, 0x2, 0x2, 
       0x2, 0x56, 0x54, 0x3, 0x2, 0x2, 0x2, 0x57, 0x11, 0x3, 0x2, 0x2, 0x2, 
       0x58, 0x59, 0x7, 0x20, 0x2, 0x2, 0x59, 0x5a, 0x7, 0xa, 0x2, 0x2, 
       0x5a, 0x5d, 0x5, 0x12, 0xa, 0x2, 0x5b, 0x5d, 0x7, 0x20, 0x2, 0x2, 
       0x5c, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 
       0x13, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x8, 0xb, 0x1, 0x2, 0x5f, 0x69, 
       0x7, 0x20, 0x2, 0x2, 0x60, 0x69, 0x7, 0x1b, 0x2, 0x2, 0x61, 0x69, 
       0x7, 0x22, 0x2, 0x2, 0x62, 0x63, 0x9, 0x2, 0x2, 0x2, 0x63, 0x69, 
       0x5, 0x14, 0xb, 0x4, 0x64, 0x65, 0x7, 0x4, 0x2, 0x2, 0x65, 0x66, 
       0x5, 0x14, 0xb, 0x2, 0x66, 0x67, 0x7, 0x5, 0x2, 0x2, 0x67, 0x69, 
       0x3, 0x2, 0x2, 0x2, 0x68, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x68, 0x60, 0x3, 
       0x2, 0x2, 0x2, 0x68, 0x61, 0x3, 0x2, 0x2, 0x2, 0x68, 0x62, 0x3, 0x2, 
       0x2, 0x2, 0x68, 0x64, 0x3, 0x2, 0x2, 0x2, 0x69, 0x7b, 0x3, 0x2, 0x2, 
       0x2, 0x6a, 0x6b, 0xc, 0x9, 0x2, 0x2, 0x6b, 0x6c, 0x9, 0x3, 0x2, 0x2, 
       0x6c, 0x7a, 0x5, 0x14, 0xb, 0xa, 0x6d, 0x6e, 0xc, 0x8, 0x2, 0x2, 
       0x6e, 0x6f, 0x9, 0x4, 0x2, 0x2, 0x6f, 0x7a, 0x5, 0x14, 0xb, 0x9, 
       0x70, 0x71, 0xc, 0x7, 0x2, 0x2, 0x71, 0x72, 0x9, 0x5, 0x2, 0x2, 0x72, 
       0x7a, 0x5, 0x14, 0xb, 0x8, 0x73, 0x74, 0xc, 0x6, 0x2, 0x2, 0x74, 
       0x75, 0x9, 0x6, 0x2, 0x2, 0x75, 0x7a, 0x5, 0x14, 0xb, 0x7, 0x76, 
       0x77, 0xc, 0x5, 0x2, 0x2, 0x77, 0x78, 0x9, 0x7, 0x2, 0x2, 0x78, 0x7a, 
       0x5, 0x14, 0xb, 0x6, 0x79, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x79, 0x6d, 
       0x3, 0x2, 0x2, 0x2, 0x79, 0x70, 0x3, 0x2, 0x2, 0x2, 0x79, 0x73, 0x3, 
       0x2, 0x2, 0x2, 0x79, 0x76, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7d, 0x3, 0x2, 
       0x2, 0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x3, 0x2, 0x2, 
       0x2, 0x7c, 0x15, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7b, 0x3, 0x2, 0x2, 0x2, 
       0x7e, 0x7f, 0x7, 0x1f, 0x2, 0x2, 0x7f, 0x17, 0x3, 0x2, 0x2, 0x2, 
       0xa, 0x28, 0x33, 0x50, 0x56, 0x5c, 0x68, 0x79, 0x7b, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ifccParser::Initializer ifccParser::_init;
