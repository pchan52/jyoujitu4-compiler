/*
  $Id: codegen-skel.c,v 1.3 2009/03/27 09:36:54 gondow Exp gondow $
 */
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "xcc.h"
#include "misc.h"
#include "AST.h"
#include "type.h"
#include "symbol.h"
#include "codegen.h"

static void emit_code (struct AST *ast, char *fmt, ...);
static void codegen_begin_block (struct AST *ast);
static void codegen_end_block (void);
static void codegen_begin_function (struct AST *ast);
static void codegen_end_function (void);

static int frame_height;	/* スタックフレームの大きさ */
static char *funcname;		/* コンパイル中の関数名 */

static void codegen_global (void);
static void codegen_global_func (struct Symbol *sym);
static void visit_AST (struct AST *ast);
static void codegen_function_definition (struct AST *ast);
static void codegen_statement_exp (struct AST *ast);
static void codegen_statement_while(struct AST *ast);  //while文用関数の宣言
static void codegen_compound_statement (struct AST *ast);
static void codegen_expression_id (struct AST *ast);
static void codegen_expression_assign(struct AST *ast); //代入文(=)用関数の宣言
static void codegen_expression_less(struct AST *ast);   //<式用関数の宣言
static void codegen_expression_add(struct AST *ast);    //+式用関数の宣言
static void codegen_expression_sub(struct AST *ast);    //-式用関数の宣言
static void codegen_expression_intchar (struct AST *ast);
static void codegen_expression_string (struct AST *ast);
static void codegen_expression_funcall (struct AST *ast);
static void codegen_argument_expression_list_pair (struct AST *ast);

//ラベル用変数
int label = 0;
/* ---------------------------------------------------------------------- */

static void
emit_code (struct AST *ast, char *fmt, ...)
{
  va_list  argp;
  va_start (argp, fmt);
  vfprintf (xcc_out, fmt, argp);
  va_end   (argp);

  /* the argument 'ast' can be used for debug purpose */
}

static void
codegen_begin_block (struct AST *ast)
{
  assert (!strcmp (ast->ast_type, "AST_compound_statement"));
  sym_table.local [++sym_table.local_index] = ast->u.local;
}

static void
codegen_end_block (void)
{
  sym_table.local_index--;
}

static void
codegen_begin_function (struct AST *ast)
{
  assert(!strcmp (ast->ast_type, "AST_function_definition"));
  sym_table.local_index = -1;
  sym_table.global = ast->u.func.global;
  sym_table.arg    = ast->u.func.arg;
  sym_table.label  = ast->u.func.label;
  sym_table.string = ast->u.func.string;
}

static void
codegen_end_function (void)
{
  /* do nothing */
}

/* ---------------------------------------------------------------------- */
void
codegen (void)
{
  emit_code (ast_root, "\t.file   \"%s\"\n", filename);

  codegen_global ();

  emit_code (ast_root, "\t.ident  \"XCC skeleton ($Revision: 1.3 $)\"\n");
}
/* ---------------------------------------------------------------------- */

static void
codegen_global (void)
{
  struct Symbol *sym;

  sym = sym_table.global;
  while (sym != NULL) {
    if (sym->type->kind == TYPE_KIND_FUNCTION) {
      codegen_global_func (sym);
    };
    sym = sym->next;
  }

  //大域変数
  sym = sym_table.global;
  while (sym != NULL) {
    if (sym->type->kind == TYPE_KIND_PRIM) {
      emit_code(sym->ast,"\t.comm\t_%s,4,2\n",sym->name);
    };
    sym = sym->next;
  }



}

static void
codegen_global_func (struct Symbol *sym)
{
  assert (!strcmp (sym->ast->ast_type, "AST_function_definition")
          || !strcmp (sym->ast->ast_type, "AST_declaration"));

  if (!strcmp (sym->ast->ast_type, "AST_function_definition")) {
    funcname = sym->name;
    codegen_function_definition (sym->ast);
  }
}

static void
visit_AST (struct AST *ast)
{
  int i;

  if (!strcmp (ast->ast_type, "AST_statement_exp")) {
    codegen_statement_exp (ast);
  } else if (!strcmp (ast->ast_type, "AST_statement_while")) { //while文
    codegen_statement_while (ast);
  } else if (!strcmp (ast->ast_type, "AST_compound_statement")) {
    codegen_compound_statement (ast);
  } else if (!strcmp (ast->ast_type, "AST_expression_int")
             ||!strcmp (ast->ast_type, "AST_expression_char")) {
    codegen_expression_intchar (ast);
  } else if (!strcmp (ast->ast_type, "AST_expression_string")) {
    codegen_expression_string (ast);
  } else if (!strcmp (ast->ast_type, "AST_expression_id")) {
    codegen_expression_id (ast);
  } else if (!strcmp (ast->ast_type, "AST_expression_assign")) { //代入文(=)
    codegen_expression_assign (ast);
  } else if (!strcmp (ast->ast_type, "AST_expression_less")) { //　<式
    codegen_expression_less (ast);
  } else if (!strcmp (ast->ast_type, "AST_expression_add")) { // +式
    codegen_expression_add (ast);
  } else if (!strcmp (ast->ast_type, "AST_expression_sub")) { // -式
    codegen_expression_sub (ast);
  }
  else if (!strcmp (ast->ast_type, "AST_expression_funcall1")
             || !strcmp (ast->ast_type, "AST_expression_funcall2")) {
    codegen_expression_funcall (ast);
  } else if (!strcmp (ast->ast_type, "AST_argument_expression_list_pair")) {
    codegen_argument_expression_list_pair (ast);
  } else {
    for (i = 0; i < ast->num_child; i++) {
      visit_AST (ast->child [i]);
    };
  };
}

static void
codegen_string_def (struct AST *ast, struct String *string)
{
  struct String *p;

  emit_code (ast, "\t.cstring\n");
  for (p = string; p != NULL; p = p->next) {
    emit_code (ast, "L%s:\n", p->label);
    emit_code (ast, "\t.ascii\t\"%s\\0\"\n", p->data);
  }
}

static void
codegen_function_definition (struct AST *ast)
{
  int i;

  assert (!strcmp (ast->ast_type, "AST_function_definition"));

  codegen_begin_function (ast);	/* 名前表の修正 */

  frame_height = 4;	/* 呼び出されたときは、%eipのみスタックにあるため、大きさは4 */
  if (sym_table.string != NULL)
    codegen_string_def (ast, sym_table.string);
  emit_code (ast, "\t.text\n");
  emit_code (ast, "\t.globl\t_%s\n", funcname);
  emit_code (ast, "_%s:\n", funcname);
  emit_code (ast, "\tpushl\t%%ebp\t\t# スタックフレームを作成\n");
  frame_height += 4;	/* スタックに%ebpが積まれたため、大きさを4増やす */
  emit_code (ast, "\tmovl\t%%esp, %%ebp\n");

  /* 本体のコンパイル */
  for (i = 0; i < ast->num_child; i++) {
    visit_AST (ast->child [i]);
  };

  emit_code (ast, "L.XCC.RE.%s:\n", funcname);
  emit_code (ast, "\tmovl\t%%ebp, %%esp\t# スタックフレームを除去\n");
  emit_code (ast, "\tpopl\t%%ebp\n");
  emit_code (ast, "\tret\n");

  codegen_end_function (); /* 名前表の修正 */
}

static void
codegen_statement_exp (struct AST *ast)
{
  int i;

  assert (!strcmp (ast->ast_type, "AST_statement_exp"));

  /* 本体のコンパイル */
  for (i = 0; i < ast->num_child; i++) {
    visit_AST (ast->child [i]);
  };
  if (!strcmp (ast->child[0]->ast_type, "AST_expression_opt_single")){
    emit_code (ast, "\taddl\t$%d, %%esp\t# 返り値を廃棄\n", 4);
    frame_height -= 4;	/* スタックトップが廃棄されたので、4減らす。*/
  };
}

//while文
static void
codegen_statement_while(struct AST *ast)
{
  int i;
  int while_label = label;
  label += 2; //whileroopの中と外用の2つを確保
  emit_code(ast,"L%d:\t\t\t\t#whileの戻り先\n",while_label);
  visit_AST(ast->child[0]);
  emit_code(ast,"\tpopl\t%%eax\n");
  frame_height -= 4;
  emit_code(ast,"\tcmpl\t$0,%%eax\n");
  emit_code(ast,"\tje\tL%d\n",while_label+1);  //roop　out
  visit_AST(ast->child[1]);
  emit_code(ast,"\tjmp\tL%d\n",while_label);  //roop restart
  emit_code(ast,"L%d:\n",while_label+1);
}


static void
codegen_compound_statement (struct AST *ast)
{
  int i;

  assert (!strcmp (ast->ast_type, "AST_compound_statement"));

  codegen_begin_block (ast);	/* 名前表の修正 */

  /* 本体のコンパイル */
  for (i = 0; i < ast->num_child; i++) {
    visit_AST (ast->child [i]);
  };

  codegen_end_block ();	/* 名前表の修正 */
}


static void
codegen_expression_id (struct AST *ast)
{
  char *id;
  struct Symbol *symbol;

  assert (!strcmp (ast->ast_type, "AST_expression_id"));

  id = ast->child[0]->u.id;
  symbol = sym_lookup (id);

  switch (symbol->name_space) {
  case NS_LOCAL:
    break;
  case NS_ARG:
    break;
  case NS_GLOBAL:
    switch (symbol->type->kind) {
    case TYPE_KIND_PRIM:
      if((!strcmp (ast->parent->ast_type, "AST_expression_assign")) && (ast->nth == 0)){
          emit_code (ast, "\tpushl\t$_%s\t\t#左辺値をスタックに積む\n",id);
          frame_height +=4;
      }else{
        emit_code(ast,"\tpushl\t_%s\n",id);
        frame_height += 4;
      }
      break;
    case TYPE_KIND_POINTER:
      break;
    case TYPE_KIND_FUNCTION:
      emit_code (ast, "\tcall\t_%s\n", id);
      break;
    default:
      assert (0);
      break;
    };
    break;
  case NS_LABEL:
    break;
  default:
    assert (0);
    break;
  };
}

static void
codegen_expression_intchar (struct AST *ast)
{
  assert (!strcmp (ast->ast_type, "AST_expression_int")
          || !strcmp (ast->ast_type, "AST_expression_char"));

  emit_code (ast, "\tpushl\t$%d\n", ast->u.int_val);
  frame_height += 4;	/* スタックに即値が積まれた */
}

static void
codegen_expression_string (struct AST *ast)
{
  struct String *string;

  assert (!strcmp (ast->ast_type, "AST_expression_string"));

  string = string_lookup(ast->u.id);
  emit_code (ast, "\tpushl\t$L%s\n", string->label);
  frame_height += 4;	/* スタックにstringのあるアドレスが積まれた */
}

//代入文(=)
static void
codegen_expression_assign(struct AST *ast)
{
  int i;
  for (i = ast->num_child-1; i>=0; i--){
    visit_AST(ast->child[i]);
  }
  emit_code(ast,"\tpopl\t%%eax\n");
  frame_height -=4;
  emit_code(ast,"\tmovl\t0(%%esp),%%ecx\n");
  emit_code(ast,"\tmovl\t%%ecx,0(%%eax)\n");
}

//<式
static void
codegen_expression_less (struct AST *ast)
{
  int i;
  for (i=0; i < ast->num_child; i++){
    visit_AST (ast->child[i]);
  }
  emit_code(ast,"\tpopl\t%%ecx\n");
  frame_height -= 4;
  emit_code(ast,"\tpopl\t%%eax\n");
  frame_height -= 4;
  emit_code(ast,"\tcmpl\t%%ecx,%%eax\n");
  emit_code(ast,"\tsetl\t%%al\t\t# <式\n");
  emit_code(ast,"\tmovzbl\t%%al,%%eax\n");
  emit_code(ast,"\tpushl\t%%eax\n");
  frame_height += 4;
}

//+式
static void codegen_expression_add (struct AST *ast){
  int i;
  for (i=0; i < ast->num_child; i++){
    visit_AST (ast->child[i]);
  }
  emit_code(ast,"\tpopl\t%%ecx\n");
  frame_height -= 4;
  emit_code(ast,"\tpopl\t%%eax\n");
  frame_height -= 4;
  emit_code(ast,"\taddl\t%%ecx,%%eax\t# 足し算\n");
  emit_code(ast,"\tpushl\t%%eax\n");
}

//-式
static void codegen_expression_sub (struct AST *ast){
  int i;
  for (i=0; i < ast->num_child; i++){
    visit_AST (ast->child[i]);
  }
  emit_code(ast,"\tpopl\t%%ecx\n");
  frame_height -= 4;
  emit_code(ast,"\tpopl\t%%eax\n");
  frame_height -= 4;
  emit_code(ast,"\tsubl\t%%ecx,%%eax\t# 引き算\n");
  emit_code(ast,"\tpushl\t%%eax\n");
}

static void
codegen_expression_funcall (struct AST *ast)
{
  int i;
  int fh;
  int padding; /* 呼び出し時%espが16バイト境界のため、挿入するpaddingの大きさ */

  assert (!strcmp (ast->ast_type, "AST_expression_funcall1")
          || !strcmp (ast->ast_type, "AST_expression_funcall2"));

  /*  挿入するpaddingの大きさの計算し、paddingを積む */
  if (!strcmp (ast->ast_type, "AST_expression_funcall1")) {
    fh = (frame_height + ast->child[1]->u.arg_size) % 16;
  } else {
    fh = frame_height % 16;
  };
  if (fh == 0) {
    padding = 0;
  } else {
    padding = 16 - fh;
  };
  if (padding != 0) {
    emit_code (ast, "\tsubl\t$%d, %%esp\t# paddingを積む\n", padding);
    frame_height += padding;
  };

  /* 引数の値を積んでから、関数呼び出し */
  for (i = ast->num_child - 1; i >= 0 ; i--) {
    visit_AST (ast->child [i]);
  };

  /* 引数とpaddingを捨てる */
  if (!strcmp (ast->ast_type, "AST_expression_funcall1")
      && ast->child[1]->u.arg_size != 0) {
    emit_code (ast, "\taddl\t$%d, %%esp\t# 引数を捨てる\n", ast->child[1]->u.arg_size);
    frame_height -= ast->child[1]->u.arg_size;
  };
  if (padding != 0) {
    emit_code (ast, "\taddl\t$%d, %%esp\t# paddingを廃棄\n", padding);
    frame_height -= padding;
  };

  /* 返り値をスタックに乗せる */
  emit_code (ast, "\tpushl\t%%eax\t\t# 返り値を積む\n");
  frame_height += 4;
}

static void
codegen_argument_expression_list_pair (struct AST *ast)
{
  int i;

  assert (!strcmp (ast->ast_type, "AST_argument_expression_list_pair"));

  /* 引数の値を逆順にスタックに積むため、逆に子供をたどる */
  for (i = ast->num_child - 1; i >= 0 ; i--) {
    visit_AST (ast->child [i]);
  };
}
