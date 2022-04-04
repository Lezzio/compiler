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
   movl $1, -12(%rbp)
   movl -40(%rbp), %eax
   cmpl -12(%rbp), %eax
    sete %al
    movzbl %al, %eax
   movl %eax, -16(%rbp)
   cmpl    $0, -16(%rbp)
   je  .mainBB3
.mainBB2:
   movl $3, -20(%rbp)
   movl -44(%rbp), %eax
   cmpl -20(%rbp), %eax
    sete %al
    movzbl %al, %eax
   movl %eax, -24(%rbp)
   cmpl    $0, -24(%rbp)
   je  .mainBB6
.mainBB4:
   movl $5, -28(%rbp)
   movl -28(%rbp), %eax
   movl %eax, -40(%rbp)
   jmp   .mainBB5
.mainBB6:
   movl $6, -32(%rbp)
   movl -32(%rbp), %eax
   movl %eax, -40(%rbp)
   jmp   .mainBB5
.mainBB5:
   jmp   .mainBB3
.mainBB3:
   movl -40(%rbp), %eax
   movl %eax, -36(%rbp)
   jmp   .mainBB1
.mainBB1:
   movl -36(%rbp), %eax
   #epilogue
   leave
   ret
