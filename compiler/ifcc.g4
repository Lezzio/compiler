grammar ifcc;

axiom : prog ;

prog : INT 'main' '(' ')' block ;

block : '{' statement* '}' ; 

statement : declaration ';' #statement1
          | affectation ';' #statement2
          | retcode ';' #statement3 ;

declaration : type VAR (',' VAR)* 
            | VAR '(' declaration? ')' #functionexpr;

affectation : type VAR '=' expression #affectation1
            | VAR '=' expression #affectation2 
            | VAR '[' expression ']' '=' expression #affectation3;

retcode : RETURN CONST #ret1
        | RETURN VAR #ret2 ;

  
expression : VAR #varexpr
           | CONST #constexpr
           | CHARACTER #charexpr
           | expression op=('*' | '/' | '%') expression #multplicationexpr
           | expression op=('+' | '-') expression #additiveexpr
           | expression op=('|' | '&' | '^') expression #bitsexpr
           | expression op=('<' | '<=' | '>=' | '>') expression #relationalexpr
           | expression op=('==' | '!=') expression #equalityexpr
           | expression op=('&&' | '||') expression #logicalexpr
           | op=('-' | '!') expression #unaryexpr
           | '(' expression ')' #bracketexpr
	   | VAR '[' expression ']' #arrayexpr
	   | ('-' | '!')? (CONST | CHAR | VAR)	#literalexpr;

type : INT | CHAR ;

RETURN : 'return' ;
CONST : [0-9]+ ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
INT : 'int' ;
CHAR : 'char' ;
LVALUE : VAR ;
VAR : IDENT ;
IDENT : [a-zA-Z_][a-zA-Z1-9_]* ;
CHARACTER : '\'' .? '\'';