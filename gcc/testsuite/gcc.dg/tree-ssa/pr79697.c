/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-gimple -fdump-tree-cddce-details -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_frontend } */

void f(void)
{
  __builtin_strdup ("abc");
}

void g(void)
{
  __builtin_strndup ("abc", 3);
}

void h(void)
{
  __builtin_realloc (0, 10);
}

/* { dg-final { scan-tree-dump "Deleting : __builtin_strdup" "cddce1" } } */
/* { dg-final { scan-tree-dump "Deleting : __builtin_strndup" "cddce1" } } */
/* { dg-final { scan-tree-dump "__builtin_malloc" "gimple" } } */
