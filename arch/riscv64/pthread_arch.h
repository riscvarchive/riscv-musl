static inline struct pthread *__pthread_self()
{
        struct pthread *self;
        __asm__ __volatile__("addi %0, tp, 0" : "=r"(self));
        return self;
}

#define TP_ADJ(p) (p)

#define MC_PC gregs[0]
