#ifndef BN_SPRITE_ITEMS_THE_TREE_H
#define BN_SPRITE_ITEMS_THE_TREE_H

#include "bn_sprite_item.h"

//{{BLOCK(the_tree_bn_graphics)

//======================================================================
//
//	the_tree_bn_graphics, 64x64@4, 
//	+ palette 16 entries, not compressed
//	+ 64 tiles not compressed
//	Total size: 32 + 2048 = 2080
//
//	Time-stamp: 2022-03-10, 17:41:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_THE_TREE_BN_GRAPHICS_H
#define GRIT_THE_TREE_BN_GRAPHICS_H

#define the_tree_bn_graphicsTilesLen 2048
extern const bn::tile the_tree_bn_graphicsTiles[bn::max(512 / 8, 1)];

#define the_tree_bn_graphicsPalLen 32
extern const bn::color the_tree_bn_graphicsPal[16];

#endif // GRIT_THE_TREE_BN_GRAPHICS_H

//}}BLOCK(the_tree_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item the_tree(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(the_tree_bn_graphicsTiles, 64), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(the_tree_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

