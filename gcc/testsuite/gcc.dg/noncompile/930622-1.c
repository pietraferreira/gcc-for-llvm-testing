/* { dg-require-effective-target gcc_frontend } */
void
f ()
{
  double b;
  b = b * 10;
  goto c;	/* { dg-error "used but not defined" } */
}
