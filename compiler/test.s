.text
.globl	test2
 test2: 
.test2BB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
  subq $80, %rsp
   movl $8, -4(%rbp)
   movl -4(%rbp), %eax
   movl %eax, -72(%rbp)
   movl -72(%rbp), %eax
   movl %eax, -8(%rbp)
   jmp   .test2BB1
.test2BB1:
   movl -8(%rbp), %eax
   #epilogue
   leave
   ret
.text
.globl	test
 test: 
.testBB0:
   #prologue
   pushq %rbp
   movq %rsp, %rbp
  subq $80, %rsp
   movl $4, -4(%rbp)
   movl -4(%rbp), %eax
   movl %eax, -76(%rbp)
   movl $9, -16(%rbp)
   movl -16(%rbp), %eax
   movl %eax, -72(%rbp)
   movl $5, -20(%rbp)
   movl -20(%rbp), %eax
   movl %eax, %edi
   call test2
   movl %eax, -24(%rbp)
   movl -76(%rbp), %eax
   movl %eax, -8(%rbp)
   jmp   .testBB1
.testBB1:
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
  subq $80, %rsp
   movl $0, -4(%rbp)
   movl -4(%rbp), %eax
   movl %eax, -80(%rbp)
   movl $5, -16(%rbp)
   movl -16(%rbp), %eax
   movl %eax, %edi
   call test
   movl %eax, -20(%rbp)
   movl -20(%rbp), %eax
   movl %eax, -84(%rbp)
   movl $7, -24(%rbp)
   movl -24(%rbp), %eax
   movl %eax, %edi
   call test2
   movl %eax, -44(%rbp)
   movl -44(%rbp), %eax
   movl %eax, -88(%rbp)
   movl $5, -48(%rbp)
   movl -48(%rbp), %eax
   movl %eax, %edi
   call test
   movl %eax, -52(%rbp)
   movl -52(%rbp), %eax
   movl %eax, -76(%rbp)
   movl $8, -56(%rbp)
   movl -56(%rbp), %eax
   movl %eax, %edi
   call test
   movl %eax, -60(%rbp)
   movl -60(%rbp), %eax
   movl %eax, -72(%rbp)
   movl $5, -64(%rbp)
   movl -64(%rbp), %eax
   movl %eax, %edi
   call test
   movl %eax, -68(%rbp)
   movl -76(%rbp), %eax
   movl %eax, -8(%rbp)
   jmp   .mainBB1
.mainBB1:
   movl -8(%rbp), %eax
   #epilogue
   leave
   ret
