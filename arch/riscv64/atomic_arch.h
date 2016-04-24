#ifdef __riscv_atomic
#include "atomic_a.h"
#else
#include "atomic_shim.h"
#endif
