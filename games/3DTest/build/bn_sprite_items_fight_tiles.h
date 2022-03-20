#ifndef BN_SPRITE_ITEMS_FIGHT_TILES_H
#define BN_SPRITE_ITEMS_FIGHT_TILES_H

#include "bn_sprite_item.h"

//{{BLOCK(fight_tiles_bn_graphics)

//======================================================================
//
//	fight_tiles_bn_graphics, 32x64@4, 
//	+ palette 16 entries, not compressed
//	+ 32 tiles not compressed
//	Total size: 32 + 1024 = 1056
//
//	Time-stamp: 2022-03-10, 17:41:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FIGHT_TILES_BN_GRAPHICS_H
#define GRIT_FIGHT_TILES_BN_GRAPHICS_H

#define fight_tiles_bn_graphicsTilesLen 1024
extern const bn::tile fight_tiles_bn_graphicsTiles[bn::max(256 / 8, 1)];

#define fight_tiles_bn_graphicsPalLen 32
extern const bn::color fight_tiles_bn_graphicsPal[16];

#endif // GRIT_FIGHT_TILES_BN_GRAPHICS_H

//}}BLOCK(fight_tiles_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item fight_tiles(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(fight_tiles_bn_graphicsTiles, 32), bpp_mode::BPP_4, compression_type::NONE, 2), 
            sprite_palette_item(span<const color>(fight_tiles_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

