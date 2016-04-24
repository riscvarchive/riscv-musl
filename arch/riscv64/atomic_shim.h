#include "syscall.h"

#define ATOMIC_CMPXCHG 1
#define ATOMIC_CMPXCHG64 2

#define a_cas a_cas
static inline int a_cas(volatile int *p, int t, int s)
{
        return __syscall4(SYS_sysriscv, ATOMIC_CMPXCHG, p, t, s);
}

#define a_cas_p a_cas_p
static inline void *a_cas_p(volatile void *p, void *t, void *s)
{
        return __syscall4(SYS_sysriscv, ATOMIC_CMPXCHG64, p, t, s);
}
