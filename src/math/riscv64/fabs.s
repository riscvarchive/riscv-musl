.global fabs
.type   fabs, %function
fabs:
        fsgnjx.d fa0, fa0, fa0
        ret
