#ifndef BN_REGULAR_BG_ITEMS_CASTLE_H
#define BN_REGULAR_BG_ITEMS_CASTLE_H

#include "bn_regular_bg_item.h"

//{{BLOCK(castle_bn_graphics)

//======================================================================
//
//	castle_bn_graphics, 256x256@8, 
//	+ palette 48 entries, not compressed
//	+ 282 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 96 + 18048 + 2048 = 20192
//
//	Time-stamp: 2021-08-25, 02:05:55
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CASTLE_BN_GRAPHICS_H
#define GRIT_CASTLE_BN_GRAPHICS_H

#define castle_bn_graphicsTilesLen 18048
extern const bn::tile castle_bn_graphicsTiles[bn::max(4512 / 8, 1)];

#define castle_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell castle_bn_graphicsMap[1024];

#define castle_bn_graphicsPalLen 96
extern const bn::color castle_bn_graphicsPal[48];

#endif // GRIT_CASTLE_BN_GRAPHICS_H

//}}BLOCK(castle_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item castle(
            regular_bg_tiles_item(span<const tile>(castle_bn_graphicsTiles, 564), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(castle_bn_graphicsPal, 48), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(castle_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

