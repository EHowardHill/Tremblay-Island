#ifndef BN_REGULAR_BG_ITEMS_CASTLE02_01_H
#define BN_REGULAR_BG_ITEMS_CASTLE02_01_H

#include "bn_regular_bg_item.h"

//{{BLOCK(castle02_01_bn_graphics)

//======================================================================
//
//	castle02_01_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 608 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 19456 + 2048 = 21536
//
//	Time-stamp: 2022-03-10, 17:41:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CASTLE02_01_BN_GRAPHICS_H
#define GRIT_CASTLE02_01_BN_GRAPHICS_H

#define castle02_01_bn_graphicsTilesLen 19456
extern const bn::tile castle02_01_bn_graphicsTiles[bn::max(4864 / 8, 1)];

#define castle02_01_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell castle02_01_bn_graphicsMap[1024];

#define castle02_01_bn_graphicsPalLen 32
extern const bn::color castle02_01_bn_graphicsPal[16];

#endif // GRIT_CASTLE02_01_BN_GRAPHICS_H

//}}BLOCK(castle02_01_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item castle02_01(
            regular_bg_tiles_item(span<const tile>(castle02_01_bn_graphicsTiles, 608), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(castle02_01_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(castle02_01_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

