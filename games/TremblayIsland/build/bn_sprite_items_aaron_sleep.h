#ifndef BN_SPRITE_ITEMS_AARON_SLEEP_H
#define BN_SPRITE_ITEMS_AARON_SLEEP_H

#include "bn_sprite_item.h"

//{{BLOCK(aaron_sleep_bn_graphics)

//======================================================================
//
//	aaron_sleep_bn_graphics, 32x192@4, 
//	+ palette 16 entries, not compressed
//	+ 96 tiles not compressed
//	Total size: 32 + 3072 = 3104
//
//	Time-stamp: 2022-01-22, 04:49:13
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_AARON_SLEEP_BN_GRAPHICS_H
#define GRIT_AARON_SLEEP_BN_GRAPHICS_H

#define aaron_sleep_bn_graphicsTilesLen 3072
extern const bn::tile aaron_sleep_bn_graphicsTiles[bn::max(768 / 8, 1)];

#define aaron_sleep_bn_graphicsPalLen 32
extern const bn::color aaron_sleep_bn_graphicsPal[16];

#endif // GRIT_AARON_SLEEP_BN_GRAPHICS_H

//}}BLOCK(aaron_sleep_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item aaron_sleep(sprite_shape_size(sprite_shape::TALL, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(aaron_sleep_bn_graphicsTiles, 96), bpp_mode::BPP_4, compression_type::NONE, 3), 
            sprite_palette_item(span<const color>(aaron_sleep_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

