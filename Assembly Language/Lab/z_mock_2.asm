.ORIG x3000

	LEA R0, OUTPUT
	PUTS

	AND R1, R1, #0
	ADD R1, R1, #10

	LD R2, INPUTS

LOOP1	IN
	STR R0, R2, #0
	ADD R2, R2, #1
	ADD R1, R1, #-1
	BRp LOOP1

	LD R3, COUNTER
	LD R4, DUPE
	LD R5, START

LOOP2	LDR R6, R5, #0
	STR R6, R4, #0
	ADD R4, R4, #1
	ADD R5, R5, #1
	ADD R3, R3, #-1
	BRp LOOP2

HALT

OUTPUT 	.STRINGZ "Enter 10 characters: "
INPUTS	.FILL x3500
START	.FILL x3000
DUPE	.FILL x4000
COUNTER	.FILL x1000

.END