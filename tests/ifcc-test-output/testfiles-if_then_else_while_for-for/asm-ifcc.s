.text
.globl	main
 main: 
.mainBB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
  subq $48, %rsp
   movl $1, -4(%rbp)
   movl -4(%rbp), %eax
   movl %eax, -40(%rbp)
   jmp   .mainBB2
.mainBB2:
   movl $0, -8(%rbp)
   movl -8(%rbp), %eax
   movl %eax, -44(%rbp)
   jmp   .mainBB3
.mainBB3:
   movl $10, -12(%rbp)
   movl -44(%rbp), %eax
   cmpl -12(%rbp), %eax
    setl %al
    movzbl %al, %eax
   movl %eax, -16(%rbp)
   cmpl    $0, -16(%rbp)
   je  .mainBB6
.mainBB5:
   movl $1, -20(%rbp)
   movl -40(%rbp), %eax
   addl -20(%rbp), %eax
   movl %eax, -24(%rbp)
   movl -24(%rbp), %eax
   movl %eax, -40(%rbp)
   jmp   .mainBB4
.mainBB4:
   movl $1, -28(%rbp)
   movl -44(%rbp), %eax
   addl -28(%rbp), %eax
   movl %eax, -32(%rbp)
   movl -32(%rbp), %eax
   movl %eax, -44(%rbp)
   jmp   .mainBB3
.mainBB6:
   movl -40(%rbp), %eax
   movl %eax, -36(%rbp)
   jmp   .mainBB1
.mainBB1:
   movl -36(%rbp), %eax
   #epilogue
   leave
   ret
