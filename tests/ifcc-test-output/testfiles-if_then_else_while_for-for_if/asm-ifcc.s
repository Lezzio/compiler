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
	movl		$1, -4(%rbp)

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -8(%rbp)

	#ldconst
	movl		$3, -12(%rbp)

	#copy
	movl		-12(%rbp), %eax
	movl		%eax, -16(%rbp)
	jmp			.main_2
.main_2:

	#ldconst
	movl		$0, -20(%rbp)

	#copy
	movl		-20(%rbp), %eax
	movl		%eax, -24(%rbp)
	jmp			.main_3
.main_3:

	#ldconst
	movl		$10, -28(%rbp)

	#cmp_lt
	movl		-24(%rbp), %eax
	cmpl		-28(%rbp), %eax
	setl		%al
	movzbl		%al, %eax
	movl		%eax, -32(%rbp)
	cmpl		$0, -32(%rbp)
	je			.main_6
.main_5:

	#ldconst
	movl		$1, -36(%rbp)

	#add
	movl		-8(%rbp), %eax
	addl		-36(%rbp), %eax
	movl		%eax, -40(%rbp)

	#copy
	movl		-40(%rbp), %eax
	movl		%eax, -8(%rbp)

	#ldconst
	movl		$3, -44(%rbp)

	#cmp_eq
	movl		-8(%rbp), %eax
	cmpl		-44(%rbp), %eax
	sete		%al
	movzbl		%al, %eax
	movl		%eax, -48(%rbp)
	cmpl		$0, -48(%rbp)
	je			.main_8
.main_7:

	#ldconst
	movl		$6, -52(%rbp)

	#copy
	movl		-52(%rbp), %eax
	movl		%eax, -16(%rbp)
	jmp			.main_8
.main_8:
	jmp			.main_4
.main_4:

	#ldconst
	movl		$1, -56(%rbp)

	#add
	movl		-24(%rbp), %eax
	addl		-56(%rbp), %eax
	movl		%eax, -60(%rbp)

	#copy
	movl		-60(%rbp), %eax
	movl		%eax, -24(%rbp)
	jmp			.main_3
.main_6:

	#ret
	movl		-16(%rbp), %eax
	movl		%eax, -64(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-64(%rbp), %eax
	#epilogue
	leave
	ret
