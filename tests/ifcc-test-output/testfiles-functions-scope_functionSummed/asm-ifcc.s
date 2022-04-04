Error detected can't declare symbol twice ADD_SYMBOL
Error detected can't declare symbol twice ADD_SYMBOL
.text
.globl	func
 func: 
.funcBB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
  subq $48, %rsp
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
.globl	func2
 func2: 
.func2BB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
  subq $48, %rsp
   movl --1(%rbp), %eax
   addl --1(%rbp), %eax
   movl %eax, -4(%rbp)
   movl -4(%rbp), %eax
   movl %eax, -8(%rbp)
   jmp   .func2BB1
.func2BB1:
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
  subq $48, %rsp
   movl $1, -4(%rbp)
   movl -4(%rbp), %eax
   movl %eax, -36(%rbp)
   movl $2, -12(%rbp)
   movl -12(%rbp), %eax
   movl %eax, -40(%rbp)
   movl $3, -16(%rbp)
   movl -16(%rbp), %eax
   movl %eax, -44(%rbp)
   movl $4, -20(%rbp)
   movl -20(%rbp), %eax
   movl %eax, -48(%rbp)
   movl -36(%rbp), %eax
   movl %eax, %edi
   movl -40(%rbp), %eax
   movl %eax, %esi
   call func
   movl %eax, -24(%rbp)
   movl -44(%rbp), %eax
   movl %eax, %edi
   movl -48(%rbp), %eax
   movl %eax, %esi
   call func2
   movl %eax, -28(%rbp)
   movl -24(%rbp), %eax
   addl -28(%rbp), %eax
   movl %eax, -32(%rbp)
   movl -32(%rbp), %eax
   movl %eax, -52(%rbp)
   movl -52(%rbp), %eax
   movl %eax, -8(%rbp)
   jmp   .mainBB1
.mainBB1:
   movl -8(%rbp), %eax
   #epilogue
   leave
   ret
