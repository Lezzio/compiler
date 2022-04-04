.text
.globl	func
 func: 
.func_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$16, %rsp
.func_1:

	#finret
reg = !retvalue

***   Actual Symbol Table   ***
-------------------------------------------------------------------------------------------------------------
|   Index   ;    Name   ;   Scope name   ;   Scope table level   ;   Scope current level   ;   Scope context   ;   Type   ;   Additional   ;    State    ;    IsConst   | 
-------------------------------------------------------------------------------------------------------------
|  1  ;  func  ;  GLOBAL  ;  TL=0  ;  CL=0  ;  Ctx=0   ;  3  ;  0  ;  2  ;  0  | 
|  1  ;  getchar@PLT  ;  GLOBAL  ;  TL=0  ;  CL=0  ;  Ctx=0   ;  2  ;  0  ;  2  ;  0  | 
|  1  ;  main  ;  GLOBAL  ;  TL=0  ;  CL=0  ;  Ctx=0   ;  0  ;  0  ;  2  ;  0  | 
|  1  ;  putchar@PLT  ;  GLOBAL  ;  TL=0  ;  CL=0  ;  Ctx=0   ;  3  ;  0  ;  2  ;  0  | 
------------------------------------------------------------------------------------------------------------
