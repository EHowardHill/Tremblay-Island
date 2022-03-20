#ifndef BN_SPRITE_ITEMS_AARON02_H
#define BN_SPRITE_ITEMS_AARON02_H

#include "bn_sprite_item.h"

//{{BLOCK(aaron02_bn_graphics)

//======================================================================
//
//	aaron02_bn_graphics, 64x64@4, 
//	+ palette 16 entries, not compressed
//	+ 64 tiles not compressed
//	Total size: 32 + 2048 = 2080
//
//	Time-stamp: 2022-03-10, 17:41:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_AARON02_BN_GRAPHICS_H
#define GRIT_AARON02_BN_GRAPHICS_H

#define aaron02_bn_graphicsTilesLen 2048
extern const bn::tile aaron02_bn_graphicsTiles[bn::max(512 / 8, 1)];

#define aaron02_bn_graphicsPalLen 32
extern const bn::color aaron02_bn_graphicsPal[16];

#endif // GRIT_AARON02_BN_GRAPHICS_H

//}}BLOCK(aaron02_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item aaron02(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(aaron02_bn_graphicsTiles, 64), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(aaron02_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

