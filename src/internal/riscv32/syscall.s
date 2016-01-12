.global __syscall
.hidden __syscall
.type   __syscall,%function
__syscall:
        addi t0, a0, 0
        addi a0, a1, 0
        addi a1, a2, 0
        addi a2, a3, 0
        addi a3, a4, 0
        addi a4, a5, 0
        addi a5, a6, 0
        addi a6, a7, 0
        addi a7, t0, 0
        scall
        jr ra
