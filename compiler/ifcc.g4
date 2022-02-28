grammar ifcc;

axiom : prog ;

block : '{' statements '}' ;

prog : INT 'main' '(' ')' block ;

statements : statement
           | statement statements ;

statement : declaration ';'
          | affectation ';'
          | retcode ';' ;

declaration : INT VAR ;
affectation : VAR '=' CONST ;
retcode : RETURN CONST ;

RETURN : 'return' ;
CONST : [0-9]+ ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
INT : 'int' ;
VAR : IDENT ;
IDENT : [a-zA-Z_][a-zA-Z1-9_]* ;


