/* XCC: Experimental C-subset Compiler.
  Copyright (c) 2002-2008, gondow@cs.titech.ac.jp, All rights reserved.
  $Id: AST.h,v 1.4 2009/03/27 10:12:09 gondow Exp gondow $ */ 
#ifndef XCC_AST_H
#define XCC_AST_H
/* ---------------------------------------------------------------------- */
struct AST {
  /* common members */
  char           *ast_type; /* ノードの種類 AST type of this node */
  struct AST     *parent;   /* 親ノードへのポインタ back pointer for parent. NULL for root */
  int            nth;	      /* 親から見て自分が何番目の子供か this AST is the nth child of the parent */
  int            num_child; /* 子ノードの数 num of children */
  struct AST     **child;   /* 子ノードへのポインタの配列 array of pointers to children */
  
  /* misc values for specific AST nodes */
  struct Type    *type; /* 型 for declaration and expression */
  union {
    char   *id;       /* 識別子 for AST_IDENTIFIER, AST_expression_string */
    int    int_val;   /* 整数定数の値 for AST_expression_int */
    struct {
      int    total_arg_size;	/* 引数の合計サイズ */
      int    total_local_size;	/* 局所変数の合計サイズ */
      struct Symbol *global;	/* 関数、大域変数情報のリスト */
      struct Symbol *arg;	/* 引数情報のリスト */
      struct Symbol *label;	/* ラベル情報のリスト */
      struct String *string;	/* 文字列定数のリスト */
    } func;                /* for AST_function_definition */
    struct Symbol *local;  /* 局所変数情報のリスト for AST_compound_statement */
    int    arg_size;       /* 引数のサイズ for AST_argument_expression_list_* */
  } u;
};
/* ---------------------------------------------------------------------- */
struct AST *search_AST_bottom (struct AST *root, char *bottom, int *n);
struct AST *create_AST (char *ast_type, int argp_len, ...);
void dump_AST (struct AST *ast, int indent_depth);
/* ---------------------------------------------------------------------- */
#endif /* XCC_AST_H */
