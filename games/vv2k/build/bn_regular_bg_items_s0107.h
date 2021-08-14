#ifndef BN_REGULAR_BG_ITEMS_S0107_H
#define BN_REGULAR_BG_ITEMS_S0107_H

#include "bn_regular_bg_item.h"

//{{BLOCK(s0107_bn_graphics)

//======================================================================
//
//	s0107_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 590 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 18880 + 2048 = 20960
//
//	Time-stamp: 2021-08-14, 05:35:16
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_S0107_BN_GRAPHICS_H
#define GRIT_S0107_BN_GRAPHICS_H

#define s0107_bn_graphicsTilesLen 18880
extern const bn::tile s0107_bn_graphicsTiles[bn::max(4720 / 8, 1)];

#define s0107_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell s0107_bn_graphicsMap[1024];

#define s0107_bn_graphicsPalLen 32
extern const bn::color s0107_bn_graphicsPal[16];

#endif // GRIT_S0107_BN_GRAPHICS_H

//}}BLOCK(s0107_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item s0107(
            regular_bg_tiles_item(span<const tile>(s0107_bn_graphicsTiles, 590), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(s0107_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(s0107_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

