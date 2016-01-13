.global __fpclassify
.type   __fpclassify, %function
__fpclassify:
        fclass.d t0, fa0
        andi t1, t0, 0x24  # negative or positive subnormal
        bnez t1, 1f
        andi t1, t0, 0x18  # negative or positive zero
        bnez t1, 2f
        andi t1, t0, 0x81  # negative or positive infinity
        bnez t1, 3f
        andi t1, t0, 0x300 # signaling or quiet NaN
        bnez t1, 4f
        li a0, 4           # FP_NORMAL
        ret

1:      li a0, 3           # FP_SUBNORMAL
        ret

2:      li a0, 2           # FP_ZERO
        ret

3:      li a0, 1           # FP_INFINITE
        ret

4:      li a0, 0           # FP_NAN
        ret

