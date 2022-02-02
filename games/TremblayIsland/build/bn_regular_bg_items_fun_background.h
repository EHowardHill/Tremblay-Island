#ifndef BN_REGULAR_BG_ITEMS_FUN_BACKGROUND_H
#define BN_REGULAR_BG_ITEMS_FUN_BACKGROUND_H

#include "bn_regular_bg_item.h"

//{{BLOCK(fun_background_bn_graphics)

//======================================================================
//
//	fun_background_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 515 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 16480 + 2048 = 18560
//
//	Time-stamp: 2022-01-26, 07:36:09
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FUN_BACKGROUND_BN_GRAPHICS_H
#define GRIT_FUN_BACKGROUND_BN_GRAPHICS_H

#define fun_background_bn_graphicsTilesLen 16480
extern const bn::tile fun_background_bn_graphicsTiles[bn::max(4120 / 8, 1)];

#define fun_background_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell fun_background_bn_graphicsMap[1024];

#define fun_background_bn_graphicsPalLen 32
extern const bn::color fun_background_bn_graphicsPal[16];

#endif // GRIT_FUN_BACKGROUND_BN_GRAPHICS_H

//}}BLOCK(fun_background_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item fun_background(
            regular_bg_tiles_item(span<const tile>(fun_background_bn_graphicsTiles, 515), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(fun_background_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(fun_background_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

