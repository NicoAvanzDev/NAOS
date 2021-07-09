#include "idt.h"

void set_idt_gate(int n, uint32_t handler)
{
  idt[n].offset_low = (uint16_t)handler & 0xffff;
  idt[n].selector = KERNEL_CS;
  idt[n].zero = 0;
  idt[n].flags = 0x8e;
  idt[n].offset_low = (uint16_t)(handler >> 16) & 0xffff;
}