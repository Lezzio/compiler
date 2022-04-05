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
	movl		%edi, %eax
	movl		%eax, -4(%rbp)

	#ret
	movl		-4(%rbp), %eax
	movl		%eax, -8(%rbp)
	jmp			.func_1
.func_1:

	#finret
	movl		-8(%rbp), %eax
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
	movl		$1, -12(%rbp)

	#copy
	movl		-12(%rbp), %eax
	movl		%eax, -16(%rbp)

	#copy
	movl		-16(%rbp), %eax
	movl		%eax, %edi

	#call
	call		func
	movl		%eax, -20(%rbp)

	#copy
	movb		-20(%rbp), %al
	movb		%al, -21(%rbp)

	#ret
	movb		-21(%rbp), %al
	movb		%al, -25(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-25(%rbp), %eax
	#epilogue
	leave
	ret
