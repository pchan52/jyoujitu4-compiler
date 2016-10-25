	.file   "test/kadai0.c"
	.cstring
LSTR0:
	.ascii	"hello, world, %d, %d\n\0"
	.text
	.globl	_main
_main:
	pushl	%ebp	# スタックフレームを作成
	movl	%esp, %ebp
	subl	$12, %esp	# paddingを積む
	pushl	$20
	pushl	$10
	pushl	$LSTR0
	call	_printf
	addl	$12, %esp	# 引数を捨てる
	addl	$12, %esp	# paddingを廃棄
	pushl	%eax	# 返り値を積む
	addl	$4, %esp	# 返り値を廃棄
L.XCC.RE.main:
	movl	%ebp, %esp	# スタックフレームを除去
	popl	%ebp
	ret
	.ident  "XCC skeleton ($Revision: 1.3 $)"
