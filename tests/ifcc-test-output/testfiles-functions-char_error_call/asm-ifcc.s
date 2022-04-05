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
	movb		%dil, %al
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
	subq		$32, %rsp

	#ldconst
	movl		$1, -8(%rbp)

	#copy
	movb		-8(%rbp), %al
	movb		%al, -9(%rbp)

	#copy
	movb		-9(%rbp), %al
	movb		%al, %dil

	#call
	call		func
	movb		%al, -10(%rbp)

	#copy
	movl		-10(%rbp), %eax
	movl		%eax, -14(%rbp)

	#ret
	movl		-14(%rbp), %eax
	movl		%eax, -18(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-18(%rbp), %eax
	#epilogue
	leave
	ret
