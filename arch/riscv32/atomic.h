#ifndef _INTERNAL_ATOMIC_H
#define _INTERNAL_ATOMIC_H

#include <stdint.h>

static inline int a_ctz_64(uint64_t x)
{
}

static inline int a_ctz_l(unsigned long x)
{
}

static inline void a_barrier()
{
}

static inline void *a_cas_p(volatile void *p, void *t, void *s)
{
        void *old;
        int tmp;
        __asm__(
                "1:\n"
                "lr.w .aq %0, %4\n"
                "bne %0, %2, 1f\n"
                "sc.w .rl %4, %3, %1\n"
                "bne %1, %x0, 1b\n"
                "1:\n"
                : "r"(old), "r"(tmp)
                : "r"(t), "r"(s), "+A"(p));
        return old;
}

static inline int a_cas(volatile int *p, int t, int s)
{
        int old, tmp;
        __asm__(
                "1:\n"
                "lr.w .aq %0, %4\n"
                "bne %0, %2, 1f\n"
                "sc.w .rl %4, %3, %1\n"
                "bne %1, %x0, 1b\n"
                "1:\n"
                : "r"(old), "r"(tmp)
                : "r"(t), "r"(s), "+A"(p));
        return old;
}

static inline int a_swap(volatile int *x, int v)
}

static inline int a_fetch_add(volatile int *x, int v)
{
}

static inline void a_inc(volatile int *x)
{
}

static inline void a_dec(volatile int *x)
{
}

static inline void a_and_64(volatile uint64_t *p, uint64_t v)
{
}

static inline void a_and(volatile int *p, int v)
{
}

static inline void a_or_64(volatile uint64_t *p, uint64_t v)
{
}

static inline void a_or_l(volatile void *p, long v)
{
}

static inline void a_or(volatile int *p, int v)
{
}

static inline void a_store(volatile int *p, int x)
{
}

static inline void a_spin()
{
}

static inline void a_crash()
{
}

#endif
