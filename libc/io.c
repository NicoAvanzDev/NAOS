#include "io.h"

char *gets()
{
  wait_eoinput();
  char *str;
  char *buffer = get_buffer();
  int i = 0;
  while (buffer[i] != '\0')
  {
    str[i] = buffer[i];
  }
  str[i + 1] = '\0';
  clean_buffer();
  return str;
}