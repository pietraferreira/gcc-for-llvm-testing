/* PR c/69974 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

struct S;
char foo (struct S *);
struct S a;	/* { dg-error "storage size of 'a' isn't known" } */
int b;

void
bar ()
{
  b &= foo (&a);
}
