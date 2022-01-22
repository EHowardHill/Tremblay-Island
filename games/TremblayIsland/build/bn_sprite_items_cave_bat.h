#ifndef BN_SPRITE_ITEMS_CAVE_BAT_H
#define BN_SPRITE_ITEMS_CAVE_BAT_H

#include "bn_sprite_item.h"

//{{BLOCK(cave_bat_bn_graphics)

//======================================================================
//
//	cave_bat_bn_graphics, 16x64@4, 
//	+ palette 16 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 32 + 512 = 544
//
//	Time-stamp: 2022-01-22, 04:49:13
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CAVE_BAT_BN_GRAPHICS_H
#define GRIT_CAVE_BAT_BN_GRAPHICS_H

#define cave_bat_bn_graphicsTilesLen 512
extern const bn::tile cave_bat_bn_graphicsTiles[bn::max(128 / 8, 1)];

#define cave_bat_bn_graphicsPalLen 32
extern const bn::color cave_bat_bn_graphicsPal[16];

#endif // GRIT_CAVE_BAT_BN_GRAPHICS_H

//}}BLOCK(cave_bat_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item cave_bat(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(cave_bat_bn_graphicsTiles, 16), bpp_mode::BPP_4, compression_type::NONE, 4), 
            sprite_palette_item(span<const color>(cave_bat_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

