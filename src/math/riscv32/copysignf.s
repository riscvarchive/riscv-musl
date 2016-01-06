.global copysignf
.type   copysignf, %function
copysignf:
        fsgnj.s fa0, fa0, fa1
        ret
