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
#include "bn_affine_bg_mat_attributes.h"
#include "bn_affine_bg_attributes_hbe_ptr.h"
#include "bn_affine_bg_pivot_position_hbe_ptr.h"
#include "bn_affine_bg_mat_attributes_hbe_ptr.h"
#include "bn_affine_bg_pa_register_hbe_ptr.h"
#include "bn_affine_bg_pc_register_hbe_ptr.h"
#include "bn_affine_bg_dx_register_hbe_ptr.h"
#include "bn_affine_bg_dy_register_hbe_ptr.h"

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

#include "bn_affine_bg_items_bg_crystal_ball.h"
#include "bn_regular_bg_items_bg_crystal01.h"
#include "bn_affine_bg_items_bg_ocean.h"
#include "bn_sprite_items_bg_sky.h"
#include "bn_affine_bg_items_bg_sky_trees.h"
#include "bn_sprite_items_l_button.h"

// Extended headers
#include "objects.h"
#include "save.h"
#include "bn_sprite_items_b_button.h"

#include "dialogue.h"
#include "scripts.h"
#include "wander.h"
#include "keyboard.h"

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
#include "bn_sprite_items_avocado.h"

#include "bn_sprite_items_magic_keys.h"

#include "bn_regular_bg_items_bg_toutes.h"
#include "bn_regular_bg_items_bg_static.h"
#include "bn_sprite_items_toutes_spr.h"
#include "bn_regular_bg_items_bg_dock.h"

#include "bn_sprite_items_gumbo.h"
#include "bn_sprite_items_gumbo_mons.h"
#include "bn_regular_bg_items_bg_cooking_01.h"
#include "bn_regular_bg_items_bg_cooking_02.h"
#include "bn_regular_bg_items_bg_monch.h"
#include "bn_sprite_items_bg_monch_face.h"

#include "bn_sprite_items_battle_aaron.h"
#include "bn_sprite_items_battle_rufus.h"
#include "bn_sprite_items_fight_tiles.h"
#include "bn_regular_bg_items_bg_stage.h"

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
        ss1 << ": " << (all_save.so[0].checkpoint * 6.6) << "%%";
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
        ss1 << ": " << (all_save.so[0].checkpoint * 6.6) << "%%";
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
        ss1 << ": " << (all_save.so[0].checkpoint * 6.6) << "%%";
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

    if (all_save.so[0].last_char_id > -1 && all_save.so[0].last_char_id < 7) file1_icon = bn::sprite_items::save_tiles.create_sprite(98,-34, all_save.so[0].last_char_id);
    else file1_icon.set_visible(false);

    if (all_save.so[1].last_char_id > -1 && all_save.so[1].last_char_id < 7) file2_icon = bn::sprite_items::save_tiles.create_sprite(98,0, all_save.so[1].last_char_id);
    else file2_icon.set_visible(false);

    if (all_save.so[2].last_char_id > -1 && all_save.so[2].last_char_id < 7) file3_icon = bn::sprite_items::save_tiles.create_sprite(98,34, all_save.so[2].last_char_id);
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

    // do the save thingy
    switch(c) {
        case 0: {
            file1_icon.set_visible(true);
            file2_icon.set_visible(false);
            file3_icon.set_visible(false);
            break;
        }
        case 1: {
            file1_icon.set_visible(false);
            file2_icon.set_visible(true);
            file3_icon.set_visible(false);
            break;
        }
        case 2: {
            file1_icon.set_visible(false);
            file2_icon.set_visible(false);
            file3_icon.set_visible(true);
            break;
        }
        default: {}
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

            bn::sound_items::maple_alright_01.play();
            bn::sound_items::fireblast.play();
            break;
        }
        case 2: {
            victory_anim = bn::create_sprite_animate_action_forever(victory_spr, 3, bn::sprite_items::aaron_victory_anim.tiles_item(),
                                                                                            0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 30, 30, 30, 30, 30, 30, 30, 30);
            victory_anim2 = bn::create_sprite_animate_action_forever(victory_spr2, 3, bn::sprite_items::aaron_victory_anim.tiles_item(),
                                                                                            1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 31, 31, 31, 31, 31, 31, 31, 31);
            
            if (so->xp == 69) {
                bn::sound_items::aaron_yeah_03.play();
            } else {
                bn::sound_items::aaron_yeah_02.play();
            }
            break;
        }
        default: {
            bn::sound_items::enoki_whoo.play();
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
    if (so->checkpoint < 8) {
        if (new_xp > 100) new_xp = 100;
    } else if(so->checkpoint < 10) {
        if (new_xp > 200) new_xp = 100;
    }

    so->xp = new_xp; // Add score to save total

    float bar_modifier = 0.48;
    if (so->checkpoint > 6) {
        bar_modifier = 0.24;
    }
    if (so->checkpoint > 8) {
        bar_modifier = 0.16;
    }

    float new_xp_d = new_xp * bar_modifier;
    int new_xp_p = 0;
    bool final_hit = false;

    auto a_button = bn::sprite_items::a_button.create_sprite(48,48);

    bn::music_items_info::span[13].first.play(bn::fixed(40) / 100);

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
    bn::music_items_info::span[2].first.play(bn::fixed(50) / 100);
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
                bn::sound_items::aaron_yeah_01.play();
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
                    bool penalty = false;
                    for (int t = 0; t < max_chop; t++)
                    {
                        if (chop.at(t).visible()) {
                            penalty = true;
                            score = score / 2;
                        }
                    }

                    if (penalty) {
                        int ugh = std::rand() % 7;
                        switch (ugh) {
                            case 0:
                                bn::sound_items::aaron_ugh_01.play();
                                break;
                            case 1:
                                bn::sound_items::aaron_ugh_02.play();
                                break;
                            case 2:
                                bn::sound_items::aaron_ugh_03.play();
                                break;
                            case 3:
                                bn::sound_items::aaron_ugh_01.play();
                                break;
                            case 4:
                                bn::sound_items::aaron_ugh_05.play();
                                break;
                            case 5:
                                bn::sound_items::aaron_ugh_06.play();
                                break;
                            case 6:
                                bn::sound_items::aaron_ugh_07.play();
                                break;
                            default:

                                // we do not have an entry for aaron_ugh_08
                                // but i can't bring myself to delete it

                                break;
                        }
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
                        for (int tt = 0; tt < 24; tt++)
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

        pc_cursor.set_position(
            pc_cursor.x().integer() + bn::keypad::right_held() - bn::keypad::left_held(),
            pc_cursor.y().integer() + bn::keypad::down_held() - bn::keypad::up_held()
        );

        if (pc_cursor.x() < -30) pc_cursor.set_x(-30);
        if (pc_cursor.x() > 55) pc_cursor.set_x(55);
        if (pc_cursor.y() < -35) pc_cursor.set_y(-35);
        if (pc_cursor.y() > 30) pc_cursor.set_y(30);

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

void victory_toutes(int emotion, int total) {

    bn::music_items_info::span[16].first.play(bn::fixed(80) / 100);
    so->xp += (total / 10);

    bn::rect_window external_window = bn::rect_window::external();
    auto bg = bn::regular_bg_items::bg_toutes.create_bg(0,0);
    auto bg_static = bn::regular_bg_items::bg_static.create_bg(0,0);
    auto face = bn::sprite_items::toutes_spr.create_sprite(-80,-38,1);
    auto food = bn::sprite_items::toutes_spr.create_sprite(24,-92,emotion+3);

    bg_static.set_blending_enabled(true);
    bn::blending::set_transparency_alpha(0.4);

    external_window.set_show_bg(bg, true);
    external_window.set_show_bg(bg_static, false);
    external_window.set_boundaries(-80, -120, 80, 120);

    int w = 0;
    bn::rect_window internal_window = bn::rect_window::internal();
    internal_window.set_show_bg(bg, true);
    internal_window.set_show_bg(bg_static, true);
    internal_window.set_boundaries(-130, 36 - w - 12, 130, 36 + w - 12);

    char buf[36];
    char bf2[36];

    bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
    bn::vector<bn::sprite_ptr, 12> file1_spr;
    bn::sprite_text_generator file2_gen(common::variable_8x16_sprite_font);
    bn::vector<bn::sprite_ptr, 12> file2_spr;

    auto dg_bg1 = bn::sprite_items::dialogue_bg_2.create_sprite(-64, 64);
    auto dg_bg2 = bn::sprite_items::dialogue_bg_2.create_sprite(64, 64);
    dg_bg1.set_scale(2,1);
    dg_bg2.set_scale(2,1);
    dg_bg1.set_visible(false);
    dg_bg2.set_visible(false);

    auto b_button = bn::sprite_items::b_button.create_sprite(90,0);
    b_button.set_visible(false);

    /*
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
    */

    bool ready = false;
    while (!bn::keypad::b_pressed()) {

        if (w < 36) {
            internal_window.set_boundaries(-130, 36 - w - 12, 130, 36 + w - 12);
            w++;
        }

        if (food.y().integer() < -24) {
            food.set_y(food.y() + 1);
        }

        if (food.y().integer() == -24 && !ready) {
            ready = true;
            bn::sound_items::start.play();
            face = bn::sprite_items::toutes_spr.create_sprite(-80,-38,emotion);

            switch(emotion) {
                case 2: {
                    sprintf(buf, "You've got a... smelly sock.");
                    file1_gen.generate(-96, 48, buf, file1_spr);
                    break;
                }
                case 1: {
                    sprintf(buf, "You've got... chocolate mousse!");
                    file1_gen.generate(-96, 48, buf, file1_spr);
                    break;
                }
                case 0: {
                    sprintf(buf, "You've got a twenty!");
                    file1_gen.generate(-96, 48, buf, file1_spr);
                    break;
                }
            }

            sprintf(bf2, "Your XP is now: %d", so->xp);
            file2_gen.generate(-96, 60, bf2, file2_spr);

            dg_bg1.set_visible(true);
            dg_bg2.set_visible(true);
            b_button.set_visible(true);
        }

        bg_static.set_position((bg_static.x().integer() + 2) % 256, (bg_static.y().integer() + 1) % 256);

        bn::core::update();
    }
}

dungeon_return crystal_ball() {

    int score = 0;
    int total = 0;

    if (true) {
    bn::vector<bn::sprite_ptr, 16> buttons;
    bn::vector<int, 16> buttons_n;
    bn::random random;

    bn::regular_bg_ptr crystal_bg = bn::regular_bg_items::bg_crystal01.create_bg(0,0);
    bn::affine_bg_ptr crystal_rot = bn::affine_bg_items::bg_crystal_ball.create_bg(0,0);
    crystal_rot.put_above();

    bn::array<bn::fixed, bn::display::height()> horizontal_deltas;
    bn::affine_bg_pivot_position_hbe_ptr horizontal_hbe =
            bn::affine_bg_pivot_position_hbe_ptr::create_horizontal(crystal_rot, horizontal_deltas);

    bn::fixed base_degrees_angle;

    bn::music_items_info::span[22].first.play(bn::fixed(80) / 100);

    char buf[12];
    char bf2[12];

    bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
    bn::vector<bn::sprite_ptr, 12> file1_spr;
    bn::sprite_text_generator file2_gen(common::variable_8x16_sprite_font);
    bn::vector<bn::sprite_ptr, 12> file2_spr;

    buttons.push_back(bn::sprite_items::magic_keys.create_sprite(96,0,0));
    buttons_n.push_back(0);

    auto b_button = bn::sprite_items::b_button.create_sprite(90,50);
    b_button.set_visible(true);

    for (int t = 0; t < 4; t++) {
        int nb = (random.get() % 7);
        int wd = 16;

        if (buttons.size() > 0) wd = buttons.at(buttons.size() - 1).x().integer() + 36;

        buttons.push_back(bn::sprite_items::magic_keys.create_sprite(wd,0 - pow(wd/5,2) / 5,nb));
        buttons_n.push_back(nb);
    }

    int tick = 0;
    int angle = 0;

    while(!bn::keypad::b_pressed()) {

        base_degrees_angle += 4;

        if(base_degrees_angle >= 360)
        {
            base_degrees_angle -= 360;
        }

        bn::fixed degrees_angle = base_degrees_angle;

        for(int index = 0, limit = bn::display::height() / 2; index < limit; ++index)
        {
            degrees_angle += 16;

            if(degrees_angle >= 360)
            {
                degrees_angle -= 360;
            }

            bn::fixed desp = bn::degrees_lut_sin(degrees_angle) * 8;
            horizontal_deltas[(bn::display::height() / 2) + index] = desp;
            horizontal_deltas[(bn::display::height() / 2) - index - 1] = desp;
        }

        horizontal_hbe.reload_deltas_ref();

        crystal_rot.set_rotation_angle(angle);
        angle = (angle + 1) % 360;

        tick++;
        if (tick == 10) {
            tick = 0;
            if (score > 0) score--;
        }

        sprintf(buf, "Score: %d", score);
        file1_spr.clear();
        file1_gen.generate(-114, -70, buf, file1_spr);

        sprintf(bf2, "Total: %d", total);
        file2_spr.clear();
        file2_gen.generate(-114, -58, bf2, file2_spr);

        if (total < score) total = score;

        int s = 0;
        if (bn::keypad::a_pressed())        s = 1;
        if (bn::keypad::r_pressed())        s = 2;
        if (bn::keypad::l_pressed())        s = 3;
        if (bn::keypad::up_pressed())       s = 4;
        if (bn::keypad::left_pressed())     s = 5;
        if (bn::keypad::right_pressed())    s = 6;
        if (bn::keypad::down_pressed())     s = 7;

        if (s > 0) {
            if (s - 1== buttons_n.at(0)) {
                bn::sound_items::ding.play();
                score += 5;
            } else {
                bn::sound_items::firehit.play();
                score = 0;
            }

            buttons.erase(buttons.begin());
            buttons_n.erase(buttons_n.begin());

            int nb = (random.get() % 7);
            int wd = 16;

            if (buttons.size() > 0) wd = buttons.at(buttons.size() - 1).x().integer() + 36;

            buttons.push_back(bn::sprite_items::magic_keys.create_sprite(wd,0 - pow(wd/5,2) / 5,nb));
            buttons_n.push_back(nb);
        }

        if (buttons.at(0).x() > 0) {
            for (int t = 0; t < buttons.size(); t++) {
                int nw = buttons.at(t).x().integer() - 4;
                buttons.at(t).set_position(nw, 0 - pow(nw/5,2) / 5);
            }
        }

        bn::core::update();
    }
    }

    int emotion = 2;
    if (total > 100) emotion = 1;
    if (total > 200) emotion = 0;

    bn::core::update();
    victory_toutes(emotion, total);

    dungeon_return dt(2, 1, 12);
    return dt;
}

struct boat_camera
{
    bn::fixed x = 440;
    bn::fixed y = 128;
    bn::fixed z = 320;
    int phi = 10;
    int cos = 0;
    int sin = 0;
};

struct rock {
    bn::sprite_ptr entity = bn::sprite_items::avocado.create_sprite(0,-20,5);
    float size = 0.01;
    float m_y = -48;
    int speed = 0;
};

dungeon_return boat_game() {

    int score = 0;
    int total = 0;

    if (true) {
        int phi = 10;
        int cos = 0;
        int sin = 0;
        bn::random random;

        char buf[12];
        char bf2[12];
        char bf3[12]; 

        bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
        bn::vector<bn::sprite_ptr, 12> file1_spr;
        bn::sprite_text_generator file2_gen(common::variable_8x16_sprite_font);
        bn::vector<bn::sprite_ptr, 12> file2_spr;
        bn::sprite_text_generator file3_gen(common::variable_8x16_sprite_font);
        bn::vector<bn::sprite_ptr, 12> file3_spr;

        if (bn::music::playing()) bn::music::stop();
        bn::music_items_info::span[30].first.play(bn::fixed(80) / 100);

        boat_camera camera;
        camera.y = 300;
        //camera.y += bn::fixed::from_data(8192 * 256);
        bn::affine_bg_ptr bg = bn::affine_bg_items::bg_ocean.create_bg(-376, -336);
        bn::affine_bg_ptr bg_trees = bn::affine_bg_items::bg_sky_trees.create_bg(0, -276); // -212

        auto boat = bn::sprite_items::avocado.create_sprite(0, 112);
        auto wave = bn::sprite_items::avocado.create_sprite(0, 112, 3);
        auto wave_anim = bn::create_sprite_animate_action_forever(wave, 2, bn::sprite_items::avocado.tiles_item(), 3, 4, 3, 4);
        boat.set_blending_enabled(true);

        std::vector<bn::sprite_ptr> sky_ptr;
        sky_ptr.push_back(bn::sprite_items::bg_sky.create_sprite(-120 + 16,-132,0)); // -68
        sky_ptr.push_back(bn::sprite_items::bg_sky.create_sprite(-120 + 16 + 64,-132,1));
        sky_ptr.push_back(bn::sprite_items::bg_sky.create_sprite(-120 + 16 + 128,-132,2));
        sky_ptr.push_back(bn::sprite_items::bg_sky.create_sprite(-120 + 16 + 192,-132,3));

        bg.set_z_order(1);
        bg_trees.set_z_order(0);

        int16_t pa_values[bn::display::height()];
        bn::affine_bg_pa_register_hbe_ptr pa_hbe = bn::affine_bg_pa_register_hbe_ptr::create(bg, pa_values);

        int16_t pc_values[bn::display::height()];
        bn::affine_bg_pc_register_hbe_ptr pc_hbe = bn::affine_bg_pc_register_hbe_ptr::create(bg, pc_values);

        int dx_values[bn::display::height()];
        bn::affine_bg_dx_register_hbe_ptr dx_hbe = bn::affine_bg_dx_register_hbe_ptr::create(bg, dx_values);

        int dy_values[bn::display::height()];
        bn::affine_bg_dy_register_hbe_ptr dy_hbe = bn::affine_bg_dy_register_hbe_ptr::create(bg, dy_values);

        float x_offset = 0;

        // Rocks
        rock rs[8] = {};
        for (int t = 0; t < 8; t++) {
            rock r;
            rs[t] = r;
        }

        int isMoving = 0;
        float boat_transparency = 1;

        bn::sound_items::motorboat.play();
        int distance = 32;
        int tick = 0;

        bool completed = false;
        float completed_size = 0.48;

        while(completed_size > 0.02) {

            if (distance < 1) completed = true;

            sprintf(buf, "Score: %d", score);
            file1_spr.clear();
            file1_gen.generate(-114, -58, buf, file1_spr);

            sprintf(bf2, "Total: %d", total);
            file2_spr.clear();
            file2_gen.generate(-114, -46, bf2, file2_spr);

            if (distance < 0) distance = 0;

            sprintf(bf3, "Distance: %d", distance);
            file3_spr.clear();
            file3_gen.generate(-114, -34, bf3, file3_spr);

            if (total < score) total = score;

            bn::blending::set_transparency_alpha(boat_transparency);

            if (boat_transparency < 1) {
                boat_transparency += 0.02;
            }

            if (boat_transparency > 1) {
                boat_transparency = 1;
            }

            if (!completed) {
                isMoving = !bn::keypad::down_held();
                if (bn::keypad::down_released()) bn::sound_items::fireblast.play();
                if (bn::keypad::up_pressed()) bn::sound_items::fireblast.play();
                if (bn::keypad::up_held()) isMoving = 2;
            } else {
                isMoving = 0;
            }

            tick++;
            if (tick > 256) {
                tick = 0;
                distance -= isMoving;
            }

            for (int t = 0; t < 8; t++) {

                if (abs(rs[t].entity.x() - boat.x()) < 24 && abs(rs[t].entity.y() - boat.y()) < 24) {
                    rs[t].m_y += 96;
                    boat_transparency = 0.25;
                    bn::sound_items::firehit.play();
                    score = score / 10;
                }

                if (rs[t].m_y > 128) {
                    if (random.get() % 36 == 0) {
                        rs[t].size = 0.01;
                        rs[t].entity.set_scale(rs[t].size);
                        rs[t].entity.set_x((random.get() % 120) - 60);
                        rs[t].speed = rs[t].entity.x().integer() / 10;

                        if (random.get() % 2 == 0) {
                            rs[t].entity.set_visible(false);
                            rs[t].m_y = (0 - (random.get() % 1280));
                            rs[t].entity.set_y(rs[t].m_y);
                        } else {
                            score++;
                            rs[t].entity.set_visible(true);
                            rs[t].m_y = -48;
                            rs[t].entity.put_above();
                        }
                    } else {
                        rs[t].entity.set_y(rs[t].m_y);
                        rs[t].m_y += 1;
                    }
                } else {
                    rs[t].entity.set_scale(rs[t].size);
                    rs[t].entity.set_y(rs[t].m_y);

                    if (isMoving == 1) {
                        rs[t].entity.set_x(rs[t].entity.x() + rs[t].speed);
                        rs[t].m_y += 1;
                        if (rs[t].size < 1) {
                            rs[t].size += 0.01;
                        }
                    } else if (isMoving == 2) {
                        rs[t].entity.set_x(rs[t].entity.x() + (rs[t].speed * 2));
                        rs[t].m_y += 2;
                        if (rs[t].size < 1) {
                            rs[t].size += 0.02;
                        }
                    }
                }
            }

            int camera_x = camera.x.data();
            int camera_y = camera.y.data() >> 4;
            int camera_z = camera.z.data();
            int camera_cos = camera.cos;
            int camera_sin = camera.sin;
            int y_shift = 160;
            bn::fixed dir_x = 0;
            bn::fixed dir_z = bn::fixed::from_data(-64); //-30

            if (isMoving == 0) {
                dir_z = bn::fixed::from_data(-1);
                wave.set_visible(false);
            } else if (isMoving == 2) {
                dir_z = bn::fixed::from_data(-196);
            }else {
                wave.set_visible(true);
            }

            wave_anim.update();
            wave = wave_anim.sprite();
            boat.put_above();

            // Intro animation
            int sky_y = sky_ptr.at(0).y().integer();
            if (sky_y < -68) {
                if (sky_y > -92) camera.y = camera.y - 3;
                for (int t = 0; t < sky_ptr.size(); t++) {
                    sky_ptr.at(t).set_y(sky_y + 1);
                }
                bg_trees.set_y(bg_trees.y().integer() + 1);
                boat.set_y(boat.y().integer() - 1);
                wave.set_y(wave.y().integer() - 1);
            } else {
                boat = bn::sprite_items::avocado.create_sprite(0, 48, 0);
                if (isMoving > 0) {
                    if (bn::keypad::left_held()) {
                        x_offset += 0.01;
                        dir_x -= bn::fixed::from_data(32);
                        boat = bn::sprite_items::avocado.create_sprite(0, 48, 2);
                        
                        for (int t = 0; t < 8; t++) {
                            rs[t].entity.set_x(rs[t].entity.x().integer() + 1);
                        }
                    }
                    else if (bn::keypad::right_held()) {
                        x_offset -= 0.01;
                        dir_x += bn::fixed::from_data(32);
                        boat = bn::sprite_items::avocado.create_sprite(0, 48, 1);

                        for (int t = 0; t < 8; t++) {
                            rs[t].entity.set_x(rs[t].entity.x().integer() - 1);
                        }
                    }
                }
            }

            bg_trees.set_x(x_offset);

            camera.cos = bn::lut_cos(camera.phi).data() >> 4;
            camera.sin = bn::lut_sin(camera.phi).data() >> 4;
            camera.x += (dir_x * camera.cos) - (dir_z * camera.sin);
            camera.z += (dir_x * camera.sin) + (dir_z * camera.cos);

            for(int index = 0; index < bn::display::height(); ++index)
            {
                int reciprocal = bn::reciprocal_lut[index].data() >> 4;
                int lam = camera_y * reciprocal >> 12;
                int lcf = lam * camera_cos >> 8;
                int lsf = lam * camera_sin >> 8;

                pa_values[index] = int16_t(lcf >> 4);
                pc_values[index] = int16_t(lsf >> 4);

                int lxr = (bn::display::width() / 2) * lcf;
                int lyr = y_shift * lsf;
                dx_values[index] = (camera_x - lxr + lyr) >> 4;

                lxr = (bn::display::width() / 2) * lsf;
                lyr = y_shift * lcf;
                dy_values[index] = (camera_z - lxr - lyr) >> 4;
            }

            pa_hbe.reload_values_ref();
            pc_hbe.reload_values_ref();
            dx_hbe.reload_values_ref();
            dy_hbe.reload_values_ref();

            for (int t = 0; t < sky_ptr.size(); t++) {
                sky_ptr.at(t).put_above();
            }

            if (completed) {
                boat.set_y(boat.y().integer() - 64);
                wave.set_y(wave.y().integer() - 64);
                for (int t = 0; t < 8; t++) {
                    rs[t].entity.set_visible(false);
                }
                boat.set_scale(completed_size);
                wave.set_scale(completed_size);
                float new_completed_size = completed_size - 0.02;
                if (new_completed_size > 0) {
                    completed_size = new_completed_size;
                }
            }

            bn::core::update();
        }

    }

    if (true) {
        char buf[36] = {0};
        char bf2[36] = {0};
        char bf3[36] = {0};

        bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
        bn::vector<bn::sprite_ptr, 32> file1_spr;
        bn::sprite_text_generator file2_gen(common::variable_8x16_sprite_font);
        bn::vector<bn::sprite_ptr, 32> file2_spr;
        bn::sprite_text_generator file3_gen(common::variable_8x16_sprite_font);
        bn::vector<bn::sprite_ptr, 32> file3_spr;

        auto b_button = bn::sprite_items::b_button.create_sprite(90,0);
        b_button.set_visible(false);
        so->xp += (total / 4.675);

        bn::music::stop();
        sprintf(buf, "'Well done! I'll take the");
        file1_gen.generate(-96, -12, buf, file1_spr);
        sprintf(bf3, "boat on the way back.'");
        file3_gen.generate(-96, 0, bf3, file3_spr);

        int xp_count = 1;
        int sfx_play = 0;

        while(!bn::keypad::b_pressed()) {
            auto docks = bn::regular_bg_items::bg_dock.create_bg(0,0);

            if ((xp_count - 1) < so->xp) {
                sfx_play = (sfx_play + 1) % 8;
                if (sfx_play == 1) bn::sound_items::ding.play();
                xp_count++;
            }

            if (xp_count == so->xp - 1) {
                xp_count++;
                b_button.set_visible(true);
                bn::music_items_info::span[16].first.play(bn::fixed(80) / 100);
            }

            sprintf(buf, "XP: %d", xp_count - 1);
            file2_spr.clear();
            file2_gen.generate(-96, 48, buf, file2_spr);

            bn::core::update();
        }
    }

    dungeon_return dt(9, 17, 4);
    return dt;
}

dungeon_return store() {

    auto bg = bn::regular_bg_items::cruz_01.create_bg(0,0);

    int item = -1;
    auto b_button = bn::sprite_items::b_button.create_sprite(90,-50);
    auto item_hat = bn::sprite_items::funny_items.create_sprite(-80, 32, 0);
    auto item_bal = bn::sprite_items::funny_items.create_sprite(80, 32, 2);

    if (so->hat_world > -1) item_hat = bn::sprite_items::funny_items.create_sprite(-80, 32, 2);

    item_hat.set_scale(2,2);
    item_bal.set_scale(2,2);

    char xp_val[8];
    char item_name[16];
    char description[16];
    char status[8];

    bn::sprite_text_generator text_gen(common::variable_8x16_sprite_font);
    bn::vector<bn::sprite_ptr, 8> xp_spr;
    bn::vector<bn::sprite_ptr, 16> item_spr;
    bn::vector<bn::sprite_ptr, 16> desc_spr;
    bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
    bn::sprite_text_generator file2_gen(common::variable_8x16_sprite_font);
    bn::sprite_text_generator file3_gen(common::variable_8x16_sprite_font);

    sprintf(xp_val, "XP: %d", so->xp);
    file1_gen.generate(64, -48, xp_val, xp_spr);
    int skip = 0;
    bn::core::update();

    while(!bn::keypad::b_pressed()) {

        if (bn::keypad::a_pressed()) {
            if (so->hat_world == -1 && item == -1 && so->xp >= 75) {
                bn::sound_items::ching.play();
                item_hat = bn::sprite_items::funny_items.create_sprite(-80, 32, 2);
                item_hat.set_scale(2,2);
                so->xp -= 75;
                so->hat_char = so->last_char_id;
                so->hat_world = 14;

                b_button.set_visible(false);
                bn::core::update();

                line lc[32] = {
                    {true, true, 00, "                                                                  Merci!!                          I know you'll love it!"},
                    {true, true, 00, "COM: Endscene"}};
                dialogue_page_lite(lc);

                b_button.set_visible(true);

            } else {
                bn::sound_items::firehit.play();
            }

            xp_spr.clear();
            sprintf(xp_val, "XP: %d", so->xp);
            file1_gen.generate(64, -48, xp_val, xp_spr);
        }

        if (bn::keypad::left_pressed() || bn::keypad::right_pressed()) {
            bn::sound_items::pop.play();
            item = item * -1;
        }

        if (item == -1) {
            item_spr.clear();
            file2_gen.generate(-114, -58, "BANANA HAT", item_spr);
            desc_spr.clear();
            file3_gen.generate(-114, -70, "Price: 75 XP", desc_spr);

            if (item_hat.y() > 32 - 8) item_hat.set_y(item_hat.y() - 1);
            if (item_bal.y() <  32) item_bal.set_y(item_bal.y() + 1);
        } else {
            item_spr.clear();
            file2_gen.generate(-114, -58, "COMING SOON ITEM", item_spr);
            desc_spr.clear();
            file3_gen.generate(-114, -70, "Price: N/A", desc_spr);

            if (item_bal.y() > 32 - 8) item_bal.set_y(item_bal.y() - 1);
            if (item_hat.y() <  32) item_hat.set_y(item_hat.y() + 1);
        }

        bn::core::update();
    }

    dungeon_return dt(3, 8, 14);
    return dt;
}

class ingredient {
    public:
    bn::sprite_ptr entity = bn::sprite_items::gumbo.create_sprite(0,0,0);
    int type = 0;
};

dungeon_return kitchen() {

    int score = 0;

    char buf[36] = {0};
    char bf2[36] = {0};
    char bf3[36] = {0};

    bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
    bn::vector<bn::sprite_ptr, 32> file1_spr;
    bn::sprite_text_generator file2_gen(common::variable_8x16_sprite_font);
    bn::vector<bn::sprite_ptr, 32> file2_spr;
    bn::sprite_text_generator file3_gen(common::variable_8x16_sprite_font);
    bn::vector<bn::sprite_ptr, 32> file3_spr;

    bn::music_items_info::span[34].first.play(bn::fixed(80) / 100);

    char buf1[32] = {};
    char buf2[32] = {};

    // Cooking bit
    if (true) {
        auto tr_bg = bn::regular_bg_items::axe_game_bg.create_bg(0,0);
        auto pc_bg = bn::regular_bg_items::bg_cooking_01.create_bg(8,0);
        int chari = 0;

        bn::sprite_ptr hand = bn::sprite_items::gumbo.create_sprite(0,0,14);

        while(chari < 7) {

            int je_veus_de = 8 + std::rand() % 4;

            switch(chari) {
                case 0:
                    bn::sound_items::maple_hey_01.play();
                    break;
                case 1:
                    bn::sound_items::enoki_hey.play();
                    break;
                case 2:
                    bn::sound_items::aaron_hey_02.play();
                    break;
                case 3:
                    bn::sound_items::scout_hey_01.play();
                    break;
                case 4:
                    bn::sound_items::vee_hey_01.play();
                    break;
                case 5:
                    bn::sound_items::eleanor_hey_01.play();
                    break;
                case 6:
                    bn::sound_items::diana_hey_01.play();
                    break;
            }

            ingredient food[6];
            bn::sprite_ptr je_veus_de_food = bn::sprite_items::gumbo.create_sprite(40, -52, je_veus_de);

            food[0].entity = bn::sprite_items::gumbo.create_sprite(-42,-39 + 48,13); // Knife
            food[1].entity = bn::sprite_items::gumbo.create_sprite(-10,-39 + 38,0);
            food[2].entity = bn::sprite_items::gumbo.create_sprite(-10,-39 + 57,1);
            food[3].entity = bn::sprite_items::gumbo.create_sprite(-10,-39 + 76,4);

            food[4].entity = bn::sprite_items::gumbo.create_sprite(32,-39 + 38,12); // Bowl
            food[5].entity = bn::sprite_items::gumbo.create_sprite(-78,-24,5);      // Spices
            
            for (int t = 0; t < 5; t++) {
                food[t].type = 0;
            }

            int sel = -1;
            int counter = 0;

            bn::sprite_ptr chari_mons = bn::sprite_items::gumbo_mons.create_sprite(102,-57, chari * 2);
            chari_mons.put_below();
            bool done = false;
            bool ready = false;
            bool ready_freddy = false;
            float blend_value = 0;

            bn::blending::set_transparency_alpha(0);

            while(!done) {
                hand.put_above();

                if (blend_value < 0.05 && ready_freddy) {
                    done = true;
                }

                if (food[4].type == je_veus_de && !ready) {

                    switch(chari) {
                        case 0:
                            bn::sound_items::maple_alright_04.play();
                            break;
                        case 1:
                            bn::sound_items::enoki_whoo.play();
                            break;
                        case 2:
                            bn::sound_items::aaron_yeah_01.play();
                            break;
                        case 3:
                            bn::sound_items::scout_nice_01.play();
                            break;
                        case 4:
                            bn::sound_items::vee_alright_01.play();
                            break;
                        case 5:
                            bn::sound_items::eleanor_merci_01.play();
                            break;
                        case 6:
                            bn::sound_items::diana_alright_01.play();
                            break;
                    }

                    ready = true;
                    chari_mons = bn::sprite_items::gumbo_mons.create_sprite(102,-57, (chari * 2) + 1);
                    chari_mons.put_below();
                }

                counter++;
                if (counter > 5) {
                    if (score > 0) score--;
                    counter = 0;
                }

                file1_spr.clear();
                file2_spr.clear();
                file1_gen.generate(-104, -72, buf1, file1_spr);
                file2_gen.generate(-104, -60,  buf2, file2_spr);
                sprintf(buf1, "");
                sprintf(buf2, "Score: %d", score);

                for (int t = 0; t < 6; t++) {
                    if (food[t].entity.y() < -24 && t != sel) {
                        food[t].entity.set_y(food[t].entity.y() + 2);
                    }
                    if (abs(food[t].entity.x() - hand.x()) + abs(food[t].entity.y() - hand.y()) < 16) {
                        switch(t-1) {
                            case 0:
                                sprintf(buf1, "Holy Trinity");
                                break;
                            case 1:
                                sprintf(buf1, "Proteins");
                                break;
                            case 2:
                                sprintf(buf1, "Roux");
                                break;
                            case 3:
                                switch(food[t].type) {
                                    case 1:
                                        sprintf(buf1, "Rice Bowl");
                                        break;
                                    case 8:
                                        sprintf(buf1, "Jumbalaya");
                                        break;
                                    case 9:
                                        sprintf(buf1, "Gumbo");
                                        break;
                                    case 10:
                                        sprintf(buf1, "Gumbo + Rice");
                                        break;
                                    case 11:
                                        sprintf(buf1, "Ettoufee");
                                        break;
                                    default:
                                        sprintf(buf1, "Empty Bowl");
                                        break;
                                }
                                break;
                            case 4:
                                sprintf(buf1, "Spices");
                                break;
                        }
                    }
                }

                if (bn::keypad::a_pressed()) {
                    bn::sound_items::pop.play();

                    for (int t = 0; t < 6; t++) {
                        if (abs(food[t].entity.x() - hand.x()) + abs(food[t].entity.y() - hand.y()) < 16) {
                            sel = t;
                        }
                    }
                }

                if (sel > -1) {
                    food[sel].entity.set_position(hand.x(), hand.y());
                }

                if (bn::keypad::a_released()) {
                    bn::sound_items::fireblast.play();

                    if (sel == 0) {
                        for (int t = 1; t < 3; t++) {
                            if (abs(food[t].entity.x() - hand.x()) + abs(food[t].entity.y() - hand.y()) < 16) {
                                food[t].entity = bn::sprite_items::gumbo.create_sprite(food[t].entity.x(),food[t].entity.y(),t + 1);
                                food[t].type = 1;
                                score += 50;
                            }
                        }
                    } else if ((sel > 0 && sel < 3 && food[sel].type == 1) || sel == 3) {
                        if (abs(food[4].entity.x() - hand.x()) + abs(food[4].entity.y() - hand.y()) < 16) {
                            switch(food[4].type) {
                                case 1:
                                    if (sel == 1) {
                                        food[4].type = 7;
                                        food[4].entity = bn::sprite_items::gumbo.create_sprite(food[4].entity.x(),food[4].entity.y(),7);
                                        food[1].entity.set_visible(false);
                                        score += 50;
                                    }
                                    break;
                                case 7:
                                    if (sel == 2) {
                                        food[4].type = 8;
                                        food[4].entity = bn::sprite_items::gumbo.create_sprite(food[4].entity.x(),food[4].entity.y(),8);
                                        food[2].entity.set_visible(false);
                                        score += 50;
                                    }
                                    break;
                                case 8:
                                    if (sel == 3) {
                                        food[4].type = 9;
                                        food[4].entity = bn::sprite_items::gumbo.create_sprite(food[4].entity.x(),food[4].entity.y(),9);
                                        food[3].entity.set_y(food[3].entity.y().integer() + 16);
                                        score += 50;
                                    }
                                    break;
                                case 9:
                                    if (sel == 3) {
                                        food[4].type = 11;
                                        food[4].entity = bn::sprite_items::gumbo.create_sprite(food[4].entity.x(),food[4].entity.y(),11);
                                        food[3].entity.set_visible(false);
                                        score += 50;
                                    }
                                    break;
                            }
                        }

                    } else if (sel == 4) {
                        if (abs(-105 - hand.x()) + abs(-30 - hand.y()) < 16) {
                            if (food[4].type == 0) {
                                food[4].type = 1;
                                food[4].entity = bn::sprite_items::gumbo.create_sprite(food[4].entity.x(),food[4].entity.y(),6);
                                score += 50;
                            } else if (food[4].type == 9) {
                                food[4].type = 10;
                                food[4].entity = bn::sprite_items::gumbo.create_sprite(food[4].entity.x(),food[4].entity.y(),10);
                                score += 50;
                            }
                        } else if (hand.x().integer() > 84 && hand.y().integer() < -33) {
                            ready_freddy = true;
                            if (food[4].type == je_veus_de) {
                                score += 100;
                                bn::sound_items::cnaut.play();
                            } else {
                                score = score / 2;
                                bn::sound_items::firecrackle.play();
                            }
                        }
                    } else if (sel == 5) {
                        if (abs(food[4].entity.x() - hand.x()) + abs(food[4].entity.y() - hand.y()) < 16) {
                            food[5].entity.set_visible(false);
                            score += std::rand() % 100;
                        }
                    }

                    sel = -1;
                }

                if (bn::keypad::a_held()) {
                    hand = bn::sprite_items::gumbo.create_sprite(hand.x(),hand.y(),15);
                } else {
                    hand = bn::sprite_items::gumbo.create_sprite(hand.x(),hand.y(),14);
                }

                if (bn::keypad::up_held()) {
                    hand.set_y(hand.y().integer() - 1);
                }

                if (bn::keypad::down_held()) {
                    hand.set_y(hand.y().integer() + 1);
                }

                if (bn::keypad::left_held()) {
                    hand.set_x(hand.x().integer() - 1);
                }

                if (bn::keypad::right_held()) {
                    hand.set_x(hand.x().integer() + 1);
                }

                if (bn::keypad::b_pressed()) {
                    chari = 7;
                    done = true;
                }

                bn::core::update();
            }
        
            chari++;
        }
    }

    // Reward screen
    if (true) {
        sprintf(buf1, "");
        file1_spr.clear();
        file3_spr.clear();
        file1_gen.generate(-104, -72, buf1, file1_spr);
        file3_gen.generate(-104, -72, buf1, file3_spr);

        bn::music::stop();
        bn::core::update();

        auto face_spr = bn::sprite_items::bg_monch_face.create_sprite(8, -43);
        auto face_b_like = bn::create_sprite_animate_action_forever(face_spr, 4, bn::sprite_items::bg_monch_face.tiles_item(), 0, 1, 2, 3, 4, 5, 6, 7);
        auto pc_bg = bn::regular_bg_items::bg_monch.create_bg(0,0);

        auto b_button = bn::sprite_items::b_button.create_sprite(90,0);
        b_button.set_visible(false);
        so->xp += (score / 22);
        int xp_count = 1;
        int sfx_play = 0;
        while(!bn::keypad::b_pressed()) {

            if ((xp_count - 1) < so->xp) {
                sfx_play = (sfx_play + 1) % 8;
                if (sfx_play == 1) bn::sound_items::ding.play();
                xp_count++;
            }

            if (xp_count == so->xp - 1) {
                xp_count++;
                b_button.set_visible(true);
                bn::music_items_info::span[16].first.play(bn::fixed(80) / 100);
            }

            sprintf(buf, "XP: %d", xp_count - 1);
            file2_spr.clear();
            file2_gen.generate(-84, 32, buf, file2_spr);
            face_b_like.update();
            face_spr = face_b_like.sprite();

            bn::core::update();
        }
    }

    dungeon_return dt(4, 4, 13);
    return dt;
}

void final_battle() {

    bn::camera_ptr camera = bn::camera_ptr::create(0, 0);

    auto bg_stage = bn::regular_bg_items::bg_stage.create_bg(0,0);
    bg_stage.set_camera(camera);

    bn::music_items_info::span[35].first.play(bn::fixed(100) / 100);
    auto axe = bn::sprite_items::ax_bar.create_sprite(0, 64);

    int aaron_x = -64;
    int aaron_y = -64;
    int aaron_offset_x = 0;
    int aaron_offset_y = 0;

    bool aaron_change = true;
    int aaron_action = 1;

    int rufus_x = 64;
    int rufus_y = -64;

    int rufus_offset_x = 0;
    int rufus_offset_y = 0;

    bool rufus_change = true;
    int rufus_action = 1;

    auto aaron_tile = bn::sprite_items::fight_tiles.create_sprite(96,64,0);
    auto rufus_tile = bn::sprite_items::fight_tiles.create_sprite(-96,64,1);

    auto a_01 = bn::sprite_items::battle_aaron.create_sprite(aaron_x + 0, aaron_y + 0);
    auto a_02 = bn::sprite_items::battle_aaron.create_sprite(aaron_x + 0, aaron_y + 64);
    auto a_03 = bn::sprite_items::battle_aaron.create_sprite(aaron_x + 64, aaron_y + 0);
    auto a_04 = bn::sprite_items::battle_aaron.create_sprite(aaron_x + 64, aaron_y + 64);
    auto a_01_anim = bn::create_sprite_animate_action_forever(a_01, 1, bn::sprite_items::battle_aaron.tiles_item(), 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22);
    auto a_02_anim = bn::create_sprite_animate_action_forever(a_02, 1, bn::sprite_items::battle_aaron.tiles_item(), 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23);
    auto a_03_anim = bn::create_sprite_animate_action_forever(a_03, 1, bn::sprite_items::battle_aaron.tiles_item(), 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46);
    auto a_04_anim = bn::create_sprite_animate_action_forever(a_04, 1, bn::sprite_items::battle_aaron.tiles_item(), 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47);

    auto r_01 = bn::sprite_items::battle_rufus.create_sprite(rufus_x + 0, rufus_y + 0);
    auto r_02 = bn::sprite_items::battle_rufus.create_sprite(rufus_x + 0, rufus_y + 64);
    auto r_03 = bn::sprite_items::battle_rufus.create_sprite(rufus_x + 64, rufus_y + 0);
    auto r_04 = bn::sprite_items::battle_rufus.create_sprite(rufus_x + 64, rufus_y + 64);
    auto r_01_anim = bn::create_sprite_animate_action_forever(r_01, 1, bn::sprite_items::battle_rufus.tiles_item(), 0, 2, 2, 4, 6, 8, 8, 10, 12, 14, 14, 16);
    auto r_02_anim = bn::create_sprite_animate_action_forever(r_02, 1, bn::sprite_items::battle_rufus.tiles_item(), 1, 3, 3, 5, 7, 9, 9, 11, 13, 15, 15, 17);
    auto r_03_anim = bn::create_sprite_animate_action_forever(r_03, 1, bn::sprite_items::battle_rufus.tiles_item(), 18, 20, 20, 22, 24, 26, 26, 28, 30, 32, 32, 34);
    auto r_04_anim = bn::create_sprite_animate_action_forever(r_04, 1, bn::sprite_items::battle_rufus.tiles_item(), 19, 21, 21, 23, 25, 27, 27, 29, 31, 33, 33, 35);    

    int rufus_logic = 3;

    while(axe.x() > -72) {

        if (aaron_x < -128) aaron_x = -128;
        if (rufus_x > 128) rufus_x = 128;

        // controls
        if (bn::keypad::left_released() || bn::keypad::right_released()) {
            aaron_change = true;
            aaron_action = 1;
        }

        if (bn::keypad::left_pressed()) {
            aaron_change = true;
            aaron_action = 4;
        }
        if (bn::keypad::left_held()) {
            aaron_x -= 4;
        }

        if (bn::keypad::right_pressed()) {
            aaron_change = true;
            aaron_action = 0;
        }
        if (bn::keypad::right_held()) {
            aaron_x += 4;
        }

        // handle random movement
        if (std::rand() % 50 == 0) {
            int old_logic = rufus_logic;
            rufus_logic = std::rand() % 12;
            if (old_logic != rufus_logic) {
                if (rufus_x > 100) rufus_logic = 0;
                rufus_change = true;
            }
        }

        switch(rufus_logic) {
            case 0: {
                rufus_action = 0;
                rufus_x -= 1;
                break;
            };
            case 1: {
                rufus_action = 4;
                rufus_x += 1;
                break;
            };
            case 13: {
                rufus_action = 2;
                break;
            }
            case 14: {
                rufus_action = 3;
                break;
            }
            default: {
                rufus_action = 1;
                break;
            };
        }

        // Collision logic

        if (abs(rufus_x - aaron_x) < 72) {
            axe.set_x(axe.x() - 3);

            rufus_action = 2;
            rufus_change = true;
            aaron_action = 3;
            aaron_change = true;

            bn::sound_items::firehit.play();

            if (std::rand() % 16 == 0) {
                bn::sound_items::mina_aw.play();
            }

            int ugh = std::rand() % 12;
            switch (ugh) {
                case 0:
                    bn::sound_items::aaron_ugh_01.play();
                    break;
                case 1:
                    bn::sound_items::aaron_ugh_02.play();
                    break;
                case 2:
                    bn::sound_items::aaron_ugh_03.play();
                    break;
                case 3:
                    bn::sound_items::aaron_ugh_01.play();
                    break;
                case 4:
                    bn::sound_items::aaron_ugh_05.play();
                    break;
                case 5:
                    bn::sound_items::aaron_ugh_06.play();
                    break;
                case 6:
                    bn::sound_items::aaron_ugh_07.play();
                    break;
                default:

                    // we do not have an entry for aaron_ugh_08
                    // but i can't bring myself to delete it

                    break;
            }
        }

        if (bn::keypad::a_pressed() && aaron_action != 3) {
            bn::sound_items::firehit.play();

            if (abs(rufus_x - aaron_x) < 96) {
                rufus_action = 3;
                rufus_change = true;
                bn::sound_items::rufus_01.play();
                axe.set_x(axe.x() + 1);

                if (std::rand() % 24 == 0) {
                    bn::sound_items::mina_whoo.play();
                }
            }

            aaron_action = 2;
            aaron_change = true;
        }
 
        // Handle animation changes
        if (aaron_change) {
            aaron_change = false;
            switch(aaron_action) {
                case 0: {
                    a_01_anim = bn::create_sprite_animate_action_forever(a_01, 1, bn::sprite_items::battle_aaron.tiles_item(), 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22);
                    a_02_anim = bn::create_sprite_animate_action_forever(a_02, 1, bn::sprite_items::battle_aaron.tiles_item(), 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23);
                    a_03_anim = bn::create_sprite_animate_action_forever(a_03, 1, bn::sprite_items::battle_aaron.tiles_item(), 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46);
                    a_04_anim = bn::create_sprite_animate_action_forever(a_04, 1, bn::sprite_items::battle_aaron.tiles_item(), 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47);

                    aaron_offset_x = 4;
                    aaron_offset_y = 6;
                    break;
                };
                case 1: {
                    a_01_anim = bn::create_sprite_animate_action_forever(a_01, 1, bn::sprite_items::battle_aaron.tiles_item(), 48, 48, 50, 52, 54, 56, 56, 58, 60, 62, 64, 66);
                    a_02_anim = bn::create_sprite_animate_action_forever(a_02, 1, bn::sprite_items::battle_aaron.tiles_item(), 49, 49, 51, 53, 55, 57, 57, 59, 61, 63, 65, 67);
                    a_03_anim = bn::create_sprite_animate_action_forever(a_03, 1, bn::sprite_items::battle_aaron.tiles_item(), 70, 70, 72, 74, 76, 78, 78, 80, 82, 84, 86, 88);
                    a_04_anim = bn::create_sprite_animate_action_forever(a_04, 1, bn::sprite_items::battle_aaron.tiles_item(), 71, 71, 73, 75, 77, 79, 79, 81, 83, 85, 87, 89);

                    aaron_offset_x = 6;
                    aaron_offset_y = 6;
                    break;
                };
                case 2: {
                    a_01_anim = bn::create_sprite_animate_action_forever(a_01, 1, bn::sprite_items::battle_aaron.tiles_item(), 92, 92, 94, 96, 98, 100, 100, 100, 100, 100, 100, 100);
                    a_02_anim = bn::create_sprite_animate_action_forever(a_02, 1, bn::sprite_items::battle_aaron.tiles_item(), 93, 93, 95, 97, 99, 101, 101, 101, 101, 101, 101, 101);
                    a_03_anim = bn::create_sprite_animate_action_forever(a_03, 1, bn::sprite_items::battle_aaron.tiles_item(), 104, 104, 106, 108, 110, 112, 112, 112, 112, 112, 112, 114);
                    a_04_anim = bn::create_sprite_animate_action_forever(a_04, 1, bn::sprite_items::battle_aaron.tiles_item(), 105, 105, 107, 109, 111, 113, 113, 113, 113, 113, 113, 115);

                    aaron_offset_x = 0;
                    aaron_offset_y = 0;
                    break;
                };
                case 3: {
                    a_01_anim = bn::create_sprite_animate_action_forever(a_01, 1, bn::sprite_items::battle_aaron.tiles_item(), 116, 118, 120, 122, 124, 126, 126, 126, 126, 126, 126, 126);
                    a_02_anim = bn::create_sprite_animate_action_forever(a_02, 1, bn::sprite_items::battle_aaron.tiles_item(), 117, 119, 121, 123, 125, 127, 127, 127, 127, 127, 127, 127);
                    a_03_anim = bn::create_sprite_animate_action_forever(a_03, 1, bn::sprite_items::battle_aaron.tiles_item(), 128, 130, 132, 134, 136, 138, 138, 138, 138, 138, 138, 138);
                    a_04_anim = bn::create_sprite_animate_action_forever(a_04, 1, bn::sprite_items::battle_aaron.tiles_item(), 129, 131, 133, 135, 137, 139, 139, 139, 139, 139, 139, 139);

                    aaron_offset_x = 0;
                    aaron_offset_y = 0;
                    break;
                };
                case 4: {
                    a_01_anim = bn::create_sprite_animate_action_forever(a_01, 1, bn::sprite_items::battle_aaron.tiles_item(), 22 ,20 ,18 ,16 ,14 ,12 ,10 ,8 ,6 ,4 ,2 ,0);
                    a_02_anim = bn::create_sprite_animate_action_forever(a_02, 1, bn::sprite_items::battle_aaron.tiles_item(), 23 ,21 ,19 ,17 ,15 ,13 ,11 ,9 ,7 ,5 ,3 ,1);
                    a_03_anim = bn::create_sprite_animate_action_forever(a_03, 1, bn::sprite_items::battle_aaron.tiles_item(), 46 ,44 ,42 ,40 ,38 ,36 ,34 ,32 ,30 ,28 ,26 ,24);
                    a_04_anim = bn::create_sprite_animate_action_forever(a_04, 1, bn::sprite_items::battle_aaron.tiles_item(), 47 ,45 ,43 ,41 ,39 ,37 ,35 ,33 ,31 ,29 ,27 ,25);

                    aaron_offset_x = 4;
                    aaron_offset_y = 6;
                    break;
                };
            }
        }

        if (rufus_change) {
            rufus_change = false;
            switch(rufus_action) {
                case 0: {
                    r_01_anim = bn::create_sprite_animate_action_forever(r_01, 1, bn::sprite_items::battle_rufus.tiles_item(), 0, 2, 2, 4, 6, 8, 8, 10, 12, 14, 14, 16);
                    r_02_anim = bn::create_sprite_animate_action_forever(r_02, 1, bn::sprite_items::battle_rufus.tiles_item(), 1, 3, 3, 5, 7, 9, 9, 11, 13, 15, 15, 17);
                    r_03_anim = bn::create_sprite_animate_action_forever(r_03, 1, bn::sprite_items::battle_rufus.tiles_item(), 18, 20, 20, 22, 24, 26, 26, 28, 30, 32, 32, 34);
                    r_04_anim = bn::create_sprite_animate_action_forever(r_04, 1, bn::sprite_items::battle_rufus.tiles_item(), 19, 21, 21, 23, 25, 27, 27, 29, 31, 33, 33, 35);
                    break;
                };
                case 1: {
                    r_01_anim = bn::create_sprite_animate_action_forever(r_01, 1, bn::sprite_items::battle_rufus.tiles_item(), 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58);
                    r_02_anim = bn::create_sprite_animate_action_forever(r_02, 1, bn::sprite_items::battle_rufus.tiles_item(), 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59);
                    r_03_anim = bn::create_sprite_animate_action_forever(r_03, 1, bn::sprite_items::battle_rufus.tiles_item(), 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82);
                    r_04_anim = bn::create_sprite_animate_action_forever(r_04, 1, bn::sprite_items::battle_rufus.tiles_item(), 61, 63, 65, 67, 69, 71, 73, 75, 77, 79, 81, 83);
                    break;
                };
                case 2: {
                    r_01_anim = bn::create_sprite_animate_action_forever(r_01, 1, bn::sprite_items::battle_rufus.tiles_item(), 84, 86, 90, 92, 94, 96, 98, 100, 102, 102, 102, 102);
                    r_02_anim = bn::create_sprite_animate_action_forever(r_02, 1, bn::sprite_items::battle_rufus.tiles_item(), 85, 87, 91, 93, 95, 97, 99, 101, 103, 103, 103, 103);
                    r_03_anim = bn::create_sprite_animate_action_forever(r_03, 1, bn::sprite_items::battle_rufus.tiles_item(), 104, 106, 108, 110, 112, 114, 116, 118, 120, 120, 120, 120);
                    r_04_anim = bn::create_sprite_animate_action_forever(r_04, 1, bn::sprite_items::battle_rufus.tiles_item(), 105, 107, 109, 111, 113, 115, 117, 119, 121, 121, 121, 121);
                    BN_LOG("RUFUS ATTACK");
                    break;
                };
                case 3: {
                    r_01_anim = bn::create_sprite_animate_action_forever(r_01, 1, bn::sprite_items::battle_rufus.tiles_item(), 124, 126, 128, 130, 132, 134, 136, 138, 140, 140, 140, 140);
                    r_02_anim = bn::create_sprite_animate_action_forever(r_02, 1, bn::sprite_items::battle_rufus.tiles_item(), 125, 127, 129, 131, 133, 135, 137, 139, 141, 141, 141, 141);
                    r_03_anim = bn::create_sprite_animate_action_forever(r_03, 1, bn::sprite_items::battle_rufus.tiles_item(), 144, 146, 148, 150, 152, 154, 156, 158, 160, 160, 160, 160);
                    r_04_anim = bn::create_sprite_animate_action_forever(r_04, 1, bn::sprite_items::battle_rufus.tiles_item(), 145, 147, 149, 151, 153, 155, 157, 159, 161, 161, 161, 161);
                    BN_LOG("RUFUS DEFEND");
                    break;
                };
                case 4: {
                    r_01_anim = bn::create_sprite_animate_action_forever(r_01, 1, bn::sprite_items::battle_rufus.tiles_item(), 16 ,14 ,14 ,12 ,10 ,8 ,8 ,6 ,4 ,2 ,2 ,0);
                    r_02_anim = bn::create_sprite_animate_action_forever(r_02, 1, bn::sprite_items::battle_rufus.tiles_item(), 17 ,15 ,15 ,13 ,11 ,9 ,9 ,7 ,5 ,3 ,3 ,1);
                    r_03_anim = bn::create_sprite_animate_action_forever(r_03, 1, bn::sprite_items::battle_rufus.tiles_item(), 34 ,32 ,32 ,30 ,28 ,26 ,26 ,24 ,22 ,20 ,20 ,18);
                    r_04_anim = bn::create_sprite_animate_action_forever(r_04, 1, bn::sprite_items::battle_rufus.tiles_item(), 35 ,33 ,33 ,31 ,29 ,27 ,27 ,25 ,23 ,21 ,21 ,19 );
                    break;
                };
            }
        }

        camera.set_x(((rufus_x + aaron_x) / 2) + 32);

        // Handle Aaron's movement
        a_01_anim.update();
        a_02_anim.update();
        a_03_anim.update();
        a_04_anim.update();
        a_01 = a_01_anim.sprite();
        a_02 = a_02_anim.sprite();
        a_03 = a_03_anim.sprite();
        a_04 = a_04_anim.sprite();
        a_01.set_camera(camera);
        a_02.set_camera(camera);
        a_03.set_camera(camera);
        a_04.set_camera(camera);
        a_01.set_position(aaron_x + aaron_offset_x, aaron_y + aaron_offset_y);
        a_02.set_position(aaron_x + aaron_offset_x, aaron_y + aaron_offset_y + 64);
        a_03.set_position(aaron_x + aaron_offset_x + 64, aaron_y + aaron_offset_y);
        a_04.set_position(aaron_x + aaron_offset_x + 64, aaron_y + aaron_offset_y + 64);

        // Handle Rufus's movement
        r_01_anim.update();
        r_02_anim.update();
        r_03_anim.update();
        r_04_anim.update();
        r_01 = r_01_anim.sprite();
        r_02 = r_02_anim.sprite();
        r_03 = r_03_anim.sprite();
        r_04 = r_04_anim.sprite();
        r_01.set_camera(camera);
        r_02.set_camera(camera);
        r_03.set_camera(camera);
        r_04.set_camera(camera);
        r_01.set_position(rufus_x + rufus_offset_x, rufus_y + rufus_offset_y);
        r_02.set_position(rufus_x + rufus_offset_x, rufus_y + rufus_offset_y + 64);
        r_03.set_position(rufus_x + rufus_offset_x + 64, rufus_y + rufus_offset_y);
        r_04.set_position(rufus_x + rufus_offset_x + 64, rufus_y + rufus_offset_y + 64);
        bn::core::update();

        if (aaron_action == 2 || aaron_action == 3) {

            for (int t = 1; t < 8; t++) {
                // Handle Aaron's movement
                a_01_anim.update();
                a_02_anim.update();
                a_03_anim.update();
                a_04_anim.update();
                a_01 = a_01_anim.sprite();
                a_02 = a_02_anim.sprite();
                a_03 = a_03_anim.sprite();
                a_04 = a_04_anim.sprite();
                a_01.set_camera(camera);
                a_02.set_camera(camera);
                a_03.set_camera(camera);
                a_04.set_camera(camera);
                a_01.set_position(aaron_x + aaron_offset_x, aaron_y + aaron_offset_y);
                a_02.set_position(aaron_x + aaron_offset_x, aaron_y + aaron_offset_y + 64);
                a_03.set_position(aaron_x + aaron_offset_x + 64, aaron_y + aaron_offset_y);
                a_04.set_position(aaron_x + aaron_offset_x + 64, aaron_y + aaron_offset_y + 64);

                // Handle Rufus's movement
                r_01_anim.update();
                r_02_anim.update();
                r_03_anim.update();
                r_04_anim.update();
                r_01 = r_01_anim.sprite();
                r_02 = r_02_anim.sprite();
                r_03 = r_03_anim.sprite();
                r_04 = r_04_anim.sprite();
                r_01.set_camera(camera);
                r_02.set_camera(camera);
                r_03.set_camera(camera);
                r_04.set_camera(camera);
                r_01.set_position(rufus_x + rufus_offset_x, rufus_y + rufus_offset_y);
                r_02.set_position(rufus_x + rufus_offset_x, rufus_y + rufus_offset_y + 64);
                r_03.set_position(rufus_x + rufus_offset_x + 64, rufus_y + rufus_offset_y);
                r_04.set_position(rufus_x + rufus_offset_x + 64, rufus_y + rufus_offset_y + 64);
                bn::core::update();
            }

            if (aaron_action == 2) {
                if (rufus_action == 3) {
                    rufus_x += 32;
                }
            } else {
                aaron_x -= 32;
            }

            aaron_action = 1;
            aaron_change = true;
        }
    }
}

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

        // March event
        if (so->checkpoint == 4 && so->xp > 99 && so->last_char_id != 4) {
            so->checkpoint = 5;
            break;
        }

        // June event
        if (so->checkpoint == 8 && so->xp > 199) {
            so->checkpoint = 9;
            break;
        }

        // June event
        if (so->checkpoint == 10 && so->xp > 299) {
            so->checkpoint = 12;
            break;
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
                case 5: {
                    dt = crystal_ball();
                    break;
                }
                case 6: {
                    exec_dialogue(27);
                    dt = boat_game();
                    break;
                }
                case 7: {
                    bn::blending::set_transparency_alpha(0);
                    bn::music_items_info::span[33].first.play(bn::fixed(80) / 100);
                    if (so->hat_world == -1) {
                        if (so->last_char_id == 1) {
                            exec_dialogue(31);
                        } else {
                            exec_dialogue(30);
                        }
                    }
                    dt = store();
                    break;
                }
                case 8: {
                    dt = kitchen();
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
            exec_dialogue(3);
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
            if (so->last_char_id == 3) {
                core_gameplay(8, 10, 4, 0, true);
            } else if (so->last_char_id < 3) {
                core_gameplay(9, 6, 4, 0, true);
            } else {
                core_gameplay(10, 6, 8, 0, true);
            }
            break;

        case 9:
            exec_dialogue(29);
            exec_dialogue(28);
            break;

        case 10:
            if (so->last_char_id == 3) {
                core_gameplay(8, 10, 4, 0, true);
            } else if (so->last_char_id < 3) {
                core_gameplay(9, 6, 4, 0, true);
            } else {
                core_gameplay(10, 6, 8, 0, true);
            }
            break;

        case 11:
            so->checkpoint = 10;
            break;

        case 12:

            if (bn::music::playing()) bn::music::stop();

            exec_dialogue(32);
            so->last_char_id = 2;
            core_gameplay(9, 6, 4, 0, true);
            break;

        case 13:
            so->checkpoint = 12;
            break;

        case 14: {
            dungeon_return dt;
            dt.spawn_x = 1;//1;//3;//22;//1;
            dt.spawn_y = 9;//9;//62;//22;//9;
            dt.world_index = 0;//0;//2;//1;//0;

            do {
                dt = rufus_dungeon(dt, so);
            } while(dt.world_index < 99);

            break;
        }

        case 15: {
            exec_dialogue(34);
            final_battle();
            exec_dialogue(35);
        }

        default:
            return 0;
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

    while (so->checkpoint < 99) {
        so->checkpoint = checkpoint(so->checkpoint);
    }

    // Get to the end?
    bn::core::reset();
}