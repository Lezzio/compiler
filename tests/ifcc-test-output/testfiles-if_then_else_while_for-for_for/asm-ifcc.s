.text
.globl	main
 main: 
.mainBB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
  subq $64, %rsp
   movl $3, -4(%rbp)
   movl -4(%rbp), %eax
   movl %eax, -56(%rbp)
   jmp   .mainBB2
.mainBB2:
   movl $0, -8(%rbp)
   movl -8(%rbp), %eax
   movl %eax, -60(%rbp)
   jmp   .mainBB3
.mainBB3:
   movl $10, -12(%rbp)
   movl -60(%rbp), %eax
   cmpl -12(%rbp), %eax
    setl %al
    movzbl %al, %eax
   movl %eax, -16(%rbp)
   cmpl    $0, -16(%rbp)
   je  .mainBB6
.mainBB5:
   jmp   .mainBB7
.mainBB7:
   movl $0, -20(%rbp)
   movl -20(%rbp), %eax
   movl %eax, -64(%rbp)
   jmp   .mainBB8
.mainBB8:
   movl $10, -24(%rbp)
   movl -64(%rbp), %eax
   cmpl -24(%rbp), %eax
    setl %al
    movzbl %al, %eax
   movl %eax, -28(%rbp)
   cmpl    $0, -28(%rbp)
   je  .mainBB11
.mainBB10:
   movl -60(%rbp), %eax
   imull -64(%rbp), %eax
   movl %eax, -32(%rbp)
   movl -32(%rbp), %eax
   movl %eax, -56(%rbp)
   jmp   .mainBB9
.mainBB9:
   movl $1, -36(%rbp)
   movl -64(%rbp), %eax
   addl -36(%rbp), %eax
   movl %eax, -40(%rbp)
   movl -40(%rbp), %eax
   movl %eax, -64(%rbp)
   jmp   .mainBB8
.mainBB11:
   jmp   .mainBB4
.mainBB4:
   movl $1, -44(%rbp)
   movl -60(%rbp), %eax
   addl -44(%rbp), %eax
   movl %eax, -48(%rbp)
   movl -48(%rbp), %eax
   movl %eax, -60(%rbp)
   jmp   .mainBB3
.mainBB6:
   movl -56(%rbp), %eax
   movl %eax, -52(%rbp)
   jmp   .mainBB1
.mainBB1:
   movl -52(%rbp), %eax
   #epilogue
   leave
   ret
