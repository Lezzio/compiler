.text
.globl	test
 test: 
.test_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$32, %rsp

	#ldconst
	movl		$2, -4(%rbp)

	#mul
	movl		%edi, %eax
	imull		-4(%rbp), %eax
	movl		%eax, -8(%rbp)

	#copy
	movl		-8(%rbp), %eax
	movl		%eax, -28(%rbp)

	#ret
	movl		-28(%rbp), %eax
	movl		%eax, -12(%rbp)
	jmp			.test_1
.test_1:

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
	movl		$6, -16(%rbp)

	#copy
	movl		-16(%rbp), %eax
	movl		%eax, -32(%rbp)

	#copy
	movl		-32(%rbp), %eax
	movl		%eax, %edi

	#call
	call		test
	movl		%eax, -20(%rbp)

	#copy
	movl		-20(%rbp), %eax
	movl		%eax, -36(%rbp)

	#ret
	movl		-36(%rbp), %eax
	movl		%eax, -24(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-24(%rbp), %eax
	#epilogue
	leave
	ret
