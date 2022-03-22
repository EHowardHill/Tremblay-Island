#ifndef BN_SPRITE_ITEMS_HORIZONTAL_BAR_H
#define BN_SPRITE_ITEMS_HORIZONTAL_BAR_H

#include "bn_sprite_item.h"

//{{BLOCK(horizontal_bar_bn_graphics)

//======================================================================
//
//	horizontal_bar_bn_graphics, 8x8@4, 
//	+ palette 16 entries, not compressed
//	+ 1 tiles not compressed
//	Total size: 32 + 32 = 64
//
//	Time-stamp: 2022-03-21, 06:46:33
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_HORIZONTAL_BAR_BN_GRAPHICS_H
#define GRIT_HORIZONTAL_BAR_BN_GRAPHICS_H

#define horizontal_bar_bn_graphicsTilesLen 32
extern const bn::tile horizontal_bar_bn_graphicsTiles[bn::max(8 / 8, 1)];

#define horizontal_bar_bn_graphicsPalLen 32
extern const bn::color horizontal_bar_bn_graphicsPal[16];

#endif // GRIT_HORIZONTAL_BAR_BN_GRAPHICS_H

//}}BLOCK(horizontal_bar_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item horizontal_bar(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(horizontal_bar_bn_graphicsTiles, 1), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(horizontal_bar_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

