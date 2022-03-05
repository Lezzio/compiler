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
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, RETURN=8, CONST=9, 
		COMMENT=10, DIRECTIVE=11, WS=12, INT=13, VAR=14, IDENT=15;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "RETURN", "CONST", 
			"COMMENT", "DIRECTIVE", "WS", "INT", "VAR", "IDENT"
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\21h\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\3\2\3\2\3\2\3\2\3\2"+
		"\3\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\t\3\t\3\t\3\t\3\t\3"+
		"\t\3\t\3\n\6\n;\n\n\r\n\16\n<\3\13\3\13\3\13\3\13\7\13C\n\13\f\13\16\13"+
		"F\13\13\3\13\3\13\3\13\3\13\3\13\3\f\3\f\7\fO\n\f\f\f\16\fR\13\f\3\f\3"+
		"\f\3\f\3\f\3\r\3\r\3\r\3\r\3\16\3\16\3\16\3\16\3\17\3\17\3\20\3\20\7\20"+
		"d\n\20\f\20\16\20g\13\20\4DP\2\21\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23"+
		"\13\25\f\27\r\31\16\33\17\35\20\37\21\3\2\6\3\2\62;\5\2\13\f\17\17\"\""+
		"\5\2C\\aac|\6\2\63;C\\aac|\2k\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t"+
		"\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2"+
		"\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2"+
		"\37\3\2\2\2\3!\3\2\2\2\5&\3\2\2\2\7(\3\2\2\2\t*\3\2\2\2\13,\3\2\2\2\r"+
		".\3\2\2\2\17\60\3\2\2\2\21\62\3\2\2\2\23:\3\2\2\2\25>\3\2\2\2\27L\3\2"+
		"\2\2\31W\3\2\2\2\33[\3\2\2\2\35_\3\2\2\2\37a\3\2\2\2!\"\7o\2\2\"#\7c\2"+
		"\2#$\7k\2\2$%\7p\2\2%\4\3\2\2\2&\'\7*\2\2\'\6\3\2\2\2()\7+\2\2)\b\3\2"+
		"\2\2*+\7}\2\2+\n\3\2\2\2,-\7\177\2\2-\f\3\2\2\2./\7=\2\2/\16\3\2\2\2\60"+
		"\61\7?\2\2\61\20\3\2\2\2\62\63\7t\2\2\63\64\7g\2\2\64\65\7v\2\2\65\66"+
		"\7w\2\2\66\67\7t\2\2\678\7p\2\28\22\3\2\2\29;\t\2\2\2:9\3\2\2\2;<\3\2"+
		"\2\2<:\3\2\2\2<=\3\2\2\2=\24\3\2\2\2>?\7\61\2\2?@\7,\2\2@D\3\2\2\2AC\13"+
		"\2\2\2BA\3\2\2\2CF\3\2\2\2DE\3\2\2\2DB\3\2\2\2EG\3\2\2\2FD\3\2\2\2GH\7"+
		",\2\2HI\7\61\2\2IJ\3\2\2\2JK\b\13\2\2K\26\3\2\2\2LP\7%\2\2MO\13\2\2\2"+
		"NM\3\2\2\2OR\3\2\2\2PQ\3\2\2\2PN\3\2\2\2QS\3\2\2\2RP\3\2\2\2ST\7\f\2\2"+
		"TU\3\2\2\2UV\b\f\2\2V\30\3\2\2\2WX\t\3\2\2XY\3\2\2\2YZ\b\r\3\2Z\32\3\2"+
		"\2\2[\\\7k\2\2\\]\7p\2\2]^\7v\2\2^\34\3\2\2\2_`\5\37\20\2`\36\3\2\2\2"+
		"ae\t\4\2\2bd\t\5\2\2cb\3\2\2\2dg\3\2\2\2ec\3\2\2\2ef\3\2\2\2f \3\2\2\2"+
		"ge\3\2\2\2\7\2<DPe\4\b\2\2\2\3\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}