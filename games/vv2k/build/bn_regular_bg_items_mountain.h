#ifndef BN_REGULAR_BG_ITEMS_MOUNTAIN_H
#define BN_REGULAR_BG_ITEMS_MOUNTAIN_H

#include "bn_regular_bg_item.h"

//{{BLOCK(mountain_bn_graphics)

//======================================================================
//
//	mountain_bn_graphics, 256x256@8, 
//	+ palette 48 entries, not compressed
//	+ 815 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 96 + 52160 + 2048 = 54304
//
//	Time-stamp: 2021-08-25, 02:05:56
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MOUNTAIN_BN_GRAPHICS_H
#define GRIT_MOUNTAIN_BN_GRAPHICS_H

#define mountain_bn_graphicsTilesLen 52160
extern const bn::tile mountain_bn_graphicsTiles[bn::max(13040 / 8, 1)];

#define mountain_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell mountain_bn_graphicsMap[1024];

#define mountain_bn_graphicsPalLen 96
extern const bn::color mountain_bn_graphicsPal[48];

#endif // GRIT_MOUNTAIN_BN_GRAPHICS_H

//}}BLOCK(mountain_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item mountain(
            regular_bg_tiles_item(span<const tile>(mountain_bn_graphicsTiles, 1630), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(mountain_bn_graphicsPal, 48), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(mountain_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

