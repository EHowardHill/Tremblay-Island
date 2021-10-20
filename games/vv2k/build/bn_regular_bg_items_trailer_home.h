#ifndef BN_REGULAR_BG_ITEMS_TRAILER_HOME_H
#define BN_REGULAR_BG_ITEMS_TRAILER_HOME_H

#include "bn_regular_bg_item.h"

//{{BLOCK(trailer_home_bn_graphics)

//======================================================================
//
//	trailer_home_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 321 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 10272 + 2048 = 12352
//
//	Time-stamp: 2021-10-17, 23:52:33
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TRAILER_HOME_BN_GRAPHICS_H
#define GRIT_TRAILER_HOME_BN_GRAPHICS_H

#define trailer_home_bn_graphicsTilesLen 10272
extern const bn::tile trailer_home_bn_graphicsTiles[bn::max(2568 / 8, 1)];

#define trailer_home_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell trailer_home_bn_graphicsMap[1024];

#define trailer_home_bn_graphicsPalLen 32
extern const bn::color trailer_home_bn_graphicsPal[16];

#endif // GRIT_TRAILER_HOME_BN_GRAPHICS_H

//}}BLOCK(trailer_home_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item trailer_home(
            regular_bg_tiles_item(span<const tile>(trailer_home_bn_graphicsTiles, 321), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(trailer_home_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(trailer_home_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

