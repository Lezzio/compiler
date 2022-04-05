.text
.globl	print_int
 print_int: 
.print_int_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$48, %rsp

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
	je			.print_int_3
.print_int_2:

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

	#ret
	movl		-4(%rbp), %eax
	movl		%eax, -21(%rbp)
	jmp			.print_int_1
	jmp			.print_int_3
.print_int_3:
.print_int_1:

	#finret
	movl		-21(%rbp), %eax
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
	movl		$273, -25(%rbp)

	#neg
	movl		-25(%rbp), %eax
	negl		%eax
	movl		%eax, -29(%rbp)

	#copy
	movl		-29(%rbp), %eax
	movl		%eax, %edi

	#call
	call		print_int
	movl		%eax, -33(%rbp)

	#ret
	movl		-33(%rbp), %eax
	movl		%eax, -37(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-37(%rbp), %eax
	#epilogue
	leave
	ret
