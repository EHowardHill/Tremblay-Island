#ifndef BN_SPRITE_ITEMS_SCOUT_WALKING_SPRING_H
#define BN_SPRITE_ITEMS_SCOUT_WALKING_SPRING_H

#include "bn_sprite_item.h"

//{{BLOCK(scout_walking_spring_bn_graphics)

//======================================================================
//
//	scout_walking_spring_bn_graphics, 32x480@4, 
//	+ palette 16 entries, not compressed
//	+ 240 tiles not compressed
//	Total size: 32 + 7680 = 7712
//
//	Time-stamp: 2021-10-31, 20:42:06
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SCOUT_WALKING_SPRING_BN_GRAPHICS_H
#define GRIT_SCOUT_WALKING_SPRING_BN_GRAPHICS_H

#define scout_walking_spring_bn_graphicsTilesLen 7680
extern const bn::tile scout_walking_spring_bn_graphicsTiles[bn::max(1920 / 8, 1)];

#define scout_walking_spring_bn_graphicsPalLen 32
extern const bn::color scout_walking_spring_bn_graphicsPal[16];

#endif // GRIT_SCOUT_WALKING_SPRING_BN_GRAPHICS_H

//}}BLOCK(scout_walking_spring_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item scout_walking_spring(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(scout_walking_spring_bn_graphicsTiles, 240), bpp_mode::BPP_4, compression_type::NONE, 15), 
            sprite_palette_item(span<const color>(scout_walking_spring_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

