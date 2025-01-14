/* { dg-do compile } */
/* { dg-options "-fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_internals } */
/* { dg-skip-if "" { *-*-* } { "-fno-fat-lto-objects" } { "" } } */
/* { dg-require-effective-target indirect_jumps } */

struct __jmp_buf_tag {};
typedef struct __jmp_buf_tag jmp_buf[1];
extern int _setjmp (struct __jmp_buf_tag __env[1]);

jmp_buf g_return_jmp_buf;

void SetNaClSwitchExpectations (void)
{
  __builtin_longjmp (g_return_jmp_buf, 1);
}
void TestSyscall(void)
{
  SetNaClSwitchExpectations();
  _setjmp (g_return_jmp_buf);
}

/* { dg-final { scan-tree-dump "setjmp" "optimized" } } */
