#ifndef BN_SPRITE_ITEMS_DEL_SLEEP_H
#define BN_SPRITE_ITEMS_DEL_SLEEP_H

#include "bn_sprite_item.h"

//{{BLOCK(del_sleep_bn_graphics)

//======================================================================
//
//	del_sleep_bn_graphics, 64x128@4, 
//	+ palette 16 entries, not compressed
//	+ 128 tiles not compressed
//	Total size: 32 + 4096 = 4128
//
//	Time-stamp: 2022-03-10, 17:41:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_DEL_SLEEP_BN_GRAPHICS_H
#define GRIT_DEL_SLEEP_BN_GRAPHICS_H

#define del_sleep_bn_graphicsTilesLen 4096
extern const bn::tile del_sleep_bn_graphicsTiles[bn::max(1024 / 8, 1)];

#define del_sleep_bn_graphicsPalLen 32
extern const bn::color del_sleep_bn_graphicsPal[16];

#endif // GRIT_DEL_SLEEP_BN_GRAPHICS_H

//}}BLOCK(del_sleep_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item del_sleep(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(del_sleep_bn_graphicsTiles, 128), bpp_mode::BPP_4, compression_type::NONE, 2), 
            sprite_palette_item(span<const color>(del_sleep_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

