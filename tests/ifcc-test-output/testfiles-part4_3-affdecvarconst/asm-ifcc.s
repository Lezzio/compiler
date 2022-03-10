.text
.globl main
 main: 
   pushq %rbp
   movq %rsp, %rbp
   movl	$666, 0(%rbp) 
   movl	0(%rbp), %eax
   popq %rbp
   ret
