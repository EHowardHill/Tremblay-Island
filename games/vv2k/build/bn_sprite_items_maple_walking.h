#ifndef BN_SPRITE_ITEMS_MAPLE_WALKING_H
#define BN_SPRITE_ITEMS_MAPLE_WALKING_H

#include "bn_sprite_item.h"

//{{BLOCK(maple_walking_bn_graphics)

//======================================================================
//
//	maple_walking_bn_graphics, 32x384@4, 
//	+ palette 16 entries, not compressed
//	+ 192 tiles not compressed
//	Total size: 32 + 6144 = 6176
//
//	Time-stamp: 2021-08-18, 01:07:49
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MAPLE_WALKING_BN_GRAPHICS_H
#define GRIT_MAPLE_WALKING_BN_GRAPHICS_H

#define maple_walking_bn_graphicsTilesLen 6144
extern const bn::tile maple_walking_bn_graphicsTiles[bn::max(1536 / 8, 1)];

#define maple_walking_bn_graphicsPalLen 32
extern const bn::color maple_walking_bn_graphicsPal[16];

#endif // GRIT_MAPLE_WALKING_BN_GRAPHICS_H

//}}BLOCK(maple_walking_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item maple_walking(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(maple_walking_bn_graphicsTiles, 192), bpp_mode::BPP_4, compression_type::NONE, 12), 
            sprite_palette_item(span<const color>(maple_walking_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

