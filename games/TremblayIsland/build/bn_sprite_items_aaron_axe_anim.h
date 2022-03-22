#ifndef BN_SPRITE_ITEMS_AARON_AXE_ANIM_H
#define BN_SPRITE_ITEMS_AARON_AXE_ANIM_H

#include "bn_sprite_item.h"

//{{BLOCK(aaron_axe_anim_bn_graphics)

//======================================================================
//
//	aaron_axe_anim_bn_graphics, 64x3584@4, 
//	+ palette 16 entries, not compressed
//	+ 3584 tiles not compressed
//	Total size: 32 + 114688 = 114720
//
//	Time-stamp: 2022-03-21, 06:46:32
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_AARON_AXE_ANIM_BN_GRAPHICS_H
#define GRIT_AARON_AXE_ANIM_BN_GRAPHICS_H

#define aaron_axe_anim_bn_graphicsTilesLen 114688
extern const bn::tile aaron_axe_anim_bn_graphicsTiles[bn::max(28672 / 8, 1)];

#define aaron_axe_anim_bn_graphicsPalLen 32
extern const bn::color aaron_axe_anim_bn_graphicsPal[16];

#endif // GRIT_AARON_AXE_ANIM_BN_GRAPHICS_H

//}}BLOCK(aaron_axe_anim_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item aaron_axe_anim(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(aaron_axe_anim_bn_graphicsTiles, 3584), bpp_mode::BPP_4, compression_type::NONE, 56), 
            sprite_palette_item(span<const color>(aaron_axe_anim_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

