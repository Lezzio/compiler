grammar ifcc;

axiom : prog ;

prog : INT 'main' '(' ')' block ;

block : '{' statements '}' ; 

statements : statement #statements1
           | statement statements #statements2;

statement : declaration ';' #statement1
          | affectation ';' #statement2
          | retcode ';' #statement3 ;

declaration : type variables ;

affectation : type VAR '=' VAR #affectation1
            | type VAR '=' CONST #affectation2
            | VAR '=' VAR #affectation3
            | VAR '=' CONST #affectation4 
            | type VAR '=' expression #affectation5
            | VAR '=' expression #affectation6;

retcode : RETURN CONST #ret1
        | RETURN VAR #ret2 ;

variables : VAR ',' variables #multvariables
          | VAR #variable;
  
expression : VAR #varexpr
           | CONST #constexpr
           | CHARACTER #charexpr
           | expression op=('*' | '/' | '%') expression #multplicationexpr
           | expression op=('+' | '-') expression #additiveexpr
           | expression op=('|' | '&' | '^') expression #bitsexpr
           | expression op=('<' | '<=' | '>=' | '>') expression #relationalexpr
           | expression op=('==' | '!=') expression #equalityexpr
           | op=('-' | '!') expression #unaryexpr
           | '(' expression ')' #bracketexpr;

type : INT ;

RETURN : 'return' ;
CONST : [0-9]+ ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
INT : 'int' ;
VAR : IDENT ;
IDENT : [a-zA-Z_][a-zA-Z1-9_]* ;
CHARACTER : '\'' .? '\'';