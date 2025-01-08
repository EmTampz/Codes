.ORIG x3000             ; This set the origin of the program 
START   LEA R0, INPUT   ; Load the address of the string INPUT into R0
	PUTS            ; Print the string at the memory location pointed to by R0

	GETC            ; Get a character, ASCII value is stored in R0
	ADD R3, R0, x0  ; Copy the value in R0 to R3
	ADD R3, R3, #-16; Subtract 16 from the value in R3 (to convert ASCII number to actual number)
	ADD R3, R3, #-16; Subtract 16 again
	ADD R3, R3, #-16; Subtract 16 again

	ADD R4, R3, x0  ; Copy the value in R3 to R4
	NOT R4, R4      ; Bitwise NOT operation on the value in R4
	ADD R4, R4, #7  ; Add 7 to the value in R4 , this serves like a terminating key of the program
	Brn END         ; Branch instructionL If result is negative, branch to END

	LEA R0, DAYS    ; Load the address of the string DAYS(Sunday,etc.) into R0

INPUT .STRINGZ "Please Enter Number (0-6):" ; this define a string

	LEA R0, DAYS    ; This Load the address of the string "Sunday" into R0
	
LOOP BRz DISPLAY    ; If result is zero, branch to DISPLAY
	ADD R0, R0, #10 ; Add 10 to the value in R0
	ADD R3, R3, #-1 ; Subtract 1 from the value in R3
	BR LOOP         ; Unconditional branch to LOOP

DISPLAY PUTS        ; Print the string at the memory location pointed to by R0
	BR START        ; Unconditional branch to START
	END             ;  end 
	HALT            ; Halt execution

DAYS    .STRINGZ "Sunday   "   ; Define a string for each day of the week
	.STRINGZ "Monday   "
	.STRINGZ "Tuesday  "
	.STRINGZ "Wednesday"
	.STRINGZ "Thursday "
	.STRINGZ "Friday   "
	.STRINGZ "Saturday "

.END                ; end of this program
