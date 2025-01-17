/* Test operation of -Wparentheses.  Precedence warnings.  + or -
   inside shift.  */
/* Origin: Joseph Myers <jsm@polyomino.org.uk> */

/* { dg-do compile } */
/* { dg-options "-Wparentheses" } */
/* { dg-additional-options "-Wno-return-type" } */
/* { dg-require-effective-target gcc_frontend } */

int foo (int);

int
bar (int a, int b, int c)
{
  foo (a + b << c); /* { dg-warning "parentheses" "correct warning" } */
  foo ((a + b) << c);
  foo (a + (b << c));
  foo (1 + 2 << c); /* { dg-warning "parentheses" "correct warning" } */
  foo ((1 + 2) << c);
  foo (1 + (2 << c));
  foo (1 + 2 << 3); /* { dg-warning "parentheses" "correct warning" } */
  foo ((1 + 2) << 3);
  foo (1 + (2 << 3));
  foo (a << b + c); /* { dg-warning "parentheses" "correct warning" } */
  foo ((a << b) + c);
  foo (a << (b + c));
  foo (1 << 2 + c); /* { dg-warning "parentheses" "correct warning" } */
  foo ((1 << 2) + c);
  foo (1 << (2 + c));
  foo (1 << 2 + 3); /* { dg-warning "parentheses" "correct warning" } */
  foo ((1 << 2) + 3);
  foo (1 << (2 + 3));
  foo (a + b >> c); /* { dg-warning "parentheses" "correct warning" } */
  foo ((a + b) >> c);
  foo (a + (b >> c));
  foo (1 + 2 >> c); /* { dg-warning "parentheses" "correct warning" } */
  foo ((1 + 2) >> c);
  foo (1 + (2 >> c));
  foo (1 + 2 >> 3); /* { dg-warning "parentheses" "correct warning" } */
  foo ((1 + 2) >> 3);
  foo (1 + (2 >> 3));
  foo (a >> b + c); /* { dg-warning "parentheses" "correct warning" } */
  foo ((a >> b) + c);
  foo (a >> (b + c));
  foo (1 >> 2 + c); /* { dg-warning "parentheses" "correct warning" } */
  foo ((1 >> 2) + c);
  foo (1 >> (2 + c));
  foo (1 >> 2 + 3); /* { dg-warning "parentheses" "correct warning" } */
  foo ((1 >> 2) + 3);
  foo (1 >> (2 + 3));
  foo (a - b << c); /* { dg-warning "parentheses" "correct warning" } */
  foo ((a - b) << c);
  foo (a - (b << c));
  foo (6 - 5 << c); /* { dg-warning "parentheses" "correct warning" } */
  foo ((6 - 5) << c);
  foo (6 - (5 << c));
  foo (6 - 5 << 4); /* { dg-warning "parentheses" "correct warning" } */
  foo ((6 - 5) << 4);
  foo (6 - (5 << 4));
  foo (a << b - c); /* { dg-warning "parentheses" "correct warning" } */
  foo ((a << b) - c);
  foo (a << (b - c));
  foo (6 << 5 - c); /* { dg-warning "parentheses" "correct warning" } */
  foo ((6 << 5) - c);
  foo (6 << (5 - c));
  foo (6 << 5 - 4); /* { dg-warning "parentheses" "correct warning" } */
  foo ((6 << 5) - 4);
  foo (6 << (5 - 4));
  foo (a - b >> c); /* { dg-warning "parentheses" "correct warning" } */
  foo ((a - b) >> c);
  foo (a - (b >> c));
  foo (6 - 5 >> c); /* { dg-warning "parentheses" "correct warning" } */
  foo ((6 - 5) >> c);
  foo (6 - (5 >> c));
  foo (6 - 5 >> 4); /* { dg-warning "parentheses" "correct warning" } */
  foo ((6 - 5) >> 4);
  foo (6 - (5 >> 4));
  foo (a >> b - c); /* { dg-warning "parentheses" "correct warning" } */
  foo ((a >> b) - c);
  foo (a >> (b - c));
  foo (6 >> 5 - c); /* { dg-warning "parentheses" "correct warning" } */
  foo ((6 >> 5) - c);
  foo (6 >> (5 - c));
  foo (6 >> 5 - 4); /* { dg-warning "parentheses" "correct warning" } */
  foo ((6 >> 5) - 4);
  foo (6 >> (5 - 4));
}
