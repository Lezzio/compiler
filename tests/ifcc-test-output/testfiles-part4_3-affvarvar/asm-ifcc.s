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
	movl		$10, -4(%rbp)

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -8(%rbp)

	#copy
	movl		-8(%rbp), %eax
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
