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
#include <bn_random.h>
#include "bn_math.h"
#include "bn_window.h"
#include <bn_string.h>
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
#include "bn_music_items.h"
#include "bn_music_items_info.h"

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

#include "bn_sprite_items_selection.h"
#include "bn_regular_bg_items_keyboard_bg.h"

#include "bn_regular_bg_map_ptr.h"
#include "bn_regular_bg_map_cell_info.h"

#include "bn_regular_bg_items_bg_trailer_home.h"

#include "bn_affine_bg_items_bg_crystal_ball.h"
#include "bn_regular_bg_items_bg_crystal01.h"
#include "bn_sprite_items_bg_sky.h"
#include "bn_sprite_items_l_button.h"

// Extended headers
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
#include "bn_sprite_items_underground_tiles.h"

#include "bn_regular_bg_items_cinemint_01.h"
#include "bn_regular_bg_items_cinemint_02.h"
#include "bn_regular_bg_items_cinemint_03.h"
#include "bn_regular_bg_items_cinemint_04.h"

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
#include "bn_regular_bg_items_bg_monch.h"
#include "bn_sprite_items_bg_monch_face.h"

#include "bn_sprite_items_battle_aaron.h"
#include "bn_sprite_items_battle_rufus.h"
#include "bn_sprite_items_fight_tiles.h"
#include "bn_regular_bg_items_bg_stage.h"

#include <sstream>
#include <bn_blending.h>
#include <bn_regular_bg_ptr.h>

#include <bn_sprite_builder.h>
#include <bn_sprite_animate_actions.h>

// UI elements
#include "bn_sprite_items_a_button_2.h"
#include "bn_sprite_items_score.h"
#include "bn_sprite_items_awards.h"

// Characters
#include "bn_sprite_items_maple_walking.h"
#include "bn_sprite_items_maple_walking_spring.h"
#include "bn_sprite_items_maple_walking_oo.h"
#include "bn_sprite_items_enoki_walking_pj.h"
#include "bn_sprite_items_enoki_walking_spring.h"
#include "bn_sprite_items_enoki_walking_oo.h"
#include "bn_sprite_items_aaron_sleep.h"
#include "bn_sprite_items_aaron_walking_spring.h"
#include "bn_sprite_items_aaron_walking_oo.h"
#include "bn_sprite_items_scout_walking_spring.h"
#include "bn_sprite_items_vee_walking_spring.h"
#include "bn_sprite_items_eleanor_walking_spring.h"
#include "bn_sprite_items_diana_walking_spring.h"
#include "bn_sprite_items_del_sleep.h"
#include "bn_sprite_items_guy_walking_spring.h"

// Items
#include "bn_sprite_items_fireball.h"
#include "bn_sprite_items_fireplace_anim.h"
#include "bn_sprite_items_bookshelf.h"
#include "bn_sprite_items_cave_bat.h"

// Backgrounds
#include "bn_sprite_items_environment_stone.h"
#include "bn_sprite_items_underground_tiles.h"
#include "bn_sprite_items_trailer_home.h"
#include "bn_sprite_items_pools_tiles.h"
#include "bn_regular_bg_items_castle_floor.h"
#include "bn_regular_bg_items_bg_landry_cottage.h"
#include "bn_regular_bg_items_bg_diana_room.h"
#include "bn_regular_bg_items_greenhouse_bg_01.h"
#include "bn_regular_bg_items_bg_library.h"
#include "bn_regular_bg_items_bg_guy_house.h"

#include "bn_sprite_items_ocean_terrain.h"
#include "bn_regular_bg_items_grassy_knoll.h"
#include "bn_sprite_items_scout_lab.h"
#include "bn_sprite_items_corinne.h"
#include "bn_sprite_items_diana_uke.h"

#include "bn_sprite_items_funny_items.h"
#include "bn_regular_bg_items_bg_explosion.h"

#include "bn_affine_bg_items_bg_ocean.h"

#include "bn_regular_bg_items_tc_intro.h"
#include "bn_regular_bg_items_tc_1.h"
#include "bn_regular_bg_items_tc_2.h"
#include "bn_regular_bg_items_tc_3.h"
#include "bn_regular_bg_items_tc_4.h"
#include "bn_regular_bg_items_tc_5.h"

/*
Maple   0
Enoki   1
Aaron   2
Scout   3
Vee     4
Eleanor 5
Diana   6
Guy     7
*/

#include <string.h>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <list>

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
#include "bn_sprite_items_chapters.h"
#include "bn_regular_bg_items_cinemint_studios.h"
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
#include "bn_sprite_items_the_tree.h"
#include "bn_regular_bg_items_castle_floor.h"
#include "bn_regular_bg_items_scout_tv_01.h"
#include "bn_regular_bg_items_scout_tv_01_01.h"
#include "bn_regular_bg_items_scout_tv_02.h"
#include "bn_regular_bg_items_scout_tv_02_01.h"
#include "bn_regular_bg_items_scout_tv_03.h"
#include "bn_regular_bg_items_scout_tv_03_01.h"
#include "bn_regular_bg_items_scout_tv_04.h"
#include "bn_regular_bg_items_scout_tv_04_01.h"

#include "bn_regular_bg_items_s0101.h"
#include "bn_regular_bg_items_s0101_1.h"
#include "bn_regular_bg_items_s0101_2.h"

#include "bn_regular_bg_items_s0102.h"
#include "bn_regular_bg_items_s0102_01.h"
#include "bn_regular_bg_items_s0102_02.h"

#include "bn_regular_bg_items_s0103.h"
#include "bn_regular_bg_items_s0103_01.h"
#include "bn_regular_bg_items_s0103_02.h"

#include "bn_regular_bg_items_s0104.h"
#include "bn_regular_bg_items_s0104_01.h"
#include "bn_regular_bg_items_s0104_02.h"

#include "bn_regular_bg_items_s0105.h"

#include "bn_regular_bg_items_s0106.h"
#include "bn_regular_bg_items_s0106_01.h"
#include "bn_regular_bg_items_s0106_02.h"

#include "bn_regular_bg_items_s0107.h"
#include "bn_regular_bg_items_s0107_01.h"
#include "bn_regular_bg_items_s0107_02.h"

#include "bn_regular_bg_items_s0108.h"
#include "bn_regular_bg_items_s0108_01.h"
#include "bn_regular_bg_items_s0108_02.h"

#include "bn_regular_bg_items_s0109.h"
#include "bn_regular_bg_items_s0109a.h"
#include "bn_regular_bg_items_s0109b.h"

#include "bn_regular_bg_items_ocean.h"
#include "bn_regular_bg_items_ocean_01.h"
#include "bn_regular_bg_items_ocean_02.h"

#include "bn_regular_bg_items_castle01.h"
#include "bn_regular_bg_items_castle01_01.h"
#include "bn_regular_bg_items_castle01_02.h"

#include "bn_regular_bg_items_castle02.h"
#include "bn_regular_bg_items_castle02_01.h"
#include "bn_regular_bg_items_castle02_02.h"

#include "bn_regular_bg_items_castle03.h"
#include "bn_regular_bg_items_castle03_01.h"
#include "bn_regular_bg_items_castle03_02.h"

#include "bn_regular_bg_items_s0201.h"
#include "bn_regular_bg_items_s0202.h"
#include "bn_regular_bg_items_s0203.h"
#include "bn_regular_bg_items_s0204.h"
#include "bn_regular_bg_items_s0205.h"
#include "bn_regular_bg_items_s0206.h"

#include "bn_regular_bg_items_s0207.h"
#include "bn_regular_bg_items_s0207_01.h"
#include "bn_regular_bg_items_s0207_02.h"

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
#include "bn_regular_bg_items_s0501_01.h"
#include "bn_regular_bg_items_s0501_02.h"

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

#include "bn_regular_bg_items_s0202_02.h"
#include "bn_regular_bg_items_s0401_01.h"
#include "bn_regular_bg_items_s0401_02.h"
#include "bn_regular_bg_items_s0402_01.h"
#include "bn_regular_bg_items_s0402_02.h"
#include "bn_regular_bg_items_s0403_01.h"
#include "bn_regular_bg_items_s0403_02.h"
#include "bn_regular_bg_items_s0404_01.h"
#include "bn_regular_bg_items_s0404_02.h"
#include "bn_regular_bg_items_s0405_01.h"
#include "bn_regular_bg_items_s0405_02.h"
#include "bn_regular_bg_items_s0406_01.h"
#include "bn_regular_bg_items_s0406_02.h"
#include "bn_regular_bg_items_s0407_01.h"
#include "bn_regular_bg_items_s0407_02.h"

#include "bn_regular_bg_items_s0302_02.h"
#include "bn_regular_bg_items_s0909_02.h"
#include "bn_regular_bg_items_s0711_01.h"
#include "bn_regular_bg_items_s0711_02.h"
#include "bn_regular_bg_items_s0910_01.h"
#include "bn_regular_bg_items_s0712_01.h"
#include "bn_regular_bg_items_s0910_02.h"
#include "bn_regular_bg_items_s0712_02.h"
#include "bn_regular_bg_items_s0713_01.h"
#include "bn_regular_bg_items_s0911_01.h"
#include "bn_regular_bg_items_s0713_02.h"
#include "bn_regular_bg_items_s0911_02.h"
#include "bn_regular_bg_items_s0714_01.h"
#include "bn_regular_bg_items_s0912_01.h"
#include "bn_regular_bg_items_s0714_02.h"
#include "bn_regular_bg_items_s0912_02.h"
#include "bn_regular_bg_items_s0715_01.h"
#include "bn_regular_bg_items_s0913_01.h"
#include "bn_regular_bg_items_s0715_02.h"
#include "bn_regular_bg_items_s0913_02.h"
#include "bn_regular_bg_items_s0716_01.h"
#include "bn_regular_bg_items_s0914_01.h"
#include "bn_regular_bg_items_s0716_02.h"
#include "bn_regular_bg_items_s0914_02.h"
#include "bn_regular_bg_items_s0717_01.h"
#include "bn_regular_bg_items_s0915_01.h"
#include "bn_regular_bg_items_s0717_02.h"
#include "bn_regular_bg_items_s0915_02.h"
#include "bn_regular_bg_items_s0718_01.h"
#include "bn_regular_bg_items_s0916_01.h"
#include "bn_regular_bg_items_s0718_02.h"
#include "bn_regular_bg_items_s0916_02.h"
#include "bn_regular_bg_items_s0801_01.h"
#include "bn_regular_bg_items_s0917_01.h"
#include "bn_regular_bg_items_s0801_02.h"
#include "bn_regular_bg_items_s0917_02.h"
#include "bn_regular_bg_items_s0802_01.h"
#include "bn_regular_bg_items_s0918_01.h"
#include "bn_regular_bg_items_s0502_01.h"
#include "bn_regular_bg_items_s0802_02.h"
#include "bn_regular_bg_items_s0918_02.h"
#include "bn_regular_bg_items_s0502_02.h"
#include "bn_regular_bg_items_s0803_01.h"
#include "bn_regular_bg_items_s1001_01.h"
#include "bn_regular_bg_items_s0601_01.h"
#include "bn_regular_bg_items_s0803_02.h"
#include "bn_regular_bg_items_s1001_02.h"
#include "bn_regular_bg_items_s0601_02.h"
#include "bn_regular_bg_items_s0804_01.h"
#include "bn_regular_bg_items_s1002_01.h"
#include "bn_regular_bg_items_s0602_01.h"
#include "bn_regular_bg_items_s0804_02.h"
#include "bn_regular_bg_items_s1002_02.h"
#include "bn_regular_bg_items_s0602_02.h"
#include "bn_regular_bg_items_s0603_01.h"
#include "bn_regular_bg_items_s0805_01.h"
#include "bn_regular_bg_items_s1003_01.h"
#include "bn_regular_bg_items_s0603_02.h"
#include "bn_regular_bg_items_s0805_02.h"
#include "bn_regular_bg_items_s1003_02.h"
#include "bn_regular_bg_items_s0701_01.h"
#include "bn_regular_bg_items_s0806_01.h"
#include "bn_regular_bg_items_s1004_01.h"
#include "bn_regular_bg_items_s0701_02.h"
#include "bn_regular_bg_items_s0806_02.h"
#include "bn_regular_bg_items_s1004_02.h"
#include "bn_regular_bg_items_s0202_01.h"
#include "bn_regular_bg_items_s0202_02.h"
#include "bn_regular_bg_items_s0702_01.h"
#include "bn_regular_bg_items_s0807_01.h"
#include "bn_regular_bg_items_s1005_01.h"
#include "bn_regular_bg_items_s0702_02.h"
#include "bn_regular_bg_items_s0807_02.h"
#include "bn_regular_bg_items_s1005_02.h"
#include "bn_regular_bg_items_s0203_01.h"
#include "bn_regular_bg_items_s0203_02.h"
#include "bn_regular_bg_items_s0703_01.h"
#include "bn_regular_bg_items_s0901_01.h"
#include "bn_regular_bg_items_s1006_01.h"
#include "bn_regular_bg_items_s0703_02.h"
#include "bn_regular_bg_items_s0901_02.h"
#include "bn_regular_bg_items_s1006_02.h"
#include "bn_regular_bg_items_s0204_01.h"
#include "bn_regular_bg_items_s0204_02.h"
#include "bn_regular_bg_items_s0704_01.h"
#include "bn_regular_bg_items_s0902_01.h"
#include "bn_regular_bg_items_s1007_01.h"
#include "bn_regular_bg_items_s0704_02.h"
#include "bn_regular_bg_items_s0902_02.h"
#include "bn_regular_bg_items_s1007_02.h"
#include "bn_regular_bg_items_s0205_01.h"
#include "bn_regular_bg_items_s0205_02.h"
#include "bn_regular_bg_items_s0705_01.h"
#include "bn_regular_bg_items_s0903_01.h"
#include "bn_regular_bg_items_s1008_01.h"
#include "bn_regular_bg_items_s0705_02.h"
#include "bn_regular_bg_items_s0903_02.h"
#include "bn_regular_bg_items_s1008_02.h"
#include "bn_regular_bg_items_s0206_01.h"
#include "bn_regular_bg_items_s0206_02.h"
#include "bn_regular_bg_items_s0706_01.h"
#include "bn_regular_bg_items_s0904_01.h"
#include "bn_regular_bg_items_s1009_01.h"
#include "bn_regular_bg_items_s0706_02.h"
#include "bn_regular_bg_items_s0904_02.h"
#include "bn_regular_bg_items_s1009_02.h"
#include "bn_regular_bg_items_s0707_01.h"
#include "bn_regular_bg_items_s0905_01.h"
#include "bn_regular_bg_items_s1010_01.h"
#include "bn_regular_bg_items_s0707_02.h"
#include "bn_regular_bg_items_s0905_02.h"
#include "bn_regular_bg_items_s1010_02.h"
#include "bn_regular_bg_items_s0208_01.h"
#include "bn_regular_bg_items_s0708_01.h"
#include "bn_regular_bg_items_s0906_01.h"
#include "bn_regular_bg_items_s1011_01.h"
#include "bn_regular_bg_items_s0208_02.h"
#include "bn_regular_bg_items_s0708_02.h"
#include "bn_regular_bg_items_s0906_02.h"
#include "bn_regular_bg_items_s1011_02.h"
#include "bn_regular_bg_items_s0301_01.h"
#include "bn_regular_bg_items_s0709_01.h"
#include "bn_regular_bg_items_s0908_01.h"
#include "bn_regular_bg_items_s1012_01.h"
#include "bn_regular_bg_items_s0301_02.h"
#include "bn_regular_bg_items_s0709_02.h"
#include "bn_regular_bg_items_s0908_02.h"
#include "bn_regular_bg_items_s1012_02.h"
#include "bn_regular_bg_items_s0710_01.h"
#include "bn_regular_bg_items_s0302_01.h"
#include "bn_regular_bg_items_s0710_02.h"
#include "bn_regular_bg_items_s0909_01.h"

#include "bn_regular_bg_items_s1101.h"
#include "bn_regular_bg_items_s1101_01.h"
#include "bn_regular_bg_items_s1101_02.h"
#include "bn_regular_bg_items_s1102.h"
#include "bn_regular_bg_items_s1102_01.h"
#include "bn_regular_bg_items_s1102_02.h"
#include "bn_regular_bg_items_s1103.h"
#include "bn_regular_bg_items_s1103_01.h"
#include "bn_regular_bg_items_s1103_02.h"

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

// 0 = saving enabled
// 1 = saving disabled

#define DEVICE_TYPE 1

bn::fixed_t<12> lerp(bn::fixed a, int b, bn::fixed_t<12> t) {
	return a * (1 - t) + b * t;
}

class save_struct {
public:
	short int last_char_id = 0;
	short int checkpoint = 0;
	char island_name[16] = { 0 };
	short int spawn_x = 0;
	short int spawn_y = 0;
	short int world_index = 0;
	short int xp = 0;
	short int hat_x = 0;
	short int hat_y = 0;
	short int hat_world = 0;
	short int hat_char = -1;
	bool popups[16] = { false };
	bool keys[16] = {false};

	save_struct() {}

	void clear() {
		last_char_id = -1;
		checkpoint = 0;
		spawn_x = 0;
		spawn_y = 0;
		world_index = 0;
		xp = 0;
		hat_x = -1;
		hat_y = -1;
		hat_world = -1;
		hat_char = -1;

		char def[16] = { 0 };
		strcpy(island_name, def);

		for (int t = 0; t < 16; t++) {
			keys[t] = 0;
		}
	}
};

class save_all_struct {
public:
	save_struct current_save[3];
	int save_init = 0;
	int language = 0;
};

// defined expressions
constexpr auto fals = false;
constexpr auto tile_count = 400;

// Reserved global memory
class global_data {
	public:
		save_all_struct all_save;
		save_struct* current_save;
		bn::vector<unsigned short int, tile_count> local_tileset;
		bn::vector<bn::rect_window, 2> rendered_windows;
		bn::vector<unsigned short int, tile_count> collisions;
		int rand_state;
		bn::random bn_random;

		global_data() {
			rand_state = 0;
		}
};

global_data* globals;

void flash_write() {
	if (DEVICE_TYPE == 0) {
		bn::sram::write(globals->all_save);
	}
}

void flash_read() {
	if (DEVICE_TYPE == 0) {
		bn::sram::read(globals->all_save);
	}
}

void flash_reset() {
	if (DEVICE_TYPE == 0) {
		globals = new global_data();
		bn::sram::write(globals->all_save);
	}
}

__attribute__((section(".ewram.std_rnd")))
int std_rnd(int x = 0)
{
	globals->rand_state = (globals->rand_state * 137 + 12345) % 2048;
	return abs(globals->rand_state) % x;
}

int std_abs(int x) {
	short int nx = x * -1;
	if (nx > x) return nx;
	return x;
}

// Generic classes
class line {
public:
	bool transition;
	bool left;
	const int img = 0;
	const char text[192] = { 0 };
	const char move_to = 0;
};

// Generic classes
class line_min {
public:
	const char text[34] = { 0 };
};

// Set pointer by integer reference
void set_sprite(bn::sprite_ptr chari, int value) {
	switch (value) {
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

	case 32:
		chari.set_item(bn::sprite_items::the_tree);
		break;

	default:
		break;
	}
}

int select_minigame() {
	globals->rendered_windows.clear();

	{
		bn::rect_window external_window = bn::rect_window::external();
		external_window.set_show_sprites(true);
		globals->rendered_windows.push_back(external_window);

		bn::rect_window internal_window = bn::rect_window::internal();
		internal_window.set_show_sprites(true);
		globals->rendered_windows.push_back(internal_window);
	}

	auto velvet = bn::regular_bg_items::velvet.create_bg(0,0);
	auto arrow = bn::sprite_items::arrow.create_sprite(-106, 0);
	int t = 0;
	int select = 0;

	if (bn::music::playing()) bn::music::stop();
	bn::music_items_info::span[8].first.play(bn::fixed(0.8) / 100);

	bn::vector<bn::sprite_ptr, 7> chari;
	bn::sprite_ptr c1 = bn::sprite_items::save_tiles.create_sprite(-64,0,0);
	bn::sprite_ptr c2 = bn::sprite_items::save_tiles.create_sprite(-64,32,1);
	bn::sprite_ptr c3 = bn::sprite_items::save_tiles.create_sprite(-64,64,2);
	bn::sprite_ptr c4 = bn::sprite_items::save_tiles.create_sprite(-64,96,3);
	bn::sprite_ptr c5 = bn::sprite_items::save_tiles.create_sprite(-64,128,5);
	bn::sprite_ptr c6 = bn::sprite_items::save_tiles.create_sprite(-64,160,6);
	bn::sprite_ptr c7 = bn::sprite_items::save_tiles.create_sprite(-64,192,7);
	chari.push_back(c1);
	chari.push_back(c2);
	chari.push_back(c3);
	chari.push_back(c4);
	chari.push_back(c5);
	chari.push_back(c6);
	chari.push_back(c7);

	bn::sprite_text_generator text_line(common::variable_8x16_sprite_font);
	bn::vector<bn::sprite_ptr, 32> text_sprite0;

	bn::sprite_ptr a_button = bn::sprite_items::a_button.create_sprite(-90, -48, 0);

	while (!bn::keypad::a_pressed())
	{
		// Scrolling background
		t++;
		t = t % 256;
		velvet.set_position(t, t);

		for (int t = 0; t < chari.size(); t++) {
			chari.at(t).set_y(lerp(chari.at(t).y(), ((t - select) * 36), bn::fixed(0.2)));
		}

		text_sprite0.clear();
		switch (select) {
			case 0: {
				text_line.generate(-16, 0, "Maple's Gem Thing", text_sprite0);
				break;
			}
			case 1: {
				text_line.generate(-16, 0, "Enoki's Garden", text_sprite0);
				break;
			}
			case 2: {
				text_line.generate(-16, 0, "Aaron's 'Ax Game'", text_sprite0);
				break;
			}
			case 3: {
				text_line.generate(-16, 0, "Scout's Computer", text_sprite0);
				break;
			}
			case 4: {
				text_line.generate(-16, 0, "Eleanor's Crystal Ball", text_sprite0);
				break;
			}
			case 5: {
				text_line.generate(-16, 0, "Diana's 'Boat Game'", text_sprite0);
				break;
			}
			case 6: {
				text_line.generate(-16, 0, "Guy's 'Kitchen Game'", text_sprite0);
				break;
			}
		}

		if (arrow.y() > 0) arrow.set_y(arrow.y() - 1);
		if (arrow.y() < 0) arrow.set_y(arrow.y() + 1);

		if (bn::keypad::up_pressed()) {
			bn::sound_items::ui_sfx02.play();
			arrow.set_y(4);
			select--;
			if (select < 0) select = 6;
		}

		if (bn::keypad::down_pressed()) {
			bn::sound_items::ui_sfx02.play();
			arrow.set_y(-4);
			select++;
			if (select > 6) select = 0;
		}

		bn::core::update();
	}

	return select;
}

// Primary page
void dialogue_page(line n[32]) {

	// Variable initialization
	bn::vector<const bn::regular_bg_item*, 5> backdrops;
	bn::sprite_text_generator text_line(common::variable_8x16_sprite_font);
	bn::sprite_ptr chari_l = bn::sprite_items::maple01.create_sprite(-50, -15);
	bn::sprite_ptr chari_r = bn::sprite_items::maple01.create_sprite(50, -15);
	bn::sprite_ptr a_button = bn::sprite_items::a_button.create_sprite(-90, -72, 1);
	chari_l.set_visible(false);
	chari_r.set_visible(false);
	chari_r.set_horizontal_flip(true);
	bn::blending::set_intensity_alpha(0);

	bn::optional<bn::regular_bg_ptr> cascade_bg = bn::regular_bg_items::velvet.create_bg(0, 0);
	short int cascade_id = 0;

	auto dg_bg1 = bn::sprite_items::dialogue_bg_2.create_sprite(-64, 64 - 16);
	auto dg_bg2 = bn::sprite_items::dialogue_bg_2.create_sprite(64, 64 - 16);
	dg_bg1.set_scale(2, 1);
	dg_bg2.set_scale(2, 1);
	dg_bg1.set_blending_enabled(true);
	dg_bg2.set_blending_enabled(true);
	bn::fixed_t<12> bg_alpha = 0.0;

	// While dialogue is going,
	short int pos = 0;
	bool cont = true;
	short int music_volume = 80;
	while (cont) {

		// Set music
		if (strcmp(n[pos].text, "BG: 0") == 0) {
			bn::music_items_info::span[0].first.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text, "BG: 1") == 0) {
			bn::music_items_info::span[1].first.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text, "BG: 2") == 0) {
			bn::music_items_info::span[2].first.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text, "BG: champ") == 0) {
			bn::music_items_info::span[10].first.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text, "BG: Overworld 01") == 0) {
			bn::music_items_info::span[11].first.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text, "BG: frog") == 0) {
			bn::music_items_info::span[15].first.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text, "BG: news") == 0) {
			bn::music_items_info::span[24].first.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text, "BG: rain") == 0) {
			bn::music_items_info::span[14].first.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text, "BG: the flame") == 0) {
			bn::music_items_info::span[23].first.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text, "BG: maple") == 0) {
			bn::music_items_info::span[19].first.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text, "BG: pools") == 0) {
			bn::music_items_info::span[30].first.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text, "BG: groovy") == 0) {
			bn::music_items_info::span[20].first.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text, "BG: fadeout") == 0) {
			if (bn::music::playing()) {
				bn::music::set_volume(0);
			}

			// Sound effects
		}
		else if (strcmp(n[pos].text, "SF: Hey Maple") == 0) {
			bn::sound_items::heymaple.play();
		}
		else if (strcmp(n[pos].text, "SF: Maple Ugh") == 0) {
			bn::sound_items::maple_ugh_01.play();
		}
		else if (strcmp(n[pos].text, "SF: Rufus Squeak") == 0) {
			bn::sound_items::rufus_01.play();
		}
		else if (strcmp(n[pos].text, "SF: Rufus Laugh") == 0) {
			bn::sound_items::rufus_02.play();
		}
		else if (strcmp(n[pos].text, "SF: Boom") == 0) {
			bn::sound_items::boom.play();
		}
		else if (strcmp(n[pos].text, "SF: rufus") == 0) {
			bn::sound_items::rufus_02.play();

			//SE: rufus

			// Set backgrounds
		}
		else if (strcmp(n[pos].text, "BG: Ocean") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::ocean);
			backdrops.push_back(&bn::regular_bg_items::ocean_01);
			backdrops.push_back(&bn::regular_bg_items::ocean_02);
		}
		else if (strcmp(n[pos].text, "BG: Moody") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::bg_moody);
		}
		else if (strcmp(n[pos].text, "BG: CRUZ01") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::cruz_01);
		}
		else if (strcmp(n[pos].text, "BG: CRUZ02") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::cruz_02);
		}
		else if (strcmp(n[pos].text, "BG: Trailer Home") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::bg_trailer_home);
			cascade_bg.value().set_position(88, -64);
		}
		else if (strcmp(n[pos].text, "S01:01") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0101);
			backdrops.push_back(&bn::regular_bg_items::s0101_1);
			backdrops.push_back(&bn::regular_bg_items::s0101_2);
		}
		else if (strcmp(n[pos].text, "S01:02") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0102);
			backdrops.push_back(&bn::regular_bg_items::s0102_01);
			backdrops.push_back(&bn::regular_bg_items::s0102_02);
		}
		else if (strcmp(n[pos].text, "S01:03") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0103);
			backdrops.push_back(&bn::regular_bg_items::s0103_01);
			backdrops.push_back(&bn::regular_bg_items::s0103_02);
		}
		else if (strcmp(n[pos].text, "S01:04") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0104);
			backdrops.push_back(&bn::regular_bg_items::s0104_01);
			backdrops.push_back(&bn::regular_bg_items::s0104_02);
		}
		else if (strcmp(n[pos].text, "S01:05") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0105);
		}
		else if (strcmp(n[pos].text, "S01:06") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0106);
			backdrops.push_back(&bn::regular_bg_items::s0106_01);
			backdrops.push_back(&bn::regular_bg_items::s0106_02);
		}
		else if (strcmp(n[pos].text, "S01:07") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0107);
			backdrops.push_back(&bn::regular_bg_items::s0107_01);
			backdrops.push_back(&bn::regular_bg_items::s0107_02);
		}
		else if (strcmp(n[pos].text, "S01:08") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0108);
			backdrops.push_back(&bn::regular_bg_items::s0108_01);
			backdrops.push_back(&bn::regular_bg_items::s0108_02);
		}
		else if (strcmp(n[pos].text, "S01:09") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0109);
			backdrops.push_back(&bn::regular_bg_items::s0109a);
			backdrops.push_back(&bn::regular_bg_items::s0109b);
		}
		else if (strcmp(n[pos].text, "S01:10") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::castle01);
			backdrops.push_back(&bn::regular_bg_items::castle01_01);
			backdrops.push_back(&bn::regular_bg_items::castle01_02);
		}
		else if (strcmp(n[pos].text, "S01:11") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::castle02);
			backdrops.push_back(&bn::regular_bg_items::castle02_01);
			backdrops.push_back(&bn::regular_bg_items::castle02_02);
		}
		else if (strcmp(n[pos].text, "S01:12") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::castle03);
			backdrops.push_back(&bn::regular_bg_items::castle03_01);
			backdrops.push_back(&bn::regular_bg_items::castle03_02);
		}
		else if (strcmp(n[pos].text, "S01:13") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::day_castle);
		}
		else if (strcmp(n[pos].text, "S02:01") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0201);
		}
		else if (strcmp(n[pos].text, "S02:02") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0202);
			backdrops.push_back(&bn::regular_bg_items::s0202_01);
			backdrops.push_back(&bn::regular_bg_items::s0202_02);
		}
		else if (strcmp(n[pos].text, "S02:03") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0203);
			backdrops.push_back(&bn::regular_bg_items::s0203_01);
			backdrops.push_back(&bn::regular_bg_items::s0203_02);
		}
		else if (strcmp(n[pos].text, "S02:04") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0204);
			backdrops.push_back(&bn::regular_bg_items::s0204_01);
			backdrops.push_back(&bn::regular_bg_items::s0204_02);
		}
		else if (strcmp(n[pos].text, "S02:05") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0205);
			backdrops.push_back(&bn::regular_bg_items::s0205_01);
			backdrops.push_back(&bn::regular_bg_items::s0205_02);
		}
		else if (strcmp(n[pos].text, "S02:06") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0206);
			backdrops.push_back(&bn::regular_bg_items::s0206_01);
			backdrops.push_back(&bn::regular_bg_items::s0206_02);
		}
		else if (strcmp(n[pos].text, "S02:07") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0207);
			backdrops.push_back(&bn::regular_bg_items::s0207_01);
			backdrops.push_back(&bn::regular_bg_items::s0207_02);
		}
		else if (strcmp(n[pos].text, "S02:08") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0208);
			backdrops.push_back(&bn::regular_bg_items::s0208_01);
			backdrops.push_back(&bn::regular_bg_items::s0208_02);
		}
		else if (strcmp(n[pos].text, "S03:01") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0301);
			backdrops.push_back(&bn::regular_bg_items::s0301_01);
			backdrops.push_back(&bn::regular_bg_items::s0301_02);
		}
		else if (strcmp(n[pos].text, "S03:02") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0302);
			backdrops.push_back(&bn::regular_bg_items::s0302_01);
			backdrops.push_back(&bn::regular_bg_items::s0302_02);
		}
		else if (strcmp(n[pos].text, "S04:01") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0401);
			backdrops.push_back(&bn::regular_bg_items::s0401_01);
			backdrops.push_back(&bn::regular_bg_items::s0401_02);
		}
		else if (strcmp(n[pos].text, "S04:02") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0402);
			backdrops.push_back(&bn::regular_bg_items::s0402_01);
			backdrops.push_back(&bn::regular_bg_items::s0402_02);
		}
		else if (strcmp(n[pos].text, "S04:03") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0403);
			backdrops.push_back(&bn::regular_bg_items::s0403_01);
			backdrops.push_back(&bn::regular_bg_items::s0403_02);
		}
		else if (strcmp(n[pos].text, "S04:04") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0404);
			backdrops.push_back(&bn::regular_bg_items::s0404_01);
			backdrops.push_back(&bn::regular_bg_items::s0404_02);
		}
		else if (strcmp(n[pos].text, "S04:05") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0405);
			backdrops.push_back(&bn::regular_bg_items::s0405_01);
			backdrops.push_back(&bn::regular_bg_items::s0405_02);
		}
		else if (strcmp(n[pos].text, "S04:06") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0406);
			backdrops.push_back(&bn::regular_bg_items::s0406_01);
			backdrops.push_back(&bn::regular_bg_items::s0406_02);
		}
		else if (strcmp(n[pos].text, "S04:07") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0407);
			backdrops.push_back(&bn::regular_bg_items::s0407_01);
			backdrops.push_back(&bn::regular_bg_items::s0407_02);
		}
		else if (strcmp(n[pos].text, "S05:01") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0501);
			backdrops.push_back(&bn::regular_bg_items::s0501_01);
			backdrops.push_back(&bn::regular_bg_items::s0501_02);
		}
		else if (strcmp(n[pos].text, "S05:02") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0502);
			backdrops.push_back(&bn::regular_bg_items::s0502_01);
			backdrops.push_back(&bn::regular_bg_items::s0502_02);
		}
		else if (strcmp(n[pos].text, "S06:01") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0601);
			backdrops.push_back(&bn::regular_bg_items::s0601_01);
			backdrops.push_back(&bn::regular_bg_items::s0601_02);
		}
		else if (strcmp(n[pos].text, "S06:02") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0602);
			backdrops.push_back(&bn::regular_bg_items::s0602_01);
			backdrops.push_back(&bn::regular_bg_items::s0602_02);
		}
		else if (strcmp(n[pos].text, "S06:03") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0603);
			backdrops.push_back(&bn::regular_bg_items::s0603_01);
			backdrops.push_back(&bn::regular_bg_items::s0603_02);
		}
		else if (strcmp(n[pos].text, "S07:01") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0701);
			backdrops.push_back(&bn::regular_bg_items::s0701_01);
			backdrops.push_back(&bn::regular_bg_items::s0701_02);
		}
		else if (strcmp(n[pos].text, "S07:02") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0702);
			backdrops.push_back(&bn::regular_bg_items::s0702_01);
			backdrops.push_back(&bn::regular_bg_items::s0702_02);
		}
		else if (strcmp(n[pos].text, "S07:03") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0703);
			backdrops.push_back(&bn::regular_bg_items::s0703_01);
			backdrops.push_back(&bn::regular_bg_items::s0703_01);
		}
		else if (strcmp(n[pos].text, "S07:04") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0704);
			backdrops.push_back(&bn::regular_bg_items::s0704_01);
			backdrops.push_back(&bn::regular_bg_items::s0704_02);
		}
		else if (strcmp(n[pos].text, "S07:05") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0705);
			backdrops.push_back(&bn::regular_bg_items::s0705_01);
			backdrops.push_back(&bn::regular_bg_items::s0705_02);
		}
		else if (strcmp(n[pos].text, "S07:06") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0706);
			backdrops.push_back(&bn::regular_bg_items::s0706_01);
			backdrops.push_back(&bn::regular_bg_items::s0706_02);
		}
		else if (strcmp(n[pos].text, "S07:07") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0707);
			backdrops.push_back(&bn::regular_bg_items::s0707_01);
			backdrops.push_back(&bn::regular_bg_items::s0707_02);
		}
		else if (strcmp(n[pos].text, "S07:08") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0708);
			backdrops.push_back(&bn::regular_bg_items::s0708_01);
			backdrops.push_back(&bn::regular_bg_items::s0708_02);
		}
		else if (strcmp(n[pos].text, "S07:09") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0709);
			backdrops.push_back(&bn::regular_bg_items::s0709_01);
			backdrops.push_back(&bn::regular_bg_items::s0709_02);
		}
		else if (strcmp(n[pos].text, "S07:10") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0710);
			backdrops.push_back(&bn::regular_bg_items::s0710_01);
			backdrops.push_back(&bn::regular_bg_items::s0710_02);
		}
		else if (strcmp(n[pos].text, "S07:11") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0711);
			backdrops.push_back(&bn::regular_bg_items::s0711_01);
			backdrops.push_back(&bn::regular_bg_items::s0711_02);
		}
		else if (strcmp(n[pos].text, "S07:12") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0712);
			backdrops.push_back(&bn::regular_bg_items::s0712_01);
			backdrops.push_back(&bn::regular_bg_items::s0712_02);
		}
		else if (strcmp(n[pos].text, "S07:13") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0713);
			backdrops.push_back(&bn::regular_bg_items::s0713_01);
			backdrops.push_back(&bn::regular_bg_items::s0713_02);
		}
		else if (strcmp(n[pos].text, "S07:14") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0714);
			backdrops.push_back(&bn::regular_bg_items::s0714_01);
			backdrops.push_back(&bn::regular_bg_items::s0714_02);
		}
		else if (strcmp(n[pos].text, "S07:15") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0715);
			backdrops.push_back(&bn::regular_bg_items::s0715_01);
			backdrops.push_back(&bn::regular_bg_items::s0715_02);
		}
		else if (strcmp(n[pos].text, "S07:16") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0716);
			backdrops.push_back(&bn::regular_bg_items::s0716_01);
			backdrops.push_back(&bn::regular_bg_items::s0716_02);
		}
		else if (strcmp(n[pos].text, "S07:17") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0717_01);
			backdrops.push_back(&bn::regular_bg_items::s0717_02);
		}
		else if (strcmp(n[pos].text, "S07:18") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0718);
			backdrops.push_back(&bn::regular_bg_items::s0718_01);
			backdrops.push_back(&bn::regular_bg_items::s0718_01);
		}
		else if (strcmp(n[pos].text, "S08:01") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0801);
			backdrops.push_back(&bn::regular_bg_items::s0801_01);
			backdrops.push_back(&bn::regular_bg_items::s0801_02);
		}
		else if (strcmp(n[pos].text, "S08:02") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0802);
			backdrops.push_back(&bn::regular_bg_items::s0802_01);
			backdrops.push_back(&bn::regular_bg_items::s0802_02);
		}
		else if (strcmp(n[pos].text, "S08:03") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0803);
			backdrops.push_back(&bn::regular_bg_items::s0803_01);
			backdrops.push_back(&bn::regular_bg_items::s0803_02);
		}
		else if (strcmp(n[pos].text, "S08:04") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0804);
			backdrops.push_back(&bn::regular_bg_items::s0804_01);
			backdrops.push_back(&bn::regular_bg_items::s0804_02);
		}
		else if (strcmp(n[pos].text, "S08:05") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0805);
			backdrops.push_back(&bn::regular_bg_items::s0805_01);
			backdrops.push_back(&bn::regular_bg_items::s0805_01);
		}
		else if (strcmp(n[pos].text, "S08:06") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0806);
			backdrops.push_back(&bn::regular_bg_items::s0806_01);
			backdrops.push_back(&bn::regular_bg_items::s0806_02);
		}
		else if (strcmp(n[pos].text, "S08:07") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0807);
			backdrops.push_back(&bn::regular_bg_items::s0807_01);
			backdrops.push_back(&bn::regular_bg_items::s0807_02);
		}
		else if (strcmp(n[pos].text, "S09:01") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0901);
			backdrops.push_back(&bn::regular_bg_items::s0901_01);
			backdrops.push_back(&bn::regular_bg_items::s0901_02);
		}
		else if (strcmp(n[pos].text, "S09:02") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0902);
			backdrops.push_back(&bn::regular_bg_items::s0902_01);
			backdrops.push_back(&bn::regular_bg_items::s0902_02);
		}
		else if (strcmp(n[pos].text, "S09:03") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0903);
			backdrops.push_back(&bn::regular_bg_items::s0903_01);
			backdrops.push_back(&bn::regular_bg_items::s0903_02);
		}
		else if (strcmp(n[pos].text, "S09:04") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0904);
			backdrops.push_back(&bn::regular_bg_items::s0904_01);
			backdrops.push_back(&bn::regular_bg_items::s0904_02);
		}
		else if (strcmp(n[pos].text, "S09:05") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0905);
			backdrops.push_back(&bn::regular_bg_items::s0905_01);
			backdrops.push_back(&bn::regular_bg_items::s0905_02);
		}
		else if (strcmp(n[pos].text, "S09:06") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0906);
			backdrops.push_back(&bn::regular_bg_items::s0906_01);
			backdrops.push_back(&bn::regular_bg_items::s0906_02);
		}
		else if (strcmp(n[pos].text, "S09:08") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0908);
			backdrops.push_back(&bn::regular_bg_items::s0908_01);
			backdrops.push_back(&bn::regular_bg_items::s0908_02);
		}
		else if (strcmp(n[pos].text, "S09:09") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0909);
			backdrops.push_back(&bn::regular_bg_items::s0909_01);
			backdrops.push_back(&bn::regular_bg_items::s0909_02);
		}
		else if (strcmp(n[pos].text, "S09:10") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0910);
			backdrops.push_back(&bn::regular_bg_items::s0910_01);
			backdrops.push_back(&bn::regular_bg_items::s0910_02);
		}
		else if (strcmp(n[pos].text, "S09:11") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0911);
			backdrops.push_back(&bn::regular_bg_items::s0911_01);
			backdrops.push_back(&bn::regular_bg_items::s0911_02);
		}
		else if (strcmp(n[pos].text, "S09:12") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0912);
			backdrops.push_back(&bn::regular_bg_items::s0912_01);
			backdrops.push_back(&bn::regular_bg_items::s0912_02);
		}
		else if (strcmp(n[pos].text, "S09:13") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0913);
			backdrops.push_back(&bn::regular_bg_items::s0913_01);
			backdrops.push_back(&bn::regular_bg_items::s0913_02);
		}
		else if (strcmp(n[pos].text, "S09:14") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0914);
			backdrops.push_back(&bn::regular_bg_items::s0914_01);
			backdrops.push_back(&bn::regular_bg_items::s0914_02);
		}
		else if (strcmp(n[pos].text, "S09:15") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0915);
			backdrops.push_back(&bn::regular_bg_items::s0915_01);
			backdrops.push_back(&bn::regular_bg_items::s0915_02);
		}
		else if (strcmp(n[pos].text, "S09:16") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0916);
			backdrops.push_back(&bn::regular_bg_items::s0916_01);
			backdrops.push_back(&bn::regular_bg_items::s0916_02);
		}
		else if (strcmp(n[pos].text, "S09:17") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0917);
			backdrops.push_back(&bn::regular_bg_items::s0917_01);
			backdrops.push_back(&bn::regular_bg_items::s0917_02);
		}
		else if (strcmp(n[pos].text, "S09:18") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0918);
			backdrops.push_back(&bn::regular_bg_items::s0918_01);
			backdrops.push_back(&bn::regular_bg_items::s0918_02);
		}
		else if (strcmp(n[pos].text, "S10:01") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1001);
			backdrops.push_back(&bn::regular_bg_items::s1001_01);
			backdrops.push_back(&bn::regular_bg_items::s1001_02);
		}
		else if (strcmp(n[pos].text, "S10:02") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1002);
			backdrops.push_back(&bn::regular_bg_items::s1002_01);
			backdrops.push_back(&bn::regular_bg_items::s1002_02);
		}
		else if (strcmp(n[pos].text, "S10:03") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1003);
			backdrops.push_back(&bn::regular_bg_items::s1003_01);
			backdrops.push_back(&bn::regular_bg_items::s1003_02);
		}
		else if (strcmp(n[pos].text, "S10:04") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1004);
			backdrops.push_back(&bn::regular_bg_items::s1004_01);
			backdrops.push_back(&bn::regular_bg_items::s1004_02);
		}
		else if (strcmp(n[pos].text, "S10:05") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1005);
			backdrops.push_back(&bn::regular_bg_items::s1005_01);
			backdrops.push_back(&bn::regular_bg_items::s1005_02);
		}
		else if (strcmp(n[pos].text, "S10:06") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1006);
			backdrops.push_back(&bn::regular_bg_items::s1006_01);
			backdrops.push_back(&bn::regular_bg_items::s1006_02);
		}
		else if (strcmp(n[pos].text, "S10:07") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1007);
			backdrops.push_back(&bn::regular_bg_items::s1007_01);
			backdrops.push_back(&bn::regular_bg_items::s1007_02);
		}
		else if (strcmp(n[pos].text, "S10:08") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1008);
			backdrops.push_back(&bn::regular_bg_items::s1008_01);
			backdrops.push_back(&bn::regular_bg_items::s1008_02);
		}
		else if (strcmp(n[pos].text, "S10:09") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1009);
			backdrops.push_back(&bn::regular_bg_items::s1009_01);
			backdrops.push_back(&bn::regular_bg_items::s1009_02);
		}
		else if (strcmp(n[pos].text, "S10:10") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1010);
			backdrops.push_back(&bn::regular_bg_items::s1010_01);
			backdrops.push_back(&bn::regular_bg_items::s1010_02);
		}
		else if (strcmp(n[pos].text, "S10:11") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1011);
			backdrops.push_back(&bn::regular_bg_items::s1011_01);
			backdrops.push_back(&bn::regular_bg_items::s1011_02);
		}
		else if (strcmp(n[pos].text, "S10:12") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1012);
			backdrops.push_back(&bn::regular_bg_items::s1012_01);
			backdrops.push_back(&bn::regular_bg_items::s1012_02);
		}

		else if (strcmp(n[pos].text, "S11:01") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1101);
			backdrops.push_back(&bn::regular_bg_items::s1101_01);
			backdrops.push_back(&bn::regular_bg_items::s1101_02);
		}
		else if (strcmp(n[pos].text, "S11:02") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1102);
			backdrops.push_back(&bn::regular_bg_items::s1102_01);
			backdrops.push_back(&bn::regular_bg_items::s1102_02);
		}
		else if (strcmp(n[pos].text, "S11:03") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1103);
			backdrops.push_back(&bn::regular_bg_items::s1103_01);
			backdrops.push_back(&bn::regular_bg_items::s1103_02);
		}

		else if (strcmp(n[pos].text, "S_STV_01") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::scout_tv_01);
			backdrops.push_back(&bn::regular_bg_items::scout_tv_01_01);
		}
		else if (strcmp(n[pos].text, "S_STV_02") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::scout_tv_02);
			backdrops.push_back(&bn::regular_bg_items::scout_tv_02_01);
		}
		else if (strcmp(n[pos].text, "S_STV_03") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::scout_tv_03);
			backdrops.push_back(&bn::regular_bg_items::scout_tv_03_01);
		}
		else if (strcmp(n[pos].text, "S_STV_04") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::scout_tv_04);
			backdrops.push_back(&bn::regular_bg_items::scout_tv_04_01);
		}
		else if (strcmp(n[pos].text, "S_DOCKS") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::bg_docks);

			// End dialogue
		}
		else if (strcmp(n[pos].text, "BG:CINEMINT") == 0) {
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::cinemint_01);
			backdrops.push_back(&bn::regular_bg_items::cinemint_02);
			backdrops.push_back(&bn::regular_bg_items::cinemint_03);
			backdrops.push_back(&bn::regular_bg_items::cinemint_04);
			backdrops.push_back(&bn::regular_bg_items::cinemint_03);

			// End dialogue
		}
		else if (strcmp(n[pos].text, "COM: Endscene") == 0 || bn::keypad::b_held()) {
			cont = false;

			// Handle sprite/dialogue
		}
		else {

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
				}
				else {
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
			bn::vector<bn::sprite_ptr, 32> text_sprite0;
			bn::vector<bn::sprite_ptr, 32> text_sprite2;
			bn::vector<bn::sprite_ptr, 32> text_sprite3;
			bn::vector<bn::sprite_ptr, 32> text_sprite4;
			bn::vector<bn::sprite_ptr, 32> text_sprite5;
			char line1[42] = { 0 };
			char line3[42] = { 0 };
			char line4[42] = { 0 };
			char line5[42] = { 0 };
			char line6[42] = { 0 };

			for (short int t = 0; t < 33; t++) { line1[t] = n[pos].text[t]; };
			for (short int t = 0; t < 33; t++) { line3[t] = n[pos].text[t + 33]; };
			for (short int t = 0; t < 33; t++) { line4[t] = n[pos].text[t + 66]; };
			for (short int t = 0; t < 33; t++) { line5[t] = n[pos].text[t + 99]; };
			for (short int t = 0; t < 32; t++) { line6[t] = n[pos].text[t + 132]; };

			text_line.generate(-108, 21, line1, text_sprite0);
			for (short int t = 0; t < text_sprite0.size(); t++) { text_sprite0.at(t).set_visible(false); }
			bn::core::update();

			text_line.generate(-108, 33, line3, text_sprite2);
			for (short int t = 0; t < text_sprite2.size(); t++) { text_sprite2.at(t).set_visible(false); }
			//bn::core::update();

			text_line.generate(-108, 45, line4, text_sprite3);
			for (short int t = 0; t < text_sprite3.size(); t++) { text_sprite3.at(t).set_visible(false); }
			bn::core::update();

			text_line.generate(-108, 57, line5, text_sprite4);
			for (short int t = 0; t < text_sprite4.size(); t++) { text_sprite4.at(t).set_visible(false); }
			//bn::core::update();

			text_line.generate(-108, 69, line6, text_sprite5);
			for (short int t = 0; t < text_sprite5.size(); t++) { text_sprite5.at(t).set_visible(false); }
			bn::core::update();

			// Process visual effects
			short int ticker = 0;
			short int ticker_delay = 0;

			cascade_id = 0;
			short int cascade_offset = 0;
			short int c_x = cascade_bg.value().x().integer();
			short int c_y = cascade_bg.value().y().integer();
			while (!bn::keypad::a_pressed() && !bn::keypad::b_held()) {

				a_button.set_y(lerp(a_button.y(), -50, 0.2));

				// Handle moving backgrounds
				if (backdrops.size() > 0) {
					cascade_bg.reset();
					cascade_bg = backdrops.at(cascade_id)->create_bg(c_x, c_y);
					if (backdrops.size() > 1) {
						cascade_offset++;
						if (cascade_offset > 8) {
							cascade_offset = 0;
							cascade_id++;
							if (cascade_id > backdrops.size() - 1) cascade_id = 0;
						}
					}
				}

				// Handle text ticker
				if (ticker < 160) {
					if (ticker_delay == 0) {
						short int ticked = ticker % 32;
						if (ticker >= 0 && ticker < 32) {
							if (text_sprite0.size() > ticked) {
								text_sprite0.at(ticked).set_visible(true);
								bn::sound_items::click.play();
							}
							else {
								ticker = 31;
							}
						}
						if (ticker >= 32 && ticker < 64) {
							if (text_sprite2.size() > ticked) {
								text_sprite2.at(ticked).set_visible(true);
								bn::sound_items::click.play();
							}
							else {
								ticker = 63;
							}
						}
						if (ticker >= 64 && ticker < 96) {
							if (text_sprite3.size() > ticked) {
								text_sprite3.at(ticked).set_visible(true);
								bn::sound_items::click.play();
							}
							else {
								ticker = 95;
							}
						}
						if (ticker >= 96 && ticker < 128) {
							if (text_sprite4.size() > ticked) {
								text_sprite4.at(ticked).set_visible(true);
								bn::sound_items::click.play();
							}
							else {
								ticker = 127;
							}
						}
						if (ticker >= 128 && ticker < 160) {
							if (text_sprite5.size() > ticked) {
								text_sprite5.at(ticked).set_visible(true);
								bn::sound_items::click.play();
							}
							else {
								ticker = 160;
							}
						}
						ticker++;
					}
					ticker_delay = (ticker_delay + 1) % 2;
				}

				// Move in from side
				if (chari_l.visible() && chari_l.x().integer() < -40) chari_l.set_x(chari_l.x() + 1);
				if (chari_r.visible() && chari_r.x().integer() > 40) chari_r.set_x(chari_r.x() - 1);

				// Handle transparency
				if (bn::blending::transparency_alpha().to_double() + 0.1 <= 0.9) {
					bn::blending::set_transparency_alpha(bn::blending::transparency_alpha().to_double() + 0.1);
				}
				else {
					bn::blending::set_transparency_alpha(0.95);
					chari_l.set_blending_enabled(false);
					chari_r.set_blending_enabled(false);
				}

				bn::core::update();
			}

			// Handle weirdness
			ticker = 160;

			for (short int t = 1; t < 3; t++) {
				bn::core::update();
			}

		}

		// Increment location
		pos++;
	}

	// Process visual effects
	while (bg_alpha > 0.1) {
		bg_alpha -= 0.1;
		if (bg_alpha < 0) bg_alpha = 0;
		bn::blending::set_transparency_alpha(bg_alpha);
		bn::core::update();
	}

	dg_bg1.set_visible(false);
	dg_bg2.set_visible(false);
	bn::blending::set_transparency_alpha(1);

	bn::core::update();
}

void dialogue_page_lite(line n[32]) {

	// Variable initialization
	bn::sprite_text_generator text_line(common::variable_8x16_sprite_font);
	bn::sprite_ptr a_button = bn::sprite_items::a_button.create_sprite(-90, -72, 1);
	auto dg_bg1 = bn::sprite_items::dialogue_bg_2.create_sprite(-64, 64);
	auto dg_bg2 = bn::sprite_items::dialogue_bg_2.create_sprite(64, 64);
	dg_bg1.set_scale(2, 1);
	dg_bg2.set_scale(2, 1);
	dg_bg1.set_blending_enabled(true);
	dg_bg2.set_blending_enabled(true);
	bn::fixed_t<12> bg_alpha = 0.0;
	bn::blending::set_intensity_alpha(0);

	// While dialogue is going,
	short int pos = 0;
	bool cont = true;
	bool a_dir = false;

	short int enoki_spoken = false;
	short int maple_spoken = false;
	short int aaron_spoken = false;
	short int scout_spoken = false;
	short int vee_spoken = false;
	short int el_spoken = false;
	short int diana_spoken = false;
	short int guy_spoken = false;

	while (cont) {

		// End dialogue
		if (strcmp(n[pos].text, "COM: Endscene") == 0) {
			cont = false;

			// Handle sprite/dialogue
		}
		else {

			// SFX
			bn::sound_items::pop.play((std_rnd(100)) / 100);

			// Fresh init
			bn::vector<bn::sprite_ptr, 33> text_sprite0;
			bn::vector<bn::sprite_ptr, 33> text_sprite1;
			bn::vector<bn::sprite_ptr, 33> text_sprite2;
			char line0[34] = { 0 };
			char line1[34] = { 0 };
			char line2[34] = { 0 };

			// Set up arrow
			auto arrow = bn::sprite_items::arrow.create_sprite(-108, 69);
			if (n[pos].move_to == 0) {
				arrow.set_visible(false);
			}

			strncpy(line0, n[pos].text + 0, 33);
			strncpy(line1, n[pos].text + 33, 33);
			strncpy(line2, n[pos].text + 66, 33);
			text_line.generate(-108, 45, line0, text_sprite0);
			text_line.generate(-108, 57, line1, text_sprite1);

			if (n[pos].move_to == 0) {
				text_line.generate(-108, 69, line2, text_sprite2);
			}
			else {
				text_line.generate(-92, 69, line2, text_sprite2);
			}

			if (!enoki_spoken && strncmp(line0, "ENOKI", 5) == 0) {
				bn::sound_items::enoki_hey.play();
				enoki_spoken = true;
			}

			if (!maple_spoken && strncmp(line0, "MAPLE", 5) == 0) {
				bn::sound_items::maple_hey_01.play();
				maple_spoken = true;
			}

			if (!aaron_spoken && strncmp(line0, "AARON", 5) == 0) {
				if (pos < 2) {
					bn::sound_items::aaron_hey_01.play();
				}
				else {
					bn::sound_items::aaron_hey_02.play();
				}
				aaron_spoken = true;
			}

			if (!scout_spoken && strncmp(line0, "SCOUT", 5) == 0) {
				bn::sound_items::scout_hey_01.play();
				scout_spoken = true;
			}

			if (!vee_spoken && strncmp(line0, "OLIVIER", 7) == 0) {
				bn::sound_items::vee_hey_01.play();
				vee_spoken = true;
			}

			if (!el_spoken && strncmp(line0, "ELEANOR", 7) == 0) {
				bn::sound_items::eleanor_hey_01.play();
				el_spoken = true;
			}

			if (!diana_spoken && strncmp(line0, "DIANA", 5) == 0) {
				bn::sound_items::diana_hey_01.play();
				diana_spoken = true;
			}

			if (!guy_spoken && strncmp(line0, "GUY", 3) == 0) {
				bn::sound_items::guy_hey_01.play();
				guy_spoken = true;
			}

			// Process visual effects
			while (!(bn::keypad::a_pressed())) {
				a_button.set_y(lerp(a_button.y(), -50, 0.2));

				// Handle arrow
				if (arrow.visible()) {
					if (bn::keypad::left_pressed()) {
						a_dir = false;
						bn::sound_items::cnaut.play();
					}

					if (bn::keypad::right_pressed()) {
						a_dir = true;
						bn::sound_items::cnaut.play();
					}

					if (!a_dir) {
						arrow.set_x(lerp(arrow.x(), -108, 0.4));
						arrow.set_horizontal_flip(false);
					}
					else {
						arrow.set_x(lerp(arrow.x(), 108, 0.4));
						arrow.set_horizontal_flip(true);
					}
				}

				if (bg_alpha < 0.9) {
					bg_alpha += 0.05;
					bn::blending::set_transparency_alpha(bg_alpha);
				}
				else {
					bg_alpha = 1;
				}

				bn::core::update();

				if (bn::keypad::b_held()) {
					for (short int t = 0; t < 2; t++) {
						bn::core::update();
					}
					break;
				}
			}

			if (n[pos].move_to > 0 && a_dir) {
				pos = n[pos].move_to;
			}

			bn::core::update();
		}

		// Increment location
		pos++;
	}

	// Process visual effects
	while (bg_alpha > 0.1) {
		bg_alpha -= 0.1;
		if (bg_alpha < 0) bg_alpha = 0;
		bn::blending::set_transparency_alpha(bg_alpha);
		bn::core::update();
	}

	a_button.set_scale(1.2, 1.2);
	bn::sound_items::click.play();
	bn::core::update();

	dg_bg1.set_visible(false);
	dg_bg2.set_visible(false);
	bn::blending::set_transparency_alpha(1);
}

int exec_dialogue(int x, int checkpoint = 0) {

	constexpr int n = -1;

	switch (x)
	{
	case 0:
	{
		line lc[32] = {
			{fals, true, 0, "BG: 1"},
			{fals, true, 0, "S01:01"},
			{fals, true, 0, "04h15                            1er Janvier 2000 Province Nord deLouisiane, Republique des        Laurentides"},
			{fals, true, 0, "S01:02"},
			{fals, true, 0, "AHHHHH. J'ai conduit pendant des heures. Mon pied droit dort et   l'autre va dans le meme sens."},
			{fals, true, 0, "S01:03"},
			{fals, true, 0, "Et ce gombo... Il doit etre      congele maintenant. Je n'arrive  pas a croire qu'ils voulaient    que je leur apporte de la        nourriture."},
			{fals, true, 0, "S01:04"},
			{fals, true, 0, "Pour dire la verite... Si je ne  vois pas ce chateau dans quinze  minutes, je pourrais faire       demi-tour."},
			{fals, true, 0, "Le trajet etait agreable         cependant, je suppose."},
			{fals, true, 0, "Bon, j'abandonne. Il n'y a pas   moyen-"},
			{fals, true, 0, "S01:06"},
			{fals, true, 0, ".....Oh."},
			{fals, true, 0, "Je ne peux pas dire si je suis   soulage ou de'u."},
			{fals, true, 0, "BG: fadeout"},
			{fals, true, 0, "S01:07"},
			{fals, true, 0, "                                 *knock*                          *knock*                          *knock*"},
			{fals, true, 0, "S01:08"},
			{fals, true, 0, "Je me demande s'ils peuvent meme m'entendre... Cet endroit semble immense."},
			{fals, true, 0, "                                 '..... ey!'"},
			{fals, true, 0, "S01:09"},
			{fals, true, 0, "BG: 0"},
			{fals, true, 0, "                                 He, Maple!!                      C'mon in, allez!"},
			{fals, true, 0, "COM: Endscene"}};
		dialogue_page(lc);
		return 0;
		break;
	};

	case 1:
	{
		bn::sound_items::maple_alright_03.play();
		line lc[32] = {
			{true, true, 0, "BG: Ocean"},
			{true, fals, 1, "MAPLE                            D'accord, ou J'branche cette     mijoteuse? Y a-t-il des prises   icitte?"},
			{fals, fals, 1, "MAPLE                            J'suppose que j'suis en retard etque t'as deja mangee?"},
			{fals, true, 9, "ENOKI                            On a un evier exterieur, mais    c'est la seule place avec de     l'electricite. Et oui, on a mangedu poulet."},
			{fals, true, 8, "ENOKI                            Tu nous as vraiment manque!"},
			{fals, fals, 5, "MAPLE                            Eh bien, j'suis enfin arrivee. Ouest- Oh! Salut, Aaron."},
			{true, true, 10,"AARON                            Bonsoir! Ou plutot Bonjour, on   est deja demain. Non? Quoi qu'il en soit, nous sommes heureux de  te voir. Joyeux millenaire!"},
			{fals, fals, 3, "MAPLE                            Joyeux millenaire! Vous etes au  milieu de nulle part, vous le    savez, non?"},
			{true, true, 12, "DEL                              Maple! Tu es la! Joyeux 2000!"},
			{fals, fals, 5, "MAPLE                            Delphine Thibodeaux! Salut! Mon  Dieu, ca fait combien de temps   deja? Un an?"},
			{fals, true, 13, "DEL                              He fille! Quelle joie de te voir.On t'a attendue pour ouvrir le   vin et sortir les eclairs."},
			{fals, true, 12, "DEL                              Bien qu'on n'est tous des adultesennuyeux maintenant. Donc j'peux pas te promettre qu'on va veillertard."},
			{true, true, 7, "ENOKI                            He Maple, comment ca va?  On     s'est pas vraiment parlees depuisle mariage?! Ma meilleure amie   m'a manquee!"},
			{fals, fals, 2, "MAPLE                            Ton mari a du t'occuper,         j'suppose."},
			{true, true, 10, "AARON                            Well, comme tu vois, nous vivons dans un chateau desormais, et    c'etait toute une aventure."},
			{true, true, 7, "ENOKI                            Je suis une princesse."},
			{fals, fals, 2, "MAPLE                            Il te faudrait plus qu'un chateaupour etre une princesse."},
			{fals, true, 8, "ENOKI                            Alors je suis une duchesse?"},
			{fals, fals, 4, "MAPLE                            Je- euh... Hmm... You know what? Il est trop tard pour ca."},
			{fals, fals, 2, "MAPLE                            Ca va bien pour moi, j'ai besoin d'un dernier semestre pour etre  enseignante. Apres? J'sais pas."},
			{true, true, 10, "AARON                            Tu es encore sur ca, tu veux etreprof, hein? Meme si tu as        toujours dit que tu serais tout  sauf une prof?"},
			{fals, true, 11, "AARON                            Y'a pas des diplomes pour les    gens qui crache du feu avec leursmains?"},
			{fals, fals, 4, "MAPLE                            Pas un qui m'interesse, du moins."},
			{fals, true, 10, "AARON                            Well, une prof avec de la magie  de feu me semble cool."},
			{true, true, 8, "ENOKI                            *Aaawn* my goodness, je m'endors.Et si on allait se coucher et    finir de parler demain?"},
			{fals, true, 7, "ENOKI                            Hey Maple, on fais tu une soiree pyjama? On pourrait faire comme  si on etait encore colocs        d'universite?"},
			{fals, fals, 2, "MAPLE                            Euh... Ok, je suppose."},
			{fals, true, n, "ENOKI                            Bonne nuit Del! Eh Aaron, Je te  vois demain matin? Ben tot?"},
			{fals, true, 0, "AARON                            Bien sur, Noc-Noc. *Bisou*"},
			{fals, fals, 3, "MAPLE                            Je m'y habituerai jamais."},
			{true, true, 9, "ENOKI                            Tres bien, attrape ta valise et  je te montre ou on dort.         Allons-y!"},
			{true, true, 0, "COM: Endscene"}};
		dialogue_page(lc);
		return 0;
		break;
	};

	case 2:
	{
		line lc[32] = {
			{true, true, 0, "BG: fadeout"},
			{true, true, 0, "S01:11"},
			{fals, true, 0, "MAPLE                            Wow... Il fait froid ici, non?"},
			{fals, true, 0, "ENOKI                            He silly, qui porte un debardeur et un short en plein decembre? Tupeux juste allumer un feu."},
			{true, true, 0, "BG: 2"},
			{true, true, 0, "S01:10"},
			{fals, true, 0, "MAPLE                            Alors, pendant combien de temps  vous restez ici? Tu peux pas etrea 50 km de la civilisation sans  electricite pour toujours."},
			{true, true, 0, "S01:11"},
			{fals, true, 0, "ENOKI                            On est heureux ici, donc j'pense qu'on va rester ici longtemps."},
			{fals, true, 0, "MAPLE                            Et Aaron y pense quoi? L'Aaron   que je connaissais aurait ete un peu plus... responsable."},
			{fals, true, 0, "ENOKI                            Je veux pas paraitre mechante    mais... Vous n'avez pas grandi   dans un char vous deux?"},
			{fals, true, 0, "MAPLE                            Enoki, On sait tous que t'es     riche, t'a pas besoin de te      vanter."},
			{fals, true, 0, "ENOKI                            Mais t'as vraiment grandie dans  un char? Comparez a ca, un       chateau, c'est mieux, non?"},
			{fals, true, 0, "MAPLE                            C'est juste... C'est fou. Je me  moque pas de toi ou quoi que ce"},
			{fals, true, 0, "MAPLE                            soit du genre, mais j'pense reell-ement que c'est une tresmauvaise idee."},
			{fals, true, 0, "ENOKI                            Et ca vient de la fille qui avaithonte de ses notes en premiere   annee et a decidee d'abandonner  l'universite..."},
			{true, true, 0, "S01:10"},
			{fals, true, 0, "MAPLE                            Come on, c'etait ton idee en     plus."},
			{true, true, 0, "S01:11"},
			{fals, true, 0, "ENOKI                            He, j'assume!! '97... Ouais,     c'etait vraiment l'une des       meilleures annees de ma vie."},
			{fals, true, 0, "ENOKI                            Donc, apres l'ecole, tu as un    plan pour ou vivre?"},
			{fals, true, 0, "MAPLE                            J'vais trouver quelque chose."},
			{fals, true, 0, "ENOKI                            Aaron et moi discutions et, tu   sais, il y a une ecole pas trop  loin ou tu pourrais enseigner, tupourrais... vivre avec n..."},
			{fals, true, 0, "MAPLE                            Oh que NON. J'vais me trouver un vrai appartement d'adulte. Quand tu seras tanner d'icitte, tu   pourras peut-etre vivre avec moi."},
			{true, true, 0, "S01:12"},
			{fals, true, 0, "ENOKI                            Ton sens de l'humour Maple, Il   arretera jamais de m'etonner."},
			{true, true, 0, "S01:11"},
			{fals, true, 0, "ENOKI                            Hey- Je suis triste et c'est     stupide! Tu veux faire une       aventure Maple et Enoki comme au bon vieux temps?!"},
			{fals, true, 0, "ENOKI                            Explorons le chateau!!"},
			{fals, true, 0, "MAPLE                            Attends, tu as achetee ce chateauet tu ne l'as pas toute visitee?"},
			{fals, true, 0, "ENOKI                            Duh, je prends mon temps avec ca - c'est un chateau! Allons-y!"},
			{true, true, 0, "COM: Endscene"}};
		dialogue_page(lc);
		return 0;
		break;
	};

	case 3:
	{
		line lc[32] = {
			{fals, fals, 0, "BG: Moody"},
			{true, true, 30, "ENOKI                            Je veux visiter la bibliotheque  en premier!"},
			{true, fals, 02, "MAPLE                            Bien sur, en avant."},
			{fals, true, 31, "ENOKI                            Tu vas comprendre pourquoi quand on y seras!"},
			{fals, true, 30, "ENOKI                            Si veux que j'mene, appuis sur   'B'."},
			{fals, fals, 03, "MAPLE                            ...Uh?"},
			{fals, true, 30, "ENOKI                            Quoi?"},
			{fals, fals, 0, "COM: Endscene"}};
		bn::sound_item hm = bn::sound_items::heymaple;
		hm.play();
		dialogue_page(lc);
		return 0;
		break;
	}

	case 13:
	{
		line lc[32] = {
			{true, true, 0, "S01:13"},
			{true, true, 10, "AARON                            Bonjour! As tu bien dormi?"},
			{fals, fals, 4, "MAPLE                            Oui, je crois."},
			{true, true, 9, "ENOKI                            Bonjour! On as trouve quelque    chose de cool pendant quetu dor- mais, mais tu dois me promettre  que tu ne vas pas te facher!"},
			{true, true, 4, "MAPLE                            Tu sais que je peux pas te le    promettre."},
			{fals, fals, 7, "ENOKI                            Tu te souviens du livre que tu   voulais que je prenne? Well,     c'est un Atlas et nous avons vu  quelque chose de fun!"},
			{fals, true, 9, "ENOKI                            Nous avons trouve une ile du lac Superieur appelee Tremblay       Island!"},
			{fals, true, 0, "MAPLE                            Aww, c'est marrant. Je pensais   que tu allais dire un jeu de motsou quelque chose comme ca."},
			{fals, fals, 0, "ENOKI                            Well, nous, euh- nous pensions   que ce serait amusant si, eh     bien, Del avait l'idee, d..."},
			{fals, true, 12, "DEL                              La derniere fois que j'ai vus moncousin Rufus, il etait obsede parla creation d'un petit pays."},
			{true, true, 11, "AARON                            Il y a du travail proche, donc cadevrait pas etre difficile       d'obtenir les fournitures qu'on abesoin."},
			{true, true, 7, "ENOKI                            Avec l'argent que nous recevrons en vendant le chateau et grace a ta magie, on pensait que-"},
			{true, true, 3, "MAPLE                            WHOA WHOA WHOA, ATTENDEZ UNE     MINUTE."},
			{fals, fals, 3, "MAPLE                            Etes-tu vraiment en train de direque vous allez VENDRE le chateau pour vivre sur cette ile-"},
			{fals, fals, 3, "MAPLE                            parce que nous avons le meme nom de famille que celle-ci?"},
			{fals, fals, 9, "ENOKI                            En plus, on voudrais  nous       detacher des Laurentides pour    fonder notre propre pays."},
			{fals, true, 0, "MAPLE                            ... je..."},
			{fals, fals, 0, "MAPLE                            ..."},
			{fals, fals, 4, "MAPLE                            ... Je pense que je vais avoir   besoin de temps pour assimiler   tout ca."},
			{fals, fals, 10, "AARON                            Ca peut sembler fou, mais nous   avons fait des recherches et ca  serais quelque chose de possible."},
			{true, true, 9, "ENOKI                            Je sais qu'on a eu une           conversation hier, mais..."},
			{true, true, 3, "MAPLE                            Et apres? Que vas-tu faire       lorsque tu... tu vas etre tanner d'avoir unev ile?"},
			{fals, fals, 0, "MAPLE                            Tu vas devenir Pape? Peut-etre lareine de France? Tu vas acheter  ta propre planete?"},
			{fals, fals, 0, "MAPLE                            Et tu as tellement de chance que tu vas l'avoir. Mais, but you    know what?"},
			{fals, fals, 0, "MAPLE                            Je vais garder les pieds sur     terre avec un *vrai* travail et  eviter de mourir de faim sur une roche."},
			{fals, true, 0, "MAPLE                            Ou pire encore, me faire enfermerpour avoir brise une loi stupide."},
			{fals, fals, 4, "MAPLE                            Bien ... J'ai aime mon sejour,   mais je vais allez chez moi. Je  suis tannee."},
			{fals, fals, 0, "MAPLE                            Aaron, Enoki, Delphine, je suis  contente de vous revoir, mais    j'ai besoin de prendre du temps."},
			{true, true, 10, "AARON                            Tu es sur? On peut parler d'autrechose. Tu peux aussi prendre le  petit dejeuner avec nous-autres  si tu veux."},
			{fals, fals, 0, "MAPLE                            ...Well, je vais rester un       moment, mais je dois partir      bientot."},
			{true, true, 0, "COM: Endscene"}};
		dialogue_page(lc);
		return 0;
		break;
	};

	case 14:
	{
		if (DEVICE_TYPE == 0)
		{
			line lc[32] = {
				{true, true, 0, "S02:02"},
				{true, true, 0, "BG: champ"},
				{fals, true, 0, "                                 Hmm, hmm, hmm...."},
				{fals, true, 0, "                                 Mon Dieu, ma pizza est vraiment  en retard, elle devait etre      icitte en moins de 20 minutes."},
				{fals, true, 0, "                                 J'ai tu checker la malle         aujourd'hui? Je devrais le faire en passant."},
				{true, true, 0, "S02:03"},
				{fals, true, 0, "                                 Hein, Ca viens? De la maison     Tremblay? J'ai pas eu de         nouvelles d'Aaron et d'Enoki     depuis un moment."},
				{fals, true, 0, "                                 J'ai hate de lire a quel point   ils veulent venir vivre avec moi."},
				{true, true, 0, "BG: fadeout"},
				{true, true, 0, "S02:04"},
				{fals, true, 0, "                                 He, Maple!"},
				{true, true, 0, "S02:05"},
				{fals, true, 0, "                                 Oh, elle est a l'envers."},
				{true, true, 0, "S02:04"},
				{true, true, 0, "BG: 0"},
				{fals, true, 0, "                                 'He, Maple!'"},
				{fals, true, 0, "                                 'Nous avons pense a t'envoyer unelettre pour te tenir informee'"},
				{fals, true, 0, "                                 'Nous avons vendu le chateau et  achete un trailer.'"},
				{fals, true, 0, "                                 'C'est pas tout, on l'a deja     installe sur notre nouvelle ile!'"},
				{true, true, 0, "S02:05"},
				{true, true, 0, "                                  ...  Ok. Je vais les tuer."},
				{true, true, 0, "S02:04"},
				{fals, true, 0, "                                 'Alors nous avons decide de      l'appeler-..'"},
				{true, true, 0, "COM: Endscene"}};
			dialogue_page(lc);
		}
		else
		{
			line lc[32] = {
				{true, true, 0, "S02:02"},
				{true, true, 0, "BG: champ"},
				{fals, true, 0, "                                 Hmm, hmm, hmm...."},
				{fals, true, 0, "                                 Mon Dieu, ma pizza est vraiment  en retard, elle devait etre      icitte en moins de 20 minutes."},
				{fals, true, 0, "                                 J'ai tu checker la malle         aujourd'hui? Je devrais le faire en passant."},
				{true, true, 0, "S02:03"},
				{fals, true, 0, "                                 Hein, ..]a viens? De la maison   Tremblay? J'ai pas eu de         nouvelles d'Aaron et d'Enoki     depuis un moment."},
				{fals, true, 0, "                                 J'ai hate de lire a quel point   ils veulent venir vivre avec moi."},
				{true, true, 0, "BG: fadeout"},
				{true, true, 0, "S02:04"},
				{fals, true, 0, "                                 He, Maple!"},
				{true, true, 0, "S02:05"},
				{fals, true, 0, "                                 Oh, elle est a l'envers."},
				{true, true, 0, "S02:04"},
				{true, true, 0, "BG: 0"},
				{fals, true, 0, "                                 'He, Maple!'"},
				{fals, true, 0, "                                 'Nous avons pense a t'envoyer unelettre pour te tenir informee'"},
				{fals, true, 0, "                                 'Nous avons vendu le chateau et  achete un trailer.'"},
				{fals, true, 0, "                                 'C'est pas tout, on l'a deja     installe sur notre nouvelle ile!'"},
				{true, true, 0, "S02:05"},
				{true, true, 0, "                                  ...  Ok. Je vais les tuer."},
				{true, true, 0, "S02:04"},
				{true, true, 0, "                                       'See you soon!                   AARON & ENOKI'"},
				{true, true, 0, "COM: Endscene"}};
			dialogue_page(lc);
		}
		return 0;
		break;
	};

	case 15:
	{
		line lc[32] = {
			{true, true, 0, "S02:06"},
			{fals, true, 0, "MAPLE                            Oh my gosh, j'en ai ASSEZ, ils   vont voir!"},
			{fals, true, 0, "MAPLE                            Je suis a ma limite, ils vont    MOURIR SEUL. Et ]a va etre leur  faute."},
			{fals, true, 0, "MAPLE                            Quand ils vont etre tannes de    leur ile, ils vont venir ici, et tu sais ce que je vais leur dire?"},
			{fals, true, 0, "PIZZA GUY                        Que vas-tu dire?"},
			{true, true, 0, "S02:07"},
			{fals, true, 0, "MAPLE                            Je vais dire NON!"},
			{fals, true, 0, "PIZZA GUY                        A mon avis, vivre sur une ile,   tout seul, semble parfait."},
			{fals, true, 0, "MAPLE                            Oui, c'est une vie de reve, mais ils vont la gacher, parce qu'ils sont tous completement           incompetents!"},
			{fals, true, 0, "PIZZA GUY                        Si j'etais toi, j'irais les      rejoindre et je leur montrerais  comment gerer l'ile."},
			{fals, true, 0, "MAPLE                            Je vais devoir y aller hein? Ils vont mourir la-bas."},
			{fals, true, 0, "MAPLE                            Mais je peux pas. Je dois etre   une meilleure personne et rester dans le vrai monde."},
			{true, true, 0, "S02:06"},
			{fals, true, 0, "PIZZA GUY                        Ouais, c'est plus important de   continuer a manger de la pizza etde pleurer pour t'endormir comme a chaque soir non?"},
			{true, true, 0, "S02:08"},
			{fals, true, 0, "MAPLE                            ..]a se voit?"},
			{fals, true, 0, "PIZZA GUY                        Oui, on prend tous notre tour    pour livrer la pizza a 'la fille seule deprimee'."},
			{fals, true, 0, "MAPLE                            Incroyable."},
			{true, true, 0, "S02:04"},
			{fals, true, 0, "MAPLE                            Eh bien, c'est vrai qu'apres     avoir commandee autant de pizza, j'ai plus de piastre pour mon    loyer."},
			{fals, true, 0, "PIZZA GUY                        Well... j'ai toujours mon        pourboire pour la session de     therapie?"},
			{true, true, 0, "BG: fadeout"},
			{true, true, 0, "COM: Endscene"}};
		dialogue_page(lc);
		return 0;
		break;
	};

	case 16:
	{
		// Spring
		line lc[32] = {
			{fals, true, 0, "S03:01"},
			{fals, true, 0, "BG: 1"},
			{fals, true, 0, "18h40                            20 mars 2000 Au milieu du Lac    Superieur, La Republique         Laurentides(?)"},
			{fals, true, 0, "                                 Alors... C'est l'ile... Elle a ducharme."},
			{fals, true, 0, "                                 Ont verras si elle a assez de    charme pour que je reste."},
			{fals, true, 0, "                                 J'suppose que l'idee d'vivre sur une ile sans avoir de dettes est interessante."},
			{fals, true, 0, "S03:02"},
			{fals, true, 0, "MAPLE                            Combien ca cout le trajet en     traversier? 10 dollars?"},
			{fals, true, 0, "LE VIEUX MARIN                   Oui fille, mais j'dois te dire   quelque chose avant que tu parte."},
			{fals, true, 0, "MAPLE                            Hold up, quesqu'il a?"},
			{fals, true, 0, "LE VIEUX MARIN                   'Fais attention la-bas, on sait  jamais qui peux te poignarder    dans l'dos."},
			{fals, true, 0, "MAPLE                            Vous pouvez couper un 20?"},
			{fals, true, 0, ":E VIEUX MARIN                   J'peux oui."},
			{fals, true, 0, "COM: Endscene"}};
		dialogue_page(lc);
		return 0;
		break;
	}

	case 18:
	{
		line lc[32] = {
			{fals, fals, 0, "BG: Trailer Home"},
			{true, true, 22, "ENOKI                            Maple, tu es venue!"},
			{true, fals, 17, "MAPLE                            Well oui, j'suppose c'etait ma   meilleure option."},
			{true, true, 24, "AARON                            Comment s'est passe le voyage? Caas tu pris longtemps?"},
			{fals, fals, 16, "MAPLE                            J'ai prit un train. Ca m'a pris  environ... Trois jours? C'etais  pas mal, j'ai beaucoup lis et    j'ai mal aux jambes."},
			{fals, true, 25, "AARON                            Si tu nous avais dit que tu      venais, nous aurions paye un     avion!"},
			{fals, fals, 18, "MAPLE                            Pas grave je suis la. Alors, tu  es passe d'un chateau a un       camper? La classe."},
			{true, true, 20, "ENOKI                            Dude, on as demenage d'un chateaua une maison 'normale' et        maintenant tu veux qu'on y       retourne ou quoi?"},
			{fals, fals, 16, "MAPLE                            Non, je dis juste que... en faiteje sais pas."},
			{true, true, 26, "AARON                            Well, on n'a qu'un sofa, mais il est super comfo, donc fais comme chez toi."},
			{fals, true, 24, "AARON                            Nous avons travaille a la sueur  de nos front. J'ai coupe beaucoupde bois de pour l'hiver, et      Enoki-"},
			{true, true, 22, "ENOKI                            Je croyais qu'emmener quelques   lapins allais rendre l'ile plus  vivante, y'know?"},
			{fals, true, 20, "ENOKI                            Eh bien, ils se sont multiplier  et je dois les tenirs hors du    jardin."},
			{true, true, 26, "AARON                            Que pense-tu de visiter les      grottes au nord?"},
			{fals, true, 24, "AARON                            J'ai entendu dire qu'elles       contiennent des gemmes qui seraisutile pour obtenir de l'argent."},
			{fals, fals, 14, "MAPLE                            Ca semble pas difficile."},
			{fals, fals, 15, "MAPLE                            Et... merci pour la chambre."},
			{fals, true, 25, "AARON                            De rien."},
			{fals, true, 22, "ENOKI                            Oh, et si t'a pas vus Scout,     c'est un gars cool! Il est       surement dans son bunker a       l'exterieur."},
			{fals, fals, 0, "COM: Endscene"}};
		dialogue_page(lc);
		return 0;
		break;
	}

	case 17:
	{
		line lc[32] = {
			{fals, fals, 0, "BG: Trailer Home"},
			{true, true, 22, "ENOKI                            Well... Premiere journee         terminee! ..]'etais amusant."},
			{true, fals, 17, "MAPLE                            Tu sais quoi? Je suis d'accord.  C'est la journee la plus         interessante que j'ai eue depuis longtemps."},
			{true, true, 24, "AARON                            Es tu prete a avoue que c'etais  pas une mauvaise idee?"},
			{fals, fals, 16, "MAPLE                            Je suis ici que depuis une       journee, j'ai besoin d'un moment avant mon jugement final."},
			{fals, true, 25, "AARON                            C'est dommage que nous n'ayons   qu'un sofa. Mais nous sommes     heureux que tu restes avec"},
			{fals, true, 25, "AARON                            nous-autres jusqu'a ce que la    maison soit finie"},
			{fals, fals, 18, "MAPLE                            Je dormais sur mon propre sofa   dans mon appartement, t'en fais  pas."},
			{true, true, 20, "ENOKI                            Aw, tu dormais sur ton sofa?"},
			{fals, fals, 16, "MAPLE                            Il etait comfo mon sofa."},
			{true, true, 26, "AARON                            Dans tous les cas, on devrait se reposer. J'ai coupe du bois toutela journee et je suis fatigue."},
			{fals, true, 24, "AARON                            a demain?"},
			{true, true, 22, "ENOKI                            Je suis sur que je vais trouver  plus de chose a faire!"},
			{fals, fals, 15, "MAPLE                            Merci beaucoup.. Je vais essayer de pas trop etre chiante tout le temps. Bonne nuit!"},
			{fals, true, 22, "ENOKI                            Bonne nuit!"},
			{fals, fals, 0, "COM: Endscene"}};
		dialogue_page(lc);
		return 0;
		break;
	}

	case 19:
	{
		line lc[32] = {
			{fals, fals, 0, "BG: fadeout"},
			{fals, fals, 0, "S04:01"},
			{fals, true, 0, "                                 Ugh... Ma tete... J'arrive pas a dormir."},
			{fals, true, 0, "                                 Je croyais qu'apres un trajet et une longue journee de dur labeur,on devait dormir facilement?"},
			{fals, true, 0, "                                 Et c'est quoi la lumiere a       l'exterieur? C'est peut-etre     Scout..."},
			{fals, true, 0, "                                 Je devrais surement sortir et    jeter un coup d'oeil."},
			{fals, fals, 0, "S04:02"},
			{fals, true, 0, "                                 quoi-? C'es tu un Mons de Plonj? ecris t'il quelque chose?"},
			{fals, true, 0, "                                 Je devrais aller voir avant que  quelque chose de grave n'arrive."},
			{fals, fals, 0, "S04:03"},
			{fals, true, 0, "                                 Hmm, hmm... hmm..."},
			{fals, fals, 0, "S04:04"},
			{fals, true, 0, "                                 He! IDENTIFIEZ-VOUS OU JE FAIS UNBARBECUE AVEC VOTRE VISAGE!"},
			{fals, fals, 0, "S04:05"},
			{fals, fals, 0, "SF: Rufus Squeak"},
			{fals, true, 0, "                                 AHHH?!"},
			{fals, true, 0, "                                 OH, HUH... HUH, RUFUS! RUFUS     THIBODEAUX!"},
			{fals, true, 0, "                                 J'AI BESOIN DE MON VISAGE, S'IL  VOUS PLAIT NE LE BRULE PAS!"},
			{fals, fals, 0, "COM: Endscene"}};
		dialogue_page(lc);
		return 0;
		break;
	}

	case 20:
	{
		line lc[32] = {
			{fals, fals, 0, "BG: frog"},
			{fals, fals, 0, "S04:06"},
			{fals, true, 0, "MAPLE                            Oh, alors vous etes le fameux    Rufus? Le cousin de Del? Je suis Maple."},
			{fals, true, 0, "RUFUS                            Oh, vous etes l'elfe du feu?     J'aurais aime le savoir avant    d'essayer d'allumer ce feu."},
			{fals, true, 0, "MAPLE                            Que faite-vous ici?"},
			{fals, true, 0, "RUFUS                            Je fais de la reconnaissance.    J'ai un oeil sur les iles Bill &  Jim a cote."},
			{fals, true, 0, "RUFUS                            J'aime l'idee d'avoir un endroit rien que pour moi, sans avoir    affaire a personne."},
			{fals, true, 0, "RUFUS                            Je suis juste preoccupe par la   temerite de mon 'ile privee'."},
			{fals, true, 0, "RUFUS                            En plus, tous ceux qui habitent  pres de Quebec parlent avec cet  accent enervant..."},
			{fals, true, 0, "MAPLE                            ..]a m'inquiete aussi. Enoki est super, mais parfois cet accent metape sur les nerfs."},
			{fals, true, 0, "MAPLE                            Je commence a entendre l'accent  quebecois se glisser dans la voixd'Aaron. Vraiment enervant."},
			{fals, true, 0, "MAPLE                            Donc, qu'est-ce que vous ecrivez?"},
			{fals, true, 0, "RUFUS                            ... Vous allez penser que c'est  idiot, mais je fais un dessin."},
			{fals, true, 0, "MAPLE                            Eh, apres avoir vendu toutes mes affaires pour venir sur cette    ile, je t'assure que votre dessinn'est pas idiot."},
			{fals, true, 0, "RUFUS                            ... Okay, c'est une grenouille.  J'ai vu une photo quand j'etais  petit et ]a me rend nostalgique  pour une raison quelconque."},
			{fals, true, 0, "RUFUS                            Je ne me souviens pas reellement de l'apparence, alors je continued'essayer. Je sais pas pourquoi,"},
			{fals, true, 0, "RUFUS                            mais je sens que je dois le      faire."},
			{fals, true, 0, "MAPLE                            Ouais, quand vous l'expliquez, ]aa l'air un peu idiot, mais je    comprends!"},
			{fals, true, 0, "MAPLE                            Au fait... Avez-vous un endroit  ou dormir? Je ne peux pas offrir grand-chose, mais il fait froid  dehors et nous avons un bain."},
			{fals, true, 0, "RUFUS                            J'apprecie, mais je pars demain  matin. Et j'ai assurement pas    envie de parler a qui que ce     soit, meme si vous semblez bien."},
			{fals, true, 0, "MAPLE                            Ce fut un plaisir de parler avec quelqu'un avec du sens."},
			{fals, fals, 0, "S04:07"},
			{fals, fals, 0, "BG: fadeout"},
			{fals, true, 0, "MAPLE                            Prends bien soin de toi,         d'accord? Ravi de vous           rencontrer, Rufus."},
			{fals, true, 0, "RUFUS                            Toi aussi! Ravi de vous          rencontrer, Maple."},
			{fals, fals, 0, "COM: Endscene"}};
		dialogue_page(lc);
		return 0;
		break;
	}

	case 21:
	{
		line lc[32] = {
			{fals, fals, 0, "BG: news"},
			{fals, fals, 0, "S_STV_01"},
			{fals, true, 0, "                                 Bonjour Scout est de retour!"},
			{fals, fals, 0, "S_STV_02"},
			{fals, true, 0, "                                 C'est excitant d'avoir enfin un  vrai public, mesdames et         messieurs. Euh... monsieur."},
			{fals, true, 0, "                                 Aujourd'hui, c'est le 1er avril, et vous savez ce que ]a veux     dire!"},
			{fals, true, 0, "                                 Maple a demenagee sur l'ile      depuis hier! Comme le temps      passe!"},
			{fals, true, 0, "                                 C'est une, euh, blague... Parce  qu'on est le 1er avril, et elle  est avec nous-autres depuis un   mois entier."},
			{fals, true, 0, "                                 Je-je vais passer a autre        chose... Bien! J'ai enfin pu     recuperer le mot de passe de mon PC...!"},
			{fals, true, 0, "                                 Oh, d'accord, d'accord, quelque  chose de plus important. Trois   nouvelles personnes s'installent sur l'ile!"},
			{fals, true, 0, "                                 Mais je suis pas sur qu'on va    trouver plus d'insulaires        potentiels sur Craigslist."},
			{fals, true, 0, "                                 Ils s'appellent Diana, Eleanor etOlivier. Et ils emmenagent dans  la nouvelle cabine au nord-ouest."},
			{fals, true, 0, "                                 Olivier a une serre dans le nord et Diana est une navigatrice     aspirante. Elle s'occupera de    conduire le navire."},
			{fals, true, 0, "                                 Alors accueillons-les            chaleureusement!"},
			{fals, fals, 0, "S_STV_01"},
			{fals, true, 0, "                                 D'accord, c'est tout... Je       suppose que je vais tous vous    voir plus tard. Merci beaucoup   d'etre la!"},
			{fals, fals, 0, "S05:01"},
			{fals, fals, 0, "BG: fadeout"},
			{fals, true, 0, "ENOKI                            Mmmmmm.... J'ai fait du pop-corn,mais j'ai pas envie d'aller le   chercher."},
			{fals, fals, 0, "SF: Hey Maple"},
			{fals, true, 0, "ENOKI                            Peux-tu aller le chercher, Maple?S'il te plait?"},
			{fals, true, 0, "MAPLE                            Ugh, prenez-vous une chambre vousdeux!"},
			{fals, true, 0, "AARON                            Mais, c'est notre maison."},
			{fals, true, 0, "MAPLE                            Alors?"},
			{fals, fals, 0, "COM: Endscene"}};
		dialogue_page(lc);
		return 0;
		break;
	}

	case 22:
	{
		if (checkpoint < 12)
		{
			line lc[32] = {
				{fals, true, 0, "1er avril 2000                   - Carnet d'exploration, no 48"},
				{fals, true, 0, "Scout TV a eu quelques           telespectateurs cette fois.      J'espere qu'ils ont aime."},
				{fals, true, 0, "La prochaine fois, j'aimerais en avoir assez pour creer l'Expo    Scout."},
				{fals, true, 0, "Les choses avancent lentement    mais j'ai du financements donc."},
				{fals, true, 0, "Je peux au moins travailler sur  des projets personnel"},
				{fals, true, 0, "La 'Magic Pocket' ne sera pas    pret avant un moment, mais le"},
				{fals, true, 0, "prototype est prometteur."},
				{fals, true, 0, "..]a pourrait etre utile pour la demande d'Aaron?"},
				{fals, true, 0, "Il voulait faire des courses de  voitures sur l'ile."},
				{fals, true, 0, "Je pourrais mettre une piste de  course entiere dans la dimension magique de la pocket."},
				{fals, true, 0, "De cette fa]on, on pouras laisserl'ile propre."},
				{fals, true, 0, "Bien sur, tout doit etre parfait Je veux pas qu'il reste prit..."},
				{fals, true, 0, "...eh, it'll be fine."},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page_lite(lc);
			return 0;
		}
		else
		{
			line lc[32] = {
				{fals, true, 0, "1 mai 2000                       - Carnet d'exploration, no 68"},
				{fals, true, 0, "Deux nouveaux villageois sont    arrives, l'un est un peu louche  mais Enoki lui fait confiance."},
				{fals, true, 0, "L'autre gars est un grand chef,  en plus son nom de famille est   Pizza."},
				{fals, true, 0, "Je connais pas son vrai prenom etla curiosite me tue."},
				{fals, true, 0, "Rufus a ete enervant et il a     interrompue Scout TV."},
				{fals, true, 0, "Il a un probleme d'ego ou quoi?"},
				{fals, true, 0, "Je suis un peu inquiet. Je       devrais peut-etre le garder sous surveillance."},
				{fals, true, 0, "Je veux dire, encore plus        qu'avant."},
				{fals, true, 0, "Il semble qu'une entreprise      veuille stocker beaucoup         d'gasoline sur l'ile."},
				{fals, true, 0, "J'ai decouvert ]a quand ils en onamenee par accident."},
				{fals, true, 0, "Il vas faire quoi avec toute     cette gasoline? Peut-etre que    l'avenir nous le dira."},
				{fals, true, 0, "J'espeere que le monde va bien cemois-ci. Je m'amuse beaucoup aveceux."},
				{fals, true, 0, "Scout out. Hehe, 'scout out'."},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page_lite(lc);
			return 0;
		}
		break;
	}

	case 23:
	{
		if (checkpoint < 12)
		{
			line lc[32] = {
				{fals, true, 0, "29 mars 2000                     - Carnet d'exploration, no 45    (supprime)"},
				{fals, true, 0, "Depuis mon depars des iles Bill &Jim, c'est l'une de mes meilleursjournees."},
				{fals, true, 0, "Ces iles ne me manquent          definitivement pas."},
				{fals, true, 0, "Rufus etais comme un coup de pieddans les couilles. Toujours en   train de chialer"},
				{fals, true, 0, "avec toutes ses idees de complot."},
				{fals, true, 0, "J'espere qu'il se porte bien toutseul."},
				{fals, true, 0, "Mais, cette fille Maple... Ouf.  Je crois qu'elle m'a souri pour  la premiere fois"},
				{fals, true, 0, "Depuis son arrivee sur l'ile."},
				{fals, true, 0, "..]a veut probablement rien dire,mais chaque fois que j'y pense,"},
				{fals, true, 0, "Je dors pas."},
				{fals, true, 0, "Elle ne m'a jamais parle autre   que quand elle se moque de moi..."},
				{fals, true, 0, "Mais peut-etre qu'elle joue la   difficile."},
				{fals, true, 0, "J'ai vu comment elle parle avec  Aaron et Enoki, elle semble      pareille avec tout le monde."},
				{fals, true, 0, "Hmm... Peut-etre qu'un jour, je  trouverai comment l'approcher."},
				{fals, true, 0, "Je ferai quelque chose pour      l'impressionner."},
				{fals, true, 0, "Elle n'aime pas grand-chose, maiselle semble aimer les livres et  manger."},
				{fals, true, 0, "C'est peut-etre pas les memes,   mais j'aime aussi les livres et  la nourriture."},
				{fals, true, 0, "Surement qu'elle aime les gars   muscles et je ressemble plus a   Grimace de McDonald's."},
				{fals, true, 0, "He, je pourrais inventer quelque chose pour me mettre en forme."},
				{fals, true, 0, "Apres tout, elle m'a souri. Meme si c'est parce que j'ai tombe"},
				{fals, true, 0, "sur quelque chose..."},
				{fals, true, 0, "Je vais supprimer cet            enregistrement. Je sais meme pas pourquoi je l'ai ecrit."},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page_lite(lc);
			return 0;
		}
		else
		{
			line lc[32] = {
				{fals, true, 0, "29 abril 2000                     - Carnet d'exploration, no 65   (supprime)"},
				{fals, true, 0, "Je ne peux pas rivaliser avec le nouveau."},
				{fals, true, 0, "Il semble deja connaitre Maple dequelque part."},
				{fals, true, 0, "Autant abandonner."},
				{fals, true, 0, "Well... Peut-etre que je pourraisapprendre a cuisiner."},
				{fals, true, 0, "Peut-etre que je pourrais essayerde me mettre en forme."},
				{fals, true, 0, "Je dois arreter d'ecrire toutes  les entrees de mon journal sur mavie amoureuse."},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page_lite(lc);
			return 0;
		}
		break;
	}

	case 24:
	{
		if (checkpoint < 12)
		{
			line lc[32] = {
				{fals, true, 0, "30 mars 2000                     - Carnet d'exploration, no 66   (supprime)"},
				{fals, fals, 0, "Les gens de l'entreprise ont    envoye un message crypte aujourd'hui. Ils sont plus interesses par"},
				{fals, fals, 0, "l'equipement de surveillance quepars les resultats. Peut-etre    veulent-ils voir Scout TV? Cela a"},
				{fals, fals, 0, "probablement a voir avec Rufus. On dirait qu'ils veulent         l'arreter, mais ils attendent"},
				{fals, fals, 0, "qu'il ait fini d'inventer en    premier. Cela ne m'etonnerait passi c'etait vrai. Je dois"},
				{fals, fals, 0, "supprimer ceci."},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page_lite(lc);
			return 0;
		}
		else
		{
			line lc[32] = {
				{fals, true, 0, "30 abril 2000                     - Carnet d'exploration, no 66   (supprime)"},
				{fals, fals, 0, "Je parie que la fille Enoki a    pris la fleur d'Apres."},
				{fals, fals, 0, "Cela expliquerait beaucoup de    choses sur elle."},
				{fals, fals, 0, "Ce n'est peut-etre pas une       mauvaise idee de surveiller."},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page_lite(lc);
			return 0;
		}
		break;
	}

	case 25:
	{
		if (checkpoint < 12)
		{
			line lc[32] = {
				{fals, fals, 0, "TIME RAIDERS: GENESIS            une creation de fan par          ICHABOD 'SCOUT' WILLIAMS"},
				{fals, fals, 0, "L'heure des comptes etait sur    lui, sentit Jahn-Jahn Gazebo. Ce"},
				{fals, fals, 0, "n'etait qu'une question de temps avant"},
				{fals, fals, 0, "Star Space Goblin Emperor Wizard rattraperait sa planete. Mais les"},
				{fals, fals, 0, "Time Raiders etaient prepares."},
				{fals, fals, 0, "Les squeebo-zeebos l'avaient     prevenu a l'avance, alors lui et sa bande etaient prets."},
				{fals, fals, 0, "Ils allaient se cacher a la vue  de tous en faisant semblant"},
				{fals, fals, 0, "d'etre un groupe different -     'Space Raiders'."},
				{fals, fals, 0, "Jahn-Jahn avait donne a son epee de guitare un nouveau travail de peinture."},
				{fals, fals, 0, "Nexus, son acolyte quipster,     avait fa]onne son clavier pour   qu'il ressemble"},
				{fals, fals, 0, "comme un clavier d'ordinateur,   eta troque ses lunettes Mondo"},
				{fals, fals, 0, "contre une paire de lunettes de  soleil normales."},
				{fals, fals, 0, "Ninjette, leur batteur et ninja, avait deguise son mondo"},
				{fals, fals, 0, "nunchakus / pilons comme une     paire de pilons de poulet. Ils   avaient l'air tres delicieux."},
				{fals, fals, 0, "L'heure avait sonne. Ils ont     decide d'echanger les genres. La "},
				{fals, fals, 0, "musique country etait ce qu'ils  allaient faire."},
				{fals, fals, 0, "Bientot, le Star Space Goblin    Emperor Wizard avait atterri sur Sqeeb-Sqeeb 9."},
				{fals, fals, 0, "'AA D'ACCORD !' s'ecria-t-il,    'JECHERCHE JAHN-JAHN GAZEBO !"},
				{fals, fals, 0, "SON CRANE RENCONTRERA MON MECHANTPOING DU MAL !.. POUR LE MAL !'"},
				{fals, fals, 0, "'Pas si vite, Star Space Goblin  Emperor Wizard!' dit Jahn-Jahn,  portant une fausse perruque."},
				{fals, fals, 0, "' Comment le sais-tu, civil au   hasard ? ' a demande l'Espace    Etoile"},
				{fals, fals, 0, "Goblin Emperor Wizard, qui n'a   pas reconnu son ennemi jure."},
				{fals, fals, 0, "'J'ai ecrit une chanson a ce     sujet ! Voulez-vous l'entendre?"},
				{fals, fals, 0, "C'est parti !' Et avec ]a, la    chanson a commence."},
				{fals, fals, 0, "Parce que c'etait de la musique  country, ]a craignait tellement"},
				{fals, fals, 0, "que tous ses hommes de main      soient morts."},
				{fals, fals, 0, "Le Star Space Goblin Emperor     Wizard lui-meme etait suspect"},
				{fals, fals, 0, "que c'etait en fait eux, mais    Ninjette reflechit vite...."},
				{fals, fals, 0, "Je n'arrive pas a croire que cet histoire ait ete rejetee du"},
				{fals, fals, 0, "concours de scenario Time        Raiders, c'est parfait."},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page_lite(lc);
			return 0;
		}
		else
		{
			line lc[32] = {
				{fals, fals, 0, "TIME RAIDERS: NEO GENESIS DAWN   une creation de fan par          ICHABOD 'SCOUT' WILLIAMS"},
				{fals, fals, 0, "Jahn-Jahn Gazebo etait triste.   Tres triste. Il ressentit une    profonde tristesse."},
				{fals, fals, 0, "C'est parce qu'il avait          accidentellement consomme le     poivre de tristesse du secteur 9."},
				{fals, fals, 0, "Qu'y a-t-il, Jahn-Jahn ? demanda Scout, qui etait son premier     officier."},
				{fals, fals, 0, "'Les poivrons, c'est nul',       repondit-il. Il avait raison."},
				{fals, fals, 0, "Ils ne sont pas partis a         l'aventure cette fois, puisqu'ils"},
				{fals, fals, 0, "ont laisse Scout decider de leur destination. Scout est un indivi-du tres indecis, voyez-vous."},
				{fals, fals, 0, "En fait, Scout souffrait a la    fois du blocage de l'ecriture et d'une horrible douleur au poignet"},
				{fals, fals, 0, "Ainsi, l'empereur Star Space     Goblin a decide d'abandonner au  hasard et de leur donner son"},
				{fals, fals, 0, "vaisseau. Tout le mal dans       l'univers a ete zappe comme par  magie et tout allait bien a la"},
				{fals, fals, 0, "fin, je suis fatigue."},
				{fals, fals, 0, "..."},
				{fals, fals, 0, "Je ne suis pas fait pour etre ecrivain, n'est-ce pas? Bien trop   paresseux."},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page_lite(lc);
			return 0;
		}
		break;
	}

	case 26:
	{
		line lc[32] = {
			{fals, fals, 0, "Euh, j'ai... j'ai en fait gagné."},
			{fals, fals, 0, "J'aimerais qu'il y ait une       recompense."},
			{fals, fals, 0, "Eh, later."},
			{fals, fals, 0, "COM: Endscene"}};
		dialogue_page_lite(lc);
		return 0;
		break;
	}

	case 27:
	{
		line lc[32] = {
			{fals, fals, 0, "S_DOCKS"},
			{true, true, 28, "CAP'N NICHOLAS                                                    He, fille! Pret pour le voyage?"},
			{true, fals, 29, "DIANA                                                             Oui, capitaine!"},
			{fals, true, 28, "CAP'N NICHOLAS                                                    Rappelle-toi ce que j'ai dit -   evite les rochers et fait        attention a la vitesse!"},
			{fals, fals, 29, "DIANA                                                             Oui, capitaine!!"},
			{fals, fals, 0, "COM: Endscene"}};
		dialogue_page(lc);
		return 0;
		break;
	}

	case 28:
	{
		line lc[32] = {
			{fals, fals, 0, "BG: news"},
			{fals, fals, 0, "S_STV_01"},
			{fals, true, 0, "SCOUT                            Salut tout le monde! Scout est   la! C'est le moment!"},
			{fals, fals, 0, "S_STV_02"},
			{fals, true, 0, "                                 Scout TV est une chose reguliere!Comme vous pouvez le voir,       maintenant je me sens comme un   vrai journaliste!"},
			{fals, true, 0, "                                 Nous sommes tous sur l'ile depuistrois mois. Je peux pas dire si  c'est plus comme un jour ou un   million d'annees!"},
			{fals, true, 0, "                                 Bon. Cela fait un moment depuis  la derniere fois, mais il semble que deux autres personnes se     soient jointes a nous!"},
			{fals, true, 0, "                                 Nous avons d'abord Cesar de la   Cruz, un invite special de notre reine Enoki."},
			{fals, true, 0, "                                 Apparemment, il etait un celebre avocat a la recherche d'un       nouveau depart."},
			{fals, true, 0, "                                 Nous avons aussi un nouveau gars qui emmenage. Il s'appelle Guy etil est cuisinier!"},
			{fals, true, 0, "                                 J'ai hate de voir ]a nourriture! Sont jambalaya est               exceptionnellement repute!"},
			{fals, true, 0, "                                 De plus, nous rapprochons de la  Scout Expo, et ce n'est qu'une   question de temps avant qu'elle  soit prete!"},
			{fals, true, 0, "                                 J'ai aussi commande un tas de    numeros de Time Raiders parce queje sais que certains insulaires  se sont mis a..."},
			{fals, fals, 0, "BG: fadeout"},
			{fals, fals, 0, "S_STV_03"},
			{fals, fals, 0, "                                 . . . ."},
			{fals, fals, 0, "BG: rain"},
			{fals, fals, 0, "S_STV_04"},
			{fals, true, 0, "RUFUS                            Moi, euh- hmm.. oui, bonsoir,    voisins de l'ile. Je suis Rufus  Thibodeaux, et si vous ne me     connaissez pas, vous allez le"},
			{fals, true, 0, "                                 decouvir. J'interromps cette tran-smission pour donner un         ultimatum. Soit   ils me donnent l'ile, soit je vais-!"},
			{fals, fals, 0, "BG: fadeout"},
			{fals, fals, 0, "S_STV_03"},
			{fals, fals, 0, "                                 . . . ."},
			{fals, fals, 0, "S_STV_01"},
			{fals, true, 0, "                                 -et c'est tous les amis! a la    prochaine!"},
			{fals, fals, 0, "S05:02"},
			{fals, true, 0, "ENOKI                            Aw, j'ai rate l'emission de      Scout... Je l'attendais avec     impatience..."},
			{fals, true, 0, "MAPLE                            He, n'etait-ce pas le neveu de   cet abruti de Del? Il s'est      arrete sur l'ile il y a quelques mois, je crois."},
			{fals, true, 0, "AARON                            Quelle etrange transmission."},
			{fals, true, 0, "ENOKI                            Je vais boire un verre."},
			{fals, fals, 0, "COM: Endscene"}};
		dialogue_page(lc);
		return 0;
		break;
	}

	case 29:
	{
		line lc[32] = {
			{fals, fals, 0, "BG: fadeout"},
			{fals, fals, 0, "S11:01"},
			{fals, fals, 0, ". . ."},
			{fals, fals, 0, "BG: 1"},
			{fals, true, 0, "ENOKI                            He, Aaron?"},
			{fals, true, 0, "AARON                            *Baille* Oui?"},
			{fals, true, 0, "ENOKI                            Etes-tu heureux?"},
			{fals, true, 0, "AARON                            Bien sur que je le suis, Noke."},
			{fals, fals, 0, "S11:02"},
			{fals, true, 0, "ENOKI                            Je veux dire, es tu vraiment     heureux? Je m'inquiete pour toi."},
			{fals, true, 0, "AARON                            Je suppose que je suis un peu    melancolique a ce sujet, c'est   tout."},
			{fals, true, 0, "ENOKI                            Qu'est-ce que tu veux dire?"},
			{fals, true, 0, "AARON                            Tu sais. Maple avait raison, nousne pouvons etre ici que grace a  l'argent que tu as gagnee."},
			{fals, true, 0, "AARON                            Nous avons tout donne pour cet   endroit et si quelque chose      tourne mal, nous aurons          absolument rien."},
			{fals, true, 0, "ENOKI                            Tu me connais deja moi et ma     chance, en plus je t'ai a mes    cotes c'est tout ce dont j'ai    besoin."},
			{fals, true, 0, "AARON                            Tu penseras tu comme ]a lorsque  tu seras affamee. Tu ne sais pas ce que c'est que d'avoir faim."},
			{fals, true, 0, "ENOKI                            Je veux pas y penser... Si je le fais, je ne pourrai pas dormir."},
			{fals, fals, 0, "S11:03"},
			{fals, true, 0, "ENOKI                            Pouvons-nous juste etre heureux? Nous en reparlerons une autre    fois."},
			{fals, true, 0, "AARON                            Je suppose que oui. Bonne nuit,  Noc-Noc."},
			{fals, true, 0, "ENOKI                            Bonne nuit, Aaron."},
			{fals, fals, 0, "BG: fadeout"},
			{fals, fals, 0, ". . ."},
			{fals, fals, 0, "COM: Endscene"}};
		dialogue_page(lc);
		return 0;
		break;
	}

	case 30:
	{
		line lc[32] = {
			{fals, fals, 0, "BG: CRUZ01"},
			{fals, true, 0, "CESAR                            Ah! Heureux de vous rencontrer!  Vous devez etre l'un des         habitants. Vous pouvez m'appeler Cesar."},
			{fals, true, 0, "                                 Croyez-le ou non, j'etais avocat,mais je n'etait pas vraiment un  bon avocat."},
			{fals, fals, 0, "BG: CRUZ02"},
			{fals, true, 0, "                                 Je n'avais pas de diplome, mais  je gagnais quand meme chaque     fosi."},
			{fals, true, 0, "                                 Pourquoi je te dis ]a alors que  nous ne nous sommes jamais       rencontres auparavant?"},
			{fals, true, 0, "                                 ..."},
			{fals, fals, 0, "BG: CRUZ01"},
			{fals, fals, 0, "                                 ..."},
			{fals, true, 0, "                                 C'est mieux si on se connait tousun peu. Non?"},
			{fals, true, 0, "                                 J'aime m'occuper et je realise   mon reve d'etre un commer]ant    dans un endroit calme."},
			{fals, true, 0, "                                 Si vous voyez des clients        etrangers qui sont en colere     contre moi, faites-le moi savoir"},
			{fals, true, 0, "                                 pour que je puisse... euh. Me    chachez. Merci!"},
			{fals, true, 0, "                                 Quoi qu'il en soit, ai-je un     article qui attire votre         attention?"},

			{fals, fals, 0, "COM: Endscene"}};
		dialogue_page(lc);
		return 0;
		break;
	}

	case 31:
	{
		line lc[32] = {
			{fals, fals, 0, "BG: CRUZ01"},
			{fals, true, 0, "                                 Enoki Ramirez! Euh... Maintenant Tremblay, non? Merci beaucoup de m'avoir permis de venir ici."},
			{fals, true, 0, "                                 Je promets que je ne causerait   aucun probleme ici, bien que mes derniers clients..."},
			{fals, fals, 0, "BG: CRUZ02"},
			{fals, true, 0, "                                 Ecoute, ce n'etait pas MA faute  si j'etais si doue pour faire    semblant d'etre un avocat de hautniveau, tu sais?"},
			{fals, fals, 0, "BG: CRUZ01"},
			{fals, true, 0, "                                 Je sais que tu me comprends.     Faites-moi savoir s'ils viennent me chercher pour que je puisse mecacher a temps. Bien?"},
			{fals, true, 0, "                                 Mon reve depuis que je suis      enfant est d'etre commer]ant dansune petite ville, meme si je n'aipas grand-chose a vendre."},
			{fals, true, 0, "                                 Maintenant que j'en ai           l'opportunite, je ferai de mon   mieux! Comment puis-je vous aideraujourd'hui?"},
			{fals, fals, 0, "COM: Endscene"}};
		dialogue_page(lc);
		return 0;
		break;
	}

	case 32:
	{
		line lc[32] = {
			{fals, fals, 0, "S_STV_03"},
			{fals, fals, 0, "                                 . . . ."},
			{fals, fals, 0, "BG: rain"},
			{fals, fals, 0, "S_STV_04"},
			{fals, true, 0, "RUFUS                            Bonjour a tous. Il semble que monavertissement precedent n'etait  pas suffisant et personne n'a    montre le moindre"},
			{fals, true, 0, "RUFUS                            soup]on de peur au cours du mois dernier. vous avez fait une graveerreur, car je prevois prendre   l'ile par la force si necessaire."},
			{fals, fals, 0, "S06:01"},
			{fals, true, 0, "MAPLE                            ...Ugggh, tais-toi, Rufus,       j'essaie de dormir."},
			{fals, true, 0, "RUFUS                            J'ai developpe un-"},
			{fals, fals, 0, "S06:02"},
			{fals, true, 0, "ENOKI                            Je ne me souviens pas d'avoir    allume la tele ce matin, tu l'as allume, Maple?"},
			{fals, true, 0, "MAPLE                            ..."},
			{fals, fals, 0, "S06:03"},
			{fals, true, 0, "AARON                            J'ai peut-etre heurte quelque    chose par accident. Je l'eteins?"},
			{fals, true, 0, "MAPLE                            ...mmmrff... TV... off...        Samedi..."},
			{fals, true, 0, "RUFUS                            Dans moins de trente secondes, jelacherai mon-"},
			{fals, fals, 0, "BG: fadeout"},
			{fals, true, 0, "AARON                            D'accord, c'est fini."},
			{fals, true, 0, "ENOKI                            C'etais quoi?"},
			{fals, true, 0, "AARON                            Aucune idee, Noke."},
			{fals, true, 0, "MAPLE                            ..."},
			{fals, fals, 0, "SF: Boom"},
			{fals, true, 0, "ENOKI                            He, c'est quoi ce bruit?"},
			{fals, true, 0, "AARON                            Je n'aime pas ce son.. Maple, tu devrais peut-etre te lever."},
			{fals, true, 0, "MAPLE                            ...Grr, je vais tuer cet         alligator..."},
			{fals, true, 0, "ENOKI                            Mais quoi- oh non..."},
			{fals, true, 0, "AARON                            Enoki, toi et Maple courez au    bunker de Scout, je vais vers    l'ouest pour voir si les autres  vont bien."},
			{fals, true, 0, "MAPLE                            Excusez-moi, je peux m'occuper demon-"},
			{fals, true, 0, "AARON                            Tu vas aller au bunker, en plus  tu pourras still y dormir."},
			{fals, true, 0, "MAPLE                            He, pas besoin d'etre aussi      passif-agressif avec moi."},
			{fals, fals, 0, "COM: Endscene"}};
		dialogue_page(lc);
		return 0;
	}

	case 33:
	{
		line lc[32] = {
			{fals, fals, 0, "S07:01"},
			{fals, fals, 0, "BG: fadeout"},
			{fals, true, 0, "MAPLE                            Dis-moi la verite, C'est toi qui a construit cet endroit?"},
			{fals, true, 0, "SCOUT                            Oh que non! Bien que j'aurais    aime le faire."},
			{true, true, 0, "S07:02"},
			{true, true, 0, "..."},
			{true, true, 0, "S07:03"},
			{fals, true, 0, "SCOUT                            MAPLE, ATTENTION!"},
			{true, true, 0, "S07:04"},
			{fals, true, 0, "MAPLE                            ... Scout, tu vas bien?"},
			{fals, true, 0, "RUFUS                            Aie. Meme si je me suis un peu   cogne le dos. Je pense que ]a    ira."},
			{true, true, 0, "S07:05"},
			{fals, true, 0, "MAPLE                            Qu'est-ce que toute cette        gasoline fait ici?"},
			{fals, true, 0, "SCOUT                            Pour notre bien, vous feriez     mieux d'etre prudent avec vos    pouvoirs."},
			{fals, fals, 0, "COM: Endscene"}};
		dialogue_page(lc);
		return 0;
	}

	case 34:
	{

		{
			line lc[32] = {
				{fals, fals, 0, "S07:06"},
				{fals, fals, 0, "BG: fadeout"},
				{fals, true, 0, "MAPLE                            ..."},
				{fals, true, 0, "MAPLE                            Quoi... Quesque je regarde en ce moment?"},
				{true, true, 0, "S07:07"},
				{true, true, 0, "BG: rain"},
				{true, true, 0, "SF: rufus"},
				{fals, true, 0, "RUFUS                            Ichabod Williams et Maple        Tremblay, Quelle surprise! Je    suis content de vous autres voir ici."},
				{fals, true, 0, "RUFUS                            Enfin, nous avons tous pu nous   rencontrer."},
				{true, true, 0, "S07:08"},
				{fals, true, 0, "SCOUT                            RUFUS Qu-, QU'EST-CE QUE TU FAIS?"},
				{fals, true, 0, "MAPLE                            LAISSEZ-MOI TRANQUILLE, ENFANT!"},
				{fals, true, 0, "RUFUS                            Tu ferais mieux de mettre un     bracelet anti-magie sur toi pour eviter d'en avoir... Des         etincelles d'inspiration."},
				{true, true, 0, "BG: fadeout"},
				{true, true, 0, "S07:14"},
				{fals, true, 0, "RUFUS                            Bon, maintenant que nous avons   tous les Tremblay reunis au meme endroit... nous pouvons          commencer!"},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page(lc);
		}

		{
			line lc[32] = {
				{true, true, 0, "BG: groovy"},
				{true, true, 0, "S07:09"},
				{fals, true, 0, "RUFUS                            Tout d'abord, faisons une breve  introduction. Je suis Monsieur   Rufus Thibodeaux, et aujourd'hui je serai votre professeur."},
				{fals, true, 0, "RUFUS                            Faites attention. Personne ne    semble m'ecouter, alors nous     ferons un quiz a la fin de la    seance."},
				{true, true, 0, "S07:10"},
				{fals, true, 0, "RUFUS                            Le]on numero un. Repetez apres   moi, 'Rufus n'est pas petit. Il  n'a que de petits os."},
				{fals, true, 0, "MAPLE                            .....Tu plaisante?"},
				{fals, true, 0, "RUFUS                            ..]a ressemble pas a la phrase   que tu as a dire maintenant,     n'est-ce pas, Maple?"},
				{true, true, 0, "S07:11"},
				{fals, true, 0, "RUFUS                            Il semble que tout le monde      echoue cette le]on. Alors passonsau suivant... Parlons de la fleurd'Apres. Une entreprise m'a"},
				{fals, true, 0, "RUFUS                            engage pour l'etudier. Tout commeIchabod... ou 'Scout', cette     fleur est native et contient"},
				{fals, true, 0, "RUFUS                            des 'proprietes metaphysiques'   cool non? Malgre mes             instructions. Un jour, je me suisennuye et j'ai decide de prendre"},
				{fals, true, 0, "RUFUS                            quelques bouchees. Et savez-vous ce qui s'est passe ensuite?"},
				{true, true, 0, "S07:12"},
				{fals, true, 0, "RUFUS                            Je me suis retrouve a voyager a  travers le multivers. J'ai       explore toutes sortes de mondes  differents, certains similaires"},
				{fals, true, 0, "RUFUS                            acelui-ci et d'autres            completement eloignes decette    realite. Mais savez-vous ceque"},
				{fals, true, 0, "RUFUS                            j'ai decouvert dans presque      chacun d'entre eux?"},
				{true, true, 0, "S07:13"},
				{fals, true, 0, "RUFUS                            Il y avait une tendance etrange  de femmes attirantes combattant  le mal de ces mondes."},
				{fals, true, 0, "RUFUS                            Avec des hommes flamboyants qui  servait de cible a toutes les    blagues ou ont etais  des        mechants incompetents."},
				{fals, true, 0, "RUFUS                            a la fin, ils ont tous ete       remplaces par des mechantes plus competentes et incompris qui"},
				{fals, true, 0, "RUFUS                            etais mauvaise parce que un      homme les avaient"},
				{fals, true, 0, "RUFUS                            maltraitee. Pouvez-vous deviner  ce que je pensais a ce moment-la?"},
				{fals, true, 0, "MAPLE                            Calme-toi-"},
				{true, true, 0, "S07:14"},
				{fals, true, 0, "MAPLE                            Es-tu vraiment en train de me    dire que tu es devenu mechant    simplement parce qu'une fleur t'adit"},
				{fals, true, 0, "MAPLE                            tu es le 'mechant'?"},
				{true, true, 0, "S07:16"},
				{fals, true, 0, "RUFUS                            Je crois qu'avec une frappe      preventive, je peux garder       intacte mon image et mon         autonomie. Oui."},
				{fals, true, 0, "RUFUS                            De mon point de vue et apres     avoir etudie ses attributs, Mapleressemble au 'personnage"},
				{fals, true, 0, "RUFUS                            principal' et c'etait mon        meilleur plan."},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page(lc);
		}

		{
			line lc[32] = {
				{true, true, 0, "S07:15"},
				{fals, true, 0, "ENOKI                            Monsieur Rufus, puis-je aller auxtoilettes?"},
				{true, true, 0, "S07:16"},
				{fals, true, 0, "RUFUS                            Vous pouvez y aller apres la     le]on. J'ai presque fini."},
				{true, true, 0, "S07:17"},
				{fals, true, 0, "RUFUS                            Voyons, ou etais-je...?"},
				{true, true, 0, "BG: fadeout"},
				{true, true, 0, "S07:16"},
				{fals, true, 0, "AARON                            Rufus, nous devons parler."},
				{true, true, 0, "S07:18"},
				{fals, true, 0, "AARON                            D'abord. Je suis surpris que tu  savais pas que ma femme est"},
				{fals, true, 0, "AARON                            magicienne. Elle est bonne pour  s'echapper a travers des espaces restreints."},
				{fals, true, 0, "AARON                            Et deuxiemement. Je me fiche de  ce que tu as vu avec cette fleur,tu as effraye tous mes amis."},
				{fals, true, 0, "AARON                            C'est totalement inacceptable. Tune peux pas kidnapper des gens etles garder en otage."},
				{fals, true, 0, "AARON                            Lache-nous et laisse-nous        tranquille, c'est bon?           Comprends-tu?"},
				{fals, true, 0, "RUFUS                            Attend une minute, Aaron."},
				{fals, true, 0, "RUFUS                            Il y a quelque chose que tu dois savoir. Les portes de cette piecesont hermetiquement fermees."},
				{fals, true, 0, "RUFUS                            Si une bombe explosait a         l'exterieur, nous le serions pas.Mais les portes s'ouvriront..."},
				{fals, true, 0, "RUFUS                            si quelqu'un goute la fleur.     Alors je vous mets au defi. Si   vous parvenez a me battre, je    laisserai votre ile en paix."},
				{fals, true, 0, "RUFUS                            Si je gagne, je deviendrai le    nouveau roi. Mais vous devez     prendre la fleur pour sortir."},
				{fals, true, 0, "RUFUS                            Une fois que l'un d'entre vous   aura vu tout ce que j'ai vu, vouscesserez de me prendre pour un   imbecile."},
				{fals, true, 0, "RUFUS                            Nous verrons ce qui se passera..."},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page(lc);
		}

		return 0;
		break;
	}

	case 35:
	{
		{
			line lc[32] = {
				{true, true, 0, "S08:01"},
				{fals, true, 0, "RUFUS                            Bien, bien, bien..."},
				{fals, true, 0, "RUFUS                            HA! On dirait que je gagne! C'estle moment d'utiliser la fleur    d'Apres!"},
				{fals, true, 0, "RUFUS                            Alors... qui va la gouter? Aaron?Que pense?"},
				{fals, true, 0, "MAPLE                            Tu sais quoi? Meme pas dans tes  reves, petit gars."},
				{true, true, 0, "S08:02"},
				{true, true, 0, "BG: rain"},
				{fals, true, 0, "RUFUS                            Qui appelles-tu petit gars?"},
				{fals, true, 0, "MAPLE                            Meme tes petites jambes          robotiques son sur la pointe de  leurs pieds."},
				{true, true, 0, "S08:03"},
				{fals, true, 0, "MAPLE                            Je sais pas pourquoi tu es obsedepar l'idee que le monde est commeton reve de creer par les fleurs."},
				{fals, true, 0, "MAPLE                            Mais la vie est dure, tu sais? Jeme fiche de ce que tu as vu dans"},
				{fals, true, 0, "MAPLE                            tes reves, tu ne peux pas venir  nous deranger sur notre propre   ile."},
				{fals, true, 0, "MAPLE                            On savait meme pas qui tu etais. je vais te menacer comme je      menace tout le monde. Si tu      continu a nous menacer je vais-"},
				{fals, true, 0, "RUFUS                            Je-je sais, je sais, tu l'as dejadit, tu vas me griller le visage."},
				{fals, true, 0, "RUFUS                            Bien que, euh, fais attention au feu. Il y a beaucoup d'objets    inflammables ici."},
				{fals, true, 0, "MAPLE                            FAIS ATTENTION? Tu dis de faire  attention apres nous avoir       KIDNAPPES? Finalement,ton visage va bruler!"},
				{true, true, 0, "S08:04"},
				{fals, true, 0, "CESAR                            He, Maple?"},
				{true, true, 0, "S08:05"},
				{fals, true, 0, "MAPLE                            NON CAESAR, JE DOIS PRENDRE SOIN DE CE PETIT MEGALOMANE!"},
				{true, true, 0, "S08:06"},
				{fals, true, 0, "RUFUS                            N-non vraiment, tu as, euh,      euh... Mon Dieu..."},
				{true, true, 0, "S08:07"},
				{fals, true, 0, "MAPLE                            QUOI?!"},
				{true, true, 0, "BG: fadeout"},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page(lc);
		}
		{
			line lc[32] = {
				{true, true, 0, "S09:01"},
				{true, true, 0, "BG: pools"},
				{fals, true, 0, "GUY                              Je me sent bien ici."},
				{fals, true, 0, "DIANA                            Si la c'etait pas si chere, je leferais tout le temps."},
				{fals, true, 0, "GUY                              Penses-tu que des touristes      viendront sur l'ile?"},
				{fals, true, 0, "DIANA                            Tu devrais te detendre un peu    avec ton restaurant."},
				{fals, true, 0, "DIANA                            Tu devrais prendre une pause et  te detendre de temps en temps,   non?"},
				{fals, true, 0, "GUY                              J'suppose que je devrais. Mais lacuisine est comme mon bebe, je nepeux pas m'en empecher."},
				{fals, true, 0, "DIANA                            Et si elle explosait soudainementun jour?"},
				{true, true, 0, "BG: fadeout"},
				{true, true, 0, "S09:02"},
				{true, true, 0, "..."},
				{true, true, 0, "SF: Boom"},
				{true, true, 0, "S09:03"},
				{true, true, 0, "......"},
				{true, true, 0, "S09:04"},
				{true, true, 0, "GUY                              ..."},
				{true, true, 0, "DIANA                            ..."},
				{true, true, 0, "GUY                              Tonnere.. mon.. chien."},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page(lc);
		}
		{
			line lc[32] = {
				{true, true, 0, "S09:05"},
				{fals, true, 0, "RUFUS                            Mais quoi..."},
				{true, true, 0, "RUFUS                            ..."},
				{true, true, 0, "S09:06"},
				{fals, true, 0, "MAPLE                            Je... je-je..."},
				{fals, true, 0, "AARON                            Maple, je-"},
				{fals, true, 0, "MAPLE                            ... je-je suis..."},
				{true, true, 0, "S09:08"},
				{fals, true, 0, "ENOKI                            Maple, reviens!"},
				{true, true, 0, "MAPLE                            ..."},
				{true, true, 0, "S09:09"},
				{true, true, 0, "MAPLE                            ..."},
				{fals, true, 0, "AARON                            Maple, nous devons parler.       Maintenant."},
				{true, true, 0, "S09:10"},
				{fals, true, 0, "ENOKI                            Maple, tu es-"},
				{fals, true, 0, "AARON                            Maria, je t'aime, mais Maple et  moi devons parler."},
				{true, true, 0, "S09:11"},
				{fals, true, 0, "ENOKI                            Maria..."},
				{fals, true, 0, "ENOKI                            D-D'accord, je vais voir comment vont les autres."},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page(lc);
		}
		{
			line lc[32] = {
				{true, true, 0, "S09:12"},
				{fals, true, 0, "AARON                            Maple. Nous devrions avoir  cetteconversation depuis longtemps, etje ne peux plus attendre."},
				{true, true, 0, "S09:13"},
				{fals, true, 0, "AARON                            Je pense que tu sais de quoi il  s'agit."},
				{fals, true, 0, "MAPLE                            Je-je n'ai pas envie de parler ence moment."},
				{true, true, 0, "S09:14"},
				{true, true, 0, "BG: maple"},
				{fals, true, 0, "AARON                            Je veux m'excuser."},
				{true, true, 0, "S09:13"},
				{fals, true, 0, "AARON                            Je me suis plaint de toi aux     autres."},
				{fals, true, 0, "AARON                            Bien qu'au final tu aies fait    beaucoup de choses qui me rendentfier d'etre ton grand frere."},
				{fals, true, 0, "AARON                            Tu as cette colere qui est en toitout le temps, une colere que tu projettes vers tout ce que tu    vois comme mauvais dans ce monde."},
				{fals, true, 0, "AARON                            La colere n'est pas une mauvaise chose, mais je vois que tous ce  qui te met en colere c'est des   choses que tu vois aussi en toi."},
				{true, true, 0, "S09:14"},
				{fals, true, 0, "AARON                            Merci pour tout, j'apprecie      vraiment que tu me defendes."},
				{fals, true, 0, "MAPLE                            Tais-toi."},
				{true, true, 0, "S09:13"},
				{fals, true, 0, "AARON                            Je ne vais pas me taire."},
				{fals, true, 0, "AARON                            Prends ton temps pour te calmer, mais tu devras apprendre a       controler ta colere. Ou je ne    pourrai plus te soutenir."},
				{fals, true, 0, "MAPLE                            ...Oui."},
				{true, true, 0, "S09:15"},
				{fals, true, 0, "AARON                            Je suis content que tu           comprennes. Rufus, je pense que  nous avons aussi quelque chose a nous dire."},
				{true, true, 0, "S09:16"},
				{true, true, 0, "BG: fadeout"},
				{fals, true, 0, "ENOKI                            A-Aar.. AARON, ATTENDS!"},
				{fals, true, 0, "AARON                            Nous devons ouvrir ces portes."},
				{fals, true, 0, "RUFUS                            He, je suis sur que je peux      trouver un moyen de desactiver leverrou. Je pense que tu n'as pas a-"},
				{fals, true, 0, "ENOKI                            J-Je ne veux pas que tu changes."},
				{fals, true, 0, "AARON                            Je vais le faire."},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page(lc);
		}

		// kiss
		{
			globals->current_save->checkpoint = 15;
			flash_write();

			for (int clicks = 0; clicks < 16 * 2; clicks++)
			{
				bn::core::update();
			}

			line l2[10] = {
				{fals, true, 0, "N-Non... je ne peux pas te       perdre..."},
				{true, true, 0, "COM: Endscene"}};
			dialogue_page_lite(l2);

			for (int clicks = 0; clicks < 64 * 2; clicks++)
			{
				bn::core::update();
			}
		}
		{
			auto aaron_01 = bn::regular_bg_items::real_aaron_01.create_bg(0, 0);
			auto aaron_02 = bn::regular_bg_items::real_aaron_02.create_bg(0, 0);
			auto aaron_03 = bn::regular_bg_items::real_aaron_03.create_bg(0, 0);
			auto eye_01 = bn::sprite_items::real_aaron_eyes.create_sprite(-10, -1, 0);
			auto eye_02 = bn::sprite_items::real_aaron_eyes.create_sprite(22, -2, 1);

			for (int clicks = 0; clicks < 64 * 2; clicks++)
			{
				bn::core::update();
			}

			line l2[10] = {
				{fals, true, 0, "                                 A-Aaron? Pourquoi me regardes-tu ainsi?"},
				{true, true, 0, "COM: Endscene"}};
			dialogue_page_lite(l2);
		}
		{
			auto enoki_01 = bn::regular_bg_items::real_enoki_01.create_bg(0, 0);
			auto enoki_02 = bn::regular_bg_items::real_enoki_02.create_bg(0, 0);
			auto enoki_03 = bn::regular_bg_items::real_enoki_03.create_bg(0, 0);
			auto eye_01 = bn::sprite_items::real_enoki_eyes.create_sprite(-4, -9, 0);
			auto eye_02 = bn::sprite_items::real_enoki_eyes.create_sprite(22, -8, 1);

			for (int clicks = 0; clicks < 64 * 2; clicks++)
			{
				bn::core::update();
			}

			line l2[10] = {
				{fals, true, 0, "Dis quelque chose... tu me fais  peur..."},
				{true, true, 0, "COM: Endscene"}};
			dialogue_page_lite(l2);
		}
		{
			auto bg = bn::regular_bg_items::s0917.create_bg(0, 0);
			for (int clicks = 0; clicks < 64 * 4; clicks++)
			{
				bn::core::update();
			}
		}
		{
			auto bg = bn::regular_bg_items::s0918.create_bg(0, 0);
			for (int clicks = 0; clicks < 64 * 4; clicks++)
			{
				bn::core::update();
			}
		}

		{
			line lc[32] = {
				{true, true, 0, "BG: 2"},
				{true, true, 0, "S10:01"},
				{fals, true, 0, "AARON                            J'ai paye l'ile en especes. Nous devrions en avoir assez pour     louer une maison en Louisiane."},
				{fals, true, 0, "AARON                            Un acadien ne trouvera jamais unemeilleure maison en dehors de la Louisiane de toute fa]on, oui?"},
				{fals, true, 0, "AARON                            Je pense que j'ai assez d'argent pour payer a tout le monde"},
				{fals, true, 0, "AARON                            quelques mois de loyer jusqu'a cequ'ils puissent reprendre une vienormale."},
				{fals, true, 0, "AARON                            Je veux dire que ce fut un       honneur pour moi d'etre votre roipendant cette periode. Merci a   tous d'etre la."},
				{true, true, 0, "S10:02"},
				{fals, true, 0, "OLIVIER                          Nous tenons egalement a vous     remerciez. Je sais pas ce que moiet Eleanor allons faire, mais... On trouvera quelque chose."},
				{fals, true, 0, "OLIVIER                          Nous sommes venus ici parce que  nous n'avions pas de ressources. Donc vous rencontrez a ete une   benediction."},
				{fals, true, 0, "CESAR                            Et il ne fait aucun doute que    Enoki m'a sauve la mise."},
				{fals, true, 0, "RUFUS                            Je... Je peux aider si quelqu'un a besoin de moi ou a besoin d'un logement. Je suis vraiment desolepour votre ile..."},
				{fals, true, 0, "RUFUS                            Je n'ai jamais vraiment voulu    causer autant de problemes,      j'etais juste ici pour jouer un  peu l'antagoniste, je..."},
				{fals, true, 0, "RUFUS                            He, j'ai des couvertures et des  trucs si tu as besoin de passer  la nuit."},
				{true, true, 0, "S10:01"},
				{fals, true, 0, "AARON                            ...Merci, Rufus."},
				{fals, true, 0, "AARON                            Nous aurons tous besoin de temps pour assimiler ce qui s'est"},
				{fals, true, 0, "AARON                            passe. J'ai cependant pas vu le  bateau de Diana sur les images del'ile."},
				{fals, true, 0, "AARON                            Tout le monde semble okay. Et a  la fin, c'est la chose la plus   importante de toutes."},
				{fals, true, 0, "AARON                            Je vous-autres aime tous."},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page(lc);
		}

		{
			line lc[32] = {
				{true, true, 0, "S10:04"},
				{true, true, 0, "BG: fadeout"},
				{fals, true, 0, "SCOUT                            Maple, comment ]a va?"},
				{true, true, 0, "MAPLE                            ..."},
				{true, true, 0, "S10:03"},
				{fals, true, 0, "MAPLE                            ... N'ose pas t'inquieter pour   moi. C'est clair?"},
				{true, true, 0, "S10:04"},
				{fals, true, 0, "SCOUT                            Oui, bien sur, c'est juste... je suis desole pour-"},
				{true, true, 0, "S10:03"},
				{fals, true, 0, "MAPLE                            Desole pour quoi?"},
				{fals, true, 0, "SCOUT                            Laisse-moi finir."},
				{fals, true, 0, "MAPLE                            Bon. Continue."},
				{fals, true, 0, "SCOUT                            Desole d'etre audacieux, mais    s'il te plait, arrete de te      blamer autant. Je suis de ton    cote, tu sais?"},
				{fals, true, 0, "MAPLE                            Quoi, tu vas m'inviter a sortir  ou quoi?"},
				{true, true, 0, "S10:04"},
				{fals, true, 0, "SCOUT                            Non, je-je... eh well, non, je   suis pas... ecoute, je veux justepas te perdre."},
				{fals, true, 0, "SCOUT                            Je suis pas en colere contre toi,et... he, je ne voudrais pas     gacher notre amitie non plus."},
				{fals, true, 0, "SCOUT                            juste parce que tu es en colere, d'accord? Tu es plus important   que l'ile. Et..."},
				{fals, true, 0, "SCOUT                            Je veux que tu me promettes que  tu n'iras nulle part ou faire    quelque chose de stupide a cause de ]a je t'en prie!"},
				{fals, true, 0, "MAPLE                            ..."},
				{true, true, 0, "S10:04"},
				{fals, true, 0, "MAPLE                            ...Je ne ferais, ne t'inquiete   pas pour moi."},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page(lc);
		}

		{
			bn::regular_bg_ptr text = bn::regular_bg_items::s0201.create_bg(0, 0);
			bn::sound_items::firehit.play();

			for (int clicks = 0; clicks < 64 * 2; clicks++)
			{
				bn::core::update();
			}
		}

		{
			line lc[32] = {
				{true, true, 0, "BG: the flame"},
				{true, true, 0, "S10:05"},
				{fals, true, 0, "ENOKI                            He, Maple! Tu es de retour?"},
				{fals, true, 0, "MAPLE                            Oui. L'entretien s'est bien      passe. etre dans l'armee         ressemble a une corvee, mais les avantages sont enormes."},
				{fals, true, 0, "AARON                            Je sais que tu t'en sortiras tresbien, Maple."},
				{fals, true, 0, "MAPLE                            TU es serieuse?"},
				{fals, true, 0, "AARON                            Je parie que tu seras la seule   elfe du peloton. Et cela jouera  en ta faveur."},
				{fals, true, 0, "MAPLE                            Oui, je pense que oui. J'en ai   parle a Scout. Il dit qu'il est  heureux mais je vais lui manquer."},
				{fals, true, 0, "ENOKI                            Tu nous manqueras aussi."},
				{true, true, 0, "S10:06"},
				{fals, true, 0, "ENOKI                            Well, Aaron et moi avons aussi   des nouvelles pour toi."},
				{true, true, 0, "S10:07"},
				{fals, true, 0, "MAPLE                            Wow, quelles nouvelles?"},
				{true, true, 0, "S10:08"},
				{fals, true, 0, "ENOKI                            Il parait que bientot... Euh...  Que bientot il y aura un nouveau Tremblay avec nous."},
				{true, true, 0, "S10:10"},
				{fals, true, 0, "MAPLE                            Attendez, ne me dit pas-?"},
				{true, true, 0, "S10:09"},
				{fals, true, 0, "ENOKI                            Ah!"},
				{true, true, 0, "S10:11"},
				{fals, true, 0, "MAPLE                            Est-tu... ENCEINTE?"},
				{fals, true, 0, "AARON                            Oh que oui, miss"},
				{true, true, 0, "S10:09"},
				{fals, true, 0, "MAPLE                            C'est pas possible, je suis... jevais etre tante. Quel genre de   personne sortira d'un melange    comme Aaron et Enoki?"},
				{true, true, 0, "S10:12"},
				{fals, true, 0, "ENOKI                            2000 a ete une annee incroyable, et je suis sur que 2001 sera     encore meilleure!"},
				{fals, true, 0, "AARON                            Quelle que soit l'aventure qui   nous attend, je suis contente quevous soyez avec moi."},
				{fals, true, 0, "MAPLE                            Bonne annee 2001, les gars!"},
				{fals, true, 0, "ENOKI                            Bonne annee 2001!"},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page(lc);
		}

		for (int t = 0; t < 6; t++)
		{
			bn::core::update();
		}
		break;
	}

	case 36:
	{
		line lc[32] = {
			{true, fals, 32, "penis"}, // What was I drinking?
			{fals, fals, 0, "COM: Endscene"},
		};
		dialogue_page(lc);
		return 0;
		break;
	}

	case 37:
	{
		line lc[32] = {
			{true, fals, 32, "BG:CINEMINT"}, // What was I drinking?
			{fals, fals, 0, "Ohe! Bienvenue! Venez prendre un siege et un the ou un cafe ou    quelque chose."},
			{fals, fals, 0, "Alors, qu'as-tu pense de mon jeu?Ouais.. ce n'etait pas super     long, mais pour etre tout a fait "},
			{fals, fals, 0, "honnete, je n'etais pas          completement sur  que je serais  capable de le retirer, haha."},
			{fals, fals, 0, "J'espere que vous avez passe un  bon moment, cependant. Puisque   vous avez reussi a obtenir toutes"},
			{fals, fals, 0, "les cles, je vais vous laisser   jouer aux mini-jeux que vous     voulez! Arretez-vous simplement a"},
			{fals, fals, 0, "ce fichier de sauvegarde chaque  foisque vous souhaitez les       essayer."},
			{fals, fals, 0, "Jusqu'a la prochaine fois!"},
			{fals, fals, 0, "COM: Endscene"},
		};
		dialogue_page(lc);
		return 0;
		break;
	}

	default:
	{
		return 1;
		break;
	}
	}

	return 0;
}

// Function to calculate the smallest multiple
int roundDown(int n) {
	return n >> 5;
}

int roundUp(int n)
{
	return roundDown(n + 31);
}

int countDigit(int n)
{
	if (n / 10 == 0)
		return 1;
	return 1 + countDigit(n / 10);
}

// Projectiles
class projectile
{
public:
	bn::sprite_item fireball_item = bn::sprite_items::fireball;
	bn::sprite_ptr fireball = fireball_item.create_sprite(0, 0);
	bn::sprite_animate_action<4> fireball_anim = bn::create_sprite_animate_action_forever(fireball, 3, fireball_item.tiles_item(), 00, 1, 2, 3);
	bn::sprite_animate_action<4> fireball_anim_end = bn::create_sprite_animate_action_forever(fireball, 3, fireball_item.tiles_item(), 4, 5, 6, 7);
	short int dir = 1, dur = 0;
	bool active = false;
	void update()
	{
		dur++;
		if (dur < 16)
		{
			fireball_anim.update();
			fireball = fireball_anim.sprite();
			switch (dir)
			{
			case 1:
				fireball.set_x(fireball.x() + 4);
				break;
			case 2:
				fireball.set_x(fireball.x() - 4);
				break;
			case 3:
				fireball.set_y(fireball.y() - 4);
				break;
			default:
				fireball.set_y(fireball.y() + 4);
				break;
			};
		}
		else
		{
			if (dur < 23)
			{
				if (dur == 16)
					bn::sound_items::firehit.play();
				fireball = fireball_anim_end.sprite();
				fireball_anim_end.update();
			}
			else
			{
				fireball.set_visible(false);
			}
		}
	}
};

// Dungeon return type
class dungeon_return
{
public:
	short int spawn_x = 0;
	short int spawn_y = 0;
	short int world_index = 0;
};

// Custom character class
class character
{
public:
	short int identity = 0;
	short int dir = 0;
	short int last_dir = 0;
	short int follow_id = -1;
	bool done = false;
	bool is_walking = false;
	bool event = false;
	bool can_follow = true;
	bool is_npc = false;
	bool teleport = true;

	short int last_x, last_y, loop_x, loop_y;
	short int room_width = 0;

	bn::sprite_item entity_item = bn::sprite_items::maple_walking;
	bn::sprite_ptr entity = entity_item.create_sprite(0, 0);
	bn::sprite_animate_action<4> entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 00, 1, 00, 2);

	short int role = 0;
	// 0 = follower
	// 1 = main
	// 2 = independent

	short int collideFrom = 1;

	character(const bn::sprite_item sprite, bn::fixed_t<12> x = 0, bn::fixed_t<12> y = 0, int main = 0, int r_width = 0)
	{
		entity = sprite.create_sprite(x * 32, y * 32);
		entity.set_visible(true);
		entity_item = sprite;
		entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 0, 1, 0, 2);
		role = main;
		room_width = r_width;
	}

	// Get position on board
	short int get_loc()
	{
		return ((entity.x().round_integer() / 32) + 5) + (((entity.y().round_integer() / 32) + 1) * 8) + 5;
	}

	// Run this regularly!
	void update(int x = 0, int y = 0)
	{
		// Collision detection
		int x_int = entity.x().integer();
		int y_int = entity.y().integer();

		short int col[8] = { 0 };
		short int gol[8] = { 0 };
		bool canLeft = true;
		bool canRite = true;
		bool canUp = true;
		bool canDn = true;
		bool newLeft = 0;
		bool newRite = 0;
		bool newUp = 0;
		bool newDown = 0;

		int close[4] = {
			roundDown(x_int + 6),
			roundUp(x_int - 6),
			roundDown(y_int + 6) * room_width,
			roundUp(y_int) * room_width
		};

		int anti_close[4] = {
			roundUp(x_int + 6),
			roundDown(x_int - 6),
			roundUp(y_int + 6) * room_width,
			roundDown(y_int) * room_width
		};

		if (globals->collisions.size() > 0) {
			col[0] = globals->collisions.at(close[0] + close[2]) == 1;
			col[1] = globals->collisions.at(close[0] + close[3]) == 1;
			col[2] = globals->collisions.at(close[1] + close[2]) == 1;
			col[3] = globals->collisions.at(close[1] + close[3]) == 1;
			col[4] = globals->collisions.at(close[0] + close[2]) == 1;
			col[5] = globals->collisions.at(close[1] + close[2]) == 1;
			col[6] = globals->collisions.at(close[0] + close[3]) == 1;
			col[7] = globals->collisions.at(close[1] + close[3]) == 1;

			gol[0] = globals->collisions.at(anti_close[0] + anti_close[2]) == 1;
			gol[1] = globals->collisions.at(anti_close[0] + anti_close[3]) == 1;
			gol[2] = globals->collisions.at(anti_close[1] + anti_close[2]) == 1;
			gol[3] = globals->collisions.at(anti_close[1] + anti_close[3]) == 1;
			gol[4] = globals->collisions.at(anti_close[0] + anti_close[2]) == 1;
			gol[5] = globals->collisions.at(anti_close[1] + anti_close[2]) == 1;
			gol[6] = globals->collisions.at(anti_close[0] + anti_close[3]) == 1;
			gol[7] = globals->collisions.at(anti_close[1] + anti_close[3]) == 1;

			canLeft = !(((col[4] & col[5]) ^ col[0]) || ((col[6] & col[7]) ^ col[1]));
			canRite = !(((col[4] & col[5]) ^ col[2]) || ((col[6] & col[7]) ^ col[3]));
			canUp = !(((col[0] & col[1]) ^ col[4]) || ((col[2] & col[3]) ^ col[5]));
			canDn = !(((col[0] & col[1]) ^ col[6]) || ((col[2] & col[3]) ^ col[7]));

			newDown = (!gol[0] & !gol[1] & !gol[2] & !gol[4] & !gol[5] & !gol[6] & gol[3] & gol[7]);
			newUp = (!gol[0] & !gol[1] & !gol[3] & !gol[4] & !gol[6] & !gol[7] & gol[2] & gol[5]);
			newLeft = (!gol[0] & !gol[2] & !gol[3] & !gol[4] & !gol[5] & !gol[7] & gol[1] & gol[6]);
			newRite = (!gol[1] & !gol[2] & !gol[3] & !gol[5] & !gol[6] & !gol[7] & gol[0] & gol[4]);
		}

		// If following...
		if (role == 0)
		{

			// Collision detection
			done = true;
			is_walking = false;

			// Follow player
			short int dist = abs(x - entity.x().integer()) + abs(y - entity.y().integer());

			bool isXTravel = false;
			if (x < entity.x() - 24 || (x < entity.x() && dist > 72))
			{
				if (canLeft)
				{
					isXTravel = true;
					x_int = entity.x().integer() - 1;
					dir = 2;
					if (last_dir != dir)
						done = false;
					last_dir = dir;
					is_walking = true;
				}
				else {
					y_int = entity.y().integer() + newDown - newUp;
				}
			}
			else if (x > entity.x() + 24 || (x > entity.x() && dist > 72))
			{
				if (canRite)
				{
					isXTravel = true;
					x_int = entity.x().integer() + 1;
					dir = 1;
					if (last_dir != dir)
						done = false;
					last_dir = dir;
					is_walking = true;
				}
				else {
					y_int = entity.y().integer() + newLeft - newRite;
				}
			}
			if (y < entity.y() - 24 || (y < entity.y() && dist > 72))
			{
				if (canUp)
				{
					y_int = entity.y().integer() - 1;
					if (!isXTravel)
					{
						dir = 3;
						if (last_dir != dir)
							done = false;
						last_dir = dir;
						is_walking = true;
					}
				}
				else {
					x_int = entity.x().integer() + newDown - newLeft;
				}
			}
			else if (y > entity.y() + 24 || (y > entity.y() && dist > 72))
			{
				if (canDn)
				{
					y_int = entity.y().integer() + 1;
					if (!isXTravel)
					{
						dir = 0;
						if (last_dir != dir)
							done = false;
						last_dir = dir;
						is_walking = true;
					}
				}
				else {
					x_int = entity.x().integer() - newRite + newLeft;
				}
			}

			// Animate
			if (!done)
			{
				switch (dir)
				{
				case 1:
					entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 4, 3, 5, 3);
					break;
				case 2:
					entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 7, 6, 8, 6);
					break;
				case 3:
					entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 10, 9, 11, 9);
					break;
				default:
					entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 1, 00, 2, 0);
					break;
				}
			}

			if (dist > 124 && teleport) {
				bn::sound_items::cnaut.play();
				x_int = x;
				y_int = y;
			}

			// Walk
			if (is_walking || (entity_anim.current_index() % 2 == 1))
			{
				entity_anim.update();
			}
		}

		// If main character....
		else if (role == 1)
		{
			if (entity.blending_enabled())
			{
				if (bn::blending::intensity_alpha() > 0.2)
				{
					bn::blending::set_intensity_alpha(bn::blending::intensity_alpha() - 0.02);
				}
				else
				{
					entity.set_blending_enabled(false);
				}
			}

			// Keyboard controls
			if (bn::keypad::up_released() + bn::keypad::down_released() + bn::keypad::left_released() + bn::keypad::right_released() > 0)
			{
				if (bn::keypad::down_held())
				{
					dir = 0;
				}
				else if (bn::keypad::right_held())
				{
					dir = 1;
				}
				else if (bn::keypad::left_held())
				{
					dir = 2;
				}
				else if (bn::keypad::up_held())
				{
					dir = 3;
				}
			}
			else
			{
				if (bn::keypad::down_held())
				{
					dir = 0;
				}
				else if (bn::keypad::right_held())
				{
					dir = 1;
				}
				else if (bn::keypad::left_held())
				{
					dir = 2;
				}
				else if (bn::keypad::up_held())
				{
					dir = 3;
				}
			}

			// Move
			if ((bn::keypad::down_held() || bn::keypad::up_held() || bn::keypad::left_held() || bn::keypad::right_held()) || (entity_anim.current_index() % 2 == 1))
			{
				if (event)
					done = false;
				entity_anim.update();
			}

			// Manage the previously handled value
			if (last_dir != dir)
			{
				done = false;
				last_dir = dir;
			}

			// Control directional animation
			if (!done)
			{
				switch (dir)
				{
				case 1:
					entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 4, 3, 5, 3);
					break;
				case 2:
					entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 7, 6, 8, 6);
					break;
				case 3:
					entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 10, 9, 11, 9);
					break;
				default:
					entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 1, 00, 2, 0);
					break;
				}
				done = true;
			}

			int delta_x = 0;
			int delta_y = 0;

			// Key controls
			if (bn::keypad::left_held())
			{
				delta_x += (-1 * canLeft);
				if (!canLeft) delta_y += newDown - newUp;
			}
			if (bn::keypad::right_held())
			{
				delta_x += (1 * canRite);
				if (!canRite) delta_y += newLeft - newRite;
			}
			if (bn::keypad::up_held())
			{
				delta_y += (-1 * canUp);
				if (!canUp) delta_x += newDown - newLeft;
			}
			if (bn::keypad::down_held())
			{
				delta_y += (1 * canDn);
				if (!canDn) delta_x += newUp - newRite;
			}
			if (delta_x > 1) delta_x = 1;
			if (delta_x < -1) delta_x = -1;
			if (delta_y > 1) delta_y = 1;
			if (delta_y < -1) delta_y = -1;

			x_int += delta_x;
			y_int += delta_y;
		}

		// If generic dude....
		else if (role == 2)
		{

			if (abs(entity.x() - x) + abs(entity.y() - y) < 64)
			{
				if (x < entity.x() - 24)
				{
					entity_anim = bn::create_sprite_animate_action_forever(entity, 4, entity_item.tiles_item(), 6, 6, 6, 6);
				}
				else if (x > entity.x() + 24)
				{
					entity_anim = bn::create_sprite_animate_action_forever(entity, 4, entity_item.tiles_item(), 3, 3, 3, 3);
				}
				if (y < entity.y() - 24)
				{
					entity_anim = bn::create_sprite_animate_action_forever(entity, 4, entity_item.tiles_item(), 9, 9, 9, 9);
				}
				else if (y > entity.y() + 24)
				{
					entity_anim = bn::create_sprite_animate_action_forever(entity, 4, entity_item.tiles_item(), 00, 00, 00, 0);
				}
				entity_anim.update();
			}
		}

		if (event)
		{
			event = false;
			switch (dir)
			{
			case 0:
				entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 12, 12, 12, 12);
				break;
			case 1:
				entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 13, 13, 13, 13);
				break;
			case 2:
				entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 14, 14, 14, 14);
				break;
			default:
				entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 15, 15, 15, 15);
				break;
			}
			entity_anim.update();
			done = false;
		}

		// Handle update
		int canHorz = 0;
		int canVert = 0;

		if (!canLeft && !canRite) {
			x_int = last_x;
			canHorz = 1;
		}

		if (!canUp && !canDn) {
			y_int = last_y;
			canVert = 1;
		}

		close[0] = roundDown(x_int + 6);
		close[1] = roundUp(x_int - 6);
		close[2] = roundDown(y_int + 6) * room_width;
		close[3] = roundUp(y_int) * room_width;

		if (globals->collisions.size() > 0) {
			col[0] = globals->collisions.at(close[0] + close[2]) == 1;
			col[1] = globals->collisions.at(close[0] + close[3]) == 1;
			col[2] = globals->collisions.at(close[1] + close[2]) == 1;
			col[3] = globals->collisions.at(close[1] + close[3]) == 1;
			col[4] = globals->collisions.at(close[0] + close[2]) == 1;
			col[5] = globals->collisions.at(close[1] + close[2]) == 1;
			col[6] = globals->collisions.at(close[0] + close[3]) == 1;
			col[7] = globals->collisions.at(close[1] + close[3]) == 1;

			canLeft = !(((col[4] & col[5]) ^ col[0]) || ((col[6] & col[7]) ^ col[1]));
			canRite = !(((col[4] & col[5]) ^ col[2]) || ((col[6] & col[7]) ^ col[3]));
			canUp = !(((col[0] & col[1]) ^ col[4]) || ((col[2] & col[3]) ^ col[5]));
			canDn = !(((col[0] & col[1]) ^ col[6]) || ((col[2] & col[3]) ^ col[7]));
		}

		if (!canLeft && !canRite) {
			x_int = last_x;
		}

		if (!canUp && !canDn) {
			y_int = last_y;
		}
		entity.set_position(x_int, y_int);
		entity = entity_anim.sprite();

		if (canLeft || canRite) {
			last_x = x_int;
		}

		if (canUp || canDn) {
			last_y = y_int;
		}

	}
};

// Animated objects
class anim_object
{
public:
	short int id = 0;
	short int ticker = 0;
	bn::sprite_item entity_item = bn::sprite_items::aaron_sleep;
	bn::sprite_ptr entity = entity_item.create_sprite(0, 0);
	bn::sprite_animate_action<4> entity_anim = bn::create_sprite_animate_action_forever(entity, 18, entity_item.tiles_item(), 00, 00, 00, 1);

	void update() {
		entity_anim.update();
		entity = entity_anim.sprite();
		entity.set_z_order(1);
	}
};

// Bats and flying bits
class creepy_crawly
{
public:
	bn::sprite_ptr sprite = bn::sprite_items::cave_bat.create_sprite(0, 0);
	bn::sprite_animate_action<4> sprite_anim = bn::create_sprite_animate_action_forever(sprite, 1, bn::sprite_items::cave_bat.tiles_item(), 0, 1, 0, 1);
	bool moving = true;
	bool carry = false;
	short int spend = 0;
	short int dir = 0;
	short int vector_x = 1;
	short int vector_y = 1;
	short int to_x = 0;
	short int to_y = 0;
	short int init_y = 0;
	bool enabled = true;
	short int room_width = 20;

	creepy_crawly() {}

	void update()
	{
		short int flap = std_rnd(2);
		if (flap == 0)
		{
			sprite_anim.update();
			sprite = sprite_anim.sprite();
		}

		short int mx = sprite.x().integer() / 32;
		short int my = sprite.y().integer() / 32;

		if (mx == to_x && my == to_y)
		{
			to_x = 0;
			to_y = 0;
		}

		if (to_x == 0 && to_y == 0)
		{
			to_x = std_rnd(room_width);
			to_y = std_rnd(room_width);
		}
		else
		{
			if (mx < to_x)
			{
				vector_x = 1;
			}
			else if (mx > to_x)
			{
				vector_x = -1;
			}
			if (my < to_y)
			{
				vector_y = 1;
			}
			else if (my > to_y)
			{
				vector_y = -1;
			}
		}
		sprite.set_position(sprite.x().integer() + (vector_x), sprite.y().integer() + (vector_y));
	}
};

class moving_block
{
public:
	bn::sprite_ptr entity = bn::sprite_items::underground_tiles.create_sprite(0, 0, 15);
	bool is_moving = true;
	short int moving_x = 0;
	short int moving_y = 0;
	moving_block() {};
};

class gem
{
public:
	bn::sprite_ptr entity = bn::sprite_items::underground_tiles.create_sprite(0, 0, 1);
};

class xy
{
public:
	short int x = 0;
	short int y = 0;
};

class button
{
public:
	bool toggled = false;
	bool short_toggle = false;
	short int x = 0;
	short int y = 0;
};

class gate
{
public:
	short int triggered_by = 0;
	short int x = 0;
	short int y = 0;
};

// Pop-Up Instruction
void popup(int scene) {

	// Check to see if you've seen it before
	if (!globals->current_save->popups[scene]) {
		bn::core::update();
		globals->current_save->popups[scene] = true;
		bn::sprite_text_generator text_line(common::variable_8x16_sprite_font);
		bn::regular_bg_ptr background = bn::regular_bg_items::fun_background.create_bg(0, 0);
		bn::sprite_ptr a_button = bn::sprite_items::a_button.create_sprite(-80, -48);

		int my_chari = globals->current_save->last_char_id;
		if (my_chari < 0 || my_chari > 7) my_chari = 0;

		auto dg_bg1 = bn::sprite_items::dialogue_bg_2.create_sprite(-64, 0);
		auto dg_bg2 = bn::sprite_items::dialogue_bg_2.create_sprite(64, 0);
		dg_bg1.set_scale(2, 0.01);
		dg_bg2.set_scale(2, 0.01);
		dg_bg1.set_blending_enabled(true);
		dg_bg2.set_blending_enabled(true);
		bn::music_items_info::span[4].first.play(bn::fixed(50) / 100);

		char text[192] = { 0 };

		switch (scene) {
		case 0: {
			char txt1[192] = "Vous trouverez des choses autour de l'ile pour construire votre   compte Trembloon. Si vous obtenez100, vous pouvez passer au       chapitre suivant! Bonne chance!";
			strncpy(text, txt1, 192);
			break;
		}
		case 1: {
			char txt1[192] = "Essayez d'attraper tous les      lapins et de les jeter hors du   jardin des que possible.         Ramassez-les et jetez-les avec lebouton A. Bonne chance!";
			strncpy(text, txt1, 192);
			my_chari = 1;
			break;
		}
		case 2: {
			char txt1[192] = "Essayez de trouver la gemme et   evitez les chauves-souris. Si    vous etes touche, la gemme se    deplace vers un nouvel endroit.  Bonne chance!";
			strncpy(text, txt1, 192);
			my_chari = 0;
			break;
		}
		case 3: {
			char txt1[192] = "Utilisez le bouton A pour couper les chevilles en bois. Assurez-  vous de ne pas sortir de la ligneou d'en manquer, sinon vous      perdrez des points! Bonne chance!";
			strncpy(text, txt1, 192);
			my_chari = 2;
			break;
		}
		case 4: {
			char txt1[192] = "Il y a de nouveaux villageois au nord-ouest! Il existe de         nouvelles facons de gagner des   Trembloons.                      Bonne chance!";
			strncpy(text, txt1, 192);
			break;
		}
		case 5: {
			char txt1[192] = "Essayez d'obtenir la plus grande sequence de combinaisons de      boutons d'affilee et vous pourrezinvoquer un objet comme par      magie. Bonne chance!";
			strncpy(text, txt1, 192);
			my_chari = 5;
			break;
		}
		case 6: {
			char txt1[192] = "Pilotez le bateau pour eviter lesrochers ! Utilisez haut pour     accelerer, gauche et droite pour diriger et bas pour arreter le   bateau. Bonne chance!";
			strncpy(text, txt1, 192);
			my_chari = 6;
			break;
		}
		case 7: {
			char txt1[192] = "N'oubliez pas d'appuyer sur R si vous avez besoin de jeter un coupd'oeil au livre de cuisine.                                       Bonne chance!";
			strncpy(text, txt1, 192);
			my_chari = 7;
			break;
		}
		default: {}
		}

		// Profile picture
		auto prof_pic = bn::sprite_items::save_tiles.create_sprite(0, 32, my_chari);

		// Fresh init
		bn::vector<bn::sprite_ptr, 32> text_sprite0;
		bn::vector<bn::sprite_ptr, 32> text_sprite2;
		bn::vector<bn::sprite_ptr, 32> text_sprite3;
		bn::vector<bn::sprite_ptr, 32> text_sprite4;
		bn::vector<bn::sprite_ptr, 32> text_sprite5;
		char line1[42] = { 0 };
		char line3[42] = { 0 };
		char line4[42] = { 0 };
		char line5[42] = { 0 };
		char line6[42] = { 0 };

		for (short int t = 0; t < 33; t++) { line1[t] = text[t]; };
		for (short int t = 0; t < 33; t++) { line3[t] = text[t + 33]; };
		for (short int t = 0; t < 33; t++) { line4[t] = text[t + 66]; };
		for (short int t = 0; t < 33; t++) { line5[t] = text[t + 99]; };
		for (short int t = 0; t < 32; t++) { line6[t] = text[t + 132]; };

		text_line.generate(-108, 21 - 64, line1, text_sprite0);
		for (short int t = 0; t < text_sprite0.size(); t++) { text_sprite0.at(t).set_visible(false); }

		text_line.generate(-108, 33 - 64, line3, text_sprite2);
		for (short int t = 0; t < text_sprite2.size(); t++) { text_sprite2.at(t).set_visible(false); }

		text_line.generate(-108, 45 - 64, line4, text_sprite3);
		for (short int t = 0; t < text_sprite3.size(); t++) { text_sprite3.at(t).set_visible(false); }

		text_line.generate(-108, 57 - 64, line5, text_sprite4);
		for (short int t = 0; t < text_sprite4.size(); t++) { text_sprite4.at(t).set_visible(false); }

		text_line.generate(-108, 69 - 64, line6, text_sprite5);
		for (short int t = 0; t < text_sprite5.size(); t++) { text_sprite5.at(t).set_visible(false); }

		// Process visual effects
		short int ticker = 0;
		short int ticker_delay = 0;

		while (!bn::keypad::a_pressed()) {
			background.set_position((background.x().integer() + 1) % 256, (background.y().integer() + 1) % 256);

			bn::fixed_t<12> new_level = dg_bg1.vertical_scale() + 0.05;
			if (new_level > 2) new_level = 2;
			dg_bg1.set_vertical_scale(new_level);
			dg_bg2.set_vertical_scale(new_level);
			prof_pic.set_scale(new_level / 2, new_level / 2);

			// Handle text ticker
			if (ticker < 160) {
				if (ticker_delay == 0) {
					short int ticked = ticker % 32;
					if (ticker >= 0 && ticker < 32) {
						if (text_sprite0.size() > ticked) {
							text_sprite0.at(ticked).set_visible(true);
							bn::sound_items::click.play();
						}
						else {
							ticker = 31;
						}
					}
					if (ticker >= 32 && ticker < 64) {
						if (text_sprite2.size() > ticked) {
							text_sprite2.at(ticked).set_visible(true);
							bn::sound_items::click.play();
						}
						else {
							ticker = 63;
						}
					}
					if (ticker >= 64 && ticker < 96) {
						if (text_sprite3.size() > ticked) {
							text_sprite3.at(ticked).set_visible(true);
							bn::sound_items::click.play();
						}
						else {
							ticker = 95;
						}
					}
					if (ticker >= 96 && ticker < 128) {
						if (text_sprite4.size() > ticked) {
							text_sprite4.at(ticked).set_visible(true);
							bn::sound_items::click.play();
						}
						else {
							ticker = 127;
						}
					}
					if (ticker >= 128 && ticker < 160) {
						if (text_sprite5.size() > ticked) {
							text_sprite5.at(ticked).set_visible(true);
							bn::sound_items::click.play();
						}
						else {
							ticker = 160;
						}
					}
					ticker++;
				}
				ticker_delay = (ticker_delay + 1) % 2;
			}

			prof_pic.put_above();
			a_button.put_above();
			bn::core::update();
		}
	}

	bn::core::update();
}

// Score HUD
class hud {
public:
	bn::sprite_ptr orb = bn::sprite_items::score.create_sprite(0, -90, 0);
	bn::sprite_ptr l_wing = bn::sprite_items::score.create_sprite(-48, -90, 1);
	bn::sprite_ptr r_wing = bn::sprite_items::score.create_sprite(48, -90, 1);
	bn::sprite_ptr l_wing_2 = bn::sprite_items::score.create_sprite(-32, -90, 2);
	bn::sprite_ptr r_wing_2 = bn::sprite_items::score.create_sprite(32, -90, 2);
	bn::vector<bn::sprite_ptr, 8> text_sprite0;
	bn::fixed_t<12> wing_scale = 1.25;
	short int score = 0;
	short int rotation = 0;

	hud() {
		r_wing.set_horizontal_flip(true);
		r_wing_2.set_horizontal_flip(true);
		l_wing_2.put_above();
		r_wing_2.put_above();
		orb.put_above();

		l_wing_2.set_scale(wing_scale, 0.01);
		r_wing_2.set_scale(wing_scale, 0.01);
	}

	void update(bn::fixed_t<12> new_value, int new_score) {
		bn::sprite_text_generator text_line(common::variable_8x16_sprite_font);
		score = new_score;
		wing_scale = new_value;
		if (wing_scale < 0.01) wing_scale = 0.01;
		if (wing_scale > 2) wing_scale = 2;

		rotation = (rotation + 1) % 360;

		short int q = -3;
		if (new_score > 9) q = -5;
		if (new_score > 99) q = -8;

		text_sprite0.clear();
		bn::string<8> txt_score = bn::to_string<8>(score);
		text_line.generate(q, -72, txt_score, text_sprite0);

		l_wing_2.set_scale(wing_scale, 1);
		r_wing_2.set_scale(wing_scale, 1);

		l_wing.put_above();
		r_wing.put_above();
		l_wing_2.put_above();
		r_wing_2.put_above();
		orb.put_above();

		for (int t = 0; t < text_sprite0.size(); t++) {
			text_sprite0.at(t).put_above();
		}
	}
};

// Victory object
class victory {
public:
	bn::vector<bn::sprite_ptr, 4> file1_spr;
	bn::vector<bn::sprite_ptr, 4> file2_spr;
	bn::sprite_ptr bg = bn::sprite_items::awards.create_sprite(80, -8, 0);
	bn::sprite_ptr tg = bn::sprite_items::awards.create_sprite(80, -40, 1);
	bn::sprite_ptr award = bn::sprite_items::awards.create_sprite(80, 24, 2);
	bn::sprite_ptr letter = bn::sprite_items::awards.create_sprite(80, 24, 3);
	bn::sprite_ptr a_button = bn::sprite_items::a_button.create_sprite(-80, -48);

#define mo_x 32
#define mo_y 64

	bn::sprite_ptr b_m1 = bn::sprite_items::power_meter.create_sprite(32 + mo_x, mo_y, 1);
	bn::sprite_ptr b_m2 = bn::sprite_items::power_meter.create_sprite(64 + mo_x, mo_y, 1);
	bn::sprite_ptr b_l = bn::sprite_items::power_meter.create_sprite(16 + mo_x, mo_y, 0);
	bn::sprite_ptr b_r = bn::sprite_items::power_meter.create_sprite(80 + mo_x, mo_y, 2);
	bn::sprite_ptr b_a = bn::sprite_items::power_meter.create_sprite(16 + mo_x, mo_y, 3);

	short int stage = 0;
	short int xp_render = 0;
	short int chari = 0;
	short int level = 0;
	short int music_counter = 0;
	short int chapter = 0;
	short int chap_go = 16 + mo_x;
	short int score = 0;
	short int xp = 0;

	victory(int l = 0, int charis = 0, int scores = 50, int xps = 250, int chap = 3) {
		letter = bn::sprite_items::awards.create_sprite(80, 24, l + 3);
		level = l;
		chapter = chap;
		score = scores;
		xp = xps;
		chari = charis;

		chap_go += ((xp / chapter) * 0.64);

		tg.set_visible(false);
		award.set_visible(false);
		letter.set_visible(false);

		award.set_scale(2, 2);
		letter.set_scale(2, 2);

		b_m1.set_scale(4, 1);
		b_m2.set_scale(4, 1);

		bn::music_items_info::span[13].first.play(bn::fixed(50) / 100);
	}

	void update() {
		bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);

		//b_a.set_x(new_lc + 32);

		if (b_a.x().integer() < chap_go) b_a.set_x(b_a.x() + 1);

		if (music_counter < 224) {
			music_counter++;
		}
		else if (music_counter == 224) {
			bn::music_items_info::span[16].first.play(bn::fixed(50) / 100);
			music_counter++;
		}

		switch (stage) {
		case 0: {
			bn::fixed_t<12> hs = bg.vertical_scale();
			if (hs < 1.9) {
				hs += 0.1;
				if (hs > 1.9) {
					stage = 1;
					hs = 2;
				}
				bg.set_vertical_scale(hs);
			}
			break;
		}
		case 1: {
			if (xp_render < xp) {
				xp_render += 3;
				if (xp_render > xp) xp_render = xp;
				bn::sound_items::click.play();
			}
			else {
				stage = 2;
			}

			tg.set_visible(true);
			file1_spr.clear();
			file2_spr.clear();
			file1_gen.generate(80 - 8, -48, bn::to_string<4>(score), file1_spr);
			file1_gen.generate(80 - 8, -18, bn::to_string<4>(xp_render), file2_spr);
			break;
		}
		case 2: {
			award.set_visible(true);
			letter.set_visible(true);

			bn::fixed_t<12> a = award.horizontal_scale();
			if (a > 1) {
				a -= 0.1;
			}
			else {
				a = 1;
				stage = 3;
				bn::sound_items::firehit.play();

				switch (chari) {
				case 0: {
					bn::sound_items::fireblast.play();
					if (level < 3) bn::sound_items::maple_alright_02.play();
					else bn::sound_items::maple_ugh_01.play();
					break;
				}
				case 1: {
					if (level < 3) bn::sound_items::enoki_hey.play();
					else bn::sound_items::enoki_aw.play();
					break;
				}
				case 2: {
					if (level < 3) bn::sound_items::aaron_yeah_02.play();
					else bn::sound_items::aaron_ugh_07.play();
					break;
				}
				default: {
					break;
				}
				}
			}
			award.set_scale(a, a);
			letter.set_scale(a, a);
			break;
		}
		case 3: {
			break;
		}
		default: {}
		}
	}
};

// Room setup object
class room
{
public:
	short int last_camera_x = 0;
	short int last_camera_y = 0;

	unsigned short int width = 29;
	unsigned short int height = 14;
	unsigned short int start_x = 8;
	unsigned short int start_y = 3;
	unsigned short int anim_ticker = 0;
	unsigned char anim_ticker_ticker = 0;
	const bn::sprite_item* environment = &bn::sprite_items::environment_stone;

	short int follow_x = 0;
	short int follow_y = 0;
	unsigned short int follow_id = 0;

	// Cam + characters
	bn::camera_ptr camera = bn::camera_ptr::create(0, 0);
	bn::vector<character, 7> chari;
	bn::vector<anim_object, 2> anim_objects;

	// Tiled environmentupda
	bn::vector<bn::sprite_ptr, 94> tile_hop;
	bn::vector<unsigned char, 94> ref_hop;

	// Misc environment
	bn::regular_bg_ptr primary_bg = bn::regular_bg_items::velvet.create_bg(0, 0);
	bn::sprite_ptr a_notif = bn::sprite_items::a_button_2.create_sprite(0, 0);

	// Make a fireball!
	unsigned short int p_index = 0;
	bn::vector<projectile, 3> p;

	room(short int w, short int h, short int x, short int y) {
		width = w;
		height = h;
		start_x = x;
		start_y = y;

		chari.clear();
		primary_bg.set_camera(camera);
	}

	void configure(short int w, short int h, short int x, short int y) {
		width = w;
		height = h;
		start_x = x;
		start_y = y;
	}

	void place(int x, int y) {
		short int z = x + (y * width);
		if (z < globals->local_tileset.size() && z > -1) {
			if (globals->local_tileset.at(z) > 0 && globals->local_tileset.at(z) < 64) {
				bn::sprite_ptr s = environment->create_sprite(x * 32, y * 32, globals->local_tileset.at(z) - 1);
				s.set_camera(camera);

				// Set Palette
				if (environment == &bn::sprite_items::ocean_terrain && globals->current_save->checkpoint == 5) {
					s.set_palette(bn::sprite_items::underground_tiles.palette_item());
				}

				// Set Z order
				if (environment == &bn::sprite_items::ocean_terrain && globals->local_tileset.at(z) == 1) {
					s.set_z_order(1);
				}
				else if (environment == &bn::sprite_items::pools_tiles && globals->local_tileset.at(z) == 1) {
					s.set_z_order(1);
				}
				else {
					s.set_z_order(296);
				}
				if (tile_hop.size() < 88) tile_hop.push_back(s);
				if (ref_hop.size() < 88) ref_hop.push_back(globals->local_tileset.at(z) - 1);
			}
		}
	}

	void fix_camera() {
		if (camera.x().integer() < (3 * 32) + 16) camera.set_x((3 * 32) + 16);
		if (camera.x().integer() > (width * 32) - (5 * 32) + 16) camera.set_x((width * 32) - (5 * 32) + 16);
		if (camera.y().integer() < (2 * 32) + 16) camera.set_y((2 * 32) + 16);
		if (camera.y().integer() > (height * 32) - (4 * 32) + 16) camera.set_y((height * 32) - (4 * 32) + 16);
	}

	void init_render(int p_x = 0, int p_y = 0) {
		for (unsigned short int t = 0; t < chari.size(); t++) {
			chari.at(t).room_width = width;
		}

		short int f_x = p_x - 5;
		short int t_x = p_x + 6;
		short int f_y = p_y - 3;
		short int t_y = p_y + 5;
		if (f_x < 0) f_x = 0;
		if (t_x > width) t_x = width;
		if (f_y < 0) f_y = 0;
		if (t_y > height) t_y = height;
		for (int y2 = f_y; y2 < t_y; y2++) {
			for (int x2 = f_x; x2 < t_x; x2++) {
				place(x2, y2);
			}
		}

		// Handle camera work initially
		last_camera_x = camera.x().integer() / 32;
		last_camera_y = camera.y().integer() / 32;
		fix_camera();

		// Handle active character
		for (unsigned short int t = 0; t < chari.size(); t++) {
			if (chari.at(t).identity == globals->current_save->last_char_id) {
				follow_id = t;
				break;
			}
		}
	}

	void start_notif(unsigned short int type = 0) {
		if (type == 0) {
			a_notif = bn::sprite_items::a_button_2.create_sprite(follow_x, follow_y - 28, 0);
		}
		else if (type == 1) {
			a_notif = bn::sprite_items::l_button.create_sprite(follow_x, follow_y - 28, 0);
		}

		a_notif.set_camera(camera);
		a_notif.set_z_order(0);
		a_notif.set_visible(true);
	}

	void refresh_tiles(bn::fixed_t<12> x, bn::fixed_t<12> y) {
		tile_hop.clear();
		ref_hop.clear();
		short int p_x = x.integer();
		short int p_y = y.integer();

		short int f_x = p_x - 5;
		short int t_x = p_x + 6;
		short int f_y = p_y - 3;
		short int t_y = p_y + 5;
		if (f_x < 0) f_x = 0;
		if (t_x > width) t_x = width;
		if (f_y < 0) f_y = 0;
		if (t_y > height) t_y = height;
		for (int y2 = f_y; y2 < t_y; y2++) {
			for (int x2 = f_x; x2 < t_x; x2++) {
				place(x2, y2);
			}
		}

		// Update ocean tiles
		if (environment == &bn::sprite_items::ocean_terrain) {
			for (int t = 0; t < ref_hop.size(); t++) {
				if (ref_hop.at(t) == 25) {
					tile_hop.at(t).set_mosaic_enabled(true);
				}
			}
		}
	}

	void update_objects() {

		// Set up animation bit
		anim_ticker_ticker++;
		if (anim_ticker_ticker == 8) {

			anim_ticker_ticker = 0;
			anim_ticker++;
		}

		camera.set_position(chari.at(follow_id).entity.x(), chari.at(follow_id).entity.y());
		fix_camera();

		//bn::fixed_t<12> sin_v = abs(sin(anim_ticker / 3));
		//bn::sprites_mosaic::set_horizontal_stretch(sin_v);

		// set current_room.camera follow point
		follow_x = chari.at(follow_id).entity.x().integer();
		follow_y = chari.at(follow_id).entity.y().integer();

		unsigned short int cam_x = (camera.x().integer() + 16) / 32;
		unsigned short int cam_y = (camera.y().integer()) / 32;

		if (cam_x != last_camera_x || cam_y != last_camera_y) {
			last_camera_x = cam_x;
			last_camera_y = cam_y;
			refresh_tiles(cam_x, cam_y);
		}

		// Pause
		if (bn::keypad::start_pressed())
		{
			bn::core::update();
			bn::music::pause();
			bn::sound_items::cnaut.play();
			while (!bn::keypad::start_pressed())
			{
				bn::core::update();
			}
			bn::music::resume();
			bn::sound_items::pop.play();
		}

		// Create projectiles
		if (bn::keypad::r_pressed())
		{
			chari.at(follow_id).event = true;
			if (chari.at(follow_id).identity == 0)
			{
				bn::sound_items::fireblast.play();
				if (p.size() > 2) p.erase(p.begin());
				projectile new_p;
				new_p.active = true;
				new_p.fireball.set_camera(camera);
				new_p.fireball.set_x(follow_x);
				new_p.fireball.set_y(follow_y);
				new_p.dir = chari.at(follow_id).dir;
				new_p.dur = 0;
				p.push_back(new_p);
			}
			else if (chari.at(follow_id).identity == 4)
			{
				bn::sound_items::firecrackle.play();

				if (globals->current_save->checkpoint == 8 && globals->current_save->xp < 201)
				{
					globals->current_save->xp++;
				}
				else if (globals->current_save->checkpoint == 10 && globals->current_save->xp < 301)
				{
					globals->current_save->xp++;
				}
			}
			else
			{
				bn::sound_items::squeak.play();
			}
		}

		// Update projectiles
		for (short int t = 0; t < p.size(); t++)
		{
			if (p.at(t).active)
			{
				p.at(t).fireball.set_z_order(1);
				p.at(t).update();
			}
			else {
				p.erase(p.begin() + t);
			}
		}

		// Swap characters
		if (bn::keypad::b_pressed())
		{
			bn::sound_items::cnaut.play();
			bn::blending::set_intensity_alpha(1);
			short int new_chari = (follow_id + 1) % chari.size();

			chari.at(follow_id).entity.set_blending_enabled(false);
			for (short int t = 0; t < chari.size(); t++) {
				if (t != new_chari) {
					if (chari.at(t).can_follow) chari.at(t).role = 0;
					else chari.at(t).role = 2;
				}
			}

			chari.at(new_chari).entity.set_blending_enabled(true);
			chari.at(new_chari).role = 1;
			globals->current_save->last_char_id = chari.at(new_chari).identity;
			follow_id = new_chari;
		}

		// Character operations
		for (unsigned short int t = 0; t < chari.size(); t++)
		{
			// Set primary camera following X/Y coordinates
			chari.at(t).entity.set_z_order(200 - (chari.at(t).entity.y().integer() - camera.y().integer()));
			chari.at(t).entity.set_camera(camera);

			if (chari.at(t).role == 1)
			{
				chari.at(t).update();
			}
			else if (chari.at(t).role == 0)
			{
				short int my_follow_at = chari.at(t).follow_id;
				if (my_follow_at == -1) my_follow_at = (t + 1) % chari.size();
				chari.at(t).update(chari.at(my_follow_at).entity.x().integer(), chari.at(my_follow_at).entity.y().integer());
			}
		}
	}
};

class xp_hud {
public:
	bn::sprite_ptr l_side = bn::sprite_items::power_meter.create_sprite(76, 96, 0);
	bn::sprite_ptr m_side = bn::sprite_items::power_meter.create_sprite(92, 96, 1);
	bn::sprite_ptr r_side = bn::sprite_items::power_meter.create_sprite(108, 96, 2);
	bn::sprite_ptr pointer = bn::sprite_items::power_meter.create_sprite(76, 96, 3);
	int x_to = 76;
	int chap = 4;

	xp_hud() {

	}

	void update() {

		// Set up chapter
		if (globals->current_save->checkpoint < 15) {
			chap = 3;
			if (globals->current_save->xp > 300) globals->current_save->xp = 300;
		}
		if (globals->current_save->checkpoint < 9) {
			chap = 2;
			if (globals->current_save->xp > 200) globals->current_save->xp = 200;
		}
		if (globals->current_save->checkpoint < 6) {
			chap = 1;
			if (globals->current_save->xp > 100) globals->current_save->xp = 100;
		}
		if (globals->current_save->checkpoint == 0) {
			chap = 1;
			if (globals->current_save->xp > 50) globals->current_save->xp = 50;
		}
		x_to = 76 + (globals->current_save->xp / chap) * 0.32;

		// Configure X position
		if (x_to > pointer.x()) {
			pointer.set_x(pointer.x() + 1);
		}
		else if (x_to < pointer.x()) {
			pointer.set_x(x_to);
		}

		if (69 < pointer.y()) {
			l_side.set_y(lerp(pointer.y(), 69, 0.3));
			m_side.set_y(lerp(pointer.y(), 69, 0.3));
			r_side.set_y(lerp(pointer.y(), 69, 0.3));
			pointer.set_y(lerp(pointer.y(), 69, 0.3));
		}
	}

	void acknowledge() {
		bn::sound_items::pop.play();
	}
};

dungeon_return dungeon(dungeon_return& dt) {

	// Prep memory
	globals->local_tileset.clear();
	globals->collisions.clear();
	globals->rendered_windows.clear();

	if (globals->current_save->checkpoint > 1)
	{
		if (bn::music::playing())
			bn::music::stop();
	}

	// Constants
	room current_room(0, 0, dt.spawn_x, dt.spawn_y);

	// current_room.camera setup
	short int sx = current_room.start_x * 32;
	short int sy = current_room.start_y * 32;

	current_room.camera.set_position(sx, sy);
	bn::vector<anim_object, 3> anim_objects;

	// Create initial characters
	switch (globals->current_save->last_char_id)
	{
	default:
	{
		if (dt.world_index < 4)
		{
			character default_chari(bn::sprite_items::maple_walking, current_room.start_x, current_room.start_y, false, current_room.width);
			default_chari.entity.set_camera(current_room.camera);
			default_chari.entity.set_position(sx, sy);
			default_chari.role = 1;
			default_chari.identity = 0;
			current_room.chari.push_back(default_chari);
			break;
		}
		else if (globals->current_save->checkpoint < 12)
		{
			character default_chari(bn::sprite_items::maple_walking_spring, current_room.start_x, current_room.start_y, current_room.width);
			default_chari.entity.set_camera(current_room.camera);
			default_chari.entity.set_position(sx, sy);
			default_chari.role = 1;
			default_chari.identity = 0;
			current_room.chari.push_back(default_chari);
			break;
		}
		else
		{
			character default_chari(bn::sprite_items::maple_walking_oo, current_room.start_x, current_room.start_y, false, current_room.width);
			default_chari.entity.set_camera(current_room.camera);
			default_chari.entity.set_position(sx, sy);
			default_chari.role = 1;
			default_chari.identity = 0;
			current_room.chari.push_back(default_chari);
			break;
		}
	}
	case 0:
	{
		if (dt.world_index < 4)
		{
			character default_chari(bn::sprite_items::maple_walking, current_room.start_x, current_room.start_y, false, current_room.width);
			default_chari.entity.set_camera(current_room.camera);
			default_chari.entity.set_position(sx, sy);
			default_chari.role = 1;
			default_chari.identity = 0;
			current_room.chari.push_back(default_chari);
			break;
		}
		else if (dt.world_index < 15)
		{
			if (globals->current_save->checkpoint < 12)
			{
				character default_chari(bn::sprite_items::maple_walking_spring, current_room.start_x, current_room.start_y, current_room.width);
				default_chari.entity.set_camera(current_room.camera);
				default_chari.entity.set_position(sx, sy);
				default_chari.role = 1;
				default_chari.identity = 0;
				current_room.chari.push_back(default_chari);
				break;
			}
			else
			{
				character default_chari(bn::sprite_items::maple_walking_oo, current_room.start_x, current_room.start_y, false, current_room.width);
				default_chari.entity.set_camera(current_room.camera);
				default_chari.entity.set_position(sx, sy);
				default_chari.role = 1;
				default_chari.identity = 0;
				current_room.chari.push_back(default_chari);
				break;
			}
		}
		else
		{
			character default_chari(bn::sprite_items::maple_walking_oo, current_room.start_x, current_room.start_y, false, current_room.width);
			default_chari.entity.set_camera(current_room.camera);
			default_chari.entity.set_position(sx, sy);
			default_chari.role = 1;
			default_chari.identity = 0;
			current_room.chari.push_back(default_chari);
			break;
		}
	}
	case 1:
	{
		if (globals->current_save->checkpoint < 1)
		{
			character default_chari(bn::sprite_items::enoki_walking_pj, current_room.start_x, current_room.start_y, false, current_room.width);
			default_chari.entity.set_camera(current_room.camera);
			default_chari.entity.set_position(sx, sy);
			default_chari.role = 1;
			default_chari.identity = 1;
			current_room.chari.push_back(default_chari);
			break;
		}
		else if (globals->current_save->checkpoint < 12)
		{
			character default_chari(bn::sprite_items::enoki_walking_spring, current_room.start_x, current_room.start_y, false, current_room.width);
			default_chari.entity.set_camera(current_room.camera);
			default_chari.entity.set_position(sx, sy);
			default_chari.role = 1;
			default_chari.identity = 1;
			current_room.chari.push_back(default_chari);
			break;
		}
		else
		{
			character default_chari(bn::sprite_items::enoki_walking_spring, current_room.start_x, current_room.start_y, false, current_room.width);
			default_chari.entity.set_camera(current_room.camera);
			default_chari.entity.set_position(sx, sy);
			default_chari.role = 1;
			default_chari.identity = 1;
			current_room.chari.push_back(default_chari);
			break;
		}
	}
	case 2:
	{
		character default_chari(bn::sprite_items::aaron_walking_spring, current_room.start_x, current_room.start_y, false, current_room.width);
		default_chari.entity.set_camera(current_room.camera);
		default_chari.entity.set_position(sx, sy);
		default_chari.role = 1;
		default_chari.identity = 2;
		current_room.chari.push_back(default_chari);
		break;
	}
	case 3:
	{
		character default_chari(bn::sprite_items::scout_walking_spring, current_room.start_x, current_room.start_y, false, current_room.width);
		default_chari.entity.set_camera(current_room.camera);
		default_chari.entity.set_position(sx, sy);
		default_chari.role = 1;
		default_chari.identity = 3;
		current_room.chari.push_back(default_chari);
		break;
	}
	case 4:
	{
		character default_chari(bn::sprite_items::vee_walking_spring, current_room.start_x, current_room.start_y, false, current_room.width);
		default_chari.entity.set_camera(current_room.camera);
		default_chari.entity.set_position(sx, sy);
		default_chari.role = 1;
		default_chari.identity = 4;
		current_room.chari.push_back(default_chari);
		break;
	}
	case 5:
	{
		character default_chari(bn::sprite_items::eleanor_walking_spring, current_room.start_x, current_room.start_y, false, current_room.width);
		default_chari.entity.set_camera(current_room.camera);
		default_chari.entity.set_position(sx, sy);
		default_chari.role = 1;
		default_chari.identity = 5;
		current_room.chari.push_back(default_chari);
		break;
	}
	case 6:
	{
		character default_chari(bn::sprite_items::diana_walking_spring, current_room.start_x, current_room.start_y, false, current_room.width);
		default_chari.entity.set_camera(current_room.camera);
		default_chari.entity.set_position(sx, sy);
		default_chari.role = 1;
		default_chari.identity = 6;
		current_room.chari.push_back(default_chari);
		break;
	}
	case 7:
	{
		character default_chari(bn::sprite_items::guy_walking_spring, current_room.start_x, current_room.start_y, false, current_room.width);
		default_chari.entity.set_camera(current_room.camera);
		default_chari.entity.set_position(sx, sy);
		default_chari.role = 1;
		default_chari.identity = 7;
		current_room.chari.push_back(default_chari);
		break;
	}
	}

	// World generation
	switch (dt.world_index)
	{
	case 0:
	{
		if (!bn::music::playing()) {
			bn::music_items_info::span[2].first.play(0.8);
		}

		current_room.configure(12, 6, 8, 3);
		const short int local_col[current_room.width * current_room.height] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
			1, 1, 2, 40, 3, 1, 1, 1, 0, 1, 1, 0,
			1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
			1, 36, 0, 0, 0, 0, 0, 0, 31, 1, 1, 0,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 };
		const short int local[current_room.width * current_room.height] = {
			4, 3, 8, 11, 13, 3, 3, 3, 8, 3, 5, 0,
			2, 18, 0, 0, 0, 18, 2, 9, 0, 9, 2, 0,
			2, 0, 0, 0, 0, 0, 2, 10, 0, 10, 2, 0,
			2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0,
			17, 0, 0, 0, 0, 0, 0, 0, 0, 18, 2, 0,
			7, 3, 3, 3, 3, 3, 3, 3, 16, 3, 6, 0 };

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++) {
			globals->local_tileset.push_back(local[t]);
			globals->collisions.push_back(local_col[t]);
		}

		if (globals->current_save->last_char_id == 1)
		{
			character maple(bn::sprite_items::maple_walking, 8, 3, false, current_room.width);
			maple.entity.set_position((current_room.start_x + 1) * 32, current_room.start_y * 32);
			maple.entity.set_camera(current_room.camera);
			maple.role = 0;
			maple.identity = 0;
			maple.can_follow = true;
			current_room.chari.push_back(maple);
		}

		if (globals->current_save->last_char_id < 1)
		{
			character enoki(bn::sprite_items::enoki_walking_pj, 8, 3, false, current_room.width);
			enoki.entity.set_position((current_room.start_x + 1) * 32, current_room.start_y * 32);
			enoki.entity.set_camera(current_room.camera);
			enoki.role = 0;
			enoki.identity = 1;
			enoki.can_follow = true;
			current_room.chari.push_back(enoki);
		}

		current_room.primary_bg = bn::regular_bg_items::castle_floor.create_bg(0, 0);
		current_room.primary_bg.set_camera(current_room.camera);
		current_room.environment = &bn::sprite_items::environment_stone;
		break;
	}
	case 1:
	{
		current_room.configure(21, 12, 18, 1);
		const short int local[current_room.width * current_room.height] = {
			4, 3, 3, 16, 12, 3, 13, 12, 3, 8, 12, 8, 3, 12, 3, 3, 12, 13, 16, 3, 5,
			2, 18, 0, 0, 0, 0, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 2,
			2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
			12, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
			12, 1, 1, 1, 1, 0, 0, 0, 0, 25, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
			12, 1, 1, 1, 1, 1, 1, 0, 0, 21, 23, 0, 0, 0, 0, 1, 1, 1, 1, 1, 17,
			12, 1, 1, 1, 1, 1, 0, 0, 25, 22, 24, 25, 0, 0, 1, 1, 1, 1, 1, 1, 17,
			12, 1, 1, 1, 1, 0, 0, 0, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
			12, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
			2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
			2, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 2,
			7, 3, 14, 3, 12, 3, 3, 12, 3, 3, 12, 3, 13, 12, 3, 3, 12, 3, 14, 13, 6 };
		const short int local_col[current_room.width * current_room.height] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 0, 35, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 1, 1,
			1, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 1, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++) {
			globals->local_tileset.push_back(local[t]);
			globals->collisions.push_back(local_col[t]);
		}

		if (globals->current_save->last_char_id == 1)
		{
			character maple(bn::sprite_items::maple_walking, 8, 3, false, current_room.width);
			maple.entity.set_position(current_room.chari.at(0).entity.x(), current_room.chari.at(0).entity.y());
			maple.entity.set_camera(current_room.camera);
			maple.role = 0;
			maple.identity = 0;
			maple.can_follow = true;
			current_room.chari.push_back(maple);
		}

		if (globals->current_save->last_char_id < 1)
		{
			character enoki(bn::sprite_items::enoki_walking_pj, 8, 3, false, current_room.width);
			enoki.entity.set_position(current_room.chari.at(0).entity.x(), current_room.chari.at(0).entity.y());
			enoki.entity.set_camera(current_room.camera);
			enoki.role = 0;
			enoki.identity = 1;
			enoki.can_follow = true;
			current_room.chari.push_back(enoki);
		}

		anim_object fp;
		fp.entity_item = bn::sprite_items::fireplace_anim;
		fp.entity = fp.entity_item.create_sprite(0, 0);
		fp.entity_anim = bn::create_sprite_animate_action_forever(fp.entity, 2, fp.entity_item.tiles_item(), 00, 1, 00, 2);
		fp.entity.set_visible(false);
		fp.entity.set_camera(current_room.camera);
		fp.entity.set_position(304, 176);
		anim_objects.push_back(fp);

		current_room.primary_bg = bn::regular_bg_items::castle_floor.create_bg(0, 0);
		current_room.primary_bg.set_camera(current_room.camera);
		current_room.environment = &bn::sprite_items::environment_stone;
		break;
	}
	case 2:
	{
		current_room.configure(11, 8, 9, 6);
		const short int local[current_room.width * current_room.height] = {
			4, 11, 8, 12, 8, 3, 3, 3, 3, 3, 5,
			2, 18, 9, 9, 26, 27, 2, 0, 0, 0, 2,
			2, 0, 10, 10, 0, 0, 2, 19, 1, 20, 2,
			2, 0, 0, 0, 0, 0, 2, 3, 0, 0, 2,
			2, 0, 1, 1, 1, 0, 2, 0, 0, 18, 2,
			2, 0, 1, 1, 1, 0, 2, 0, 0, 3, 12,
			2, 18, 0, 0, 0, 0, 0, 0, 0, 0, 17,
			7, 3, 3, 14, 3, 3, 3, 3, 3, 3, 6 };
		const short int local_col[current_room.width * current_room.height] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 0, 1, 1, 0, 0, 1, 1, 8, 1, 1,
			1, 0, 10, 10, 0, 0, 1, 1, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1,
			1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1,
			1, 1, 0, 34, 0, 4, 0, 0, 0, 33, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++) {
			globals->local_tileset.push_back(local[t]);
			globals->collisions.push_back(local_col[t]);
		}

		if (globals->current_save->last_char_id == 1)
		{
			character maple(bn::sprite_items::maple_walking, 8, 3, false, current_room.width);
			maple.entity.set_position(current_room.chari.at(0).entity.x(), current_room.chari.at(0).entity.y());
			maple.entity.set_camera(current_room.camera);
			maple.role = 0;
			maple.identity = 0;
			maple.can_follow = true;
			current_room.chari.push_back(maple);
		}

		if (globals->current_save->last_char_id < 1)
		{
			character enoki(bn::sprite_items::enoki_walking_pj, 8, 3, false, current_room.width);
			enoki.entity.set_position(current_room.chari.at(0).entity.x(), current_room.chari.at(0).entity.y());
			enoki.entity.set_camera(current_room.camera);
			enoki.role = 0;
			enoki.identity = 1;
			enoki.can_follow = true;
			current_room.chari.push_back(enoki);
		}

		anim_object aaron;
		aaron.entity.set_visible(true);
		aaron.entity.set_camera(current_room.camera);
		aaron.entity.set_position(64, 48);
		anim_objects.push_back(aaron);

		anim_object del;
		del.id = 1;
		del.entity_item = bn::sprite_items::del_sleep;
		del.entity = del.entity_item.create_sprite(0, 0);
		del.entity_anim = bn::create_sprite_animate_action_forever(del.entity, 20, del.entity_item.tiles_item(), 0, 1, 0, 0);
		del.entity.set_visible(true);
		del.entity.set_camera(current_room.camera);
		del.entity.set_position(256, 48);
		anim_objects.push_back(del);

		current_room.primary_bg = bn::regular_bg_items::castle_floor.create_bg(0, 0);
		current_room.primary_bg.set_camera(current_room.camera);
		current_room.environment = &bn::sprite_items::environment_stone;
		break;
	}
	case 3:
	{
		current_room.configure(24, 12, 22, 1);
		const short int local[current_room.width * current_room.height] = {
			4, 8, 11, 12, 3, 3, 12, 11, 8, 5, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 4, 14, 5,
			2, 18, 0, 0, 0, 0, 0, 0, 18, 2, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 2, 0, 2,
			2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 2, 0, 2,
			2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 2, 0, 2,
			2, 0, 0, 0, 1, 1, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 2,
			2, 0, 0, 1, 1, 1, 1, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 2,
			2, 0, 0, 1, 1, 1, 1, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 2,
			2, 0, 0, 0, 1, 1, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 2,
			2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 0, 2,
			2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
			2, 18, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
			7, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6 };
		const short int local_col[current_room.width * current_room.height] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 38, 1,
			1, 0, 0, 11, 11, 11, 11, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1,
			1, 0, 0, 11, 11, 11, 11, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++) {
			globals->local_tileset.push_back(local[t]);
			globals->collisions.push_back(local_col[t]);
		}

		if (globals->current_save->last_char_id == 1)
		{
			character maple(bn::sprite_items::maple_walking, 8, 3, false, current_room.width);
			maple.entity.set_position(22 * 32, 1 * 32);
			maple.entity.set_camera(current_room.camera);
			maple.role = 0;
			maple.identity = 0;
			maple.can_follow = true;
			current_room.chari.push_back(maple);
		}

		if (globals->current_save->last_char_id < 1)
		{
			character enoki(bn::sprite_items::enoki_walking_pj, 8, 3, false, current_room.width);
			enoki.entity.set_position(22 * 32, 1 * 32);
			enoki.entity.set_camera(current_room.camera);
			enoki.role = 0;
			enoki.identity = 1;
			enoki.can_follow = true;
			current_room.chari.push_back(enoki);
		}

		anim_object fp;
		fp.entity_item = bn::sprite_items::bookshelf;
		fp.entity = fp.entity_item.create_sprite(0, 0);
		fp.entity_anim = bn::create_sprite_animate_action_forever(fp.entity, 2, fp.entity_item.tiles_item(), 00, 00, 00, 0);
		fp.entity.set_visible(true);
		fp.entity.set_camera(current_room.camera);
		fp.entity.set_position(144, 16);
		anim_objects.push_back(fp);

		//character enoki(bn::sprite_items::enoki_walking_pj, current_room, current_room.start_x - 0.9, current_room.start_y, false);
		/*
				if (globals->local_tileset.at((current_room.start_x - 1) + (current_room.start_y * current_room.width)] > 0) {
					enoki.entity.set_position(4 + current_room.start_x * 32, current_room.start_y * 32);
					maple.entity.set_position(-4 + current_room.start_x * 32, (current_room.start_y * 32));
				}
				*/

		for (short int t = 0; t < 2; t++)
		{
			current_room.chari.at(t).entity.set_camera(current_room.camera);
		}

		current_room.primary_bg = bn::regular_bg_items::castle_floor.create_bg(0, 0);
		current_room.primary_bg.set_camera(current_room.camera);
		current_room.environment = &bn::sprite_items::environment_stone;
		break;
	}

	// Main overworld plot
	case 4:
	{
		if (globals->current_save->checkpoint == 5)
		{
			bn::music_items_info::span[21].first.play(0.8);
		}
		else if (globals->current_save->checkpoint < 12)
		{
			bn::music_items_info::span[11].first.play(0.8);
		}
		else if (globals->current_save->checkpoint < 14)
		{
			if (bn::music::playing())
				bn::music::stop();
			bn::music_items_info::span[1].first.play(0.8);
		}

		current_room.configure(20, 20, 9, 17);

		if (globals->current_save->checkpoint < 7)
		{
			const short int local_col[current_room.width * current_room.height] = {
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
				1, 1, 0, 0, 0, 0, 0, 0, 22, 24, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0,
				0, 26, 25, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 23, 21, 0, 0, 0, 0, 1, 20, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

			const short int local[current_room.width * current_room.height] = {
				39, 1, 27, 27, 39, 27, 27, 27, 44, 0, 27, 27, 27, 27, 27, 42, 43, 42, 12, 13,
				27, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43, 3, 43, 11, 26,
				0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 5, 2, 3, 12, 26,
				38, 27, 0, 0, 0, 15, 18, 18, 18, 18, 18, 18, 18, 23, 0, 4, 3, 2, 11, 26,
				39, 47, 44, 0, 1, 16, 19, 19, 19, 19, 19, 19, 19, 24, 1, 5, 2, 3, 12, 26,
				38, 0, 0, 0, 27, 17, 20, 21, 20, 22, 20, 21, 20, 25, 27, 4, 3, 2, 11, 26,
				39, 1, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 4, 2, 3, 12, 26,
				38, 27, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 5, 3, 2, 11, 26,
				39, 1, 27, 0, 0, 0, 0, 0, 40, 3, 42, 0, 0, 0, 0, 4, 2, 3, 12, 26,
				0, 27, 44, 0, 0, 0, 0, 1, 41, 2, 43, 1, 0, 14, 7, 6, 3, 2, 11, 26,
				0, 0, 0, 0, 0, 0, 0, 27, 2, 3, 3, 27, 0, 4, 2, 3, 2, 3, 12, 26,
				38, 0, 1, 0, 0, 0, 0, 0, 2, 2, 3, 0, 0, 5, 3, 2, 3, 2, 11, 26,
				39, 1, 27, 0, 0, 0, 0, 14, 42, 3, 42, 8, 7, 6, 2, 3, 2, 3, 12, 26,
				38, 27, 0, 0, 0, 0, 14, 6, 43, 2, 43, 2, 3, 2, 3, 2, 3, 46, 45, 26,
				39, 0, 0, 0, 0, 0, 5, 2, 3, 3, 2, 3, 2, 46, 9, 10, 9, 45, 13, 26,
				42, 7, 8, 7, 8, 7, 6, 3, 3, 2, 3, 2, 46, 45, 13, 26, 26, 26, 26, 26,
				43, 2, 3, 2, 3, 2, 3, 46, 42, 3, 42, 10, 45, 26, 26, 26, 26, 26, 26, 26,
				42, 10, 9, 10, 9, 10, 9, 45, 43, 2, 43, 26, 26, 26, 26, 26, 26, 26, 0, 0,
				43, 26, 26, 26, 13, 26, 26, 26, 26, 10, 26, 26, 26, 26, 26, 26, 26, 0, 0, 0,
				26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 0, 0, 0 };

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++) {
				globals->local_tileset.push_back(local[t]);
				globals->collisions.push_back(local_col[t]);
			}
		}
		else if (globals->current_save->checkpoint < 9)
		{
			const short int local_col[current_room.width * current_room.height] = {
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
				1, 42, 41, 0, 0, 0, 0, 0, 22, 24, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0,
				1, 26, 25, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 23, 21, 0, 0, 0, 0, 1, 20, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 1, 1, 61, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

			const short int local[current_room.width * current_room.height] = {
				39, 27, 44, 27, 27, 27, 27, 27, 44, 0, 27, 27, 27, 27, 27, 42, 43, 42, 12, 13,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43, 3, 43, 11, 26,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 5, 2, 3, 12, 26,
				27, 27, 0, 0, 0, 15, 18, 18, 18, 18, 18, 18, 18, 23, 0, 4, 3, 2, 11, 26,
				39, 47, 44, 0, 1, 16, 19, 19, 19, 19, 19, 19, 19, 24, 1, 5, 2, 3, 12, 26,
				38, 0, 0, 0, 27, 17, 20, 21, 20, 22, 20, 21, 20, 25, 27, 4, 3, 2, 11, 26,
				39, 1, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 4, 2, 3, 12, 26,
				38, 27, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 5, 3, 2, 11, 26,
				39, 1, 27, 0, 0, 0, 0, 0, 40, 3, 42, 0, 0, 0, 0, 4, 2, 3, 12, 26,
				0, 27, 44, 0, 0, 0, 0, 1, 41, 2, 43, 1, 0, 14, 7, 6, 3, 2, 11, 26,
				0, 0, 0, 0, 0, 0, 0, 27, 2, 3, 3, 27, 0, 4, 2, 3, 2, 3, 12, 26,
				38, 0, 1, 0, 0, 0, 0, 0, 2, 2, 3, 0, 0, 5, 3, 2, 3, 2, 11, 26,
				39, 1, 27, 0, 0, 0, 0, 14, 42, 3, 42, 8, 7, 6, 2, 3, 2, 3, 12, 26,
				38, 27, 0, 0, 0, 0, 14, 6, 43, 2, 43, 2, 3, 2, 3, 2, 3, 46, 45, 26,
				39, 0, 0, 0, 0, 0, 5, 2, 3, 3, 2, 3, 2, 46, 9, 10, 9, 45, 13, 26,
				42, 7, 8, 7, 8, 7, 6, 3, 3, 2, 3, 2, 46, 45, 13, 26, 26, 26, 26, 26,
				43, 2, 3, 2, 3, 2, 3, 46, 42, 3, 42, 10, 45, 26, 26, 26, 26, 26, 26, 26,
				42, 10, 9, 10, 9, 10, 9, 45, 43, 2, 43, 26, 26, 26, 26, 26, 26, 26, 0, 0,
				43, 26, 26, 26, 13, 26, 26, 26, 52, 10, 26, 26, 26, 26, 26, 26, 26, 0, 0, 0,
				26, 26, 26, 26, 26, 26, 26, 26, 53, 26, 26, 26, 26, 26, 26, 26, 26, 0, 0, 0 };

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++) {
				globals->local_tileset.push_back(local[t]);
				globals->collisions.push_back(local_col[t]);
			}
		}
		else if (globals->current_save->checkpoint < 11)
		{
			const short int local_col[current_room.width * current_room.height] = {
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
				1, 42, 41, 0, 0, 0, 0, 0, 22, 24, 0, 0, 0, 0, 0, 1, 66, 1, 1, 0,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0,
				1, 26, 25, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 23, 21, 0, 0, 0, 0, 1, 20, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 1, 1, 61, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

			const short int local[current_room.width * current_room.height] = {
				39, 44, 27, 27, 39, 27, 27, 27, 44, 0, 27, 27, 27, 27, 27, 42, 2, 42, 12, 13,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43, 3, 43, 11, 26,
				0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 5, 2, 3, 12, 26,
				38, 27, 0, 0, 0, 15, 18, 18, 18, 18, 18, 18, 18, 23, 0, 4, 3, 2, 11, 26,
				39, 47, 44, 0, 1, 16, 19, 19, 19, 19, 19, 19, 19, 24, 1, 5, 2, 3, 12, 26,
				38, 0, 0, 0, 27, 17, 20, 21, 20, 22, 20, 21, 20, 25, 27, 4, 3, 2, 11, 26,
				39, 1, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 4, 2, 3, 12, 26,
				38, 27, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 5, 3, 2, 11, 26,
				39, 1, 27, 0, 0, 0, 0, 0, 40, 3, 42, 0, 0, 0, 0, 4, 2, 3, 12, 26,
				0, 27, 44, 0, 0, 0, 0, 1, 41, 2, 43, 1, 0, 14, 7, 6, 3, 2, 11, 26,
				0, 0, 0, 0, 0, 0, 0, 27, 2, 3, 3, 27, 0, 4, 2, 3, 2, 3, 12, 26,
				38, 0, 1, 0, 0, 0, 0, 0, 2, 2, 3, 0, 0, 5, 3, 2, 3, 2, 11, 26,
				39, 1, 27, 0, 0, 0, 0, 14, 42, 3, 42, 8, 7, 6, 2, 3, 2, 3, 12, 26,
				38, 27, 0, 0, 0, 0, 14, 6, 43, 2, 43, 2, 3, 2, 3, 2, 3, 46, 45, 26,
				39, 0, 0, 0, 0, 0, 5, 2, 3, 3, 2, 3, 2, 46, 9, 10, 9, 45, 13, 26,
				42, 7, 8, 7, 8, 7, 6, 3, 3, 2, 3, 2, 46, 45, 13, 26, 26, 26, 26, 26,
				43, 2, 3, 2, 3, 2, 3, 46, 42, 3, 42, 10, 45, 26, 26, 26, 26, 26, 26, 26,
				42, 10, 9, 10, 9, 10, 9, 45, 43, 2, 43, 26, 26, 26, 26, 26, 26, 26, 26, 0,
				43, 26, 26, 26, 13, 26, 26, 26, 52, 10, 26, 26, 26, 26, 26, 26, 26, 26, 26, 0,
				26, 26, 26, 26, 26, 26, 26, 26, 53, 26, 26, 26, 26, 26, 26, 26, 26, 0, 0, 0 };

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++) {
				globals->local_tileset.push_back(local[t]);
				globals->collisions.push_back(local_col[t]);
			}
		}
		else if (globals->current_save->checkpoint == 12)
		{
			const short int local_col[current_room.width * current_room.height] = {
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
				1, 42, 41, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0,
				1, 26, 25, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 21, 0, 0, 0, 0, 1, 20, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

			const short int local[current_room.width * current_room.height] = {
				39, 44, 27, 27, 39, 27, 27, 27, 44, 0, 27, 27, 27, 27, 27, 42, 2, 42, 12, 13,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43, 3, 43, 11, 26,
				0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 5, 2, 3, 12, 26,
				38, 27, 0, 0, 0, 15, 18, 18, 18, 18, 18, 18, 18, 23, 0, 4, 3, 2, 11, 26,
				39, 47, 44, 0, 1, 16, 19, 19, 19, 19, 19, 19, 19, 24, 1, 5, 2, 3, 12, 26,
				38, 0, 0, 0, 27, 17, 20, 21, 20, 22, 20, 21, 20, 25, 27, 4, 3, 2, 11, 26,
				39, 1, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 4, 2, 3, 12, 26,
				38, 27, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 5, 3, 2, 11, 26,
				39, 1, 27, 0, 0, 0, 0, 0, 40, 3, 42, 0, 0, 0, 0, 4, 2, 3, 12, 26,
				0, 27, 44, 0, 0, 0, 0, 1, 41, 2, 43, 1, 0, 14, 7, 6, 3, 2, 11, 26,
				0, 0, 0, 0, 0, 0, 0, 27, 2, 3, 3, 27, 0, 4, 2, 3, 2, 3, 12, 26,
				38, 0, 1, 0, 0, 0, 0, 0, 2, 2, 3, 0, 0, 5, 3, 2, 3, 2, 11, 26,
				39, 1, 27, 0, 0, 0, 0, 14, 42, 3, 42, 8, 7, 6, 2, 3, 2, 3, 12, 26,
				38, 27, 0, 0, 0, 0, 14, 6, 43, 2, 43, 2, 3, 2, 3, 2, 3, 46, 45, 26,
				39, 0, 0, 0, 0, 0, 5, 2, 3, 3, 2, 3, 2, 46, 9, 10, 9, 45, 13, 26,
				42, 7, 8, 7, 8, 7, 6, 3, 3, 2, 3, 2, 46, 45, 13, 26, 26, 26, 26, 26,
				43, 2, 3, 2, 3, 2, 3, 46, 42, 3, 42, 10, 45, 26, 26, 26, 26, 26, 26, 26,
				42, 10, 9, 10, 9, 10, 9, 45, 43, 2, 43, 26, 26, 26, 26, 26, 26, 26, 26, 0,
				43, 26, 26, 26, 13, 26, 26, 26, 26, 10, 26, 26, 26, 26, 26, 26, 26, 26, 26, 0,
				26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 0, 0, 0 };

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++) {
				globals->local_tileset.push_back(local[t]);
				globals->collisions.push_back(local_col[t]);
			}

			current_room.chari.at(0).can_follow = false;

			character maple(bn::sprite_items::maple_walking_oo, 5, 1, false, current_room.width);
			maple.entity.set_position(10 * 32, 6 * 32);
			maple.entity.set_camera(current_room.camera);
			maple.role = 0;
			maple.identity = 0;
			maple.follow_id = 2;
			maple.can_follow = true;
			current_room.chari.push_back(maple);

			character enoki(bn::sprite_items::enoki_walking_oo, 6, 2, false, current_room.width);
			enoki.entity.set_position(11 * 32, 6 * 32);
			enoki.entity.set_camera(current_room.camera);
			enoki.role = 0;
			enoki.identity = 1;
			enoki.follow_id = 1;
			enoki.can_follow = true;
			current_room.chari.push_back(enoki);
		}
		else if (globals->current_save->checkpoint == 13)
		{
			const short int local_col[current_room.width * current_room.height] = {
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
				1, 0, 41, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0,
				1, 26, 25, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 21, 0, 0, 0, 0, 1, 20, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0,
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
				1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

			const short int local[current_room.width * current_room.height] = {
				39, 44, 27, 27, 39, 27, 27, 27, 44, 0, 27, 27, 27, 27, 27, 42, 2, 42, 12, 13,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43, 3, 43, 11, 26,
				0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 5, 2, 3, 12, 26,
				38, 27, 0, 0, 0, 15, 18, 18, 18, 18, 18, 18, 18, 23, 0, 4, 3, 2, 11, 26,
				39, 47, 44, 0, 1, 16, 19, 19, 19, 19, 19, 19, 19, 24, 1, 5, 2, 3, 12, 26,
				38, 0, 0, 0, 27, 17, 20, 21, 20, 22, 20, 21, 20, 25, 27, 4, 3, 2, 11, 26,
				39, 1, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 4, 2, 3, 12, 26,
				38, 27, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 5, 3, 2, 11, 26,
				39, 1, 27, 0, 0, 0, 0, 0, 40, 3, 42, 0, 0, 0, 0, 4, 2, 3, 12, 26,
				0, 27, 44, 0, 0, 0, 0, 1, 41, 2, 43, 1, 0, 14, 7, 6, 3, 2, 11, 26,
				0, 0, 0, 0, 0, 0, 0, 27, 2, 3, 3, 27, 0, 4, 2, 3, 2, 3, 12, 26,
				38, 0, 1, 0, 0, 0, 0, 0, 2, 2, 3, 0, 0, 5, 3, 2, 3, 2, 11, 26,
				39, 1, 27, 0, 0, 0, 0, 14, 42, 3, 42, 8, 7, 6, 2, 3, 2, 3, 12, 26,
				38, 27, 0, 0, 0, 0, 14, 6, 43, 2, 43, 2, 3, 2, 3, 2, 3, 46, 45, 26,
				39, 0, 0, 0, 0, 0, 5, 2, 3, 3, 2, 3, 2, 46, 9, 10, 9, 45, 13, 26,
				42, 7, 8, 7, 8, 7, 6, 3, 3, 2, 3, 2, 46, 45, 13, 26, 26, 26, 26, 26,
				43, 2, 3, 2, 3, 2, 3, 46, 42, 3, 42, 10, 45, 26, 26, 26, 26, 26, 26, 26,
				42, 10, 9, 10, 9, 10, 9, 45, 43, 2, 43, 26, 26, 26, 26, 26, 26, 26, 26, 0,
				43, 26, 26, 26, 13, 26, 26, 26, 26, 10, 26, 26, 26, 26, 26, 26, 26, 26, 26, 0,
				26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 0, 0, 0 };

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++) {
				globals->local_tileset.push_back(local[t]);
				globals->collisions.push_back(local_col[t]);
			}

			if (globals->current_save->last_char_id != 2)
			{
				character vee(bn::sprite_items::aaron_walking_oo, 3, 2, false, current_room.width);
				vee.entity.set_position(1 * 32, 1 * 32);
				vee.entity.set_camera(current_room.camera);
				vee.role = 0;
				vee.follow_id = 2;
				vee.identity = 2;
				current_room.chari.push_back(vee);
			}
			else {
				current_room.chari.at(0).follow_id = 2;
			}

			if (globals->current_save->last_char_id != 4)
			{
				character vee(bn::sprite_items::vee_walking_spring, 3, 2, false, current_room.width);
				vee.entity.set_position(2 * 32, 1 * 32);
				vee.entity.set_camera(current_room.camera);
				vee.role = 0;
				vee.follow_id = 0;
				vee.identity = 4;
				current_room.chari.push_back(vee);
			}
			else {
				current_room.chari.at(0).follow_id = 0;
			}

			if (globals->current_save->last_char_id != 5)
			{
				character eleanor(bn::sprite_items::eleanor_walking_spring, 4, 4, false, current_room.width);
				eleanor.entity.set_position(3 * 32, 1 * 32);
				eleanor.entity.set_camera(current_room.camera);
				eleanor.role = 0;
				eleanor.follow_id = 1;
				eleanor.identity = 5;
				current_room.chari.push_back(eleanor);
			}
			else {
				current_room.chari.at(0).follow_id = 1;
			}
		}

		current_room.primary_bg = bn::regular_bg_items::grassy_knoll.create_bg(0, 0);
		current_room.environment = &bn::sprite_items::ocean_terrain;

		if (globals->current_save->checkpoint == 5)
			current_room.primary_bg.set_palette(bn::regular_bg_items::castle_floor.palette_item());
		current_room.primary_bg.set_camera(current_room.camera);
		break;
	}
	case 5:
	{
		bn::music_items_info::span[2].first.play(0.8);

		current_room.configure(11, 5, 5, 3);
		const short int local_col[current_room.width * current_room.height] = {
			01, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			01, 1, 0, 0, 17, 0, 18, 0, 0, 0, 1,
			01, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1,
			01, 1, 16, 1, 1, 13, 0, 1, 0, 1, 1,
			01, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		const short int local[current_room.width * current_room.height] = {
			1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 51,
			2, 7, 0, 0, 0, 0, 0, 0, 0, 0, 52,
			3, 8, 0, 0, 0, 0, 0, 0, 0, 0, 53,
			4, 9, 0, 0, 0, 0, 0, 0, 0, 0, 54,
			5, 10, 0, 0, 0, 0, 0, 0, 0, 0, 55 };

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++) {
			globals->local_tileset.push_back(local[t]);
			globals->collisions.push_back(local_col[t]);
		}

		current_room.primary_bg = bn::regular_bg_items::bg_trailer_home.create_bg(0, 0);
		current_room.primary_bg.set_camera(current_room.camera);

		if (globals->current_save->last_char_id != 0)
		{
			character maple(bn::sprite_items::maple_walking_spring, 5, 1, false, current_room.width);
			maple.entity.set_position(5 * 32, 1 * 32);
			maple.entity.set_camera(current_room.camera);
			maple.role = 2;
			maple.identity = 0;
			current_room.chari.push_back(maple);
		}

		if (globals->current_save->last_char_id != 1)
		{
			character enoki(bn::sprite_items::enoki_walking_spring, 6, 2, false, current_room.width);
			enoki.entity.set_position(6 * 32, 2 * 32);
			enoki.entity.set_camera(current_room.camera);
			enoki.role = 2;
			enoki.identity = 1;
			current_room.chari.push_back(enoki);
		}

		if (globals->current_save->last_char_id != 2)
		{
			character aaron(bn::sprite_items::aaron_walking_spring, 4, 1, false, current_room.width);
			aaron.entity.set_position(4 * 32, 1 * 32);
			aaron.entity.set_camera(current_room.camera);
			aaron.role = 2;
			aaron.identity = 2;
			current_room.chari.push_back(aaron);
		}

		current_room.environment = &bn::sprite_items::trailer_home;
		break;
	}
	case 6:
	{
		if (globals->current_save->checkpoint < 12)
		{
			bn::music_items_info::span[17].first.play(0.8);
		}
		current_room.configure(9, 11, 7, 3);

		if (globals->current_save->checkpoint == 12)
		{
			const short int local[current_room.width * current_room.height] = {
				00, 0, 0, 0, 0, 0, 0, 12, 0,
				00, 0, 0, 0, 0, 0, 0, 12, 0,
				00, 0, 0, 0, 0, 0, 1, 12, 1,
				00, 0, 0, 0, 0, 0, 1, 0, 1,
				1, 1, 1, 1, 1, 1, 1, 0, 1,
				1, 2, 4, 8, 9, 11, 0, 0, 1,
				1, 3, 5, 0, 10, 0, 0, 0, 1,
				1, 0, 0, 0, 0, 0, 0, 0, 1,
				1, 6, 0, 0, 0, 13, 14, 0, 1,
				1, 7, 0, 0, 0, 0, 0, 0, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 1 };
			const short int local_col[current_room.width * current_room.height] = {
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 1, 0, 1,
				1, 1, 1, 1, 1, 1, 1, 0, 1,
				1, 1, 0, 1, 1, 1, 0, 0, 1,
				1, 1, 0, 0, 0, 0, 0, 0, 1,
				1, 0, 0, 0, 30, 0, 0, 0, 1,
				1, 1, 0, 0, 0, 1, 1, 0, 1,
				1, 1, 0, 0, 0, 0, 0, 0, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 1 };

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++) {
				globals->local_tileset.push_back(local[t]);
				globals->collisions.push_back(local_col[t]);
			}

			if (globals->current_save->last_char_id != 0)
			{
				character maple(bn::sprite_items::maple_walking_oo, 5, 1, false, current_room.width);
				maple.entity.set_position(7 * 32, 4 * 32);
				maple.entity.set_camera(current_room.camera);
				maple.role = 0;
				maple.identity = 0;
				maple.follow_id = -1;
				maple.teleport = false;
				current_room.chari.push_back(maple);
			}

			if (globals->current_save->last_char_id != 1)
			{
				character enoki(bn::sprite_items::enoki_walking_oo, 6, 2, false, current_room.width);
				enoki.entity.set_position(7 * 32, 3 * 32);
				enoki.entity.set_camera(current_room.camera);
				enoki.role = 0;
				enoki.identity = 1;
				enoki.follow_id = -1;
				enoki.teleport = false;
				current_room.chari.push_back(enoki);
			}
		}
		else if (globals->current_save->checkpoint == 13)
		{
			const short int local[current_room.width * current_room.height] = {
				00, 0, 0, 0, 0, 0, 0, 12, 0,
				00, 0, 0, 0, 0, 0, 0, 12, 0,
				00, 0, 0, 0, 0, 0, 1, 12, 1,
				00, 0, 0, 0, 0, 0, 1, 0, 1,
				1, 1, 1, 1, 1, 1, 1, 0, 1,
				1, 2, 4, 8, 9, 11, 0, 0, 1,
				1, 3, 5, 0, 10, 0, 0, 0, 1,
				1, 0, 0, 0, 0, 0, 0, 0, 1,
				1, 6, 0, 0, 0, 13, 14, 0, 1,
				1, 7, 0, 0, 0, 0, 0, 0, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 1 };
			const short int local_col[current_room.width * current_room.height] = {
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 1, 0, 1,
				1, 1, 1, 1, 1, 1, 1, 0, 1,
				1, 1, 0, 1, 1, 1, 0, 0, 1,
				1, 1, 0, 0, 0, 0, 0, 0, 1,
				1, 0, 0, 0, 30, 0, 0, 0, 1,
				1, 1, 0, 0, 0, 1, 1, 0, 1,
				1, 1, 0, 0, 0, 0, 0, 0, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 1 };

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++) {
				globals->local_tileset.push_back(local[t]);
				globals->collisions.push_back(local_col[t]);
			}

			if (globals->current_save->last_char_id != 0)
			{
				character maple(bn::sprite_items::maple_walking_oo, 5, 1, false, current_room.width);
				maple.entity.set_position(4 * 32, 7 * 32);
				maple.entity.set_camera(current_room.camera);
				maple.role = 0;
				maple.identity = 0;
				maple.teleport = false;
				maple.follow_id = current_room.chari.size() - 1;
				current_room.chari.push_back(maple);
			}

			if (globals->current_save->last_char_id != 1)
			{
				character enoki(bn::sprite_items::enoki_walking_oo, 6, 2, false, current_room.width);
				enoki.entity.set_position(4 * 32, 8 * 32);
				enoki.entity.set_camera(current_room.camera);
				enoki.role = 0;
				enoki.identity = 1;
				enoki.teleport = false;
				enoki.follow_id = current_room.chari.size() - 1;
				current_room.chari.push_back(enoki);
			}

			if (globals->current_save->last_char_id != 2)
			{
				character maple(bn::sprite_items::aaron_walking_oo, 5, 1, false, current_room.width);
				maple.entity.set_position(7 * 32, 4 * 32);
				maple.entity.set_camera(current_room.camera);
				maple.role = 0;
				maple.identity = 2;
				maple.teleport = false;
				maple.follow_id = current_room.chari.size() - 1;
				current_room.chari.push_back(maple);
			}

			if (globals->current_save->last_char_id != 4)
			{
				character enoki(bn::sprite_items::vee_walking_spring, 6, 2, false, current_room.width);
				enoki.entity.set_position(7 * 32, 5 * 32);
				enoki.entity.set_camera(current_room.camera);
				enoki.role = 0;
				enoki.identity = 4;
				enoki.teleport = false;
				enoki.follow_id = current_room.chari.size() - 1;
				current_room.chari.push_back(enoki);
			}

			if (globals->current_save->last_char_id != 5)
			{
				character enoki(bn::sprite_items::eleanor_walking_spring, 6, 2, false, current_room.width);
				enoki.entity.set_position(7 * 32, 6 * 32);
				enoki.entity.set_camera(current_room.camera);
				enoki.role = 0;
				enoki.identity = 5;
				enoki.teleport = false;
				enoki.follow_id = current_room.chari.size() - 1;
				current_room.chari.push_back(enoki);
			}
		}
		else
		{
			const short int local[current_room.width * current_room.height] = {
				00, 0, 0, 0, 0, 0, 0, 12, 0,
				00, 0, 0, 0, 0, 0, 0, 12, 0,
				00, 0, 0, 0, 0, 0, 1, 12, 1,
				00, 0, 0, 0, 0, 0, 1, 0, 1,
				1, 1, 1, 1, 1, 1, 1, 0, 1,
				1, 2, 4, 8, 9, 11, 0, 0, 1,
				1, 3, 5, 0, 10, 0, 0, 0, 1,
				1, 0, 0, 0, 0, 0, 0, 0, 1,
				1, 6, 0, 0, 0, 13, 14, 0, 1,
				1, 7, 0, 0, 0, 0, 0, 0, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 1 };
			const short int local_col[current_room.width * current_room.height] = {
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 1, 19, 1,
				1, 1, 1, 1, 1, 1, 1, 0, 1,
				1, 1, 0, 1, 1, 1, 0, 0, 1,
				1, 1, 28, 0, 29, 0, 0, 0, 1,
				1, 0, 0, 0, 30, 0, 0, 0, 1,
				1, 1, 0, 0, 0, 1, 1, 0, 1,
				1, 1, 27, 0, 30, 0, 0, 0, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 1 };

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++) {
				globals->local_tileset.push_back(local[t]);
				globals->collisions.push_back(local_col[t]);
			}
		}

		if (globals->current_save->last_char_id != 3)
		{
			character scout(bn::sprite_items::scout_walking_spring, 4, 8, false, current_room.width);
			scout.entity.set_position(4 * 32, 8 * 32);
			scout.entity.set_camera(current_room.camera);
			scout.role = 2;
			scout.identity = 3;
			current_room.chari.push_back(scout);
		}

		current_room.primary_bg = bn::regular_bg_items::velvet.create_bg(0, 0);
		current_room.primary_bg.set_camera(current_room.camera);
		current_room.environment = &bn::sprite_items::scout_lab;
		break;
	}

	// Additional housing area
	case 8:
	{
		if (globals->current_save->checkpoint < 12)
		{
			bn::music_items_info::span[27].first.play(0.8);
		}
		else
		{
			if (!bn::music::playing())
				bn::music_items_info::span[1].first.play(0.2);
		}

		current_room.configure(20, 20, 9, 17);

		if (globals->current_save->checkpoint < 10)
		{
			const short int local_col[current_room.width * current_room.height] = {
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 54, 52, 0, 0, 0, 0, 0, 0, 0, 43, 1,
				1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1,
				1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1,
				1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1,
				1, 1, 0, 0, 0, 1, 48, 0, 0, 0, 0, 0, 1, 1, 1, 1, 44, 0, 1, 1,
				1, 1, 0, 0, 0, 45, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1,
				1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1,
				1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1,
				1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1,
				1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1,
				1, 1, 0, 46, 0, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 47, 0, 1, 1,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
			const short int local[current_room.width * current_room.height] = {
				35, 35, 35, 35, 35, 35, 35, 35, 35, 44, 0, 35, 35, 35, 35, 35, 35, 39, 27, 27,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 8, 8,
				27, 1, 0, 0, 28, 28, 33, 28, 28, 0, 14, 8, 7, 7, 7, 7, 7, 6, 42, 1,
				1, 27, 0, 0, 29, 29, 48, 29, 29, 0, 4, 0, 0, 0, 0, 0, 0, 4, 1, 27,
				27, 1, 0, 0, 30, 30, 49, 30, 30, 0, 5, 0, 42, 42, 42, 42, 0, 4, 27, 1,
				1, 27, 0, 1, 31, 31, 50, 31, 31, 0, 4, 0, 43, 10, 9, 43, 0, 4, 1, 27,
				27, 1, 0, 27, 32, 32, 51, 32, 32, 0, 5, 0, 42, 26, 26, 42, 44, 4, 27, 1,
				1, 27, 0, 0, 0, 44, 0, 0, 0, 0, 4, 0, 43, 26, 26, 43, 0, 4, 1, 27,
				27, 1, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 43, 43, 43, 43, 0, 4, 27, 1,
				1, 27, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 4, 1, 27,
				27, 1, 0, 0, 0, 0, 0, 0, 0, 0, 42, 7, 7, 7, 7, 7, 7, 6, 27, 1,
				1, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 27,
				27, 1, 0, 0, 28, 28, 33, 28, 28, 0, 0, 28, 28, 33, 28, 28, 0, 0, 27, 1,
				1, 27, 0, 0, 29, 29, 48, 29, 29, 0, 0, 29, 29, 48, 29, 29, 0, 0, 1, 27,
				27, 1, 0, 1, 30, 30, 49, 30, 30, 0, 0, 30, 30, 49, 30, 30, 1, 0, 27, 1,
				1, 27, 0, 27, 31, 31, 50, 31, 31, 0, 0, 31, 31, 50, 31, 31, 27, 0, 1, 27,
				27, 1, 0, 44, 32, 32, 51, 32, 32, 0, 0, 32, 32, 51, 32, 32, 44, 0, 27, 1,
				1, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 27,
				27, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 27, 1,
				1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27 };

			for (short int t = 0; t < current_room.width * current_room.height; t++) {
				globals->local_tileset.push_back(local[t]);
				globals->collisions.push_back(local_col[t]);
			}
		}
		else if (globals->current_save->checkpoint < 12)
		{
			const short int local_col[current_room.width * current_room.height] = {
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 54, 52, 0, 0, 0, 0, 0, 0, 0, 43, 1,
				1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1,
				1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1,
				1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1,
				1, 1, 0, 0, 0, 1, 48, 0, 0, 0, 0, 0, 1, 1, 1, 1, 44, 0, 1, 1,
				1, 1, 0, 0, 0, 45, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1,
				1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1,
				1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1,
				1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1,
				1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1,
				1, 1, 0, 46, 0, 0, 50, 0, 0, 0, 0, 0, 0, 64, 0, 0, 47, 0, 1, 1,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
			const short int local[current_room.width * current_room.height] = {
				35, 35, 35, 35, 35, 35, 35, 35, 35, 44, 0, 35, 35, 35, 35, 35, 35, 39, 27, 27,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 8, 8,
				27, 1, 0, 0, 28, 28, 33, 28, 28, 0, 14, 8, 7, 7, 7, 7, 7, 6, 42, 1,
				1, 27, 0, 0, 29, 29, 48, 29, 29, 0, 4, 0, 0, 0, 0, 0, 0, 4, 1, 27,
				27, 1, 0, 0, 30, 30, 49, 30, 30, 0, 5, 0, 42, 42, 42, 42, 0, 4, 27, 1,
				1, 27, 0, 1, 31, 31, 50, 31, 31, 0, 4, 0, 43, 10, 9, 43, 0, 4, 1, 27,
				27, 1, 0, 27, 32, 32, 51, 32, 32, 0, 5, 0, 42, 26, 26, 42, 44, 4, 27, 1,
				1, 27, 0, 0, 0, 44, 0, 0, 0, 0, 4, 0, 43, 26, 26, 43, 0, 4, 1, 27,
				27, 1, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 43, 43, 43, 43, 0, 4, 27, 1,
				1, 27, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 4, 1, 27,
				27, 1, 0, 0, 0, 0, 0, 0, 0, 0, 42, 7, 7, 7, 7, 7, 7, 6, 27, 1,
				1, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 27,
				27, 1, 0, 0, 28, 28, 33, 28, 28, 0, 0, 28, 28, 33, 28, 28, 0, 0, 27, 1,
				1, 27, 0, 0, 29, 29, 48, 29, 29, 0, 0, 29, 29, 48, 29, 29, 0, 0, 1, 27,
				27, 1, 0, 1, 30, 30, 49, 30, 30, 0, 0, 30, 30, 49, 30, 30, 1, 0, 27, 1,
				1, 27, 0, 27, 31, 31, 50, 31, 31, 0, 0, 31, 31, 50, 31, 31, 27, 0, 1, 27,
				27, 1, 0, 44, 32, 32, 51, 32, 32, 0, 0, 32, 32, 51, 32, 32, 44, 0, 27, 1,
				1, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 27,
				27, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 27, 1,
				1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27 };

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++) {
				globals->local_tileset.push_back(local[t]);
				globals->collisions.push_back(local_col[t]);
			}
		}
		else if (globals->current_save->checkpoint == 12)
		{
			const short int local_col[current_room.width * current_room.height] = {
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 0, 0, 0, 0, 0, 43, 1,
				1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1,
				1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1,
				1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1,
				1, 1, 0, 0, 0, 1, 48, 0, 0, 0, 0, 0, 1, 1, 1, 1, 44, 0, 1, 1,
				1, 1, 0, 0, 0, 45, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1,
				1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1,
				1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1,
				1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1,
				1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1,
				1, 1, 0, 46, 0, 0, 71, 0, 0, 0, 0, 0, 0, 71, 0, 0, 47, 0, 1, 1,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
			const short int local[current_room.width * current_room.height] = {
				35, 35, 35, 35, 35, 35, 35, 35, 35, 44, 0, 35, 35, 35, 35, 35, 35, 39, 27, 27,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 8, 8,
				27, 1, 0, 0, 28, 28, 33, 28, 28, 0, 14, 8, 7, 7, 7, 7, 7, 6, 42, 1,
				1, 27, 0, 0, 29, 29, 48, 29, 29, 0, 4, 0, 0, 0, 0, 0, 0, 4, 1, 27,
				27, 1, 0, 0, 30, 30, 49, 30, 30, 0, 5, 0, 42, 42, 42, 42, 0, 4, 27, 1,
				1, 27, 0, 1, 31, 31, 50, 31, 31, 0, 4, 0, 43, 10, 9, 43, 0, 4, 1, 27,
				27, 1, 0, 27, 32, 32, 51, 32, 32, 0, 5, 0, 42, 26, 26, 42, 44, 4, 27, 1,
				1, 27, 0, 0, 0, 44, 0, 0, 0, 0, 4, 0, 43, 26, 26, 43, 0, 4, 1, 27,
				27, 1, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 43, 43, 43, 43, 0, 4, 27, 1,
				1, 27, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 4, 1, 27,
				27, 1, 0, 0, 0, 0, 0, 0, 0, 0, 42, 7, 7, 7, 7, 7, 7, 6, 27, 1,
				1, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 27,
				27, 1, 0, 0, 28, 28, 33, 28, 28, 0, 0, 28, 28, 33, 28, 28, 0, 0, 27, 1,
				1, 27, 0, 0, 29, 29, 48, 29, 29, 0, 0, 29, 29, 48, 29, 29, 0, 0, 1, 27,
				27, 1, 0, 1, 30, 30, 49, 30, 30, 0, 0, 30, 30, 49, 30, 30, 1, 0, 27, 1,
				1, 27, 0, 27, 31, 31, 50, 31, 31, 0, 0, 31, 31, 50, 31, 31, 27, 0, 1, 27,
				27, 1, 0, 44, 32, 32, 51, 32, 32, 0, 0, 32, 32, 51, 32, 32, 44, 0, 27, 1,
				1, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 27,
				27, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 27, 1,
				1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27 };

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++) {
				globals->local_tileset.push_back(local[t]);
				globals->collisions.push_back(local_col[t]);
			}
		}
		else if (globals->current_save->checkpoint == 13)
		{
			const short int local_col[current_room.width * current_room.height] = {
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 0, 0, 0, 0, 0, 43, 1,
				1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1,
				1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1,
				1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1,
				1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 44, 0, 1, 1,
				1, 1, 0, 0, 0, 45, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1,
				1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1,
				1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1,
				1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1,
				1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1,
				1, 1, 0, 46, 0, 0, 71, 0, 0, 0, 0, 0, 0, 71, 0, 0, 47, 0, 1, 1,
				1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
			const short int local[current_room.width * current_room.height] = {
				35, 35, 35, 35, 35, 35, 35, 35, 35, 44, 0, 35, 35, 35, 35, 35, 35, 39, 27, 27,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 8, 8,
				27, 1, 0, 0, 28, 28, 33, 28, 28, 0, 14, 8, 7, 7, 7, 7, 7, 6, 42, 1,
				1, 27, 0, 0, 29, 29, 48, 29, 29, 0, 4, 0, 0, 0, 0, 0, 0, 4, 1, 27,
				27, 1, 0, 0, 30, 30, 49, 30, 30, 0, 5, 0, 42, 42, 42, 42, 0, 4, 27, 1,
				1, 27, 0, 1, 31, 31, 50, 31, 31, 0, 4, 0, 43, 10, 9, 43, 0, 4, 1, 27,
				27, 1, 0, 27, 32, 32, 51, 32, 32, 0, 5, 0, 42, 26, 26, 42, 44, 4, 27, 1,
				1, 27, 0, 0, 0, 44, 0, 0, 0, 0, 4, 0, 43, 26, 26, 43, 0, 4, 1, 27,
				27, 1, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 43, 43, 43, 43, 0, 4, 27, 1,
				1, 27, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 4, 1, 27,
				27, 1, 0, 0, 0, 0, 0, 0, 0, 0, 42, 7, 7, 7, 7, 7, 7, 6, 27, 1,
				1, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 27,
				27, 1, 0, 0, 28, 28, 33, 28, 28, 0, 0, 28, 28, 33, 28, 28, 0, 0, 27, 1,
				1, 27, 0, 0, 29, 29, 48, 29, 29, 0, 0, 29, 29, 48, 29, 29, 0, 0, 1, 27,
				27, 1, 0, 1, 30, 30, 49, 30, 30, 0, 0, 30, 30, 49, 30, 30, 1, 0, 27, 1,
				1, 27, 0, 27, 31, 31, 50, 31, 31, 0, 0, 31, 31, 50, 31, 31, 27, 0, 1, 27,
				27, 1, 0, 44, 32, 32, 51, 32, 32, 0, 0, 32, 32, 51, 32, 32, 44, 0, 27, 1,
				1, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 27,
				27, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 27, 1,
				1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27 };

			globals->local_tileset.clear();
			globals->collisions.clear();
			current_room.environment = &bn::sprite_items::ocean_terrain;

			for (short int t = 0; t < current_room.width * current_room.height; t++) {
				globals->local_tileset.push_back(local[t]);
				globals->collisions.push_back(local_col[t]);
			}
		}

		if (globals->current_save->checkpoint == 13)
		{
			if (globals->current_save->last_char_id != 2)
			{
				character aaron(bn::sprite_items::aaron_walking_spring, 3, 2, false, current_room.width);
				aaron.entity.set_position(6 * 32, 7 * 32);
				aaron.entity.set_camera(current_room.camera);
				aaron.role = 0;
				aaron.follow_id = 2;
				aaron.identity = 2;
				current_room.chari.push_back(aaron);
			}
			else {
				current_room.chari.at(0).follow_id = 2;
			}

			if (globals->current_save->last_char_id != 4)
			{
				character vee(bn::sprite_items::vee_walking_spring, 3, 2, false, current_room.width);
				vee.entity.set_position(7 * 32, 7 * 32);
				vee.entity.set_camera(current_room.camera);
				vee.role = 0;
				vee.follow_id = 0;
				vee.identity = 4;
				current_room.chari.push_back(vee);
			}
			else {
				current_room.chari.at(0).follow_id = 0;
			}

			if (globals->current_save->last_char_id != 5)
			{
				character eleanor(bn::sprite_items::eleanor_walking_spring, 4, 4, false, current_room.width);
				eleanor.entity.set_position(8 * 32, 7 * 32);
				eleanor.entity.set_camera(current_room.camera);
				eleanor.role = 0;
				eleanor.follow_id = 1;
				eleanor.identity = 5;
				current_room.chari.push_back(eleanor);
			}
			else {
				current_room.chari.at(0).follow_id = 1;
			}
		}

		current_room.primary_bg = bn::regular_bg_items::grassy_knoll.create_bg(0, 0);

		if (globals->current_save->checkpoint == 5)
			current_room.primary_bg.set_palette(bn::regular_bg_items::castle_floor.palette_item());
		current_room.primary_bg.set_camera(current_room.camera);
		current_room.environment = &bn::sprite_items::ocean_terrain;

		break;
	}
	case 9:
	{
		if (globals->current_save->checkpoint < 12)
		{
			bn::music_items_info::span[26].first.play(0.8);
		}
		current_room.chari.at(0).entity.set_position(3 * 32, 5 * 32);

		if (globals->current_save->checkpoint < 12)
		{
			current_room.configure(7, 7, 3, 5);
			const short int local_col[current_room.width * current_room.height] = {
				1, 1, 1, 1, 1, 1, 1,
				1, 1, 1, 57, 0, 1, 1,
				1, 1, 1, 0, 0, 1, 1,
				1, 1, 1, 0, 0, 0, 1,
				1, 1, 1, 55, 0, 0, 1,
				1, 1, 1, 49, 1, 1, 1,
				1, 1, 1, 1, 1, 1, 1 };

			const short int local[current_room.width * current_room.height] = {
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0 };

			for (short int t = 0; t < current_room.width * current_room.height; t++) {
				globals->local_tileset.push_back(local[t]);
				globals->collisions.push_back(local_col[t]);
			}

			if (globals->current_save->last_char_id != 4)
			{
				character vee(bn::sprite_items::vee_walking_spring, 3, 2, false, current_room.width);
				vee.entity.set_position(3 * 32, 2 * 32);
				vee.entity.set_camera(current_room.camera);
				vee.role = 2;
				vee.identity = 4;
				current_room.chari.push_back(vee);
			}

			if (globals->current_save->last_char_id != 5)
			{
				character eleanor(bn::sprite_items::eleanor_walking_spring, 4, 4, false, current_room.width);
				eleanor.entity.set_position(4 * 32, 4 * 32);
				eleanor.entity.set_camera(current_room.camera);
				eleanor.role = 2;
				eleanor.identity = 5;
				current_room.chari.push_back(eleanor);
			}
		}
		else
		{
			current_room.configure(7, 7, 3, 5);
			const short int local_col[current_room.width * current_room.height] = {
				1, 1, 1, 1, 1, 1, 1,
				1, 1, 1, 0, 0, 1, 1,
				1, 1, 1, 0, 0, 1, 1,
				1, 1, 1, 0, 0, 0, 1,
				1, 1, 1, 55, 0, 0, 1,
				1, 1, 1, 49, 1, 1, 1,
				1, 1, 1, 1, 1, 1, 1 };

			const short int local[current_room.width * current_room.height] = {
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0 };

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++) {
				globals->local_tileset.push_back(local[t]);
				globals->collisions.push_back(local_col[t]);
			}

			if (globals->current_save->checkpoint < 12)
			{
				if (globals->current_save->last_char_id != 4)
				{
					character vee(bn::sprite_items::vee_walking_spring, 3, 2, false, current_room.width);
					vee.entity.set_position(3 * 32, 2 * 32);
					vee.entity.set_camera(current_room.camera);
					vee.role = 2;
					vee.follow_id = 0;
					vee.identity = 4;
					current_room.chari.push_back(vee);
				}

				if (globals->current_save->last_char_id != 5)
				{
					character eleanor(bn::sprite_items::eleanor_walking_spring, 4, 4, false, current_room.width);
					eleanor.entity.set_position(4 * 32, 4 * 32);
					eleanor.entity.set_camera(current_room.camera);
					eleanor.role = 2;
					eleanor.follow_id = 1;
					eleanor.identity = 5;
					current_room.chari.push_back(eleanor);
				}
			}
			else
			{
				if (globals->current_save->last_char_id != 4)
				{
					character vee(bn::sprite_items::vee_walking_spring, 3, 2, false, current_room.width);
					vee.entity.set_position(3 * 32, 2 * 32);
					vee.entity.set_camera(current_room.camera);
					vee.role = 0;
					vee.follow_id = 0;
					vee.identity = 4;
					current_room.chari.push_back(vee);
				}

				if (globals->current_save->last_char_id != 5)
				{
					character eleanor(bn::sprite_items::eleanor_walking_spring, 4, 4, false, current_room.width);
					eleanor.entity.set_position(4 * 32, 2 * 32);
					eleanor.entity.set_camera(current_room.camera);
					eleanor.role = 0;
					eleanor.follow_id = 1;
					eleanor.identity = 5;
					current_room.chari.push_back(eleanor);
				}
			}
		}

		current_room.primary_bg = bn::regular_bg_items::bg_landry_cottage.create_bg(0, 0);
		current_room.primary_bg.set_camera(current_room.camera);
		break;
	}
	case 10:
	{
		bn::music_items_info::span[5].first.play(0.8);
		current_room.chari.at(0).entity.set_position(3 * 32, 5 * 32);

		current_room.configure(7, 7, 3, 5);
		const short int local_col[current_room.width * current_room.height] = {
			1, 1, 1, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 1, 1,
			1, 1, 0, 62, 0, 1, 1,
			1, 1, 0, 0, 0, 1, 1,
			1, 1, 0, 60, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1 };

		const short int local[current_room.width * current_room.height] = {
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0 };

		for (short int t = 0; t < current_room.width * current_room.height; t++) {
			globals->local_tileset.push_back(local[t]);
			globals->collisions.push_back(local_col[t]);
		}

		if (globals->current_save->last_char_id != 6)
		{
			character vee(bn::sprite_items::diana_walking_spring, 3, 2, false, current_room.width);
			vee.entity.set_position(3 * 32, 2 * 32);
			vee.entity.set_camera(current_room.camera);
			vee.role = 2;
			vee.identity = 6;
			current_room.chari.push_back(vee);
		}

		current_room.primary_bg = bn::regular_bg_items::bg_diana_room.create_bg(0, 0);
		current_room.primary_bg.set_camera(current_room.camera);
		break;
	}

	// the creepy garden
	case 11:
	{
		bn::music_items_info::span[12].first.play(0.8);
		current_room.chari.at(0).entity.set_position(15 * 32, 18 * 32);

		current_room.configure(20, 20, 15, 18);
		const short int local_col[current_room.width * current_room.height] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
			1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1,
			1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1,
			1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53, 0, 0, 0, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

		const short int local[current_room.width * current_room.height] = {
			2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
			2, 7, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 14, 0, 3, 21, 28, 30, 2,
			2, 8, 0, 0, 0, 8, 0, 0, 0, 8, 0, 0, 0, 15, 0, 3, 20, 29, 31, 2,
			2, 9, 0, 1, 0, 9, 0, 1, 0, 9, 0, 1, 0, 16, 0, 3, 21, 26, 26, 2,
			2, 10, 0, 0, 0, 10, 0, 0, 0, 10, 0, 0, 0, 17, 0, 3, 2, 27, 27, 2,
			2, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2,
			2, 5, 0, 0, 0, 12, 0, 0, 0, 5, 0, 0, 0, 12, 0, 3, 20, 24, 24, 2,
			2, 6, 0, 1, 0, 13, 0, 1, 0, 6, 0, 1, 0, 13, 0, 3, 21, 28, 30, 2,
			2, 7, 0, 0, 0, 14, 0, 0, 0, 7, 0, 0, 0, 14, 0, 3, 20, 29, 31, 2,
			2, 8, 0, 0, 0, 15, 0, 0, 0, 8, 0, 0, 0, 15, 0, 3, 21, 28, 30, 2,
			2, 9, 0, 0, 0, 16, 0, 0, 0, 9, 0, 0, 0, 16, 0, 3, 20, 29, 31, 2,
			2, 10, 0, 1, 0, 17, 0, 1, 0, 10, 0, 1, 0, 17, 0, 3, 21, 26, 26, 2,
			2, 11, 0, 0, 0, 11, 0, 0, 0, 4, 0, 0, 0, 11, 0, 3, 2, 27, 27, 2,
			2, 12, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2,
			2, 13, 0, 0, 0, 13, 0, 0, 0, 6, 0, 0, 0, 13, 0, 3, 0, 0, 0, 2,
			2, 14, 0, 1, 0, 14, 0, 1, 0, 7, 0, 1, 0, 14, 0, 3, 0, 4, 0, 2,
			2, 15, 0, 0, 0, 15, 0, 0, 0, 8, 0, 0, 0, 15, 0, 3, 0, 5, 0, 2,
			2, 16, 0, 1, 0, 16, 0, 1, 0, 9, 0, 1, 0, 16, 0, 3, 0, 6, 0, 2,
			2, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 3, 0, 0, 0, 2,
			2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2 };

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++) {
			globals->local_tileset.push_back(local[t]);
			globals->collisions.push_back(local_col[t]);
		}

		anim_object fp;
		fp.entity_item = bn::sprite_items::corinne;
		fp.entity = fp.entity_item.create_sprite(0, 0);
		fp.entity_anim = bn::create_sprite_animate_action_forever(fp.entity, 2, fp.entity_item.tiles_item(), 0, 1, 2, 1);
		fp.entity.set_visible(false);
		fp.entity.set_camera(current_room.camera);
		fp.entity.set_position(304, 176);
		current_room.anim_objects.push_back(fp);

		current_room.primary_bg = bn::regular_bg_items::greenhouse_bg_01.create_bg(0, 0);
		current_room.primary_bg.set_camera(current_room.camera);
		current_room.environment = &bn::sprite_items::pools_tiles;
		break;
	}
	case 12:
	{
		current_room.configure(7, 7, 3, 5);
		const short int local_col[current_room.width * current_room.height] = {
			1, 1, 1, 1, 1, 1, 1,
			1, 0, 59, 0, 0, 0, 1,
			1, 0, 1, 1, 1, 0, 1,
			1, 0, 1, 1, 1, 0, 1,
			1, 0, 1, 1, 1, 0, 1,
			1, 0, 0, 58, 0, 0, 1,
			1, 1, 1, 1, 1, 1, 1 };
		const short int local[current_room.width * current_room.height] = {
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0 };

		for (short int t = 0; t < current_room.width * current_room.height; t++) {
			globals->local_tileset.push_back(local[t]);
			globals->collisions.push_back(local_col[t]);
		}

		current_room.primary_bg = bn::regular_bg_items::bg_library.create_bg(0, 0);
		current_room.primary_bg.set_camera(current_room.camera);
		current_room.environment = &bn::sprite_items::environment_stone;
		break;
	}
	case 13:
	{
		bn::music_items_info::span[25].first.play(0.8);
		current_room.chari.at(0).entity.set_position(3 * 32, 5 * 32);

		current_room.configure(7, 7, 3, 5);
		const short int local_col[current_room.width * current_room.height] = {
			1, 1, 1, 1, 1, 1, 1,
			1, 1, 0, 0, 1, 1, 1,
			1, 1, 0, 1, 0, 1, 1,
			1, 1, 0, 1, 0, 1, 1,
			1, 1, 0, 0, 70, 1, 1,
			1, 1, 1, 65, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1 };

		const short int local[current_room.width * current_room.height] = {
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0 };

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++) {
			globals->local_tileset.push_back(local[t]);
			globals->collisions.push_back(local_col[t]);
		}

		if (globals->current_save->last_char_id != 7)
		{
			character guy(bn::sprite_items::guy_walking_spring, 2, 2, false, current_room.width);
			guy.entity.set_position(2 * 32, 2 * 32);
			guy.entity.set_camera(current_room.camera);
			guy.role = 2;
			guy.identity = 7;
			current_room.chari.push_back(guy);
		}

		current_room.primary_bg = bn::regular_bg_items::bg_guy_house.create_bg(0, 0);
		current_room.primary_bg.set_camera(current_room.camera);
		break;
	}
	case 14:
	{
		bn::music_items_info::span[27].first.play(0.8);

		current_room.configure(12, 20, 7, 18);

		const short int local_col[current_room.width * current_room.height] = {
			01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
			01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
			01, 01, 01, 01, 01, 00, 00, 00, 01, 01, 01, 01,
			01, 01, 01, 00, 00, 00, 00, 00, 00, 01, 01, 01,
			01, 01, 01, 01, 01, 01, 00, 00, 00, 01, 01, 01,
			01, 01, 01, 01, 01, 01, 00, 00, 00, 01, 01, 01,
			01, 01, 01, 01, 01, 01, 00, 00, 00, 01, 01, 01,
			01, 01, 01, 01, 01, 00, 00, 00, 00, 01, 01, 01,
			01, 01, 01, 68, 00, 00, 00, 01, 00, 01, 01, 01,
			01, 01, 69, 00, 00, 00, 00, 00, 00, 01, 01, 01,
			01, 01, 00, 00, 00, 00, 00, 00, 00, 01, 01, 01,
			01, 01, 00, 00, 00, 00, 00, 00, 00, 01, 01, 01,
			01, 01, 00, 00, 00, 00, 00, 00, 00, 01, 01, 01,
			01, 01, 00, 00, 00, 00, 00, 00, 00, 01, 01, 01,
			01, 01, 00, 00, 00, 00, 00, 00, 00, 01, 01, 01,
			01, 01, 00, 00, 00, 00, 00, 00, 00, 01, 01, 01,
			01, 01, 00, 00, 00, 00, 00, 00, 00, 01, 01, 01,
			01, 01, 00, 01, 00, 00, 00, 00, 00, 01, 01, 01,
			01, 01, 01, 00, 01, 00, 01, 67, 01, 01, 01, 01,
			01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01 };

		const short int local[current_room.width * current_room.height] = {
			34, 34, 34, 34, 37, 34, 34, 34, 39, 42, 26, 26,
			35, 35, 35, 35, 34, 35, 35, 39, 42, 43, 26, 26,
			34, 34, 38, 47, 39, 0, 0, 0, 43, 11, 13, 26,
			35, 35, 39, 0, 1, 0, 0, 0, 5, 12, 26, 26,
			34, 38, 48, 48, 48, 1, 0, 0, 4, 11, 26, 26,
			35, 39, 49, 49, 49, 27, 0, 0, 5, 12, 26, 26,
			34, 38, 50, 54, 50, 41, 0, 0, 4, 11, 26, 26,
			35, 39, 51, 51, 51, 0, 0, 1, 5, 12, 26, 26,
			34, 38, 44, 0, 0, 0, 0, 27, 4, 11, 26, 26,
			35, 39, 0, 0, 0, 0, 0, 0, 5, 12, 26, 26,
			34, 38, 0, 0, 0, 0, 0, 0, 4, 11, 26, 13,
			35, 39, 0, 2, 0, 0, 0, 14, 6, 12, 26, 26,
			34, 38, 0, 0, 0, 0, 0, 4, 2, 11, 26, 26,
			35, 39, 0, 0, 0, 3, 0, 5, 3, 12, 26, 26,
			34, 38, 0, 0, 0, 0, 0, 4, 2, 11, 26, 26,
			35, 39, 0, 0, 0, 0, 0, 5, 3, 12, 26, 26,
			34, 38, 0, 1, 0, 0, 0, 5, 2, 11, 26, 26,
			35, 39, 0, 27, 0, 0, 14, 6, 3, 12, 13, 26,
			34, 36, 38, 0, 1, 0, 42, 2, 42, 11, 26, 26,
			35, 37, 39, 1, 27, 1, 43, 3, 43, 12, 26, 26 };

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++) {
			globals->local_tileset.push_back(local[t]);
			globals->collisions.push_back(local_col[t]);
		}

		current_room.primary_bg = bn::regular_bg_items::grassy_knoll.create_bg(0, 0);
		current_room.primary_bg.set_camera(current_room.camera);
		current_room.environment = &bn::sprite_items::ocean_terrain;
		break;
	}
	default:
	{
		break;
	}
	};

	// funny hat be like
	auto hat = bn::sprite_items::funny_items.create_sprite(0, 0, 0);
	hat.set_camera(current_room.camera);
	hat.set_visible(false);
	bool active_hat = false;

	for (short int t = 0; t < current_room.chari.size(); t++)
	{
		if (globals->current_save->hat_char == current_room.chari.at(t).identity)
			active_hat = true;
	}
	if (globals->current_save->hat_world == dt.world_index)
		active_hat = true;
	if (active_hat)
		hat.set_visible(true);

	auto l_button = bn::sprite_items::l_button.create_sprite(-90, 14);
	l_button.set_visible(false);

	bn::blending::set_transparency_alpha(1);
	bool jukebox = false;

	globals->rendered_windows.clear();
	{
		bn::rect_window external_window = bn::rect_window::external();
		external_window.set_show_bg(current_room.primary_bg, false);
		external_window.set_show_sprites(false);
		external_window.set_boundaries(-80, -120, 80, 120);
		globals->rendered_windows.push_back(external_window);

		bn::rect_window internal_window = bn::rect_window::internal();
		internal_window.set_show_bg(current_room.primary_bg, true);
		internal_window.set_show_sprites(true);
		internal_window.set_camera(current_room.camera);
		globals->rendered_windows.push_back(internal_window);
	}

	short int window_y = 80;
	current_room.init_render(dt.spawn_x, dt.spawn_y);
	xp_hud xphud;

	while (true)
	{
		xphud.update();

		unsigned short int follow_z = ((current_room.follow_x + 16) / 32) + (((current_room.follow_y + 16) / 32) * current_room.width);

		globals->rendered_windows.at(0).set_boundaries(-80, -120, window_y, 120);
		if (window_y > -80)
			window_y -= 10;

		short int possible_action = globals->collisions.at(follow_z);

		if (possible_action > 1)
		{
			current_room.start_notif(0);

			if (bn::keypad::a_pressed())
			{

				// Start action
				current_room.a_notif.set_scale(1.2, 1.2);
				bn::sound_items::pop.play();
				bn::core::update();

				current_room.a_notif.set_visible(false);
				bn::core::update();
				short int me = current_room.chari.at(current_room.follow_id).identity;

				switch (possible_action)
				{

				case 2:
				{
					line lc[10] = {
						{fals, true, 0, "MAPLE                            Enoki, y'a pas de fenetre."},
						{fals, true, 0, "ENOKI                            Euh?"},
						{fals, true, 0, "MAPLE                            Et si quelqu'un"},
						{fals, true, 0, "MAPLE                            tente de vous voler?"},
						{fals, true, 0, "ENOKI                            Aaron le frappera."},
						{fals, true, 0, "ENOKI                            Dans la face."},
						{fals, true, 0, "MAPLE                            Mais il n'est pas avec nous."},
						{fals, true, 0, "ENOKI                            Alors je vais le frapper."},
						{fals, true, 0, "MAPLE                            Euh... Hum. C'est bien, je       suppose."},
						{true, true, 0, "COM: Endscene"}};
					dialogue_page_lite(lc);
					break;
				};

				case 3:
				{
					line l2[10] = {
						{fals, true, 0, "Vous voyez un vase."},
						{fals, true, 0, "Tu sens que tu devrais le briser."},
						{fals, true, 0, "Mais tu n'y arrives pas."},
						{fals, true, 0, "Une etrange deception t'envahit."},
						{true, true, 0, "COM: Endscene"}};
					dialogue_page_lite(l2);
					break;
				};

				case 4:
				{
					line lc[19] = {
						{fals, true, 0, "MAPLE                            Nous ferions mieux d'y aller."},
						{fals, true, 0, "ENOKI                            C'est bon. Il dort avec la       lumiere allumee."},
						{fals, true, 0, "MAPLE                            Je pensais que ta prise          electrique etait a l'exterieur?"},
						{fals, true, 0, "ENOKI                            Well, on a une autre, c'est la   seule, elle est tres importante."},
						{fals, true, 0, "MAPLE                            Aimes-tu vraiment ]a ici?"},
						{fals, true, 0, "ENOKI                            Es-tu venu juste pour te plaindrede ma maison?"},
						{fals, true, 0, "MAPLE                            Non, pas du tout..."},
						{fals, true, 0, "ENOKI                            Donc, je disais."},
						{fals, true, 0, "MAPLE                            Je m'excuse."},
						{fals, true, 0, "ENOKI                            Merci."},
						{fals, true, 0, "MAPLE                            Mais quand vous allez venir vivrechez moi,"},
						{fals, true, 0, "MAPLE                            Dit pas que je t'avais pas       prevenue."},
						{true, true, 0, "COM: Endscene"}};
					dialogue_page_lite(lc);
					break;
				};

				case 8:
				{
					line lc[9] = {
						{fals, true, 0, "ENOKI                            Savais-tu, quand Del etait ma    gardienne, mes parents lui ont"},
						{fals, true, 0, "ENOKI                            offert trois chambres pour       dormir. Mais Del dormait toujours"},
						{fals, true, 0, "ENOKI                            dans le bain."},
						{fals, true, 0, "MAPLE                            Well, ]a ne sonne pas si mal."},
						{fals, true, 0, "ENOKI                            Ouais, j'ai essaye, mais ma peau n'a pas trop aime."},
						{true, true, 0, "COM: Endscene"}};
					dialogue_page_lite(lc);
					break;
				};

				case 9:
				{
					line lc[9] = {
						{fals, true, 0, "MAPLE                            Enoki, c'est verrouille."},
						{fals, true, 0, "ENOKI                            Oh. Oui, je pense que c'est la   cuisine. Mais on ne sait pas ou"},
						{fals, true, 0, "ENOKI                            est la clef."},
						{fals, true, 0, "MAPLE                            Comment vous faites a manger     d'abord'?"},
						{fals, true, 0, "ENOKI                            Nous cuisinons presque tout sur  le feu de bois!"},
						{fals, true, 0, "MAPLE                            Vous deux, je jure!"},
						{true, true, 0, "COM: Endscene"}};
					dialogue_page_lite(lc);
					break;
				};

				// M and E talking about A
				case 10:
				{
					line lc[20] = {
						{fals, true, 0, "ENOKI                            N'est-il pas trop mignon quand ildort? <3"},
						{fals, true, 0, "MAPLE                            Cela fait pas plusieurs mois que vous etes maries?"},
						{fals, true, 0, "MAPLE                            C'est pas deja l'heure de la     phase dans laquelle vous ne vous"},
						{fals, true, 0, "MAPLE                            parlez pas quand vous mangez et  que vous avez pris 10 livres?"},
						{fals, true, 0, "ENOKI                            Euh, je pense que j'ai meme perdudu poids."},
						{fals, true, 0, "MAPLE                            Je comprendrais jamais."},
						{fals, true, 0, "ENOKI                            C'est pas parce que tu es        toujours en combat avec tes ex"},
						{fals, true, 0, "ENOKI                            que tous les couples sont comme  ]a."},
						{fals, true, 0, "ENOKI                            En plus tu toujours la mauvaise  habitude de-"},
						{fals, true, 0, "MAPLE                            Si tu finit cette phrase,"},
						{fals, true, 0, "MAPLE                            Je vais te bruler les cils."},
						{fals, true, 0, "ENOKI                            ...Mon point est fait."},
						{true, true, 0, "COM: Endscene"}};
					dialogue_page_lite(lc);
					break;
				};

				// The bookshelf room
				case 11:
				{
					line lc[32] = {
						{fals, true, 0, "ENOKI                            Nous sommes ici!"},
						{fals, true, 0, "ENOKI                            Voici la bibliotheque!"},
						{fals, true, 0, "MAPLE                            Je vois que tu ne plaisantais en disant que c'etais juste une"},
						{fals, true, 0, "MAPLE                            bibliotheque..."},
						{fals, true, 0, "ENOKI                            Bon, nous autres on a pas pu la  bouger. Pourrais-tu me rendre"},
						{fals, true, 0, "ENOKI                            service et utiliser ta magie     elfique?"},
						{fals, true, 0, "MAPLE                            Ok si je comprends..."},
						{fals, true, 0, "MAPLE                            Tu veux que je *brule* une       bibliotheque presque neuve?"},
						{fals, true, 0, "ENOKI                            Je veux verifier s'il y a un     passage secret derriere elle ou"},
						{fals, true, 0, "ENOKI                            quelque chose, tu sais?"},
						{fals, true, 0, "MAPLE                            Je refuse. C'est stupide."},
						{fals, true, 0, "MAPLE                            En plus, ces livres ont l'air    bien."},
						{fals, true, 0, "ENOKI                            La plupart son en train de       moisir."},
						{fals, true, 0, "ENOKI                            Je les ai deja verifies. Les     bruler serais la meilleur"},
						{fals, true, 0, "ENOKI                            solutions."},
						{fals, true, 0, "MAPLE                            en es-tu sur?"},
						{fals, true, 0, "ENOKI                            Completement."},
						{fals, true, 0, "MAPLE                            OK, faisons un marche alors."},
						{fals, true, 0, "MAPLE                            Je vais bruler tous bruler, mais tu dois garder un livre."},
						{fals, true, 0, "MAPLE                            Compris?"},
						{fals, true, 0, "ENOKI                            Oui! ... Ok, j'ai pris un livre."},
						{fals, true, 0, "ENOKI                            Utilise le bouton 'R' pour lancerune boule de feu!"},
						{fals, true, 0, "MAPLE                            ...De quoi?"},
						{fals, true, 0, "ENOKI                            Hein? Oh, it's nothing."},
						{true, true, 0, "COM: Endscene"}};
					dialogue_page_lite(lc);
					break;
				};

				// Shoot the bookshelf
				case 12:
				{
					line lc[32] = {
						{fals, true, 0, "MAPLE                            ...."},
						{fals, true, 0, "ENOKI                            Oui..."},
						{fals, true, 0, "MAPLE                            ...."},
						{fals, true, 0, "ENOKI                            Eh bien, il n'y a pas de passage."},
						{fals, true, 0, "MAPLE                            Wow, vraiment."},
						{fals, true, 0, "ENOKI                            Comme c'est etrange."},
						{fals, true, 0, "MAPLE                            Enoki..."},
						{fals, true, 0, "MAPLE                            Je suppose que ]a sert a rien de se facher contre toi, mais tu"},
						{fals, true, 0, "MAPLE                            devrais arreter d'agir comme ]a."},
						{fals, true, 0, "MAPLE                            Toi et Aaron avez depense une    fortune dans un chateau non"},
						{fals, true, 0, "MAPLE                            meuble."},
						{fals, true, 0, "MAPLE                            Et pourquoi? Pour jouer a la     princesse? Pendant ce temps, je"},
						{fals, true, 0, "MAPLE                            sacrifie ma jeunesse dan un      apartemnt en Caroline avec juste"},
						{fals, true, 0, "MAPLE                            le necessaire."},
						{fals, true, 0, "MAPLE                            Enoki... Je t'en pris."},
						{fals, true, 0, "MAPLE                            Je veux pas etre le mechant dans cette histoire."},
						{fals, true, 0, "MAPLE                            Je sai que tu n'aies pas eu une  bonne enfance etant si loin de"},
						{fals, true, 0, "MAPLE                            tes parents..."},
						{fals, true, 0, "MAPLE                            Mais tu peux pas continuer a agircomme ]a. You get it?"},
						{fals, true, 0, "ENOKI                            Je comprends."},
						{fals, true, 0, "MAPLE                            Il est 5 heures du matin, je     retourne me coucher. Je te verrai"},
						{fals, true, 0, "MAPLE                            demain matin, oui?"},
						{fals, true, 0, "ENOKI                            Oui..."},
						{fals, true, 0, "MAPLE                            Ne pense pas trop a ce que j'ai  dit. S'il te plait, bonne nuit."},
						{fals, true, 0, "ENOKI                            Bonne nuit..."},
						{true, true, 0, "COM: Endscene"}};
					dialogue_page_lite(lc);
					break;
				};

				case 13:
				{
					dt.spawn_x = 9;
					dt.spawn_y = 6;
					dt.world_index = 4;
					bn::sound_items::door.play();

					return dt;
					break;
				};

				case 14:
				{
					if (globals->current_save->checkpoint > 3 || globals->current_save->last_char_id == 0)
					{
						dt.spawn_x = 5;
						dt.spawn_y = 3;
						dt.world_index = 5;
						bn::sound_items::door.play();

						return dt;
					}
					break;
				};

				// Clothes pile in Tremblay trailer
				case 16:
				{
					if (me == 0)
					{
						line lc[32] = {
							{fals, true, 0, "(Chacun de ces vetements sont    vraiment a Enoki?)"},
							{fals, true, 0, "(Bien sur, Aaron a les siens.)"},
							{fals, true, 0, "(Ils sont si differents... Je    comprends pas comment il ne"},
							{fals, true, 0, "(dispute pas tous le temps. Je   comprends pas.)"},
							{fals, true, 0, "(Si j'avais un mari, je le       forcerais a ramasser tous ses"},
							{fals, true, 0, "(vetements immediatement.)"},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
					}

					else if (me == 1)
					{
						line lc[32] = {

							{fals, true, 0, "(Si j'avais su que Maple arrivaitsitot, j'aurais nettoyer  plus   vite...)"},
							{fals, true, 0, "(Peut-etre qu'elle va pas        remarquer si je commence a       ramasser maintenant)"},
							{fals, true, 0, "(Mais peut etre qu'elle a deja   remarquer et qu'elle ma juge deja)"},
							{fals, true, 0, "(... Celui-ci est mignon,        peut-etre que je le porterai     demain.)"},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
					}

					else if (me == 2)
					{
						line lc[32] = {
							{fals, true, 0, "(Enoki n'etait pas aussi         malprorpe quand on vivais dans lechateau.)"},
							{fals, true, 0, "(Elle doit penser que nous somme installee et  elle commence a se sentir a l'aise.)"},
							{fals, true, 0, "(Bien que ce soit trop tot pour  le dire, Aaron Tremblay,"},
							{fals, true, 0, "(Tu as reussi. Tu as une maison  a toi et une femme)"},
							{fals, true, 0, "(qui laisse trainer ses vetementspar terre.)"},
							{fals, true, 0, "(Je ne peux penser a rien d'autreque je voudrais avoir en         cemoment.)"},
							{fals, true, 0, "(Well... ma voiture me manque.)"},
							{fals, true, 0, "(Je devrais parler a Scout pour  la mise en place d'une piste de  course.)"},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
					}

					else if (me == 3)
					{
						line lc[32] = {
							{fals, true, 0, "(Je devrais pas etre ici.)"},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
					}

					else
					{
						line lc[32] = {
							{true, true, 0, "(Ces vetements sont la depuis un moment.)"},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
					}

					break;
				};

				case 17:
				{
					if (globals->current_save->checkpoint < 7)
					{
						if (me == 0)
						{
							line lc[32] = {

								{fals, true, 0, "(Au moins, quand ils vivaient    dans le chateau, leur lit etait  au centre de la piece. Pourquoi  "},
								{fals, true, 0, "(c'est comme ]a? Qui dort dans lecoin? Probablement Aaron.)"},
								{fals, true, 0, "(Je jure cette fille va lui      donner des cheveux gris 10 ans   plus tot.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
						if (me == 1)
						{
							line lc[32] = {
								{fals, true, 0, "(Je suis contente de ne pas      avoira dormir au milieu de la    piece.)"},
								{fals, true, 0, "(Rouler hors du lit sur le sol   enpierre faisait tres mal.)"},
								{fals, true, 0, "(Maintenant, je peux rouler en   toute securite vers le mur ou    vers Aaron.)"},
								{fals, true, 0, "(Je suis tellement heureuse que  ]a ne le derange pas trop.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
						if (me == 2)
						{
							line lc[32] = {
								{fals, true, 0, "(Maple ne sera pas contente      quandelle verra cette piece.)"},
								{fals, true, 0, "(Je me souviens quand elle etait plus calme...)"},
								{fals, true, 0, "(MAintenat, c'est un peu         frustrant de l'avoir avec nous.)"},
								{fals, true, 0, "(Peut-etre qu'elle n'aurait pas  du venir. Chaque fois que)"},
								{fals, true, 0, "(j'essai ede l'aider, elle ne    fait que se plaindre et s'en     prendre a moi.)"},
								{fals, true, 0, "(Elle pourrait s'ennuyer de      vivreici et rentrer chez elle.)"},
								{fals, true, 0, "(Ou peut-etre qu'elle a raison   etque je vis dans la fantaisie   d'Enoki.)"},
								{fals, true, 0, "(Mais Enoki est le seul bonheur  que j'aie depuis des annees.)"},
								{fals, true, 0, "(Ont vas peut-etre changer, ou   que quelque chose va changer...)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
						if (me == 3)
						{
							line lc[32] = {

								{true, true, 0, "(Je ne devrais pas entree sans   etre invite...)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
					}
					else if (globals->current_save->checkpoint < 10)
					{
						if (me == 0)
						{
							line lc[32] = {
								{fals, true, 0, "(Je vais surement jamais         l'admettre, mais...)"},
								{fals, true, 0, "(C'est super d'etre avec eux.    Parfois, j'oublie a quel point ]a"},
								{fals, true, 0, "memanque de vivre avec           quelqu'un.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
						if (me == 1)
						{
							line lc[32] = {
								{fals, true, 0, "(Parfois j'aimerais pouvoir      remonter le temps pour me parler)"},
								{fals, true, 0, "(Je ne pourrais jamais croire    comment cette annee ce passe.)"},
								{fals, true, 0, "(Et... je ne pense pas que mes   parents sachent que je suis ici.)"},
								{fals, true, 0, "(Je me demande ou ils pensent    queje suis en ce moment.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
						if (me == 2)
						{
							line lc[32] = {
								{fals, true, 0, "(J'ai besoin de trouver une      placepour Maple.)"},
								{fals, true, 0, "(Je ne pensais pas qu'elle se    donnerait a font pour sa part...)"},
								{fals, true, 0, "(Avec toute cette speleologie,   ona reussi a atteindre le seuil  de rentabilite.)"},
								{fals, true, 0, "(Je suis surpris qu'elle n'a pas demandee un nouveau logement.)"},
								{fals, true, 0, "(Peut etre qu'elle n'aime pas    rester seule?)"},
								{fals, true, 0, "(Et je ne veux pas construire    uneautre maison.)"},
								{fals, true, 0, "(Je vais parler a cet Olivier et voir ce qu'il peut faire.)"},
								{fals, true, 0, "(Il semble etre bon avec ses     mains.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
						if (me == 3)
						{
							line lc[32] = {
								{fals, true, 0, "(Oui, c'est une chambre.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
						if (me == 4)
						{
							line lc[32] = {
								{fals, true, 0, "(J'aime le soleil ici.)"},
								{fals, true, 0, "(Je pourrais mettre des plantes.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
						if (me == 5)
						{
							line lc[32] = {
								{fals, true, 0, "(..]a me rappelle beaucoup la    maison des parents de Vee.)"},
								{fals, true, 0, "(J'espere que ce sont des gens   deconfiance.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
						if (me == 6)
						{
							line lc[32] = {
								{fals, true, 0, "(Ok, j'aime ces gens.)"},
								{fals, true, 0, "(Ils me font me sentir propre.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
					}
					else if (globals->current_save->checkpoint < 12)
					{
						if (me == 0)
						{
							line lc[32] = {
								{fals, true, 0, "(Merci mon Dieu, le nouvel       arrivant est cuisinier.)"},
								{fals, true, 0, "(Manger la meme chose encore et  encore ne seras pas aussi lourd   quand je fais pas la cuisine.)"},
								{fals, true, 0, "(Esperons qu'il a le sens de     l'humour.)"},
								{fals, true, 0, "(Ugh, je sais pas ce qui va pas  chez moi.Je suis contente de le   rencontrer?)"},
								{fals, true, 0, "(Je vais perdre la carte si je   deviens sociable...)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
						else if (me == 1)
						{
							line lc[32] = {
								{fals, true, 0, "(Cette piece n'a pas change du   tout.)"},
								{fals, true, 0, "(Et si je depla]ais le lit de    l'autre cote?)"},
								{fals, true, 0, "(Hmm, ]a sera plus difficile de  cacher nos vetements aux         invites.)"},
								{fals, true, 0, "(Je devrais recuperer tous...    euh......... mieux vaut le faire plus tard.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
						else if (me == 2)
						{
							line lc[32] = {
								{fals, true, 0, "(C'est la derniere chance a Maplede prendre la cabine.)"},
								{fals, true, 0, "(Tant que Enoki est contente,    Maple reste dans la maison.)"},
								{fals, true, 0, "(Mais ]a sera plus ma maison. Je sais pas quelle mouche l'a       pique.)"},
								{fals, true, 0, "(Utilise-t-elle sa fierte pour   cacher la sangsue qu'elle est    vraiment?)"},
								{fals, true, 0, "(Et Enoki commence a realiser queje suis enerve.)"},
								{fals, true, 0, "(Merde... Je sonne comme Maple.)"},
								{fals, true, 0, "(Est-ce que tous les freres et   soeurs sont comme nous?)"},
								{fals, true, 0, "(J'aimerais pouvoir le demander  aquelqu'un, mais je n'ai pas     d'amis.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
						else if (me == 3)
						{
							line lc[32] = {
								{fals, true, 0, "(L'anniversaire d'Aaron approche.Une plante serait un beau        cadeau.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
						else if (me == 7)
						{
							line lc[32] = {
								{fals, true, 0, "(J'aime le soleil ici.)"},
								{fals, true, 0, "(Je pourrais mettre des plantes.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
						else
						{
							line lc[32] = {
								{fals, true, 0, "(Je ne devrais pas fouiller ici.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
					}
					break;
				};

				// Tremblay bookcase?
				case 18:
				{
					if (globals->current_save->checkpoint < 7)
					{
						if (me == 0)
						{
							line lc[32] = {
								{fals, true, 0, "MAPLE                            He, c'est quoi ce livre?"},
								{fals, true, 0, "AARON                            Oh, c'est a moi."},
								{fals, true, 0, "AARON                            Tu sais que j'aime pas beaucoup  la fiction,"},
								{fals, true, 0, "AARON                            Mais Enoki est parfois un peu    tetue."},
								{fals, true, 0, "ENOKI                            Connais tu Yellow?"},
								{fals, true, 0, "ENOKI                            C'est tellement amusant, J'ai    demander a Aaron d'essayer."},
								{fals, true, 0, "MAPLE                            ...c'es tu un livre a images?"},
								{fals, true, 0, "MAPLE                            Lis tu encore des livres avec desimages?"},
								{fals, true, 0, "ENOKI                            Mais c'est des images de         cigarettes!"},
								{fals, true, 0, "ENOKI                            Alors c'est pour les enfants et  adultes."},
								{fals, true, 0, "MAPLE                            Hein, ]a existe des livres comme ]a?"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}

						if (me == 1)
						{
							line lc[32] = {
								{fals, true, 0, "ENOKI                            Oh, hey Maple, veux tu du jus?"},
								{fals, true, 0, "MAPLE                            Quel  jus?"},
								{fals, true, 0, "ENOKI                            C'est un secret."},
								{fals, true, 0, "MAPLE                            Je vais pas un liquide mystere."},
								{fals, true, 0, "ENOKI                            ...."},
								{fals, true, 0, "ENOKI                            Allez, c'est...                  du jus d'orange        POISON", 9},
								{fals, true, 0, "MAPLE                            Tu ne pensais pas que je le      decouvrirai en y goutant?"},
								{fals, true, 0, "ENOKI                            Peut-etre?"},
								{fals, true, 0, "MAPLE                            Merci, mais non."},
								{true, true, 0, "COM: Endscene"},
								{fals, true, 0, "MAPLE                            Venant de toi, c'est possible."},
								{fals, true, 0, "ENOKI                            Tu peux l'essayer pour le        decouvrir."},
								{fals, true, 0, "MAPLE                            J'ai pas si soif."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}

						if (me == 2)
						{
							line lc[32] = {
								{fals, true, 0, "(Il nous reste pas beaucoup de   jus d'orange.)"},
								{fals, true, 0, "(Je vais devoir aller en ville   pour vendre nos produits.)"},
								{fals, true, 0, "(Vendre un fruit pour en acheter un autre, comique.)"},
								{fals, true, 0, "(Si seulement le jus de patate   avait meilleur gout...)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}

						if (me == 3)
						{
							line lc[32] = {
								{fals, true, 0, "ENOKI                            EEEE! Tous mes amis se           connaissent maintenant!"},
								{fals, true, 0, "ENOKI                            Nous sommes un vrai un groupe    enfin!"},
								{fals, true, 0, "MAPLE                            Wow, je n'ai pas encore decide   si-"},
								{fals, true, 0, "MAPLE                            Si je reste ici, calme-toi."},
								{fals, true, 0, "SCOUT                            On doit tu attendre quelqu'un    d'autre?"},
								{fals, true, 0, "AARON                            Nous devrons attendre et voir    quelqu'un arrive."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
					}

					else if (globals->current_save->checkpoint < 10)
					{
						if (me < 3)
						{
							line lc[32] = {
								{fals, true, 0, "MAPLE                            Bon je les ai tous lus."},
								{fals, true, 0, "AARON                            ..]a fait un moment que nous     sommes pas alles en ville."},
								{fals, true, 0, "MAPLE                            Je me demande ce qui se passe    la-bas."},
								{fals, true, 0, "ENOKI                            Si quelque chose de grave s'etaitproduit."},
								{fals, true, 0, "ENOKI                            Scout aurait dit quelque chose."},
								{fals, true, 0, "ENOKI                            Comme il est toujours sur        Internet."},
								{fals, true, 0, "MAPLE                            Je pourrais lui demander de      m'acheter des livres en ligne."},
								{fals, true, 0, "AARON                            Ce serait une bonne idee."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
						else
						{
							line lc[32] = {
								{fals, true, 0, "Vous voyez un tas de livres que  vous n'avez jamais vus auparavant."},
								{fals, true, 0, "Mais aucun ne semble             interessant... Pour l'instant."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
					}
					else if (globals->current_save->checkpoint < 12)
					{
						if (me < 3)
						{
							line lc[32] = {
								{fals, true, 0, "MAPLE                            On devrais acheter un lecteur    VHS."},
								{fals, true, 0, "AARON                            Vas-tu en acheter un?"},
								{fals, true, 0, "MAPLE                            Oui, et beaucoup de cassettes."},
								{fals, true, 0, "ENOKI                            Oooh, peux-tu acheter le dernier film Time Raider? Je crois qu'il"},
								{fals, true, 0, "ENOKI                            est sorti!"},
								{fals, true, 0, "MAPLE                            Tu sais quoi, je vais acheter    tout, SAUF celui-la."},
								{fals, true, 0, "ENOKI                            Aw... Je pensais que nous        pourrions faire."},
								{fals, true, 0, "ENOKI                            ... Une soiree cinema?"},
								{fals, true, 0, "MAPLE                            Okay, PEUT-ETRE."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
						else if (me == 7)
						{
							line lc[32] = {
								{fals, true, 0, "Tu souris en pensant a leur      cuisine inferieure."},
								{fals, true, 0, "Ils deviendront certainement des clients reguliers."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
						else
						{
							line lc[32] = {
								{true, true, 0, "Aucun des livres ne semble       interessant."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
					}
					break;
				};
				case 19:
				{
					dt.spawn_x = 8;
					dt.spawn_y = 10;
					dt.world_index = 4;
					bn::sound_items::door.play();

					return dt;
					break;
				};
				case 20:
				{
					if (globals->current_save->checkpoint < 12 || current_room.chari.at(current_room.follow_id).identity != 2 || globals->current_save->checkpoint == 13)
					{
						dt.spawn_x = 7;
						dt.spawn_y = 3;
						dt.world_index = 6;
						bn::sound_items::door.play();
						return dt;
					}
					else
					{
						line lc[32] = {
							{fals, true, 0, "AARON                            J'ai besoin de voir comment vont les autres."},
							{true, true, 0, "COM: Endscene"},
						};
						dialogue_page_lite(lc);
						break;
					}
					break;
				};
				case 21:
				{
					line lc[32] = {
						{fals, true, 0, "LE JARDIN D'ENOKI                Tu touches, tu meur."},
						{true, true, 0, "COM: Endscene"},
					};
					dialogue_page_lite(lc);
					break;
				};
				case 22:
				{
					line lc[32] = {
						{fals, true, 0, "POINT DE COUPE DU BOIS           Ou on coupe le bois."},
						{true, true, 0, "COM: Endscene"}};
					dialogue_page_lite(lc);
					break;
				};
				case 23:
				{
					if (me == 1)
					{
						dt.spawn_x = 2;
						dt.spawn_y = 0;
						dt.world_index = 99;

						return dt;
					}
					else
					{
						line lc[32] = {
							{fals, true, 0, "Hmmm... ..]a semble etre une     tache pour Enoki."},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
					}
					break;
				};
				case 24:
				{
					if (me == 2)
					{
						dt.spawn_x = 1;
						dt.spawn_y = 0;
						dt.world_index = 99;
						bn::sound_items::door.play();

						return dt;
					}
					else
					{
						line lc[32] = {
							{fals, true, 0, "Hmmm... ..]a semble etre une     mission pour Aaron."},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
					}
					break;
				};
				case 25:
				{
					line lc[32] = {
						{fals, true, 0, "GROTTE DES CHAUVES-SOURIS        agressive Attention :            Contient des chauves-souris."},
						{true, true, 0, "COM: Endscene"}};
					dialogue_page_lite(lc);
					break;
				};
				case 26:
				{
					if (me == 0)
					{
						dt.spawn_x = 3;
						dt.spawn_y = 0;
						dt.world_index = 99;
						bn::sound_items::door.play();
						return dt;
					}
					else
					{
						line lc[32] = {
							{fals, true, 0, "Je pense que Maple est la seule  apouvoir entrer en toute securite."},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
					}
					break;
				};

				// Dirt in jars
				case 27:
				{
					if (globals->current_save->checkpoint < 7)
					{
						if (me == 0)
						{
							line lc[32] = {
								{fals, true, 0, "MAPLE                            Des plantes, hein?"},
								{fals, true, 0, "MAPLE                            Y a-t-il un jardin aussi?"},
								{fals, true, 0, "SCOUT                            Enfaite, je, euh-"},
								{fals, true, 0, "SCOUT                            C'est pas vraiment pour les      plantes"},
								{fals, true, 0, "SCOUT                            Je suis un scientifique pour le  sol."},
								{fals, true, 0, "MAPLE                            Un scientifique pour le sol?"},
								{fals, true, 0, "SCOUT                            Il y a un scientifique pour      beauc..."},
								{fals, true, 0, "SCOUT                            Eh bien, pour tout, vraiment."},
								{fals, true, 0, "MAPLE                            Je vois ]a."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 1)
						{
							line lc[32] = {
								{fals, true, 0, "ENOKI                            JE PENSE que c'est la bonne      plante."},
								{fals, true, 0, "ENOKI                            C'est ma favorite."},
								{fals, true, 0, "SCOUT                            Veux-tu que je la coupe?"},
								{fals, true, 0, "ENOKI                            Tu peux le faire?"},
								{fals, true, 0, "SCOUT                            Je sais pas..."},
								{fals, true, 0, "SCOUT                            J'etudie le sol, pas les plantes."},
								{fals, true, 0, "ENOKI                            ..]a pourrait etre un fruit      mysterieux!"},
								{fals, true, 0, "SCOUT                            Et bien... C'est possible."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 2)
						{
							line lc[32] = {
								{fals, true, 0, "AARON                            Tu as fait des progres?"},
								{fals, true, 0, "SCOUT                            Et oui!"},
								{fals, true, 0, "SCOUT                            J'ai fait quelque chose de       nouveau."},
								{fals, true, 0, "AARON                            Comment ]a s'appelle?"},
								{fals, true, 0, "SCOUT                            Je l'ai baptise 'Scout-Out'."},
								{fals, true, 0, "SCOUT                            C'est parfait pour les mauvaises herbes."},
								{fals, true, 0, "AARON                            Bougre, c'est tellement cool!"},
								{fals, true, 0, "SCOUT                            Le seul tracas c'est que..."},
								{fals, true, 0, "SCOUT                            ..]a detruit tous les plantes."},
								{fals, true, 0, "AARON                            Ah, triste..."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 3)
						{
							line lc[32] = {
								{fals, true, 0, "(Oh non, oh non, oh non...!)"},
								{fals, true, 0, "(Je dois comprendre la formule   aussi vite que possible.)"},
								{fals, true, 0, "(Promettre de la terre magique   aux investisseurs n'etait pas une  bonne idee.)"},
								{fals, true, 0, "(Si je me cache ici, ils ne me   trouveront pas.)"},
								{fals, true, 0, "(Mais je devrais enlever mon nom de la trappe ...)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
					}
					else if (globals->current_save->checkpoint < 10)
					{
						if (me == 0)
						{
							line lc[32] = {
								{fals, true, 0, "MAPLE                            Toujours la meme routine?"},
								{fals, true, 0, "SCOUT                            Oui, oui."},
								{fals, true, 0, "MAPLE                            Ils n'ont pas encore demande"},
								{fals, true, 0, "MAPLE                            les resultats?"},
								{fals, true, 0, "SCOUT                            Pas encore, mais je re]ois       toujours"},
								{fals, true, 0, "SCOUT                            un salaire chaque semaine."},
								{fals, true, 0, "MAPLE                            He, c'est parfait."},
								{fals, true, 0, "SCOUT                            Oh que oui."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 3)
						{
							line lc[32] = {
								{fals, true, 0, "(Maple regarde les plantes de    temps en temps...)"},
								{fals, true, 0, "(Au moins, elle a une opinion    sur]a.)"},
								{fals, true, 0, "(J'ai besoin que mon patron      reponde vite a mes messages.)"},
								{fals, true, 0, "(Mais avec mon bon salaire, je   nedevrais pas trop le risquer.)"},
								{fals, true, 0, "(Je dois juste m'assurer que je  fais tous comme il le faut.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else
						{
							line lc[32] = {
								{fals, true, 0, "(Beaucoup de plantes et de terresdans des bocaux.)"},
								{fals, true, 0, "(Tu ne comprends pas vraiment,   mais cela semble inoffensif.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
					}
					else if (globals->current_save->checkpoint < 12)
					{
						if (me == 0)
						{
							line lc[32] = {
								{fals, true, 0, "SCOUT                            He, euh... Maple?"},
								{fals, true, 0, "SCOUT                            Puis-je poser une question?"},
								{fals, true, 0, "MAPLE                            Bien sur?"},
								{fals, true, 0, "SCOUT                            A... aime... Aime tu le tennis?"},
								{fals, true, 0, "MAPLE                                                             J'aime le tennis!       Brute!", 14},
								{fals, true, 0, "MAPLE                            Pourquoi?"},
								{fals, true, 0, "SCOUT                            Oh, rien, rien... J'ai juste..."},
								{fals, true, 0, "MAPLE                            Tu veux jouer avec moi?"},
								{fals, true, 0, "SCOUT                            J'ai toujours desire y jouer,    mais j'ai personne avec qui"},
								{fals, true, 0, "SCOUT                            jouer, tu comprend?"},
								{fals, true, 0, "MAPLE                            Bien, trouve un terrain et je    vais te montrer un truc ou deux."},
								{fals, true, 0, "SCOUT                            T'es serieuse?"},
								{fals, true, 0, "MAPLE                            Bien sur."},
								{fals, true, 0, "SCOUT                            Merci!"},
								{true, true, 0, "COM: Endscene"},
								{fals, true, 0, "SCOUT                            Oh, laisse faire."},
								{fals, true, 0, "MAPLE                            D'accord."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 2)
						{
							line lc[32] = {
								{fals, true, 0, "AARON                            Ecoute-moi une minute."},
								{fals, true, 0, "AARON                            Tu as un outil pour"},
								{fals, true, 0, "AARON                            fabriquer des bunkers avec"},
								{fals, true, 0, "AARON                            facilite, non? On peut faire-"},
								{fals, true, 0, "AARON                            Une course sous-terrain!"},
								{fals, true, 0, "SCOUT                            Oh, C'est une super idee!"},
								{fals, true, 0, "SCOUT                            Je vais voir ce que je peux      faire!"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 3)
						{
							line lc[32] = {
								{fals, true, 0, "(Well, le moment est venu. Ils   veulent que je montre mes          echantillons.)"},
								{fals, true, 0, "(Avec espoir, je vais garder mon travaille.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else
						{
							line lc[32] = {
								{fals, true, 0, "(Beaucoup de plantes et de terresdans des bocaux.)"},
								{fals, true, 0, "(Tu ne comprends pas vraiment,   mais cela semble inoffensif.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
					}

					break;
				};

				// le Scout comic book bit
				case 28:
				{
					if (globals->current_save->checkpoint < 7)
					{
						if (me == 0)
						{
							line lc[32] = {
								{fals, true, 0, "MAPLE                            He, regarde, un autre truc de    nerds."},
								{fals, true, 0, "SCOUT                            Excusez-moi, mademoiselle!"},
								{fals, true, 0, "SCOUT                            C'est les Time Raiders!"},
								{fals, true, 0, "MAPLE                            Time... Raiders?"},
								{fals, true, 0, "SCOUT                            Oui! Les aventures de"},
								{fals, true, 0, "SCOUT                            Jahn-Jahn Gazebo et ses          apprentis, Nexus et Ninjette!"},
								{fals, true, 0, "MAPLE                            ..]a sonne vraiment comme..."},
								{fals, true, 0, "MAPLE                            As-tu deja ete en couple?"},
								{fals, true, 0, "SCOUT                            Non, les filles me prenaient pourun nerd."},
								{fals, true, 0, "MAPLE                            Crois-moi, elles le pensent      encore."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 1)
						{
							line lc[32] = {
								{fals, true, 0, "ENOKI                            Ah! C'est Time Raiders?"},
								{fals, true, 0, "SCOUT                            Tu connais Time Raiders?"},
								{fals, true, 0, "ENOKI                            'J'ai compris, Jahn-Jahn!'"},
								{fals, true, 0, "SCOUT                            Enfin quelqu'un d'autre connais  ]a!"},
								{fals, true, 0, "ENOKI                            Oui, Aaron m'a montre ]a."},
								{fals, true, 0, "ENOKI                            J'aime le style de dessin."},
								{fals, true, 0, "ENOKI                            Veux-tu me le preter?"},
								{fals, true, 0, "SCOUT                            Bien sur! J'ai presque fini."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 2)
						{
							line lc[32] = {
								{fals, true, 0, "AARON                            He, c'est pas Time Raiders?"},
								{fals, true, 0, "SCOUT                            Oh que oui!"},
								{fals, true, 0, "AARON                            Cool! As-tu vus le dernier?"},
								{fals, true, 0, "SCOUT                            Pas encore."},
								{fals, true, 0, "SCOUT                            Quelque chose que j'ai appris    avec ma 'Island Life', c'est que"},
								{fals, true, 0, "SCOUT                            s'est difficile d'obtenir de     nouvelles choses."},
								{fals, true, 0, "SCOUT                            Je pourrais continuer a lire sur le PC, mais ce n'est pas"},
								{fals, true, 0, "SCOUT                            du tout pareil."},
								{fals, true, 0, "AARON                            Je comprends."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 3)
						{
							line lc[32] = {
								{fals, true, 0, "(Je dois finir pour pouvoir      l'offrir a Enoki.)"},
								{fals, true, 0, "(Mais la formule que j'ai        promise... Je suis si proche.)"},
								{fals, true, 0, "(Je vais devoir faire d'autres   nuits blanches.)"},
								{fals, true, 0, "(Encore un peu de temps et je    vais reussir.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
					}
					else if (globals->current_save->checkpoint < 10)
					{

						if (me == 0)
						{
							line lc[32] = {
								{fals, true, 0, "SCOUT                            He, tu aimes vraiment lire des   livres?"},
								{fals, true, 0, "MAPLE                            Oh que oui."},
								{fals, true, 0, "SCOUT                            Penses-tu que je pourrais        emprunter"},
								{fals, true, 0, "SCOUT                            certain de tes livres?"},
								{fals, true, 0, "MAPLE                            T'aimerais pas ]a."},
								{fals, true, 0, "SCOUT                            Au moins, je veux essayer."},
								{fals, true, 0, "MAPLE                            Aimes-tu la romance?"},
								{fals, true, 0, "MAPLE                            Des relations compliquees?"},
								{fals, true, 0, "SCOUT                            Eh... Tu en a pas d'autres?"},
								{fals, true, 0, "MAPLE                            Non, c'est ce que j'aime."},
								{fals, true, 0, "MAPLE                            Es tu mal a l'aise?"},
								{fals, true, 0, "SCOUT                            ... Un peu."},
								{fals, true, 0, "MAPLE                            Continue a lire des bandes       dessinees."},
								{true, true, 0, "COM: Endscene"},
							};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 1)
						{
							line lc[32] = {
								{fals, true, 0, "SCOUT                            He, Enoki?"},
								{fals, true, 0, "ENOKI                            Oui?"},
								{fals, true, 0, "SCOUT                            Peut-on parler de Maple?"},
								{fals, true, 0, "ENOKI                            Oooh, a propos de quoi?"},
								{fals, true, 0, "ENOKI                            TU AIMES Maple, hein?"},
								{fals, true, 0, "SCOUT                            Oui?"},
								{fals, true, 0, "ENOKI                            Nous le savons tous deja, hehe."},
								{fals, true, 0, "SCOUT                            Merde, c'est si evident?"},
								{fals, true, 0, "ENOKI                            Mais elle est compliquee."},
								{fals, true, 0, "ENOKI                            Je l'ai presentee une fois a un  gar]on."},
								{fals, true, 0, "SCOUT                            Eh puis?"},
								{fals, true, 0, "ENOKI                            Et ils sont sortis ensemble      pendant un moment."},
								{fals, true, 0, "ENOKI                            Mais il l'enervait donc elle la  quitte."},
								{fals, true, 0, "ENOKI                            Tu dois etre parfait pour elle."},
								{fals, true, 0, "SCOUT                            Et je ne le suis pas."},
								{fals, true, 0, "ENOKI                            Je ne connais personne de        parfait."},
								{fals, true, 0, "SCOUT                            Eh bien, un homme peut rever."},
								{fals, true, 0, "ENOKI                            Ne change pas comment tu es."},
								{fals, true, 0, "ENOKI                            Tu n'as qu'a etre 'toi-meme'."},
								{fals, true, 0, "SCOUT                            Je suppose que tu as raison."},
								{fals, true, 0, "ENOKI                            Tu trouveras la bonne."},
								{fals, true, 0, "SCOUT                            Ok. Merci, Enoki."},
								{fals, true, 0, "ENOKI                            De rien!"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 2)
						{
							line lc[32] = {
								{fals, true, 0, "SCOUT                            Ehm... comment es-tu sorti avec"},
								{fals, true, 0, "SCOUT                            Enoki pour la premiere fois?"},
								{fals, true, 0, "AARON                            Je lui est acheter du cafe."},
								{fals, true, 0, "SCOUT                            Cafe, cafe... D'accord."},
								{fals, true, 0, "SCOUT                            J'ai pas, hmm...  De cafe..."},
								{fals, true, 0, "AARON                            Tu veux sortir avec Maple?"},
								{fals, true, 0, "SCOUT                            Well, je... Oui, j'aimerais bien."},
								{fals, true, 0, "AARON                            Tu pourrais essayer, mais c'est  complique. Aucun gar]on n'est"},
								{fals, true, 0, "AARON                            assez bien pour elle."},
								{fals, true, 0, "SCOUT                            C'est peut-etre inutile          d'essayer."},
								{fals, true, 0, "AARON                            C'est impossible de lui plaire."},
								{fals, true, 0, "AARON                            Crois-moi, je la connais bien."},
								{fals, true, 0, "SCOUT                            Que veux-tu dire?"},
								{fals, true, 0, "AARON                            Son type est les perdants qui    pensent qu'ils sont meilleurs"},
								{fals, true, 0, "AARON                            qu'ils ne le sont. C'est vrai."},
								{fals, true, 0, "AARON                            Je l'ai aussi vu sortir avec     d'autres types de perdants."},
								{fals, true, 0, "AARON                            Probablement que tu dois juste   faire des efforts pour augmenter"},
								{fals, true, 0, "AARON                            ta confiance?"},
								{fals, true, 0, "SCOUT                            Eh bien, c'est un bon debut."},
								{fals, true, 0, "AARON                            Bonne chance avec elle."},
								{fals, true, 0, "SCOUT                            Merci."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 3)
						{
							line lc[32] = {
								{fals, true, 0, "(Si je peux convaincre Maple de  donner une chance a ces bandes    dessinees.)"},
								{fals, true, 0, "(Alors nous pourrions avoir      quelque chose en commun.)"},
								{fals, true, 0, "(.....]a arrivera jamais.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 7)
						{
							line lc[32] = {
								{fals, true, 0, "GUY                              Aimes-tu Time Raiders?"},
								{fals, true, 0, "SCOUT                            Oui, un peu."},
								{fals, true, 0, "GUY                              Quand est-ce que tu re]ois les   nouveaux?"},
								{fals, true, 0, "SCOUT                            Diana les apporte chaque semaine."},
								{fals, true, 0, "GUY                              Quel soulagement, je pensais ne  pas pouvoir suivre quand j'ai    "},
								{fals, true, 0, "demenage ici."},
								{fals, true, 0, "SCOUT                            Mais on a une liste d'attente."},
								{fals, true, 0, "SCOUT                            Il faudra que tu attendes        qu'Enoki termine, elle les adore."},
								{fals, true, 0, ""},
								{fals, true, 0, "GUY                              Et si je veux les lire en        premier?"},
								{fals, true, 0, "SCOUT                            Tu devras lui en parler."},
								{fals, true, 0, "GUY                              Je vais le faire."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else
						{
							line lc[32] = {
								{fals, true, 0, "(Les bandes dessinees du mois    dernier trainent toujours sur le    sol.)"},
								{fals, true, 0, "(Elle collecte la poussiere.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
					}
					else if (globals->current_save->checkpoint < 12)
					{
						if (me == 0)
						{
							line lc[32] = {
								{fals, true, 0, "SCOUT                            He, tu aimes vraiment lire des   livres?"},
								{fals, true, 0, "MAPLE                            Oh que oui."},
								{fals, true, 0, "SCOUT                            Penses-tu que je pourrais        emprunter"},
								{fals, true, 0, "SCOUT                            certain de tes livres?"},
								{fals, true, 0, "MAPLE                            T'aimerais pas ]a."},
								{fals, true, 0, "SCOUT                            Au moins, je veux essayer."},
								{fals, true, 0, "MAPLE                            Aimes-tu la romance?"},
								{fals, true, 0, "MAPLE                            Des relations compliquees?"},
								{fals, true, 0, "SCOUT                            Eh... Tu en a pas d'autres?"},
								{fals, true, 0, "MAPLE                            Non, c'est ce que j'aime."},
								{fals, true, 0, "MAPLE                            Es tu mal a l'aise?"},
								{fals, true, 0, "SCOUT                            ... Un peu."},
								{fals, true, 0, "MAPLE                            Continue a lire des bandes       dessinees."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 1)
						{
							line lc[32] = {
								{fals, true, 0, "SCOUT                            He, Enoki?"},
								{fals, true, 0, "ENOKI                            Oui?"},
								{fals, true, 0, "SCOUT                            Peut-on parler de Maple?"},
								{fals, true, 0, "ENOKI                            Oooh, a propos de quoi?"},
								{fals, true, 0, "ENOKI                            TU AIMES Maple, hein?"},
								{fals, true, 0, "SCOUT                            Oui?"},
								{fals, true, 0, "ENOKI                            Nous le savons tous deja, hehe."},
								{fals, true, 0, "SCOUT                            Merde, c'est si evident?"},
								{fals, true, 0, "ENOKI                            Mais elle est compliquee."},
								{fals, true, 0, "ENOKI                            Je l'ai presentee une fois a un  gar]on."},
								{fals, true, 0, "SCOUT                            Eh puis?"},
								{fals, true, 0, "ENOKI                            Et ils sont sortis ensemble      pendant un moment."},
								{fals, true, 0, "ENOKI                            Mais il l'enervait donc elle la  quitte."},
								{fals, true, 0, "ENOKI                            Tu dois etre parfait pour elle."},
								{fals, true, 0, "SCOUT                            Et je ne le suis pas."},
								{fals, true, 0, "ENOKI                            Je ne connais personne de        parfait."},
								{fals, true, 0, "SCOUT                            Eh bien, un homme peut rever."},
								{fals, true, 0, "ENOKI                            Ne change pas comment tu es."},
								{fals, true, 0, "ENOKI                            Tu n'as qu'a etre 'toi-meme'."},
								{fals, true, 0, "SCOUT                            Je suppose que tu as raison."},
								{fals, true, 0, "ENOKI                            Tu trouveras la bonne."},
								{fals, true, 0, "SCOUT                            Ok. Merci, Enoki."},
								{fals, true, 0, "ENOKI                            De rien!"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 2)
						{
							line lc[32] = {
								{fals, true, 0, "AARON                            As-tu entendu parler du bug de   l'an 2000?"},
								{fals, true, 0, "SCOUT                            Bien sur."},
								{fals, true, 0, "AARON                            Rien n'est arrive?"},
								{fals, true, 0, "SCOUT                            Rien de trop grave."},
								{fals, true, 0, "SCOUT                            Une application m'a donne un     probleme plutot etrange."},
								{fals, true, 0, "SCOUT                            J'avais un programme pour        organiser mes achats et ]a a     "},
								{fals, true, 0, "ajoute des tonnes de cire a      soulier a la liste."},
								{fals, true, 0, "SCOUT                            ..]a dois arriver le 5 mars      192000."},
								{fals, true, 0, "AARON                            C'est un peu long, hein?"},
								{fals, true, 0, "SCOUT                            J'arriverais jamais a comprendre les bugs informatiques."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 3)
						{
							line lc[32] = {
								{fals, true, 0, "(Si je peux convaincre Maple de  donner une chance a ces bandes    dessinees.)"},
								{fals, true, 0, "(Alors nous pourrions avoir      quelque chose en commun.)"},
								{fals, true, 0, "(.....]a arrivera jamais.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 7)
						{
							line lc[32] = {
								{fals, true, 0, "SCOUT                            Bonjour! Tu es Guy?"},
								{fals, true, 0, "GUY                              Oui. Et tu dois etre, Scout?"},
								{fals, true, 0, "SCOUT                            Bienvenu! Tu aime ta cabine?"},
								{fals, true, 0, "GUY                              Tu ne plaisantais pas a propos dela cuisine."},
								{fals, true, 0, "SCOUT                            Pas du tout!"},
								{fals, true, 0, "GUY                              Il ne semble pas y avoir beaucoupde monde ici, et tu sais que je  "},
								{fals, true, 0, "GUY                              ne pourrai pas cuisiner beaucoup si je n'ai pas de clients."},
								{fals, true, 0, "GUY                              Combien de temps ca vas presndre jusqu'a ce que ce soit rempli de "},
								{fals, true, 0, "GUY                              monde?"},
								{fals, true, 0, "SCOUT                            Cela ne devrait pas prendre si   longtemps."},
								{fals, true, 0, "GUY                              Tu es sur?"},
								{fals, true, 0, "SCOUT                            Sans doute."},
								{fals, true, 0, "GUY                              Tres bien alors."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else
						{
							line lc[32] = {
								{true, true, 0, "(Le sol devient poussiereux.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
					}
					break;
				};

				// Scout's computer
				case 29:
				{
					if (globals->current_save->checkpoint < 7)
					{
						if (me == 0)
						{
							line lc[32] = {
								{fals, true, 0, "SCOUT                            He, fais tres attention avec mon PC, ..]a coute un bras."},
								{fals, true, 0, "MAPLE                            Je n'allais pas y toucher. Mais"},
								{fals, true, 0, "MAPLE                            Maintenant, je suis curieuse..."},
								{fals, true, 0, "SCOUT                            Attend, n'y touche pas!"},
								{fals, true, 0, "MAPLE                            Je ne vais pas y toucher!"},
								{fals, true, 0, "MAPLE                            Les nerds et leurs machines..."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 1)
						{
							line lc[32] = {
								{fals, true, 0, "ENOKI                            He Scout, tu as un site Web?"},
								{fals, true, 0, "SCOUT                            Oui! Mais il n'est pas tres beau."},
								{fals, true, 0, "ENOKI                            Je peux voir?"},
								{fals, true, 0, "SCOUT                            Pas maintenant, je ne l'ai pas   encore fini."},
								{fals, true, 0, "ENOKI                            Oh, d'accord."},
								{fals, true, 0, "ENOKI                            J'aimerais avoir mon propre site web."},
								{fals, true, 0, "ENOKI                            ..]a semble amusant."},
								{fals, true, 0, "SCOUT                            Oh que oui!"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 2)
						{
							line lc[32] = {
								{fals, true, 0, "AARON                            As-tu entendu parler du bug de   l'an 2000?"},
								{fals, true, 0, "SCOUT                            Bien sur."},
								{fals, true, 0, "AARON                            Rien n'est arrive?"},
								{fals, true, 0, "SCOUT                            Rien de trop grave."},
								{fals, true, 0, "SCOUT                            Une application m'a donne un     probleme plutot etrange."},
								{fals, true, 0, "SCOUT                            J'avais un programme pour        organiser mes achats et ]a a"},
								{fals, true, 0, "SCOUT                            ajoute des tonnes de cire a      soulier a la liste."},
								{fals, true, 0, "SCOUT                            ..]a dois arriver le 5 mars      192000."},
								{fals, true, 0, "AARON                            C'est un peu long, hein?"},
								{fals, true, 0, "SCOUT                            J'arriverais jamais a comprendre les bugs informatiques."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 3)
						{
							line lc[32] = {
								{fals, true, 0, "(J'ai obtenu mon diplome en tete de ma classe avec un GPA de      3,99.)"},
								{fals, true, 0, "(Je suis maintenant un           scientifique vivant d'une        subvention d'entreprise.)"},
								{fals, true, 0, "(J'ai un PC Castor 5000 a la     pointe de la technologie.)"},
								{fals, true, 0, "(Que je ne peux pas utiliser,    carj'ai oublie mon propre mot de passe.)"},
								{fals, true, 0, "(J'ai du mal a dormir la nuit en y pensant...)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
					}
					else
					{
						if (me == 3)
						{
							dt.spawn_x = 4;
							dt.spawn_y = 0;
							dt.world_index = 99;

							return dt;
						}
						else
						{
							line lc[32] = {
								{true, true, 0, "(Je ne devrais pas toucher.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
					}
					break;
				};

				// Scout meet-point
				case 30:
				{
					if (globals->current_save->checkpoint < 7)
					{
						if (me == 0)
						{
							line lc[32] = {
								{true, true, 0, "MAPLE                            Ah ! Qui es-tu?"},
								{true, true, 0, "SCOUT                            Je suis Scout Williams! Vous etes Maple, n'est-ce pas?"},
								{true, true, 0, "MAPLE                            Well... tout ce bunker est a toi?"},
								{true, true, 0, "SCOUT                            Ca l'est!"},
								{true, true, 0, "MAPLE                            Pourquoi?"},
								{true, true, 0, "SCOUT                            C'est un secret."},
								{true, true, 0, "MAPLE                            Allez comprendre."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 1)
						{
							line lc[32] = {
								{true, true, 0, "SCOUT                            Enoki! What's up?"},
								{true, true, 0, "ENOKI                            Vraiment bien!!! Parfait."},
								{true, true, 0, "ENOKI                            J'aime les fleurs que tu fais pousser ici."},
								{true, true, 0, "SCOUT                            Oh, merci, hehe."},
								{true, true, 0, "SCOUT                            Ne touchez pas."},
								{true, true, 0, "ENOKI                            Oh, je ne le ferai pas, je ne le ferai pas."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 2)
						{
							line lc[32] = {
								{true, true, 0, "AARON                            He!"},
								{true, true, 0, "SCOUT                            Aaron ! Bienvenue ici!"},
								{true, true, 0, "AARON                            Je vois... beaucoup de choses queje ne comprends pas."},
								{true, true, 0, "AARON                            Moi non plus, hehe. A peine."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 3)
						{
							line lc[32] = {
								{fals, true, 0, "(Cette formule verte rend les    plantes enormes.)"},
								{fals, true, 0, "(Je me demande ce qui arriverait si j'en avalais...)"},
								{fals, true, 0, "(Peut-etre que j'aurais des      pouvoirs lies aux plantes...)"},
								{fals, true, 0, "(Ou je ferai juste mourir.)"},
								{fals, true, 0, "(Mais ]a vaut vraiment le coup   d'essayer...)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else
						{
						}
						break;
					}
					else if (globals->current_save->checkpoint < 10)
					{
						if (me < 3)
						{
							line lc[32] = {
								{fals, true, 0, "SCOUT                            Attention!"},
								{fals, true, 0, "SCOUT                            Beaucoup de ces choses sont"},
								{fals, true, 0, "SCOUT                            SUPER TOXIQUE!"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 4)
						{
							line lc[32] = {
								{fals, true, 0, "SCOUT                            Bonjour! Es tu Olivier?"},
								{fals, true, 0, "OLIVIER                          Oui! Et tu es Scout, non?"},
								{fals, true, 0, "SCOUT                            Oui, c'est moi. Bienvenue!"},
								{fals, true, 0, "OLIVIER                          Cet endroit est incroyable!"},
								{fals, true, 0, "SCOUT                            J'ai ete sincere dans l'annonce."},
								{fals, true, 0, "OLIVIER                          Vous etes scientifique?"},
								{fals, true, 0, "SCOUT                            D'une fa]on, oui."},
								{fals, true, 0, "SCOUT                            Je fais un peu de tout."},
								{fals, true, 0, "OLIVIER                          Et vous vivez sous terre?"},
								{fals, true, 0, "SCOUT                            J'ai une machine qui creuse des  bunkers facilement."},
								{fals, true, 0, "SCOUT                            Je pourrais creuser jusqu'a des  limites improbables."},
								{fals, true, 0, "OLIVIER                          Cool! He, tu viens diner chez lesTremblay?"},
								{fals, true, 0, "SCOUT                            Oh que oui!"},
								{fals, true, 0, "OLIVIER                          Cool! On se voit la-bas alors."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 5)
						{
							line lc[32] = {
								{fals, true, 0, "ELEANOR                          Bonjour, monsieur!"},
								{fals, true, 0, "SCOUT                            Bonjour! Es-tu Eleanor?"},
								{fals, true, 0, "ELEANOR                          Oui! Ravi de te rencontrer."},
								{fals, true, 0, "ELEANOR                          Cet endroit est incroyable!"},
								{fals, true, 0, "SCOUT                            J'ai ete sincere dans l'annonce."},
								{fals, true, 0, "ELEANOR                          etes-vous un magicien?"},
								{fals, true, 0, "SCOUT                            D'une maniere oui."},
								{fals, true, 0, "SCOUT                            Je fais un peu de tout."},
								{fals, true, 0, "ELEANOR                          Et vous vivez sous terre?"},
								{fals, true, 0, "SCOUT                            J'ai une machine qui creuse des  bunkers facilement."},
								{fals, true, 0, "SCOUT                            Je pourrais creuser jusqu'a des  limites improbables."},
								{fals, true, 0, "ELEANOR                          Comme c'est fascinant!"},
								{fals, true, 0, "SCOUT                            Ah, merci!"},
								{fals, true, 0, "ELEANOR                          On se voit plus tard au diner?"},
								{fals, true, 0, "SCOUT                            Bien sur!"},
								{fals, true, 0, "ELEANOR                          Merveilleux!"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (me == 6)
						{
							line lc[32] = {
								{fals, true, 0, "DIANA                            Bonjour! Hey, tu es Scout?"},
								{fals, true, 0, "SCOUT                            Bonjour! Tu es Diana?"},
								{fals, true, 0, "DIANA                            Oui! C'est un plaisir de te      rencontrer!"},
								{fals, true, 0, "DIANA                            Bougre, cet endroit est          magnifique!"},
								{fals, true, 0, "SCOUT                            J'ai ete sincere dans l'annonce."},
								{fals, true, 0, "DIANA                            Tu es scientifique ou quoi?"},
								{fals, true, 0, "SCOUT                            D'une maniere oui."},
								{fals, true, 0, "SCOUT                            Je fais un peu de tout."},
								{fals, true, 0, "DIANA                            Et vous vivez sous terre?"},
								{fals, true, 0, "SCOUT                            J'ai une machine qui creuse des  bunkers facilement."},
								{fals, true, 0, "SCOUT                            Je pourrais creuser jusqu'a des  limites improbables."},
								{fals, true, 0, "DIANA                            Wow, c'est cool!"},
								{fals, true, 0, "SCOUT                            Merci!"},
								{fals, true, 0, "DIANA                            Tu viens au diner?"},
								{fals, true, 0, "SCOUT                            Bien sur!"},
								{fals, true, 0, "DIANA                            Genial!"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else
						{
							line lc[32] = {
								{fals, true, 0, "(J'aimerais pouvoir obtenir      quelque chose qui me rendrait         heureux.)"},
								{fals, true, 0, "(Apres avoir passe tant de temps a etudier, me voila...)"},
								{fals, true, 0, "(Et je ne sais pas. Je passe     d'une chose a l'autre.)"},
								{fals, true, 0, "(Je ne peux pas faire quelque    chose sans vouloir le laisser a     mi-chemin.)"},
								{fals, true, 0, "(J'aimerais juste etre heureux laou je suis maintenant, pour une  fois.)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
					}
					else if (globals->current_save->checkpoint < 12)
					{
						if (me < 7)
						{
							line lc[32] = {
								{fals, true, 0, "SCOUT                            Attention!"},
								{fals, true, 0, "SCOUT                            Beaucoup de ces choses sont"},
								{fals, true, 0, "SCOUT                            TOXIQUE MORTEL!"},
								{fals, true, 0, "SCOUT                            Eh bien, vous le saviez deja."},
								{fals, true, 0, "SCOUT                            OU du moins, je l'espere."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else
						{
							line lc[32] = {
								{fals, true, 0, "SCOUT                            Bonjour! Tu es Guy?"},
								{fals, true, 0, "GUY                              Oui. Et tu dois etre, Scout?"},
								{fals, true, 0, "SCOUT                            Bienvenu! Tu aime ta cabine?"},
								{fals, true, 0, "GUY                              Tu ne plaisantais pas a propos dela cuisine."},
								{fals, true, 0, "SCOUT                            Pas du tout!"},
								{fals, true, 0, "GUY                              Il ne semble pas y avoir beaucoupde monde ici, et tu sais que je"},
								{fals, true, 0, "GUY                              ne pourrai pas cuisiner beaucoup si je n'ai pas de clients."},
								{fals, true, 0, "GUY                              Combien de temps ca vas presndre jusqu'a ce que ce soit rempli de"},
								{fals, true, 0, "GUY                              monde?"},
								{fals, true, 0, "SCOUT                            Cela ne devrait pas prendre si   longtemps."},
								{fals, true, 0, "GUY                              Tu es sur?"},
								{fals, true, 0, "SCOUT                            Sans doute."},
								{fals, true, 0, "GUY                              Tres bien alors."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
					}
					else if (globals->current_save->checkpoint == 12)
					{
						globals->current_save->checkpoint = 13;
						line lc[32] = {
							{fals, true, 0, "ENOKI                            Bonjour? Scout, es-tu la?"},
							{fals, true, 0, "SCOUT                            Oui! Je suis ici! Ou est Aaron?"},
							{fals, true, 0, "ENOKI                            Il est sorti pour voir comment   vont les autres."},
							{fals, true, 0, "SCOUT                            Dieu merci. Salut Maple. Tu te   sens bien?"},
							{fals, true, 0, "SCOUT                            Tu as l'air fatiguee."},
							{fals, true, 0, "MAPLE                            Ferme la j'ai deja entendu asser de monde me dire que je"},
							{fals, true, 0, "MAPLE                            semble fatiguee."},
							{fals, true, 0, "SCOUT                            Oh- D'accord..."},
							{fals, true, 0, "SCOUT                            Hey Enoki, comment ]a semble en  haut?"},
							{fals, true, 0, "ENOKI                            C'est bien, c'est juste... Il y aun bruit etrange."},
							{fals, true, 0, "ENOKI                            Aaron a eu peur et voulait que   nous allions en securitee."},
							{fals, true, 0, "SCOUT                            Je lui fais confiance sur ]a."},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);

						character aaron(bn::sprite_items::aaron_walking_spring, 3, 2, false, current_room.width);
						aaron.entity.set_position(7 * 32, 3 * 32);
						aaron.entity.set_camera(current_room.camera);
						aaron.role = 0;
						aaron.follow_id = current_room.chari.size() - 1;
						aaron.identity = 2;
						current_room.chari.push_back(aaron);

						character vee(bn::sprite_items::vee_walking_spring, 3, 2, false, current_room.width);
						vee.entity.set_position(7 * 32, 3 * 32);
						vee.entity.set_camera(current_room.camera);
						vee.role = 0;
						vee.follow_id = current_room.chari.size() - 1;
						vee.identity = 4;
						current_room.chari.push_back(vee);

						character eleanor(bn::sprite_items::eleanor_walking_spring, 4, 4, false, current_room.width);
						eleanor.entity.set_position(7 * 32, 3 * 32);
						eleanor.entity.set_camera(current_room.camera);
						eleanor.role = 0;
						eleanor.follow_id = current_room.chari.size() - 1;
						eleanor.identity = 5;
						current_room.chari.push_back(eleanor);

						for (int n = 0; n < 64; n++)
						{
							aaron.update();
							vee.update();
							eleanor.update();
							bn::core::update();
						}

						break;
					}
					else if (globals->current_save->checkpoint == 13)
					{
						if (true)
						{
							line lc[32] = {
								{fals, true, 0, "AARON                            Qu'est-ce qui se passe dehors?"},
								{fals, true, 0, "SCOUT                            C'est Rufus. Je pense qu'il a uneindigestion alimentaire."},
								{fals, true, 0, "ENOKI                            Hehe, ]a m'arrive aussi apres    avoir mange la nourriture de Guy."},
								{fals, true, 0, "SCOUT                            Non, ]a pourrait etre grave.     C'est peut-etre lie a mes        "},
								{fals, true, 0, "SCOUT                            recherches."},
								{fals, true, 0, "AARON                            Oh, alors le scientifique va nousreveler ce qu'il fait dans ce    "},
								{fals, true, 0, "AARON                            mysterieux bunker depuis quelquesmois?"},
								{fals, true, 0, "SCOUT                            Je suis un scientifique du sol,  mais la verite, je fais aussi des"},
								{fals, true, 0, "SCOUT                            recherches sur les plantes."},
								{fals, true, 0, "ENOKI                            Vraiment!"},
								{fals, true, 0, "OLIVIER                          Et pourquoi tu n'a rien dit?"},
								{fals, true, 0, "SCOUT                            Je ne pouvais pas, c'etait       confidentiel."},
								{fals, true, 0, "SCOUT                            Vous voyez, il y a une certaine  plante qui pousse ici et beaucoup"},
								{fals, true, 0, "SCOUT                            de gens crois qu'elle est        magique. Elle vous donne des     visions."},
								{fals, true, 0, "ENOKI                            Comment les champignons?"},
								{fals, true, 0, "SCOUT                            Non, eux donnent des visions     aleatoires, la plante donne la   "},
								{fals, true, 0, "SCOUT                            meme vision a tous. C'est        pourquoi on l'etudie. C'est pas  juste un bad trip."},
								{fals, true, 0, "SCOUT                            Chaque personne qui en prend agisdifferemment, mais c'est rien de "},
								{fals, true, 0, "SCOUT                            chimique. Comme si ce qu'il      voyait etais quelque change qui  change-"},
								{fals, true, 0, "SCOUT                            leur vie. Et ils deviennent      quelque de differents apres      "},
								{fals, true, 0, "SCOUT                            l'experience."},
								{fals, true, 0, "ELEANOR                          Et que voient-ils?"},
								{fals, true, 0, "SCOUT                            Je ne sais pas. Les personnes    concernees preferent garder le   "},
								{fals, true, 0, "SCOUT                            silence."},
								{fals, true, 0, "SCOUT                            Les personnes qu, en consomme, onun cercle bleu dans les yeux.    "},
								{fals, true, 0, "SCOUT                            ..]a ne dure pas pour toujours,  mais on peut le remarquer pour unmoment."},
								{fals, true, 0, "SCOUT                            J'ai regarde la video de Rufus etbien sur, il avait un cercle     "},
								{fals, true, 0, "SCOUT                            bleu."},
								{fals, true, 0, "AARON                            Donc il est devenu un            super-vilain ou quoi?"},
								{fals, true, 0, "SCOUT                            Je sais pas. Rufus n'est pas     tres... grand., tu sais?         "},
								{fals, true, 0, "SCOUT                            Peut-etre-"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}

						if (true)
						{
							bn::sound_items::knock.play();
							line lc[32] = {
								{fals, true, 0, "SCOUT                            Euh... Je pense qu'il y a        quelqu'un a la porte."},
								{fals, true, 0, "AARON                            J'ai ma hache a portee de main."},
								{fals, true, 0, "SCOUT                            He, vous vous rappelez de ma     machine a bunker?"},
								{fals, true, 0, "AARON                            Oui...?"},
								{fals, true, 0, "SCOUT                            ecoutez-moi. Et si on creusait untunnel qui va hors de l'ile? En  "},
								{fals, true, 0, "plus, je voulais deja en faire unjusqu'au rivage."},
								{fals, true, 0, "SCOUT                            (Je souhaitais garder ]a pour    l'Expo Scout, mais, euh...)"},
								{fals, true, 0, "SCOUT                            (Mais j'ai plus de choix         maintenant.)"},
								{fals, true, 0, "ELEANOR                          C'est securitaire?"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}

						if (true)
						{
							bn::sound_items::knock.play();
							bn::sound_items::boom.play();

							line lc[3] = {
								{fals, true, 0, "SCOUT                            Allons-y."},
								{fals, true, 0, "ENOKI                            Allons-y!"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}

						globals->current_save->checkpoint = 14;
						dt.world_index = 0;

						return dt;
						break;
					};
					break;
				};

				case 31:
				{
					dt.spawn_x = 18;
					dt.spawn_y = 1;
					dt.world_index = 1;
					bn::sound_items::door.play();

					return dt;
				};
				case 32:
				{
					dt.spawn_x = 8;
					dt.spawn_y = 4;
					dt.world_index = 0;
					bn::sound_items::door.play();

					return dt;
				};
				case 33:
				{
					dt.spawn_x = 1;
					dt.spawn_y = 4;
					dt.world_index = 0;
					bn::sound_items::door.play();

					return dt;
				};
				case 34:
				{
					dt.spawn_x = 3;
					dt.spawn_y = 1;
					dt.world_index = 1;
					bn::sound_items::door.play();

					return dt;
				};
				case 35:
				{
					dt.spawn_x = 3;
					dt.spawn_y = 6;
					dt.world_index = 2;
					bn::sound_items::door.play();

					return dt;
				};
				case 36:
				{
					dt.spawn_x = 9;
					dt.spawn_y = 6;
					dt.world_index = 2;
					bn::sound_items::door.play();

					return dt;
				};
				case 37:
				{
					dt.spawn_x = 22;
					dt.spawn_y = 1;
					dt.world_index = 3;
					bn::sound_items::door.play();

					return dt;
				};
				case 38:
				{
					dt.spawn_x = 2;
					dt.spawn_y = 10;
					dt.world_index = 1;
					bn::sound_items::door.play();

					return dt;
				};

				// Art stare
				case 40:
				{
					line lc[5] = {
						{fals, true, 0, "Vous regardez l'oeuvre d'art."},
						{fals, true, 0, "Et par consequent...."},
						{fals, true, 0, "L'oeuvre d'art vous observe."},
						{fals, true, 0, "L'art c'est etrange."},
						{true, true, 0, "COM: Endscene"}};
					dialogue_page_lite(lc);
					break;
				};

				case 41:
				{
					line lc[5] = {
						{fals, true, 0, "- PLUS DE MAISONS PLUS LOIN -"},
						{true, true, 0, "COM: Endscene"}};
					dialogue_page_lite(lc);
					break;
				};
				case 42:
				{
					if (globals->current_save->checkpoint < 12 || current_room.chari.at(current_room.follow_id).identity == 2)
					{
						dt.spawn_x = 18;
						dt.spawn_y = 1;
						dt.world_index = 8;
						return dt;
					}
					else
					{
						line lc[5] = {
							{fals, true, 0, "MAPLE                            Je devrais peut-etre aller chez  Scout."},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					}
				};
				case 43:
				{
					dt.spawn_x = 1;
					dt.spawn_y = 1;
					dt.world_index = 4;
					return dt;
				};

				// Wishing pond
				case 44:
				{
					line lc[5] = {
						{fals, true, 0, "- PUITS A SOUHAIT - NE FONCTIONNEPAS MAIS N'HESITEZ PAS A L'UTILISER SI VOUS LE VOULEZ"},
						{fals, true, 0, "Les rochers devant vous ne       permettent meme pas de prendre la vue."},
						{fals, true, 0, "Si vous pouviez escalader les    rochers, vous pourriez lancer une   piece pour faire un voeu."},
						{fals, true, 0, "L'etang aurait pu etre mieux     amenagee."},
						{true, true, 0, "COM: Endscene"}};
					dialogue_page_lite(lc);
					break;
				};

				case 45:
				{
					line lc[5] = {
						{true, true, 0, " - LE MAISON DE LANDRY -"},
						{true, true, 0, "COM: Endscene"}};
					dialogue_page_lite(lc);
					break;
				};
				case 46:
				{
					line lc[5] = {
						{true, true, 0, " - DIANA -"},
						{fals, true, 0, "C'est le nom de la maison ou du  proprietaire?"},
						{true, true, 0, "COM: Endscene"}};
					dialogue_page_lite(lc);
					break;
				};

				// Guy's house signage
				case 47:
				{
					if (globals->current_save->checkpoint < 10)
					{
						line lc[5] = {
							{fals, true, 0, "- LA MAISON DE QUELQU'UN -"},
							{fals, true, 0, "C'est inhabite."},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					}
					else
					{
						line lc[5] = {
							{fals, true, 0, "- MAISON DE GUY -"},
							{fals, true, 0, "La maison d'un certain Guy."},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					}
				};

				case 48:
				{
					dt.spawn_x = 3;
					dt.spawn_y = 5;
					dt.world_index = 9;
					return dt;
				};
				case 49:
				{
					if (globals->current_save->checkpoint == 12)
					{
						globals->current_save->checkpoint = 13;
					}

					dt.spawn_x = 6;
					dt.spawn_y = 7;
					dt.world_index = 8;
					return dt;
				};
				case 50:
				{
					dt.spawn_x = 3;
					dt.spawn_y = 5;
					dt.world_index = 10;
					return dt;
				};
				case 51:
				{
					dt.spawn_x = 6;
					dt.spawn_y = 17;
					dt.world_index = 8;
					return dt;
				};
				case 52:
				{
					dt.spawn_x = 15;
					dt.spawn_y = 18;
					dt.world_index = 11;
					return dt;
				};
				case 53:
				{
					dt.spawn_x = 10;
					dt.spawn_y = 1;
					dt.world_index = 8;
					return dt;
					break;
				};
				case 54:
				{
					line lc[32] = {
						{true, true, 0, "- JARGINS NOIRS -"},
						{true, true, 0, "COM: Endscene"}};
					dialogue_page_lite(lc);
					break;
				}

				// Eleanor + Olivier meet 'n greet
				case 55:
				{
					if (globals->current_save->checkpoint < 10)
					{
						switch (me)
						{
						default:
						{
							break;
						}

						case 0:
						{
							line lc[32] = {
								{fals, true, 0, "MAPLE                            Oh, he. Tu es Eleanor?"},
								{fals, true, 0, "ELEANOR                          Oui! Enchante de faire votre     connaissance."},
								{fals, true, 0, "MAPLE                            Egalement. Je ne voudrais pas    t'offenser, mais tu sembles..."},
								{fals, true, 0, "MAPLE                            Un peu demodee?"},
								{fals, true, 0, "ELEANOR                          Oh, c'est une habitude."},
								{fals, true, 0, "ELEANOR                          ..]a fait du bien d'etre a       nouveau loin de la ville. J'avais"},
								{fals, true, 0, "ELEANOR                          oubliee comment j'aimais etre    entouree d'arbre."},
								{fals, true, 0, "MAPLE                            Je comprends. Tu es son mari,    j'imagine?"},
								{fals, true, 0, "OLIVIER                          Oui, je suis Olivier."},
								{fals, true, 0, "ELEANOR                          Bien qu'il soit tres reserve,    c'est quelqu'un de tres          "},
								{fals, true, 0, "ELEANOR                          attentionne."},
								{fals, true, 0, "ELEANOR                          Je l'ai rencontre dans un jardin et il m'a appris a lire."},
								{fals, true, 0, "OLIVIER                          Elle est tres speciale pour moi. Elle m'a pratiquement sauve la   "},
								{fals, true, 0, "OLIVIER                          vie."},
								{fals, true, 0, "MAPLE                            Oh, comment?"},
								{fals, true, 0, "OLIVIER                          C'est pas quelque chose          d'important-"},
								{fals, true, 0, "ELEANOR                          De ma mere."},
								{fals, true, 0, "MAPLE                            Ah, je comprends, he."},
								{fals, true, 0, "ELEANOR                          Vraiment? Elle allait drainer    tout son sang pour un rituel."},
								{fals, true, 0, "MAPLE                            Je... Hmm, eh bien, d'accord.    Ce... n'etait pas ce a quoi je   "},
								{fals, true, 0, "MAPLE                            m'attendais."},
								{fals, true, 0, "MAPLE                            Ravi de vous rencontrer, je      suppose?"},
								{fals, true, 0, "ELEANOR                          Bien sur! Je vais preparer une   tarte pour toi en guise de       "},
								{fals, true, 0, "ELEANOR                          'merci'."},
								{fals, true, 0, "MAPLE                            C'est bon, je demanderai juste depas utiliser d'ingredients       "},
								{fals, true, 0, "MAPLE                            bizarres."},
								{fals, true, 0, "MAPLE                            (a quoi pensait Scout en invitantces cingles?!)"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						case 1:
						{
							line lc[32] = {
								{true, true, 0, "ENOKI                            Bienvenue, y'all!! Je suis Enoki!Ravie de vous-autres rencontrer!"},
								{true, true, 0, "ELEANOR                          Bonjour! Enchante de faire votre connaissance."},
								{true, true, 0, "OLIVIER                          Bonjour!"},
								{true, true, 0, "ELEANOR                          I'm Eleanor, and this is my      husband Olivier."},
								{true, true, 0, "ENOKI                            I love your dress!! Where did youget it from?"},
								{true, true, 0, "ELEANOR                          Oh! I made it myself. I love yourdress, too!"},
								{true, true, 0, "ENOKI                            That's soo cool!!"},
								{true, true, 0, "ENOKI                            We look like we're about the samesize, maybe we can trade someday!"},
								{true, true, 0, "OLIVIER                          So, Scout said that you and your husband are royalty?"},
								{true, true, 0, "ENOKI                            Oh yes! This is our little       kingdom, but we're not cruel."},
								{true, true, 0, "ENOKI                            I'm like the chillest queen      you'll ever meet."},
								{true, true, 0, "ENOKI                            You guys wanna be a duke and     duchess?"},
								{true, true, 0, "ELEANOR                          I.. no thank you, I don't think  I know what those are."},
								{true, true, 0, "OLIVIER                          Merci, en tout cas."},
								{true, true, 0, "ENOKI                            Bien sur! N'importe quand!"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						case 2:
						{
							line lc[32] = {
								{fals, true, 0, "AARON                            Bienvenue! Olivier et Eleanor, jesuppose?"},
								{fals, true, 0, "ELEANOR                          Oui oui!"},
								{fals, true, 0, "OLIVIER                          Etes-vous le 'roi' de cette ile?"},
								{fals, true, 0, "AARON                            Scout a dit ]a? Je suppose que   oui.."},
								{fals, true, 0, "AARON                            J'ai jamais termine mes etudes   secondaires, donc je suis pas"},
								{fals, true, 0, "AARON                            fait pour grand chose, mais je nevoulais pas passer ma vie dans   une usine."},
								{fals, true, 0, "AARON                            Ma femme, Enoki, et moi avons eu l'idee d'acquerir un terrain pourvivre par nous-memes. La"},
								{fals, true, 0, "AARON                            'royaute' etait son idee. Elle   etait si mignonne quand elle a   demande quej'ai dit oui."},
								{fals, true, 0, "AARON                            Elle vous a surement offert aussides roles aristocratiques."},
								{fals, true, 0, "OLIVIER                          Oh, Aaron? Merci d'avoir degage  la zone pour la serre."},
								{fals, true, 0, "OLIVIER                          Maintenant, je peux partager ce  que j'y cultive."},
								{fals, true, 0, "ELEANOR                          Et j'adore cette cabine! Cela me rappelle ma maison natale."},
								{fals, true, 0, "ELEANOR                          Vee et moi etions ravis de voir  l'ile."},
								{fals, true, 0, "AARON                            Et nous sommes heureux que vous  ayez decide de venir ici!"},
								{fals, true, 0, "AARON                            Si ma petite soeur vous donne du fil a retordre..."},
								{fals, true, 0, "AARON                            Je vous promets qu'elle ne le    fait pas expres."},
								{fals, true, 0, "AARON                            Vous pouvez passer ce soir pour  diner ensemble."},
								{fals, true, 0, "OLIVIER                          Encore une fois, je vous remerciesincerement."},
								{fals, true, 0, "AARON                            Nous sommes une famille          maintenant, tu peur dire tu."},

								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						case 3:
						{
							line lc[32] = {
								{true, true, 0, "SCOUT                            He! Je suis Scout, en internet!"},
								{true, true, 0, "OLIVIER                          Enchante de faire votre          connaissance."},
								{true, true, 0, "ELEANOR                          Oh.. D'apres ta photo, j'ai      pense.."},
								{true, true, 0, "SCOUT                            Quoi?"},
								{true, true, 0, "ELEANOR                          Je pensais que tu etais un       squelette."},
								{true, true, 0, "SCOUT                            Oh, hehe, non, je pense juste queles squelettes sont geniaux."},
								{true, true, 0, "SCOUT                            Bienvenue sur l'ile!"},
								{true, true, 0, "ELEANOR                          Merci!!"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						// Fall-through to the next bit
						case 4:
						{
						}

						case 5:
						{
							line lc[32] = {
								{fals, true, 0, "OLIVIER                          Eleanor, pourquoi as-tu allume lacuisiniere? Nous n'allions pas"},
								{fals, true, 0, "OLIVIER                          diner avec les Tremblay ce soir?"},
								{fals, true, 0, "ELEANOR                          Oh, bien sur, mais je n'ai pas pum'en empecher."},
								{fals, true, 0, "ELEANOR                          Jee n'ai pas vus un four comme ]adepuis mon enfance."},
								{fals, true, 0, "ELEANOR                          Alors j'ai voulu essayer de me   faire des toasts."},
								{fals, true, 0, "OLIVIER                          Que penses-tu de cet endroit?"},
								{fals, true, 0, "OLIVIER                          Il n'y a pas beaucoup de monde,  tu vas pas te sentir un peu seul?"},
								{fals, true, 0, "ELEANOR                          Et toi? Pense-tu que tu vas te   sentir seul?"},
								{fals, true, 0, "OLIVIER                          J'aimerais que mon grand-pere    puisse nous voir en ce moment."},
								{fals, true, 0, "OLIVIER                          Je pense qu'il serait tres fier  de toi."},
								{fals, true, 0, "ELEANOR                          Peut-etre qu'il nous regarde     depuis le ciel."},
								{fals, true, 0, "ELEANOR                          Et ma mere a peut-etre changee   la-haut et elle pense que tu es"},
								{fals, true, 0, "ELEANOR                          un gars bien maintenant."},
								{fals, true, 0, "OLIVIER                          Nous n'aurons jamai la reponse,  mais je sait que je ne me sent   pas seul."},
								{fals, true, 0, "OLIVIER                          Je ne me sens plus seul depuis   que tu es avec moi."},
								{fals, true, 0, "ELEANOR                          Vee, j'espere que nous           n'arreterons jamais de ressentir cela."},
								{fals, true, 0, "ELEANOR                          J'ai vu comment mes parents sont devenus et j'ai l'impression de"},
								{fals, true, 0, "ELEANOR                          vieillir. Je sais qu'une fois quenous aurons nos enfants..."},
								{fals, true, 0, "OLIVIER                          Comment va ta soeur?"},
								{fals, true, 0, "ELEANOR                          Elle est toujours epuisee. Elle  plaisante sur ses cheveux gris,"},
								{fals, true, 0, "ELEANOR                          mais, elle est differente."},
								{fals, true, 0, "ELEANOR                          Les choses qui l'enervait sont siloin maintenant."},
								{fals, true, 0, "OLIVIER                          Et s'il nous arrivait la meme    chose? Nous devrons etre patient."},
								{fals, true, 0, "ELEANOR                          Ce sera etrange d'avoir des amis maries a notre age. Pense-tu que"},
								{fals, true, 0, "ELEANOR                          Diana sera jalouse?"},
								{fals, true, 0, "OLIVIER                          Je pense qu'elle va s'amuser ici.S'il te plait relax!"},
								{fals, true, 0, "ELEANOR                          Je suppose que tu as raison, Vee."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						case 6:
						{
							line lc[32] = {
								{fals, true, 0, "DIANA                            Oh super! J'adore cet endroit,   c'est tres cosy."},
								{fals, true, 0, "DIANA                            J'espere que vous derange pas queje passe tous mon temps ici."},
								{fals, true, 0, "ELEANOR                          Bien sur que non! Tant que cela  ne te derange pas de nous aider  "},
								{fals, true, 0, "ELEANOR                          parfois."},
								{fals, true, 0, "OLIVIER                          Rappeles toi, vivre ainsi        signifie que nous devons         "},
								{fals, true, 0, "OLIVIER                          travailler dur."},
								{fals, true, 0, "OLIVIER                          Tu devras probablement passer    beaucoup de temps a couper du    "},
								{fals, true, 0, "OLIVIER                          bois, ou travailler dans le      jardin a arroser et desherber."},
								{fals, true, 0, "ELEANOR                          Tu etais interesser a travailler pour le capitaine du navire?"},
								{fals, true, 0, "DIANA                            Oh oui, je vais aller a la jetee aujourd'hui."},
								{fals, true, 0, "DIANA                            Je serai capitaine d'un navire   avant que tu ne le saches!"},
								{fals, true, 0, "ELEANOR                          Je sais que tu peux faire tout ceque tu veux, Diana!"},
								{fals, true, 0, "OLIVIER                          Ce n'est pas ce que tu pensais   faire a 22 ans, hein?"},
								{fals, true, 0, "DIANA                            Eh bien, c'est pas comme si      j'avais une idee claire avant."},
								{fals, true, 0, "DIANA                            Demenager sur une ile est quelquechose d'inattendu pour tout le   "},
								{fals, true, 0, "DIANA                            monde. Non?"},
								{fals, true, 0, "OLIVIER                          Je pensais passer le reste de ma vie a jardiner."},
								{fals, true, 0, "ELEANOR                          Je suis toujours en vie et Vee   est avec nous, je ne peux pas en "},
								{fals, true, 0, "ELEANOR                          demander plus."},
								{fals, true, 0, "DIANA                            Oui... J'espere que les choses   resteront aussi bonnes pendant   "},
								{fals, true, 0, "DIANA                            longtemps."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						}
						break;
					}
					else if (globals->current_save->checkpoint < 12)
					{
						switch (me)
						{
						default:
						{
							break;
						}

						case 0:
						{
							line lc[32] = {
								{fals, true, 0, "MAPLE                            Bonjour, les gars."},
								{fals, true, 0, "ELEANOR                          Bonjour, Maple! Veux tu du       ragout? Il est frais."},
								{fals, true, 0, "MAPLE                            Bien sur que j'en veux, ton      ragout est fantastique."},
								{fals, true, 0, "OLIVIER                          Diana nous a emmenee un nouveau  jeu de societe de la ville."},
								{fals, true, 0, "OLIVIER                          Pourrais-tu demander au autre    s'ils souhaitent jouer ce soir?"},
								{fals, true, 0, "MAPLE                            Mais pas moi? Haha."},
								{fals, true, 0, "MAPLE                            Hey, euh... Desole pour la partiede la semaine derniere."},
								{fals, true, 0, "ELEANOR                          C'est bon, Maple. C'es tres      facile de s'enerver sur des jeux."},
								{fals, true, 0, "MAPLE                            En plus votre cabine semble avoircesse de sentir la fumee."},
								{fals, true, 0, "ELEANOR                          As-tu essaye le nouveau gumbo desiles?"},
								{fals, true, 0, "MAPLE                            Me demandes-tu si j'ai peur de   l'essayer? Nan, pas pour le      "},
								{fals, true, 0, "MAPLE                            moment."},
								{fals, true, 0, "MAPLE                            Quoi qu'il en soit, il n'y a rienque plus de Tabasco ne peux pas  "},
								{fals, true, 0, "MAPLE                            regler."},
								{fals, true, 0, "MAPLE                            Je sais que je ne viens pas vous souvent mais..."},
								{fals, true, 0, "MAPLE                            Je tiens a vous remercier pour   les ingredients. Vous etes des   "},
								{fals, true, 0, "MAPLE                            anges."},
								{fals, true, 0, "OLIVIER                          Merci pour ton travail acharne.  Je n'avais pas completement      "},
								{fals, true, 0, "OLIVIER                          confiance avec cette histoire    d'ile."},
								{fals, true, 0, "OLIVIER                          C'est presque comme si vous aviezun porte-bonheur."},
								{fals, true, 0, "MAPLE                            Oui... D'une maniere ou d'une    autre, Enoki obtient tout ce     "},
								{fals, true, 0, "MAPLE                            qu'elle veut."},
								{fals, true, 0, "MAPLE                            Ce n'est qu'une question de tempsavant que quelque chose ne tourne"},
								{fals, true, 0, "MAPLE                            mal et qu'elle n'aille pas ce    qu'elle souhaite"},
								{fals, true, 0, "OLIVIER                          Je vois. Eh bien, si tu as besoinde quelque chose de notre part,  "},
								{fals, true, 0, "OLIVIER                          tu n'as qu'a demander."},
								{fals, true, 0, "MAPLE                            Pareil!"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						case 1:
						{
							line lc[32] = {
								{fals, true, 0, "ENOKI                            Salut!! Comment vas-tu           aujourd'hui?"},
								{fals, true, 0, "ELEANOR                          Nous allons tres bien! Veux-tu duragout?"},
								{fals, true, 0, "ENOKI                            Je mentirais si je disais que    quelqu'un n'en reclamait pas,    "},
								{fals, true, 0, "ENOKI                            hehe."},
								{fals, true, 0, "OLIVIER                          Tu viens jouer ce soir?"},
								{fals, true, 0, "ENOKI                            Je ne manquerais ]a pour rien au monde!"},
								{fals, true, 0, "ELEANOR                          Avez-vous deja rencontre le      nouvel insulaire?"},
								{fals, true, 0, "ENOKI                            Ne dis rien a Maple..."},
								{fals, true, 0, "ENOKI                            mais je pense que son gombo est  meilleur que le sien."},
								{fals, true, 0, "ENOKI                            Tu dois me promettre de ne PAS   dire ]a a Maple."},
								{fals, true, 0, "ELEANOR                          Mes levres sont scellees."},
								{fals, true, 0, "ENOKI                            He, vous avez une machine a      coudre par ici?"},
								{fals, true, 0, "ELEANOR                          Oui."},
								{fals, true, 0, "ENOKI                            Tu as dit que tu fabriques tes   propres vetements, oui? Tu,      "},
								{fals, true, 0, "ENOKI                            euh..."},
								{fals, true, 0, "ENOKI                            ..]a te derangerait-il de me     donner des le]ons?"},
								{fals, true, 0, "ELEANOR                          Pas du tout! C'est avec plaisir  que je t'enseignerai."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						case 2:
						{
							line lc[32] = {
								{fals, true, 0, "AARON                            Bonjour! J'ai entendu parler de  jeux de societe ce soir."},
								{fals, true, 0, "ELEANOR                          Oui! Nous aimerions l'installer al'exterieur sous un arbre."},
								{fals, true, 0, "ELEANOR                          J'ai fait une courtepointe assez grande pour que tout le monde    "},
								{fals, true, 0, "ELEANOR                          puisse s'y glisser."},
								{fals, true, 0, "AARON                            ..]a va etre dehors cette fois   donc Maple ne bruleras rien      "},
								{fals, true, 0, "AARON                            d'important, oui?"},
								{fals, true, 0, "OLIVIER                          Oui, ha ha."},
								{fals, true, 0, "ELEANOR                          Nous avons aussi fait du ragout, au cas ou tu aurais envie de     "},
								{fals, true, 0, "ELEANOR                          manger quelque chose."},
								{fals, true, 0, "AARON                            J'ai deja mange le reste du gomboa Maple, mais merci!"},
								{fals, true, 0, "AARON                            Parlant de nourriture. Bien qu'ilsoit timide, Guy est un bon      "},
								{fals, true, 0, "AARON                            gar]on."},
								{fals, true, 0, "AARON                            Je suis ravi que plus de gens    viennent sur l'ile."},
								{fals, true, 0, "OLIVIER                          Petit a petit cela devient un    vrai village."},
								{fals, true, 0, "AARON                            Ouais, je pensais la meme chose."},
								{fals, true, 0, "OLIVIER                          ..]a va, Aaron? Tu as le visage  pale."},
								{fals, true, 0, "AARON                            Ouais, je pensais juste que Mapleet avons des problemes recemment."},
								{fals, true, 0, "OLIVIER                          Comment-]?"},
								{fals, true, 0, "AARON                            Elle veut pas changer de maison, mais elle va devoir le faire."},
								{fals, true, 0, "OLIVIER                          Pourquoi tu ne lui parles pas? Tues le roi nom?"},
								{fals, true, 0, "AARON                            Je peux et je devrai. Elle est   just tres difficile."},
								{fals, true, 0, "AARON                            Elle n'arrete pas de changer     entre vouloir etre super         "},
								{fals, true, 0, "AARON                            independente et devenir une      sangsue."},
								{fals, true, 0, "OLIVIER                          Tu devrais discuter ]a avec elle,pas avec nous."},
								{fals, true, 0, "AARON                            Oui tu as raison."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						case 3:
						{
							line lc[32] = {
								{fals, true, 0, "SCOUT                            Salut tout le monde! Scout est   arrive!"},
								{fals, true, 0, "ELEANOR                          Bonjour! Veux-tu du ragout?"},
								{fals, true, 0, "SCOUT                            Merci, mais j'ai mange il y a... un moment?"},
								{fals, true, 0, "SCOUT                            Merde, j'ai rien mange de la     journee. Je vais prendre du"},
								{fals, true, 0, "SCOUT                            ragout!"},
								{fals, true, 0, "ELEANOR                          Hehe, pas de probleme, prend la  portion que tu veux."},
								{fals, true, 0, "SCOUT                            Avez-vous vu le reportage de     Scout TV ce matin?"},
								{fals, true, 0, "ELEANOR                          Oh, nous-autres on a pas de      television."},
								{fals, true, 0, "SCOUT                            C'est vrai... Je suis desole,    j'avais oublie."},
								{fals, true, 0, "SCOUT                            Ma transmission a ete piratee de toute fa]on."},
								{fals, true, 0, "OLIVIER                          pirate? Par qui?"},
								{fals, true, 0, "SCOUT                            Aucune idee. Les Tremblay ne     semblent pas trop inquiets de"},
								{fals, true, 0, "SCOUT                            toute fa]on."},
								{fals, true, 0, "ELEANOR                          Tu viens jouer avec nous-autres  ce soir?"},
								{fals, true, 0, "SCOUT                            Je vais essayer de venir, j'ai   still du travail devant moi."},
								{fals, true, 0, "SCOUT                            Alors je vais te revenir avec ]a."},
								{fals, true, 0, "OLIVIER                          Pas de probleme, on vous garde   une place."},
								{fals, true, 0, "SCOUT                            Merci!"},
								{fals, true, 0, "ELEANOR                          De rien!"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						// Fall-through to the next bit
						case 4:
						{
						}

						case 5:
						{
							line lc[32] = {
								{fals, true, 0, "OLIVIER                          Alors ton anniversaire c'est dansune semaine..."},
								{fals, true, 0, "ELEANOR                          Oui?"},
								{fals, true, 0, "OLIVIER                          J'aimerais faire une surprise,   mais je ne veux pas te decevoir  "},
								{fals, true, 0, "OLIVIER                          avec-"},
								{fals, true, 0, "ELEANOR                          ..."},
								{fals, true, 0, "OLIVIER                          ... Tu veux que je te surprenne?"},
								{fals, true, 0, "OLIVIER                          ..."},
								{fals, true, 0, "OLIVIER                          Pense-tu encore a la ceremonie?"},
								{fals, true, 0, "ELEANOR                          C'est une nuit que je n'oublieraijamais."},
								{fals, true, 0, "ELEANOR                          Je ne peux pas dire si c'est bon ou mauvais malheureusement."},
								{fals, true, 0, "ELEANOR                          Tu m'as donne le seul cadeau que j'avais besoin toute ma vie"},
								{fals, true, 0, "OLIVIER                          Mais tu ne te plaindrais pas si  j'achetais une nouvelle machine a"},
								{fals, true, 0, "OLIVIER                          coudre."},
								{fals, true, 0, "ELEANOR                          ..."},
								{fals, true, 0, "OLIVIER                          Je confirme pas que c'est ton    cadeau mais..."},
								{fals, true, 0, "ELEANOR                          Tu n'as pas des legumes a coupe? je dois commencer"},
								{fals, true, 0, "ELEANOR                          pour les mettre en conserve pour l'hiver."},
								{fals, true, 0, "OLIVIER                          D'accord, d'accord, c'est        juste... Eh bien, tant pis."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						case 6:
						{
							line lc[32] = {
								{fals, true, 0, "DIANA                            Les gars, nous devons parler."},
								{fals, true, 0, "OLIVIER                          Il y a un probleme?"},
								{fals, true, 0, "DIANA                            Quelqu'un a pirate la chaine de  Scout ce matin."},
								{fals, true, 0, "DIANA                            Je pense que c'etait un Mons     d'Plonj, il a menace l'ile."},
								{fals, true, 0, "ELEANOR                          O-Oh.. Oh non..  Il n'etait pas  avec les sorcieres quand meme?"},
								{fals, true, 0, "ELEANOR                          Vee, nous ont-ils trouves?"},
								{fals, true, 0, "DIANA                            Non, il avait juste l'air d'un   abruti. Et Maple semble le"},
								{fals, true, 0, "DIANA                            connaitre."},
								{fals, true, 0, "DIANA                            Les Tremblay ne sont pas         inquiets."},
								{fals, true, 0, "ELEANOR                          Oh... Dieu merci..."},
								{fals, true, 0, "DIANA                            As-tu rencontre le gars au Nord, Cesar?"},
								{fals, true, 0, "DIANA                            Il parait bizarre, mais Enoki luifait confiance. Il a un magasin"},
								{fals, true, 0, "DIANA                            en plus. Et l'autre gar]on, Guy, cuisine tres bien."},
								{fals, true, 0, "OLIVIER                          He, El, calme-toi, tu as l'air   d'etre au bord de la crise."},
								{fals, true, 0, "ELEANOR                          Desole... desole..."},
								{fals, true, 0, "DIANA                            He, Eleanor, ]a va aller. Veux tuvenir chez moi?"},
								{fals, true, 0, "DIANA                            Nous pouvons nous detendre et    manger des collations importees."},
								{fals, true, 0, "DIANA                            Ouais, ]a a l'air amusant. Merci."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						case 7:
						{
							line lc[32] = {
								{fals, true, 0, "ELEANOR                          Bonjour! Vous devez etre Guy."},
								{fals, true, 0, "GUY                              Oui. Je suis Guy. Guy Pizza."},
								{fals, true, 0, "ELEANOR                          Guy... pizza?"},
								{fals, true, 0, "GUY                              Le nom etait plus drole quand je travaillais a la pizzeria."},
								{fals, true, 0, "OLIVIER                          Eh bien, en tout cas, vous etes  le bienvenu sur l'ile!"},
								{fals, true, 0, "GUY                              Ravi de vous rencontrer. Je dois still finir de ranger mes        "},
								{fals, true, 0, "GUY                              affaires."},
								{fals, true, 0, "GUY                              J'ai toujours voulu une cuisine  tres grande et je vais en faire  "},
								{fals, true, 0, "GUY                              bon usage, vous verrez."},
								{fals, true, 0, "ELEANOR                          On va jouer a un jeu de societe  ce soir."},
								{fals, true, 0, "ELEANOR                          Veux-tu nous rejoindre?"},
								{fals, true, 0, "GUY                              J'adorerais, mais en ce moment,  je suis preoccupe avec ma        "},
								{fals, true, 0, "GUY                              cuisine."},
								{fals, true, 0, "ELEANOR                          Je vois... J'espere que tous ira bien avec ta cuisine."},
								{fals, true, 0, "GUY                              Oh, j'espere. J'espere."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						}
						break;
					}
					else if (globals->current_save->checkpoint < 14)
					{

						if (true)
						{
							line lc[32] = {
								{fals, true, 0, "ELEANOR                          Que se passe-t-il dehors?"},
								{fals, true, 0, "AARON                            Je sais pas, mais suivez-moi, on va au bunker de Scout etpour     "},
								{fals, true, 0, "AARON                            attendre que les choses se       calment."},
								{fals, true, 0, "AARON                            Ou est Diana?"},
								{fals, true, 0, "OLIVIER                          Elle est partie naviguer avec Guyet ne reviendra que plus tard."},
								{fals, true, 0, "AARON                            Dieu merci. Suivez-moi, sortons  d'ici."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}

						if (globals->current_save->checkpoint == 12)
						{
							globals->current_save->checkpoint = 13;
						}

						dt.spawn_x = 6;
						dt.spawn_y = 7;
						dt.world_index = 8;
						return dt;
						break;
					}

					break;
				};

				// Eleanor's room
				case 57:
				{
					if (me == 4)
					{
						line lc[32] = {
							{fals, true, 0, "C'est la bibliotheque d'Eleanor."},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
					}
					else if (me != 5)
					{
						line lc[32] = {
							{fals, true, 0, "La porte est fermee."},
							{fals, true, 0, "Vous ne devriez pas fouiner chez les autres."},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
					}
					else
					{
						dt.spawn_x = 3;
						dt.spawn_y = 5;
						dt.world_index = 12;
						return dt;
					}
					break;
				};

				case 58:
				{
					dt.spawn_x = 4;
					dt.spawn_y = 1;
					dt.world_index = 9;
					return dt;
					break;
				};
				case 59:
				{
					dt.spawn_x = 5;
					dt.spawn_y = 0;
					dt.world_index = 99;
					return dt;
					break;
				};
				case 60:
				{
					dt.spawn_x = 6;
					dt.spawn_y = 17;
					dt.world_index = 8;
					return dt;
					break;
				};
				case 61:
				{
					if (current_room.chari.at(current_room.follow_id).identity == 6)
					{
						dt.spawn_x = 6;
						dt.spawn_y = 0;
						dt.world_index = 99;
						return dt;
						break;
					}
					break;
				};

				// Diana meet n' greet
				case 62:
				{
					if (globals->current_save->checkpoint < 10)
					{
						switch (me)
						{
						default:
						{
							break;
						}

						case 0:
						{
							line lc[32] = {
								{fals, true, 0, "MAPLE                            He! Tu es Diana?"},
								{fals, true, 0, "DIANA                            Salut! Cool une autre rousse!"},
								{fals, true, 0, "MAPLE                            Oh, mes cheveux ne sont pas roux,c'est plutot blond miel."},
								{fals, true, 0, "MAPLE                            Je suis une elfe, donc parfois   ils semblent un peu d'orange."},
								{fals, true, 0, "DIANA                            Oh, je vois? Mais pourquoi..."},
								{fals, true, 0, "MAPLE                            Pourquoi mes oreilles sont ronde?"},
								{fals, true, 0, "DIANA                            Je ne veux pas te rendre mal a   l'aise."},
								{fals, true, 0, "MAPLE                            C'est pas un probleme. Elles ont ete coupees quand j'etais bebe."},
								{fals, true, 0, "MAPLE                            Je m'appelle Maple, au fait.     Maple Tremblay."},
								{fals, true, 0, "DIANA                            Heureuse de te rencontrer!"},
								{fals, true, 0, "DIANA                            Ces cabines sont confortables!   C'est ton grand frere qui les    "},
								{fals, true, 0, "DIANA                            faits?"},
								{fals, true, 0, "MAPLE                            En partie. Je sors               occasionnellement chercher des   "},
								{fals, true, 0, "MAPLE                            pierres precieuses dans les      grottes."},
								{fals, true, 0, "MAPLE                            Nous gagnons assez pour bien     vivre ici."},
								{fals, true, 0, "DIANA                            Vie tu dans le camper?"},
								{fals, true, 0, "MAPLE                            Oui, je dors sur le sofa."},
								{fals, true, 0, "DIANA                            Et tu ne veux pas de cabine?     L'une parais vide."},
								{fals, true, 0, "MAPLE                            Enfaite, Aaron et Enoki desirent faire un chateau."},
								{fals, true, 0, "MAPLE                            Donc, je prevois de garder le    camper quand se sera fait."},
								{fals, true, 0, "DIANA                            Alors... Cette ile, est-ce un    vrai pays?"},
								{fals, true, 0, "MAPLE                            Si en pense que ]a l'est, ]a doisl'etre non?"},
								{fals, true, 0, "DIANA                            Est-ce si facile de creer un     pays?"},
								{fals, true, 0, "MAPLE                            On verra s'il y a une guerre, en passant ravit de te connaitre"},
								{fals, true, 0, "DIANA                            Ehm, oui, ravie de te rencontrer aussi!"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						case 1:
						{
							line lc[32] = {
								{fals, true, 0, "ENOKI                            He! Tu es Diana? Je suis Enoki   Tremblay!"},
								{fals, true, 0, "DIANA                            Enchantee de faire ta            connaissance!"},
								{fals, true, 0, "ENOKI                            Tu te sens bien ici?"},
								{fals, true, 0, "DIANA                            C'est fou, je suis pas encore surque c'est reel."},
								{fals, true, 0, "DIANA                            C'est trop incroyable pour etre  vrais."},
								{fals, true, 0, "ENOKI                            Je suis tres chanceuse, quand je veux que quelque chose se"},
								{fals, true, 0, "ENOKI                            passe..."},
								{fals, true, 0, "ENOKI                            La vie fais tout pour que je     l'aille, et je l'ai demandee."},
								{fals, true, 0, "ENOKI                            J'ai entendu dire que tu etais   souvent avec Capitaine Nicholas?"},
								{fals, true, 0, "DIANA                            Oui! Il cherche quelqu'un pour   reprendre son flambeau."},
								{fals, true, 0, "DIANA                            Un jour, je conduirai le navire  partout dans le lac Superieur."},
								{fals, true, 0, "ENOKI                            ..]a a l'air amusant! Tu devras  nous laisser venir des fois."},
								{fals, true, 0, "ENOKI                            Si tu as besoin de quoi que ce   soit, dit le nous."},
								{fals, true, 0, "DIANA                            D'accord!"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						case 2:
						{
							line lc[32] = {
								{fals, true, 0, "DIANA                            Bienvenu! Tu es Aaron Tremblay,  non?"},
								{fals, true, 0, "AARON                            Bienvenue! Comment ]a vas dans tacabine?"},
								{fals, true, 0, "DIANA                            C'est super! Trop beau pour etre vrai."},
								{fals, true, 0, "DIANA                            Aujourd'hui, j'aurai ma premiere instruction de conduite du       "},
								{fals, true, 0, "DIANA                            bateau."},
								{fals, true, 0, "DIANA                            Connais-tu  capitaine Nicholas?"},
								{fals, true, 0, "AARON                            En vrai, je passe la plupart de  mon temps a couper du bois."},
								{fals, true, 0, "AARON                            Mais il semble etre un bon gars  d'apres ce que j'ai compris."},
								{fals, true, 0, "AARON                            Je resterai pas longtemps, je    suis juste venu voir comment tu  "},
								{fals, true, 0, "AARON                            allais."},
								{fals, true, 0, "AARON                            Dis-moi si tu as besoin de quoi  que ce soit, d'accord?"},
								{fals, true, 0, "DIANA                            Bien sur! Merci beaucoup!"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						case 3:
						{
							line lc[32] = {
								{fals, true, 0, "SCOUT                            He! C'est moi, Scout. Je voulais juste me presenter."},
								{fals, true, 0, "DIANA                            Oh, ravie! Je sais toujours pas  si c'est reel..."},
								{fals, true, 0, "DIANA                            Je suis contente de ne pas       avoir... Eh bien... ete tuee ou  "},
								{fals, true, 0, "DIANA                            pire."},
								{fals, true, 0, "SCOUT                            J'avoue que je suis ici que      depuis peu de temps aussi."},
								{fals, true, 0, "SCOUT                            J'ai demenage ici d'une ile qui  est pas trop loin."},
								{fals, true, 0, "SCOUT                            Mais ensuite j'ai rencontre les  Tremblay et j'ai decide de me    "},
								{fals, true, 0, "SCOUT                            joindre."},
								{fals, true, 0, "SCOUT                            C'etait pas si facile de faire unnouveau bunker, mais ]a valait le"},
								{fals, true, 0, "SCOUT                            coup. Je me sens bien ici."},
								{fals, true, 0, "DIANA                            Eh bien, tu sembles aller bien.  Tu es un scientifique?"},
								{fals, true, 0, "SCOUT                            Oui, c'est drole. Parce qu'une   entreprise m'a aussi envoye ici  "},
								{fals, true, 0, "SCOUT                            pour faire des experiences sur   l'ile, sans beaucoup de details."},
								{fals, true, 0, "DIANA                            As-tu decouvert de quoi de cool?"},
								{fals, true, 0, "SCOUT                            J'ai cree un appareil qui fait   des bunkers rapidement."},
								{fals, true, 0, "SCOUT                            Je sais pas quoi faire d'autre   avec, mais ]a a du potentiel."},
								{fals, true, 0, "DIANA                            He, si tu en as envie,           pourrais-tu me construire un     "},
								{fals, true, 0, "DIANA                            bunker aussi?"},
								{fals, true, 0, "SCOUT                            Bien sur, j'adorerais!"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						// Fall-through to the next bit
						case 4:
						{
							line lc[32] = {
								{fals, true, 0, "DIANA                            He, Vee! Contente de te voir dansma /nouvelle cabine/!"},
								{fals, true, 0, "OLIVIER                          Il ne t'a pris qu'une journee    pour la remodeler comme"},
								{fals, true, 0, "OLIVIER                          ton ancienne maison, hein?"},
								{fals, true, 0, "DIANA                            Si tout va bien, cette cabine    sera comme mon ancienne maison."},
								{fals, true, 0, "OLIVIER                          Tout dependra si nous pouvons    faire confiance au autres."},
								{fals, true, 0, "OLIVIER                          Tu as de quoi te defendre si les choses tournent mal?"},
								{fals, true, 0, "DIANA                            Oui, je porte un fusil a fusee   eclairante."},
								{fals, true, 0, "DIANA                            Bien que j'espere ne pas avoir a l'utiliser."},
								{fals, true, 0, "OLIVIER                          J'espere moi aussi. Ils ont l'airde gens sympas."},
								{fals, true, 0, "OLIVIER                          Ou du moins ils n'on aucun       interet a nous sacrifier."},
								{fals, true, 0, "DIANA                            Hehe, je te le dis. Si quelqu'un de la famille d'El se presente,"},
								{fals, true, 0, "DIANA                            Appelle-moi tout de suite,       d'accord?"},
								{fals, true, 0, "OLIVIER                          Bien sur, bien sur."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						case 5:
						{
							line lc[32] = {
								{fals, true, 0, "ELEANOR                          ..]a ressemble a ton ancienne    chambre!"},
								{fals, true, 0, "DIANA                            Bien sur, tu me prend pour qui,  hi hi."},
								{fals, true, 0, "ELEANOR                          J'adore ]a, c'est tellement      confortable."},
								{fals, true, 0, "ELEANOR                          Dit moi si tu as besoin de quoi  que ce soit,"},
								{fals, true, 0, "ELEANOR                          J'ai decore ma chambre, et j'ai  installe la boule de cristal. Je "},
								{fals, true, 0, "ELEANOR                          pratique toujours l'invocation."},
								{fals, true, 0, "DIANA                            Et tu sur que l'utilisation de tamagie n'attireras pas... euh...  "},
								{fals, true, 0, "DIANA                            les sorcieres ?"},
								{fals, true, 0, "ELEANOR                          Je suis sur. Si tout se passe    bien, nous pourons meme inviter  "},
								{fals, true, 0, "ELEANOR                          ma famille. J'aimerais leur      montrer cet endroit relaxant."},
								{fals, true, 0, "DIANA                            Nous verrons, on a pas eu une vietranquille jusqu'ici."},
								{fals, true, 0, "DIANA                            Au fait, as-tu deja parle au     Tremblay?"},
								{fals, true, 0, "DIANA                            On dirait qu'il en a un pour noustrois."},
								{fals, true, 0, "DIANA                            Il y a une fille rousse et       deux... fermiers?"},
								{fals, true, 0, "DIANA                            Enoki est mignone, mais tu l'es  encore plus!"},
								{fals, true, 0, "ELEANOR                          Ah, merci!"},
								{fals, true, 0, "DIANA                            Je ne peux pas m'empecher d'etre sur mes gardes, mais je pense que"},
								{fals, true, 0, "DIANA                            tout ira bien ici."},
								{fals, true, 0, "ELEANOR                          Je pense la meme chose."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						case 6:
						{
							auto b_button = bn::sprite_items::b_button.create_sprite(90, -50, globals->all_save.language);
							auto uke_anim = bn::create_sprite_animate_action_forever(current_room.chari.at(current_room.follow_id).entity, 12, bn::sprite_items::diana_uke.tiles_item(), 0, 1, 2, 3);
							bn::music::stop();
							bn::music_items::z23_diana.play(0.8);

							while (!bn::keypad::b_pressed())
							{
								bn::core::update();

								uke_anim.update();
								current_room.chari.at(current_room.follow_id).entity = uke_anim.sprite();
							}

							bn::music::stop();
							bn::music_items::v01.play(0.8);
						}
						}
					}
					else if (globals->current_save->checkpoint < 12)
					{
						switch (me)
						{
						default:
						{
							break;
						}

						case 0:
						{
							line lc[32] = {
								{fals, true, 0, "MAPLE                            Diana! He!"},
								{fals, true, 0, "DIANA                            He, Maple! Comment tu vas?"},
								{fals, true, 0, "MAPLE                            Bien, je suis entrain de         m'ennuyer ."},
								{fals, true, 0, "DIANA                            As tu regarder Scout TV ce matin?"},
								{fals, true, 0, "MAPLE                            Celui que Rufus a pirate? C'est  un idiot, tout ira bien."},
								{fals, true, 0, "MAPLE                            Peut-etre que maintenant il pensequ'il est un super mechant ou    "},
								{fals, true, 0, "MAPLE                            quelque chose."},
								{fals, true, 0, "DIANA                            Des gars comme ]a me font rire   aux eclats, vraiment. Haha!"},
								{fals, true, 0, "MAPLE                            En passant. Previens-moi si tu levois dans le coin."},
								{fals, true, 0, "MAPLE                            Je vais essayer de lui parler."},
								{fals, true, 0, "DIANA                            Okay."},
								{fals, true, 0, "DIANA                            Que fais tu dernierement?"},
								{fals, true, 0, "MAPLE                            As-tu vu Scout? Ce pauvre garc a vraiment son oeil sur moi.."},
								{fals, true, 0, "MAPLE                            C'est un gars adorable, mais je  devrai lui faire comprendre      "},
								{fals, true, 0, "MAPLE                            bientot qu'il est pas mon genre."},
								{fals, true, 0, "DIANA                            Fille, je t'envie pas, haha. Cestquoi ton type?"},
								{fals, true, 0, "MAPLE                            J'aimerais quelqu'un qui est     calme et qui me fait sentir      "},
								{fals, true, 0, "MAPLE                            excitee."},
								{fals, true, 0, "MAPLE                            Tous les gar]ons agissent comme  si j'etait une deesse et je      "},
								{fals, true, 0, "MAPLE                            n'aime pas ]a. Je pourrais faire un barbecue avec eux si je le"},
								{fals, true, 0, "MAPLE                            voulais."},
								{fals, true, 0, "DIANA                            Heh, peut-etre que tout le monde te traite comme ]a parce que tu  "},
								{fals, true, 0, "DIANA                            finis par leur faire peur."},
								{fals, true, 0, "MAPLE                            Je devrais trouvee un autre elfe du feu."},
								{fals, true, 0, "DIANA                            Nous sommes loin dans le sud-est,il en a pas beaucoup."},
								{fals, true, 0, "MAPLE                            Ouais, je vais continuer a       chercher, meme si cette ile est  "},
								{fals, true, 0, "MAPLE                            petite."},
								{fals, true, 0, "DIANA                            Bonne chance, ha ha. Prends bien soin de toi, Maple."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						case 1:
						{
							line lc[32] = {
								{fals, true, 0, "ENOKI                            He fille!"},
								{fals, true, 0, "DIANA                            Enoki, ma cherie! Veux-tu une    collation?"},
								{fals, true, 0, "ENOKI                            Comme toujours."},
								{fals, true, 0, "DIANA                            Haha, j'aime ]a comme ]a. Comments'est passee ta journee?"},
								{fals, true, 0, "ENOKI                            Bon, meme si je suis un peu      inquiete."},
								{fals, true, 0, "DIANA                            Ah, et pourquoi?"},
								{fals, true, 0, "ENOKI                            Eh bien, Aaron et Maple se       dispute recemment."},
								{fals, true, 0, "DIANA                            Quelque chose est arrive?"},
								{fals, true, 0, "ENOKI                            Et bien Aaron retient toujours   ses emotions."},
								{fals, true, 0, "ENOKI                            Et Maple dit tout en face sans   penser a nos sentiments."},
								{fals, true, 0, "DIANA                            C'est pas une bonne combinaison."},
								{fals, true, 0, "ENOKI                            ..]a ce calme apres, mais ]a me  rend triste a chaque fois que ]a "},
								{fals, true, 0, "ENOKI                            arrive."},
								{fals, true, 0, "DIANA                            Je n'ai pas de freres et soeurs  mais... C'est comme ]a hein?"},
								{fals, true, 0, "ENOKI                            Es tu aussi enfant unique?       J'aurais aime avoir une soeur."},
								{fals, true, 0, "DIANA                            Moi un frere, moins de drames."},
								{fals, true, 0, "ENOKI                            Je vois, je vois."},
								{fals, true, 0, "DIANA                            Tiens-moi au courant, d'accord?"},
								{fals, true, 0, "ENOKI                            D'accord."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						case 2:
						{
							line lc[32] = {
								{fals, true, 0, "DIANA                            He, Aaron! En quoi je peux       t'aider?"},
								{fals, true, 0, "AARON                            Tu as entendu parler du jeu de   societe ce soir?"},
								{fals, true, 0, "DIANA                            Oui! Je serai la. As-tu vu       l'emission?"},
								{fals, true, 0, "AARON                            J'ai parle a Maple, et elle      semble connaitre ce Plonj."},
								{fals, true, 0, "AARON                            Elle ne parait pas derangee."},
								{fals, true, 0, "DIANA                            Oh, je suis contente d'entendre  ]a. On se voit ce soir?"},
								{fals, true, 0, "AARON                            Bien sur!"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						case 3:
						{
							line lc[32] = {
								{fals, true, 0, "SCOUT                            He! C'est moi, Scout."},
								{fals, true, 0, "DIANA                            He Scout! Quoi de neuf?"},
								{fals, true, 0, "SCOUT                            Il semble que le Scout TV de ce  mois-ci soit termine."},
								{fals, true, 0, "SCOUT                            Maintenant, je n'ai plus qu'a    m'occuper de l'Expo Scout."},
								{fals, true, 0, "DIANA                            Tu en parles toujours, qu'est-ce que c'est exactement?"},
								{fals, true, 0, "SCOUT                            C'est un endroit ou je montre mesinventions. D'habitude, je poste "},
								{fals, true, 0, "SCOUT                            en ligne, mais la j'ai des amis aqui je peux montrer mes gadgets!"},
								{fals, true, 0, "DIANA                            ..]a a l'air amusant! Peux tu me faire un exemple?"},
								{fals, true, 0, "SCOUT                            Ah, ah, ah. Tu vas d'avoir       attendre l'Expo comme le reste."},
								{fals, true, 0, "DIANA                            D'accord... J'etais juste        curieuse."},
								{fals, true, 0, "SCOUT                            ...Eh bien, j'ai cree cet        appareil-"},
								{fals, true, 0, "DIANA                            Mais tu viens de dire, que je    devais attendre."},
								{fals, true, 0, "SCOUT                            Mais je- Et... hmm... J'avoue,   j'ai de la misere a attendre"},
								{fals, true, 0, "DIANA                            Heh, je le savais."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						// Fall-through to the next bit
						case 4:
						{
							line lc[32] = {
								{fals, true, 0, "DIANA                            He, Vee! Comment ]a va?"},
								{fals, true, 0, "OLIVIER                          Bien, bien."},
								{fals, true, 0, "DIANA                            Tu viens  tu me damander pour    organiser un jeu ici?"},
								{fals, true, 0, "OLIVIER                          Non! Pas du tout... On le fais   dehors."},
								{fals, true, 0, "OLIVIER                          Et si tout va bien, l'ile ne     bruleras pas."},
								{fals, true, 0, "OLIVIER                          Comment vont tous le monde hors  de l'ile?"},
								{fals, true, 0, "DIANA                            Merveilleux! Mes parents         aimeraient y passer un jour."},
								{fals, true, 0, "DIANA                            Bien que ma maison soit en       desordre. Peux-tu me laisser la  "},
								{fals, true, 0, "DIANA                            tienne?"},
								{fals, true, 0, "OLIVIER                          Continue a rever, hahaha."},
								{fals, true, 0, "OLIVIER                          Je devrais inviter ma famille un jour."},
								{fals, true, 0, "DIANA                            Oh, ils aimeront l'ile."},
								{fals, true, 0, "DIANA                            J'espere que tout iras bien."},
								{fals, true, 0, "OLIVIER                          Esperons que oui. Haha."},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						case 5:
						{
							line lc[32] = {
								{fals, true, 0, "ELEANOR                          Bonjour!"},
								{fals, true, 0, "DIANA                            Bonjour ma cherie! What's up?"},
								{fals, true, 0, "ELEANOR                          Oh, quelle est cette odeur?      etais-tu en train de petrir"},
								{fals, true, 0, "ELEANOR                          quelque chose?"},
								{fals, true, 0, "DIANA                            Non, je crois que je dois        nettoyer ma chambre..."},
								{fals, true, 0, "DIANA                            Comment vas-tu? Quelque chose de nouveau?"},
								{fals, true, 0, "ELEANOR                          Oh pas grand-chose, j'ai cousu   une courtepointe.."},
								{fals, true, 0, "DIANA                            Fantastique. Tu as utilise quoi  comme materiel?"},
								{fals, true, 0, "ELEANOR                          J'ai apporte tous les vetements  de ma ville natale sur l'ile."},
								{fals, true, 0, "ELEANOR                          Ils sont tous bon pour la        poubelle, mais j'ai honte de m'en"},
								{fals, true, 0, "ELEANOR                          debarrasser."},
								{fals, true, 0, "ELEANOR                          Ils ont toujours ete avec moi    alors je vais en faire une"},
								{fals, true, 0, "ELEANOR                          courtepointe."},
								{fals, true, 0, "DIANA                            Aw, ]a va etre magnifique."},
								{fals, true, 0, "DIANA                            As-tu dessine recemment?"},
								{fals, true, 0, "ELEANOR                          Un peu! Il y a beaucoup de beaux paysages ici."},
								{fals, true, 0, "DIANA                            Je pourrais jouer de la guitare  en voyageant l'ocean pour le"},
								{fals, true, 0, "DIANA                            reste de ma vie."},
								{fals, true, 0, "DIANA                            Well, quand je dis ocean, je veuxdire  le lac."},
								{fals, true, 0, "DIANA                            Je crois que j'ai le coeur marin."},
								{fals, true, 0, "ELEANOR                          ..]a semble etre une belle vie."},
								{fals, true, 0, "DIANA                            Arrrrrrrg, je vais etre une      pirates!"},
								{fals, true, 0, "DIANA                            Ne t'inquiete pas, je viendrais  faire des visites tous le tempes"},
								{fals, true, 0, "ELEANOR                          S'il te plait!"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}

						case 6:
						{
							auto b_button = bn::sprite_items::b_button.create_sprite(90, -50, globals->all_save.language);
							auto uke_anim = bn::create_sprite_animate_action_forever(current_room.chari.at(current_room.follow_id).entity, 12, bn::sprite_items::diana_uke.tiles_item(), 0, 1, 2, 3);
							bn::music::stop();
							bn::music_items::z23_diana.play(0.8);

							while (!bn::keypad::b_pressed())
							{
								bn::core::update();

								uke_anim.update();
								current_room.chari.at(current_room.follow_id).entity = uke_anim.sprite();
							}

							bn::music::stop();
							bn::music_items::v01.play(0.8);
							break;
						}

						case 7:
						{
							line lc[32] = {
								{fals, true, 0, "DIANA                            Salut! Tu es Guy, n'est-ce pas?"},
								{fals, true, 0, "GUY                              C'est moi! Tu vis ici?"},
								{fals, true, 0, "DIANA                            C'est humble mais c'est ma       nouvelle maison. Tu aimes la     "},
								{fals, true, 0, "DIANA                            tienne?"},
								{fals, true, 0, "GUY                              Des mon plus jeune age, je revaisd'avoir ma propre cuisine de     "},
								{fals, true, 0, "GUY                              taille industrielle a cote d'un  lit escamotable."},
								{fals, true, 0, "DIANA                            C'est un reve tres specifique,   mais je comprends."},
								{fals, true, 0, "GUY                              T'as meme pas de cuisine dans ta cabine?"},
								{fals, true, 0, "DIANA                            J'ai un four et un mini frigo,   haha."},
								{fals, true, 0, "DIANA                            J'apporte des produits importes  donc je mange beaucoup de        "},
								{fals, true, 0, "DIANA                            conserves"},
								{fals, true, 0, "GUY                              C'est pas tres bon pour la sante tu sais?"},
								{fals, true, 0, "DIANA                            Oui, eh bien, je vais penser a ]adans plusieurs annees."},
								{fals, true, 0, "DIANA                            Tout le monde devient gros et    vieux un jour."},
								{fals, true, 0, "GUY                              Pas moi. Un jour, je serai plus  vieux mais toujours en bonne     "},
								{fals, true, 0, "GUY                              sante et mince."},
								{fals, true, 0, "DIANA                            Nous verrons qui sera en meilleursante quand nous atteindrons 50  "},
								{fals, true, 0, "DIANA                            ans."},
								{fals, true, 0, "GUY                              Avec plaisir."},
								{fals, true, 0, "DIANA                            Nous allons jouer a un jeu de    societe ce soir. Tu viens?"},
								{fals, true, 0, "GUY                              Non, je vais etre occupe avec ma cuisine toute la nuit."},
								{fals, true, 0, "DIANA                            Oh... D'accord, j'ai compris."},
								{fals, true, 0, "DIANA                            Tu me diras comment c'est."},
								{fals, true, 0, "GUY                              Bien sur!"},
								{true, true, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						}
					}
					break;
				}

				// Corinne meet 'n greet
				case 63:
				{
					if (globals->current_save->checkpoint < 10)
					{
						// corinne.set_blending_enabled(false);
						line lc[32] = {
							{fals, true, 0, "OLIVIER                          O-Oh! Excusez-moi Madame. D'ou   venez-vous?"},
							{fals, true, 0, "GRAND-MERE CORINNE               Cette serre a fiere allure.      As-t-elle ete bouge?"},
							{fals, true, 0, "OLIVIER                          Oh, ils m'ont dit qu'ils         l'avaient apporte de l'exterieur."},
							{fals, true, 0, "GRAND-MERE CORINNE               Tu vois jeune homme, cette serre etait la mienne."},
							{fals, true, 0, "GRAND-MERE CORINNE               Je pense qu'il ne sert a rien de le cacher, je suis un fantome."},
							{fals, true, 0, "OLIVIER                          Un fantome???"},
							{fals, true, 0, "GRAND-MERE CORINNE               Il semble que je sois condamnee ahantee cette serre."},
							{fals, true, 0, "OLIVIER                          Mes excuses... ..]a semble etre  terrible..."},
							{fals, true, 0, "GRAND-MERE CORINNE               Trouvez-vous terrible de passer  une eternite ici?"},
							{fals, true, 0, "OLIVIER                          A la reflexion... Je suppose que ce n'est pas si mal."},
							{fals, true, 0, "OLIVIER                          Mon sejour ici a ete agreable."},
							{fals, true, 0, "GRAND-MERE CORINNE               Je vois que tu aimes entretenir  ces plantes, jeune homme."},
							{fals, true, 0, "GRAND-MERE CORINNE               Laissez-moi vous dire quelque    chose avant de vous dire au      "},
							{fals, true, 0, "GRAND-MERE CORINNE               revoir."},
							{fals, true, 0, "GRAND-MERE CORINNE               S'occuper des plantes semble     inutile."},
							{fals, true, 0, "GRAND-MERE CORINNE               Un bel avenir attend les gens    patient."},
							{fals, true, 0, "GRAND-MERE CORINNE               Ce fut un plaisir de te          rencontrer. Prends soin de toi!"},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					}
					else if (globals->current_save->checkpoint < 12)
					{
						// corinne.set_blending_enabled(false);
						line lc[32] = {
							{true, true, 0, "OLIVIER                          Bonjour, Grand-Mere!"},
							{true, true, 0, "GRAND-MERE CORINNE               Bonjour, Olivier. C'est agreable d'avoir des visiteurs."},
							{true, true, 0, "OLIVIER                          Comment s'est passee ta journee?"},
							{true, true, 0, "GRAND-MERE CORINNE               Oh, comme d'habitude.. Troubles  eternels. Une vie de fantome."},
							{true, true, 0, "GRAND-MERE CORINNE               Ou son absence, hehe."},
							{true, true, 0, "OLIVIER                          L'au-dela semble plutot terne."},
							{true, true, 0, "GRAND-MERE CORINNE               Ce n'est pas necessaire. Dites..."},
							{true, true, 0, "GRAND-MERE CORINNE               pouvez-vous me parler de cet     homme?"},
							{true, true, 0, "OLIVIER                          Homme?"},
							{true, true, 0, "GRAND-MERE CORINNE               Oui, le costaud capitaine de     bateau. Avec la barbe?"},
							{true, true, 0, "OLIVIER                          Ah, le capitaine? L'aimes-tu?"},
							{true, true, 0, "GRAND-MERE CORINNE               Cela semble plutot morbide, mais combien d'annees pensez-vous    "},
							{true, true, 0, "GRAND-MERE CORINNE               qu'il lui reste?"},
							{true, true, 0, "GRAND-MERE CORINNE               Je ne suppose pas qu'il          apprecierait une vie apres"},
							{true, true, 0, "GRAND-MERE CORINNE               la mort ici."},
							{true, true, 0, "OLIVIER                          Cet.. euh.. question vaut        peut-etre mieux lui poser."},
							{true, true, 0, "GRAND-MERE CORINNE               Bien sur, bien sur."},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					}

					break;
				}

				// Guy's house
				case 64:
				{
					dt.spawn_x = 3;
					dt.spawn_y = 5;
					dt.world_index = 13;
					return dt;
				};
				case 65:
				{
					dt.spawn_x = 13;
					dt.spawn_y = 17;
					dt.world_index = 8;
					return dt;
				};

				// Northern Area
				case 66:
				{
					dt.spawn_x = 7;
					dt.spawn_y = 18;
					dt.world_index = 14;
					return dt;
				}
				case 67:
				{
					dt.spawn_x = 16;
					dt.spawn_y = 1;
					dt.world_index = 4;
					return dt;
				}
				case 68:
				{
					dt.spawn_x = 7;
					dt.spawn_y = 0;
					dt.world_index = 99;
					return dt;
				}
				case 69:
				{
					line lc[32] = {
						{fals, true, 0, "LE BIZAAR D'CESAR                'NOUS AVONS SEULEMENT DEUX       ARTICLES, DEAL WITH IT'"},
						{true, true, 0, "COM: Endscene"}};
					dialogue_page_lite(lc);
					break;
				}

				// i make-a da gumbo
				case 70:
				{
					switch (me)
					{
					case 0:
					{
						line lc[32] = {
							{fals, true, 0, "MAPLE                            Alors... Guy, uhg... Tu met de latomate sur le Jambalaya?"},
							{fals, true, 0, "GUY                              Comme Dieu le voulais."},
							{fals, true, 0, "MAPLE                            Comme Dieu le voulais?"},
							{fals, true, 0, "MAPLE                            ...Tu te moque de moi?"},
							{fals, true, 0, "GUY                              Tu fais aussi partie de ceux qui aiment leur roux brule?"},
							{fals, true, 0, "MAPLE                            Definit 'brule'."},
							{fals, true, 0, "GUY                              Tellement brule qu'il perd ses   couleurs et qu'on ne peut plus le"},
							{fals, true, 0, "GUY                              gouter."},
							{fals, true, 0, "MAPLE                            Comment ]a 'plus le gouter'.     J'aime le gout!"},
							{fals, true, 0, "GUY                              Oui, parce que tu l'enterre dans un tas d'epices au hasard."},
							{fals, true, 0, "MAPLE                            Mon choix d'epices n'est PAS     aleatoire."},
							{fals, true, 0, "GUY                              j'ai plus rien a dire, si tu veuxbien m'excuser, je vais balayer  "},
							{fals, true, 0, "GUY                              le sol"},
							{fals, true, 0, "GUY                              de la cuisine pour faire un bon  jambalaya."},
							{fals, true, 0, "MAPLE                            Les creoles sont mortelles en    cusime."},
							{fals, true, 0, "GUY                              Pas autant que les acadiens, ma  fille, tu sais quoi?"},
							{fals, true, 0, "GUY                              Organisons un concours de gombos et laissons les autres juger,    "},
							{fals, true, 0, "GUY                              hein?"},
							{fals, true, 0, "MAPLE                            Parfait. C'est de la tarte."},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					}
					case 1:
					{
						line lc[32] = {
							{fals, true, 0, "ENOKI                            Ooooooh... j'adore ta cuisine,   elle est immense!"},
							{fals, true, 0, "GUY                              Merci. Je peux meme rouler de monlit pour prendre du pain de mais."},
							{fals, true, 0, "ENOKI                            J'aimerais ]a aussi, hehe."},
							{fals, true, 0, "GUY                              Au fait, euh. Cette Maple...     Est-ce que son gombo est meilleur"},
							{fals, true, 0, "GUY                              ou le mien?"},
							{fals, true, 0, "ENOKI                            Es-tu en competition avec elle?  Si oui, je veux pas choisir."},
							{fals, true, 0, "ENOKI                            Je veux pas me retourner contre  toi maintenant que tu as demenage"},
							{fals, true, 0, "ENOKI                            ici."},
							{fals, true, 0, "ENOKI                            Mais tu devrais savoir que Maple et moi somme meilleures amies."},
							{fals, true, 0, "GUY                              Peut-etre que je peux te cuisinerun gombo qui te fera             "},
							{fals, true, 0, "GUY                              reconsiderer."},
							{fals, true, 0, "ENOKI                            ..]a vas etre complique. Je     n'aime pas vraiment manger /tant/"},
							{fals, true, 0, "ENOKI                            que ]a."},
							{fals, true, 0, "GUY                              Mais... Ah, anyway. Prends soin  de toi, cherie."},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					}
					case 2:
					{
						line lc[32] = {
							{fals, true, 0, "AARON                            ..]a sent bon ici!"},
							{fals, true, 0, "GUY                              Oui, c'est comme ]a que ]a doit  etre."},
							{fals, true, 0, "AARON                            He, j'ai entendu dire que tu     etais venu chercher des clients?"},
							{fals, true, 0, "GUY                              C'est vrai."},
							{fals, true, 0, "AARON                            Well, euh... Comme tu peux le    voir, on est pas beaucoup ici."},
							{fals, true, 0, "AARON                            Bien que j'essaie de faire de    l'ile un beau chez-soi."},
							{fals, true, 0, "GUY                              Ou veux-tu en venir?"},
							{fals, true, 0, "AARON                            J'espere juste que vous savez quenous sommes pas assez nombreux   "},
							{fals, true, 0, "AARON                            pour avoir notre propre monnaie  et c'est pas tout qui traine du"},
							{fals, true, 0, "AARON                            cash."},
							{fals, true, 0, "GUY                              Je facture que 5 dollars, c'est  abordable et j'attends des       "},
							{fals, true, 0, "GUY                              clients."},
							{fals, true, 0, "AARON                            You knoe what? Combien coute     cette cabine? 10 ou 20 mille     "},
							{fals, true, 0, "AARON                            dollars?"},
							{fals, true, 0, "AARON                            Je sais pas faire de maths, j'ai jamais obtenu mon diplome        "},
							{fals, true, 0, "AARON                            d'etudes secondaires."},
							{fals, true, 0, "AARON                            Elle n'est pas la, mais Enoki    peut faire des calculs complexes."},
							{fals, true, 0, "AARON                            Et si tu donnais des repas       gratuits pour le reste de        "},
							{fals, true, 0, "AARON                            l'annee?"},
							{fals, true, 0, "AARON                            Et ]a payeras le loyer. C'est    bon?"},
							{fals, true, 0, "GUY                              Je vais y reflechir."},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					}
					case 3:
					{
						line lc[32] = {
							{fals, true, 0, "OLIVIER                          O-Oh! Excusez-moi Madame. D'ou   venez-vous?"},
							{fals, true, 0, "GRAND-MERE CORINNE               Cette serre a fiere allure.      As-t-elle ete bouge?"},
							{fals, true, 0, "OLIVIER                          Oh, ils m'ont dit qu'ils         l'avaient apporte de l'exterieur."},
							{fals, true, 0, "GRAND-MERE CORINNE               Tu vois jeune homme, cette serre etait la mienne."},
							{fals, true, 0, "GRAND-MERE CORINNE               Je pense qu'il ne sert a rien de le cacher, je suis un fantome."},
							{fals, true, 0, "OLIVIER                          Un fantome???"},
							{fals, true, 0, "GRAND-MERE CORINNE               Il semble que je sois condamnee ahantee cette serre."},
							{fals, true, 0, "OLIVIER                          Mes excuses... ..]a semble etre  terrible..."},
							{fals, true, 0, "GRAND-MERE CORINNE               Trouvez-vous terrible de passer  une eternite ici?"},
							{fals, true, 0, "OLIVIER                          A la reflexion... Je suppose que ce n'est pas si mal."},
							{fals, true, 0, "OLIVIER                          Mon sejour ici a ete agreable."},
							{fals, true, 0, "GRAND-MERE CORINNE               Je vois que tu aimes entretenir  ces plantes, jeune homme."},
							{fals, true, 0, "GRAND-MERE CORINNE               Laissez-moi vous dire quelque    chose avant de vous dire au      "},
							{fals, true, 0, "GRAND-MERE CORINNE               revoir."},
							{fals, true, 0, "GRAND-MERE CORINNE               S'occuper des plantes semble     inutile."},
							{fals, true, 0, "GRAND-MERE CORINNE               Un bel avenir attend les gens    patient."},
							{fals, true, 0, "GRAND-MERE CORINNE               Ce fut un plaisir de te          rencontrer. Prends soin de toi!"},

							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					}
					case 4:
					{
						line lc[32] = {
							{fals, true, 0, "OLIVIER                          Bonjour!"},
							{fals, true, 0, "GUY                              Oui. J'suppose que tu es le      jardinier?"},
							{fals, true, 0, "GUY                              Cultive-tu du celeri, de l'oignonet des poivrons?"},
							{fals, true, 0, "OLIVIER                          Bien sur!"},
							{fals, true, 0, "GUY                              Tu sais? Tu peux m'apporter de lamarchandise fraiche."},
							{fals, true, 0, "GUY                              En retour, je te cuisinerais du  gombo gratuitement."},
							{fals, true, 0, "OLIVIER                          Et ma femme?"},
							{fals, true, 0, "GUY                              C'est celle avec la tenue ou les cheveux de Wendy?"},
							{fals, true, 0, "OLIVIER                          ...C'est celle qui a les cheveux bruns."},
							{fals, true, 0, "GUY                              Je vois, merci Dave."},
							{fals, true, 0, "OLIVIER                          ...Olivier. Olivier Landry."},
							{fals, true, 0, "OLIVIER                          Ton nom est Guy non?"},
							{fals, true, 0, "GUY                              Correct."},
							{fals, true, 0, "OLIVIER                          'Guy Pizza'?"},
							{fals, true, 0, "GUY                              C'etait une blague, mais ne le   dis a personne. Compris?"},
							{fals, true, 0, "OLIVIER                          Compris."},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					}
					case 5:
					{
						line lc[32] = {
							{fals, true, 0, "ELEANOR                          Bonjour! Comment allez-vous?"},
							{fals, true, 0, "GUY                              C'est bon, et comment vas-tu?"},
							{fals, true, 0, "ELEANOR                          Cet endroit me donne vraiment    faim, et ]a sent bon!"},
							{fals, true, 0, "GUY                              Vraiment?"},
							{fals, true, 0, "ELEANOR                          J'aime la patisserie plus que    cuisiner, mais cette cuisine est "},
							{fals, true, 0, "ELEANOR                          geniale!"},
							{fals, true, 0, "GUY                              Qu'est-ce que tu aimes faire au  four?"},
							{fals, true, 0, "ELEANOR                          Ma preferee est la tarte au      citron vert, meme si je dois     "},
							{fals, true, 0, "ELEANOR                          faire beaucoup de pacanes        pralinees. Aimes-tu ]a?"},
							{fals, true, 0, "GUY                              Si j'aime le praline?"},
							{fals, true, 0, "GUY                              SI J'AIME LA PRALINE?"},
							{fals, true, 0, "GUY                              C'est delicieux."},
							{fals, true, 0, "GUY                              Tu m'apporte des pralines et je  t'offre des repas gratuits,      "},
							{fals, true, 0, "GUY                              d'accord?"},
							{fals, true, 0, "ELEANOR                          Affaire conclue!"},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					}
					case 6:
					{
						line lc[32] = {
							{fals, true, 0, "DIANA                            Salut! Tu es Guy Pizza si je me  souviens bien?"},
							{fals, true, 0, "GUY                              Guy Pizza, the one and only."},
							{fals, true, 0, "DIANA                            Je peux comprendre pourquoi,     haha. Tu es italien?"},
							{fals, true, 0, "GUY                              Non, je viens de Donaldsonville. Nouveau nom, nouvelle vie."},
							{fals, true, 0, "DIANA                            Et tu as choisit 'pizza'?"},
							{fals, true, 0, "GUY                              Les gens m'appellent 'pizza guy' depuis des annees."},
							{fals, true, 0, "GUY                              Mon nom est Guy en plus et ]a    rend les gens affames."},
							{fals, true, 0, "DIANA                            Bien sur, tous le monde aime la  pizza. En fais tu souvent?"},
							{fals, true, 0, "GUY                              Pas vraiment."},
							{fals, true, 0, "DIANA                            Tu peux toujours change de nom."},
							{fals, true, 0, "GUY                              As-tu des suggestions?"},
							{fals, true, 0, "DIANA                            Guy... le Mysterieux. Les gens   aiment l'enigmatique"},
							{fals, true, 0, "GUY                              Je suis pas magician."},
							{fals, true, 0, "DIANA                            Tu n'es pas une pizza non plus."},
							{fals, true, 0, "GUY                              Touche."},
							{fals, true, 0, "GUY                              Je vais me rappeler d ]a."},
							{true, true, 0, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					}
					case 7:
					{
						dt.spawn_x = 8;
						dt.spawn_y = 0;
						dt.world_index = 99;
						return dt;
						break;
					}
					default:
					{
					}
					}
					break;
				}

				case 71:
				{
					line lc[5] = {
						{fals, true, 0, "AARON                            On dirait qu'il n'y a personne a la maison."},
						{true, true, 0, "COM: Endscene"}};
					dialogue_page_lite(lc);
					break;
				};

				case 72:
				{
					if (!jukebox)
					{
						bn::music::stop();
						bn::music_items::z14_flame.play(0.8);
						jukebox = true;
					}
					else
					{
						bn::music::stop();
						bn::music_items::new_castle.play(0.8);
						jukebox = false;
					}
				};

				default:
				{
				};
				}

				globals->current_save->xp += 2;
				xphud.acknowledge();
			}

		}
		else {
			current_room.a_notif.set_visible(false);
		}

		// Hat logic
		if (active_hat)
		{
			if (globals->current_save->hat_char > -1)
			{
				short int my_id = 0;
				for (int i = 0; i < current_room.chari.size(); i++)
				{
					if (current_room.chari.at(i).identity == globals->current_save->hat_char)
						my_id = i;
				}

				hat.set_position(current_room.chari.at(my_id).entity.x().integer(), current_room.chari.at(my_id).entity.y().integer() - 22);
				hat.set_z_order(2);
				l_button.set_visible(true);

				if (bn::keypad::l_pressed())
				{
					bn::sound_items::pop.play();
					globals->current_save->hat_x = current_room.chari.at(my_id).entity.x().integer();
					globals->current_save->hat_y = current_room.chari.at(my_id).entity.y().integer() + 1;
					globals->current_save->hat_world = dt.world_index;
					globals->current_save->hat_char = -1;
					l_button.set_visible(false);
				}
			}
			else
			{
				hat.set_position(globals->current_save->hat_x, globals->current_save->hat_y);

				if (globals->current_save->hat_y > current_room.chari.at(current_room.follow_id).entity.y())
				{
					hat.put_above();
				}
				else
				{
					hat.put_below();
				}

				if (abs(globals->current_save->hat_x - current_room.chari.at(current_room.follow_id).entity.x().integer()) + abs(globals->current_save->hat_y - current_room.chari.at(current_room.follow_id).entity.y().integer()) < 32)
				{
					current_room.a_notif = bn::sprite_items::a_button_2.create_sprite(globals->current_save->hat_x, globals->current_save->hat_y - 28, 1);
					current_room.a_notif.set_camera(current_room.camera);
					current_room.a_notif.set_visible(true);
				}

				if (bn::keypad::l_pressed())
				{
					bn::sound_items::squeak.play();
					globals->current_save->hat_char = current_room.chari.at(current_room.follow_id).identity;
				}
			}
		}

		current_room.update_objects();

		// Handle animated objects
		for (unsigned short int t = 0; t < anim_objects.size(); t++) {
			anim_objects.at(t).update();
			anim_objects.at(t).entity.set_camera(current_room.camera);
		}

		bn::core::update();

		// World-specific special events

		switch (dt.world_index) {
		case 1: {
			for (int i = 0; i < current_room.p.size(); i++)
			{
				short int my_x = current_room.p.at(i).fireball.x().integer() / 32;
				short int my_y = current_room.p.at(i).fireball.y().integer() / 32;
				if (my_x >= 8 && my_x <= 11 && my_y >= 4 && my_y <= 7)
				{
					anim_objects.at(0).entity.set_visible(true);
				}
			}
			break;
		}
		case 2: {
			for (int i = 0; i < current_room.p.size(); i++)
			{
				if (current_room.p.at(i).dur < 16)
				{
					short int my_x = current_room.p.at(i).fireball.x().integer() / 32;
					short int my_y = current_room.p.at(i).fireball.y().integer() / 32;
					if (my_x >= 2 && my_x <= 3 && my_y >= 2 && my_y <= 3)
					{
						current_room.p.at(i).dur = 16;
						//current_room.p.erase(current_room.p.begin() + i);

						anim_objects.at(0).entity_anim = bn::create_sprite_animate_action_forever(anim_objects.at(0).entity, 18, anim_objects.at(0).entity_item.tiles_item(), 2, 1, 00, 1);
						anim_objects.at(0).entity.set_horizontal_flip(!anim_objects.at(0).entity.horizontal_flip());
						break;

						//anim_objects.at(0).entity_anim.update();
					}
				}
			}
			break;
		}
		case 3: {
			//(144,16);
			for (int i = 0; i < current_room.p.size(); i++)
			{
				short int my_x = current_room.p.at(i).fireball.x().integer() / 32;
				short int my_y = current_room.p.at(i).fireball.y().integer() / 32;
				if (my_x >= 4 && my_x <= 5 && my_y >= 0 && my_y <= 1)
				{
					current_room.p.at(i).dur = 16;
					bn::sound_items::firecrackle.play();
					anim_objects.at(0).entity_anim = bn::create_sprite_animate_action_forever(anim_objects.at(0).entity, 18, anim_objects.at(0).entity_item.tiles_item(), 1, 1, 1, 1);
					anim_objects.at(0).entity_anim.update();
					current_room.a_notif.set_visible(false);

					if (bn::music::playing())
						bn::music::stop();
					for (short int t = 0; t < 128; t++)
					{
						current_room.chari.at(0).update();
						current_room.p.at(i).update();
						bn::core::update();
					}

					line lc[18] = {
					{fals, true, 0, "ENOKI                            Eh bien, il n'y a pas de passage."},
					{fals, true, 0, "MAPLE                            Wow, vraiment."},
					{fals, true, 0, "ENOKI                            Comme c'est etrange."},
					{fals, true, 0, "MAPLE                            Enoki..."},
					{fals, true, 0, "MAPLE                            Je suppose que ]a sert a rien de se facher contre toi, mais tu"},
					{fals, true, 0, "MAPLE                            devrais arreter d'agir comme ]a."},
					{fals, true, 0, "MAPLE                            Toi et Aaron avez depense une    fortune dans un chateau non"},
					{fals, true, 0, "MAPLE                            meuble."},
					{fals, true, 0, "MAPLE                            Et pourquoi? Pour jouer a la     princesse? Pendant ce temps, je"},
					{fals, true, 0, "MAPLE                            sacrifie ma jeunesse dan un      apartemnt en Caroline avec juste"},
					{fals, true, 0, "MAPLE                            le necessaire."},
					{fals, true, 0, "MAPLE                            Il est 5 heures du matin, je     retourne me coucher. Je te verrai"},
					{fals, true, 0, "MAPLE                            demain matin, oui?"},
					{fals, true, 0, "ENOKI                            Oui..."},
					{fals, true, 0, "MAPLE                            Ne pense pas trop a ce que j'ai  dit. S'il te plait, bonne nuit."},
					{fals, true, 0, "ENOKI                            Bonne nuit..."},
					{true, true, 0, "COM: Endscene"}
					};
					dialogue_page_lite(lc);

					dt.world_index = -1;
					return dt;
				}
			}
			break;
		}
		case 11: {
			bn::sprite_ptr* corinne = &current_room.anim_objects.at(0).entity;

			if (corinne->visible())
			{
				if (abs(current_room.chari.at(current_room.follow_id).entity.x().integer() - corinne->x().integer()) + abs(current_room.chari.at(current_room.follow_id).entity.y().integer() - corinne->y().integer()) < 48)
				{
					corinne->set_blending_enabled(true);
					bn::blending::set_transparency_alpha(0.5);
				}
				else
				{
					corinne->set_blending_enabled(false);
				}
			}

			if (current_room.chari.at(current_room.follow_id).identity == 4 && bn::keypad::r_pressed() && corinne->visible() == false)
			{
				corinne->set_visible(true);
				corinne->set_x(current_room.chari.at(current_room.follow_id).entity.x());
				bn::sound_items::pop.play();

				if (current_room.chari.at(current_room.follow_id).entity.y() < (current_room.height * 32) / 2)
				{
					corinne->set_y(current_room.chari.at(current_room.follow_id).entity.y() + 192);
				}
				else
				{
					corinne->set_y(current_room.chari.at(current_room.follow_id).entity.y() - 192);
				}

				short int s_x = (corinne->x().integer() + 16) / 32;
				short int s_y = (corinne->y().integer() + 16) / 32;
				corinne->set_position(s_x * 32, s_y * 32);

				if (globals->collisions.at(s_x + (current_room.width * (s_y + 1))) == 0)
				{
					globals->collisions.at(s_x + (current_room.width * (s_y + 1))) = 63;
				}
				else if (globals->collisions.at(s_x + (current_room.width * (s_y - 1))) == 0)
				{
					globals->collisions.at(s_x + (current_room.width * (s_y - 1))) = 63;
				}
				else if (globals->collisions.at(s_x + (current_room.width * s_y) - 1) == 0)
				{
					globals->collisions.at(s_x + (current_room.width * s_y) - 1) = 63;
				}
				else if (globals->collisions.at(s_x + (current_room.width * s_y) + 1) == 0)
				{
					globals->collisions.at(s_x + (current_room.width * s_y) + 1) = 63;
				}
			}
			break;
		};
		default: {}
		}
	}
}

class after_effect {
public:
	bn::sprite_ptr me = bn::sprite_items::underground_tiles.create_sprite(0, 0, 4);
	bool done = false;

	after_effect() {
		done = false;
	}

	void update() {
		if ((me.horizontal_scale() - 0.05) > 0) {
			me.set_scale(me.horizontal_scale() - 0.05, me.vertical_scale() - 0.05);
			me.put_below();
		}
		else {
			done = true;
		}
	}
};

dungeon_return rufus_dungeon(dungeon_return& dt)
{
	bn::vector<after_effect, 2> aes;

	if (dt.world_index == 2)
	{
		line lc[32] = {
			{true, true, 0, "S07:01"},
			{true, true, 0, "BG: fadeout"},
			{true, true, 00, "MAPLE                            So come clean with me, oui?      Did you make this place?"},
			{true, true, 00, "SCOUT                            Heck no! I kind of wish I did,   though."},
			{true, true, 00, "S07:02"},
			{true, true, 00, "..."},
			{true, true, 00, "S07:03"},
			{true, true, 00, "SCOUT                            MAPLE LOOK OUT!"},
			{true, true, 00, "S07:04"},
			{true, true, 00, "MAPLE                            ...Scout, are you alright?"},
			{true, true, 00, "RUFUS                            Ow. At least it helped pop my    back."},
			{true, true, 00, "S07:05"},
			{true, true, 00, "MAPLE                            What's with all the gasoline in  this place, huh?"},
			{true, true, 00, "SCOUT                            Maybe be a little extra careful  with that fire power of yours in this next part, huh?"},
			{true, true, 0, "COM: Endscene"} };
		dialogue_page(lc);

		bn::music_items_info::span[29].first.play(0.8);
	}

	if (!bn::music::playing())
	{
		bn::music_items_info::span[29].first.play(0.8);
	}

	// Constants
	room current_room(0, 0, 0, 0);

	// If different than default, reset
	if (dt.spawn_x > 0 && dt.spawn_y > 0)
	{
		current_room.start_x = dt.spawn_x;
		current_room.start_y = dt.spawn_y;
	}

	// current_room.camera setup
	short int sx = current_room.start_x * 32;
	short int sy = current_room.start_y * 32;

	if (dt.world_index == 0)
	{
		character maple(bn::sprite_items::maple_walking_oo, current_room.start_x, current_room.start_y, false, current_room.width);
		maple.entity.set_camera(current_room.camera);
		maple.entity.set_position(sx, sy);
		maple.role = 0;
		maple.identity = 0;
		maple.follow_id = 5;
		current_room.chari.push_back(maple);

		character scout(bn::sprite_items::scout_walking_spring, current_room.start_x, current_room.start_y, false, current_room.width);
		scout.entity.set_camera(current_room.camera);
		scout.entity.set_position(sx, sy);
		scout.role = 0;
		scout.identity = 3;
		scout.follow_id = 0;
		current_room.chari.push_back(scout);

		character enoki(bn::sprite_items::enoki_walking_oo, current_room.start_x, current_room.start_y, false, current_room.width);
		enoki.entity.set_camera(current_room.camera);
		enoki.entity.set_position(sx, sy);
		enoki.role = 0;
		enoki.identity = 1;
		enoki.follow_id = 1;
		current_room.chari.push_back(enoki);

		character aaron(bn::sprite_items::aaron_walking_oo, current_room.start_x, current_room.start_y, false, current_room.width);
		aaron.entity.set_camera(current_room.camera);
		aaron.entity.set_position(sx, sy);
		aaron.role = 0;
		aaron.identity = 2;
		aaron.follow_id = 2;
		current_room.chari.push_back(aaron);

		character vee(bn::sprite_items::vee_walking_spring, current_room.start_x, current_room.start_y, false, current_room.width);
		vee.entity.set_camera(current_room.camera);
		vee.entity.set_position(sx, sy);
		vee.role = 0;
		vee.identity = 4;
		vee.follow_id = 3;
		current_room.chari.push_back(vee);

		character eleanor(bn::sprite_items::eleanor_walking_spring, current_room.start_x, current_room.start_y, false, current_room.width);
		eleanor.entity.set_camera(current_room.camera);
		eleanor.entity.set_position(sx, sy);
		eleanor.role = 0;
		eleanor.identity = 5;
		eleanor.follow_id = 4;
		current_room.chari.push_back(eleanor);
	}
	else
	{
		character maple(bn::sprite_items::maple_walking_oo, current_room.start_x, current_room.start_y, false, current_room.width);
		maple.entity.set_camera(current_room.camera);
		maple.entity.set_position(sx, sy);
		maple.role = 0;
		maple.identity = 0;
		maple.follow_id = 1;
		current_room.chari.push_back(maple);

		character scout(bn::sprite_items::scout_walking_spring, current_room.start_x, current_room.start_y, false, current_room.width);
		scout.entity.set_camera(current_room.camera);
		scout.entity.set_position(sx, sy);
		scout.role = 0;
		scout.identity = 3;
		scout.follow_id = 0;
		current_room.chari.push_back(scout);
	}

	current_room.environment = &bn::sprite_items::underground_tiles;

	// Handle active character
	current_room.chari.at(0).role = 1;
	current_room.follow_id = 0;
	globals->current_save->last_char_id = current_room.chari.at(0).identity;

	// World generation
	switch (dt.world_index)
	{
	case 0:
	{
		// exit door - 4
		// exit message - 3
		// init - 6
		// gas talk - 5

		current_room.configure(26, 12, 1, 9);
		const short int local_col[current_room.width * current_room.height] = {
			0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,
			0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,4,1,1,
			0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,0,0,1,1,0,0,1,1,
			0,0,1,1,0,0,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,3,3,1,1,
			0,0,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,
			0,0,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,
			0,0,1,1,0,1,5,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,
			1,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1,1,
			1,1,1,1,1,1,1,1,0,1,1,1,0,1,0,0,1,1,0,0,0,1,0,0,1,1,
			1,0,6,1,0,1,0,1,0,1,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1,1,
			1,0,6,1,1,1,0,1,0,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,1,1,
			1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
		const short int local[current_room.width * current_room.height] = {
			0,0,0,0,0,0,12,1,1,1,1,1,1,1,1,1,1,12,0,0,12,1,1,9,1,12,
			0,0,12,12,12,12,12,1,0,0,0,0,0,0,0,0,1,12,0,0,12,1,4,0,1,12,
			0,0,12,1,1,1,1,1,0,1,1,1,1,1,1,0,1,12,0,0,12,1,0,0,1,12,
			0,0,0,1,0,0,0,1,0,1,12,12,12,12,1,0,1,12,12,12,12,10,0,0,1,12,
			0,0,0,1,0,0,0,1,16,1,1,1,1,1,1,5,1,1,1,1,1,11,0,0,1,12,
			0,0,0,1,0,0,0,1,5,5,5,5,5,1,1,5,1,5,5,5,1,10,12,0,1,12,
			0,0,0,1,0,5,0,1,0,0,0,5,5,5,1,5,1,5,5,5,1,1,0,0,1,12,
			0,0,0,1,0,5,0,1,0,1,1,1,5,5,1,5,1,1,5,5,0,1,0,0,1,12,
			1,1,1,1,16,1,16,1,0,1,12,1,0,16,0,0,1,1,0,0,0,1,0,0,10,12,
			0,0,0,5,0,1,0,5,0,1,12,1,0,0,1,1,1,1,0,0,0,16,0,0,1,12,
			0,0,0,5,1,1,0,5,0,1,12,1,12,0,0,0,0,0,0,0,0,16,0,12,1,12,
			1,1,1,1,1,1,1,1,1,1,12,1,1,1,1,1,1,1,1,1,1,1,1,1,1,12 };

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++) {
			globals->local_tileset.push_back(local[t]);
			globals->collisions.push_back(local_col[t]);
		}

		current_room.primary_bg.set_camera(current_room.camera);
		break;
	}
	case 1:
	{
		current_room.configure(18, 21, 16, 19);
		const short int local_col[current_room.width * current_room.height] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 1,
			1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1,
			1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1,
			1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
			1, 9, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1,
			1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1,
			1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1,
			1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
			1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1,
			1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1,
			1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1,
			1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1,
			1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1,
			1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
			1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1,
			1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1,
			1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		const short int local[current_room.width * current_room.height] = {
			1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,1,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
			1,0,12,1,12,0,0,0,0,0,0,0,0,12,1,12,1,1,
			1,0,12,0,12,0,0,0,0,0,0,0,0,12,0,12,0,1,
			1,15,1,1,1,0,0,0,0,0,0,0,0,1,12,1,0,1,
			1,0,1,13,1,1,6,7,8,6,7,8,6,6,7,8,0,11,
			1,0,1,14,0,0,15,5,0,0,0,1,12,0,0,16,0,10,
			1,0,1,1,1,0,1,16,0,16,0,1,0,0,0,16,0,11,
			1,0,1,5,1,0,1,0,0,0,0,1,0,0,0,16,0,10,
			1,0,1,0,5,0,1,1,5,1,1,1,16,16,16,10,0,11,
			1,0,1,0,0,5,12,1,5,0,1,0,0,0,0,11,0,10,
			1,0,1,0,5,0,1,1,14,0,1,0,0,0,0,10,15,11,
			1,15,1,1,1,15,1,1,5,5,15,0,14,0,0,11,0,10,
			1,0,0,0,0,0,10,12,1,1,1,1,0,0,0,10,13,11,
			1,0,0,16,10,0,11,0,1,0,0,1,12,0,0,11,0,10,
			1,0,0,0,11,0,10,0,0,0,16,1,1,1,1,1,0,11,
			1,0,0,0,10,2,11,0,0,0,0,0,0,0,0,1,0,10,
			1,0,0,0,11,0,10,12,0,0,0,0,0,12,0,1,0,11,
			1,14,0,0,0,0,10,12,0,12,12,12,0,12,0,1,0,1,
			1,0,0,0,16,0,16,0,0,0,0,0,0,0,5,1,0,1,
			1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 };

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++) {
			globals->local_tileset.push_back(local[t]);
			globals->collisions.push_back(local_col[t]);
		}

		current_room.primary_bg.set_camera(current_room.camera);
		break;
	}
	case 2:
	{
		// 9 - exit door
		// 

		current_room.configure(19, 19, 14, 17);
		const short int local_col[current_room.width * current_room.height] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1,
			1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1,
			1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1,
			1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
			1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1,
			1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
			1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1,
			1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1,
			1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 };
		const short int local[current_room.width * current_room.height] = {
			10, 9, 10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 14, 12, 0, 0, 12, 0, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 12, 16, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 15, 0, 0, 0, 0, 0, 16, 1,
			1, 0, 0, 0, 0, 1, 2, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 14, 1,
			1, 12, 0, 0, 0, 1, 0, 0, 0, 14, 0, 1, 15, 0, 0, 0, 0, 5, 1,
			1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 1,
			1, 16, 0, 0, 0, 1, 12, 0, 16, 0, 0, 15, 0, 0, 0, 0, 0, 12, 1,
			1, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0, 0, 12, 12, 0, 0, 0, 1,
			1, 5, 6, 5, 10, 7, 8, 6, 6, 6, 6, 7, 8, 6, 6, 6, 7, 8, 11,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 10,
			1, 15, 1, 1, 10, 0, 0, 0, 12, 0, 12, 0, 12, 0, 0, 0, 0, 0, 10,
			1, 0, 0, 0, 10, 0, 0, 0, 0, 12, 0, 12, 0, 12, 0, 0, 0, 0, 10,
			1, 14, 0, 0, 10, 0, 0, 0, 12, 0, 12, 0, 12, 0, 0, 0, 0, 0, 10,
			1, 0, 0, 0, 10, 13, 0, 0, 0, 12, 0, 12, 0, 12, 0, 0, 0, 0, 10,
			1, 0, 0, 0, 10, 16, 0, 0, 12, 0, 12, 0, 12, 0, 0, 0, 0, 0, 10,
			1, 5, 5, 5, 10, 0, 0, 0, 0, 12, 0, 12, 0, 12, 0, 0, 0, 0, 10,
			1, 5, 5, 5, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
			1, 6, 6, 6, 10, 6, 8, 6, 6, 6, 6, 7, 8, 6, 0, 6, 7, 8, 11 };

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++) {
			globals->local_tileset.push_back(local[t]);
			globals->collisions.push_back(local_col[t]);
		}

		current_room.primary_bg.set_camera(current_room.camera);
		break;
	}
	case 3:
	{
		current_room.configure(6, 64, 3, 62);
		const short int local[current_room.width * current_room.height] = {
			10, 9, 9, 10, 0, 0,
			1, 10, 10, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 1, 1,
			1, 0, 0, 0, 12, 1,
			1, 12, 0, 0, 0, 1,
			1, 1, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 1, 1, 0, 0, 1,
			0, 1, 12, 0, 0, 1,
			0, 1, 0, 0, 0, 1,
			0, 1, 0, 0, 0, 1,
			0, 1, 1, 0, 1, 1 };
		const short int local_col[current_room.width * current_room.height] = {
			1, 1, 1, 1, 0, 0,
			1, 10, 10, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 0, 0,
			1, 0, 0, 1, 1, 1,
			1, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 1,
			1, 1, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 0, 1, 0, 0, 1,
			0, 1, 1, 0, 0, 1,
			0, 1, 1, 0, 0, 1,
			0, 1, 0, 0, 0, 1,
			0, 1, 0, 0, 0, 1,
			0, 1, 1, 0, 1, 1 };

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++) {
			globals->local_tileset.push_back(local[t]);
			globals->collisions.push_back(local_col[t]);
		}

		current_room.primary_bg.set_camera(current_room.camera);
		break;
	}
	default:
	{
		break;
	}
	};

	// set up levels
	bn::vector<moving_block, 16> blocks;
	bn::vector<gem, 4> gems;
	bn::vector<xy, 64> gas_tanks;
	bn::vector<button, 12> buttons;
	bn::vector<gate, 12> gates;

	// Set up special items
	for (int y = 0; y < current_room.height; y++)
	{
		for (int x = 0; x < current_room.width; x++)
		{
			short int absloc = x + (y * current_room.width);

			if (globals->local_tileset.at(absloc) == 2)
			{
				gem gemy;
				gemy.entity.set_camera(current_room.camera);
				gemy.entity.set_position(x * 32, y * 32);
				gems.push_back(gemy);
			}
			else if (globals->local_tileset.at(absloc) == 12)
			{
				xy gassy;
				gassy.x = x;
				gassy.y = y;
				globals->collisions.at(x + (y * current_room.width)) = 1;
				gas_tanks.push_back(gassy);
			}
			else if (globals->local_tileset.at(absloc) == 13)
			{
				button buttony;
				buttony.x = x;
				buttony.y = y;
				buttons.push_back(buttony);
			}
			else if (globals->local_tileset.at(absloc) == 14)
			{
				button buttony;
				buttony.x = x;
				buttony.y = y;
				buttony.short_toggle = true;
				buttons.push_back(buttony);
				globals->local_tileset.at(absloc) = 13;
			}
			else if (globals->local_tileset.at(absloc) == 15)
			{
				gate gatey;
				gatey.x = x;
				gatey.y = y;
				globals->collisions.at(x + (y * current_room.width)) = 1;
				gates.push_back(gatey);
			}
			else if (globals->local_tileset.at(absloc) == 16)
			{
				moving_block pushy;
				pushy.entity.set_camera(current_room.camera);
				pushy.entity.set_position(x * 32, y * 32);
				globals->collisions.at(absloc) = 1;
				globals->local_tileset.at(absloc) = 0;
				blocks.push_back(pushy);
			}
		}
	}

	// Configure doors and latches
	if (dt.world_index == 1)
	{
		gates.at(0).triggered_by = 0;
		gates.at(1).triggered_by = 2;
		gates.at(2).triggered_by = 4;
		gates.at(3).triggered_by = 5;
		gates.at(4).triggered_by = 1;
		gates.at(5).triggered_by = 3;
	}
	else if (dt.world_index == 2)
	{
		gates.at(0).triggered_by = 0;
		gates.at(1).triggered_by = 2;
		gates.at(2).triggered_by = 1;
		gates.at(3).triggered_by = 3;
		gates.at(4).triggered_by = 4;
	}

	// GAMELOOP
	short int last_x = dt.spawn_x;
	short int last_y = dt.spawn_y;

	globals->rendered_windows.clear();
	{
		bn::rect_window external_window = bn::rect_window::external();
		external_window.set_show_bg(current_room.primary_bg, false);
		external_window.set_show_sprites(false);
		external_window.set_boundaries(-80, -120, 80, 120);
		globals->rendered_windows.push_back(external_window);

		bn::rect_window internal_window = bn::rect_window::internal();
		internal_window.set_show_bg(current_room.primary_bg, true);
		internal_window.set_show_sprites(true);
		internal_window.set_camera(current_room.camera);
		globals->rendered_windows.push_back(internal_window);
	}

	short int window_y = 80;
	current_room.init_render();
	while (true)
	{
		// Control window
		globals->rendered_windows.at(0).set_boundaries(-80, -120, window_y, 120);
		if (window_y > -80)
			window_y -= 10;

		// the fancy effect
		for (int t = 0; t < aes.size(); t++) {
			aes.at(t).update();
			if (aes.at(t).done) {
				aes.clear();
				break;
			}
		}

		// set current_room.camera follow point
		current_room.follow_x = current_room.chari.at(current_room.follow_id).entity.x().integer();
		current_room.follow_y = current_room.chari.at(current_room.follow_id).entity.y().integer();

		// manage a notif
		current_room.a_notif.set_visible(false);
		current_room.a_notif.set_position(current_room.follow_x, current_room.follow_y - 28);

		// deal with stuff
		char rel_x = (current_room.follow_x + 16) / 32;
		char rel_y = (current_room.follow_y + 16) / 32;

		if (current_room.chari.at(current_room.follow_id).identity == 3)
		{
			if (globals->local_tileset.at(rel_x + ((rel_y + 1) * current_room.width)) == 5 && current_room.chari.at(current_room.follow_id).dir == 0)
			{
				current_room.start_notif(0);
				if (bn::keypad::a_pressed())
				{
					bn::sound_items::firecrackle.play();
					globals->local_tileset.at(rel_x + ((rel_y + 1) * current_room.width)) = 0;
					globals->collisions.at(rel_x + ((rel_y + 1) * current_room.width)) = 0;
					current_room.refresh_tiles(current_room.camera.x() / 32, current_room.camera.y() / 32);

					after_effect ae;
					ae.me.set_position(rel_x * 32, (rel_y + 1) * 32);
					ae.me.set_camera(current_room.camera);
					aes.push_back(ae);
				}
			}
			if (globals->local_tileset.at(rel_x + ((rel_y - 1) * current_room.width)) == 5 && current_room.chari.at(current_room.follow_id).dir == 3)
			{
				current_room.start_notif(0);
				if (bn::keypad::a_pressed())
				{
					bn::sound_items::firecrackle.play();
					globals->local_tileset.at(rel_x + ((rel_y - 1) * current_room.width)) = 0;
					globals->collisions.at(rel_x + ((rel_y - 1) * current_room.width)) = 0;
					current_room.refresh_tiles(current_room.camera.x() / 32, current_room.camera.y() / 32);

					after_effect ae;
					ae.me.set_position(rel_x * 32, (rel_y - 1) * 32);
					ae.me.set_camera(current_room.camera);
					aes.push_back(ae);
				}
			}
			if (globals->local_tileset.at(rel_x + 1 + ((rel_y)*current_room.width)) == 5 && current_room.chari.at(current_room.follow_id).dir == 1)
			{
				current_room.start_notif(0);
				if (bn::keypad::a_pressed())
				{
					bn::sound_items::firecrackle.play();
					globals->local_tileset.at(rel_x + 1 + ((rel_y)*current_room.width)) = 0;
					globals->collisions.at(rel_x + 1 + ((rel_y)*current_room.width)) = 0;
					current_room.refresh_tiles(current_room.camera.x() / 32, current_room.camera.y() / 32);

					after_effect ae;
					ae.me.set_position((rel_x + 1) * 32, rel_y * 32);
					ae.me.set_camera(current_room.camera);
					aes.push_back(ae);
				}
			}
			if (globals->local_tileset.at(rel_x - 1 + ((rel_y)*current_room.width)) == 5 && current_room.chari.at(current_room.follow_id).dir == 2)
			{
				current_room.start_notif(0);
				if (bn::keypad::a_pressed())
				{
					bn::sound_items::firecrackle.play();
					globals->local_tileset.at(rel_x - 1 + ((rel_y)*current_room.width)) = 0;
					globals->collisions.at(rel_x - 1 + ((rel_y)*current_room.width)) = 0;
					current_room.refresh_tiles(current_room.camera.x() / 32, current_room.camera.y() / 32);

					after_effect ae;
					ae.me.set_position((rel_x - 1) * 32, rel_y * 32);
					ae.me.set_camera(current_room.camera);
					aes.push_back(ae);
				}
			}
		}

		// Update projectiles
		for (short int t = 0; t < current_room.p.size(); t++)
		{
			short int f_x = (current_room.p.at(t).fireball.x().integer() + 16) / 32;
			short int f_y = (current_room.p.at(t).fireball.y().integer() + 16) / 32;
			short int f_z = f_x + (f_y * current_room.width);

			if (current_room.p.at(t).fireball.visible()) {
				for (int i = 0; i < buttons.size(); i++)
				{
					if (buttons.at(i).x == f_x && buttons.at(i).y == f_y && !buttons.at(i).short_toggle)
					{
						if (!buttons.at(t).toggled)
						{
							bn::sound_items::pop.play();
							buttons.at(t).toggled = true;
							globals->local_tileset.at(f_z) = 14;
							current_room.last_camera_x = 0;
							current_room.last_camera_y = 0;
							current_room.p.at(t).fireball.set_visible(false);
							current_room.refresh_tiles(current_room.camera.x() / 32, current_room.camera.y() / 32);
						}
					}
				}

				for (int i = 0; i < gas_tanks.size(); i++)
				{
					if (gas_tanks.at(i).x == f_x && gas_tanks.at(i).y == f_y)
					{
						dt.spawn_x = last_x;
						dt.spawn_y = last_y;

						// death explosion
						for (int n = 0; n < current_room.chari.size(); n++)
						{
							current_room.chari.at(n).entity.set_visible(false);
						}
						current_room.primary_bg = bn::regular_bg_items::bg_explosion.create_bg(0, 0);
						bn::sound_items::boom.play();
						bn::music::stop();

						for (int n = 0; n < 64; n++)
						{
							bn::core::update();
						}

						return dt;
					}
				}

			}

		}

		// Control actions
		unsigned short int follow_z = ((current_room.follow_x + 16) / 32) + (((current_room.follow_y + 16) / 32) * current_room.width);

		unsigned short int possible_action = globals->collisions.at(follow_z);
		if (possible_action > 1)
		{
			current_room.start_notif(0);

			if (bn::keypad::a_pressed())
			{

				// Start action
				current_room.a_notif.set_visible(false);
				bn::core::update();
				switch (possible_action)
				{
				case 2:
				{
					line lc[10] = {
						{true, true, 00, "MAPLE                            Qu.."},
						{true, true, 00, "MAPLE                            Quoi?"},
						{true, true, 00, "SCOUT                            Je devrais recalibrer mon outil.."},
						{true, true, 00, "MAPLE                            Repare le! Je veux pas mourir!"},
						{true, true, 00, "COM: Endscene"} };
					dialogue_page_lite(lc);
					break;
				};
				case 3:
				{
					line lc[32] = {
						{true, true, 00, "ELEANOR                          Vee, c'est quoi ca?"},
						{true, true, 00, "OLIVIER                          Je ne sais pas..."},
						{true, true, 00, "SCOUT                            Je vais avancer et verifier."},
						{true, true, 00, "MAPLE                            Pas tous seul. Je viens avec toi."},
						{true, true, 00, "AARON                            Soyez prudent."},
						{true, true, 00, "MAPLE                            Eh, we'll be fine."},
						{true, true, 00, "COM: Endscene"} };
					dialogue_page_lite(lc);
					break;
				};
				case 4:
				{
					dt.spawn_x = 16;
					dt.spawn_y = 19;
					dt.world_index = 1;
					return dt;
				};
				case 5:
				{
					line lc[10] = {
						{true, true, 00, "OLIVIER                          C'es tu de la gasoline?"},
						{true, true, 00, "SCOUT                            Je, crois que.."},
						{true, true, 00, "AARON                            Crois que?"},
						{true, true, 00, "SCOUT                            Que quelqu'un.."},
						{true, true, 00, "SCOUT                            Est passe par ici."},
						{true, true, 00, "MAPLE                            Oh, ca sense pas bon."},
						{true, true, 00, "COM: Endscene"} };
					dialogue_page_lite(lc);
					break;
				};
				case 6:
				{
					if (current_room.chari.at(current_room.follow_id).identity != 3) {
						line lc[10] = {
							{true, true, 00, "SCOUT                            He- je peux gerer ca."},
							{true, true, 00, "COM: Endscene"} };
						dialogue_page_lite(lc);
					}
					break;
				};
				case 7:
				{
					dt.spawn_x = 14;
					dt.spawn_y = 17;
					dt.world_index = 2;
					return dt;
					break;
				};
				case 8:
				{
					dt.spawn_x = 3;
					dt.spawn_y = 62;
					dt.world_index = 3;
					return dt;
					break;
				};
				case 9:
				{
					line lc[10] = {
						{true, true, 00, "Je me demande si le feu pourrait aider..."},
						{true, true, 00, "COM: Endscene"} };
					dialogue_page_lite(lc);
					break;
				};
				case 10:
				{
					dt.spawn_x = 0;
					dt.spawn_y = 0;
					dt.world_index = 99;
					return dt;
					break;
				};
				default: {};
				}
			}
		}

		// manage objects
		for (unsigned short int t = 0; t < blocks.size(); t++)
		{
			blocks.at(t).entity.put_above();
			short int my_x = blocks.at(t).entity.x().integer() / 32;
			short int my_y = blocks.at(t).entity.y().integer() / 32;
			short int my_z = my_x + (my_y * current_room.width);

			if (blocks.at(t).moving_y < 0)
			{
				my_z += current_room.width;
			}

			if (blocks.at(t).moving_x < 0)
			{
				my_z++;
			}

			// Push block
			if (rel_x == my_x)
			{
				if (rel_y == my_y + 1 && globals->collisions.at(my_z - current_room.width) != 1 && current_room.chari.at(current_room.follow_id).dir == 3)
				{
					current_room.start_notif(0);
					if (bn::keypad::a_pressed())
					{
						blocks.at(t).moving_y = -2;
						globals->collisions.at(my_z) = 0;
					}
				}
				else if (rel_y == my_y - 1 && globals->collisions.at(my_z + current_room.width) != 1 && current_room.chari.at(current_room.follow_id).dir == 0)
				{
					current_room.start_notif(0);
					if (bn::keypad::a_pressed())
					{
						blocks.at(t).moving_y = 2;
						globals->collisions.at(my_z) = 0;
					}
				}
			}
			else if (rel_y == my_y)
			{
				if (rel_x == my_x + 1 && globals->collisions.at(my_z - 1) != 1 && current_room.chari.at(current_room.follow_id).dir == 2)
				{
					current_room.start_notif(0);
					if (bn::keypad::a_pressed())
					{
						blocks.at(t).moving_x = -2;
						globals->collisions.at(my_z) = 0;
					}
				}
				else if (rel_x == my_x - 1 && globals->collisions.at(my_z + 1) != 1 && current_room.chari.at(current_room.follow_id).dir == 1)
				{
					current_room.start_notif(0);
					if (bn::keypad::a_pressed())
					{
						blocks.at(t).moving_x = 2;
						globals->collisions.at(my_z) = 0;
					}
				}
			}

			// End movement
			if (blocks.at(t).moving_x != 0)
			{
				if (
					globals->collisions.at(
						my_z + (blocks.at(t).moving_x / 2)) == 1)
				{
					bn::sound_items::firehit.play();
					if (blocks.at(t).moving_x < 0)
						my_x++;
					blocks.at(t).moving_x = 0;
					globals->collisions.at(my_z) = 1;

					blocks.at(t).entity.set_position(my_x * 32, my_y * 32);
				}
				else
				{
					blocks.at(t).entity.set_x(blocks.at(t).entity.x().integer() + blocks.at(t).moving_x);
				}
			}
			if (blocks.at(t).moving_y != 0)
			{
				if (
					globals->collisions.at(
						my_z + ((blocks.at(t).moving_y / 2) * current_room.width)) == 1)
				{
					bn::sound_items::firehit.play();
					if (blocks.at(t).moving_y < 0)
						my_y++;
					blocks.at(t).moving_y = 0;
					globals->collisions.at(my_z) = 1;

					blocks.at(t).entity.set_position(my_x * 32, my_y * 32);
				}
				else
				{
					blocks.at(t).entity.set_y(blocks.at(t).entity.y().integer() + blocks.at(t).moving_y);
				}
			}
		}

		// Gems
		for (unsigned short int t = 0; t < gems.size(); t++)
		{
			if (gems.at(t).entity.visible())
			{
				gems.at(t).entity.put_above();
				unsigned short int my_x = gems.at(t).entity.x().integer() / 32;
				unsigned short int my_y = gems.at(t).entity.y().integer() / 32;

				if (my_x == rel_x && my_y == rel_y)
				{
					short int my_z = my_x + (my_y * current_room.width);
					bn::sound_items::ding.play();
					globals->local_tileset.at(my_z) = 0;
					gems.at(t).entity.set_visible(false);
					last_x = my_x;
					last_y = my_y;
					current_room.refresh_tiles(current_room.camera.x() / 32, current_room.camera.y() / 32);
					current_room.refresh_tiles(current_room.camera.x() / 32, current_room.camera.y() / 32);
				}
			}
		}

		// Switches and buttons
		for (unsigned short int t = 0; t < buttons.size(); t++)
		{
			unsigned short int my_x = buttons.at(t).x;
			unsigned short int my_y = buttons.at(t).y;
			unsigned short int my_z = my_x + (my_y * current_room.width);

			if ((my_x == rel_x && my_y == rel_y) || globals->collisions.at(my_z) == 1)
			{
				if (!buttons.at(t).toggled)
				{
					bn::sound_items::pop.play();
					buttons.at(t).toggled = true;
					globals->local_tileset.at(my_z) = 14;
				}
			}
			else if (buttons.at(t).short_toggle)
			{
				if (buttons.at(t).toggled)
				{
					bn::sound_items::pop.play();
					buttons.at(t).toggled = false;
					globals->local_tileset.at(my_z) = 13;
				}
			}
		}
		for (unsigned short int t = 0; t < gates.size(); t++)
		{
			button* bt = &buttons.at(gates.at(t).triggered_by);
			if (globals->local_tileset.at(bt->x + (bt->y * current_room.width)) == 14)
			{
				globals->local_tileset.at(gates.at(t).x + (gates.at(t).y * current_room.width)) = 0;
				globals->collisions.at(gates.at(t).x + (gates.at(t).y * current_room.width)) = 0;
			}
			else
			{
				globals->local_tileset.at(gates.at(t).x + (gates.at(t).y * current_room.width)) = 15;
				globals->collisions.at(gates.at(t).x + (gates.at(t).y * current_room.width)) = 1;
			}
		}

		// things
		if (globals->local_tileset.at(rel_x + (rel_y * current_room.width)) == 4)
		{
			globals->local_tileset.at(rel_x + (rel_y * current_room.width)) = 0;
		}

		current_room.update_objects();
		bn::core::update();
	}
}

void keyboard() {
	bn::core::update();

	bn::string<16> string;
	bn::ostringstream ss(string);
	bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
	bn::vector<bn::sprite_ptr, 16> file1_spr;
	auto velvet = bn::regular_bg_items::velvet.create_bg(0, 0);
	auto ui = bn::regular_bg_items::keyboard_bg.create_bg(0, 0);
	auto sel = bn::sprite_items::selection.create_sprite(-100, -18);
	char basis[96] = "abcdefghijklmnopqrstuvwxyz     -'&  ABCDEFGHIJKLMNOPQRSTUVWXYZ     -'&  ";
	auto x_state = 0, y_state = 0, t = 0, height = -64;
	auto lower = true;
	ui.set_y(64);

	while (!bn::keypad::start_pressed()) {

		if (bn::keypad::left_pressed()) {
			if (((basis[x_state - 1 + (y_state * 12)] != ' ') || (y_state == 2)) && !(x_state == 7 && y_state == 2)) {
				x_state--;
				if (x_state < 0) x_state = 11;
				sel.set_x(-100 + 18 * x_state);
			}
		}
		else if (bn::keypad::right_pressed()) {
			if ((basis[x_state + 1 + (y_state * 12)] != ' ') || (x_state > 8)) {
				x_state++;
				x_state = x_state % 12;
				sel.set_x(-100 + 18 * x_state);
			}
		}
		if (bn::keypad::up_pressed()) {
			if (!(x_state > 1 && x_state < 7 && y_state == 0) || (x_state > 8)) {
				y_state--;
				if (y_state < 0) y_state = 2;
				sel.set_y(-18 + 26 * y_state);
			}
		}
		else if (bn::keypad::down_pressed()) {
			if ((basis[x_state + ((y_state + 1) * 12)] != ' ') || (x_state > 8)) {
				y_state++;
				y_state = y_state % 3;
				sel.set_y(-18 + 26 * y_state);
			}
		}

		if (bn::keypad::a_pressed()) {
			if (ss.size() < 16) {
				bn::sound_items::pop.play();
				file1_spr.clear();
				unsigned short int plus = 0;
				if (!lower) plus = 36;
				ss << (basis[x_state + plus + (y_state * 12)]);
				file1_gen.generate(-104, height, ss.str().c_str(), file1_spr);
			}
			else {
				bn::sound_items::firehit.play();
			}
		}

		if (bn::keypad::b_pressed()) {
			if (ss.size() > 0) {
				string.pop_back();
				file1_spr.clear();
				file1_gen.generate(-104, height, string.c_str(), file1_spr);
				bn::sound_items::cnaut.play();
			}
			else {
				bn::sound_items::firehit.play();
			}
		}

		if (bn::keypad::select_pressed()) {
			bn::sound_items::fireblast.play();
			file1_spr.clear();
			lower = !lower;
			height = height * -1;
			if (!lower) {
				while (ui.y().integer() != 192) { //192, 204
					short int y = ui.y().integer() + 4;
					y = y % 256;
					ui.set_y(y);
					bn::core::update();
				}
			}
			else {
				while (ui.y().integer() != 64) {
					short int y = ui.y().integer() + 4;
					y = y % 256;
					ui.set_y(y);
					bn::core::update();
				}
			}
			file1_gen.generate(-104, height, string.c_str(), file1_spr);
			bn::sound_items::firehit.play();
		}

		// Scrolling background
		t = (t + 1) % 256;
		velvet.set_position(t, t);
		bn::core::update();
	}

	for (int tt = 0; tt < ss.size(); tt++) globals->current_save->island_name[tt] = string.at(tt);
}

void timer(int delay)
{
	for (short int t = 0; t < delay; t++)
	{
		bn::core::update();
	}
}

void intros(int t) {

	flash_write();

	bn::fixed_t<12> glow = 1;

	auto header = bn::regular_bg_items::cinemint_studios.create_bg(0, 0);
	auto a_button = bn::sprite_items::a_button.create_sprite(-90, -50);
	int intro_stage = 0;

	a_button.set_visible(false);

	switch (t) {
	case 0: {
		header = bn::regular_bg_items::tc_intro.create_bg(0, 0);
		break;
	}
	case 1: {
		header = bn::regular_bg_items::tc_1.create_bg(0, 0);
		break;
	}
	case 2: {
		header = bn::regular_bg_items::tc_2.create_bg(0, 0);
		break;
	}
	case 3: {
		header = bn::regular_bg_items::tc_3.create_bg(0, 0);
		break;
	}
	case 4: {
		header = bn::regular_bg_items::tc_4.create_bg(0, 0);
		break;
	}
	case 5: {
		header = bn::regular_bg_items::tc_5.create_bg(0, 0);
		break;
	}
	default: {}
	}

	header.set_mosaic_enabled(true);

	while (!bn::keypad::a_pressed()) {
		if (intro_stage == 0) {
			if (glow - 0.02 > 0)
			{
				glow -= 0.02;
				bn::bgs_mosaic::set_horizontal_stretch(glow);
				bn::bgs_mosaic::set_vertical_stretch(glow);
			}
			else
			{
				a_button.set_visible(true);
				header.set_mosaic_enabled(false);
				intro_stage++;
			}
		}

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
	bn::fixed_t<12> glow = 0.5;
	short int intro_stage = 0;
	short int height = -24;
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
			bn::music_items_info::span[3].first.play(0.8);
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

	bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
	bn::vector<bn::sprite_ptr, 12> file1_spr;
	bn::string<32> buf1;

	// Clear if need be
	if (globals->all_save.save_init != 99) {
		flash_reset();
		for (int t = 0; t < 3; t++) {
			globals->all_save.current_save[t].clear();
		}
		globals->all_save.save_init = 99;
	}

	if (DEVICE_TYPE == 0) {
		auto ui = bn::regular_bg_items::file_select_bg.create_bg(0, 0);
		auto arrow = bn::sprite_items::arrow.create_sprite(-98, -32);

		bn::sprite_text_generator file2_gen(common::variable_8x16_sprite_font);
		bn::sprite_text_generator file3_gen(common::variable_8x16_sprite_font);
		bn::vector<bn::sprite_ptr, 12> file2_spr;
		bn::vector<bn::sprite_ptr, 12> file3_spr;

		bn::string<32> buf2;
		bn::string<32> buf3;

		if (globals->all_save.current_save[0].island_name[0] < 123 && globals->all_save.current_save[0].island_name[0] > 0) {
			bn::ostringstream ss1(buf1);
			for (short int t = 0; t < 16; t++) {
				if (globals->all_save.current_save[0].island_name[t] > 31 && globals->all_save.current_save[0].island_name[t] < 123) {
					BN_LOG((int)globals->all_save.current_save[0].island_name[t]);
					ss1 << globals->all_save.current_save[0].island_name[t];
				}
			}
			if (globals->all_save.current_save[0].xp == -1) globals->all_save.current_save[0].xp = 0;
			ss1 << ": ";
			ss1 << (int)(globals->all_save.current_save[0].checkpoint * 6.6);
			ss1 << "%";
		}
		else {
			buf1 = "Slot 1: 0%";
		}

		if (globals->all_save.current_save[1].island_name[0] < 123 && globals->all_save.current_save[1].island_name[0] > 0) {
			bn::ostringstream ss1(buf2);
			for (short int t = 0; t < 16; t++) {
				if (globals->all_save.current_save[1].island_name[t] > 31 && globals->all_save.current_save[1].island_name[t] < 123) {
					BN_LOG((int)globals->all_save.current_save[1].island_name[t]);
					ss1 << globals->all_save.current_save[1].island_name[t];
				}
			}
			if (globals->all_save.current_save[1].xp == -1) globals->all_save.current_save[1].xp = 0;
			ss1 << ": ";
			ss1 << (int)(globals->all_save.current_save[1].checkpoint * 6.6);
			ss1 << "%";
		}
		else {
			buf2 = "Slot 2: 0%";
		}

		if (globals->all_save.current_save[2].island_name[0] < 123 && globals->all_save.current_save[2].island_name[0] > 0) {
			bn::ostringstream ss1(buf3);
			for (short int t = 0; t < 16; t++) {
				if (globals->all_save.current_save[2].island_name[t] > 31 && globals->all_save.current_save[2].island_name[t] < 123) {
					BN_LOG((int)globals->all_save.current_save[2].island_name[t]);
					ss1 << globals->all_save.current_save[2].island_name[t];
				}
			}
			if (globals->all_save.current_save[2].xp == -1) globals->all_save.current_save[2].xp = 0;
			ss1 << ": ";
			ss1 << (int)(globals->all_save.current_save[2].checkpoint * 6.6);
			ss1 << "%";
		}
		else {
			buf3 = "Slot 3: 0%";
		}

		file1_gen.generate(-72, -32, buf1.c_str(), file1_spr);
		file2_gen.generate(-72, 0, buf2.c_str(), file2_spr);
		file3_gen.generate(-72, 32, buf3.c_str(), file3_spr);

		auto file1_icon = bn::sprite_items::save_tiles.create_sprite(98, -34, 0);
		auto file2_icon = bn::sprite_items::save_tiles.create_sprite(98, -34 + 34, 0);
		auto file3_icon = bn::sprite_items::save_tiles.create_sprite(98, -34 + 68, 0);

		if (globals->all_save.current_save[0].last_char_id > -1 && globals->all_save.current_save[0].last_char_id < 7) file1_icon = bn::sprite_items::save_tiles.create_sprite(98, -34, globals->all_save.current_save[0].last_char_id);
		else file1_icon.set_visible(false);

		if (globals->all_save.current_save[1].last_char_id > -1 && globals->all_save.current_save[1].last_char_id < 7) file2_icon = bn::sprite_items::save_tiles.create_sprite(98, 0, globals->all_save.current_save[1].last_char_id);
		else file2_icon.set_visible(false);

		if (globals->all_save.current_save[2].last_char_id > -1 && globals->all_save.current_save[2].last_char_id < 7) file3_icon = bn::sprite_items::save_tiles.create_sprite(98, 34, globals->all_save.current_save[2].last_char_id);
		else file3_icon.set_visible(false);

		short int t = 0;
		short int c = 0;

		bn::music_items_info::span[8].first.play(0.8);

		while (!bn::keypad::a_pressed())
		{
			if (bn::keypad::l_held() && bn::keypad::r_held()) {
				flash_reset();
				globals->all_save.current_save[c].clear();
				bn::core::reset();
			}

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

			arrow.set_y(lerp(arrow.y(), -32 + (32 * c), 0.2));
			bn::core::update();
		}

		// do the save thingy
		switch (c) {
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

		globals->current_save = &globals->all_save.current_save[c];

		// remove panels
		for (int tt = 0; tt < 7; tt++) {
			globals->current_save->popups[tt] = false;
		}
	}

	// if saving doesn't work
	else {
		auto a_button = bn::sprite_items::a_button.create_sprite(90, -48, 0);

		short int t = 0;
		short int c = 0;

		bn::music_items_info::span[8].first.play(0.8);

		bn::vector<bn::sprite_ptr, 6> icons;
		auto t1 = bn::sprite_items::chapters.create_sprite(0,0,0);
		icons.push_back(t1);
		auto t2 = bn::sprite_items::chapters.create_sprite(150,0,1);
		icons.push_back(t2);
		auto t3 = bn::sprite_items::chapters.create_sprite(260,0,2);
		icons.push_back(t3);
		auto t4 = bn::sprite_items::chapters.create_sprite(370,0,3);
		icons.push_back(t4);
		auto t5 = bn::sprite_items::chapters.create_sprite(480,0,4);
		icons.push_back(t5);
		auto t6 = bn::sprite_items::chapters.create_sprite(590,0,5);
		icons.push_back(t6);

		while (!bn::keypad::a_pressed())
		{
			if (bn::keypad::l_held() && bn::keypad::r_held()) {
				//flash_reset();
				globals->all_save.current_save[c].clear();
				bn::core::reset();
			}

			if (bn::keypad::left_pressed()) {
				c--;
				bn::sound_items::click.play();
			}
			if (bn::keypad::right_pressed()) {
				c++;
				bn::sound_items::click.play();
			}

			if (c > 5) c = 0;
			if (c < 0) c = 5;

			for (int t = 0; t < icons.size(); t++) {
				bn::fixed_t new_x = lerp(icons.at(t).x(), (t - c) * 100, 0.2);
				icons.at(t).set_x(new_x);
				if (t != c) icons.at(t).set_scale(1,1);
			}
			icons.at(c).set_scale(1.5, 1.5);

			switch (c) {
				case 0: {
					file1_spr.clear();
					file1_gen.generate(-81, -72, "L'INTRODUCTION", file1_spr);
					break;
				}
				case 1: {
					file1_spr.clear();
					file1_gen.generate(-81, -72, "CHAPITRE 1", file1_spr);
					break;
				}
				case 2: {
					file1_spr.clear();
					file1_gen.generate(-81, -72, "CHAPITRE 2", file1_spr);
					break;
				}
				case 3: {
					file1_spr.clear();
					file1_gen.generate(-81, -72, "CHAPITRE 3", file1_spr);
					break;
				}
				case 4: {
					file1_spr.clear();
					file1_gen.generate(-81, -72, "CHAPITRE 4", file1_spr);
					break;
				}
				case 5: {
					file1_spr.clear();
					file1_gen.generate(-81, -72, "EPILOGUE", file1_spr);
					break;
				}
			}

			// Scrolling background
			t++;
			t = t % 256;
			velvet.set_position(t, t);

			bn::core::update();
		}

		velvet.set_visible(false);
		file1_spr.clear();

		for (int t = 0; t < icons.size(); t++) {
			if (t != c) icons.at(t).set_visible(false);
		}

		bn::sound_items::firehit.play();
		bn::music::stop();
		timer(64);

		globals->current_save->clear();

		switch(c) {
			case 1: {
				globals->current_save->xp = 0;
				globals->current_save->checkpoint = 1;
				break;
			}
			case 2: {
				globals->current_save->xp = 100;
				globals->current_save->checkpoint = 7;
				break;
			}
			case 3: {
				globals->current_save->xp = 200;
				globals->current_save->checkpoint = 9;
				break;
			}
			case 4: {
				globals->current_save->xp = 300;
				globals->current_save->checkpoint = 12;
				break;
			}
			case 5: {
				globals->current_save->xp = 300;
				globals->current_save->checkpoint = 14;
				break;
			}
		}

		BN_LOG("set it to ", globals->current_save->checkpoint);

		// remove panels
		for (int tt = 0; tt < 7; tt++) {
			globals->current_save->popups[tt] = false;
		}
	}
}

void cutscenes(int c)
{
	if (c == 0)
	{
		bn::music_items_info::span[9].first.play(0.8);
		bn::regular_bg_ptr f1 = bn::regular_bg_items::intro_final_1.create_bg(0, 0);
		bn::regular_bg_ptr f2 = bn::regular_bg_items::intro_final_2.create_bg(0, 0);
		f2.set_blending_enabled(true);
		bn::blending::set_transparency_alpha(0);
		f1.put_below();
		timer(32);
		bn::fixed_t<12> see = 0;
		f2.set_visible(true);
		for (short int t = 0; t < 256; t++)
		{
			bn::blending::set_transparency_alpha(see);
			bn::fixed_t<12> c_see = see + 0.01;
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
	bn::core::update();
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

	short int offset = 0;

	bn::regular_bg_ptr background = bn::regular_bg_items::fun_background.create_bg(0, 0);
	bn::regular_bg_ptr sidebar = bn::regular_bg_items::sidebar.create_bg(0, 0);

	// Forest   0.065x
	// Garden   0.13x
	// Caves    0.023x + 2.94

	bn::fixed_t<12> modifier = 0;
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

	short int xp = globals->current_save->xp;
	if (xp == -1) xp = 0;

	bn::fixed_t<12> new_xp = xp + (modifier * score);

	if (globals->current_save->checkpoint < 15) {
		if (new_xp > 300) new_xp = 300;
	}
	else if (globals->current_save->checkpoint < 9) {
		if (new_xp > 200) new_xp = 200;
	}
	else {
		if (globals->current_save->checkpoint < 6) {
			if (new_xp > 100) new_xp = 100;
		}
		else
			if (new_xp > 50) new_xp = 50;
	}

	globals->current_save->xp = new_xp.integer(); // Add score to save total

	int grade = 3;
	bn::fixed_t<12> new_addition = (modifier * score);
	if (new_addition < 40) grade = 0;
	if (new_addition < 30) grade = 1;
	if (new_addition < 20) grade = 2;
	if (new_addition < 10) grade = 3;

	int chap = 4;
	if (globals->current_save->checkpoint < 11) chap = 3;
	if (globals->current_save->checkpoint < 9) chap = 2;
	if (globals->current_save->checkpoint < 5) chap = 1;

	bn::core::update();
	victory v(grade, chari, score, globals->current_save->xp, chap);
	while (!bn::keypad::a_pressed())
	{
		v.update();

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
		bn::core::update();
	}

	return true; // Fortunately, arrow_pos and the final decision weight mean the same thing
}

dungeon_return tree_cut()
{
	popup(3);

	bn::music_items_info::span[2].first.play(bn::fixed(50) / 100);
	short int score = 0;
	short int total = 0;
	bool can_have_sp = false;

	{
		auto cursor = bn::sprite_items::ax_bar.create_sprite(0, 0);
		auto axe_bg = bn::regular_bg_items::axe_game_bg.create_bg(0, 0);
		bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
		bn::vector<bn::sprite_ptr, 16> file1_spr;
		bn::vector<bn::sprite_ptr, 16> file2_spr;
		bn::vector<bn::sprite_ptr, 16> bars;
		bn::vector<bn::sprite_ptr, 16> chop;

		for (short int t = 0; t < 14; t++)
			bars.push_back(bn::sprite_items::horizontal_bar.create_sprite(((t - 7) * 8) + 4, 0));

		auto sq1_spr = bn::sprite_items::aaron_axe_anim.create_sprite(-64 - 48, -16);
		auto sq1 = bn::create_sprite_animate_action_forever(sq1_spr, 4, bn::sprite_items::aaron_axe_anim.tiles_item(), 0, 0, 0, 12, 14, 16, 18, 20, 4, 14, 12);

		auto sq2_spr = bn::sprite_items::aaron_axe_anim.create_sprite(-64 - 48, -16 + 64);
		auto sq2 = bn::create_sprite_animate_action_forever(sq2_spr, 4, bn::sprite_items::aaron_axe_anim.tiles_item(), 1, 1, 1, 13, 15, 17, 19, 21, 5, 15, 13);

		auto sq3_spr = bn::sprite_items::aaron_axe_anim.create_sprite(-48, -16);
		auto sq3 = bn::create_sprite_animate_action_forever(sq3_spr, 4, bn::sprite_items::aaron_axe_anim.tiles_item(), 28, 28, 28, 40, 42, 44, 46, 48, 32, 42, 40);

		auto sq4_spr = bn::sprite_items::aaron_axe_anim.create_sprite(-48, -16 + 64);
		auto sq4 = bn::create_sprite_animate_action_forever(sq4_spr, 4, bn::sprite_items::aaron_axe_anim.tiles_item(), 29, 29, 29, 41, 43, 45, 47, 49, 33, 43, 41);

		auto sq1_sw = bn::create_sprite_animate_action_once(sq1_spr, 1, bn::sprite_items::aaron_axe_anim.tiles_item(), 26, 6, 8, 10);
		auto sq2_sw = bn::create_sprite_animate_action_once(sq2_spr, 1, bn::sprite_items::aaron_axe_anim.tiles_item(), 27, 7, 9, 11);
		auto sq3_sw = bn::create_sprite_animate_action_once(sq3_spr, 1, bn::sprite_items::aaron_axe_anim.tiles_item(), 38, 34, 36, 36);
		auto sq4_sw = bn::create_sprite_animate_action_once(sq4_spr, 1, bn::sprite_items::aaron_axe_anim.tiles_item(), 39, 35, 37, 37);

		auto b_button = bn::sprite_items::b_button.create_sprite(90, -50);
		b_button.set_visible(false);

		auto stump = bn::sprite_items::tree_stump.create_sprite(-32, 39, 0);

		bn::fixed_t<12> curs = 0;
		short int width = 16;
		short int calc_width = width * 4;
		short int max_chop = 4;
		short int hits = 1;
		bool left = false;
		short int wood_stage = 0;

		auto key = bn::sprite_items::magic_keys.create_sprite(-128,0,7);
		key.set_visible(false);

		for (short int t = 0; t < max_chop; t++)
		{
			short int x_pos = -(calc_width / 2) + (std_rnd(calc_width));
			x_pos = (x_pos / 16) * 16;
			chop.push_back(bn::sprite_items::chop_bar.create_sprite(x_pos, 0));
		}

		// Gameloop
		hud current_hud;
		while (!bn::keypad::b_pressed())
		{
			if (key.visible()) {
				if (key.x() < 72) {
					key.set_position(key.x() + 0.75, 0);
				} else {
					key.set_visible(false);
				}
			}

			// Stage of the stump
			switch (wood_stage) {
			default: {
				stump = bn::sprite_items::tree_stump.create_sprite(-32, 38, 0);
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
					stump = bn::sprite_items::tree_stump.create_sprite(-32, 39, 1);
					wood_stage += 1;
				}
				break;
			}
			case 3: {
				break;
			}
			case 4: {
				stump = bn::sprite_items::tree_stump.create_sprite(-32, 39, 2);
				wood_stage += 1;
				break;
			}
			case 5: {
				stump.set_y(stump.y() + 4);
				if (stump.y().integer() > 128) wood_stage += 1;
				break;
			}
			case 6: {
				stump = bn::sprite_items::tree_stump.create_sprite(-32, 38, 0);
				bn::sound_items::pop.play();
				wood_stage = 1;
			}
			}

			// Ready to go notif
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
			}
			else {
				sq1_spr = sq1.sprite();
				sq2_spr = sq2.sprite();
				sq3_spr = sq3.sprite();
				sq4_spr = sq4.sprite();
				sq1.update();
				sq2.update();
				sq3.update();
				sq4.update();
			}

			// Handle HUD
			bn::fixed_t<12> wing = score % 200;
			wing /= 100;
			if (wing < 0.01) wing = 0;
			current_hud.update(wing, score);

			// Move cursor forwards
			curs += 0.2 * (1 + ((bn::fixed_t<12>)score / 200));
			if (curs > 32)
				curs = 0;
			bn::fixed_t<12> curs_f = curs;

			short int dir = (curs.integer() % 32);
			bn::fixed_t<12> curs_loc = sin(curs_f / 32) * calc_width;

			if (score > total)
				total = score;

			if (dir < 8 || dir > 24)
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
					for (short int t = 0; t < max_chop; t++)
					{
						if (chop.at(t).visible()) {
							penalty = true;
							score = score / 2;
						}
					}

					if (penalty) {
						short int ugh = std_rnd(3);
						switch (ugh) {
						case 1:
							bn::sound_items::aaron_ugh_05.play();
							break;
						case 2:
							bn::sound_items::aaron_ugh_05.play();
							break;
						case 3:
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

					if (std_rnd(64) == 2 && globals->current_save->keys[0] != 1) {
						key.set_visible(true);
						key.set_position(-72,0);
					}

					for (short int t = 0; t < max_chop; t++)
					{
						short int x_pos = -(calc_width / 2) + (std_rnd(calc_width));
						x_pos = (x_pos / 4) * 4;
						chop.push_back(bn::sprite_items::chop_bar.create_sprite(x_pos, 0));
					}
				}
				cursor.put_below();
				left = false;
			}

			if (bn::keypad::a_pressed() && left)
			{
				if (key.visible() && std_abs(curs_loc.integer() - key.x().integer()) < 16) {
					bn::sound_items::cnaut.play();
					key.set_visible(false);
					bn::core::update();

					line lc[32] = {
						{true, true, 00, "Tu as une cle!                   Deverrouillez toutes les cles    pour une surprise speciale."},
						{true, true, 00, "COM: Endscene"} };
					dialogue_page_lite(lc);

					globals->current_save->keys[0] = 1;
				}

				bool penalty = true;
				for (short int t = 0; t < max_chop; t++)
				{
					short int c_x = chop.at(t).x().integer();
					if (curs_loc - 8 > c_x - 16 && curs_loc - 8 < c_x + 16)
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
			b_button.put_above();
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
	short int spend = 0;
	short int dir = 0;
	bn::fixed_t<12> x_vector = 0;
	bn::fixed_t<12> y_vector = 1;
	short int init_y = 0;
	bool enabled = true;
	rabbit() {}

	void move()
	{
		entity_anim.update();
		sprite = entity_anim.sprite();

		if (x_vector > 0) {
			sprite.set_horizontal_flip(true);
		}
		else {
			sprite.set_horizontal_flip(false);
		}

		if (spend > 0)
		{
			if (sprite.x() < 0 || sprite.x() > 240 || sprite.y() < 0 || sprite.y() > 160)
			{
				sprite.set_visible(false);
			}
			bn::fixed_t<12> sine = sinf((64 - spend) / 21);
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
	popup(1);

	short int score = 0;
	{
		room current_room(9, 5, 4, 2);

		globals->collisions.clear();
		const short int local_col[current_room.width * current_room.height] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 1, 
			1, 0, 0, 0, 0, 0, 0, 0, 1, 
			1, 1, 1, 1, 1, 1, 1, 1, 1};
		for (short int t = 0; t < current_room.width * current_room.height; t++) {
			globals->collisions.push_back(local_col[t]);
		}

		bn::vector<rabbit, 32> rabbits;
		auto max_rabbits = 32;

		bn::regular_bg_ptr garden_bg = bn::regular_bg_items::garden_bg.create_bg(0, 0);
		garden_bg.set_camera(current_room.camera);

		bool isHolding = false;

		globals->local_tileset.clear();
		globals->collisions.clear();

		if (bn::music::playing()) bn::music::stop();
		bn::music_items_info::span[18].first.play(0.8);

		character enoki(bn::sprite_items::enoki_walking_spring, 8, 2, true);
		enoki.role = 1;
		enoki.identity = 1;
		current_room.chari.push_back(enoki);

		bn::sprite_ptr enoki_hold = bn::sprite_items::enoki_walking_spring.create_sprite(current_room.start_x, current_room.start_y, 12);
		enoki_hold.set_camera(current_room.camera);
		enoki_hold.set_visible(false);

		for (short int t = 0; t < max_rabbits; t++)
		{
			rabbit r;
			r.sprite.set_camera(current_room.camera);
			rabbits.push_back(r);
		}

		short int score_meter = 0;
		short int dir = 0;
		short int last_dir = 0;
		bool playing = true;

		hud current_hud;

		auto key = bn::sprite_items::magic_keys.create_sprite(-172,0,7);
		key.set_camera(current_room.camera);
		key.set_visible(false);

		current_room.init_render(0, 0);
		int ready = 0;
		while (playing)
		{
			if (!key.visible()) {
				ready++;
				if (globals->current_save->keys[1] != 1 && ready == 1024) {
					ready = 0;
					key.set_visible(true);
				}
			} else {
				key.set_x(key.x() + 2);
				if (key.x() > 256) {
					key.set_visible(false);
					key.set_x(-172);
					key.set_y(std_rnd(240) - 120);
				}
			}

			current_room.a_notif.set_visible(false);

			score_meter++;
			if (score_meter == 50)
			{
				score_meter = 0;
				if (score > 10)
					score -= 10;
			}

			bn::fixed_t<12> stretch = score;
			stretch = stretch / 300;
			current_hud.update(stretch, score);

			if (isHolding) {
				enoki.entity.set_position(enoki_hold.x(), enoki_hold.y());
				enoki_hold.set_visible(true);
				enoki.entity.set_visible(false);

				if (bn::keypad::down_pressed()) dir = 0;
				if (bn::keypad::left_pressed()) dir = 2;
				if (bn::keypad::right_pressed()) dir = 1;
				if (bn::keypad::up_pressed()) dir = 3;

				if (dir != last_dir) {
					enoki_hold = bn::sprite_items::enoki_walking_spring.create_sprite(enoki_hold.x(), enoki_hold.y(), 12 + dir);
					enoki_hold.set_camera(current_room.camera);
					last_dir = dir;
				}
			}
			else {
				enoki_hold.set_visible(false);
				enoki.entity.set_visible(true);
				enoki_hold.set_position(enoki.entity.x(), enoki.entity.y());
			}

			bool allOut = true;
			for (short int t = 0; t < max_rabbits; t++)
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
			if (std_rnd(20) == 2)
			{
				for (short int t = 0; t < max_rabbits; t++)
				{
					if (std_rnd(3) == 2)
					{
						rabbits.at(t).moving = false;
					}
					else
					{
						rabbits.at(t).moving = true;
						signed int c_x = (std_rnd(4)) - 2;
						signed int c_y = (std_rnd(4)) - 2;

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

			for (short int t = 0; t < max_rabbits; t++)
			{
				if (
					(std_abs(rabbits.at(t).sprite.x().integer() - enoki.entity.x().integer()) < 8) &&
					(std_abs(rabbits.at(t).sprite.y().integer() - enoki.entity.y().integer()) < 16))
				{
					current_room.start_notif(0);
				}
			}

			if (bn::keypad::a_pressed())
			{
				if (isHolding)
				{
					bn::sound_items::cnaut.play();
					for (short int t = 0; t < max_rabbits; t++)
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
					for (short int t = 0; t < max_rabbits; t++)
					{
						if (
							(std_abs(rabbits.at(t).sprite.x().integer() - enoki.entity.x().integer()) < 8) &&
							(std_abs(rabbits.at(t).sprite.y().integer() - enoki.entity.y().integer()) < 16))
						{
							bn::sound_items::squeak.play();
							isHolding = true;
							rabbits.at(t).carry = true;
							t = max_rabbits;
						}
					}
				}

				if (std_abs(enoki.entity.x().integer() - key.x().integer()) + std_abs(enoki.entity.y().integer() - key.y().integer()) < 32) {
					bn::sound_items::cnaut.play();
					key.set_visible(false);
					bn::core::update();

					line lc[32] = {
						{true, true, 00, "Tu as une cle!                   Deverrouillez toutes les cles    pour une surprise speciale."},
						{true, true, 00, "COM: Endscene"} };
					dialogue_page_lite(lc);

					globals->current_save->keys[1] = 1;
				}
			}

			current_room.update_objects();
			bn::core::update();
		}
	}

	victory_page(1, score);

	dungeon_return dt(1, 10, 4);
	return dt;
}

dungeon_return underground()
{
	popup(2);

	short int score = 0;
	bool is_returned = false;
	bool is_victory = false;

	{
		room current_room(20, 20, 17, 17);

		bn::music_items_info::span[19].first.play(0.8);
		bn::regular_bg_ptr back_floor = bn::regular_bg_items::velvet.create_bg(0, 0);
		bn::regular_bg_ptr back_black = bn::regular_bg_items::velvet.create_bg(0, 0);
		back_floor.set_camera(current_room.camera);
		back_black.set_camera(current_room.camera);

		bn::blending::set_transparency_alpha(0.9);
		bn::sprite_text_generator file_gen(common::variable_8x16_sprite_font);
		bn::vector<bn::sprite_ptr, 16> file_spr;
		bn::vector<bn::sprite_ptr, 16> bars;

		globals->rendered_windows.clear();
		{
			bn::rect_window external_window = bn::rect_window::external();
			external_window.set_show_bg(back_floor, false);
			external_window.set_show_bg(back_black, true);
			external_window.set_show_sprites(false);
			external_window.set_boundaries(-80, -120, 80, 120);
			globals->rendered_windows.push_back(external_window);

			bn::rect_window internal_window = bn::rect_window::internal();
			internal_window.set_show_bg(back_floor, true);
			internal_window.set_show_bg(back_black, false);
			internal_window.set_show_sprites(true);
			internal_window.set_camera(current_room.camera);
			globals->rendered_windows.push_back(internal_window);
		}

		character maple = character(
			bn::sprite_items::maple_walking_spring,
			current_room.start_x,
			current_room.start_y,
			true,
			current_room.width);
		current_room.chari.push_back(maple);

		globals->local_tileset.clear();
		globals->collisions.clear();

		const short int local_col[current_room.width * current_room.height] = {
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
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		const short int local[current_room.width * current_room.height] = {
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
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1 };
		for (short int t = 0; t < current_room.width * current_room.height; t++) {
			globals->local_tileset.push_back(local[t]);
			globals->collisions.push_back(local_col[t]);
		}

		current_room.environment = &bn::sprite_items::underground_tiles;

		current_room.init_render(current_room.start_x, current_room.start_y);

		bn::vector<creepy_crawly, 24> bugs;
		for (short int t = 0; t < 23; t++)
		{
			creepy_crawly bug;
			bug.sprite.set_camera(current_room.camera);

			short int mx = std_rnd(current_room.width - 6);
			short int my = std_rnd(current_room.height - 6);
			short int mz = abs(mx + (my * current_room.width));
			while (globals->local_tileset.at(mz) > 0)
			{
				mx = std_rnd(current_room.width - 6);
				my = std_rnd(current_room.height - 6);
				mz = abs(mx + (my * current_room.width));
			}

			bug.sprite.set_position(mx * 32, my * 32);
			bugs.push_back(bug);
		}

		short int brightness = 1;
		short int abx = 0;
		short int aby = 0;
		short int abz = 0;

		while (globals->local_tileset.at(abz) > 0)
		{
			abx = std_abs(std_rnd(current_room.width - 6));
			aby = std_abs(std_rnd(current_room.height - 6));
			abz = std_abs(abx + (current_room.width * aby));
		}

		if ((abx * -1) > abx) abx = abx * 1;
		if ((aby * -1) > aby) aby = aby * 1;

		bn::sprite_ptr treasure = bn::sprite_items::underground_tiles.create_sprite(abs(abx) * 32, abs(aby) * 32, 1);
		treasure.set_camera(current_room.camera);
		bn::string<8> score_text = bn::to_string<8>(score);

		auto key = bn::sprite_items::magic_keys.create_sprite(-172,0,7);
		key.set_camera(current_room.camera);
		key.set_visible(false);

		if (globals->current_save->keys[2] != 1) {
			while (globals->local_tileset.at(abz) > 0)
			{
				abx = std_abs(std_rnd(current_room.width - 6));
				aby = std_abs(std_rnd(current_room.height - 6));
				abz = std_abs(abx + (current_room.width * aby));
			}

			if ((abx * -1) > abx) abx = abx * 1;
			if ((aby * -1) > aby) aby = aby * 1;	

			key.set_position(32 * abx, 32 * aby);
			key.set_visible(true);
		}

		current_room.a_notif.set_visible(false);
		while (!is_returned)
		{
			if (key.visible()) {
				if (std_abs(maple.entity.x().integer() - key.x().integer()) + std_abs(maple.entity.y().integer() - key.y().integer()) < 32) {
					bn::sound_items::cnaut.play();
					key.set_visible(false);
					globals->rendered_windows.at(0).set_show_sprites(true);
					bn::core::update();

					line lc[32] = {
						{true, true, 00, "Tu as une cle!                   Deverrouillez toutes les cles    pour une surprise speciale."},
						{true, true, 00, "COM: Endscene"} };
					dialogue_page_lite(lc);

					globals->rendered_windows.at(0).set_show_sprites(false);
					globals->current_save->keys[2] = 1;
				}
			}

			score_text = bn::to_string<8>(score);
			file_spr.clear();
			file_gen.generate(0, -48, score_text, file_spr);
			current_room.a_notif.set_visible(false);

			if (abs((current_room.start_y * 32) - maple.entity.y().integer()) < 32 && abs((current_room.start_x * 32) - maple.entity.x().integer()) < 32) {
				current_room.start_notif(0);

				if (bn::keypad::a_pressed()) {
					is_returned = true;
					globals->rendered_windows.at(0).set_show_sprites(true);
				}

				if (!treasure.visible()) {
					is_returned = true;
					is_victory = true;
					globals->rendered_windows.at(0).set_show_sprites(true);
				}
			}

			// Create projectiles
			if (bn::keypad::r_pressed())
			{
				if (score > 50)
				{
					score -= 50;
				}
			}

			// Check collision
			short int mx1 = maple.entity.x().integer();
			short int my1 = maple.entity.y().integer();

			// Update projectiles
			for (short int tt = 0; tt < bugs.size(); tt++)
			{
				bugs.at(tt).update();

				// Maple collision
				if (abs(mx1 - bugs.at(tt).sprite.x().integer()) + abs(my1 - bugs.at(tt).sprite.y().integer()) < 16)
				{
					if (std_rnd(2) == 1) {
						bn::sound_items::maple_ugh_01.play();
					}
					else {
						bn::sound_items::maple_ugh_02.play();
					}

					// Move the treasure
					short int abxx = 0;
					short int abyy = 0;
					while (globals->local_tileset.at(abxx + (current_room.width * abyy)) > 0)
					{
						abxx = std_rnd(current_room.width - 6);
						abyy = std_rnd(current_room.height - 6);
					}

					treasure.set_position(abxx * 32, abyy * 32);
					treasure.set_visible(true);
					score = 0;
					maple.entity.set_position(current_room.start_x * 32, current_room.start_y * 32);
				}

				// Projectile effect
				for (short int t = 0; t < current_room.p.size(); t++)
				{
					if (current_room.p[t].active)
					{
						short int mx = current_room.p[t].fireball.x().integer();
						short int my = current_room.p[t].fireball.y().integer();
						short int distance = abs(bugs.at(tt).sprite.y().integer() - my) + abs(bugs.at(tt).sprite.x().integer() - mx);
						if (distance < 16)
						{
							bn::sound_items::pop.play();

							short int mxx = (std_rnd(current_room.width));
							short int myy = (std_rnd(current_room.height));

							bugs.at(tt).sprite.set_position(mxx * 32, myy * 32);
							bugs.at(tt).to_x = 0;
							bugs.at(tt).to_y = 0;

							score += distance * 5;
						}
					}
				}
			}

			back_black.set_position(
				(back_black.x().integer() + 1) % 256,
				(back_black.y().integer() + 1) % 256);

			if (bn::keypad::r_pressed())
				brightness = 200;
			if (brightness > 4)
				brightness -= 4;
			short int x_from = maple.entity.x().integer() - 24 - 48 - (brightness);
			short int y_from = maple.entity.y().integer() - 24 - 48 - (brightness);
			short int x_to = maple.entity.x().integer() + 24 + 48 + (brightness);
			short int y_to = maple.entity.y().integer() + 24 + 48 + (brightness);
			globals->rendered_windows.at(1).set_boundaries(y_from, x_from, y_to, x_to);

			if (treasure.visible())
			{
				if (abs(maple.entity.x() - treasure.x()) + abs(maple.entity.y() - treasure.y()) < 16)
				{
					bn::sound_items::maple_alright_02.play();
					score += 100;
					treasure.set_visible(false);
				}
			}

			current_room.update_objects();
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

	while (!leave) {

		bn::camera_ptr camera = bn::camera_ptr::create(30, 42);

		bn::vector<bn::sprite_ptr, 54> tiles;
		auto ball = bn::sprite_items::bb_sprites.create_sprite(32, 56, 6);
		ball.set_scale(1, 1);
		ball.set_camera(camera);
		auto paddle = bn::sprite_items::bb_sprites.create_sprite(32, 72);
		paddle.set_scale(2, 1);
		paddle.set_camera(camera);

		for (int x = 0; x < 9; x++) {
			for (int y = 0; y < 5; y++) {
				auto bb = bn::sprite_items::bb_sprites.create_sprite(x * 8, y * 8, y);
				bb.set_camera(camera);
				tiles.push_back(bb);
			}
		}

		short int d_x = 1;
		short int d_y = 1;

		while (ball.y() < 75 && !leave) {

			if (bn::keypad::b_pressed()) leave = true;

			ball.set_position(ball.x() + d_x, ball.y() + d_y);

			if (ball.y() == 64 && (abs(ball.x() - paddle.x()) < 16)) {
				d_y = -1;
				if (ball.x() > paddle.x()) {
					d_x = 1;
				}
				else {
					d_x = -1;
				}
				if (abs(ball.x() - paddle.x()) > 8) d_x = d_x * 2;
				bn::sound_items::pop.play();
			}
			if (ball.y() < 1) d_y = 1;
			if (ball.x() > 63) d_x = d_x * -1;
			if (ball.x() < 1) d_x = d_x * -1;

			bool complete = true;
			for (short int t = 0; t < tiles.size(); t++) {
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

	auto pc_bg = bn::regular_bg_items::pc_background.create_bg(0, 0);
	auto pc_scout = bn::regular_bg_items::pc_scout.create_bg(0, 0);
	auto pc_cursor = bn::sprite_items::pc_cursor.create_sprite(0, 0, 1);
	auto b_button = bn::sprite_items::b_button.create_sprite(90, -50);

	pc_bg.put_above();

	pc_scout.set_blending_enabled(true);
	bn::blending::set_transparency_alpha(0);
	bn::sound_items::pc_whir.play();

	short int ticks = 0;
	bn::fixed_t<12> alpha = 0;
	short int select = 0;
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
			}
			else {
				bn::blending::set_transparency_alpha(bn::fixed(1));
			}
		}

		if (ticks == 108) {
			pc_cursor = bn::sprite_items::pc_cursor.create_sprite(0, 0, 0);
			pc_scout.set_blending_enabled(false);
			bn::blending::set_transparency_alpha(bn::fixed(0.5));
		}

		if (ticks > 108) {
			if (bn::keypad::a_pressed() && pc_cursor.visible()) {
				if (pc_cursor.x().integer() < -14 && pc_cursor.y().integer() < 12) {
					if (pc_cursor.y().integer() < -9) {
						pc_scout = bn::regular_bg_items::pc_folder02.create_bg(0, 0);
						select = 2;
					}
					else {
						pc_scout = bn::regular_bg_items::pc_folder01.create_bg(0, 0);
						select = 1;
					}
				}
				else {
					if (pc_cursor.y() > -14 && pc_cursor.y() < 4) {

						// Trash Folder
						if (select == 2) {
							if (pc_cursor.x() > 14 && pc_cursor.x() < 33) {
								pc_scout = bn::regular_bg_items::pc_document.create_bg(0, 0);
								pc_bg.put_above();

								bn::core::update();
								b_button.set_visible(false);
								exec_dialogue(23);
								pc_scout = bn::regular_bg_items::pc_folder02.create_bg(0, 0);
								b_button.set_visible(true);
							}
							else if (pc_cursor.x() > 32 && pc_cursor.x() < 51) {
								pc_scout = bn::regular_bg_items::pc_document.create_bg(0, 0);
								pc_bg.put_above();

								bn::core::update();
								b_button.set_visible(false);
								exec_dialogue(24);
								pc_scout = bn::regular_bg_items::pc_folder02.create_bg(0, 0);
								b_button.set_visible(true);
							}
							else if (pc_cursor.x() > 50 && pc_cursor.x() < 70) {
								pc_scout = bn::regular_bg_items::pc_document.create_bg(0, 0);
								pc_bg.put_above();

								bn::core::update();
								b_button.set_visible(false);
								exec_dialogue(25);
								pc_scout = bn::regular_bg_items::pc_folder02.create_bg(0, 0);
								b_button.set_visible(true);
							}
						}

						// Documents folder
						else if (select == 1) {
							if (pc_cursor.x() > 14 && pc_cursor.x() < 33) {
								bn::music_items_info::span[28].first.play(0.8);
								pc_scout = bn::regular_bg_items::pc_bbscreen.create_bg(0, 0);
								pc_cursor.set_visible(false);
								pc_bg.put_above();

								// Play breakout
								bool success = ball_breakout();

								bn::music::stop();
								pc_scout = bn::regular_bg_items::pc_folder01.create_bg(0, 0);
								pc_cursor.set_visible(true);
								bn::core::update();

								// Play dialogue on success
								if (success) exec_dialogue(26);

							}
							else if (pc_cursor.x() > 32 && pc_cursor.x() < 51) {
								pc_scout = bn::regular_bg_items::pc_document.create_bg(0, 0);
								pc_bg.put_above();

								b_button.set_visible(false);
								bn::core::update();
								exec_dialogue(22);
								pc_scout = bn::regular_bg_items::pc_folder01.create_bg(0, 0);
								b_button.set_visible(true);
							}
						}

					}
					else {
						pc_scout = bn::regular_bg_items::pc_desktop.create_bg(0, 0);
						select = 0;
					}
				}
			}
		}

		if (ticks == 128) {
			pc_scout = bn::regular_bg_items::pc_desktop.create_bg(0, 0);
		}

		if (ticks < 256) ticks++;
		pc_bg.put_above();
		bn::core::update();
	}

	dungeon_return dt(4, 7, 6);
	return dt;
}

void victory_toutes(int emotion, int total) {

	bn::core::update();

	int new_xp = globals->current_save->xp + (total / 10);

	if (globals->current_save->checkpoint < 15) {
		if (new_xp > 300) new_xp = 300;
	}
	else if (globals->current_save->checkpoint < 9) {
		if (new_xp > 200) new_xp = 200;
	}
	else {
		if (globals->current_save->checkpoint < 6) {
			if (new_xp > 100) new_xp = 100;
		}
		else
			if (new_xp > 50) new_xp = 50;
	}

	globals->current_save->xp = new_xp;

	globals->rendered_windows.clear();
	{
		bn::rect_window external_window = bn::rect_window::external();
		external_window.set_show_sprites(true);
		globals->rendered_windows.push_back(external_window);
	}

	auto bg = bn::regular_bg_items::bg_toutes.create_bg(0, 0);
	auto bg_static = bn::regular_bg_items::bg_static.create_bg(0, 0);
	auto face = bn::sprite_items::toutes_spr.create_sprite(-80, -38, 1);
	auto food = bn::sprite_items::toutes_spr.create_sprite(24, -92, emotion + 3);

	bg_static.set_blending_enabled(true);
	bn::blending::set_transparency_alpha(0.4);

	globals->rendered_windows.at(0).set_show_bg(bg, true);
	globals->rendered_windows.at(0).set_show_bg(bg_static, false);
	globals->rendered_windows.at(0).set_boundaries(-80, -120, 80, 120);

	short int w = 0;
	{
		bn::rect_window internal_window = bn::rect_window::internal();
		internal_window.set_show_bg(bg, true);
		internal_window.set_show_bg(bg_static, true);
		internal_window.set_show_sprites(true);
		internal_window.set_boundaries(-130, 96 - w - 12, 130, 96 + w - 12);
		globals->rendered_windows.push_back(internal_window);
	}

	bn::string<36> buf;

	bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
	bn::vector<bn::sprite_ptr, 12> file1_spr;

	auto b_button = bn::sprite_items::b_button.create_sprite(90, 0);
	b_button.set_visible(false);

	int chap = 2;
	if (globals->current_save->checkpoint > 8) chap = 3;

	bool ready = false;
	victory v(emotion, 6, total, globals->current_save->xp, chap);
	while (!bn::keypad::a_pressed()) {

		v.update();

		if (w < 36) {
			globals->rendered_windows.at(1).set_boundaries(-130, 116 - w - 12, 172, 116 + w - 12);
			w++;
		}

		if (food.y().integer() < -24) {
			food.set_y(food.y() + 1);
		}

		if (food.y().integer() == -24 && !ready) {
			ready = true;
			bn::sound_items::start.play();
			face = bn::sprite_items::toutes_spr.create_sprite(-80, -38, emotion);

			switch (emotion) {
			case 2: {
				buf = "Tu as.. une chaussette.";
				file1_gen.generate(-112, 64, buf.c_str(), file1_spr);
				break;
			}
			case 1: {
				buf = "Tu as.. de le chaussette!";
				file1_gen.generate(-112, 64, buf.c_str(), file1_spr);
				break;
			}
			case 0: {
				buf = "Tu as.. une twenty!";
				file1_gen.generate(-112, 64, buf.c_str(), file1_spr);
				break;
			}
			default: {}
			}
		}

		bg_static.set_position((bg_static.x().integer() + 2) % 256, (bg_static.y().integer() + 1) % 256);

		bn::core::update();
	}

	globals->rendered_windows.clear();
	{
		bn::rect_window external_window = bn::rect_window::external();
		external_window.set_show_sprites(false);
		external_window.set_boundaries(-80, -120, 80, 120);
		globals->rendered_windows.push_back(external_window);

		bn::rect_window internal_window = bn::rect_window::internal();
		internal_window.set_boundaries(0, 0, 0, 0);
		internal_window.set_show_sprites(true);
		globals->rendered_windows.push_back(internal_window);
	}
}

dungeon_return crystal_ball() {

	popup(5);

	short int score = 0;
	short int total = 0;

	{
		bn::vector<bn::sprite_ptr, 16> buttons;
		bn::vector<int, 16> buttons_n;

		bn::regular_bg_ptr crystal_bg = bn::regular_bg_items::bg_crystal01.create_bg(0, 0);
		bn::affine_bg_ptr crystal_rot = bn::affine_bg_items::bg_crystal_ball.create_bg(0, 0);
		crystal_rot.put_above();

		bn::array<bn::fixed, bn::display::height()> horizontal_deltas;
		bn::affine_bg_pivot_position_hbe_ptr horizontal_hbe =
			bn::affine_bg_pivot_position_hbe_ptr::create_horizontal(crystal_rot, horizontal_deltas);

		bn::fixed base_degrees_angle;

		bn::music_items_info::span[22].first.play(0.8);

		buttons.push_back(bn::sprite_items::magic_keys.create_sprite(96, 0, 0));
		buttons_n.push_back(0);

		auto b_button = bn::sprite_items::b_button.create_sprite(90, 50);
		b_button.set_visible(true);

		for (short int t = 0; t < 4; t++) {
			short int nb = (std_rnd(7));
			short int wd = 16;

			if (buttons.size() > 0) wd = buttons.at(buttons.size() - 1).x().integer() + 36;

			buttons.push_back(bn::sprite_items::magic_keys.create_sprite(wd, 0 - pow(wd / 5, 2) / 5, nb));
			buttons_n.push_back(nb);
		}

		short int tick = 0;
		short int angle = 0;

		auto key = bn::sprite_items::magic_keys.create_sprite(0,0,7);
		key.set_visible(false);

		int ready = 0;
		int focus = -1;

		hud current_hud;
		while (!bn::keypad::b_pressed()) {

			if (focus > -1) {
				key.set_visible(true);
				key.set_position(buttons.at(focus - 1).x(), buttons.at(focus - 1).y());
				key.put_above();
			} else {
				key.set_visible(false);
			}

			// Score hud
			bn::fixed_t<12> my_width = total + 1;
			if (my_width > 0) {
				my_width = (score + 1) / my_width;
			}
			else {
				my_width = 0.01;
			}
			current_hud.update(my_width * 2, score);

			base_degrees_angle += 4;

			if (base_degrees_angle >= 360)
			{
				base_degrees_angle -= 360;
			}

			bn::fixed degrees_angle = base_degrees_angle;

			for (int index = 0, limit = bn::display::height() / 2; index < limit; ++index)
			{
				degrees_angle += 16;

				if (degrees_angle >= 360)
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

			if (total < score) total = score;

			short int s = 0;
			if (bn::keypad::a_pressed())        s = 1;
			if (bn::keypad::r_pressed())        s = 2;
			if (bn::keypad::l_pressed())        s = 3;
			if (bn::keypad::up_pressed())       s = 4;
			if (bn::keypad::left_pressed())     s = 5;
			if (bn::keypad::right_pressed())    s = 6;
			if (bn::keypad::down_pressed())     s = 7;

			if (s > 0) {
				if (focus > -1) {
					focus--;
				}

				if (s - 1 == buttons_n.at(0)) {
					bn::sound_items::ding.play();
					score += 5;

					if (focus == 0) {
						bn::sound_items::cnaut.play();
						key.set_visible(false);
						bn::core::update();

						line lc[32] = {
							{true, true, 00, "Tu as une cle!                   Deverrouillez toutes les cles    pour une surprise speciale."},
							{true, true, 00, "COM: Endscene"} };
						dialogue_page_lite(lc);

						globals->current_save->keys[3] = 1;

						ready = 0;
						focus = -1;
					}
				}
				else {
					bn::sound_items::firehit.play();
					score = 0;

					if (focus == 0) {
						ready = 0;
						focus = -1;
					}
				}

				buttons.erase(buttons.begin());
				buttons_n.erase(buttons_n.begin());

				short int nb = (std_rnd(7));
				short int wd = 16;

				if (buttons.size() > 0) wd = buttons.at(buttons.size() - 1).x().integer() + 36;

				buttons.push_back(bn::sprite_items::magic_keys.create_sprite(wd, 0 - pow(wd / 5, 2) / 5, nb));
				buttons_n.push_back(nb);

				if (globals->current_save->keys[3] != 1) ready++;
				if (ready > 42 && focus == -1) focus = buttons_n.size() - 1;
			}

			if (buttons.at(0).x() > 0) {
				for (short int t = 0; t < buttons.size(); t++) {
					short int nw = buttons.at(t).x().integer() - 4;
					buttons.at(t).set_position(nw, 0 - pow(nw / 5, 2) / 5);
				}
			}

			bn::core::update();
		}
	}

	short int emotion = 2;
	if (total > 100) emotion = 1;
	if (total > 200) emotion = 0;

	bn::core::update();
	victory_toutes(emotion, total);

	dungeon_return dt(2, 1, 12);
	return dt;
}

class boat_camera
{
public:
	bn::fixed x = 440;
	bn::fixed y = 128;
	bn::fixed z = 320;
	short int phi = 10;
	short int cos = 0;
	short int sin = 0;
};

struct rock {
	bn::sprite_ptr entity = bn::sprite_items::avocado.create_sprite(0, -20, 5);
	bn::fixed_t<12> size = 0.01;
	bn::fixed_t<12> m_y = -48;
	short int speed = 0;
};

dungeon_return boat_game() {

	popup(6);

	short int score = 0;
	short int total = 0;

	{
		bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
		bn::vector<bn::sprite_ptr, 12> file1_spr;
		bn::sprite_text_generator file2_gen(common::variable_8x16_sprite_font);
		bn::vector<bn::sprite_ptr, 12> file2_spr;
		bn::sprite_text_generator file3_gen(common::variable_8x16_sprite_font);
		bn::vector<bn::sprite_ptr, 12> file3_spr;

		if (bn::music::playing()) bn::music::stop();
		bn::music_items_info::span[30].first.play(0.8);

		boat_camera camera;
		camera.y = -16;
		bn::affine_bg_ptr bg = bn::affine_bg_items::bg_ocean.create_bg(-376, -336);

		auto boat = bn::sprite_items::avocado.create_sprite(0, 48, 0);
		auto wave = bn::sprite_items::avocado.create_sprite(0, 48, 3);
		auto wave_anim = bn::create_sprite_animate_action_forever(wave, 2, bn::sprite_items::avocado.tiles_item(), 3, 4, 3, 4);

		bn::vector<bn::sprite_ptr, 4> sky_ptr;
		sky_ptr.push_back(bn::sprite_items::bg_sky.create_sprite(-120 + 16, -68, 0)); // -68
		sky_ptr.push_back(bn::sprite_items::bg_sky.create_sprite(-120 + 16 + 64, -68, 1));
		sky_ptr.push_back(bn::sprite_items::bg_sky.create_sprite(-120 + 16 + 128, -68, 2));
		sky_ptr.push_back(bn::sprite_items::bg_sky.create_sprite(-120 + 16 + 192, -68, 3));

		for (int t = 0; t < 4; t++) {
			sky_ptr.at(t).set_z_order(0);
		}

		bg.set_z_order(1);

		int16_t pa_values[bn::display::height()];
		bn::affine_bg_pa_register_hbe_ptr pa_hbe = bn::affine_bg_pa_register_hbe_ptr::create(bg, pa_values);

		int16_t pc_values[bn::display::height()];
		bn::affine_bg_pc_register_hbe_ptr pc_hbe = bn::affine_bg_pc_register_hbe_ptr::create(bg, pc_values);

		int dx_values[bn::display::height()];
		bn::affine_bg_dx_register_hbe_ptr dx_hbe = bn::affine_bg_dx_register_hbe_ptr::create(bg, dx_values);

		int dy_values[bn::display::height()];
		bn::affine_bg_dy_register_hbe_ptr dy_hbe = bn::affine_bg_dy_register_hbe_ptr::create(bg, dy_values);

		bn::fixed_t<12> x_offset = 0;

		// Rocks
		rock rs[8] = {};
		for (short int t = 0; t < 8; t++) {
			rock r;
			rs[t] = r;
		}

		short int isMoving = 0;
		short int distance = 16;
		short int tick = 0;

		bool completed = false;
		bn::fixed_t<12> completed_size = 0.48;

		hud current_hud;
		while (completed_size > 0.02) {

			if (distance < 1) completed = true;
			if (distance < 0) distance = 0;
			if (total < score) total = score;

			if (!completed) {
				isMoving = !bn::keypad::down_held();
				if (bn::keypad::down_released()) bn::sound_items::fireblast.play();
				if (bn::keypad::up_pressed()) bn::sound_items::fireblast.play();
				if (bn::keypad::up_held()) isMoving = 2;
			}
			else {
				isMoving = 0;
			}

			tick++;
			if (tick > 256) {
				tick = 0;
				distance -= isMoving;
			}

			for (short int t = 0; t < 8; t++) {

				if (abs(rs[t].entity.x() - boat.x()) < 24 && abs(rs[t].entity.y() - boat.y()) < 24) {
					rs[t].m_y += 96;
					bn::sound_items::firehit.play();
					score = score / 10;
				}

				if (rs[t].m_y > 128) {
					if (std_rnd(36 - (16 - (distance / 2))) == 1) {

						rs[t].size = 0.01;
						rs[t].entity.set_scale(rs[t].size);
						rs[t].entity.set_x((std_rnd(120)) - 60);
						rs[t].speed = rs[t].entity.x().integer() / 10;

						if (std_rnd(6 - (distance / 10)) == 1) {
							rs[t].entity.set_visible(false);
							rs[t].m_y = (0 - (std_rnd(1280)));
							rs[t].entity.set_y(rs[t].m_y);
						}
						else {
							score++;
							rs[t].entity.set_visible(true);
							rs[t].m_y = -48;
							rs[t].entity.put_above();
						}
					}
					else {
						rs[t].entity.set_y(rs[t].m_y);
						rs[t].m_y += 1;
					}
				}
				else {
					if (rs[t].size <= 0)  rs[t].size = 0.01;
					rs[t].entity.set_scale(rs[t].size);
					rs[t].entity.set_y(rs[t].m_y);

					if (isMoving == 1) {
						rs[t].entity.set_x(rs[t].entity.x() + rs[t].speed);
						rs[t].m_y += 1;
						if (rs[t].size < 1) {
							rs[t].size += 0.01;
						}
					}
					else if (isMoving == 2) {
						rs[t].entity.set_x(rs[t].entity.x() + (rs[t].speed * 2));
						rs[t].m_y += 2;
						if (rs[t].size < 1) {
							rs[t].size += 0.02;
						}
					}
				}
			}

			short int camera_x = camera.x.data();
			short int camera_y = camera.y.data() >> 4;
			short int camera_z = camera.z.data();
			short int camera_cos = camera.cos;
			short int camera_sin = camera.sin;
			short int y_shift = 160;
			bn::fixed dir_x = 0;
			bn::fixed dir_z = bn::fixed::from_data(12); //-30

			wave.set_visible(true);
			if (isMoving == 0) {
				dir_z = bn::fixed::from_data(1); // 1
				wave.set_visible(false);
			}
			else if (isMoving == 2) {
				dir_z = bn::fixed::from_data(-196);
			}
			else {
				wave.set_visible(true);
			}

			wave_anim.update();
			wave = wave_anim.sprite();
			boat.put_above();

			// Intro animation
			{
				boat = bn::sprite_items::avocado.create_sprite(0, 48, 0);
				if (isMoving > 0) {
					if (bn::keypad::left_held()) {
						x_offset += 0.01;
						dir_x += bn::fixed::from_data(8);
						boat = bn::sprite_items::avocado.create_sprite(0, 48, 2);

						for (short int t = 0; t < 8; t++) {
							rs[t].entity.set_x(rs[t].entity.x().integer() + 1);
						}
					}
					else if (bn::keypad::right_held()) {
						x_offset -= 0.01;
						dir_x -= bn::fixed::from_data(8);
						boat = bn::sprite_items::avocado.create_sprite(0, 48, 1);

						for (short int t = 0; t < 8; t++) {
							rs[t].entity.set_x(rs[t].entity.x().integer() - 1);
						}
					}
				}
			}

			camera.cos = bn::lut_cos(camera.phi).data() >> 4;
			camera.sin = bn::lut_sin(camera.phi).data() >> 4;
			camera.x += (dir_x * camera.cos) - (dir_z * camera.sin);
			camera.z += (dir_x * camera.sin) + (dir_z * camera.cos);

			for (int index = 0; index < bn::display::height(); ++index)
			{
				short int reciprocal = bn::reciprocal_lut[index].data() >> 4;
				short int lam = camera_y * reciprocal >> 12;
				short int lcf = lam * camera_cos >> 8;
				short int lsf = lam * camera_sin >> 8;

				pa_values[index] = int16_t(lcf >> 4);
				pc_values[index] = int16_t(lsf >> 4);

				short int lxr = (bn::display::width() / 2) * lcf;
				short int lyr = y_shift * lsf;
				dx_values[index] = (camera_x - lxr + lyr) >> 4;

				lxr = (bn::display::width() / 2) * lsf;
				lyr = y_shift * lcf;
				dy_values[index] = (camera_z - lxr - lyr) >> 4;
			}

			pa_hbe.reload_values_ref();
			pc_hbe.reload_values_ref();
			dx_hbe.reload_values_ref();
			dy_hbe.reload_values_ref();

			for (short int t = 0; t < sky_ptr.size(); t++) {
				sky_ptr.at(t).put_above();
			}

			if (completed) {
				boat.set_y(boat.y().integer() - 64);
				wave.set_y(boat.y());
				for (short int t = 0; t < 8; t++) {
					rs[t].entity.set_visible(false);
				}
				if (completed_size <= 0) completed_size = 0.01;
				boat.set_scale(completed_size);
				wave.set_scale(completed_size);
				bn::fixed_t<12> new_completed_size = completed_size - 0.02;
				if (new_completed_size > 0) {
					completed_size = new_completed_size;
				}
			}

			bn::fixed_t<12> me_level = distance * 0.125;
			current_hud.update(me_level, score);
			bn::core::update();
		}

	}

	{
		bn::string<36> buf;
		bn::string<36> bf3;
		bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
		bn::vector<bn::sprite_ptr, 32> file1_spr;
		bn::sprite_text_generator file3_gen(common::variable_8x16_sprite_font);
		bn::vector<bn::sprite_ptr, 32> file3_spr;

		int new_xp = globals->current_save->xp + (total / 4.675);

		if (globals->current_save->checkpoint < 15) {
			if (new_xp > 300) new_xp = 300;
		}
		else if (globals->current_save->checkpoint < 9) {
			if (new_xp > 200) new_xp = 200;
		}
		else {
			if (globals->current_save->checkpoint < 6) {
				if (new_xp > 100) new_xp = 100;
			}
			else
				if (new_xp > 50) new_xp = 50;
		}

		globals->current_save->xp = new_xp;

		bn::music::stop();
		buf = "'Bon travail! Je piloterai";
		file1_gen.generate(-108, -12, buf.c_str(), file1_spr);
		bf3 = "sur le chemin du retour.'";
		file3_gen.generate(-108, 0, bf3.c_str(), file3_spr);

		int grade = 0;
		if (total < 40) grade = 1;
		if (total < 30) grade = 2;
		if (total < 20) grade = 3;

		int chap = 4;
		if (globals->current_save->checkpoint < 11) chap = 3;
		if (globals->current_save->checkpoint < 9) chap = 2;
		if (globals->current_save->checkpoint < 5) chap = 1;

		victory v(grade, 7, total, globals->current_save->xp, chap);
		while (!bn::keypad::a_pressed()) {
			auto docks = bn::regular_bg_items::bg_dock.create_bg(0, 0);
			v.update();

			bn::core::update();
		}
	}

	dungeon_return dt(9, 17, 4);
	return dt;
}

dungeon_return store() {

	// Set up sprites
	auto bg = bn::regular_bg_items::cruz_01.create_bg(0, 0);
	short int item = -1;
	auto b_button = bn::sprite_items::b_button.create_sprite(90, -50);
	auto item_hat = bn::sprite_items::funny_items.create_sprite(-80, 32, 0);
	auto item_bal = bn::sprite_items::funny_items.create_sprite(80, 32, 2);

	if (globals->current_save->hat_world > -1) item_hat = bn::sprite_items::funny_items.create_sprite(-80, 32, 2);

	item_hat.set_scale(2, 2);
	item_bal.set_scale(2, 2);

	bn::sprite_text_generator text_gen(common::variable_8x16_sprite_font);
	bn::vector<bn::sprite_ptr, 8> xp_spr;
	bn::vector<bn::sprite_ptr, 16> item_spr;
	bn::vector<bn::sprite_ptr, 16> desc_spr;
	bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
	bn::sprite_text_generator file2_gen(common::variable_8x16_sprite_font);
	bn::sprite_text_generator file3_gen(common::variable_8x16_sprite_font);

	bn::string<64> string;
	bn::ostringstream string_stream(string);

	xp_spr.clear();
	string = "";
	string_stream << "$";
	string_stream << globals->current_save->xp;
	file1_gen.generate(64, -48, string_stream.str().c_str(), xp_spr);

	bn::core::update();
	while (!bn::keypad::b_pressed()) {

		if (bn::keypad::a_pressed()) {
			if (globals->current_save->hat_world == -1 && item == -1 && globals->current_save->xp >= 75) {
				bn::sound_items::ching.play();
				item_hat = bn::sprite_items::funny_items.create_sprite(-80, 32, 2);
				item_hat.set_scale(2, 2);
				globals->current_save->xp -= 75;
				globals->current_save->hat_char = globals->current_save->last_char_id;
				globals->current_save->hat_world = 14;

				b_button.set_visible(false);
				bn::core::update();

				line lc[32] = {
					{true, true, 00, "Merci!!"},
					{true, true, 00, "COM: Endscene"} };
				dialogue_page_lite(lc);

				xp_spr.clear();
				string = "";
				string_stream << "$";
				string_stream << globals->current_save->xp;
				file1_gen.generate(64, -48, string_stream.str().c_str(), xp_spr);

				b_button.set_visible(true);

			}
			else {
				bn::sound_items::firehit.play();
			}
		}

		if (bn::keypad::left_pressed() || bn::keypad::right_pressed()) {
			bn::sound_items::pop.play();
			item = item * -1;
		}
		
		if (item == -1) {
			item_spr.clear();
			file2_gen.generate(-114, -58, "CHAPEAU DE BANANE", item_spr);
			desc_spr.clear();
			file3_gen.generate(-114, -70, "Le Prix: $75", desc_spr);

			if (item_hat.y() > 32 - 8) item_hat.set_y(item_hat.y() - 1);
			if (item_bal.y() < 32) item_bal.set_y(item_bal.y() + 1);
		}
		else {
			item_spr.clear();
			file2_gen.generate(-114, -58, "PAS D'OBJET", item_spr);
			desc_spr.clear();
			file3_gen.generate(-114, -70, "Le Prix: N/A", desc_spr);

			if (item_bal.y() > 32 - 8) item_bal.set_y(item_bal.y() - 1);
			if (item_hat.y() < 32) item_hat.set_y(item_hat.y() + 1);
		}

		bn::core::update();
	}

	dungeon_return dt(3, 8, 14);
	return dt;
}

class ingredient {
public:
	bn::sprite_ptr entity = bn::sprite_items::gumbo.create_sprite(0, 0, 0);
	short int type = 0;
};

dungeon_return kitchen() {

	short int score = 0;

	bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
	bn::vector<bn::sprite_ptr, 32> file1_spr;

	bn::music_items_info::span[34].first.play(0.8);

	bn::string<32> buf1;

	// Cooking bit
	{
		auto tr_bg = bn::regular_bg_items::axe_game_bg.create_bg(0, 0);
		auto pc_bg = bn::regular_bg_items::bg_cooking_01.create_bg(8, 0);
		short int chari = 0;

		bn::sprite_ptr hand = bn::sprite_items::gumbo.create_sprite(0, 0, 14);

		hud current_hud;
		while (chari < 7) {

			short int je_veus_de = 8 + std_rnd(4);

			switch (chari) {
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
			default: {};
			}

			ingredient food[6];
			bn::sprite_ptr je_veus_de_food = bn::sprite_items::gumbo.create_sprite(40, -36, je_veus_de);

			food[0].entity = bn::sprite_items::gumbo.create_sprite(-42, -39 + 48, 13); // Knife
			food[1].entity = bn::sprite_items::gumbo.create_sprite(-10, -39 + 38, 0);
			food[2].entity = bn::sprite_items::gumbo.create_sprite(-10, -39 + 57, 1);
			food[3].entity = bn::sprite_items::gumbo.create_sprite(-10, -39 + 76, 4);

			food[4].entity = bn::sprite_items::gumbo.create_sprite(32, -39 + 38, 12); // Bowl
			food[5].entity = bn::sprite_items::gumbo.create_sprite(-78, -24, 5);      // Spices

			for (short int t = 0; t < 5; t++) {
				food[t].type = 0;
			}

			short int sel = -1;
			short int counter = 0;

			bn::sprite_ptr chari_mons = bn::sprite_items::gumbo_mons.create_sprite(104, -58, chari * 2);
			chari_mons.put_below();
			bool done = false;
			bool ready = false;
			bool ready_freddy = false;
			bn::fixed_t<12> blend_value = 0;

			bn::blending::set_transparency_alpha(0);
			bn::fixed_t<12> current_level;
			while (!done) {
				current_level = ((6 - chari) * 0.325) + 0.01;
				current_hud.update(current_level, score);

				hand.put_above();

				if (blend_value < 0.05 && ready_freddy) {
					done = true;
				}

				if (food[4].type == je_veus_de && !ready) {

					switch (chari) {
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
					default: {};
					}

					ready = true;
					chari_mons = bn::sprite_items::gumbo_mons.create_sprite(104, -58, (chari * 2) + 1);
					chari_mons.put_below();
				}

				counter++;
				if (counter > 5) {
					if (score > 0) score--;
					counter = 0;
				}

				file1_spr.clear();
				file1_gen.generate(-112, 72, buf1.c_str(), file1_spr);
				buf1 = "";

				for (int t = 0; t < 6; t++) {
					if (food[t].entity.y() < -24 && t != sel) {
						food[t].entity.set_y(food[t].entity.y() + 2);
					}
					if (abs(food[t].entity.x() - hand.x()) + abs(food[t].entity.y() - hand.y()) < 16) {
						switch (t - 1) {
						case 0:
							buf1 = "Des Legumes";
							break;
						case 1:
							buf1 = "Viande";
							break;
						case 2:
							buf1 = "Roux";
							break;
						case 3:
							switch (food[t].type) {
							case 1:
								buf1 = "Bol de riz";
								break;
							case 8:
								buf1 = "Jambalaya";
								break;
							case 9:
								buf1 = "Gumbo";
								break;
							case 10:
								buf1 = "Gumbo + Riz";
								break;
							case 11:
								buf1 = "Ettoufee";
								break;
							default:
								buf1 = "Bol de Vide";
								break;
							}
							break;
						case 4:
							buf1 = "Epices";
							break;
						default: {};
						}
					}
				}

				if (bn::keypad::a_pressed()) {
					bn::sound_items::pop.play();

					for (short int t = 0; t < 6; t++) {
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
						for (short int t = 1; t < 3; t++) {
							if (abs(food[t].entity.x() - hand.x()) + abs(food[t].entity.y() - hand.y()) < 16) {
								food[t].entity = bn::sprite_items::gumbo.create_sprite(food[t].entity.x(), food[t].entity.y(), t + 1);
								food[t].type = 1;
								score += 50;
							}
						}
					}
					else if ((sel > 0 && sel < 3 && food[sel].type == 1) || sel == 3) {
						if (abs(food[4].entity.x() - hand.x()) + abs(food[4].entity.y() - hand.y()) < 16) {
							switch (food[4].type) {
							case 1: {
								if (sel == 1) {
									food[4].type = 7;
									food[4].entity = bn::sprite_items::gumbo.create_sprite(food[4].entity.x(), food[4].entity.y(), 7);
									food[1].entity.set_visible(false);
									score += 50;
								}
								break;
							}
							case 7: {
								if (sel == 2) {
									food[4].type = 8;
									food[4].entity = bn::sprite_items::gumbo.create_sprite(food[4].entity.x(), food[4].entity.y(), 8);
									food[2].entity.set_visible(false);
									score += 50;
								}
								break;
							}
							case 8: {
								if (sel == 3) {
									food[4].type = 9;
									food[4].entity = bn::sprite_items::gumbo.create_sprite(food[4].entity.x(), food[4].entity.y(), 9);
									food[3].entity.set_y(food[3].entity.y().integer() + 16);
									score += 50;
								}
								break;
							}
							case 9: {
								if (sel == 3) {
									food[4].type = 11;
									food[4].entity = bn::sprite_items::gumbo.create_sprite(food[4].entity.x(), food[4].entity.y(), 11);
									food[3].entity.set_visible(false);
									score += 50;
								}
								break;
							}
							default: {};
							}
						}

					}
					else if (sel == 4) {
						if (abs(-105 - hand.x()) + abs(-30 - hand.y()) < 16) {
							if (food[4].type == 0) {
								food[4].type = 1;
								food[4].entity = bn::sprite_items::gumbo.create_sprite(food[4].entity.x(), food[4].entity.y(), 6);
								score += 50;
							}
							else if (food[4].type == 9) {
								food[4].type = 10;
								food[4].entity = bn::sprite_items::gumbo.create_sprite(food[4].entity.x(), food[4].entity.y(), 10);
								score += 50;
							}
						}
						else if (hand.x().integer() > 84 && hand.y().integer() < -33) {
							ready_freddy = true;
							if (food[4].type == je_veus_de) {
								score += 100;
								bn::sound_items::cnaut.play();
							}
							else {
								score = score / 2;
								bn::sound_items::firecrackle.play();
							}
						}
					}
					else if (sel == 5) {
						if (abs(food[4].entity.x() - hand.x()) + abs(food[4].entity.y() - hand.y()) < 16) {
							food[5].entity.set_visible(false);
							score += std_rnd(100);
						}
					}

					sel = -1;
				}

				if (bn::keypad::a_held()) {
					hand = bn::sprite_items::gumbo.create_sprite(hand.x(), hand.y(), 15);
				}
				else {
					hand = bn::sprite_items::gumbo.create_sprite(hand.x(), hand.y(), 14);
				}

				if (bn::keypad::up_held()) {
					if (hand.y().integer() > -80) hand.set_y(hand.y().integer() - 1);
				}

				if (bn::keypad::down_held()) {
					if (hand.y().integer() < 80) hand.set_y(hand.y().integer() + 1);
				}

				if (bn::keypad::left_held()) {
					if (hand.x().integer() > -120) hand.set_x(hand.x().integer() - 1);
				}

				if (bn::keypad::right_held()) {
					if (hand.x().integer() < 120) hand.set_x(hand.x().integer() + 1);
				}

				if (bn::keypad::b_pressed()) {
					chari = 7;
					done = true;
				}

				if (bn::keypad::r_pressed()) {
					switch (je_veus_de) {
					case 8: {
						line lc[32] = {
							{fals, fals, 0, "JUMBALAYA                        Riz, Leg, Vian"},
							{fals, fals, 0, "COM: Endscene"}
						};
						dialogue_page_lite(lc);
						break;
					};
					case 9: {
						line lc[32] = {
							{fals, fals, 0, "GUMBO                            Riz, Leg, Vian, Roux"},
							{fals, fals, 0, "COM: Endscene"}
						};
						dialogue_page_lite(lc);
						break;
					};
					case 10: {
						line lc[32] = {
							{fals, fals, 0, "GUMBO, PLUS DE RICE              Riz, Leg, Vian, Roux, Riz"},
							{fals, fals, 0, "COM: Endscene"}
						};
						dialogue_page_lite(lc);
						break;
					};
					case 11: {
						line lc[32] = {
							{fals, fals, 0, "ETTOUFEE                         Riz, Leg, Vian, Roux, Roux"},
							{fals, fals, 0, "COM: Endscene"}
						};
						dialogue_page_lite(lc);
						break;
					};
					default: {};
					}
				}

				bn::core::update();
			}

			chari++;
		}
	}

	// Reward screen
	{
		bn::music::stop();
		bn::core::update();
		file1_spr.clear();

		auto face_spr = bn::sprite_items::bg_monch_face.create_sprite(8, -43);
		auto face_b_like = bn::create_sprite_animate_action_forever(face_spr, 4, bn::sprite_items::bg_monch_face.tiles_item(), 0, 1, 2, 3, 4, 5, 6, 7);
		auto pc_bg = bn::regular_bg_items::bg_monch.create_bg(0, 0);

		int new_xp = globals->current_save->xp + (score / 22);

		if (globals->current_save->checkpoint < 15) {
			if (new_xp > 300) new_xp = 300;
		}
		else if (globals->current_save->checkpoint < 9) {
			if (new_xp > 200) new_xp = 200;
		}
		else {
			if (globals->current_save->checkpoint < 6) {
				if (new_xp > 100) new_xp = 100;
			}
			else
				if (new_xp > 50) new_xp = 50;
		}

		globals->current_save->xp = new_xp;

		victory v(0, 8, score, globals->current_save->xp, 3);
		while (!bn::keypad::a_pressed()) {
			v.update();
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

	auto bg_stage = bn::regular_bg_items::bg_stage.create_bg(0, 0);
	bg_stage.set_camera(camera);

	bn::music_items_info::span[35].first.play(bn::fixed(100) / 100);
	auto ax = bn::sprite_items::ax_bar.create_sprite(0, 64);

	short int aaron_x = -64;
	short int aaron_y = -64;
	short int aaron_offset_x = 0;
	short int aaron_offset_y = 0;

	bool aaron_change = true;
	short int aaron_action = 1;

	short int rufus_x = 64;
	short int rufus_y = -64;

	short int rufus_offset_x = 0;
	short int rufus_offset_y = 0;

	bool rufus_change = true;
	short int rufus_action = 1;

	auto aaron_tile = bn::sprite_items::fight_tiles.create_sprite(96, 64, 0);
	auto rufus_tile = bn::sprite_items::fight_tiles.create_sprite(-96, 64, 1);

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

	short int rufus_logic = 3;

	while (ax.x() > -72) {

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
		if (std_rnd(12) == 1) {
			short int old_logic = rufus_logic;
			rufus_logic = std_rnd(12);
			if (old_logic != rufus_logic) {
				if (rufus_x > 100) rufus_logic = 0;
				rufus_change = true;
			}
		}

		switch (rufus_logic) {
		case 1: {
			rufus_action = 1;
			break;
		};
		case 2: {
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
			rufus_action = 0;
			rufus_x -= 1;
			break;
		};
		}

		// Collision logic
		if (abs(rufus_x - aaron_x) < 24) {
			ax.set_x(ax.x() - 3);

			rufus_action = 2;
			rufus_change = true;
			aaron_action = 3;
			aaron_change = true;

			bn::sound_items::firehit.play();

			short int ugh = std_rnd(6);
			switch (ugh) {
			case 4:
				bn::sound_items::aaron_ugh_05.play();
				break;
			case 5:
				bn::sound_items::aaron_ugh_05.play();
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

			if (std_rnd(3) == 2) {
				bn::sound_items::firehit.play();

				if (abs(rufus_x - aaron_x) < 96) {
					rufus_action = 3;
					rufus_change = true;
					bn::sound_items::rufus_01.play();
					ax.set_x(ax.x() + 1);
				}

				aaron_action = 2;
				aaron_change = true;
			}
			else if (abs(rufus_x - aaron_x) < 96) {

				ax.set_x(ax.x() - 3);

				rufus_action = 2;
				rufus_change = true;
				aaron_action = 3;
				aaron_change = true;

				bn::sound_items::firehit.play();

				short int ugh = std_rnd(6);
				switch (ugh) {
				case 4:
					bn::sound_items::aaron_ugh_05.play();
					break;
				case 5:
					bn::sound_items::aaron_ugh_05.play();
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
		}

		// Handle animation changes
		if (aaron_change) {
			aaron_change = false;
			switch (aaron_action) {
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
				a_01_anim = bn::create_sprite_animate_action_forever(a_01, 1, bn::sprite_items::battle_aaron.tiles_item(), 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0);
				a_02_anim = bn::create_sprite_animate_action_forever(a_02, 1, bn::sprite_items::battle_aaron.tiles_item(), 23, 21, 19, 17, 15, 13, 11, 9, 7, 5, 3, 1);
				a_03_anim = bn::create_sprite_animate_action_forever(a_03, 1, bn::sprite_items::battle_aaron.tiles_item(), 46, 44, 42, 40, 38, 36, 34, 32, 30, 28, 26, 24);
				a_04_anim = bn::create_sprite_animate_action_forever(a_04, 1, bn::sprite_items::battle_aaron.tiles_item(), 47, 45, 43, 41, 39, 37, 35, 33, 31, 29, 27, 25);

				aaron_offset_x = 4;
				aaron_offset_y = 6;
				break;
			};
			default: {};
			}
		}

		if (rufus_change) {
			rufus_change = false;
			switch (rufus_action) {
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
				break;
			};
			case 3: {
				r_01_anim = bn::create_sprite_animate_action_forever(r_01, 1, bn::sprite_items::battle_rufus.tiles_item(), 124, 126, 128, 130, 132, 134, 136, 138, 140, 140, 140, 140);
				r_02_anim = bn::create_sprite_animate_action_forever(r_02, 1, bn::sprite_items::battle_rufus.tiles_item(), 125, 127, 129, 131, 133, 135, 137, 139, 141, 141, 141, 141);
				r_03_anim = bn::create_sprite_animate_action_forever(r_03, 1, bn::sprite_items::battle_rufus.tiles_item(), 144, 146, 148, 150, 152, 154, 156, 158, 160, 160, 160, 160);
				r_04_anim = bn::create_sprite_animate_action_forever(r_04, 1, bn::sprite_items::battle_rufus.tiles_item(), 145, 147, 149, 151, 153, 155, 157, 159, 161, 161, 161, 161);
				break;
			};
			case 4: {
				r_01_anim = bn::create_sprite_animate_action_forever(r_01, 1, bn::sprite_items::battle_rufus.tiles_item(), 16, 14, 14, 12, 10, 8, 8, 6, 4, 2, 2, 0);
				r_02_anim = bn::create_sprite_animate_action_forever(r_02, 1, bn::sprite_items::battle_rufus.tiles_item(), 17, 15, 15, 13, 11, 9, 9, 7, 5, 3, 3, 1);
				r_03_anim = bn::create_sprite_animate_action_forever(r_03, 1, bn::sprite_items::battle_rufus.tiles_item(), 34, 32, 32, 30, 28, 26, 26, 24, 22, 20, 20, 18);
				r_04_anim = bn::create_sprite_animate_action_forever(r_04, 1, bn::sprite_items::battle_rufus.tiles_item(), 35, 33, 33, 31, 29, 27, 27, 25, 23, 21, 21, 19);
				break;
			};
			default: {}
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

			for (short int t = 1; t < 8; t++) {
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
			}
			else {
				aaron_x -= 32;
			}

			aaron_action = 1;
			aaron_change = true;
		}
	}
}

void core_gameplay(int x, int y, int world, int until)
{
	// Ensures the 'brown screen' doesn't happen
	bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));
	bn::core::update();
	globals->rand_state = globals->current_save->xp;

	// Configure defaults
	dungeon_return dt(x, y, world);

	if (globals->current_save->last_char_id < 0 || globals->current_save->last_char_id > 7) globals->current_save->last_char_id = 0;
	dt.spawn_x = x;
	dt.spawn_y = y;
	dt.world_index = world;

	// Execute until time to leave
	do
	{
		// March event
		if (globals->current_save->checkpoint == 4 && globals->current_save->xp > 99 && globals->current_save->last_char_id != 4) {
			globals->current_save->checkpoint = 5;
			break;
		}

		// June event
		if (globals->current_save->checkpoint == 8 && globals->current_save->xp > 199) {
			globals->current_save->checkpoint = 9;
			break;
		}

		// June event
		if (globals->current_save->checkpoint == 10 && globals->current_save->xp > 299) {
			globals->current_save->checkpoint = 12;
			break;
		}

		// if minigame....
		if (dt.world_index == 99)
		{
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
				bn::music_items_info::span[33].first.play(0.8);
				if (globals->current_save->hat_world == -1) {
					if (globals->current_save->last_char_id == 1) {
						exec_dialogue(31);
					}
					else {
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

		// if legit world....
		else
		{
			dt = dungeon(dt);
		}

		bn::core::update();
	} while (!(dt.world_index == until));
}

void credits() {
	// credits
	{
		bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
		bn::sprite_text_generator file2_gen(common::variable_8x16_sprite_font);
		bn::sprite_text_generator file3_gen(common::variable_8x16_sprite_font);
		bn::vector<bn::sprite_ptr, 42> file1_spr;
		bn::vector<bn::sprite_ptr, 42> file2_spr;
		bn::vector<bn::sprite_ptr, 42> file3_spr;
		bn::string<48> buf1;
		bn::string<48> buf2;
		bn::string<48> buf3;
		short int reg = 3;

		const line_min lc[217] = {
			{"MAPLE TREMBLAY"},
			{"Natalie Anderson"},
			{" - - - - "},

			{"MARIA 'ENOKI' TREMBLAY"},
			{"Brianna Beamer / Mely-Anne Dupuis"},
			{" - - - - "},

			{"AARON TREMBLAY"},
			{"Josh Hollwarth"},
			{" - - - - "},

			{"RUFUS THIBODEAUX"},
			{"Patrick Williams"},
			{" - - - - "},

			{"built with Butano"},
			{"github.com/GValiente/butano"},
			{" - - - - "},

			{"Traduction aidee par"},
			{"Jacob Richer"},
			{" - - - - "},

			{"base sur"},
			{"'Vous Voila' de"},
			{"Ethan Hill"},

			{"created by"},
			{"Ethan Hill"},
			{" - - - - "},

			{" - - - - "},
			{"BAILLEURS DE FONDS KICKSTARTER"},
			{" - - - - "},

			{"Eric Cleveland"},
			{"jess"},
			{"Mithril"},

			{"The Creative Fund by BackerKit"},
			{"Gabe"},
			{"Michael Nock"},

			{"Sam"},
			{"Dean McFarland"},
			{"Ash"},

			{"Jonathan Mellis"},
			{"Alex Fehr"},
			{"Seth Varela"},

			{"Nathan Jaffrey"},
			{"geemuboi"},
			{"Maicon Hieronymus"},

			{"Jay Marsh"},
			{"Brian Revell"},
			{"exelotl"},

			{"Madelyn Watts"},
			{"Scott curbow"},
			{"20JPorter"},

			{"Anna Stevens"},
			{"Ashley SheyLe Heckert"},
			{"Panagiotis konstantatos"},

			{"StripeFruit"},
			{"Sean"},
			{"Josiah Schiewe"},

			{"CrisKa"},
			{"Glyn Thomas Gowing"},
			{"John Burns"},

			{"Andrew Brown"},
			{"Brendon Miller"},
			{"Hexadigital"},

			{"Markus Kitsinger"},
			{"Jon Klein"},
			{"Jared Collins"},

			{"Amra"},
			{"Steven Bedford"},
			{"Shae Trimmer"},

			{"Christopher Chavez"},
			{"Jaicee Orchard"},
			{"Christian Lane"},

			{"Andrew Kennedy"},
			{"Jordan"},
			{"Jack Kelty"},

			{"DrifterCarbon"},
			{"John Mcmillan"},
			{"Timmy Petersson"},

			{"Caylen Williams"},
			{"noah"},
			{"Meepo64"},

			{"Christopher C-C"},
			{"Patrice Tremblay"},
			{"Danilo de Brito Oliveira"},

			{"Lucas Suggate"},
			{"Santiago Valero Lopez"},
			{"paillocher sylvain"},

			{"Callie"},
			{"patrick a estes"},
			{"Russ Perry Jr"},

			{"Zachary"},
			{"Michael Lathrop"},
			{"jonathan moniz"},

			{"Aaron Kaluszka"},
			{"Carmine Red"},
			{"ovenheater"},

			{"Doug Cornforth"},
			{"EnthusiasmEnthusiast"},
			{"Steven"},

			{"Wick.brstm"},
			{"Travis"},
			{"Michelle Alvarado"},

			{"James Paine"},
			{"BlueShadow17"},
			{"Ryan Garland"},

			{"Melissa Jordan"},
			{"Tony Marchese"},
			{"William F"},

			{"Jesse Glenn"},
			{"Juan Velez"},
			{"Tony"},

			{"Jeffery Murphy"},
			{"Thoughts"},
			{"Laurent Dufresne"},

			{"W"},
			{"Cesar Arminio"},
			{"JC Hersey"},

			{"Christer Hakansson"},
			{"Andre Schreieck"},
			{"Rik"},

			{"Plusgalaxy39"},
			{"Taylor Whaley"},
			{"Barry Carenza"},

			{"Gino Stolfa"},
			{"Ben Singletary"},
			{"Robert F. Place"},

			{"Dominic Giambra"},
			{"Giles Hamson"},
			{"Christian Aliferis"},

			{"Nchatxu Vang"},
			{"Mr.SackBoySon"},
			{"Ty Laughlin"},

			{"Andy Sexton"},
			{"veru"},
			{"Seth Adams"},

			{"Edward"},
			{"Jesus Alejandro Hernandez Andrade"},
			{"David Fields"},

			{"Paul Anthony Maddaloni"},
			{"Jonathan S"},
			{"Michael Towns"},

			{"Saysavanh"},
			{"Timothy Bohman"},
			{"Matthew Ohanlon"},

			{"Nicolas Pflanzl"},
			{"Jonathan Kade"},
			{"Siddhartha Barnhoorn"},

			{"Evan Bowman"},
			{"Brian Gupta"},
			{"Chris Bardsley"},

			{"Chairman Kaga"},
			{"Nitrobot"},
			{"John Pettit"},

			{"Martin M"},
			{"Willem"},
			{"Niki Coppola"},

			{"Paul Stedman"},
			{"Tom Nichols"},
			{"Leif Conti-Groome"},

			{"Henry Seymour"},
			{"Eric"},
			{"Ethan N Holloway"},

			{"Ronald Le"},
			{"Nicholas Paul Wilson"},
			{"Kurt K"},

			{"Avery"},
			{"Gary Mullen"},
			{"Noah"},

			{"Gautham Yerroju"},
			{"David Herrera"},
			{"michael darrow"},

			{"Cassandra Pohlkotte"},
			{"Voosh"},
			{"Zach Curley"},

			{"Samer Najjar"},
			{"Anthony Rappazzo"},
			{"Kendra Jones"},

			{"Adrienne M."},
			{"Fray Coache"},
			{"metalrocks5150"},

			{"Jackson D. Q-Wrenslater"},
			{"SerMolok"},
			{"Lee Broadley"},

			{"Blake McKean"},
			{"Brad Parker"},
			{"Mike D"},

			{"YourNerdyJoe"},
			{"Foghorn Ladytown"},
			{"Deontiae Moore"},

			{"Billy Harwood-Sloan"},
			{"Boggie"},
			{"Magic Nathan 65"},

			{"Kevin"},
			{"Nathan"},
			{"Kit Kong"},

			{"Wendy Wentworth Smiseck"},
			{"Lewis J Cabibi II"},
			{"Joshua Kohn"},

			{"Suede"},
			{"Click_Kom"},
			{"Chad McManus"},
			{"jsh1up"},

			{"Petr Hollay"},
			{"Jammy"},

			{"Dayna"},
			{"James"},
			{"Thomas McGuire"},

			{" - - - - " },
			{"REMERCIEMENT SPECIAL:"},
			{" - - - - "},

			{"my friends and family"},
			{"r/cajunfrench"},
			{"LETU Game Design Club"},

			{"Thank you for playing!"},
			{"Merci d'avoir joue!"},
			{" - LA FIN - "},

			{" . . . . "},
			{" - - - - "}
		};

		buf1 = lc[0].text;
		buf2 = lc[1].text;
		buf3 = lc[2].text;

		file1_spr.clear();
		file1_gen.generate(-112, 96, buf1.c_str(), file1_spr);
		file2_gen.generate(-112, 96 + 14, buf2.c_str(), file2_spr);
		file3_gen.generate(-112, 96 + 28, buf3.c_str(), file3_spr);

		short int ending = 215;
		short int scroll_on = 0;
		while (reg < ending) {
			scroll_on += 1;
			scroll_on = scroll_on % 2;

			if (scroll_on == 0 && reg < ending - 1) {
				for (short int t = 0; t < file1_spr.size(); t++) {
					file1_spr.at(t).set_y(file1_spr.at(t).y() - 1);
				}
				if (file1_spr.at(0).y().integer() < -104 && reg < ending - 1) {
					buf1 = lc[reg].text;
					file1_spr.clear();
					file1_gen.generate(-112, 96, buf1.c_str(), file1_spr);
					reg++;
				}

				for (short int t = 0; t < file2_spr.size(); t++) {
					file2_spr.at(t).set_y(file2_spr.at(t).y() - 1);
				}
				if (file2_spr.at(0).y().integer() < -104 && reg < ending - 1) {
					buf2 = lc[reg].text;
					file2_spr.clear();
					file2_gen.generate(-112, 96, buf2.c_str(), file2_spr);
					reg++;
				}

				for (short int t = 0; t < file3_spr.size(); t++) {
					file3_spr.at(t).set_y(file3_spr.at(t).y() - 1);
				}
				if (file3_spr.at(0).y().integer() < -104 && reg < ending - 1) {
					buf3 = lc[reg].text;
					file3_spr.clear();
					file3_gen.generate(-112, 96, buf3.c_str(), file3_spr);
					reg++;
				}
			}

			bn::core::update();
		}
	}

	while (true) {
		bn::core::update();
	}
}

void handle_minigame() {
	exec_dialogue(37);

	while(true) {
		int select = select_minigame();

		{
			switch(select) {
				case 0: {
					underground();
					break;
				}
				case 1: {
					rabbit_game();
					break;
				}
				case 2: {
					tree_cut();
					break;
				}
				case 3: {
					computer();
					break;
				}
				case 4: {
					crystal_ball();
					break;
				}
				case 5: {
					boat_game();
					break;
				}
				case 6: {
					kitchen();
					break;
				}
			}
		}

		bn::core::update();
	}
}

int checkpoint(int level)
{

	if (globals->current_save->checkpoint < 1)
	{
		globals->current_save->checkpoint = 0;
		level = 0;
	}

	switch (level)
	{

		// Introduction
	case 0: {
		intros(0);

		exec_dialogue(0);
		exec_dialogue(1);
		exec_dialogue(2);
		exec_dialogue(3);

		bn::music_items_info::span[2].first.play(0.8);
		bn::music_items_info::span[2].first.play(0.8);

		core_gameplay(8, 3, 0, -1);
		cutscenes(0);
		exec_dialogue(13);
		cutscenes(1);
		exec_dialogue(14);
		if (DEVICE_TYPE == 0) keyboard();
		exec_dialogue(15);
		break;
	}

		  // Spring
	case 1: {
		intros(1);
		exec_dialogue(16);
		globals->current_save->last_char_id = 0;
		core_gameplay(9, 16, 4, 5);
		break;
	}

		  // Welcome message
	case 2: {
		bn::music_items_info::span[8].first.play(0.8);
		exec_dialogue(18);
		popup(0);
		break;
	}

		  // Spawning into their house
	case 3: {
		core_gameplay(5, 3, 5, 4);
		break;
	}

		  // Yes
	case 4: {
		core_gameplay(9, 6, 4, 7);
		break;
	}
	case 5: {
		//core_gameplay(5, 8, 4, 5);
		globals->current_save->checkpoint++;
		break;
	}
	case 6: {
		bn::music_items_info::span[8].first.play(0.8);
		exec_dialogue(17);
		exec_dialogue(19);
		exec_dialogue(20);
		break;

		// Summer - Diana, Eleanor, and Vee
	}
	case 7: {
		intros(2);
		exec_dialogue(21);
		popup(4);
		break;
	}
	case 8: {
		if (globals->current_save->last_char_id == 3) {
			core_gameplay(8, 10, 4, 0);
		}
		else if (globals->current_save->last_char_id < 3) {
			core_gameplay(9, 6, 4, 0);
		}
		else {
			core_gameplay(10, 6, 8, 0);
		}
		break;
	}

	case 9: {
		exec_dialogue(29);
		intros(3);
		exec_dialogue(28);
		break;
	}

	case 10: {
		if (globals->current_save->last_char_id == 3) {
			core_gameplay(8, 10, 4, 0);
		}
		else if (globals->current_save->last_char_id < 3) {
			core_gameplay(9, 6, 4, 0);
		}
		else {
			core_gameplay(10, 6, 8, 0);
		}
		break;
	}

	case 11: {
		globals->current_save->checkpoint = 10;
		break;
	}

	case 12: {
		{
			intros(4);
			if (bn::music::playing()) bn::music::stop();
		}
		
		{
			exec_dialogue(32);
			globals->current_save->last_char_id = 2;
		}

		core_gameplay(9, 6, 4, 0);
		break;
	}

	case 13: {
		globals->current_save->checkpoint = 12;
		break;
	}

	case 14: {
		dungeon_return dt;
		dt.spawn_x = 1;//1;//3;//22;//1;
		dt.spawn_y = 9;//9;//62;//22;//9;
		dt.world_index = 0;//0;//2;//1;//0;

		do {
			dt = rufus_dungeon(dt);
		} while (dt.world_index < 99);

		intros(5);
		exec_dialogue(34);
		final_battle();
		exec_dialogue(35);
		credits();
		break;
	}

	case 15: {

		bool keys_got = true;
		for (int t = 0; t < 4; t++) {
			if (globals->current_save->keys[t] != 1) keys_got = false;
		}

		if (keys_got) {
			handle_minigame();
		} else {
			intros(5);
			exec_dialogue(34);
			final_battle();
			exec_dialogue(35);
			credits();
		}
		break;
	}

	default: {
		return 0;
		break;
	}
	}
	bn::core::update();
	return level + 1;
}

int main()
{
	bn::core::init(); // Initialize Butano libraries
	//int f = flash_init(FLASH_SIZE_AUTO);

	// 'new' allows me to store this in the heap instead of the stack
	globals = new global_data();
	globals->current_save = new save_struct();
	BN_LOG(DEVICE_TYPE);

	/*
	dungeon_return dt;
	dt.spawn_x = 16;
	dt.spawn_y = 19;
	dt.world_index = 1;
	rufus_dungeon(dt);
	*/

	startup();
	flash_read();
	load_save();

	while (globals->current_save->checkpoint < 99) {
		globals->current_save->checkpoint = checkpoint(globals->current_save->checkpoint);
	}

	// Get to the end?
	bn::core::reset();
}