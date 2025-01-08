.ORIG x3000
    LEA R0, NUM1
    LD R1, MULTIPLICAND
    LD R2, MULTIPLIER
    AND R3, R3, #0

MULTIPLICATION_LOOP
    ADD R3, R3, R1
    ADD R2, R2, #-1
    BRp MULTIPLICATION_LOOP

    ADD R3, R3, #1 ; Add 1 to the product

    ST R3, PRODUCT
    LD R0, PRODUCT
    LD R3, HEX
    ADD R0, R0, R3 ; Convert to ASCII
    OUT
    HALT

NUM1 .STRINGZ "The product is: "
MULTIPLICAND .FILL #5 ; The first number
MULTIPLIER .FILL #4 ; The second number
PRODUCT .BLKW #1 ; Space to store the product
HEX .FILL x0030
.END



