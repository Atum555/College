# void SUM(int *a, int *b, int r, int *r);
# Alínea a
SUM:
    beqz a2, SUM_END
    lw t0, 0(a0)
    lw t1, 0(a1)
    add t2, t0, t1
    sw t2, 0(a3)

    addi a2, a2, -1
    addi a0, a0, 4
    addi a1, a1, 4
    addi a3, a3, 4
    j SUM
SUM_END:
    ret


# void SUM_OVER(int *a, int *b, int n, int *r);
# Alínea b
SUM_OVER:
    addi sp, sp, -32
    sw ra, 0(sp)

SUM_OVER_LOOP:
    beqz a2, SUM_OVER_END
    sw a0, 4(sp)        # a
    sw a1, 8(sp)        # b
    sw a2, 12(sp)       # n
    sw a3, 16(sp)       # r

    lw a0, 0(a0)
    lw a1, 0(a1)
    call SUM_D_OVER

    lw a3, 16(sp)       # r
    sw a0, 0(a3)        # Store Result

    lw a0, 4(sp)        # a
    lw a1, 8(sp)        # b
    lw a2, 12(sp)       # n

    addi a0, a0, 4
    addi a1, a1, 4
    addi a2, a2, -1
    addi a3, a3, 4
    j SUM_OVER_LOOP
SUM_OVER_END:
    lw ra, 0(sp)
    ret



# int SUM_D_OVER(int a, int b)
SUM_D_OVER:
    add t0, a0, a1              # t0 = a + b

    xor t1, a0, a1              # Check Diferent Bits
    li t2, 0x80000000           # t4 = 0b1000...
    and t1, t1, t2              # Select first bit
    beqz t1, SUM_D_OVER_END  # Skip overflow check if operands have diferent signs

    slt t1, a0, zero            # a < zero ? t1
    beqz t1, SUM_D_OVER_NEGATIVE  # If operands are negative

SUM_D_OVER_POSITIVE:
    bge t0, zero, SUM_D_OVER_END    # t0 >= zero ? Return
    li a0, 0x7FFFFFFF               # Overflow
    ret 

SUM_D_OVER_NEGATIVE:
    blt t0, zero, SUM_D_OVER_END    # t0 < zero ? Return
    li a0, 0x80000000               # Overflow
    ret 

SUM_D_OVER_END:
    mv a0, t0
    ret