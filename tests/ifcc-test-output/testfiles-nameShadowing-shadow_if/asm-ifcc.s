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
	movl		%eax, -8(%rbp)

	#ldconst
	movl		$1, -12(%rbp)
	cmpl		$0, -12(%rbp)
	je			.main_3
.main_2:

	#ldconst
	movl		$2, -16(%rbp)

	#copy
	movl		-16(%rbp), %eax
	movl		%eax, -20(%rbp)

	#ret
	movl		-20(%rbp), %eax
	movl		%eax, -24(%rbp)
	jmp			.main_1
	jmp			.main_3
.main_3:
.main_1:

	#finret
	movl		-24(%rbp), %eax
	#epilogue
	leave
	ret
