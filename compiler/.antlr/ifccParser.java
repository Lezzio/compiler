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
		WS=32, INT=33, CHAR=34, LVALUE=35, VAR=36, IDENT=37, CHARACTER=38;
	public static final int
		RULE_axiom = 0, RULE_prog = 1, RULE_block = 2, RULE_statement = 3, RULE_declaration = 4, 
		RULE_affectation = 5, RULE_retcode = 6, RULE_ifBlock = 7, RULE_elseBlock = 8, 
		RULE_whileBlock = 9, RULE_forBlock = 10, RULE_expression = 11, RULE_type = 12;
	private static String[] makeRuleNames() {
		return new String[] {
			"axiom", "prog", "block", "statement", "declaration", "affectation", 
			"retcode", "ifBlock", "elseBlock", "whileBlock", "forBlock", "expression", 
			"type"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'main'", "'('", "')'", "'{'", "'}'", "';'", "','", "'='", "'if'", 
			"'else'", "'while'", "'for'", "'*'", "'/'", "'%'", "'+'", "'-'", "'|'", 
			"'&'", "'^'", "'<'", "'<='", "'>='", "'>'", "'=='", "'!='", "'!'", "'return'", 
			null, null, null, null, "'int'", "'char'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, "RETURN", "CONST", "COMMENT", "DIRECTIVE", "WS", 
			"INT", "CHAR", "LVALUE", "VAR", "IDENT", "CHARACTER"
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
			setState(26);
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
			setState(28);
			match(INT);
			setState(29);
			match(T__0);
			setState(30);
			match(T__1);
			setState(31);
			match(T__2);
			setState(32);
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
		enterRule(_localctx, 4, RULE_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(34);
			match(T__3);
			setState(38);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__8) | (1L << T__10) | (1L << T__11) | (1L << RETURN) | (1L << INT) | (1L << CHAR) | (1L << VAR))) != 0)) {
				{
				{
				setState(35);
				statement();
				}
				}
				setState(40);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(41);
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
		enterRule(_localctx, 6, RULE_statement);
		try {
			setState(55);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				_localctx = new Statement1Context(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(43);
				declaration();
				setState(44);
				match(T__5);
				}
				break;
			case 2:
				_localctx = new Statement2Context(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(46);
				affectation();
				setState(47);
				match(T__5);
				}
				break;
			case 3:
				_localctx = new Statement3Context(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(49);
				retcode();
				setState(50);
				match(T__5);
				}
				break;
			case 4:
				_localctx = new Statement4Context(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(52);
				ifBlock();
				}
				break;
			case 5:
				_localctx = new Statement5Context(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(53);
				whileBlock();
				}
				break;
			case 6:
				_localctx = new Statement6Context(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(54);
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

	public static class DeclarationContext extends ParserRuleContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public List<TerminalNode> VAR() { return getTokens(ifccParser.VAR); }
		public TerminalNode VAR(int i) {
			return getToken(ifccParser.VAR, i);
		}
		public DeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration; }
	}

	public final DeclarationContext declaration() throws RecognitionException {
		DeclarationContext _localctx = new DeclarationContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(57);
			type();
			setState(58);
			match(VAR);
			setState(63);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__6) {
				{
				{
				setState(59);
				match(T__6);
				setState(60);
				match(VAR);
				}
				}
				setState(65);
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
		public TerminalNode VAR() { return getToken(ifccParser.VAR, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Affectation2Context(AffectationContext ctx) { copyFrom(ctx); }
	}
	public static class Affectation1Context extends AffectationContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode VAR() { return getToken(ifccParser.VAR, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Affectation1Context(AffectationContext ctx) { copyFrom(ctx); }
	}

	public final AffectationContext affectation() throws RecognitionException {
		AffectationContext _localctx = new AffectationContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_affectation);
		try {
			setState(74);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INT:
			case CHAR:
				_localctx = new Affectation1Context(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(66);
				type();
				setState(67);
				match(VAR);
				setState(68);
				match(T__7);
				setState(69);
				expression(0);
				}
				break;
			case VAR:
				_localctx = new Affectation2Context(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(71);
				match(VAR);
				setState(72);
				match(T__7);
				setState(73);
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
		enterRule(_localctx, 12, RULE_retcode);
		try {
			setState(80);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				_localctx = new Ret1Context(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(76);
				match(RETURN);
				setState(77);
				match(CONST);
				}
				break;
			case 2:
				_localctx = new Ret2Context(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(78);
				match(RETURN);
				setState(79);
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
		enterRule(_localctx, 14, RULE_ifBlock);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(82);
			match(T__8);
			setState(83);
			match(T__1);
			setState(84);
			expression(0);
			setState(85);
			match(T__2);
			setState(88);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__8:
			case T__10:
			case T__11:
			case RETURN:
			case INT:
			case CHAR:
			case VAR:
				{
				setState(86);
				statement();
				}
				break;
			case T__3:
				{
				setState(87);
				block();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(91);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				{
				setState(90);
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
		enterRule(_localctx, 16, RULE_elseBlock);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(93);
			match(T__9);
			setState(97);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				{
				setState(94);
				statement();
				}
				break;
			case 2:
				{
				setState(95);
				block();
				}
				break;
			case 3:
				{
				setState(96);
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
		enterRule(_localctx, 18, RULE_whileBlock);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(99);
			match(T__10);
			setState(100);
			match(T__1);
			setState(101);
			expression(0);
			setState(102);
			match(T__2);
			setState(105);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__8:
			case T__10:
			case T__11:
			case RETURN:
			case INT:
			case CHAR:
			case VAR:
				{
				setState(103);
				statement();
				}
				break;
			case T__3:
				{
				setState(104);
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
		enterRule(_localctx, 20, RULE_forBlock);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(107);
			match(T__11);
			setState(108);
			match(T__1);
			setState(111);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__8:
			case T__10:
			case T__11:
			case RETURN:
			case INT:
			case CHAR:
			case VAR:
				{
				setState(109);
				((ForBlockContext)_localctx).init = statement();
				}
				break;
			case T__5:
				{
				setState(110);
				match(T__5);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			{
			setState(113);
			((ForBlockContext)_localctx).test = expression(0);
			}
			setState(114);
			match(T__5);
			setState(116);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << INT) | (1L << CHAR) | (1L << VAR))) != 0)) {
				{
				setState(115);
				((ForBlockContext)_localctx).update = affectation();
				}
			}

			setState(118);
			match(T__2);
			setState(121);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__8:
			case T__10:
			case T__11:
			case RETURN:
			case INT:
			case CHAR:
			case VAR:
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
		int _startState = 22;
		enterRecursionRule(_localctx, 22, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(133);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case VAR:
				{
				_localctx = new VarexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(124);
				match(VAR);
				}
				break;
			case CONST:
				{
				_localctx = new ConstexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(125);
				match(CONST);
				}
				break;
			case CHARACTER:
				{
				_localctx = new CharexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(126);
				match(CHARACTER);
				}
				break;
			case T__16:
			case T__26:
				{
				_localctx = new UnaryexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(127);
				((UnaryexprContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==T__16 || _la==T__26) ) {
					((UnaryexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(128);
				expression(2);
				}
				break;
			case T__1:
				{
				_localctx = new BracketexprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(129);
				match(T__1);
				setState(130);
				expression(0);
				setState(131);
				match(T__2);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(152);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(150);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
					case 1:
						{
						_localctx = new MultplicationexprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(135);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(136);
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
						setState(137);
						expression(8);
						}
						break;
					case 2:
						{
						_localctx = new AdditiveexprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(138);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(139);
						((AdditiveexprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__15 || _la==T__16) ) {
							((AdditiveexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(140);
						expression(7);
						}
						break;
					case 3:
						{
						_localctx = new BitsexprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(141);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(142);
						((BitsexprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__17) | (1L << T__18) | (1L << T__19))) != 0)) ) {
							((BitsexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(143);
						expression(6);
						}
						break;
					case 4:
						{
						_localctx = new RelationalexprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(144);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(145);
						((RelationalexprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__20) | (1L << T__21) | (1L << T__22) | (1L << T__23))) != 0)) ) {
							((RelationalexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(146);
						expression(5);
						}
						break;
					case 5:
						{
						_localctx = new EqualityexprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(147);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(148);
						((EqualityexprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__24 || _la==T__25) ) {
							((EqualityexprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(149);
						expression(4);
						}
						break;
					}
					} 
				}
				setState(154);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
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
		enterRule(_localctx, 24, RULE_type);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(155);
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
		case 11:
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3(\u00a0\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\3\3\4\3\4"+
		"\7\4\'\n\4\f\4\16\4*\13\4\3\4\3\4\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5"+
		"\3\5\3\5\3\5\5\5:\n\5\3\6\3\6\3\6\3\6\7\6@\n\6\f\6\16\6C\13\6\3\7\3\7"+
		"\3\7\3\7\3\7\3\7\3\7\3\7\5\7M\n\7\3\b\3\b\3\b\3\b\5\bS\n\b\3\t\3\t\3\t"+
		"\3\t\3\t\3\t\5\t[\n\t\3\t\5\t^\n\t\3\n\3\n\3\n\3\n\5\nd\n\n\3\13\3\13"+
		"\3\13\3\13\3\13\3\13\5\13l\n\13\3\f\3\f\3\f\3\f\5\fr\n\f\3\f\3\f\3\f\5"+
		"\fw\n\f\3\f\3\f\3\f\5\f|\n\f\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\5"+
		"\r\u0088\n\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3"+
		"\r\7\r\u0099\n\r\f\r\16\r\u009c\13\r\3\16\3\16\3\16\2\3\30\17\2\4\6\b"+
		"\n\f\16\20\22\24\26\30\32\2\t\4\2\23\23\35\35\3\2\17\21\3\2\22\23\3\2"+
		"\24\26\3\2\27\32\3\2\33\34\3\2#$\2\u00ac\2\34\3\2\2\2\4\36\3\2\2\2\6$"+
		"\3\2\2\2\b9\3\2\2\2\n;\3\2\2\2\fL\3\2\2\2\16R\3\2\2\2\20T\3\2\2\2\22_"+
		"\3\2\2\2\24e\3\2\2\2\26m\3\2\2\2\30\u0087\3\2\2\2\32\u009d\3\2\2\2\34"+
		"\35\5\4\3\2\35\3\3\2\2\2\36\37\7#\2\2\37 \7\3\2\2 !\7\4\2\2!\"\7\5\2\2"+
		"\"#\5\6\4\2#\5\3\2\2\2$(\7\6\2\2%\'\5\b\5\2&%\3\2\2\2\'*\3\2\2\2(&\3\2"+
		"\2\2()\3\2\2\2)+\3\2\2\2*(\3\2\2\2+,\7\7\2\2,\7\3\2\2\2-.\5\n\6\2./\7"+
		"\b\2\2/:\3\2\2\2\60\61\5\f\7\2\61\62\7\b\2\2\62:\3\2\2\2\63\64\5\16\b"+
		"\2\64\65\7\b\2\2\65:\3\2\2\2\66:\5\20\t\2\67:\5\24\13\28:\5\26\f\29-\3"+
		"\2\2\29\60\3\2\2\29\63\3\2\2\29\66\3\2\2\29\67\3\2\2\298\3\2\2\2:\t\3"+
		"\2\2\2;<\5\32\16\2<A\7&\2\2=>\7\t\2\2>@\7&\2\2?=\3\2\2\2@C\3\2\2\2A?\3"+
		"\2\2\2AB\3\2\2\2B\13\3\2\2\2CA\3\2\2\2DE\5\32\16\2EF\7&\2\2FG\7\n\2\2"+
		"GH\5\30\r\2HM\3\2\2\2IJ\7&\2\2JK\7\n\2\2KM\5\30\r\2LD\3\2\2\2LI\3\2\2"+
		"\2M\r\3\2\2\2NO\7\36\2\2OS\7\37\2\2PQ\7\36\2\2QS\7&\2\2RN\3\2\2\2RP\3"+
		"\2\2\2S\17\3\2\2\2TU\7\13\2\2UV\7\4\2\2VW\5\30\r\2WZ\7\5\2\2X[\5\b\5\2"+
		"Y[\5\6\4\2ZX\3\2\2\2ZY\3\2\2\2[]\3\2\2\2\\^\5\22\n\2]\\\3\2\2\2]^\3\2"+
		"\2\2^\21\3\2\2\2_c\7\f\2\2`d\5\b\5\2ad\5\6\4\2bd\5\20\t\2c`\3\2\2\2ca"+
		"\3\2\2\2cb\3\2\2\2d\23\3\2\2\2ef\7\r\2\2fg\7\4\2\2gh\5\30\r\2hk\7\5\2"+
		"\2il\5\b\5\2jl\5\6\4\2ki\3\2\2\2kj\3\2\2\2l\25\3\2\2\2mn\7\16\2\2nq\7"+
		"\4\2\2or\5\b\5\2pr\7\b\2\2qo\3\2\2\2qp\3\2\2\2rs\3\2\2\2st\5\30\r\2tv"+
		"\7\b\2\2uw\5\f\7\2vu\3\2\2\2vw\3\2\2\2wx\3\2\2\2x{\7\5\2\2y|\5\b\5\2z"+
		"|\5\6\4\2{y\3\2\2\2{z\3\2\2\2|\27\3\2\2\2}~\b\r\1\2~\u0088\7&\2\2\177"+
		"\u0088\7\37\2\2\u0080\u0088\7(\2\2\u0081\u0082\t\2\2\2\u0082\u0088\5\30"+
		"\r\4\u0083\u0084\7\4\2\2\u0084\u0085\5\30\r\2\u0085\u0086\7\5\2\2\u0086"+
		"\u0088\3\2\2\2\u0087}\3\2\2\2\u0087\177\3\2\2\2\u0087\u0080\3\2\2\2\u0087"+
		"\u0081\3\2\2\2\u0087\u0083\3\2\2\2\u0088\u009a\3\2\2\2\u0089\u008a\f\t"+
		"\2\2\u008a\u008b\t\3\2\2\u008b\u0099\5\30\r\n\u008c\u008d\f\b\2\2\u008d"+
		"\u008e\t\4\2\2\u008e\u0099\5\30\r\t\u008f\u0090\f\7\2\2\u0090\u0091\t"+
		"\5\2\2\u0091\u0099\5\30\r\b\u0092\u0093\f\6\2\2\u0093\u0094\t\6\2\2\u0094"+
		"\u0099\5\30\r\7\u0095\u0096\f\5\2\2\u0096\u0097\t\7\2\2\u0097\u0099\5"+
		"\30\r\6\u0098\u0089\3\2\2\2\u0098\u008c\3\2\2\2\u0098\u008f\3\2\2\2\u0098"+
		"\u0092\3\2\2\2\u0098\u0095\3\2\2\2\u0099\u009c\3\2\2\2\u009a\u0098\3\2"+
		"\2\2\u009a\u009b\3\2\2\2\u009b\31\3\2\2\2\u009c\u009a\3\2\2\2\u009d\u009e"+
		"\t\b\2\2\u009e\33\3\2\2\2\21(9ALRZ]ckqv{\u0087\u0098\u009a";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}