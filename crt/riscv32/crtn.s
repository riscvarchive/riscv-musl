.section .init
        lw ra, 12(sp)
        lw gp, 8(sp)
        addi sp, sp, 16
        jr ra

.section .fini
        lw ra, 12(sp)
        lw gp, 8(sp)
        addi sp, sp, 16
        jr ra
