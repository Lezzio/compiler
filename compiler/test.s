.text
.globl	main
 main: 
.mainBB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
   movl $2, -4(%rbp)
   movl -4(%rbp), %eax
   movl %eax, -32(%rbp)
   movl $8, -8(%rbp)
   movl -32(%rbp), %eax
   cmpl -8(%rbp), %eax
   setne %al
   movzbl %al, %eax
   movl %eax, -12(%rbp)
   cmpl    $0, -12(%rbp)
   je  .mainBB3
.mainBB2:
   movl $1, -16(%rbp)
   movl -32(%rbp), %eax
   addl -16(%rbp), %eax
   movl %eax, -20(%rbp)
   movl -20(%rbp), %eax
   movl %eax, -32(%rbp)
   jmp   .mainBB3
.mainBB3:
   movl $5, -24(%rbp)
   movl -24(%rbp), %eax
   movl %eax, -28(%rbp)
   jmp   .mainBB1
.mainBB1:
   movl -28(%rbp), %eax
   #epilogue
   popq %rbp
   ret
