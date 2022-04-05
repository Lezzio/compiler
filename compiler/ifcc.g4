grammar ifcc;

axiom : prog EOF;

prog :function* ;

function : (type|'void') IDENT '(' parameters? ')' block ;

block : '{' statement* '}' ; 

statement : declaration ';' #statement1
          | array ';' #statement10 
          | affectation ';' #statement2
          | retcode ';' #statement3 
          | ifBlock #statement4
          | whileBlock #statement5
          | forBlock #statement6
          | expression ';' #statement7
          | BREAK ';' #statement8
          | CONTINUE ';' #statement9;

nameFunction : IDENT ;

parameters : parameter (',' parameter)* ;

parameter : type IDENT ;

declaration : type IDENT (',' IDENT)*;

affectation : type IDENT '=' expression #affectation1
            | IDENT '=' expression #affectation2
            | expression '=' expression #affectation3;

array : type IDENT'[' CONST ']' #declarationArray 
      | type IDENT'[' CONST? ']' '=' '{' expression (',' expression)* '}' #affectationArray;

retcode : RETURN expression #ret1 ;

ifBlock : 'if' '(' expression ')' (statement | block) elseBlock? ;

elseBlock : 'else' (statement| block| ifBlock) ;

whileBlock : 'while' '(' expression ')' (statement | block) ;

forBlock : 'for' '(' (init=statement | ';') (test=expression) ';' (update=affectation)? ')' (statement | block) ;
//deal with infinite loop ?

expression :  '(' expression ')' #bracketexpr
           | IDENT '(' (expression (',' expression)*)? ')' #functionexpr 
           | IDENT '[' expression ']' #arrayexpr
           | IDENT #varexpr
           | CONST #constexpr
           | CHARACTER #charexpr
           | op=('-' | '!') expression #unaryexpr
           | expression op=('*' | '/' | '%') expression #multplicationexpr
           | expression op=('+' | '-') expression #additiveexpr
           | expression op=('<' | '<=' | '>=' | '>') expression #relationalexpr
           | expression op=('==' | '!=') expression #equalityexpr  
           | expression op=('|' | '&' | '^') expression #bitsexpr;

type : INT | CHAR ;

RETURN : 'return' ;
CONST : [0-9]+ ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
INT : 'int' ;
CHAR : 'char' ;
BREAK : 'break';
CONTINUE : 'continue' ;
IDENT : [a-zA-Z_][a-zA-Z1-9_]* ;
CHARACTER : '\'' .? '\'';