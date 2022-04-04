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
	movl		%eax, -40(%rbp)

	#ldconst
	movl		$3, -8(%rbp)

	#copy
	movl		-8(%rbp), %eax
	movl		%eax, -44(%rbp)

	#ldconst
	movl		$1, -12(%rbp)

	#cmp_eq
	movl		-40(%rbp), %eax
	cmpl		-12(%rbp), %eax
	sete		%al
	movzbl		%al, %eax
	movl		%eax, -16(%rbp)
	cmpl		$0, -16(%rbp)
	je			.main_3
.main_2:

	#ldconst
	movl		$3, -20(%rbp)

	#cmp_eq
	movl		-44(%rbp), %eax
	cmpl		-20(%rbp), %eax
	sete		%al
	movzbl		%al, %eax
	movl		%eax, -24(%rbp)
	cmpl		$0, -24(%rbp)
	je			.main_6
.main_4:

	#ldconst
	movl		$5, -28(%rbp)

	#copy
	movl		-28(%rbp), %eax
	movl		%eax, -40(%rbp)
	jmp			.main_5
.main_6:

	#ldconst
	movl		$6, -32(%rbp)

	#copy
	movl		-32(%rbp), %eax
	movl		%eax, -40(%rbp)
	jmp			.main_5
.main_5:
	jmp			.main_3
.main_3:

	#ret
	movl		-40(%rbp), %eax
	movl		%eax, -36(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-36(%rbp), %eax
	#epilogue
	leave
	ret
