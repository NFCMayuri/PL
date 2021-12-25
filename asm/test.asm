global main

main:
    mov ebx, 1
    mov ecx, 2
    add ebx, ecx
    
    mov [a], ebx
    mov eax, [a]
    ret

section .data
a   dw    0
