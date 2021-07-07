#include "../drivers/screen.h"

void kernel_main()
{
  init_vga();
  *((unsigned char *)0xb8000) = 'A';
  *((unsigned char *)0xb8001) = 0xf0;
}