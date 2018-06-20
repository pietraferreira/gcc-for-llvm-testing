/* PR c/9262 */
/* Originator: Rasmus Hahn <rassahah@neofonie.de> */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

int foo(int i)
{
  switch (i)
    case 3:
      return 1;
    case 4:      /* { dg-error "not within a switch statement" } */
      return 1;
}
