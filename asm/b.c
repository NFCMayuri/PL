global main

main:
	mov ebx, 1
	mov ecx, 2
	add ebx, ecx


	mov [abcd], ebx
	mov eax ,[abcd]

	ret

section .data

abcd		dw	0
