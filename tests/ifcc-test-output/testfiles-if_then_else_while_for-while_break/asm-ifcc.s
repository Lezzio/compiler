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
   movl %eax, -36(%rbp)
   jmp   .mainBB3
.mainBB3:
   movl $5, -8(%rbp)
   movl -36(%rbp), %eax
   cmpl -8(%rbp), %eax
    setne %al
    movzbl %al, %eax
   movl %eax, -12(%rbp)
   cmpl    $0, -12(%rbp)
   je  .mainBB4
.mainBB2:
   movl $1, -16(%rbp)
   movl -36(%rbp), %eax
   addl -16(%rbp), %eax
   movl %eax, -20(%rbp)
   movl -20(%rbp), %eax
   movl %eax, -36(%rbp)
   movl $4, -24(%rbp)
   movl -36(%rbp), %eax
   cmpl -24(%rbp), %eax
    sete %al
    movzbl %al, %eax
   movl %eax, -28(%rbp)
   cmpl    $0, -28(%rbp)
   je  .mainBB6
.mainBB5:
   jmp   .mainBB4
   jmp   .mainBB6
.mainBB6:
   jmp   .mainBB3
.mainBB4:
   movl -36(%rbp), %eax
   movl %eax, -32(%rbp)
   jmp   .mainBB1
.mainBB1:
   movl -32(%rbp), %eax
   #epilogue
   leave
   ret
