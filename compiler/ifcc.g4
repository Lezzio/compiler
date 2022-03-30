grammar ifcc;

axiom : prog ;

prog : INT 'main' '(' ')' block ;

block : '{' statement* '}' ; 

statement : declaration ';' #statement1
          | affectation ';' #statement2
          | retcode ';' #statement3 
          | ifBlock #statement4
          | whileBlock #statement5
          | forBlock #statement6;

declaration : type VAR (',' VAR)* ;
    //        | VAR '(' declaration? ')' #functionexpr;

affectation : type VAR '=' expression #affectation1
            | VAR '=' expression #affectation2; 
          //  | VAR '[' expression ']' '=' expression #affectation3;

retcode : RETURN CONST #ret1
        | RETURN VAR #ret2 ;

ifBlock : 'if' '(' expression ')' (statement | block) elseBlock? ;

elseBlock : 'else' (statement| block| ifBlock);      

whileBlock : 'while' '(' expression ')' (statement | block) ;

forBlock : 'for' '(' (init=statement | ';') (test=expression) ';' (update=affectation)? ')' (statement | block) ;
//deal with infinite loop ?

expression : VAR #varexpr
           | CONST #constexpr
           | CHARACTER #charexpr
           | expression op=('*' | '/' | '%') expression #multplicationexpr
           | expression op=('+' | '-') expression #additiveexpr
           | expression op=('|' | '&' | '^') expression #bitsexpr
           | expression op=('<' | '<=' | '>=' | '>') expression #relationalexpr
           | expression op=('==' | '!=') expression #equalityexpr
          // | expression op=('&&' | '||') expression #logicalexpr
           | op=('-' | '!') expression #unaryexpr
           | '(' expression ')' #bracketexpr ;
	  // | VAR '[' expression ']' #arrayexpr;
	  // | ('-' | '!')? (CONST | CHAR | VAR)	#literalexpr;

type : INT | CHAR ;

RETURN : 'return' ;
CONST : [0-9]+ ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
INT : 'int' ;
CHAR : 'char' ;
VAR : IDENT ;
IDENT : [a-zA-Z_][a-zA-Z1-9_]* ;
CHARACTER : '\'' .? '\'';