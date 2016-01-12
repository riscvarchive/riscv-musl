.section .init
.global _init
.type _init,%function
_init:
        addi sp, sp, -16
        sw   ra, 12(sp)
        sw   gp, 8(sp)

.section .fini
.global _fini
.type _fini,%function
_fini:
        addi sp, sp, -16
        sw   ra, 12(sp)
        sw   gp, 8(sp)
