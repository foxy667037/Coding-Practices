include irvine32.inc

.data
    var1 dd ?                 
    var2 dd ?
    msg1 byte "Enter Value For Variable 1: ", 0
    msg2 byte "Enter Value For Variable 2: ", 0
    msg3 byte "The Multiplication of given two numbers is: ", 0
    result dd ?

.code
MainPractice5 PROC
    ; Ask for first number
    mov edx, OFFSET msg1
    call WriteString
    call ReadInt
    mov var1, eax  ; Store user input into var1

    ; Ask for second number
    mov edx, OFFSET msg2
    call WriteString
    call ReadInt
    mov var2, eax  ; Store user input into var2

    ; Perform multiplication
    mov eax, var1  
    mov ebx, var2  
    mul ebx        

    mov result, eax  ; Store the result in 'result' variable

    ; Display result message
    call CRLF ; use to insert new line
    mov edx, OFFSET msg3
    call WriteString

    ; Display result
    mov eax, result
    call WriteInt

    exit
MainPractice5 ENDP
end MainPractice5