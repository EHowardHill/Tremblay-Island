#ifndef BN_REGULAR_BG_ITEMS_FILE_SELECT_BG_H
#define BN_REGULAR_BG_ITEMS_FILE_SELECT_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(file_select_bg_bn_graphics)

//======================================================================
//
//	file_select_bg_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 182 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 5824 + 2048 = 7904
//
//	Time-stamp: 2022-03-10, 17:41:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FILE_SELECT_BG_BN_GRAPHICS_H
#define GRIT_FILE_SELECT_BG_BN_GRAPHICS_H

#define file_select_bg_bn_graphicsTilesLen 5824
extern const bn::tile file_select_bg_bn_graphicsTiles[bn::max(1456 / 8, 1)];

#define file_select_bg_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell file_select_bg_bn_graphicsMap[1024];

#define file_select_bg_bn_graphicsPalLen 32
extern const bn::color file_select_bg_bn_graphicsPal[16];

#endif // GRIT_FILE_SELECT_BG_BN_GRAPHICS_H

//}}BLOCK(file_select_bg_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item file_select_bg(
            regular_bg_tiles_item(span<const tile>(file_select_bg_bn_graphicsTiles, 182), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(file_select_bg_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(file_select_bg_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

