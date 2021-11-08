#ifndef BN_SPRITE_ITEMS_OCEAN_TERRAIN_H
#define BN_SPRITE_ITEMS_OCEAN_TERRAIN_H

#include "bn_sprite_item.h"

//{{BLOCK(ocean_terrain_bn_graphics)

//======================================================================
//
//	ocean_terrain_bn_graphics, 32x1504@4, 
//	+ palette 16 entries, not compressed
//	+ 752 tiles not compressed
//	Total size: 32 + 24064 = 24096
//
//	Time-stamp: 2021-11-05, 00:18:23
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_OCEAN_TERRAIN_BN_GRAPHICS_H
#define GRIT_OCEAN_TERRAIN_BN_GRAPHICS_H

#define ocean_terrain_bn_graphicsTilesLen 24064
extern const bn::tile ocean_terrain_bn_graphicsTiles[bn::max(6016 / 8, 1)];

#define ocean_terrain_bn_graphicsPalLen 32
extern const bn::color ocean_terrain_bn_graphicsPal[16];

#endif // GRIT_OCEAN_TERRAIN_BN_GRAPHICS_H

//}}BLOCK(ocean_terrain_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item ocean_terrain(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(ocean_terrain_bn_graphicsTiles, 752), bpp_mode::BPP_4, compression_type::NONE, 47), 
            sprite_palette_item(span<const color>(ocean_terrain_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

