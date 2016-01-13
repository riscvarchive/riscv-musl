.global sigsetjmp
.global __sigsetjmp
.type sigsetjmp, %function
.type __sigsetjmp, %function
sigsetjmp:
__sigsetjmp:
        beqz a1, setjmp

        sd ra, 224(a0)
        sd s0, 232(a0)
        mv s0, a0

        jal setjmp

        mv a1, a0
        mv a0, s0
        ld ra, 224(a0)
        ld s0, 232(a0)

.hidden __sigsetjmp_tail
        j __sigsetjmp_tail
