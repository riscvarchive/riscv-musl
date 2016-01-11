#ifndef _INTERNAL_ATOMIC_H
#define _INTERNAL_ATOMIC_H

#include <stdint.h>

#ifdef __riscv_atomic
#include "atomic_a.h"
#else
#error "Atomics unimplemented without A extension."
#endif

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
        __asm__("fence");
}

#define a_spin a_barrier

static inline void a_crash()
{
        *(volatile char*) 0 = 0;
}

#endif
