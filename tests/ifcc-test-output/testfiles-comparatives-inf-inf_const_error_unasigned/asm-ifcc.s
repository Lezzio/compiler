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
About to add symbol name = a

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
Scope is = main_1
Scope is = main_1
code = main_1_a

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  4  ;  !tmp0  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  a  ;  main_1  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
Scope is = main_1
code = main_1_!tmp0

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  4  ;  !tmp0  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  a  ;  main_1  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
Scope is = main_1
Scope is = main_1
code = main_1_!tmp1

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  4  ;  !tmp0  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  a  ;  main_1  ;  0  ;  0  ;  0  ;  0  | 
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
|  12  ;  !retvalue  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  a  ;  main_1  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
   movl $3, -4(%rbp)
IR reg to asm
reg = !tmp1
code = main_1_!tmp1

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  12  ;  !retvalue  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  a  ;  main_1  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
IR reg to asm
reg = a
code = main_1_a

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  12  ;  !retvalue  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  a  ;  main_1  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
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
|  12  ;  !retvalue  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  a  ;  main_1  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
   movl -1(%rbp), %eax
   cmpl -4(%rbp), %eax
    setl %al
    movzbl %al, %eax
   movl %eax, -8(%rbp)
IR reg to asm
reg = !retvalue
code = main_1_!retvalue

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  12  ;  !retvalue  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  a  ;  main_1  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
IR reg to asm
reg = !tmp1
code = main_1_!tmp1

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  12  ;  !retvalue  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  a  ;  main_1  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
   movl -8(%rbp), %eax
   movl %eax, -12(%rbp)
   jmp   .main#1
.main#1:
IR reg to asm
reg = !retvalue
code = main_1_!retvalue

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  12  ;  !retvalue  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  a  ;  main_1  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
   movl -12(%rbp), %eax
   #epilogue
Scope is = main_0
code = main_0_main

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  12  ;  !retvalue  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_1  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  a  ;  main_1  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
THE SYMBOL IS NULL
