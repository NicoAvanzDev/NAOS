section .bss
align 4096
page_level_4:
  resb 4096
end_page_level_4:

page_level_3:
  resb 4096
end_page_level_3:

page_level_2:
  resb 4096
end_page_level_2:


section .text
setup_page_tables:
  mov eax, page_level_3
  or eax, 0b11 ; Present, Writable
  mov [page_level_4], eax

  mov eax, page_level_2
  or eax, 0b11 ; Present, Writable
  mov [page_level_3], eax

  mov ecx, 0  ; counter
.loop:
  mov eax, 0x200000 ; 2MiB
  mul ecx
  or eax, 0b10000011 ; Present, Writable, Huge Page
  mov [page_level_2 + ecx * 8], eax 

  inc ecx ; increment counter
  cmp ecx, 512 ; Check if the page table is mapped
  jne .loop

  ret

enable_paging:
  jmp setup_page_tables
  ; Pass table location to cpu
  mov eax, page_level_4
  mov cr3, eax
  ret