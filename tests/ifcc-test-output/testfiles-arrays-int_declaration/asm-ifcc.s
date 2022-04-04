.text
.globl	main
 main: 
.main_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$32, %rsp

	#ret
	movl		-24(%rbp), %eax
	movl		%eax, -28(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-28(%rbp), %eax
	#epilogue
	leave
	ret
