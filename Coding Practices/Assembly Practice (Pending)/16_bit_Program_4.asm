include irvine32.inc

.data
	; Datatypes
		; BYTE: Defines an 8-bit (1-byte) value, typically used for storing a single character. Used in registers like AL, AH, BL, BH, CL, CH, DL, DH.
		; SBYTE: Defines an 8-bit signed value (Signed BYTE). It can store values from -128 to 127.
		; WORD (dw): Defines a 16-bit (2-byte) value. Used in registers like AX, BX, CX, DX.
		; SWORD (sdw): Defines a 16-bit signed value (Signed WORD). It can store values from -32,768 to 32,767.
		; DWORD (dd): Defines a 32-bit (4-byte) value. Used in extended registers like EAX, EBX, ECX, EDX.
		; QWORD (dq): Defines a 64-bit (8-byte) value. Used in registers like RAX, RBX, RCX, RDX in x86_64 (64-bit mode).
		; TBYTE (dt): Defines a Ten-Byte (80-bit) value, typically used for FPU (Floating Point Unit) registers for extended precision floating-point calculations.

	; Variable Making Syantax
		; variable_name datatype value OR ?  (like, var1 dd 10)
		var2 dd 9

		msg byte "Hellow I am foxy and my age is: ", 0

.code
	MainPractice4 PROC
		mov eax,2
		mul var2

		mov edx, offset msg 
			;the offset tell the assembler to get memory address (not value of msg).
		call writestring 
			;it always takes value from edx. And it read the address and show output.
		call writeint
			; it always takes value from eax. And it cannot read memory address it display the value.
	exit
	MainPractice4 ENDP

end MainPractice4