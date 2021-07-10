#include "idt.h"

void set_idt_gate(int n, uint32_t handler)
{
  idt[n].offset_low = low_16(handler);
  idt[n].selector = KERNEL_CS;
  idt[n].zero = 0;
  idt[n].flags = 0x8e;
  idt[n].offset_high = high_16(handler);
}

void set_idt()
{
  idt_reg.base = (uint32_t)&idt;
  idt_reg.limit = IDT_ENTRIES * sizeof(idt_gate_t) - 1;

  asm volatile("lidtl (%0)"
               :
               : "r"(&idt_reg));
}