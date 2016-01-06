struct user_regs_struct {
	unsigned long pc;
	unsigned long ra;
	unsigned long s[12];
	unsigned long sp;
	unsigned long tp;
	unsigned long v[2];
	unsigned long a[8];
	unsigned long t[5];
	unsigned long gp;
	unsigned long status;
};
#define ELF_NGREG 32
#define ELF_NFPREG 32
typedef unsigned long elf_greg_t, elf_gregset_t[ELF_NGREG];
typedef double elf_fpreg_t, elf_fpregset_t[ELF_NFPREG];
