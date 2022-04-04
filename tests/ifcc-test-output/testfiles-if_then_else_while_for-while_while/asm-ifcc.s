.text
.globl	main
 main: 
.mainBB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
  subq $64, %rsp
   movl $1, -4(%rbp)
   movl -4(%rbp), %eax
   movl %eax, -52(%rbp)
   movl $1, -8(%rbp)
   movl -8(%rbp), %eax
   movl %eax, -56(%rbp)
   jmp   .mainBB3
.mainBB3:
   movl $5, -12(%rbp)
   movl -52(%rbp), %eax
   cmpl -12(%rbp), %eax
    setne %al
    movzbl %al, %eax
   movl %eax, -16(%rbp)
   cmpl    $0, -16(%rbp)
   je  .mainBB4
.mainBB2:
   movl $1, -20(%rbp)
   movl -52(%rbp), %eax
   addl -20(%rbp), %eax
   movl %eax, -24(%rbp)
   movl -24(%rbp), %eax
   movl %eax, -52(%rbp)
   jmp   .mainBB6
.mainBB6:
   movl $5, -28(%rbp)
   movl -56(%rbp), %eax
   cmpl -28(%rbp), %eax
    setne %al
    movzbl %al, %eax
   movl %eax, -32(%rbp)
   cmpl    $0, -32(%rbp)
   je  .mainBB7
.mainBB5:
   movl $1, -36(%rbp)
   movl -56(%rbp), %eax
   addl -36(%rbp), %eax
   movl %eax, -40(%rbp)
   movl -40(%rbp), %eax
   movl %eax, -56(%rbp)
   jmp   .mainBB6
.mainBB7:
   movl $1, -44(%rbp)
   movl -44(%rbp), %eax
   movl %eax, -56(%rbp)
   jmp   .mainBB3
.mainBB4:
   movl -52(%rbp), %eax
   movl %eax, -48(%rbp)
   jmp   .mainBB1
.mainBB1:
   movl -48(%rbp), %eax
   #epilogue
   leave
   ret
