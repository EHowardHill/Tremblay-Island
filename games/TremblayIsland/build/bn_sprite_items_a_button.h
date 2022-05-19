#ifndef BN_SPRITE_ITEMS_A_BUTTON_H
#define BN_SPRITE_ITEMS_A_BUTTON_H

#include "bn_sprite_item.h"

//{{BLOCK(a_button_bn_graphics)

//======================================================================
//
//	a_button_bn_graphics, 64x128@4, 
//	+ palette 16 entries, not compressed
//	+ 128 tiles not compressed
//	Total size: 32 + 4096 = 4128
//
//	Time-stamp: 2022-05-18, 00:37:27
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.18
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_A_BUTTON_BN_GRAPHICS_H
#define GRIT_A_BUTTON_BN_GRAPHICS_H

#define a_button_bn_graphicsTilesLen 4096
extern const bn::tile a_button_bn_graphicsTiles[bn::max(1024 / 8, 1)];

#define a_button_bn_graphicsPalLen 32
extern const bn::color a_button_bn_graphicsPal[16];

#endif // GRIT_A_BUTTON_BN_GRAPHICS_H

//}}BLOCK(a_button_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item a_button(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(a_button_bn_graphicsTiles, 128), bpp_mode::BPP_4, compression_type::NONE, 2), 
            sprite_palette_item(span<const color>(a_button_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

