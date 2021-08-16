#ifndef BN_SPRITE_ITEMS_MAPLE05_H
#define BN_SPRITE_ITEMS_MAPLE05_H

#include "bn_sprite_item.h"

//{{BLOCK(maple05_bn_graphics)

//======================================================================
//
//	maple05_bn_graphics, 64x64@4, 
//	+ palette 16 entries, not compressed
//	+ 64 tiles not compressed
//	Total size: 32 + 2048 = 2080
//
//	Time-stamp: 2021-08-15, 21:43:41
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MAPLE05_BN_GRAPHICS_H
#define GRIT_MAPLE05_BN_GRAPHICS_H

#define maple05_bn_graphicsTilesLen 2048
extern const bn::tile maple05_bn_graphicsTiles[bn::max(512 / 8, 1)];

#define maple05_bn_graphicsPalLen 32
extern const bn::color maple05_bn_graphicsPal[16];

#endif // GRIT_MAPLE05_BN_GRAPHICS_H

//}}BLOCK(maple05_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item maple05(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(maple05_bn_graphicsTiles, 64), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(maple05_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

