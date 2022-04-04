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
	movl		$1, -4(%rbp)

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -8(%rbp)

	#ldconst
	movl		$3, -12(%rbp)

	#copy
	movl		-12(%rbp), %eax
	movl		%eax, -16(%rbp)
	jmp			.main_3
.main_3:

	#ldconst
	movl		$5, -20(%rbp)

	#cmp_neq
	movl		-8(%rbp), %eax
	cmpl		-20(%rbp), %eax
	setne		%al
	movzbl		%al, %eax
	movl		%eax, -24(%rbp)
	cmpl		$0, -24(%rbp)
	je			.main_4
.main_2:

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
	movl		$4, -36(%rbp)

	#cmp_eq
	movl		-8(%rbp), %eax
	cmpl		-36(%rbp), %eax
	sete		%al
	movzbl		%al, %eax
	movl		%eax, -40(%rbp)
	cmpl		$0, -40(%rbp)
	je			.main_6
.main_5:

	#jmp
	jmp			.main_3
	jmp			.main_6
.main_6:

	#copy
	movl		-8(%rbp), %eax
	movl		%eax, -16(%rbp)
	jmp			.main_3
.main_4:

	#ret
	movl		-8(%rbp), %eax
	movl		%eax, -44(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-44(%rbp), %eax
	#epilogue
	leave
	ret
