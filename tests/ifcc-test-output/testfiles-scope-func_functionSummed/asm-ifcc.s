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
	movl		-1(%rbp), %eax
	addl		-2(%rbp), %eax
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
.globl	func2
 func2: 
.func2_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$48, %rsp

	#add
	movl		-1(%rbp), %eax
	addl		-2(%rbp), %eax
	movl		%eax, -4(%rbp)

	#ret
	movl		-4(%rbp), %eax
	movl		%eax, -8(%rbp)
	jmp			.func2_1
.func2_1:

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
	movl		$1, -4(%rbp)

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -36(%rbp)

	#ldconst
	movl		$2, -12(%rbp)

	#copy
	movl		-12(%rbp), %eax
	movl		%eax, -40(%rbp)

	#ldconst
	movl		$3, -16(%rbp)

	#copy
	movl		-16(%rbp), %eax
	movl		%eax, -44(%rbp)

	#ldconst
	movl		$4, -20(%rbp)

	#copy
	movl		-20(%rbp), %eax
	movl		%eax, -48(%rbp)

	#copy
	movl		-36(%rbp), %eax
	movl		%eax, %edi

	#copy
	movl		-40(%rbp), %eax
	movl		%eax, %esi

	#call
	call		func
	movl		%eax, -24(%rbp)

	#copy
	movl		-44(%rbp), %eax
	movl		%eax, %edi

	#copy
	movl		-48(%rbp), %eax
	movl		%eax, %esi

	#call
	call		func2
	movl		%eax, -28(%rbp)

	#add
	movl		-24(%rbp), %eax
	addl		-28(%rbp), %eax
	movl		%eax, -32(%rbp)

	#copy
	movl		-32(%rbp), %eax
	movl		%eax, -52(%rbp)

	#ret
	movl		-52(%rbp), %eax
	movl		%eax, -8(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-8(%rbp), %eax
	#epilogue
	leave
	ret
