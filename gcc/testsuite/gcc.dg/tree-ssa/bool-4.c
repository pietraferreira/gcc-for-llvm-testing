/* { dg-do compile } */
/* { dg-options "-O1 -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_frontend } */

int f(_Bool x)
{
  return (x != 0);
}

/* There should be no != 0 which is produced by the front-end as
   bool_var != 0 is the same as bool_var. */
/* { dg-final { scan-tree-dump-times "!= 0" 0 "optimized"} } */

/* There should be no adde for powerpc.  Check if we actually optimized
   away the comparison.  */
/* { dg-final { scan-assembler-times "adde" 0 { target powerpc*-*-* } } } */

