#ifndef BN_REGULAR_BG_ITEMS_AXE_GAME_BG_H
#define BN_REGULAR_BG_ITEMS_AXE_GAME_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(axe_game_bg_bn_graphics)

//======================================================================
//
//	axe_game_bg_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 614 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 19648 + 2048 = 21728
//
//	Time-stamp: 2021-11-02, 21:28:55
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_AXE_GAME_BG_BN_GRAPHICS_H
#define GRIT_AXE_GAME_BG_BN_GRAPHICS_H

#define axe_game_bg_bn_graphicsTilesLen 19648
extern const bn::tile axe_game_bg_bn_graphicsTiles[bn::max(4912 / 8, 1)];

#define axe_game_bg_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell axe_game_bg_bn_graphicsMap[1024];

#define axe_game_bg_bn_graphicsPalLen 32
extern const bn::color axe_game_bg_bn_graphicsPal[16];

#endif // GRIT_AXE_GAME_BG_BN_GRAPHICS_H

//}}BLOCK(axe_game_bg_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item axe_game_bg(
            regular_bg_tiles_item(span<const tile>(axe_game_bg_bn_graphicsTiles, 614), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(axe_game_bg_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(axe_game_bg_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

