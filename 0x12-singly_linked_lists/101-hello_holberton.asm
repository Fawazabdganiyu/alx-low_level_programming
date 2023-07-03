section .data
	message db 'Hello, Holberton', 0x0A  ; String to be printed followed by a new line

section .text
	global main

main:
	; Write the message to stdout
	mov eax, 1                  ; System call number for write
	mov edi, 1                  ; File descriptor (1 = stdout)
	mov esi, message            ; Address of the message
	mov edx, 17                 ; Length of the message
	syscall

	; Exit the program
	mov eax, 60                 ; System call number for exit
	xor edi, edi                ; Exit status (0)
	syscall
