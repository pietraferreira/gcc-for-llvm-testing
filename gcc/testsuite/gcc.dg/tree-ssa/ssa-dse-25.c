/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-dse1-details -w" } */
/* { dg-require-effective-target gcc_frontend } */

char z[32];


int
foo(void)
{
  memset (z, 0, 16);
  memset (z+8, 0, 24);
}

/* { dg-final { scan-tree-dump "memset .&z, 0, 8." "dse1" } } */


