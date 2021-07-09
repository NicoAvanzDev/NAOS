#pragma once
#ifndef IDT_H
#define IDT_H

#include "../libs/types.h"

#define IDT_ENTRIES 128

/* Segment selectors */
#define KERNEL_CS 0x08

struct IDT_struct
{
  uint16_t offset_low;
  uint16_t selector;
  uint8_t zero;
  uint8_t flags;
  uint16_t offset_high;
} __attribute__((packed)) idt[IDT_ENTRIES];

struct IDT_reg
{
  uint16_t limit;
  uint32_t base;
} __attribute__((packed)) idt_reg;

#endif