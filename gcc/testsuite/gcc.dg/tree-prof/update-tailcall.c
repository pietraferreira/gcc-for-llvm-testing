/* { dg-options "-O2 -fdump-tree-tailc -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_frontend } */
__attribute__ ((noinline))
int factorial(int x)
{
   if (x == 1)
     return 1;
   else
     return x*factorial(--x);
}
int gbl;
int
main()
{
   gbl = factorial(100);
   return 0;
}
/* { dg-final-use { scan-tree-dump-not "Invalid sum" "tailc"} } */
/* { dg-final-use { scan-tree-dump-not "Invalid sum" "optimized"} } */
