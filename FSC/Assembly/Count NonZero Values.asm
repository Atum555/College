.data
D1:
87
12
32
43
65
87

.text
la x29, D1      # Load adress to x29
li x28, 0       # Contador 0

L1:
lw x30,(x29)        # Load next to x30
beqz x30, L2        # Zero found, jump end
addi x28, x28, 1    # Add one to conter
addi x29, x29, 4    # Add 4 to adrress
b L1

L2:
add x5,x28,x0       # Load result to x5