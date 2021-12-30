#ifndef BN_REGULAR_BG_ITEMS_PC_BBSCREEN_H
#define BN_REGULAR_BG_ITEMS_PC_BBSCREEN_H

#include "bn_regular_bg_item.h"

//{{BLOCK(pc_bbscreen_bn_graphics)

//======================================================================
//
//	pc_bbscreen_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 42 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 1344 + 2048 = 3424
//
//	Time-stamp: 2021-12-30, 07:43:03
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PC_BBSCREEN_BN_GRAPHICS_H
#define GRIT_PC_BBSCREEN_BN_GRAPHICS_H

#define pc_bbscreen_bn_graphicsTilesLen 1344
extern const bn::tile pc_bbscreen_bn_graphicsTiles[bn::max(336 / 8, 1)];

#define pc_bbscreen_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell pc_bbscreen_bn_graphicsMap[1024];

#define pc_bbscreen_bn_graphicsPalLen 32
extern const bn::color pc_bbscreen_bn_graphicsPal[16];

#endif // GRIT_PC_BBSCREEN_BN_GRAPHICS_H

//}}BLOCK(pc_bbscreen_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item pc_bbscreen(
            regular_bg_tiles_item(span<const tile>(pc_bbscreen_bn_graphicsTiles, 42), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(pc_bbscreen_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(pc_bbscreen_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

