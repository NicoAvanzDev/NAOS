#include "screen.h"

void clear()
{
  for (int row = 0; row < NUM_ROWS; row++)
  {
    for (int col = 0; col < NUM_COLS; col++)
    {
      print_at('A', row, col);
    }
  }
}

void print_at(byte c, int row, int col)
{
  byte *buf = (byte *)VIDEO_ADDRESS;
  int offset = col + NUM_COLS * row;

  *(buf + (byte)offset) = c;
  *(buf + (byte)offset + 1) = 0x0f;
  *((byte *)0xb8002) = c;
  *((byte *)0xb8003) = 0x0f;
}