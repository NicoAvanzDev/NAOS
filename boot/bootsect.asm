; Declare constants for the multiboot header. (first 8k)
section .multiboot
header_start:
  dd 0xe85250d6 ; 'magic number' lets bootloader find the header
  dd 0  ; this is the Multiboot 'flag' field
  dd header_end - header_start ; header length
  dd 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start))  ; checksum of above, to prove we are multiboot

 ; end tag
  dw 0
  dw 0
  dd 8
header_end:

section .bss
align 16
stack_bottom:
resb 16384
stack_top:

section .text
global _start
[extern kernel_main]
[bits 32]
_start:  
  cli
  mov ebp, stack_top ; 6. update the stack right at the top of the free space
  mov esp, ebp
  lgdt [gdt_descriptor]
  mov eax, cr0
  or eax, 0x1
  mov cr0, eax
  mov ax, DATA_SEG ; 5. update the segment registers
  mov ds, ax
  mov ss, ax
  mov es, ax
  mov fs, ax
  mov gs, ax
  
  call kernel_main  
  hlt

; -------- GDT --------
gdt_start: ; don't remove the labels, they're needed to compute sizes and jumps
    ; the GDT starts with a null 8-byte
    dd 0x0 ; 4 byte
    dd 0x0 ; 4 byte

; GDT for code segment. base = 0x00000000, length = 0xfffff
; for flags, refer to os-dev.pdf document, page 36
gdt_code: 
    dw 0xffff    ; segment length, bits 0-15
    dw 0x0       ; segment base, bits 0-15
    db 0x0       ; segment base, bits 16-23
    db 10011010b ; flags (8 bits)
    db 11001111b ; flags (4 bits) + segment length, bits 16-19
    db 0x0       ; segment base, bits 24-31

; GDT for data segment. base and length identical to code segment
; some flags changed, again, refer to os-dev.pdf
gdt_data:
    dw 0xffff
    dw 0x0
    db 0x0
    db 10010010b
    db 11001111b
    db 0x0

gdt_end:

; GDT descriptor
gdt_descriptor:
    dw gdt_end - gdt_start - 1 ; size (16 bit), always one less of its true size
    dd gdt_start ; address (32 bit)

; define some constants for later use
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start

