#pragma once
#ifndef TIMER_H
#define TIMER_H

#include "isr.h"
#include "../drivers/ports.h"
#include "../drivers/screen.h"
#include "../libs/types.h"

void init_timer(uint32_t freq);

#endif