a200
db 50

a260
db 'Iveskite teksta' 0D 0A '$'

a300
xor al, al
mov si, cl
mov dl, [bx + si]
cmp dl, 61
jl 32d
cmp dl, 7a
jg 32d
clc
rcr dl, 1
adc al, 0
rcr dl, 2
adc al, 0
rcr dl, 1
adc al, 0
rcr dl, 1
adc al, 0
rcr dl, 3
mov dl, [bx + si]
cmp al, 2
jnz 32d
mov dl, 39
mov ah, 02
int 21
ret

a100
mov ah, 09
mov dx, 260
int 21
mov ah, 0A
mov dx, 200
int 21 mov ah, 02 mov dl, 0d int 21
mov dl, 0a
int 21
xor cx, cx
mov bx, 201
mov cl, [bx]
call 300
loop 11f
mov ah, 4c
int 21

n programa.com
r cx
500
w
q
