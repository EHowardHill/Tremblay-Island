#ifndef BN_REGULAR_BG_ITEMS_INTRO_FINAL_1_H
#define BN_REGULAR_BG_ITEMS_INTRO_FINAL_1_H

#include "bn_regular_bg_item.h"

//{{BLOCK(intro_final_1_bn_graphics)

//======================================================================
//
//	intro_final_1_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 601 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 19232 + 2048 = 21312
//
//	Time-stamp: 2022-01-26, 07:36:10
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_INTRO_FINAL_1_BN_GRAPHICS_H
#define GRIT_INTRO_FINAL_1_BN_GRAPHICS_H

#define intro_final_1_bn_graphicsTilesLen 19232
extern const bn::tile intro_final_1_bn_graphicsTiles[bn::max(4808 / 8, 1)];

#define intro_final_1_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell intro_final_1_bn_graphicsMap[1024];

#define intro_final_1_bn_graphicsPalLen 32
extern const bn::color intro_final_1_bn_graphicsPal[16];

#endif // GRIT_INTRO_FINAL_1_BN_GRAPHICS_H

//}}BLOCK(intro_final_1_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item intro_final_1(
            regular_bg_tiles_item(span<const tile>(intro_final_1_bn_graphicsTiles, 601), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(intro_final_1_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(intro_final_1_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

