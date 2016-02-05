#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
# define MINSIGSTKSZ 2048
# define SIGSTKSZ 8192
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
typedef unsigned long greg_t, gregset_t[32];
typedef struct user_fpregs_struct {
        double f[32];
        unsigned long fcsr;
} fpregset_t;
typedef struct sigcontext {
        struct user_regs_struct {
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
        } sc_regs;
        struct user_fpregs_struct sc_fpregs;
} mcontext_t;
#else
typedef struct {
        unsigned long __regs[32 + 32 + 1];
} mcontext_t;
#endif

struct sigaltstack {
        void *ss_sp;
        size_t ss_size;
        int ss_flags;
};

typedef struct __ucontext
{
        unsigned long uc_flags;
        struct __ucontext *uc_link;
        stack_t uc_stack;
        mcontext_t uc_mcontext;
        sigset_t uc_sigmask;
} ucontext_t;

#define SA_NOCLDSTOP 1
#define SA_NOCLDWAIT 2
#define SA_SIGINFO   4
#define SA_ONSTACK   0x08000000
#define SA_RESTART   0x10000000
#define SA_NODEFER   0x40000000
#define SA_RESETHAND 0x80000000
#define SA_RESTORER  0x04000000

#endif

#define SIGHUP     1
#define SIGINT     2
#define SIGQUIT    3
#define SIGILL     4
#define SIGTRAP    5
#define SIGABRT    6
#define SIGIOT     SIGABRT
#define SIGBUS     7
#define SIGFPE     8
#define SIGKILL    9
#define SIGUSR1   10
#define SIGSEGV   11
#define SIGUSR2   12
#define SIGPIPE   13
#define SIGALRM   14
#define SIGTERM   15
#define SIGSTKFLT 16
#define SIGCHLD   17
#define SIGCONT   18
#define SIGSTOP   19
#define SIGTSTP   20
#define SIGTTIN   21
#define SIGTTOU   22
#define SIGURG    23
#define SIGXCPU   24
#define SIGXFSZ   25
#define SIGVTALRM 26
#define SIGPROF   27
#define SIGWINCH  28
#define SIGIO     29
#define SIGPOLL   SIGIO
#define SIGPWR    30
#define SIGSYS    31
#define SIGUNUSED SIGSYS

#define _NSIG     65
