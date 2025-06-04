;60 - 20 + 60 x 10 x 80 / 4 + 8 - 5
;using DMAS rule

include irvine32.inc
.code
	DMAS PROC
		mov eax, 80
		mov ebx, 4
		mov edx, 0

		div ebx
		;call writeint

		mov ebx, 60
		mul ebx
		;call writeint

		mov ebx, 10
		mul ebx
		;call writeint

		add eax, 8
		;call writeint
		sub eax, 5     
		;call writeint
		add eax, 60    
		;call writeint
		sub eax, 20      
		call writeint
		exit
	DMAS ENDP
end DMAS