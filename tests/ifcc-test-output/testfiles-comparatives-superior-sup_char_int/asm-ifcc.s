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
	movl		%eax, -20(%rbp)

	#ldconst
	movl		$10, -8(%rbp)

	#copy
	movb		-8(%rbp), %al
	movb		%al, -21(%rbp)

	#cmp_gt
	movl		-21(%rbp), %eax
	cmpl		-20(%rbp), %eax
	setg		%al
	movzbl		%al, %eax
	movl		%eax, -12(%rbp)

	#ret
	movl		-12(%rbp), %eax
	movl		%eax, -16(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-16(%rbp), %eax
	#epilogue
	leave
	ret
