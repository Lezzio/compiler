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
	movb		$97, -1(%rbp)

	#copy
	movb		-1(%rbp), %al
	movb		%al, -8(%rbp)

	#ldconst
	movb		$97, -2(%rbp)

	#copy
	movb		-2(%rbp), %al
	movb		%al, -9(%rbp)

	#cmp_neq
	movb		-9(%rbp), %eax
	cmpb		-8(%rbp), %eax
	setne		%al
	movb		%al, -3(%rbp)

	#ret
	movb		-3(%rbp), %al
	movb		%al, -7(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-7(%rbp), %eax
	#epilogue
	leave
	ret
