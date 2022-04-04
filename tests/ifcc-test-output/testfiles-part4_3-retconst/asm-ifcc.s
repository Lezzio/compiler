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
	movl		$42, -4(%rbp)

	#ret
	movl		-4(%rbp), %eax
	movl		%eax, -8(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-8(%rbp), %eax
	#epilogue
	leave
	ret
