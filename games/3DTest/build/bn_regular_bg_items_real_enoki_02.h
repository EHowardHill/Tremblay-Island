#ifndef BN_REGULAR_BG_ITEMS_REAL_ENOKI_02_H
#define BN_REGULAR_BG_ITEMS_REAL_ENOKI_02_H

#include "bn_regular_bg_item.h"

//{{BLOCK(real_enoki_02_bn_graphics)

//======================================================================
//
//	real_enoki_02_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 40 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 1280 + 2048 = 3360
//
//	Time-stamp: 2022-03-10, 17:41:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_REAL_ENOKI_02_BN_GRAPHICS_H
#define GRIT_REAL_ENOKI_02_BN_GRAPHICS_H

#define real_enoki_02_bn_graphicsTilesLen 1280
extern const bn::tile real_enoki_02_bn_graphicsTiles[bn::max(320 / 8, 1)];

#define real_enoki_02_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell real_enoki_02_bn_graphicsMap[1024];

#define real_enoki_02_bn_graphicsPalLen 32
extern const bn::color real_enoki_02_bn_graphicsPal[16];

#endif // GRIT_REAL_ENOKI_02_BN_GRAPHICS_H

//}}BLOCK(real_enoki_02_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item real_enoki_02(
            regular_bg_tiles_item(span<const tile>(real_enoki_02_bn_graphicsTiles, 40), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(real_enoki_02_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(real_enoki_02_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

