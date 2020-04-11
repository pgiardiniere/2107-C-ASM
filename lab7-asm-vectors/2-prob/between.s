	.file	"between.c"
	.text
	.globl	between
	.type	between, @function
between:
.LFB0:
	pushq	%rbp 				# push base pointer register (rbp) current val onto stack
	movq	%rsp, %rbp 			# move base pointer (bottom of stack frame) to top of frame (rsp)
	movl	%edi, -4(%rbp) 		# Pass args: move long (4 bytes) from edi register into 4th byte pos of base pointer
	movl	%esi, -8(%rbp) 		# Pass args: move long from esi register into 2nd pos of base pointer
	movl	%edx, -12(%rbp) 	# Pass args: move long from edx register into 3rd pos of base pointer
	movl	-4(%rbp), %eax 		# Move 1st long from rbp into eax
	cmpl	-8(%rbp), %eax 		# Compare Longs 2 and 1, i.e. compare 2nd long of rbp to eax
	jle	.L2 					# to .L2 if prior cmpl was <=
	movl	-4(%rbp), %eax 		# Move 2nd long from rbp into eax
	cmpl	-12(%rbp), %eax 	# Compare Longs 3 and 2
	jge	.L2 					# Jump if >= to .L2
	movl	$1, %eax 			# Put 1 (true) into eax (return register)
	jmp	.L3 					# Unconditional jump to .L3
.L2:
	movl	$0, %eax 			# Put 0 (false) into eax (return register)
.L3:
	popq	%rbp 				# function complete, Pop the stack to get base pointer register to prior execution point
	ret	 						# Return execution to callee function (as eax contains val)
