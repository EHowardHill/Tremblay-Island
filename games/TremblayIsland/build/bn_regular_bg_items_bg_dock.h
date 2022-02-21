#ifndef BN_REGULAR_BG_ITEMS_BG_DOCK_H
#define BN_REGULAR_BG_ITEMS_BG_DOCK_H

#include "bn_regular_bg_item.h"

//{{BLOCK(bg_dock_bn_graphics)

//======================================================================
//
//	bg_dock_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 498 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 15936 + 2048 = 18016
//
//	Time-stamp: 2022-02-20, 01:35:23
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BG_DOCK_BN_GRAPHICS_H
#define GRIT_BG_DOCK_BN_GRAPHICS_H

#define bg_dock_bn_graphicsTilesLen 15936
extern const bn::tile bg_dock_bn_graphicsTiles[bn::max(3984 / 8, 1)];

#define bg_dock_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell bg_dock_bn_graphicsMap[1024];

#define bg_dock_bn_graphicsPalLen 32
extern const bn::color bg_dock_bn_graphicsPal[16];

#endif // GRIT_BG_DOCK_BN_GRAPHICS_H

//}}BLOCK(bg_dock_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item bg_dock(
            regular_bg_tiles_item(span<const tile>(bg_dock_bn_graphicsTiles, 498), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(bg_dock_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(bg_dock_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

