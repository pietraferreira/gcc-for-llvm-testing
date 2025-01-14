/* PR c/27301 */
/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu89" } */
/* { dg-require-effective-target alloca } */
/* { dg-require-effective-target vla_in_struct } */

void
foo (void *ptr, long n)
{
  __asm__ __volatile__ ("" :: "m" (({ struct { char x[n]; } *p = ptr; *p; })));
}

void
bar (void *ptr, long n)
{
  __asm__ __volatile__ ("" :: "m" (*({ struct { char x[n]; } *p = ptr; p; })));
}
