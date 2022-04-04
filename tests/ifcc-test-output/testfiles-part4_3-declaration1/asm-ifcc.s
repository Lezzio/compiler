.text
.globl	main
 main: 
.mainBB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
  subq $16, %rsp
   movl $0, -4(%rbp)
   movl -4(%rbp), %eax
   movl %eax, -8(%rbp)
   jmp   .mainBB1
.mainBB1:
   movl -8(%rbp), %eax
   #epilogue
   leave
   ret
