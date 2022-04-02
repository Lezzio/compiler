.text
.globl	main
 main: 
.mainBB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
  subq $32, %rsp
   movq $3, -4(%rbp)
   movq -4(%rbp), %rax
   movq %rax, -32(%rbp)
   movq $2, -8(%rbp)
   movq -8(%rbp), %rax
   movq %rax, -36(%rbp)
   movq $7, -12(%rbp)
   movq -12(%rbp), %rax
   movq %rax, -20(%rbp)
   movq -32(%rbp), %rax
   addq -36(%rbp), %rax
   movq %rax, -16(%rbp)
   movq $-20, -24(%rbp)
   movq %rbp, %rax
   addq -24(%rbp), %rax
   movq %rax, -24(%rbp)
   movq -24(%rbp), %rax
   movq -16(%rbp), %r10
   movq %r10, (%rax)
   movq -20(%rbp), %rax
   movq %rax, -28(%rbp)
   jmp   .mainBB1
.mainBB1:
   movq -28(%rbp), %rax
   #epilogue
   leave
   ret
