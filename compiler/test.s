.text
.globl	main
 main: 
.mainBB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
  subq $32, %rsp
   movl $3, -4(%rbp)
   movl -4(%rbp), %eax
   movl %eax, -32(%rbp)
   movl $5, -8(%rbp)
   movl -8(%rbp), %eax
   movl %eax, -36(%rbp)
   movl $7, -12(%rbp)
   movl -12(%rbp), %eax
   movl %eax, -20(%rbp)
   movl -32(%rbp), %eax
   addl -36(%rbp), %eax
   movl %eax, -16(%rbp)
   movl $20, -20(%rbp)
   movl %ebp, %eax
   addl -20(%rbp), %eax
   movl %eax, -20(%rbp)
   movl -20(%rbp), %eax
   movl -16(%rbp), %r10d
   movl %r10d, (%eax)
   movl $0, -24(%rbp)
   movl -24(%rbp), %eax
   movl %eax, -28(%rbp)
   jmp   .mainBB1
.mainBB1:
   movl -28(%rbp), %eax
   #epilogue
   leave
   ret
