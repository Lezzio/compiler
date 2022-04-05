.text
.globl	main
 main: 
.main_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$192, %rsp

	#ldconst
	movl		$0, -28(%rbp)

	#cast
	movslq		-28(%rbp), %rax
	movq		%rax, -44(%rbp)

	#ldconst
	movq		$-24, -36(%rbp)

	#add
	movq		%rbp, %rax
	addq		-36(%rbp), %rax
	movq		%rax, -36(%rbp)

	#add
	movq		-44(%rbp), %rax
	addq		-36(%rbp), %rax
	movq		%rax, -36(%rbp)

	#ldconst
	movl		$0, -48(%rbp)

	#wmem
	movq		-36(%rbp), %rax
	movq		-48(%rbp), %r10
	movq		%r10, (%rax)

	#ldconst
	movl		$8, -52(%rbp)

	#cast
	movslq		-52(%rbp), %rax
	movq		%rax, -68(%rbp)

	#ldconst
	movq		$-24, -60(%rbp)

	#add
	movq		%rbp, %rax
	addq		-60(%rbp), %rax
	movq		%rax, -60(%rbp)

	#add
	movq		-68(%rbp), %rax
	addq		-60(%rbp), %rax
	movq		%rax, -60(%rbp)

	#ldconst
	movl		$1, -72(%rbp)

	#wmem
	movq		-60(%rbp), %rax
	movq		-72(%rbp), %r10
	movq		%r10, (%rax)

	#ldconst
	movl		$16, -76(%rbp)

	#cast
	movslq		-76(%rbp), %rax
	movq		%rax, -92(%rbp)

	#ldconst
	movq		$-24, -84(%rbp)

	#add
	movq		%rbp, %rax
	addq		-84(%rbp), %rax
	movq		%rax, -84(%rbp)

	#add
	movq		-92(%rbp), %rax
	addq		-84(%rbp), %rax
	movq		%rax, -84(%rbp)

	#ldconst
	movl		$3, -96(%rbp)

	#wmem
	movq		-84(%rbp), %rax
	movq		-96(%rbp), %r10
	movq		%r10, (%rax)

	#ldconst
	movl		$16, -100(%rbp)

	#cast
	movslq		-100(%rbp), %rax
	movq		%rax, -116(%rbp)

	#ldconst
	movq		$-24, -108(%rbp)

	#add
	movq		%rbp, %rax
	addq		-108(%rbp), %rax
	movq		%rax, -108(%rbp)

	#add
	movq		-116(%rbp), %rax
	addq		-108(%rbp), %rax
	movq		%rax, -108(%rbp)

	#rmem
	movq		-108(%rbp), %rax
	movq		(%rax), %r10
	movq		%r10, -124(%rbp)

	#ldconst
	movl		$8, -128(%rbp)

	#cast
	movslq		-128(%rbp), %rax
	movq		%rax, -144(%rbp)

	#ldconst
	movq		$-24, -136(%rbp)

	#add
	movq		%rbp, %rax
	addq		-136(%rbp), %rax
	movq		%rax, -136(%rbp)

	#add
	movq		-144(%rbp), %rax
	addq		-136(%rbp), %rax
	movq		%rax, -136(%rbp)

	#rmem
	movq		-136(%rbp), %rax
	movq		(%rax), %r10
	movq		%r10, -152(%rbp)

	#add
	movb		-124(%rbp), %al
	addb		-152(%rbp), %al
	movb		%al, -153(%rbp)

	#ldconst
	movl		$0, -157(%rbp)

	#cast
	movslq		-157(%rbp), %rax
	movq		%rax, -173(%rbp)

	#ldconst
	movq		$-24, -165(%rbp)

	#add
	movq		%rbp, %rax
	addq		-165(%rbp), %rax
	movq		%rax, -165(%rbp)

	#add
	movq		-173(%rbp), %rax
	addq		-165(%rbp), %rax
	movq		%rax, -165(%rbp)

	#rmem
	movq		-165(%rbp), %rax
	movq		(%rax), %r10
	movq		%r10, -181(%rbp)

	#add
	movb		-153(%rbp), %al
	addb		-181(%rbp), %al
	movb		%al, -182(%rbp)

	#ret
	movb		-182(%rbp), %al
	movb		%al, -186(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-186(%rbp), %eax
	#epilogue
	leave
	ret
