extern void abort() __attribute__ ((noreturn));

struct s
{
  unsigned long long f1 : 40;
#if(__SIZEOF_INT__ >= 4)
  unsigned int f2 : 24;
#else
  unsigned long int f2 : 24;
#endif
} sv;

int main()
{
  long f2;
  sv.f2 = ((long)1 << 24) - 1;
  __asm__ volatile ("" : : : "memory");
  ++sv.f2;
  f2 = sv.f2;
  if (f2 != 0)
    abort();
  return 0;
}
