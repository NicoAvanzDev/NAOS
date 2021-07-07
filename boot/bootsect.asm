; Declare constants for the multiboot header.
FLAGS         equ  0                 ; this is the Multiboot 'flag' field
MAGIC         equ  0xe85250d6        ; 'magic number' lets bootloader find the header
HEADER_LENGTH equ header_end - header_start
CHECKSUM      equ  0x100000000 - (MAGIC + FLAGS + (HEADER_LENGTH))   ; checksum of above, to prove we are multiboot

section .multiboot
header_start:
	dd 0xe85250d6
	dd 0
  dd header_end - header_start
	dd 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start)) 

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
  mov esp, stack_top  
  call kernel_main
  cli
  hlt  