#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include "ports.h"
#include "../libc/types.h"

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

void kprint(const char *str);
void kputc(char c);
void kput_backspace();
void kclear();

#endif