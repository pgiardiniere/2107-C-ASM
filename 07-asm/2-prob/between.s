	.file	"between.c"
	.text
	.globl	between
	.type	between, @function
between:
.LFB0:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax 		# Compare Longs ___ and ___ 
	jle	.L2 					# Jump if <= to .L2
	movl	-4(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jge	.L2 					# Jump if >= to .L2
	movl	$1, %eax
	jmp	.L3 					# Unconditional jump to .L3
.L2:
	movl	$0, %eax
.L3:
	popq	%rbp
	ret
