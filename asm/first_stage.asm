bits 16

jmp start

%include "asm/print_hex.asm"
%include "asm/gdt.inc"

; ================================================

start:
    cli
    mov ah, 0x00              ; очистка экрана
    mov al, 0x03
    int 0x10

    xor ax, ax                ; инициализация сегментных регистров
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7e00           ; инициализация стека

    ; call check_a20

    mov [bootdisk], dl
    jmp reset

reset:
    ; reset the disk
    xor ax, ax
    mov dl, [bootdisk]
    int 0x13
    jc error


load_disk:
    ; ===================================
    ; чтение с диска
    ; если cf = 1, то произошла ошибка, в ah код ошибки

    mov bx, 0xffff            ; загружаем код по адресу 0x100000
    mov es, bx
    mov bx, 0x10              ; получается es:bx = 0xffff:0x10
    ; mov bx, 0x0900
    ; mov es, bx
    ; mov bx, 0x0         ; 0x0900:0x0 = 0x9000


    mov ah, 0x02              ; функция
    mov dl, [bootdisk]        ; номер накопителя
    mov al, 0x10              ; количество читаемых секторов
    mov ch, 0x0
    mov cl, 0x2               ; номер сектора
    mov dh, 0x0               ; head

    int 0x13                  ; читаем, используя все параметры

    jc error                  ; если ошибка

    xor ax, ax                ; null segments
    mov ds, ax
    mov es, ax
    mov ss, ax

    ; mov ah, 0x00
    ; mov al, 0x3
    ; int 0x10

    ; ENTERING PM MODE!
    lgdt [gdtr]
    mov eax, cr0
    or al, 1
    mov cr0, eax

    jmp 0x8:final_stage

error:
    mov dx, ax
    call print_hex_dx

    jmp $


bootdisk: db 0 ; for boot disk number

; =================================================
bits 32

final_stage:
    cli			              ; почему без эого комп вырубается?
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov ss, ax

    mov esp, 0xffffff         ; = стек находится в конце отведенной для ядра памяти

    call 0x100000             ; C CODE!

    jmp $


; is_A20_on?:
;     pushad
;     mov edi,0x112345  ;odd megabyte address.
;     mov esi,0x012345  ;even megabyte address.
;     mov [esi],esi     ;making sure that both addresses contain diffrent values.
;     mov [edi],edi     ;(if A20 line is cleared the two pointers would point to the address 0x012345 that would contain 0x112345 (edi))
;     cmpsd             ;compare addresses to see if the're equivalent.
;     popad
;     jne A20_on        ;if not equivalent , A20 line is set.
;     ret               ;if equivalent , the A20 line is cleared.
; A20_on:
;     mov ebx, 0xb8000
;     mov byte [ebx], 'x'
;     mov byte [ebx+1], 0x4
;     ret


times 510 - ($ - $$) db 0
dw 0xaa55
