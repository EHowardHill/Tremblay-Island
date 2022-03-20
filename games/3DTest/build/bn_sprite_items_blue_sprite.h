#ifndef BN_SPRITE_ITEMS_BLUE_SPRITE_H
#define BN_SPRITE_ITEMS_BLUE_SPRITE_H

#include "bn_sprite_item.h"

//{{BLOCK(blue_sprite_bn_graphics)

//======================================================================
//
//	blue_sprite_bn_graphics, 64x64@4, 
//	+ palette 16 entries, not compressed
//	+ 64 tiles not compressed
//	Total size: 32 + 2048 = 2080
//
//	Time-stamp: 2022-03-16, 22:13:47
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BLUE_SPRITE_BN_GRAPHICS_H
#define GRIT_BLUE_SPRITE_BN_GRAPHICS_H

#define blue_sprite_bn_graphicsTilesLen 2048
extern const bn::tile blue_sprite_bn_graphicsTiles[bn::max(512 / 8, 1)];

#define blue_sprite_bn_graphicsPalLen 32
extern const bn::color blue_sprite_bn_graphicsPal[16];

#endif // GRIT_BLUE_SPRITE_BN_GRAPHICS_H

//}}BLOCK(blue_sprite_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item blue_sprite(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(blue_sprite_bn_graphicsTiles, 64), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(blue_sprite_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

