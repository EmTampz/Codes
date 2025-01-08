.ORIG x3000; program begins at address x3000
LEA R0, prompt1; load address of prompt1 into register
TRAP x22; print string pointed to by R0
AND R0,R0, x0
HALT; THE PROGRAM IS done , ALL OBJECTIVES
prompt1 .STRINGZ "Hello World!"; STRING VARIABLE
.END