.text
.globl	func
 func: 
.func_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$32, %rsp

	#ldconst
	movl		$1, -4(%rbp)

	#add
	movl		-1(%rbp), %eax
	addl		-4(%rbp), %eax
	movl		%eax, -8(%rbp)

	#ret
	movl		-8(%rbp), %eax
	movl		%eax, -12(%rbp)
	jmp			.func_1
.func_1:

	#finret
	movl		-12(%rbp), %eax
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
	movl		$5, -4(%rbp)

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -24(%rbp)

	#copy
	movl		-24(%rbp), %eax
	movl		%eax, %edi

	#call
	call		func
	movl		%eax, -8(%rbp)

	#copy
	movl		-8(%rbp), %eax
	movl		%eax, %edi

	#call
	call		func
	movl		%eax, -16(%rbp)

	#copy
	movl		-16(%rbp), %eax
	movl		%eax, %edi

	#call
	call		func
	movl		%eax, -20(%rbp)

	#copy
	movl		-20(%rbp), %eax
	movl		%eax, -28(%rbp)

	#ret
	movl		-28(%rbp), %eax
	movl		%eax, -12(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-12(%rbp), %eax
	#epilogue
	leave
	ret
