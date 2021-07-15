#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include "ports.h"
#include "../libc/types.h"
#include <stdarg.h>

#define VIDEO_ADDRESS 0xB8000

#define NUM_COLS 80
#define NUM_ROWS 80
struct cursor
{
  int row;
  int col;
} cursor;

// Initialize screen related informations
void init_screen();

void kprintf(const char *str, ...);
void kput_backspace();
void kclear();

#endif