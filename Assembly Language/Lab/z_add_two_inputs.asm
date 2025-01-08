.ORIG x3000

;input 1ST NUM
IN; input ASCII
LD R3,HEXN30 ; subtract x30 to get integer
ADD R0,R0,R3
ADD R1,R0,X0; move the 1st integer to r1 and free up r0

;input 2nd num
IN
ADD R0,R0,R3

;ADD NUMBERS
ADD R2,R0,R1

;print result
LEA R0, MESG
PUTS

ADD R0, R2,X0; move to r0
LD R3, HEX30; add 30 to convert to ASCII character

ADD R0, R0, R3
OUT; display sum

HALT

;data
MESG .STRINGZ "tHE SUM OF THE TWO INPUT IS: "
HEXN30 .FILL xFFD0 ; -30hex
HEX30 .FILL x0030; 30 hex

.END




