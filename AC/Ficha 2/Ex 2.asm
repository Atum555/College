# Alínea A
# void calcExpress(float *A, float *B, float *C, float *D, float *r)
.text
calcExpress:
    flw ft0, 0(a0)          # A
    flw ft1, 0(a1)          # B
    flw ft2, 0(a2)          # C
    flw ft3, 0(a3)          # D

    fsub.s ft4, ft0, ft1    # temp0 = A - B
    fmul.s ft4, ft4, ft2    # temp0 *= C

    fadd.s ft3, ft3, ft0    # D += A
    li t0, -3
    fcvt.s.w ft0, t0        # temp1 = (float) -3
    fadd.s ft0, ft0, ft3    # temp1 += D
    fdiv.s ft0, ft4, ft0    # temp1 = temp0 / temp1

    fsw ft0, 0(a4)          # Store Result
    ret