#ifndef BN_SPRITE_ITEMS_VARIABLE_8X16_FONT_YELLOW_H
#define BN_SPRITE_ITEMS_VARIABLE_8X16_FONT_YELLOW_H

#include "bn_sprite_item.h"

//{{BLOCK(variable_8x16_font_yellow_bn_graphics)

//======================================================================
//
//	variable_8x16_font_yellow_bn_graphics, 8x16@4, 
//	+ palette 16 entries, not compressed
//	+ 2 tiles not compressed
//	Total size: 32 + 64 = 96
//
//	Time-stamp: 2022-03-24, 04:15:58
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_VARIABLE_8X16_FONT_YELLOW_BN_GRAPHICS_H
#define GRIT_VARIABLE_8X16_FONT_YELLOW_BN_GRAPHICS_H

#define variable_8x16_font_yellow_bn_graphicsTilesLen 64
extern const bn::tile variable_8x16_font_yellow_bn_graphicsTiles[bn::max(16 / 8, 1)];

#define variable_8x16_font_yellow_bn_graphicsPalLen 32
extern const bn::color variable_8x16_font_yellow_bn_graphicsPal[16];

#endif // GRIT_VARIABLE_8X16_FONT_YELLOW_BN_GRAPHICS_H

//}}BLOCK(variable_8x16_font_yellow_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item variable_8x16_font_yellow(sprite_shape_size(sprite_shape::TALL, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(variable_8x16_font_yellow_bn_graphicsTiles, 2), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(variable_8x16_font_yellow_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

