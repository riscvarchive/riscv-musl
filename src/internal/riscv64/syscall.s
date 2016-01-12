.global __syscall
.hidden __syscall
.type   __syscall,%function
__syscall:
        mv t0, a0
        mv a0, a1
        mv a1, a2
        mv a2, a3
        mv a3, a4
        mv a4, a5
        mv a5, a6
        mv a6, a7
        mv a7, t0
        scall
        ret
