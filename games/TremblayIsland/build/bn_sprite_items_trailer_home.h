#ifndef BN_SPRITE_ITEMS_TRAILER_HOME_H
#define BN_SPRITE_ITEMS_TRAILER_HOME_H

#include "bn_sprite_item.h"

//{{BLOCK(trailer_home_bn_graphics)

//======================================================================
//
//	trailer_home_bn_graphics, 32x1760@4, 
//	+ palette 16 entries, not compressed
//	+ 880 tiles not compressed
//	Total size: 32 + 28160 = 28192
//
//	Time-stamp: 2021-10-26, 01:25:50
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TRAILER_HOME_BN_GRAPHICS_H
#define GRIT_TRAILER_HOME_BN_GRAPHICS_H

#define trailer_home_bn_graphicsTilesLen 28160
extern const bn::tile trailer_home_bn_graphicsTiles[bn::max(7040 / 8, 1)];

#define trailer_home_bn_graphicsPalLen 32
extern const bn::color trailer_home_bn_graphicsPal[16];

#endif // GRIT_TRAILER_HOME_BN_GRAPHICS_H

//}}BLOCK(trailer_home_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item trailer_home(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(trailer_home_bn_graphicsTiles, 880), bpp_mode::BPP_4, compression_type::NONE, 55), 
            sprite_palette_item(span<const color>(trailer_home_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

