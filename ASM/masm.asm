assume cs:code,ds:data
data segment
        string db 'hello masm!','$';display string
data ends
code segment
start:
        mov ax,data
        mov ds,ax
        lea dx,string
        mov ah,9
        int 21h
        mov ax,4c00h
        int 21h
code ends
end start
