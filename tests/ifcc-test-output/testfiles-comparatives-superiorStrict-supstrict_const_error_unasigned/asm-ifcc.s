.text
.globl	main
 main: 
.main_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$16, %rsp

	#ldconst
	movl		$1, -4(%rbp)

	#cmp_gt
	movl		-1(%rbp), %eax
	cmpl		-4(%rbp), %eax
	setg		%al
	movzbl		%al, %eax
	movl		%eax, -8(%rbp)

	#ret
	movl		-8(%rbp), %eax
	movl		%eax, -12(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-12(%rbp), %eax
	#epilogue
	leave
	ret
