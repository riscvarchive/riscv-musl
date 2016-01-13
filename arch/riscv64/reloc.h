#include <endian.h>

#if __BYTE_ORDER == __BIG_ENDIAN
#define ENDIAN_SUFFIX "eb"
#else
#define ENDIAN_SUFFIX ""
#endif

#ifdef __riscv_soft_float
#define FP_SUFFIX "-sf"
#else
#define FP_SUFFIX ""
#endif

#define LDSO_ARCH "riscv64" ENDIAN_SUFFIX FP_SUFFIX

#define REL_SYMBOLIC    R_RISCV_64
#define REL_PLT         R_RISCV_JUMP_SLOT
#define REL_RELATIVE    R_RISCV_RELATIVE
#define REL_COPY        R_RISCV_COPY
#define REL_DTPMOD      R_RISCV_TLS_DTPMOD64
#define REL_DTPOFF      R_RISCV_TLS_DTPREL64
#define REL_TPOFF       R_RISCV_TLS_TPREL64

#define CRTJMP(pc,sp) __asm__ __volatile__( \
                "mv sp, %1 ; jr %0" : : "r"(pc), "r"(sp) : "memory" )
