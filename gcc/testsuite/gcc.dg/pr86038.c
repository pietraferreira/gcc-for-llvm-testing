/* { dg-do compile } */
/* { dg-require-effective-target pthread } */
/* { dg-options "-O2 -ftracer -ftree-parallelize-loops=2 -fno-tree-scev-cprop --param parloops-schedule=dynamic" } */
/* { dg-require-effective-target gcc_frontend } */

int
sd (int lw)
{
  while (lw < 1)
    ++lw;

  return lw;
}
