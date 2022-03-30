	.file	"test.c"
	.text
	.globl	test
	.type	test, @function
test:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%ecx, %eax
	movl	%r8d, %r10d
	movl	%r9d, %r8d
	movl	%edi, %ecx
	movb	%cl, -20(%rbp)
	movl	%esi, %ecx
	movb	%cl, -24(%rbp)
	movb	%dl, -28(%rbp)
	movb	%al, -32(%rbp)
	movl	%r10d, %eax
	movb	%al, -36(%rbp)
	movl	%r8d, %eax
	movb	%al, -40(%rbp)
	movzbl	-20(%rbp), %eax
	movb	%al, -6(%rbp)
	movzbl	-24(%rbp), %eax
	movb	%al, -5(%rbp)
	movzbl	-28(%rbp), %eax
	movb	%al, -4(%rbp)
	movzbl	-32(%rbp), %eax
	movb	%al, -3(%rbp)
	movzbl	-36(%rbp), %eax
	movb	%al, -2(%rbp)
	movzbl	-40(%rbp), %eax
	movb	%al, -1(%rbp)
	movzbl	-6(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	test, .-test
	.globl	fibo
	.type	fibo, @function
fibo:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jg	.L4
	movl	$0, %eax
	jmp	.L5
.L4:
	cmpl	$1, -4(%rbp)
	jne	.L6
	movl	$1, %eax
	jmp	.L5
.L6:
	movl	-4(%rbp), %eax
.L5:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	fibo, .-fibo
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movb	$1, -6(%rbp)
	movb	$2, -5(%rbp)
	movb	$3, -4(%rbp)
	movb	$4, -3(%rbp)
	movb	$5, -2(%rbp)
	movb	$6, -1(%rbp)
	movsbl	-1(%rbp), %r8d
	movsbl	-2(%rbp), %edi
	movsbl	-3(%rbp), %ecx
	movsbl	-4(%rbp), %edx
	movsbl	-5(%rbp), %esi
	movsbl	-6(%rbp), %eax
	movl	%r8d, %r9d
	movl	%edi, %r8d
	movl	%eax, %edi
	call	test
	movsbl	-6(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
