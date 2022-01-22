#ifndef BN_REGULAR_BG_ITEMS_DIALOGUE_BG_H
#define BN_REGULAR_BG_ITEMS_DIALOGUE_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(dialogue_bg_bn_graphics)

//======================================================================
//
//	dialogue_bg_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 157 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 5024 + 2048 = 7104
//
//	Time-stamp: 2022-01-22, 04:49:13
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_DIALOGUE_BG_BN_GRAPHICS_H
#define GRIT_DIALOGUE_BG_BN_GRAPHICS_H

#define dialogue_bg_bn_graphicsTilesLen 5024
extern const bn::tile dialogue_bg_bn_graphicsTiles[bn::max(1256 / 8, 1)];

#define dialogue_bg_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell dialogue_bg_bn_graphicsMap[1024];

#define dialogue_bg_bn_graphicsPalLen 32
extern const bn::color dialogue_bg_bn_graphicsPal[16];

#endif // GRIT_DIALOGUE_BG_BN_GRAPHICS_H

//}}BLOCK(dialogue_bg_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item dialogue_bg(
            regular_bg_tiles_item(span<const tile>(dialogue_bg_bn_graphicsTiles, 157), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(dialogue_bg_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(dialogue_bg_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

