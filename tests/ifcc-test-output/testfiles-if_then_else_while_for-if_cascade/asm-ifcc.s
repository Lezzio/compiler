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

	#ldconst
	movl		$1, -20(%rbp)

	#cmp_eq
	movl		-8(%rbp), %eax
	cmpl		-20(%rbp), %eax
	sete		%al
	movzbl		%al, %eax
	movl		%eax, -24(%rbp)
	cmpl		$0, -24(%rbp)
	je			.main_3
.main_2:

	#ldconst
	movl		$3, -28(%rbp)

	#cmp_eq
	movl		-16(%rbp), %eax
	cmpl		-28(%rbp), %eax
	sete		%al
	movzbl		%al, %eax
	movl		%eax, -32(%rbp)
	cmpl		$0, -32(%rbp)
	je			.main_6
.main_4:

	#ldconst
	movl		$5, -36(%rbp)

	#copy
	movl		-36(%rbp), %eax
	movl		%eax, -8(%rbp)
	jmp			.main_5
.main_6:

	#ldconst
	movl		$6, -40(%rbp)

	#copy
	movl		-40(%rbp), %eax
	movl		%eax, -8(%rbp)
	jmp			.main_5
.main_5:
	jmp			.main_3
.main_3:

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
