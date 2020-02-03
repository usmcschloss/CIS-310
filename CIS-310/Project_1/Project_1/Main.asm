; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
A dword 30h
B dword 20h
C1 dword 10h
D dword 5h
finalVal dword ?

.code
main proc
	mov	eax,A				
	add	eax,B
	mov ebx,C1
	add ebx,D
	sub eax,ebx
	mov finalVal,eax

	invoke ExitProcess,0
main endp
end main