	.file	"hw01-guessing-game.c"
	.section	.rodata
.LC0:
	.string	"Make a guess: "
.LC1:
	.string	"%d"
.LC2:
	.string	"No guess lower!"
.LC3:
	.string	"No guess higher!"
.LC4:
	.string	"You got it!"
	.text
	.globl	guessing_random_number
	.type	guessing_random_number, @function
guessing_random_number:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$1, -8(%rbp)
	movl	$50, -12(%rbp)
	movl	$1, -4(%rbp)
	call	rand
	movl	-8(%rbp), %edx
	movl	-12(%rbp), %ecx
	subl	%edx, %ecx
	movl	%ecx, %edx
	leal	1(%rdx), %ecx
	cltd
	idivl	%ecx
	movl	-8(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -16(%rbp)
.L6:
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-20(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jle	.L2
	movl	$.LC2, %edi
	call	puts
	addl	$1, -4(%rbp)
	jmp	.L3
.L2:
	movl	-20(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jge	.L4
	movl	$.LC3, %edi
	call	puts
	addl	$1, -4(%rbp)
	jmp	.L3
.L4:
	movl	-20(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jne	.L3
	movl	$.LC4, %edi
	call	puts
	jmp	.L5
.L3:
	movl	-20(%rbp), %eax
	cmpl	%eax, -16(%rbp)
	jne	.L6
.L5:
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	guessing_random_number, .-guessing_random_number
	.section	.rodata
	.align 8
.LC5:
	.string	"==========================\nCPU Says: Pick a number 1-50\n=========================="
	.align 8
.LC6:
	.string	"================================================="
	.align 8
.LC7:
	.string	"|Here are the results of your guessing abilities|"
.LC8:
	.string	"Game %d took you %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$5, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L9
.L10:
	movl	$.LC5, %edi
	call	puts
	movl	$0, %eax
	call	guessing_random_number
	movl	%eax, -12(%rbp)
	movl	-4(%rbp), %eax
	cltq
	movl	-12(%rbp), %edx
	movl	%edx, -32(%rbp,%rax,4)
	addl	$1, -4(%rbp)
.L9:
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jl	.L10
	movl	$.LC6, %edi
	call	puts
	movl	$.LC7, %edi
	call	puts
	movl	$.LC6, %edi
	call	puts
	movl	$0, -4(%rbp)
	jmp	.L11
.L12:
	movl	-4(%rbp), %eax
	cltq
	movl	-32(%rbp,%rax,4), %edx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC8, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -4(%rbp)
.L11:
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jl	.L12
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
