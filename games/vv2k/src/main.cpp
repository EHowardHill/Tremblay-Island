/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#include "bn_core.h"
#include "bn_music.h"
#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_regular_bg_ptr.h"
#include "bn_blending_actions.h"
#include "bn_blending_fade_alpha.h"
#include "bn_sprite_text_generator.h"
#include "bn_blending_fade_alpha_hbe_ptr.h"
#include "bn_blending_transparency_attributes.h"
#include "bn_blending_transparency_attributes_hbe_ptr.h"

#include "bn_sprite_items_enoki.h"
#include "bn_regular_bg_items_mountain.h"
#include "bn_sprite_items_variable_8x16_font_yellow.h"

#include "bn_music_items_info.h"

#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"

#include "bn_config_sprite_text.h"
#include "bn_sprite_font.h"
#include "bn_sprite_text_generator.h"
#include "bn_utf8_character.h"

#include <string.h>
#include <cstdlib>
#include <cstring>
#include <sstream>

#include "Dialogue.h"

// Custom variables

namespace
{
    const Dialogue::line scene01[3] = {
        {true, true, 0, "Haw haw"},
        {true, true, 0, "Yee yee"},
        {true, true, 0, "Yeah"}
    };

    const int TEXT_X = -108;
    const int TEXT_Y = 24;
    const int TEXT_MAX_CHARS = 33;
    
    static bn::vector<bn::sprite_ptr, 32> txt_spr;
    static bn::sprite_text_generator txt_gen(common::variable_8x16_sprite_font);

    void second_draw(const char* txt) {
        txt_spr.clear();
        txt_gen.generate(-108, 24, txt, txt_spr);
    }

    void dialogue_page(bn::sprite_ptr& chari)
    {   
        chari.set_scale(1.25);

        int pos = 0;
        while(true) {
            second_draw(scene01[pos].text.c_str());
            bn::core::update();

            while(!bn::keypad::a_pressed()) {
                if (chari.x().integer() < -80) {
                    chari.set_x(chari.x() + 1);
                }

                bn::core::update();
            }
            pos++;
        }
    }
}

int main()
{
    bn::core::init();
    
    int music_item_index = 0;
    int music_volume = 0;
    bn::music_items_info::span[music_item_index].first.play(bn::fixed(music_volume) / 100);

    bn::regular_bg_ptr mountain_bg = bn::regular_bg_items::mountain.create_bg(0, 0);
    //bn::regular_bg_ptr castle_bg = bn::regular_bg_items::castle.create_bg(0, 0);
    bn::sprite_ptr enoki = bn::sprite_items::enoki.create_sprite(-90, -25);

    while(true)
    {
        dialogue_page(enoki);
        bn::core::update();
    }
}
