/* { dg-do compile } */
/* { dg-options "-O2 -fno-strict-overflow -fdump-tree-ivcanon-details" } */
/* { dg-require-effective-target gcc_frontend } */

void bar();
void foo(char *dst)
{
  char *const end = dst;
  do {
    bar();
    dst += 2;
  } while (dst < end);
}

/* { dg-final { scan-tree-dump " zero if " "ivcanon" } } */
