.text
.globl	main
 main: 
.main_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$32, %rsp

	#ldconst
	movl		$3, -4(%rbp)

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -32(%rbp)

	#ldconst
	movl		$0, -8(%rbp)

	#copy
	movl		-8(%rbp), %eax
	movl		%eax, -36(%rbp)
	jmp			.main_3
.main_3:

	#ldconst
	movl		$10, -12(%rbp)

	#cmp_lt
	movl		-36(%rbp), %eax
	cmpl		-12(%rbp), %eax
	setl		%al
	movzbl		%al, %eax
	movl		%eax, -16(%rbp)
	cmpl		$0, -16(%rbp)
	je			.main_6
.main_5:

	#copy
	movl		-36(%rbp), %eax
	movl		%eax, -32(%rbp)
	jmp			.main_4
.main_4:

	#ldconst
	movl		$1, -20(%rbp)

	#add
	movl		-36(%rbp), %eax
	addl		-20(%rbp), %eax
	movl		%eax, -24(%rbp)

	#copy
	movl		-24(%rbp), %eax
	movl		%eax, -36(%rbp)
	jmp			.main_3
.main_6:

	#ret
	movl		-32(%rbp), %eax
	movl		%eax, -28(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-28(%rbp), %eax
	#epilogue
	leave
	ret
