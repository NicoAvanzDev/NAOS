#include "keyboard.h"

static void keyboard_callback(registers_t *regs)
{
  // Read PIC scancode output
  uint8_t scancode = port_byte_in(0x60);

  if (scancode > 57) // Keyup case
    return;

  if (scancode == BACKSPACE)
  {
    kput_backspace();
    return;
  }
  if (scancode == ENTER)
    kprint("\n");

  char ascii = sc_ascii[(int)scancode];

  const char output[2] = {ascii, '\0'};
  kprint(output);
}

void init_keyboard()
{
  register_interrupt_handler(IRQ1, keyboard_callback);
}