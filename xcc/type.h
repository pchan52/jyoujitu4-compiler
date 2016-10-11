/* XCC: Experimental C-subset Compiler.
  Copyright (c) 2002-2008, gondow@cs.titech.ac.jp, All rights reserved.
  $Id: type.h,v 1.1 2009/03/13 05:12:54 gondow Exp $ */ 
#ifndef XCC_TYPE_H
#define XCC_TYPE_H
/* ---------------------------------------------------------------------- */
enum PrimType {		/* 原始型(基本型) primitive type */
  PRIM_TYPE_VOID,	/* void型 */
  PRIM_TYPE_CHAR,	/* char型 */
  PRIM_TYPE_INT		/* int型 */
};

enum TypeKind {
  TYPE_KIND_PRIM,         /* 原始型 primitive type */
  TYPE_KIND_FUNCTION,     /* 関数型 function type */
  TYPE_KIND_POINTER       /* ポインタ型 pointer type */
};

struct Type {
  enum TypeKind   kind;	/* 型の種類 */
  int             size;	/* 型のサイズ total size of this type */
  char            *id;	/* 関連する識別子 NULL if no identifier is associated */
    
  union {
    struct { enum PrimType  ptype; } t_prim;	/* 原始型 */
    struct { struct Type    *type; } t_pointer;	/* ポインタ型 */
    struct {	/* 関数型 */
      struct Type *ret_type;	/* 返り値の型 */
      int      	arg_num;	/* 引数の数 */
      char        **arg_name;	/* 引数の名前の配列 array of argument names */
      struct Type **arg_type;	/* 引数の型の配列 array of argument type pointers */
    } t_function;
  } u;
};

struct Types {
  struct Type *t_void;
  struct Type *t_char;
  struct Type *t_int;
  struct Type *t_char_p;
};
/* ---------------------------------------------------------------------- */
struct Type *create_prim_type     (enum PrimType ptype);
struct Type *create_pointer_type  (struct Type *pointedto_type);
struct Type *type_analyze_declarator (struct AST *ast_decr, struct Type *type);
struct Type *type_add (struct Type *type1, struct Type *type2);
struct Type *type_sub (struct Type *type1, struct Type *type2);
struct Type *type_uop (struct AST *ast, struct Type *type1);
void type_dump (struct Type *type);
extern struct Types types;
/* ---------------------------------------------------------------------- */
#endif /* XCC_TYPE_H */
