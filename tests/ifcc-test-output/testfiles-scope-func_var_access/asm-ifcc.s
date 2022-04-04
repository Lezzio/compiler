.text
.globl	func
 func: 
.func_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$64, %rsp

	#ldconst
	movl		$5, -4(%rbp)

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -8(%rbp)

	#add
	movl		%edi, %eax
	addl		-8(%rbp), %eax
	movl		%eax, -12(%rbp)

	#ret
	movl		-12(%rbp), %eax
	movl		%eax, -16(%rbp)
	jmp			.func_1
.func_1:

	#finret
	movl		-16(%rbp), %eax
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
	subq		$64, %rsp

	#ldconst
	movl		$1, -20(%rbp)

	#copy
	movl		-20(%rbp), %eax
	movl		%eax, -24(%rbp)

	#ldconst
	movl		$2, -28(%rbp)

	#copy
	movl		-28(%rbp), %eax
	movl		%eax, -32(%rbp)

	#copy
	movl		-24(%rbp), %eax
	movl		%eax, %edi

	#call
	call		func
	movl		%eax, -36(%rbp)

	#add
	movl		-36(%rbp), %eax
	addl		-32(%rbp), %eax
	movl		%eax, -40(%rbp)

	#copy
	movl		-40(%rbp), %eax
	movl		%eax, -44(%rbp)

	#ret
	movl		-44(%rbp), %eax
	movl		%eax, -48(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-48(%rbp), %eax
	#epilogue
	leave
	ret
