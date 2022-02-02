#ifndef BN_SPRITE_ITEMS_DIANA_UKE_H
#define BN_SPRITE_ITEMS_DIANA_UKE_H

#include "bn_sprite_item.h"

//{{BLOCK(diana_uke_bn_graphics)

//======================================================================
//
//	diana_uke_bn_graphics, 32x128@4, 
//	+ palette 16 entries, not compressed
//	+ 64 tiles not compressed
//	Total size: 32 + 2048 = 2080
//
//	Time-stamp: 2022-01-26, 07:36:08
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_DIANA_UKE_BN_GRAPHICS_H
#define GRIT_DIANA_UKE_BN_GRAPHICS_H

#define diana_uke_bn_graphicsTilesLen 2048
extern const bn::tile diana_uke_bn_graphicsTiles[bn::max(512 / 8, 1)];

#define diana_uke_bn_graphicsPalLen 32
extern const bn::color diana_uke_bn_graphicsPal[16];

#endif // GRIT_DIANA_UKE_BN_GRAPHICS_H

//}}BLOCK(diana_uke_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item diana_uke(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(diana_uke_bn_graphicsTiles, 64), bpp_mode::BPP_4, compression_type::NONE, 4), 
            sprite_palette_item(span<const color>(diana_uke_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

