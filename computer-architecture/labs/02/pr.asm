%include 'yasmmac.inc'
org 100h

section .text                   

    startas:                     
    macPutString 'Joris Lisas, 1 kursas, 2 grupe', crlf, '$'

    ;--- Get argument from command line ---
    mov cx, [80h]
    mov si, 82h
    mov di, inputFile 

    getArgument:
	mov al, [si]
	mov [di], al
	inc di
	inc si
    loop getArgument

    ;--- Read into buffer ---
    mov dx, inputFile
    call procFOpenForReading
    jc error
    mov dx, readingBuffer
    mov cx, 50000
    call procFRead  
    call procFClose

    ;--- Get output file name ---
    macPutString 'Ivesk isvesties failo pavadinima:', crlf, '$'
    mov dx, outputFile
    mov al, 50h
    call procGetStr
    
    mov si, readingBuffer   ; iteravimui per duomenis
    xor ax, ax		    ; al - simboliams
			    ; ah - B ir C radimo pozymis
    xor bl, bl		    ; bl - pirmo, stulpelio sekimui
    xor dx, dx		    ; rezultato sekimui

    logic:
	LODSB

	cmp al, 00
	jz .end
	cmp al, 0ah
	jz .endOfLine
	cmp al, ';'
	jz .endOfField
	cmp al, 'B'
	jz .foundBC
	cmp al, 'C'
	jz .foundBC
	jmp .restartLoop

	.foundBC:
	cmp bl, 00
	jz .restartLoop
	mov ah, 01
	jmp .restartLoop

	.endOfField:
	cmp bl, 00
	jz .zeroAH
	dec bl
	cmp ah, 00
	jnz .zeroAH
	add dx, 0001h
	jmp .zeroAH

	.endOfLine:
	int 3
	mov bl, 02
	jmp .restartLoop

	.zeroAH:
	mov ah, 00
	.restartLoop:
    jmp logic

    .end:
    
    xor si, si
    mov ax, dx
    mov dx, answer
    call procUInt16ToStr

    mov dx, outputFile
    call procFCreateOrTruncate 
    jc error

    printAnswer:
    mov al, [answer + si]
    cmp al, 00
    je end
    call procFPutChar
    inc si
    jmp printAnswer

    error:
    macPutString 'Could not open file', crlf, '$'

    end:
    call procFClose

    exit

%include 'yasmlib.asm'

section .data
    answer:
	times 5 db 00
    inputFile:
	times 0x60 db 00
    outputFile:
	times 0x60 db 00
    readingBuffer:
	times 0x300 db 00

section .bss
