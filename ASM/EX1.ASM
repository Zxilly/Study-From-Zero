DATAS SEGMENT
        S1 DB 'ABCDEFG'
        S@ DB 5 DUP(?)
DATAS ENDS

CODES SEGMENT
        ASSUME CS:CODES,DS:DATAS
START:
        MOV AX,DATAS
        MOV DA,AX
        MOV SI,OFFSET S1
        MOV DI,OFFSET S2
        MOV CX,5
NEXT:
        MOV AL,[SI]
        MOV [DI],AL
        INC SI
        INC DI
        LOOP NEXT

        MOV AH:4CH
        INT 21H
CODES ENDS
ENS START
