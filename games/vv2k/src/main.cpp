#include <string.h>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <list>
#include <math.h>
#include <ctime>

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

#include "bn_regular_bg_map_ptr.h"
#include "bn_regular_bg_map_cell_info.h"

#include "bn_regular_bg_items_bg_trailer_home.h"

// Extended headers
#include "objects.h"
#include "save.h"
#include "dialogue.h"
#include "scripts.h"
#include "wander.h"
#include "keyboard.h"

#include "bn_sprite_items_b_button.h"

// tree cut
#include "bn_sprite_items_horizontal_bar.h"
#include "bn_sprite_items_chop_bar.h"
#include "bn_sprite_items_ax_bar.h"

#include "bn_sprite_items_enoki_victory_anim.h"
#include "bn_sprite_items_aaron_victory_anim.h"
#include "bn_sprite_items_maple_victory_anim.h"

#include "bn_sprite_items_save_tiles.h"

#include "bn_sprite_items_power_meter.h"
#include "bn_regular_bg_items_fun_background.h"
#include "bn_regular_bg_items_sidebar.h"
#include "bn_regular_bg_items_garden_bg.h"
#include "bn_sprite_items_bunbun.h"
#include "bn_sprite_items_aaron_axe_anim.h"
#include "bn_regular_bg_items_axe_game_bg.h"
#include "bn_sprite_items_tree_stump.h"
#include "bn_regular_bg_items_underground_bg.h"
#include "bn_sprite_items_underground_tiles.h"
#include "bn_sprite_items_cave_bat.h"

#include "bn_regular_bg_items_pc_background.h"
#include "bn_regular_bg_items_pc_scout.h"
#include "bn_regular_bg_items_pc_desktop.h"
#include "bn_sprite_items_pc_cursor.h"
#include "bn_regular_bg_items_pc_bbscreen.h"
#include "bn_regular_bg_items_pc_folder01.h"
#include "bn_regular_bg_items_pc_folder02.h"
#include "bn_regular_bg_items_pc_document.h"
#include "bn_sprite_items_pc_highlight.h"
#include "bn_sprite_items_bb_sprites.h"

static save_all_struct all_save;
static save_struct *so;
constexpr bool fals = false;

void timer(int delay)
{
    for (int t = 0; t < delay; t++)
    {
        bn::core::update();
    }
}

void startup()
{

    //bn::regular_bg_ptr
    auto header = bn::regular_bg_items::cinemint_studios.create_bg(0, 0);
    auto ocean = bn::regular_bg_items::titlebackground.create_bg(0, 0);
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

    auto tree1 = bn::sprite_items::titlebackground_trees.create_sprite(64 + 16, -32);
    auto tree2 = bn::sprite_items::titlebackground_trees.create_sprite(64 + 32, -32);
    auto trees_left = bn::create_sprite_animate_action_forever(tree1, 12, bn::sprite_items::titlebackground_trees.tiles_item(), 0, 1);
    auto trees_right = bn::create_sprite_animate_action_forever(tree2, 12, bn::sprite_items::titlebackground_trees.tiles_item(), 2, 3);
    tree1.set_visible(false);
    tree2.set_visible(false);

    while (!bn::keypad::start_pressed())
    {
        trees_left.update();
        trees_right.update();
        tree1 = trees_left.sprite();
        tree2 = trees_right.sprite();

        switch (intro_stage)
        {
        case 0:
            item0.set_visible(false);
            item1.set_visible(false);
            item2.set_visible(false);
            item3.set_visible(false);
            if (glow - 0.02 > 0)
            {
                glow -= 0.02;
                bn::bgs_mosaic::set_horizontal_stretch(glow);
                bn::bgs_mosaic::set_vertical_stretch(glow);
            }
            else
            {
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
            if (glow - 0.02 > 0)
            {
                glow -= 0.02;
                bn::blending::set_transparency_alpha(glow);
            }
            else
            {
                intro_stage++;
            }
            break;
        case 4:
            glow = 0.5;
            bn::music_items_info::span[3].first.play(bn::fixed(80) / 100);
            timer(16);
            intro_stage++;
            break;
        case 5:
            item0.set_visible(true);
            item1.set_visible(true);
            item2.set_visible(true);
            item3.set_visible(true);
            if (glow - 0.01 > 0)
            {
                glow -= 0.01;
                bn::sprites_mosaic::set_horizontal_stretch(glow);
                bn::sprites_mosaic::set_vertical_stretch(glow);
            }
            else
            {
                intro_stage++;
            }
            break;
        case 6:
            ocean.set_visible(true);
            tree1.set_visible(true);
            tree2.set_visible(true);
            intro_stage++;
            break;
        default:
        {
            item0.set_y(-32 + height);
            item1.set_y(-34 + height);
            item2.set_y(32 + height);
            item3.set_y(30 + height);
            break;
        }
        }
        bn::core::update();
    }

    bn::core::update();
}

void load_save()
{
    auto velvet = bn::regular_bg_items::velvet.create_bg(0, 0);
    auto ui = bn::regular_bg_items::file_select_bg.create_bg(0, 0);
    auto arrow = bn::sprite_items::arrow.create_sprite(-98, -32);

    bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
    bn::sprite_text_generator file2_gen(common::variable_8x16_sprite_font);
    bn::sprite_text_generator file3_gen(common::variable_8x16_sprite_font);
    bn::vector<bn::sprite_ptr, 12> file1_spr;
    bn::vector<bn::sprite_ptr, 12> file2_spr;
    bn::vector<bn::sprite_ptr, 12> file3_spr;

    char buf1[32];
    char buf2[32];
    char buf3[32];

    if (all_save.so[0].island_name[0] < 255 && all_save.so[0].island_name[0] > 0) {
        std::stringstream ss1;
        for (int t = 0; t < 16; t++) {
            if (all_save.so[0].island_name[t] < 255) {
                ss1 << all_save.so[0].island_name[t];
            }
        }
        if (all_save.so[0].xp == -1) all_save.so[0].xp = 0;
        ss1 << ": " << all_save.so[0].xp << "%%";
        sprintf(buf1, ss1.str().c_str());
    } else {
        sprintf(buf1, "Slot 1: 0%%");
    }

    if (all_save.so[1].island_name[0] < 255 && all_save.so[1].island_name[0] > 0) {
        std::stringstream ss1;
        for (int t = 0; t < 16; t++) {
            if (all_save.so[1].island_name[t] < 255) {
                ss1 << all_save.so[1].island_name[t];
            }
        }
        if (all_save.so[1].xp == -1) all_save.so[1].xp = 0;
        ss1 << ": " << all_save.so[1].xp << "%%";
        sprintf(buf2, ss1.str().c_str());
    } else {
        sprintf(buf2, "Slot 2: 0%%");
    }

    if (all_save.so[2].island_name[0] < 255 && all_save.so[2].island_name[0] > 0) {
        std::stringstream ss1;
        for (int t = 0; t < 16; t++) {
            if (all_save.so[2].island_name[t] < 255) {
                ss1 << all_save.so[2].island_name[t];
            }
        }
        if (all_save.so[2].xp == -1) all_save.so[2].xp = 0;
        ss1 << ": " << all_save.so[2].xp << "%%";
        sprintf(buf3, ss1.str().c_str());
    } else {
        sprintf(buf3, "Slot 3: 0%%");
    }

    file1_gen.generate(-72, -32, buf1, file1_spr);
    file2_gen.generate(-72,   0, buf2, file2_spr);
    file3_gen.generate(-72,  32, buf3, file3_spr);

    auto file1_icon = bn::sprite_items::save_tiles.create_sprite(98,-34, 0);
    auto file2_icon = bn::sprite_items::save_tiles.create_sprite(98,-34 + 34,0);
    auto file3_icon = bn::sprite_items::save_tiles.create_sprite(98,-34 + 68,0);

    if (all_save.so[0].last_char_id > -1) file1_icon = bn::sprite_items::save_tiles.create_sprite(98,-34, all_save.so[0].last_char_id);
    else file1_icon.set_visible(false);

    if (all_save.so[1].last_char_id > -1) file2_icon = bn::sprite_items::save_tiles.create_sprite(98,0, all_save.so[1].last_char_id);
    else file2_icon.set_visible(false);

    if (all_save.so[2].last_char_id > -1) file3_icon = bn::sprite_items::save_tiles.create_sprite(98,34, all_save.so[2].last_char_id);
    else file3_icon.set_visible(false);

    int t = 0;
    int c = 0;

    bn::music_items_info::span[8].first.play(bn::fixed(80) / 100);

    while (!bn::keypad::a_pressed())
    {

        // Scrolling background
        t++;
        t = t % 256;
        velvet.set_position(t, t);

        if (bn::keypad::up_pressed())
        {
            c -= 1;
            if (c < 0)
                c = 2;
            bn::sound_items::pop.play();
        }
        else if (bn::keypad::down_pressed())
        {
            c += 1;
            if (c > 2)
                c = 0;
            bn::sound_items::pop.play();
        }

        arrow.set_y(-32 + (32 * c));
        bn::core::update();
    }

    velvet.set_visible(false);
    ui.set_visible(false);
    arrow.set_visible(false);
    file1_spr.clear();
    file2_spr.clear();
    file3_spr.clear();

    bn::sound_items::firehit.play();
    bn::music::stop();
    timer(64);

    so = &all_save.so[c];
}

void cutscenes(int c)
{
    if (c == 0)
    {
        bn::sound_items::birds.play();
        bn::music_items_info::span[9].first.play(bn::fixed(80) / 100);
        bn::regular_bg_ptr f1 = bn::regular_bg_items::intro_final_1.create_bg(0, 0);
        bn::regular_bg_ptr f2 = bn::regular_bg_items::intro_final_2.create_bg(0, 0);
        f2.set_blending_enabled(true);
        bn::blending::set_transparency_alpha(0);
        f1.put_below();
        timer(32);
        float see = 0;
        f2.set_visible(true);
        for (int t = 0; t < 256; t++)
        {
            bn::blending::set_transparency_alpha(see);
            float c_see = see + 0.01;
            if (c_see <= 1)
                see = c_see;
            bn::core::update();
        }
    }
    else if (c == 1)
    {
        bool isPlayed = false;
        bn::regular_bg_ptr text = bn::regular_bg_items::s0201.create_bg(0, 0);
        bn::music::stop();
        if (!isPlayed)
        {
            bn::sound_items::firehit.play();
            isPlayed = true;
        }
        timer(64);
    }
}

bool victory_page(int chari, int score)
{
    bn::sprite_ptr victory_spr = bn::sprite_items::enoki_victory_anim.create_sprite(-48, -32);
    bn::sprite_ptr victory_spr2 = bn::sprite_items::enoki_victory_anim.create_sprite(-48, 32);
    bn::sprite_animate_action victory_anim = bn::create_sprite_animate_action_forever(victory_spr, 3, bn::sprite_items::enoki_victory_anim.tiles_item(),
                                                                                            46, 44, 42, 40, 38, 36, 34, 32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0);
    bn::sprite_animate_action victory_anim2 = bn::create_sprite_animate_action_forever(victory_spr2, 3, bn::sprite_items::enoki_victory_anim.tiles_item(),
                                                                                            47, 45, 43, 41, 39, 37, 35, 33, 31, 29, 27, 25, 23, 21, 19, 17, 15, 13, 11, 9, 7, 5, 3, 1);

    switch (chari) {
        case 0: {
            victory_anim = bn::create_sprite_animate_action_forever(victory_spr, 5, bn::sprite_items::maple_victory_anim.tiles_item(),
                                                                                            0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26);
            victory_anim2 = bn::create_sprite_animate_action_forever(victory_spr2, 5, bn::sprite_items::maple_victory_anim.tiles_item(),
                                                                                            1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27);
            break;

            bn::sound_items::maple_alright_01.play();
            bn::sound_items::fireblast.play();
        }
        case 2: {
            victory_anim = bn::create_sprite_animate_action_forever(victory_spr, 3, bn::sprite_items::aaron_victory_anim.tiles_item(),
                                                                                            0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 30, 30, 30, 30, 30, 30, 30, 30);
            victory_anim2 = bn::create_sprite_animate_action_forever(victory_spr2, 3, bn::sprite_items::aaron_victory_anim.tiles_item(),
                                                                                            1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 31, 31, 31, 31, 31, 31, 31, 31);
            break;
        }
        default: {
            break;
        }
    }

    int offset = 0;
    int total = 0;
    char buf[24];
    char bf2[24];
    bn::sprite_text_generator text_gen(common::variable_8x16_sprite_font);
    bn::vector<bn::sprite_ptr, 24> text_spr;
    bn::vector<bn::sprite_ptr, 24> text_spr_2;
    bn::vector<bn::sprite_ptr, 7> text_spr_3;
    bn::vector<bn::sprite_ptr, 4> text_spr_4;

    bn::sprite_ptr b_m1 = bn::sprite_items::power_meter.create_sprite(32, 0, 1);
    bn::sprite_ptr b_m2 = bn::sprite_items::power_meter.create_sprite(64, 0, 1);
    b_m1.set_scale(4, 1);
    b_m2.set_scale(4, 1);
    bn::sprite_ptr b_l = bn::sprite_items::power_meter.create_sprite(16, 0, 0);
    bn::sprite_ptr b_r = bn::sprite_items::power_meter.create_sprite(80, 0, 2);
    bn::sprite_ptr b_a = bn::sprite_items::power_meter.create_sprite(32, 0, 3);

    bn::regular_bg_ptr background = bn::regular_bg_items::fun_background.create_bg(0, 0);
    bn::regular_bg_ptr sidebar = bn::regular_bg_items::sidebar.create_bg(0, 0);

    // Forest   0.065x
    // Garden   0.13x
    // Caves    0.023x + 2.94

    float modifier = 0;
    switch (chari)
    {
        case 0: {
            modifier = 0.13;
            break;
        }
        case 1:
        { // Garden
            modifier = 0.035;
            break;
        }
        case 2: {
            modifier = 0.065;
            break;
        }
        default: {
            break;
        }
    }

    int xp = so->xp;
    if (xp == -1) xp = 0;

    int new_lc = 0;
    float new_xp = xp + (modifier * score);
    if (new_xp > 100)
        new_xp = 100;

    so->xp = new_xp; // Add score to save total

    float new_xp_d = new_xp * 0.48;
    int new_xp_p = 0;
    bool final_hit = false;

    auto a_button = bn::sprite_items::a_button.create_sprite(48,48);

    bn::music_items_info::span[13].first.play(bn::fixed(80) / 100);

    int music_int = 0;
    while (!bn::keypad::a_pressed())
    {
        if (offset < 48 * 2)
        {
            victory_anim.update();
            victory_anim2.update();
            offset++;
        }
        
        switch (chari) {
            case 0: {
                victory_spr.set_palette(bn::sprite_items::maple_victory_anim.palette_item());
                victory_spr2.set_palette(bn::sprite_items::maple_victory_anim.palette_item());
                break;
            }
            case 2: {
                victory_spr.set_palette(bn::sprite_items::aaron_victory_anim.palette_item());
                victory_spr2.set_palette(bn::sprite_items::aaron_victory_anim.palette_item());
                break;
            }
            default: {
                break;
            }
        }

        victory_spr = victory_anim.sprite();
        victory_spr2 = victory_anim2.sprite();

        background.set_position((background.x().integer() + 1) % 256, (background.y().integer() + 1) % 256);

        if (music_int < 225)
        {
            music_int++;
        }
        else if (music_int == 225)
        {
            bn::music::stop();
            music_int++;
        }

        if (total < score)
            total += 5;
        if (total > score)
            total = score;
        if (new_xp_p < new_xp)
            new_xp_p += 5;
        if (new_xp_p > new_xp)
            new_xp_p = new_xp;

        sprintf(buf, "Score:     %d", total);
        sprintf(bf2, "XP Earned: %d", new_xp_p);
        text_spr.clear();
        text_spr_2.clear();
        text_gen.generate(8, -64, buf, text_spr);
        text_gen.generate(8, -48, bf2, text_spr_2);

        if (new_lc < new_xp_d)
        {
            new_lc++;
            bn::sound_items::start.play();
        }
        else if (!final_hit)
        {
            final_hit = true;
            total = score;
            bn::sound_items::firecrackle.play();
        }
        b_a.set_x(new_lc + 32);

        bn::core::update();
    }

    return true; // Fortunately, arrow_pos and the final decision weight mean the same thing
}

dungeon_return tree_cut()
{
    bn::music_items_info::span[2].first.play(bn::fixed(80) / 100);
    int score = 0;
    int total = 0;
    bool can_have_sp = false;

    if (true) {
        auto cursor = bn::sprite_items::ax_bar.create_sprite(0, 0);
        auto axe_bg = bn::regular_bg_items::axe_game_bg.create_bg(0,0);
        char buf[16];
        char bf2[16];
        bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
        bn::vector<bn::sprite_ptr, 16> file1_spr;
        bn::vector<bn::sprite_ptr, 16> file2_spr;

        bn::vector<bn::sprite_ptr, 16> bars;
        bn::vector<bn::sprite_ptr, 16> chop;
        bn::random random;
        for (int t = 0; t < 14; t++)
            bars.push_back(bn::sprite_items::horizontal_bar.create_sprite(((t - 7) * 8) + 4, 0));

        auto sq1_spr = bn::sprite_items::aaron_axe_anim.create_sprite(-64 - 48,-16);
        auto sq1 = bn::create_sprite_animate_action_forever(sq1_spr, 4, bn::sprite_items::aaron_axe_anim.tiles_item(), 0, 0, 0, 12, 14, 16, 18, 20, 4, 14, 12);

        auto sq2_spr = bn::sprite_items::aaron_axe_anim.create_sprite(-64 - 48,-16 + 64);
        auto sq2 = bn::create_sprite_animate_action_forever(sq2_spr, 4, bn::sprite_items::aaron_axe_anim.tiles_item(), 1, 1, 1, 13, 15, 17, 19, 21, 5, 15, 13);

        auto sq3_spr = bn::sprite_items::aaron_axe_anim.create_sprite(- 48,-16);
        auto sq3 = bn::create_sprite_animate_action_forever(sq3_spr, 4, bn::sprite_items::aaron_axe_anim.tiles_item(), 28, 28, 28, 40, 42, 44, 46, 48, 32, 42, 40);

        auto sq4_spr = bn::sprite_items::aaron_axe_anim.create_sprite(- 48,-16 + 64);
        auto sq4 = bn::create_sprite_animate_action_forever(sq4_spr, 4, bn::sprite_items::aaron_axe_anim.tiles_item(), 29, 29, 29, 41, 43, 45, 47, 49, 33, 43, 41);

        auto sq1_sw = bn::create_sprite_animate_action_once(sq1_spr, 1, bn::sprite_items::aaron_axe_anim.tiles_item(), 26, 6, 8, 10);
        auto sq2_sw = bn::create_sprite_animate_action_once(sq2_spr, 1, bn::sprite_items::aaron_axe_anim.tiles_item(), 27, 7, 9, 11);
        auto sq3_sw = bn::create_sprite_animate_action_once(sq3_spr, 1, bn::sprite_items::aaron_axe_anim.tiles_item(), 38, 34, 36, 36);
        auto sq4_sw = bn::create_sprite_animate_action_once(sq4_spr, 1, bn::sprite_items::aaron_axe_anim.tiles_item(), 39, 35, 37, 37);

        auto b_button = bn::sprite_items::b_button.create_sprite(90,-50);
        b_button.set_visible(false);

        auto stump = bn::sprite_items::tree_stump.create_sprite(-32,39,0);

        float curs = 0;
        int width = 16;
        int calc_width = width * 4;
        int max_chop = 4;
        int hits = 1;
        bool left = false;
        int wood_stage = 0;

        for (int t = 0; t < max_chop; t++)
        {
            int x_pos = -(calc_width / 2) + (random.get() % calc_width);
            x_pos = (x_pos / 16) * 16;
            chop.push_back(bn::sprite_items::chop_bar.create_sprite(x_pos, 0));
        }

        while (!bn::keypad::b_pressed())
        {

            switch (wood_stage) {
                default: {
                    stump = bn::sprite_items::tree_stump.create_sprite(-32,38,0);
                    wood_stage += 1;
                    break;
                }
                case 1: {
                    stump.set_y(39);
                    wood_stage += 1;
                    break;
                }
                case 2: {
                    if (bn::keypad::a_held()) {
                        stump = bn::sprite_items::tree_stump.create_sprite(-32,39,1);
                        wood_stage += 1;
                    }
                    break;
                }
                case 3: {
                    break;
                }
                case 4: {
                    stump = bn::sprite_items::tree_stump.create_sprite(-32,39,2);
                    wood_stage += 1;
                    break;
                }
                case 5: {
                    stump.set_y(stump.y() + 4);
                    if (stump.y().integer() > 128) wood_stage += 1;
                    break;
                }
                case 6: {
                    stump = bn::sprite_items::tree_stump.create_sprite(-32,38,0);
                    bn::sound_items::pop.play();
                    wood_stage = 1;
                }
            }

            if (!can_have_sp && score > 100) {
                bn::sound_items::squeak.play();
                b_button.set_visible(true);
                can_have_sp = true;
            }

            if (bn::keypad::a_released()) {
                sq1_sw = bn::create_sprite_animate_action_once(sq1_spr, 1, bn::sprite_items::aaron_axe_anim.tiles_item(), 26, 6, 8, 10);
                sq2_sw = bn::create_sprite_animate_action_once(sq2_spr, 1, bn::sprite_items::aaron_axe_anim.tiles_item(), 27, 7, 9, 11);
                sq3_sw = bn::create_sprite_animate_action_once(sq3_spr, 1, bn::sprite_items::aaron_axe_anim.tiles_item(), 38, 34, 36, 36);
                sq4_sw = bn::create_sprite_animate_action_once(sq4_spr, 1, bn::sprite_items::aaron_axe_anim.tiles_item(), 39, 35, 37, 37);
            }

            if (bn::keypad::a_held()) {
                sq1_spr = sq1_sw.sprite();
                sq2_spr = sq2_sw.sprite();
                sq3_spr = sq3_sw.sprite();
                sq4_spr = sq4_sw.sprite();
                if (!sq1_sw.done()) {
                    sq1_sw.update();
                    sq2_sw.update();
                    sq3_sw.update();
                    sq4_sw.update();
                }
            } else {
                sq1_spr = sq1.sprite();
                sq2_spr = sq2.sprite();
                sq3_spr = sq3.sprite();
                sq4_spr = sq4.sprite();
                sq1.update();
                sq2.update();
                sq3.update();
                sq4.update();
            }

            sprintf(buf, "Score: %d", score);
            sprintf(bf2, "Total: %d", total);
            file1_spr.clear();
            file2_spr.clear();
            file1_gen.generate(-114, -70, buf, file1_spr);
            file1_gen.generate(-114, -58, bf2, file2_spr);

            curs += 1 + (score / 200);
            if (curs > 200)
                curs = 0;
            float curs_f = curs;
            int dir = ((curs) / 20);
            int curs_loc = sin(curs_f / 32) * calc_width;

            if (score > total)
                total = score;

            if (dir > 2 && dir < 8)
            { //left
                if (bn::keypad::a_held())
                {
                    cursor.set_scale(1.1);
                }
                else
                {
                    cursor.set_scale(1);
                }
                cursor.put_above();
                left = true;
            }
            else
            { // right
                if (left)
                {
                    cursor.set_scale(0.9);
                    for (int t = 0; t < max_chop; t++)
                    {
                        if (chop.at(t).visible())
                            score = score / 2;
                    }

                    hits = 1;
                    bn::sound_items::ui_sfx01.play();
                    chop.clear();
                    max_chop = 4 + (score / 1000);
                    if (max_chop > 16)
                        max_chop = 16;

                    for (int t = 0; t < max_chop; t++)
                    {
                        int x_pos = -(calc_width / 2) + (random.get() % calc_width);
                        x_pos = (x_pos / 4) * 4;
                        chop.push_back(bn::sprite_items::chop_bar.create_sprite(x_pos, 0));
                    }
                }
                cursor.put_below();
                left = false;
            }

            if (bn::keypad::a_pressed() && left)
            {
                bool penalty = true;
                for (int t = 0; t < max_chop; t++)
                {
                    int c_x = chop.at(t).x().integer();
                    if (curs_loc + 8 > c_x - 16 && curs_loc + 8 < c_x + 16)
                    {
                        chop.at(t).set_visible(false);
                        if (hits < 5)
                        {
                            bn::sound_items::firehit.play();
                            hits++;
                        }
                        score += hits;
                        penalty = false;

                        if (t == max_chop - 1 && wood_stage < 4) {
                            wood_stage = 4;
                        }
                    }
                }
                if (penalty)
                {
                    score -= (score / 5);
                }
            }

            cursor.set_x(curs_loc);
            bn::core::update();
        }

    }
    
    if (can_have_sp) {
        victory_page(2, total);
    }

    dungeon_return dt(9, 1, 4);
    return dt;
}

class rabbit
{
public:
    bn::sprite_item entity = bn::sprite_items::bunbun;
    bn::sprite_ptr sprite = entity.create_sprite(0, 0);
    bn::sprite_animate_action<4> entity_anim = bn::create_sprite_animate_action_forever(sprite, 4, entity.tiles_item(), 0, 1, 0, 1);
    bool moving = true;
    bool carry = false;
    int spend = 0;
    int dir = 0;
    float x_vector = 0;
    float y_vector = 1;
    int init_y = 0;
    bool enabled = true;
    rabbit() {}

    void move()
    {
        entity_anim.update();
        sprite = entity_anim.sprite();

        if (x_vector > 0) {
            sprite.set_horizontal_flip(true);
        } else {
            sprite.set_horizontal_flip(false);
        }

        if (spend > 0)
        {
            if (sprite.x() < 0 || sprite.x() > 240 || sprite.y() < 0 || sprite.y() > 160)
            {
                sprite.set_visible(false);
            }
            float sine = sinf((64 - spend) / 21);
            switch (dir)
            {
                default:
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
        }
        else if (moving)
        {
            sprite.set_position(sprite.x() + x_vector, sprite.y() + y_vector);
        }
    }
};

dungeon_return rabbit_game()
{
    int score = 0;
    if (true)
    {
        bn::vector<rabbit, 32> rabbits;
        auto max_rabbits = 32;
        bn::camera_ptr camera = bn::camera_ptr::create(0, 0);

        bn::regular_bg_ptr garden_bg = bn::regular_bg_items::garden_bg.create_bg(0,0);
        garden_bg.set_camera(camera);

        char buf[12];
        bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
        bn::vector<bn::sprite_ptr, 12> file1_spr;
        bn::vector<bn::sprite_ptr, 12> file2_spr;

        bn::vector<bn::sprite_ptr, 16> bars;
        bn::vector<bn::sprite_ptr, 16> chop;

        bool isHolding = false;

        room myRoom;

        std::vector<int> local = {
            2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 0, 0, 0, 0, 0, 0, 0, 2,
            2, 0, 0, 0, 0, 0, 0, 0, 2,
            2, 0, 0, 0, 0, 0, 0, 0, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2};
        deep_copy(local, myRoom.local_tileset);

        std::vector<int> local_col = {
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0
        };
        deep_copy(local_col, myRoom.collisions);

        myRoom.width = 9;
        myRoom.height = 5;
        myRoom.start_x = 4;
        myRoom.start_y = 2;
        camera.set_position(myRoom.start_x * 32, myRoom.start_y * 32);

        if (bn::music::playing()) bn::music::stop();
        bn::music_items_info::span[18].first.play(bn::fixed(80) / 100);

        character enoki(bn::sprite_items::enoki_walking_spring, myRoom, myRoom.start_x, myRoom.start_y, true);
        enoki.entity.set_camera(camera);

        bn::sprite_ptr enoki_hold = bn::sprite_items::enoki_walking_spring.create_sprite(myRoom.start_x, myRoom.start_y, 12);
        enoki_hold.set_camera(camera);
        enoki_hold.set_visible(false);

        for (int t = 0; t < max_rabbits; t++)
        {
            rabbit r;
            r.sprite.set_camera(camera);
            rabbits.push_back(r);
        }

        int score_meter = 0;
        int dir = 0;
        int last_dir = 0;
        int heldItem = 0;
        bool playing = true;

        while (playing)
        {
            score_meter++;
            if (score_meter == 50)
            {
                score_meter = 0;
                if (score > 0)
                    score -= 10;
            }

            sprintf(buf, "Score: %d", score);
            file1_spr.clear();
            file1_gen.generate(-114, -70, buf, file1_spr);

            if (isHolding) {
                enoki_hold.set_position(enoki.entity.x(), enoki.entity.y());
                enoki_hold.set_visible(true);
                enoki.entity.set_visible(false);

                if (bn::keypad::down_pressed()) dir = 0;
                if (bn::keypad::left_pressed()) dir = 2;
                if (bn::keypad::right_pressed()) dir = 1;
                if (bn::keypad::up_pressed()) dir = 3;

                if (dir != last_dir) {
                    enoki_hold = bn::sprite_items::enoki_walking_spring.create_sprite(enoki_hold.x(), enoki_hold.y(), 12 + dir);
                    enoki_hold.set_camera(camera);
                    last_dir = dir;
                }
            } else {
                enoki_hold.set_visible(false);
                enoki.entity.set_visible(true);
                enoki.update();
            }

            bool allOut = true;
            for (int t = 0; t < max_rabbits; t++)
            {
                if (rabbits.at(t).sprite.visible())
                {
                    allOut = false;
                    if (rabbits.at(t).sprite.y() < enoki.entity.y() + 4)
                    {
                        rabbits.at(t).sprite.put_below();
                    }
                    else
                    {
                        rabbits.at(t).sprite.put_above();
                    }

                    if (rabbits.at(t).carry)
                    {
                        rabbits.at(t).sprite.set_position(enoki.entity.x(), enoki.entity.y() - 12);
                        rabbits.at(t).sprite.put_above();
                    }
                    else
                    {
                        rabbits.at(t).move();
                    }
                }
                else if (rabbits.at(t).enabled)
                {
                    rabbits.at(t).enabled = false;
                    bn::sound_items::firecrackle.play();
                    score += 25;
                }
            }
            if (allOut)
            {
                playing = false;
            }

            // Random init
            if (std::rand() % 20 == 0)
            {
                for (int t = 0; t < max_rabbits; t++)
                {
                    if (std::rand() % 3 == 0)
                    {
                        rabbits.at(t).moving = false;
                    }
                    else
                    {
                        rabbits.at(t).moving = true;
                        signed int c_x = (std::rand() % 4) - 2;
                        signed int c_y = (std::rand() % 4) - 2;

                        if (rabbits.at(t).sprite.x().integer() > 190)
                        {
                            c_x = -2;
                        }
                        else if (rabbits.at(t).sprite.x().integer() < 50)
                        {
                            c_x = 2;
                        }

                        if (rabbits.at(t).sprite.y().integer() > 120)
                        {
                            c_y = -2;
                        }
                        else if (rabbits.at(t).sprite.y().integer() < 40)
                        {
                            c_y = 2;
                        }

                        rabbits.at(t).x_vector = c_x;
                        rabbits.at(t).y_vector = c_y;
                    }
                }
            }

            if (bn::keypad::a_pressed())
            {
                if (isHolding)
                {
                    bn::sound_items::cnaut.play();
                    for (int t = 0; t < max_rabbits; t++)
                    {
                        if (rabbits.at(t).carry)
                        {
                            rabbits.at(t).init_y = enoki.entity.y().integer();
                            rabbits.at(t).dir = enoki.dir;
                            rabbits.at(t).carry = false;
                            rabbits.at(t).spend = 64;
                        }
                    }
                    isHolding = false;
                }
                else
                {
                    for (int t = 0; t < max_rabbits; t++)
                    {
                        if (
                            (std::abs(rabbits.at(t).sprite.x().integer() - enoki.entity.x().integer()) < 8) &&
                            (std::abs(rabbits.at(t).sprite.y().integer() - enoki.entity.y().integer()) < 16))
                        {
                            bn::sound_items::squeak.play();
                            isHolding = true;
                            heldItem = t;
                            rabbits.at(t).carry = true;
                            t = max_rabbits;
                        }
                    }
                }
            }

            //while(true) bn::core::update();

            bn::core::update();
        }
    }

    victory_page(1, score);

    dungeon_return dt(1, 10, 4);
    return dt;
}

class creepy_crawly
{
public:
    bn::sprite_ptr sprite = bn::sprite_items::cave_bat.create_sprite(0, 0);
    bn::sprite_animate_action<4> sprite_anim = bn::create_sprite_animate_action_forever(sprite, 1, bn::sprite_items::cave_bat.tiles_item(), 0, 1, 0, 1);
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
    room *current_room;
    creepy_crawly() {}

    void update()
    {
        int flap = std::rand() % 2;
        if (flap == 0) {
            sprite_anim.update();
            sprite = sprite_anim.sprite();
        }

        int mx = sprite.x().integer() / 32;
        int my = sprite.y().integer() / 32;
        int mz = mx + (my * current_room->width);

        if (mx == to_x && my == to_y)
        {
            to_x = 0;
            to_y = 0;
        }

        if (to_x == 0 && to_y == 0)
        {
            int dir = std::rand() % 4;
            switch (dir)
            {
            case 0:
                if (current_room->local_tileset[mz + 1] == 0)
                {
                    to_x = mx + 1;
                    to_y = my;
                }
                break;
            case 1:
                if (current_room->local_tileset[mz + current_room->width] == 0)
                {
                    to_y = my + 1;
                    to_x = mx;
                }
                break;
            case 2:
                if (current_room->local_tileset[mz - 1] == 0)
                {
                    to_x = mx - 1;
                    to_y = my;
                }
                break;
            case 3:
                if (current_room->local_tileset[mz - current_room->width] == 0)
                {
                    to_y = my - 1;
                    to_x = mx;
                }
                break;
            }
        }
        else
        {
            int vector_x = 0;
            if (mx < to_x)
            {
                vector_x++;
            }
            else if (mx > to_x)
            {
                vector_x--;
            }

            int vector_y = 0;
            if (my < to_y)
            {
                vector_y++;
            }
            else if (my > to_y)
            {
                vector_y--;
            }

            sprite.set_position(sprite.x().integer() + (vector_x * 2), sprite.y().integer() + (vector_y * 2));
        }
    }
};

dungeon_return underground()
{
    int score = 0;
    bool is_returned = false;
    bool is_victory = false;

    if (true) {
        bn::music_items_info::span[19].first.play(bn::fixed(80) / 100);

        bn::camera_ptr camera = bn::camera_ptr::create(0, 0);
        bn::regular_bg_ptr back_floor = bn::regular_bg_items::underground_bg.create_bg(0, 0);
        bn::regular_bg_ptr back_black = bn::regular_bg_items::velvet.create_bg(0, 0);
        back_floor.set_camera(camera);
        back_black.set_camera(camera);

        bn::blending::set_transparency_alpha(0.9);

        char buf[16];
        bn::sprite_text_generator file_gen(common::variable_8x16_sprite_font);
        bn::vector<bn::sprite_ptr, 16> file_spr;
        bn::vector<bn::sprite_ptr, 16> bars;

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

        current_room.init(20, 20, 17, 18);
        std::vector<int> local {
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1,
            1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1,
            1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1,
            1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1,
            1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1,
            1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
            1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1,
            1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
            1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1,
            1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1,
            1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1,
            1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1,
            1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1,
            1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1,
            1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1};
        std::vector<int> local_col {
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1,
            1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1,
            1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1,
            1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1,
            1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1,
            1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
            1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1,
            1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
            1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1,
            1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1,
            1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1,
            1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1,
            1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1,
            1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1,
            1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        deep_copy(local, current_room.local_tileset);
        deep_copy(local_col, current_room.collisions);

        character maple = character(
            bn::sprite_items::maple_walking_spring,
            current_room,
            current_room.start_x,
            current_room.start_y,
            true);
        maple.entity.set_camera(camera);

        //bn::sprite_ptr a_button = bn::sprite_items::a_button_2.create_sprite(maple.entity.x().integer(), maple.entity.y().integer() - 32);
        //a_button.set_camera(camera);

        creepy_crawly bugs[24];
        for (int t = 0; t < 24; t++)
        {
            bugs[t].sprite.set_camera(camera);
            int mx = (std::rand() % (current_room.width - 6));
            int my = (std::rand() % (current_room.height - 6));
            while (current_room.local_tileset[mx + (my * current_room.width)] > 0)
            {
                mx = (std::rand() % (current_room.width - 6));
                my = (std::rand() % (current_room.height - 6));
            }
            bugs[t].sprite.set_position(mx * 32, my * 32);
            bugs[t].current_room = &current_room;
        }

        // Make a fireball!
        int p_index = 0;
        int p_size = 3;
        projectile p[3];
        for (int t = 0; t < 3; t++)
        {
            p[t].fireball.set_camera(camera);
            p[t].fireball.set_visible(false);
        }

        int update_counter = 0;
        int flex = 84;
        int brightness = 1;

        camera.set_position(maple.entity.x(), maple.entity.y());
        int forgiveness = 0;

        int abx = 0;
        int aby = 0;
        while (current_room.local_tileset[abx + (current_room.width * aby)] > 0)
        {
            abx = std::rand() % (current_room.width - 6);
            aby = std::rand() % (current_room.height - 6);
        }
        bn::sprite_ptr treasure = bn::sprite_items::underground_tiles.create_sprite(abx * 32, aby * 32, 1);
        treasure.set_camera(camera);
        bool is_done = false;

        while (!is_returned)
        {
            sprintf(buf, "%d", score);
            file_spr.clear();
            file_gen.generate(-(countDigit(score - 1) * 3), -24, buf, file_spr);



            if (abs((current_room.start_y * 32) - maple.entity.y().integer()) < 32 && abs((current_room.start_x * 32) - maple.entity.x().integer()) < 32) {
                if (bn::keypad::a_pressed()) {
                    is_returned = true;
                    external_window.set_show_sprites(true);
                }

                if (!treasure.visible()) {
                    is_returned = true;
                    is_victory = true;
                    external_window.set_show_sprites(true);
                }
            }

            // Create projectiles
            if (bn::keypad::r_pressed())
            {
                if (score > 50)
                {
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
                if (p_index >= p_size)
                    p_index = 0;
            }

            // Check collision
            int mx = maple.entity.x().integer();
            int my = maple.entity.y().integer();
            if (forgiveness < 1)
            {
                for (int t = 0; t < 24; t++)
                {
                    if (abs(mx - bugs[t].sprite.x().integer()) + abs(my - bugs[t].sprite.y().integer()) < 16)
                    {
                        score -= 100;

                        if (std::rand() % 2 == 0) {
                            bn::sound_items::maple_ugh_01.play();
                        } else {
                            bn::sound_items::maple_ugh_02.play();
                        }
                        
                        forgiveness = 2000;

                        // Move the treasure
                        int abx = 0;
                        int aby = 0;
                        while (current_room.local_tileset[abx + (current_room.width * aby)] > 0)
                        {
                            abx = std::rand() % (current_room.width - 6);
                            aby = std::rand() % (current_room.height - 6);
                        }
                        treasure.set_position(abx * 32, aby * 32);
                        treasure.set_visible(true);
                        is_done = false;
                    }
                    if (score < 0)
                    {
                        score = 0;
                        maple.entity.set_position(current_room.start_x * 32, current_room.start_y * 32);
                    }
                }
            }
            else
            {
                forgiveness = 0;
            }

            maple.entity.set_z_order(2);

            // Update projectiles
            for (int t = 0; t < p_size; t++)
            {
                if (p[t].active)
                {
                    p[t].fireball.set_z_order(1);
                    p[t].update();
                    int mxx = p[t].fireball.x().integer();
                    int myy = p[t].fireball.y().integer();
                    if (p[t].fireball.visible())
                    {
                        for (int tt = 0; tt < 24; t++)
                        {
                            int distance = abs(bugs[tt].sprite.y().integer() - myy) + abs(bugs[tt].sprite.x().integer() - mxx);
                            if (distance < 16)
                            {
                                bn::sound_items::pop.play();

                                int mxx = (std::rand() % (current_room.width));
                                int myy = (std::rand() % (current_room.height));

                                bugs[tt].sprite.set_position(mxx * 32, myy * 32);
                                bugs[tt].to_x = 0;
                                bugs[tt].to_y = 0;

                                score += distance * 5;
                            }
                        }
                    }
                }
            }

            back_black.set_position(
                (back_black.x().integer() + 1) % 256,
                (back_black.y().integer() + 1) % 256);
            maple.update();

            camera.set_x(maple.entity.x());
            camera.set_y(maple.entity.y());

            if (bn::keypad::r_pressed())
                brightness = 200;
            if (brightness > 4)
                brightness -= 4;
            int x_from = maple.entity.x().integer() - 24 - (brightness);
            int y_from = maple.entity.y().integer() - 24 - (brightness);
            int x_to = maple.entity.x().integer() + 24 + (brightness);
            int y_to = maple.entity.y().integer() + 24 + (brightness);
            switch (maple.dir)
            {
            case 0:
            {
                y_to += 36;
                break;
            }
            case 1:
            {
                x_to += 36;
                break;
            }
            case 2:
            {
                x_from -= 36;
                break;
            }
            case 3:
            {
                y_from -= 36;
                break;
            }
            }
            internal_window.set_boundaries(y_from, x_from, y_to, x_to);

            for (int t = 0; t < 24; t++)
            {
                bugs[t].update();
                if (bugs[t].sprite.x().integer() + 32 > x_from && bugs[t].sprite.x().integer() - 32 < x_to)
                {
                    if (bugs[t].sprite.y().integer() + 32 > y_from && bugs[t].sprite.y().integer() - 32 < y_to)
                    {
                    }
                }
            }

            // Regularly update the tileset based on new camera coordinates
            if (update_counter == 0)
            {
                local_walls_p = 0;
                int f_x_a = camera.x().integer() / 32;
                int f_y_a = camera.y().integer() / 32;
                int min_y = f_y_a - 4;
                if (min_y < 0)
                    min_y = 0;
                int min_x = f_x_a - 4;
                if (min_x < 0)
                    min_x = 0;
                int max_y = f_y_a + 7;
                if (max_y > current_room.height)
                    max_y = current_room.height;
                int max_x = f_x_a + 7;
                if (max_x > current_room.width)
                    max_x = current_room.width;
                for (int y = min_y; y < max_y; y++)
                {
                    for (int x = min_x; x < max_x; x++)
                    {
                        int loc = current_room.local_tileset[(current_room.width * y) + x];
                        if (local_walls_p < w_size && loc > 0)
                        {
                            local_walls[local_walls_p].entity = bn::sprite_items::underground_tiles.create_sprite(x * 32, y * 32, loc - 1);
                            local_walls[local_walls_p].entity.set_camera(camera);
                            local_walls[local_walls_p].entity.set_z_order(3);
                            local_walls_p++;
                        }
                    }
                }
            }
            update_counter++;
            if (update_counter > 16)
                update_counter = 0;

            if (treasure.visible())
            {
                if (abs(maple.entity.x() - treasure.x()) + abs(maple.entity.y() - treasure.y()) < 16)
                {
                    bn::sound_items::maple_alright_02.play();
                    is_done == true;
                    score += 100;
                    treasure.set_visible(false);
                }
            }

            maple.entity.put_above();
            bn::core::update();
        }

    }

    if (is_victory) {
        victory_page(0, score);
    }

    dungeon_return dt(1, 5, 4);
    return dt;
}

bool ball_breakout() {
    bool leave = false;

    while(!leave) {

        bn::camera_ptr camera = bn::camera_ptr::create(30, 42);

        bn::vector<bn::sprite_ptr, 54> tiles;
        auto ball = bn::sprite_items::bb_sprites.create_sprite(32, 56, 6);
        ball.set_scale(1,1);
        ball.set_camera(camera);
        auto paddle = bn::sprite_items::bb_sprites.create_sprite(32,72);
        paddle.set_scale(2,1);
        paddle.set_camera(camera);

        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 5; y++) {
                auto bb = bn::sprite_items::bb_sprites.create_sprite(x * 8, y * 8, y);
                bb.set_camera(camera);
                tiles.push_back(bb);
            }
        }

        int d_x = 1;
        int d_y = 1;

        while (ball.y() < 75 && !leave) {

            if (bn::keypad::b_pressed()) leave = true;

            ball.set_position(ball.x() + d_x, ball.y() + d_y);

            if (ball.y() == 64 && (abs(ball.x() - paddle.x()) < 16)) {
                d_y = -1;
                if (ball.x() > paddle.x()) {
                    d_x = 1;
                } else {
                    d_x = -1;
                }
                if (abs(ball.x() - paddle.x()) > 8) d_x = d_x * 2;
                bn::sound_items::pop.play();
            }
            if (ball.y() < 1) d_y = 1;
            if (ball.x() > 63) d_x = d_x * -1;
            if (ball.x() < 1) d_x = d_x * -1;

            bool complete = true;
            for (int t = 0; t < tiles.size(); t++) {
                if (tiles.at(t).visible()) {
                    complete = false;
                    if (abs(tiles.at(t).x() - ball.x()) < 4) {
                        if (abs(tiles.at(t).y().integer() - ball.y()) < 8) {
                            d_y = 1;
                            tiles.at(t).set_visible(false);
                            bn::sound_items::firehit.play();
                        }
                    }
                }
            }

            if (complete) return true;

            if (bn::keypad::left_held() && paddle.x() > 8) {
                paddle.set_x(paddle.x() - 3);
            }

            if (bn::keypad::right_held() && paddle.x() < 63) {
                paddle.set_x(paddle.x() + 3);
            }

            bn::core::update();
        }

    bn::sound_items::squeak.play();
    }

    return false;
}

dungeon_return computer() {
    bn::music::stop();

    auto pc_bg = bn::regular_bg_items::pc_background.create_bg(0,0);
    auto pc_scout = bn::regular_bg_items::pc_scout.create_bg(0,0);
    auto pc_cursor = bn::sprite_items::pc_cursor.create_sprite(0,0,1);
    auto b_button = bn::sprite_items::b_button.create_sprite(90,-50);

    pc_bg.put_above();

    pc_scout.set_blending_enabled(true);
    bn::blending::set_transparency_alpha(0);
    bn::sound_items::pc_whir.play();

    int ticks = 0;
    double alpha = 0;
    int select = 0;
    while (!bn::keypad::b_pressed()) {

        BN_LOG(pc_cursor.x(), " - ", pc_cursor.y());

        pc_cursor.set_position(
            pc_cursor.x().integer() + bn::keypad::right_held() - bn::keypad::left_held(),
            pc_cursor.y().integer() + bn::keypad::down_held() - bn::keypad::up_held()
        );

        if (pc_cursor.x() < -30) pc_cursor.set_x(-30);
        if (pc_cursor.x() > 55) pc_cursor.set_x(55);
        if (pc_cursor.y() < -35) pc_cursor.set_y(-35);
        if (pc_cursor.y() > 30) pc_cursor.set_y(30);

        BN_LOG(pc_cursor.x(), " - ", pc_cursor.y());

        if (ticks > 64) {
            if (alpha < 1) {
                if (alpha == 0) {
                    bn::sound_items::pc_boot.play();
                }
                bn::blending::set_transparency_alpha(alpha);
                alpha += 0.05;
            } else {
                bn::blending::set_transparency_alpha(bn::fixed(1));
            }
        }

        if (ticks == 108) {
            pc_cursor = bn::sprite_items::pc_cursor.create_sprite(0,0,0);
            pc_scout.set_blending_enabled(false);
            bn::blending::set_transparency_alpha(bn::fixed(0.5));
        }

        if (ticks > 108) {
            if (bn::keypad::a_pressed() && pc_cursor.visible()) {
                if (pc_cursor.x().integer() < -14 && pc_cursor.y().integer() < 12) {
                    if (pc_cursor.y().integer() < -9) {
                        pc_scout = bn::regular_bg_items::pc_folder02.create_bg(0,0);
                        select = 2;
                    } else {
                        pc_scout = bn::regular_bg_items::pc_folder01.create_bg(0,0);
                        select = 1;
                    }
                } else {
                    if (pc_cursor.y() > -14 && pc_cursor.y() < 4) {

                        // Trash Folder
                        if (select == 2) {
                            if (pc_cursor.x() > 14 && pc_cursor.x() < 33) {
                                pc_scout = bn::regular_bg_items::pc_document.create_bg(0,0);
                                pc_bg.put_above();

                                bn::core::update();
                                b_button.set_visible(false);
                                exec_dialogue(23);
                                pc_scout = bn::regular_bg_items::pc_folder02.create_bg(0,0);
                                b_button.set_visible(true);
                            } else if (pc_cursor.x() > 32 && pc_cursor.x() < 51) {
                                pc_scout = bn::regular_bg_items::pc_document.create_bg(0,0);
                                pc_bg.put_above();

                                bn::core::update();
                                b_button.set_visible(false);
                                exec_dialogue(24);
                                pc_scout = bn::regular_bg_items::pc_folder02.create_bg(0,0);
                                b_button.set_visible(true);
                            } else if (pc_cursor.x() > 50 && pc_cursor.x() < 70) {
                                pc_scout = bn::regular_bg_items::pc_document.create_bg(0,0);
                                pc_bg.put_above();

                                bn::core::update();
                                b_button.set_visible(false);
                                exec_dialogue(25);
                                pc_scout = bn::regular_bg_items::pc_folder02.create_bg(0,0);
                                b_button.set_visible(true);
                            }
                        }

                        // Documents folder
                        else if (select == 1) {
                            if (pc_cursor.x() > 14 && pc_cursor.x() < 33) {
                                bn::music_items_info::span[28].first.play(bn::fixed(80) / 100);
                                pc_scout = bn::regular_bg_items::pc_bbscreen.create_bg(0,0);
                                pc_cursor.set_visible(false);
                                pc_bg.put_above();

                                // Play breakout
                                bool success = ball_breakout();

                                bn::music::stop();
                                pc_scout = bn::regular_bg_items::pc_folder01.create_bg(0,0);
                                pc_cursor.set_visible(true);
                                bn::core::update();
                                
                                // Play dialogue on success
                                if (success) exec_dialogue(26);

                            } else if (pc_cursor.x() > 32 && pc_cursor.x() < 51) {
                                pc_scout = bn::regular_bg_items::pc_document.create_bg(0,0);
                                pc_bg.put_above();

                                b_button.set_visible(false);
                                bn::core::update();
                                exec_dialogue(22);
                                pc_scout = bn::regular_bg_items::pc_folder01.create_bg(0,0);
                                b_button.set_visible(true);
                            } 
                        }
  
                    } else {
                        pc_scout = bn::regular_bg_items::pc_desktop.create_bg(0,0);
                        select = 0;
                    }
                }
            }
        }

        if (ticks == 128) {
            pc_scout = bn::regular_bg_items::pc_desktop.create_bg(0,0);
        }

        if (ticks < 256) ticks++;
        pc_bg.put_above();
        bn::core::update();
    }

    dungeon_return dt(4, 7, 6);
    return dt;
}

//9,16,4

void core_gameplay(int x, int y, int world, int until, bool force = false, int force_char = 0)
{

    // Configure defaults
    dungeon_return dt(x, y, world);
    if ((so->spawn_x < 1 && so->spawn_y < 1) || force)
    {
        if (so->last_char_id == -1)
            so->last_char_id = force_char;
        dt.spawn_x = x;
        dt.spawn_y = y;
        dt.world_index = world;
    }
    else
    {
        dt.spawn_x = so->spawn_x;
        dt.spawn_y = so->spawn_y;
        dt.world_index = so->world_index;
    }

    // Execute until time to leave
    do
    {
        // Random seed
        std::srand(so->xp);

        // Spring event trigger
        if (so->checkpoint == 4 && so->xp > 99 && so->last_char_id != 4) {
            dt.world_index = 7;
        }
        
        // if minigame....
        else if (dt.world_index == 99)
        {
            bn::core::update();          

            switch (dt.spawn_x)
            {
                default:
                {
                    dt = tree_cut();
                    break;
                }
                case 2:
                {
                    dt = rabbit_game();
                    break;
                }
                case 3:
                {
                    dt = underground();
                    break;
                }
                case 4: {
                    dt = computer();
                    break;
                }
            };
        }
        else
        {

            // if legit world....
            dt = dungeon(dt, so, false);
        }

        bn::sram::write(all_save);
        bn::core::update();
    } while (!(dt.world_index == until));
}

void clear_save() {
    so->last_char_id = 0;
    so->checkpoint = 0;
    so->spawn_x = 0;
    so->spawn_y = 0;
    so->world_index = 0;
    so->xp = 0;
    so->spring_housewarming = 0;

    bn::sram::write(all_save);
}

int checkpoint(int level)
{

    if (so->checkpoint < 1)
    {
        so->checkpoint = 0;
        level = 0;
    }

    switch (level)
    {

        // Introduction
        case 0:
            exec_dialogue(0);
            exec_dialogue(1);
            exec_dialogue(2);
            core_gameplay(8, 3, 0, -1, true, 0);

            cutscenes(0);
            exec_dialogue(13);
            cutscenes(1);
            exec_dialogue(14);
            keyboard(so);
            exec_dialogue(15);
            break;

        // Spring
        case 1:
            exec_dialogue(16);
            so->last_char_id = 0;
            core_gameplay(9, 16, 4, 5, true);
            break;
        case 2:
            bn::music_items_info::span[8].first.play(bn::fixed(80) / 100);
            exec_dialogue(18);
            break;
        case 3:
            core_gameplay(5, 3, 5, 4, true);
            break;
        case 4:
            core_gameplay(9, 6, 4, 7);
            break;
        case 5:
            core_gameplay(5, 8, 4, 5);
            break;
        case 6:
            bn::music_items_info::span[8].first.play(bn::fixed(80) / 100);
            exec_dialogue(17);
            exec_dialogue(19);
            exec_dialogue(20);
            break;

        // Summer - Diana, Eleanor, and Vee
        case 7:
            exec_dialogue(21);
            break;
        case 8:
            //BN_LOG(so->last_char_id);
            if (so->last_char_id == 3) {
                core_gameplay(8, 10, 7, 0, true);
            } else {
                core_gameplay(9, 6, 7, 0, true);
            }
            break;

        default:
            return -1;
            break;
        }
        bn::core::update();
        return level + 1;
}

int main()
{
    bn::core::init(); // Initialize Butano libraries

    startup();
    bn::sram::read(all_save);         // Read save data from cartridge
    load_save();
    so->checkpoint = 7;               // Force for dev purposes
    while (so->checkpoint < 99) {
        so->checkpoint = checkpoint(so->checkpoint);
    }

    // Get to the end?
    bn::core::reset();
}