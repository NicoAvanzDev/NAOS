#include "screen.h"

#define OFFSET() (2 * (cursor.col + NUM_COLS * cursor.row))

// Private function
static void update_cursor();
static void kputc(char c);
static void kputs(const char *str);
static void kputi(int32_t i);
static void kput_hex(uint32_t i);
static void kput_hex_digit(uint8_t i);

// Pointer to video memory
unsigned char *buf = (unsigned char *)VIDEO_ADDRESS;

void init_screen()
{
  cursor.row = 0;
  cursor.col = 0;
}

// Simple output method
void kprintf(const char *str, ...)
{
  int i = 0;

  va_list args;
  int32_t ival;
  char *strval;
  va_start(args, str);

  while (str[i] != '\0')
  {
    if (str[i] != '%')
    {
      kputc(str[i]);
    }
    else
    {
      i++; // Skip the format letter
      switch (str[i])
      {
      case 'd':
        ival = va_arg(args, uint32_t);
        kputi(ival);
        break;
      case 'x':
        ival = va_arg(args, uint32_t);
        kput_hex(ival);
        break;
      case 's':
        strval = va_arg(args, char *);
        kputs(strval);
        break;
      }
    }
    i++;
  }
  va_end(args);
}

static void kputs(const char *str)
{
  while (*str)
  {
    kputc(*str);
    str++;
  }
}

static void kputi(int32_t i)
{
  int f, d;
  if (i < 0 && i != 0)
  {
    kputc('-');
    i = -i;
  }

  f = 1;
  while ((i / f) >= 10)
  {
    f *= 10;
  }
  while (f > 0)
  {
    d = i / f;
    kputc('0' + d);
    i = i - d * f;
    f = f / 10;
  }
}

static void kputc(char c)
{
  // If character is newline then increment column and return
  if (c == '\n')
  {
    cursor.row++;
    cursor.col = 0;
    update_cursor();
    return;
  }

  buf[OFFSET()] = c;
  cursor.col++;

  // Check if we've reached the end of the screen
  if (cursor.col == NUM_COLS)
  {
    cursor.row++;
    cursor.col = 0;
  }

  update_cursor();
}

static void kput_hex_digit(uint8_t i)
{
  if (i < 10)
  {
    kputc('0' + i);
  }
  else
  {
    kputc('a' + i - 10);
  }
}

static void kput_hex(uint32_t i)
{
  int j;
  for (j = 28; j >= 0; j = j - 4)
  {
    kput_hex_digit((i >> j) & 0x0f);
  }
}

void kput_backspace()
{
  if (cursor.col <= 0)
    return;
  cursor.col--;
  buf[OFFSET()] = ' ';

  update_cursor();
}

void kclear()
{
}

// set cursor position where our cursor currently is
static void update_cursor()
{
  uint16_t offset = OFFSET() / 2;
  port_byte_out(0x3d4, 14);
  port_byte_out(0x3d5, (uint8_t)(offset >> 8));
  port_byte_out(0x3d4, 15);
  port_byte_out(0x3d5, (uint8_t)(offset & 0xff));
}