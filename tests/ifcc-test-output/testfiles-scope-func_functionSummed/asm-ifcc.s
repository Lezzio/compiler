.text
.globl	func
 func: 
.func_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$96, %rsp

	#copy
	movl		%edi, %eax
	movl		%eax, -4(%rbp)

	#copy
	movl		%esi, %eax
	movl		%eax, -8(%rbp)

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
.globl	func2
 func2: 
.func2_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$96, %rsp

	#copy
	movl		%edi, %eax
	movl		%eax, -20(%rbp)

	#copy
	movl		%esi, %eax
	movl		%eax, -24(%rbp)

	#add
	movl		-20(%rbp), %eax
	addl		-24(%rbp), %eax
	movl		%eax, -28(%rbp)

	#ret
	movl		-28(%rbp), %eax
	movl		%eax, -32(%rbp)
	jmp			.func2_1
.func2_1:

	#finret
	movl		-32(%rbp), %eax
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
	subq		$96, %rsp

	#ldconst
	movl		$1, -36(%rbp)

	#copy
	movl		-36(%rbp), %eax
	movl		%eax, -40(%rbp)

	#ldconst
	movl		$2, -44(%rbp)

	#copy
	movl		-44(%rbp), %eax
	movl		%eax, -48(%rbp)

	#ldconst
	movl		$3, -52(%rbp)

	#copy
	movl		-52(%rbp), %eax
	movl		%eax, -56(%rbp)

	#ldconst
	movl		$4, -60(%rbp)

	#copy
	movl		-60(%rbp), %eax
	movl		%eax, -64(%rbp)

	#copy
	movl		-40(%rbp), %eax
	movl		%eax, %edi

	#copy
	movl		-48(%rbp), %eax
	movl		%eax, %esi

	#call
	call		func
	movl		%eax, -68(%rbp)

	#copy
	movl		-56(%rbp), %eax
	movl		%eax, %edi

	#copy
	movl		-64(%rbp), %eax
	movl		%eax, %esi

	#call
	call		func2
	movl		%eax, -72(%rbp)

	#add
	movl		-68(%rbp), %eax
	addl		-72(%rbp), %eax
	movl		%eax, -76(%rbp)

	#copy
	movl		-76(%rbp), %eax
	movl		%eax, -80(%rbp)

	#ret
	movl		-80(%rbp), %eax
	movl		%eax, -84(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-84(%rbp), %eax
	#epilogue
	leave
	ret
