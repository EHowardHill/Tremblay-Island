#ifndef BN_SPRITE_ITEMS_MAPLE_VICTORY_ANIM_H
#define BN_SPRITE_ITEMS_MAPLE_VICTORY_ANIM_H

#include "bn_sprite_item.h"

//{{BLOCK(maple_victory_anim_bn_graphics)

//======================================================================
//
//	maple_victory_anim_bn_graphics, 64x1792@4, 
//	+ palette 16 entries, not compressed
//	+ 1792 tiles not compressed
//	Total size: 32 + 57344 = 57376
//
//	Time-stamp: 2022-03-10, 17:41:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MAPLE_VICTORY_ANIM_BN_GRAPHICS_H
#define GRIT_MAPLE_VICTORY_ANIM_BN_GRAPHICS_H

#define maple_victory_anim_bn_graphicsTilesLen 57344
extern const bn::tile maple_victory_anim_bn_graphicsTiles[bn::max(14336 / 8, 1)];

#define maple_victory_anim_bn_graphicsPalLen 32
extern const bn::color maple_victory_anim_bn_graphicsPal[16];

#endif // GRIT_MAPLE_VICTORY_ANIM_BN_GRAPHICS_H

//}}BLOCK(maple_victory_anim_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item maple_victory_anim(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(maple_victory_anim_bn_graphicsTiles, 1792), bpp_mode::BPP_4, compression_type::NONE, 28), 
            sprite_palette_item(span<const color>(maple_victory_anim_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

