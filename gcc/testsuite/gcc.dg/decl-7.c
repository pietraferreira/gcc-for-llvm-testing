/* Test diagnostic for array defaulting to one element.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "" } */

int a[]; /* { dg-warning "array 'a' assumed to have one element" } */
