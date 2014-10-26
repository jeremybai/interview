	.file	"globalcount.cpp"
.globl _slock
	.bss
	.align 4
_slock:
	.space 4
.globl _add_loops
	.data
	.align 4
_add_loops:
	.long	10000
.globl _global_count
	.bss
	.align 4
_global_count:
	.space 4
.globl _endSema
	.align 4
_endSema:
	.space 4
.globl _beginSemaArr
	.align 32
_beginSemaArr:
	.space 2000
	.text
	.align 2
	.p2align 4,,15
.globl __Z13threadAddFuncPv
	.def	__Z13threadAddFuncPv;	.scl	2;	.type	32;	.endef
__Z13threadAddFuncPv:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$4, %esp
	movl	8(%ebp), %eax
	leal	_beginSemaArr(,%eax,4), %ebx
	.p2align 4,,15
L2:
	movl	%ebx, (%esp)
	call	*__imp__sem_wait
	movl	_add_loops, %eax
	testl	%eax, %eax
	jle	L9
	movl	_global_count, %ecx
	.p2align 4,,15
L7:
	leal	1(%ecx), %edx
	decl	%eax
	movl	%edx, %ecx
	jne	L7
	movl	%edx, _global_count
L9:
	movl	$_endSema, (%esp)
	call	*__imp__sem_post
	jmp	L2
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "iter %d: global_count = %d\12\0"
	.text
	.align 2
	.p2align 4,,15
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	$4028, %eax
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	call	__alloca
	andl	$-16, %esp
	movl	$16, %eax
	call	__alloca
	call	___main
	movl	$_beginSemaArr, %esi
	movl	$499, %ebx
L15:
	movl	%esi, (%esp)
	xorl	%eax, %eax
	xorl	%edi, %edi
	movl	%eax, 8(%esp)
	addl	$4, %esi
	movl	%edi, 4(%esp)
	call	*__imp__sem_init
	decl	%ebx
	jns	L15
	movl	$_endSema, (%esp)
	xorl	%esi, %esi
	xorl	%ebx, %ebx
	movl	%esi, 8(%esp)
	leal	-4024(%ebp), %esi
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	call	*__imp__sem_init
L19:
	movl	%ebx, 12(%esp)
	xorl	%edx, %edx
	movl	$__Z13threadAddFuncPv, %ecx
	movl	%esi, (%esp)
	incl	%ebx
	addl	$8, %esi
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	call	*__imp__pthread_create
	cmpl	$499, %ebx
	jle	L19
	movl	$1, %edi
L20:
	xorl	%eax, %eax
	movl	$_beginSemaArr, %esi
	movl	$499, %ebx
	movl	%eax, _global_count
	.p2align 4,,15
L26:
	movl	%esi, (%esp)
	addl	$4, %esi
	call	*__imp__sem_post
	decl	%ebx
	jns	L26
	movl	$499, %ebx
	.p2align 4,,15
L30:
	movl	$_endSema, (%esp)
	call	*__imp__sem_wait
	decl	%ebx
	jns	L30
	movl	_global_count, %eax
	cmpl	$5000000, %eax
	je	L22
	movl	%eax, 8(%esp)
	movl	%edi, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
L22:
	incl	%edi
	jmp	L20
	.def	_printf;	.scl	2;	.type	32;	.endef
