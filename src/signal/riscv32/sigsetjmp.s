.global sigsetjmp
.global __sigsetjmp
.type sigsetjmp, %function
.type __sigsetjmp, %function
sigsetjmp:
__sigsetjmp:
        beqz a1, setjmp

        sw ra, 160(a0)
        sw s0, 164(a0)
        mv s0, a0

        jal setjmp

        mv a1, a0
        mv a0, s0
        lw s0, 164(a0)
        lw ra, 160(a0)

.hidden __sigsetjmp_tail
        j __sigsetjmp_tail
