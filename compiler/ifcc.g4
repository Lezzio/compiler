grammar ifcc;

axiom : prog ;

prog : INT 'main' '(' ')' block ;

block : '{' statements '}' ; 

statements : statement
           | statement statements ;

statement : declaration ';'
          | affectation ';' 
          | retcode ';' ;

declaration : type VAR ;

affectation : type VAR '=' VAR # cas1 
            | type VAR '=' CONST # cas2
            | VAR '=' VAR # cas3
            | VAR '=' CONST # cas4 
            ;

retcode : RETURN CONST
        | RETURN VAR ;

type : INT ;

RETURN : 'return' ;
CONST : [0-9]+ ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
INT : 'int' ;
VAR : IDENT ;
IDENT : [a-zA-Z_][a-zA-Z1-9_]* ;