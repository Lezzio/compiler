going to L function :main
Entering scope
Level = 0About to add symbol name = main

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
------------------------------------------------------------------------------------------------------------
Added symbol finished
Scope is = 0 main_0
Scope is = 0 main_0
About to L block
 DEF AFFECTATION L 
About to add symbol name = a

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
------------------------------------------------------------------------------------------------------------
Scope is = 0 main_0
Added symbol finished
 POINT #1 
Scope is = 0 main_0
 POINT #2 
Scope is = 0 main_0

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  4  ;  !tmp0  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  a  ;  main_0  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
code = main_0_a
 POINT #3 
 END DEF AFFECTATION L 
Scope is = 0 main_0
Scope is = 0 main_0
Scope is = 0 main_0
 DEF AFFECTATION L 
About to add symbol name = b

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  4  ;  !tmp0  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  a  ;  main_0  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
Scope is = 0 main_0
Added symbol finished
 POINT #1 
Scope is = 0 main_0
 POINT #2 
Scope is = 0 main_0

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  4  ;  !tmp0  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  a  ;  main_0  ;  0  ;  0  ;  0  ;  0  | 
|  1  ;  b  ;  main_0  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
code = main_0_b
 POINT #3 
 END DEF AFFECTATION L 
Scope is = 0 main_0

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  4  ;  !tmp0  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  a  ;  main_0  ;  0  ;  0  ;  0  ;  0  | 
|  1  ;  b  ;  main_0  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
code = main_0_a
Scope is = 0 main_0
end L of function :main
.text
.globl	main
 main: 
.main#0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
op = 24
  subq $32, %rsp
op = 0
IR reg to asm
reg = !tmp0

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  16  ;  !retvalue  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  a  ;  main_0  ;  0  ;  0  ;  0  ;  0  | 
|  1  ;  b  ;  main_0  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
code = main_0_!tmp0
   movl $3, -4(%rbp)
op = 3
copy operation
BRANCH 2

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  16  ;  !retvalue  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  a  ;  main_0  ;  0  ;  0  ;  0  ;  0  | 
|  1  ;  b  ;  main_0  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
code = main_0_a
Scope is = 0 main_0

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  16  ;  !retvalue  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  a  ;  main_0  ;  0  ;  0  ;  0  ;  0  | 
|  1  ;  b  ;  main_0  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
code = main_0_a
IR reg to asm
reg = a

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  16  ;  !retvalue  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  20  ;  a  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  b  ;  main_0  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
code = main_0_a
IR reg to asm
reg = !tmp0

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  16  ;  !retvalue  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  20  ;  a  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  b  ;  main_0  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
code = main_0_!tmp0
   movl -4(%rbp), %eax
   movl %eax, -20(%rbp)
op = 0
IR reg to asm
reg = !tmp1

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  16  ;  !retvalue  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  20  ;  a  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  b  ;  main_0  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
code = main_0_!tmp1
   movl $1, -8(%rbp)
IR reg to asm
reg = !tmp1

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  16  ;  !retvalue  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  20  ;  a  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  b  ;  main_0  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
code = main_0_!tmp1

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  16  ;  !retvalue  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  20  ;  a  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  b  ;  main_0  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
code = main_0_!tmp1
   cmpl    $0, -8(%rbp)
   je  .main#3
.main#2:
op = 0
IR reg to asm
reg = !tmp2

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  16  ;  !retvalue  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  20  ;  a  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  b  ;  main_0  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
code = main_0_!tmp2
   movl $10, -12(%rbp)
op = 3
copy operation
BRANCH 2

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  16  ;  !retvalue  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  20  ;  a  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  b  ;  main_0  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
code = main_0_b
Scope is = 0 main_0

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  16  ;  !retvalue  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  20  ;  a  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  b  ;  main_0  ;  0  ;  0  ;  0  ;  0  | 
------------------------------------------------------------------------------------------------------------
code = main_0_b
IR reg to asm
reg = b

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  16  ;  !retvalue  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  20  ;  a  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  24  ;  b  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
------------------------------------------------------------------------------------------------------------
code = main_0_b
IR reg to asm
reg = !tmp2

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  16  ;  !retvalue  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  20  ;  a  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  24  ;  b  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
------------------------------------------------------------------------------------------------------------
code = main_0_!tmp2
   movl -12(%rbp), %eax
   movl %eax, -24(%rbp)
   jmp   .main#3
.main#3:
op = 1
IR reg to asm
reg = !retvalue

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  16  ;  !retvalue  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  20  ;  a  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  24  ;  b  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
------------------------------------------------------------------------------------------------------------
code = main_0_!retvalue
IR reg to asm
reg = a

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  16  ;  !retvalue  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  20  ;  a  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  24  ;  b  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
------------------------------------------------------------------------------------------------------------
code = main_0_a
   movl -20(%rbp), %eax
   movl %eax, -16(%rbp)
   jmp   .main#1
.main#1:
op = 2
IR reg to asm
reg = !retvalue

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  16  ;  !retvalue  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  20  ;  a  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  24  ;  b  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
------------------------------------------------------------------------------------------------------------
code = main_0_!retvalue
   movl -16(%rbp), %eax
   #epilogue

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  getchar@PLT  ;  GLOBAL  ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  3  ;  0  ;  2  ;  0  | 
|  16  ;  !retvalue  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  20  ;  a  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
|  24  ;  b  ;  main_0  ;  0  ;  0  ;  1  ;  0  | 
------------------------------------------------------------------------------------------------------------
code = GLOBAL_main
   leave
   ret
