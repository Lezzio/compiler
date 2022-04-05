.text
.globl	func
 func: 
.func_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$64, %rsp

	#copy
	movl		%edi, %eax
	movl		%eax, -4(%rbp)

	#ldconst
	movl		$5, -8(%rbp)

	#copy
	movl		-8(%rbp), %eax
	movl		%eax, -12(%rbp)

	#add
	movl		-4(%rbp), %eax
	addl		-12(%rbp), %eax
	movl		%eax, -16(%rbp)

	#ret
	movl		-16(%rbp), %eax
	movl		%eax, -20(%rbp)
	jmp			.func_1
.func_1:

	#finret
	movl		-20(%rbp), %eax
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
	movl		$1, -24(%rbp)

	#copy
	movl		-24(%rbp), %eax
	movl		%eax, -28(%rbp)

	#ldconst
	movl		$2, -32(%rbp)

	#copy
	movl		-32(%rbp), %eax
	movl		%eax, -36(%rbp)

	#copy
	movl		-28(%rbp), %eax
	movl		%eax, %edi

	#call
	call		func
	movl		%eax, -40(%rbp)

	#add
	movl		-40(%rbp), %eax
	addl		-36(%rbp), %eax
	movl		%eax, -44(%rbp)

	#copy
	movl		-44(%rbp), %eax
	movl		%eax, -48(%rbp)

	#ret
	movl		-48(%rbp), %eax
	movl		%eax, -52(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-52(%rbp), %eax
	#epilogue
	leave
	ret
