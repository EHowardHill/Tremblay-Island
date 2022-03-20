#ifndef BN_SPRITE_ITEMS_AWARDS_H
#define BN_SPRITE_ITEMS_AWARDS_H

#include "bn_sprite_item.h"

//{{BLOCK(awards_bn_graphics)

//======================================================================
//
//	awards_bn_graphics, 64x448@4, 
//	+ palette 16 entries, not compressed
//	+ 448 tiles not compressed
//	Total size: 32 + 14336 = 14368
//
//	Time-stamp: 2022-03-10, 17:41:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_AWARDS_BN_GRAPHICS_H
#define GRIT_AWARDS_BN_GRAPHICS_H

#define awards_bn_graphicsTilesLen 14336
extern const bn::tile awards_bn_graphicsTiles[bn::max(3584 / 8, 1)];

#define awards_bn_graphicsPalLen 32
extern const bn::color awards_bn_graphicsPal[16];

#endif // GRIT_AWARDS_BN_GRAPHICS_H

//}}BLOCK(awards_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item awards(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(awards_bn_graphicsTiles, 448), bpp_mode::BPP_4, compression_type::NONE, 7), 
            sprite_palette_item(span<const color>(awards_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

