.text
.globl main
 main: 
   pushq %rbp
   movq %rsp, %rbp
   movl	$8, 0(%rbp) 
   movl	0(%rbp), %eax
   popq %rbp
   ret
