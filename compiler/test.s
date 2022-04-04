.text
.globl	main
 main: 
.main_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$128, %rsp

	#ldconst
	movl		$0, -20(%rbp)

	#cast
	movslq		-20(%rbp), %rax
  movq %rax, -20(%rbp)

	#ldconst
  movq $-16, -28(%rbp)

	#add
    movq %rbp, %rax
  addq -28(%rbp), %rax
  movq %rax, -28(%rbp)

	#add
  movq -20(%rbp), %rax
  addq -28(%rbp), %rax
  movq %rax, -28(%rbp)

	#ldconst
	movl		$1, -32(%rbp)

	#wmem
  movq -28(%rbp), %rax
  movq -32(%rbp), %r10
  movq %r10, (%rax)

	#ldconst
	movl		$8, -36(%rbp)

	#cast
	movslq		-36(%rbp), %rax
  movq %rax, -36(%rbp)

	#ldconst
  movq $-16, -44(%rbp)

	#add
    movq %rbp, %rax
  addq -44(%rbp), %rax
  movq %rax, -44(%rbp)

	#add
  movq -36(%rbp), %rax
  addq -44(%rbp), %rax
  movq %rax, -44(%rbp)

	#ldconst
	movl		$2, -48(%rbp)

	#wmem
  movq -44(%rbp), %rax
  movq -48(%rbp), %r10
  movq %r10, (%rax)

	#ldconst
	movl		$8, -52(%rbp)

	#cast
	movslq		-52(%rbp), %rax
  movq %rax, -68(%rbp)

	#ldconst
  movq $-16, -60(%rbp)

	#add
    movq %rbp, %rax
  addq -60(%rbp), %rax
  movq %rax, -60(%rbp)

	#add
  movq -68(%rbp), %rax
  addq -60(%rbp), %rax
  movq %rax, -60(%rbp)

	#rmem
  movq -60(%rbp), %rax
  movq (%rax), %r10
  movq %r10, -76(%rbp)

	#copy
	movl		-76(%rbp), %eax
	movl		%eax, -80(%rbp)

	#ldconst
	movl		$0, -84(%rbp)

	#cast
	movslq		-84(%rbp), %rax
  movq %rax, -100(%rbp)

	#ldconst
  movq $-16, -92(%rbp)

	#add
    movq %rbp, %rax
  addq -92(%rbp), %rax
  movq %rax, -92(%rbp)

	#add
  movq -100(%rbp), %rax
  addq -92(%rbp), %rax
  movq %rax, -92(%rbp)

	#rmem
  movq -92(%rbp), %rax
  movq (%rax), %r10
  movq %r10, -108(%rbp)

	#copy
	movl		-108(%rbp), %eax
	movl		%eax, -112(%rbp)

	#add
	movl		-80(%rbp), %eax
	addl		-112(%rbp), %eax
	movl		%eax, -116(%rbp)

	#ret
	movl		-116(%rbp), %eax
	movl		%eax, -120(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-120(%rbp), %eax
	#epilogue
	leave
	ret


