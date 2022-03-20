#ifndef BN_REGULAR_BG_ITEMS_VELVET_H
#define BN_REGULAR_BG_ITEMS_VELVET_H

#include "bn_regular_bg_item.h"

//{{BLOCK(velvet_bn_graphics)

//======================================================================
//
//	velvet_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 505 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 16160 + 2048 = 18240
//
//	Time-stamp: 2022-03-10, 17:41:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_VELVET_BN_GRAPHICS_H
#define GRIT_VELVET_BN_GRAPHICS_H

#define velvet_bn_graphicsTilesLen 16160
extern const bn::tile velvet_bn_graphicsTiles[bn::max(4040 / 8, 1)];

#define velvet_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell velvet_bn_graphicsMap[1024];

#define velvet_bn_graphicsPalLen 32
extern const bn::color velvet_bn_graphicsPal[16];

#endif // GRIT_VELVET_BN_GRAPHICS_H

//}}BLOCK(velvet_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item velvet(
            regular_bg_tiles_item(span<const tile>(velvet_bn_graphicsTiles, 505), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(velvet_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(velvet_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

