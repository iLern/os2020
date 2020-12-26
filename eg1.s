	.file	"eg1.c"
	.section	.rodata
.LC0:
	.string	"Hello world,x=%d\n"
.LC1:
	.string	"This is parent,x=%d\n"
.LC2:
	.string	"This is child ,x=%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$20, %esp
	movl	$100, -16(%ebp)
	subl	$8, %esp
	pushl	-16(%ebp)
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	call	fork
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	je	.L2
	movl	$200, -16(%ebp)
	subl	$8, %esp
	pushl	-16(%ebp)
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	jmp	.L3
.L2:
	movl	$300, -16(%ebp)
	subl	$8, %esp
	pushl	-16(%ebp)
	pushl	$.LC2
	call	printf
	addl	$16, %esp
.L3:
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	.cfi_def_cfa 1, 0
	leave
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
