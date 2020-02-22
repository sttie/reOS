; prints dx's hex value (2 bytes)
print_hex_dx:
    pusha
    mov cx, 4
    mov si, HEX_OUT+2    ; the pointer to the end of HEX_OUT

    ; after this the print_letter is executed

print_letter:
    cmp cx, 0            ; if cx is 0
    je print_hex_dx_done ; then printing is done

    mov bx, dx
    and bx, 0xf          ; get the last 4 bits of dx
    shr dx, 4            ; delete the last 4 bits of dx

    cmp bx, 0xa          ; check if the last 4 bits are a letter or a number
    jl number            ; jmp to the number func if a number
    jmp letter           ; otherwise jmp to the letter func

number:
    add bx, 48           ; add 48 to make the bits a correct ASCII code for the current number
    mov [si], bx         ; insert to the current place of HEX_OUT the ASCII code

    dec cx               ; decrement the counter
    inc si               ; decrement the pointer
    jmp print_letter     ; and loop again

letter:
    add bx, 87           ; add 87 to make the bits a correct ASCII code for the current letter
    mov [si], bx         ; insert to the current place of HEX_OUT the ASCII code

    dec cx               ; decrement the counter
    inc si               ; decrement the pointer
    jmp print_letter     ; and loop again

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
