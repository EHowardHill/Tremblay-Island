#ifndef BN_REGULAR_BG_ITEMS_TC_1_H
#define BN_REGULAR_BG_ITEMS_TC_1_H

#include "bn_regular_bg_item.h"

//{{BLOCK(tc_1_bn_graphics)

//======================================================================
//
//	tc_1_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 374 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 11968 + 2048 = 14048
//
//	Time-stamp: 2022-03-10, 17:41:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TC_1_BN_GRAPHICS_H
#define GRIT_TC_1_BN_GRAPHICS_H

#define tc_1_bn_graphicsTilesLen 11968
extern const bn::tile tc_1_bn_graphicsTiles[bn::max(2992 / 8, 1)];

#define tc_1_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell tc_1_bn_graphicsMap[1024];

#define tc_1_bn_graphicsPalLen 32
extern const bn::color tc_1_bn_graphicsPal[16];

#endif // GRIT_TC_1_BN_GRAPHICS_H

//}}BLOCK(tc_1_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item tc_1(
            regular_bg_tiles_item(span<const tile>(tc_1_bn_graphicsTiles, 374), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(tc_1_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(tc_1_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

