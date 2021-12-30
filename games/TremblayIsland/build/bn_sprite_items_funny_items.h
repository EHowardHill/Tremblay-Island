#ifndef BN_SPRITE_ITEMS_FUNNY_ITEMS_H
#define BN_SPRITE_ITEMS_FUNNY_ITEMS_H

#include "bn_sprite_item.h"

//{{BLOCK(funny_items_bn_graphics)

//======================================================================
//
//	funny_items_bn_graphics, 32x96@4, 
//	+ palette 16 entries, not compressed
//	+ 48 tiles not compressed
//	Total size: 32 + 1536 = 1568
//
//	Time-stamp: 2021-12-30, 07:43:03
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FUNNY_ITEMS_BN_GRAPHICS_H
#define GRIT_FUNNY_ITEMS_BN_GRAPHICS_H

#define funny_items_bn_graphicsTilesLen 1536
extern const bn::tile funny_items_bn_graphicsTiles[bn::max(384 / 8, 1)];

#define funny_items_bn_graphicsPalLen 32
extern const bn::color funny_items_bn_graphicsPal[16];

#endif // GRIT_FUNNY_ITEMS_BN_GRAPHICS_H

//}}BLOCK(funny_items_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item funny_items(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(funny_items_bn_graphicsTiles, 48), bpp_mode::BPP_4, compression_type::NONE, 3), 
            sprite_palette_item(span<const color>(funny_items_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

