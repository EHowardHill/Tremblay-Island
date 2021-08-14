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
#include "bn_sprite_items_a_button.h"

#include "bn_regular_bg_items_mountain.h"
#include "bn_regular_bg_items_ocean.h"
#include "bn_sprite_items_variable_8x16_font_yellow.h"

#include "bn_sound_items.h"
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

#include "objects.h"
#include "scenes.h"

// Custom variables

namespace
{
    const int TEXT_X = -108;
    const int TEXT_Y = 24;
    const int TEXT_MAX_CHARS = 33;
    const int WAITFOR = 100000;
    
    static bn::vector<bn::sprite_ptr, 32> text_sprite01;
    static bn::vector<bn::sprite_ptr, 32> text_sprite02;
    static bn::vector<bn::sprite_ptr, 32> text_sprite03;
    static bn::vector<bn::sprite_ptr, 32> text_sprite04;
    static bn::vector<bn::sprite_ptr, 32> text_sprite05;
    static bn::vector<bn::sprite_ptr, 32> text_sprite06;
    static bn::sprite_text_generator text_line01(common::variable_8x16_sprite_font);
    static bn::sprite_text_generator text_line02(common::variable_8x16_sprite_font);
    static bn::sprite_text_generator text_line03(common::variable_8x16_sprite_font);
    static bn::sprite_text_generator text_line04(common::variable_8x16_sprite_font);
    static bn::sprite_text_generator text_line05(common::variable_8x16_sprite_font);
    static bn::sprite_text_generator text_line06(common::variable_8x16_sprite_font);

    void second_draw(const char* txt) {
        bn::sound_items::pop.play(0.5);

        char line1[33], line2[33], line3[33], line4[33], line5[33], line6[33];
        strncpy(line1, txt + (33 * 0), 33);
        strncpy(line2, txt + (33 * 1), 33);
        strncpy(line3, txt + (33 * 2), 33);
        strncpy(line4, txt + (33 * 3), 33);
        strncpy(line5, txt + (33 * 4), 33);
        strncpy(line6, txt + (33 * 5), 33);

        text_sprite01.clear();
        text_line01.generate(-108, 22, line1, text_sprite01);
        int x = 0;

        for (int t = 0; t < WAITFOR; t += 1) {
            x += 1;
        }
        x = 0;

        text_sprite02.clear();
        text_line02.generate(-108, 32, line2, text_sprite02);

        for (int t = 0; t < WAITFOR; t += 1) {
            
        }

        text_sprite03.clear();
        text_line03.generate(-108, 42, line3, text_sprite03);

        for (int t = 0; t < WAITFOR; t += 1) {
            
        }

        text_sprite04.clear();
        text_line04.generate(-108, 52, line4, text_sprite04);

        for (int t = 0; t < WAITFOR; t += 1) {
            
        }

        text_sprite05.clear();
        text_line05.generate(-108, 62, line5, text_sprite05);

        for (int t = 0; t < WAITFOR; t += 1) {
            
        }

        text_sprite06.clear();
        text_line06.generate(-108, 72, line6, text_sprite06);
    }

    void dialogue_page()
    {   
        static bn::sprite_ptr a_button = bn::sprite_items::a_button.create_sprite(-90, -50);

        //bn::regular_bg_ptr castle_bg = bn::regular_bg_items::castle.create_bg(0, 0);
        static bn::sprite_ptr chari_l = bn::sprite_items::enoki.create_sprite(-90, -25);
        static bn::sprite_ptr chari_r = bn::sprite_items::enoki.create_sprite(90, -25);
        static bn::regular_bg_ptr primary_bg = bn::regular_bg_items::ocean.create_bg(0, 0);
        chari_l.set_scale(1.25);
        chari_l.set_visible(false);
        chari_r.set_scale(1.25);
        chari_r.set_visible(false);

        int pos = 0;
        while(true) {

            // Set backgrounds
            if (strcmp(scenes::n1[pos].text, "BG: Ocean") == 0) {
                primary_bg.set_item(bn::regular_bg_items::ocean);
            } else if (strcmp(scenes::n1[pos].text, "BG: Forest") == 0) {
                primary_bg.set_item(bn::regular_bg_items::mountain);
            } else if (strcmp(scenes::n1[pos].text, "S01:01") == 0) {
                primary_bg.set_item(bn::regular_bg_items::s0101);
            } else if (strcmp(scenes::n1[pos].text, "S01:02") == 0) {
                primary_bg.set_item(bn::regular_bg_items::s0102);
            } else if (strcmp(scenes::n1[pos].text, "S01:03") == 0) {
                primary_bg.set_item(bn::regular_bg_items::s0103);
            } else if (strcmp(scenes::n1[pos].text, "S01:04") == 0) {
                primary_bg.set_item(bn::regular_bg_items::s0104);
            // Handle sprite/dialogue
            } else {

                switch(scenes::n1[pos].img) {
                    case 1:
                        if (!chari_l.visible()) {
                            chari_l.set_blending_enabled(true);
                            bn::blending::set_transparency_alpha(0);
                            chari_l.set_x(-90);
                            chari_l.set_visible(true);
                        }
                        chari_l.set_item(bn::sprite_items::enoki);
                        break;
                    default:
                        break;
                }

                second_draw(scenes::n1[pos].text);
                bn::core::update();

                while(!bn::keypad::a_pressed()) {
                    if (chari_l.x().integer() < -80) {
                        chari_l.set_x(chari_l.x() + 1);
                    }

                    if (bn::blending::transparency_alpha().to_double() + 0.1 <= 1) {
                        bn::blending::set_transparency_alpha(bn::blending::transparency_alpha().to_double() + 0.1);
                    } else {
                        bn::blending::set_transparency_alpha(1);
                        chari_l.set_blending_enabled(false);
                    }

                    bn::core::update();
                }
            }

            pos++;
        }
    }
}

int main()
{
    bn::core::init();
    
    int music_item_index = 0;
    int music_volume = 15;
    bn::music_items_info::span[music_item_index].first.play(bn::fixed(music_volume) / 100);

    while(true)
    {
        dialogue_page();
        bn::core::update();
    }
}
