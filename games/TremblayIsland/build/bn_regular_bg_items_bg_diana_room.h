#ifndef BN_REGULAR_BG_ITEMS_BG_DIANA_ROOM_H
#define BN_REGULAR_BG_ITEMS_BG_DIANA_ROOM_H

#include "bn_regular_bg_item.h"

//{{BLOCK(bg_diana_room_bn_graphics)

//======================================================================
//
//	bg_diana_room_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 773 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 24736 + 2048 = 26816
//
//	Time-stamp: 2021-11-27, 06:58:52
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BG_DIANA_ROOM_BN_GRAPHICS_H
#define GRIT_BG_DIANA_ROOM_BN_GRAPHICS_H

#define bg_diana_room_bn_graphicsTilesLen 24736
extern const bn::tile bg_diana_room_bn_graphicsTiles[bn::max(6184 / 8, 1)];

#define bg_diana_room_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell bg_diana_room_bn_graphicsMap[1024];

#define bg_diana_room_bn_graphicsPalLen 32
extern const bn::color bg_diana_room_bn_graphicsPal[16];

#endif // GRIT_BG_DIANA_ROOM_BN_GRAPHICS_H

//}}BLOCK(bg_diana_room_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item bg_diana_room(
            regular_bg_tiles_item(span<const tile>(bg_diana_room_bn_graphicsTiles, 773), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(bg_diana_room_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(bg_diana_room_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif
