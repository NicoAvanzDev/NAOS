#pragma once
#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "ports.h"
#include "screen.h"
#include "../cpu/isr.h"
#include "../libc/types.h"
#include "../memory/mem.h"

#define BACKSPACE 0x0e
#define ENTER 0x1c

#define BUFFER_SIZE 256

void init_keyboard();
char *get_buffer();
void clear_buffer();
void wait_eoinput();

#endif