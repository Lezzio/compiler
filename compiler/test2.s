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

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -16(%rbp)

	#ldconst
	movl		$10, -8(%rbp)

	#copy
	movl		-8(%rbp), %eax
	movl		%eax, -16(%rbp)

	#ret
	movl		-16(%rbp), %eax
	movl		%eax, -12(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-12(%rbp), %eax
	#epilogue
	leave
	ret
