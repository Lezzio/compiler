.text
.globl	main
 main: 
   #prologue
   pushq %rbp
   movq %rsp, %rbp
   movl $1080, -4(%rbp)
  movb -4(%rbp), %al
  movb %al, -5(%rbp)
  movb -5(%rbp), %al
   #epilogue
   popq %rbp
   ret
