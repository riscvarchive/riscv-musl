#include "syscall.h"

#define ATOMIC_CMPXCHG 1

#define a_cas a_cas
static inline int a_cas(volatile int *p, int t, int s)
{
        return __syscall4(SYS_sysriscv, ATOMIC_CMPXCHG, p, t, s);
}
