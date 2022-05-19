#ifndef BN_SPRITE_ITEMS_BOOKSHELF_H
#define BN_SPRITE_ITEMS_BOOKSHELF_H

#include "bn_sprite_item.h"

//{{BLOCK(bookshelf_bn_graphics)

//======================================================================
//
//	bookshelf_bn_graphics, 64x128@4, 
//	+ palette 16 entries, not compressed
//	+ 128 tiles not compressed
//	Total size: 32 + 4096 = 4128
//
//	Time-stamp: 2022-05-17, 22:36:29
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.18
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BOOKSHELF_BN_GRAPHICS_H
#define GRIT_BOOKSHELF_BN_GRAPHICS_H

#define bookshelf_bn_graphicsTilesLen 4096
extern const bn::tile bookshelf_bn_graphicsTiles[bn::max(1024 / 8, 1)];

#define bookshelf_bn_graphicsPalLen 32
extern const bn::color bookshelf_bn_graphicsPal[16];

#endif // GRIT_BOOKSHELF_BN_GRAPHICS_H

//}}BLOCK(bookshelf_bn_graphics)

namespace bn::sprite_items
{
    constexpr inline sprite_item bookshelf(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(bookshelf_bn_graphicsTiles, 128), bpp_mode::BPP_4, compression_type::NONE, 2), 
            sprite_palette_item(span<const color>(bookshelf_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

