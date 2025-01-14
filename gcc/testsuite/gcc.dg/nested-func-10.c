/* PR c/70093 */
/* { dg-do compile } */
/* { dg-options "" } */
/* { dg-require-effective-target alloca } */
/* { dg-require-effective-target vla_in_struct } */
/* { dg-require-effective-target nested_func } */
/* { dg-require-effective-target noclone } */

void __attribute__((noinline, noclone))
foo (int n)
{
  struct S { int a[n]; };

  struct S __attribute__((noreturn))
  fn (void)
  {
    __builtin_abort ();
  }

  auto struct S __attribute__((noreturn))
  fn2 (void)
  {
    __builtin_abort ();
  }

  struct S x;
  __typeof__ (fn ()) *p = &x;
  switch (n)
    {
    case 1:
      fn ();
      break;
    case 2:
      fn2 ();
      break;
    case 3:
      x = fn ();
      if (x.a[0] != 42)
	__builtin_abort ();
      break;
    case 4:
      if (fn ().a[0] != 42)
	__builtin_abort ();
      break;
    case 5:
      if (p->a[0] != 42)
	__builtin_abort ();
      break;
    case 6:
      if (fn2 ().a[0] != 42)
	__builtin_abort ();
      break;
    }
}

int
main (void)
{
  foo (1);
}
