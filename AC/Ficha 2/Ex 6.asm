# int conta_intervalo(float *V, int n, float a, float b)
.text
conta_intervalo:
    # a0  = float *V
    # a1  = int n
    # fa0 = float a
    # fa1 = float b
    fcvt.s.wu ft0, zero     # count = zero

conta_intervalo_loop:
    beqz a1 conta_intervalo_end  # n == 0 ? stop
    addi a1, a1, -1         # --n

    flw ft1, 0(a0)
    fle.s t0, 
    fadd.s ft0, fa0, ft1    # Total += temp

    addi a0, a0, 4          # *V += 4
    j conta_intervalo_loop
conta_intervalo_end:
    ret