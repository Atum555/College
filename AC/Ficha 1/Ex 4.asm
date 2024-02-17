.data
    num : .word 7
.text
    la t0, num
    lw a0, 0( t0)
    jal ra, POLI
    li a7, 10
    ecall # termina


POLI :
    addi sp, sp, -16
    sw ra, 0(sp)
    sw s0, 4(sp)
    mv s0, a0       # s0 = a0
    jal ra, QUAD    # a0 = n**2 
    mv t0, a0       # t0 = n**2
    li a0, 3
    mul s0, s0, a0  # s0 = 3n
    add a0, t0, s0  # a0 = n**2 + 3n
    addi a0, a0, 1  # a0 = n**2 + 3n + 1
    lw ra, 0(sp)
    lw s0, 4(sp)
    addi sp, sp, 16
    ret 

QUAD : 
    mul a0 , a0 , a0
    ret