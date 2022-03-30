grammar ifcc;

axiom : prog ;

prog :function* ;

function : (type|'void') IDENT '(' parameters? ')' block ;
//TODO: add void

block : '{' statement* '}' ; 

statement : declaration ';' #statement1
          | affectation ';' #statement2
          | retcode ';' #statement3 
          | ifBlock #statement4
          | whileBlock #statement5
          | forBlock #statement6
          | expression ';' #statement7;

nameFunction : IDENT ;

parameters : parameter (',' parameter)* ;

parameter : type IDENT ;

declaration : type IDENT (',' IDENT)* ;
    //        | VAR '(' declaration? ')' #functionexpr;

affectation : type IDENT '=' expression #affectation1
            | IDENT '=' expression #affectation2; 
          //  | VAR '[' expression ']' '=' expression #affectation3;

retcode : RETURN CONST #ret1
        | RETURN IDENT #ret2 ;

ifBlock : 'if' '(' expression ')' (statement | block) elseBlock? ;

elseBlock : 'else' (statement| block| ifBlock);      

whileBlock : 'while' '(' expression ')' (statement | block) ;

forBlock : 'for' '(' (init=statement | ';') (test=expression) ';' (update=affectation)? ')' (statement | block) ;
//deal with infinite loop ?

expression : IDENT #varexpr
           | CONST #constexpr
           | CHARACTER #charexpr
           | expression op=('*' | '/' | '%') expression #multplicationexpr
           | expression op=('+' | '-') expression #additiveexpr
           | expression op=('|' | '&' | '^') expression #bitsexpr
           | expression op=('<' | '<=' | '>=' | '>') expression #relationalexpr
           | expression op=('==' | '!=') expression #equalityexpr
          // | expression op=('&&' | '||') expression #logicalexpr
           | op=('-' | '!') expression #unaryexpr
           | '(' expression ')' #bracketexpr 
           | IDENT '(' (expression (',' expression)*)? ')' #functionexpr ;
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
//LVALUE : VAR ;
//VAR : [a-zA-Z_][a-zA-Z1-9_]* ;
IDENT : [a-zA-Z_][a-zA-Z1-9_]* ;
CHARACTER : '\'' .? '\'';