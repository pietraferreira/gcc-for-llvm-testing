/* { dg-do compile } */
/* { dg-options "-O -fwhole-program -g" } */
/* { dg-require-effective-target gcc_internals } */

extern void *malloc(__SIZE_TYPE__);

struct S {
  int i;
};

int main(int argc, char *argv[])
{
  int i = argc;
  struct S *p = malloc(sizeof (struct S));
  return p[i].i;
}
