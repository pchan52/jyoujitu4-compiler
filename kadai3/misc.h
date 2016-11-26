/* XCC: Experimental C-subset Compiler.
  Copyright (c) 2002-2008, gondow@cs.titech.ac.jp, All rights reserved.
  $Id: misc.h,v 1.1 2009/03/13 05:12:54 gondow Exp $ */ 
#ifndef XCC_MISC_H
#define XCC_MISC_H
/* --------------------------------------------------------------------- */
#define ROUNDUP(p, n)      ((((unsigned int)p)+((n)-1)) & ~((n)-1))
#define ROUNDUP_INT(p)     ROUNDUP((p), 4)
#define ROUNDUP_ANY(p)     ROUNDUP((p), 4)
#define ROUNDUP_STACK(p)   ROUNDUP((p), 4)
/* --------------------------------------------------------------------- */
void *emalloc (size_t nbytes);
void efree (void *ptr);
/* --------------------------------------------------------------------- */
#endif /* XCC_MISC_H */
