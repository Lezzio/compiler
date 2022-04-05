.text
.globl	alphabet
 alphabet: 
.alphabet_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$48, %rsp

	#copy
	movl		%edi, %eax
	movl		%eax, -4(%rbp)

	#ldconst
	movb		$65, -5(%rbp)

	#copy
	movb		-5(%rbp), %al
	movb		%al, -6(%rbp)
	jmp			.alphabet_3
.alphabet_3:

	#ldconst
	movb		$65, -7(%rbp)

	#add
	movzbl		-7(%rbp), %eax
	addl		-4(%rbp), %eax
	movl		%eax, -11(%rbp)

	#cast
	movsbl		-6(%rbp), %eax
	movl		%eax, -15(%rbp)

	#cmp_lt
	movl		-15(%rbp), %eax
	cmpl		-11(%rbp), %eax
	setl		%al
	movzbl		%al, %eax
	movl		%eax, -19(%rbp)
	cmpl		$0, -19(%rbp)
	je			.alphabet_4
.alphabet_2:

	#copy
	movb		-6(%rbp), %al
	movb		%al, %dil

	#call
	call		putchar@PLT

	#ldconst
	movl		$1, -23(%rbp)

	#add
	movzbl		-6(%rbp), %eax
	addl		-23(%rbp), %eax
	movl		%eax, -27(%rbp)

	#copy
	movb		-27(%rbp), %al
	movb		%al, -6(%rbp)
	jmp			.alphabet_3
.alphabet_4:

	#ret
	movb		-6(%rbp), %al
	movb		%al, -31(%rbp)
	jmp			.alphabet_1
.alphabet_1:

	#finret
	movl		-31(%rbp), %eax
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
	movl		$15, -35(%rbp)

	#copy
	movl		-35(%rbp), %eax
	movl		%eax, %edi

	#call
	call		alphabet
	movl		%eax, -39(%rbp)

	#copy
	movl		-39(%rbp), %eax
	movl		%eax, -43(%rbp)

	#ret
	movl		-43(%rbp), %eax
	movl		%eax, -47(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-47(%rbp), %eax
	#epilogue
	leave
	ret
