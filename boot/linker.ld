ENTRY(kernel_main)

SECTIONS
{
  . = 1M;
  .text ALIGN(0x1000) : { *(.text) }
  .data ALIGN(0x1000) : { *(.data) }
  .bss  ALIGN(0x1000) : { *(.bss) *(COMMON) }
}