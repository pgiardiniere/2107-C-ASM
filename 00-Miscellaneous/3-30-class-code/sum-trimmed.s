	.file	"sum.c"
	.text
	.globl	sum
	.type	sum, @function
sum:                            # Comments go behind number signs.
	pushq	%rbp                # Store old base pointer 
	movq	%rsp, %rbp          # Make old stack pointer current base pointer
	movl	$30, -12(%rbp)      # x
	movl	$57, -8(%rbp)       # y  --- ints, so rbp is 128 bits. This puts in ram
	movl	$39, -4(%rbp)       # z
	movl	-12(%rbp), %edx     #
	movl	-8(%rbp), %eax      #    --- this set is pushing from Ram to registers
	addl	%eax, %edx          #
	movl	-4(%rbp), %eax
	addl	%edx, %eax          # register of second term contains the summed result
	popq	%rbp
	ret
