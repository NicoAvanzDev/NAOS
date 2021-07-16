#include "io.h"

char *gets()
{
  wait_eoinput();
  char *str = (char *)kmalloc(sizeof(char) * 256);
  char *buffer = get_buffer();

  int i = 0;
  while (buffer[i] != '\0')
  {
    str[i] = buffer[i];
    i++;
  }
  str[i + 1] = '\0';

  clear_buffer();
  return str;
}