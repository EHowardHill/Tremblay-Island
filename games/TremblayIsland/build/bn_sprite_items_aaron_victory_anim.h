#ifndef BN_SPRITE_ITEMS_AARON_VICTORY_ANIM_H
#define BN_SPRITE_ITEMS_AARON_VICTORY_ANIM_H

#include "bn_sprite_item.h"

//{{BLOCK(aaron_victory_anim_bn_graphics)

//======================================================================
//
//	aaron_victory_anim_bn_graphics, 64x2048@4, 
//	+ palette 16 entries, not compressed
//	+ 2048 tiles not compressed
//	Total size: 32 + 65536 = 65568
//
//	Time-stamp: 2021-11-03, 01:33:31
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_AARON_VICTORY_ANIM_BN_GRAPHICS_H
#define GRIT_AARON_VICTORY_ANIM_BN_GRAPHICS_H

#define aaron_victory_anim_bn_graphicsTilesLen 65536
extern const bn::tile aaron_victory_anim_bn_graphicsTiles[bn::max(16384 / 8, 1)];

#define aaron_victory_anim_bn_graphicsPalLen 32
extern const bn::color aaron_victory_anim_bn_graphicsPal[16];

#endif // GRIT_AARON_VICTORY_ANIM_BN_GRAPHICS_H

//}}BLOCK(aaron_victory_anim_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item aaron_victory_anim(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(aaron_victory_anim_bn_graphicsTiles, 2048), bpp_mode::BPP_4, compression_type::NONE, 32), 
            sprite_palette_item(span<const color>(aaron_victory_anim_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

