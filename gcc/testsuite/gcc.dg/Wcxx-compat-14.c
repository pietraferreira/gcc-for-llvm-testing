/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-Wc++-compat" } */

char a1[] = "a";
char a2[1] = "a";	/* { dg-warning "C\[+\]\[+\]" } */
char a3[2] = "a";
