
// Generated from ifcc.g4 by ANTLR 4.7.2


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

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(18);
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

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(20);
    match(ifccParser::INT);
    setState(21);
    match(ifccParser::T__0);
    setState(22);
    match(ifccParser::T__1);
    setState(23);
    match(ifccParser::T__2);
    setState(24);
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

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(26);
    match(ifccParser::T__3);
    setState(27);
    statements();
    setState(28);
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

<<<<<<< HEAD
antlrcpp::Any ifccParser::StatementsContext::accept(tree::ParseTreeVisitor *visitor) {
=======
ifccParser::StatementContext* ifccParser::Statements1Context::statement() {
  return getRuleContext<ifccParser::StatementContext>(0);
}

ifccParser::Statements1Context::Statements1Context(StatementsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::Statements1Context::accept(tree::ParseTreeVisitor *visitor) {
>>>>>>> 926982dc6434e97012ef64a66a1e344978a0bde7
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitStatements1(this);
  else
    return visitor->visitChildren(this);
}
ifccParser::StatementsContext* ifccParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 6, ifccParser::RuleStatements);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(34);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementsContext *>(_tracker.createInstance<ifccParser::Statements1Context>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(30);
      statement();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementsContext *>(_tracker.createInstance<ifccParser::Statements2Context>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(31);
      statement();
      setState(32);
      statements();
      break;
    }

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

<<<<<<< HEAD
antlrcpp::Any ifccParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
=======
ifccParser::Statement1Context::Statement1Context(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::Statement1Context::accept(tree::ParseTreeVisitor *visitor) {
>>>>>>> 926982dc6434e97012ef64a66a1e344978a0bde7
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

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(45);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ifccParser::Statement1Context>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(36);
      declaration();
      setState(37);
      match(ifccParser::T__5);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ifccParser::Statement2Context>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(39);
      affectation();
      setState(40);
      match(ifccParser::T__5);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ifccParser::Statement3Context>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(42);
      retcode();
      setState(43);
      match(ifccParser::T__5);
      break;
    }

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

tree::TerminalNode* ifccParser::DeclarationContext::VAR() {
  return getToken(ifccParser::VAR, 0);
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

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(47);
    type();
    setState(48);
    match(ifccParser::VAR);
   
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

<<<<<<< HEAD
//----------------- Cas3Context ------------------------------------------------------------------

std::vector<tree::TerminalNode *> ifccParser::Cas3Context::VAR() {
  return getTokens(ifccParser::VAR);
}

tree::TerminalNode* ifccParser::Cas3Context::VAR(size_t i) {
  return getToken(ifccParser::VAR, i);
}

ifccParser::Cas3Context::Cas3Context(AffectationContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::Cas3Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitCas3(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Cas4Context ------------------------------------------------------------------

tree::TerminalNode* ifccParser::Cas4Context::VAR() {
  return getToken(ifccParser::VAR, 0);
}

tree::TerminalNode* ifccParser::Cas4Context::CONST() {
  return getToken(ifccParser::CONST, 0);
}

ifccParser::Cas4Context::Cas4Context(AffectationContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::Cas4Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitCas4(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Cas1Context ------------------------------------------------------------------

ifccParser::TypeContext* ifccParser::Cas1Context::type() {
  return getRuleContext<ifccParser::TypeContext>(0);
}

std::vector<tree::TerminalNode *> ifccParser::Cas1Context::VAR() {
  return getTokens(ifccParser::VAR);
}

tree::TerminalNode* ifccParser::Cas1Context::VAR(size_t i) {
  return getToken(ifccParser::VAR, i);
}

ifccParser::Cas1Context::Cas1Context(AffectationContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::Cas1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitCas1(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Cas2Context ------------------------------------------------------------------

ifccParser::TypeContext* ifccParser::Cas2Context::type() {
  return getRuleContext<ifccParser::TypeContext>(0);
}

tree::TerminalNode* ifccParser::Cas2Context::VAR() {
  return getToken(ifccParser::VAR, 0);
}

tree::TerminalNode* ifccParser::Cas2Context::CONST() {
  return getToken(ifccParser::CONST, 0);
}

ifccParser::Cas2Context::Cas2Context(AffectationContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::Cas2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitCas2(this);
=======
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
>>>>>>> 926982dc6434e97012ef64a66a1e344978a0bde7
  else
    return visitor->visitChildren(this);
}
ifccParser::AffectationContext* ifccParser::affectation() {
  AffectationContext *_localctx = _tracker.createInstance<AffectationContext>(_ctx, getState());
  enterRule(_localctx, 12, ifccParser::RuleAffectation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(66);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
<<<<<<< HEAD
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<ifccParser::Cas1Context>(_localctx));
=======
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<ifccParser::Affectation1Context>(_localctx));
>>>>>>> 926982dc6434e97012ef64a66a1e344978a0bde7
      enterOuterAlt(_localctx, 1);
      setState(50);
      type();
      setState(51);
      match(ifccParser::VAR);
      setState(52);
      match(ifccParser::T__6);
      setState(53);
      match(ifccParser::VAR);
      break;
    }

    case 2: {
<<<<<<< HEAD
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<ifccParser::Cas2Context>(_localctx));
=======
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<ifccParser::Affectation2Context>(_localctx));
>>>>>>> 926982dc6434e97012ef64a66a1e344978a0bde7
      enterOuterAlt(_localctx, 2);
      setState(55);
      type();
      setState(56);
      match(ifccParser::VAR);
      setState(57);
      match(ifccParser::T__6);
      setState(58);
      match(ifccParser::CONST);
      break;
    }

    case 3: {
<<<<<<< HEAD
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<ifccParser::Cas3Context>(_localctx));
=======
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<ifccParser::Affectation3Context>(_localctx));
>>>>>>> 926982dc6434e97012ef64a66a1e344978a0bde7
      enterOuterAlt(_localctx, 3);
      setState(60);
      match(ifccParser::VAR);
      setState(61);
      match(ifccParser::T__6);
      setState(62);
      match(ifccParser::VAR);
      break;
    }

    case 4: {
<<<<<<< HEAD
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<ifccParser::Cas4Context>(_localctx));
=======
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<ifccParser::Affectation4Context>(_localctx));
>>>>>>> 926982dc6434e97012ef64a66a1e344978a0bde7
      enterOuterAlt(_localctx, 4);
      setState(63);
      match(ifccParser::VAR);
      setState(64);
      match(ifccParser::T__6);
      setState(65);
      match(ifccParser::CONST);
      break;
    }

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

<<<<<<< HEAD
antlrcpp::Any ifccParser::RetcodeContext::accept(tree::ParseTreeVisitor *visitor) {
=======
tree::TerminalNode* ifccParser::Ret1Context::CONST() {
  return getToken(ifccParser::CONST, 0);
}

ifccParser::Ret1Context::Ret1Context(RetcodeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::Ret1Context::accept(tree::ParseTreeVisitor *visitor) {
>>>>>>> 926982dc6434e97012ef64a66a1e344978a0bde7
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitRet1(this);
  else
    return visitor->visitChildren(this);
}
ifccParser::RetcodeContext* ifccParser::retcode() {
  RetcodeContext *_localctx = _tracker.createInstance<RetcodeContext>(_ctx, getState());
  enterRule(_localctx, 14, ifccParser::RuleRetcode);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(72);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<RetcodeContext *>(_tracker.createInstance<ifccParser::Ret1Context>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(68);
      match(ifccParser::RETURN);
      setState(69);
      match(ifccParser::CONST);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<RetcodeContext *>(_tracker.createInstance<ifccParser::Ret2Context>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(70);
      match(ifccParser::RETURN);
      setState(71);
      match(ifccParser::VAR);
      break;
    }

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
  enterRule(_localctx, 16, ifccParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(74);
    match(ifccParser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> ifccParser::_decisionToDFA;
atn::PredictionContextCache ifccParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ifccParser::_atn;
std::vector<uint16_t> ifccParser::_serializedATN;

std::vector<std::string> ifccParser::_ruleNames = {
  "axiom", "prog", "block", "statements", "statement", "declaration", "affectation", 
  "retcode", "type"
};

std::vector<std::string> ifccParser::_literalNames = {
  "", "'main'", "'('", "')'", "'{'", "'}'", "';'", "'='", "'return'", "", 
  "", "", "", "'int'"
};

std::vector<std::string> ifccParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "RETURN", "CONST", "COMMENT", "DIRECTIVE", 
  "WS", "INT", "VAR", "IDENT"
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

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x11, 0x4f, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x5, 0x5, 0x25, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x30, 0xa, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x45, 
    0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x4b, 0xa, 
    0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x2, 0x2, 0xb, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x2, 0x2, 0x2, 0x4c, 0x2, 0x14, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x16, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1c, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x24, 0x3, 0x2, 0x2, 0x2, 0xa, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xc, 0x31, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x44, 0x3, 0x2, 0x2, 0x2, 0x10, 0x4a, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 0x5, 0x4, 
    0x3, 0x2, 0x15, 0x3, 0x3, 0x2, 0x2, 0x2, 0x16, 0x17, 0x7, 0xf, 0x2, 
    0x2, 0x17, 0x18, 0x7, 0x3, 0x2, 0x2, 0x18, 0x19, 0x7, 0x4, 0x2, 0x2, 
    0x19, 0x1a, 0x7, 0x5, 0x2, 0x2, 0x1a, 0x1b, 0x5, 0x6, 0x4, 0x2, 0x1b, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x7, 0x6, 0x2, 0x2, 0x1d, 0x1e, 
    0x5, 0x8, 0x5, 0x2, 0x1e, 0x1f, 0x7, 0x7, 0x2, 0x2, 0x1f, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x20, 0x25, 0x5, 0xa, 0x6, 0x2, 0x21, 0x22, 0x5, 0xa, 
    0x6, 0x2, 0x22, 0x23, 0x5, 0x8, 0x5, 0x2, 0x23, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0x20, 0x3, 0x2, 0x2, 0x2, 0x24, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0x25, 0x9, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x5, 0xc, 0x7, 0x2, 0x27, 
    0x28, 0x7, 0x8, 0x2, 0x2, 0x28, 0x30, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 
    0x5, 0xe, 0x8, 0x2, 0x2a, 0x2b, 0x7, 0x8, 0x2, 0x2, 0x2b, 0x30, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x2d, 0x5, 0x10, 0x9, 0x2, 0x2d, 0x2e, 0x7, 0x8, 
    0x2, 0x2, 0x2e, 0x30, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x26, 0x3, 0x2, 0x2, 
    0x2, 0x2f, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2c, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0xb, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x5, 0x12, 0xa, 0x2, 0x32, 
    0x33, 0x7, 0x10, 0x2, 0x2, 0x33, 0xd, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 
    0x5, 0x12, 0xa, 0x2, 0x35, 0x36, 0x7, 0x10, 0x2, 0x2, 0x36, 0x37, 0x7, 
    0x9, 0x2, 0x2, 0x37, 0x38, 0x7, 0x10, 0x2, 0x2, 0x38, 0x45, 0x3, 0x2, 
    0x2, 0x2, 0x39, 0x3a, 0x5, 0x12, 0xa, 0x2, 0x3a, 0x3b, 0x7, 0x10, 0x2, 
    0x2, 0x3b, 0x3c, 0x7, 0x9, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0xb, 0x2, 0x2, 
    0x3d, 0x45, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0x10, 0x2, 0x2, 0x3f, 
    0x40, 0x7, 0x9, 0x2, 0x2, 0x40, 0x45, 0x7, 0x10, 0x2, 0x2, 0x41, 0x42, 
    0x7, 0x10, 0x2, 0x2, 0x42, 0x43, 0x7, 0x9, 0x2, 0x2, 0x43, 0x45, 0x7, 
    0xb, 0x2, 0x2, 0x44, 0x34, 0x3, 0x2, 0x2, 0x2, 0x44, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0x44, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x44, 0x41, 0x3, 0x2, 0x2, 
    0x2, 0x45, 0xf, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x7, 0xa, 0x2, 0x2, 
    0x47, 0x4b, 0x7, 0xb, 0x2, 0x2, 0x48, 0x49, 0x7, 0xa, 0x2, 0x2, 0x49, 
    0x4b, 0x7, 0x10, 0x2, 0x2, 0x4a, 0x46, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x48, 
    0x3, 0x2, 0x2, 0x2, 0x4b, 0x11, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x7, 
    0xf, 0x2, 0x2, 0x4d, 0x13, 0x3, 0x2, 0x2, 0x2, 0x6, 0x24, 0x2f, 0x44, 
    0x4a, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ifccParser::Initializer ifccParser::_init;
