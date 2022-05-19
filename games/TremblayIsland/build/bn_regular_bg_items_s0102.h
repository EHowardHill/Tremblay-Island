#ifndef BN_REGULAR_BG_ITEMS_S0102_H
#define BN_REGULAR_BG_ITEMS_S0102_H

#include "bn_regular_bg_item.h"

//{{BLOCK(s0102_bn_graphics)

//======================================================================
//
//	s0102_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 627 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 20064 + 2048 = 22144
//
//	Time-stamp: 2022-05-17, 22:36:30
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.18
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_S0102_BN_GRAPHICS_H
#define GRIT_S0102_BN_GRAPHICS_H

#define s0102_bn_graphicsTilesLen 20064
extern const bn::tile s0102_bn_graphicsTiles[bn::max(5016 / 8, 1)];

#define s0102_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell s0102_bn_graphicsMap[1024];

#define s0102_bn_graphicsPalLen 32
extern const bn::color s0102_bn_graphicsPal[16];

#endif // GRIT_S0102_BN_GRAPHICS_H

//}}BLOCK(s0102_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item s0102(
            regular_bg_tiles_item(span<const tile>(s0102_bn_graphicsTiles, 627), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(s0102_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(s0102_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

