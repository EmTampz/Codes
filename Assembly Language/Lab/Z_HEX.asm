.ORIG x3000

AND R0,R0, #0
LD R0, NUM
LD R2, ASCII
ADD R0, R0,R2
OUT; display the result in console
HALT

;data
NUM .FILL X08
ASCII .FILL X30
OUT; display the sum

.END