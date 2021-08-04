#ifndef BN_SPRITE_ITEMS_DINOSAUR_H
#define BN_SPRITE_ITEMS_DINOSAUR_H

#include "bn_sprite_item.h"

//{{BLOCK(dinosaur_bn_graphics)

//======================================================================
//
//	dinosaur_bn_graphics, 64x64@4, 
//	+ palette 16 entries, not compressed
//	+ 64 tiles not compressed
//	Total size: 32 + 2048 = 2080
//
//	Time-stamp: 2021-07-31, 01:13:42
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_DINOSAUR_BN_GRAPHICS_H
#define GRIT_DINOSAUR_BN_GRAPHICS_H

#define dinosaur_bn_graphicsTilesLen 2048
extern const bn::tile dinosaur_bn_graphicsTiles[bn::max(512 / 8, 1)];

#define dinosaur_bn_graphicsPalLen 32
extern const bn::color dinosaur_bn_graphicsPal[16];

#endif // GRIT_DINOSAUR_BN_GRAPHICS_H

//}}BLOCK(dinosaur_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item dinosaur(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(dinosaur_bn_graphicsTiles, 64), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(dinosaur_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

