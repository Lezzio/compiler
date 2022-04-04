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
	movl		$1, -4(%rbp)

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -52(%rbp)

	#ldconst
	movl		$1, -8(%rbp)

	#copy
	movl		-8(%rbp), %eax
	movl		%eax, -56(%rbp)
	jmp			.main_3
.main_3:

	#ldconst
	movl		$5, -12(%rbp)

	#cmp_neq
	movl		-52(%rbp), %eax
	cmpl		-12(%rbp), %eax
	setne		%al
	movzbl		%al, %eax
	movl		%eax, -16(%rbp)
	cmpl		$0, -16(%rbp)
	je			.main_4
.main_2:

	#ldconst
	movl		$1, -20(%rbp)

	#add
	movl		-52(%rbp), %eax
	addl		-20(%rbp), %eax
	movl		%eax, -24(%rbp)

	#copy
	movl		-24(%rbp), %eax
	movl		%eax, -52(%rbp)
	jmp			.main_6
.main_6:

	#ldconst
	movl		$5, -28(%rbp)

	#cmp_neq
	movl		-56(%rbp), %eax
	cmpl		-28(%rbp), %eax
	setne		%al
	movzbl		%al, %eax
	movl		%eax, -32(%rbp)
	cmpl		$0, -32(%rbp)
	je			.main_7
.main_5:

	#ldconst
	movl		$1, -36(%rbp)

	#add
	movl		-56(%rbp), %eax
	addl		-36(%rbp), %eax
	movl		%eax, -40(%rbp)

	#copy
	movl		-40(%rbp), %eax
	movl		%eax, -56(%rbp)
	jmp			.main_6
.main_7:

	#ldconst
	movl		$1, -44(%rbp)

	#copy
	movl		-44(%rbp), %eax
	movl		%eax, -56(%rbp)
	jmp			.main_3
.main_4:

	#ret
	movl		-52(%rbp), %eax
	movl		%eax, -48(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-48(%rbp), %eax
	#epilogue
	leave
	ret
