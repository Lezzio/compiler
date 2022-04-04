.text
.globl	main
 main: 
.mainBB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
  subq $16, %rsp
  movb $98, -1(%rbp)
  movb -1(%rbp), %al
  movb %al, -7(%rbp)
  movb -7(%rbp), %eax
  cmpb --1(%rbp), %eax
    setne %al
  movb %al, -2(%rbp)
  movb -2(%rbp), %al
  movb %al, -6(%rbp)
   jmp   .mainBB1
.mainBB1:
   movl -6(%rbp), %eax
   #epilogue
   leave
   ret
