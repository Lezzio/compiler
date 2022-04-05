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
	movl		$0, -28(%rbp)

	#cast
	movslq		-28(%rbp), %rax
  movq %rax, -28(%rbp)

	#ldconst
  movq $-24, -36(%rbp)

	#add
    movq %rbp, %rax
  addq -36(%rbp), %rax
  movq %rax, -36(%rbp)

	#add
  movq -28(%rbp), %rax
  addq -36(%rbp), %rax
  movq %rax, -36(%rbp)

	#ldconst
	movl		$0, -40(%rbp)

	#wmem
  movq -36(%rbp), %rax
  movq -40(%rbp), %r10
  movq %r10, (%rax)

	#ldconst
	movl		$8, -44(%rbp)

	#cast
	movslq		-44(%rbp), %rax
  movq %rax, -44(%rbp)

	#ldconst
  movq $-24, -52(%rbp)

	#add
    movq %rbp, %rax
  addq -52(%rbp), %rax
  movq %rax, -52(%rbp)

	#add
  movq -44(%rbp), %rax
  addq -52(%rbp), %rax
  movq %rax, -52(%rbp)

	#ldconst
	movl		$1, -56(%rbp)

	#wmem
  movq -52(%rbp), %rax
  movq -56(%rbp), %r10
  movq %r10, (%rax)

	#ldconst
	movl		$16, -60(%rbp)

	#cast
	movslq		-60(%rbp), %rax
  movq %rax, -60(%rbp)

	#ldconst
  movq $-24, -68(%rbp)

	#add
    movq %rbp, %rax
  addq -68(%rbp), %rax
  movq %rax, -68(%rbp)

	#add
  movq -60(%rbp), %rax
  addq -68(%rbp), %rax
  movq %rax, -68(%rbp)

	#ldconst
	movl		$3, -72(%rbp)

	#wmem
  movq -68(%rbp), %rax
  movq -72(%rbp), %r10
  movq %r10, (%rax)

	#ldconst
	movl		$8, -76(%rbp)

	#cast
	movslq		-76(%rbp), %rax
  movq %rax, -92(%rbp)

	#ldconst
  movq $-24, -84(%rbp)

	#add
    movq %rbp, %rax
  addq -84(%rbp), %rax
  movq %rax, -84(%rbp)

	#add
  movq -92(%rbp), %rax
  addq -84(%rbp), %rax
  movq %rax, -84(%rbp)

	#rmem
  movq -84(%rbp), %rax
  movq (%rax), %r10
  movq %r10, -100(%rbp)

	#ret
  movq -100(%rbp), %rax
  movq %rax, -104(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-104(%rbp), %eax
	#epilogue
	leave
	ret
