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
	movb		-4(%rbp), %al
	movb		%al, -5(%rbp)

	#ldconst
	movl		$3, -9(%rbp)

	#copy
	movb		-9(%rbp), %al
	movb		%al, -10(%rbp)

	#cmp_eq
	movb		-5(%rbp), %al
	cmpb		-10(%rbp), %al
	sete		%al
	movb		%al, -11(%rbp)

	#copy
	movl		-11(%rbp), %eax
	movl		%eax, -15(%rbp)

	#ret
	movl		-15(%rbp), %eax
	movl		%eax, -19(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-19(%rbp), %eax
	#epilogue
	leave
	ret
