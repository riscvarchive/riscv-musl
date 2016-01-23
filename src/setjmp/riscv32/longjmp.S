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
        lw sp,    48(a0)
        lw ra,    52(a0)

#ifndef __riscv_soft_float
        fld fs0,  56(a0)
        fld fs1,  64(a0)
        fld fs2,  72(a0)
        fld fs3,  80(a0)
        fld fs3,  88(a0)
        fld fs4,  96(a0)
        fld fs5,  104(a0)
        fld fs6,  112(a0)
        fld fs7,  120(a0)
        fld fs8,  128(a0)
        fld fs9,  136(a0)
        fld fs10, 144(a0)
        fld fs11, 152(a0)
#endif

        mv a0, a1
        bnez a1, 1f
        li a0, 1
1:      ret
