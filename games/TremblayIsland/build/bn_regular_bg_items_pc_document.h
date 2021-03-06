#ifndef BN_REGULAR_BG_ITEMS_PC_DOCUMENT_H
#define BN_REGULAR_BG_ITEMS_PC_DOCUMENT_H

#include "bn_regular_bg_item.h"

//{{BLOCK(pc_document_bn_graphics)

//======================================================================
//
//	pc_document_bn_graphics, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 140 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 4480 + 2048 = 6560
//
//	Time-stamp: 2022-03-28, 02:39:22
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PC_DOCUMENT_BN_GRAPHICS_H
#define GRIT_PC_DOCUMENT_BN_GRAPHICS_H

#define pc_document_bn_graphicsTilesLen 4480
extern const bn::tile pc_document_bn_graphicsTiles[bn::max(1120 / 8, 1)];

#define pc_document_bn_graphicsMapLen 2048
extern const bn::regular_bg_map_cell pc_document_bn_graphicsMap[1024];

#define pc_document_bn_graphicsPalLen 32
extern const bn::color pc_document_bn_graphicsPal[16];

#endif // GRIT_PC_DOCUMENT_BN_GRAPHICS_H

//}}BLOCK(pc_document_bn_graphics)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item pc_document(
            regular_bg_tiles_item(span<const tile>(pc_document_bn_graphicsTiles, 140), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(pc_document_bn_graphicsPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(pc_document_bn_graphicsMap[0], size(32, 32), compression_type::NONE));
}

#endif

