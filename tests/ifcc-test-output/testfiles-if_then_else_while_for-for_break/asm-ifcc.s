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

	#ldconst
	movl		$1, -28(%rbp)

	#add
	movl		-8(%rbp), %eax
	addl		-28(%rbp), %eax
	movl		%eax, -32(%rbp)

	#copy
	movl		-32(%rbp), %eax
	movl		%eax, -8(%rbp)

	#ldconst
	movl		$3, -36(%rbp)

	#cmp_eq
	movl		-8(%rbp), %eax
	cmpl		-36(%rbp), %eax
	sete		%al
	movzbl		%al, %eax
	movl		%eax, -40(%rbp)
	cmpl		$0, -40(%rbp)
	je			.main_8
.main_7:

	#jmp
	jmp			.main_6
	jmp			.main_8
.main_8:
	jmp			.main_4
.main_4:

	#ldconst
	movl		$1, -44(%rbp)

	#add
	movl		-16(%rbp), %eax
	addl		-44(%rbp), %eax
	movl		%eax, -48(%rbp)

	#copy
	movl		-48(%rbp), %eax
	movl		%eax, -16(%rbp)
	jmp			.main_3
.main_6:

	#ret
	movl		-8(%rbp), %eax
	movl		%eax, -52(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-52(%rbp), %eax
	#epilogue
	leave
	ret
