/* PR debug/94283 */
/* { dg-do compile } */
/* { dg-options "-O3 -fno-tree-dce -fcompare-debug" } */
/* { dg-require-effective-target not_llvm } */

void
foo (int *n)
{
  for (int i = 0; i < 32; i++)
    {
      int x = 0;
      x++;
      if (i & 4)
	x++;
      x++;
    }
}
