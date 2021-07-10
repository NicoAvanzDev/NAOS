[bits 32]
load_gdt:
  mov ebp, stack_top ; update the stack right at the top of the free space
  mov esp, ebp
  lgdt [gdt_descriptor]
  mov eax, cr0
  or eax, 0x1
  mov cr0, eax
init_pm:
  mov ax, DATA_SEG ; update the segment registers
  mov ds, ax
  mov ss, ax
  mov es, ax
  mov fs, ax
  mov gs, ax
  jmp CODE_SEG:end_load_gdt