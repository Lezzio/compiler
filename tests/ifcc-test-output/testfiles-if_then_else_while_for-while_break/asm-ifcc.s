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
	movl		%eax, -36(%rbp)
	jmp			.main_3
.main_3:

	#ldconst
	movl		$5, -8(%rbp)

	#cmp_neq
	movl		-36(%rbp), %eax
	cmpl		-8(%rbp), %eax
	setne		%al
	movzbl		%al, %eax
	movl		%eax, -12(%rbp)
	cmpl		$0, -12(%rbp)
	je			.main_4
.main_2:

	#ldconst
	movl		$1, -16(%rbp)

	#add
	movl		-36(%rbp), %eax
	addl		-16(%rbp), %eax
	movl		%eax, -20(%rbp)

	#copy
	movl		-20(%rbp), %eax
	movl		%eax, -36(%rbp)

	#ldconst
	movl		$4, -24(%rbp)

	#cmp_eq
	movl		-36(%rbp), %eax
	cmpl		-24(%rbp), %eax
	sete		%al
	movzbl		%al, %eax
	movl		%eax, -28(%rbp)
	cmpl		$0, -28(%rbp)
	je			.main_6
.main_5:

	#jmp
	jmp			.main_4
	jmp			.main_6
.main_6:
	jmp			.main_3
.main_4:

	#ret
	movl		-36(%rbp), %eax
	movl		%eax, -32(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-32(%rbp), %eax
	#epilogue
	leave
	ret
