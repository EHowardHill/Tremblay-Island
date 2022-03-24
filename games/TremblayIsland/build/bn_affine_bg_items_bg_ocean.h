#ifndef BN_AFFINE_BG_ITEMS_BG_OCEAN_H
#define BN_AFFINE_BG_ITEMS_BG_OCEAN_H

#include "bn_affine_bg_item.h"

//{{BLOCK(bg_ocean_bn_graphics)

//======================================================================
//
//	bg_ocean_bn_graphics, 256x256@8, 
//	+ palette 16 entries, not compressed
//	+ 253 tiles (t reduced) not compressed
//	+ affine map, not compressed, 32x32 
//	Total size: 32 + 16192 + 1024 = 17248
//
//	Time-stamp: 2022-03-24, 04:15:53
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BG_OCEAN_BN_GRAPHICS_H
#define GRIT_BG_OCEAN_BN_GRAPHICS_H

#define bg_ocean_bn_graphicsTilesLen 16192
extern const bn::tile bg_ocean_bn_graphicsTiles[bn::max(4048 / 8, 1)];

#define bg_ocean_bn_graphicsMapLen 1024
extern const bn::affine_bg_map_cell bg_ocean_bn_graphicsMap[1024];

#define bg_ocean_bn_graphicsPalLen 32
extern const bn::color bg_ocean_bn_graphicsPal[16];

#endif // GRIT_BG_OCEAN_BN_GRAPHICS_H

//}}BLOCK(bg_ocean_bn_graphics)

namespace bn::affine_bg_items
{
    constexpr inline affine_bg_item bg_ocean(
            affine_bg_tiles_item(span<const tile>(bg_ocean_bn_graphicsTiles, 506), compression_type::NONE), 
            bg_palette_item(span<const color>(bg_ocean_bn_graphicsPal, 16), bpp_mode::BPP_8, compression_type::NONE),
            affine_bg_map_item(bg_ocean_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

