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
	movb		-12(%rbp), %al
	movb		%al, -13(%rbp)

	#cast
	movsbl		-13(%rbp), %eax
	movl		%eax, -13(%rbp)

	#cmp_ge
	movl		-8(%rbp), %eax
	cmpl		-13(%rbp), %eax
	setge		%al
	movzbl		%al, %eax
	movl		%eax, -17(%rbp)

	#ret
	movl		-17(%rbp), %eax
	movl		%eax, -21(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-21(%rbp), %eax
	#epilogue
	leave
	ret
