# int SOMA(int *v, int n)
.text
SOMA:
    mv t0, zero     # Sum
SOMA_loop:
    beqz a1, SOMA_end   # counter == 0 ? stop
    addi a1, a1, -1     # --n
    lw t1, 0(a0)
    add t0, t0, t1
    addi a0, a0, 4  # V[++]
    j SOMA_loop
SOMA_end:
    mv a0, t0
    ret


# Alínea a
# int MEDIA(int *v, int n)
.text
MEDIA:
    addi sp, sp, -16
    sw ra, 0(sp)
    sw a1, 4(sp)
    call SOMA
    lw t0, 4(sp)
    div a0, a0, t0
    lw ra, 0(sp)
    addi sp, sp, 16
    ret

# Alínea b
# int MAXMED(int *v1, int *v2, int n);
.text
MAXMED:
    addi sp, sp, -16
    sw ra, 0(sp)
    sw a1, 4(sp)
    sw a2, 8(sp)
    mv a1, a2
    call MEDIA
    sw a0, 12(sp)
    lw a0, 4(sp)
    lw a1, 8(sp)
    call MEDIA
    lw a1, 12(sp)
    blt a1, a0, MAXMED_END
    mv a0, a1
MAXMED_END:
    lw ra, 0(sp)
    addi sp, sp, 16
    ret
