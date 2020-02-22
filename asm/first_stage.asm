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


    mov ah, 0x02              ; функция
    mov dl, [bootdisk]        ; номер накопителя
    mov al, 0x10              ; количество читаемых секторов
    mov ch, 0x0
    mov cl, 0x2               ; номер сектора
    mov dh, 0x0               ; head

    int 0x13                  ; читаем, используя все параметры

    jc error                  ; если ошибка

    xor ax, ax                ; обнуление сегментных регистров
    mov ds, ax
    mov es, ax
    mov ss, ax

    ; mov ah, 0x00
    ; mov al, 0x3
    ; int 0x10

    ; переключение в PMode
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
    cli
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov ss, ax

    mov esp, 0xffffff         ; = стек находится в конце отведенной для ядра памяти

    call 0x100000             ; КОД НА СИ!

    jmp $


times 510 - ($ - $$) db 0
dw 0xaa55
