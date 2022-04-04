.text
.globl	func
 func: 
.func_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$48, %rsp

	#add
	movl		%edi, %eax
	addl		%esi, %eax
	movl		%eax, -4(%rbp)
