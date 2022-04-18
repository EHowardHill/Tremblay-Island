// Flash save code based on https://github.com/lesserkuma/goombacolor

#include <tonc.h>
#include "flashsaves.h"

__attribute__((section(".iwram"), target("arm"), long_call))
static void bytecopy(vu8 *dst, vu8 *src, int count)
{
	for (int i = 0; i < count; i++) {
		dst[i] = src[i];
	}
}

EWRAM_CODE static int bytecmp(vu8 *buf1, vu8 *buf2, size_t count) {
	if (count == 0) {
		return 0;
	}
	while (--count && *buf1 == *buf2) {
		buf1++;
		buf2++;
	}
	return *buf1 - *buf2;
}

#define STATEID 0x57a731d8
#define STATEID2 0x57a731d9

u32 flash_size = 0;
u32 flash_sram_area = 0;
u8 flash_type = 0;

// This function will auto-detect three common
// types of reproduction flash cartridges.
// Must run in EWRAM because ROM data is
// not visible to the system while checking.
EWRAM_CODE u32 get_flash_type() {
	
	
	u32 rom_data, data;
	u16 ie = REG_IE;
	REG_IE = ie & 0xFFFE;
	
	rom_data = *(vu32 *)AGB_ROM;
	
	// Type 1 or 4
	_FLASH_WRITE(0, 0xFF);
	_FLASH_WRITE(0, 0x90);
	data = *(vu32 *)AGB_ROM;
	_FLASH_WRITE(0, 0xFF);
	if (rom_data != data) {
		// Check if the chip is responding to this command
		// which then needs a different write command later
		_FLASH_WRITE(0x59, 0x42);
		data = *(vu8 *)(AGB_ROM+0xB2);
		_FLASH_WRITE(0x59, 0x96);
		_FLASH_WRITE(0, 0xFF);
		if (data != 0x96) {
			REG_IE = ie;
			return 4;
		}
		REG_IE = ie;
		return 1;
	}

	// Type 2
	_FLASH_WRITE(0, 0xF0);
	_FLASH_WRITE(0xAAA, 0xA9);
	_FLASH_WRITE(0x555, 0x56);
	_FLASH_WRITE(0xAAA, 0x90);
	data = *(vu32 *)AGB_ROM;
	_FLASH_WRITE(0, 0xF0);
	if (rom_data != data) {
		REG_IE = ie;
		return 2;
	}
	
	// Type 3
	_FLASH_WRITE(0, 0xF0);
	_FLASH_WRITE(0xAAA, 0xAA);
	_FLASH_WRITE(0x555, 0x55);
	_FLASH_WRITE(0xAAA, 0x90);
	data = *(vu32 *)AGB_ROM;
	_FLASH_WRITE(0, 0xF0);
	if (rom_data != data) {
		REG_IE = ie;
		return 3;
	}
	
	REG_IE = ie;
	return 0;
}

// This function will issue a flash sector erase
// operation at the given sector address and then
// write 64 kilobytes of SRAM data to Flash ROM.
// Must run in EWRAM because ROM data is
// not visible to the system while erasing/writing.
EWRAM_CODE void flash_write(u8 flash_type, u32 sa)
{
	if (flash_type == 0) return;
	u16 ie = REG_IE;
	REG_IE = ie & 0xFFFE;
	
	if (flash_type == 1) {
		// Erase flash sector
		_FLASH_WRITE(sa, 0xFF);
		_FLASH_WRITE(sa, 0x60);
		_FLASH_WRITE(sa, 0xD0);
		_FLASH_WRITE(sa, 0x20);
		_FLASH_WRITE(sa, 0xD0);
		while (1) {
			__asm("nop");
			if (*(((vu16 *)AGB_ROM)+(sa/2)) == 0x80) {
				break;
			}
		}
		_FLASH_WRITE(sa, 0xFF);
		
		// Write data
		for (int i=0; i<SRAM_SIZE; i+=2) {
			_FLASH_WRITE(sa+i, 0x40);
			_FLASH_WRITE(sa+i, (*(vu8 *)(AGB_SRAM+i+1)) << 8 | (*(vu8 *)(AGB_SRAM+i)));
			while (1) {
				__asm("nop");
				if (*(((vu16 *)AGB_ROM)+(sa/2)) == 0x80) {
					break;
				}
			}
		}
		_FLASH_WRITE(sa, 0xFF);
		
	} else if (flash_type == 2) {
		// Erase flash sector
		_FLASH_WRITE(sa, 0xF0);
		_FLASH_WRITE(0xAAA, 0xA9);
		_FLASH_WRITE(0x555, 0x56);
		_FLASH_WRITE(0xAAA, 0x80);
		_FLASH_WRITE(0xAAA, 0xA9);
		_FLASH_WRITE(0x555, 0x56);
		_FLASH_WRITE(sa, 0x30);
		while (1) {
			__asm("nop");
			if (*(((vu16 *)AGB_ROM)+(sa/2)) == 0xFFFF) {
				break;
			}
		}
		_FLASH_WRITE(sa, 0xF0);
		
		// Write data
		for (int i=0; i<SRAM_SIZE; i+=2) {
			_FLASH_WRITE(0xAAA, 0xA9);
			_FLASH_WRITE(0x555, 0x56);
			_FLASH_WRITE(0xAAA, 0xA0);
			_FLASH_WRITE(sa+i, (*(vu8 *)(AGB_SRAM+i+1)) << 8 | (*(vu8 *)(AGB_SRAM+i)));
			while (1) {
				__asm("nop");
				if (*(((vu16 *)AGB_ROM)+((sa+i)/2)) == ((*(vu8 *)(AGB_SRAM+i+1)) << 8 | (*(vu8 *)(AGB_SRAM+i)))) {
					break;
				}
			}
		}
		_FLASH_WRITE(sa, 0xF0);
		
	} else if (flash_type == 3) {
		// Erase flash sector
		_FLASH_WRITE(sa, 0xF0);
		_FLASH_WRITE(0xAAA, 0xAA);
		_FLASH_WRITE(0x555, 0x55);
		_FLASH_WRITE(0xAAA, 0x80);
		_FLASH_WRITE(0xAAA, 0xAA);
		_FLASH_WRITE(0x555, 0x55);
		_FLASH_WRITE(sa, 0x30);
		while (1) {
			__asm("nop");
			if (*(((vu16 *)AGB_ROM)+(sa/2)) == 0xFFFF) {
				break;
			}
		}
		_FLASH_WRITE(sa, 0xF0);
		
		// Write data
		for (int i=0; i<SRAM_SIZE; i+=2) {
			_FLASH_WRITE(0xAAA, 0xAA);
			_FLASH_WRITE(0x555, 0x55);
			_FLASH_WRITE(0xAAA, 0xA0);
			_FLASH_WRITE(sa+i, (*(vu8 *)(AGB_SRAM+i+1)) << 8 | (*(vu8 *)(AGB_SRAM+i)));
			while (1) {
				__asm("nop");
				if (*(((vu16 *)AGB_ROM)+((sa+i)/2)) == ((*(vu8 *)(AGB_SRAM+i+1)) << 8 | (*(vu8 *)(AGB_SRAM+i)))) {
					break;
				}
			}
		}
		_FLASH_WRITE(sa, 0xF0);
		
	} else if (flash_type == 4) {
		// Erase flash sector
		_FLASH_WRITE(sa, 0xFF);
		_FLASH_WRITE(sa, 0x60);
		_FLASH_WRITE(sa, 0xD0);
		_FLASH_WRITE(sa, 0x20);
		_FLASH_WRITE(sa, 0xD0);
		while (1) {
			__asm("nop");
			if ((*(((vu16 *)AGB_ROM)+(sa/2)) & 0x80) == 0x80) {
				break;
			}
		}
		_FLASH_WRITE(sa, 0xFF);
		
		// Write data
		int c = 0;
		while (c < SRAM_SIZE) {
			_FLASH_WRITE(sa+c, 0xEA);
			while (1) {
				__asm("nop");
				if ((*(((vu16 *)AGB_ROM)+((sa+c)/2)) & 0x80) == 0x80) {
					break;
				}
			}
			_FLASH_WRITE(sa+c, 0x1FF);
			for (int i=0; i<1024; i+=2) {
				_FLASH_WRITE(sa+c+i, (*(vu8 *)(AGB_SRAM+c+i+1)) << 8 | (*(vu8 *)(AGB_SRAM+c+i)));
			}
			_FLASH_WRITE(sa+c, 0xD0);
			while (1) {
				__asm("nop");
				if ((*(((vu16 *)AGB_ROM)+((sa+c)/2)) & 0x80) == 0x80) {
					break;
				}
			}
			_FLASH_WRITE(sa+c, 0xFF);
			c += 1024;
		}
	}
	
	REG_IE = ie;
}

void flash_init() {
	
	REG_DISPCNT = 0;
	
	flash_type = get_flash_type();
	if (flash_type > 0) {
		
		// Determine the size of the flash chip by checking for ROM loops,
		// then set the SRAM storage area 0x40000 bytes before the end.
		// This is due to different sector sizes of different flash chips,
		// and should hopefully cover all cases.
		if (bytecmp(AGB_ROM+4, AGB_ROM+4+0x400000, 0x40) == 0) {
			flash_size = 0x400000;
		} else if (bytecmp(AGB_ROM+4, AGB_ROM+4+0x800000, 0x40) == 0) {
			flash_size = 0x800000;
		} else if (bytecmp(AGB_ROM+4, AGB_ROM+4+0x1000000, 0x40) == 0) {
			flash_size = 0x1000000;
		} else {
			flash_size = 0x2000000;
		}
		flash_sram_area = flash_size - 0x40000;
		
		// Finally, restore the SRAM data and proceed.
		bytecopy(AGB_SRAM, ((vu8*)AGB_ROM+flash_sram_area), SRAM_SIZE);
		
	} else { // Emulator mode?
		
		if ((*(vu32*)(AGB_ROM+0x400000-0x40000) == STATEID) || (*(vu32*)(AGB_ROM+0x400000-0x40000) == STATEID2)) {
			flash_sram_area = 0x400000-0x40000;
		} else if ((*(vu32*)(AGB_ROM+0x800000-0x40000) == STATEID) || (*(vu32*)(AGB_ROM+0x800000-0x40000) == STATEID2)) {
			flash_sram_area = 0x800000-0x40000;
		} else if ((*(vu32*)(AGB_ROM+0x1000000-0x40000) == STATEID) || (*(vu32*)(AGB_ROM+0x1000000-0x40000) == STATEID2)) {
			flash_sram_area = 0x1000000-0x40000;
		} else if ((*(vu32*)(AGB_ROM+0x2000000-0x40000) == STATEID) || (*(vu32*)(AGB_ROM+0x2000000-0x40000) == STATEID2)) {
			flash_sram_area = 0x2000000-0x40000;
		}
		
		if (flash_sram_area != 0) {
			bytecopy(AGB_SRAM, ((vu8*)AGB_ROM+flash_sram_area), SRAM_SIZE);
		}
	}
	
}

#include "bn_core.h"
#include "bn_timer.h"
#include "bn_timers.h"
#include "../../butano/src/bn_hdma_manager.h"
#include "../../butano/src/bn_link_manager.h"
#include "../../butano/src/bn_gpio_manager.h"
#include "../../butano/src/bn_audio_manager.h"
#include "../../butano/src/bn_memory_manager.h"
#include "../../butano/src/bn_display_manager.h"
#include "../../butano/src/bn_hblank_effects_manager.h"
#include "../../butano/hw/include/bn_hw_core.h"

void write_sram_to_flash() {
	if (flash_type != 0) {
		bn::gpio_manager::sleep();
		bn::hdma_manager::disable();
		bn::audio_manager::disable();
		bn::link_manager::disable();
		bn::hblank_effects_manager::disable();
		flash_write(flash_type, flash_sram_area);
		bn::hblank_effects_manager::enable();
		bn::link_manager::enable();
		bn::audio_manager::enable();
		bn::hdma_manager::enable();
		bn::hw::core::wait_for_vblank();
		bn::gpio_manager::wake_up();
	}
}
