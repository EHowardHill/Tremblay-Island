#ifndef BN_REGULAR_BG_ITEMS_GREEN_H
#define BN_REGULAR_BG_ITEMS_GREEN_H

#include "bn_regular_bg_item.h"

//{{BLOCK(green_bn_graphics)

//======================================================================
//
//	green_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 70 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 2240 + 2048 = 4320
//
//	Time-stamp: 2022-01-22, 04:49:14
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GREEN_BN_GRAPHICS_H
#define GRIT_GREEN_BN_GRAPHICS_H

#define green_bn_graphicsTilesLen 2240
extern const bn::tile green_bn_graphicsTiles[bn::max(560 / 8, 1)];

#define green_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell green_bn_graphicsMap[1024];

#define green_bn_graphicsPalLen 32
extern const bn::color green_bn_graphicsPal[16];

#endif // GRIT_GREEN_BN_GRAPHICS_H

//}}BLOCK(green_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item green(
            regular_bg_tiles_item(span<const tile>(green_bn_graphicsTiles, 70), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(green_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(green_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

