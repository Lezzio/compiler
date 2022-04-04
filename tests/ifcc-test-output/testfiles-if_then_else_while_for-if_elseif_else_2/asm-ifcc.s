.text
.globl	main
 main: 
.mainBB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
  subq $48, %rsp
   movl $2, -4(%rbp)
   movl -4(%rbp), %eax
   movl %eax, -40(%rbp)
   movl $1, -8(%rbp)
   movl -40(%rbp), %eax
   cmpl -8(%rbp), %eax
    sete %al
    movzbl %al, %eax
   movl %eax, -12(%rbp)
   cmpl    $0, -12(%rbp)
   je  .mainBB4
.mainBB2:
   movl $12, -16(%rbp)
   movl -16(%rbp), %eax
   movl %eax, -40(%rbp)
   jmp   .mainBB3
.mainBB4:
   movl $2, -20(%rbp)
   movl -40(%rbp), %eax
   cmpl -20(%rbp), %eax
    sete %al
    movzbl %al, %eax
   movl %eax, -24(%rbp)
   cmpl    $0, -24(%rbp)
   je  .mainBB7
.mainBB5:
   movl $9, -28(%rbp)
   movl -28(%rbp), %eax
   movl %eax, -40(%rbp)
   jmp   .mainBB6
.mainBB7:
   movl $10, -32(%rbp)
   movl -32(%rbp), %eax
   movl %eax, -40(%rbp)
   jmp   .mainBB6
.mainBB6:
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
