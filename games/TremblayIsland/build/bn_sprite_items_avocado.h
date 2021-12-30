#ifndef BN_SPRITE_ITEMS_AVOCADO_H
#define BN_SPRITE_ITEMS_AVOCADO_H

#include "bn_sprite_item.h"

//{{BLOCK(avocado_bn_graphics)

//======================================================================
//
//	avocado_bn_graphics, 64x384@4, 
//	+ palette 16 entries, not compressed
//	+ 384 tiles not compressed
//	Total size: 32 + 12288 = 12320
//
//	Time-stamp: 2021-12-30, 07:43:02
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_AVOCADO_BN_GRAPHICS_H
#define GRIT_AVOCADO_BN_GRAPHICS_H

#define avocado_bn_graphicsTilesLen 12288
extern const bn::tile avocado_bn_graphicsTiles[bn::max(3072 / 8, 1)];

#define avocado_bn_graphicsPalLen 32
extern const bn::color avocado_bn_graphicsPal[16];

#endif // GRIT_AVOCADO_BN_GRAPHICS_H

//}}BLOCK(avocado_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item avocado(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(avocado_bn_graphicsTiles, 384), bpp_mode::BPP_4, compression_type::NONE, 6), 
            sprite_palette_item(span<const color>(avocado_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

