	.file	"main.c"
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jge	.L2
	movl	-8(%rbp), %eax
	subl	-4(%rbp), %eax
	jmp	.L3
.L2:
	movl	-4(%rbp), %eax
	subl	-8(%rbp), %eax
.L3:
	popq	%rbp
	ret

