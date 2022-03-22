#ifndef BN_SPRITE_ITEMS_UNDERGROUND_TILES_H
#define BN_SPRITE_ITEMS_UNDERGROUND_TILES_H

#include "bn_sprite_item.h"

//{{BLOCK(underground_tiles_bn_graphics)

//======================================================================
//
//	underground_tiles_bn_graphics, 32x512@4, 
//	+ palette 16 entries, not compressed
//	+ 256 tiles not compressed
//	Total size: 32 + 8192 = 8224
//
//	Time-stamp: 2022-03-21, 06:46:40
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_UNDERGROUND_TILES_BN_GRAPHICS_H
#define GRIT_UNDERGROUND_TILES_BN_GRAPHICS_H

#define underground_tiles_bn_graphicsTilesLen 8192
extern const bn::tile underground_tiles_bn_graphicsTiles[bn::max(2048 / 8, 1)];

#define underground_tiles_bn_graphicsPalLen 32
extern const bn::color underground_tiles_bn_graphicsPal[16];

#endif // GRIT_UNDERGROUND_TILES_BN_GRAPHICS_H

//}}BLOCK(underground_tiles_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item underground_tiles(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(underground_tiles_bn_graphicsTiles, 256), bpp_mode::BPP_4, compression_type::NONE, 16), 
            sprite_palette_item(span<const color>(underground_tiles_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

