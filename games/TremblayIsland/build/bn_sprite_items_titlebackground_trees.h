#ifndef BN_SPRITE_ITEMS_TITLEBACKGROUND_TREES_H
#define BN_SPRITE_ITEMS_TITLEBACKGROUND_TREES_H

#include "bn_sprite_item.h"

//{{BLOCK(titlebackground_trees_bn_graphics)

//======================================================================
//
//	titlebackground_trees_bn_graphics, 64x256@4, 
//	+ palette 16 entries, not compressed
//	+ 256 tiles not compressed
//	Total size: 32 + 8192 = 8224
//
//	Time-stamp: 2022-03-21, 06:46:39
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TITLEBACKGROUND_TREES_BN_GRAPHICS_H
#define GRIT_TITLEBACKGROUND_TREES_BN_GRAPHICS_H

#define titlebackground_trees_bn_graphicsTilesLen 8192
extern const bn::tile titlebackground_trees_bn_graphicsTiles[bn::max(2048 / 8, 1)];

#define titlebackground_trees_bn_graphicsPalLen 32
extern const bn::color titlebackground_trees_bn_graphicsPal[16];

#endif // GRIT_TITLEBACKGROUND_TREES_BN_GRAPHICS_H

//}}BLOCK(titlebackground_trees_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item titlebackground_trees(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(titlebackground_trees_bn_graphicsTiles, 256), bpp_mode::BPP_4, compression_type::NONE, 4), 
            sprite_palette_item(span<const color>(titlebackground_trees_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

