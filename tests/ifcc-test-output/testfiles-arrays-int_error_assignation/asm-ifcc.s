.text
.globl	main
 main: 
.main_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$176, %rsp

	#ldconst
	movl		$0, -36(%rbp)

	#cast
	movslq		-36(%rbp), %rax
	movq		%rax, -52(%rbp)

	#ldconst
	movq		$-32, -44(%rbp)

	#add
	movq		%rbp, %rax
	addq		-44(%rbp), %rax
	movq		%rax, -44(%rbp)

	#add
	movq		-52(%rbp), %rax
	addq		-44(%rbp), %rax
	movq		%rax, -44(%rbp)

	#ldconst
	movl		$0, -56(%rbp)

	#wmem
	movq		-44(%rbp), %rax
	movq		-56(%rbp), %r10
	movq		%r10, (%rax)

	#ldconst
	movl		$8, -60(%rbp)

	#cast
	movslq		-60(%rbp), %rax
	movq		%rax, -76(%rbp)

	#ldconst
	movq		$-32, -68(%rbp)

	#add
	movq		%rbp, %rax
	addq		-68(%rbp), %rax
	movq		%rax, -68(%rbp)

	#add
	movq		-76(%rbp), %rax
	addq		-68(%rbp), %rax
	movq		%rax, -68(%rbp)

	#ldconst
	movl		$1, -80(%rbp)

	#wmem
	movq		-68(%rbp), %rax
	movq		-80(%rbp), %r10
	movq		%r10, (%rax)

	#ldconst
	movl		$16, -84(%rbp)

	#cast
	movslq		-84(%rbp), %rax
	movq		%rax, -100(%rbp)

	#ldconst
	movq		$-32, -92(%rbp)

	#add
	movq		%rbp, %rax
	addq		-92(%rbp), %rax
	movq		%rax, -92(%rbp)

	#add
	movq		-100(%rbp), %rax
	addq		-92(%rbp), %rax
	movq		%rax, -92(%rbp)

	#ldconst
	movl		$3, -104(%rbp)

	#wmem
	movq		-92(%rbp), %rax
	movq		-104(%rbp), %r10
	movq		%r10, (%rax)

	#ldconst
	movl		$24, -108(%rbp)

	#cast
	movslq		-108(%rbp), %rax
	movq		%rax, -124(%rbp)

	#ldconst
	movq		$-32, -116(%rbp)

	#add
	movq		%rbp, %rax
	addq		-116(%rbp), %rax
	movq		%rax, -116(%rbp)

	#add
	movq		-124(%rbp), %rax
	addq		-116(%rbp), %rax
	movq		%rax, -116(%rbp)

	#ldconst
	movl		$4, -128(%rbp)

	#wmem
	movq		-116(%rbp), %rax
	movq		-128(%rbp), %r10
	movq		%r10, (%rax)

	#ldconst
	movl		$8, -132(%rbp)

	#cast
	movslq		-132(%rbp), %rax
	movq		%rax, -148(%rbp)

	#ldconst
	movq		$-32, -140(%rbp)

	#add
	movq		%rbp, %rax
	addq		-140(%rbp), %rax
	movq		%rax, -140(%rbp)

	#add
	movq		-148(%rbp), %rax
	addq		-140(%rbp), %rax
	movq		%rax, -140(%rbp)

	#rmem
	movq		-140(%rbp), %rax
	movq		(%rax), %r10
	movq		%r10, -156(%rbp)

	#ret
	movslq		-156(%rbp), %rax
	movq		%rax, -160(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-160(%rbp), %eax
	#epilogue
	leave
	ret
