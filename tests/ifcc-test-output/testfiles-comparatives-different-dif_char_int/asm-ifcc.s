.text
.globl	main
 main: 
.mainBB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
  subq $32, %rsp
   movl $3, -4(%rbp)
   movl -4(%rbp), %eax
   movl %eax, -20(%rbp)
   movl $2, -8(%rbp)
  movb -8(%rbp), %al
  movb %al, -21(%rbp)
   movl -21(%rbp), %eax
   cmpl -20(%rbp), %eax
    setne %al
    movzbl %al, %eax
   movl %eax, -12(%rbp)
   movl -12(%rbp), %eax
   movl %eax, -16(%rbp)
   jmp   .mainBB1
.mainBB1:
   movl -16(%rbp), %eax
   #epilogue
   leave
   ret
