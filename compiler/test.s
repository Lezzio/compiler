.text
.globl	main
 main: 
   #prologue
   pushq %rbp
   movq %rsp, %rbp
    movl $17, -4(%rbp)
    movl -4(%rbp), %eax
    movl %eax, -32(%rbp)
    movl $42, -8(%rbp)
    movl -8(%rbp), %eax
    movl %eax, -36(%rbp)
    movl -32(%rbp), %eax
    imul -32(%rbp), %eax
    movl %eax, -12(%rbp)
    movl -36(%rbp), %eax
    imul -36(%rbp), %eax
    movl %eax, -16(%rbp)
    movl -12(%rbp), %eax
    addl -16(%rbp), %eax
    movl %eax, -20(%rbp)
    movl $1, -24(%rbp)
    movl -20(%rbp), %eax
    addl -24(%rbp), %eax
    movl %eax, -28(%rbp)
    movl -28(%rbp), %eax
    movl %eax, -40(%rbp)
    movl -40(%rbp), %eax
   #epilogue
   popq %rbp
   ret
