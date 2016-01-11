#ifndef _INTERNAL_ATOMIC_H
#define _INTERNAL_ATOMIC_H

#include <stdint.h>

#ifdef __riscv_atomic
#include "atomic_a.h"
#else
#error "Atomics unimplemented without A extension."
#endif

static inline int a_ctz_l(unsigned long x)
{
	static const char debruijn32[32] = {
		0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13,
		31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14
	};
	return debruijn32[(x&-x)*0x076be629 >> 27];
}

static inline int a_ctz_64(uint64_t x)
{
        uint32_t y = x;
        if (!y) {
                y = x >> 32;
                return 32 + a_ctz_l(y);
        }
        return a_ctz_l(y);
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
