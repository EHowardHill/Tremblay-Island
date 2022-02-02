#ifndef BN_REGULAR_BG_ITEMS_PC_SCOUT_H
#define BN_REGULAR_BG_ITEMS_PC_SCOUT_H

#include "bn_regular_bg_item.h"

//{{BLOCK(pc_scout_bn_graphics)

//======================================================================
//
//	pc_scout_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 221 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 7072 + 2048 = 9152
//
//	Time-stamp: 2022-01-26, 07:36:09
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PC_SCOUT_BN_GRAPHICS_H
#define GRIT_PC_SCOUT_BN_GRAPHICS_H

#define pc_scout_bn_graphicsTilesLen 7072
extern const bn::tile pc_scout_bn_graphicsTiles[bn::max(1768 / 8, 1)];

#define pc_scout_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell pc_scout_bn_graphicsMap[1024];

#define pc_scout_bn_graphicsPalLen 32
extern const bn::color pc_scout_bn_graphicsPal[16];

#endif // GRIT_PC_SCOUT_BN_GRAPHICS_H

//}}BLOCK(pc_scout_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item pc_scout(
            regular_bg_tiles_item(span<const tile>(pc_scout_bn_graphicsTiles, 221), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(pc_scout_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(pc_scout_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

