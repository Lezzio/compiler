.text
.globl	func
 func: 
.func_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$32, %rsp

	#ldconst
	movl		$5, -4(%rbp)

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -24(%rbp)

	#add
	movl		-1(%rbp), %eax
	addl		-24(%rbp), %eax
	movl		%eax, -8(%rbp)

	#ret
	movl		-8(%rbp), %eax
	movl		%eax, -12(%rbp)
	jmp			.func_1
.func_1:

	#finret
	movl		-12(%rbp), %eax
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
	movl		%eax, -28(%rbp)

	#ldconst
	movl		$2, -8(%rbp)

	#copy
	movl		-8(%rbp), %eax
	movl		%eax, -24(%rbp)

	#copy
	movl		-28(%rbp), %eax
	movl		%eax, %edi

	#call
	call		func
	movl		%eax, -16(%rbp)

	#add
	movl		-16(%rbp), %eax
	addl		-24(%rbp), %eax
	movl		%eax, -20(%rbp)

	#copy
	movl		-20(%rbp), %eax
	movl		%eax, -32(%rbp)

	#ret
	movl		-32(%rbp), %eax
	movl		%eax, -12(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-12(%rbp), %eax
	#epilogue
	leave
	ret
