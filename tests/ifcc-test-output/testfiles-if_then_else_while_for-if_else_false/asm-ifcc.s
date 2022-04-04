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
	movl		$1, -4(%rbp)

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -28(%rbp)

	#ldconst
	movl		$1, -8(%rbp)

	#cmp_neq
	movl		-28(%rbp), %eax
	cmpl		-8(%rbp), %eax
	setne		%al
	movzbl		%al, %eax
	movl		%eax, -12(%rbp)
	cmpl		$0, -12(%rbp)
	je			.main_4
.main_2:

	#ldconst
	movl		$12, -16(%rbp)

	#copy
	movl		-16(%rbp), %eax
	movl		%eax, -28(%rbp)
	jmp			.main_3
.main_4:

	#ldconst
	movl		$9, -20(%rbp)

	#copy
	movl		-20(%rbp), %eax
	movl		%eax, -28(%rbp)
	jmp			.main_3
.main_3:

	#ret
	movl		-28(%rbp), %eax
	movl		%eax, -24(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-24(%rbp), %eax
	#epilogue
	leave
	ret
