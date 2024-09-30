	.file	"circularQueue.c"
	.text
	.globl	_createQueue
	.def	_createQueue;	.scl	2;	.type	32;	.endef
_createQueue:
LFB23:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$16, (%esp)
	call	_malloc
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	$-1, 4(%eax)
	movl	-12(%ebp), %eax
	movl	$-1, 8(%eax)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 12(%eax)
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE23:
	.globl	_isFull
	.def	_isFull;	.scl	2;	.type	32;	.endef
_isFull:
LFB24:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movl	12(%eax), %ecx
	movl	%edx, %eax
	cltd
	idivl	%ecx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	%eax, %edx
	jne	L4
	movl	$1, %eax
	jmp	L5
L4:
	movl	$0, %eax
L5:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE24:
	.globl	_isEmpty
	.def	_isEmpty;	.scl	2;	.type	32;	.endef
_isEmpty:
LFB25:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$-1, %eax
	jne	L7
	movl	$1, %eax
	jmp	L8
L7:
	movl	$0, %eax
L8:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE25:
	.section .rdata,"dr"
LC0:
	.ascii "Queue is empty\0"
LC1:
	.ascii "Queue elements are: \0"
LC2:
	.ascii "%d \0"
LC3:
	.ascii "%d\12\0"
	.text
	.globl	_display
	.def	_display;	.scl	2;	.type	32;	.endef
_display:
LFB26:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_isEmpty
	testl	%eax, %eax
	je	L10
	movl	$LC0, (%esp)
	call	_puts
	jmp	L14
L10:
	movl	$LC1, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -12(%ebp)
	jmp	L12
L13:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	-12(%ebp), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movl	12(%eax), %ecx
	movl	%edx, %eax
	cltd
	idivl	%ecx
	movl	%edx, -12(%ebp)
L12:
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	%eax, -12(%ebp)
	jne	L13
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
L14:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE26:
	.section .rdata,"dr"
	.align 4
LC4:
	.ascii "Queue overflow, Cannot enqueue\0"
LC5:
	.ascii "Enqueued %d\12\0"
	.text
	.globl	_enqueue
	.def	_enqueue;	.scl	2;	.type	32;	.endef
_enqueue:
LFB27:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_isFull
	testl	%eax, %eax
	je	L16
	movl	$LC4, (%esp)
	call	_puts
	jmp	L19
L16:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$-1, %eax
	jne	L18
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
L18:
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movl	12(%eax), %ecx
	movl	%edx, %eax
	cltd
	idivl	%ecx
	movl	8(%ebp), %eax
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	sall	$2, %eax
	addl	%eax, %edx
	movl	12(%ebp), %eax
	movl	%eax, (%edx)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_display
L19:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE27:
	.section .rdata,"dr"
	.align 4
LC6:
	.ascii "Queue Underflow, Cannot dequeue\0"
LC7:
	.ascii "Dequeued %d\12\0"
	.text
	.globl	_dequeue
	.def	_dequeue;	.scl	2;	.type	32;	.endef
_dequeue:
LFB28:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_isEmpty
	testl	%eax, %eax
	je	L21
	movl	$LC6, (%esp)
	call	_puts
	movl	$-1, %eax
	jmp	L22
L21:
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	%eax, %edx
	jne	L23
	movl	8(%ebp), %eax
	movl	$-1, 4(%eax)
	movl	8(%ebp), %eax
	movl	$-1, 8(%eax)
	jmp	L24
L23:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movl	12(%eax), %ecx
	movl	%edx, %eax
	cltd
	idivl	%ecx
	movl	8(%ebp), %eax
	movl	%edx, 4(%eax)
L24:
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_display
	movl	-12(%ebp), %eax
L22:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE28:
	.section .rdata,"dr"
	.align 4
LC8:
	.ascii "\12Select an operation from below:\12\0"
LC9:
	.ascii "1. Enqueue\0"
LC10:
	.ascii "2. Dequeue\0"
LC11:
	.ascii "3. Exit\0"
LC12:
	.ascii "Enter your choice: \0"
	.text
	.globl	_menu
	.def	_menu;	.scl	2;	.type	32;	.endef
_menu:
LFB29:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$LC8, (%esp)
	call	_puts
	movl	$LC9, (%esp)
	call	_puts
	movl	$LC10, (%esp)
	call	_puts
	movl	$LC11, (%esp)
	call	_puts
	movl	$LC12, (%esp)
	call	_printf
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE29:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC13:
	.ascii "Enter the maximum size of the queue: \0"
LC14:
	.ascii "%d\0"
LC15:
	.ascii "Enter an integer to begin: \0"
LC16:
	.ascii "Enter value to enqueue: \0"
LC17:
	.ascii "Exiting...\0"
	.align 4
LC18:
	.ascii "Invalid choice! Please choose a valid option.\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB30:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$48, %esp
	call	___main
	movl	$LC13, (%esp)
	call	_printf
	leal	32(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC14, (%esp)
	call	_scanf
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	_createQueue
	movl	%eax, 44(%esp)
	movl	$LC15, (%esp)
	call	_printf
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC14, (%esp)
	call	_scanf
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	_enqueue
L32:
	call	_menu
	leal	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC14, (%esp)
	call	_scanf
	movl	28(%esp), %eax
	cmpl	$3, %eax
	je	L27
	cmpl	$3, %eax
	jg	L28
	cmpl	$1, %eax
	je	L29
	cmpl	$2, %eax
	je	L30
	jmp	L28
L29:
	movl	$LC16, (%esp)
	call	_printf
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC14, (%esp)
	call	_scanf
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	_enqueue
	jmp	L31
L30:
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	_dequeue
	jmp	L31
L27:
	movl	$LC17, (%esp)
	call	_puts
	movl	44(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, 36(%esp)
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	___mingw_free
	nop
	movl	44(%esp), %eax
	movl	%eax, 40(%esp)
	movl	40(%esp), %eax
	movl	%eax, (%esp)
	call	___mingw_free
	nop
	movl	$0, (%esp)
	call	_exit
L28:
	movl	$LC18, (%esp)
	call	_puts
L31:
	jmp	L32
	.cfi_endproc
LFE30:
	.ident	"GCC: (MinGW.org GCC Build-2) 9.2.0"
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	___mingw_free;	.scl	2;	.type	32;	.endef
	.def	_exit;	.scl	2;	.type	32;	.endef
