/* { dg-do compile } */
/* { dg-options "-O3 -ftracer -fno-tree-ccp -fno-tree-copy-prop -fno-tree-dce" } */
/* { dg-require-effective-target gcc_internals } */

char *vx;
char buf[20];

void
foo (void)
{
  vx = __builtin___stpcpy_chk (buf, vx ? "gh" : "e", sizeof(buf));
}
