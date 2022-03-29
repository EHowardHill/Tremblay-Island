#ifndef BN_SPRITE_ITEMS_SCOUT_LAB_H
#define BN_SPRITE_ITEMS_SCOUT_LAB_H

#include "bn_sprite_item.h"

//{{BLOCK(scout_lab_bn_graphics)

//======================================================================
//
//	scout_lab_bn_graphics, 32x448@4, 
//	+ palette 16 entries, not compressed
//	+ 224 tiles not compressed
//	Total size: 32 + 7168 = 7200
//
//	Time-stamp: 2022-03-28, 02:39:24
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SCOUT_LAB_BN_GRAPHICS_H
#define GRIT_SCOUT_LAB_BN_GRAPHICS_H

#define scout_lab_bn_graphicsTilesLen 7168
extern const bn::tile scout_lab_bn_graphicsTiles[bn::max(1792 / 8, 1)];

#define scout_lab_bn_graphicsPalLen 32
extern const bn::color scout_lab_bn_graphicsPal[16];

#endif // GRIT_SCOUT_LAB_BN_GRAPHICS_H

//}}BLOCK(scout_lab_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item scout_lab(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(scout_lab_bn_graphicsTiles, 224), bpp_mode::BPP_4, compression_type::NONE, 14), 
            sprite_palette_item(span<const color>(scout_lab_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

