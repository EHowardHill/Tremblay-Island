#ifndef BN_REGULAR_BG_ITEMS_S0204_H
#define BN_REGULAR_BG_ITEMS_S0204_H

#include "bn_regular_bg_item.h"

//{{BLOCK(s0204_bn_graphics)

//======================================================================
//
//	s0204_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 601 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 19232 + 2048 = 21312
//
//	Time-stamp: 2022-03-28, 02:39:22
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_S0204_BN_GRAPHICS_H
#define GRIT_S0204_BN_GRAPHICS_H

#define s0204_bn_graphicsTilesLen 19232
extern const bn::tile s0204_bn_graphicsTiles[bn::max(4808 / 8, 1)];

#define s0204_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell s0204_bn_graphicsMap[1024];

#define s0204_bn_graphicsPalLen 32
extern const bn::color s0204_bn_graphicsPal[16];

#endif // GRIT_S0204_BN_GRAPHICS_H

//}}BLOCK(s0204_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item s0204(
            regular_bg_tiles_item(span<const tile>(s0204_bn_graphicsTiles, 601), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(s0204_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(s0204_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

