#ifndef BN_SPRITE_ITEMS_ENOKI_WALKING_SPRING_H
#define BN_SPRITE_ITEMS_ENOKI_WALKING_SPRING_H

#include "bn_sprite_item.h"

//{{BLOCK(enoki_walking_spring_bn_graphics)

//======================================================================
//
//	enoki_walking_spring_bn_graphics, 32x512@4, 
//	+ palette 16 entries, not compressed
//	+ 256 tiles not compressed
//	Total size: 32 + 8192 = 8224
//
//	Time-stamp: 2022-03-28, 02:39:20
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ENOKI_WALKING_SPRING_BN_GRAPHICS_H
#define GRIT_ENOKI_WALKING_SPRING_BN_GRAPHICS_H

#define enoki_walking_spring_bn_graphicsTilesLen 8192
extern const bn::tile enoki_walking_spring_bn_graphicsTiles[bn::max(2048 / 8, 1)];

#define enoki_walking_spring_bn_graphicsPalLen 32
extern const bn::color enoki_walking_spring_bn_graphicsPal[16];

#endif // GRIT_ENOKI_WALKING_SPRING_BN_GRAPHICS_H

//}}BLOCK(enoki_walking_spring_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item enoki_walking_spring(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(enoki_walking_spring_bn_graphicsTiles, 256), bpp_mode::BPP_4, compression_type::NONE, 16), 
            sprite_palette_item(span<const color>(enoki_walking_spring_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

