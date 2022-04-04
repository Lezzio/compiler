.text
.globl	main
 main: 
.main_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$32, %rsp

	#ldconst
	movl		$1, -4(%rbp)

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -20(%rbp)

	#ldconst
	movl		$1, -8(%rbp)
	cmpl		$0, -8(%rbp)
	je			.main_3
.main_2:

	#ldconst
	movl		$2, -12(%rbp)

	#copy
	movl		-12(%rbp), %eax
	movl		%eax, -24(%rbp)

	#ret
	movl		-24(%rbp), %eax
	movl		%eax, -16(%rbp)
	jmp			.main_1
	jmp			.main_3
.main_3:
.main_1:

	#finret
reg = !retvalue

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope name   ;   Scope table level   ;   Scope current level   ;   Scope context   ;   Type   ;   Additional   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  16  ;  !retvalue  ;  main  ;  TL=1  ;  CL=1  ;  Ctx=0 0 1   ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main  ;  TL=0  ;  CL=0  ;  Ctx=0 0   ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main  ;  TL=0  ;  CL=0  ;  Ctx=0 0   ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main  ;  TL=1  ;  CL=1  ;  Ctx=0 0 1   ;  0  ;  0  ;  1  ;  0  | 
|  20  ;  a  ;  main  ;  TL=0  ;  CL=0  ;  Ctx=0 0   ;  0  ;  0  ;  1  ;  0  | 
|  24  ;  a  ;  main  ;  TL=1  ;  CL=1  ;  Ctx=0 0 1   ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  getchar@PLT  ;  GLOBAL  ;  TL=0  ;  CL=0  ;  Ctx=0   ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  TL=0  ;  CL=0  ;  Ctx=0   ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  TL=0  ;  CL=0  ;  Ctx=0   ;  3  ;  0  ;  2  ;  0  | 
------------------------------------------------------------------------------------------------------------
