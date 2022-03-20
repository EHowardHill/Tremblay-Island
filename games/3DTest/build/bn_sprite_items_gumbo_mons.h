#ifndef BN_SPRITE_ITEMS_GUMBO_MONS_H
#define BN_SPRITE_ITEMS_GUMBO_MONS_H

#include "bn_sprite_item.h"

//{{BLOCK(gumbo_mons_bn_graphics)

//======================================================================
//
//	gumbo_mons_bn_graphics, 64x896@4, 
//	+ palette 16 entries, not compressed
//	+ 896 tiles not compressed
//	Total size: 32 + 28672 = 28704
//
//	Time-stamp: 2022-03-10, 17:41:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GUMBO_MONS_BN_GRAPHICS_H
#define GRIT_GUMBO_MONS_BN_GRAPHICS_H

#define gumbo_mons_bn_graphicsTilesLen 28672
extern const bn::tile gumbo_mons_bn_graphicsTiles[bn::max(7168 / 8, 1)];

#define gumbo_mons_bn_graphicsPalLen 32
extern const bn::color gumbo_mons_bn_graphicsPal[16];

#endif // GRIT_GUMBO_MONS_BN_GRAPHICS_H

//}}BLOCK(gumbo_mons_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item gumbo_mons(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(gumbo_mons_bn_graphicsTiles, 896), bpp_mode::BPP_4, compression_type::NONE, 14), 
            sprite_palette_item(span<const color>(gumbo_mons_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

