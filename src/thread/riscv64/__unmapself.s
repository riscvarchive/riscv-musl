.global __unmapself
.type __unmapself, %function
__unmapself:
       li a7, 215 # SYS_munmap
       scall
       li a7, 93  # SYS_exit
       scall
