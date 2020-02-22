bits 16

; dw - 1 байт
; dd - 2 байта
; dq - 4 байта
; В GDT три дескриптора: Нуль-дескриптор, дескриптор код и дескриптор данных.
; every desc. !!IS 8 BYTES LONG!!

;==========================================
; Global Descriptor Table (GDT)
;===========================================

gdt_start:
    dd 0                ; Заполняем нулями нуль-дескриптор
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
    dw end_of_gdt - gdt_start - 1   ; лимит (размер GDT)
    dd gdt_start
