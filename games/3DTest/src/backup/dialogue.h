#include <string.h>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <list>

#include "bn_core.h"
#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_blending_actions.h"
#include "bn_blending_fade_alpha.h"
#include "bn_blending_fade_alpha_hbe_ptr.h"
#include "bn_blending_transparency_attributes.h"
#include "bn_blending_transparency_attributes_hbe_ptr.h"
#include "bn_config_sprite_text.h"
#include "bn_sprite_text_generator.h"
#include "bn_regular_bg_ptr.h"
#include "bn_utf8_character.h"
#include "bn_log.h"

#include "bn_music.h"
#include "bn_sound_items.h"
#include "bn_music_items_info.h"

#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"
#include "bn_sprite_items_a_button.h"

#include "bn_regular_bg_items_cinemint_studios.h"
#include "bn_regular_bg_items_dialogue_bg.h"

#include "bn_sprite_items_enoki.h"
#include "bn_sprite_items_maple01.h"
#include "bn_sprite_items_maple02.h"
#include "bn_sprite_items_maple03.h"
#include "bn_sprite_items_maple04.h"
#include "bn_sprite_items_maple05.h"
#include "bn_sprite_items_maple06.h"
#include "bn_sprite_items_maple07.h"
#include "bn_sprite_items_maple08.h"
#include "bn_sprite_items_maple09.h"
#include "bn_sprite_items_maple10.h"
#include "bn_sprite_items_enoki01.h"
#include "bn_sprite_items_enoki02.h"
#include "bn_sprite_items_enoki03.h"
#include "bn_sprite_items_enoki04.h"
#include "bn_sprite_items_enoki05.h"
#include "bn_sprite_items_enoki06.h"
#include "bn_sprite_items_enoki07.h"
#include "bn_sprite_items_enoki08.h"
#include "bn_sprite_items_enoki09.h"
#include "bn_sprite_items_enoki10.h"
#include "bn_sprite_items_enoki11.h"
#include "bn_sprite_items_aaron01.h"
#include "bn_sprite_items_aaron02.h"
#include "bn_sprite_items_aaron03.h"
#include "bn_sprite_items_aaron04.h"
#include "bn_sprite_items_aaron05.h"
#include "bn_sprite_items_aaron06.h"
#include "bn_sprite_items_delphine01.h"
#include "bn_sprite_items_delphine02.h"
#include "bn_sprite_items_diana01.h"
#include "bn_sprite_items_nicholas01.h"

#include "bn_regular_bg_items_castle_floor.h"
#include "bn_regular_bg_items_castle01.h"
#include "bn_regular_bg_items_castle02.h"
#include "bn_regular_bg_items_castle03.h"
#include "bn_regular_bg_items_scout_tv_01.h"
#include "bn_regular_bg_items_scout_tv_02.h"
#include "bn_regular_bg_items_scout_tv_03.h"
#include "bn_regular_bg_items_scout_tv_04.h"

#include "bn_regular_bg_items_s0101.h"
#include "bn_regular_bg_items_s0102.h"
#include "bn_regular_bg_items_s0103.h"
#include "bn_regular_bg_items_s0104.h"
#include "bn_regular_bg_items_s0105.h"
#include "bn_regular_bg_items_s0106.h"
#include "bn_regular_bg_items_s0107.h"
#include "bn_regular_bg_items_s0108.h"
#include "bn_regular_bg_items_s0109.h"
#include "bn_regular_bg_items_s0201.h"
#include "bn_regular_bg_items_s0202.h"
#include "bn_regular_bg_items_s0203.h"
#include "bn_regular_bg_items_s0204.h"
#include "bn_regular_bg_items_s0205.h"
#include "bn_regular_bg_items_s0206.h"
#include "bn_regular_bg_items_s0207.h"
#include "bn_regular_bg_items_s0208.h"
#include "bn_regular_bg_items_s0301.h"
#include "bn_regular_bg_items_s0302.h"
#include "bn_regular_bg_items_s0401.h"
#include "bn_regular_bg_items_s0402.h"
#include "bn_regular_bg_items_s0403.h"
#include "bn_regular_bg_items_s0404.h"
#include "bn_regular_bg_items_s0405.h"
#include "bn_regular_bg_items_s0406.h"
#include "bn_regular_bg_items_s0407.h"
#include "bn_regular_bg_items_s0501.h"
#include "bn_regular_bg_items_s0502.h"
#include "bn_regular_bg_items_s0601.h"
#include "bn_regular_bg_items_s0602.h"
#include "bn_regular_bg_items_s0603.h"

#include "bn_regular_bg_items_s0701.h"
#include "bn_regular_bg_items_s0702.h"
#include "bn_regular_bg_items_s0703.h"
#include "bn_regular_bg_items_s0704.h"
#include "bn_regular_bg_items_s0705.h"
#include "bn_regular_bg_items_s0706.h"
#include "bn_regular_bg_items_s0707.h"
#include "bn_regular_bg_items_s0708.h"
#include "bn_regular_bg_items_s0709.h"
#include "bn_regular_bg_items_s0710.h"
#include "bn_regular_bg_items_s0711.h"
#include "bn_regular_bg_items_s0712.h"
#include "bn_regular_bg_items_s0713.h"
#include "bn_regular_bg_items_s0714.h"
#include "bn_regular_bg_items_s0715.h"
#include "bn_regular_bg_items_s0716.h"
#include "bn_regular_bg_items_s0717.h"
#include "bn_regular_bg_items_s0718.h"
#include "bn_regular_bg_items_s0801.h"
#include "bn_regular_bg_items_s0802.h"
#include "bn_regular_bg_items_s0803.h"
#include "bn_regular_bg_items_s0804.h"
#include "bn_regular_bg_items_s0805.h"
#include "bn_regular_bg_items_s0806.h"
#include "bn_regular_bg_items_s0807.h"
#include "bn_regular_bg_items_s0901.h"
#include "bn_regular_bg_items_s0902.h"
#include "bn_regular_bg_items_s0903.h"
#include "bn_regular_bg_items_s0904.h"
#include "bn_regular_bg_items_s0905.h"
#include "bn_regular_bg_items_s0906.h"
#include "bn_regular_bg_items_s0907.h"
#include "bn_regular_bg_items_s0908.h"
#include "bn_regular_bg_items_s0909.h"
#include "bn_regular_bg_items_s0910.h"
#include "bn_regular_bg_items_s0911.h"
#include "bn_regular_bg_items_s0912.h"
#include "bn_regular_bg_items_s0913.h"
#include "bn_regular_bg_items_s0914.h"
#include "bn_regular_bg_items_s0915.h"
#include "bn_regular_bg_items_s0916.h"
#include "bn_regular_bg_items_s0917.h"
#include "bn_regular_bg_items_s0918.h"
#include "bn_regular_bg_items_s1001.h"
#include "bn_regular_bg_items_s1002.h"
#include "bn_regular_bg_items_s1003.h"
#include "bn_regular_bg_items_s1004.h"
#include "bn_regular_bg_items_s1005.h"
#include "bn_regular_bg_items_s1006.h"
#include "bn_regular_bg_items_s1007.h"
#include "bn_regular_bg_items_s1008.h"
#include "bn_regular_bg_items_s1009.h"
#include "bn_regular_bg_items_s1010.h"
#include "bn_regular_bg_items_s1011.h"
#include "bn_regular_bg_items_s1012.h"

#include "bn_regular_bg_items_mountain.h"
#include "bn_regular_bg_items_ocean.h"
#include "bn_regular_bg_items_day_castle.h"
#include "bn_regular_bg_items_bg_docks.h"
#include "bn_regular_bg_items_bg_moody.h"

#include "bn_sprite_items_dialogue_bg_2.h"

#include "bn_regular_bg_items_cruz_01.h"
#include "bn_regular_bg_items_cruz_02.h"

#include "bn_regular_bg_items_real_aaron_01.h"
#include "bn_regular_bg_items_real_aaron_02.h"
#include "bn_regular_bg_items_real_aaron_03.h"
#include "bn_regular_bg_items_real_enoki_01.h"
#include "bn_regular_bg_items_real_enoki_02.h"
#include "bn_regular_bg_items_real_enoki_03.h"
#include "bn_sprite_items_real_aaron_eyes.h"
#include "bn_sprite_items_real_enoki_eyes.h"

// Set pointer by integer reference
void set_sprite(bn::sprite_ptr chari, int value) {
    switch(value) {
        case 1:
            chari.set_item(bn::sprite_items::maple01);
            break;
        case 2:
            chari.set_item(bn::sprite_items::maple02);
            break;
        case 3:
            chari.set_item(bn::sprite_items::maple03);
            break;
        case 4:
            chari.set_item(bn::sprite_items::maple04);
            break;
        case 5:
            chari.set_item(bn::sprite_items::maple05);
            break;
        case 6:
            chari.set_item(bn::sprite_items::enoki01);
            break;
        case 7:
            chari.set_item(bn::sprite_items::enoki02);
            break;
        case 8:
            chari.set_item(bn::sprite_items::enoki03);
            break;
        case 9:
            chari.set_item(bn::sprite_items::enoki04);
            break;
        case 10:
            chari.set_item(bn::sprite_items::aaron01);
            break;
        case 11:
            chari.set_item(bn::sprite_items::aaron02);
            break;
        case 12:
            chari.set_item(bn::sprite_items::delphine01);
            break;
        case 13:
            chari.set_item(bn::sprite_items::delphine02);
            break;

        // Spring
        case 14:
            chari.set_item(bn::sprite_items::maple06);
            break;
        case 15:
            chari.set_item(bn::sprite_items::maple07);
            break;
        case 16:
            chari.set_item(bn::sprite_items::maple08);
            break;
        case 17:
            chari.set_item(bn::sprite_items::maple09);
            break;
        case 18:
            chari.set_item(bn::sprite_items::maple10);
            break;
        case 19:
            chari.set_item(bn::sprite_items::enoki05);
            break;
        case 20:
            chari.set_item(bn::sprite_items::enoki06);
            break;
        case 21:
            chari.set_item(bn::sprite_items::enoki07);
            break;
        case 22:
            chari.set_item(bn::sprite_items::enoki08);
            break;
        case 23:
            chari.set_item(bn::sprite_items::enoki09);
            break;
        case 24:
            chari.set_item(bn::sprite_items::aaron03);
            break;
        case 25:
            chari.set_item(bn::sprite_items::aaron04);
            break;
        case 26:
            chari.set_item(bn::sprite_items::aaron05);
            break;
        case 27:
            chari.set_item(bn::sprite_items::aaron06);
            break;
        case 28:
            chari.set_item(bn::sprite_items::nicholas01);
            break;
        case 29:
            chari.set_item(bn::sprite_items::diana01);
            break;

        case 30:
            chari.set_item(bn::sprite_items::enoki10);
            break;
        case 31:
            chari.set_item(bn::sprite_items::enoki11);
            break;

        default:
            break;
    }
}

// Primary page
void dialogue_page(line n[32]) {

    // Variable initialization
    bn::sprite_text_generator text_line0(common::variable_8x16_sprite_font);
    bn::sprite_ptr chari_l = bn::sprite_items::maple01.create_sprite(-50, -17);
    bn::sprite_ptr chari_r = bn::sprite_items::maple01.create_sprite(50, -17);
    bn::regular_bg_ptr primary_bg = bn::regular_bg_items::castle_floor.create_bg(0, 0);
    bn::sprite_ptr a_button = bn::sprite_items::a_button.create_sprite(-90, -50);
    chari_l.set_visible(false);
    chari_r.set_visible(false);
    chari_r.set_horizontal_flip(true);
    primary_bg.set_visible(false);
    bn::blending::set_intensity_alpha(0);

    bn::regular_bg_ptr dialogue_bg = bn::regular_bg_items::dialogue_bg.create_bg(0, 0);
    dialogue_bg.set_visible(false);

    auto dg_bg1 = bn::sprite_items::dialogue_bg_2.create_sprite(-64, 64 - 16);
    auto dg_bg2 = bn::sprite_items::dialogue_bg_2.create_sprite(64, 64 - 16);
    dg_bg1.set_scale(2,1);
    dg_bg2.set_scale(2,1);
    dg_bg1.set_blending_enabled(true);
    dg_bg2.set_blending_enabled(true);
    float bg_alpha = 0.0;

    // While dialogue is going,
    int pos = 0;
    bool cont = true;
    while (cont) {

        if (n[pos].img > 0) {
            dialogue_bg.set_visible(true);
            dg_bg1.set_visible(false);
            dg_bg2.set_visible(false);
        }

        // Set music
        if (strcmp(n[pos].text, "BG: 0") == 0) {
            int music_volume = 80;
            bn::music_items_info::span[0].first.play(bn::fixed(music_volume) / 100);
        } else if (strcmp(n[pos].text, "BG: 1") == 0) {
            int music_volume = 80;
            bn::music_items_info::span[1].first.play(bn::fixed(music_volume) / 100);
        } else if (strcmp(n[pos].text, "BG: 2") == 0) {
            int music_volume = 80;
            bn::music_items_info::span[2].first.play(bn::fixed(music_volume) / 100);
        } else if (strcmp(n[pos].text, "BG: champ") == 0) {
            int music_volume = 80;
            bn::music_items_info::span[10].first.play(bn::fixed(music_volume) / 100);
        } else if (strcmp(n[pos].text, "BG: Overworld 01") == 0) {
            int music_volume = 80;
            bn::music_items_info::span[11].first.play(bn::fixed(music_volume) / 100);
        } else if (strcmp(n[pos].text, "BG: frog") == 0) {
            int music_volume = 80;
            bn::music_items_info::span[15].first.play(bn::fixed(music_volume) / 100);
        } else if (strcmp(n[pos].text, "BG: news") == 0) {
            int music_volume = 80;
            bn::music_items_info::span[24].first.play(bn::fixed(music_volume) / 100);
        } else if (strcmp(n[pos].text, "BG: rain") == 0) {
            int music_volume = 80;
            bn::music_items_info::span[14].first.play(bn::fixed(music_volume) / 100);
        } else if (strcmp(n[pos].text, "BG: the flame") == 0) {
            int music_volume = 80;
            bn::music_items_info::span[23].first.play(bn::fixed(music_volume) / 100);
        } else if (strcmp(n[pos].text, "BG: maple") == 0) {
            int music_volume = 80;
            bn::music_items_info::span[19].first.play(bn::fixed(music_volume) / 100);
        } else if (strcmp(n[pos].text, "BG: pools") == 0) {
            int music_volume = 80;
            bn::music_items_info::span[30].first.play(bn::fixed(music_volume) / 100);
        } else if (strcmp(n[pos].text, "BG: groovy") == 0) {
            int music_volume = 80;
            bn::music_items_info::span[20].first.play(bn::fixed(music_volume) / 100);
        } else if (strcmp(n[pos].text, "BG: fadeout") == 0) {
            if (bn::music::playing()) {
                bn::music::set_volume(0);
            }

        // Sound effects
        } else if (strcmp(n[pos].text, "SF: Hey Maple") == 0) {
            bn::sound_items::heymaple.play();
        } else if (strcmp(n[pos].text, "SF: Maple Ugh") == 0) {
            bn::sound_items::maple_ugh_01.play();
        } else if (strcmp(n[pos].text, "SF: Rufus Squeak") == 0) {
            bn::sound_items::rufus_01.play();
        } else if (strcmp(n[pos].text, "SF: Rufus Laugh") == 0) {
            bn::sound_items::rufus_02.play();
        } else if (strcmp(n[pos].text, "SF: Boom") == 0) {
            bn::sound_items::boom.play();

        // Set backgrounds
        } else if (strcmp(n[pos].text, "BG: Ocean") == 0) {
            primary_bg.set_item(bn::regular_bg_items::ocean);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "BG: Forest") == 0) {
            primary_bg.set_item(bn::regular_bg_items::mountain);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "BG: Moody") == 0) {
            primary_bg.set_item(bn::regular_bg_items::bg_moody);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "BG: CRUZ01") == 0) {
            primary_bg.set_item(bn::regular_bg_items::cruz_01);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "BG: CRUZ02") == 0) {
            primary_bg.set_item(bn::regular_bg_items::cruz_02);
            primary_bg.set_visible(true);

        } else if (strcmp(n[pos].text, "BG: Trailer Home") == 0) {
            primary_bg.set_item(bn::regular_bg_items::bg_trailer_home);
            primary_bg.set_visible(true);
            primary_bg.set_position(88,-64);


        } else if (strcmp(n[pos].text, "S01:01") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0101);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S01:02") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0102);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S01:03") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0103);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S01:04") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0104);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S01:05") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0105);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S01:06") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0106);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S01:07") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0107);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S01:08") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0108);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S01:09") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0109);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S01:10") == 0) {
            primary_bg.set_item(bn::regular_bg_items::castle01);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S01:11") == 0) {
            primary_bg.set_item(bn::regular_bg_items::castle02);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S01:12") == 0) {
            primary_bg.set_item(bn::regular_bg_items::castle03);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S01:13") == 0) {
            primary_bg.set_item(bn::regular_bg_items::day_castle);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S02:01") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0201);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S02:02") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0202);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S02:03") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0203);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S02:04") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0204);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S02:05") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0205);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S02:06") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0206);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S02:07") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0207);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S02:08") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0208);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S03:01") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0301);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S03:02") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0302);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S04:01") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0401);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S04:02") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0402);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S04:03") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0403);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S04:04") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0404);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S04:05") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0405);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S04:06") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0406);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S04:07") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0407);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S05:01") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0501);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S05:02") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0502);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S06:01") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0601);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S06:02") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0602);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S06:03") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0603);
            primary_bg.set_visible(true);

        } else if (strcmp(n[pos].text, "S07:01") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0701);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S07:02") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0702);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S07:03") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0703);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S07:04") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0704);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S07:05") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0705);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S07:06") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0706);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S07:07") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0707);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S07:08") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0708);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S07:09") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0709);
            primary_bg.set_visible(true);

        } else if (strcmp(n[pos].text, "S07:10") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0710);
            primary_bg.set_visible(true);

        } else if (strcmp(n[pos].text, "S07:11") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0711);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S07:12") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0712);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S07:13") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0713);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S07:14") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0714);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S07:15") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0715);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S07:16") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0716);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S07:17") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0717);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S07:18") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0718);
            primary_bg.set_visible(true);

        } else if (strcmp(n[pos].text, "S08:01") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0801);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S08:02") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0802);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S08:03") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0803);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S08:04") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0804);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S08:05") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0805);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S08:06") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0806);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S08:07") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0807);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S09:01") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0901);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S09:02") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0902);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S09:03") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0903);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S09:04") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0904);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S09:05") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0905);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S09:06") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0906);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S09:07") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0907);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S09:08") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0908);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S09:09") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0909);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S09:10") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0910);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S09:11") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0911);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S09:12") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0912);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S09:13") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0913);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S09:14") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0914);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S09:15") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0915);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S09:16") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0916);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S09:17") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0917);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S09:18") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s0918);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S10:01") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s1001);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S10:02") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s1002);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S10:03") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s1003);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S10:04") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s1004);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S10:05") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s1005);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S10:06") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s1006);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S10:07") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s1007);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S10:08") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s1008);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S10:09") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s1009);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S10:10") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s1010);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S10:11") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s1011);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S10:12") == 0) {
            primary_bg.set_item(bn::regular_bg_items::s1012);
            primary_bg.set_visible(true);

        } else if (strcmp(n[pos].text, "S_STV_01") == 0) {
            primary_bg.set_item(bn::regular_bg_items::scout_tv_01);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S_STV_02") == 0) {
            primary_bg.set_item(bn::regular_bg_items::scout_tv_02);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S_STV_03") == 0) {
            primary_bg.set_item(bn::regular_bg_items::scout_tv_03);
            primary_bg.set_visible(true);
        } else if (strcmp(n[pos].text, "S_STV_04") == 0) {
            primary_bg.set_item(bn::regular_bg_items::scout_tv_04);
            primary_bg.set_visible(true);

        } else if (strcmp(n[pos].text, "S_DOCKS") == 0) {
            primary_bg.set_item(bn::regular_bg_items::bg_docks);
            primary_bg.set_visible(true);
        

        // End dialogue
        } else if (strcmp(n[pos].text, "COM: Endscene") == 0) {
            cont = false;

        } else if (strcmp(n[pos].text, "COM: Popup") == 0) {
            dialogue_bg.set_visible(true);

        // Handle sprite/dialogue
        } else {

            // Process initial transparency states
            if (n[pos].img != 0) {
                if (n[pos].left) {
                    if (n[pos].transition || n[pos].img == -1) chari_l.set_visible(false);
                    if (!chari_l.visible() && n[pos].img != -1) {
                        chari_r.set_blending_enabled(false);
                        chari_l.set_blending_enabled(true);
                        bn::blending::set_transparency_alpha(0);
                        chari_l.set_x(-50);
                        chari_l.set_visible(true);
                    }
                    set_sprite(chari_l, n[pos].img);
                } else {
                    if (n[pos].transition || n[pos].img == -1) chari_r.set_visible(false);
                    if (!chari_r.visible() && n[pos].img != -1) {
                        chari_l.set_blending_enabled(false);
                        chari_r.set_blending_enabled(true);
                        bn::blending::set_transparency_alpha(0);
                        chari_r.set_x(50);
                        chari_r.set_visible(true);
                    }
                    set_sprite(chari_r, n[pos].img);
                }
            }

            // SFX
            bn::sound_items::pop.play(0.5);

            // Fresh init
            bn::vector<bn::sprite_ptr, 33> text_sprite0;
            bn::vector<bn::sprite_ptr, 33> text_sprite2;
            bn::vector<bn::sprite_ptr, 33> text_sprite3;
            bn::vector<bn::sprite_ptr, 33> text_sprite4;
            bn::vector<bn::sprite_ptr, 33> text_sprite5;
            char line1[42] = {0};
            char line3[42] = {0};
            char line4[42] = {0};
            char line5[42] = {0};
            char line6[42] = {0};

            BN_LOG(n[pos].text);
            for (int t = 0; t < 33; t++) if (n[pos].text[t] < 256) {line1[t] = n[pos].text[t];} else {line1[t] = ' ';};
            for (int t = 0; t < 33; t++) if (n[pos].text[t] < 256) {line3[t] = n[pos].text[t + 33];} else {line3[t] = ' ';};
            for (int t = 0; t < 33; t++) if (n[pos].text[t] < 256) {line4[t] = n[pos].text[t + 66];} else {line4[t] = ' ';};
            for (int t = 0; t < 33; t++) if (n[pos].text[t] < 256) {line5[t] = n[pos].text[t + 99];} else {line5[t] = ' ';};
            for (int t = 0; t < 32; t++) if (n[pos].text[t] < 256) {line6[t] = n[pos].text[t + 132];} else {line6[t] = ' ';};

            text_line0.generate(-108, 21, line1, text_sprite0);
            text_line0.generate(-108, 33, line3, text_sprite2);
            text_line0.generate(-108, 45, line4, text_sprite3);
            text_line0.generate(-108, 57, line5, text_sprite4);
            text_line0.generate(-108, 69, line6, text_sprite5);

            // Hide all text
            for (int t = 0; t < text_sprite0.size(); t++) {text_sprite0.at(t).set_visible(false); text_sprite0.at(t).set_rotation_angle(12);}
            for (int t = 0; t < text_sprite2.size(); t++) {text_sprite2.at(t).set_visible(false); text_sprite2.at(t).set_rotation_angle(12);}
            for (int t = 0; t < text_sprite3.size(); t++) {text_sprite3.at(t).set_visible(false); text_sprite3.at(t).set_rotation_angle(12);}
            for (int t = 0; t < text_sprite4.size(); t++) {text_sprite4.at(t).set_visible(false); text_sprite4.at(t).set_rotation_angle(12);}
            for (int t = 0; t < text_sprite5.size(); t++) {text_sprite5.at(t).set_visible(false); text_sprite5.at(t).set_rotation_angle(12);}

            dialogue_bg.put_above();
            bn::core::update();

            // Process visual effects
            int ticker = 0;
            int ticker_delay = 0;
            while(!bn::keypad::a_pressed()) {

                for (int t = 0; t < text_sprite0.size(); t++) if (text_sprite0.at(t).visible() && text_sprite0.at(t).rotation_angle() > 0) {text_sprite0.at(t).set_rotation_angle(text_sprite0.at(t).rotation_angle() - 1);}
                for (int t = 0; t < text_sprite2.size(); t++) if (text_sprite2.at(t).visible() && text_sprite2.at(t).rotation_angle() > 0) {text_sprite2.at(t).set_rotation_angle(text_sprite2.at(t).rotation_angle() - 1);}
                for (int t = 0; t < text_sprite3.size(); t++) if (text_sprite3.at(t).visible() && text_sprite3.at(t).rotation_angle() > 0) {text_sprite3.at(t).set_rotation_angle(text_sprite3.at(t).rotation_angle() - 1);}
                for (int t = 0; t < text_sprite4.size(); t++) if (text_sprite4.at(t).visible() && text_sprite4.at(t).rotation_angle() > 0) {text_sprite4.at(t).set_rotation_angle(text_sprite4.at(t).rotation_angle() - 1);}
                for (int t = 0; t < text_sprite5.size(); t++) if (text_sprite5.at(t).visible() && text_sprite5.at(t).rotation_angle() > 0) {text_sprite5.at(t).set_rotation_angle(text_sprite5.at(t).rotation_angle() - 1);}

                if (ticker < 160) {
                    if (ticker_delay == 0) {
                        int ticked = ticker % 32;
                        if (ticker >= 0 && ticker < 32) {
                            if (text_sprite0.size() > ticked) {
                                text_sprite0.at(ticked).set_visible(true);
                                bn::sound_items::click.play();
                            } else {
                                ticker = 31;
                            }
                        }
                        if (ticker >= 32 && ticker < 64) {
                            if (text_sprite2.size() > ticked) {
                                text_sprite2.at(ticked).set_visible(true);
                                bn::sound_items::click.play();
                            } else {
                                ticker = 63;
                            }
                        }
                        if (ticker >= 64 && ticker < 96) {
                            if (text_sprite3.size() > ticked) {
                                text_sprite3.at(ticked).set_visible(true);
                                bn::sound_items::click.play();
                            } else {
                                ticker = 95;
                            }
                        }
                        if (ticker >= 96 && ticker < 128) {
                            if (text_sprite4.size() > ticked) {
                                text_sprite4.at(ticked).set_visible(true);
                                bn::sound_items::click.play();
                            } else {
                                ticker = 127;
                            }
                        }
                        if (ticker >= 128 && ticker < 160) {
                            if (text_sprite5.size() > ticked) {
                                text_sprite5.at(ticked).set_visible(true);
                                bn::sound_items::click.play();
                            } else {
                                ticker = 160;
                            }
                        }
                        ticker++;
                    }
                    ticker_delay = (ticker_delay + 1) % 2;
                }

                if (dialogue_bg.visible()) {

                    // Move in from side
                    if (chari_l.visible() && chari_l.x().integer() < -40) chari_l.set_x(chari_l.x() + 1);
                    if (chari_r.visible() && chari_r.x().integer() > 40) chari_r.set_x(chari_r.x() - 1);

                    // Handle transparency
                    if (bn::blending::transparency_alpha().to_double() + 0.1 <= 1) {
                        bn::blending::set_transparency_alpha(bn::blending::transparency_alpha().to_double() + 0.1);
                    } else {
                        bn::blending::set_transparency_alpha(1);
                        chari_l.set_blending_enabled(false);
                    }

                } else {

                    // Handle dialogue background sprite box
                    if (bg_alpha < 0.9 && text_sprite0.size() > 0) {
                        bg_alpha += 0.05;
                        bn::blending::set_transparency_alpha(bg_alpha);
                    }
                }

                dialogue_bg.put_above();
                bn::core::update();
            }
        }

        // Increment location
        pos++;
    }

    // Process visual effects
    while(bg_alpha > 0.1) {
        bg_alpha -= 0.1;
        if (bg_alpha < 0) bg_alpha = 0;
        bn::blending::set_transparency_alpha(bg_alpha);
        bn::core::update();
    }

    dg_bg1.set_visible(false);
    dg_bg2.set_visible(false);
    bn::blending::set_transparency_alpha(1);
}

void dialogue_page_lite(line n[32]) {

    // Variable initialization
    bn::sprite_text_generator text_line0(common::variable_8x16_sprite_font);
    bn::sprite_ptr a_button = bn::sprite_items::a_button.create_sprite(-90, -50);
    auto dg_bg1 = bn::sprite_items::dialogue_bg_2.create_sprite(-64, 64);
    auto dg_bg2 = bn::sprite_items::dialogue_bg_2.create_sprite(64, 64);
    dg_bg1.set_scale(2,1);
    dg_bg2.set_scale(2,1);
    dg_bg1.set_blending_enabled(true);
    dg_bg2.set_blending_enabled(true);
    float bg_alpha = 0.0;
    bn::blending::set_intensity_alpha(0);

    // While dialogue is going,
    int pos = 0;
    bool cont = true;

    int enoki_spoken = false;
    int maple_spoken = false;
    int aaron_spoken = false;
    int scout_spoken = false;
    int vee_spoken = false;
    int el_spoken = false;
    int diana_spoken = false;
    int guy_spoken = false;

    while (cont) {

        // End dialogue
        if (strcmp(n[pos].text, "COM: Endscene") == 0) {
            cont = false;

        // Handle sprite/dialogue
        } else {

            // SFX
            bn::sound_items::pop.play(0.5);

            // Fresh init
            bn::vector<bn::sprite_ptr, 33> text_sprite0;
            bn::vector<bn::sprite_ptr, 33> text_sprite2;
            bn::vector<bn::sprite_ptr, 33> text_sprite3;
            bn::vector<bn::sprite_ptr, 33> text_sprite4;
            bn::vector<bn::sprite_ptr, 33> text_sprite5;
            char line1[48] = {0};
            char line3[48] = {0};
            char line4[48] = {0};
            char line5[48] = {0};
            char line6[48] = {0};

            BN_LOG(n[pos].text);
            for (int t = 0; t < 33; t++) if (n[pos].text[t] < 256) {line1[t] = n[pos].text[t];} else {line1[t] = ' ';};
            for (int t = 0; t < 33; t++) if (n[pos].text[t] < 256) {line3[t] = n[pos].text[t + 33];} else {line3[t] = ' ';};
            for (int t = 0; t < 33; t++) if (n[pos].text[t] < 256) {line4[t] = n[pos].text[t + 66];} else {line4[t] = ' ';};
            for (int t = 0; t < 33; t++) if (n[pos].text[t] < 256) {line5[t] = n[pos].text[t + 99];} else {line5[t] = ' ';};
            for (int t = 0; t < 32; t++) if (n[pos].text[t] < 256) {line6[t] = n[pos].text[t + 132];} else {line6[t] = ' ';};
            text_line0.generate(-108, 21, line1, text_sprite0);
            text_line0.generate(-108, 33, line3, text_sprite2);
            text_line0.generate(-108, 45, line4, text_sprite3);
            text_line0.generate(-108, 57, line5, text_sprite4);
            text_line0.generate(-108, 69, line6, text_sprite5);

            if (!enoki_spoken && strncmp(line4, "ENOKI", 5) == 0) {
                bn::sound_items::enoki_hey.play();
                enoki_spoken = true;
            }

            if (!maple_spoken && strncmp(line4, "MAPLE", 5) == 0) {
                bn::sound_items::maple_hey_01.play();
                maple_spoken = true;
            }

            if (!aaron_spoken && strncmp(line4, "AARON", 5) == 0) {
                if (pos < 2) {
                    bn::sound_items::aaron_hey_01.play();
                } else {
                    bn::sound_items::aaron_hey_02.play();
                }
                aaron_spoken = true;
            }

            if (!scout_spoken && strncmp(line4, "SCOUT", 5) == 0) {
                bn::sound_items::scout_hey_01.play();
                scout_spoken = true;
            }

            if (!vee_spoken && strncmp(line4, "OLIVIER", 7) == 0) {
                bn::sound_items::vee_hey_01.play();
                vee_spoken = true;
            }

            if (!el_spoken && strncmp(line4, "ELEANOR", 7) == 0) {
                bn::sound_items::eleanor_hey_01.play();
                el_spoken = true;
            }

            if (!diana_spoken && strncmp(line4, "DIANA", 5) == 0) {
                bn::sound_items::diana_hey_01.play();
                diana_spoken = true;
            }

            if (!guy_spoken && strncmp(line4, "GUY", 3) == 0) {
                bn::sound_items::guy_hey_01.play();
                guy_spoken = true;
            }

            // Process visual effects
            while(!bn::keypad::a_pressed()) {
                if (bg_alpha < 0.9) {
                    bg_alpha += 0.05;
                    bn::blending::set_transparency_alpha(bg_alpha);
                }

                bn::core::update();
            }

            bn::core::update();
        }

        // Increment location
        pos++;
    }

    // Process visual effects
    while(bg_alpha > 0.1) {
        bg_alpha -= 0.1;
        if (bg_alpha < 0) bg_alpha = 0;
        bn::blending::set_transparency_alpha(bg_alpha);
        bn::core::update();
    }

    dg_bg1.set_visible(false);
    dg_bg2.set_visible(false);
    bn::blending::set_transparency_alpha(1);
}