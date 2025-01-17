/* Test diagnostics for duplicate field names involving anonymous
   struct or union as first field.  PR 46889.  */
/* { dg-do compile } */
/* { dg-options "" } */
/* { dg-require-effective-target gcc_frontend } */

struct foo {
  union {
    struct {
      unsigned long time_stamp;
    };
    struct {
      int *page;
    };
  };
  int *page; /* { dg-error "duplicate member" } */
};
