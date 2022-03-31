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
		T__17=18, T__18=19, T__19=20, T__20=21, T__21=22, T__22=23, T__23=24, 
		T__24=25, T__25=26, T__26=27, RETURN=28, CONST=29, COMMENT=30, DIRECTIVE=31, 
		WS=32, INT=33, CHAR=34, IDENT=35, CHARACTER=36;
	public static final int
		RULE_axiom = 0, RULE_prog = 1, RULE_function = 2, RULE_block = 3, RULE_statement = 4, 
		RULE_nameFunction = 5, RULE_parameters = 6, RULE_parameter = 7, RULE_declaration = 8, 
		RULE_affectation = 9, RULE_retcode = 10, RULE_ifBlock = 11, RULE_elseBlock = 12, 
		RULE_whileBlock = 13, RULE_forBlock = 14, RULE_expression = 15, RULE_type = 16;
	private static String[] makeRuleNames() {
		return new String[] {
			"axiom", "prog", "function", "block", "statement", "nameFunction", "parameters", 
			"parameter", "declaration", "affectation", "retcode", "ifBlock", "elseBlock", 
			"whileBlock", "forBlock", "expression", "type"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'void'", "'('", "')'", "'{'", "'}'", "';'", "','", "'='", "'if'", 
			"'else'", "'while'", "'for'", "'*'", "'/'", "'%'", "'-'", "'!'", "'+'", 
			"'|'", "'&'", "'^'", "'<'", "'<='", "'>='", "'>'", "'=='", "'!='", "'return'", 
			null, null, null, null, "'int'", "'char'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, "RETURN", "CONST", "COMMENT", "DIRECTIVE", "WS", 
			"INT", "CHAR", "IDENT", "CHARACTER"
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
			setState(34);
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
		public List<FunctionContext> function() {
			return getRuleContexts(FunctionContext.class);
		}
		public FunctionContext function(int i) {
			return getRuleContext(FunctionContext.class,i);
		}
		public ProgContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_prog; }
	}

	public final ProgContext prog() throws RecognitionException {
		ProgContext _localctx = new ProgContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_prog);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(39);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << INT) | (1L << CHAR))) != 0)) {
				{
				{
				setState(36);
				function();
				}
				}
				setState(41);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
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

	public static class FunctionContext extends ParserRuleContext {
		public TerminalNode IDENT() { return getToken(ifccParser.IDENT, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public ParametersContext parameters() {
			return getRuleContext(ParametersContext.class,0);
		}
		public FunctionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_function; }
	}

	public final FunctionContext function() throws RecognitionException {
		FunctionContext _localctx = new FunctionContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_function);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(44);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INT:
			case CHAR:
				{
				setState(42);
				type();
				}
				break;
			case T__0:
				{
				setState(43);
				match(T__0);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(46);
			match(IDENT);
			setState(47);
			match(T__1);
			setState(49);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==INT || _la==CHAR) {
				{
				setState(48);
				parameters();
				}
			}

			setState(51);
			match(T__2);
			setState(52);
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
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(54);
			match(T__3);
			setState(58);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__1) | (1L << T__8) | (1L << T__10) | (1L << T__11) | (1L << T__15) | (1L << T__16) | (1L << RETURN) | (1L << CONST) | (1L << INT) | (1L << CHAR) | (1L << IDENT) | (1L << CHARACTER))) != 0)) {
				{
				{
				setState(55);
				statement();
				}
				}
				setState(60);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(61);
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
	public static class Statement7Context extends StatementContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Statement7Context(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class Statement5Context extends StatementContext {
		public WhileBlockContext whileBlock() {
			return getRuleContext(WhileBlockContext.class,0);
		}
		public Statement5Context(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class Statement6Context extends StatementContext {
		public ForBlockContext forBlock() {
			return getRuleContext(ForBlockContext.class,0);
		}
		public Statement6Context(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class Statement3Context extends StatementContext {
		public RetcodeContext retcode() {
			return getRuleContext(RetcodeContext.class,0);
		}
		public Statement3Context(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class Statement4Context extends StatementContext {
		public IfBlockContext ifBlock() {
			return getRuleContext(IfBlockContext.class,0);
		}
		public Statement4Context(StatementContext ctx) { copyFrom(ctx); }
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
			setState(78);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				_localctx = new Statement1Context(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(63);
				declaration();
				setState(64);
				match(T__5);
				}
				break;
			case 2:
				_localctx = new Statement2Context(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(66);
				affectation();
				setState(67);
				match(T__5);
				}
				break;
			case 3:
				_localctx = new Statement3Context(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(69);
				retcode();
				setState(70);
				match(T__5);
				}
				break;
			case 4:
				_localctx = new Statement4Context(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(72);
				ifBlock();
				}
				break;
			case 5:
				_localctx = new Statement5Context(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(73);
				whileBlock();
				}
				break;
			case 6:
				_localctx = new Statement6Context(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(74);
				forBlock();
				}
				break;
			case 7:
				_localctx = new Statement7Context(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(75);
				expression(0);
				setState(76);
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

	public static class NameFunctionContext extends ParserRuleContext {
		public TerminalNode IDENT() { return getToken(ifccParser.IDENT, 0); }
		public NameFunctionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_nameFunction; }
	}

	public final NameFunctionContext nameFunction() throws RecognitionException {
		NameFunctionContext _localctx = new NameFunctionContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_nameFunction);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(80);
			match(IDENT);
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

	public static class ParametersContext extends ParserRuleContext {
		public List<ParameterContext> parameter() {
			return getRuleContexts(ParameterContext.class);
		}
		public ParameterContext parameter(int i) {
			return getRuleContext(ParameterContext.class,i);
		}
		public ParametersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameters; }
	}

	public final ParametersContext parameters() throws RecognitionException {
		ParametersContext _localctx = new ParametersContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_parameters);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(82);
			parameter();
			setState(87);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__6) {
				{
				{
				setState(83);
				match(T__6);
				setState(84);
				parameter();
				}
				}
				setState(89);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
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

	public static class ParameterContext extends ParserRuleContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode IDENT() { return getToken(ifccParser.IDENT, 0); }
		public ParameterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter; }
	}

	public final ParameterContext parameter() throws RecognitionException {
		ParameterContext _localctx = new ParameterContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_parameter);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(90);
			type();
			setState(91);
			match(IDENT);
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
		public List<TerminalNode> IDENT() { return getTokens(ifccParser.IDENT); }
		public TerminalNode IDENT(int i) {
			return getToken(ifccParser.IDENT, i);
		}
		public DeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration; }
	}

	public final DeclarationContext declaration() throws RecognitionException {
		DeclarationContext _localctx = new DeclarationContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(93);
			type();
			setState(94);
			match(IDENT);
			setState(99);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__6) {
				{
				{
				setState(95);
				match(T__6);
				setState(96);
				match(IDENT);
				}
				}
				setState(101);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
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
	public static class Affectation2Context extends AffectationContext {
		public TerminalNode IDENT() { return getToken(ifccParser.IDENT, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Affectation2Context(AffectationContext ctx) { copyFrom(ctx); }
	}
	public static class Affectation1Context extends AffectationContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode IDENT() { return getToken(ifccParser.IDENT, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Affectation1Context(AffectationContext ctx) { copyFrom(ctx); }
	}

	public final AffectationContext affectation() throws RecognitionException {
		AffectationContext _localctx = new AffectationContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_affectation);
		try {
			setState(110);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INT:
			case CHAR:
				_localctx = new Affectation1Context(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(102);
				type();
				setState(103);
				match(IDENT);
				setState(104);
				match(T__7);
				setState(105);
				expression(0);
				}
				break;
			case IDENT:
				_localctx = new Affectation2Context(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(107);
				match(IDENT);
				setState(108);
				match(T__7);
				setState(109);
				expression(0);
				}
				break;
			default:
				throw new NoViableAltException(this);
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
	public static class Ret1Context extends RetcodeContext {
		public TerminalNode RETURN() { return getToken(ifccParser.RETURN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Ret1Context(RetcodeContext ctx) { copyFrom(ctx); }
	}

	public final RetcodeContext retcode() throws RecognitionException {
		RetcodeContext _localctx = new RetcodeContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_retcode);
		try {
			_localctx = new Ret1Context(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(112);
			match(RETURN);
			setState(113);
			expression(0);
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

	public static class IfBlockContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public ElseBlockContext elseBlock() {
			return getRuleContext(ElseBlockContext.class,0);
		}
		public IfBlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ifBlock; }
	}

	public final IfBlockContext ifBlock() throws RecognitionException {
		IfBlockContext _localctx = new IfBlockContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_ifBlock);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(115);
			match(T__8);
			setState(116);
			match(T__1);
			setState(117);
			expression(0);
			setState(118);
			match(T__2);
			setState(121);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__1:
			case T__8:
			case T__10:
			case T__11:
			case T__15:
			case T__16:
			case RETURN:
			case CONST:
			case INT:
			case CHAR:
			case IDENT:
			case CHARACTER:
				{
				setState(119);
				statement();
				}
				break;
			case T__3:
				{
				setState(120);
				block();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(124);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
			case 1:
				{
				setState(123);
				elseBlock();
				}
				break;
			}
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

	public static class ElseBlockContext extends ParserRuleContext {
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public IfBlockContext ifBlock() {
			return getRuleContext(IfBlockContext.class,0);
		}
		public ElseBlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_elseBlock; }
	}

	public final ElseBlockContext elseBlock() throws RecognitionException {
		ElseBlockContext _localctx = new ElseBlockContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_elseBlock);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(126);
			match(T__9);
			setState(130);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				{
				setState(127);
				statement();
				}
				break;
			case 2:
				{
				setState(128);
				block();
				}
				break;
			case 3:
				{
				setState(129);
				ifBlock();
				}
				break;
			}
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

	public static class WhileBlockContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public WhileBlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whileBlock; }
	}

	public final WhileBlockContext whileBlock() throws RecognitionException {
		WhileBlockContext _localctx = new WhileBlockContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_whileBlock);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(132);
			match(T__10);
			setState(133);
			match(T__1);
			setState(134);
			expression(0);
			setState(135);
			match(T__2);
			setState(138);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__1:
			case T__8:
			case T__10:
			case T__11:
			case T__15:
			case T__16:
			case RETURN:
			case CONST:
			case INT:
			case CHAR:
			case IDENT:
			case CHARACTER:
				{
				setState(136);
				statement();
				}
				break;
			case T__3:
				{
				setState(137);
				block();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
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

	public static class ForBlockContext extends ParserRuleContext {
		public StatementContext init;
		public ExpressionContext test;
		public AffectationContext update;
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public AffectationContext affectation() {
			return getRuleContext(AffectationContext.class,0);
		}
		public ForBlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forBlock; }
	}

	public final ForBlockContext forBlock() throws RecognitionException {
		ForBlockContext _localctx = new ForBlockContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_forBlock);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(140);
			match(T__11);
			setState(141);
			match(T__1);
			setState(144);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__1:
			case T__8:
			case T__10:
			case T__11:
			case T__15:
			case T__16:
			case RETURN:
			case CONST:
			case INT:
			case CHAR:
			case IDENT:
			case CHARACTER:
				{
				setState(142);
				((ForBlockContext)_localctx).init = statement();
				}
				break;
			case T__5:
				{
				setState(143);
				match(T__5);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			{
			setState(146);
			((ForBlockContext)_localctx).test = expression(0);
			}
			setState(147);
			match(T__5);
			setState(149);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << INT) | (1L << CHAR) | (1L << IDENT))) != 0)) {
				{
				setState(148);
				((ForBlockContext)_localctx).update = affectation();
				}
			}

			setState(151);
			match(T__2);
			setState(154);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__1:
			case T__8:
			case T__10:
			case T__11:
			case T__15:
			case T__16:
			case RETURN:
			case CONST:
			case INT:
			case CHAR:
			case IDENT:
			case CHARACTER:
				{
				setState(152);
				statement();
				}
				break;
			case T__3:
				{
				setState(153);
				block();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
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
		public TerminalNode IDENT() { return getToken(ifccParser.IDENT, 0); }
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
	public static class FunctionexprContext extends ExpressionContext {
		public TerminalNode IDENT() { return getToken(ifccParser.IDENT, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public FunctionexprContext(ExpressionContext ctx) { copyFrom(ctx); }
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
		int _startState = 30;
		enterRecursionRule(_localctx, 30, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(181);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				{
				_localctx = new VarexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(157);
				match(IDENT);
				}
				break;
			case 2:
				{
				_localctx = new ConstexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(158);
				match(CONST);
				}
				break;
			case 3:
				{
				_localctx = new CharexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(159);
				match(CHARACTER);
				}
				break;
			case 4:
				{
				_localctx = new UnaryexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(160);
				((UnaryexprContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==T__15 || _la==T__16) ) {
					((UnaryexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(161);
				expression(8);
				}
				break;
			case 5:
				{
				_localctx = new UnaryexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(162);
				((UnaryexprContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==T__15 || _la==T__16) ) {
					((UnaryexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(163);
				expression(3);
				}
				break;
			case 6:
				{
				_localctx = new BracketexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(164);
				match(T__1);
				setState(165);
				expression(0);
				setState(166);
				match(T__2);
				}
				break;
			case 7:
				{
				_localctx = new FunctionexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(168);
				match(IDENT);
				setState(169);
				match(T__1);
				setState(178);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__1) | (1L << T__15) | (1L << T__16) | (1L << CONST) | (1L << IDENT) | (1L << CHARACTER))) != 0)) {
					{
					setState(170);
					expression(0);
					setState(175);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==T__6) {
						{
						{
						setState(171);
						match(T__6);
						setState(172);
						expression(0);
						}
						}
						setState(177);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
				}

				setState(180);
				match(T__2);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(200);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(198);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
					case 1:
						{
						_localctx = new MultplicationexprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(183);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(184);
						((MultplicationexprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__12) | (1L << T__13) | (1L << T__14))) != 0)) ) {
							((MultplicationexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(185);
						expression(10);
						}
						break;
					case 2:
						{
						_localctx = new AdditiveexprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(186);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(187);
						((AdditiveexprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__15 || _la==T__17) ) {
							((AdditiveexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(188);
						expression(8);
						}
						break;
					case 3:
						{
						_localctx = new BitsexprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(189);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(190);
						((BitsexprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__18) | (1L << T__19) | (1L << T__20))) != 0)) ) {
							((BitsexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(191);
						expression(7);
						}
						break;
					case 4:
						{
						_localctx = new RelationalexprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(192);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(193);
						((RelationalexprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__21) | (1L << T__22) | (1L << T__23) | (1L << T__24))) != 0)) ) {
							((RelationalexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(194);
						expression(6);
						}
						break;
					case 5:
						{
						_localctx = new EqualityexprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(195);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(196);
						((EqualityexprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__25 || _la==T__26) ) {
							((EqualityexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(197);
						expression(5);
						}
						break;
					}
					} 
				}
				setState(202);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
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
		public TerminalNode CHAR() { return getToken(ifccParser.CHAR, 0); }
		public TypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type; }
	}

	public final TypeContext type() throws RecognitionException {
		TypeContext _localctx = new TypeContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_type);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(203);
			_la = _input.LA(1);
			if ( !(_la==INT || _la==CHAR) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
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
		case 15:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expression_sempred(ExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 9);
		case 1:
			return precpred(_ctx, 7);
		case 2:
			return precpred(_ctx, 6);
		case 3:
			return precpred(_ctx, 5);
		case 4:
			return precpred(_ctx, 4);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3&\u00d0\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\3\2\3\2\3\3\7\3(\n\3\f\3\16\3+\13\3\3\4\3\4\5\4/\n\4\3\4\3\4\3\4\5\4"+
		"\64\n\4\3\4\3\4\3\4\3\5\3\5\7\5;\n\5\f\5\16\5>\13\5\3\5\3\5\3\6\3\6\3"+
		"\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\5\6Q\n\6\3\7\3\7\3"+
		"\b\3\b\3\b\7\bX\n\b\f\b\16\b[\13\b\3\t\3\t\3\t\3\n\3\n\3\n\3\n\7\nd\n"+
		"\n\f\n\16\ng\13\n\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\5\13q\n\13\3"+
		"\f\3\f\3\f\3\r\3\r\3\r\3\r\3\r\3\r\5\r|\n\r\3\r\5\r\177\n\r\3\16\3\16"+
		"\3\16\3\16\5\16\u0085\n\16\3\17\3\17\3\17\3\17\3\17\3\17\5\17\u008d\n"+
		"\17\3\20\3\20\3\20\3\20\5\20\u0093\n\20\3\20\3\20\3\20\5\20\u0098\n\20"+
		"\3\20\3\20\3\20\5\20\u009d\n\20\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21"+
		"\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\7\21\u00b0\n\21\f\21\16"+
		"\21\u00b3\13\21\5\21\u00b5\n\21\3\21\5\21\u00b8\n\21\3\21\3\21\3\21\3"+
		"\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\7\21\u00c9"+
		"\n\21\f\21\16\21\u00cc\13\21\3\22\3\22\3\22\2\3 \23\2\4\6\b\n\f\16\20"+
		"\22\24\26\30\32\34\36 \"\2\t\3\2\22\23\3\2\17\21\4\2\22\22\24\24\3\2\25"+
		"\27\3\2\30\33\3\2\34\35\3\2#$\2\u00e0\2$\3\2\2\2\4)\3\2\2\2\6.\3\2\2\2"+
		"\b8\3\2\2\2\nP\3\2\2\2\fR\3\2\2\2\16T\3\2\2\2\20\\\3\2\2\2\22_\3\2\2\2"+
		"\24p\3\2\2\2\26r\3\2\2\2\30u\3\2\2\2\32\u0080\3\2\2\2\34\u0086\3\2\2\2"+
		"\36\u008e\3\2\2\2 \u00b7\3\2\2\2\"\u00cd\3\2\2\2$%\5\4\3\2%\3\3\2\2\2"+
		"&(\5\6\4\2\'&\3\2\2\2(+\3\2\2\2)\'\3\2\2\2)*\3\2\2\2*\5\3\2\2\2+)\3\2"+
		"\2\2,/\5\"\22\2-/\7\3\2\2.,\3\2\2\2.-\3\2\2\2/\60\3\2\2\2\60\61\7%\2\2"+
		"\61\63\7\4\2\2\62\64\5\16\b\2\63\62\3\2\2\2\63\64\3\2\2\2\64\65\3\2\2"+
		"\2\65\66\7\5\2\2\66\67\5\b\5\2\67\7\3\2\2\28<\7\6\2\29;\5\n\6\2:9\3\2"+
		"\2\2;>\3\2\2\2<:\3\2\2\2<=\3\2\2\2=?\3\2\2\2><\3\2\2\2?@\7\7\2\2@\t\3"+
		"\2\2\2AB\5\22\n\2BC\7\b\2\2CQ\3\2\2\2DE\5\24\13\2EF\7\b\2\2FQ\3\2\2\2"+
		"GH\5\26\f\2HI\7\b\2\2IQ\3\2\2\2JQ\5\30\r\2KQ\5\34\17\2LQ\5\36\20\2MN\5"+
		" \21\2NO\7\b\2\2OQ\3\2\2\2PA\3\2\2\2PD\3\2\2\2PG\3\2\2\2PJ\3\2\2\2PK\3"+
		"\2\2\2PL\3\2\2\2PM\3\2\2\2Q\13\3\2\2\2RS\7%\2\2S\r\3\2\2\2TY\5\20\t\2"+
		"UV\7\t\2\2VX\5\20\t\2WU\3\2\2\2X[\3\2\2\2YW\3\2\2\2YZ\3\2\2\2Z\17\3\2"+
		"\2\2[Y\3\2\2\2\\]\5\"\22\2]^\7%\2\2^\21\3\2\2\2_`\5\"\22\2`e\7%\2\2ab"+
		"\7\t\2\2bd\7%\2\2ca\3\2\2\2dg\3\2\2\2ec\3\2\2\2ef\3\2\2\2f\23\3\2\2\2"+
		"ge\3\2\2\2hi\5\"\22\2ij\7%\2\2jk\7\n\2\2kl\5 \21\2lq\3\2\2\2mn\7%\2\2"+
		"no\7\n\2\2oq\5 \21\2ph\3\2\2\2pm\3\2\2\2q\25\3\2\2\2rs\7\36\2\2st\5 \21"+
		"\2t\27\3\2\2\2uv\7\13\2\2vw\7\4\2\2wx\5 \21\2x{\7\5\2\2y|\5\n\6\2z|\5"+
		"\b\5\2{y\3\2\2\2{z\3\2\2\2|~\3\2\2\2}\177\5\32\16\2~}\3\2\2\2~\177\3\2"+
		"\2\2\177\31\3\2\2\2\u0080\u0084\7\f\2\2\u0081\u0085\5\n\6\2\u0082\u0085"+
		"\5\b\5\2\u0083\u0085\5\30\r\2\u0084\u0081\3\2\2\2\u0084\u0082\3\2\2\2"+
		"\u0084\u0083\3\2\2\2\u0085\33\3\2\2\2\u0086\u0087\7\r\2\2\u0087\u0088"+
		"\7\4\2\2\u0088\u0089\5 \21\2\u0089\u008c\7\5\2\2\u008a\u008d\5\n\6\2\u008b"+
		"\u008d\5\b\5\2\u008c\u008a\3\2\2\2\u008c\u008b\3\2\2\2\u008d\35\3\2\2"+
		"\2\u008e\u008f\7\16\2\2\u008f\u0092\7\4\2\2\u0090\u0093\5\n\6\2\u0091"+
		"\u0093\7\b\2\2\u0092\u0090\3\2\2\2\u0092\u0091\3\2\2\2\u0093\u0094\3\2"+
		"\2\2\u0094\u0095\5 \21\2\u0095\u0097\7\b\2\2\u0096\u0098\5\24\13\2\u0097"+
		"\u0096\3\2\2\2\u0097\u0098\3\2\2\2\u0098\u0099\3\2\2\2\u0099\u009c\7\5"+
		"\2\2\u009a\u009d\5\n\6\2\u009b\u009d\5\b\5\2\u009c\u009a\3\2\2\2\u009c"+
		"\u009b\3\2\2\2\u009d\37\3\2\2\2\u009e\u009f\b\21\1\2\u009f\u00b8\7%\2"+
		"\2\u00a0\u00b8\7\37\2\2\u00a1\u00b8\7&\2\2\u00a2\u00a3\t\2\2\2\u00a3\u00b8"+
		"\5 \21\n\u00a4\u00a5\t\2\2\2\u00a5\u00b8\5 \21\5\u00a6\u00a7\7\4\2\2\u00a7"+
		"\u00a8\5 \21\2\u00a8\u00a9\7\5\2\2\u00a9\u00b8\3\2\2\2\u00aa\u00ab\7%"+
		"\2\2\u00ab\u00b4\7\4\2\2\u00ac\u00b1\5 \21\2\u00ad\u00ae\7\t\2\2\u00ae"+
		"\u00b0\5 \21\2\u00af\u00ad\3\2\2\2\u00b0\u00b3\3\2\2\2\u00b1\u00af\3\2"+
		"\2\2\u00b1\u00b2\3\2\2\2\u00b2\u00b5\3\2\2\2\u00b3\u00b1\3\2\2\2\u00b4"+
		"\u00ac\3\2\2\2\u00b4\u00b5\3\2\2\2\u00b5\u00b6\3\2\2\2\u00b6\u00b8\7\5"+
		"\2\2\u00b7\u009e\3\2\2\2\u00b7\u00a0\3\2\2\2\u00b7\u00a1\3\2\2\2\u00b7"+
		"\u00a2\3\2\2\2\u00b7\u00a4\3\2\2\2\u00b7\u00a6\3\2\2\2\u00b7\u00aa\3\2"+
		"\2\2\u00b8\u00ca\3\2\2\2\u00b9\u00ba\f\13\2\2\u00ba\u00bb\t\3\2\2\u00bb"+
		"\u00c9\5 \21\f\u00bc\u00bd\f\t\2\2\u00bd\u00be\t\4\2\2\u00be\u00c9\5 "+
		"\21\n\u00bf\u00c0\f\b\2\2\u00c0\u00c1\t\5\2\2\u00c1\u00c9\5 \21\t\u00c2"+
		"\u00c3\f\7\2\2\u00c3\u00c4\t\6\2\2\u00c4\u00c9\5 \21\b\u00c5\u00c6\f\6"+
		"\2\2\u00c6\u00c7\t\7\2\2\u00c7\u00c9\5 \21\7\u00c8\u00b9\3\2\2\2\u00c8"+
		"\u00bc\3\2\2\2\u00c8\u00bf\3\2\2\2\u00c8\u00c2\3\2\2\2\u00c8\u00c5\3\2"+
		"\2\2\u00c9\u00cc\3\2\2\2\u00ca\u00c8\3\2\2\2\u00ca\u00cb\3\2\2\2\u00cb"+
		"!\3\2\2\2\u00cc\u00ca\3\2\2\2\u00cd\u00ce\t\b\2\2\u00ce#\3\2\2\2\26)."+
		"\63<PYep{~\u0084\u008c\u0092\u0097\u009c\u00b1\u00b4\u00b7\u00c8\u00ca";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}