#include "utils.h"

void *memcpy(void *dest, const void *src, int bytes)
{
  const char *s = (char *)src;
  char *d = (char *)dest;

  for (int i = 0; i < bytes; i++)
  {
    d[i] = s[i];
  }

  return dest;
}