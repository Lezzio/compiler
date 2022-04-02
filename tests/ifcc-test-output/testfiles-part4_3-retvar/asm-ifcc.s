going to L function :main
About to add symbol name = main

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
------------------------------------------------------------------------------------------------------------
Added symbol finished
Scope is = main_1
Scope is = main_1
About to L block
 DEF AFFECTATION L 
About to add symbol name = variable

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
------------------------------------------------------------------------------------------------------------
Scope is = main_1
Added symbol finished
 POINT #1 
Scope is = main_1
 POINT #2 
Scope is = main_1
code = main_1_variable

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  4  ;  !tmp0  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  variable  ;  main_1  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
 POINT #3 
 END DEF AFFECTATION L 
Scope is = main_1
code = main_1_variable

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  4  ;  !tmp0  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  variable  ;  main_1  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
Scope is = main_1
end L of function :main
.text
.globl	main
 main: 
.main#0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
  subq $16, %rsp
IR reg to asm
reg = !tmp0
code = main_1_!tmp0

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  8  ;  !retvalue  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  variable  ;  main_1  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
   movl $10, -4(%rbp)
Scope is = main_0
code = main_0_variable

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  8  ;  !retvalue  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  variable  ;  main_1  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
THE SYMBOL IS NULL
