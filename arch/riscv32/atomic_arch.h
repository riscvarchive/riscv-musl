#ifdef __riscv_atomic
#include "atomic_a.h"
#else
#error "Atomics unimplemented without A extension."
#endif
