#ifndef BN_SPRITE_ITEMS_AX_BAR_H
#define BN_SPRITE_ITEMS_AX_BAR_H

#include "bn_sprite_item.h"

//{{BLOCK(ax_bar_bn_graphics)

//======================================================================
//
//	ax_bar_bn_graphics, 32x32@4, 
//	+ palette 16 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 32 + 512 = 544
//
//	Time-stamp: 2022-01-26, 07:36:08
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_AX_BAR_BN_GRAPHICS_H
#define GRIT_AX_BAR_BN_GRAPHICS_H

#define ax_bar_bn_graphicsTilesLen 512
extern const bn::tile ax_bar_bn_graphicsTiles[bn::max(128 / 8, 1)];

#define ax_bar_bn_graphicsPalLen 32
extern const bn::color ax_bar_bn_graphicsPal[16];

#endif // GRIT_AX_BAR_BN_GRAPHICS_H

//}}BLOCK(ax_bar_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item ax_bar(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(ax_bar_bn_graphicsTiles, 16), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(ax_bar_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

