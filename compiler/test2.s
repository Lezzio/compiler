.text
.globl	main
 main: 
.mainBB0:
  #prologue
  pushq %rbp
  movq %rsp, %rbp
  subq $64, %rsp
  movl $0, -12(%rbp)
  movq $-8, -20(%rbp)
  movq %rbp, %rax
  addq -20(%rbp), %rax
  movq %rax, -20(%rbp)
  movq -12(%rbp), %rax
  addq -20(%rbp), %rax
  movq %rax, -20(%rbp)
  movl $7, -24(%rbp)
  movq -20(%rbp), %rax
  movq -24(%rbp), %r10
  movq %r10, (%rax)

  movq $0, -28(%rbp)
  movq $-8, -36(%rbp)
  
  movq %rbp, %rax
  addq -36(%rbp), %rax
  movq %rax, -36(%rbp)
  
  movq -28(%rbp), %rax
  addq -36(%rbp), %rax
  movq %rax, -36(%rbp)

#readMem
  movq -36(%rbp), %rax
  movq (%rax), %r10
  movq %r10, -44(%rbp)

  movl -44(%rbp), %eax
  movl %eax, -52(%rbp)
  movl -52(%rbp), %eax
  movl %eax, -48(%rbp)
  jmp   .mainBB1
.mainBB1:
  movl -48(%rbp), %eax
  #epilogue
  leave
  ret
