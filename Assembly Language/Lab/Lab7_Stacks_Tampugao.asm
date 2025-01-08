.ORIG x3000 ;Start of the program

; Initialize stack pointer 
    LEA R6, STACK          ; Initialization of stack pointer

    ; Input 7 numbers 
    LEA R0, INPUT_NOTE     ; Loading the note to prompt
    PUTS                   
    LD R1, INPUT_SEVEN       
    LEA R2, ARRAY_INPUT    
       
    INPUT_NUM 
    GETC                   
    OUT                    
    STR R0, R2, #0         
    ADD R2, R2, #1         
    ADD R1, R1, #-1      ;Decrementing
    BRp INPUT_NUM              

    LD R1, INPUT_SEVEN
    LEA R2, ARRAY_INPUT

REV_ORDER_LOOP 
        LDR R0, R2, #0       
        JSR PUSH             ; Jumping to the subroutine PUSH  for storing the input into the stack
        ADD R2, R2, #1       ; Move to the next memory location(ARRAY_REV_OUTPUT)
        ADD R1, R1, #-1      ; Decrement 
        BRp REV_ORDER_LOOP   ; go back to the process

    LD R1, INPUT_SEVEN     
    LEA R2, ARRAY_REV_OUTPUT     

REV2_ORDER_LOOP  
        JSR POP              ; Jumping to the subroutine POP for  retrieving the input from the stack 
        STR R0, R2, #0       
        ADD R2, R2, #1       ;move to the next memory location(ARRAY_REV_OUTPUT)
        ADD R1, R1, #-1      ;decrement
        BRp REV2_ORDER_LOOP         ; go back to the processs

     ; Printing of the reverse order
    LEA R0, REV_INPUT_NOTE      ; Loading the note for reverse order
    PUTS                   
    LD R1, INPUT_SEVEN       
    LEA R2, ARRAY_REV_OUTPUT
       
DISPLAY_REV_ORDER 
        LDR R0, R2, #0         
        OUT                    
        ADD R2, R2, #1         
        ADD R1, R1, #-1        
        BRp DISPLAY_REV_ORDER      

; Sorting the input using bubble sort in Ascending Oorder
LD R4, INPUT_SEVEN ; Store total outer loop count in R4

SORT_ASCD 
        ADD R4, R4, #-1  
        BRZ SORTED ;exit, When loop has been complete
        ADD R5, R4, #0 ; Initializing inner loop counter to outer 
        LEA R3, ARRAY_INPUT ; Setting the file pointer to  the the starting of the array 

SORT_ASCD_INNER ;Inner loop
        LDR R0, R3, #0 ; Get the num at file pointer 
        LDR R1, R3, #1 ; Get next num
        NOT R2, R1 e
        ADD R2, R2, #1 ; next num 
        ADD R2, R0, R2 ;  num - next num ( swapping)
        BRNZ SWAPPING ; halt the  swapping if value is in order 
        STR R1, R3, #0 ; 
        STR R0, R3, #1 ;  swap 

SWAPPING 
        ADD R3, R3, #1 ; Increment file pointer 
        ADD R5, R5, #-1 ; Decrement inner loop counter 
        BRP SORT_ASCD_INNER ; End of inner loop 
        BRNZP SORT_ASCD  ; End of outer loop 
        SORTED

; Printing sorted order
LEA R0, SORT_INPUT_NOTE     ; Load the note for sorted order
PUTS                   
LD R1, INPUT_SEVEN       
LEA R2, ARRAY_INPUT       
DISPLAY_SORT_ASCD_ORDER 
LDR R0, R2, #0         
OUT                    
ADD R2, R2, #1         
ADD R1, R1, #-1        
BRp DISPLAY_SORT_ASCD_ORDER        ;In an ascending order, Repeat until the last number is printed  

HALT                    

PUSH 
    ADD R6, R6, #-1   ;  Decrement stack pointer and store the num
    STR R0, R6, #0         ; Store R0 value in the stack
    RET                     

POP 
    LDR R0, R6, #0     ;Load value from stack to R0
    ADD R6, R6, #1         ; Increment stack pointer
    RET                    

INPUT_NOTE .STRINGZ "Input a seven integers: "
REV_INPUT_NOTE .STRINGZ "\n Reverse Order: "
SORT_INPUT_NOTE .STRINGZ "\nSorted Order: "
INPUT_SEVEN .FILL #7
ARRAY_INPUT .BLKW #7
ARRAY_REV_OUTPUT .BLKW #7
STACK .BLKW #7

.END



