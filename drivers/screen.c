#include "screen.h"

#define OFFSET() (2 * (cursor.col + NUM_COLS * cursor.row))

// Private function
void update_cursor();

// Pointer to video memory
unsigned char *buf = (unsigned char *)VIDEO_ADDRESS;

void init_screen()
{
  cursor.row = 0;
  cursor.col = 0;
}

// Simple output method
void kprint(const char *str)
{
  int i = 0;
  while (str[i] != '\0')
  {
    kputc(str[i]);
    i++;
  }
}

void kputc(char c)
{
  // If character is newline then increment column and return
  if (c == '\n')
  {
    cursor.row++;
    cursor.col = 0;
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
void update_cursor()
{
  uint16_t offset = OFFSET() / 2;
  port_byte_out(0x3d4, 14);
  port_byte_out(0x3d5, (uint8_t)(offset >> 8));
  port_byte_out(0x3d4, 15);
  port_byte_out(0x3d5, (uint8_t)(offset & 0xff));
}