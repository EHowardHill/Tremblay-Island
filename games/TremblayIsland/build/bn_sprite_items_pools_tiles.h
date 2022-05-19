#ifndef BN_SPRITE_ITEMS_POOLS_TILES_H
#define BN_SPRITE_ITEMS_POOLS_TILES_H

#include "bn_sprite_item.h"

//{{BLOCK(pools_tiles_bn_graphics)

//======================================================================
//
//	pools_tiles_bn_graphics, 32x2048@4, 
//	+ palette 16 entries, not compressed
//	+ 1024 tiles not compressed
//	Total size: 32 + 32768 = 32800
//
//	Time-stamp: 2022-05-17, 22:36:30
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.18
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_POOLS_TILES_BN_GRAPHICS_H
#define GRIT_POOLS_TILES_BN_GRAPHICS_H

#define pools_tiles_bn_graphicsTilesLen 32768
extern const bn::tile pools_tiles_bn_graphicsTiles[bn::max(8192 / 8, 1)];

#define pools_tiles_bn_graphicsPalLen 32
extern const bn::color pools_tiles_bn_graphicsPal[16];

#endif // GRIT_POOLS_TILES_BN_GRAPHICS_H

//}}BLOCK(pools_tiles_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item pools_tiles(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(pools_tiles_bn_graphicsTiles, 1024), bpp_mode::BPP_4, compression_type::NONE, 64), 
            sprite_palette_item(span<const color>(pools_tiles_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

