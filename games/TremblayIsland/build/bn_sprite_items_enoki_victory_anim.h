#ifndef BN_SPRITE_ITEMS_ENOKI_VICTORY_ANIM_H
#define BN_SPRITE_ITEMS_ENOKI_VICTORY_ANIM_H

#include "bn_sprite_item.h"

//{{BLOCK(enoki_victory_anim_bn_graphics)

//======================================================================
//
//	enoki_victory_anim_bn_graphics, 64x3072@4, 
//	+ palette 16 entries, not compressed
//	+ 3072 tiles not compressed
//	Total size: 32 + 98304 = 98336
//
//	Time-stamp: 2022-03-28, 02:39:21
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ENOKI_VICTORY_ANIM_BN_GRAPHICS_H
#define GRIT_ENOKI_VICTORY_ANIM_BN_GRAPHICS_H

#define enoki_victory_anim_bn_graphicsTilesLen 98304
extern const bn::tile enoki_victory_anim_bn_graphicsTiles[bn::max(24576 / 8, 1)];

#define enoki_victory_anim_bn_graphicsPalLen 32
extern const bn::color enoki_victory_anim_bn_graphicsPal[16];

#endif // GRIT_ENOKI_VICTORY_ANIM_BN_GRAPHICS_H

//}}BLOCK(enoki_victory_anim_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item enoki_victory_anim(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(enoki_victory_anim_bn_graphicsTiles, 3072), bpp_mode::BPP_4, compression_type::NONE, 48), 
            sprite_palette_item(span<const color>(enoki_victory_anim_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

