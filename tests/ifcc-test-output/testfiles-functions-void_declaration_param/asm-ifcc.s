.text
.globl	func
 func: 
.func_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$32, %rsp

	#copy
	movl		%edi, %eax
	movl		%eax, -4(%rbp)

	#copy
	movl		%esi, %eax
	movl		%eax, -8(%rbp)
	#epilogue
	nop
	leave
	ret
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
	movl		$1, -12(%rbp)

	#copy
	movl		-12(%rbp), %eax
	movl		%eax, -16(%rbp)

	#ldconst
	movl		$2, -20(%rbp)

	#copy
	movl		-20(%rbp), %eax
	movl		%eax, -24(%rbp)

	#copy
	movl		-16(%rbp), %eax
	movl		%eax, %edi

	#copy
	movl		-24(%rbp), %eax
	movl		%eax, %esi

	#call
	call		func
	movl		$0, %eax
	#epilogue
	leave
	ret
