;Lab 4 Subroutines
.ORIG	x3000
	LDI R1, X ; Load value of X into R1
	LDI R2, Y ; Load value of Y into R2
	
	JSR DVSN ; Jump to subroutine DVSN
	STI R5, QTNT ; Store indirect quotient into QTNT
	STI R3, MDL ; Store indirect modulo into MDL
	HALT 

LOOP2 	ADD R6, R5, R4 ; Add and store result in R6
	BRz QT2 ; If zero, branch to QT2
	ADD R5, R5, #1 ; Increment R5 by 1
	ADD R3, R3, R1 ; Add and store result in R3
	BR LOOP2 ; Branch to LOOP2
QT2 	NOT R3, R3 ; 
	ADD R3, R3 #1 ; Increment R3 by 1

	LD R5, Rgstr5 ; 
	LD R6, Rgstr6 ; 
	RET ; Return from subroutine
Rgstr5 .FILL X0 ; Fill Rgstr5 with X0
Rgstr6 .FILL X0 ; Fill Rgstr6 with X0

DVSN ; Subroutine for division
	ADD R2, R2, #0 ; Copy R2 into itself
	BRz QT3 ; If zero, branch to QT3
	ADD R6, R2, #0 ; Copy R2 into R6
	AND R5, R5, #0 ; Clear R5
	ADD R3, R1, #0 ; Copy R1 into R3
	ADD R4, R2, #0 ; Copy R2 into R4
	NOT R4, R4 ; Negate R4
	ADD R4, R4, #1 ; Increment R4 by 1
	ADD R0, R3, R4 ; Add and store result in R0
	BRn QT2 ; If negative, branch to QT2
LOOP3	ADD R5, R5, #1 ; Increment R5 by 1
	ADD R3, R3, R4 ; Add R3 and R4, store result in R3
	BRp LOOP3 ; If positive, branch to LOOP3
	BRz QT3 ; If zero, branch to QT3
	ADD R3, R3, R6 ; Add and store result in R3
	ADD R5, R5, #-1 ; Decrement R5 by 1
	BR QT3 ; Branch to QT3
QT3	RET ; Return from subroutine

X	.FILL X3100 ; Fill X with X3100
Y	.FILL X3101 ; Fill Y with X3101
QTNT	.FILL X3103 ; Fill QTNT with X3103
MDL	.FILL X3104 ; Fill MDL with X3104
.END ; End of program