.text
.globl main
 main: 
   pushq %rbp
   movq %rsp, %rbp
 	movl	$0, %eax
   popq %rbp #restore %rbp from the stack
 	ret
