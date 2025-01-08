.ORIG x3000

LEA R6, STACK; Initialize stack pointer

; Input 7 numbers
LEA R0, INPUT
PUTS
LD R1, SEVEN_NUM
LD R2, ARRAY_LIST
INPLOOP
    GETC
    OUT
    STR R0, R2, #0
    ADD R2, R2, #1
    ADD R1, R1, #-1
    BRp INPLOOP

; Reverse array_LIST using stack
LD R1, SEVEN_NUM
LD R2, ARRAY_LIST
REVERSE_LOOP
    LDR R0, R2, #0
    JSR PUSH
    ADD R2, R2, #1
    ADD R1, R1, #-1
    BRp REVERSE_LOOP

LD R1, SEVEN_NUM
LD R2, ALIST_REVERSE
REVERSE1_LOOP
    JSR POP
    STR R0, R2, #0
    ADD R2, R2, #1
    ADD R1, R1, #-1
    BRp REVERSE1_LOOP

;  Print reversed array_LIST
LEA R0, REVERSE_ORDER
PUTS
LD R1, SEVEN_NUM
LD R2, ALIST_REVERSE
DISPLAY_REVLOOP
    LDR R0, R2, #0
    OUT
    ADD R2, R2, #1
    ADD R1, R1, #-1
    BRp DISPLAY_REVLOOP

; Sort array_LIST using bubble sort
LD R4, Stck_Pntr
SORT_LOOP
    LD R1, SEVEN_NUM
    LD R2, ARRAY_LIST
SORT_INNER_LOOP
        LDR R0, R2, #0
        LDR R3, R2, #1
        ADD R2, R2, #1
        ADD R1, R1, #-1
        BRz SORT_INNER_LOOP   ; If R0 is 0, no swap needed

        BRz SWAP             ; If R0 (smaller) is 0, skip swap
        STR R3, R2, #-1      ; Swap
        STR R0, R2, #0
        BRnzp SORT_INNER_LOOP  ; Jump back if swap occurred

SWAP
        ADD R4, R4, #-1
        BRp SORT_LOOP          ; Repeat outer loop

;  Print sorted array_LIST
LEA R0, SORT_INPUT
PUTS
LD R1, SEVEN_NUM
LD R2, ARRAY_LIST
DISPLAY_SORT_LOOP
        LDR R0, R2, #0
        OUT
        ADD R2, R2, #1
        ADD R1, R1, #-1
        BRp DISPLAY_SORT_LOOP

HALT

; Subroutine: PUSH
PUSH
        ADD R6, R6, #-1
        STR R0, R6, #0
        RET

; Subroutine: POP
POP
        LDR R0, R6, #0
        ADD R6, R6, #1
        RET

INPUT .STRINGZ "Input Seven numbers: "
REVERSE_ORDER .STRINGZ "\nReversed Order: "
SORT_INPUT .STRINGZ "\nSorted Order: "
SEVEN_NUM .FILL #7
Stck_Pntr .FILL #6
ARRAY_LIST .BLKW #7
ALIST_REVERSE .BLKW #7
STACK .BLKW #7

.END































