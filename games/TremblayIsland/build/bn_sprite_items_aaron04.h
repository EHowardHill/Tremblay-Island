#ifndef BN_SPRITE_ITEMS_AARON04_H
#define BN_SPRITE_ITEMS_AARON04_H

#include "bn_sprite_item.h"

//{{BLOCK(aaron04_bn_graphics)

//======================================================================
//
//	aaron04_bn_graphics, 64x64@4, 
//	+ palette 16 entries, not compressed
//	+ 64 tiles not compressed
//	Total size: 32 + 2048 = 2080
//
//	Time-stamp: 2021-10-26, 01:25:49
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_AARON04_BN_GRAPHICS_H
#define GRIT_AARON04_BN_GRAPHICS_H

#define aaron04_bn_graphicsTilesLen 2048
extern const bn::tile aaron04_bn_graphicsTiles[bn::max(512 / 8, 1)];

#define aaron04_bn_graphicsPalLen 32
extern const bn::color aaron04_bn_graphicsPal[16];

#endif // GRIT_AARON04_BN_GRAPHICS_H

//}}BLOCK(aaron04_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item aaron04(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(aaron04_bn_graphicsTiles, 64), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(aaron04_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

