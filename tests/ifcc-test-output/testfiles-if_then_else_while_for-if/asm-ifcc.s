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
   movl %eax, -24(%rbp)
   movl $1, -8(%rbp)
   movl -24(%rbp), %eax
   cmpl -8(%rbp), %eax
    sete %al
    movzbl %al, %eax
   movl %eax, -12(%rbp)
   cmpl    $0, -12(%rbp)
   je  .mainBB3
.mainBB2:
   movl $12, -16(%rbp)
   movl -16(%rbp), %eax
   movl %eax, -24(%rbp)
   jmp   .mainBB3
.mainBB3:
   movl -24(%rbp), %eax
   movl %eax, -20(%rbp)
   jmp   .mainBB1
.mainBB1:
   movl -20(%rbp), %eax
   #epilogue
   leave
   ret
