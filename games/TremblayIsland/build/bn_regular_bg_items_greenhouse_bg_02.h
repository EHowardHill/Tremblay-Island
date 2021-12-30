#ifndef BN_REGULAR_BG_ITEMS_GREENHOUSE_BG_02_H
#define BN_REGULAR_BG_ITEMS_GREENHOUSE_BG_02_H

#include "bn_regular_bg_item.h"

//{{BLOCK(greenhouse_bg_02_bn_graphics)

//======================================================================
//
//	greenhouse_bg_02_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 908 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 29056 + 2048 = 31136
//
//	Time-stamp: 2021-12-30, 07:43:03
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GREENHOUSE_BG_02_BN_GRAPHICS_H
#define GRIT_GREENHOUSE_BG_02_BN_GRAPHICS_H

#define greenhouse_bg_02_bn_graphicsTilesLen 29056
extern const bn::tile greenhouse_bg_02_bn_graphicsTiles[bn::max(7264 / 8, 1)];

#define greenhouse_bg_02_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell greenhouse_bg_02_bn_graphicsMap[1024];

#define greenhouse_bg_02_bn_graphicsPalLen 32
extern const bn::color greenhouse_bg_02_bn_graphicsPal[16];

#endif // GRIT_GREENHOUSE_BG_02_BN_GRAPHICS_H

//}}BLOCK(greenhouse_bg_02_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item greenhouse_bg_02(
            regular_bg_tiles_item(span<const tile>(greenhouse_bg_02_bn_graphicsTiles, 908), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(greenhouse_bg_02_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(greenhouse_bg_02_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

