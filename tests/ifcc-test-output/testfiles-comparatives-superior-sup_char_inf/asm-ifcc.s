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
	movb		%al, -2(%rbp)

	#ldconst
	movb		$98, -3(%rbp)

	#copy
	movb		-3(%rbp), %al
	movb		%al, -4(%rbp)

	#cmp_gt
	movb		-2(%rbp), %al
	cmpb		-4(%rbp), %al
	setg		%al
	movb		%al, -5(%rbp)

	#ret
	movb		-5(%rbp), %al
	movb		%al, -9(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-9(%rbp), %eax
	#epilogue
	leave
	ret
