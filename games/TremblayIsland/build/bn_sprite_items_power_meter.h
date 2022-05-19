#ifndef BN_SPRITE_ITEMS_POWER_METER_H
#define BN_SPRITE_ITEMS_POWER_METER_H

#include "bn_sprite_item.h"

//{{BLOCK(power_meter_bn_graphics)

//======================================================================
//
//	power_meter_bn_graphics, 16x64@4, 
//	+ palette 16 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 32 + 512 = 544
//
//	Time-stamp: 2022-05-17, 22:36:30
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.18
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_POWER_METER_BN_GRAPHICS_H
#define GRIT_POWER_METER_BN_GRAPHICS_H

#define power_meter_bn_graphicsTilesLen 512
extern const bn::tile power_meter_bn_graphicsTiles[bn::max(128 / 8, 1)];

#define power_meter_bn_graphicsPalLen 32
extern const bn::color power_meter_bn_graphicsPal[16];

#endif // GRIT_POWER_METER_BN_GRAPHICS_H

//}}BLOCK(power_meter_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item power_meter(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(power_meter_bn_graphicsTiles, 16), bpp_mode::BPP_4, compression_type::NONE, 4), 
            sprite_palette_item(span<const color>(power_meter_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

