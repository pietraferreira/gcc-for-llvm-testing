/* This is from PR c/25892.  See Wpointer-sign.c for more details.  */

/* { dg-options "-pedantic" } */
/* { dg-require-effective-target gcc_frontend } */

void foo(unsigned long* ulp);/* { dg-message "note: expected '\[^'\n\]*' but argument is of type '\[^'\n\]*'" "note: expected" } */

void bar(long* lp) {
  foo(lp); /* { dg-warning "differ in signedness" } */
}
