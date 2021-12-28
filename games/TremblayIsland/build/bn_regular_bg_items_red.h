#ifndef BN_REGULAR_BG_ITEMS_RED_H
#define BN_REGULAR_BG_ITEMS_RED_H

#include "bn_regular_bg_item.h"

//{{BLOCK(red_bn_graphics)

//======================================================================
//
//	red_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 341 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 10912 + 2048 = 12992
//
//	Time-stamp: 2021-11-28, 00:05:42
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_RED_BN_GRAPHICS_H
#define GRIT_RED_BN_GRAPHICS_H

#define red_bn_graphicsTilesLen 10912
extern const bn::tile red_bn_graphicsTiles[bn::max(2728 / 8, 1)];

#define red_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell red_bn_graphicsMap[1024];

#define red_bn_graphicsPalLen 32
extern const bn::color red_bn_graphicsPal[16];

#endif // GRIT_RED_BN_GRAPHICS_H

//}}BLOCK(red_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item red(
            regular_bg_tiles_item(span<const tile>(red_bn_graphicsTiles, 341), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(red_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(red_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

