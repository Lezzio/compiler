.text
.globl	func
 func: 
.func_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$16, %rsp

	#ldconst
	movl		$2, -4(%rbp)

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -16(%rbp)

	#ret
	movl		-16(%rbp), %eax
	movl		%eax, -8(%rbp)
	jmp			.func_1
.func_1:

	#finret
	movl		-8(%rbp), %eax
	#epilogue
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
	movl		$1, -4(%rbp)

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -16(%rbp)

	#call
	call		func
	movl		%eax, -12(%rbp)

	#ret
	movl		-12(%rbp), %eax
	movl		%eax, -8(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-8(%rbp), %eax
	#epilogue
	leave
	ret
