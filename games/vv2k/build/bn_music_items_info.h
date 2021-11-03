#ifndef BN_MUSIC_ITEMS_INFO_H
#define BN_MUSIC_ITEMS_INFO_H

#include "bn_span.h"
#include "bn_music_item.h"
#include "bn_string_view.h"

namespace bn::music_items_info
{
    constexpr inline pair<music_item, string_view> array[] = {
        make_pair(music_item(0), string_view("castle")),
        make_pair(music_item(1), string_view("fruit")),
        make_pair(music_item(2), string_view("new_castle")),
        make_pair(music_item(3), string_view("title")),
        make_pair(music_item(4), string_view("twinkle")),
        make_pair(music_item(5), string_view("v01")),
        make_pair(music_item(6), string_view("v02")),
        make_pair(music_item(7), string_view("v02_b")),
        make_pair(music_item(8), string_view("velvet")),
        make_pair(music_item(9), string_view("z01_maple_is_sad")),
        make_pair(music_item(10), string_view("z02_the_champ")),
        make_pair(music_item(11), string_view("z03_overworld")),
        make_pair(music_item(12), string_view("z04_underground")),
        make_pair(music_item(13), string_view("z05_victory")),
        make_pair(music_item(14), string_view("z06_dangerous")),
        make_pair(music_item(15), string_view("z07_frog")),
        make_pair(music_item(16), string_view("z08_rain")),
        make_pair(music_item(17), string_view("z09_scout_lab")),
        make_pair(music_item(18), string_view("z10_enoki_theme")),
        make_pair(music_item(19), string_view("z11_maple_theme")),
        make_pair(music_item(20), string_view("z12_aaron_theme")),
    };

    constexpr inline span<const pair<music_item, string_view>> span(array);
}

#endif

