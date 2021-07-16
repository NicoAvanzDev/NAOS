#include "io.h"

char *gets()
{
  kprintf("WAITING INPUT. \n");
  wait_eoinput();
  kprintf("INPUT RECEIVED. \n");
  char *str = kmalloc(256);
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