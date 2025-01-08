     .ORIG x3000

    ; Load R1 and R2 with the numbers to compare
    ;AND R1, R1, #0
    ;ADD R1, R1, #3
    ;AND R2, R2, #0
    ;ADD R2, R2, #4

	LD R1,Num1
	LD R2,Num2

    ; Subtract R2 from R1 and store the result in R0
    NOT R2, R2
    ADD R2, R2, #1
    ADD R0, R1, R2

    BRz EQUAL ; Branch if equal
    BRn LESS  ; Branch if less than
    BRp GREATER ; Branch if greater than

EQUAL:
    AND R0, R0, #0 ; If R1 = R2, then R0 = 0
    BR DONE

LESS:
    AND R0, R0, #0 ; If R1 < R2, then R0 = -1
    ADD R0, R0, #-1
    BR DONE

GREATER:
    AND R0, R0, #0 ; If R1 > R2, then R0 = 1
    ADD R0, R0, #1
	 BR DONE


DONE:
    STI R0, RESULT ; Store the result at memory location x4000
    HALT

RESULT .FILL x4000
Num1 .FILL #4
Num2 .FILL #6

 .END


