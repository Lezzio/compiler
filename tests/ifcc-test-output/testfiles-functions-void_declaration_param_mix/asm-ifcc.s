.text
.globl	func
 func: 
.func_0:
	#prologue
	pushq		%rbp
	movq		%rsp, %rbp

	#offset
	subq		$32, %rsp

	#copy
	movl		%edi, %eax
	movl		%eax, -4(%rbp)

	#copy
	movb		%sil, %al
	movb		%al, -5(%rbp)
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
	subq		$32, %rsp

	#ldconst
	movl		$1, -9(%rbp)

	#copy
	movl		-9(%rbp), %eax
	movl		%eax, -13(%rbp)

	#ldconst
	movl		$2, -17(%rbp)

	#copy
	movb		-17(%rbp), %al
	movb		%al, -18(%rbp)

	#copy
	movl		-13(%rbp), %eax
	movl		%eax, %edi

	#copy
	movb		-18(%rbp), %al
	movb		%al, %sil

	#call
	call		func
	movl		$0, %eax
	#epilogue
	leave
	ret
