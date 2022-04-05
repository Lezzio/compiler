.text
.globl	main
 main: 
	push	{r7, lr}
	subs	sp, sp, #24
	adds	r7, sp, #0
.main_0:
	movs	r3, #3
	str	r3, [r7, #4]
	ldrb	r3, [r7, #4]
	strb	r3, [r7, #5]
	movs	r3, #3
	str	r3, [r7, #9]
	ldrb	r3, [r7, #9]
	strb	r3, [r7, #10]
	ldrb	r2, [r7, #5]
	ldrb	r3, [r7, #10]
	cmp r2, r3
	ite eq
	moveq	r3, #1
	movne	r3, #0
	uxtb	r3, r3
	strb	r3, [r7, #11]
	ldr	r3, [r7, #11]
	str	r3, [r7, #15]
	ldr	r3, [r7, #15]
	mov	r0, r3
	adds	r7, r7, #24
	mov	sp, r7
	mov	sp, r7
	pop	{r7, pc}
