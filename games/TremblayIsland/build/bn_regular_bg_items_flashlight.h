#ifndef BN_REGULAR_BG_ITEMS_FLASHLIGHT_H
#define BN_REGULAR_BG_ITEMS_FLASHLIGHT_H

#include "bn_regular_bg_item.h"

//{{BLOCK(flashlight_bn_graphics)

//======================================================================
//
//	flashlight_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 531 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 16992 + 2048 = 19072
//
//	Time-stamp: 2021-12-30, 07:43:03
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FLASHLIGHT_BN_GRAPHICS_H
#define GRIT_FLASHLIGHT_BN_GRAPHICS_H

#define flashlight_bn_graphicsTilesLen 16992
extern const bn::tile flashlight_bn_graphicsTiles[bn::max(4248 / 8, 1)];

#define flashlight_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell flashlight_bn_graphicsMap[1024];

#define flashlight_bn_graphicsPalLen 32
extern const bn::color flashlight_bn_graphicsPal[16];

#endif // GRIT_FLASHLIGHT_BN_GRAPHICS_H

//}}BLOCK(flashlight_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item flashlight(
            regular_bg_tiles_item(span<const tile>(flashlight_bn_graphicsTiles, 531), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(flashlight_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(flashlight_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

