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

	#ldconst
	movl		$3, -8(%rbp)

	#copy
	movl		-8(%rbp), %eax
	movl		%eax, -40(%rbp)
	jmp			.main_3
.main_3:

	#ldconst
	movl		$0, -12(%rbp)

	#cmp_gt
	movl		-40(%rbp), %eax
	cmpl		-12(%rbp), %eax
	setg		%al
	movzbl		%al, %eax
	movl		%eax, -16(%rbp)
	cmpl		$0, -16(%rbp)
	je			.main_4
.main_2:

	#ldconst
	movl		$2, -20(%rbp)

	#copy
	movl		-20(%rbp), %eax
	movl		%eax, -44(%rbp)

	#ldconst
	movl		$1, -24(%rbp)

	#sub
	movl		-40(%rbp), %eax
	subl		-24(%rbp), %eax
	movl		%eax, -28(%rbp)

	#copy
	movl		-28(%rbp), %eax
	movl		%eax, -40(%rbp)
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
