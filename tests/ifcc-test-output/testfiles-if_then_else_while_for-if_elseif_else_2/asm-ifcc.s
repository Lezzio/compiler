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
	movl		$2, -4(%rbp)

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -40(%rbp)

	#ldconst
	movl		$1, -8(%rbp)

	#cmp_eq
	movl		-40(%rbp), %eax
	cmpl		-8(%rbp), %eax
	sete		%al
	movzbl		%al, %eax
	movl		%eax, -12(%rbp)
	cmpl		$0, -12(%rbp)
	je			.main_4
.main_2:

	#ldconst
	movl		$12, -16(%rbp)

	#copy
	movl		-16(%rbp), %eax
	movl		%eax, -40(%rbp)
	jmp			.main_3
.main_4:

	#ldconst
	movl		$2, -20(%rbp)

	#cmp_eq
	movl		-40(%rbp), %eax
	cmpl		-20(%rbp), %eax
	sete		%al
	movzbl		%al, %eax
	movl		%eax, -24(%rbp)
	cmpl		$0, -24(%rbp)
	je			.main_7
.main_5:

	#ldconst
	movl		$9, -28(%rbp)

	#copy
	movl		-28(%rbp), %eax
	movl		%eax, -40(%rbp)
	jmp			.main_6
.main_7:

	#ldconst
	movl		$10, -32(%rbp)

	#copy
	movl		-32(%rbp), %eax
	movl		%eax, -40(%rbp)
	jmp			.main_6
.main_6:
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
