.text
.globl	main
 main: 
.main_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$48, %rsp

	#ldconst
	movl		$1, -4(%rbp)

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -36(%rbp)

	#ldconst
	movl		$3, -8(%rbp)

	#copy
	movl		-8(%rbp), %eax
	movl		%eax, -40(%rbp)
	jmp			.main_3
.main_3:

	#ldconst
	movl		$0, -12(%rbp)

	#cmp_gt
	movl		-40(%rbp), %eax
	cmpl		-12(%rbp), %eax
	setg		%al
	movzbl		%al, %eax
	movl		%eax, -16(%rbp)
	cmpl		$0, -16(%rbp)
	je			.main_4
.main_2:

	#ldconst
	movl		$2, -20(%rbp)

	#copy
	movl		-20(%rbp), %eax
	movl		%eax, -44(%rbp)

	#ret
	movl		-44(%rbp), %eax
	movl		%eax, -24(%rbp)
	jmp			.main_1

	#ldconst
	movl		$1, -28(%rbp)

	#sub
	movl		-40(%rbp), %eax
	subl		-28(%rbp), %eax
	movl		%eax, -32(%rbp)

	#copy
	movl		-32(%rbp), %eax
	movl		%eax, -40(%rbp)
	jmp			.main_3
.main_4:
.main_1:

	#finret
reg = !retvalue

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope name   ;   Scope table level   ;   Scope current level   ;   Scope context   ;   Type   ;   Additional   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  24  ;  !retvalue  ;  main  ;  TL=1  ;  CL=1  ;  Ctx=0 0 1   ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main  ;  TL=0  ;  CL=0  ;  Ctx=0 0   ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main  ;  TL=0  ;  CL=0  ;  Ctx=0 0   ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main  ;  TL=0  ;  CL=0  ;  Ctx=0 0   ;  0  ;  0  ;  1  ;  0  | 
|  16  ;  !tmp3  ;  main  ;  TL=0  ;  CL=0  ;  Ctx=0 0   ;  0  ;  0  ;  1  ;  0  | 
|  20  ;  !tmp4  ;  main  ;  TL=1  ;  CL=1  ;  Ctx=0 0 1   ;  0  ;  0  ;  1  ;  0  | 
|  28  ;  !tmp5  ;  main  ;  TL=1  ;  CL=1  ;  Ctx=0 0 1   ;  0  ;  0  ;  1  ;  0  | 
|  32  ;  !tmp6  ;  main  ;  TL=1  ;  CL=1  ;  Ctx=0 0 1   ;  0  ;  0  ;  1  ;  0  | 
|  36  ;  a  ;  main  ;  TL=0  ;  CL=0  ;  Ctx=0 0   ;  0  ;  0  ;  1  ;  0  | 
|  44  ;  a  ;  main  ;  TL=1  ;  CL=1  ;  Ctx=0 0 1   ;  0  ;  0  ;  1  ;  0  | 
|  40  ;  b  ;  main  ;  TL=0  ;  CL=0  ;  Ctx=0 0   ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  getchar@PLT  ;  GLOBAL  ;  TL=0  ;  CL=0  ;  Ctx=0   ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  TL=0  ;  CL=0  ;  Ctx=0   ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  TL=0  ;  CL=0  ;  Ctx=0   ;  3  ;  0  ;  2  ;  0  | 
------------------------------------------------------------------------------------------------------------
