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
	movl		%eax, -8(%rbp)

	#ldconst
	movl		$1, -12(%rbp)

	#copy
	movl		-12(%rbp), %eax
	movl		%eax, -16(%rbp)

	#cmp_gt
	movl		-16(%rbp), %eax
	cmpl		-8(%rbp), %eax
	setg		%al
	movzbl		%al, %eax
	movl		%eax, -20(%rbp)

	#ret
	movl		-20(%rbp), %eax
	movl		%eax, -24(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-24(%rbp), %eax
	#epilogue
	leave
	ret
