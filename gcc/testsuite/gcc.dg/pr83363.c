/* { dg-require-effective-target noclone } */
/* PR rtl-optimization/83363 */
/* { dg-do run } */
/* { dg-options "-O2 -fno-forward-propagate" } */
/* { dg-require-effective-target gcc_frontend } */

unsigned char a;
unsigned int b;

static unsigned short __attribute__ ((noinline, noclone))
foo (unsigned short x)
{
  x -= b;
  x <<= x == 0;
  a = ~0;
  a >>= (unsigned char) x == 0;
  x *= a -= ~a;
  return x;
}

int
main ()
{
  asm volatile ("" : : : "memory");
  if (foo (3) != (unsigned short) (3 * (unsigned char) ~0))
    __builtin_abort ();
  return 0;
}
