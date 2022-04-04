Error detected can't declare symbol twice ADD_SYMBOL
.text
.globl	func
 func: 
.funcBB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
  subq $32, %rsp
   movl --1(%rbp), %eax
   addl --1(%rbp), %eax
   movl %eax, -4(%rbp)
   movl -4(%rbp), %eax
   movl %eax, -8(%rbp)
   jmp   .funcBB1
.funcBB1:
   movl -8(%rbp), %eax
   #epilogue
   leave
   ret
.text
.globl	main
 main: 
.mainBB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
  subq $32, %rsp
   movl $1, -4(%rbp)
   movl -4(%rbp), %eax
   movl %eax, -20(%rbp)
   movl $2, -12(%rbp)
   movl -12(%rbp), %eax
   movl %eax, -24(%rbp)
   movl -20(%rbp), %eax
   movl %eax, %edi
   movl -24(%rbp), %eax
   movl %eax, %esi
   call func
   movl %eax, -16(%rbp)
   movl -16(%rbp), %eax
   movl %eax, -28(%rbp)
   movl -28(%rbp), %eax
   movl %eax, -8(%rbp)
   jmp   .mainBB1
.mainBB1:
   movl -8(%rbp), %eax
   #epilogue
   leave
   ret
