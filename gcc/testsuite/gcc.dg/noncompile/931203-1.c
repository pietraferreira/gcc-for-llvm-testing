/* { dg-require-effective-target gcc_frontend } */
typedef struct
{
  int x, y;
} point_t;


point_t
f ()
{
  return 0;	/* { dg-error "incompatible types" } */
}
