#include "io.h"

char *gets()
{
  wait_eoinput();
  char *str = (char *)kmalloc(sizeof(char) * 256);
  char *buffer = get_buffer();

  memcpy(str, buffer, 256);

  clear_buffer();
  return str;
}