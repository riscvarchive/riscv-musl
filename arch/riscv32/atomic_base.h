static inline void a_aq()
{
        __asm__("fence r, rw");
}

static inline void a_rl()
{
        __asm__("fence rw, w");
}

static inline void *a_cas_p(volatile void *p, void *t, void *s)
{
        return NULL;
}

static inline int a_cas(volatile int *p, int t, int s)
{
        return NULL;
}

static inline int a_swap(volatile int *x, int v)
{
        return NULL;
}

static inline int a_fetch_add(volatile int *x, int v)
{
        return NULL;
}

static inline void a_inc(volatile int *x)
{
}

static inline void a_dec(volatile int *x)
{
}

static inline void a_and_64(volatile uint64_t *p, uint64_t v)
{
}

static inline void a_and(volatile int *p, int v)
{
}

static inline void a_or_64(volatile uint64_t *p, uint64_t v)
{
}

static inline void a_or_l(volatile void *p, long v)
{
}

static inline void a_or(volatile int *p, int v)
{
}

static inline void a_store(volatile int *p, int x)
{
}
