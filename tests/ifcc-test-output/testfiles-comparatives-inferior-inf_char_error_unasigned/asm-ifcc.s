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
	movb		%al, -2(%rbp)

	#cmp_le
	movb		-2(%rbp), %al
	cmpb		-1(%rbp), %al
	setle		%al
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
