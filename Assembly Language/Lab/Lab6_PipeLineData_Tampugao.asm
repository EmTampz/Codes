
.ORIG x3000
    AND R1, R1, #0
    ADD R1, R1, #7   
    AND R2, R2, #0
    ADD R2, R2, #1
    
FACT
    AND R4, R4, #0
    AND R3, R3, #0
    ADD R3, R3, #1

MULT
    ADD R4, R4, R2
    ADD R3, R3, #-1
    BRp MULT

    NOP; NOPs for stalling
    NOP
    NOP

    AND R2, R2, #0
    ADD R2, R2, R4
    ADD R1, R1, #-1
    BRp FACT

    HALT
.END


	

	