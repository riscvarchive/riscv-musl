typedef struct user_regs_struct {
        unsigned long pc;
        unsigned long ra;
        unsigned long sp;
        unsigned long gp;
	unsigned long tp;
	unsigned long t0, t1, t2;
	unsigned long s0, s1;
	unsigned long a0, a1, a2, a3, a4, a5, a6, a7;
	unsigned long s2, s3, s4, s5, s6, s7, s8, s9, s10, s11;
	unsigned long t3, t4, t5, t6;
} elf_gregset_t;

#define ELF_NGREG 32
typedef struct user_fpregs_struct {
        double f[32];
        unsigned long fcsr;
} elf_fpregset_t;

typedef unsigned long elf_greg_t;
