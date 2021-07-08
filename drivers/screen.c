#include "screen.h"

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
  while (str[i] != 0)
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

  buf[2 * (cursor.col + NUM_COLS * cursor.row)] = c;
  cursor.col++;

  // Check if we've reached the end of the screen
  if (cursor.col == NUM_COLS)
  {
    cursor.row++;
    cursor.col = 0;
  }
}

void kclear()
{
}
