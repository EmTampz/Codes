.ORIG x3000
	LDI R1, X
	ADD R1, R1, #-2
	BRp XJANXFEB
	ADD R1, R1, #12
	LDI R0, C
	ADD R0, R0, #-1
	STI R0, C

;Zeller's EQUATION: f=k+(13m-1)/5 +d+d/4 + c/4-2c
XJANXFEB
	STI R1, M
	AND R0, R0, x0
	ADD R0, R0, #13; multiply by 13

	JSR MULTIPLY
	ADD R2, R2, #-1
	STI R2, REVISEDMONTH; REVISEDMONTH=(13m-1)
	ADD R0, R2, x0
	AND R1, R1, x0
	ADD R1, R1, x5

	JSR DIVIDE
	STI R2, MONQUOTIENT; MONQUOTIENT(13m-1)/5
	LDI R0, C
	AND R1, R1, x0
	ADD R1, R1, xF
	ADD R1, R1, xF
	ADD R1, R1, xF
	ADD R1, R1, xF
	ADD R1, R1, xF
	ADD R1, R1, xF
	ADD R1, R1, xA; R1=100

	JSR DIVIDE; DIVIDE R0 BY 100 TO GET THE YEAR 
	STI R0, D; r0 as remainder, the last 2 digit of year
	STI R2, REVISEDCENT; r0 as remainder, the last 2 digit of year
	LDI R0, D
	AND R1, R1, x0
	ADD R1, R1, x4

	JSR DIVIDE; 
	STI R2, LASTNUMQUOTIENT; LASTNUMQUOTIENT=D/4
	AND R1, R1, x0
	ADD R1, R1, x4

	JSR DIVIDE	 
	STI R2, CENTQUOTIENT; = C/4

	JSR ZELEQ
	STI R0, F+7
	AND R1, R1, x0
	ADD R1, R1, x7

	JSR DIVIDE;this the  modulo of 7 of the f
	STI R0, FMODULO
	ADD R1, R0, x0; copy the remainder(r0) to r1
	LEA R0, DAYS; load te adddress of DAYS

	LOOP
	ADD R1, R1, #-1; r1 holds the remainder,decrement it til neg.
	BRn DISPLAY
	ADD R0, R0, xA
	BR LOOP
	DISPLAY PUTS
	HALT

MULTIPLY
	BRnz END; go to end if the parameter is having 0 remainder or negative
	AND R2, R2, x0
	
MULTIPLYLOOP
	ADD R2, R2, R0
	ADD R1, R1, #-1
	BRp MULTIPLYLOOP
	BRn END; if it's negative
	RET

DIVIDE					;r0 dividend, r1 divisor, 42 where the result is stored, r0 remainder
	BRn END; if positive keep going
	NOT R1, R1
	NOT R1, R1
	ADD R1, R1, x1; 2's complement
	AND R2, R2, x0; clear r2

DIVIDELOOP ; subtraction of r1 from r0 til it became negative or 0
	ADD R0, R0, R1
	BRn QUOTEND1; if negative to QUOTEND1
	BRz QUOTEND2; if 0 , no remainder
	ADD R2, R2, x1;ADD ONE TO RESULT
	BR DIVIDELOOP

QUOTEND2			;if there's no remainder
	ADD R2, R2, x1	;add final number to result
	ADD R0,R0, R1

QUOTEND1
	NOT R1, R1
	ADD R1, R1, x1; add final number to result
	ADD R0, R0, R1
	RET

ZELEQ; Zeller's EQUATION: f=k+(13m-1)/5 +d+d/4 + c/4-2c
	LDI R0, K
	LDI R1,  MONQUOTIENT
	ADD R0, R0, R1
	LDI R1, D
	ADD R0, R0, R1
	LDI R1, LASTNUMQUOTIENT
	ADD R0, R0, R1
	LDI R1, CENTQUOTIENT
	ADD R0, R0, R1
	LDI R1, REVISEDCENT
	ADD R1, R1, R1;  to double the c(2c)
	NOT R1, R1
	ADD R1, R1, x1;2c becomes negative
	ADD R0, R0, R1
	RET
END HALT

;output
DAYS    .STRINGZ "Sunday   "
	.STRINGZ "Monday   "
	.STRINGZ "Tuesday  "
	.STRINGZ "Wednesday"
	.STRINGZ "Thursday "
	.STRINGZ "Friday   "
	.STRINGZ "Saturday "

X	.FILL X3200
K	.FILL X3201
C	.FILL X3202; first 2 digit of yr
FMODULO .FILL X3203;LAST 2 DIGIT Of year
R	.FILL X3204
M	.FILL X3205
REVISEDMONTH	.FILL X31F6
MONQUOTIENT	.FILL X3103
LASTNUMQUOTIENT	.FILL X3104
CENTQUOTIENT	.FILL X3105
F	.FILL X3106
D	.FILL X3017
REVISEDCENT	.FILL X3018
	.END
