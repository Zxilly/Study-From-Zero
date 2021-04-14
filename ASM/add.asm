;#MODE=DOS

CSEG SEGMENT
    ASSUME CS:CSEG
    START:
        MOV AH,80H
        MOV BH,80H
        ADD AH,BH
        NOP
        MOV AH,4CH
        INT 21H
        CSEG ENDS
        END START