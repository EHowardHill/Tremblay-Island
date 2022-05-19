#ifndef BN_SPRITE_ITEMS_AARON01_H
#define BN_SPRITE_ITEMS_AARON01_H

#include "bn_sprite_item.h"

//{{BLOCK(aaron01_bn_graphics)

//======================================================================
//
//	aaron01_bn_graphics, 64x64@4, 
//	+ palette 16 entries, not compressed
//	+ 64 tiles not compressed
//	Total size: 32 + 2048 = 2080
//
//	Time-stamp: 2022-05-17, 22:36:30
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.18
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_AARON01_BN_GRAPHICS_H
#define GRIT_AARON01_BN_GRAPHICS_H

#define aaron01_bn_graphicsTilesLen 2048
extern const bn::tile aaron01_bn_graphicsTiles[bn::max(512 / 8, 1)];

#define aaron01_bn_graphicsPalLen 32
extern const bn::color aaron01_bn_graphicsPal[16];

#endif // GRIT_AARON01_BN_GRAPHICS_H

//}}BLOCK(aaron01_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item aaron01(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(aaron01_bn_graphicsTiles, 64), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(aaron01_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

