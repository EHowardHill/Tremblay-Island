#ifndef BN_REGULAR_BG_ITEMS_REAL_ENOKI_01_H
#define BN_REGULAR_BG_ITEMS_REAL_ENOKI_01_H

#include "bn_regular_bg_item.h"

//{{BLOCK(real_enoki_01_bn_graphics)

//======================================================================
//
//	real_enoki_01_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 65 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 2080 + 2048 = 4160
//
//	Time-stamp: 2022-03-10, 17:41:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_REAL_ENOKI_01_BN_GRAPHICS_H
#define GRIT_REAL_ENOKI_01_BN_GRAPHICS_H

#define real_enoki_01_bn_graphicsTilesLen 2080
extern const bn::tile real_enoki_01_bn_graphicsTiles[bn::max(520 / 8, 1)];

#define real_enoki_01_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell real_enoki_01_bn_graphicsMap[1024];

#define real_enoki_01_bn_graphicsPalLen 32
extern const bn::color real_enoki_01_bn_graphicsPal[16];

#endif // GRIT_REAL_ENOKI_01_BN_GRAPHICS_H

//}}BLOCK(real_enoki_01_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item real_enoki_01(
            regular_bg_tiles_item(span<const tile>(real_enoki_01_bn_graphicsTiles, 65), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(real_enoki_01_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(real_enoki_01_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

