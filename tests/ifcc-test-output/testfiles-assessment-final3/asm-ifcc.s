.text
.globl	print_int
 print_int: 
.print_int_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$64, %rsp

	#copy
	movl		%edi, %eax
	movl		%eax, -4(%rbp)

	#ldconst
	movl		$0, -8(%rbp)

	#cmp_lt
	movl		-4(%rbp), %eax
	cmpl		-8(%rbp), %eax
	setl		%al
	movzbl		%al, %eax
	movl		%eax, -12(%rbp)
	cmpl		$0, -12(%rbp)
	je			.print_int_2
.print_int_1:

	#ldconst
	movb		$45, -13(%rbp)

	#copy
	movb		-13(%rbp), %al
	movb		%al, %dil

	#call
	call		putchar@PLT

	#neg
	movl		-4(%rbp), %eax
	negl		%eax
	movl		%eax, -17(%rbp)

	#copy
	movl		-17(%rbp), %eax
	movl		%eax, -4(%rbp)
	jmp			.print_int_2
.print_int_2:

	#ldconst
	movl		$10, -21(%rbp)

	#div
	movl		-4(%rbp), %eax
	idivl		-21(%rbp), %eax
	movl		%eax, -25(%rbp)

	#ldconst
	movl		$0, -29(%rbp)

	#cmp_neq
	movl		-25(%rbp), %eax
	cmpl		-29(%rbp), %eax
	setne		%al
	movzbl		%al, %eax
	movl		%eax, -33(%rbp)
	cmpl		$0, -33(%rbp)
	je			.print_int_4
.print_int_3:

	#ldconst
	movl		$10, -37(%rbp)

	#div
	movl		-4(%rbp), %eax
	idivl		-37(%rbp), %eax
	movl		%eax, -41(%rbp)

	#copy
	movl		-41(%rbp), %eax
	movl		%eax, %edi

	#call
	call		print_int
	jmp			.print_int_4
.print_int_4:

	#ldconst
	movl		$10, -45(%rbp)

	#mod
	movl		-4(%rbp), %eax
	idivl		-45(%rbp), %eax
	movl		%eax, -49(%rbp)

	#ldconst
	movb		$48, -50(%rbp)

	#add
	movl		-49(%rbp), %eax
	addl		-50(%rbp), %eax
	movl		%eax, -54(%rbp)

	#cast
	mov		-54(%rbp), %al
	movb		%al, -54(%rbp)

	#copy
	movl		-54(%rbp), %eax
	movl		%eax, %edi

	#call
	call		putchar@PLT
	#epilogue
	nop
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
	subq		$64, %rsp

	#ldconst
	movl		$10, -58(%rbp)

	#copy
	movl		-58(%rbp), %eax
	movl		%eax, %edi

	#call
	call		print_int

	#ldconst
	movl		$10, -62(%rbp)

	#cast
	mov		-62(%rbp), %al
	movb		%al, -62(%rbp)

	#copy
	movl		-62(%rbp), %eax
	movl		%eax, %edi

	#call
	call		putchar@PLT
	movl		$0, %eax
	#epilogue
	leave
	ret
