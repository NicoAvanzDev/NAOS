#include "../drivers/screen.h"
#include "../drivers/keyboard.h"
#include "../cpu/isr.h"
#include "../cpu/idt.h"
#include "../cpu/timer.h"

#include "../libc/io.h"

#define VERSION "0.1"

void init();

void kernel_main()
{
  init();

  kprintf("\nNAOS (i386) --- VERSION: %s\n", VERSION);
  kprintf("Welcome to NAOS operating system.\n");
  kprintf("Please feel free to edit the souce code made for educational purposes only!\n\n");

  kprintf("\n> ");
  char *str = gets();
  kprintf("%s", str);
}

void init()
{
  init_screen();
  kprintf("[ OK ] Screen initialized.\n");
  init_isr();
  kprintf("[ OK ] Interrupts initialized.\n");
  init_timer(50);
  kprintf("[ OK ] Timer initialized.\n");
  init_keyboard();
  kprintf("[ OK ] Keyboard initialized.\n");
}