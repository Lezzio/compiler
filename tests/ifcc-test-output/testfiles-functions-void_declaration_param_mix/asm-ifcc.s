.text
.globl	func
 func: 
.func_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$16, %rsp
	#epilogue
	nop
	leave
	ret
.text
.globl	main
 main: 
.main_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$16, %rsp

	#ldconst
	movl		$1, -4(%rbp)

	#copy
	movl		-4(%rbp), %eax
	movl		%eax, -8(%rbp)

	#ldconst
	movl		$2, -12(%rbp)

	#copy
	movb		-12(%rbp), %al
	movb		%al, -13(%rbp)

	#copy
	movl		-8(%rbp), %eax
	movl		%eax, %edi

	#copy
	movb		-13(%rbp), %al
	movb		%al, %sil

	#call
	call		func
	movl		$0, %eax
	#epilogue
	leave
	ret
