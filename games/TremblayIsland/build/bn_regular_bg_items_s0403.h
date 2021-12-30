#ifndef BN_REGULAR_BG_ITEMS_S0403_H
#define BN_REGULAR_BG_ITEMS_S0403_H

#include "bn_regular_bg_item.h"

//{{BLOCK(s0403_bn_graphics)

//======================================================================
//
//	s0403_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 576 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 18432 + 2048 = 20512
//
//	Time-stamp: 2021-12-30, 07:43:04
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_S0403_BN_GRAPHICS_H
#define GRIT_S0403_BN_GRAPHICS_H

#define s0403_bn_graphicsTilesLen 18432
extern const bn::tile s0403_bn_graphicsTiles[bn::max(4608 / 8, 1)];

#define s0403_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell s0403_bn_graphicsMap[1024];

#define s0403_bn_graphicsPalLen 32
extern const bn::color s0403_bn_graphicsPal[16];

#endif // GRIT_S0403_BN_GRAPHICS_H

//}}BLOCK(s0403_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item s0403(
            regular_bg_tiles_item(span<const tile>(s0403_bn_graphicsTiles, 576), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(s0403_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(s0403_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

