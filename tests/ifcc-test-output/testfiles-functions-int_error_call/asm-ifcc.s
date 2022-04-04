.text
.globl	func
 func: 
.func_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$32, %rsp

	#ret
	movl		%edi, %eax
	movl		%eax, -4(%rbp)
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
	subq		$32, %rsp

	#ldconst
	movl		$1, -8(%rbp)

	#copy
	movl		-8(%rbp), %eax
	movl		%eax, -12(%rbp)

	#copy
	movl		-12(%rbp), %eax
	movl		%eax, %edi

	#call
	call		func
	movl		%eax, -16(%rbp)

	#copy
	movb		-16(%rbp), %al
	movb		%al, -17(%rbp)

	#ret
	movb		-17(%rbp), %al
	movb		%al, -21(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-21(%rbp), %eax
	#epilogue
	leave
	ret
