.text
.global sumSquare
sumSquare:
    ble a0, zero, skip  # if input <= zero then skip
    mv t0, zero         # t0 = zero
loop:
    mul t1, a0, a0      # t1 = n**2
    add t0, t0, t1      # t0 += t1
    addi a0, a0, -1     # a0 -= 1
    bne a0, zero, loop  # if a0 != zero then loop
    mv  a0, t0          # a0 = t0
    ret
skip:
    mv a0, zero         # a0 = zero
    ret