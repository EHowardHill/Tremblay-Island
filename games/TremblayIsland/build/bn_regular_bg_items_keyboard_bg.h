#ifndef BN_REGULAR_BG_ITEMS_KEYBOARD_BG_H
#define BN_REGULAR_BG_ITEMS_KEYBOARD_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(keyboard_bg_bn_graphics)

//======================================================================
//
//	keyboard_bg_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 310 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 9920 + 2048 = 12000
//
//	Time-stamp: 2022-03-21, 06:46:34
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_KEYBOARD_BG_BN_GRAPHICS_H
#define GRIT_KEYBOARD_BG_BN_GRAPHICS_H

#define keyboard_bg_bn_graphicsTilesLen 9920
extern const bn::tile keyboard_bg_bn_graphicsTiles[bn::max(2480 / 8, 1)];

#define keyboard_bg_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell keyboard_bg_bn_graphicsMap[1024];

#define keyboard_bg_bn_graphicsPalLen 32
extern const bn::color keyboard_bg_bn_graphicsPal[16];

#endif // GRIT_KEYBOARD_BG_BN_GRAPHICS_H

//}}BLOCK(keyboard_bg_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item keyboard_bg(
            regular_bg_tiles_item(span<const tile>(keyboard_bg_bn_graphicsTiles, 310), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(keyboard_bg_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(keyboard_bg_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

