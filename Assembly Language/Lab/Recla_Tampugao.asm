.ORIG x3000
START   LEA R0, INPUT
    PUTS

    GETC
    ADD R0, R0, #-16
    ADD R0, R0, #-16
    ADD R0, R0, #-16

    ADD R1, R0, #-7
    BRn END

    LEA R0, DAYS
    ADD R0, R0, R1
    PUTS
    BRnzp START

END HALT

DAYS    .STRINGZ "Sunday   \n"
    .STRINGZ "Monday   \n"
    .STRINGZ "Tuesday  \n"
    .STRINGZ "Wednesday\n"
    .STRINGZ "Thursday \n"
    .STRINGZ "Friday   \n"
    .STRINGZ "Saturday \n"

INPUT .STRINGZ "Please Enter Number (0-6):\n"

.END

