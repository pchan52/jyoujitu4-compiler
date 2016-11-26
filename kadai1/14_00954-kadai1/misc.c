/* XCC: Experimental C-subset compiler.
  Copyright (c) 2002-2008, gondow@cs.titech.ac.jp, All rights reserved.
  $Id: misc.c,v 1.1 2009/03/13 05:12:54 gondow Exp $ */ 
/* --------------------------------------------------------------------- */
#include <stdio.h>
#include <string.h>  /* for strcpy */
#include <assert.h>  /* for assert */
#include <stdlib.h>  /* for malloc */
#include "misc.h"
/* --------------------------------------------------------------------- */
/* --------------------------------------------------------------------- */
void *
emalloc (size_t nbytes)
{ 
  void *p = malloc (nbytes);
  if (p == NULL) perror ("malloc");
  return p;
}

void
efree (void *ptr)
{
  free (ptr);
}
/* ---------------------------------------------------------------------- */
