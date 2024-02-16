.data
array: .word 7, -8, -23, 56, 20, -10, 0, 40 

.text
li a0, 20
li a1, 8
la a2, array
call CheckABS
ebreak


.global CheckABS
CheckABS:
	mv t0, zero
	mv t6, zero
loop1:
	beq t0, a1, end
	li t4, 4
	mul t5, t0, t4
	add t1, a2, t5
	lw t2, (t1)
	bleu t2, a0, skip
	neg t2, t2
	bleu t2, a0, skip
	sw zero, (t1)
	addi t6, t6, 1
skip:
	addi t0, t0, 1
	j loop1
end:
	mv a0, t6
	ret