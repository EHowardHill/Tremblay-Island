#ifndef BN_REGULAR_BG_ITEMS_PC_DESKTOP_H
#define BN_REGULAR_BG_ITEMS_PC_DESKTOP_H

#include "bn_regular_bg_item.h"

//{{BLOCK(pc_desktop_bn_graphics)

//======================================================================
//
//	pc_desktop_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 106 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 3392 + 2048 = 5472
//
//	Time-stamp: 2022-03-10, 17:41:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PC_DESKTOP_BN_GRAPHICS_H
#define GRIT_PC_DESKTOP_BN_GRAPHICS_H

#define pc_desktop_bn_graphicsTilesLen 3392
extern const bn::tile pc_desktop_bn_graphicsTiles[bn::max(848 / 8, 1)];

#define pc_desktop_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell pc_desktop_bn_graphicsMap[1024];

#define pc_desktop_bn_graphicsPalLen 32
extern const bn::color pc_desktop_bn_graphicsPal[16];

#endif // GRIT_PC_DESKTOP_BN_GRAPHICS_H

//}}BLOCK(pc_desktop_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item pc_desktop(
            regular_bg_tiles_item(span<const tile>(pc_desktop_bn_graphicsTiles, 106), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(pc_desktop_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(pc_desktop_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

