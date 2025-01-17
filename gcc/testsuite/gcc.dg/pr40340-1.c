/* PR middle-end/40340 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-O2 -Wall -Wno-system-headers" } */

#include "pr40340.h"

static inline
__attribute__ ((always_inline))
void
test (char *p)
{
  memset (p, 0, 6);
}

int
main (void)
{
  char buf[4];
  test (buf);
  return 0;
}

/* { dg-warning "writing" "" { target *-*-* } 10 } */
/* { dg-message "file included" "In file included" { target *-*-* } 0 } */
