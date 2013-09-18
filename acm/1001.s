	.file	"1001.c"
	.section	.rodata
.LC0:
	.string	"%d %d"
.LC1:
	.string	"%d"
.LC2:
	.string	"%d %d %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$4160, %esp
	movl	$0, 44(%esp)
.L26:
	leal	32(%esp), %eax
	movl	%eax, 8(%esp)
	leal	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	__isoc99_scanf
	movl	28(%esp), %eax
	testl	%eax, %eax
	jne	.L2
	movl	32(%esp), %eax
	testl	%eax, %eax
	je	.L30
.L2:
	movl	$0, 36(%esp)
	jmp	.L4
.L7:
	movl	$0, 40(%esp)
	jmp	.L5
.L6:
	movl	36(%esp), %eax
	imull	$22, %eax, %edx
	movl	40(%esp), %eax
	addl	%edx, %eax
	movl	$0, 288(%esp,%eax,4)
	movl	36(%esp), %eax
	imull	$22, %eax, %edx
	movl	40(%esp), %eax
	addl	%edx, %eax
	movl	$0, 2224(%esp,%eax,4)
	addl	$1, 40(%esp)
.L5:
	cmpl	$21, 40(%esp)
	jle	.L6
	addl	$1, 36(%esp)
.L4:
	cmpl	$21, 36(%esp)
	jle	.L7
	movl	$1, 36(%esp)
	jmp	.L8
.L11:
	movl	$1, 40(%esp)
	jmp	.L9
.L10:
	leal	288(%esp), %eax
	movl	36(%esp), %edx
	imull	$22, %edx, %ecx
	movl	40(%esp), %edx
	addl	%ecx, %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	__isoc99_scanf
	addl	$1, 40(%esp)
.L9:
	movl	32(%esp), %eax
	addl	$1, %eax
	cmpl	40(%esp), %eax
	jg	.L10
	addl	$1, 36(%esp)
.L8:
	movl	28(%esp), %eax
	addl	$1, %eax
	cmpl	36(%esp), %eax
	jg	.L11
	movl	$1, 36(%esp)
	jmp	.L12
.L20:
	movl	$1, 40(%esp)
	jmp	.L13
.L19:
	movl	36(%esp), %eax
	addl	$1, %eax
	imull	$22, %eax, %edx
	movl	40(%esp), %eax
	addl	%edx, %eax
	movl	288(%esp,%eax,4), %eax
	testl	%eax, %eax
	je	.L14
	movl	36(%esp), %eax
	imull	$22, %eax, %edx
	movl	40(%esp), %eax
	addl	%edx, %eax
	movl	288(%esp,%eax,4), %edx
	movl	36(%esp), %eax
	addl	$1, %eax
	imull	$22, %eax, %ecx
	movl	40(%esp), %eax
	addl	%ecx, %eax
	movl	288(%esp,%eax,4), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	bijiao
	cmpl	$1, %eax
	jne	.L14
	movl	36(%esp), %eax
	imull	$22, %eax, %edx
	movl	40(%esp), %eax
	addl	%edx, %eax
	movl	2224(%esp,%eax,4), %edx
	movl	36(%esp), %eax
	addl	$1, %eax
	imull	$22, %eax, %ecx
	movl	40(%esp), %eax
	addl	%ecx, %eax
	movl	288(%esp,%eax,4), %eax
	addl	%eax, %edx
	movl	36(%esp), %eax
	imull	$22, %eax, %ecx
	movl	40(%esp), %eax
	addl	%ecx, %eax
	movl	%edx, 2224(%esp,%eax,4)
.L14:
	movl	36(%esp), %eax
	subl	$1, %eax
	imull	$22, %eax, %edx
	movl	40(%esp), %eax
	addl	%edx, %eax
	movl	288(%esp,%eax,4), %eax
	testl	%eax, %eax
	je	.L15
	movl	36(%esp), %eax
	imull	$22, %eax, %edx
	movl	40(%esp), %eax
	addl	%edx, %eax
	movl	288(%esp,%eax,4), %edx
	movl	36(%esp), %eax
	subl	$1, %eax
	imull	$22, %eax, %ecx
	movl	40(%esp), %eax
	addl	%ecx, %eax
	movl	288(%esp,%eax,4), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	bijiao
	cmpl	$1, %eax
	jne	.L15
	movl	36(%esp), %eax
	imull	$22, %eax, %edx
	movl	40(%esp), %eax
	addl	%edx, %eax
	movl	2224(%esp,%eax,4), %edx
	movl	36(%esp), %eax
	subl	$1, %eax
	imull	$22, %eax, %ecx
	movl	40(%esp), %eax
	addl	%ecx, %eax
	movl	288(%esp,%eax,4), %eax
	addl	%eax, %edx
	movl	36(%esp), %eax
	imull	$22, %eax, %ecx
	movl	40(%esp), %eax
	addl	%ecx, %eax
	movl	%edx, 2224(%esp,%eax,4)
.L15:
	movl	40(%esp), %eax
	leal	1(%eax), %edx
	movl	36(%esp), %eax
	imull	$22, %eax, %eax
	addl	%edx, %eax
	movl	288(%esp,%eax,4), %eax
	testl	%eax, %eax
	je	.L16
	movl	36(%esp), %eax
	imull	$22, %eax, %edx
	movl	40(%esp), %eax
	addl	%edx, %eax
	movl	288(%esp,%eax,4), %edx
	movl	40(%esp), %eax
	leal	1(%eax), %ecx
	movl	36(%esp), %eax
	imull	$22, %eax, %eax
	addl	%ecx, %eax
	movl	288(%esp,%eax,4), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	bijiao
	cmpl	$1, %eax
	jne	.L16
	movl	36(%esp), %eax
	imull	$22, %eax, %edx
	movl	40(%esp), %eax
	addl	%edx, %eax
	movl	2224(%esp,%eax,4), %edx
	movl	40(%esp), %eax
	leal	1(%eax), %ecx
	movl	36(%esp), %eax
	imull	$22, %eax, %eax
	addl	%ecx, %eax
	movl	288(%esp,%eax,4), %eax
	addl	%eax, %edx
	movl	36(%esp), %eax
	imull	$22, %eax, %ecx
	movl	40(%esp), %eax
	addl	%ecx, %eax
	movl	%edx, 2224(%esp,%eax,4)
.L16:
	movl	40(%esp), %eax
	leal	-1(%eax), %edx
	movl	36(%esp), %eax
	imull	$22, %eax, %eax
	addl	%edx, %eax
	movl	288(%esp,%eax,4), %eax
	testl	%eax, %eax
	je	.L17
	movl	36(%esp), %eax
	imull	$22, %eax, %edx
	movl	40(%esp), %eax
	addl	%edx, %eax
	movl	288(%esp,%eax,4), %edx
	movl	40(%esp), %eax
	leal	-1(%eax), %ecx
	movl	36(%esp), %eax
	imull	$22, %eax, %eax
	addl	%ecx, %eax
	movl	288(%esp,%eax,4), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	bijiao
	cmpl	$1, %eax
	jne	.L17
	movl	36(%esp), %eax
	imull	$22, %eax, %edx
	movl	40(%esp), %eax
	addl	%edx, %eax
	movl	2224(%esp,%eax,4), %edx
	movl	40(%esp), %eax
	leal	-1(%eax), %ecx
	movl	36(%esp), %eax
	imull	$22, %eax, %eax
	addl	%ecx, %eax
	movl	288(%esp,%eax,4), %eax
	addl	%eax, %edx
	movl	36(%esp), %eax
	imull	$22, %eax, %ecx
	movl	40(%esp), %eax
	addl	%ecx, %eax
	movl	%edx, 2224(%esp,%eax,4)
.L17:
	movl	36(%esp), %eax
	imull	$22, %eax, %edx
	movl	40(%esp), %eax
	addl	%edx, %eax
	movl	2224(%esp,%eax,4), %eax
	testl	%eax, %eax
	jns	.L18
	movl	36(%esp), %eax
	imull	$22, %eax, %edx
	movl	40(%esp), %eax
	addl	%edx, %eax
	movl	2224(%esp,%eax,4), %eax
	movl	%eax, %edx
	negl	%edx
	movl	36(%esp), %eax
	imull	$22, %eax, %ecx
	movl	40(%esp), %eax
	addl	%ecx, %eax
	movl	%edx, 2224(%esp,%eax,4)
.L18:
	addl	$1, 40(%esp)
.L13:
	movl	32(%esp), %eax
	addl	$1, %eax
	cmpl	40(%esp), %eax
	jg	.L19
	addl	$1, 36(%esp)
.L12:
	movl	28(%esp), %eax
	addl	$1, %eax
	cmpl	36(%esp), %eax
	jg	.L20
	movl	380(%esp), %edx
	movl	44(%esp), %eax
	movl	%edx, 208(%esp,%eax,4)
	movl	44(%esp), %eax
	movl	$1, 48(%esp,%eax,4)
	movl	44(%esp), %eax
	movl	$1, 128(%esp,%eax,4)
	movl	$1, 36(%esp)
	jmp	.L21
.L25:
	movl	$1, 40(%esp)
	jmp	.L22
.L24:
	movl	36(%esp), %eax
	imull	$22, %eax, %edx
	movl	40(%esp), %eax
	addl	%edx, %eax
	movl	2224(%esp,%eax,4), %edx
	movl	44(%esp), %eax
	movl	208(%esp,%eax,4), %eax
	cmpl	%eax, %edx
	jle	.L23
	movl	36(%esp), %eax
	imull	$22, %eax, %edx
	movl	40(%esp), %eax
	addl	%edx, %eax
	movl	2224(%esp,%eax,4), %edx
	movl	44(%esp), %eax
	movl	%edx, 208(%esp,%eax,4)
	movl	44(%esp), %eax
	movl	36(%esp), %edx
	movl	%edx, 48(%esp,%eax,4)
	movl	44(%esp), %eax
	movl	40(%esp), %edx
	movl	%edx, 128(%esp,%eax,4)
.L23:
	addl	$1, 40(%esp)
.L22:
	movl	32(%esp), %eax
	addl	$1, %eax
	cmpl	40(%esp), %eax
	jg	.L24
	addl	$1, 36(%esp)
.L21:
	movl	28(%esp), %eax
	addl	$1, %eax
	cmpl	36(%esp), %eax
	jg	.L25
	addl	$1, 44(%esp)
	jmp	.L26
.L30:
	nop
.L29:
.L3:
	movl	$0, 36(%esp)
	jmp	.L27
.L28:
	movl	36(%esp), %eax
	movl	208(%esp,%eax,4), %ecx
	movl	36(%esp), %eax
	movl	128(%esp,%eax,4), %edx
	movl	36(%esp), %eax
	movl	48(%esp,%eax,4), %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	addl	$1, 36(%esp)
.L27:
	movl	36(%esp), %eax
	cmpl	44(%esp), %eax
	jne	.L28
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	bijiao
	.type	bijiao, @function
bijiao:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	cmpl	$0, 8(%ebp)
	jle	.L32
	cmpl	$0, 12(%ebp)
	jns	.L32
	movl	$1, %eax
	jmp	.L33
.L32:
	cmpl	$0, 8(%ebp)
	jns	.L34
	cmpl	$0, 12(%ebp)
	jle	.L34
	movl	$1, %eax
	jmp	.L33
.L34:
	jmp	.L31
.L33:
.L31:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	bijiao, .-bijiao
	.ident	"GCC: (Ubuntu/Linaro 4.7.2-2ubuntu1) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
