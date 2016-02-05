static inline struct pthread *__pthread_self()
{
        char *tp;
        __asm__ __volatile__("mv %0, tp" : "=r"(tp));
        return (void *)(tp - sizeof(struct pthread) + 16);
}

#define TLS_ABOVE_TP
#define TP_ADJ(p) ((char *)p + sizeof(struct pthread) - 16)

#define MC_PC sc_regs.pc
