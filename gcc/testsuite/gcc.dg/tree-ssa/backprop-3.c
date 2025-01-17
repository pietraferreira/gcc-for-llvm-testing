/* { dg-do compile } */
/* { dg-options "-O -g -fdump-tree-backprop-details" }  */
/* { dg-require-effective-target gcc_frontend } */

/* Test a simple case of non-looping code in which one use ignores
   the sign but another doesn't.  */
#define TEST_FUNCTION(TYPE, SUFFIX)				\
  TYPE								\
  test##SUFFIX (TYPE x, int sel1, int sel2)			\
  {								\
    TYPE input = sel1 ? -x : __builtin_fabs##SUFFIX (x);	\
    if (sel2)							\
      return __builtin_cos##SUFFIX (input);			\
    else							\
      return __builtin_sin##SUFFIX (input);			\
  }

TEST_FUNCTION (float, f)
TEST_FUNCTION (double, )
TEST_FUNCTION (long double, l)

/* { dg-final { scan-tree-dump-times {Deleting[^\n]* = -x} 0 "backprop" } } */
