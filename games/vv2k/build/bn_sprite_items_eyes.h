#ifndef BN_SPRITE_ITEMS_EYES_H
#define BN_SPRITE_ITEMS_EYES_H

#include "bn_sprite_item.h"

//{{BLOCK(eyes_bn_graphics)

//======================================================================
//
//	eyes_bn_graphics, 16x32@4, 
//	+ palette 16 entries, not compressed
//	+ 8 tiles not compressed
//	Total size: 32 + 256 = 288
//
//	Time-stamp: 2021-11-28, 00:05:42
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_EYES_BN_GRAPHICS_H
#define GRIT_EYES_BN_GRAPHICS_H

#define eyes_bn_graphicsTilesLen 256
extern const bn::tile eyes_bn_graphicsTiles[bn::max(64 / 8, 1)];

#define eyes_bn_graphicsPalLen 32
extern const bn::color eyes_bn_graphicsPal[16];

#endif // GRIT_EYES_BN_GRAPHICS_H

//}}BLOCK(eyes_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item eyes(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(eyes_bn_graphicsTiles, 8), bpp_mode::BPP_4, compression_type::NONE, 2), 
            sprite_palette_item(span<const color>(eyes_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

