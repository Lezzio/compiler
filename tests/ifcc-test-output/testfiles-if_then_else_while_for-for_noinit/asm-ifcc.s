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

	#copy
	movl		-16(%rbp), %eax
	movl		%eax, -8(%rbp)
	jmp			.main_4
.main_4:

	#ldconst
	movl		$1, -28(%rbp)

	#add
	movl		-16(%rbp), %eax
	addl		-28(%rbp), %eax
	movl		%eax, -32(%rbp)

	#copy
	movl		-32(%rbp), %eax
	movl		%eax, -16(%rbp)
	jmp			.main_3
.main_6:

	#ret
	movl		-8(%rbp), %eax
	movl		%eax, -36(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-36(%rbp), %eax
	#epilogue
	leave
	ret
