/* { dg-do compile } */
/* { dg-options "-O1 -fdump-tree-optimized" } */
/* { dg-additional-options "-mbranch-cost=2" { target branch_cost } } */
/* { dg-require-effective-target gcc_frontend } */

int f(int a, int b, int c)
{
  if (a == 0 && b > c)
   return 0;
 return a;
}

int g(int a, int b, int c)
{
  if (a == 42 && b > c)
   return 42;
 return a;
}

int h(int a, int b, int c, int d)
{
  if (a == d && b > c)
   return d;
 return a;
}

/* { dg-final { scan-tree-dump-times "if" 0 "optimized" { target { ! logical_op_short_circuit } } } } */
/* { dg-final { scan-tree-dump-times "if" 2 "optimized" { target logical_op_short_circuit } } } */
