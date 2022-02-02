#ifndef BN_SPRITE_ITEMS_BUNBUN_H
#define BN_SPRITE_ITEMS_BUNBUN_H

#include "bn_sprite_item.h"

//{{BLOCK(bunbun_bn_graphics)

//======================================================================
//
//	bunbun_bn_graphics, 8x16@4, 
//	+ palette 16 entries, not compressed
//	+ 2 tiles not compressed
//	Total size: 32 + 64 = 96
//
//	Time-stamp: 2022-01-26, 07:36:08
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BUNBUN_BN_GRAPHICS_H
#define GRIT_BUNBUN_BN_GRAPHICS_H

#define bunbun_bn_graphicsTilesLen 64
extern const bn::tile bunbun_bn_graphicsTiles[bn::max(16 / 8, 1)];

#define bunbun_bn_graphicsPalLen 32
extern const bn::color bunbun_bn_graphicsPal[16];

#endif // GRIT_BUNBUN_BN_GRAPHICS_H

//}}BLOCK(bunbun_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item bunbun(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(bunbun_bn_graphicsTiles, 2), bpp_mode::BPP_4, compression_type::NONE, 2), 
            sprite_palette_item(span<const color>(bunbun_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

