#include <iostream>
#include <cstring>

#include "bn_core.h"
#include "bn_log.h"
#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_colors.h"
#include <bn_random.h>
#include "bn_math.h"
#include "bn_window.h"
#include <bn_string.h>
#include "bn_sram.h"
#include <bn_sprite_text_generator.h>
#include "bn_sound_items.h"

#include <string.h>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <list>

#include "bn_config_sprite_text.h"
#include "bn_sprite_text_generator.h"
#include "bn_regular_bg_ptr.h"
#include "bn_utf8_character.h"
#include "bn_log.h"
#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"

__attribute__((section(".ewram.update")))
void update(int x) {
	for (int t = 0; t < x; t++) {
		bn::sound_items::fireblast.play();
		for (int i = 0; i < 16; i++) {
			bn::core::update();
		}
	}

	for (int t = 0; t < 128; t++) {
		bn::core::update();
	}
}

#define flash_address 0

/*************************************************************************************************/

typedef volatile uint8_t vu8;
typedef volatile unsigned short vu16;
typedef volatile unsigned long vu32;

#define REG_DM0CNT_H *(u16*)0x40000ba
#define REG_DM1CNT_H *(u16*)0x40000c6
#define REG_DM3CNT_H *(u16*)0x40000de
#define REG_DISPCNT *(vu32*)0x4000000
#define FORCE_BLANK 0x80
#define BG2_EN 0x400
#define REG_IE *(vu16*)0x4000200
#define STATEID 0x57a731d7
#define STATEID2 0x57a731d8
#define AGB_ROM  ((u8*)0x8000000)
#define AGB_SRAM ((u8*)0xE000000)
#define AGB_SRAM_SIZE 64*1024
#define _FLASH_WRITE(pa, pd) { *(((u16 *)AGB_ROM)+((pa)/2)) = pd; __asm("nop"); }
#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t

u32 total_rom_size = 0;
u32 flash_size = 0;
u32 flash_sram_area = 0;

extern u32 total_rom_size;
extern u32 flash_sram_area;

int save_value = 0;

__attribute__((section(".ewram.bytecopy")))
void bytecopy(u8 *dst, const u8 *src, int count) {
	int i=0;
	do {
		dst[i]=src[i];
		i++;
	} while(--count);
}

__attribute__((section(".ewram.flash_write")))
int flash_write()
{
	bn::sram::write(137);
	flash_sram_area = 0x3C0000;

	update(3);

	// Finally, restore the SRAM data and proceed.
	bytecopy(AGB_SRAM, ((u8*)AGB_ROM+flash_sram_area), AGB_SRAM_SIZE);
	u16 ie = REG_IE;

	//stop all DMAs
	REG_DM0CNT_H=0;
	REG_DM1CNT_H=0;
	REG_DM3CNT_H=0;	
	REG_DISPCNT&=~0x0100; 				//disable BG 0
	REG_DISPCNT&=~(7 | FORCE_BLANK); 	//force mode 0, and turn off force blank
	REG_DISPCNT|=BG2_EN; 				//text on BG2

	REG_IE = REG_IE & 0xFFFE;

	update(4);

	// Erase flash sector
	_FLASH_WRITE(flash_sram_area, 0xF0);
	_FLASH_WRITE(0xAAA, 0xA9);
	_FLASH_WRITE(0x555, 0x56);
	_FLASH_WRITE(0xAAA, 0x80);
	_FLASH_WRITE(0xAAA, 0xA9);
	_FLASH_WRITE(0x555, 0x56);
	//_FLASH_WRITE(flash_sram_area, 0x30);

	while (1) {
		__asm("nop");
		if (*(((u16 *)AGB_ROM)+(flash_sram_area/2)) == 0xFFFF) {
			break;
		}
	}

	/*

	_FLASH_WRITE(flash_sram_area, 0xF0);

	// Write data
	for (int i=0; i<AGB_SRAM_SIZE; i+=2) {
		_FLASH_WRITE(0xAAA, 0xA9);
		_FLASH_WRITE(0x555, 0x56);
		_FLASH_WRITE(0xAAA, 0xA0);
		_FLASH_WRITE(flash_sram_area+i, (*(vu8 *)(AGB_SRAM+i+1)) << 8 | (*(vu8 *)(AGB_SRAM+i)));
		while (1) {
			__asm("nop");
			if (*(((vu16 *)AGB_ROM)+((flash_sram_area+i)/2)) == ((*(vu8 *)(AGB_SRAM+i+1)) << 8 | (*(vu8 *)(AGB_SRAM+i)))) {
				break;
			}
		}
	}
	_FLASH_WRITE(flash_sram_area, 0xF0);

	REG_IE = ie;

	*/

	update(6);

	return 2;
}

int flash_read() {
    uint8_t* save = (uint8_t*)&save_value;
    uint8_t* rom = (uint8_t*)AGB_ROM;

	// Read data
	for (int i=0; i < sizeof(save_value) / sizeof(uint8_t); i++) {
		save[i] = rom[i];
	}

	bn::sram::read(save_value);
    return 0;
}

/*************************************************************************************************/

int main()
{
	bn::core::init(); // Initialize Butano libraries
	//int f = flash_init(FLASH_SIZE_AUTO);

	bn::sprite_text_generator text_line(common::variable_8x16_sprite_font);
	bn::vector<bn::sprite_ptr, 8> text_sprite0;

	update(0);

	save_value = flash_write();

	//save_value = 0;
	//flash_read();

	text_sprite0.clear();
	bn::string<8> txt_score = bn::to_string<8>(save_value);
	text_line.generate(0, 0, txt_score, text_sprite0);

	while(true) {
		bn::core::update();
	}

	// Get to the end?
	bn::core::reset();
}