#ifndef BN_REGULAR_BG_ITEMS_CASTLE_FLOOR_H
#define BN_REGULAR_BG_ITEMS_CASTLE_FLOOR_H

#include "bn_regular_bg_item.h"

//{{BLOCK(castle_floor_bn_graphics)

//======================================================================
//
//	castle_floor_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 503 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 16096 + 2048 = 18176
//
//	Time-stamp: 2021-08-30, 02:59:46
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CASTLE_FLOOR_BN_GRAPHICS_H
#define GRIT_CASTLE_FLOOR_BN_GRAPHICS_H

#define castle_floor_bn_graphicsTilesLen 16096
extern const bn::tile castle_floor_bn_graphicsTiles[bn::max(4024 / 8, 1)];

#define castle_floor_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell castle_floor_bn_graphicsMap[1024];

#define castle_floor_bn_graphicsPalLen 32
extern const bn::color castle_floor_bn_graphicsPal[16];

#endif // GRIT_CASTLE_FLOOR_BN_GRAPHICS_H

//}}BLOCK(castle_floor_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item castle_floor(
            regular_bg_tiles_item(span<const tile>(castle_floor_bn_graphicsTiles, 503), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(castle_floor_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(castle_floor_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

