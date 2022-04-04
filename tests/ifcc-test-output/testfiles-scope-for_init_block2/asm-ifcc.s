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
	movl		$5, -4(%rbp)

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -8(%rbp)
	jmp			.main_2
.main_2:

	#ldconst
	movl		$2, -12(%rbp)

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
	je			.main_6
.main_5:

	#ret
	movl		-16(%rbp), %eax
	movl		%eax, -28(%rbp)
	jmp			.main_1
	jmp			.main_4
.main_4:

	#ldconst
	movl		$1, -32(%rbp)

	#sub
	movl		-16(%rbp), %eax
	subl		-32(%rbp), %eax
	movl		%eax, -36(%rbp)

	#copy
	movl		-36(%rbp), %eax
	movl		%eax, -16(%rbp)
	jmp			.main_3
.main_6:
.main_1:

	#finret
	movl		-28(%rbp), %eax
	#epilogue
	leave
	ret
