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
	jmp			.main_2
.main_2:

	#ldconst
reg = !tmp1

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope name   ;   Scope table level   ;   Scope current level   ;   Scope context   ;   Type   ;   Additional   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  24  ;  !retvalue  ;  main  ;  TL=2  ;  CL=2  ;  Ctx=0 0 2   ;  0  ;  0  ;  1  ;  0  | 
|  4  ;  !tmp0  ;  main  ;  TL=0  ;  CL=0  ;  Ctx=0 0   ;  0  ;  0  ;  1  ;  0  | 
|  8  ;  !tmp1  ;  main  ;  TL=1  ;  CL=1  ;  Ctx=0 0 1   ;  0  ;  0  ;  1  ;  0  | 
|  12  ;  !tmp2  ;  main  ;  TL=0  ;  CL=0  ;  Ctx=0 0   ;  0  ;  0  ;  1  ;  0  | 
|  16  ;  !tmp3  ;  main  ;  TL=0  ;  CL=0  ;  Ctx=0 0   ;  0  ;  0  ;  1  ;  0  | 
|  20  ;  !tmp4  ;  main  ;  TL=2  ;  CL=2  ;  Ctx=0 0 2   ;  0  ;  0  ;  1  ;  0  | 
|  28  ;  !tmp5  ;  main  ;  TL=0  ;  CL=0  ;  Ctx=0 0   ;  0  ;  0  ;  1  ;  0  | 
|  32  ;  !tmp6  ;  main  ;  TL=0  ;  CL=0  ;  Ctx=0 0   ;  0  ;  0  ;  1  ;  0  | 
|  36  ;  a  ;  main  ;  TL=0  ;  CL=0  ;  Ctx=0 0   ;  0  ;  0  ;  1  ;  0  | 
|  1  ;  a  ;  main  ;  TL=2  ;  CL=2  ;  Ctx=0 0 2   ;  0  ;  0  ;  0  ;  0  | 
|  1  ;  b  ;  main  ;  TL=0  ;  CL=0  ;  Ctx=0 0   ;  0  ;  0  ;  0  ;  0  | 
|  1  ;  getchar@PLT  ;  GLOBAL  ;  TL=0  ;  CL=0  ;  Ctx=0   ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  TL=0  ;  CL=0  ;  Ctx=0   ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  TL=0  ;  CL=0  ;  Ctx=0   ;  3  ;  0  ;  2  ;  0  | 
------------------------------------------------------------------------------------------------------------
