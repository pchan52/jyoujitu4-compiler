/* XCC: Experimental C-subset Compiler.
  Copyright (c) 2002-2008, gondow@cs.titech.ac.jp, All rights reserved.
  $Id: symbol.h,v 1.1 2009/03/13 05:12:54 gondow Exp $
*/ 
#ifndef XCC_SYMBOL_H
#define XCC_SYMBOL_H
/* --------------------------------------------------------------------- */
/* 
   ANSI C has 4 name spaces for identifiers: labels, tags, fields, 
   and the others including variable and typedef names.
   NameSpace here is much simplified and different from ANSI C's.
*/
enum NameSpace {	/* 名前空間 */
  NS_GLOBAL,	/* 大域 (関数の外) */
  NS_LOCAL,	/* 局所 (関数の中) */
  NS_ARG,	/* 関数引数 */
  NS_LABEL	/* ラベル */
};

struct Symbol {		/* 記号 */
  char             *name;    /* 記号名 symbol name */
  struct Type      *type;    /* 記号の型 symbol type */
  struct AST       *ast;     /* 記号が宣言されたASTノード AST where the symbol being declared */
  int              offset;   /* オフセット(局所変数と引数)  for local vars and arguments */
  enum NameSpace   name_space;	/* 名前空間 */
  struct Symbol    *next;    /* 次の記号へのポインタ pointer to next entry */
};

struct String {		/* 文字列定数 */
  char             *data;    /* 文字列定数の内容 content of string literals */
  char             *label;   /* 文字列定数のラベル uniq labels for string literals */
  struct String    *next;	/* 次の文字列定数へのポインタ */
};

enum { MAX_BLOCK_DEPTH = 128 };
struct SymTable {
  struct Symbol    *global;	/* 大域の記号リスト */
  struct Symbol    *arg;	/* 引数の記号リスト */
  struct Symbol    *label;	/* ラベルの記号リスト */
  struct String    *string;	/* 文字列定数のリスト */
  int              local_index;	/* 局所の記号リストのネスト数 */
  struct Symbol    *local [MAX_BLOCK_DEPTH];	/* 局所の記号リストの配列 */
};
extern int max_arg_size;
extern struct SymTable sym_table;	/* 記号表 */
/* --------------------------------------------------------------------- */
struct Symbol *sym_lookup (char *name);
struct Symbol *sym_lookup_label  (char *name);
struct String *string_lookup (char *data);
void sym_entry (struct AST *ast);
void string_entry (char *data);
void sym_backpatch (struct AST *ast, struct Type *type);
void sym_begin_function (void);
void sym_end_function (struct AST *ast);
void sym_begin_block (void);
void sym_middle_block (void);
void sym_end_block (struct AST *ast);
void sym_entry_param (struct Type *func_type);
struct Symbol *sym_check_var_decl (struct AST *ast);
void sym_table_dump (void);
/* --------------------------------------------------------------------- */
#endif /* XCC_SYMBOL_H */
