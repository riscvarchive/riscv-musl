.global __longjmp
.global _longjmp
.global longjmp
.type __longjmp, %function
.type _longjmp,  %function
.type longjmp,   %function
__longjmp:
_longjmp:
longjmp:
        lw s0,    0(a0)
        lw s1,    4(a0)
        lw s2,    8(a0)
        lw s3,    12(a0)
        lw s4,    16(a0)
        lw s5,    20(a0)
        lw s6,    24(a0)
        lw s7,    28(a0)
        lw s8,    32(a0)
        lw s9,    36(a0)
        lw s10,   40(a0)
        lw s11,   44(a0)
        lw tp,    48(a0)
        lw sp,    52(a0)
        lw ra,    56(a0)
        fld fs0,  60(a0)
        fld fs1,  68(a0)
        fld fs2,  76(a0)
        fld fs3,  84(a0)
        fld fs3,  92(a0)
        fld fs4,  100(a0)
        fld fs5,  108(a0)
        fld fs6,  116(a0)
        fld fs7,  124(a0)
        fld fs8,  132(a0)
        fld fs9,  140(a0)
        fld fs10, 148(a0)
        fld fs11, 156(a0)

        mv a0, a1
        bnez a1, 1f
        li a0, 1
1:      jr ra
