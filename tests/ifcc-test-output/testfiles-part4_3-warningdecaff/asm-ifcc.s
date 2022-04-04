.text
.globl	main
 main: 
.mainBB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
  subq $16, %rsp
   movl $2, -4(%rbp)
   movl -4(%rbp), %eax
   movl %eax, -16(%rbp)
   movl $42, -8(%rbp)
   movl -8(%rbp), %eax
   movl %eax, -12(%rbp)
   jmp   .mainBB1
.mainBB1:
   movl -12(%rbp), %eax
   #epilogue
   leave
   ret
