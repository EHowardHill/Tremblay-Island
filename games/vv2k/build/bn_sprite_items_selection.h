#ifndef BN_SPRITE_ITEMS_SELECTION_H
#define BN_SPRITE_ITEMS_SELECTION_H

#include "bn_sprite_item.h"

//{{BLOCK(selection_bn_graphics)

//======================================================================
//
//	selection_bn_graphics, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2021-09-12, 02:53:07
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SELECTION_BN_GRAPHICS_H
#define GRIT_SELECTION_BN_GRAPHICS_H

#define selection_bn_graphicsTilesLen 128
extern const bn::tile selection_bn_graphicsTiles[bn::max(32 / 8, 1)];

#define selection_bn_graphicsPalLen 32
extern const bn::color selection_bn_graphicsPal[16];

#endif // GRIT_SELECTION_BN_GRAPHICS_H

//}}BLOCK(selection_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item selection(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(selection_bn_graphicsTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(selection_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

