#ifndef BN_REGULAR_BG_ITEMS_S0917_H
#define BN_REGULAR_BG_ITEMS_S0917_H

#include "bn_regular_bg_item.h"

//{{BLOCK(s0917_bn_graphics)

//======================================================================
//
//	s0917_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 269 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 8608 + 2048 = 10688
//
//	Time-stamp: 2022-03-10, 17:41:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_S0917_BN_GRAPHICS_H
#define GRIT_S0917_BN_GRAPHICS_H

#define s0917_bn_graphicsTilesLen 8608
extern const bn::tile s0917_bn_graphicsTiles[bn::max(2152 / 8, 1)];

#define s0917_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell s0917_bn_graphicsMap[1024];

#define s0917_bn_graphicsPalLen 32
extern const bn::color s0917_bn_graphicsPal[16];

#endif // GRIT_S0917_BN_GRAPHICS_H

//}}BLOCK(s0917_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item s0917(
            regular_bg_tiles_item(span<const tile>(s0917_bn_graphicsTiles, 269), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(s0917_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(s0917_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

