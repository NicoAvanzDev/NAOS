#include "keyboard.h"

static char *buffer;

static int eoinput;

const char sc_ascii[] = {'?', '?', '1', '2', '3', '4', '5', '6',
                         '7', '8', '9', '0', '-', '=', '?', '?', 'Q', 'W', 'E', 'R', 'T', 'Y',
                         'U', 'I', 'O', 'P', '[', ']', '?', '?', 'A', 'S', 'D', 'F', 'G',
                         'H', 'J', 'K', 'L', ';', '\'', '`', '?', '\\', 'Z', 'X', 'C', 'V',
                         'B', 'N', 'M', ',', '.', '/', '?', '?', '?', ' '};

void append_buffer(char c);
void backspace_buffer();

static void keyboard_callback(registers_t *regs)
{
  // Read PIC scancode output
  uint8_t scancode = port_byte_in(0x60);

  if (scancode > 57) // Keyup case
    return;

  if (scancode == BACKSPACE)
  {
    backspace_buffer();
    kput_backspace();
    return;
  }
  else if (scancode == ENTER)
  {
    eoinput = 1;
    kprintf("\n");
    return;
  }

  char ascii = sc_ascii[(int)scancode];
  append_buffer(ascii);

  const char output[2] = {ascii, '\0'};
  kprintf(output);
}

void init_keyboard()
{
  register_interrupt_handler(IRQ1, keyboard_callback);
  buffer = kmalloc(BUFFER_SIZE);
  *buffer = '\0';

  eoinput = 0;
}

void append_buffer(char c)
{
  int i = 0;
  while (buffer[i] != '\0')
  {
    i++;
  }
  if (i == BUFFER_SIZE)
    i = 0;
  buffer[i] = c;
  buffer[i + 1] = '\0';
}

void backspace_buffer()
{
  int i = 0;
  while (buffer[i] != '\0')
  {
    i++;
  }
  if (i <= 0)
    i = 0;
  buffer[i - 1] = '\0';
}

char *get_buffer()
{
  return buffer;
}

void clean_buffer()
{
  buffer[0] = '\0';
}

void wait_eoinput()
{
  while (eoinput != 1)
  {
  }
  eoinput = 0;
}