#if defined __riscv_float_abi_soft
#define RISCV_FP_SUFFIX "-sf"
#elif defined __riscv_float_abi_single
#define RISCV_FP_SUFFIX "-sp"
#elif defined __riscv_float_abi_double
#define RISCV_FP_SUFFIX ""
#endif

#define RISCV_LDSO_HELPER(x) "riscv" #x
#define RISCV_LDSO(x) RISCV_LDSO_HELPER(x)

#define LDSO_ARCH RISCV_LDSO(__riscv_xlen) RISCV_FP_SUFFIX

#define NO_LEGACY_INITFINI

#define TPOFF_K 16

#define REL_SYMBOLIC    R_RISCV_64
#define REL_PLT         R_RISCV_JUMP_SLOT
#define REL_RELATIVE    R_RISCV_RELATIVE
#define REL_COPY        R_RISCV_COPY
#define REL_DTPMOD      R_RISCV_TLS_DTPMOD64
#define REL_DTPOFF      R_RISCV_TLS_DTPREL64
#define REL_TPOFF       R_RISCV_TLS_TPREL64

#define CRTJMP(pc,sp) __asm__ __volatile__( \
                "mv sp, %1 ; jr %0" : : "r"(pc), "r"(sp) : "memory" )
