#pragma once
#ifndef MEM_H
#define MEM_H

#include "../libc/types.h"

#define MEM_ADDR 0x100000

void *kmalloc(uint32_t sz);
void *kmalloc_a(uint32_t sz, int align);

#endif