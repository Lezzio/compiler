.text
.globl	func
 func: 
.func_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$16, %rsp

	#ret
	movb		-1(%rbp), %al
	movb		%al, -4(%rbp)
	jmp			.func_1
.func_1:

	#finret
	movl		-4(%rbp), %eax
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
	subq		$16, %rsp

	#ldconst
	movl		$1, -8(%rbp)

	#copy
	movb		-8(%rbp), %al
	movb		%al, -10(%rbp)

	#copy
	movb		-10(%rbp), %al
	movb		%al, %edi

	#call
	call		func
	movb		%al, -9(%rbp)

	#copy
	movl		-9(%rbp), %eax
	movl		%eax, -14(%rbp)

	#ret
	movl		-14(%rbp), %eax
	movl		%eax, -4(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-4(%rbp), %eax
	#epilogue
	leave
	ret
