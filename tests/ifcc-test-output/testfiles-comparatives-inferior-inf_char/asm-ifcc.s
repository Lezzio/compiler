.text
.globl	main
 main: 
.mainBB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
  subq $16, %rsp
  movb $97, -1(%rbp)
  movb -1(%rbp), %al
  movb %al, -8(%rbp)
  movb $98, -2(%rbp)
  movb -2(%rbp), %al
  movb %al, -9(%rbp)
  movb -8(%rbp), %eax
  cmpb -9(%rbp), %eax
    setl %al
  movb %al, -3(%rbp)
  movb -3(%rbp), %al
  movb %al, -7(%rbp)
   jmp   .mainBB1
.mainBB1:
   movl -7(%rbp), %eax
   #epilogue
   leave
   ret
