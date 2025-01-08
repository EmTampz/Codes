.ORIG x3000
    ; Prompt the user to enter a key
    LEA     R0, PROMPT
    PUTS
    GETC

    ; Subtract ASCII '0' to get the integer value
    ADD     R1, R0, #-16  ; Corrected subtraction from ASCII '0'
    ADD     R1, R0, #-16  ; Corrected subtraction from ASCII '0'
    ADD     R1, R0, #-16  ; Corrected subtraction from ASCII '0'

    ; Check if the value is in the range 0-6
    ADD     R2, R1, #-7
    BRN     INVALID_INPUT

    ; Array to store the names of days of the week
    LD      R3, DAYS_TABLE
    ADD     R3, R3, R1

    LEA     R0, DAY_PROMPT
    PUTS

    HALT

PROMPT      .STRINGZ "Enter a number (0-6): "
DAY_PROMPT  .STRINGZ "The day of the week is: "
DAYS_TABLE  .FILL x4000 ; Address of the days of the week strings
    .STRINGZ "Sunday"
    .STRINGZ "Monday"
    .STRINGZ "Tuesday"
    .STRINGZ "Wednesday"
    .STRINGZ "Thursday"
    .STRINGZ "Friday"
    .STRINGZ "Saturday"

INVALID_INPUT
    LEA     R0, INVALID_MSG
    PUTS
    HALT

INVALID_MSG .STRINGZ "Invalid input. Please enter a number between 0 and 6."

.END