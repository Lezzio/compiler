.text
.globl	func
 func: 
.func_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$48, %rsp

	#copy
	movl		%edi, %eax
	movl		%eax, -4(%rbp)

	#copy
	movl		%esi, %eax
	movl		%eax, -8(%rbp)

	#add
	movl		-4(%rbp), %eax
	addl		-8(%rbp), %eax
	movl		%eax, -12(%rbp)
