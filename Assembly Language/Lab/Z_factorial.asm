.ORIG	x3000
;Initialize 
    LDI	R0, ZERO
    LDI R1, a


LOOP 
    ADD	R0,R0,R2 ;number added to itself
    ADD	R0,R0,#-1
    BRp LOOP

DONE 
    STI R0, PRODUCT
    HALT

a .FILL	x4000

PRODUCT .FILL	x4001
ZERO .FILL	x3100  
.END