#include <string.h>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <list>
#include <math.h>

#include "bn_core.h"
#include "bn_log.h"

#include "bn_music.h"
#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_bg_palettes.h"
#include "bn_bgs_mosaic.h"
#include "bn_sprites_mosaic.h"
#include "bn_colors.h"
#include "bn_random.h"
#include "bn_math.h"
#include "bn_window.h"
#include "bn_rect_window_actions.h"
#include "bn_rect_window_boundaries_hbe_ptr.h"
#include "bn_sram.h"

#include "bn_sound_items.h"
#include "bn_music_items_info.h"

#include "common_info.h"

// Special items
#include "bn_regular_bg_items_cinemint_studios.h"
#include "bn_regular_bg_items_titlebackground.h"
#include "bn_regular_bg_items_velvet.h"
#include "bn_sprite_items_biglogo.h"
#include "bn_sprite_items_titlebackground_trees.h"

#include "bn_sprite_items_arrow.h"
#include "bn_regular_bg_items_file_select_bg.h"

#include "bn_regular_bg_items_intro_final_1.h"
#include "bn_regular_bg_items_intro_final_2.h"
#include "bn_regular_bg_items_tbc.h"

#include "bn_sprite_items_selection.h"
#include "bn_regular_bg_items_keyboard_bg.h"

// Extended headers
#include "objects.h"
#include "save.h"
#include "dialogue.h"
#include "scripts.h"
#include "wander.h"
#include "keyboard.h"

// tree cut
#include "bn_sprite_items_horizontal_bar.h"
#include "bn_sprite_items_chop_bar.h"
#include "bn_sprite_items_ax_bar.h"
#include "bn_sprite_items_enoki_victory_anim.h"
#include "bn_sprite_items_power_meter.h"
#include "bn_regular_bg_items_fun_background.h"
#include "bn_regular_bg_items_sidebar.h"

void timer(int delay) {
    for (int t = 0; t < delay; t++) {
        bn::core::update();
    }
}

void startup() {

    //bn::regular_bg_ptr
    auto header = bn::regular_bg_items::cinemint_studios.create_bg(0,0);
    auto ocean = bn::regular_bg_items::titlebackground.create_bg(0,0);
    ocean.set_visible(false);

    header.set_mosaic_enabled(true);
    float glow = 0.5;
    int intro_stage = 0;
    int height = -24;
    auto item0 = bn::sprite_items::biglogo.create_sprite(-32 - 48, -32 + height, 0);
    auto item1 = bn::sprite_items::biglogo.create_sprite(32 - 48, -34 + height, 2);
    auto item2 = bn::sprite_items::biglogo.create_sprite(-32 - 48, 32 + height, 1);
    auto item3 = bn::sprite_items::biglogo.create_sprite(32 - 48, 30 + height, 3);
    item0.set_mosaic_enabled(true);
    item1.set_mosaic_enabled(true);
    item2.set_mosaic_enabled(true);
    item3.set_mosaic_enabled(true);

    auto tree1 = bn::sprite_items::titlebackground_trees.create_sprite(64 + 16,-32);
    auto tree2 = bn::sprite_items::titlebackground_trees.create_sprite(64 + 32,-32);
    auto trees_left = bn::create_sprite_animate_action_forever(tree1, 12, bn::sprite_items::titlebackground_trees.tiles_item(), 0, 1);
    auto trees_right = bn::create_sprite_animate_action_forever(tree2, 12, bn::sprite_items::titlebackground_trees.tiles_item(), 2, 3);
    tree1.set_visible(false);
    tree2.set_visible(false);

    while(!bn::keypad::start_pressed()) {
        trees_left.update();
        trees_right.update();
        tree1 = trees_left.sprite();
        tree2 = trees_right.sprite();

        switch(intro_stage) {
            case 0:
                item0.set_visible(false);
                item1.set_visible(false);
                item2.set_visible(false);
                item3.set_visible(false);
                if (glow - 0.02 > 0) {
                    glow -= 0.02;
                    bn::bgs_mosaic::set_horizontal_stretch(glow);
                    bn::bgs_mosaic::set_vertical_stretch(glow);
                } else {
                    header.set_mosaic_enabled(false);
                    intro_stage++;
                }
                break;
            case 1:
                bn::sound_items::ahoy.play();
                header.set_blending_enabled(true);
                intro_stage++;
                break;
            case 2:
                timer(32);
                glow = 1;
                intro_stage++;
                break;
            case 3:
                if (glow - 0.02 > 0) {
                    glow -= 0.02;
                    bn::blending::set_transparency_alpha(glow);
                } else {
                    intro_stage++;
                }
                break;
            case 4:
                glow = 0.5;
                bn::music_items_info::span[3].first.play(bn::fixed(50) / 100);
                timer(16);
                intro_stage++;
                break;
            case 5:
                item0.set_visible(true);
                item1.set_visible(true);
                item2.set_visible(true);
                item3.set_visible(true);
                if (glow - 0.01 > 0) {
                    glow -= 0.01;
                    bn::sprites_mosaic::set_horizontal_stretch(glow);
                    bn::sprites_mosaic::set_vertical_stretch(glow);
                } else {
                    intro_stage++;
                }
                break;
            case 6:
                ocean.set_visible(true);
                tree1.set_visible(true);
                tree2.set_visible(true);
                intro_stage++;
                break;
            default: {
                item0.set_y(-32 + height);
                item1.set_y(-34 + height);
                item2.set_y(32 + height);
                item3.set_y(30 + height);
                break;
            }
        }
        bn::core::update();
    }
}

void load_save() {

    auto velvet = bn::regular_bg_items::velvet.create_bg(0,0);
    auto ui = bn::regular_bg_items::file_select_bg.create_bg(0,0);
    auto arrow = bn::sprite_items::arrow.create_sprite(-98, - 32);

    bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
    bn::vector<bn::sprite_ptr, 12> file1_spr;
    file1_gen.generate(-72, -32, "Slot 1", file1_spr);

    bn::sprite_text_generator file2_gen(common::variable_8x16_sprite_font);
    bn::vector<bn::sprite_ptr, 12> file2_spr;
    file2_gen.generate(-72, 0, "Slot 2", file2_spr);

    bn::sprite_text_generator file3_gen(common::variable_8x16_sprite_font);
    bn::vector<bn::sprite_ptr, 12> file3_spr;
    file3_gen.generate(-72, 32, "Slot 3", file3_spr);

    int t = 0;
    int c = 0;

    bn::music_items_info::span[8].first.play(bn::fixed(50) / 100);

    while(!bn::keypad::a_pressed()) {
        
        // Scrolling background
        t++;
        t = t % 256;
        velvet.set_position(t,t);

        if (bn::keypad::up_pressed()) {
            c -= 1;
            if (c < 0) c = 2;
            bn::sound_items::pop.play();
        } else if (bn::keypad::down_pressed()) {
            c += 1;
            if (c > 2) c = 0;
            bn::sound_items::pop.play();
        }

        arrow.set_y(-32 + (32 * c));
        bn::core::update();
    }

    bn::sound_items::firehit.play();
    bn::music::stop();
    timer(256);
}

void introduction() {
    dungeon_return dt(0,0,0);
    dt.spawn_x = 0;
    dt.spawn_y = 0;
    dt.world_index = 0;
    while (true) {
        dungeon_return dt2 = dungeon(dt);
        if (dt2.world_index == -1) break;
    };
}

void cutscenes(int c) {
    if (c == 0) {
        bn::sound_items::birds.play();
        bn::music_items_info::span[9].first.play(bn::fixed(25) / 100);
        bn::regular_bg_ptr f1 = bn::regular_bg_items::intro_final_1.create_bg(0,0);
        bn::regular_bg_ptr f2 = bn::regular_bg_items::intro_final_2.create_bg(0,0);
        f2.set_blending_enabled(true);
        bn::blending::set_transparency_alpha(0);
        f1.put_below();
        timer(32);
        float see = 0;
        f2.set_visible(true);
        for (int t = 0; t < 256; t++) {
            bn::blending::set_transparency_alpha(see);
            float c_see = see + 0.01;
            if (c_see <= 1) see = c_see;
            bn::core::update();
        }
    } else if (c == 1) {
        bool isPlayed = false;
        bn::regular_bg_ptr text = bn::regular_bg_items::s0201.create_bg(0, 0);
        bn::music::stop();
        if (!isPlayed) {
            bn::sound_items::firehit.play();
            isPlayed = true;
        }
        timer(96);
    }
}

void tree_cut() {
    auto cursor = bn::sprite_items::ax_bar.create_sprite(0,0);

    int score = 100;
    char buf[16];
    char bf2[16];
    bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
    bn::vector<bn::sprite_ptr, 16> file1_spr;
    bn::vector<bn::sprite_ptr, 16> file2_spr;

    bn::vector<bn::sprite_ptr,16> bars;
    bn::vector<bn::sprite_ptr,16> chop;
    bn::random random;
    for (int t = 0; t < 14; t++) bars.push_back(bn::sprite_items::horizontal_bar.create_sprite(((t - 7) * 8) + 4,0));

    float curs = 0;
    int width = 16;
    int calc_width = width * 4;
    int max_chop = 4;
    int hits = 1;
    bool left = false;
    int total = 0;
    for (int t = 0; t < max_chop; t++) {
        int x_pos = -(calc_width / 2) + (random.get() % calc_width);
        x_pos = (x_pos / 16) * 16;
        chop.push_back(bn::sprite_items::chop_bar.create_sprite(x_pos, 0));
    }

    while(true) {

        sprintf(buf, "Score: %d", score);
        sprintf(bf2, "Total: %d", total);
        file1_spr.clear();
        file2_spr.clear();        
        file1_gen.generate(-114, -70, buf, file1_spr);
        file1_gen.generate(-114, -58, bf2, file2_spr);

        curs += 1 + (score / 200);
        if (curs > 200) curs = 0;
        float curs_f = curs;
        int curs_i = curs_f / 32;
        int dir = ((curs) / 20);
        int curs_loc = sin(curs_f / 32) * calc_width;

        if (score > total) total = score;

        if (dir > 2 && dir < 8) { //left
            if (bn::keypad::a_held()) {
                cursor.set_scale(1.1);
            } else {
                cursor.set_scale(1);
            }
            cursor.put_above();
            left = true;
        } else { // right
            if (left) {
                cursor.set_scale(0.9);
                for (int t = 0; t < max_chop; t++) {
                    if (chop.at(t).visible()) score = score / 2;
                }

                hits = 1;
                bn::sound_items::ui_sfx01.play();
                chop.clear();
                max_chop = 4 + (score / 1000);
                if (max_chop > 16) max_chop = 16;

                for (int t = 0; t < max_chop; t++) {
                    int x_pos = -(calc_width / 2) + (random.get() % calc_width);
                    x_pos = (x_pos / 4) * 4;
                    chop.push_back(bn::sprite_items::chop_bar.create_sprite(x_pos, 0));
                }
            }
            cursor.put_below();
            left = false;
        }

        for (int t = 0; t < max_chop; t++) {
            if (left) {
                if (chop.at(t).visible() && chop.at(t).x().integer() > curs_loc - 6) {
                    //chop.at(t).set_visible(false);
                    //score = 0;
                }
            }
        }

        if (bn::keypad::a_pressed() && left) {
            bool penalty = true;
            for (int t = 0; t < max_chop; t++) {
                int c_x = chop.at(t).x().integer();
                if (curs_loc + 8 > c_x - 16 && curs_loc + 8 < c_x + 16) {
                    chop.at(t).set_visible(false);
                    if (hits < 5) {
                        bn::sound_items::firehit.play();
                        hits++;
                    }
                    score += hits;
                    penalty = false;
                }
            }
            if (penalty) {
                score -= (score / 5);
            }
        }

        cursor.set_x(curs_loc);
        bn::core::update();
    }
}

class rabbit {
    public:
        bn::sprite_ptr sprite = bn::sprite_items::horizontal_bar.create_sprite(0,0);
        bool moving = true;
        bool carry = false;
        int spend = 0;
        int dir = 0;
        float x_vector = 0;
        float y_vector = 1;
        int init_y = 0;
        bool enabled = true;
        rabbit() {}

        void move() {
            if (spend > 0) {
                if (sprite.x() < 0 || sprite.x() > 240 || sprite.y() < 0 || sprite.y() > 160) {
                    sprite.set_visible(false);
                }
                float sine = sinf((64 - spend) / 21);
                switch(dir) {
                    case 0:
                        sprite.set_position(sprite.x(), sprite.y() + 3);
                        break;
                    case 1:
                        sprite.set_position(sprite.x() + 3, init_y + (sine * 20.01));
                        break;
                    case 2:
                        sprite.set_position(sprite.x() - 3, init_y + (sine * 20.01));
                        break;
                    case 3:
                        sprite.set_position(sprite.x(), sprite.y() - 3);
                        break;
                }
                spend--;
            } else if (moving) {
                sprite.set_position(sprite.x() + x_vector, sprite.y() + y_vector);
            }
        }
};

void rabbit_game() {
    bn::vector<rabbit, 8> rabbits;
    auto max_rabbits = 6;
    bn::random rnd;
    bn::camera_ptr camera = bn::camera_ptr::create(0,0);

    char buf[16];
    char bf2[16];
    bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
    bn::vector<bn::sprite_ptr, 16> file1_spr;
    bn::vector<bn::sprite_ptr, 16> file2_spr;

    bn::vector<bn::sprite_ptr,16> bars;
    bn::vector<bn::sprite_ptr,16> chop;

    bool isHolding = false;
    bool heldItem = 0;

    room myRoom;

    int local[406] = {
        2,2,2,2,2,2,2,2,2,
        2,0,0,0,0,0,0,0,2,
        2,0,0,0,0,0,0,0,2,
        2,0,0,0,0,0,0,0,2,
        2,2,2,2,2,2,2,2,2
    };
    for (int t = 0; t < myRoom.width * myRoom.height; t++) {
        myRoom.local_tileset[t] = local[t];
    }
    myRoom.width = 9;
    myRoom.height = 5;
    myRoom.start_x = 4;
    myRoom.start_y = 2;
    camera.set_position(myRoom.start_x * 32, myRoom.start_y * 32);

    character enoki(bn::sprite_items::enoki_walking_pj, myRoom, myRoom.start_x, myRoom.start_y, true);
    enoki.entity.set_camera(camera);

    for (int t = 0; t < max_rabbits; t++) {
        rabbit r;
        r.sprite.set_camera(camera);
        rabbits.push_back(r);
    }

    int score = 0;
    int total = 0;
    int score_meter = 0;
    bool playing = true;

    while(playing) {

        score_meter++;
        if (score_meter == 50) {
            score_meter = 0;
            if (score > 0) score -= 1;
        }

        sprintf(buf, "Score: %d", score);
        sprintf(bf2, "Total: %d", total);
        file1_spr.clear();
        file2_spr.clear();        
        file1_gen.generate(-114, -70, buf, file1_spr);
        file1_gen.generate(-114, -58, bf2, file2_spr);

        enoki.update();

        bool allOut = true;
        for (int t = 0; t < max_rabbits; t++) {
            if (rabbits.at(t).sprite.visible()) {
                allOut = false;
                if (rabbits.at(t).sprite.y() < enoki.entity.y() + 4) {
                    rabbits.at(t).sprite.put_below();
                } else {
                    rabbits.at(t).sprite.put_above();
                }

                if (rabbits.at(t).carry) {
                    rabbits.at(t).sprite.set_position(enoki.entity.x(), enoki.entity.y() - 12);
                    rabbits.at(t).sprite.put_above();
                } else {
                    rabbits.at(t).move();
                }
            } else if (rabbits.at(t).enabled) {
                rabbits.at(t).enabled = false;
                bn::sound_items::firecrackle.play();
                score += 25;
            }
        }
        if (allOut) {
            playing = false;
        }

        // Random init
        if (rnd.get() % 20 == 0) {
            for (int t = 0; t < max_rabbits; t++) {
                if (rnd.get() % 3 == 0) {
                    rabbits.at(t).moving = false;
                } else {
                    rabbits.at(t).moving = true;
                    signed int c_x = (rnd.get() % 4) - 2;
                    signed int c_y = (rnd.get() % 4) - 2;

                    if (rabbits.at(t).sprite.x().integer() > 190) {
                        c_x = -2;
                    } else if (rabbits.at(t).sprite.x().integer() < 50) {
                        c_x = 2;
                    }

                    if (rabbits.at(t).sprite.y().integer() > 120) {
                        c_y = -2;
                    } else if (rabbits.at(t).sprite.y().integer() < 40) {
                        c_y = 2;
                    }

                    rabbits.at(t).x_vector = c_x;
                    rabbits.at(t).y_vector = c_y;
                }
            }
        }

        if (bn::keypad::a_pressed()) {
            if (isHolding) {
                bn::sound_items::cnaut.play();
                for (int t = 0; t < max_rabbits; t++) {
                    if (rabbits.at(t).carry) {
                        rabbits.at(t).init_y = enoki.entity.y().integer();
                        rabbits.at(t).dir = enoki.dir;
                        rabbits.at(t).carry = false;
                        rabbits.at(t).spend = 64;
                    }
                }
                isHolding = false;
            } else {
                for (int t = 0; t < max_rabbits; t++) {
                    if (
                        (std::abs(rabbits.at(t).sprite.x().integer() - enoki.entity.x().integer()) < 8) &&
                        (std::abs(rabbits.at(t).sprite.y().integer() - enoki.entity.y().integer()) < 16)
                    ) {
                        bn::sound_items::squeak.play();
                        isHolding = true;
                        heldItem = t;
                        rabbits.at(t).carry = true;
                        t = max_rabbits;
                    }
                }
            }
        }

        bn::core::update();
    }

    bn::sound_items::ahoy.play();

    while(true) {
        enoki.update();
        bn::core::update();
    }
}

class creepy_crawly {
    public:
        bn::sprite_ptr sprite = bn::sprite_items::chop_bar.create_sprite(0,0);
        bool moving = true;
        bool carry = false;
        int spend = 0;
        int dir = 0;
        int x_vector = 1;
        int y_vector = 1;
        int to_x = 0;
        int to_y = 0;
        int init_y = 0;
        bool enabled = true;
        room* current_room;
        creepy_crawly() {}
        bn::random rand;

        void update() {
            int mx = sprite.x().integer() / 32;
            int my = sprite.y().integer() / 32;
            int mz = mx + (my * current_room -> width);

            if (mx == to_x && my == to_y) {
                to_x = 0;
                to_y = 0;
            }

            if (to_x == 0 && to_y == 0) {
                int dir = rand.get() % 4;
                switch(dir) {
                    case 0:
                        if (current_room -> local_tileset[mz + 1] == 0) {
                            to_x = mx + 1;
                            to_y = my;
                        }
                        break;
                    case 1:
                        if (current_room -> local_tileset[mz + current_room -> width] == 0) {
                            to_y = my + 1;
                            to_x = mx;
                        }
                        break;
                    case 2:
                        if (current_room -> local_tileset[mz - 1] == 0) {
                            to_x = mx - 1;
                            to_y = my;
                        }
                        break;
                    case 3:
                        if (current_room -> local_tileset[mz - current_room -> width] == 0) {
                            to_y = my - 1;
                            to_x = mx;
                        }
                        break;
                }
            } else {
                int vector_x = 0;
                if (mx < to_x) {
                    vector_x++;
                } else if (mx > to_x) {
                    vector_x--;
                }

                int vector_y = 0;
                if (my < to_y) {
                    vector_y++;
                } else if (my > to_y) {
                    vector_y--;
                }

                sprite.set_position(sprite.x().integer() + (vector_x * 2), sprite.y().integer() + (vector_y * 2));
            }
        }
};

void underground() {
    bn::camera_ptr camera = bn::camera_ptr::create(0,0);
    bn::regular_bg_ptr back_floor = bn::regular_bg_items::castle_floor.create_bg(0,0);
    bn::regular_bg_ptr back_black = bn::regular_bg_items::velvet.create_bg(0,0);
    back_floor.set_camera(camera);
    back_black.set_camera(camera);

    bn::blending::set_transparency_alpha(0.9);

    char buf[16];
    bn::sprite_text_generator file_gen(common::variable_8x16_sprite_font);
    bn::vector<bn::sprite_ptr, 16> file_spr;
    bn::vector<bn::sprite_ptr,16> bars;
    
    bn::rect_window external_window = bn::rect_window::external();
    external_window.set_show_bg(back_floor, false);
    external_window.set_show_bg(back_black, true);
    external_window.set_show_sprites(false);
    external_window.set_boundaries(-80, -120, 80, 120);

    bn::rect_window internal_window = bn::rect_window::internal();
    internal_window.set_show_bg(back_floor, true);
    internal_window.set_show_bg(back_black, false);
    internal_window.set_show_sprites(true);
    internal_window.set_camera(camera);

    const int w_size = 96;
    stone local_walls[w_size];
    int local_walls_p = 0;
    room current_room;
    bn::random rnd;

    current_room.init(20, 20, 16, 16);
    int local[406] = {
        4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,5,
        2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
        2,0,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,0,2,
        2,0,2,0,0,0,0,0,0,2,0,2,0,0,0,0,0,2,0,2,
        2,0,2,0,2,2,2,2,2,2,0,2,2,2,2,2,0,2,0,2,
        2,0,2,0,2,0,0,0,0,2,0,0,0,0,0,2,0,2,0,2,
        2,0,2,0,2,0,2,2,0,2,2,2,0,0,0,2,0,2,0,2,
        2,0,2,0,2,0,2,0,0,2,0,3,0,3,0,2,0,2,0,2,
        2,0,2,0,2,0,0,0,0,2,0,0,0,3,2,2,0,2,0,2,
        2,0,2,0,0,0,0,0,0,2,0,0,0,3,0,0,0,2,0,2,
        2,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,2,
        2,0,2,0,2,0,3,3,3,3,3,3,3,0,0,0,0,2,0,2,
        2,0,2,0,2,0,0,0,0,0,0,0,0,0,2,0,2,2,0,2,
        2,0,2,0,2,0,3,3,3,3,3,3,3,0,2,0,2,0,0,2,
        2,0,2,0,2,0,2,0,0,0,0,0,2,0,2,3,3,0,0,2,
        2,0,2,0,2,0,2,0,0,0,0,0,2,0,2,0,0,0,0,2,
        2,0,0,0,2,0,2,0,0,0,0,0,2,0,2,0,0,0,0,2,
        2,0,0,0,0,0,2,2,2,0,2,2,2,2,2,0,0,0,0,2,
        2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
        7,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,6
        };
    for (int t = 0; t < current_room.width * current_room.height; t++) {
        current_room.local_tileset[t] = local[t];
    }

    character maple = character(
        bn::sprite_items::maple_walking,
        current_room,
        current_room.start_x,
        current_room.start_y,
        true);
    maple.entity.set_camera(camera);

    creepy_crawly bugs[24];
    for (int t = 0; t < 24; t++) {
        bugs[t].sprite.set_camera(camera);
        int mx = (rnd.get() % (current_room.width - 6));
        int my = (rnd.get() % (current_room.height - 6));
        while (current_room.local_tileset[mx + (my * current_room.width)] > 0) {
            mx = (rnd.get() % (current_room.width - 6));
            my = (rnd.get() % (current_room.height - 6));
        }
        bugs[t].sprite.set_position(mx * 32, my * 32);
        bugs[t].current_room = &current_room;
    }

    // Make a fireball!
    int p_index = 0;
    int p_size = 3;
    projectile p[3];
    for (int t = 0; t < 3; t++) {
        p[t].fireball.set_camera(camera);
        p[t].fireball.set_visible(false);
    }

    int update_counter = 0;
    int flex = 84;
    int brightness = 1;

    camera.set_position(maple.entity.x(), maple.entity.y());
    int score = 0;
    int forgiveness = 0;

    int abx = 0;
    int aby = 0;
    while (current_room.local_tileset[abx + (current_room.width * aby)] > 0) {
        abx = rnd.get() % (current_room.width - 6);
        aby = rnd.get() % (current_room.height - 6);
    }
    bn::sprite_ptr treasure = bn::sprite_items::a_button_2.create_sprite(abx * 32, aby * 32);
    treasure.set_camera(camera);
    bool is_done = false;

    bn::sprite_ptr destination = bn::sprite_items::bookshelf.create_sprite(maple.entity.x(), maple.entity.y());
    destination.set_camera(camera);
    destination.set_visible(false);

    while(true) {

        sprintf(buf, "%d", score);
        file_spr.clear();    
        file_gen.generate( - (countDigit(score-1) * 3), -24, buf, file_spr);

        // Create projectiles
        if (bn::keypad::r_pressed()) {
            if (score > 50) {
                score -= 50;
            }
            bn::sound_items::fireblast.play();
            p[p_index].active = true;
            p[p_index].fireball.set_x(maple.entity.x());
            p[p_index].fireball.set_y(maple.entity.y());
            p[p_index].dir = maple.dir;
            p[p_index].dur = 0;
            p[p_index].fireball.set_visible(true);
            p_index++;
            if (p_index >= p_size) p_index = 0;
        }

        // Check collision
        int mx = maple.entity.x().integer();
        int my = maple.entity.y().integer();
        if (forgiveness < 1) {
            for (int t = 0; t < 24; t++) {
                if (abs(mx - bugs[t].sprite.x().integer()) + abs(my - bugs[t].sprite.y().integer()) < 16) {
                    score -= 100;
                    bn::sound_items::squeak.play();
                    forgiveness = 2000;

                    // Move the treasure
                    int abx = 0;
                    int aby = 0;
                    while (current_room.local_tileset[abx + (current_room.width * aby)] > 0) {
                        abx = rnd.get() % (current_room.width - 6);
                        aby = rnd.get() % (current_room.height - 6);
                    }
                    treasure.set_position(abx * 32, aby * 32);
                    treasure.set_visible(true);
                    bool is_done = false;
                }
                if (score < 0) {
                    score = 0;
                    maple.entity.set_position(current_room.start_x * 32, current_room.start_y * 32);
                }
            }
        } else {
            forgiveness = 0;
        }

        // Update projectiles
        for (int t = 0; t < p_size; t++) {
            if (p[t].active) {
                if (p[t].dir == 3) p[t].fireball.put_above();
                p[t].update();
                int mx = p[t].fireball.x().integer();
                int my = p[t].fireball.y().integer();
                if (p[t].fireball.visible()) {
                    for (int t = 0; t < 24; t++) {
                        int distance = abs(bugs[t].sprite.y().integer() - my) + abs(bugs[t].sprite.x().integer() - mx);
                        if (distance < 16) {

                            bn::sound_items::pop.play();

                            int mxx = (rnd.get() % (current_room.width));
                            int myy = (rnd.get() % (current_room.height));

                            bugs[t].sprite.set_position(mxx * 32, myy * 32);
                            bugs[t].to_x = 0;
                            bugs[t].to_y = 0;

                            BN_LOG("GOTEM!");
                            score += distance * 5;
                        }
                    }
                }
            }
        }

        back_black.set_position(
            (back_black.x().integer() + 1) % 256,
            (back_black.y().integer() + 1) % 256
            );
        maple.update();

        camera.set_x(maple.entity.x());
        camera.set_y(maple.entity.y());

        if (bn::keypad::r_pressed()) brightness = 200;
        if (brightness > 4) brightness -= 4;
        int x_from = maple.entity.x().integer() - 24 - (brightness);
        int y_from = maple.entity.y().integer() -24 - (brightness);
        int x_to = maple.entity.x().integer() + 24 + (brightness);
        int y_to = maple.entity.y().integer() + 24 + (brightness);
        switch(maple.dir) {
            case 0: {
                y_to += 36;
                break;
            }
            case 1: {
                x_to += 36;
                break;
            }
            case 2: {
                x_from -= 36;
                break;
            }
            case 3: {
                y_from -= 36;
                break;
            }
        }
        internal_window.set_boundaries(y_from, x_from, y_to, x_to);

        for (int t = 0; t < 24; t++) {
            bugs[t].update();
            if (bugs[t].sprite.x().integer() + 32 > x_from && bugs[t].sprite.x().integer() - 32 < x_to) {
                if (bugs[t].sprite.y().integer() + 32 > y_from && bugs[t].sprite.y().integer() - 32 < y_to) {
                    
                }
            }
        }

        // Regularly update the tileset based on new camera coordinates
        if (update_counter == 0) {
            local_walls_p = 0;
            int f_x_a = camera.x().integer() / 32;
            int f_y_a = camera.y().integer() / 32;
            int min_y = f_y_a - 4;
            if (min_y < 0) min_y = 0;
            int min_x = f_x_a - 4;
            if (min_x < 0) min_x = 0;
            int max_y = f_y_a + 7;
            if (max_y > current_room.height) max_y = current_room.height;
            int max_x = f_x_a + 7;
            if (max_x > current_room.width) max_x = current_room.width;
            for (int y = min_y; y < max_y; y++) {
                for (int x = min_x; x < max_x; x++) {
                    int loc = current_room.local_tileset[(current_room.width * y) + x];
                    if (local_walls_p < w_size && loc > 0) {
                        local_walls[local_walls_p].entity = bn::sprite_items::environment_stone.create_sprite(x * 32, y * 32, loc - 1);
                        local_walls[local_walls_p].entity.set_camera(camera);
                        local_walls[local_walls_p].entity.put_below();
                        local_walls_p++;
                    }
                }
            }
        }
        update_counter++;
        if (update_counter > 16) update_counter = 0;

        if (treasure.visible()) {
            destination.set_visible(false);
            if (abs(maple.entity.x() - treasure.x()) + abs(maple.entity.y() - treasure.y()) < 16)
            {
                bn::sound_items::cnaut.play();
                is_done == true;
                treasure.set_visible(false);
            }
        } else {
            destination.set_visible(true);
            if (abs(maple.entity.x() - destination.x()) + abs(maple.entity.y() - destination.y()) < 16) {
                bn::sound_items::cnaut.play();
                while(true) {
                    maple.update();
                    bn::core::update();
                }
            }
        }
        

        maple.entity.put_above();
        bn::core::update();
    }
}

void victory_page() {

    bn::sprite_ptr victory_spr = bn::sprite_items::enoki_victory_anim.create_sprite(-48,-32);
    bn::sprite_ptr victory_spr2 = bn::sprite_items::enoki_victory_anim.create_sprite(-48,32);
    bn::sprite_animate_action victory_anim = bn::create_sprite_animate_action_forever(victory_spr, 3, bn::sprite_items::enoki_victory_anim.tiles_item(),
    46,44,42,40,38,36,34,32,30,28,26,24,22,20,18,16,14,12,10,8,6,4,2,0
    );
    bn::sprite_animate_action victory_anim2 = bn::create_sprite_animate_action_forever(victory_spr2, 3, bn::sprite_items::enoki_victory_anim.tiles_item(),
    47,45,43,41,39,37,35,33,31,29,27,25,23,21,19,17,15,13,11,9,7,5,3,1
    );

    int offset = 0;
    int total = 0;
    char buf[16];
    char bf2[16];
    bn::sprite_text_generator text_gen(common::variable_8x16_sprite_font);
    bn::vector<bn::sprite_ptr, 16> text_spr;
    bn::vector<bn::sprite_ptr, 16> text_spr_2;
    bn::vector<bn::sprite_ptr, 7> text_spr_3;
    bn::vector<bn::sprite_ptr, 4> text_spr_4;

    bn::sprite_ptr b_m1 = bn::sprite_items::power_meter.create_sprite(32,0,1);
    bn::sprite_ptr b_m2 = bn::sprite_items::power_meter.create_sprite(64,0,1);
    b_m1.set_scale(4,1);
    b_m2.set_scale(4,1);
    bn::sprite_ptr b_l = bn::sprite_items::power_meter.create_sprite(16,0,0);
    bn::sprite_ptr b_r = bn::sprite_items::power_meter.create_sprite(80,0,2);
    bn::sprite_ptr b_a = bn::sprite_items::power_meter.create_sprite(32,0,3);

    bn::sprite_ptr arrow = bn::sprite_items::arrow.create_sprite(16,32);

    bn::regular_bg_ptr background = bn::regular_bg_items::fun_background.create_bg(0,0);
    bn::regular_bg_ptr sidebar = bn::regular_bg_items::sidebar.create_bg(0,0);

    // Forest   0.065x
    // Garden   0.13x
    // Caves    0.023x + 2.94

    int score = 770;
    int xp = 0;
    int new_lc = 0;
    float new_xp = xp + (0.13 * score);
    if (new_xp > 100) new_xp = 100;

    float new_xp_d = new_xp * 0.48;
    int new_xp_p = 0;
    bool arrow_pos = false;
    bool final_hit = false;

    text_gen.generate(32, 32, "Restart", text_spr_3);
    text_gen.generate(32, 48, "Exit", text_spr_4);

    bn::music_items_info::span[13].first.play(bn::fixed(50) / 100);

    int music_int = 0;
    while(true) {
        if (offset < 48 * 2) {
            victory_anim.update();
            victory_anim2.update();
            offset++;
        }
        victory_spr = victory_anim.sprite();
        victory_spr2 = victory_anim2.sprite();

       background.set_position((background.x().integer() + 1) % 256, (background.y().integer() + 1) % 256);

        if (music_int < 225) {
            music_int++;
        } else if (music_int == 225) {
            bn::music::stop();
            music_int++;
        }

        if (total < score) total += 5;
        if (total > score) total = score;
        if (new_xp_p < new_xp) new_xp_p += 5;
        if (new_xp_p > new_xp) new_xp_p = new_xp;

        sprintf(buf, "Score:     %d", total);
        sprintf(bf2, "XP Earned: %d", new_xp_p);
        text_spr.clear();    
        text_spr_2.clear();
        text_gen.generate(8, -64, buf, text_spr);
        text_gen.generate(8, -48, bf2, text_spr_2);

        if (new_lc < new_xp_d) {
            new_lc++;
            bn::sound_items::start.play();
        }
        else if (!final_hit) {
            final_hit = true;
            total = score;
            bn::sound_items::firecrackle.play();
        }
        b_a.set_x(new_lc + 32);

        if (bn::keypad::up_pressed() || bn::keypad::down_pressed()) {
            bn::sound_items::pop.play();
            arrow_pos = !arrow_pos;
        }

        if (arrow_pos) arrow.set_y(48);
        else arrow.set_y(32);

        bn::core::update();
    }
}

static struct save_struct so;

int main()
{
    bn::core::init();           // Initialize Butano libraries
    bn::sram::read(so);         // Read save data from cartridge

    //exec_dialogue(18);

    dungeon_return dt(0,0,0);
    dt.spawn_x = 0;
    dt.spawn_y = 0;
    dt.world_index = 5;
    dungeon_return dt2 = dungeon(dt);

    //victory_page();
        /*
    
    

    exec_dialogue(16);
    dungeon_return dt(0,0,0);
    dt.spawn_x = 0;
    dt.spawn_y = 0;
    dt.world_index = 4;
    dungeon_return dt2 = dungeon(dt);

    /*
    //tree_cut();
    //rabbit_game();
    //underground();
    //victory_page();

    /*
    // Intro
    startup();
    load_save();

    // Introduction
    exec_dialogue(0);
    exec_dialogue(1);
    exec_dialogue(2);
    introduction();
    cutscenes(0);
    exec_dialogue(13);
    cutscenes(1);
    exec_dialogue(14);
    keyboard();
    exec_dialogue(15);

    // Get to the end?
    bn::core::reset();
    */
}