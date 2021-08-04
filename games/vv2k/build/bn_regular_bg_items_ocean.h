#ifndef BN_REGULAR_BG_ITEMS_OCEAN_H
#define BN_REGULAR_BG_ITEMS_OCEAN_H

#include "bn_regular_bg_item.h"

//{{BLOCK(ocean_bn_graphics)

//======================================================================
//
//	ocean_bn_graphics, 256x256@8, 
//	+ palette 48 entries, not compressed
//	+ 551 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 96 + 35264 + 2048 = 37408
//
//	Time-stamp: 2021-08-01, 20:56:56
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_OCEAN_BN_GRAPHICS_H
#define GRIT_OCEAN_BN_GRAPHICS_H

#define ocean_bn_graphicsTilesLen 35264
extern const bn::tile ocean_bn_graphicsTiles[bn::max(8816 / 8, 1)];

#define ocean_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell ocean_bn_graphicsMap[1024];

#define ocean_bn_graphicsPalLen 96
extern const bn::color ocean_bn_graphicsPal[48];

#endif // GRIT_OCEAN_BN_GRAPHICS_H

//}}BLOCK(ocean_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item ocean(
            regular_bg_tiles_item(span<const tile>(ocean_bn_graphicsTiles, 1102), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(ocean_bn_graphicsPal, 48), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(ocean_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

