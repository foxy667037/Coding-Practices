; body

include irvine32.inc
.data
.code
main PROC
	mov eax, 7
	call dumpregs
	exit
main ENDP
end main
