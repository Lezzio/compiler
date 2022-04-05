.text
.globl	fibo
 fibo: 
.fibo_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$96, %rsp

	#copy
	movl		%edi, %eax
	movl		%eax, -4(%rbp)

	#ldconst
	movl		$0, -8(%rbp)

	#cmp_le
	movl		-4(%rbp), %eax
	cmpl		-8(%rbp), %eax
	setle		%al
	movzbl		%al, %eax
	movl		%eax, -12(%rbp)
	cmpl		$0, -12(%rbp)
	je			.fibo_4
.fibo_2:

	#ldconst
	movl		$0, -16(%rbp)

	#ret
	movl		-16(%rbp), %eax
	movl		%eax, -20(%rbp)
	jmp			.fibo_1
	jmp			.fibo_3
.fibo_4:

	#ldconst
	movl		$1, -24(%rbp)

	#cmp_eq
	movl		-4(%rbp), %eax
	cmpl		-24(%rbp), %eax
	sete		%al
	movzbl		%al, %eax
	movl		%eax, -28(%rbp)
	cmpl		$0, -28(%rbp)
	je			.fibo_6
.fibo_5:

	#ldconst
	movl		$1, -32(%rbp)

	#ret
	movl		-32(%rbp), %eax
	movl		%eax, -20(%rbp)
	jmp			.fibo_1
	jmp			.fibo_6
.fibo_6:
	jmp			.fibo_3
.fibo_3:

	#ldconst
	movl		$1, -36(%rbp)

	#sub
	movl		-4(%rbp), %eax
	subl		-36(%rbp), %eax
	movl		%eax, -40(%rbp)

	#copy
	movl		-40(%rbp), %eax
	movl		%eax, %edi

	#call
	call		fibo
	movl		%eax, -44(%rbp)

	#ldconst
	movl		$2, -48(%rbp)

	#sub
	movl		-4(%rbp), %eax
	subl		-48(%rbp), %eax
	movl		%eax, -52(%rbp)

	#copy
	movl		-52(%rbp), %eax
	movl		%eax, %edi

	#call
	call		fibo
	movl		%eax, -56(%rbp)

	#add
	movl		-44(%rbp), %eax
	addl		-56(%rbp), %eax
	movl		%eax, -60(%rbp)

	#ret
	movl		-60(%rbp), %eax
	movl		%eax, -20(%rbp)
	jmp			.fibo_1
.fibo_1:

	#finret
	movl		-20(%rbp), %eax
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
	movl		$2, -64(%rbp)

	#ldconst
	movl		$8, -68(%rbp)

	#copy
	movl		-68(%rbp), %eax
	movl		%eax, %edi

	#call
	call		fibo
	movl		%eax, -72(%rbp)

	#mul
	movl		-64(%rbp), %eax
	imull		-72(%rbp), %eax
	movl		%eax, -76(%rbp)

	#ret
	movl		-76(%rbp), %eax
	movl		%eax, -80(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-80(%rbp), %eax
	#epilogue
	leave
	ret
