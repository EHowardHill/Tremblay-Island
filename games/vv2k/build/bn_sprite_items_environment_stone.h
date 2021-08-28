#ifndef BN_SPRITE_ITEMS_ENVIRONMENT_STONE_H
#define BN_SPRITE_ITEMS_ENVIRONMENT_STONE_H

#include "bn_sprite_item.h"

//{{BLOCK(environment_stone_bn_graphics)

//======================================================================
//
//	environment_stone_bn_graphics, 32x32@4, 
//	+ palette 16 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 32 + 512 = 544
//
//	Time-stamp: 2021-08-26, 01:52:07
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ENVIRONMENT_STONE_BN_GRAPHICS_H
#define GRIT_ENVIRONMENT_STONE_BN_GRAPHICS_H

#define environment_stone_bn_graphicsTilesLen 512
extern const bn::tile environment_stone_bn_graphicsTiles[bn::max(128 / 8, 1)];

#define environment_stone_bn_graphicsPalLen 32
extern const bn::color environment_stone_bn_graphicsPal[16];

#endif // GRIT_ENVIRONMENT_STONE_BN_GRAPHICS_H

//}}BLOCK(environment_stone_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item environment_stone(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(environment_stone_bn_graphicsTiles, 16), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(environment_stone_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

