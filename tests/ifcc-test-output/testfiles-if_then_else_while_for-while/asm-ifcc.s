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
	movl		%eax, -8(%rbp)
	jmp			.main_3
.main_3:

	#ldconst
	movl		$5, -12(%rbp)

	#cmp_neq
	movl		-8(%rbp), %eax
	cmpl		-12(%rbp), %eax
	setne		%al
	movzbl		%al, %eax
	movl		%eax, -16(%rbp)
	cmpl		$0, -16(%rbp)
	je			.main_4
.main_2:

	#ldconst
	movl		$1, -20(%rbp)

	#add
	movl		-8(%rbp), %eax
	addl		-20(%rbp), %eax
	movl		%eax, -24(%rbp)

	#copy
	movl		-24(%rbp), %eax
	movl		%eax, -8(%rbp)
	jmp			.main_3
.main_4:

	#ret
	movl		-8(%rbp), %eax
	movl		%eax, -28(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-28(%rbp), %eax
	#epilogue
	leave
	ret
