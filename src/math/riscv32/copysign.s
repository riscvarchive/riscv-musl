.global copysign
.type   copysign, %function
copysign:
        fsgnj.d fa0, fa0, fa1
        ret
