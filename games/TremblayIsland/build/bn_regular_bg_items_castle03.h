#ifndef BN_REGULAR_BG_ITEMS_CASTLE03_H
#define BN_REGULAR_BG_ITEMS_CASTLE03_H

#include "bn_regular_bg_item.h"

//{{BLOCK(castle03_bn_graphics)

//======================================================================
//
//	castle03_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 609 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 19488 + 2048 = 21568
//
//	Time-stamp: 2022-03-21, 06:46:33
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CASTLE03_BN_GRAPHICS_H
#define GRIT_CASTLE03_BN_GRAPHICS_H

#define castle03_bn_graphicsTilesLen 19488
extern const bn::tile castle03_bn_graphicsTiles[bn::max(4872 / 8, 1)];

#define castle03_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell castle03_bn_graphicsMap[1024];

#define castle03_bn_graphicsPalLen 32
extern const bn::color castle03_bn_graphicsPal[16];

#endif // GRIT_CASTLE03_BN_GRAPHICS_H

//}}BLOCK(castle03_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item castle03(
            regular_bg_tiles_item(span<const tile>(castle03_bn_graphicsTiles, 609), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(castle03_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(castle03_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

