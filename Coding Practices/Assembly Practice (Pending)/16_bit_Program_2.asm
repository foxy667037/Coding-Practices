include irvine32.inc
    ; library include for use 32-bit keywords.

.code
    ;tell that the code start there

Practice2Main PROC
    ;tell the start of the procedure

    ; Move values into registers
        mov eax, 10     
            ; Store 10 in EAX
        mov ebx, 8     
            ; Store 8 in EBX
        mov eax, 5     
            ; Overwrites EAX with 5

    ; Sum operation
        ; add ebx, eax  
        ; mov eax, ebx
        ; call writeint 
            ; Display eax values because it always take value from eax.

    ; Subtraction operation
        ; sub ebx,eax
        ; mov eax,ebx
        ; call writeint

    ; Multiplicatoin operation
        ; mul ebx     
            ;Mul always multiply the register with the value written in eax register and also store it in eax.
        ; call writeint

    ; Division operation
        ;mov eax, 15
        ;mov ebx, 10
        ;mov ecx, 3

        ; div always division the value with eax register value and store result in eax register. And the remainder store in edx register. To avoid the dump value we must make edx = 0.
        ;mov edx, 0
        ;div ebx 
        ;call writeInt

    ;call dumpregs  
        ; Display all registers values include dump register values.

    exit           
        ; Terminate program and ensure program terminate without any crashes.

Practice2Main ENDP
    ; it tell the end of the procedure, like (@if and @end if) in php

end Practice2Main
    ; this tell the entry point from where the instructions begin. it tell that the instructions start from Practice2Main procedure.