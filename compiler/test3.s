.text
.globl	main
 main: 
.mainBB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp

	#offset
  subq $96, %rsp

	#ldconst
   movl $0, -20(%rbp)

	#cast
    movzbl -20(%rbp), %rax
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
   movl $7, -32(%rbp)

	#wmem
  movq -28(%rbp), %rax
  movq -32(%rbp), %r10
  movq %r10, (%rax)

	#ldconst
   movl $8, -36(%rbp)

	#cast
    movzbl -36(%rbp), %rax
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
   movl $9, -48(%rbp)

	#wmem
  movq -44(%rbp), %rax
  movq -48(%rbp), %r10
  movq %r10, (%rax)

	#ldconst
   movl $1, -52(%rbp)

	#copy
   movl -52(%rbp), %eax
   movl %eax, -84(%rbp)

	#ldconst
   movl $8, -56(%rbp)

	#mul
   movl -84(%rbp), %eax
   imull -56(%rbp), %eax
   movl %eax, -60(%rbp)

	#cast
    movzbl -60(%rbp), %rax
  movq %rax, -60(%rbp)

	#ldconst
  movq $-16, -68(%rbp)

	#add
    movq %rbp, %rax
  addq -68(%rbp), %rax
  movq %rax, -68(%rbp)

	#add
  movq -60(%rbp), %rax
  addq -68(%rbp), %rax
  movq %rax, -68(%rbp)

	#rmem
#readMem
  movq -68(%rbp), %rax
  movq (%rax), %r10
  movq %r10, -76(%rbp)

	#copy
   movl -76(%rbp), %eax
   movl %eax, -88(%rbp)

	#ret
   movl -88(%rbp), %eax
   movl %eax, -80(%rbp)
   jmp   .mainBB1
.mainBB1:

	#finret
   movl -80(%rbp), %eax
   #epilogue
   leave
   ret
