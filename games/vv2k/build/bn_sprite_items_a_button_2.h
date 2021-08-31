#ifndef BN_SPRITE_ITEMS_A_BUTTON_2_H
#define BN_SPRITE_ITEMS_A_BUTTON_2_H

#include "bn_sprite_item.h"

//{{BLOCK(a_button_2_bn_graphics)

//======================================================================
//
//	a_button_2_bn_graphics, 32x32@4, 
//	+ palette 16 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 32 + 512 = 544
//
//	Time-stamp: 2021-08-31, 03:52:08
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_A_BUTTON_2_BN_GRAPHICS_H
#define GRIT_A_BUTTON_2_BN_GRAPHICS_H

#define a_button_2_bn_graphicsTilesLen 512
extern const bn::tile a_button_2_bn_graphicsTiles[bn::max(128 / 8, 1)];

#define a_button_2_bn_graphicsPalLen 32
extern const bn::color a_button_2_bn_graphicsPal[16];

#endif // GRIT_A_BUTTON_2_BN_GRAPHICS_H

//}}BLOCK(a_button_2_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item a_button_2(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(a_button_2_bn_graphicsTiles, 16), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(a_button_2_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

