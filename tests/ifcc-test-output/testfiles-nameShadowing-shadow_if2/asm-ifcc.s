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
	movl		$1, -4(%rbp)

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -20(%rbp)

	#ldconst
	movl		$1, -8(%rbp)
	cmpl		$0, -8(%rbp)
	je			.main_3
.main_2:

	#ldconst
	movl		$2, -12(%rbp)

	#copy
	movl		-12(%rbp), %eax
	movl		%eax, -24(%rbp)
	jmp			.main_3
.main_3:

	#ret
	movl		-20(%rbp), %eax
	movl		%eax, -16(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-16(%rbp), %eax
	#epilogue
	leave
	ret
