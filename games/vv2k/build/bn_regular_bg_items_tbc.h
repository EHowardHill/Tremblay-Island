#ifndef BN_REGULAR_BG_ITEMS_TBC_H
#define BN_REGULAR_BG_ITEMS_TBC_H

#include "bn_regular_bg_item.h"

//{{BLOCK(tbc_bn_graphics)

//======================================================================
//
//	tbc_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 101 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 3232 + 2048 = 5312
//
//	Time-stamp: 2021-10-26, 01:25:50
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TBC_BN_GRAPHICS_H
#define GRIT_TBC_BN_GRAPHICS_H

#define tbc_bn_graphicsTilesLen 3232
extern const bn::tile tbc_bn_graphicsTiles[bn::max(808 / 8, 1)];

#define tbc_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell tbc_bn_graphicsMap[1024];

#define tbc_bn_graphicsPalLen 32
extern const bn::color tbc_bn_graphicsPal[16];

#endif // GRIT_TBC_BN_GRAPHICS_H

//}}BLOCK(tbc_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item tbc(
            regular_bg_tiles_item(span<const tile>(tbc_bn_graphicsTiles, 101), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(tbc_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(tbc_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

