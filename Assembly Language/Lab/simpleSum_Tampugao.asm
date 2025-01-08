.ORIG x3000 ; Program begins at address x3000

	AND R3, R3, x0; clear R3
	AND R1,R1, x0; Clear R1
ADD 	    R1,R1,x3; R1 is set to 3
	AND R2,R2,x0;  Clear r2
	ADD R2, R2, xA; R2 is set to 10
ADD	    R3,R1,R2; R3 <- R1+R2

	HALT; the program is done, all the objective met
.END