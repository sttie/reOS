; печатает значение регистра dx в хекс (2 байта)
print_hex_dx:
    pusha
    mov cx, 4
    mov si, HEX_OUT+2    ; указатель на конец HEX_OUT

print_letter:
    cmp cx, 0            ; если cx = 0
    je print_hex_dx_done ; то вывод закончен

    mov bx, dx
    and bx, 0xf          ; извлечение последних 4 бит dx
    shr dx, 4            ; удаление последних 4 бит dx

                            
    cmp bx, 0xa          ; проверяем, являются последние 4 бит буквой или цифрой
    jl number            ; прыгаем в функцию вывода цифры
    jmp letter           ; иначе в фукцию вывода буквы

number:
    add bx, 48           ; добавляем 48 чтобы сделать цифру корректным ASCII кодом
    mov [si], bx         ; помещаем цифру по указателю si

    dec cx
    inc si
    jmp print_letter     ; перезапускаем цикл

letter:
    add bx, 87           ; добавляем 87, чтобы сделать букву корректным ASCII кодом
    mov [si], bx         ; помещаем цифру по указателю si

    dec cx
    inc si
    jmp print_letter     ; перезапускаем цикл

print_hex_dx_done:
    mov ah, 0x0e
    mov al, [HEX_OUT+5]
    int 0x10
    mov al, [HEX_OUT+4]
    int 0x10
    mov al, [HEX_OUT+3]
    int 0x10
    mov al, [HEX_OUT+2]
    int 0x10

    popa
    ret



HEX_OUT: db '0x0000', 0
