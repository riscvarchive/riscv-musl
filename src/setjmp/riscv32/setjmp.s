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
        fsd fs0,  60(a0)
        fsd fs1,  68(a0)
        fsd fs2,  76(a0)
        fsd fs3,  84(a0)
        fsd fs3,  92(a0)
        fsd fs4,  100(a0)
        fsd fs5,  108(a0)
        fsd fs6,  116(a0)
        fsd fs7,  124(a0)
        fsd fs8,  132(a0)
        fsd fs9,  140(a0)
        fsd fs10, 148(a0)
        fsd fs11, 156(a0)
        li a0, 0
        ret
