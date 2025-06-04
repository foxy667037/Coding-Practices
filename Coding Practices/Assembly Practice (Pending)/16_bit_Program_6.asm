include irvine32.inc
.data
    msg1 byte "Enter Number 1: ", 0
    var1 dd ?

    msg2 byte "Enter Number 2: ", 0
    var2 dd ?
    
    msg3 byte "Enter Operation To Perform (+ - / *): ", 0
    inputchr byte ?

    msg4 byte "The Answer is : ",0
    res1 dd ?
    res2 dd ?

    msg5 byte "Invalid Choice: ",0

    msg6 byte "Quotient: ",0

    msg7 byte "Remainder: ",0

.code
  CALCULATOR PROC
    ; Input value 1
        mov edx, OFFSET msg1
        call WriteString
        call ReadInt
        mov var1, eax   ; Store in var1
        call CRLF       ; New line

    ; Input value 2
        mov edx, OFFSET msg2
        call WriteString
        call ReadInt
        mov var2, eax   ; Store in var2
        call CRLF       ; New line

    ; Input operation
        mov edx, OFFSET msg3
        call WriteString
        call ReadChar
        mov inputchr, al   ; Store the character in chr1

    ; Display the character
        mov al, inputchr   ; Move stored char to AL
        call WriteChar     ; Print the character
        call CRLF          ; New line
        jmp check

    ; Procedure     
        check: 
          cmp al, '+'
          je addition

          cmp al, '-'
          je subtraction

          cmp al, '*'
          je multiplication

          cmp al, '/'
          je division

          jmp invalidOpr

           ; for addition  
              addition:
                mov eax, var1
                mov ebx, var2
                add eax, ebx
                mov res1, eax

                call CRLF
                mov edx, OFFSET msg4
                call WriteString

                mov eax, res1
                call WriteInt

                jmp endProgram

           ; for subtraction  
              subtraction:
                mov eax, var1
                mov ebx, var2
                sub eax, ebx
                mov res1, eax

                call CRLF
                mov edx, OFFSET msg4
                call WriteString

                mov eax, res1
                call WriteInt

                jmp endProgram

           ; for multiplication  
              multiplication:
                mov eax, var1
                mov ebx, var2
                mul ebx
                mov res1, eax

                call CRLF
                mov edx, OFFSET msg4
                call WriteString

                mov eax, res1
                call WriteInt

                jmp endProgram

           ; for division
              division:
                 mov eax, var1
                 mov ebx, var2
                 mov edx, 0     
                 div ebx        

                 mov res1, eax   ; Store Quotient
                 mov res2, edx   ; Store Remainder

                 call CRLF
                 mov edx, OFFSET msg6
                 call WriteString

                 ; Print Quotient
                     mov eax, res1
                     call WriteInt  

                     call CRLF
                     mov edx, OFFSET msg7
                     call WriteString

                 ; Print Remainder
                     mov eax, res2
                     call WriteInt
                     call CRLF

                     jmp endProgram
          
           ; if conditions fails
              invalidOpr:
                mov edx, OFFSET msg5
                call WriteString
                exit

           ; end the program
              endProgram:
                exit
CALCULATOR ENDP
end CALCULATOR