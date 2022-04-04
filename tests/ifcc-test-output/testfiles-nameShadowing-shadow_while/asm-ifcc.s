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
	movl		$0, -20(%rbp)

	#cmp_gt
	movl		-16(%rbp), %eax
	cmpl		-20(%rbp), %eax
	setg		%al
	movzbl		%al, %eax
	movl		%eax, -24(%rbp)
	cmpl		$0, -24(%rbp)
	je			.main_4
.main_2:

	#ldconst
	movl		$2, -28(%rbp)

	#copy
	movl		-28(%rbp), %eax
	movl		%eax, -32(%rbp)

	#ret
	movl		-32(%rbp), %eax
	movl		%eax, -36(%rbp)
	jmp			.main_1

	#ldconst
	movl		$1, -40(%rbp)

	#sub
	movl		-16(%rbp), %eax
	subl		-40(%rbp), %eax
	movl		%eax, -44(%rbp)

	#copy
	movl		-44(%rbp), %eax
	movl		%eax, -16(%rbp)
	jmp			.main_3
.main_4:
.main_1:

	#finret
	movl		-36(%rbp), %eax
	#epilogue
	leave
	ret
