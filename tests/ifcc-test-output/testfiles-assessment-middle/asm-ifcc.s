.text
.globl	main
 main: 
.main_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$48, %rsp

	#ldconst
	movl		$17, -4(%rbp)

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -8(%rbp)

	#ldconst
	movl		$42, -12(%rbp)

	#copy
	movl		-12(%rbp), %eax
	movl		%eax, -16(%rbp)

	#mul
	movl		-8(%rbp), %eax
	imull		-8(%rbp), %eax
	movl		%eax, -20(%rbp)

	#mul
	movl		-16(%rbp), %eax
	imull		-16(%rbp), %eax
	movl		%eax, -24(%rbp)

	#add
	movl		-20(%rbp), %eax
	addl		-24(%rbp), %eax
	movl		%eax, -28(%rbp)

	#ldconst
	movl		$1, -32(%rbp)

	#add
	movl		-28(%rbp), %eax
	addl		-32(%rbp), %eax
	movl		%eax, -36(%rbp)

	#copy
	movl		-36(%rbp), %eax
	movl		%eax, -40(%rbp)

	#ret
	movl		-40(%rbp), %eax
	movl		%eax, -44(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-44(%rbp), %eax
	#epilogue
	leave
	ret
