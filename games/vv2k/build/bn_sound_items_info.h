#ifndef BN_SOUND_ITEMS_INFO_H
#define BN_SOUND_ITEMS_INFO_H

#include "bn_span.h"
#include "bn_sound_item.h"
#include "bn_string_view.h"

namespace bn::sound_items_info
{
    constexpr inline pair<sound_item, string_view> array[] = {
        make_pair(sound_item(12), string_view("heymaple")),
        make_pair(sound_item(13), string_view("pop")),
        make_pair(sound_item(14), string_view("shortclip")),
        make_pair(sound_item(15), string_view("ui_sfx01")),
        make_pair(sound_item(16), string_view("ui_sfx02")),
        make_pair(sound_item(17), string_view("ui_sfx03")),
    };

    constexpr inline span<const pair<sound_item, string_view>> span(array);
}

#endif

