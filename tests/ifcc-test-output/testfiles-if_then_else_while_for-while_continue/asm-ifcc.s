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
   movl $3, -8(%rbp)
   movl -8(%rbp), %eax
   movl %eax, -44(%rbp)
   jmp   .mainBB3
.mainBB3:
   movl $5, -12(%rbp)
   movl -40(%rbp), %eax
   cmpl -12(%rbp), %eax
    setne %al
    movzbl %al, %eax
   movl %eax, -16(%rbp)
   cmpl    $0, -16(%rbp)
   je  .mainBB4
.mainBB2:
   movl $1, -20(%rbp)
   movl -40(%rbp), %eax
   addl -20(%rbp), %eax
   movl %eax, -24(%rbp)
   movl -24(%rbp), %eax
   movl %eax, -40(%rbp)
   movl $4, -28(%rbp)
   movl -40(%rbp), %eax
   cmpl -28(%rbp), %eax
    sete %al
    movzbl %al, %eax
   movl %eax, -32(%rbp)
   cmpl    $0, -32(%rbp)
   je  .mainBB6
.mainBB5:
   jmp   .mainBB3
   jmp   .mainBB6
.mainBB6:
   movl -40(%rbp), %eax
   movl %eax, -44(%rbp)
   jmp   .mainBB3
.mainBB4:
   movl -40(%rbp), %eax
   movl %eax, -36(%rbp)
   jmp   .mainBB1
.mainBB1:
   movl -36(%rbp), %eax
   #epilogue
   leave
   ret
