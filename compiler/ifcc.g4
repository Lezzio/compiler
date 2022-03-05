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

affectation : type VAR '=' VAR 
            | type VAR '=' CONST
            | VAR '=' VAR
            | VAR '=' CONST ;

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