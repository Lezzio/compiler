.text
.globl	main
 main: 
.mainBB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
  subq $16, %rsp
   movl $1, -4(%rbp)
   movl -4(%rbp), %eax
   movl %eax, -16(%rbp)
   movl -16(%rbp), %eax
   cmpl --1(%rbp), %eax
    setg %al
    movzbl %al, %eax
   movl %eax, -8(%rbp)
   movl -8(%rbp), %eax
   movl %eax, -12(%rbp)
   jmp   .mainBB1
.mainBB1:
   movl -12(%rbp), %eax
   #epilogue
   leave
   ret