#ifndef BN_REGULAR_BG_ITEMS_GARDEN_BG_H
#define BN_REGULAR_BG_ITEMS_GARDEN_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(garden_bg_bn_graphics)

//======================================================================
//
//	garden_bg_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 349 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 11168 + 2048 = 13248
//
//	Time-stamp: 2022-03-28, 02:39:20
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GARDEN_BG_BN_GRAPHICS_H
#define GRIT_GARDEN_BG_BN_GRAPHICS_H

#define garden_bg_bn_graphicsTilesLen 11168
extern const bn::tile garden_bg_bn_graphicsTiles[bn::max(2792 / 8, 1)];

#define garden_bg_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell garden_bg_bn_graphicsMap[1024];

#define garden_bg_bn_graphicsPalLen 32
extern const bn::color garden_bg_bn_graphicsPal[16];

#endif // GRIT_GARDEN_BG_BN_GRAPHICS_H

//}}BLOCK(garden_bg_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item garden_bg(
            regular_bg_tiles_item(span<const tile>(garden_bg_bn_graphicsTiles, 349), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(garden_bg_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(garden_bg_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

