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
        make_pair(music_item(16), string_view("z08_award")),
        make_pair(music_item(17), string_view("z09_scout_lab")),
        make_pair(music_item(18), string_view("z10_enoki_theme")),
        make_pair(music_item(19), string_view("z11_maple_theme")),
        make_pair(music_item(20), string_view("z12_groovy")),
        make_pair(music_item(21), string_view("z12_overworld_night")),
        make_pair(music_item(22), string_view("z13_spooky")),
        make_pair(music_item(23), string_view("z14_flame")),
        make_pair(music_item(24), string_view("z15_flame")),
        make_pair(music_item(25), string_view("z16_boat")),
        make_pair(music_item(26), string_view("z17_ptit")),
        make_pair(music_item(27), string_view("z18_houses")),
        make_pair(music_item(28), string_view("z19_digital")),
        make_pair(music_item(29), string_view("z20_waves")),
        make_pair(music_item(30), string_view("z21_pools")),
        make_pair(music_item(31), string_view("z22_cbx")),
        make_pair(music_item(32), string_view("z23_diana")),
        make_pair(music_item(33), string_view("z24_cruz")),
        make_pair(music_item(34), string_view("z25_funky")),
    };

    constexpr inline span<const pair<music_item, string_view>> span(array);
}

#endif

