	.file   "test/kadai1.c"
	.cstring
LSTR1:
	.ascii	"sum = %d\n\0"
LSTR0:
	.ascii	"i = %d\n\0"
	.text
	.globl	_main
_main:
	pushl	%ebp		# スタックフレームを作成
	movl	%esp, %ebp
	pushl	$5
	pushl	$_i		#左辺値をスタックに積む
	popl	%eax
	movl	0(%esp),%ecx
	movl	%ecx,0(%eax)
	addl	$4, %esp	# 返り値を廃棄
	pushl	$0
	pushl	$_sum		#左辺値をスタックに積む
	popl	%eax
	movl	0(%esp),%ecx
	movl	%ecx,0(%eax)
	addl	$4, %esp	# 返り値を廃棄
L0:				#whileの戻り先
	pushl	$0
	pushl	_i
	popl	%ecx
	popl	%eax
	cmpl	%ecx,%eax
	setl	%al		# <式
	movzbl	%al,%eax
	pushl	%eax
	popl	%eax
	cmpl	$0,%eax
	je	L1
	pushl	_i
	pushl	$LSTR0
	call	_printf
	addl	$8, %esp	# 引数を捨てる
	pushl	%eax		# 返り値を積む
	addl	$4, %esp	# 返り値を廃棄
	pushl	_sum
	pushl	_i
	popl	%ecx
	popl	%eax
	addl	%ecx,%eax	# 足し算
	pushl	%eax
	pushl	$_sum		#左辺値をスタックに積む
	popl	%eax
	movl	0(%esp),%ecx
	movl	%ecx,0(%eax)
	addl	$4, %esp	# 返り値を廃棄
	pushl	_i
	pushl	$1
	popl	%ecx
	popl	%eax
	subl	%ecx,%eax	# 引き算
	pushl	%eax
	pushl	$_i		#左辺値をスタックに積む
	popl	%eax
	movl	0(%esp),%ecx
	movl	%ecx,0(%eax)
	addl	$4, %esp	# 返り値を廃棄
	jmp	L0
L1:
	subl	$8, %esp	# paddingを積む
	pushl	_sum
	pushl	$LSTR1
	call	_printf
	addl	$8, %esp	# 引数を捨てる
	addl	$8, %esp	# paddingを廃棄
	pushl	%eax		# 返り値を積む
	addl	$4, %esp	# 返り値を廃棄
L.XCC.RE.main:
	movl	%ebp, %esp	# スタックフレームを除去
	popl	%ebp
	ret
	.comm	_sum,4,2
	.comm	_i,4,2
	.ident  "XCC skeleton ($Revision: 1.3 $)"
