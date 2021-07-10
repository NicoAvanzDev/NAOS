#include "../drivers/screen.h"
#include "../cpu/isr.h"
#include "../cpu/idt.h"

void kernel_main()
{
  init_screen();

  kprint("NAOS (i386) --- VERSION: 0.1\n");
  kprint("Welcome to NAOS operating system.\n");
  kprint("Please feel free to edit the souce code made for educational purposes only!\n\n");

  init_isr();
  asm volatile("int $2");
}