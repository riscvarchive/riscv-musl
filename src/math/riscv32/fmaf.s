.global fmaf
.type   fmaf, %function
fmaf:
        fmadd.s fa0, fa0, fa1, fa2
        ret
