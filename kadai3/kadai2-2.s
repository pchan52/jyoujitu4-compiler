	.file   "test/kadai2-2.c"
	.cstring
LSTR0:
	.ascii	"mrn(%d) = %d\n\0"
	.text
	.globl	_main
_main:
	pushl	%ebp		# スタックフレームを作成
	movl	%esp, %ebp
	subl	$4,%esp	#自動変数用
	pushl	$0
	leal	-4(%ebp),%eax	#左辺値
	pushl	%eax
	popl	%eax
	movl	0(%esp),%ecx
	movl	%ecx,0(%eax)
	addl	$4, %esp	# 返り値を廃棄
L0:				#whileの戻り先
	pushl	-4(%ebp)		#iの内容をスタックに積む
	pushl	$15
	popl	%ecx
	popl	%eax
	cmpl	%ecx,%eax
	setl	%al		# <式
	movzbl	%al,%eax
	pushl	%eax
	popl	%eax
	cmpl	$0,%eax
	je	L1
	subl	$8, %esp	# paddingを積む
	subl	$8, %esp	# paddingを積む
	pushl	-4(%ebp)		#iの内容をスタックに積む
	call	_mrn
	addl	$4, %esp	# 引数を捨てる
	addl	$8, %esp	# paddingを廃棄
	pushl	%eax		# 返り値を積む
	pushl	-4(%ebp)		#iの内容をスタックに積む
	pushl	$LSTR0
	call	_printf
	addl	$12, %esp	# 引数を捨てる
	addl	$8, %esp	# paddingを廃棄
	pushl	%eax		# 返り値を積む
	addl	$4, %esp	# 返り値を廃棄
	pushl	-4(%ebp)		#iの内容をスタックに積む
	pushl	$2
	popl	%ecx
	popl	%eax
	addl	%ecx,%eax	# 足し算
	pushl	%eax
	leal	-4(%ebp),%eax	#左辺値
	pushl	%eax
	popl	%eax
	movl	0(%esp),%ecx
	movl	%ecx,0(%eax)
	addl	$4, %esp	# 返り値を廃棄
	jmp	L0
L1:
L.XCC.RE.main:
	movl	%ebp, %esp	# スタックフレームを除去
	popl	%ebp
	ret
	.text
	.globl	_mrn
_mrn:
	pushl	%ebp		# スタックフレームを作成
	movl	%esp, %ebp
	pushl	$0
	pushl	8(%ebp)		#nの内容をスタックに積む
	popl	%ecx
	popl	%eax
	cmpl	%ecx,%eax
	setl	%al		# <式
	movzbl	%al,%eax
	pushl	%eax
	popl	%eax
	cmpl	$1,%eax
	jne	L2
	pushl	8(%ebp)		#nの内容をスタックに積む
	pushl	$10
	popl	%ecx
	popl	%eax
	cmpl	%ecx,%eax
	setl	%al		# <式
	movzbl	%al,%eax
	pushl	%eax
	popl	%eax
	cmpl	$1,%eax
	jne	L2
	pushl	$1
	jmp	L3
L2:					# && in
	pushl	$0
L3:					# && out
	popl	%eax
	cmpl	$0,%eax
	je	L4
	pushl	$120
	pushl	8(%ebp)		#nの内容をスタックに積む
	popl	%ecx
	popl	%eax
	cltd
	idivl	%ecx,%eax	# 割り算
	pushl	%eax
	popl	%eax
	jmp	L.XCC.RE.mrn	#return
	jmp	L5
L4:					#elseのとき
	pushl	8(%ebp)		#nの内容をスタックに積む
	popl	%eax
	jmp	L.XCC.RE.mrn	#return
L5:					#ifelseの出口
L.XCC.RE.mrn:
	movl	%ebp, %esp	# スタックフレームを除去
	popl	%ebp
	ret
	.ident  "XCC skeleton ($Revision: 1.3 $)"
