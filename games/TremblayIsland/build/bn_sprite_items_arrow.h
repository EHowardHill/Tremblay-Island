#ifndef BN_SPRITE_ITEMS_ARROW_H
#define BN_SPRITE_ITEMS_ARROW_H

#include "bn_sprite_item.h"

//{{BLOCK(arrow_bn_graphics)

//======================================================================
//
//	arrow_bn_graphics, 32x32@4, 
//	+ palette 16 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 32 + 512 = 544
//
//	Time-stamp: 2022-03-21, 06:46:34
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ARROW_BN_GRAPHICS_H
#define GRIT_ARROW_BN_GRAPHICS_H

#define arrow_bn_graphicsTilesLen 512
extern const bn::tile arrow_bn_graphicsTiles[bn::max(128 / 8, 1)];

#define arrow_bn_graphicsPalLen 32
extern const bn::color arrow_bn_graphicsPal[16];

#endif // GRIT_ARROW_BN_GRAPHICS_H

//}}BLOCK(arrow_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item arrow(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(arrow_bn_graphicsTiles, 16), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(arrow_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

