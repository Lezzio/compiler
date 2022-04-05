.text
.globl	fibo
 fibo: 
.fibo_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp
	movl	%edi, -80(%rbp)
	#offset
	subq		$80, %rsp

	#ldconst
	movl		$0, -4(%rbp)

	#cmp_le
	movl		-80(%rbp), %eax
	cmpl		-4(%rbp), %eax
	setle		%al
	movzbl		%al, %eax
	movl		%eax, -8(%rbp)
	cmpl		$0, -8(%rbp)
	je			.fibo_4
.fibo_2:

	#ldconst
	movl		$0, -12(%rbp)

	#ret
	movl		-12(%rbp), %eax
	movl		%eax, -16(%rbp)
	jmp			.fibo_1
	jmp			.fibo_3
.fibo_4:

	#ldconst
	movl		$1, -20(%rbp)

	#cmp_eq
	movl		-80(%rbp), %eax
	cmpl		-20(%rbp), %eax
	sete		%al
	movzbl		%al, %eax
	movl		%eax, -24(%rbp)
	cmpl		$0, -24(%rbp)
	je			.fibo_6
.fibo_5:

	#ldconst
	movl		$1, -28(%rbp)

	#ret
	movl		-28(%rbp), %eax
	movl		%eax, -16(%rbp)
	jmp			.fibo_1
	jmp			.fibo_6
.fibo_6:
	jmp			.fibo_3
.fibo_3:

	#ldconst
	movl		$1, -32(%rbp)

	#sub
	movl		-80(%rbp), %eax
	subl		-32(%rbp), %eax
	movl		%eax, -36(%rbp)

	#copy
	movl		-36(%rbp), %eax
	movl		%eax, -80(%rbp)

	#call
	call		fibo
	movl		%eax, -40(%rbp)

	#ldconst
	movl		$2, -44(%rbp)

	#sub
	movl		-80(%rbp), %eax
	subl		-44(%rbp), %eax
	movl		%eax, -48(%rbp)

	#copy
	movl		-48(%rbp), %eax
	movl		%eax, -80(%rbp)

	#call
	call		fibo
	movl		%eax, -52(%rbp)

	#add
	movl		-40(%rbp), %eax
	addl		-52(%rbp), %eax
	movl		%eax, -56(%rbp)

	#ret
	movl		-56(%rbp), %eax
	movl		%eax, -16(%rbp)
	jmp			.fibo_1
.fibo_1:

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
	movl		$3, -60(%rbp)

	#copy
	movl		-60(%rbp), %eax
	movl		%eax, %edi

	#call
	call		fibo
	movl		%eax, -64(%rbp)

	#copy
	movl		-64(%rbp), %eax
	movl		%eax, -68(%rbp)

	#ret
	movl		-68(%rbp), %eax
	movl		%eax, -72(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-72(%rbp), %eax
	#epilogue
	leave
	ret
