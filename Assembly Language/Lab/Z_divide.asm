; R1 = dividend
; R2 = divisor
; R3 = quotient
; R4 = counter

.ORIG x3000
    LEA R4, Dividend
    LEA R5, Divisor
    LDR R1, R4, #0
    LDR R2, R5, #0
    AND R3, R3, #0
    
; Division loop
Loop: NOT R4, R2
    ADD R4, R4, #1
    ADD R5, R1, R4
    BRn EndLoop
    ADD R3, R3, #1
    ADD R1, R1, R4
    BRp Loop
    
EndLoop: 
    ; Print the result
    LEA R0, Output
    PUTS
    ADD R0, R3, #0
    OUT

; Variables
Dividend: .FILL #10 ; Change this to your dividend
Divisor: .FILL #2 ; Change this to your divisor
Output: .STRINGZ "The quotient is: "

.END




