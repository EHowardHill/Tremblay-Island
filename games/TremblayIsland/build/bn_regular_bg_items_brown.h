#ifndef BN_REGULAR_BG_ITEMS_BROWN_H
#define BN_REGULAR_BG_ITEMS_BROWN_H

#include "bn_regular_bg_item.h"

//{{BLOCK(brown_bn_graphics)

//======================================================================
//
//	brown_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 238 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 7616 + 2048 = 9696
//
//	Time-stamp: 2021-12-30, 07:43:02
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BROWN_BN_GRAPHICS_H
#define GRIT_BROWN_BN_GRAPHICS_H

#define brown_bn_graphicsTilesLen 7616
extern const bn::tile brown_bn_graphicsTiles[bn::max(1904 / 8, 1)];

#define brown_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell brown_bn_graphicsMap[1024];

#define brown_bn_graphicsPalLen 32
extern const bn::color brown_bn_graphicsPal[16];

#endif // GRIT_BROWN_BN_GRAPHICS_H

//}}BLOCK(brown_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item brown(
            regular_bg_tiles_item(span<const tile>(brown_bn_graphicsTiles, 238), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(brown_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(brown_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

