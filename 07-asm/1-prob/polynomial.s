	.file	"polynomial.c"
	.text
	.globl	polynomial
	.type	polynomial, @function
polynomial:
	pushq	%rbp
	movq	%rsp, %rbp

	# ----- C-generated -----
	# movl	%edi, -4(%rbp)
	# movl	%esi, -8(%rbp)
	# movl	%edx, -12(%rbp)
	# movl	%ecx, -16(%rbp)
	# movl	-4(%rbp), %eax
	# imull	-16(%rbp), %eax
	# movl	%eax, %edx
	# movl	-8(%rbp), %eax
	# addl	%edx, %eax
	# imull	-16(%rbp), %eax
	# movl	%eax, %edx
	# movl	-12(%rbp), %eax
	# addl	%edx, %eax

	# movl %edi, %eax 		# edi contains a
	# movl %esi, %eax 		# esi contains b
	# movl %edx, %eax 		# edx contains c
	# movl %ecx, %eax 		# ecx contains x
	
	movl 	%edx, 	%eax
	imull 	%ecx, 	%esi
	addl 	%esi, 	%eax
	imull 	%ecx, 	%ecx 	# square x
	imull 	%ecx, 	%edi 	# ax^2
	addl 	%edi, 	%eax
	
	popq	%rbp
	ret
