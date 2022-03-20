#ifndef BN_SPRITE_ITEMS_FLAGS_H
#define BN_SPRITE_ITEMS_FLAGS_H

#include "bn_sprite_item.h"

//{{BLOCK(flags_bn_graphics)

//======================================================================
//
//	flags_bn_graphics, 32x96@4, 
//	+ palette 16 entries, not compressed
//	+ 48 tiles not compressed
//	Total size: 32 + 1536 = 1568
//
//	Time-stamp: 2022-03-10, 17:41:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FLAGS_BN_GRAPHICS_H
#define GRIT_FLAGS_BN_GRAPHICS_H

#define flags_bn_graphicsTilesLen 1536
extern const bn::tile flags_bn_graphicsTiles[bn::max(384 / 8, 1)];

#define flags_bn_graphicsPalLen 32
extern const bn::color flags_bn_graphicsPal[16];

#endif // GRIT_FLAGS_BN_GRAPHICS_H

//}}BLOCK(flags_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item flags(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(flags_bn_graphicsTiles, 48), bpp_mode::BPP_4, compression_type::NONE, 3), 
            sprite_palette_item(span<const color>(flags_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

