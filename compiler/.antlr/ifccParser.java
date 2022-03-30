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
		T__24=25, T__25=26, RETURN=27, CONST=28, COMMENT=29, DIRECTIVE=30, WS=31, 
		INT=32, CHAR=33, IDENT=34, CHARACTER=35;
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
			null, "'('", "')'", "'{'", "'}'", "';'", "','", "'='", "'if'", "'else'", 
			"'while'", "'for'", "'*'", "'/'", "'%'", "'+'", "'-'", "'|'", "'&'", 
			"'^'", "'<'", "'<='", "'>='", "'>'", "'=='", "'!='", "'!'", "'return'", 
			null, null, null, null, "'int'", "'char'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, "RETURN", "CONST", "COMMENT", "DIRECTIVE", "WS", "INT", 
			"CHAR", "IDENT", "CHARACTER"
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
			while (_la==INT || _la==CHAR) {
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
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode IDENT() { return getToken(ifccParser.IDENT, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
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
			setState(42);
			type();
			setState(43);
			match(IDENT);
			setState(44);
			match(T__0);
			setState(46);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==INT || _la==CHAR) {
				{
				setState(45);
				parameters();
				}
			}

			setState(48);
			match(T__1);
			setState(49);
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
			setState(51);
			match(T__2);
			setState(55);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__7) | (1L << T__9) | (1L << T__10) | (1L << RETURN) | (1L << INT) | (1L << CHAR) | (1L << IDENT))) != 0)) {
				{
				{
				setState(52);
				statement();
				}
				}
				setState(57);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(58);
			match(T__3);
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
			setState(72);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				_localctx = new Statement1Context(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(60);
				declaration();
				setState(61);
				match(T__4);
				}
				break;
			case 2:
				_localctx = new Statement2Context(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(63);
				affectation();
				setState(64);
				match(T__4);
				}
				break;
			case 3:
				_localctx = new Statement3Context(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(66);
				retcode();
				setState(67);
				match(T__4);
				}
				break;
			case 4:
				_localctx = new Statement4Context(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(69);
				ifBlock();
				}
				break;
			case 5:
				_localctx = new Statement5Context(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(70);
				whileBlock();
				}
				break;
			case 6:
				_localctx = new Statement6Context(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(71);
				forBlock();
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
			setState(74);
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
			setState(76);
			parameter();
			setState(81);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__5) {
				{
				{
				setState(77);
				match(T__5);
				setState(78);
				parameter();
				}
				}
				setState(83);
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
			setState(84);
			type();
			setState(85);
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
			setState(87);
			type();
			setState(88);
			match(IDENT);
			setState(93);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__5) {
				{
				{
				setState(89);
				match(T__5);
				setState(90);
				match(IDENT);
				}
				}
				setState(95);
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
			setState(104);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INT:
			case CHAR:
				_localctx = new Affectation1Context(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(96);
				type();
				setState(97);
				match(IDENT);
				setState(98);
				match(T__6);
				setState(99);
				expression(0);
				}
				break;
			case IDENT:
				_localctx = new Affectation2Context(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(101);
				match(IDENT);
				setState(102);
				match(T__6);
				setState(103);
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
	public static class Ret2Context extends RetcodeContext {
		public TerminalNode RETURN() { return getToken(ifccParser.RETURN, 0); }
		public TerminalNode IDENT() { return getToken(ifccParser.IDENT, 0); }
		public Ret2Context(RetcodeContext ctx) { copyFrom(ctx); }
	}
	public static class Ret1Context extends RetcodeContext {
		public TerminalNode RETURN() { return getToken(ifccParser.RETURN, 0); }
		public TerminalNode CONST() { return getToken(ifccParser.CONST, 0); }
		public Ret1Context(RetcodeContext ctx) { copyFrom(ctx); }
	}

	public final RetcodeContext retcode() throws RecognitionException {
		RetcodeContext _localctx = new RetcodeContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_retcode);
		try {
			setState(110);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				_localctx = new Ret1Context(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(106);
				match(RETURN);
				setState(107);
				match(CONST);
				}
				break;
			case 2:
				_localctx = new Ret2Context(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(108);
				match(RETURN);
				setState(109);
				match(IDENT);
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
			setState(112);
			match(T__7);
			setState(113);
			match(T__0);
			setState(114);
			expression(0);
			setState(115);
			match(T__1);
			setState(118);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__7:
			case T__9:
			case T__10:
			case RETURN:
			case INT:
			case CHAR:
			case IDENT:
				{
				setState(116);
				statement();
				}
				break;
			case T__2:
				{
				setState(117);
				block();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(121);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
			case 1:
				{
				setState(120);
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
			setState(123);
			match(T__8);
			setState(127);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				{
				setState(124);
				statement();
				}
				break;
			case 2:
				{
				setState(125);
				block();
				}
				break;
			case 3:
				{
				setState(126);
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
			setState(129);
			match(T__9);
			setState(130);
			match(T__0);
			setState(131);
			expression(0);
			setState(132);
			match(T__1);
			setState(135);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__7:
			case T__9:
			case T__10:
			case RETURN:
			case INT:
			case CHAR:
			case IDENT:
				{
				setState(133);
				statement();
				}
				break;
			case T__2:
				{
				setState(134);
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
			setState(137);
			match(T__10);
			setState(138);
			match(T__0);
			setState(141);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__7:
			case T__9:
			case T__10:
			case RETURN:
			case INT:
			case CHAR:
			case IDENT:
				{
				setState(139);
				((ForBlockContext)_localctx).init = statement();
				}
				break;
			case T__4:
				{
				setState(140);
				match(T__4);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			{
			setState(143);
			((ForBlockContext)_localctx).test = expression(0);
			}
			setState(144);
			match(T__4);
			setState(146);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << INT) | (1L << CHAR) | (1L << IDENT))) != 0)) {
				{
				setState(145);
				((ForBlockContext)_localctx).update = affectation();
				}
			}

			setState(148);
			match(T__1);
			setState(151);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__7:
			case T__9:
			case T__10:
			case RETURN:
			case INT:
			case CHAR:
			case IDENT:
				{
				setState(149);
				statement();
				}
				break;
			case T__2:
				{
				setState(150);
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
			setState(163);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IDENT:
				{
				_localctx = new VarexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(154);
				match(IDENT);
				}
				break;
			case CONST:
				{
				_localctx = new ConstexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(155);
				match(CONST);
				}
				break;
			case CHARACTER:
				{
				_localctx = new CharexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(156);
				match(CHARACTER);
				}
				break;
			case T__15:
			case T__25:
				{
				_localctx = new UnaryexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(157);
				((UnaryexprContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==T__15 || _la==T__25) ) {
					((UnaryexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(158);
				expression(2);
				}
				break;
			case T__0:
				{
				_localctx = new BracketexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(159);
				match(T__0);
				setState(160);
				expression(0);
				setState(161);
				match(T__1);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(182);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,17,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(180);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
					case 1:
						{
						_localctx = new MultplicationexprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(165);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(166);
						((MultplicationexprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__11) | (1L << T__12) | (1L << T__13))) != 0)) ) {
							((MultplicationexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(167);
						expression(8);
						}
						break;
					case 2:
						{
						_localctx = new AdditiveexprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(168);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(169);
						((AdditiveexprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__14 || _la==T__15) ) {
							((AdditiveexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(170);
						expression(7);
						}
						break;
					case 3:
						{
						_localctx = new BitsexprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(171);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(172);
						((BitsexprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__16) | (1L << T__17) | (1L << T__18))) != 0)) ) {
							((BitsexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(173);
						expression(6);
						}
						break;
					case 4:
						{
						_localctx = new RelationalexprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(174);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(175);
						((RelationalexprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__19) | (1L << T__20) | (1L << T__21) | (1L << T__22))) != 0)) ) {
							((RelationalexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(176);
						expression(5);
						}
						break;
					case 5:
						{
						_localctx = new EqualityexprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(177);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(178);
						((EqualityexprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__23 || _la==T__24) ) {
							((EqualityexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(179);
						expression(4);
						}
						break;
					}
					} 
				}
				setState(184);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,17,_ctx);
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
			setState(185);
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3%\u00be\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\3\2\3\2\3\3\7\3(\n\3\f\3\16\3+\13\3\3\4\3\4\3\4\3\4\5\4\61\n\4\3\4\3"+
		"\4\3\4\3\5\3\5\7\58\n\5\f\5\16\5;\13\5\3\5\3\5\3\6\3\6\3\6\3\6\3\6\3\6"+
		"\3\6\3\6\3\6\3\6\3\6\3\6\5\6K\n\6\3\7\3\7\3\b\3\b\3\b\7\bR\n\b\f\b\16"+
		"\bU\13\b\3\t\3\t\3\t\3\n\3\n\3\n\3\n\7\n^\n\n\f\n\16\na\13\n\3\13\3\13"+
		"\3\13\3\13\3\13\3\13\3\13\3\13\5\13k\n\13\3\f\3\f\3\f\3\f\5\fq\n\f\3\r"+
		"\3\r\3\r\3\r\3\r\3\r\5\ry\n\r\3\r\5\r|\n\r\3\16\3\16\3\16\3\16\5\16\u0082"+
		"\n\16\3\17\3\17\3\17\3\17\3\17\3\17\5\17\u008a\n\17\3\20\3\20\3\20\3\20"+
		"\5\20\u0090\n\20\3\20\3\20\3\20\5\20\u0095\n\20\3\20\3\20\3\20\5\20\u009a"+
		"\n\20\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\5\21\u00a6\n\21"+
		"\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21"+
		"\3\21\7\21\u00b7\n\21\f\21\16\21\u00ba\13\21\3\22\3\22\3\22\2\3 \23\2"+
		"\4\6\b\n\f\16\20\22\24\26\30\32\34\36 \"\2\t\4\2\22\22\34\34\3\2\16\20"+
		"\3\2\21\22\3\2\23\25\3\2\26\31\3\2\32\33\3\2\"#\2\u00c9\2$\3\2\2\2\4)"+
		"\3\2\2\2\6,\3\2\2\2\b\65\3\2\2\2\nJ\3\2\2\2\fL\3\2\2\2\16N\3\2\2\2\20"+
		"V\3\2\2\2\22Y\3\2\2\2\24j\3\2\2\2\26p\3\2\2\2\30r\3\2\2\2\32}\3\2\2\2"+
		"\34\u0083\3\2\2\2\36\u008b\3\2\2\2 \u00a5\3\2\2\2\"\u00bb\3\2\2\2$%\5"+
		"\4\3\2%\3\3\2\2\2&(\5\6\4\2\'&\3\2\2\2(+\3\2\2\2)\'\3\2\2\2)*\3\2\2\2"+
		"*\5\3\2\2\2+)\3\2\2\2,-\5\"\22\2-.\7$\2\2.\60\7\3\2\2/\61\5\16\b\2\60"+
		"/\3\2\2\2\60\61\3\2\2\2\61\62\3\2\2\2\62\63\7\4\2\2\63\64\5\b\5\2\64\7"+
		"\3\2\2\2\659\7\5\2\2\668\5\n\6\2\67\66\3\2\2\28;\3\2\2\29\67\3\2\2\29"+
		":\3\2\2\2:<\3\2\2\2;9\3\2\2\2<=\7\6\2\2=\t\3\2\2\2>?\5\22\n\2?@\7\7\2"+
		"\2@K\3\2\2\2AB\5\24\13\2BC\7\7\2\2CK\3\2\2\2DE\5\26\f\2EF\7\7\2\2FK\3"+
		"\2\2\2GK\5\30\r\2HK\5\34\17\2IK\5\36\20\2J>\3\2\2\2JA\3\2\2\2JD\3\2\2"+
		"\2JG\3\2\2\2JH\3\2\2\2JI\3\2\2\2K\13\3\2\2\2LM\7$\2\2M\r\3\2\2\2NS\5\20"+
		"\t\2OP\7\b\2\2PR\5\20\t\2QO\3\2\2\2RU\3\2\2\2SQ\3\2\2\2ST\3\2\2\2T\17"+
		"\3\2\2\2US\3\2\2\2VW\5\"\22\2WX\7$\2\2X\21\3\2\2\2YZ\5\"\22\2Z_\7$\2\2"+
		"[\\\7\b\2\2\\^\7$\2\2][\3\2\2\2^a\3\2\2\2_]\3\2\2\2_`\3\2\2\2`\23\3\2"+
		"\2\2a_\3\2\2\2bc\5\"\22\2cd\7$\2\2de\7\t\2\2ef\5 \21\2fk\3\2\2\2gh\7$"+
		"\2\2hi\7\t\2\2ik\5 \21\2jb\3\2\2\2jg\3\2\2\2k\25\3\2\2\2lm\7\35\2\2mq"+
		"\7\36\2\2no\7\35\2\2oq\7$\2\2pl\3\2\2\2pn\3\2\2\2q\27\3\2\2\2rs\7\n\2"+
		"\2st\7\3\2\2tu\5 \21\2ux\7\4\2\2vy\5\n\6\2wy\5\b\5\2xv\3\2\2\2xw\3\2\2"+
		"\2y{\3\2\2\2z|\5\32\16\2{z\3\2\2\2{|\3\2\2\2|\31\3\2\2\2}\u0081\7\13\2"+
		"\2~\u0082\5\n\6\2\177\u0082\5\b\5\2\u0080\u0082\5\30\r\2\u0081~\3\2\2"+
		"\2\u0081\177\3\2\2\2\u0081\u0080\3\2\2\2\u0082\33\3\2\2\2\u0083\u0084"+
		"\7\f\2\2\u0084\u0085\7\3\2\2\u0085\u0086\5 \21\2\u0086\u0089\7\4\2\2\u0087"+
		"\u008a\5\n\6\2\u0088\u008a\5\b\5\2\u0089\u0087\3\2\2\2\u0089\u0088\3\2"+
		"\2\2\u008a\35\3\2\2\2\u008b\u008c\7\r\2\2\u008c\u008f\7\3\2\2\u008d\u0090"+
		"\5\n\6\2\u008e\u0090\7\7\2\2\u008f\u008d\3\2\2\2\u008f\u008e\3\2\2\2\u0090"+
		"\u0091\3\2\2\2\u0091\u0092\5 \21\2\u0092\u0094\7\7\2\2\u0093\u0095\5\24"+
		"\13\2\u0094\u0093\3\2\2\2\u0094\u0095\3\2\2\2\u0095\u0096\3\2\2\2\u0096"+
		"\u0099\7\4\2\2\u0097\u009a\5\n\6\2\u0098\u009a\5\b\5\2\u0099\u0097\3\2"+
		"\2\2\u0099\u0098\3\2\2\2\u009a\37\3\2\2\2\u009b\u009c\b\21\1\2\u009c\u00a6"+
		"\7$\2\2\u009d\u00a6\7\36\2\2\u009e\u00a6\7%\2\2\u009f\u00a0\t\2\2\2\u00a0"+
		"\u00a6\5 \21\4\u00a1\u00a2\7\3\2\2\u00a2\u00a3\5 \21\2\u00a3\u00a4\7\4"+
		"\2\2\u00a4\u00a6\3\2\2\2\u00a5\u009b\3\2\2\2\u00a5\u009d\3\2\2\2\u00a5"+
		"\u009e\3\2\2\2\u00a5\u009f\3\2\2\2\u00a5\u00a1\3\2\2\2\u00a6\u00b8\3\2"+
		"\2\2\u00a7\u00a8\f\t\2\2\u00a8\u00a9\t\3\2\2\u00a9\u00b7\5 \21\n\u00aa"+
		"\u00ab\f\b\2\2\u00ab\u00ac\t\4\2\2\u00ac\u00b7\5 \21\t\u00ad\u00ae\f\7"+
		"\2\2\u00ae\u00af\t\5\2\2\u00af\u00b7\5 \21\b\u00b0\u00b1\f\6\2\2\u00b1"+
		"\u00b2\t\6\2\2\u00b2\u00b7\5 \21\7\u00b3\u00b4\f\5\2\2\u00b4\u00b5\t\7"+
		"\2\2\u00b5\u00b7\5 \21\6\u00b6\u00a7\3\2\2\2\u00b6\u00aa\3\2\2\2\u00b6"+
		"\u00ad\3\2\2\2\u00b6\u00b0\3\2\2\2\u00b6\u00b3\3\2\2\2\u00b7\u00ba\3\2"+
		"\2\2\u00b8\u00b6\3\2\2\2\u00b8\u00b9\3\2\2\2\u00b9!\3\2\2\2\u00ba\u00b8"+
		"\3\2\2\2\u00bb\u00bc\t\b\2\2\u00bc#\3\2\2\2\24)\609JS_jpx{\u0081\u0089"+
		"\u008f\u0094\u0099\u00a5\u00b6\u00b8";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}