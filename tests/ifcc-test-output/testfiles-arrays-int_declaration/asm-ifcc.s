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

	#rmem
	movq		-36(%rbp), %rax
	movq		(%rax), %r10
	movq		%r10, -52(%rbp)

	#ret
	movslq		-52(%rbp), %rax
	movq		%rax, -56(%rbp)
	jmp			.main_1
.main_1:

	#finret
	movl		-56(%rbp), %eax
	#epilogue
	leave
	ret
