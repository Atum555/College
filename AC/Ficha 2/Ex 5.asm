# double prodint_VF(float *X, float *Y, int n)
.text
prodint_VF:
    fcvt.s.wu fa0, zero     # Total = zero

prodint_VF_loop:
    beqz a2 prodint_VF_end  # n == 0 ? stop
    addi a2, a2, -1         # --n

    flw ft1, 0(a0)
    flw ft2, 0(a1)
    fmul.s ft1, ft1, ft2    # temp = X[i] * Y[i]
    fadd.s fa0, fa0, ft1    # Total += temp

    addi a0, a0, 4          # *X += 4
    addi a1, a1, 4          # *Y += 4
    j prodint_VF_loop
prodint_VF_end:
    ret