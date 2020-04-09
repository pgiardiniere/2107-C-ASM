	.file	"dblit.c"
	.text
	.globl	dblit
	.type	dblit, @function
dblit:
	pushq	%rbp 				# push base pointer register (rbp) current val onto stack
	movq	%rsp, %rbp 			# move base pointer (bottom of stack frame) to top of frame (rsp)
	movq	%rdi, -24(%rbp) 	# Pass args: move quad-word (8 bytes) from rdi register into rbp, with offset = -24
	movl	%esi, -28(%rbp) 	# Pass args: move long (4 bytes) from esi register into rbp, offset = -28
	movl	$0, -4(%rbp) 		# Move integer literal 0 into 4th byte position of rbp
	jmp	.L2 					# Unconditional execution jump to .L2
.L3:
	movl	-4(%rbp), %eax 		# Move long at 4th byte pos in rbp reg into eax register
	cltq 						# Extend eax to quadword (8-byte val), eax -> rax   (probably casting an int as long)
	leaq	0(,%rax,4), %rdx 	# load effective address quadword. 0 + 4y: multiply rax by 4. Store result into rdx
	movq	-24(%rbp), %rax 	# move val stored at rbp less 24 into rax register
	addq	%rdx, %rax 			# add quadwords stored in rdx, rax. store in rax.
	movl	(%rax), %edx 		# move long in rax into edx
	movl	-4(%rbp), %eax 		# move long at rbp less 4 into eax register
	cltq 						# Extend eax to quadword again.
	leaq	0(,%rax,4), %rcx 	# load effective address quadword. 0 + 4y: multiply rax by 4. Store result into rcx
	movq	-24(%rbp), %rax 	# move quadword at rbp less 24 into rax
	addq	%rcx, %rax 			# add quadwords in rcx, rax
	addl	%edx, %edx 			# add longs in edx, edx. store in edx (so, the doubling required)
	movl	%edx, (%rax) 		# move long in edx to rax
	addl	$1, -4(%rbp) 		# add int literal 1 to base pointer less 4 positions, i.e. to the start of the next byte
.L2:
	movl	-4(%rbp), %eax 		# Move long at 4th byte pos in rbp reg into eax register
	cmpl	-28(%rbp), %eax 	# Compare long at -28th pos rbp to eax register
	jl	.L3 					# Jump if prior cmpl eval'd < to .L3
	nop
	popq	%rbp 				# function complete, Pop the stack to get base pointer register to prior execution point
	ret 						# Return execution to callee function
