// Generated from c:\Users\Benoi\OneDrive\Bureau\Cours\4A\PLDcomp\tp\compiler\compiler\ifcc.g4 by ANTLR 4.8
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class ifccLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, T__18=19, T__19=20, T__20=21, T__21=22, T__22=23, RETURN=24, 
		CONST=25, COMMENT=26, DIRECTIVE=27, WS=28, INT=29, CHAR=30, VAR=31, IDENT=32, 
		CHARACTER=33;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
			"T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "T__16", 
			"T__17", "T__18", "T__19", "T__20", "T__21", "T__22", "RETURN", "CONST", 
			"COMMENT", "DIRECTIVE", "WS", "INT", "CHAR", "VAR", "IDENT", "CHARACTER"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'main'", "'('", "')'", "'{'", "'}'", "';'", "','", "'='", "'*'", 
			"'/'", "'%'", "'+'", "'-'", "'|'", "'&'", "'^'", "'<'", "'<='", "'>='", 
			"'>'", "'=='", "'!='", "'!'", "'return'", null, null, null, null, "'int'", 
			"'char'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			"RETURN", "CONST", "COMMENT", "DIRECTIVE", "WS", "INT", "CHAR", "VAR", 
			"IDENT", "CHARACTER"
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


	public ifccLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "ifcc.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2#\u00bb\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\3\2\3\2\3\2\3\2\3\2\3\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3"+
		"\7\3\b\3\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\r\3\r\3\16\3\16\3\17\3"+
		"\17\3\20\3\20\3\21\3\21\3\22\3\22\3\23\3\23\3\23\3\24\3\24\3\24\3\25\3"+
		"\25\3\26\3\26\3\26\3\27\3\27\3\27\3\30\3\30\3\31\3\31\3\31\3\31\3\31\3"+
		"\31\3\31\3\32\6\32\u0083\n\32\r\32\16\32\u0084\3\33\3\33\3\33\3\33\7\33"+
		"\u008b\n\33\f\33\16\33\u008e\13\33\3\33\3\33\3\33\3\33\3\33\3\34\3\34"+
		"\7\34\u0097\n\34\f\34\16\34\u009a\13\34\3\34\3\34\3\34\3\34\3\35\3\35"+
		"\3\35\3\35\3\36\3\36\3\36\3\36\3\37\3\37\3\37\3\37\3\37\3 \3 \3!\3!\7"+
		"!\u00b1\n!\f!\16!\u00b4\13!\3\"\3\"\5\"\u00b8\n\"\3\"\3\"\4\u008c\u0098"+
		"\2#\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35"+
		"\20\37\21!\22#\23%\24\'\25)\26+\27-\30/\31\61\32\63\33\65\34\67\359\36"+
		";\37= ?!A\"C#\3\2\6\3\2\62;\5\2\13\f\17\17\"\"\5\2C\\aac|\6\2\63;C\\a"+
		"ac|\2\u00bf\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2"+
		"\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27"+
		"\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2"+
		"\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2\2\2-\3\2\2\2"+
		"\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3\2\2\2\29\3\2"+
		"\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2\2C\3\2\2\2\3E\3\2\2\2"+
		"\5J\3\2\2\2\7L\3\2\2\2\tN\3\2\2\2\13P\3\2\2\2\rR\3\2\2\2\17T\3\2\2\2\21"+
		"V\3\2\2\2\23X\3\2\2\2\25Z\3\2\2\2\27\\\3\2\2\2\31^\3\2\2\2\33`\3\2\2\2"+
		"\35b\3\2\2\2\37d\3\2\2\2!f\3\2\2\2#h\3\2\2\2%j\3\2\2\2\'m\3\2\2\2)p\3"+
		"\2\2\2+r\3\2\2\2-u\3\2\2\2/x\3\2\2\2\61z\3\2\2\2\63\u0082\3\2\2\2\65\u0086"+
		"\3\2\2\2\67\u0094\3\2\2\29\u009f\3\2\2\2;\u00a3\3\2\2\2=\u00a7\3\2\2\2"+
		"?\u00ac\3\2\2\2A\u00ae\3\2\2\2C\u00b5\3\2\2\2EF\7o\2\2FG\7c\2\2GH\7k\2"+
		"\2HI\7p\2\2I\4\3\2\2\2JK\7*\2\2K\6\3\2\2\2LM\7+\2\2M\b\3\2\2\2NO\7}\2"+
		"\2O\n\3\2\2\2PQ\7\177\2\2Q\f\3\2\2\2RS\7=\2\2S\16\3\2\2\2TU\7.\2\2U\20"+
		"\3\2\2\2VW\7?\2\2W\22\3\2\2\2XY\7,\2\2Y\24\3\2\2\2Z[\7\61\2\2[\26\3\2"+
		"\2\2\\]\7\'\2\2]\30\3\2\2\2^_\7-\2\2_\32\3\2\2\2`a\7/\2\2a\34\3\2\2\2"+
		"bc\7~\2\2c\36\3\2\2\2de\7(\2\2e \3\2\2\2fg\7`\2\2g\"\3\2\2\2hi\7>\2\2"+
		"i$\3\2\2\2jk\7>\2\2kl\7?\2\2l&\3\2\2\2mn\7@\2\2no\7?\2\2o(\3\2\2\2pq\7"+
		"@\2\2q*\3\2\2\2rs\7?\2\2st\7?\2\2t,\3\2\2\2uv\7#\2\2vw\7?\2\2w.\3\2\2"+
		"\2xy\7#\2\2y\60\3\2\2\2z{\7t\2\2{|\7g\2\2|}\7v\2\2}~\7w\2\2~\177\7t\2"+
		"\2\177\u0080\7p\2\2\u0080\62\3\2\2\2\u0081\u0083\t\2\2\2\u0082\u0081\3"+
		"\2\2\2\u0083\u0084\3\2\2\2\u0084\u0082\3\2\2\2\u0084\u0085\3\2\2\2\u0085"+
		"\64\3\2\2\2\u0086\u0087\7\61\2\2\u0087\u0088\7,\2\2\u0088\u008c\3\2\2"+
		"\2\u0089\u008b\13\2\2\2\u008a\u0089\3\2\2\2\u008b\u008e\3\2\2\2\u008c"+
		"\u008d\3\2\2\2\u008c\u008a\3\2\2\2\u008d\u008f\3\2\2\2\u008e\u008c\3\2"+
		"\2\2\u008f\u0090\7,\2\2\u0090\u0091\7\61\2\2\u0091\u0092\3\2\2\2\u0092"+
		"\u0093\b\33\2\2\u0093\66\3\2\2\2\u0094\u0098\7%\2\2\u0095\u0097\13\2\2"+
		"\2\u0096\u0095\3\2\2\2\u0097\u009a\3\2\2\2\u0098\u0099\3\2\2\2\u0098\u0096"+
		"\3\2\2\2\u0099\u009b\3\2\2\2\u009a\u0098\3\2\2\2\u009b\u009c\7\f\2\2\u009c"+
		"\u009d\3\2\2\2\u009d\u009e\b\34\2\2\u009e8\3\2\2\2\u009f\u00a0\t\3\2\2"+
		"\u00a0\u00a1\3\2\2\2\u00a1\u00a2\b\35\3\2\u00a2:\3\2\2\2\u00a3\u00a4\7"+
		"k\2\2\u00a4\u00a5\7p\2\2\u00a5\u00a6\7v\2\2\u00a6<\3\2\2\2\u00a7\u00a8"+
		"\7e\2\2\u00a8\u00a9\7j\2\2\u00a9\u00aa\7c\2\2\u00aa\u00ab\7t\2\2\u00ab"+
		">\3\2\2\2\u00ac\u00ad\5A!\2\u00ad@\3\2\2\2\u00ae\u00b2\t\4\2\2\u00af\u00b1"+
		"\t\5\2\2\u00b0\u00af\3\2\2\2\u00b1\u00b4\3\2\2\2\u00b2\u00b0\3\2\2\2\u00b2"+
		"\u00b3\3\2\2\2\u00b3B\3\2\2\2\u00b4\u00b2\3\2\2\2\u00b5\u00b7\7)\2\2\u00b6"+
		"\u00b8\13\2\2\2\u00b7\u00b6\3\2\2\2\u00b7\u00b8\3\2\2\2\u00b8\u00b9\3"+
		"\2\2\2\u00b9\u00ba\7)\2\2\u00baD\3\2\2\2\b\2\u0084\u008c\u0098\u00b2\u00b7"+
		"\4\b\2\2\2\3\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}