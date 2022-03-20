#ifndef BN_REGULAR_BG_ITEMS_S1103_H
#define BN_REGULAR_BG_ITEMS_S1103_H

#include "bn_regular_bg_item.h"

//{{BLOCK(s1103_bn_graphics)

//======================================================================
//
//	s1103_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 601 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 19232 + 2048 = 21312
//
//	Time-stamp: 2022-03-10, 17:41:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_S1103_BN_GRAPHICS_H
#define GRIT_S1103_BN_GRAPHICS_H

#define s1103_bn_graphicsTilesLen 19232
extern const bn::tile s1103_bn_graphicsTiles[bn::max(4808 / 8, 1)];

#define s1103_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell s1103_bn_graphicsMap[1024];

#define s1103_bn_graphicsPalLen 32
extern const bn::color s1103_bn_graphicsPal[16];

#endif // GRIT_S1103_BN_GRAPHICS_H

//}}BLOCK(s1103_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item s1103(
            regular_bg_tiles_item(span<const tile>(s1103_bn_graphicsTiles, 601), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(s1103_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(s1103_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

