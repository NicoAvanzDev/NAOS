#include "mem.h"

void *kmalloc(uint32_t sz)
{
  void *mem_ptr = (void *)MEM_ADDR;
  mem_ptr += sz;
  return mem_ptr;
}

void *kmalloc_a(uint32_t sz, int align)
{
  uint32_t mem_loc = (uint32_t)MEM_ADDR;
  if (align == 1 && (MEM_ADDR & 0xFFFFF000))
  {
    mem_loc &= 0xFFFFF000;
    mem_loc += 0x1000;
  }
  void *mem_ptr = &mem_loc;
  mem_ptr += sz;
  return mem_ptr;
}