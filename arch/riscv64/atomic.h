#ifndef _INTERNAL_ATOMIC_H
#define _INTERNAL_ATOMIC_H

#include <stdint.h>

static inline int a_ctz_64(uint64_t x)
{
	static const char debruijn64[64] = {
		0, 1, 2, 53, 3, 7, 54, 27, 4, 38, 41, 8, 34, 55, 48, 28,
		62, 5, 39, 46, 44, 42, 22, 9, 24, 35, 59, 56, 49, 18, 29, 11,
		63, 52, 6, 26, 37, 40, 33, 47, 61, 45, 43, 21, 23, 58, 17, 10,
		51, 25, 36, 32, 60, 20, 57, 16, 50, 31, 19, 15, 30, 14, 13, 12
	};
	return debruijn64[(x&-x)*0x022fdd63cc95386d >> 58];
}

static inline int a_ctz_l(unsigned long x)
{
        return a_ctz_64((uint64_t) x);
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
                "lr.d .aq %0, %4\n"
                "bne %0, %2, 1f\n"
                "sc.d .rl %4, %3, %1\n"
                "bne %1, %x0, 1b\n"
                "1:\n"
                : "r"(old), "r"(tmp)
                : "r"(t), "r"(s), "+A"(p));
        return (void *) old;
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
