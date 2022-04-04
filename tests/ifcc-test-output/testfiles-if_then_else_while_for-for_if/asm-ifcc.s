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
   movl %eax, -56(%rbp)
   movl $3, -8(%rbp)
   movl -8(%rbp), %eax
   movl %eax, -60(%rbp)
   jmp   .mainBB2
.mainBB2:
   movl $0, -12(%rbp)
   movl -12(%rbp), %eax
   movl %eax, -64(%rbp)
   jmp   .mainBB3
.mainBB3:
   movl $10, -16(%rbp)
   movl -64(%rbp), %eax
   cmpl -16(%rbp), %eax
    setl %al
    movzbl %al, %eax
   movl %eax, -20(%rbp)
   cmpl    $0, -20(%rbp)
   je  .mainBB6
.mainBB5:
   movl $1, -24(%rbp)
   movl -56(%rbp), %eax
   addl -24(%rbp), %eax
   movl %eax, -28(%rbp)
   movl -28(%rbp), %eax
   movl %eax, -56(%rbp)
   movl $3, -32(%rbp)
   movl -56(%rbp), %eax
   cmpl -32(%rbp), %eax
    sete %al
    movzbl %al, %eax
   movl %eax, -36(%rbp)
   cmpl    $0, -36(%rbp)
   je  .mainBB8
.mainBB7:
   movl $6, -40(%rbp)
   movl -40(%rbp), %eax
   movl %eax, -60(%rbp)
   jmp   .mainBB8
.mainBB8:
   jmp   .mainBB4
.mainBB4:
   movl $1, -44(%rbp)
   movl -64(%rbp), %eax
   addl -44(%rbp), %eax
   movl %eax, -48(%rbp)
   movl -48(%rbp), %eax
   movl %eax, -64(%rbp)
   jmp   .mainBB3
.mainBB6:
   movl -60(%rbp), %eax
   movl %eax, -52(%rbp)
   jmp   .mainBB1
.mainBB1:
   movl -52(%rbp), %eax
   #epilogue
   leave
   ret
