.ORIG x3000
START   LEA R0, INPUT
	PUTS

	GETC
	ADD R3, R0, x0
	ADD R3, R3, #-16
	ADD R3, R3, #-16
	ADD R3, R3, #-16

	ADD R4, R3, x0
	NOT R4, R4
	ADD R4, R4, #7
	Brn END

	LEA R0, DAYS
	ADD R0, R0, R3  
	ADD R0, R0, R3  
	PUTS

	LEA R0, BREAK
	PUTSP
	
	BRnzp START

END HALT


DAYS    . STRINGZ "Sunday    "
         .STRINGZ "Monday   "
         .STRINGZ "Tuesday  "
         .STRINGZ "Wednesday"
         .STRINGZ "Thursday "
         .STRINGZ "Friday   "
         .STRINGZ "Saturday "

BREAK   .FILL x0A

INPUT .STRINGZ "\nPlease Enter Number (0-6):"
.END

