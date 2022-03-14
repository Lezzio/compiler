.text
.globl	main
 main: 
   pushq %rbp
   movq %rsp, %rbp
   movl	$2, 0(%rbp) 
   movl	$3, 0(%rbp) 
   movl	$1, 0(%rbp) 
   movl 0(%rbp), %eax
   addl 0(%rbp), %eax
   movl	%eax, 0(%rbp) 
   movl 0(%rbp), %eax
   addl 0(%rbp), %eax
   movl	%eax, 0(%rbp) 
   movl	0(%rbp), %eax
   movl	%eax,0(%rbp) 
   movl	0(%rbp), %eax
   popq %rbp
   ret
