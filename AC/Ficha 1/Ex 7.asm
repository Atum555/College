# Alínea a
.text
stringLength:
    # a0 -> String Base Address
    mv  t0, zero    # t0 = zero
stringLengthLoop:
    lb t1, 0(a0)
    beqz t1, stringLengthEnd
    addi t0, t0, 1
    addi a0, a0, 1
    j stringLengthLoop
stringLengthEnd:
    mv a0, t0
    ret


# Alínea b
.text
cChar:
    # a0 -> String Base Address
    # a1 -> Char
    mv  t0, zero    # t0 = zero
cCharLoop:
    lb t2, 0(a0)
    mv t1, t2
    sub t1, t1, a1  # t1 -= a1
    seqz t1, t1     # t1 == 0 ? 1 : 0
    add t0, t0, t1  # t0 += t1
    beqz t2, cCharEnd
    addi a0, a0, 1  # a0 += 1
    j cCharLoop
cCharEnd:
    mv a0, t0
    ret


# Alínea c
.text
cWords:
    # a0 -> String Base Address
    addi sp, sp, -16
    sw ra, 0(sp)
    li a1, 32       # a1 = " "
    call cChar
    addi a0, a0, 1
    lw ra, 0(sp)
    addi sp, sp, 16
    ret


# Alínea d
.data
vowels: .asciz "aeiouAEIOU"

.text
cVowels:
    # a0 -> String Base Address
    addi sp, sp, -16
    sw ra, 0(sp)
    sw s0, 4(sp)
    sw s1, 8(sp)
    sw s2, 12(sp)
    la s0, vowels
    mv s1, a0
    mv s2, zero
cVowelsLoop:
    mv a0, s1
    lb a1, (s0)
    beqz a1, cVowelsEnd
    call cChar
    add s2, s2, a0
    addi s0, s0, 1
    j cVowelsLoop
cVowelsEnd:
    mv a0, s2
    lw s2, 12(sp)
    lw s1, 8(sp)
    lw s0, 4(sp)
    lw ra, 0(sp)
    addi sp, sp, 16
    ret


# Alínea e
.text
cUpper:
    # a0 -> String Base Address
    mv t0, zero
cUpperLoop:
    lb t1, (a0)
    beqz t1, cUpperEnd
    addi t1, t1, -65
    li t2, 26
    sltu t1, t1, t2 # t1 < 26 ? 1 : 0
    add t0, t0, t1
    addi a0, a0, 1
    j cUpperLoop
cUpperEnd:
    mv a0, t0
    ret