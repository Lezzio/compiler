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
	movl		$3, -4(%rbp)

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -8(%rbp)

	#ldconst
	movl		$1, -12(%rbp)

	#cmp_eq
	movl		-8(%rbp), %eax
	cmpl		-12(%rbp), %eax
	sete		%al
	movzbl		%al, %eax
	movl		%eax, -16(%rbp)
	cmpl		$0, -16(%rbp)
	je			.main_4
.main_2:

	#ldconst
	movl		$12, -20(%rbp)

	#copy
	movl		-20(%rbp), %eax
	movl		%eax, -8(%rbp)
	jmp			.main_3
.main_4:

	#ldconst
	movl		$2, -24(%rbp)

	#cmp_eq
	movl		-8(%rbp), %eax
	cmpl		-24(%rbp), %eax
	sete		%al
	movzbl		%al, %eax
	movl		%eax, -28(%rbp)
	cmpl		$0, -28(%rbp)
	je			.main_7
.main_5:

	#ldconst
	movl		$9, -32(%rbp)

	#copy
	movl		-32(%rbp), %eax
	movl		%eax, -8(%rbp)
	jmp			.main_6
.main_7:

	#ldconst
	movl		$10, -36(%rbp)

	#copy
	movl		-36(%rbp), %eax
	movl		%eax, -8(%rbp)
	jmp			.main_6
.main_6:
	jmp			.main_3
.main_3:

	#ret
	movl		-8(%rbp), %eax
	movl		%eax, -40(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-40(%rbp), %eax
	#epilogue
	leave
	ret
