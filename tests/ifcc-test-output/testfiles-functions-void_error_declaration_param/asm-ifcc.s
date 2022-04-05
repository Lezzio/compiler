warning: ‘return’ with a value, in function returning void [-Wreturn-type]
.text
.globl	func
 func: 
.func_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$32, %rsp

	#add
	movl		%edi, %eax
	addl		%esi, %eax
	movl		%eax, -4(%rbp)
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
	movl		$1, -8(%rbp)

	#copy
	movl		-8(%rbp), %eax
	movl		%eax, -12(%rbp)

	#ldconst
	movl		$2, -16(%rbp)

	#copy
	movl		-16(%rbp), %eax
	movl		%eax, -20(%rbp)

	#copy
	movl		-12(%rbp), %eax
	movl		%eax, %edi

	#copy
	movl		-20(%rbp), %eax
	movl		%eax, %esi

	#call
	call		func
	movl		$0, %eax
	#epilogue
	leave
	ret
