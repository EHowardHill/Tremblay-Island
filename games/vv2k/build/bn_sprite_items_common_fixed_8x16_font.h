#ifndef BN_SPRITE_ITEMS_COMMON_FIXED_8X16_FONT_H
#define BN_SPRITE_ITEMS_COMMON_FIXED_8X16_FONT_H

#include "bn_sprite_item.h"

//{{BLOCK(common_fixed_8x16_font_bn_graphics)

//======================================================================
//
//	common_fixed_8x16_font_bn_graphics, 8x1760@4, 
//	+ palette 16 entries, not compressed
//	+ 220 tiles not compressed
//	Total size: 32 + 7040 = 7072
//
//	Time-stamp: 2021-08-25, 02:05:56
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_COMMON_FIXED_8X16_FONT_BN_GRAPHICS_H
#define GRIT_COMMON_FIXED_8X16_FONT_BN_GRAPHICS_H

#define common_fixed_8x16_font_bn_graphicsTilesLen 7040
extern const bn::tile common_fixed_8x16_font_bn_graphicsTiles[bn::max(1760 / 8, 1)];

#define common_fixed_8x16_font_bn_graphicsPalLen 32
extern const bn::color common_fixed_8x16_font_bn_graphicsPal[16];

#endif // GRIT_COMMON_FIXED_8X16_FONT_BN_GRAPHICS_H

//}}BLOCK(common_fixed_8x16_font_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item common_fixed_8x16_font(sprite_shape_size(sprite_shape::TALL, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(common_fixed_8x16_font_bn_graphicsTiles, 220), bpp_mode::BPP_4, compression_type::NONE, 110), 
            sprite_palette_item(span<const color>(common_fixed_8x16_font_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

