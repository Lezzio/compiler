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

	#cmp_lt
	movl		-8(%rbp), %eax
	cmpl		-12(%rbp), %eax
	setl		%al
	movzbl		%al, %eax
	movl		%eax, -16(%rbp)

	#ret
	movl		-16(%rbp), %eax
	movl		%eax, -20(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-20(%rbp), %eax
	#epilogue
	leave
	ret
