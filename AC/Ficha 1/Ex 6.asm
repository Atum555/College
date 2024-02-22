cBits:
    mv  t0, zero            # t0 = zero
cBitsLoop:
    beq a0, zero, cBitsEnd  # if a0 == zero then cBitsEnd
    andi t1, a0, 1
    add t0, t0, t1          # t0 = t0 + t1
    srli a0, a0, 1
    j cBitsLoop             # jump to cBitsLoop    
cBitsEnd:
    mv  a0, t0 # a0 = t0
    ret


cEqualBits:
    addi sp, sp, -16
    sw ra, 0(sp)
    xor a0, a0, a1
    not a0, a0
    call cBits
    lw ra, 0(sp)
    addi sp, sp, 16
    ret