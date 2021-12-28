#ifndef BN_REGULAR_BG_ITEMS_CRUZ_02_H
#define BN_REGULAR_BG_ITEMS_CRUZ_02_H

#include "bn_regular_bg_item.h"

//{{BLOCK(cruz_02_bn_graphics)

//======================================================================
//
//	cruz_02_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 510 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 16320 + 2048 = 18400
//
//	Time-stamp: 2021-12-20, 05:50:27
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CRUZ_02_BN_GRAPHICS_H
#define GRIT_CRUZ_02_BN_GRAPHICS_H

#define cruz_02_bn_graphicsTilesLen 16320
extern const bn::tile cruz_02_bn_graphicsTiles[bn::max(4080 / 8, 1)];

#define cruz_02_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell cruz_02_bn_graphicsMap[1024];

#define cruz_02_bn_graphicsPalLen 32
extern const bn::color cruz_02_bn_graphicsPal[16];

#endif // GRIT_CRUZ_02_BN_GRAPHICS_H

//}}BLOCK(cruz_02_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item cruz_02(
            regular_bg_tiles_item(span<const tile>(cruz_02_bn_graphicsTiles, 510), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(cruz_02_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(cruz_02_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

