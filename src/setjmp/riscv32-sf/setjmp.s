.global __setjmp
.global _setjmp
.global setjmp
.type __setjmp, %function
.type _setjmp,  %function
.type setjmp,   %function
__setjmp:
_setjmp:
setjmp:
        sw s0,    0(a0)
        sw s1,    4(a0)
        sw s2,    8(a0)
        sw s3,    12(a0)
        sw s4,    16(a0)
        sw s5,    20(a0)
        sw s6,    24(a0)
        sw s7,    28(a0)
        sw s8,    32(a0)
        sw s9,    36(a0)
        sw s10,   40(a0)
        sw s11,   44(a0)
        sw tp,    48(a0)
        sw sp,    52(a0)
        sw ra,    56(a0)
        li a0, 0
        ret
