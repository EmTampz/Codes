.ORIG x3000

; Load R1 and R2 with the numbers to multiply
LD R1, Num1
LD R2, Num2

; Initialize R0 to 0
AND R0, R0, #0

; Multiply R1 and R2 and store the result in R0
MULTIPLY:
    ADD R0, R0, R1
    ADD R2, R2, #-1
    BRp MULTIPLY

; Store the result at memory location x4000
ST R0, RESULT
HALT

RESULT: .FILL x4000
Num1: .FILL #2
Num2: .FILL #4

.END

