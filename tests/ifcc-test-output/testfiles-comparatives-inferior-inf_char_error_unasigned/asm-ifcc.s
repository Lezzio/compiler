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
	movb		$98, -1(%rbp)

	#copy
	movb		-1(%rbp), %al
	movb		%al, -7(%rbp)

	#cmp_lt
	movb		-7(%rbp), %eax
	cmpb		-1(%rbp), %eax
	setl		%al
	movb		%al, -2(%rbp)

	#ret
	movb		-2(%rbp), %al
	movb		%al, -6(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-6(%rbp), %eax
	#epilogue
	leave
	ret
