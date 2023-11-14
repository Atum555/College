.data

D1:
87
12
32
43
65
87
18
34
87
93
0
0
0
0

D2:
87
12
32
43
65
87
18
34
87
93

.text
la x28, D1 	        # Load adress of list 1 to x28
la x29, D2      	# Load adress of list 2 to x29
li x10, 1	        # Init result to 1
li x5, 10	        # Init counter to 1

L1:
lw x30, (x28)       # Load values from list 1
lw x31, (x29)       # Load values from list 2
bne x30,x31,L2      # Branch to L2 if not equal
addi x28, x28, 4    # Add 4 to adsress of list 1
addi x29, x29, 4    # Add 4 to address of list 2
addi x5, x5, -1	    # Incress counter
beqz x5, L3	        # Jump to end if counter is done
b L1

L2:
li x10, 0           # Load result if not Equal

L3: