#ifndef BN_SPRITE_ITEMS_FIREPLACE_ANIM_H
#define BN_SPRITE_ITEMS_FIREPLACE_ANIM_H

#include "bn_sprite_item.h"

//{{BLOCK(fireplace_anim_bn_graphics)

//======================================================================
//
//	fireplace_anim_bn_graphics, 64x192@4, 
//	+ palette 16 entries, not compressed
//	+ 192 tiles not compressed
//	Total size: 32 + 6144 = 6176
//
//	Time-stamp: 2022-05-17, 22:36:29
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.18
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FIREPLACE_ANIM_BN_GRAPHICS_H
#define GRIT_FIREPLACE_ANIM_BN_GRAPHICS_H

#define fireplace_anim_bn_graphicsTilesLen 6144
extern const bn::tile fireplace_anim_bn_graphicsTiles[bn::max(1536 / 8, 1)];

#define fireplace_anim_bn_graphicsPalLen 32
extern const bn::color fireplace_anim_bn_graphicsPal[16];

#endif // GRIT_FIREPLACE_ANIM_BN_GRAPHICS_H

//}}BLOCK(fireplace_anim_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item fireplace_anim(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(fireplace_anim_bn_graphicsTiles, 192), bpp_mode::BPP_4, compression_type::NONE, 3), 
            sprite_palette_item(span<const color>(fireplace_anim_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

