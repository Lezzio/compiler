.text
.globl	func
 func: 
.func_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$48, %rsp

	#add
	movl		%edi, %eax
	addl		%esi, %eax
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
	subq		$48, %rsp

	#ldconst
	movl		$1, -12(%rbp)

	#copy
	movl		-12(%rbp), %eax
	movl		%eax, -16(%rbp)

	#ldconst
	movl		$2, -20(%rbp)

	#copy
	movl		-20(%rbp), %eax
	movl		%eax, -24(%rbp)

	#copy
	movl		-16(%rbp), %eax
	movl		%eax, %edi

	#copy
	movl		-24(%rbp), %eax
	movl		%eax, %esi

	#call
	call		func
	movl		%eax, -28(%rbp)

	#copy
	movl		-28(%rbp), %eax
	movl		%eax, -32(%rbp)

	#ret
	movl		-32(%rbp), %eax
	movl		%eax, -36(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-36(%rbp), %eax
	#epilogue
	leave
	ret
