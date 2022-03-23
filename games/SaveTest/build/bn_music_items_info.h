#ifndef BN_MUSIC_ITEMS_INFO_H
#define BN_MUSIC_ITEMS_INFO_H

#include "bn_span.h"
#include "bn_music_item.h"
#include "bn_string_view.h"

namespace bn::music_items_info
{
    constexpr inline span<const pair<music_item, string_view>> span;
}

#endif

