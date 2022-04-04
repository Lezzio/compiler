.text
.globl	main
 main: 
.mainBB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
  subq $32, %rsp
   movl $1, -4(%rbp)
   movl -4(%rbp), %eax
   movl %eax, -20(%rbp)
   movl $1, -8(%rbp)
   movl -8(%rbp), %eax
   movl %eax, -24(%rbp)
   movl -20(%rbp), %eax
   cmpl -24(%rbp), %eax
    sete %al
    movzbl %al, %eax
   movl %eax, -12(%rbp)
   movl -12(%rbp), %eax
   movl %eax, -16(%rbp)
   jmp   .mainBB1
.mainBB1:
   movl -16(%rbp), %eax
   #epilogue
   leave
   ret
