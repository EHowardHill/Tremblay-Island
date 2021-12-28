#ifndef BN_SPRITE_ITEMS_FIREBALL_H
#define BN_SPRITE_ITEMS_FIREBALL_H

#include "bn_sprite_item.h"

//{{BLOCK(fireball_bn_graphics)

//======================================================================
//
//	fireball_bn_graphics, 32x256@4, 
//	+ palette 16 entries, not compressed
//	+ 128 tiles not compressed
//	Total size: 32 + 4096 = 4128
//
//	Time-stamp: 2021-10-26, 01:25:50
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FIREBALL_BN_GRAPHICS_H
#define GRIT_FIREBALL_BN_GRAPHICS_H

#define fireball_bn_graphicsTilesLen 4096
extern const bn::tile fireball_bn_graphicsTiles[bn::max(1024 / 8, 1)];

#define fireball_bn_graphicsPalLen 32
extern const bn::color fireball_bn_graphicsPal[16];

#endif // GRIT_FIREBALL_BN_GRAPHICS_H

//}}BLOCK(fireball_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item fireball(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(fireball_bn_graphicsTiles, 128), bpp_mode::BPP_4, compression_type::NONE, 8), 
            sprite_palette_item(span<const color>(fireball_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

