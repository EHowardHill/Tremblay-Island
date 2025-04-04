#pragma once

#include "tonc.h"

#define AGB_ROM  ((vu8*)0x8000000)
#define AGB_SRAM ((vu8*)0xE000000)
#define _FLASH_WRITE(pa, pd) { *(((vu16 *)AGB_ROM)+((pa)/2)) = pd; __asm("nop"); }
extern u8 flash_type;
extern u32 flash_size;
extern u32 flash_sram_area;

extern u32 get_flash_type();
void write_sram_to_flash();
void flash_init();
