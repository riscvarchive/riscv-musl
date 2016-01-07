static inline void __a_aq()
{
        __asm__("fence r, rw");
}

static inline void __a_rl()
{
        __asm__("fence rw, w");
}

static inline int a_cas(volatile int *p, int t, int s)
{
        __a_aq();
        int old = *p;
        if (*p == t) {
                *p = s;
        }
        __a_rl();
        return t;
}

static inline void *a_cas_p(volatile void *p, void *t, void *s)
{
        return (void *) a_cas(p, (int) t, (int) s);
}

static inline int a_swap(volatile int *x, int v)
{
        __a_aq();
        int old = *x;
        *x = v;
        __a_rl();
        return old;
}

static inline int a_fetch_add(volatile int *x, int v)
{
        __a_aq();
        int tmp = *x + v;
        *x = tmp;
        __a_rl();
        return tmp;
}

static inline void a_inc(volatile int *x)
{
        __a_aq();
        *x = *x + 1;
        __a_rl();
}

static inline void a_dec(volatile int *x)
{
        __a_aq();
        *x = *x - 1;
        __a_rl();
}

static inline void a_and_64(volatile uint64_t *p, uint64_t v)
{
        __a_aq();
        *p &= v;
        __a_rl();
}

static inline void a_and(volatile int *p, int v)
{
        __a_aq();
        *p &= v;
        __a_rl();
}

static inline void a_or_64(volatile uint64_t *p, uint64_t v)
{
        __a_aq();
        *p |= v;
        __a_rl();
}

static inline void a_or_l(volatile void *p, long v)
{
        a_or_64(p, (uint64_t) v);
}

static inline void a_or(volatile int *p, int v)
{
        __a_aq();
        *p |= v;
        __a_rl();
}

static inline void a_store(volatile int *p, int x)
{
        __a_aq();
        *p = x;
        __a_rl();
}
