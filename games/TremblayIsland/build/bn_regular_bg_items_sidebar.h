#ifndef BN_REGULAR_BG_ITEMS_SIDEBAR_H
#define BN_REGULAR_BG_ITEMS_SIDEBAR_H

#include "bn_regular_bg_item.h"

//{{BLOCK(sidebar_bn_graphics)

//======================================================================
//
//	sidebar_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 558 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 17856 + 2048 = 19936
//
//	Time-stamp: 2022-03-28, 02:39:25
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SIDEBAR_BN_GRAPHICS_H
#define GRIT_SIDEBAR_BN_GRAPHICS_H

#define sidebar_bn_graphicsTilesLen 17856
extern const bn::tile sidebar_bn_graphicsTiles[bn::max(4464 / 8, 1)];

#define sidebar_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell sidebar_bn_graphicsMap[1024];

#define sidebar_bn_graphicsPalLen 32
extern const bn::color sidebar_bn_graphicsPal[16];

#endif // GRIT_SIDEBAR_BN_GRAPHICS_H

//}}BLOCK(sidebar_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item sidebar(
            regular_bg_tiles_item(span<const tile>(sidebar_bn_graphicsTiles, 558), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(sidebar_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(sidebar_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

