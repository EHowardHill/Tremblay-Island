#ifndef BN_SPRITE_ITEMS_CHOP_BAR_H
#define BN_SPRITE_ITEMS_CHOP_BAR_H

#include "bn_sprite_item.h"

//{{BLOCK(chop_bar_bn_graphics)

//======================================================================
//
//	chop_bar_bn_graphics, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2022-01-22, 04:49:13
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CHOP_BAR_BN_GRAPHICS_H
#define GRIT_CHOP_BAR_BN_GRAPHICS_H

#define chop_bar_bn_graphicsTilesLen 128
extern const bn::tile chop_bar_bn_graphicsTiles[bn::max(32 / 8, 1)];

#define chop_bar_bn_graphicsPalLen 32
extern const bn::color chop_bar_bn_graphicsPal[16];

#endif // GRIT_CHOP_BAR_BN_GRAPHICS_H

//}}BLOCK(chop_bar_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item chop_bar(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(chop_bar_bn_graphicsTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(chop_bar_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

