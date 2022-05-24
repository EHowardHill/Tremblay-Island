#ifndef BN_REGULAR_BG_ITEMS_TITLEBACKGROUND_H
#define BN_REGULAR_BG_ITEMS_TITLEBACKGROUND_H

#include "bn_regular_bg_item.h"

//{{BLOCK(titlebackground_bn_graphics)

//======================================================================
//
//	titlebackground_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 541 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 17312 + 2048 = 19392
//
//	Time-stamp: 2022-05-23, 22:08:24
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.18
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TITLEBACKGROUND_BN_GRAPHICS_H
#define GRIT_TITLEBACKGROUND_BN_GRAPHICS_H

#define titlebackground_bn_graphicsTilesLen 17312
extern const bn::tile titlebackground_bn_graphicsTiles[bn::max(4328 / 8, 1)];

#define titlebackground_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell titlebackground_bn_graphicsMap[1024];

#define titlebackground_bn_graphicsPalLen 32
extern const bn::color titlebackground_bn_graphicsPal[16];

#endif // GRIT_TITLEBACKGROUND_BN_GRAPHICS_H

//}}BLOCK(titlebackground_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item titlebackground(
            regular_bg_tiles_item(span<const tile>(titlebackground_bn_graphicsTiles, 541), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(titlebackground_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(titlebackground_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

