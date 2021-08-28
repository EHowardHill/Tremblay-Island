#ifndef BN_SPRITE_ITEMS_ENOKI_WALKING_PJ_H
#define BN_SPRITE_ITEMS_ENOKI_WALKING_PJ_H

#include "bn_sprite_item.h"

//{{BLOCK(enoki_walking_pj_bn_graphics)

//======================================================================
//
//	enoki_walking_pj_bn_graphics, 32x384@4, 
//	+ palette 16 entries, not compressed
//	+ 192 tiles not compressed
//	Total size: 32 + 6144 = 6176
//
//	Time-stamp: 2021-08-25, 21:58:46
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ENOKI_WALKING_PJ_BN_GRAPHICS_H
#define GRIT_ENOKI_WALKING_PJ_BN_GRAPHICS_H

#define enoki_walking_pj_bn_graphicsTilesLen 6144
extern const bn::tile enoki_walking_pj_bn_graphicsTiles[bn::max(1536 / 8, 1)];

#define enoki_walking_pj_bn_graphicsPalLen 32
extern const bn::color enoki_walking_pj_bn_graphicsPal[16];

#endif // GRIT_ENOKI_WALKING_PJ_BN_GRAPHICS_H

//}}BLOCK(enoki_walking_pj_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item enoki_walking_pj(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(enoki_walking_pj_bn_graphicsTiles, 192), bpp_mode::BPP_4, compression_type::NONE, 12), 
            sprite_palette_item(span<const color>(enoki_walking_pj_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

