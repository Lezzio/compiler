.text
.globl	func
 func: 
.func_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$48, %rsp

	#copy
	movl		%edi, %eax
	movl		%eax, -4(%rbp)

	#ldconst
	movl		$1, -8(%rbp)

	#add
	movl		-4(%rbp), %eax
	addl		-8(%rbp), %eax
	movl		%eax, -12(%rbp)

	#ret
	movl		-12(%rbp), %eax
	movl		%eax, -16(%rbp)
	jmp			.func_1
.func_1:

	#finret
	movl		-16(%rbp), %eax
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
	subq		$48, %rsp

	#ldconst
	movl		$5, -20(%rbp)

	#copy
	movl		-20(%rbp), %eax
	movl		%eax, -24(%rbp)

	#copy
	movl		-24(%rbp), %eax
	movl		%eax, %edi

	#call
	call		func
	movl		%eax, -28(%rbp)

	#copy
	movl		-28(%rbp), %eax
	movl		%eax, %edi

	#call
	call		func
	movl		%eax, -32(%rbp)

	#copy
	movl		-32(%rbp), %eax
	movl		%eax, %edi

	#call
	call		func
	movl		%eax, -36(%rbp)

	#copy
	movl		-36(%rbp), %eax
	movl		%eax, -40(%rbp)

	#ret
	movl		-40(%rbp), %eax
	movl		%eax, -44(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-44(%rbp), %eax
	#epilogue
	leave
	ret
