.text
.globl	main
 main: 
.main_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$112, %rsp

	#ldconst
	movl		$0, -36(%rbp)

	#cast
    movzbl -36(%rbp), %rax
  movq %rax, -36(%rbp)

	#ldconst
  movq $-32, -44(%rbp)

	#add
    movq %rbp, %rax
  addq -44(%rbp), %rax
  movq %rax, -44(%rbp)

	#add
  movq -36(%rbp), %rax
  addq -44(%rbp), %rax
  movq %rax, -44(%rbp)

	#ldconst
	movl		$0, -48(%rbp)

	#wmem
  movq -44(%rbp), %rax
  movq -48(%rbp), %r10
  movq %r10, (%rax)

	#ldconst
	movl		$8, -52(%rbp)

	#cast
    movzbl -52(%rbp), %rax
  movq %rax, -52(%rbp)

	#ldconst
  movq $-32, -60(%rbp)

	#add
    movq %rbp, %rax
  addq -60(%rbp), %rax
  movq %rax, -60(%rbp)

	#add
  movq -52(%rbp), %rax
  addq -60(%rbp), %rax
  movq %rax, -60(%rbp)

	#ldconst
	movl		$1, -64(%rbp)

	#wmem
  movq -60(%rbp), %rax
  movq -64(%rbp), %r10
  movq %r10, (%rax)

	#ldconst
	movl		$16, -68(%rbp)

	#cast
    movzbl -68(%rbp), %rax
  movq %rax, -68(%rbp)

	#ldconst
  movq $-32, -76(%rbp)

	#add
    movq %rbp, %rax
  addq -76(%rbp), %rax
  movq %rax, -76(%rbp)

	#add
  movq -68(%rbp), %rax
  addq -76(%rbp), %rax
  movq %rax, -76(%rbp)

	#ldconst
	movl		$3, -80(%rbp)

	#wmem
  movq -76(%rbp), %rax
  movq -80(%rbp), %r10
  movq %r10, (%rax)

	#ldconst
	movl		$24, -84(%rbp)

	#cast
    movzbl -84(%rbp), %rax
  movq %rax, -84(%rbp)

	#ldconst
  movq $-32, -92(%rbp)

	#add
    movq %rbp, %rax
  addq -92(%rbp), %rax
  movq %rax, -92(%rbp)

	#add
  movq -84(%rbp), %rax
  addq -92(%rbp), %rax
  movq %rax, -92(%rbp)

	#ldconst
	movl		$4, -96(%rbp)

	#wmem
  movq -92(%rbp), %rax
  movq -96(%rbp), %r10
  movq %r10, (%rax)

	#ret
	movl		-32(%rbp), %eax
	movl		%eax, -100(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-100(%rbp), %eax
	#epilogue
	leave
	ret
