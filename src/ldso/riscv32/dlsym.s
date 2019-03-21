.global dlsym
.hidden __dlsym
.type dlsym, %function
dlsym:
        mv a2, ra
        j __dlsym
