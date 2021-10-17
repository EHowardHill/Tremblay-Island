#ifndef BN_REGULAR_BG_ITEMS_TILES_H
#define BN_REGULAR_BG_ITEMS_TILES_H

#include "bn_regular_bg_item.h"

//{{BLOCK(tiles_bn_graphics)

//======================================================================
//
//	tiles_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 7 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 224 + 2048 = 2304
//
//	Time-stamp: 2021-10-06, 23:21:51
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TILES_BN_GRAPHICS_H
#define GRIT_TILES_BN_GRAPHICS_H

#define tiles_bn_graphicsTilesLen 224
extern const bn::tile tiles_bn_graphicsTiles[bn::max(56 / 8, 1)];

#define tiles_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell tiles_bn_graphicsMap[1024];

#define tiles_bn_graphicsPalLen 32
extern const bn::color tiles_bn_graphicsPal[16];

#endif // GRIT_TILES_BN_GRAPHICS_H

//}}BLOCK(tiles_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item tiles(
            regular_bg_tiles_item(span<const tile>(tiles_bn_graphicsTiles, 7), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(tiles_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(tiles_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

