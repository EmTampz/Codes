.ORIG x3000
LDI R0, X ; load X into R0 
LDI R1, Y ; load Y into R1 
JSR MUL ; call multiplication subroutine 
STI R2, XY ; store product in XY 
JSR DIVMOD ; call division and modulus subroutine 
STI R4, QUOT ; store quotient in QUOT 
STI R2, R ; store remainder in R 
HALT ; end program

MUL 	ST R3, SaveR3 ; save R3 ST R4, 
	SaveR4 ; save R4 
	ADD R2, R0, #0 ; set R2 to X 
	ADD R3, R1, #0 ; set R3 to Y 
	AND R4, R4, #0 ; clear R4 
	BRz DONE ; if Y is zero, skip loop 
	MLOOP ADD R4, R4, R2 ; add X to R4 
	ADD R3, R3, #-1 ; decrement Y by 1 
	BRp MLOOP ; repeat until Y is zero or negative 
	DONE LD R3, SaveR3 ; restore 
	R3 LD R4, SaveR4 ; restore R4 
	RET ; return from subroutine2 
	SaveR3 
	.FILL X0 SaveR4 .FILL X0
	DIVMOD ADD R1, R1, #0 ; check if Y is zero 
	BRz EXIT ; if so, exit subroutine 
	ADD R4, R0, #0 ; set R4 to X 
	ADD R5, R1, #0 ; set R5 to Y3 
	AND R2, R2, #0 ; clear R24 
	AND R3, R3, #0 ; clear R3 
	BRz DLOOP ; if X is zero, skip loop 
DLOOP 	ADD R4, R4, R5 ; subtract Y from X 
	BRn DEND ; if result is negative, end loop 
	ADD R2, R2, #1 ; increment quotient by 13 
	BRnzp DLOOP ; repeat until X is zero or negative DEND 
	ADD R4, R4, R1 ; add Y back to X to get remainder 
	ADD R3, R4, #0 ; set R3 to remainder 
	EXIT RET ; return from subroutine2

X .FILL X3100 
Y .FILL X3101 
XY.FILL X3102 
QUOT .FILL X3103 
R .FILL X3104 
.END