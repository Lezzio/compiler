.text
.globl	main
 main: 
.main_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$80, %rsp

	#ldconst
	movl		$3, -4(%rbp)

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -8(%rbp)
	jmp			.main_2
.main_2:

	#ldconst
	movl		$0, -12(%rbp)

	#copy
	movl		-12(%rbp), %eax
	movl		%eax, -16(%rbp)
	jmp			.main_3
.main_3:

	#ldconst
	movl		$10, -20(%rbp)

	#cmp_lt
	movl		-16(%rbp), %eax
	cmpl		-20(%rbp), %eax
	setl		%al
	movzbl		%al, %eax
	movl		%eax, -24(%rbp)
	cmpl		$0, -24(%rbp)
	je			.main_6
.main_5:
	jmp			.main_7
.main_7:

	#ldconst
	movl		$0, -28(%rbp)

	#copy
	movl		-28(%rbp), %eax
	movl		%eax, -32(%rbp)
	jmp			.main_8
.main_8:

	#ldconst
	movl		$10, -36(%rbp)

	#cmp_lt
	movl		-32(%rbp), %eax
	cmpl		-36(%rbp), %eax
	setl		%al
	movzbl		%al, %eax
	movl		%eax, -40(%rbp)
	cmpl		$0, -40(%rbp)
	je			.main_11
.main_10:

	#mul
	movl		-16(%rbp), %eax
	imull		-32(%rbp), %eax
	movl		%eax, -44(%rbp)

	#copy
	movl		-44(%rbp), %eax
	movl		%eax, -8(%rbp)
	jmp			.main_9
.main_9:

	#ldconst
	movl		$1, -48(%rbp)

	#add
	movl		-32(%rbp), %eax
	addl		-48(%rbp), %eax
	movl		%eax, -52(%rbp)

	#copy
	movl		-52(%rbp), %eax
	movl		%eax, -32(%rbp)
	jmp			.main_8
.main_11:
	jmp			.main_4
.main_4:

	#ldconst
	movl		$1, -56(%rbp)

	#add
	movl		-16(%rbp), %eax
	addl		-56(%rbp), %eax
	movl		%eax, -60(%rbp)

	#copy
	movl		-60(%rbp), %eax
	movl		%eax, -16(%rbp)
	jmp			.main_3
.main_6:

	#ret
	movl		-8(%rbp), %eax
	movl		%eax, -64(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-64(%rbp), %eax
	#epilogue
	leave
	ret
