// Generated from c:\Users\Benoi\OneDrive\Bureau\Cours\4A\PLDcomp\tp\compiler\compiler\ifcc.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class ifccParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, T__18=19, T__19=20, T__20=21, T__21=22, T__22=23, RETURN=24, 
		CONST=25, COMMENT=26, DIRECTIVE=27, WS=28, INT=29, VAR=30, IDENT=31, CHARACTER=32;
	public static final int
		RULE_axiom = 0, RULE_prog = 1, RULE_block = 2, RULE_statements = 3, RULE_statement = 4, 
		RULE_declaration = 5, RULE_affectation = 6, RULE_retcode = 7, RULE_variables = 8, 
		RULE_expression = 9, RULE_type = 10;
	private static String[] makeRuleNames() {
		return new String[] {
			"axiom", "prog", "block", "statements", "statement", "declaration", "affectation", 
			"retcode", "variables", "expression", "type"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'main'", "'('", "')'", "'{'", "'}'", "';'", "'='", "','", "'*'", 
			"'/'", "'%'", "'+'", "'-'", "'|'", "'&'", "'^'", "'<'", "'<='", "'>='", 
			"'>'", "'=='", "'!='", "'!'", "'return'", null, null, null, null, "'int'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			"RETURN", "CONST", "COMMENT", "DIRECTIVE", "WS", "INT", "VAR", "IDENT", 
			"CHARACTER"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "ifcc.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public ifccParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class AxiomContext extends ParserRuleContext {
		public ProgContext prog() {
			return getRuleContext(ProgContext.class,0);
		}
		public AxiomContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_axiom; }
	}

	public final AxiomContext axiom() throws RecognitionException {
		AxiomContext _localctx = new AxiomContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_axiom);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(22);
			prog();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProgContext extends ParserRuleContext {
		public TerminalNode INT() { return getToken(ifccParser.INT, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public ProgContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_prog; }
	}

	public final ProgContext prog() throws RecognitionException {
		ProgContext _localctx = new ProgContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_prog);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(24);
			match(INT);
			setState(25);
			match(T__0);
			setState(26);
			match(T__1);
			setState(27);
			match(T__2);
			setState(28);
			block();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockContext extends ParserRuleContext {
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_block);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(30);
			match(T__3);
			setState(31);
			statements();
			setState(32);
			match(T__4);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementsContext extends ParserRuleContext {
		public StatementsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statements; }
	 
		public StatementsContext() { }
		public void copyFrom(StatementsContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class Statements2Context extends StatementsContext {
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public Statements2Context(StatementsContext ctx) { copyFrom(ctx); }
	}
	public static class Statements1Context extends StatementsContext {
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public Statements1Context(StatementsContext ctx) { copyFrom(ctx); }
	}

	public final StatementsContext statements() throws RecognitionException {
		StatementsContext _localctx = new StatementsContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_statements);
		try {
			setState(38);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
			case 1:
				_localctx = new Statements1Context(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(34);
				statement();
				}
				break;
			case 2:
				_localctx = new Statements2Context(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(35);
				statement();
				setState(36);
				statements();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementContext extends ParserRuleContext {
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	 
		public StatementContext() { }
		public void copyFrom(StatementContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class Statement3Context extends StatementContext {
		public RetcodeContext retcode() {
			return getRuleContext(RetcodeContext.class,0);
		}
		public Statement3Context(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class Statement1Context extends StatementContext {
		public DeclarationContext declaration() {
			return getRuleContext(DeclarationContext.class,0);
		}
		public Statement1Context(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class Statement2Context extends StatementContext {
		public AffectationContext affectation() {
			return getRuleContext(AffectationContext.class,0);
		}
		public Statement2Context(StatementContext ctx) { copyFrom(ctx); }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_statement);
		try {
			setState(49);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				_localctx = new Statement1Context(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(40);
				declaration();
				setState(41);
				match(T__5);
				}
				break;
			case 2:
				_localctx = new Statement2Context(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(43);
				affectation();
				setState(44);
				match(T__5);
				}
				break;
			case 3:
				_localctx = new Statement3Context(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(46);
				retcode();
				setState(47);
				match(T__5);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclarationContext extends ParserRuleContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public VariablesContext variables() {
			return getRuleContext(VariablesContext.class,0);
		}
		public DeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration; }
	}

	public final DeclarationContext declaration() throws RecognitionException {
		DeclarationContext _localctx = new DeclarationContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_declaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(51);
			type();
			setState(52);
			variables();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AffectationContext extends ParserRuleContext {
		public AffectationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_affectation; }
	 
		public AffectationContext() { }
		public void copyFrom(AffectationContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class Affectation3Context extends AffectationContext {
		public List<TerminalNode> VAR() { return getTokens(ifccParser.VAR); }
		public TerminalNode VAR(int i) {
			return getToken(ifccParser.VAR, i);
		}
		public Affectation3Context(AffectationContext ctx) { copyFrom(ctx); }
	}
	public static class Affectation2Context extends AffectationContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode VAR() { return getToken(ifccParser.VAR, 0); }
		public TerminalNode CONST() { return getToken(ifccParser.CONST, 0); }
		public Affectation2Context(AffectationContext ctx) { copyFrom(ctx); }
	}
	public static class Affectation1Context extends AffectationContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public List<TerminalNode> VAR() { return getTokens(ifccParser.VAR); }
		public TerminalNode VAR(int i) {
			return getToken(ifccParser.VAR, i);
		}
		public Affectation1Context(AffectationContext ctx) { copyFrom(ctx); }
	}
	public static class Affectation6Context extends AffectationContext {
		public TerminalNode VAR() { return getToken(ifccParser.VAR, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Affectation6Context(AffectationContext ctx) { copyFrom(ctx); }
	}
	public static class Affectation5Context extends AffectationContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode VAR() { return getToken(ifccParser.VAR, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Affectation5Context(AffectationContext ctx) { copyFrom(ctx); }
	}
	public static class Affectation4Context extends AffectationContext {
		public TerminalNode VAR() { return getToken(ifccParser.VAR, 0); }
		public TerminalNode CONST() { return getToken(ifccParser.CONST, 0); }
		public Affectation4Context(AffectationContext ctx) { copyFrom(ctx); }
	}

	public final AffectationContext affectation() throws RecognitionException {
		AffectationContext _localctx = new AffectationContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_affectation);
		try {
			setState(78);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				_localctx = new Affectation1Context(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(54);
				type();
				setState(55);
				match(VAR);
				setState(56);
				match(T__6);
				setState(57);
				match(VAR);
				}
				break;
			case 2:
				_localctx = new Affectation2Context(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(59);
				type();
				setState(60);
				match(VAR);
				setState(61);
				match(T__6);
				setState(62);
				match(CONST);
				}
				break;
			case 3:
				_localctx = new Affectation3Context(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(64);
				match(VAR);
				setState(65);
				match(T__6);
				setState(66);
				match(VAR);
				}
				break;
			case 4:
				_localctx = new Affectation4Context(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(67);
				match(VAR);
				setState(68);
				match(T__6);
				setState(69);
				match(CONST);
				}
				break;
			case 5:
				_localctx = new Affectation5Context(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(70);
				type();
				setState(71);
				match(VAR);
				setState(72);
				match(T__6);
				setState(73);
				expression(0);
				}
				break;
			case 6:
				_localctx = new Affectation6Context(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(75);
				match(VAR);
				setState(76);
				match(T__6);
				setState(77);
				expression(0);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RetcodeContext extends ParserRuleContext {
		public RetcodeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_retcode; }
	 
		public RetcodeContext() { }
		public void copyFrom(RetcodeContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class Ret2Context extends RetcodeContext {
		public TerminalNode RETURN() { return getToken(ifccParser.RETURN, 0); }
		public TerminalNode VAR() { return getToken(ifccParser.VAR, 0); }
		public Ret2Context(RetcodeContext ctx) { copyFrom(ctx); }
	}
	public static class Ret1Context extends RetcodeContext {
		public TerminalNode RETURN() { return getToken(ifccParser.RETURN, 0); }
		public TerminalNode CONST() { return getToken(ifccParser.CONST, 0); }
		public Ret1Context(RetcodeContext ctx) { copyFrom(ctx); }
	}

	public final RetcodeContext retcode() throws RecognitionException {
		RetcodeContext _localctx = new RetcodeContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_retcode);
		try {
			setState(84);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				_localctx = new Ret1Context(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(80);
				match(RETURN);
				setState(81);
				match(CONST);
				}
				break;
			case 2:
				_localctx = new Ret2Context(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(82);
				match(RETURN);
				setState(83);
				match(VAR);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VariablesContext extends ParserRuleContext {
		public VariablesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variables; }
	 
		public VariablesContext() { }
		public void copyFrom(VariablesContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class MultvariablesContext extends VariablesContext {
		public TerminalNode VAR() { return getToken(ifccParser.VAR, 0); }
		public VariablesContext variables() {
			return getRuleContext(VariablesContext.class,0);
		}
		public MultvariablesContext(VariablesContext ctx) { copyFrom(ctx); }
	}
	public static class VariableContext extends VariablesContext {
		public TerminalNode VAR() { return getToken(ifccParser.VAR, 0); }
		public VariableContext(VariablesContext ctx) { copyFrom(ctx); }
	}

	public final VariablesContext variables() throws RecognitionException {
		VariablesContext _localctx = new VariablesContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_variables);
		try {
			setState(90);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				_localctx = new MultvariablesContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(86);
				match(VAR);
				setState(87);
				match(T__7);
				setState(88);
				variables();
				}
				break;
			case 2:
				_localctx = new VariableContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(89);
				match(VAR);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExpressionContext extends ParserRuleContext {
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	 
		public ExpressionContext() { }
		public void copyFrom(ExpressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class UnaryexprContext extends ExpressionContext {
		public Token op;
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public UnaryexprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class CharexprContext extends ExpressionContext {
		public TerminalNode CHARACTER() { return getToken(ifccParser.CHARACTER, 0); }
		public CharexprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class RelationalexprContext extends ExpressionContext {
		public Token op;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public RelationalexprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class BracketexprContext extends ExpressionContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public BracketexprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class VarexprContext extends ExpressionContext {
		public TerminalNode VAR() { return getToken(ifccParser.VAR, 0); }
		public VarexprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class MultplicationexprContext extends ExpressionContext {
		public Token op;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public MultplicationexprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class AdditiveexprContext extends ExpressionContext {
		public Token op;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public AdditiveexprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class BitsexprContext extends ExpressionContext {
		public Token op;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public BitsexprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class ConstexprContext extends ExpressionContext {
		public TerminalNode CONST() { return getToken(ifccParser.CONST, 0); }
		public ConstexprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class EqualityexprContext extends ExpressionContext {
		public Token op;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public EqualityexprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}

	public final ExpressionContext expression() throws RecognitionException {
		return expression(0);
	}

	private ExpressionContext expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpressionContext _localctx = new ExpressionContext(_ctx, _parentState);
		ExpressionContext _prevctx = _localctx;
		int _startState = 18;
		enterRecursionRule(_localctx, 18, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(102);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case VAR:
				{
				_localctx = new VarexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(93);
				match(VAR);
				}
				break;
			case CONST:
				{
				_localctx = new ConstexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(94);
				match(CONST);
				}
				break;
			case CHARACTER:
				{
				_localctx = new CharexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(95);
				match(CHARACTER);
				}
				break;
			case T__12:
			case T__22:
				{
				_localctx = new UnaryexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(96);
				((UnaryexprContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==T__12 || _la==T__22) ) {
					((UnaryexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(97);
				expression(2);
				}
				break;
			case T__1:
				{
				_localctx = new BracketexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(98);
				match(T__1);
				setState(99);
				expression(0);
				setState(100);
				match(T__2);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(121);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(119);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
					case 1:
						{
						_localctx = new MultplicationexprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(104);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(105);
						((MultplicationexprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__8) | (1L << T__9) | (1L << T__10))) != 0)) ) {
							((MultplicationexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(106);
						expression(8);
						}
						break;
					case 2:
						{
						_localctx = new AdditiveexprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(107);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(108);
						((AdditiveexprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__11 || _la==T__12) ) {
							((AdditiveexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(109);
						expression(7);
						}
						break;
					case 3:
						{
						_localctx = new BitsexprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(110);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(111);
						((BitsexprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__13) | (1L << T__14) | (1L << T__15))) != 0)) ) {
							((BitsexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(112);
						expression(6);
						}
						break;
					case 4:
						{
						_localctx = new RelationalexprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(113);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(114);
						((RelationalexprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__16) | (1L << T__17) | (1L << T__18) | (1L << T__19))) != 0)) ) {
							((RelationalexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(115);
						expression(5);
						}
						break;
					case 5:
						{
						_localctx = new EqualityexprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(116);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(117);
						((EqualityexprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__20 || _la==T__21) ) {
							((EqualityexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(118);
						expression(4);
						}
						break;
					}
					} 
				}
				setState(123);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class TypeContext extends ParserRuleContext {
		public TerminalNode INT() { return getToken(ifccParser.INT, 0); }
		public TypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type; }
	}

	public final TypeContext type() throws RecognitionException {
		TypeContext _localctx = new TypeContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_type);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(124);
			match(INT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 9:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expression_sempred(ExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 7);
		case 1:
			return precpred(_ctx, 6);
		case 2:
			return precpred(_ctx, 5);
		case 3:
			return precpred(_ctx, 4);
		case 4:
			return precpred(_ctx, 3);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\"\u0081\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\3\3\4\3\4\3\4\3\4\3\5\3\5\3"+
		"\5\3\5\5\5)\n\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\5\6\64\n\6\3\7\3\7"+
		"\3\7\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3"+
		"\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\5\bQ\n\b\3\t\3\t\3\t\3\t\5\tW\n\t\3\n\3"+
		"\n\3\n\3\n\5\n]\n\n\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13"+
		"\5\13i\n\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13"+
		"\3\13\3\13\3\13\7\13z\n\13\f\13\16\13}\13\13\3\f\3\f\3\f\2\3\24\r\2\4"+
		"\6\b\n\f\16\20\22\24\26\2\b\4\2\17\17\31\31\3\2\13\r\3\2\16\17\3\2\20"+
		"\22\3\2\23\26\3\2\27\30\2\u0088\2\30\3\2\2\2\4\32\3\2\2\2\6 \3\2\2\2\b"+
		"(\3\2\2\2\n\63\3\2\2\2\f\65\3\2\2\2\16P\3\2\2\2\20V\3\2\2\2\22\\\3\2\2"+
		"\2\24h\3\2\2\2\26~\3\2\2\2\30\31\5\4\3\2\31\3\3\2\2\2\32\33\7\37\2\2\33"+
		"\34\7\3\2\2\34\35\7\4\2\2\35\36\7\5\2\2\36\37\5\6\4\2\37\5\3\2\2\2 !\7"+
		"\6\2\2!\"\5\b\5\2\"#\7\7\2\2#\7\3\2\2\2$)\5\n\6\2%&\5\n\6\2&\'\5\b\5\2"+
		"\')\3\2\2\2($\3\2\2\2(%\3\2\2\2)\t\3\2\2\2*+\5\f\7\2+,\7\b\2\2,\64\3\2"+
		"\2\2-.\5\16\b\2./\7\b\2\2/\64\3\2\2\2\60\61\5\20\t\2\61\62\7\b\2\2\62"+
		"\64\3\2\2\2\63*\3\2\2\2\63-\3\2\2\2\63\60\3\2\2\2\64\13\3\2\2\2\65\66"+
		"\5\26\f\2\66\67\5\22\n\2\67\r\3\2\2\289\5\26\f\29:\7 \2\2:;\7\t\2\2;<"+
		"\7 \2\2<Q\3\2\2\2=>\5\26\f\2>?\7 \2\2?@\7\t\2\2@A\7\33\2\2AQ\3\2\2\2B"+
		"C\7 \2\2CD\7\t\2\2DQ\7 \2\2EF\7 \2\2FG\7\t\2\2GQ\7\33\2\2HI\5\26\f\2I"+
		"J\7 \2\2JK\7\t\2\2KL\5\24\13\2LQ\3\2\2\2MN\7 \2\2NO\7\t\2\2OQ\5\24\13"+
		"\2P8\3\2\2\2P=\3\2\2\2PB\3\2\2\2PE\3\2\2\2PH\3\2\2\2PM\3\2\2\2Q\17\3\2"+
		"\2\2RS\7\32\2\2SW\7\33\2\2TU\7\32\2\2UW\7 \2\2VR\3\2\2\2VT\3\2\2\2W\21"+
		"\3\2\2\2XY\7 \2\2YZ\7\n\2\2Z]\5\22\n\2[]\7 \2\2\\X\3\2\2\2\\[\3\2\2\2"+
		"]\23\3\2\2\2^_\b\13\1\2_i\7 \2\2`i\7\33\2\2ai\7\"\2\2bc\t\2\2\2ci\5\24"+
		"\13\4de\7\4\2\2ef\5\24\13\2fg\7\5\2\2gi\3\2\2\2h^\3\2\2\2h`\3\2\2\2ha"+
		"\3\2\2\2hb\3\2\2\2hd\3\2\2\2i{\3\2\2\2jk\f\t\2\2kl\t\3\2\2lz\5\24\13\n"+
		"mn\f\b\2\2no\t\4\2\2oz\5\24\13\tpq\f\7\2\2qr\t\5\2\2rz\5\24\13\bst\f\6"+
		"\2\2tu\t\6\2\2uz\5\24\13\7vw\f\5\2\2wx\t\7\2\2xz\5\24\13\6yj\3\2\2\2y"+
		"m\3\2\2\2yp\3\2\2\2ys\3\2\2\2yv\3\2\2\2z}\3\2\2\2{y\3\2\2\2{|\3\2\2\2"+
		"|\25\3\2\2\2}{\3\2\2\2~\177\7\37\2\2\177\27\3\2\2\2\n(\63PV\\hy{";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}