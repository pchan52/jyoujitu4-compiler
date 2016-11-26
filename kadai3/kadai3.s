	.file   "test/kadai3.c"
	.cstring
LSTR0:
	.ascii	"%d\n\0"
	.text
	.globl	_main
_main:
	pushl	%ebp		# スタックフレームを作成
	movl	%esp, %ebp
	subl	$12,%esp	#自動変数用
	subl	$8, %esp	# paddingを積む
	pushl	12(%ebp)		#argvの内容をスタックに積む
	pushl	$1
	popl	%ecx
	popl	%eax
	addl	%ecx,%eax	# 足し算
	pushl	%eax
	call	_atoi
	addl	$4, %esp	# 引数を捨てる
	addl	$8, %esp	# paddingを廃棄
	pushl	%eax		# 返り値を積む
	leal	-12(%ebp),%eax	#左辺値
	pushl	%eax
	popl	%eax
	movl	0(%esp),%ecx
	movl	%ecx,0(%eax)
	addl	$4, %esp	# 返り値を廃棄
	subl	$8, %esp	# paddingを積む
	pushl	$4
	pushl	-12(%ebp)		#sizeの内容をスタックに積む
	popl	%ecx
	popl	%eax
	imull	%ecx,%eax	# 掛け算
	pushl	%eax
	call	_malloc
	addl	$4, %esp	# 引数を捨てる
	addl	$8, %esp	# paddingを廃棄
	pushl	%eax		# 返り値を積む
	leal	-8(%ebp),%eax	#左辺値
	pushl	%eax
	popl	%eax
	movl	0(%esp),%ecx
	movl	%ecx,0(%eax)
	addl	$4, %esp	# 返り値を廃棄
	pushl	$0
	pushl	-12(%ebp)		#sizeの内容をスタックに積む
	pushl	-8(%ebp)		#pの内容をスタックに積む
	call	_make_array
	addl	$12, %esp	# 引数を捨てる
	pushl	%eax		# 返り値を積む
	addl	$4, %esp	# 返り値を廃棄
	subl	$4, %esp	# paddingを積む
	pushl	-12(%ebp)		#sizeの内容をスタックに積む
	pushl	-8(%ebp)		#pの内容をスタックに積む
	call	_bubble_sort
	addl	$8, %esp	# 引数を捨てる
	addl	$4, %esp	# paddingを廃棄
	pushl	%eax		# 返り値を積む
	addl	$4, %esp	# 返り値を廃棄
	pushl	$0
	leal	-4(%ebp),%eax	#左辺値
	pushl	%eax
	popl	%eax
	movl	0(%esp),%ecx
	movl	%ecx,0(%eax)
	addl	$4, %esp	# 返り値を廃棄
L0:				#whileの戻り先
	pushl	-4(%ebp)		#iの内容をスタックに積む
	pushl	-12(%ebp)		#sizeの内容をスタックに積む
	popl	%ecx
	popl	%eax
	cmpl	%ecx,%eax
	setl	%al		# <式
	movzbl	%al,%eax
	pushl	%eax
	popl	%eax
	cmpl	$0,%eax
	je	L1
	subl	$4, %esp	# paddingを積む
	pushl	-8(%ebp)		#pの内容をスタックに積む
	pushl	-4(%ebp)		#iの内容をスタックに積む
	popl	%ecx
	popl	%eax
	addl	%ecx,%eax	# 足し算
	pushl	%eax
	pushl	$LSTR0
	call	_printf
	addl	$8, %esp	# 引数を捨てる
	addl	$4, %esp	# paddingを廃棄
	pushl	%eax		# 返り値を積む
	addl	$4, %esp	# 返り値を廃棄
	pushl	-4(%ebp)		#iの内容をスタックに積む
	pushl	$1
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
	.globl	_make_array
_make_array:
	pushl	%ebp		# スタックフレームを作成
	movl	%esp, %ebp
	subl	$8,%esp	#自動変数用
	pushl	$0
	leal	-4(%ebp),%eax	#左辺値
	pushl	%eax
	popl	%eax
	movl	0(%esp),%ecx
	movl	%ecx,0(%eax)
	addl	$4, %esp	# 返り値を廃棄
	subl	$12, %esp	# paddingを積む
	pushl	16(%ebp)		#seedの内容をスタックに積む
	call	_srandom
	addl	$4, %esp	# 引数を捨てる
	addl	$12, %esp	# paddingを廃棄
	pushl	%eax		# 返り値を積む
	addl	$4, %esp	# 返り値を廃棄
L2:				#whileの戻り先
	pushl	-4(%ebp)		#iの内容をスタックに積む
	pushl	12(%ebp)		#sizeの内容をスタックに積む
	popl	%ecx
	popl	%eax
	cmpl	%ecx,%eax
	setl	%al		# <式
	movzbl	%al,%eax
	pushl	%eax
	popl	%eax
	cmpl	$0,%eax
	je	L3
	call	_random
	pushl	%eax		# 返り値を積む
	leal	-8(%ebp),%eax	#左辺値
	pushl	%eax
	popl	%eax
	movl	0(%esp),%ecx
	movl	%ecx,0(%eax)
	addl	$4, %esp	# 返り値を廃棄
	subl	$8, %esp	# paddingを積む
	pushl	12(%ebp)		#sizeの内容をスタックに積む
	pushl	-8(%ebp)		#jの内容をスタックに積む
	call	_mod
	addl	$8, %esp	# 引数を捨てる
	addl	$8, %esp	# paddingを廃棄
	pushl	%eax		# 返り値を積む
	pushl	8(%ebp)		#dataの内容をスタックに積む
	pushl	-4(%ebp)		#iの内容をスタックに積む
	popl	%ecx
	popl	%eax
	addl	%ecx,%eax	# 足し算
	pushl	%eax
	popl	%eax
	movl	0(%esp),%ecx
	movl	%ecx,0(%eax)
	addl	$4, %esp	# 返り値を廃棄
	pushl	-4(%ebp)		#iの内容をスタックに積む
	pushl	$1
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
	jmp	L2
L3:
L.XCC.RE.make_array:
	movl	%ebp, %esp	# スタックフレームを除去
	popl	%ebp
	ret
	.text
	.globl	_bubble_sort
_bubble_sort:
	pushl	%ebp		# スタックフレームを作成
	movl	%esp, %ebp
	subl	$8,%esp	#自動変数用
	pushl	12(%ebp)		#sizeの内容をスタックに積む
	pushl	$1
	popl	%ecx
	popl	%eax
	subl	%ecx,%eax	# 引き算
	pushl	%eax
	leal	-4(%ebp),%eax	#左辺値
	pushl	%eax
	popl	%eax
	movl	0(%esp),%ecx
	movl	%ecx,0(%eax)
	addl	$4, %esp	# 返り値を廃棄
L4:				#whileの戻り先
	pushl	$0
	pushl	-4(%ebp)		#iの内容をスタックに積む
	popl	%ecx
	popl	%eax
	cmpl	%ecx,%eax
	setl	%al		# <式
	movzbl	%al,%eax
	pushl	%eax
	popl	%eax
	cmpl	$0,%eax
	je	L5
	pushl	$0
	leal	-8(%ebp),%eax	#左辺値
	pushl	%eax
	popl	%eax
	movl	0(%esp),%ecx
	movl	%ecx,0(%eax)
	addl	$4, %esp	# 返り値を廃棄
L6:				#whileの戻り先
	pushl	-8(%ebp)		#jの内容をスタックに積む
	pushl	-4(%ebp)		#iの内容をスタックに積む
	popl	%ecx
	popl	%eax
	cmpl	%ecx,%eax
	setl	%al		# <式
	movzbl	%al,%eax
	pushl	%eax
	popl	%eax
	cmpl	$0,%eax
	je	L7
	pushl	8(%ebp)		#dataの内容をスタックに積む
	pushl	-8(%ebp)		#jの内容をスタックに積む
	pushl	$1
	popl	%ecx
	popl	%eax
	addl	%ecx,%eax	# 足し算
	pushl	%eax
	popl	%ecx
	popl	%eax
	addl	%ecx,%eax	# 足し算
	pushl	%eax
	pushl	8(%ebp)		#dataの内容をスタックに積む
	pushl	-8(%ebp)		#jの内容をスタックに積む
	popl	%ecx
	popl	%eax
	addl	%ecx,%eax	# 足し算
	pushl	%eax
	popl	%ecx
	popl	%eax
	cmpl	%ecx,%eax
	setl	%al		# <式
	movzbl	%al,%eax
	pushl	%eax
	popl	%eax
	cmpl	$0,%eax
	je	L8
	subl	$8, %esp	# paddingを積む
	pushl	8(%ebp)		#dataの内容をスタックに積む
	pushl	-8(%ebp)		#jの内容をスタックに積む
	pushl	$1
	popl	%ecx
	popl	%eax
	addl	%ecx,%eax	# 足し算
	pushl	%eax
	popl	%ecx
	popl	%eax
	addl	%ecx,%eax	# 足し算
	pushl	%eax
	pushl	8(%ebp)		#dataの内容をスタックに積む
	pushl	-8(%ebp)		#jの内容をスタックに積む
	popl	%ecx
	popl	%eax
	addl	%ecx,%eax	# 足し算
	pushl	%eax
	call	_swap
	addl	$8, %esp	# 引数を捨てる
	addl	$8, %esp	# paddingを廃棄
	pushl	%eax		# 返り値を積む
	addl	$4, %esp	# 返り値を廃棄
L8:
	pushl	-8(%ebp)		#jの内容をスタックに積む
	pushl	$1
	popl	%ecx
	popl	%eax
	addl	%ecx,%eax	# 足し算
	pushl	%eax
	leal	-8(%ebp),%eax	#左辺値
	pushl	%eax
	popl	%eax
	movl	0(%esp),%ecx
	movl	%ecx,0(%eax)
	addl	$4, %esp	# 返り値を廃棄
	jmp	L6
L7:
	pushl	-4(%ebp)		#iの内容をスタックに積む
	pushl	$1
	popl	%ecx
	popl	%eax
	subl	%ecx,%eax	# 引き算
	pushl	%eax
	leal	-4(%ebp),%eax	#左辺値
	pushl	%eax
	popl	%eax
	movl	0(%esp),%ecx
	movl	%ecx,0(%eax)
	addl	$4, %esp	# 返り値を廃棄
	jmp	L4
L5:
L.XCC.RE.bubble_sort:
	movl	%ebp, %esp	# スタックフレームを除去
	popl	%ebp
	ret
	.text
	.globl	_swap
_swap:
	pushl	%ebp		# スタックフレームを作成
	movl	%esp, %ebp
	subl	$4,%esp	#自動変数用
	pushl	8(%ebp)		#aの内容をスタックに積む
	leal	-4(%ebp),%eax	#左辺値
	pushl	%eax
	popl	%eax
	movl	0(%esp),%ecx
	movl	%ecx,0(%eax)
	addl	$4, %esp	# 返り値を廃棄
	pushl	12(%ebp)		#bの内容をスタックに積む
	pushl	8(%ebp)		#aの内容をスタックに積む
	popl	%eax
	movl	0(%esp),%ecx
	movl	%ecx,0(%eax)
	addl	$4, %esp	# 返り値を廃棄
	pushl	-4(%ebp)		#tmpの内容をスタックに積む
	pushl	12(%ebp)		#bの内容をスタックに積む
	popl	%eax
	movl	0(%esp),%ecx
	movl	%ecx,0(%eax)
	addl	$4, %esp	# 返り値を廃棄
L.XCC.RE.swap:
	movl	%ebp, %esp	# スタックフレームを除去
	popl	%ebp
	ret
	.text
	.globl	_mod
_mod:
	pushl	%ebp		# スタックフレームを作成
	movl	%esp, %ebp
	pushl	8(%ebp)		#xの内容をスタックに積む
	pushl	8(%ebp)		#xの内容をスタックに積む
	pushl	12(%ebp)		#yの内容をスタックに積む
	popl	%ecx
	popl	%eax
	cltd
	idivl	%ecx,%eax	# 割り算
	pushl	%eax
	pushl	12(%ebp)		#yの内容をスタックに積む
	popl	%ecx
	popl	%eax
	imull	%ecx,%eax	# 掛け算
	pushl	%eax
	popl	%ecx
	popl	%eax
	subl	%ecx,%eax	# 引き算
	pushl	%eax
	popl	%eax
	jmp	L.XCC.RE.mod	#return
L.XCC.RE.mod:
	movl	%ebp, %esp	# スタックフレームを除去
	popl	%ebp
	ret
	.ident  "XCC skeleton ($Revision: 1.3 $)"
