#	
#
#	CODE BY: CLAUDIO MEIRELES
#
#	CODE ON GITHUB: https://github.com/Atum555/College/blob/main/FSC/Mini%20Projeto%202/projeto.asm
#
#	


.data
inStr: .space 4
questionStr: .asciz "Input number: "
nlStr: .asciz "\n"
qnum1: .word 0x00000000, 0x00000000, 0x00000000, 0x00000000
qnum2: .word 0x00000000, 0x00000000, 0x00000000, 0x00000000
qres: .space 80

.text
main:
	li a7, 4
	la a0, questionStr
	ecall			# Print Question

	li a7, 8		# System Call Input String
	la a0, inStr	# String Buffer
	li a1, 4		# Max Length
	ecall			# Get Input
	li a7, 4
	la a0, nlStr
	ecall			# Print New Line

	la a0, inStr
	la a1, qnum1
	call stoq		# Convert Str to Q-int

	la a0, qnum1
	la a1, qnum2
	call factorial	# Calculate Factorial

	la a0, qnum2
	la a1, qres
	call qtos		# Convert to String

	li a7, 4
	la a0, qres
	ecall			# Print Result
	
	j end


qadd:
	# Prologue
	addi sp, sp, -12 # Adjust Stack Pointer
	sw ra, 0(sp)	# Store Return Adrress
	sw s0, 4(sp)	# Store Safe Values
	sw s1, 8(sp)	# Store Safe Values
	
	# Code
	li s0, 0		# Init Counter i
	li t0, 0		# Init CarryIn
qaddLoop:	
	li t5, 4
	mul t6, s0, t5	# Offset (4*i)
	add t1, t6, a0	# Address of A[i]
	lw t1, (t1)		# Value of A[i]
	add t2, t6, a1	# Address of B[i]
	lw t2, (t2)		# Value of B[i]
	
	add s1, t1, t2	# s1 = A[i] + B[i]
	sltu t6, s1, t1 # t6 = CarryOut 1
	add s1, s1, t0 	# s1 = A[i] + B[i] + carryIn
	sltu t5, s1, t0 # t5 = CarryOut 2
	or t0, t5, t6 	# Set Carry-In/Out
	
	li t5, 4
	mul t6, s0, t5	# Offset (4*i)
	add t6, t6, a2	# Address of R[i]
	sw s1, (t6)		# Store Sum into R[i]
	

	addi s0, s0, 1	# Increment Counter
	li t6, 4		
	bne s0, t6, qaddLoop	# i != 4 Loop again
	
	mv a0, t0		# Return Value - Carry
	
	# Epilogue
	lw s1, 8(sp)	# Restore Safe Values
	lw s0, 4(sp)	# Restore Safe Values
	lw ra, 0(sp)	# Restore Return Address
	addi sp, sp, 12 	# Restore Stack Pointer
	ret


qmult:
	# Prologue
	addi sp, sp, -72 # Adjust Stack Pointer -16*4
	sw s0, 68(sp)	# 17*4 Store Safe Values
	sw s1, 64(sp)	# 16*4 Store Safe Values
	sw a0, 60(sp) 	# 15*4 Store Arg 0 - Value A
	sw a1, 56(sp) 	# 14*4 Store Arg 1 - Value B
	sw a2, 52(sp) 	# 13*4 Store Arg 2 - Result Address
	sw ra, 48(sp) 	# 12*4 Store Return Adrress
					# [8*4 - 11*4] -> X
					# [4*4 - 7*4]  -> Y
					# [0   - 3*4]  -> R
		
	# Code
	li t0, 0		# Set Values to 0
	sw t0, (sp)		# R0
	sw t0, 4(sp)	# R1
	sw t0, 8(sp)	# R2
	sw t0, 12(sp)	# R3
	sw t0, 16(sp)	# Y0
	sw t0, 20(sp)	# Y1
	sw t0, 24(sp)	# Y2
	sw t0, 28(sp)	# Y3
	sw t0, 32(sp)	# X0
	sw t0, 36(sp)	# X1
	sw t0, 40(sp)	# X2
	sw t0, 44(sp)	# X3

	li s0, -1		# Init Counter i - a
qmultOuterLoop:
	addi s0, s0, 1			# Increment Counter
	li t6, 4		
	beq s0, t6, qmultFinal 	# i == 4 Stop Outer Loop
	li s1, -1 				# Init Counter j - b
qmultInnerLoop:
	addi a0, sp, 32			# a0 = address(X)
	addi a1, sp, 16			# a1 = address(Y)
	addi a2, sp, 0			# a2 = address(R)
	call qadd				# R = X + Y
	
	lw a0, 60(sp)	# Restore Argument Values
	lw a1, 56(sp)
	lw a2, 52(sp)

	lw t6, (sp)		# R0  Move R to X
	sw t6, 32(sp)	# X0
	lw t6, 4(sp)	# R1
	sw t6, 36(sp)	# X1
	lw t6, 8(sp)	# R2
	sw t6, 40(sp)	# X2
	lw t6, 12(sp)	# R3
	sw t6, 44(sp)	# X3

	li t6, 0 		# Y = 0
	sw t6, 16(sp)	# Y0
	sw t6, 20(sp)	# Y1
	sw t6, 24(sp)	# Y2
	sw t6, 28(sp)	# Y3

	addi s1, s1, 1	# Increment Counter
	add t6, s0, s1	# t6 = i+j
	li t5, 4
	beq t6, t5, qmultOuterLoop	# i+j == 4 Stop Inner Loop

	li t0, 4		# t0 = 4
	mul t0, t0, s0	# t0 = i*4
	add t0, t0, a0	# t0 = i*4 + arg0   Address of A[i]
	lw t0, (t0)		# Value of A[i]
	li t1, 4		# t1 = 4
	mul t1, t1, s1	# t1 = j*4
	add t1, t1, a1	# t1 = j*4 + arg1   Address of B[I]
	lw t1, (t1)		# Value of B[i]
	mul t2, t0, t1		# Product [31-0]
	mulhu t3, t0, t1	# Product [63-32]
	
	li t6, 4			# t6 = 4
	add t5, s0, s1		# t5 = i+j
	mul t5, t5, t6		# t5 = (i+j)*4   Offset
	addi t6, sp, 16  	# t6 = Address of Y
	add t6, t6, t5		# t6 = Address of Y[i+j]
	sw t2, (t6)			# Store Result Lower into temp Y
	
	add t6, s0, s1		# t6 = i+j 
	addi t6, t6, 1		# t6 = i+j+1
	li t5, 4
	bge t6, t5, qmultInnerLoop	# i+j+1 == 4 Continue Next Iter
	mul t6, t6, t5		# t6 = (i+j+1)*4   Offset
	addi t5, sp, 16  	# t5 = Address of Y
	add t5, t5, t6		# t5 = Address of Y[i+j+1]
	sw t3, (t5)			# Store Result Upper into temp Y
	j qmultInnerLoop
	
qmultFinal:		
	lw t6, (sp)		# R0  Store Result into arg2 address (Result Address)
	sw t6, (a2)		# A2/0
	lw t6, 4(sp)	# R1
	sw t6, 4(a2)	# A2/1
	lw t6, 8(sp)	# R2
	sw t6, 8(a2)	# A2/2
	lw t6, 12(sp)	# R3
	sw t6, 12(a2)	# A2/3
	
	li a0, 0	# a0 = 0   OverFlow

	# Epilogue
	lw ra, 48(sp)	# Restore Return Address
	lw s0, 68(sp)
	lw s1, 64(sp)
	addi sp, sp, 72 	# Restore Stack Pointer
	ret


qtos:
	# Prologue
	addi sp, sp, -52 # Adjust Stack Pointer
	sw ra, 0(sp)	# Store Return Adrress
	sw s0, 4(sp)	# Store Safe Values
	sw s1, 8(sp)	# Store Safe Values
	lw t6, (a0)
	sw t6, 12(sp)	# Store A[0]
	lw t6, 4(a0)
	sw t6, 16(sp)	# Store A[1]
	lw t6, 8(a0)
	sw t6, 20(sp)	# Store A[2]
	lw t6, 12(a0)
	sw t6, 24(sp)	# Store A[3]
					# [28-62] Characteres

	# Code
	li s0, -1		# Init String Offset
qtosLoop1:
	addi s0, s0, 1	# Increment String Offset
	
						# Algorithm based on a 
						# 16bit division and remainder
	li t6, 10
	lhu t0, 26(sp)		# t0 = A[3][1]
	divu t1, t0, t6		# t1 = A[3][1] // 10
	sh t1, 26(sp)		# Store A[3][1]

	remu t1, t0, t6 	# t1 = A[3][1] % 10
	slli t1, t1, 16		# t1 = t1 << 8
	lhu t0, 24(sp)		# t0 = A[3][0]
	add t0, t0, t1 		# t0 = A[3][0] + t1(remainder)
	divu t1, t0, t6 	# t1 = (A[3][0] + remainder) // 10
	sh t1, 24(sp)		# Store A[3][0]

	remu t1, t0, t6 	# t1 = A[3][0] % 10
	slli t1, t1, 16		# t1 = t1 << 8
	lhu t0, 22(sp)		# t0 = A[2][1]
	add t0, t0, t1 		# t0 = A[2][1] + t1(remainder)
	divu t1, t0, t6 	# t1 = (A[2][1] + remainder) // 10
	sh t1, 22(sp)		# Store A[2][1]

	remu t1, t0, t6 	# t1 = A[2][1] % 10
	slli t1, t1, 16		# t1 = t1 << 8
	lhu t0, 20(sp)		# t0 = A[2][0]
	add t0, t0, t1 		# t0 = A[2][0] + t1(remainder)
	divu t1, t0, t6 	# t1 = (A[2][0] + remainder) // 10
	sh t1, 20(sp)		# Store A[2][0]

	remu t1, t0, t6 	# t1 = A[2][0] % 10
	slli t1, t1, 16		# t1 = t1 << 8
	lhu t0, 18(sp)		# t0 = A[1][1]
	add t0, t0, t1 		# t0 = A[1][1] + t1(remainder)
	divu t1, t0, t6 	# t1 = (A[1][1] + remainder) // 10
	sh t1, 18(sp)		# Store A[1][1]

	remu t1, t0, t6 	# t1 = A[1][1] % 10
	slli t1, t1, 16		# t1 = t1 << 8
	lhu t0, 16(sp)		# t0 = A[1][0]
	add t0, t0, t1 		# t0 = A[1][0] + t1(remainder)
	divu t1, t0, t6 	# t1 = (A[1][0] + remainder) // 10
	sh t1, 16(sp)		# Store A[1][0]

	remu t1, t0, t6 	# t1 = A[1][0] % 10
	slli t1, t1, 16		# t1 = t1 << 8
	lhu t0, 14(sp)		# t0 = A[0][1]
	add t0, t0, t1 		# t0 = A[0][1] + t1(remainder)
	divu t1, t0, t6 	# t1 = (A[0][1] + remainder) // 10
	sh t1, 14(sp)		# Store A[0][1]

	remu t1, t0, t6 	# t1 = A[0][1] % 10
	slli t1, t1, 16		# t1 = t1 << 8
	lhu t0, 12(sp)		# t0 = A[0][0]
	add t0, t0, t1 		# t0 = A[0][0] + t1(remainder)
	divu t1, t0, t6 	# t1 = (A[0][0] + remainder) // 10
	sh t1, 12(sp)		# Store A[0][0]

	remu t1, t0, t6 	# t1 = A[0][0] % 10
	addi t1, t1, 48		# t1 = remainder + 0(ascii)

	add t6, sp, s0		# t6 = sp + i
	sb t1, 28(t6)		# Store Remainder(ascii) into sp +28 +i

	li t6, 38
	bne s0, t6, qtosLoop1	# i != 38 Repeat Loop

	li s0, 39		# Init Stack Offset
	li s1, -1		# Init String Offset
	li t0, 0		# Init Write
qtosLoop2:
	addi s0, s0, -1 	# Decrement Stack Offset
	add t6, sp, s0		# t6 = sp + i
	lb t6, 28(t6) 		# t6 = [sp + 28 + i]
	bnez t0, qtosCheckPoint1 	# If numbers found previously, ignore check
	li t5, 48				# t5 = 0(ascii)
	beq t6, t5, qtosLoop2	# t6 == 0(ascii) Repeat Loop
qtosCheckPoint1:
	li t0, 1			# Set as number found
	addi s1, s1, 1		# Increment String Offset
	add t5, a1, s1		# t5 = Str[j]
	sb t6, (t5)

	bnez s0, qtosLoop2	# i != 0 Repeat Loop

	li t6, 10
	sb t6, 1(t5)		# Store \n at the end of the string
	li t6, 0
	sb t6, 2(t5)		# Store \0 at the end of the string

	# Epilogue
	lw s1, 8(sp)	# Restore Safe Values
	lw s0, 4(sp)	# Restore Safe Values
	lw ra, 0(sp)	# Restore Return Address
	addi sp, sp, 52 	# Restore Stack Pointer
	ret


stoq:
	# Prologue
	addi sp, sp, -16 # Adjust Stack Pointer
	sw ra, 0(sp)	# Store Return Adrress
	sw s0, 4(sp)	# Store Safe Values
	sw s1, 8(sp)	# Store Safe Values
	sw a0, 12(sp)	# Store arg0

	# Code
	li a0, 0		# Set no Error
	li s0, -1		# Init Offset
	li s1, 0		# Init Result
stoqLoop:
	addi s0, s0, 1	# Increment Offset
	lw t6, 12(sp)
	add t6, t6, s0
	lb t0, (t6)		# t0 = char[i]
	beqz t0, stoqEPI	# char[i] == "\0" Stop
	li t6, 10
	beq t0, t6, stoqEPI	# char[i] == "\n" Stop
	sltiu t3, t0, 48	# Set Error <"0"
	li t6, 57
	sgtu t4, t0, t6		# Set Error >"9"
	or a0, t4, t3		
	bnez a0, errorEPI	# Stop if Error
	li t6, 10
	mul s1, s1, t6		# s1 = s1 * 10
	li t6, 48
	sub t0, t0, t6		# t0 = int(char[i])
	add s1, s1, t0		# s1 += t0
	j stoqLoop

stoqEPI:
	sw s1, (a1)		# A = result
	li t6, 0
	sw t6, 4(a1)
	sw t6, 8(a1)
	sw t6, 12(a1)

errorEPI:
	# Epilogue
	lw s1, 8(sp)	# Restore Safe Values
	lw s0, 4(sp)	# Restore Safe Values
	lw ra, 0(sp)	# Restore Return Address
	addi sp, sp, 16 	# Restore Stack Pointer
	ret

factorial:
	# Prologue
	addi sp, sp, -64 # Adjust Stack Pointer
	sw ra, 0(sp)	# Store Return Adrress
	sw s0, 4(sp)	# Store Safe Values
	sw s1, 8(sp)	# Store Safe Values
	lw t6, (a0)		
	sw t6, 12(sp)	# Store N[0]
	lw t6, 4(a0)		
	sw t6, 16(sp)	# Store N[1]
	lw t6, 8(a0)		
	sw t6, 20(sp)	# Store N[2]
	lw t6, 12(a0)		
	sw t6, 24(sp)	# Store N[3]
	sw a1, 28(sp)	# Store qres
	sw zero, 32(sp)	# Zero-out Temporary
	sw zero, 36(sp)
	sw zero, 40(sp)
	sw zero, 44(sp)
	sw zero, 48(sp)	# Zero-out Result
	sw zero, 52(sp)
	sw zero, 56(sp)
	sw zero, 60(sp)

	# Code
	lw t6, 12(sp)	# Temp = N
	sw t6, 32(sp)
	lw t6, 16(sp)
	sw t6, 36(sp)
	lw t6, 20(sp)
	sw t6, 40(sp)
	lw t6, 24(sp)
	sw t6, 44(sp)
factorialLoop:
	lw t6, 12(sp)	
	addi t6, t6, -1
	sw t6, 12(sp) 	# N[0] = N[0] - 1
	li t5, 1
	beq t6, t5, factorialEnd	#  * 1 -> End

	addi a0, sp, 12	# a0 = address of N
	addi a1, sp, 32 # a1 = address of T
	addi a2, sp, 48	# a2 = address of R
	call qmult

	lw t6, 48(sp)	# T = R
	sw t6, 32(sp)
	lw t6, 52(sp)
	sw t6, 36(sp)
	lw t6, 56(sp)
	sw t6, 40(sp)
	lw t6, 60(sp)
	sw t6, 44(sp)

	j factorialLoop

factorialEnd:
	lw t5, 28(sp)	# t5 = address of res
	lw t6, 48(sp)	# T = R
	sw t6, (t5)
	lw t6, 52(sp)
	sw t6, 4(t5)
	lw t6, 56(sp)
	sw t6, 8(t5)
	lw t6, 60(sp)
	sw t6, 12(t5)

	# Epilogue
	lw s1, 8(sp)	# Restore Safe Values
	lw s0, 4(sp)	# Restore Safe Values
	lw ra, 0(sp)	# Restore Return Address
	addi sp, sp, 64 	# Restore Stack Pointer
	ret


end:
	nop
