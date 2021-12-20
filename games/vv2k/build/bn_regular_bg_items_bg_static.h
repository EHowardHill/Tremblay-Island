#ifndef BN_REGULAR_BG_ITEMS_BG_STATIC_H
#define BN_REGULAR_BG_ITEMS_BG_STATIC_H

#include "bn_regular_bg_item.h"

//{{BLOCK(bg_static_bn_graphics)

//======================================================================
//
//	bg_static_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 1021 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 32672 + 2048 = 34752
//
//	Time-stamp: 2021-12-07, 20:12:58
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BG_STATIC_BN_GRAPHICS_H
#define GRIT_BG_STATIC_BN_GRAPHICS_H

#define bg_static_bn_graphicsTilesLen 32672
extern const bn::tile bg_static_bn_graphicsTiles[bn::max(8168 / 8, 1)];

#define bg_static_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell bg_static_bn_graphicsMap[1024];

#define bg_static_bn_graphicsPalLen 32
extern const bn::color bg_static_bn_graphicsPal[16];

#endif // GRIT_BG_STATIC_BN_GRAPHICS_H

//}}BLOCK(bg_static_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item bg_static(
            regular_bg_tiles_item(span<const tile>(bg_static_bn_graphicsTiles, 1021), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(bg_static_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(bg_static_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif
