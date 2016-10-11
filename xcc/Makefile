XCC_HDR = xcc.h  AST.h type.h symbol.h misc.h codegen.h
XCC_SRC =        AST.c type.c symbol.c misc.c
XCC_DOC = xcc.pdf codegen-x86.pdf x86-asm.pdf
LIBS    = -ll
WARNING = -Wall -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations
GAKUSEKI_BANGO = 01_12345
KADAI	= kadai1
G_K	= $(GAKUSEKI_BANGO)-$(KADAI)

all: xcc

xcc:  $(XCC_SRC) $(XCC_HDR) codegen.c  xcc.tab.c xcc.tab.h lex.yy.c 
	gcc $(WARNING) -g -o xcc $(XCC_SRC) codegen.c xcc.tab.c lex.yy.c $(LIBS) 

xcc.tab.c xcc.tab.h xcc.output: xcc.y
	bison -d -v xcc.y

lex.yy.c: xcc.l xcc.tab.h
	flex xcc.l

pack:
	if [ -e $(G_K) ]; then rm -rf $(G_K); fi
	mkdir $(G_K)
	cp $(XCC_HDR) $(XCC_SRC) Makefile xcc.y xcc.l codegen.c $(G_K)
	if [ ! -e $(G_K)/test ]; then mkdir $(G_K)/test; fi
	cp -r test $(G_K)/
	tar cvzf $(G_K).tgz $(G_K)

clean:
	-rm -f xcc *.o lex.yy.c xcc.tab.c xcc.tab.h xcc.output *~ \#*\#

wc:
	make clean
	wc *.[chly]

