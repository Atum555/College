# int conta_intervalo(float *V, int n, float a, float b)
.text
conta_intervalo:
    # a0  = float *V
    # a1  = int n
    # fa0 = float a
    # fa1 = float b
    mv t0, zero              # count = zero

conta_intervalo_loop:
    beqz a1 conta_intervalo_end  # n == 0 ? stop
    addi a1, a1, -1         # --n

    flw ft1, 0(a0)          # ft1 = V[i]
    fle.s t1, fa0, ft1      # a <= V[i] ? t0
    fle.s t2, ft1, fa1      # V[i] <= b ? t1
    and t1, t1, t2
    add t0, t0, t1

    addi a0, a0, 4          # *V += 4
    j conta_intervalo_loop
conta_intervalo_end:
    mv a0, t0
    ret