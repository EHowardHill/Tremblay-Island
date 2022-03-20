#ifndef BN_SPRITE_ITEMS_BATTLE_AARON_H
#define BN_SPRITE_ITEMS_BATTLE_AARON_H

#include "bn_sprite_item.h"

//{{BLOCK(battle_aaron_bn_graphics)

//======================================================================
//
//	battle_aaron_bn_graphics, 64x8960@4, 
//	+ palette 16 entries, not compressed
//	+ 8960 tiles not compressed
//	Total size: 32 + 286720 = 286752
//
//	Time-stamp: 2022-03-10, 17:41:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BATTLE_AARON_BN_GRAPHICS_H
#define GRIT_BATTLE_AARON_BN_GRAPHICS_H

#define battle_aaron_bn_graphicsTilesLen 286720
extern const bn::tile battle_aaron_bn_graphicsTiles[bn::max(71680 / 8, 1)];

#define battle_aaron_bn_graphicsPalLen 32
extern const bn::color battle_aaron_bn_graphicsPal[16];

#endif // GRIT_BATTLE_AARON_BN_GRAPHICS_H

//}}BLOCK(battle_aaron_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item battle_aaron(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(battle_aaron_bn_graphicsTiles, 8960), bpp_mode::BPP_4, compression_type::NONE, 140), 
            sprite_palette_item(span<const color>(battle_aaron_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

