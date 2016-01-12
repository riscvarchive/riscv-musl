.section .init
        ld ra, 8(sp)
        ld gp, 0(sp)
        addi sp, sp, 16
        jr ra

.section .fini
        ld ra, 8(sp)
        ld gp, 0(sp)
        addi sp, sp, 16
        jr ra
