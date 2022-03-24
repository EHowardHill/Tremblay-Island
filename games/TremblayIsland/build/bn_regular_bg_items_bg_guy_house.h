#ifndef BN_REGULAR_BG_ITEMS_BG_GUY_HOUSE_H
#define BN_REGULAR_BG_ITEMS_BG_GUY_HOUSE_H

#include "bn_regular_bg_item.h"

//{{BLOCK(bg_guy_house_bn_graphics)

//======================================================================
//
//	bg_guy_house_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 780 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 24960 + 2048 = 27040
//
//	Time-stamp: 2022-03-24, 04:15:53
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BG_GUY_HOUSE_BN_GRAPHICS_H
#define GRIT_BG_GUY_HOUSE_BN_GRAPHICS_H

#define bg_guy_house_bn_graphicsTilesLen 24960
extern const bn::tile bg_guy_house_bn_graphicsTiles[bn::max(6240 / 8, 1)];

#define bg_guy_house_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell bg_guy_house_bn_graphicsMap[1024];

#define bg_guy_house_bn_graphicsPalLen 32
extern const bn::color bg_guy_house_bn_graphicsPal[16];

#endif // GRIT_BG_GUY_HOUSE_BN_GRAPHICS_H

//}}BLOCK(bg_guy_house_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item bg_guy_house(
            regular_bg_tiles_item(span<const tile>(bg_guy_house_bn_graphicsTiles, 780), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(bg_guy_house_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(bg_guy_house_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

