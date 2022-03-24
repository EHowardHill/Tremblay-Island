#ifndef BN_SPRITE_ITEMS_BB_SPRITES_H
#define BN_SPRITE_ITEMS_BB_SPRITES_H

#include "bn_sprite_item.h"

//{{BLOCK(bb_sprites_bn_graphics)

//======================================================================
//
//	bb_sprites_bn_graphics, 8x56@4, 
//	+ palette 16 entries, not compressed
//	+ 7 tiles not compressed
//	Total size: 32 + 224 = 256
//
//	Time-stamp: 2022-03-24, 04:15:53
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BB_SPRITES_BN_GRAPHICS_H
#define GRIT_BB_SPRITES_BN_GRAPHICS_H

#define bb_sprites_bn_graphicsTilesLen 224
extern const bn::tile bb_sprites_bn_graphicsTiles[bn::max(56 / 8, 1)];

#define bb_sprites_bn_graphicsPalLen 32
extern const bn::color bb_sprites_bn_graphicsPal[16];

#endif // GRIT_BB_SPRITES_BN_GRAPHICS_H

//}}BLOCK(bb_sprites_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item bb_sprites(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(bb_sprites_bn_graphicsTiles, 7), bpp_mode::BPP_4, compression_type::NONE, 7), 
            sprite_palette_item(span<const color>(bb_sprites_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

