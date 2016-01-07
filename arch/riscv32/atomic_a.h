static inline int a_cas(volatile int *p, int t, int s)
{
        int old, tmp;
        __asm__(
                "li %1, 1\n"
                "1:\n\t"
                "lr.w %0, %4\n\t"
                "bne %0, %2, 1f\n\t"
                "sc.w %1, %3, %4\n\t"
                "bnez %1, 1b\n"
                "1:"
                : "r"(old), "r"(tmp)
                : "r"(t), "r"(s), "+A"(*(p)));
        return old;
}

static inline void *a_cas_p(volatile void *p, void *t, void *s)
{
        return (void *) a_cas(p, (int) t, (int) s);
}

static inline int a_swap(volatile int *x, int v)
{
        int old;
        __asm__(
                "amoswap.w.aq.rl %0, %1, %2"
                : "r"(old)
                : "r"(v), "+A"(*(x)));
        return old;
}

static inline int a_fetch_add(volatile int *x, int v)
{
        int tmp;
        __asm__(
                "amoadd.w.aq.rl %0, %1, %2"
                :"r"(tmp)
                :"r"(v), "+A"(*(x)));
        return tmp;
}

static inline void a_inc(volatile int *x)
{
        a_fetch_add(x, 1);
}

static inline void a_dec(volatile int *x)
{
        a_fetch_add(x, -1);
}

static inline void a_and_64(volatile uint64_t *p, uint64_t v)
{
        volatile uint32_t *x = (volatile uint32_t*) p;
        uint32_t y = (uint32_t) v;
        int tmp;
        __asm__("amoand.w.aq %0, %1, %2"
                :"r"(tmp)
                :"r"(y), "+A"(*(x)));
        y = (uint32_t) (v >> 32);
        x += 1;
        __asm__("amoand.w.rl %0, %1, %2"
                :"r"(tmp)
                :"r"(y), "+A"(*(x)));
}

static inline void a_and(volatile int *p, int v)
{
        int tmp;
        __asm__(
                "amoand.w.aq.rl %0, %1, %2"
                :"r"(tmp)
                :"r"(v), "+A"(*(p)));
}

static inline void a_or_64(volatile uint64_t *p, uint64_t v)
{
        volatile uint32_t *x = (volatile uint32_t*) p;
        uint32_t y = (uint32_t) v;
        int tmp;
        __asm__("amoor.w.aq %0, %1, %2"
                :"r"(tmp)
                :"r"(y), "+A"(*(x)));
        y = (uint32_t) (v >> 32);
        x += 1;
        __asm__("amoor.w.rl %0, %1, %2"
                :"r"(tmp)
                :"r"(y), "+A"(*(x)));
}

static inline void a_or(volatile int *p, int v)
{
        int tmp;
        __asm__(
                "amoor.w.aq.rl %0, %1, %2"
                :"r"(tmp)
                :"r"(v), "+A"(*(p)));
}

static inline void a_or_l(volatile void *p, long v)
{
        a_or(p, (int) v);
}

static inline void a_store(volatile int *p, int x)
{
        __asm__(
                "amoswap.w.aq.rl %zero, %0, %1"
                :"r"(x), "+A"(*(p)));
}
