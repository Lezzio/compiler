.text
.globl	main
 main: 
.mainBB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
  subq $16, %rsp
   movl $3, -4(%rbp)
   movl -4(%rbp), %eax
   movl %eax, -16(%rbp)
   movl --1(%rbp), %eax
   cmpl -16(%rbp), %eax
    sete %al
    movzbl %al, %eax
   movl %eax, -8(%rbp)
   movl -8(%rbp), %eax
   movl %eax, -12(%rbp)
   jmp   .mainBB1
.mainBB1:
   movl -12(%rbp), %eax
   #epilogue
   leave
   ret
