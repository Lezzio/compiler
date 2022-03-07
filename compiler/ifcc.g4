grammar ifcc;

axiom : prog ;

prog : INT 'main' '(' ')' block ;

block : '{' statements '}' ; 

statements : statement #statements1
           | statement statements #statements2;

statement : declaration ';' #statement1
          | affectation ';' #statement2
          | retcode ';' #statement3 ;

declaration : type VAR ;

<<<<<<< HEAD
affectation : type VAR '=' VAR # cas1 
            | type VAR '=' CONST # cas2
            | VAR '=' VAR # cas3
            | VAR '=' CONST # cas4 
            ;
=======
affectation : type VAR '=' VAR #affectation1
            | type VAR '=' CONST #affectation2
            | VAR '=' VAR #affectation3
            | VAR '=' CONST #affectation4 ; 
>>>>>>> 926982dc6434e97012ef64a66a1e344978a0bde7

retcode : RETURN CONST #ret1
        | RETURN VAR #ret2 ;

type : INT ;

RETURN : 'return' ;
CONST : [0-9]+ ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
INT : 'int' ;
VAR : IDENT ;
IDENT : [a-zA-Z_][a-zA-Z1-9_]* ;