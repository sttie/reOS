bits 16

; dw - byte
; dd - 2 bytes
; dq - 4 bytes
; GDT contains three descriptors: Null desc., Code desc. and Data desc.
; every desc. !!IS 8 BYTES LONG!!

;*******************************************
; Global Descriptor Table (GDT)
;*******************************************

gdt_start:
    dd 0                ; null descriptor--just fill 8 bytes
    dd 0

gdt_code:
    dw 0FFFFh           ; limit low
    dw 0                ; base low
    db 0                ; base middle
    db 10011010b        ; access
    db 11001111b        ; granularity
    db 0                ; base high

gdt_data:
    dw 0FFFFh           ; limit low (Same as code)
    dw 0                ; base low
    db 0                ; base middle
    db 10010010b        ; access
    db 11001111b        ; granularity
    db 0                ; base high
end_of_gdt:

gdtr:
    dw end_of_gdt - gdt_start - 1   ; limit (Size of GDT)
    dd gdt_start        ; base of GDT
