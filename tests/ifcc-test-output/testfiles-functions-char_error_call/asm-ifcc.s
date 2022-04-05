.text
.globl	func
 func: 
.func_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$32, %rsp

	#copy
	movb		%dil, %al
	movb		%al, -1(%rbp)

	#ret
	movb		-1(%rbp), %al
	movb		%al, -5(%rbp)
	jmp			.func_1
.func_1:

	#finret
	movl		-5(%rbp), %eax
	#epilogue
	leave
	ret
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
	movl		$1, -9(%rbp)

	#copy
	movb		-9(%rbp), %al
	movb		%al, -10(%rbp)

	#copy
	movb		-10(%rbp), %al
	movb		%al, %dil

	#call
	call		func
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
