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
%include "boot/protected_mode.asm"
%include "boot/paging.asm"

global _start
[extern kernel_main]
[bits 32]
_start:
  call begin_pm
load_kernel: ; Label used to perform long jump after lgdt
  call enable_paging
  call kernel_main  
  jmp $