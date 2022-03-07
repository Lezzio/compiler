// Generated from /home/maxime/doss/compiler/compiler/ifcc.g4 by ANTLR 4.8
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
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, RETURN=8, CONST=9, 
		COMMENT=10, DIRECTIVE=11, WS=12, INT=13, VAR=14, IDENT=15;
	public static final int
		RULE_axiom = 0, RULE_prog = 1, RULE_block = 2, RULE_statements = 3, RULE_statement = 4, 
		RULE_declaration = 5, RULE_affectation = 6, RULE_retcode = 7, RULE_type = 8;
	private static String[] makeRuleNames() {
		return new String[] {
			"axiom", "prog", "block", "statements", "statement", "declaration", "affectation", 
			"retcode", "type"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'main'", "'('", "')'", "'{'", "'}'", "';'", "'='", "'return'", 
			null, null, null, null, "'int'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, "RETURN", "CONST", "COMMENT", 
			"DIRECTIVE", "WS", "INT", "VAR", "IDENT"
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
			setState(18);
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
			setState(20);
			match(INT);
			setState(21);
			match(T__0);
			setState(22);
			match(T__1);
			setState(23);
			match(T__2);
			setState(24);
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
			setState(26);
			match(T__3);
			setState(27);
			statements();
			setState(28);
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
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public StatementsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statements; }
	}

	public final StatementsContext statements() throws RecognitionException {
		StatementsContext _localctx = new StatementsContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_statements);
		try {
			setState(34);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(30);
				statement();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(31);
				statement();
				setState(32);
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
		public DeclarationContext declaration() {
			return getRuleContext(DeclarationContext.class,0);
		}
		public AffectationContext affectation() {
			return getRuleContext(AffectationContext.class,0);
		}
		public RetcodeContext retcode() {
			return getRuleContext(RetcodeContext.class,0);
		}
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_statement);
		try {
			setState(45);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(36);
				declaration();
				setState(37);
				match(T__5);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(39);
				affectation();
				setState(40);
				match(T__5);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(42);
				retcode();
				setState(43);
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
		public TerminalNode VAR() { return getToken(ifccParser.VAR, 0); }
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
			setState(47);
			type();
			setState(48);
			match(VAR);
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
	public static class Cas3Context extends AffectationContext {
		public List<TerminalNode> VAR() { return getTokens(ifccParser.VAR); }
		public TerminalNode VAR(int i) {
			return getToken(ifccParser.VAR, i);
		}
		public Cas3Context(AffectationContext ctx) { copyFrom(ctx); }
	}
	public static class Cas4Context extends AffectationContext {
		public TerminalNode VAR() { return getToken(ifccParser.VAR, 0); }
		public TerminalNode CONST() { return getToken(ifccParser.CONST, 0); }
		public Cas4Context(AffectationContext ctx) { copyFrom(ctx); }
	}
	public static class Cas1Context extends AffectationContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public List<TerminalNode> VAR() { return getTokens(ifccParser.VAR); }
		public TerminalNode VAR(int i) {
			return getToken(ifccParser.VAR, i);
		}
		public Cas1Context(AffectationContext ctx) { copyFrom(ctx); }
	}
	public static class Cas2Context extends AffectationContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode VAR() { return getToken(ifccParser.VAR, 0); }
		public TerminalNode CONST() { return getToken(ifccParser.CONST, 0); }
		public Cas2Context(AffectationContext ctx) { copyFrom(ctx); }
	}

	public final AffectationContext affectation() throws RecognitionException {
		AffectationContext _localctx = new AffectationContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_affectation);
		try {
			setState(66);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				_localctx = new Cas1Context(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(50);
				type();
				setState(51);
				match(VAR);
				setState(52);
				match(T__6);
				setState(53);
				match(VAR);
				}
				break;
			case 2:
				_localctx = new Cas2Context(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(55);
				type();
				setState(56);
				match(VAR);
				setState(57);
				match(T__6);
				setState(58);
				match(CONST);
				}
				break;
			case 3:
				_localctx = new Cas3Context(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(60);
				match(VAR);
				setState(61);
				match(T__6);
				setState(62);
				match(VAR);
				}
				break;
			case 4:
				_localctx = new Cas4Context(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(63);
				match(VAR);
				setState(64);
				match(T__6);
				setState(65);
				match(CONST);
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
		public TerminalNode RETURN() { return getToken(ifccParser.RETURN, 0); }
		public TerminalNode CONST() { return getToken(ifccParser.CONST, 0); }
		public TerminalNode VAR() { return getToken(ifccParser.VAR, 0); }
		public RetcodeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_retcode; }
	}

	public final RetcodeContext retcode() throws RecognitionException {
		RetcodeContext _localctx = new RetcodeContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_retcode);
		try {
			setState(72);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(68);
				match(RETURN);
				setState(69);
				match(CONST);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(70);
				match(RETURN);
				setState(71);
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

	public static class TypeContext extends ParserRuleContext {
		public TerminalNode INT() { return getToken(ifccParser.INT, 0); }
		public TypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type; }
	}

	public final TypeContext type() throws RecognitionException {
		TypeContext _localctx = new TypeContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_type);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(74);
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

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\21O\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\3\2\3\2\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\3\4\3\4\3\4\3\4\3\5\3\5\3\5\3\5\5\5%\n\5\3\6\3\6"+
		"\3\6\3\6\3\6\3\6\3\6\3\6\3\6\5\6\60\n\6\3\7\3\7\3\7\3\b\3\b\3\b\3\b\3"+
		"\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\5\bE\n\b\3\t\3\t\3\t\3"+
		"\t\5\tK\n\t\3\n\3\n\3\n\2\2\13\2\4\6\b\n\f\16\20\22\2\2\2L\2\24\3\2\2"+
		"\2\4\26\3\2\2\2\6\34\3\2\2\2\b$\3\2\2\2\n/\3\2\2\2\f\61\3\2\2\2\16D\3"+
		"\2\2\2\20J\3\2\2\2\22L\3\2\2\2\24\25\5\4\3\2\25\3\3\2\2\2\26\27\7\17\2"+
		"\2\27\30\7\3\2\2\30\31\7\4\2\2\31\32\7\5\2\2\32\33\5\6\4\2\33\5\3\2\2"+
		"\2\34\35\7\6\2\2\35\36\5\b\5\2\36\37\7\7\2\2\37\7\3\2\2\2 %\5\n\6\2!\""+
		"\5\n\6\2\"#\5\b\5\2#%\3\2\2\2$ \3\2\2\2$!\3\2\2\2%\t\3\2\2\2&\'\5\f\7"+
		"\2\'(\7\b\2\2(\60\3\2\2\2)*\5\16\b\2*+\7\b\2\2+\60\3\2\2\2,-\5\20\t\2"+
		"-.\7\b\2\2.\60\3\2\2\2/&\3\2\2\2/)\3\2\2\2/,\3\2\2\2\60\13\3\2\2\2\61"+
		"\62\5\22\n\2\62\63\7\20\2\2\63\r\3\2\2\2\64\65\5\22\n\2\65\66\7\20\2\2"+
		"\66\67\7\t\2\2\678\7\20\2\28E\3\2\2\29:\5\22\n\2:;\7\20\2\2;<\7\t\2\2"+
		"<=\7\13\2\2=E\3\2\2\2>?\7\20\2\2?@\7\t\2\2@E\7\20\2\2AB\7\20\2\2BC\7\t"+
		"\2\2CE\7\13\2\2D\64\3\2\2\2D9\3\2\2\2D>\3\2\2\2DA\3\2\2\2E\17\3\2\2\2"+
		"FG\7\n\2\2GK\7\13\2\2HI\7\n\2\2IK\7\20\2\2JF\3\2\2\2JH\3\2\2\2K\21\3\2"+
		"\2\2LM\7\17\2\2M\23\3\2\2\2\6$/DJ";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}