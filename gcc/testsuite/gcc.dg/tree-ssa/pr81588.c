/* PR tree-optimization/81588 */
/* { dg-do compile } */
/* { dg-require-effective-target noclone } */
/* { dg-options "-O2 -fdump-tree-reassoc1-details" } */
/* { dg-require-effective-target gcc_frontend } */
 	
extern long long int a, c;
extern unsigned short b;

/* { dg-final { scan-tree-dump-times "Optimizing range test \[^\n\r]* and comparison" 1 "reassoc1" } } */

__attribute__((noinline, noclone)) void
foo (void)
{
  if ((b > a) != (1 + (a < 0)))
    c = 0;
}
