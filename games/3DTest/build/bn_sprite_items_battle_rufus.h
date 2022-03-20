#ifndef BN_SPRITE_ITEMS_BATTLE_RUFUS_H
#define BN_SPRITE_ITEMS_BATTLE_RUFUS_H

#include "bn_sprite_item.h"

//{{BLOCK(battle_rufus_bn_graphics)

//======================================================================
//
//	battle_rufus_bn_graphics, 64x10496@4, 
//	+ palette 16 entries, not compressed
//	+ 10496 tiles not compressed
//	Total size: 32 + 335872 = 335904
//
//	Time-stamp: 2022-03-10, 17:41:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BATTLE_RUFUS_BN_GRAPHICS_H
#define GRIT_BATTLE_RUFUS_BN_GRAPHICS_H

#define battle_rufus_bn_graphicsTilesLen 335872
extern const bn::tile battle_rufus_bn_graphicsTiles[bn::max(83968 / 8, 1)];

#define battle_rufus_bn_graphicsPalLen 32
extern const bn::color battle_rufus_bn_graphicsPal[16];

#endif // GRIT_BATTLE_RUFUS_BN_GRAPHICS_H

//}}BLOCK(battle_rufus_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item battle_rufus(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(battle_rufus_bn_graphicsTiles, 10496), bpp_mode::BPP_4, compression_type::NONE, 164), 
            sprite_palette_item(span<const color>(battle_rufus_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

