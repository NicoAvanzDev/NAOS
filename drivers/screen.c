#include "screen.h"

void clear()
{
  for (int row = 0; row < NUM_ROWS; row++)
  {
    for (int col = 0; col < NUM_COLS; col++)
    {
      print_at(' ', row, col);
    }
  }
}

void print_at(const char c, int row, int col)
{
  char *buf = (char *)VIDEO_ADDRESS;
  int offset = 2 * (col + NUM_COLS * row);

  buf[offset] = c;
  buf[offset + 1] = 0x0f;
}

void printk(const char *str)
{
  const char *p = str;
  int i = 0;
  while (p[i])
  {
    print_at(p[i], 0, i);
    i++;
  }
}