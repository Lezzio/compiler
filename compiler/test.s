.text
.globl	main
 main: 
   pushq %rbp
   movq %rsp, %rbp
   movl	$2, -4(%rbp) 
   movl	$3, -8(%rbp) 
   movl -4(%rbp), %eax
   imul -8(%rbp), %eax
   movl    %eax, -12(%rbp) 
   movl	$6, -16(%rbp) 
   movl	$9, -20(%rbp) 
   movl -16(%rbp), %eax
   subl -20(%rbp), %eax
   movl	%eax, -24(%rbp) 
   movl -12(%rbp), %eax
   addl -24(%rbp), %eax
   movl	%eax, -28(%rbp) 
   movl	-28(%rbp), %eax
   movl	%eax,-32(%rbp) 
   movl	-32(%rbp), %eax
   popq %rbp
   ret
