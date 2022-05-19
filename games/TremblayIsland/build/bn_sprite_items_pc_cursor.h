#ifndef BN_SPRITE_ITEMS_PC_CURSOR_H
#define BN_SPRITE_ITEMS_PC_CURSOR_H

#include "bn_sprite_item.h"

//{{BLOCK(pc_cursor_bn_graphics)

//======================================================================
//
//	pc_cursor_bn_graphics, 32x64@4, 
//	+ palette 16 entries, not compressed
//	+ 32 tiles not compressed
//	Total size: 32 + 1024 = 1056
//
//	Time-stamp: 2022-05-17, 22:36:30
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.18
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PC_CURSOR_BN_GRAPHICS_H
#define GRIT_PC_CURSOR_BN_GRAPHICS_H

#define pc_cursor_bn_graphicsTilesLen 1024
extern const bn::tile pc_cursor_bn_graphicsTiles[bn::max(256 / 8, 1)];

#define pc_cursor_bn_graphicsPalLen 32
extern const bn::color pc_cursor_bn_graphicsPal[16];

#endif // GRIT_PC_CURSOR_BN_GRAPHICS_H

//}}BLOCK(pc_cursor_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item pc_cursor(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(pc_cursor_bn_graphicsTiles, 32), bpp_mode::BPP_4, compression_type::NONE, 2), 
            sprite_palette_item(span<const color>(pc_cursor_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

