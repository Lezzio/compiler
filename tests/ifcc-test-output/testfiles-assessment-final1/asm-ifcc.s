.text
.globl	alphabet
 alphabet: 
.alphabet_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$48, %rsp

	#ldconst
	movb		$65, -1(%rbp)

	#copy
	movb		-1(%rbp), %al
	movb		%al, -2(%rbp)
	jmp			.alphabet_3
.alphabet_3:

	#ldconst
	movb		$65, -3(%rbp)

	#add
	movl		-3(%rbp), %eax
	addl		%edi, %eax
	movl		%eax, -7(%rbp)

	#cast
	movsbl		-2(%rbp), %eax
	movl		%eax, -2(%rbp)

	#cmp_lt
	movl		-2(%rbp), %eax
	cmpl		-7(%rbp), %eax
	setl		%al
	movzbl		%al, %eax
	movl		%eax, -11(%rbp)
	cmpl		$0, -11(%rbp)
	je			.alphabet_4
.alphabet_2:

	#copy
	movb		-2(%rbp), %al
	movb		%al, %dil

	#call
	call		putchar@PLT

	#ldconst
	movl		$1, -15(%rbp)

	#add
	movl		-2(%rbp), %eax
	addl		-15(%rbp), %eax
	movl		%eax, -19(%rbp)

	#copy
	movb		-19(%rbp), %al
	movb		%al, -2(%rbp)
	jmp			.alphabet_3
.alphabet_4:

	#ret
	movb		-2(%rbp), %al
	movb		%al, -23(%rbp)
	jmp			.alphabet_1
.alphabet_1:

	#finret
	movl		-23(%rbp), %eax
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
	movl		$15, -27(%rbp)

	#copy
	movl		-27(%rbp), %eax
	movl		%eax, %edi

	#call
	call		alphabet
	movl		%eax, -31(%rbp)

	#copy
	movl		-31(%rbp), %eax
	movl		%eax, -35(%rbp)

	#ret
	movl		-35(%rbp), %eax
	movl		%eax, -39(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-39(%rbp), %eax
	#epilogue
	leave
	ret
