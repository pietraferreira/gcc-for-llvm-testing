/* { dg-do compile } */
/* { dg-options "-Wuninitialized" } */
/* { dg-require-effective-target gcc_frontend } */

typedef _Complex float C;
C foo()
{
  C f;
  __imag__ f = 0;	/* { dg-warning "is used" "unconditional" { xfail *-*-* } } */
  return f;
}
