.text
.globl	func
 func: 
.func_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$80, %rsp

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
.globl	func2
 func2: 
.func2_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$80, %rsp

	#add
	movl		%edi, %eax
	addl		%esi, %eax
	movl		%eax, -12(%rbp)

	#ret
	movl		-12(%rbp), %eax
	movl		%eax, -16(%rbp)
	jmp			.func2_1
.func2_1:

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
	subq		$80, %rsp

	#ldconst
	movl		$1, -20(%rbp)

	#copy
	movl		-20(%rbp), %eax
	movl		%eax, -24(%rbp)

	#ldconst
	movl		$2, -28(%rbp)

	#copy
	movl		-28(%rbp), %eax
	movl		%eax, -32(%rbp)

	#ldconst
	movl		$3, -36(%rbp)

	#copy
	movl		-36(%rbp), %eax
	movl		%eax, -40(%rbp)

	#ldconst
	movl		$4, -44(%rbp)

	#copy
	movl		-44(%rbp), %eax
	movl		%eax, -48(%rbp)

	#copy
	movl		-24(%rbp), %eax
	movl		%eax, %edi

	#copy
	movl		-32(%rbp), %eax
	movl		%eax, %esi

	#call
	call		func
	movl		%eax, -52(%rbp)

	#copy
	movl		-40(%rbp), %eax
	movl		%eax, %edi

	#copy
	movl		-48(%rbp), %eax
	movl		%eax, %esi

	#call
	call		func2
	movl		%eax, -56(%rbp)

	#add
	movl		-52(%rbp), %eax
	addl		-56(%rbp), %eax
	movl		%eax, -60(%rbp)

	#copy
	movl		-60(%rbp), %eax
	movl		%eax, -64(%rbp)

	#ret
	movl		-64(%rbp), %eax
	movl		%eax, -68(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-68(%rbp), %eax
	#epilogue
	leave
	ret
