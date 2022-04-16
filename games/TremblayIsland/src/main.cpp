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

#include "bn_sprite_items_flags.h"

// 0 = saving enabled
// 1 = saving disabled

#define DEVICE_TYPE 0

bn::fixed_t<12> lerp(bn::fixed a, int b, bn::fixed_t<12> t)
{
	return a * (1 - t) + b * t;
}

class save_struct
{
public:
	short int last_char_id = 0;
	short int checkpoint = 0;
	char island_name[16] = {0};
	short int spawn_x = 0;
	short int spawn_y = 0;
	short int world_index = 0;
	short int xp = 0;
	short int hat_x = 0;
	short int hat_y = 0;
	short int hat_world = 0;
	short int hat_char = -1;
	bool popups[16] = {false};
	bool keys[16] = {false};

	save_struct() {}

	void clear()
	{
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

		char def[16] = {0};
		strcpy(island_name, def);

		for (int t = 0; t < 16; t++)
		{
			keys[t] = 0;
		}
	}
};

class save_all_struct
{
public:
	save_struct current_save[3];
	int save_init = 0;
	int language = 0;
};

// defined expressions
constexpr auto fals = false;
constexpr auto tile_count = 400;

// Reserved global memory
class global_data
{
public:
	save_all_struct all_save;
	save_struct *current_save;
	bn::vector<unsigned short int, tile_count> local_tileset;
	bn::vector<bn::rect_window, 2> rendered_windows;
	bn::vector<unsigned short int, tile_count> collisions;
	int rand_state;
	bn::random bn_random;

	global_data()
	{
		rand_state = 0;
	}
};

global_data *globals;

void flash_reset()
{
	if (DEVICE_TYPE == 0)
	{
		globals = new global_data();
		bn::sram::write(globals->all_save);
	}
}

void flash_write()
{
	if (DEVICE_TYPE == 0)
	{
		bn::sram::write(globals->all_save);
	}
}

void flash_read()
{
	if (DEVICE_TYPE == 0)
	{
		bn::sram::read(globals->all_save);
	}

	// Clear if need be
	if (globals->all_save.save_init != 99)
	{
		flash_reset();
		for (int t = 0; t < 3; t++)
		{
			globals->all_save.current_save[t].clear();
		}
		globals->all_save.save_init = 99;
	}
}

__attribute__((section(".ewram.std_rnd"))) int std_rnd(int x = 0)
{
	globals->rand_state = (globals->rand_state * 137 + 12345) % 2048;
	return abs(globals->rand_state) % x;
}

int std_abs(int x)
{
	short int nx = x * -1;
	if (nx > x)
		return nx;
	return x;
}

// Generic classes
class line
{
public:
	bool transition;
	bool left;
	const int img = 0;
	const bn::string<192> text = "";
	const char move_to = 0;
};

// Generic classes
class line_min
{
public:
	const char text[34] = {0};
};

// Set pointer by integer reference
void set_sprite(bn::sprite_ptr chari, int value)
{
	switch (value)
	{
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

int select_minigame()
{
	globals->rendered_windows.clear();

	{
		bn::rect_window external_window = bn::rect_window::external();
		external_window.set_show_sprites(true);
		globals->rendered_windows.push_back(external_window);

		bn::rect_window internal_window = bn::rect_window::internal();
		internal_window.set_show_sprites(true);
		globals->rendered_windows.push_back(internal_window);
	}

	auto velvet = bn::regular_bg_items::velvet.create_bg(0, 0);
	auto arrow = bn::sprite_items::arrow.create_sprite(-106, 0);
	int t = 0;
	int select = 0;

	if (bn::music::playing())
		bn::music::stop();

	// velvet
	bn::music_items::multisong.play(0.8);

	bn::vector<bn::sprite_ptr, 7> chari;
	bn::sprite_ptr c1 = bn::sprite_items::save_tiles.create_sprite(-64, 0, 0);
	bn::sprite_ptr c2 = bn::sprite_items::save_tiles.create_sprite(-64, 32, 1);
	bn::sprite_ptr c3 = bn::sprite_items::save_tiles.create_sprite(-64, 64, 2);
	bn::sprite_ptr c4 = bn::sprite_items::save_tiles.create_sprite(-64, 96, 3);
	bn::sprite_ptr c5 = bn::sprite_items::save_tiles.create_sprite(-64, 128, 5);
	bn::sprite_ptr c6 = bn::sprite_items::save_tiles.create_sprite(-64, 160, 6);
	bn::sprite_ptr c7 = bn::sprite_items::save_tiles.create_sprite(-64, 192, 7);
	chari.push_back(c1);
	chari.push_back(c2);
	chari.push_back(c3);
	chari.push_back(c4);
	chari.push_back(c5);
	chari.push_back(c6);
	chari.push_back(c7);

	bn::sprite_text_generator text_line(common::variable_8x16_sprite_font);
	bn::vector<bn::sprite_ptr, 32> text_sprite0;

	bn::sprite_ptr a_button = bn::sprite_items::a_button.create_sprite(-90, -48, globals->all_save.language * 2);

	while (!bn::keypad::a_pressed())
	{
		// Scrolling background
		t++;
		t = t % 256;
		velvet.set_position(t, t);

		for (int t = 0; t < chari.size(); t++)
		{
			chari.at(t).set_y(lerp(chari.at(t).y(), ((t - select) * 36), bn::fixed(0.2)));
		}

		text_sprite0.clear();
		switch (select)
		{
		case 0:
		{
			text_line.generate(-16, 0, "Maple's Gem Thing", text_sprite0);
			break;
		}
		case 1:
		{
			text_line.generate(-16, 0, "Enoki's Garden", text_sprite0);
			break;
		}
		case 2:
		{
			text_line.generate(-16, 0, "Aaron's 'Ax Game'", text_sprite0);
			break;
		}
		case 3:
		{
			text_line.generate(-16, 0, "Scout's Computer", text_sprite0);
			break;
		}
		case 4:
		{
			text_line.generate(-16, 0, "Eleanor's Crystal Ball", text_sprite0);
			break;
		}
		case 5:
		{
			text_line.generate(-16, 0, "Diana's 'Boat Game'", text_sprite0);
			break;
		}
		case 6:
		{
			text_line.generate(-16, 0, "Guy's 'Kitchen Game'", text_sprite0);
			break;
		}
		}

		if (arrow.y() > 0)
			arrow.set_y(arrow.y() - 1);
		if (arrow.y() < 0)
			arrow.set_y(arrow.y() + 1);

		if (bn::keypad::up_pressed())
		{
			bn::sound_items::ui_sfx02.play();
			arrow.set_y(4);
			select--;
			if (select < 0)
				select = 6;
		}

		if (bn::keypad::down_pressed())
		{
			bn::sound_items::ui_sfx02.play();
			arrow.set_y(-4);
			select++;
			if (select > 6)
				select = 0;
		}

		bn::core::update();
	}

	return select;
}

// Primary page
void dialogue_page(line n[32])
{

	// Variable initialization
	bn::vector<const bn::regular_bg_item *, 5> backdrops;
	bn::sprite_text_generator text_line(common::variable_8x16_sprite_font);
	bn::sprite_ptr chari_l = bn::sprite_items::maple01.create_sprite(-50, -15);
	bn::sprite_ptr chari_r = bn::sprite_items::maple01.create_sprite(50, -15);
	bn::sprite_ptr a_button = bn::sprite_items::a_button.create_sprite(-90, -72, (globals->all_save.language * 2) + 1);
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
	while (cont)
	{

		// Set music
		if (strcmp(n[pos].text.c_str(), "BG: 0") == 0)
		{
			bn::music_items::castle.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text.c_str(), "BG: 1") == 0)
		{
			bn::music_items::fruit.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text.c_str(), "BG: 2") == 0)
		{
			bn::music_items::new_castle.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text.c_str(), "BG: champ") == 0)
		{
			bn::music_items::z02_the_champ.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text.c_str(), "BG: Overworld 01") == 0)
		{
			// z03_overworld
			bn::music_items::multisong.play(bn::fixed(music_volume) / 100);
			bn::music::set_position(14);
		}
		else if (strcmp(n[pos].text.c_str(), "BG: frog") == 0)
		{
			// z07_frog
			bn::music_items::multisong.play(bn::fixed(music_volume) / 100);
			bn::music::set_position(10);
		}
		else if (strcmp(n[pos].text.c_str(), "BG: news") == 0)
		{
			bn::music_items::z15_flame.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text.c_str(), "BG: rain") == 0)
		{
			bn::music_items::z06_dangerous.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text.c_str(), "BG: the flame") == 0)
		{
			bn::music_items::z14_flame.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text.c_str(), "BG: maple") == 0)
		{
			bn::music_items::z11_maple_theme.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text.c_str(), "BG: pools") == 0)
		{
			bn::music_items::z21_pools.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text.c_str(), "BG: groovy") == 0)
		{
			bn::music_items::z12_groovy.play(bn::fixed(music_volume) / 100);
		}
		else if (strcmp(n[pos].text.c_str(), "BG: fadeout") == 0)
		{
			if (bn::music::playing())
			{
				bn::music::set_volume(0);
			}

			// Sound effects
		}
		else if (strcmp(n[pos].text.c_str(), "SF: Hey Maple") == 0)
		{
			bn::sound_items::heymaple.play();
		}
		else if (strcmp(n[pos].text.c_str(), "SF: Maple Ugh") == 0)
		{
			bn::sound_items::maple_ugh_01.play();
		}
		else if (strcmp(n[pos].text.c_str(), "SF: Rufus Squeak") == 0)
		{
			bn::sound_items::rufus_01.play();
		}
		else if (strcmp(n[pos].text.c_str(), "SF: Rufus Laugh") == 0)
		{
			bn::sound_items::rufus_02.play();
		}
		else if (strcmp(n[pos].text.c_str(), "SF: Boom") == 0)
		{
			bn::sound_items::boom.play();
		}
		else if (strcmp(n[pos].text.c_str(), "SF: rufus") == 0)
		{
			bn::sound_items::rufus_02.play();

			// SE: rufus

			// Set backgrounds
		}
		else if (strcmp(n[pos].text.c_str(), "BG: Ocean") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::ocean);
			backdrops.push_back(&bn::regular_bg_items::ocean_01);
			backdrops.push_back(&bn::regular_bg_items::ocean_02);
		}
		else if (strcmp(n[pos].text.c_str(), "BG: Moody") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::bg_moody);
		}
		else if (strcmp(n[pos].text.c_str(), "BG: CRUZ01") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::cruz_01);
		}
		else if (strcmp(n[pos].text.c_str(), "BG: CRUZ02") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::cruz_02);
		}
		else if (strcmp(n[pos].text.c_str(), "BG: Trailer Home") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::bg_trailer_home);
			cascade_bg.value().set_position(88, -64);
		}
		else if (strcmp(n[pos].text.c_str(), "S01:01") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0101);
			backdrops.push_back(&bn::regular_bg_items::s0101_1);
			backdrops.push_back(&bn::regular_bg_items::s0101_2);
		}
		else if (strcmp(n[pos].text.c_str(), "S01:02") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0102);
			backdrops.push_back(&bn::regular_bg_items::s0102_01);
			backdrops.push_back(&bn::regular_bg_items::s0102_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S01:03") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0103);
			backdrops.push_back(&bn::regular_bg_items::s0103_01);
			backdrops.push_back(&bn::regular_bg_items::s0103_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S01:04") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0104);
			backdrops.push_back(&bn::regular_bg_items::s0104_01);
			backdrops.push_back(&bn::regular_bg_items::s0104_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S01:05") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0105);
		}
		else if (strcmp(n[pos].text.c_str(), "S01:06") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0106);
			backdrops.push_back(&bn::regular_bg_items::s0106_01);
			backdrops.push_back(&bn::regular_bg_items::s0106_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S01:07") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0107);
			backdrops.push_back(&bn::regular_bg_items::s0107_01);
			backdrops.push_back(&bn::regular_bg_items::s0107_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S01:08") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0108);
			backdrops.push_back(&bn::regular_bg_items::s0108_01);
			backdrops.push_back(&bn::regular_bg_items::s0108_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S01:09") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0109);
			backdrops.push_back(&bn::regular_bg_items::s0109a);
			backdrops.push_back(&bn::regular_bg_items::s0109b);
		}
		else if (strcmp(n[pos].text.c_str(), "S01:10") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::castle01);
			backdrops.push_back(&bn::regular_bg_items::castle01_01);
			backdrops.push_back(&bn::regular_bg_items::castle01_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S01:11") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::castle02);
			backdrops.push_back(&bn::regular_bg_items::castle02_01);
			backdrops.push_back(&bn::regular_bg_items::castle02_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S01:12") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::castle03);
			backdrops.push_back(&bn::regular_bg_items::castle03_01);
			backdrops.push_back(&bn::regular_bg_items::castle03_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S01:13") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::day_castle);
		}
		else if (strcmp(n[pos].text.c_str(), "S02:01") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0201);
		}
		else if (strcmp(n[pos].text.c_str(), "S02:02") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0202);
			backdrops.push_back(&bn::regular_bg_items::s0202_01);
			backdrops.push_back(&bn::regular_bg_items::s0202_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S02:03") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0203);
			backdrops.push_back(&bn::regular_bg_items::s0203_01);
			backdrops.push_back(&bn::regular_bg_items::s0203_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S02:04") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0204);
			backdrops.push_back(&bn::regular_bg_items::s0204_01);
			backdrops.push_back(&bn::regular_bg_items::s0204_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S02:05") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0205);
			backdrops.push_back(&bn::regular_bg_items::s0205_01);
			backdrops.push_back(&bn::regular_bg_items::s0205_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S02:06") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0206);
			backdrops.push_back(&bn::regular_bg_items::s0206_01);
			backdrops.push_back(&bn::regular_bg_items::s0206_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S02:07") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0207);
			backdrops.push_back(&bn::regular_bg_items::s0207_01);
			backdrops.push_back(&bn::regular_bg_items::s0207_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S02:08") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0208);
			backdrops.push_back(&bn::regular_bg_items::s0208_01);
			backdrops.push_back(&bn::regular_bg_items::s0208_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S03:01") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0301);
			backdrops.push_back(&bn::regular_bg_items::s0301_01);
			backdrops.push_back(&bn::regular_bg_items::s0301_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S03:02") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0302);
			backdrops.push_back(&bn::regular_bg_items::s0302_01);
			backdrops.push_back(&bn::regular_bg_items::s0302_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S04:01") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0401);
			backdrops.push_back(&bn::regular_bg_items::s0401_01);
			backdrops.push_back(&bn::regular_bg_items::s0401_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S04:02") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0402);
			backdrops.push_back(&bn::regular_bg_items::s0402_01);
			backdrops.push_back(&bn::regular_bg_items::s0402_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S04:03") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0403);
			backdrops.push_back(&bn::regular_bg_items::s0403_01);
			backdrops.push_back(&bn::regular_bg_items::s0403_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S04:04") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0404);
			backdrops.push_back(&bn::regular_bg_items::s0404_01);
			backdrops.push_back(&bn::regular_bg_items::s0404_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S04:05") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0405);
			backdrops.push_back(&bn::regular_bg_items::s0405_01);
			backdrops.push_back(&bn::regular_bg_items::s0405_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S04:06") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0406);
			backdrops.push_back(&bn::regular_bg_items::s0406_01);
			backdrops.push_back(&bn::regular_bg_items::s0406_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S04:07") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0407);
			backdrops.push_back(&bn::regular_bg_items::s0407_01);
			backdrops.push_back(&bn::regular_bg_items::s0407_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S05:01") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0501);
			backdrops.push_back(&bn::regular_bg_items::s0501_01);
			backdrops.push_back(&bn::regular_bg_items::s0501_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S05:02") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0502);
			backdrops.push_back(&bn::regular_bg_items::s0502_01);
			backdrops.push_back(&bn::regular_bg_items::s0502_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S06:01") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0601);
			backdrops.push_back(&bn::regular_bg_items::s0601_01);
			backdrops.push_back(&bn::regular_bg_items::s0601_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S06:02") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0602);
			backdrops.push_back(&bn::regular_bg_items::s0602_01);
			backdrops.push_back(&bn::regular_bg_items::s0602_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S06:03") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0603);
			backdrops.push_back(&bn::regular_bg_items::s0603_01);
			backdrops.push_back(&bn::regular_bg_items::s0603_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S07:01") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0701);
			backdrops.push_back(&bn::regular_bg_items::s0701_01);
			backdrops.push_back(&bn::regular_bg_items::s0701_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S07:02") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0702);
			backdrops.push_back(&bn::regular_bg_items::s0702_01);
			backdrops.push_back(&bn::regular_bg_items::s0702_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S07:03") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0703);
			backdrops.push_back(&bn::regular_bg_items::s0703_01);
			backdrops.push_back(&bn::regular_bg_items::s0703_01);
		}
		else if (strcmp(n[pos].text.c_str(), "S07:04") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0704);
			backdrops.push_back(&bn::regular_bg_items::s0704_01);
			backdrops.push_back(&bn::regular_bg_items::s0704_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S07:05") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0705);
			backdrops.push_back(&bn::regular_bg_items::s0705_01);
			backdrops.push_back(&bn::regular_bg_items::s0705_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S07:06") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0706);
			backdrops.push_back(&bn::regular_bg_items::s0706_01);
			backdrops.push_back(&bn::regular_bg_items::s0706_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S07:07") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0707);
			backdrops.push_back(&bn::regular_bg_items::s0707_01);
			backdrops.push_back(&bn::regular_bg_items::s0707_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S07:08") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0708);
			backdrops.push_back(&bn::regular_bg_items::s0708_01);
			backdrops.push_back(&bn::regular_bg_items::s0708_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S07:09") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0709);
			backdrops.push_back(&bn::regular_bg_items::s0709_01);
			backdrops.push_back(&bn::regular_bg_items::s0709_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S07:10") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0710);
			backdrops.push_back(&bn::regular_bg_items::s0710_01);
			backdrops.push_back(&bn::regular_bg_items::s0710_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S07:11") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0711);
			backdrops.push_back(&bn::regular_bg_items::s0711_01);
			backdrops.push_back(&bn::regular_bg_items::s0711_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S07:12") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0712);
			backdrops.push_back(&bn::regular_bg_items::s0712_01);
			backdrops.push_back(&bn::regular_bg_items::s0712_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S07:13") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0713);
			backdrops.push_back(&bn::regular_bg_items::s0713_01);
			backdrops.push_back(&bn::regular_bg_items::s0713_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S07:14") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0714);
			backdrops.push_back(&bn::regular_bg_items::s0714_01);
			backdrops.push_back(&bn::regular_bg_items::s0714_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S07:15") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0715);
			backdrops.push_back(&bn::regular_bg_items::s0715_01);
			backdrops.push_back(&bn::regular_bg_items::s0715_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S07:16") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0716);
			backdrops.push_back(&bn::regular_bg_items::s0716_01);
			backdrops.push_back(&bn::regular_bg_items::s0716_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S07:17") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0717_01);
			backdrops.push_back(&bn::regular_bg_items::s0717_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S07:18") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0718);
			backdrops.push_back(&bn::regular_bg_items::s0718_01);
			backdrops.push_back(&bn::regular_bg_items::s0718_01);
		}
		else if (strcmp(n[pos].text.c_str(), "S08:01") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0801);
			backdrops.push_back(&bn::regular_bg_items::s0801_01);
			backdrops.push_back(&bn::regular_bg_items::s0801_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S08:02") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0802);
			backdrops.push_back(&bn::regular_bg_items::s0802_01);
			backdrops.push_back(&bn::regular_bg_items::s0802_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S08:03") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0803);
			backdrops.push_back(&bn::regular_bg_items::s0803_01);
			backdrops.push_back(&bn::regular_bg_items::s0803_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S08:04") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0804);
			backdrops.push_back(&bn::regular_bg_items::s0804_01);
			backdrops.push_back(&bn::regular_bg_items::s0804_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S08:05") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0805);
			backdrops.push_back(&bn::regular_bg_items::s0805_01);
			backdrops.push_back(&bn::regular_bg_items::s0805_01);
		}
		else if (strcmp(n[pos].text.c_str(), "S08:06") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0806);
			backdrops.push_back(&bn::regular_bg_items::s0806_01);
			backdrops.push_back(&bn::regular_bg_items::s0806_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S08:07") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0807);
			backdrops.push_back(&bn::regular_bg_items::s0807_01);
			backdrops.push_back(&bn::regular_bg_items::s0807_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S09:01") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0901);
			backdrops.push_back(&bn::regular_bg_items::s0901_01);
			backdrops.push_back(&bn::regular_bg_items::s0901_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S09:02") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0902);
			backdrops.push_back(&bn::regular_bg_items::s0902_01);
			backdrops.push_back(&bn::regular_bg_items::s0902_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S09:03") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0903);
			backdrops.push_back(&bn::regular_bg_items::s0903_01);
			backdrops.push_back(&bn::regular_bg_items::s0903_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S09:04") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0904);
			backdrops.push_back(&bn::regular_bg_items::s0904_01);
			backdrops.push_back(&bn::regular_bg_items::s0904_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S09:05") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0905);
			backdrops.push_back(&bn::regular_bg_items::s0905_01);
			backdrops.push_back(&bn::regular_bg_items::s0905_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S09:06") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0906);
			backdrops.push_back(&bn::regular_bg_items::s0906_01);
			backdrops.push_back(&bn::regular_bg_items::s0906_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S09:08") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0908);
			backdrops.push_back(&bn::regular_bg_items::s0908_01);
			backdrops.push_back(&bn::regular_bg_items::s0908_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S09:09") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0909);
			backdrops.push_back(&bn::regular_bg_items::s0909_01);
			backdrops.push_back(&bn::regular_bg_items::s0909_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S09:10") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0910);
			backdrops.push_back(&bn::regular_bg_items::s0910_01);
			backdrops.push_back(&bn::regular_bg_items::s0910_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S09:11") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0911);
			backdrops.push_back(&bn::regular_bg_items::s0911_01);
			backdrops.push_back(&bn::regular_bg_items::s0911_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S09:12") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0912);
			backdrops.push_back(&bn::regular_bg_items::s0912_01);
			backdrops.push_back(&bn::regular_bg_items::s0912_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S09:13") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0913);
			backdrops.push_back(&bn::regular_bg_items::s0913_01);
			backdrops.push_back(&bn::regular_bg_items::s0913_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S09:14") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0914);
			backdrops.push_back(&bn::regular_bg_items::s0914_01);
			backdrops.push_back(&bn::regular_bg_items::s0914_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S09:15") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0915);
			backdrops.push_back(&bn::regular_bg_items::s0915_01);
			backdrops.push_back(&bn::regular_bg_items::s0915_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S09:16") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0916);
			backdrops.push_back(&bn::regular_bg_items::s0916_01);
			backdrops.push_back(&bn::regular_bg_items::s0916_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S09:17") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0917);
			backdrops.push_back(&bn::regular_bg_items::s0917_01);
			backdrops.push_back(&bn::regular_bg_items::s0917_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S09:18") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s0918);
			backdrops.push_back(&bn::regular_bg_items::s0918_01);
			backdrops.push_back(&bn::regular_bg_items::s0918_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S10:01") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1001);
			backdrops.push_back(&bn::regular_bg_items::s1001_01);
			backdrops.push_back(&bn::regular_bg_items::s1001_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S10:02") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1002);
			backdrops.push_back(&bn::regular_bg_items::s1002_01);
			backdrops.push_back(&bn::regular_bg_items::s1002_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S10:03") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1003);
			backdrops.push_back(&bn::regular_bg_items::s1003_01);
			backdrops.push_back(&bn::regular_bg_items::s1003_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S10:04") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1004);
			backdrops.push_back(&bn::regular_bg_items::s1004_01);
			backdrops.push_back(&bn::regular_bg_items::s1004_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S10:05") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1005);
			backdrops.push_back(&bn::regular_bg_items::s1005_01);
			backdrops.push_back(&bn::regular_bg_items::s1005_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S10:06") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1006);
			backdrops.push_back(&bn::regular_bg_items::s1006_01);
			backdrops.push_back(&bn::regular_bg_items::s1006_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S10:07") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1007);
			backdrops.push_back(&bn::regular_bg_items::s1007_01);
			backdrops.push_back(&bn::regular_bg_items::s1007_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S10:08") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1008);
			backdrops.push_back(&bn::regular_bg_items::s1008_01);
			backdrops.push_back(&bn::regular_bg_items::s1008_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S10:09") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1009);
			backdrops.push_back(&bn::regular_bg_items::s1009_01);
			backdrops.push_back(&bn::regular_bg_items::s1009_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S10:10") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1010);
			backdrops.push_back(&bn::regular_bg_items::s1010_01);
			backdrops.push_back(&bn::regular_bg_items::s1010_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S10:11") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1011);
			backdrops.push_back(&bn::regular_bg_items::s1011_01);
			backdrops.push_back(&bn::regular_bg_items::s1011_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S10:12") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1012);
			backdrops.push_back(&bn::regular_bg_items::s1012_01);
			backdrops.push_back(&bn::regular_bg_items::s1012_02);
		}

		else if (strcmp(n[pos].text.c_str(), "S11:01") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1101);
			backdrops.push_back(&bn::regular_bg_items::s1101_01);
			backdrops.push_back(&bn::regular_bg_items::s1101_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S11:02") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1102);
			backdrops.push_back(&bn::regular_bg_items::s1102_01);
			backdrops.push_back(&bn::regular_bg_items::s1102_02);
		}
		else if (strcmp(n[pos].text.c_str(), "S11:03") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::s1103);
			backdrops.push_back(&bn::regular_bg_items::s1103_01);
			backdrops.push_back(&bn::regular_bg_items::s1103_02);
		}

		else if (strcmp(n[pos].text.c_str(), "S_STV_01") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::scout_tv_01);
			backdrops.push_back(&bn::regular_bg_items::scout_tv_01_01);
		}
		else if (strcmp(n[pos].text.c_str(), "S_STV_02") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::scout_tv_02);
			backdrops.push_back(&bn::regular_bg_items::scout_tv_02_01);
		}
		else if (strcmp(n[pos].text.c_str(), "S_STV_03") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::scout_tv_03);
			backdrops.push_back(&bn::regular_bg_items::scout_tv_03_01);
		}
		else if (strcmp(n[pos].text.c_str(), "S_STV_04") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::scout_tv_04);
			backdrops.push_back(&bn::regular_bg_items::scout_tv_04_01);
		}
		else if (strcmp(n[pos].text.c_str(), "S_DOCKS") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::bg_docks);

			// End dialogue
		}
		else if (strcmp(n[pos].text.c_str(), "BG:CINEMINT") == 0)
		{
			backdrops.clear();
			backdrops.push_back(&bn::regular_bg_items::cinemint_01);
			backdrops.push_back(&bn::regular_bg_items::cinemint_02);
			backdrops.push_back(&bn::regular_bg_items::cinemint_03);
			backdrops.push_back(&bn::regular_bg_items::cinemint_04);
			backdrops.push_back(&bn::regular_bg_items::cinemint_03);

			// End dialogue
		}
		else if (strcmp(n[pos].text.c_str(), "COM: Endscene") == 0 || bn::keypad::b_held())
		{
			cont = false;

			// Handle sprite/dialogue
		}
		else
		{

			// Process initial transparency states
			if (n[pos].img != 0)
			{
				if (n[pos].left)
				{
					if (n[pos].transition || n[pos].img == -1)
						chari_l.set_visible(false);
					if (!chari_l.visible() && n[pos].img != -1)
					{
						chari_r.set_blending_enabled(false);
						chari_l.set_blending_enabled(true);
						bn::blending::set_transparency_alpha(0);
						chari_l.set_x(-50);
						chari_l.set_visible(true);
					}
					set_sprite(chari_l, n[pos].img);
				}
				else
				{
					if (n[pos].transition || n[pos].img == -1)
						chari_r.set_visible(false);
					if (!chari_r.visible() && n[pos].img != -1)
					{
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
			bn::string<42> line1;
			bn::string<42> line3;
			bn::string<42> line4;
			bn::string<42> line5;
			bn::string<42> line6;

			for (int offset = 0; offset < 33; offset++)
				if (n[pos].text.size() > offset)
					line1.push_back(n[pos].text.at(offset));
			for (int offset = 33; offset < 66; offset++)
				if (n[pos].text.size() > offset)
					line3.push_back(n[pos].text.at(offset));
			for (int offset = 66; offset < 99; offset++)
				if (n[pos].text.size() > offset)
					line4.push_back(n[pos].text.at(offset));
			for (int offset = 99; offset < 132; offset++)
				if (n[pos].text.size() > offset)
					line5.push_back(n[pos].text.at(offset));
			for (int offset = 132; offset < 165; offset++)
				if (n[pos].text.size() > offset)
					line6.push_back(n[pos].text.at(offset));

			text_line.generate(-108, 21, line1, text_sprite0);
			for (short int t = 0; t < text_sprite0.size(); t++)
			{
				text_sprite0.at(t).set_visible(false);
			}
			bn::core::update();

			text_line.generate(-108, 33, line3, text_sprite2);
			for (short int t = 0; t < text_sprite2.size(); t++)
			{
				text_sprite2.at(t).set_visible(false);
			}
			// bn::core::update();

			text_line.generate(-108, 45, line4, text_sprite3);
			for (short int t = 0; t < text_sprite3.size(); t++)
			{
				text_sprite3.at(t).set_visible(false);
			}
			bn::core::update();

			text_line.generate(-108, 57, line5, text_sprite4);
			for (short int t = 0; t < text_sprite4.size(); t++)
			{
				text_sprite4.at(t).set_visible(false);
			}
			// bn::core::update();

			text_line.generate(-108, 69, line6, text_sprite5);
			for (short int t = 0; t < text_sprite5.size(); t++)
			{
				text_sprite5.at(t).set_visible(false);
			}
			bn::core::update();

			// Process visual effects
			short int ticker = 0;
			short int ticker_delay = 0;

			cascade_id = 0;
			short int cascade_offset = 0;
			short int c_x = cascade_bg.value().x().integer();
			short int c_y = cascade_bg.value().y().integer();
			while (!bn::keypad::a_pressed() && !bn::keypad::b_held())
			{

				a_button.set_y(lerp(a_button.y(), -50, 0.2));

				// Handle moving backgrounds
				if (backdrops.size() > 0)
				{
					cascade_bg.reset();
					cascade_bg = backdrops.at(cascade_id)->create_bg(c_x, c_y);
					if (backdrops.size() > 1)
					{
						cascade_offset++;
						if (cascade_offset > 8)
						{
							cascade_offset = 0;
							cascade_id++;
							if (cascade_id > backdrops.size() - 1)
								cascade_id = 0;
						}
					}
				}

				// Handle text ticker
				if (ticker < 160)
				{
					if (ticker_delay == 0)
					{
						short int ticked = ticker % 32;
						if (ticker >= 0 && ticker < 32)
						{
							if (text_sprite0.size() > ticked)
							{
								text_sprite0.at(ticked).set_visible(true);
								bn::sound_items::click.play();
							}
							else
							{
								ticker = 31;
							}
						}
						if (ticker >= 32 && ticker < 64)
						{
							if (text_sprite2.size() > ticked)
							{
								text_sprite2.at(ticked).set_visible(true);
								bn::sound_items::click.play();
							}
							else
							{
								ticker = 63;
							}
						}
						if (ticker >= 64 && ticker < 96)
						{
							if (text_sprite3.size() > ticked)
							{
								text_sprite3.at(ticked).set_visible(true);
								bn::sound_items::click.play();
							}
							else
							{
								ticker = 95;
							}
						}
						if (ticker >= 96 && ticker < 128)
						{
							if (text_sprite4.size() > ticked)
							{
								text_sprite4.at(ticked).set_visible(true);
								bn::sound_items::click.play();
							}
							else
							{
								ticker = 127;
							}
						}
						if (ticker >= 128 && ticker < 160)
						{
							if (text_sprite5.size() > ticked)
							{
								text_sprite5.at(ticked).set_visible(true);
								bn::sound_items::click.play();
							}
							else
							{
								ticker = 160;
							}
						}
						ticker++;
					}
					ticker_delay = (ticker_delay + 1) % 2;
				}

				// Move in from side
				if (chari_l.visible() && chari_l.x().integer() < -40)
					chari_l.set_x(chari_l.x() + 1);
				if (chari_r.visible() && chari_r.x().integer() > 40)
					chari_r.set_x(chari_r.x() - 1);

				// Handle transparency
				if (bn::blending::transparency_alpha().to_double() + 0.1 <= 0.9)
				{
					bn::blending::set_transparency_alpha(bn::blending::transparency_alpha().to_double() + 0.1);
				}
				else
				{
					bn::blending::set_transparency_alpha(0.95);
					chari_l.set_blending_enabled(false);
					chari_r.set_blending_enabled(false);
				}

				bn::core::update();
			}

			// Handle weirdness
			ticker = 160;

			for (short int t = 1; t < 3; t++)
			{
				bn::core::update();
			}
		}

		// Increment location
		pos++;
	}

	// Process visual effects
	while (bg_alpha > 0.1)
	{
		bg_alpha -= 0.1;
		if (bg_alpha < 0)
			bg_alpha = 0;
		bn::blending::set_transparency_alpha(bg_alpha);
		bn::core::update();
	}

	dg_bg1.set_visible(false);
	dg_bg2.set_visible(false);
	bn::blending::set_transparency_alpha(1);

	bn::core::update();
}

void dialogue_page_lite(line n[32])
{

	// Variable initialization
	bn::sprite_text_generator text_line(common::variable_8x16_sprite_font);
	bn::sprite_ptr a_button = bn::sprite_items::a_button.create_sprite(-90, -72, (globals->all_save.language * 2) + 1);
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

	while (cont)
	{

		// End dialogue
		if (strcmp(n[pos].text.c_str(), "COM: Endscene") == 0)
		{
			cont = false;

			// Handle sprite/dialogue
		}
		else
		{

			// SFX
			bn::sound_items::pop.play((std_rnd(100)) / 100);

			// Fresh init
			bn::vector<bn::sprite_ptr, 33> text_sprite0;
			bn::vector<bn::sprite_ptr, 33> text_sprite1;
			bn::vector<bn::sprite_ptr, 33> text_sprite2;
			bn::string<33> line0;
			bn::string<33> line1;
			bn::string<33> line2;

			// Set up arrow
			auto arrow = bn::sprite_items::arrow.create_sprite(-108, 69);
			if (n[pos].move_to == 0)
			{
				arrow.set_visible(false);
			}

			for (int offset = 0; offset < 33; offset++)
			{
				if (n[pos].text.size() > offset)
					line0.push_back(n[pos].text.at(offset));
			}
			for (int offset = 33; offset < 66; offset++)
			{
				if (n[pos].text.size() > offset)
					line1.push_back(n[pos].text.at(offset));
			}
			for (int offset = 66; offset < 99; offset++)
				if (n[pos].text.size() > offset)
					line2.push_back(n[pos].text.at(offset));
			BN_LOG(n[pos].text);
			BN_LOG("0 ", line0);
			BN_LOG("1 ", line1);
			BN_LOG("2 ", line2);

			text_line.generate(-108, 45, line0.c_str(), text_sprite0);
			text_line.generate(-108, 57, line1.c_str(), text_sprite1);

			if (n[pos].move_to == 0)
			{
				text_line.generate(-108, 69, line2.c_str(), text_sprite2);
			}
			else
			{
				text_line.generate(-92, 69, line2.c_str(), text_sprite2);
			}

			if (!enoki_spoken && strncmp(line0.c_str(), "ENOKI", 5) == 0)
			{
				bn::sound_items::enoki_hey.play();
				enoki_spoken = true;
			}

			if (!maple_spoken && strncmp(line0.c_str(), "MAPLE", 5) == 0)
			{
				bn::sound_items::maple_hey_01.play();
				maple_spoken = true;
			}

			if (!aaron_spoken && strncmp(line0.c_str(), "AARON", 5) == 0)
			{
				if (pos < 2)
				{
					bn::sound_items::aaron_hey_01.play();
				}
				else
				{
					bn::sound_items::aaron_hey_02.play();
				}
				aaron_spoken = true;
			}

			if (!scout_spoken && strncmp(line0.c_str(), "SCOUT", 5) == 0)
			{
				bn::sound_items::scout_hey_01.play();
				scout_spoken = true;
			}

			if (!vee_spoken && strncmp(line0.c_str(), "OLIVIER", 7) == 0)
			{
				bn::sound_items::vee_hey_01.play();
				vee_spoken = true;
			}

			if (!el_spoken && strncmp(line0.c_str(), "ELEANOR", 7) == 0)
			{
				bn::sound_items::eleanor_hey_01.play();
				el_spoken = true;
			}

			if (!diana_spoken && strncmp(line0.c_str(), "DIANA", 5) == 0)
			{
				bn::sound_items::diana_hey_01.play();
				diana_spoken = true;
			}

			if (!guy_spoken && strncmp(line0.c_str(), "GUY", 3) == 0)
			{
				bn::sound_items::guy_hey_01.play();
				guy_spoken = true;
			}

			// Process visual effects
			while (!(bn::keypad::a_pressed()))
			{
				a_button.set_y(lerp(a_button.y(), -50, 0.2));

				// Handle arrow
				if (arrow.visible())
				{
					if (bn::keypad::left_pressed())
					{
						a_dir = false;
						bn::sound_items::cnaut.play();
					}

					if (bn::keypad::right_pressed())
					{
						a_dir = true;
						bn::sound_items::cnaut.play();
					}

					if (!a_dir)
					{
						arrow.set_x(lerp(arrow.x(), -108, 0.4));
						arrow.set_horizontal_flip(false);
					}
					else
					{
						arrow.set_x(lerp(arrow.x(), 108, 0.4));
						arrow.set_horizontal_flip(true);
					}
				}

				if (bg_alpha < 0.9)
				{
					bg_alpha += 0.05;
					bn::blending::set_transparency_alpha(bg_alpha);
				}
				else
				{
					bg_alpha = 1;
				}

				bn::core::update();

				if (bn::keypad::b_held())
				{
					for (short int t = 0; t < 2; t++)
					{
						bn::core::update();
					}
					break;
				}
			}

			if (n[pos].move_to > 0 && a_dir)
			{
				pos = n[pos].move_to;
			}

			bn::core::update();
		}

		// Increment location
		pos++;
	}

	// Process visual effects
	while (bg_alpha > 0.1)
	{
		bg_alpha -= 0.1;
		if (bg_alpha < 0)
			bg_alpha = 0;
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

int exec_dialogue(int x, int checkpoint = 0)
{

	constexpr int n = -1;

	if (globals->all_save.language == 0)
	{
		switch (x)
		{
		case 0:
		{
			line lc[32] = {
				{fals, true, 0, "BG: 1"},
				{fals, true, 0, "S01:01"},
				{fals, true, 0, "4:15 AM                          January 1st, 2000                Providence of Nord Louisiane,    La Republique Laurentides"},
				{fals, true, 0, "S01:02"},
				{fals, true, 0, "                                 AHHHHG.                          I've been driving for hours.     My right foot's asleep, and the  left one isn't too far behind."},
				{fals, true, 0, "S01:03"},
				{fals, true, 0, "                                 Look at that gumbo.              It has to be cold by now.        I can't believe they wanted me   to bring the food."},
				{fals, true, 0, "S01:04"},
				{fals, true, 0, "                                 Y'know....                       If I don't see that castle in    fifteen minutes, I might just    head back."},
				{fals, true, 0, "                                 At least the drive was nice,     I guess."},
				{fals, true, 0, "                                 Okay, I give up. There's no way  that I'm gonna-"},
				{fals, true, 0, "S01:06"},
				{fals, true, 0, "                                 .....Oh."},
				{fals, true, 0, "                                 I.. can't decide if I'm          relieved or disappointed."},
				{fals, true, 0, "BG: fadeout"},
				{fals, true, 0, "S01:07"},
				{fals, true, 0, "                                 *knock*                          *knock*                          *knock*"},
				{fals, true, 0, "S01:08"},
				{fals, true, 0, "                                 I wonder if they can even        hear me in there... This place   looks huge."},
				{fals, true, 0, "                                 '.....coming!'"},
				{fals, true, 0, "S01:09"},
				{fals, true, 0, "BG: 0"},
				{fals, true, 0, "                                 Hey, Maple!!                     C'mon in, allez!"},
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
				{true, fals, 1, "MAPLE                            Alright, so where do I plug this crock-pot in at? Are there any   plugs?"},
				{fals, fals, 1, "MAPLE                            I take it that I'm late enough   y'all probably already ate       something else."},
				{fals, true, 9, "ENOKI                            Well, we've got an outhouse,     but that's the only place with   electricity. And yeah, we got    some chicken."},
				{fals, true, 8, "ENOKI                            We missed you earlier!"},
				{fals, fals, 5, "MAPLE                            Well I'm finally here, now. So,  where is- Oh! Salut, Aaron."},
				{true, true, 10, "AARON                            Bonsoir! Or Bonjour more like, I guess, it's technically morning, isn't it? I'm just glad you got  here. Happy new millenium!"},
				{fals, fals, 3, "MAPLE                            Happy new millenium! Y'all reallyare in the middle of nowhere, youknow that?"},
				{true, true, 12, "DEL                              Maple! You're here! Happy 2000!"},
				{fals, fals, 5, "MAPLE                            Delphine Thibodeaux!             My goodness it's been... what, a year? Salut!"},
				{fals, true, 13, "DEL                              Hey, girl! Glad you're here -    Don't worry, we've been waiting  to break out the wine and        eclairs until you showed up."},
				{fals, true, 12, "DEL                              We're all boring adults, though, so no promises about how late we would have stayed up for you."},
				{true, true, 7, "ENOKI                            So Maple, what have you been up  to lately? Have we even talked   since the wedding?! I missed my  best friend!"},
				{fals, fals, 2, "MAPLE                            Surely your husband's been       keeping you busy, I suppose."},
				{true, true, 10, "AARON                            Well, we're obviously living in acastle now, so that's been an    adventure."},
				{true, true, 7, "ENOKI                            I am a princess."},
				{fals, fals, 2, "MAPLE                            It takes a little more than just a castle to be a princess."},
				{fals, true, 8, "ENOKI                            I'm a duchess?"},
				{fals, fals, 4, "MAPLE                            I- uhm...                        Hmm...                           You know what?                   It's too late for this."},
				{fals, fals, 2, "MAPLE                            Anyway, I've been alright, I've  only got one semester left, then I'll be a school teacher.  Then? I don't know."},
				{true, true, 10, "AARON                            Still trying this teacher thing, huh? Even though you've told me  a million times you'd rather be  anything but a teacher?"},
				{fals, true, 11, "AARON                            Are there no degrees for people  who can shoot fire out of their  hands?"},
				{fals, fals, 4, "MAPLE                            ...None I want, at least."},
				{fals, true, 10, "AARON                            Well, a teacher with fire magic  sounds pretty cool to me."},
				{true, true, 8, "ENOKI                            *yawn*                           Goodness, I'm sleepy. Hey, how   about we all go to bed and catch up in the morning?"},
				{fals, true, 7, "ENOKI                            Hey Maple, you wanna have like   a sleepover? Like we can pretend we're college roommates again?"},
				{fals, fals, 2, "MAPLE                            I mean... Sure, I guess."},
				{fals, true, n, "ENOKI                            Goodnight, Del!                  Hey, Aaron, see ya tomorrow?     Bright 'n early?"},
				{fals, true, 0, "AARON                            Sure thing, Noke-noke.                                            *kiss*"},
				{fals, fals, 3, "MAPLE                            I am never going to get used to  that."},
				{true, true, 9, "ENOKI                            Alright, grab your bag and I'll  show you where we're staying.    Allons-y!"},
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
				{true, true, 0, "MAPLE                            Wow.. It's sort of chilly in     here, isn't it?"},
				{true, true, 0, "ENOKI                            Well silly, why'd ya wear a tank top and shorts in the middle of  December? Can't ya just light a  fire?"},
				{true, true, 0, "BG: 2"},
				{true, true, 0, "S01:10"},
				{true, true, 0, "MAPLE                            So, how long are you two going tostay here? You can't just stay   thirty miles from civilization   without electricity forever."},
				{true, true, 0, "S01:11"},
				{true, true, 0, "ENOKI                            We're happy, so we think a long  time."},
				{true, true, 0, "MAPLE                            I mean, what does Aaron think of all this? The Aaron I remember   growing up would be a little more...responsible."},
				{true, true, 0, "ENOKI                            I don't wanna sound rude but...  Aren't you guys used to growing  up in places like, er, in a car?"},
				{true, true, 0, "MAPLE                            Enoki, we all know you're rich,  no need to flaunt it."},
				{true, true, 0, "ENOKI                            But didn't you literally grow up in a car? I mean, compared to    that, a castle is pretty nice,   right?"},
				{true, true, 0, "MAPLE                            It just seems.. rash. I don't    mean to take the fun out of it,  but I can't help but think this  was a really, really bad idea."},
				{true, true, 0, "ENOKI                            Coming from the girl who got     embarrassed of her grades        freshman year and decided to justup and run away from college."},
				{true, true, 0, "S01:10"},
				{true, true, 0, "MAPLE                            Oh come on, that was your idea   first."},
				{true, true, 0, "S01:11"},
				{true, true, 0, "ENOKI                            Hey, I'll take it!! '97... Yeah, that was one of the best years   of my life, easy."},
				{true, true, 0, "ENOKI                            So, after college, you got any   plans for where you wanna live?"},
				{true, true, 0, "MAPLE                            I'll figure something out."},
				{true, true, 0, "ENOKI                            Aaron and I were chatting and,   y'know, there's a school not too far off you could teach at,      maybe you could.. y'know.."},
				{true, true, 0, "MAPLE                            Absolutely NOT. I'll make sure   to get myself a real adult       apartment."},
				{true, true, 0, "MAPLE                            When you get tired of this place,maybe you can move in with me."},
				{true, true, 0, "S01:12"},
				{true, true, 0, "ENOKI                            The kinda things you choose to befunny about Maple, it'll never   cease to amaze me."},
				{true, true, 0, "S01:11"},
				{true, true, 0, "ENOKI                            Hey- I'm feeling down and that's stupid! You wanna go on another  Maple and Enoki adventure like   old times?! "},
				{true, true, 0, "ENOKI                            Let's go explore the castle!!"},
				{true, true, 0, "MAPLE                            Hold up, you bought this castle  and hadn't explored it all first?"},
				{true, true, 0, "ENOKI                            Well duh, I'm taking my sweet    time with it -- it's a castle!   Allons-y, let's explore!"},
				{true, true, 0, "COM: Endscene"}};
			dialogue_page(lc);
			return 0;
			break;
		};

		case 3:
		{
			line lc[32] = {
				{fals, fals, 00, "BG: Moody"},
				{true, true, 30, "ENOKI                                                             I wanna explore the big          bookshelf room first!"},
				{true, fals, 02, "MAPLE                                                             Sure, whatever."},
				{fals, true, 31, "ENOKI                                                             I think you're gonna see why     when we get there."},
				{fals, true, 30, "ENOKI                                                             If you want me to lead,          just press 'B'."},
				{fals, fals, 03, "MAPLE                                                             ...Huh?"},
				{fals, true, 30, "ENOKI                                                             What?"},
				{fals, fals, 00, "COM: Endscene"}};
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
				{true, fals, 4, "..."},
				{true, true, 10, "AARON                            Bonjour! Did you sleep well?"},
				{fals, fals, 4, "MAPLE                            Yeah, it was ok I guess."},
				{true, true, 9, "ENOKI                            Bonjour! So.. We found something cool while you were sleeping, butyou've gotta promise you won't bemad."},
				{fals, fals, 4, "MAPLE                            You know I can't promise that."},
				{fals, true, 7, "ENOKI                            Remember that book you wanted me to get? Well, it's a world atlas!And we spotted something really  fun!"},
				{fals, true, 9, "ENOKI                            So, we found this island up in   Lake Superieur called Tremblay  Island!"},
				{fals, fals, 0, "MAPLE                            Aw, that's fun. I was afraid thatthere'd be some kind of.. catch."},
				{fals, true, 0, "ENOKI                            Well, we, uh- figured it'd be funif, well, the idea came from Del,so..."},
				{true, true, 12, "DEL                              Last time we talked, my cousin   Rufus was obsessed with starting his own tiny country."},
				{true, true, 11, "AARON                            There's work not too far out, so if we need to pick up supplies,  it shouldn't be very difficult."},
				{true, true, 7, "ENOKI                            With the money we could make     selling off the castle, and with your magic, we were thinking-"},
				{fals, fals, 3, "MAPLE                            WHOA WHOA WHOA,                  JUST HOLD UP FOR A MINUTE."},
				{fals, fals, 3, "MAPLE                            Are you seriously telling me thatyou're going to SELL this castle and move to this random island,"},
				{fals, fals, 3, "MAPLE                            All because it shares the same   last name as us?"},
				{fals, true, 9, "ENOKI                            As a bonus, we're thinking we're gonna secede from the Laurentidesand be our own country, too."},
				{fals, fals, 0, "MAPLE                            ...I..."},
				{fals, fals, 0, "MAPLE                            ..."},
				{fals, fals, 4, "MAPLE                            ...I'm going to need some time toprocess this."},
				{true, true, 10, "AARON                            It sounds insane, but we've gone over the details, and it seems   like this could actually happen."},
				{true, true, 9, "ENOKI                            I know we had that talk last     night, but.."},
				{fals, fals, 3, "MAPLE                            And then what's next?            What happens after you get bored of being your own little island?"},
				{fals, fals, 0, "MAPLE                            Do you want to be the Pope? The  Queen of France? Are you going towant your own planet?"},
				{fals, fals, 0, "MAPLE                            And for what it's worth you're   lucky enough that you'll probablyget it. But you know what?"},
				{fals, fals, 0, "MAPLE                            I'm going to settle in reality   with my *real* job and stay out  of starving to death on some     rock,"},
				{fals, fals, 0, "MAPLE                            Or worse, getting locked up in   federal prison for breaking some sort of weird law."},
				{fals, fals, 4, "MAPLE                            Look.... It's been fun, but I    need to go home. I'm done with   this."},
				{fals, fals, 0, "MAPLE                            Aaron, Enoki, Delphine, it's beenfun, but.... I need some time."},
				{true, true, 10, "AARON                            Are you sure? We can change the  subject, we were just talking.   We've got breakfast made if you  want some."},
				{fals, fals, 0, "MAPLE                            ..Alright, I'll stay a little    longer, but I do need to be      heading out soon."},
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
					{true, true, 0, "                                 Hmm, hmm hmm hmm...."},
					{true, true, 0, "                                 For goodness' sake, when is that pizza going to show up? Wasn't itsupposed to be here in under     twenty minutes?"},
					{true, true, 0, "                                 Have I checked my mail today? I  probably should go ahead and     check."},
					{true, true, 0, "S02:03"},
					{true, true, 0, "                                 Huh, what's this? From the       Tremblay household? I guess I    haven't heard from Aaron and     Enoki in a while."},
					{true, true, 0, "                                 Can't wait to read about how muchthey want to move in with me now."},
					{true, true, 0, "BG: fadeout"},
					{true, true, 0, "S02:04"},
					{true, true, 0, "                                             Hey, Maple!"},
					{true, true, 0, "S02:05"},
					{true, true, 0, "                                 Hold on, got this backwards."},
					{true, true, 0, "S02:04"},
					{true, true, 0, "BG: 0"},
					{true, true, 0, "                                             'Hey, Maple!'"},
					{true, true, 0, "                                       'We thought we'd send            you a quick letter to            give you an update.'"},
					{true, true, 0, "                                       'We sold the castle and          got to make enough to            buy a nice trailer home.'"},
					{true, true, 0, "                                       'However, that's not all-        we got it set up on our          new island!!'"},
					{true, true, 0, "S02:05"},
					{true, true, 0, "                                 I'm...                           That's it,                       I'm gonna kill 'em."},
					{true, true, 0, "S02:04"},
					{true, true, 0, "                                       'So, we've decided that          we're going to name it-..'"},
					{true, true, 0, "COM: Endscene"}};
				dialogue_page(lc);
			}
			else
			{
				line lc[32] = {
					{true, true, 0, "S02:02"},
					{true, true, 0, "BG: champ"},
					{true, true, 0, "                                 Hmm, hmm hmm hmm...."},
					{true, true, 0, "                                 For goodness' sake, when is that pizza going to show up? Wasn't itsupposed to be here in under     twenty minutes?"},
					{true, true, 0, "                                 Have I checked my mail today? I  probably should go ahead and     check."},
					{true, true, 0, "S02:03"},
					{true, true, 0, "                                 Huh, what's this? From the       Tremblay household? I guess I    haven't heard from Aaron and     Enoki in a while."},
					{true, true, 0, "                                 Can't wait to read about how muchthey want to move in with me now."},
					{true, true, 0, "BG: fadeout"},
					{true, true, 0, "S02:04"},
					{true, true, 0, "                                             Hey, Maple!"},
					{true, true, 0, "S02:05"},
					{true, true, 0, "                                 Hold on, got this backwards."},
					{true, true, 0, "S02:04"},
					{true, true, 0, "BG: 0"},
					{true, true, 0, "                                             'Hey, Maple!'"},
					{true, true, 0, "                                       'We thought we'd send            you a quick letter to            give you an update.'"},
					{true, true, 0, "                                       'We sold the castle and          got to make enough to            buy a nice trailer home.'"},
					{true, true, 0, "                                       'However, that's not all-        we got it set up on our          new island!!'"},
					{true, true, 0, "S02:05"},
					{true, true, 0, "                                 I'm...                           That's it,                       I'm gonna kill 'em."},
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
				{true, true, 0, "MAPLE                            Thunder my DOG,                  I have had ENOUGH,               they are ALL gonna get it!"},
				{true, true, 0, "MAPLE                            That's it! I'm at my limit.      They're going to DIE ALONE and   it's gonna be ALL their fault."},
				{true, true, 0, "MAPLE                            When they're tired of living thisisland fantasy, they're gonna    come here, and you know what I'llsay?"},
				{true, true, 0, "PIZZA GUY                        What will you say?"},
				{true, true, 0, "S02:07"},
				{true, true, 0, "MAPLE                            I'll say NO!"},
				{true, true, 0, "PIZZA GUY                        I dunno, living on an island by  yourself sounds kinda nice."},
				{true, true, 0, "MAPLE                            It's the nicest thing on the     planet, but they're gonna ruin itcos they're the most incompetent people on the planet!"},
				{true, true, 0, "PIZZA GUY                        If I were you, I'd go up and     teach 'em how to run the island."},
				{true, true, 0, "MAPLE                            I guess I'm gonna have to huh?   They're gonna die up there or    freeze to death!"},
				{true, true, 0, "MAPLE                            But I can't. I've gotta be the   better person and stay in adult  world."},
				{true, true, 0, "S02:06"},
				{true, true, 0, "PIZZA GUY                        Right, it's more important to    keep buying pizza and crying     yourself to sleep on your couch  like ya' do every night?"},
				{true, true, 0, "S02:08"},
				{true, true, 0, "MAPLE                            Is it really that obvious?"},
				{true, true, 0, "PIZZA GUY                        Yeah, we all take turns at the   place to see who'll get to       deliver to the 'sad pizza girl'."},
				{true, true, 0, "MAPLE                            Spectacular."},
				{true, true, 0, "S02:04"},
				{true, true, 0, "MAPLE                            Well, I suppose....              I mean, I don't exactly have the money to pay rent this month cos of all the pizza..."},
				{true, true, 0, "PIZZA GUY                        So... we gonna tip for today's   counseling session?"},
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
				{fals, true, 0, "6:40 PM                          March 20th, 2000                 The middle of Lake Superieur,   La Republique Laurentides(?)"},
				{fals, true, 0, "                                 So.. That's the island.          It's cute."},
				{fals, true, 0, "                                 I'm not sure if it's sell-every- thing-I-own cute, but..."},
				{fals, true, 0, "                                 J'suppose the thought of living  on an island and having no debt  is pretty cool."},
				{fals, true, 0, "S03:02"},
				{fals, true, 0, "MAPLE                            How much was the ferry again?    10 dollars?"},
				{fals, true, 0, "OLD SAILOR                       Aye lass, but aye've got one     warnin' fer ye befer ye dock."},
				{fals, true, 0, "MAPLE                            Oh dear, what?"},
				{fals, true, 0, "OLD SAILOR                       Keep yer wits about 'ye, ye neverknow who might go to stab ye."},
				{fals, true, 0, "MAPLE                            Will you take a 20?"},
				{fals, true, 0, "OLD SAILOR                       Aye, I can cut a 20."},
				{fals, true, 0, "COM: Endscene"}};
			dialogue_page(lc);
			return 0;
			break;
		}

		case 18:
		{
			line lc[32] = {
				{fals, fals, 0, "BG: Trailer Home"},
				{true, true, 22, "ENOKI                            Maple!! You came!"},
				{true, fals, 17, "MAPLE                            Yeah, this was my best option."},
				{true, true, 24, "AARON                            How was the trip? Did it take youlong?"},
				{fals, fals, 16, "MAPLE                            I took the train. It was like..  three days? It was fine. I read alot. My legs hurt."},
				{fals, true, 25, "AARON                            If you'd had let us know you werecoming sooner, you know we would have arranged for a plane trip!"},
				{fals, fals, 18, "MAPLE                            Doesn't matter. I'm already here.So, you go from castle to mobile home? Classy."},
				{true, true, 20, "ENOKI                            Dude, we moved outta the castle  in a 'normal home' and now you   want us to go back?"},
				{fals, fals, 16, "MAPLE                            No, I mean.. I guess I don't     know what I mean."},
				{true, true, 26, "AARON                            Well, we've only got a couch, butit's very comfortable. Feel free to make yourself at home."},
				{fals, true, 24, "AARON                            We've been working hard. I've    been chopping wood for the winterand Enoki's been-"},
				{true, true, 22, "ENOKI                            So, I, uh, I thought bringing    some bunnies here would make the island a little more alive,      y'know?"},
				{fals, true, 20, "ENOKI                            Turns out they started           multiplying so I spenda lotta    time tryna' keep em out of the   garden."},
				{true, true, 26, "AARON                            How do you feel about going into the caves a little north of here?"},
				{fals, true, 24, "AARON                            We've heard there's some gems in there that could be really       useful in earning us some money."},
				{fals, fals, 14, "MAPLE                            I guess that isn't too difficult."},
				{fals, fals, 15, "MAPLE                            Hey... thanks for the room."},
				{fals, true, 25, "AARON                            No problem."},
				{fals, true, 22, "ENOKI                            Oh, and if you haven't met Scout yet, he's pretty cool! He's down in the bunker thing outside."},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page(lc);
			return 0;
			break;
		}

		case 17:
		{
			line lc[32] = {
				{fals, fals, 0, "BG: Trailer Home"},
				{true, true, 22, "ENOKI                            Well.. First day is done! I thinktoday was a lot of fun."},
				{true, fals, 17, "MAPLE                            You know what? I think I agree.  This is the most interesting day I've had in a while."},
				{true, true, 24, "AARON                            Ready to change your mind about  this having been a bad idea?"},
				{fals, fals, 16, "MAPLE                            I've only been here a day, I'll  give it some time before I make  my final judgment."},
				{fals, true, 25, "AARON                            Well, we're happy to have you.   I'm sorry, we only have a couch, but I'm working on a new home."},
				{fals, fals, 18, "MAPLE                            Oh, I slept on my couch back at  my old apartment all the time.   No need to worry."},
				{true, true, 20, "ENOKI                            Aw, you slept on a couch?"},
				{fals, fals, 16, "MAPLE                            It was a really nice couch."},
				{true, true, 26, "AARON                            Anyway, we're gonna get some     sleep. I've been chopping wood   all day and I'm tired."},
				{fals, true, 24, "AARON                            See you tomorrow?"},
				{true, true, 22, "ENOKI                            I'm sure I'll find more stuff to do!"},
				{fals, fals, 15, "MAPLE                            Thanks again. I'll do my best to not be a butt about all this.    Goodnight, y'all."},
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
				{fals, fals, 0, "                                 Ugh.. My head.                   Why can't I sleep?"},
				{fals, fals, 0, "                                 Aren't you supposed to be able tosleep easier after a long day of travel and manual labor?"},
				{fals, fals, 0, "                                 And where's that light coming    from outside? Probably Scout or  something."},
				{fals, fals, 0, "                                 Maybe I should go on a walk and  check it out."},
				{fals, fals, 0, "S04:02"},
				{fals, fals, 0, "                                 What the-                        is that a Mons d'Plonj? Is he    writing something?"},
				{fals, fals, 0, "                                 I guess I should go check it out.Before something bad happens."},
				{fals, fals, 0, "S04:03"},
				{fals, fals, 0, "                                 Hmmm, hmmm... hmmm...."},
				{fals, fals, 0, "S04:04"},
				{fals, fals, 0, "MAPLE                            HEY! IDENTIFY YOURSELF, OR I'LL  BURN YOUR FACE OFF!"},
				{fals, fals, 0, "S04:05"},
				{fals, fals, 0, "SF: Rufus Squeak"},
				{fals, fals, 0, "                                 AHHHH?!"},
				{fals, fals, 0, "                                 AH, UH.. UH, RUFUS!              RUFUS THIBODEAUX!"},
				{fals, fals, 0, "                                 DON'T BURN MY FACE OFF, I NEED   THAT!"},
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
				{fals, fals, 0, "MAPLE                            Oh, so you're /that/ Rufus? Del'scousin, right? I'm Maple."},
				{fals, fals, 0, "RUFUS                            Oh, you're the fire elf, right?  Wish I knew that earlier when I  was trying to get this fire      started."},
				{fals, fals, 0, "MAPLE                            What are you doing here?"},
				{fals, fals, 0, "RUFUS                            Just checking things out. I've   got my eye on the Bill & Jim     Islands next door."},
				{fals, fals, 0, "RUFUS                            I really like the idea of just   having my own place and not      having to talk to anyone."},
				{fals, fals, 0, "RUFUS                            I'm just worried this whole      'private island' thing is...     kind of foolhardy."},
				{fals, fals, 0, "RUFUS                            Everyone this close to Quebec    speaks with that annoying accent,too."},
				{fals, fals, 0, "MAPLE                            That's what I was afraid of, too.Enoki is great, but that accent  wears on me sometimes."},
				{fals, fals, 0, "MAPLE                            I'm starting to hear a little    Quebec in Aaron's voice, too.    It bothers me."},
				{fals, fals, 0, "MAPLE                            So what are you writing?"},
				{fals, fals, 0, "RUFUS                            ...                              You're going to think it's       dumb. It's a drawing."},
				{fals, fals, 0, "MAPLE                            Look, I just sold everything I   owned to move to this stupid     island, your drawing isn't dumb."},
				{fals, fals, 0, "RUFUS                            ...Okay, it's a frog. I saw this picture of a frog when I was a   kid, and I don't know why, but itmakes me nostalgic."},
				{fals, fals, 0, "RUFUS                            I can't quite remember what it   looked like though, so I keep    trying. I don't know why but it'ssomething I just have to do."},
				{fals, fals, 0, "MAPLE                            Yeah, that is pretty dumb, but   I think I get what you mean."},
				{fals, fals, 0, "MAPLE                            Hey, I know it's not my place to offer, but you got a place to    sleep? I know it's cold out, but we have a bathtub."},
				{fals, fals, 0, "RUFUS                            Oh it's fine, I'll be gone in themorning, I don't really want to  short interact with anyone else. You   seem reasonable, though."},
				{fals, fals, 0, "MAPLE                            You too. It was kind of nice to  find someone with any sense to   chat for a little while."},
				{fals, fals, 0, "S04:07"},
				{fals, fals, 0, "BG: fadeout"},
				{fals, fals, 0, "MAPLE                            You take care of yourself,       alright? Ravi de vous rencontrer,Rufus."},
				{fals, fals, 0, "RUFUS                            You too! Ravi de vous rencontrer,Maple."},
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
				{fals, fals, 0, "                                 Hey, y'all! Scout here.                                           It's that time again!"},
				{fals, fals, 0, "S_STV_02"},
				{fals, fals, 0, "                                 It's exciting to finally have a  real audience, ladies and        gentlemen. Er.. gentleman."},
				{fals, fals, 0, "                                 It's April 1st, and you know     what that means!"},
				{fals, fals, 0, "                                 We've had Maple Tremblay come    move into the island for a whole day, now! Time flies, man."},
				{fals, fals, 0, "                                 That's a, uh, joke..             Cuz it's April 1st, she's been   here a month now.."},
				{fals, fals, 0, "                                 I'll just, uh, move on.. So..    ..Right! So I finally found out  my computer password!            That's good."},
				{fals, fals, 0, "                                 Oh, right- Right, the most       important bit. We have three new people moving into the village!"},
				{fals, fals, 0, "                                 I'm not sure we'll be able to    find any new potential islanders from Craigslist, though."},
				{fals, fals, 0, "                                 They're named Diana, Eleanor, andOlivier, and they're moving into the new cabin to the northwest."},
				{fals, fals, 0, "                                 Olivier has a greenhose up north,and Diana is actually an aspiringsailor! She'll be taking over    boat piloting."},
				{fals, fals, 0, "                                 So just make sure to give them a warm welcome."},
				{fals, fals, 0, "S_STV_01"},
				{fals, fals, 0, "                                 Alright, that's all..            I suppose I'll see y'all later   today. Thanks for tuning in!"},
				{fals, fals, 0, "S05:01"},
				{fals, fals, 0, "BG: fadeout"},
				{fals, fals, 0, "ENOKI                            Mmmmmm....                       I made popcorn, but I don't wannaget up to get it out of the      microwave."},
				{fals, fals, 0, "SF: Hey Maple"},
				{fals, fals, 0, "ENOKI                            Could you get it, Maple?         S'il te plait?"},
				{fals, fals, 0, "MAPLE                            Ugh, get a room already, you two."},
				{fals, fals, 0, "AARON                            Maple, this is our house."},
				{fals, fals, 0, "MAPLE                            Whatever."},
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
					{fals, fals, 0, "APRIL 1st, 2000 -                Scout log No. 48"},
					{fals, fals, 0, "Scout TV broadcast actually had  a few viewers this time. I hope  they liked it."},
					{fals, fals, 0, "Maybe next time I'll finally haveenough people that I can host my very first Scout Expo."},
					{fals, fals, 0, "This dirt stuff is going really  slowly, and I've got funding, so"},
					{fals, fals, 0, "I'm happy that I'm able to work  on stuff for fun."},
					{fals, fals, 0, "The 'bag of holding' isn't going to be done fora while, but the"},
					{fals, fals, 0, "prototype shows lots of promise."},
					{fals, fals, 0, "Maybe it could work for that     request Aaron gave me when he"},
					{fals, fals, 0, "wanted a way to race cars on the island."},
					{fals, fals, 0, "I could just stick a whole       racetrack in the pocket dimension"},
					{fals, fals, 0, "so we don't have to tear the     whole place up."},
					{fals, fals, 0, "Of course, it has to be perfect. If he gets stuck there..."},
					{fals, fals, 0, "Yeah, it's gotta be perfect."},
					{fals, fals, 0, "COM: Endscene"}};
				dialogue_page_lite(lc);
				return 0;
			}
			else
			{
				line lc[32] = {
					{fals, fals, 0, "MAY 1st, 2000 -                  Scout log No. 68"},
					{fals, fals, 0, "Two new villagers, one of them a little shady but Enoki seems to trust him."},
					{fals, fals, 0, "Apparently the other new guy is agreat chef, and his last name is Pizza."},
					{fals, fals, 0, "I've gotta figure out his real   name, my curiosity is gonna kill me."},
					{fals, fals, 0, "Rufus has been insufferable and  decided to interrupt Scout TV."},
					{fals, fals, 0, "I don't know if he's got some    kind of complex or something going on."},
					{fals, fals, 0, "Frankly enough, I'm a little     worried. Maybe I should check on him."},
					{fals, fals, 0, "Like, more than I'm supposed to."},
					{fals, fals, 0, "Apparently some company wants to store a bunch of gasoline over at his"},
					{fals, fals, 0, "island. I found out when they    accidentally took some here."},
					{fals, fals, 0, "What's he gonna do with all that gasoline? We may never know."},
					{fals, fals, 0, "Hopefully everyone does okay thismonth. I'm having a lot of fun."},
					{fals, fals, 0, "Scout out. Hehe, 'scout out'."},
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
					{fals, fals, 0, "MARCH 29th, 2000 -               Scout log No. 45 (deleted)"},
					{fals, fals, 0, "Gotta be the best day since I    moved over here from the Bill &"},
					{fals, fals, 0, "Jim islands. I do NOT miss those islands."},
					{fals, fals, 0, "That Rufus guy was a real pain inthe patookas. Constantly"},
					{fals, fals, 0, "yammering on about that          conspiracy stuff"},
					{fals, fals, 0, "I hope he's doing fine by himselfover there."},
					{fals, fals, 0, "But man, that Maple girl... whew.I think she smiled at me for the"},
					{fals, fals, 0, "first time since she came here."},
					{fals, fals, 0, "It probably doesn't mean anythingbut I haven't been able to sleep"},
					{fals, fals, 0, "just thinking about it."},
					{fals, fals, 0, "She hasn't ever said anything to me that wasn't making fun of me"},
					{fals, fals, 0, "but maybe she's just playing hardto get."},
					{fals, fals, 0, "I've seen how she talks to Aaron and Enoki, she's like that to    everyone."},
					{fals, fals, 0, "Mmm.. Maybe someday I'll figure  out how to talk to her. Maybe"},
					{fals, fals, 0, "I'll make something that really  impresses her."},
					{fals, fals, 0, "She's never acts like she's      short interested in anything but she   likes food and books."},
					{fals, fals, 0, "Maybe it's not the same kinds,   but I like food and books too."},
					{fals, fals, 0, "Maybe she just likes bigger guys though, and I'm shaped like      Grimace from McDonald's."},
					{fals, fals, 0, "That's it. I'll invent a way to  get me into shape."},
					{fals, fals, 0, "But she SMILED at me.            Now, it was because I tripped on"},
					{fals, fals, 0, "something, but maybe she thinks  I'm cute."},
					{fals, fals, 0, "I've gotta delete this log when  I'm done writing it."},
					{fals, fals, 0, "COM: Endscene"}};
				dialogue_page_lite(lc);
				return 0;
			}
			else
			{
				line lc[32] = {
					{fals, fals, 0, "APRIL 29th, 2000 -               Scout log No. 65 (deleted)"},
					{fals, fals, 0, "That new guy, man, I don't have aCHANCE with Maple."},
					{fals, fals, 0, "First off, apparently they know  each other? He calls her pizza   girl?"},
					{fals, fals, 0, "I'm done for. Completely. Might  as well give up."},
					{fals, fals, 0, "Maybe I should learn to cook     something for once."},
					{fals, fals, 0, "I definitely need to get into    shape, for real."},
					{fals, fals, 0, "I guess it wouldn't do well to   bring it up to Guy."},
					{fals, fals, 0, "Maybe I'll just work on myself   and let it go unless someone     brings it up."},
					{fals, fals, 0, "...Yeah."},
					{fals, fals, 0, "I need to stop writing these logsabout my lack of a love life."},
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
					{fals, fals, 0, "MARCH 30th, 2000 -               Scout log No. 46 (deleted)"},
					{fals, fals, 0, "That Rufus guy was a real pain inthe patookas. Constantly"},
					{fals, fals, 0, "yammering on about that          conspiracy stuff"},
					{fals, fals, 0, "Those folks from the company sentme a real cryptic message today."},
					{fals, fals, 0, "Apparently they're not interestedin 'results' anymore, they just"},
					{fals, fals, 0, "want me to install more surveillance equipment."},
					{fals, fals, 0, "Is it official? Maybe they want  Scout TV to be a real broadcast?"},
					{fals, fals, 0, "I'm suspicious it's gotta do withthat Rufus guy."},
					{fals, fals, 0, "They keep asking me about him,   even though we don't work        together."},
					{fals, fals, 0, "It's like they wanna arrest him, but they're waiting for whatever he's inventing to be done, first."},
					{fals, fals, 0, "It wouldn't surprise me."},
					{fals, fals, 0, "Yeah, this log can't be left on  my PC."},
					{fals, fals, 0, "COM: Endscene"}};
				dialogue_page_lite(lc);
				return 0;
			}
			else
			{
				line lc[32] = {
					{fals, fals, 0, "APRIL 30th, 2000 -               Scout log No. 66 (deleted)"},
					{fals, fals, 0, "I've been thinking a lot about   the Apres flower lately."},
					{fals, fals, 0, "I can't help but wonder if that  Enoki girl took some. Her eyes..."},
					{fals, fals, 0, "Well, I can never get a good     enough look to see if the 'ring' is there or not."},
					{fals, fals, 0, "But it'd explain so much."},
					{fals, fals, 0, "Actually, now that I think about it, after hearing about the, er..SECOND side effect.."},
					{fals, fals, 0, "It might not be a bad idea to    keep an eye and see if anything  happens."},
					{fals, fals, 0, "I don't want anything bad to     happen to me or anyone else."},
					{fals, fals, 0, "We'll see."},
					{fals, fals, 0, "You know what? Screw you. You    don't deserve to hear what's     happening to the Tremblays."},
					{fals, fals, 0, "They're staying out of this and  I'm going to delete this log."},
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
					{fals, fals, 0, "TIME RAIDERS: GENESIS            a fan creation by                ICHABOD 'SCOUT' WILLIAMS"},
					{fals, fals, 0, "The time for reckoning was upon  him, Jahn-Jahn Gazebo felt. It   was only a matter of time before"},
					{fals, fals, 0, "Star Space Goblin Emperor Wizard would catch up to his planet. Butthe Time Raiders   were prepared."},
					{fals, fals, 0, "The squeebo-zeebos had warned himahead of time, so he and his bandwere ready."},
					{fals, fals, 0, "They were going to hide in plain sight by pretending to be a      different band - 'Space Raiders'."},
					{fals, fals, 0, "Jahn-Jahn had given his guitar   sword a new paint job."},
					{fals, fals, 0, "Nexus, his quipster sidekick, hadfashioned his keyboard to look"},
					{fals, fals, 0, "like a computer keyboard, and    swapped out his Mondo Glasses    for a pair of normal sunglasses."},
					{fals, fals, 0, "Ninjette, their drummer and      ninja, had disguised her mondo"},
					{fals, fals, 0, "nunchucks / drumsticks as a pair of chicken drumsticks. They      looked very delicious."},
					{fals, fals, 0, "The time had come. They decided  to swap genres. Country music waswhat they were going with."},
					{fals, fals, 0, "Soon enough, the Star Space      Goblin Emperor Wizard had landed on Sqeeb-Sqeeb 9."},
					{fals, fals, 0, "'AAALRIGHT!' he exclaimed, 'I AM SEARCHING FOR JAHN-JAHN GAZEBO!"},
					{fals, fals, 0, "HIS SKULL WILL MEET MY WICKED    FIST OF EVIL!.. FOR EVIL!'"},
					{fals, fals, 0, "'Not so fast, Star Space Goblin  Emperor Wizard!' said Jahn-Jahn, wearing a fake wig."},
					{fals, fals, 0, "'How do you know, random         civilian?' asked the Star Space"},
					{fals, fals, 0, "Goblin Emperor Wizard, who did   not recognize his nemesis."},
					{fals, fals, 0, "'I wrote a song about it! Wanna  hear it? Here it goes!' And withthat, the song began."},
					{fals, fals, 0, "Because it was country music, it sucked so hard that all of his   goons died."},
					{fals, fals, 0, "The Star Space Goblin Emperor    Wizard himself was suspicious"},
					{fals, fals, 0, "that it was actually them, but   Ninjette thought fast."},
					{fals, fals, 0, "She tossed one of the chicken    legs into his mouth, which he"},
					{fals, fals, 0, "thought was delicious. It bought them enough time to leave."},
					{fals, fals, 0, "That's when they met a dude namedScout, who was a fantastic pilot who helped them escape."},
					{fals, fals, 0, "'Wow, Scout! You're such a great pilot!' said Jahn-Jahn. 'Do you  want to join the Time Raiders?'"},
					{fals, fals, 0, "Scout immediately accepted, and  everyone lived happily ever      after."},
					{fals, fals, 0, "I can't believe this story got   rejected from the Time Raiders   script competition, it's perfect."},
					{fals, fals, 0, "COM: Endscene"}};
				dialogue_page_lite(lc);
				return 0;
			}
			else
			{
				line lc[32] = {
					{fals, fals, 0, "TIME RAIDERS: NEO GENESIS DAWN   a fan creation by                ICHABOD 'SCOUT' WILLIAMS"},
					{fals, fals, 0, "Jahn-Jahn Gazebo was sad.        Very sad.                        He felt a deep sadness."},
					{fals, fals, 0, "This is because he had accident- ally consumed the sadness pepper of Sector 9."},
					{fals, fals, 0, "'What is it, Jahn-Jahn?' asked   Scout, who was his first officer."},
					{fals, fals, 0, "'Peppers suck,' he replied.      He was right."},
					{fals, fals, 0, "They didn't go on an adventure   this time, since they let Scout  decide their destination."},
					{fals, fals, 0, "Scout is a very indecisive       individual, you see."},
					{fals, fals, 0, "In fact, Scout was getting both  writer's block and a horrible    pain in his wrist."},
					{fals, fals, 0, "So, the Star Space Goblin Emperordecided to randomly give up and  give them his ship."},
					{fals, fals, 0, "All evil in the universe was     magically zapped away and all    was well the end I'm tired."},
					{fals, fals, 0, "..."},
					{fals, fals, 0, "I'm just not cut out to be a     writer, am I? Far too lazy."},
					{fals, fals, 0, "COM: Endscene"}};
				dialogue_page_lite(lc);
				return 0;
			}
			break;
		}

		case 26:
		{
			line lc[32] = {
				{fals, fals, 0, "Huh... I never thought I'd       actually beat the game."},
				{fals, fals, 0, "Maybe I should do something aboutit."},
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
				{true, true, 28, "CAP'N NICHOLAS                                                    Ahoy there, lass! Are ye ready   fer yer a voyage?"},
				{true, fals, 29, "DIANA                                                             Aye aye, Captain!"},
				{fals, true, 28, "CAP'N NICHOLAS                                                    Just remember what I told ye' -  watch out fer the rocks, and     watch yer speed!"},
				{fals, fals, 29, "DIANA                                                             Aye aye, sir!"},
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
				{fals, fals, 0, "                                 Hey, y'all! Scout here.                                           It's that time again!"},
				{fals, fals, 0, "S_STV_02"},
				{fals, fals, 0, "                                 Scout TV is a regular thing goingon! Check it out, I feel like a  real reporter now!"},
				{fals, fals, 0, "                                 We've all been on this island forthree good months, now. I can't  decide if it feels more like a   day or a million years long."},
				{fals, fals, 0, "                                 Well, it's taken a while, but it looks like we're getting two new islanders!"},
				{fals, fals, 0, "                                 We've got a certain Cesar de la  Cruz on special invitation from  our very own Queen Enoki."},
				{fals, fals, 0, "                                 He was apparently a famous lawyerwho's decided that he wants a newstart."},
				{fals, fals, 0, "                                 We've also got a guy moving in   whose name is.. Guy. I'm not     kidding - his name is Guy."},
				{fals, fals, 0, "                                 I'm looking forward to seeing    what he cooks up, literally! He'sa cook and apparently makes a    mean jambalaya."},
				{fals, fals, 0, "                                 Now, we're getting ever closer tothe Scout Expo, and it's only a  matter of time before it's all   ready."},
				{fals, fals, 0, "                                 I've also managed to order a     bunch of new Time Raiders comic, cuz I know a bunch of islanders  have really been getting into-"},
				{fals, fals, 0, "BG: fadeout"},
				{fals, fals, 0, "S_STV_03"},
				{fals, fals, 0, "                                 . . . ."},
				{fals, fals, 0, "BG: rain"},
				{fals, fals, 0, "S_STV_04"},
				{fals, fals, 0, "                                 I, er- hmm.. Yes, good evening,  island neighbors. It is I, Rufus Thibodeaux, and if you do not    know me, you soon will."},
				{fals, fals, 0, "                                 I have interrupted this broadcastto let you know that I am giving you an ultimatum. Either you     submit your island to me, or-!"},
				{fals, fals, 0, "BG: fadeout"},
				{fals, fals, 0, "S_STV_03"},
				{fals, fals, 0, "                                 . . . ."},
				{fals, fals, 0, "S_STV_01"},
				{fals, fals, 0, "                                 -and that's all, folks! See y'allnext time!"},
				{fals, fals, 0, "S05:02"},
				{fals, fals, 0, "ENOKI                            Aw, I missed the end of the Scoutbroadcast. I was looking forward to it."},
				{fals, fals, 0, "MAPLE                            Hey, isn't that twerp Del's      nephew? He, uh, stopped by the   island a few months ago, I think."},
				{fals, fals, 0, "AARON                            What a strange broadcast."},
				{fals, fals, 0, "ENOKI                            I'm gonna get a soda."},
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
				{fals, fals, 0, "ENOKI                            Hey, Aaron?"},
				{fals, fals, 0, "AARON                            *yawn* Yeah?"},
				{fals, fals, 0, "ENOKI                            Are you happy?"},
				{fals, fals, 0, "AARON                            Of course I am, Noke."},
				{fals, fals, 0, "S11:02"},
				{fals, fals, 0, "ENOKI                            No, I mean.. Are you really,     actually happy?                  I worry about you."},
				{fals, fals, 0, "AARON                            I guess I'm just a little        melancholy about it, that's all."},
				{fals, fals, 0, "ENOKI                            What d'you mean?"},
				{fals, fals, 0, "AARON                            I think you know. Maple is right,we're only able to be here       because of that money you won."},
				{fals, fals, 0, "AARON                            We gambled it all, so if anythinghappens to this place, we've got absolutely nothing."},
				{fals, fals, 0, "ENOKI                            You know me though, I'm lucky,   we'll be okay. And besides, I gotyou! That's enough."},
				{fals, fals, 0, "AARON                            You might not feel like that whenyou're hungry. You don't know    what it's like to be hungry."},
				{fals, fals, 0, "ENOKI                            I don't wanna think about this.. it'll keep me up."},
				{fals, fals, 0, "S11:03"},
				{fals, fals, 0, "ENOKI                            Can we just be happy now and talkabout these things later?"},
				{fals, fals, 0, "AARON                            I guess so. Goodnight, Noke."},
				{fals, fals, 0, "ENOKI                            Goodnight, Aire."},
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
				{fals, fals, 0, "                                 Oh! Hey, nice to meet you!       You must be one of the locals.   You can call me Cesar."},
				{fals, fals, 0, "                                 Believe it or not, I used to be  a lawyer, you know. I wasn't a   very good one, though."},
				{fals, fals, 0, "BG: CRUZ02"},
				{fals, fals, 0, "                                 Then again, I didn't even have a degree and there I was, winning  court cases one after the other."},
				{fals, fals, 0, "                                 So why am I telling you all this,despite never having seen you    before?"},
				{fals, fals, 0, "                                 ..."},
				{fals, fals, 0, "BG: CRUZ01"},
				{fals, fals, 0, "                                 ..."},
				{fals, fals, 0, "                                 Just in case we need to keep our narratives straight, oui?"},
				{fals, fals, 0, "                                 But that's neither here nor      there. I'm fulfilling my dream ofbeing a quiet shopkeep."},
				{fals, fals, 0, "                                 If any angry former clients of   mine decide to stop by, just let me know so I can.. er.. hide.    Merci!"},
				{fals, fals, 0, "                                 Anyway, what might I interest youin today?"},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page(lc);
			return 0;
			break;
		}

		case 31:
		{
			line lc[32] = {
				{fals, fals, 0, "BG: CRUZ01"},
				{fals, fals, 0, "                                 Enoki Ramirez! Er... Tremblay nowis it? Anyway, thank you so much for letting me come here."},
				{fals, fals, 0, "                                 I promise I won't cause any      trouble, but those last clients  of mine..."},
				{fals, fals, 0, "BG: CRUZ02"},
				{fals, fals, 0, "                                 Look, it's not MY fault that I   was able to pretend to be a      lawyer really well, you know?"},
				{fals, fals, 0, "BG: CRUZ01"},
				{fals, fals, 0, "                                 I know you understand. Just let  me know if they arrive so I can, you know, er.. hide."},
				{fals, fals, 0, "                                 It's been a childhood dream of   mine to be a shopkeep in some    little village, and I don't have a lot to sell,"},
				{fals, fals, 0, "                                 But I'll do my best! Anyway, how can I help you today?"},
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
				{true, true, 00, "RUFUS                            Good evening, everyone.          It seems as if my warning was    not enough for you, as no one   "},
				{true, true, 00, "RUFUS                            has shown even the tiniest hint  of fear over the past month.     This is a dreadful mistake,      for you see, I have concocted a "},
				{true, true, 00, "RUFUS                            plan to overwhelm your defenses  and take your island for         myself."},
				{fals, fals, 00, "S06:01"},
				{true, true, 00, "MAPLE                            ...Ugggh, shut up, Rufus, I'm    trying to sleep."},
				{true, true, 00, "RUFUS                            I have developed a-"},
				{fals, fals, 00, "S06:02"},
				{true, true, 00, "ENOKI                            I don't remember turning the     TV on this morning, you do       that, Maple?"},
				{true, true, 00, "MAPLE                            ..."},
				{fals, fals, 00, "S06:03"},
				{true, true, 00, "AARON                            Maybe I accidentally pushed      something. Should I turn it      off?"},
				{true, true, 00, "MAPLE                            ...mmmrff... tv... turn          off... saturday..."},
				{true, true, 00, "RUFUS                            In exactly T-Minus thirty        seconds, I will unleash my-"},
				{fals, fals, 0, "BG: fadeout"},
				{true, true, 00, "AARON                            Okay, it's off now."},
				{true, true, 00, "ENOKI                            What's he always on about?"},
				{true, true, 00, "AARON                            I don't know, Noke."},
				{true, true, 00, "MAPLE                            ..."},
				{fals, fals, 00, "SF: Boom"},
				{true, true, 00, "ENOKI                            Hey, what's that noise?"},
				{true, true, 00, "AARON                            I don't like that, it sounds     like... Hey, Maple, maybe you    should get up."},
				{true, true, 00, "MAPLE                            ...grr, I'm gonna kill that      gator..."},
				{true, true, 00, "ENOKI                            What the- oh no.."},
				{true, true, 00, "AARON                            Enoki, you and Maple go to       Scout's bunker, I'm going to     check on everyone out west."},
				{true, true, 00, "MAPLE                            Excusez-moi, I can take care     of-"},
				{true, true, 00, "AARON                            You go to the bunker and get     some more sleep."},
				{true, true, 00, "MAPLE                            Hey, no need to be               passive-aggressive about it."},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page(lc);
			return 0;
		}

		case 33:
		{
			line lc[32] = {
				{fals, fals, 0, "S07:01"},
				{fals, fals, 0, "BG: fadeout"},
				{true, true, 00, "MAPLE                            So come clean with me, oui?      Did you make this place?"},
				{true, true, 00, "SCOUT                            Heck no! I kind of wish I did,   though."},
				{true, true, 00, "S07:02"},
				{true, true, 00, "..."},
				{true, true, 00, "S07:03"},
				{true, true, 00, "SCOUT                            MAPLE LOOK OUT!"},
				{true, true, 00, "S07:04"},
				{true, true, 00, "MAPLE                            ...Scout, are you alright?"},
				{true, true, 00, "RUFUS                            Ow. I think it popped my back a  bit, though."},
				{true, true, 00, "S07:05"},
				{true, true, 00, "MAPLE                            What's with all the gasoline in  this place, huh?"},
				{true, true, 00, "SCOUT                            Maybe be a little extra careful  with that fire power of yours in this next part, huh?"},
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
					{true, true, 00, "MAPLE                            ..."},
					{true, true, 00, "MAPLE                            What... the actual heck am I     looking at right now?"},
					{true, true, 00, "S07:07"},
					{true, true, 00, "BG: rain"},
					{true, true, 00, "SF: rufus"},
					{true, true, 00, "RUFUS                            Ichabod Williams and             Maple Tremblay, what a surprise! Fancy seeing you two here."},
					{true, true, 00, "RUFUS                            Finally, I've got a full set."},
					{true, true, 00, "S07:08"},
					{true, true, 00, "SCOUT                            RUFUS THI-, WHAT ARE YOU DOING?"},
					{true, true, 00, "MAPLE                            LET ME GO, YOU PUNK!"},
					{true, true, 00, "RUFUS                            I suppose it won't be a bad idea to clap a magic-proof wristband  to keep you from getting any...  sparks of inspiration."},
					{true, true, 00, "BG: fadeout"},
					{true, true, 00, "S07:14"},
					{true, true, 00, "RUFUS                            Alright, now that we've got all  three Tremblays in one place,    let's get started, shall we?"},
					{fals, fals, 0, "COM: Endscene"}};
				dialogue_page(lc);
			}

			{
				line lc[32] = {
					{true, true, 00, "BG: groovy"},
					{true, true, 00, "S07:09"},
					{true, true, 00, "RUFUS                            Firstly, let's have an           short introduction. I'm Monsieur Rufus Thibodeaux, and I'm going  to be your professor today."},
					{true, true, 00, "RUFUS                            Pay attention - no one ever seemsto pay attention to  me, so therewill definitely be a quiz at the end of today's lecture."},
					{true, true, 00, "S07:10"},
					{true, true, 00, "RUFUS                            Lesson one. Repeat after me,     'Rufus is not short. He is just  small-boned.'"},
					{true, true, 00, "MAPLE                            .....Are you kidding me?"},
					{true, true, 00, "RUFUS                            That doesn't sound very much likethe prompt, does it, Maple?"},
					{true, true, 00, "S07:11"},
					{true, true, 00, "RUFUS                            Everyone fails that section.     Moving on... Let's talk about theApres Flower. I was employed by  a certain company to"},
					{true, true, 00, "RUFUS                            study this flower - same as our  dear Ichadod.. er.. 'Scout',     here. If you remember, it's both native here and known"},
					{true, true, 00, "RUFUS                            to contain unknown 'metaphysical'properties. Neat, huh? So,       despite my instructions, I felt  bored and decided to"},
					{true, true, 00, "RUFUS                            have myself a little chompy-chompof some of the leaves. Do you    know what happened after that?"},
					{true, true, 00, "S07:12"},
					{true, true, 00, "RUFUS                            Within moments, I found myself   traveling through the multiverse.I explored all sorts of differentworlds, some similar"},
					{true, true, 00, "RUFUS                            and others very different to     ours, but do you know what I     discovered in nearly every one?"},
					{true, true, 00, "S07:13"},
					{true, true, 00, "RUFUS                            There was this strange trend of  strong-willed, conventionally    attractive women who seemed to   act as the moral good"},
					{true, true, 00, "RUFUS                            and savior of every world, with  strange-looking men serving as   the butt of every joke, or as    incompetent villains"},
					{true, true, 00, "RUFUS                            only to be replaced by the much  more competant, misunderstood    female villains who were only badbecause a man somehow"},
					{true, true, 00, "RUFUS                            turned them evil. And you know   what I thought?"},
					{true, true, 00, "MAPLE                            Hold on-"},
					{true, true, 00, "S07:14"},
					{true, true, 00, "MAPLE                            Are you literally telling me thatyou've decided to become a super villain because you took a flowerthat told you that"},
					{true, true, 00, "MAPLE                            you're the 'bad guy'?"},
					{true, true, 00, "S07:16"},
					{true, true, 00, "RUFUS                            I believe that by taking a pre-  emptive strike, I can manage to  keep my respect and autonomy     short intact, yes."},
					{true, true, 00, "RUFUS                            You see, I believe Maple is the  'main character' based on her    attributes, so I figured it was  best to plan like this."},
					{fals, fals, 0, "COM: Endscene"}};
				dialogue_page(lc);
			}

			{
				line lc[32] = {
					{true, true, 00, "S07:15"},
					{true, true, 00, "ENOKI                            Monsieur Rufus, may I go to the  restroom?"},
					{true, true, 00, "S07:16"},
					{true, true, 00, "RUFUS                            You can go after the lecture, I'malmost done."},
					{true, true, 00, "S07:17"},
					{true, true, 00, "RUFUS                            Now, as I was saying...."},
					{true, true, 00, "BG: fadeout"},
					{true, true, 00, "S07:16"},
					{true, true, 00, "AARON                            Rufus, let's have a talk."},
					{true, true, 00, "S07:18"},
					{true, true, 00, "AARON                            First off, I'm surprised you     didn't know my wife was a        magician, she's good at getting  out of tight spaces."},
					{true, true, 00, "AARON                            Secondly, I don't care what you  saw when you ate that flower, youscared a lot of my friends. Bad."},
					{true, true, 00, "AARON                            That's completely unacceptable.  You can't just kidnap people and hold them hostage."},
					{true, true, 00, "AARON                            Let us go and leave us alone,    c'est bon? Got it?"},
					{true, true, 00, "RUFUS                            Just hold on a moment, Aaron."},
					{true, true, 00, "RUFUS                            There's something you should knowThe doors to this room are       completely, hopelessly tightly   sealed."},
					{true, true, 00, "RUFUS                            A bomb could go off outside and  we'd barely notice. However, the moment one of y'all takes a      little bit of Apres flower,"},
					{true, true, 00, "RUFUS                            those doors open wide up. Here's my challenge. We have a little   fight. If you win, I leave your  island alone."},
					{true, true, 00, "RUFUS                            I win, and I get to be the new   king. Either way, you gotta take the Apres to get out. Oui?"},
					{true, true, 00, "RUFUS                            I'm confident that once one of   you sees the things I'll see, I  won't seem nearly as crazy."},
					{true, true, 00, "RUFUS                            We'll see."},
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
					{true, true, 00, "S08:01"},
					{true, true, 00, "RUFUS                            Well, well, well..."},
					{true, true, 00, "RUFUS                            HA! Looks like I'm the victor    here. It's Apres flower time."},
					{true, true, 00, "RUFUS                            So, who will it be? Aaron, how   about you give it a go?"},
					{true, true, 00, "MAPLE                            You know what? In your dreams,   you little punk."},
					{true, true, 00, "S08:02"},
					{true, true, 00, "BG: rain"},
					{true, true, 00, "RUFUS                            W-Who you calling little?"},
					{true, true, 00, "MAPLE                            For one, even your little robot  legs are standing on their       tiptoes."},
					{true, true, 00, "S08:03"},
					{true, true, 00, "MAPLE                            Look, I don't know why you're    obsessed with thinking the world is like your flower-induced      fever dream."},
					{true, true, 00, "MAPLE                            But life is complicated, alright?Everybody's complicated. I don't care what you saw in that flower,but you can't just"},
					{true, true, 00, "MAPLE                            come in and harrass us on our ownisland. We didn't even know who  you were, dude."},
					{true, true, 00, "MAPLE                            I'll threaten you again like I   threaten everybody else-         any funny business, and-"},
					{true, true, 00, "RUFUS                            I-I know, I know, I know, you'll burn my face off."},
					{true, true, 00, "RUFUS                            Hey, uh, be careful with that    fire, it's, uh, I've got a lot offlamables down here."},
					{true, true, 00, "MAPLE                            CAREFUL? After you KIDNAP us?    You're darn straight I'll burn   your face off."},
					{true, true, 00, "S08:04"},
					{true, true, 00, "CESAR                            Hey, Maple?"},
					{true, true, 00, "S08:05"},
					{true, true, 00, "MAPLE                            NOT NOW CESAR, I'M MESSING WITH ALITTLE MEGALOMANIAC, HERE!"},
					{true, true, 00, "S08:06"},
					{true, true, 00, "RUFUS                            N-No seriously, you, er, uh..    Oh dear.."},
					{true, true, 00, "S08:07"},
					{true, true, 00, "MAPLE                            WHAT?! "},
					{true, true, 00, "BG: fadeout"},
					{fals, fals, 0, "COM: Endscene"}};
				dialogue_page(lc);
			}
			{
				line lc[32] = {
					{true, true, 00, "S09:01"},
					{true, true, 00, "BG: pools"},
					{true, true, 00, "GUY                              It's nice out here."},
					{true, true, 00, "DIANA                            You're telling me. Honestly if itwasn't so expensive, I'd just    boat around 24/7."},
					{true, true, 00, "GUY                              You think we gonna get any       tourists?"},
					{true, true, 00, "DIANA                            Okay, I don't know if this is    just you, but you need to chill  out about your restaraunt."},
					{true, true, 00, "DIANA                            You need to learn when to take a break and relax, oui?"},
					{true, true, 00, "GUY                              I guess so. It's like my baby    though. I'm crazy about it."},
					{true, true, 00, "DIANA                            I mean, what if something        happened, though? Like, what if  it blew up?"},
					{true, true, 00, "BG: fadeout"},
					{true, true, 00, "S09:02"},
					{true, true, 00, "..."},
					{true, true, 00, "SF: Boom"},
					{true, true, 00, "S09:03"},
					{true, true, 00, "......"},
					{true, true, 00, "S09:04"},
					{true, true, 00, "GUY                              ..."},
					{true, true, 00, "DIANA                            ..."},
					{true, true, 00, "GUY                              Thunder... my... dog."},
					{fals, fals, 0, "COM: Endscene"}};
				dialogue_page(lc);
			}
			{
				line lc[32] = {
					{true, true, 00, "S09:05"},
					{true, true, 00, "RUFUS                            What the..."},
					{true, true, 00, "RUFUS                            ..."},
					{true, true, 00, "S09:06"},
					{true, true, 00, "MAPLE                            I... I-I..."},
					{true, true, 00, "AARON                            Maple, I-"},
					{true, true, 00, "MAPLE                            ...I-I'm..."},
					{true, true, 00, "S09:08"},
					{true, true, 00, "ENOKI                            Maple, come back!"},
					{true, true, 00, "MAPLE                            ..."},
					{true, true, 00, "S09:09"},
					{true, true, 00, "MAPLE                            ..."},
					{true, true, 00, "AARON                            Maple, we need to talk.          Right now."},
					{true, true, 00, "S09:10"},
					{true, true, 00, "ENOKI                            Maple, it's-"},
					{true, true, 00, "AARON                            Maria, I love you, but it needs  to just be Maple and I."},
					{true, true, 00, "S09:11"},
					{true, true, 00, "ENOKI                            Maria..."},
					{true, true, 00, "ENOKI                            A-Alright, I'll go check on the  others."},
					{fals, fals, 0, "COM: Endscene"}};
				dialogue_page(lc);
			}
			{
				line lc[32] = {
					{true, true, 00, "S09:12"},
					{true, true, 00, "AARON                            Maple. We've needed to have this talk for a very long time and it can't wait."},
					{true, true, 00, "S09:13"},
					{true, true, 00, "AARON                            I think you know what it's about."},
					{true, true, 00, "MAPLE                            I d-don't want to talk right now."},
					{true, true, 00, "S09:14"},
					{true, true, 00, "BG: maple"},
					{true, true, 00, "AARON                            I wanted to apologize."},
					{true, true, 00, "S09:13"},
					{true, true, 00, "AARON                            I've been complaining about you  behind your back to the others."},
					{true, true, 00, "AARON                            You've done so much that has mademe proud to be your big brother."},
					{true, true, 00, "AARON                            But you... you've got this anger inside of you all of the time at everything you percieve to be    wrong with the world."},
					{true, true, 00, "AARON                            Anger isn't a bad thing, but     everything you're angry about..  it's because you see it in       yourself, too."},
					{true, true, 00, "S09:14"},
					{true, true, 00, "AARON                            I appreciate that you stood up   for me."},
					{true, true, 00, "MAPLE                            Shut up."},
					{true, true, 00, "S09:13"},
					{true, true, 00, "AARON                            Not right now."},
					{true, true, 00, "AARON                            Take your time to calm down, but you will learn to take care of   your anger, or I can't help you  anymore, oui?"},
					{true, true, 00, "MAPLE                            ...Oui."},
					{true, true, 00, "S09:15"},
					{true, true, 00, "AARON                            That's what I thought.           Rufus, I believe I have a deal totake care of."},
					{true, true, 00, "S09:16"},
					{true, true, 00, "BG: fadeout"},
					{true, true, 00, "ENOKI                            A-Aar.. AARON, WAIT!"},
					{true, true, 00, "AARON                            We need to get those doors open."},
					{true, true, 00, "RUFUS                            Hey, I can find a way to disable the door, I'm sure of it, a-at   least.. I think, you don't need  to-"},
					{true, true, 00, "ENOKI                            P-Please don't.. I don't want youtaking something that'll change  you."},
					{true, true, 00, "AARON                            I'll be fine, you've got nothing to worry about."},
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
					{true, true, 00, "I-I just... I can't lose you..."},
					{true, true, 00, "COM: Endscene"}};
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
					{true, true, 00, "A-Aaron?                         Why are you looking at me        like that?"},
					{true, true, 00, "COM: Endscene"}};
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
					{true, true, 00, "Say something already..          You're scaring me.."},
					{true, true, 00, "COM: Endscene"}};
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
					{true, true, 00, "BG: 2"},
					{true, true, 00, "S10:01"},
					{true, true, 00, "AARON                            I paid off the island in cash. Weshould easily have enough to renta house back in Louisiana."},
					{true, true, 00, "AARON                            It was only a matter of time     before we needed to head back to Louisiana anyway, oui?"},
					{true, true, 00, "AARON                            I should have enough to give you all a few months' rent wherever  you want to live as you return tonormal life."},
					{true, true, 00, "AARON                            I want to say that I was proud tobe your king while it lasted.    Thank you all."},
					{true, true, 00, "S10:02"},
					{true, true, 00, "OLIVIER                          No, thank you too. I don't know  what Eleanor and I will do, but..we will think of something."},
					{true, true, 00, "OLIVIER                          We all came here because we      didn't have any money anyway.    Meeting y'all has been           a blessing."},
					{true, true, 00, "CESAR                            And Enoki definitely saved my    butt, no doubt about it."},
					{true, true, 00, "RUFUS                            I-I can help if anyone needs     anything or anywhere to stay. I'mreally, really sorry about       y'all's island."},
					{true, true, 00, "RUFUS                            I never meant to actually cause  any problems, I was just here to mildly antagonize y'all, I..     Geez.."},
					{true, true, 00, "RUFUS                            Hey, I've got blankets and stuff if you need a place to sleep for the night."},
					{true, true, 00, "S10:01"},
					{true, true, 00, "AARON                            ...Thank you, Rufus."},
					{true, true, 00, "AARON                            We all need some time to process what just happened. I didn't see Diana's boat in the island       footage."},
					{true, true, 00, "AARON                            Everyone seems to have been okay,and that's what matters most."},
					{true, true, 00, "AARON                            I love you all."},
					{fals, fals, 0, "COM: Endscene"}};
				dialogue_page(lc);
			}

			{
				line lc[32] = {
					{true, true, 00, "S10:04"},
					{true, true, 00, "BG: fadeout"},
					{true, true, 00, "SCOUT                            Maple, how are you doing?"},
					{true, true, 00, "MAPLE                            ..."},
					{true, true, 00, "S10:03"},
					{true, true, 00, "MAPLE                            ...Don't you dare give me any    pity, are we clear?"},
					{true, true, 00, "S10:04"},
					{true, true, 00, "SCOUT                            Y-Yeah, of course, I just.. I'm  sorry for-"},
					{true, true, 00, "S10:03"},
					{true, true, 00, "MAPLE                            What are YOU sorry for?"},
					{true, true, 00, "SCOUT                            Please just let me finish."},
					{true, true, 00, "MAPLE                            Fine. Go on."},
					{true, true, 00, "SCOUT                            I.. I'm sorry for being forward, but please don't beat yourself   up. I'm on your side, right?"},
					{true, true, 00, "MAPLE                            What, are you going to ask me outor something?"},
					{true, true, 00, "S10:04"},
					{true, true, 00, "SCOUT                            No, I- I.. well, no, I wasn't    going to.. look, I just don't    want you to go."},
					{true, true, 00, "SCOUT                            We're not mad at you, and.. look,I don't want to lose your        friendship because you're"},
					{true, true, 00, "SCOUT                            mad at yourself, okay? You're    more important than that island. I..."},
					{true, true, 00, "SCOUT                            Just promise me that you won't   go anywhere or do anything stupidbecause of this. Please."},
					{true, true, 00, "MAPLE                            ..."},
					{true, true, 00, "S10:04"},
					{true, true, 00, "MAPLE                            ...I won't, Scout. Don't worry."},
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
					{true, true, 00, "BG: the flame"},
					{true, true, 00, "S10:05"},
					{true, true, 00, "ENOKI                            Hey, Maple! Back home so early?"},
					{true, true, 00, "MAPLE                            Yep. The interview went great.   The military is going to suck,   but... the benefits are nice."},
					{true, true, 00, "AARON                            You're gonna do great, Maple."},
					{true, true, 00, "MAPLE                            You really think so?"},
					{true, true, 00, "AARON                            You'll be the only elf on the    team, I bet. That's a huge       advantage."},
					{true, true, 00, "MAPLE                            Yeah, I guess so. I talked to    Scout about it, he's happy enoughbut he says he'll miss me."},
					{true, true, 00, "ENOKI                            We will too."},
					{true, true, 00, "S10:06"},
					{true, true, 00, "ENOKI                            Well, Aaron and I, we've got somenews, too."},
					{true, true, 00, "S10:07"},
					{true, true, 00, "MAPLE                            Oh dear, what?"},
					{true, true, 00, "S10:08"},
					{true, true, 00, "ENOKI                            It's looking like we.. uh.. theremight be another Tremblay here   soon enough."},
					{true, true, 00, "S10:10"},
					{true, true, 00, "MAPLE                            Hold on, you're not-?"},
					{true, true, 00, "S10:09"},
					{true, true, 00, "ENOKI                            Uh huh!"},
					{true, true, 00, "S10:11"},
					{true, true, 00, "MAPLE                            You're... PREGNANT?"},
					{true, true, 00, "AARON                            Yes, ma'am."},
					{true, true, 00, "S10:09"},
					{true, true, 00, "MAPLE                            Holy cow, I-.. I'm gonna be an   aunt. An Aaron-Enoki mix, what's that even going to be like?"},
					{true, true, 00, "S10:12"},
					{true, true, 00, "ENOKI                            2000 has been such a great year, I bet 2001 will be even better!"},
					{true, true, 00, "AARON                            Whatever adventure it turns out  to be like, I'm just glad y'all  are here for it."},
					{true, true, 00, "MAPLE                            Happy 2001, y'all."},
					{true, true, 00, "ENOKI                            Happy 2001."},
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
				{fals, fals, 00, "Ahoy!                            Welcome! Come grab a seat and a  tea or a coffee or something."},
				{fals, fals, 00, "So what'd you think of my game?  Yeah.. it wasn't super long, but to be completely honest,"},
				{fals, fals, 00, "I wasn't completely sure I'd be  able to pull it off, haha. I hopeyou had a good time, though."},
				{fals, fals, 00, "Since you managed to get all the keys, I'm going to let you play  whichever minigames you want!"},
				{fals, fals, 00, "Just stop by this save file      anytime you want to try them out."},
				{fals, fals, 00, "Until next time!"},
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
	}

	else if (globals->all_save.language == 2)
	{

		switch (x)
		{
		case 0:
		{
			line lc[32] = {
				{fals, true, 0, "BG: 1"},
				{fals, true, 0, "S01:01"},
				{fals, true, 0, "4:15 AM                          1 de Enero, 2000                 Providence de Nord Louisiane,    La Republique Laurentides"},
				{fals, true, 0, "S01:02"},
				{fals, true, 0, "                                 AHHHHG.                          Conduje durante horas.           Mi pie derecho esta dormido y    el otro va por el mismo camino."},
				{fals, true, 0, "S01:03"},
				{fals, true, 0, "                                 Y este gumbo...                  Tiene que estar ya helado.       No puedo creer que quisieran     que les llevase la comida."},
				{fals, true, 0, "S01:04"},
				{fals, true, 0, "                                 A decir verdad...                Si no veo ese castillo en        quince minutos, tal vez me de    la vuelta."},
				{fals, true, 0, "                                 Aunque el viaje fue agradable,   supongo."},
				{fals, true, 0, "                                 Esta bien, me rindo. No hay      manera de-"},
				{fals, true, 0, "S01:06"},
				{fals, true, 0, "                                 .....Oh."},
				{fals, true, 0, "                                 No sabria decir si me siento     aliviada o decepcionada."},
				{fals, true, 0, "BG: fadeout"},
				{fals, true, 0, "S01:07"},
				{fals, true, 0, "                                 *knock*                          *knock*                          *knock*"},
				{fals, true, 0, "S01:08"},
				{fals, true, 0, "                                 Me pregunto si podran llegar a   escucharme... Este lugar         se ve enorme."},
				{fals, true, 0, "                                 '}...hay voyy!'"},
				{fals, true, 0, "S01:09"},
				{fals, true, 0, "BG: 0"},
				{fals, true, 0, "                                 Hola, Maple!                     Adelante, allez!"},
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
				{true, fals, 1, "MAPLE                            Okey, {Donde puedo enchufar esta olla de coccion lenta?           {Hay enchufes por aqui?"},
				{fals, fals, 1, "MAPLE                            Creo que e llegado muy tarde y yahas comido algo."},
				{fals, true, 9, "ENOKI                            Tenemos una bodega afuera,       es el unico cuarto con           electricidad. Y si, ya comimos   pollo."},
				{fals, true, 8, "ENOKI                            }Te hemos extra[ado mucho!"},
				{fals, fals, 5, "MAPLE                            Bueno, pues al fin he llegado.   {Donde esta- }Oh! Hola, Aaron."},
				{true, true, 10, "AARON                            }Bonsoir! O Bonjour mas bien,    ya tecnicamente es ma[ana. {No?  Me alegra que hayas venido.      }Feliz milenio!"},
				{fals, fals, 3, "MAPLE                            }Feliz milenio! {Saben que estan a la mitad de la nada verdad?"},
				{true, true, 12, "DEL                              }Maple! }Veniste! }Feliz 2000!"},
				{fals, fals, 5, "MAPLE                            }Delphine Thibodeaux!            Dios mio, {Cuanto tiempo ha      pasado? {Un a[o? }Salut!"},
				{fals, true, 13, "DEL                              }Ay, chica! Que alegria verte. Note rayes, que te hemos estado    esperando para abrir el vino     y sacar eclairs."},
				{fals, true, 12, "DEL                              Aunque ya todos somos unos       adultos aburridos. Asi que no te aseguro que nos quedemos hasta   tarde contigo."},
				{true, true, 7, "ENOKI                            Oye Maple, {Como te ha ido?      }{Acaso hemos hablado desde la   boda?! }Extra[o a mi mejor amiga!"},
				{fals, fals, 2, "MAPLE                            Supongo que tu marido te ha      mantenido ocupada."},
				{true, true, 10, "AARON                            Bueno, como ves, vivimos en un   castillo ahora, y eso ha sido    toda una aventura."},
				{true, true, 7, "ENOKI                            Soy una princesa."},
				{fals, fals, 2, "MAPLE                            Un gran castillo no es todo para ser princesa."},
				{fals, true, 8, "ENOKI                            {Entonces una duquesa?"},
				{fals, fals, 4, "MAPLE                            Yo- ehm...                       Hmm...                           {Sabes que?                      Es muy tarde para esto."},
				{fals, fals, 2, "MAPLE                            Me ha ido bien en cualquier caso,tan solo me faltaria un semestre para poder ser maestra.          Y pues si no se."},
				{true, true, 10, "AARON                            Todavia tratas con eso?, {eh?    {Aunque me dijiste un millon de  veces que querias hacer cualquiermenos una maestra?"},
				{fals, true, 11, "AARON                            {Que no hay carreras para las    personas que puedan lanzar fuego con las manos?"},
				{fals, fals, 4, "MAPLE                            No al menos uno que quiera."},
				{fals, true, 10, "AARON                            Bueno, a mi maestra magica de    fuego me suena muy bien."},
				{true, true, 8, "ENOKI                            *Aaawn*                          Dios mio, me muero de sue[o.     {Y si nos vamos a dormir y ma[anaseguimos con la platica?"},
				{fals, true, 7, "ENOKI                            Oye Maple, {que tal una pijamada?{como cuando eramos compa[eras decuarto en el colegio?"},
				{fals, fals, 2, "MAPLE                            Ehh... supongo que esta bien."},
				{fals, true, n, "ENOKI                            }Buenas noches, Del!             Ey Aaron, {te veo en la ma[ana?  {Bien tempranito?"},
				{fals, true, 0, "AARON                            Claro que si, Noke-noke.                                          *beso*"},
				{fals, fals, 3, "MAPLE                            No terminare de acostumbrarme a  esto."},
				{true, true, 9, "ENOKI                            Andale, agarra tu maleta y te    dire donde te quedaras.          }Allons-y!"},
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
				{fals, true, 0, "MAPLE                            Uyyy... Como que hace mucho frio aqui, {no?"},
				{fals, true, 0, "ENOKI                            Ay mensa, {A quien se le ocurre  ponerse una blusa sin manga y    shores en medio de Diciembre?    {Puedes hacer una fogata?"},
				{true, true, 0, "BG: 2"},
				{true, true, 0, "S01:10"},
				{fals, true, 0, "MAPLE                            {Y por cuanto se quedaran aqui?  No se quedaran 50km de la        civilizacion y sin electricidad  por siempre."},
				{true, true, 0, "S01:11"},
				{fals, true, 0, "ENOKI                            Nos encanta aqui, creo que       estaremos aqui por mucho tiempo."},
				{fals, true, 0, "MAPLE                            {Y que dice Aaron de todo esto?  El Aaron con el recuerdo crecer  habria sido un poco mas...       responsable."},
				{fals, true, 0, "ENOKI                            Ojala y no sea grosera pero...   {Que ustedes no estan            acostumbrados a crecer en lugarescomo en un carro?"},
				{fals, true, 0, "MAPLE                            Enoki, ya sabemos que eres rica, no tienes por que fardar de ello."},
				{fals, true, 0, "ENOKI                            Pero en verdad tu creciste en un carro, {no? Comparado con eso, esincreible vivir en un castillo,  {no?"},
				{fals, true, 0, "MAPLE                            Es solo que... Es una locura. No me estoy burlando de ti ni nada  por el estilo, pero realmente    creo que  esto es una mala idea."},
				{fals, true, 0, "ENOKI                            Eso viene de la chica que se le  dieron pena sus calificaciones   del primer a[o y decidio dejar launiversidad..."},
				{true, true, 0, "S01:10"},
				{fals, true, 0, "MAPLE                            Anda ya, y esa fue idea tuya."},
				{true, true, 0, "S01:11"},
				{fals, true, 0, "ENOKI                            }Oye! Pero si, fue en el 97...   puedo decir que fue unos de mis  mejores a[os."},
				{fals, true, 0, "ENOKI                            {Has pensado donde te gustaria   vivir cuando termines tus        estudios?"},
				{fals, true, 0, "MAPLE                            Ya pensare en algo."},
				{fals, true, 0, "ENOKI                            Aaron y yo estuvimos hablando, alparecer hay una escuela cerca de aqui, quiza  podrias... Bueno,   yasabes."},
				{fals, true, 0, "MAPLE                            Ni pensarlo!. Me asegurare de    conseguir un apartamento digno deun adulto hecho y derecho."},
				{fals, true, 0, "MAPLE                            Cuando te aburras de este sitio, quizas te deje moverte conmigo."},
				{true, true, 0, "S01:12"},
				{fals, true, 0, "ENOKI                            Maple, las cosas que dices       bromeando nunca dejaran de       sorprenderme."},
				{true, true, 0, "S01:11"},
				{fals, true, 0, "ENOKI                            Oye- Creo que ando depre y es un poco loco. {Y si  nos vamos de   aventuras como en    los viejos  tiempos?"},
				{fals, true, 0, "ENOKI                            }}Vamos a explorar el castillo!!"},
				{fals, true, 0, "MAPLE                            Espera, {tratas de decirme que   compraste el castillo sin        explorarlo primero?"},
				{fals, true, 0, "ENOKI                            Bueno, digamos que estoy         tomandome mi tiempo...    }Es un gran castillo despues de todo,   Allons-y!"},
				{true, true, 0, "COM: Endscene"}};
			dialogue_page(lc);
			return 0;
			break;
		};

		case 3:
		{
			line lc[32] = {
				{fals, fals, 0, "BG: Moody"},
				{true, true, 30, "ENOKI                            }Me encantaria explorar el       cuarto con la gran biblioteca    primero!"},
				{true, fals, 02, "MAPLE                            Bueno, ya que."},
				{fals, true, 31, "ENOKI                            Entenderas porque en cuanto lo   veas!"},
				{fals, true, 30, "ENOKI                            Si quieres que vaya delante,     solo presiona 'B'."},
				{fals, fals, 03, "MAPLE                            ... {Como?"},
				{fals, true, 30, "ENOKI                            {Que?"},
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
				{true, fals, 4, "..."},
				{true, true, 10, "AARON                            }Bonjour! {Durmieron bien?"},
				{true, fals, 4, "MAPLE                            Si, he dormido bien, creo."},
				{true, true, 9, "ENOKI                            }Bonjour! Oye... Hemos encontradoalgo muy padre mientras dormias, pero promete que no te enojaras!"},
				{fals, fals, 4, "MAPLE                            Sabes que no puedo hacer eso."},
				{true, true, 7, "ENOKI                            {Recuerdas el libro que querias  que tomara? Pues bien, es un     Atlas del mundo, }y nos dimos    cuenta de algo  divertido!"},
				{fals, true, 9, "ENOKI                            }Hemos visto esta isla del Lago  Superieur, llamada Tremblay      Island!"},
				{fals, fals, 0, "MAPLE                            Ah, sin chiste. Pensaba que      dirias un chiste o algo por el   estilo."},
				{fals, true, 0, "ENOKI                            Bueno, nosotros, eh- hemos       pensado que seria divertido si,  pues, Del ha tenido la idea,     asi que..."},
				{true, true, 12, "DEL                              La ultima vez que hablamos,      mi primo Rufus estaba obsesionadocon comenzar su peque[o pais."},
				{true, true, 11, "AARON                            El trabajo no quedaria tan lejos,y si nos hacen falta provisiones,no quedaria tan lejos."},
				{true, true, 7, "ENOKI                            Con el dinero que consigamos     vendiendo el castillo y tu magia,hemos pensado que-"},
				{fals, fals, 3, "MAPLE                            Espera espera,  espera           UN MOMENTO."},
				{fals, fals, 3, "MAPLE                            {Enserio me estas diciendo que   venderias el castillo para       moverte a una tal isla-"},
				{fals, fals, 3, "MAPLE                            Solo porque tiene el mismo       apellido que nosotros?"},
				{fals, true, 9, "ENOKI                            Y aparte, estamos pensando en    separarnos de Laurentides para   fundar nuestro propio pais."},
				{fals, fals, 0, "MAPLE                            ...Yo..."},
				{fals, fals, 0, "MAPLE                            ..."},
				{fals, fals, 4, "MAPLE                            ... Creo que necesito tiempo paraprocesar todo esto."},
				{true, true, 10, "AARON                            Puede que parezca una locura,    pero nos hemos informado de los  detalles y al parecer es posible que podamos lograrlo."},
				{true, true, 9, "ENOKI                            Se que platicamos anoche, pero..."},
				{fals, fals, 3, "MAPLE                            {Y despues que?                  {que vas hacer cuando te aburras en tu peque[a isla?"},
				{fals, fals, 0, "MAPLE                            {Serias el Papa? {Quiza la Reina de Francia? {o que tal tu propio planeta?"},
				{fals, fals, 0, "MAPLE                            Y probablemente tendras la suertepara conseguirlo. Pero, {sabes   que?"},
				{fals, fals, 0, "MAPLE                            Yo estare con los pies en la     tierra con un trabajo *de verdad*y evitare morirme de hambre      aunque sea arrastrandome."},
				{fals, fals, 0, "MAPLE                            O peor aun, en la carcel federal por haber violado algun tipo de  ley rara."},
				{fals, fals, 4, "MAPLE                            Mira.... Me he divertido, pero   necesito ir a casa.  Estoy harta de todo esto."},
				{fals, fals, 0, "MAPLE                            Aaron, Enoki, Delphine, me dio   gusto haberlos visto de nuevo,   pero necesito tomarme un tiempo."},
				{true, true, 10, "AARON                            {Encerio? Cambiemos el tema, va? El desayuno ya esta listo,       {vienes?"},
				{fals, fals, 0, "MAPLE                            ...Esta bien, me quedare un poco mas, pero ya no tardaria en irme."},
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
					{fals, true, 0, "                                 Hmm, hmm hmm hmm...."},
					{fals, true, 0, "                                 {Dios mio cuando va a llegar la  pizza? {No se supone que tenia   que llegar hace 20 minutos?"},
					{fals, true, 0, "                                 Hoy he checado el correo? Deberiade ir a verlo."},
					{true, true, 0, "S02:03"},
					{fals, true, 0, "                                 Ehh, {que es esto? {De la casa   Tremblay? Hace mucho que no he   escuchado de Aaron y Enoki."},
					{fals, true, 0, "                                 Espero escuchar lo mucho que     quisieran venir a vivir ahora    conmigo."},
					{true, true, 0, "BG: fadeout"},
					{true, true, 0, "S02:04"},
					{fals, true, 0, "                                            }Hola, Maple!"},
					{true, true, 0, "S02:05"},
					{fals, true, 0, "                                 Espera, lo puse al reves."},
					{true, true, 0, "S02:04"},
					{true, true, 0, "BG: 0"},
					{fals, true, 0, "                                            }Hola, Maple!"},
					{fals, true, 0, "                                       'Pensamos en enviarte            una carta para                   tenerte informada'"},
					{fals, true, 0, "                                       'Hemos vendido el                castillo y hemos                 comprado una casa movil."},
					{fals, true, 0, "                                       'Aunque eso no es todo-          }Ya la hemos instalado           en nuestra nueva isla!'"},
					{true, true, 0, "S02:05"},
					{fals, true, 0, "                                 Ya me...                         tienen bien.    Los voy a matar."},
					{true, true, 0, "S02:04"},
					{fals, true, 0, "                                       'Asi que hemos decidido          que la vamos a llamar-..'"},
					{true, true, 0, "COM: Endscene"}};
				dialogue_page(lc);
			}
			else
			{
				line lc[32] = {
					{true, true, 0, "S02:02"},
					{true, true, 0, "BG: champ"},
					{fals, true, 0, "                                 Hmm, hmm hmm hmm...."},
					{fals, true, 0, "                                 {Dios mio cuando va a llegar la  pizza? {No se supone que tenia   que llegar hace 20 minutos?"},
					{fals, true, 0, "                                 Hoy he checado el correo? Deberiade ir a verlo."},
					{true, true, 0, "S02:03"},
					{fals, true, 0, "                                 Ehh, {que es esto? {De la casa   Tremblay? Hace mucho que no he   escuchado de Aaron y Enoki."},
					{fals, true, 0, "                                 Espero escuchar lo mucho que     quisieran venir a vivir ahora    conmigo."},
					{true, true, 0, "BG: fadeout"},
					{true, true, 0, "S02:04"},
					{fals, true, 0, "                                            }Hola, Maple!"},
					{true, true, 0, "S02:05"},
					{fals, true, 0, "                                 Espera, lo puse al reves."},
					{true, true, 0, "S02:04"},
					{true, true, 0, "BG: 0"},
					{fals, true, 0, "                                            }Hola, Maple!"},
					{fals, true, 0, "                                       'Pensamos en enviarte            una carta para                   tenerte informada'"},
					{fals, true, 0, "                                       'Hemos vendido el                castillo y hemos                 comprado una casa movil."},
					{fals, true, 0, "                                       'Aunque eso no es todo-          }Ya la hemos instalado           en nuestra nueva isla!'"},
					{true, true, 0, "S02:05"},
					{fals, true, 0, "                                 Ya me...                         tienen bien.    Los voy a matar."},
					{true, true, 0, "S02:04"},
					{fals, true, 0, "                                       '}Nos vemos pronto!            - Aaron & Enoki Tremblay'"},
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
				{fals, true, 0, "MAPLE                            Que baje Dios y me pare,         Ya me tienen hasta la CORONILLA, }me la VAN a PAGAR!"},
				{fals, true, 0, "MAPLE                            }Ya me hicieron enojar! Se van a MORIR SOLOS. Ellos mismos se la  buscaron."},
				{fals, true, 0, "MAPLE                            Cuando se cansen de tal isla de  fantasia, volveran aqui, {y que  crees que les dire?"},
				{fals, true, 0, "PIZZA GUY                        {Que les vas a decir?"},
				{true, true, 0, "S02:07"},
				{fals, true, 0, "MAPLE                            }Les dire NO!"},
				{fals, true, 0, "PIZZA GUY                        No se, eso de vivir en una isla  solos suena muy bien."},
				{fals, true, 0, "MAPLE                            Seria lo mejor en el mundo, pero lo van a estropear.}Son las      personas mas torpes en el        planeta!"},
				{fals, true, 0, "PIZZA GUY                        Si yo fuera tu, me iria a la islapara ense[arles como se hacen    las cosas."},
				{fals, true, 0, "MAPLE                            {Supongo que lo tendria que      hacer, eda? }Se van a morir, o   podria ser que se congelen!"},
				{fals, true, 0, "MAPLE                            Pero no puedo. Tengo que ser     adulta aqui y quedarme en la     realidad."},
				{true, true, 0, "S02:06"},
				{fals, true, 0, "PIZZA GUY                        Claro, {es mas importante comprarpizza y llorar hasta quedarte    dormida, como todas las noches?"},
				{true, true, 0, "S02:08"},
				{fals, true, 0, "MAPLE                            {Es obvio?"},
				{fals, true, 0, "PIZZA GUY                        Pues, nos turnamos para llevarle de comer a la pobrecita ni[a comepizzas."},
				{fals, true, 0, "MAPLE                            Me lleva."},
				{true, true, 0, "S02:04"},
				{fals, true, 0, "MAPLE                            Bueno supongo...La verdad no     tengo dinero para pagar este mes de renta por tanta pizza."},
				{fals, true, 0, "PIZZA GUY                        Entonces... {Y mi propina por la terapia?"},
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
				{fals, true, 0, "6:40 PM                          20 de Marzo, 2000                En medio del Lake Superieur,     La Republique Laurentides(?)"},
				{fals, true, 0, "                                 Asi que... Esa es la isla...     Es muy linda."},
				{fals, true, 0, "                                 Pero como para vender todas mis  cosas, a mi se me hace que no."},
				{fals, true, 0, "                                 J'suppose que vivir en una isla  sin tener deudas seria muy padre."},
				{fals, true, 0, "S03:02"},
				{fals, true, 0, "MAPLE                            {Cuanto costaba el viaje en el   ferry? {10 dolares?"},
				{fals, true, 0, "OLD SAILOR                       Alas, una advertencia te tengo   que decir antes que partas."},
				{fals, true, 0, "MAPLE                            Dios mio, y ahora que?"},
				{fals, true, 0, "OLD SAILOR                       ‘Tate atenta por ahi que nunca   sesabe quien podria darte una      pu[alada."},
				{fals, true, 0, "MAPLE                            {...tienes cambio de 20?"},
				{fals, true, 0, "OLD SAILOR                       Anda si."},
				{fals, true, 0, "COM: Endscene"}};
			dialogue_page(lc);
			return 0;
			break;
		}

		case 18:
		{
			line lc[32] = {
				{fals, fals, 0, "BG: Trailer Home"},
				{true, true, 22, "ENOKI                            }Maple, veniste!"},
				{true, fals, 17, "MAPLE                            Pues si, supongo era la mejor    opcion."},
				{true, true, 24, "AARON                            {Como te fue? {Fue muy largo el  camino?"},
				{fals, fals, 16, "MAPLE                            Tome el tren. {Fueron como dos a tres dias? Me fue bien. Lei      mucho. Me duelen las piernas."},
				{fals, true, 25, "AARON                            }Si nos hubieras avisado mas     temprano, te hubieramos comprado un boleto de avion!"},
				{fals, fals, 18, "MAPLE                            Pues ya que. Ya llegue.          {Entonces se mueven de un        castillo a una casa rodante?    Barbaros."},
				{true, true, 20, "ENOKI                            Oye, {nos movemos de un castillo a una casa normal y ahora        quieres que nos regresemos?"},
				{fals, fals, 16, "MAPLE                            No, solo que... ya ni se lo que    estoy diciendo."},
				{true, true, 26, "AARON                            Bueno, por ahora nada mas tenemosun sofa pero esta bien comodo.   Esta es tu casa, descansa."},
				{fals, true, 24, "AARON                            Hemos estado trabajando mucho    hoy. Corte un monton de le[a     para el invierno y Enoki-"},
				{true, true, 22, "ENOKI                            Pense, que, pues, la isla se     veria mas viva si traigo unos    conejitos. {Sabes?"},
				{fals, true, 20, "ENOKI                            Pero pues resulta que comenzaron a multiplicarse demasiado y      ahora los tengo que mantener    alejados del jardin."},
				{true, true, 26, "AARON                            {Que te parece si vamos a visitarlas cuevas que estan un poco mas al norte de aqui?"},
				{fals, true, 24, "AARON                            He oido que podrian tener piedraspreciosas, y podriamos conseguir algo de dinero por ellas."},
				{fals, fals, 14, "MAPLE                            Eso no suena demasiado dificil."},
				{fals, fals, 15, "MAPLE                            Hey... y gracias por la          habitacion."},
				{fals, true, 25, "AARON                            No hay de que."},
				{fals, true, 22, "ENOKI                            Oh, y si aun no has conocido a   Scout, }es un tipo genial! El    estara metido en el bunker aya  afuera."},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page(lc);
			return 0;
			break;
		}

		case 17:
		{
			line lc[32] = {
				{fals, fals, 0, "BG: Trailer Home"},
				{true, true, 22, "ENOKI                            Bueno... }Primer dia terminado!  Creo que ha sido un dia muy      divertido."},
				{true, fals, 17, "MAPLE                            {Sabes que? Estoy de acuerdo.    Este ha sido el dia mas          interesante que he tenido en    mucho tiempo."},
				{true, true, 24, "AARON                            {Estas lista para cambiar de     opinion, a que la isla fue mala  idea?"},
				{fals, fals, 16, "MAPLE                            Apenas llegue hoy, le dare algo  de tiempo antes de darle una     ultima opinion."},
				{fals, true, 25, "AARON                            Bueno me da gusto tenerte. La    verdad lamento que solo tengamos ese mueble, pero estoy          trabajando en casa nueva."},
				{fals, fals, 18, "MAPLE                            Oh, no te preocupes, dormia en unmueble en mi apartamento         anterior. Ya estoy acostumbrada."},
				{true, true, 20, "ENOKI                            Aw, {dormias en el mueble?"},
				{fals, fals, 16, "MAPLE                            Era un mueble maravilloso."},
				{true, true, 26, "AARON                            Bueno, vamonos a dormir ya. Estoycansado de tanta le[a que corte."},
				{fals, true, 24, "AARON                            {Nos vemos ma[ana?"},
				{true, true, 22, "ENOKI                            }Seguro que encontramos mas      cosas que podamos hacer!"},
				{fals, fals, 15, "MAPLE                            Muchas gracias por todo. Tratare de aportar mi granito de arena   sin ser grosera de esta isla.   }Buenas noches!."},
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
				{fals, fals, 0, "                                 Ugh... Mi cabeza...              {Por que no puedo dormir?"},
				{fals, fals, 0, "                                 {No se supone que me quedaria    bien dormido despues del viaje y un largo dia de trabajo duro?"},
				{fals, fals, 0, "                                 {Y de donde viene esa luz de     fuera? Puede que sea Scout..."},
				{fals, fals, 0, "                                 Quiza deberia salir a echar      un vistazo y ver lo que es."},
				{fals, fals, 0, "S04:02"},
				{fals, fals, 0, "                                 {Pero que-?                      {Es eso un Mons d'Plonj? {Esta   escribiendo algo?"},
				{fals, fals, 0, "                                 Deberia ir a mirar antes de que  algo malo pueda suceder."},
				{fals, fals, 0, "S04:03"},
				{fals, fals, 0, "                                 Hmmm, hmmm... hmmm...."},
				{fals, fals, 0, "S04:04"},
				{fals, fals, 0, "MAPLE                            }HEY! }IDENTIFICATE O QUEMARE TU CARA!"},
				{fals, fals, 0, "S04:05"},
				{fals, fals, 0, "SF: Rufus Squeak"},
				{fals, fals, 0, "                                 AHHHH?!"},
				{fals, fals, 0, "                                 }AH, UH.. UH, RUFUS!             }RUFUS THIBODEAUX!"},
				{fals, fals, 0, "                                 }NO LA CARA, LA NECESITO!"},
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
				{fals, fals, 0, "MAPLE                            Ah, {asi que eres el tal Rufus?  Primo de Del, {cierto?           Encantada, soy Maple."},
				{fals, fals, 0, "RUFUS                            Oh, {acaso eres una elfa de      fuego? Ojala y lo hubiera sabido antes de intentar encender este  fuego."},
				{fals, fals, 0, "MAPLE                            {Que estas haciendo aqui?"},
				{fals, fals, 0, "RUFUS                            Estoy solo mirando.   Tengo el   ojo puesto en las islas Bill &   Jim de al lado."},
				{fals, fals, 0, "RUFUS                            Me agrada la idea de tener un    lugar que sea unicamente para mi mismo, sin tener que tratar con  nadie."},
				{fals, fals, 0, "RUFUS                            Aunque tambien me preocupa lo    temerario que es todo esto de    tener una 'isla privada'"},
				{fals, fals, 0, "RUFUS                            Ademas todos los que viven cerca de Quebec hablan con ese acento  tan molesto..."},
				{fals, fals, 0, "MAPLE                            Eso es algo tambien me           preocupaba. Enoki es una buena   chica, pero a veces ese acento   consigue sacarme de quicio."},
				{fals, fals, 0, "MAPLE                            Empiezo a sentir como el acento  de Quebec se apodera de la voz   de Aaron tambien.                Es una molestia."},
				{fals, fals, 0, "MAPLE                            Por cierto, {que escribes?"},
				{fals, fals, 0, "RUFUS                            ...                              Vas a pensar que es una tonteria pero es un dibujo."},
				{fals, fals, 0, "MAPLE                            Mira, despues de haber vendido   todas mis pertenencias para      venira esta isla, te aseguro que tu dibujo no es una tonteria."},
				{fals, fals, 0, "RUFUS                            ... Okay, es una rana. Vi esta   imagen cuando era ni[o, y me hacesentir nostalgico por algun      motivo."},
				{fals, fals, 0, "RUFUS                            Aunque no puedo recordar como era realmente, pero sigo intentando.No se por que, pero siento que   debo hacerlo."},
				{fals, fals, 0, "MAPLE                            Si, ahora que lo explicas, si    suena algo tonto. }Pero se a lo  que te refieres!"},
				{fals, fals, 0, "MAPLE                            Por cierto... {Tienes en donde   dormir? No puedo ofrecer mucho,  pero hace frio aqui afuera y     tenemos ducha adentro."},
				{fals, fals, 0, "RUFUS                            Gracias, pero me voy en la       ma[ana. Y la verdad no quisiera  hablar con alguien mas,  aunque  tu me caiste bien."},
				{fals, fals, 0, "MAPLE                            Igual, fue genial en poder       hablar con alguien que tenga     tanto sentido"},
				{fals, fals, 0, "S04:07"},
				{fals, fals, 0, "BG: fadeout"},
				{fals, fals, 0, "MAPLE                            Cuidate mucho, {si?              Ravi de vous rencontrer, Rufus."},
				{fals, fals, 0, "RUFUS                            }Tu tambien! Ravi de vous        rencontrer, Maple."},
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
				{fals, fals, 0, "                                 }Hola a todos, llego el momento!                                  }Soy Scout y ya llegue!"},
				{fals, fals, 0, "S_STV_02"},
				{fals, fals, 0, "                                 Es emocionante tener por fin una audiencia de verdad, se[ores y   se[oras. Ehm... se[or y se[oras.."},
				{fals, fals, 0, "                                 Hoy es 1 de Abril, }Y ya saben   lo que eso significa!"},
				{fals, fals, 0, "                                 Maple se ha mudado a la isla y   la hemos tenido aqui por un dia  entero. }Como pasa el tiempo!"},
				{fals, fals, 0, "                                 Es una, ehm, broma...   Porque yaes 1 de Abril, y tiene con       nosotros todo un mes entero."},
				{fals, fals, 0, "                                 M-mejor cambiemos de tema...     }Bueno! }Al fin pude recuperar   la contrase[a de                 mi computadora...!"},
				{fals, fals, 0, "                                 Oh, si, si, otro dato.   }Tres   nuevas personas se mudaran a la  isla!"},
				{fals, fals, 0, "                                 Aunque no estoy seguro de que    podamos encontrar nuevos isle[os potenciales en Craigslist."},
				{fals, fals, 0, "                                 Sus nombres son Diana, Eleanor,  y Olivier. Y ellos estaran en la cabana del noreste.."},
				{fals, fals, 0, "                                 Olivier tiene un invernadero en  el norte, y Diana es una gran    aprendiz de navegacion. Se       ocupara de conducir el barco."},
				{fals, fals, 0, "                                 }Asi que a que darles una gran bienvenida!"},
				{fals, fals, 0, "S_STV_01"},
				{fals, fals, 0, "                                 Muy bien, ya esta...             Supongo que los vere a todos mas tarde. }Muchas gracias por       estar ahi!"},
				{fals, fals, 0, "S05:01"},
				{fals, fals, 0, "BG: fadeout"},
				{fals, fals, 0, "ENOKI                            Mmmmmm....                       Hice palomitas, la verdad no me  quiero levantar para ir al       microondas."},
				{fals, fals, 0, "SF: Hey Maple"},
				{fals, fals, 0, "ENOKI                            {Puedes ir a por ellas, Maple?   {S'il te plait?"},
				{fals, fals, 0, "MAPLE                            Ugh, consigance un cuarto si?."},
				{fals, fals, 0, "AARON                            Maple, esta es nuestra casa."},
				{fals, fals, 0, "MAPLE                            Lo que tu digas."},
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
					{fals, fals, 0, "                                 1 de Abril, 2000 -               Registro de Exploracion No. 48"},
					{fals, fals, 0, "                                 La transmision de Scout TV tuvo  algunos espectadores esta vez.   Espero que les haya gustado."},
					{fals, fals, 0, "                                 La proxima vez puede que tenga   los suficientes como para hacer  el primer Expo Scout."},
					{fals, fals, 0, "                                 Las cosas avanzan muy lentamente pero tengo financiacion, asi que-"},
					{fals, fals, 0, "                                 Estoy feliz de poder trabajar en esto por diversion."},
					{fals, fals, 0, "                                 El 'Bolsillo Magico' no estara   listo hasta cierto tiempo, aunqueel prototipo parece prometedor."},
					{fals, fals, 0, "                                 Tal vez podria ser util para     aquella solicitud que me hizo    Aaron"},
					{fals, fals, 0, "                                 acerca de hacer carreras de      autos en la isla."},
					{fals, fals, 0, "                                 Podria meter toda una pista de   carreras en la dimension del     bolsillo magico."},
					{fals, fals, 0, "                                 Asi no tendriamos por que dejar  todo el lugar hecho un desastre."},
					{fals, fals, 0, "                                 Claro que todo ha de salir bien. Pero si se queda atorado..."},
					{fals, fals, 0, "                                 No, todo tiene que ir perfecto."},
					{fals, fals, 0, "                                 COM: Endscene"}};
				dialogue_page_lite(lc);
				return 0;
			}
			else
			{
				line lc[32] = {
					{fals, fals, 0, "                                 1 de Mayo, 2000 -                Registro de Exploracion No. 68"},
					{fals, fals, 0, "                                 Dos nuevos aldeanos llegaron, unose ve medio raro pero Enoki      confia en el."},
					{fals, fals, 0, "                                 Al parecer el otro chico nuevo esun gran chef, su supuesto        apellido es Pizza."},
					{fals, fals, 0, "                                 Debo descubrir su nombre real,   la curiosidad me esta matando."},
					{fals, fals, 0, "                                 Rufus ha sido fastidioso y ha    decidido interrumpir Scout TV."},
					{fals, fals, 0, "                                 No se si tiene algun tipo de     problema o molestia conmigo."},
					{fals, fals, 0, "                                 Francamente, estoy un poco       preocupado por el. Quiza deberia mantener un ojo."},
					{fals, fals, 0, "                                 Osea, vigilarlo aun mas que      antes."},
					{fals, fals, 0, "                                 Al parece ser que alguna compa[iaquiere almacenar un monton de    gasolina en la isla."},
					{fals, fals, 0, "                                 Me di cuenta cuando ellos        la trajeron accidentalmente."},
					{fals, fals, 0, "                                 {Que planean hacer con toda esa  gasolina?  Quiza nunca lo        sepamos."},
					{fals, fals, 0, "                                 Esperemos que todos esten bien   este mes. Me estoy divirtiendo   mucho con ellos."},
					{fals, fals, 0, "                                 Scout out. Jeje, 'scout out'."},
					{fals, fals, 0, "                                 COM: Endscene"}};
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
					{fals, true, 0, "                                 29 de Marzo, 2000 -              Reg. de Exploracion N45 (Borrado)"},
					{fals, true, 0, "                                 Este tiene que ser el mejor dia  desde que llegue a la isla Bill yJim."},
					{fals, true, 0, "                                 Definitivamente no extra[o       aquellas otras islas."},
					{fals, true, 0, "                                 Ese tal Rufus ha sido bien       latoso. Siempre balbuceando sobreconspiraciones."},
					{fals, true, 0, "                                 Espero que se la este pasando    bien alla solo en la isla."},
					{fals, true, 0, "                                 Pero dios mio, esa Maple... ay   ya yay. Creo que hoy fue la      primera vez que sonrio conmigo,"},
					{fals, true, 0, "                                 desde que ella llego a la isla."},
					{fals, true, 0, "                                 Probablemente no es nada pero no he podido dormir desde ese       momento."},
					{fals, true, 0, "                                 Siempre dice cosas para burlarse de mi, pero creo que se hace la  dificil."},
					{fals, true, 0, "                                 He visto como trata a Aaron y    Enoki, ella es asi con todos."},
					{fals, true, 0, "                                 Mmm... Quiza algun dia pueda     encontrar la manera de acercarme a ella. Ojala."},
					{fals, true, 0, "                                 Hare algo que pueda              impresionarla."},
					{fals, true, 0, "                                 Actua como una desinteresada,    pero parece que gustan los librosy comer."},
					{fals, true, 0, "                                 Quiza no me guste lo mismo que   a ella, pero tambien me agradan  los libros y la comida."},
					{fals, true, 0, "                                 Pero seria un problema si le     gustan los fortachones, soy mas  bien como Grimace de McDonald's."},
					{fals, true, 0, "                                 Bueno ya esta, podria inventarme algo para ponerme en forma."},
					{fals, true, 0, "                                 Despues de todo ella ME SONRIO.  Puede que sea porque me tropece"},
					{fals, true, 0, "                                 con algo, pero lo mas seguro es  que piensa que soy mono."},
					{fals, true, 0, "                                 Tengo que borrar este registro   cuando termine de escribirlo."},
					{fals, fals, 0, "COM: Endscene"}};
				dialogue_page_lite(lc);
				return 0;
			}
			else
			{
				line lc[32] = {
					{fals, fals, 0, "                                 29 de Abril, 2000 -              Reg. de Exploracion N65 (Borrado)"},
					{fals, fals, 0, "                                 Ese chico nuevo, no tengo        oportunidad con Maple."},
					{fals, fals, 0, "                                 En primer lugar, {aparentemente  se conocen? {el la llama         repartidora de pizzas?"},
					{fals, fals, 0, "                                 Estoy acabado. Completamente.    Tambien podria darse por vencido."},
					{fals, fals, 0, "                                 Tal vez deberia aprender a       cocinar algo por una vez."},
					{fals, fals, 0, "                                 Definitivamente necesito ponerme en forma, de verdad."},
					{fals, fals, 0, "                                 Supongo que no seria bueno       mencionarselo a Guy."},
					{fals, fals, 0, "                                 Tal vez solo trabaje en mi mismo y lo deje pasar a menos que      alguien lo mencione."},
					{fals, fals, 0, "                                 ...Si."},
					{fals, fals, 0, "                                 Necesito dejar de escribir estos registros sobre mi falta de vida amorosa."},
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
					{fals, fals, 0, "                                 30 de Marzo, 2000 -              Reg. de Exploracion N46 (Borrado)"},
					{fals, fals, 0, "                                 Ese tal Rufus era un verdadero   dolor en los patookas.           Constantemente parloteando sobre"},
					{fals, fals, 0, "                                 esas cosas de la conspiracion.   Esa gente de la compa[ia me      envioun mensaje realmente"},
					{fals, fals, 0, "                                 criptico hoy."},
					{fals, fals, 0, "                                 Aparentemente ya no estan        interesados en los 'resultados', solo quieren que instale mas"},
					{fals, fals, 0, "                                 equipos de vigilancia. {Es       oficial? {Quizas quieren que     ScoutTV sea una transmision real?"},
					{fals, fals, 0, "                                 Sospecho que tiene que ver con   ese tal Rufus."},
					{fals, fals, 0, "                                 Me siguen preguntando por el,    aunque no trabajamos juntos."},
					{fals, fals, 0, "                                 Es como si quisieran arrestarlo, pero estan esperando que se haga lo que sea que esta inventando."},
					{fals, fals, 0, "                                 No me sorprenderia."},
					{fals, fals, 0, "                                 Si, este registro no se puede    dejar en mi PC."},
					{fals, fals, 0, "COM: Endscene"}};
				dialogue_page_lite(lc);
				return 0;
			}
			else
			{
				line lc[32] = {
					{fals, fals, 0, "                                 30 de Abril, 2000 -              Reg. de Exploracion N65 (Borrado)"},
					{fals, fals, 0, "                                 He estado pensando mucho en la   flor Apres ultimamente."},
					{fals, fals, 0, "                                 No puedo evitar preguntarme si   esa chica Enoki tomo algo. Sus   ojos..."},
					{fals, fals, 0, "                                 Bueno, nunca puedo mirar lo      suficientemente bien para ver si el 'anillo' esta ahi o no."},
					{fals, fals, 0, "                                 Pero explicaria mucho."},
					{fals, fals, 0, "                                 En realidad, ahora que lo pienso,despues de escuchar sobre el, er-SEGUNDO efecto secundario..."},
					{fals, fals, 0, "                                 Puede que no sea una mala idea   estar atento y ver si sucede     algo."},
					{fals, fals, 0, "                                 No quiero que me pase nada malo  ni a mi ni a nadie."},
					{fals, fals, 0, "                                 Ya veremos."},
					{fals, fals, 0, "                                 {Sabes que? Pudrete. No mereces  oir lo que les esta pasando a losTremblay."},
					{fals, fals, 0, "                                 Se quedan fuera de esto y voy a  borrar este registro."},
					{fals, fals, 0, "                                 COM: Endscene"}};
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
					{fals, fals, 0, "                                 TIME RAIDERS: GENESIS            a fan creation by                ICHABOD 'SCOUT' WILLIAMS"},
					{fals, fals, 0, "                                 The time for reckoning was upon  him, Jahn-Jahn Gazebo felt. It   was only a matter of time before"},
					{fals, fals, 0, "                                 Star Space Goblin Emperor Wizard would catch up to his planet. Butthe Time Raiders   were prepared."},
					{fals, fals, 0, "                                 The squeebo-zeebos had warned himahead of time, so he and his bandwere ready."},
					{fals, fals, 0, "                                 They were going to hide in plain sight by pretending to be a      different band - 'Space Raiders'."},
					{fals, fals, 0, "                                 Jahn-Jahn had given his guitar   sword a new paint job."},
					{fals, fals, 0, "                                 Nexus, his quipster sidekick, hadfashioned his keyboard to look"},
					{fals, fals, 0, "                                 like a computer keyboard, and    swapped out his Mondo Glasses    for a pair of normal sunglasses."},
					{fals, fals, 0, "                                 Ninjette, their drummer and      ninja, had disguised her mondo"},
					{fals, fals, 0, "                                 nunchucks / drumsticks as a pair of chicken drumsticks. They      looked very delicious."},
					{fals, fals, 0, "                                 The time had come. They decided  to swap genres. Country music waswhat they were going with."},
					{fals, fals, 0, "                                 Soon enough, the Star Space      Goblin Emperor Wizard had landed on Sqeeb-Sqeeb 9."},
					{fals, fals, 0, "                                 'AAALRIGHT!' he exclaimed, 'I AM SEARCHING FOR JAHN-JAHN GAZEBO!"},
					{fals, fals, 0, "                                 HIS SKULL WILL MEET MY WICKED    FIST OF EVIL!.. FOR EVIL!'"},
					{fals, fals, 0, "                                 'Not so fast, Star Space Goblin  Emperor Wizard!' said Jahn-Jahn, wearing a fake wig."},
					{fals, fals, 0, "                                 'How do you know, random         civilian?' asked the Star Space"},
					{fals, fals, 0, "                                 Goblin Emperor Wizard, who did   not recognize his nemesis."},
					{fals, fals, 0, "                                 'I wrote a song about it! Wanna  hear it? Here it goes!' And withthat, the song began."},
					{fals, fals, 0, "                                 Because it was country music, it sucked so hard that all of his   goons died."},
					{fals, fals, 0, "                                 The Star Space Goblin Emperor    Wizard himself was suspicious"},
					{fals, fals, 0, "                                 that it was actually them, but   Ninjette thought fast."},
					{fals, fals, 0, "                                 She tossed one of the chicken    legs into his mouth, which he"},
					{fals, fals, 0, "                                 thought was delicious. It bought them enough time to leave."},
					{fals, fals, 0, "                                 That's when they met a dude namedScout, who was a fantastic pilot who helped them escape."},
					{fals, fals, 0, "                                 'Wow, Scout! You're such a great pilot!' said Jahn-Jahn. 'Do you  want to join the Time Raiders?'"},
					{fals, fals, 0, "                                 Scout immediately accepted, and  everyone lived happily ever      after."},
					{fals, fals, 0, "                                 I can't believe this story got   rejected from the Time Raiders   script competition, it's perfect."},
					{fals, fals, 0, "COM: Endscene"}};
				dialogue_page_lite(lc);
				return 0;
			}
			else
			{
				line lc[32] = {
					{fals, fals, 0, "                                 TIME RAIDERS: NEO GENESIS DAWN   a fan creation by                ICHABOD 'SCOUT' WILLIAMS"},
					{fals, fals, 0, "                                 Jahn-Jahn Gazebo was sad.        Very sad.                        He felt a deep sadness."},
					{fals, fals, 0, "                                 This is because he had accident- ally consumed the sadness pepper of Sector 9."},
					{fals, fals, 0, "                                 'What is it, Jahn-Jahn?' asked   Scout, who was his first officer."},
					{fals, fals, 0, "                                 'Peppers suck,' he replied.      He was right."},
					{fals, fals, 0, "                                 They didn't go on an adventure   this time, since they let Scout  decide their destination."},
					{fals, fals, 0, "                                 Scout is a very indecisive       individual, you see."},
					{fals, fals, 0, "                                 In fact, Scout was getting both  writer's block and a horrible    pain in his wrist."},
					{fals, fals, 0, "                                 So, the Star Space Goblin Emperordecided to randomly give up and  give them his ship."},
					{fals, fals, 0, "                                 All evil in the universe was     magically zapped away and all    was well the end I'm tired."},
					{fals, fals, 0, "                                 ..."},
					{fals, fals, 0, "                                 I'm just not cut out to be a     writer, am I? Far too lazy."},
					{fals, fals, 0, "COM: Endscene"}};
				dialogue_page_lite(lc);
				return 0;
			}
			break;
		}

		case 26:
		{
			line lc[32] = {
				{fals, fals, 0, "                                 Por fin..."},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page_lite(lc);
			return 0;
			break;
		}

		case 27:
		{
			line lc[32] = {
				{fals, fals, 0, "S_DOCKS"},
				{fals, true, 0, "CAP'N NICHOLAS                   }Anda, se[orita! {Esta' lista    pa'l viaje?"},
				{fals, true, 0, "DIANA                            }Si, capitan!"},
				{fals, true, 0, "CAP'N NICHOLAS                   Recuerda lo que te he dicho -    }Cuidaito con la' piedra' y      atenta a la velosida'!"},
				{fals, true, 0, "DIANA                            }Si, capitan!"},
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
				{fals, true, 0, "SCOUT                            }Hola a todos! }Scout ha llegado!}Es tiempo de esa hora!"},
				{fals, fals, 0, "S_STV_02"},
				{fals, true, 0, "                                 }Scout TV es algo regular!       Como pueden ver, }me siento un   verdadero reportero!"},
				{fals, true, 0, "                                 Todos hemos estado en la isla    durante tres meses. }No sabria   decir si llevamos un dia o un    millon   de a[os!"},
				{fals, true, 0, "                                 Bueno. Ha pasado un tiempo desde la ultima vez, }Pero parece que  se nos han unido dos personas    mas!"},
				{fals, true, 0, "                                 Primero tenemos a CESAR de la    Cruz, un invitado especial de    nuestra Reina Enoki."},
				{fals, true, 0, "                                 Aparentemente, fue un famoso     abogado que ahora busca un nuevo comienzo."},
				{fals, true, 0, "                                 Tambien tenemos a un nuevo chico que se esta mudando. }Su nombre  es Guy y es cocinero!"},
				{fals, true, 0, "                                 }Ya no puedo esperar a ver su    comida!   }Dicen que su Jabalaya es genial!"},
				{fals, true, 0, "                                 Ademas nos estamos acercando a   la Scout Expo, }y solo es        cuestion de tiempo tenerla       preparada!"},
				{fals, true, 0, "                                 Tambien ordene un monton de copias de los ultimos volumenes de    Time Raiders porque se que       algunos"},
				{fals, fals, 0, "BG: fadeout"},
				{fals, fals, 0, "S_STV_03"},
				{fals, fals, 0, "                                 . . . ."},
				{fals, fals, 0, "BG: rain"},
				{fals, fals, 0, "S_STV_04"},
				{fals, true, 0, "RUFUS                            Yo, er- hmm.. si, buenas noches, vecinos de la isla. Soy Rufus    Thibodeaux, y si no me conocen   ahora, lo haran mas tarde."},
				{fals, true, 0, "                                 Interrumpo esta transmision para dar un ultimatum. }O me entregan la isla o tendre que-!"},
				{fals, fals, 0, "BG: fadeout"},
				{fals, fals, 0, "S_STV_03"},
				{fals, fals, 0, "                                 . . . ."},
				{fals, fals, 0, "S_STV_01"},
				{fals, fals, 0, "                                 -and that's all, folks! See y'allnext time!"},
				{fals, fals, 0, "S05:02"},
				{fals, true, 0, "                                 }-Y eso es todo, amigos!         }Nos vemos para la proxima!"},
				{fals, true, 0, "ENOKI                            Aw, me perdi el final de Scout   TV... La esperaba con ansias..."},
				{fals, true, 0, "MAPLE                            Oye, {que ese menso no es el     sobrino de Del? Estuvo aqui en la isla por unos meses, creo."},
				{fals, true, 0, "AARON                            Que transmision tan extra[a."},
				{fals, true, 0, "ENOKI                            Voy a por un refresco."},
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
				{fals, true, 0, "ENOKI                            Oye, {Aaron?"},
				{fals, true, 0, "AARON                            *Awn* {Si?"},
				{fals, true, 0, "ENOKI                            {Eres feliz aqui?"},
				{fals, true, 0, "AARON                            Claro que lo soy, Noke."},
				{fals, fals, 0, "S11:02"},
				{fals, true, 0, "ENOKI                            Aver espera, no {Enserio eres    feliz con todo esto? Me preocupo por ti."},
				{fals, true, 0, "AARON                            Supongo que estoy algo           melancolico, pero eso es todo."},
				{fals, true, 0, "ENOKI                            {A que te refieres?"},
				{fals, true, 0, "AARON                            Ya saber. Maple tenia razon, la  unica razon por la que estamos   aqui es porque te ganaste ese    dinero."},
				{fals, true, 0, "AARON                            Lo hemos dado todo por este lugary si algo sale mal, No tendremos absolutamente nada."},
				{fals, true, 0, "ENOKI                            Ya me conoces, tengo la suerte demi lado. Ademas te tengo a mi    lado, eso es todo lo que         necesito."},
				{fals, true, 0, "AARON                            Puede que dejes de sentirte asi  cuando pases hambre. No sabes lo que es tener hambre."},
				{fals, true, 0, "ENOKI                            No quiero pensar en ello...      Si lo hago, no podre dormir."},
				{fals, fals, 0, "S11:03"},
				{fals, true, 0, "ENOKI                            Que te parece si por ahora somos felices y despues nos apuramos deeso?"},
				{fals, true, 0, "AARON                            Supongo que si. Buenas noches,   Noke."},
				{fals, true, 0, "ENOKI                            Buenas noches, Aire."},
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
				{fals, true, 0, "CESAR                            }Oh! }Encantado de conocerte!    Debes ser uno de los locales.    Puedes llamarme Cesar."},
				{fals, true, 0, "                                 Lo creas o no, era un abogado.   Aunque no era uno bueno."},
				{fals, fals, 0, "BG: CRUZ02"},
				{fals, true, 0, "                                 Y pues al decir la verdad no     tenia un titulo, pero ahi yo     estaba ganando los casos uno por uno."},
				{fals, true, 0, "                                 {Y por que te cuento todo esto,  si ni siquiera te conozco?"},
				{fals, true, 0, "                                 ..."},
				{fals, fals, 0, "BG: CRUZ01"},
				{fals, true, 0, "                                 ..."},
				{fals, true, 0, "                                 Es mejor si todos nos conocemos  un poco. {No crees?"},
				{fals, true, 0, "                                 Me gusta mantenerme ocupado y    estoy cumpliendo mi sue[o de     tener una tienda en un lugar     tranquilo."},
				{fals, true, 0, "                                 Si ves a algun cliente extra[o   que este enfadado conmigo,       avisame para poder... ehm.       Esconderme. }Merci!"},
				{fals, true, 0, "                                 De todas formas, {En que te      podria ayudar hoy?"},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page(lc);
			return 0;
			break;
		}

		case 31:
		{
			line lc[32] = {
				{fals, fals, 0, "BG: CRUZ01"},
				{fals, true, 0, "                                 }Enoki Ramirez! Er... Ahora      Tremblay, {no? Muchas gracias pordejarme venir aqui."},
				{fals, true, 0, "                                 Prometo que no causare problemas aqui, aunque esos ultimos        clientes mios..."},
				{fals, fals, 0, "BG: CRUZ02"},
				{fals, true, 0, "                                 Mira, no fue MI culpa que pudierafingir ser un buen abogado,      {sabes?"},
				{fals, fals, 0, "BG: CRUZ01"},
				{fals, true, 0, "                                 Se que me entiendes. Solo avisamesi aparecen buscandome para poderesconderme a tiempo. {Okay?"},
				{fals, true, 0, "                                 Mi sue[o desde nino es tener mi  tienda en un pueblo chiquito,    aunque no tenga muchas cosas que vender."},
				{fals, true, 0, "                                 Ahora que tengo la oportunidad,  }dare lo mejor de mi!      {Como puedo ayudarte hoy?"},
				{fals, true, 0, "                                 . . . ."},
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
				{fals, true, 0, "RUFUS                            Buenas tardes a todos. Parece quemi amenaza no fue suficiente     clara y al parecer nadie"},
				{fals, true, 0, "RUFUS                            ha mostrado ni el mas minimo     indicio de miedo durante el      ultimo mes. Han cometido un graveerror, ya que"},
				{fals, true, 0, "RUFUS                            planeo tomar la isla a la fuerza si es NECESARIO."},
				{fals, fals, 0, "S06:01"},
				{fals, true, 0, "MAPLE                            ...Ugggh, callate, Rufus, Intentodormir."},
				{fals, true, 0, "RUFUS                            He desarrollado un-"},
				{fals, fals, 0, "S06:02"},
				{fals, true, 0, "ENOKI                            No recuerdo haber prendido la    tele esta ma[ana, {Maple tu la   prendiste?"},
				{fals, true, 0, "MAPLE                            ..."},
				{fals, fals, 0, "S06:03"},
				{fals, true, 0, "AARON                            Tal vez le aprete en accidente.  {La apago?"},
				{fals, true, 0, "MAPLE                            ...mmmrff... tele... apagada...  sabado..."},
				{fals, true, 0, "RUFUS                            En menos de treinta segundos     liberare mi-"},
				{fals, fals, 0, "BG: fadeout"},
				{fals, true, 0, "AARON                            Okay, se acabo."},
				{fals, true, 0, "ENOKI                            {De que iba todo eso?"},
				{fals, true, 0, "AARON                            Ni idea, Noke."},
				{fals, true, 0, "MAPLE                            ..."},
				{fals, fals, 0, "SF: Boom"},
				{fals, true, 0, "ENOKI                            Oye, {que es ese ruido?"},
				{fals, true, 0, "AARON                            No me gusta como suena eso...    Maple, quiza deberias levantarte."},
				{fals, true, 0, "MAPLE                            ... Grr, Voy a matar a ese       caiman..."},
				{fals, true, 0, "ENOKI                            Pero que- oh no..."},
				{fals, true, 0, "AARON                            Enoki, tu y Maple corran hacia elbunker de Scout, yo ire al oeste para ver si los demas estan bien."},
				{fals, true, 0, "MAPLE                            Excusez-moi, puedo cuidar de mi-"},
				{fals, true, 0, "AARON                            Vas a ir al bunker, ademas alli  podrias seguir durmiendo."},
				{fals, true, 0, "MAPLE                            Hey, no hay necesidad de ser tan agresivo conmigo."},
				{fals, fals, 0, "COM: Endscene"}};
			dialogue_page(lc);
			return 0;
		}

		case 33:
		{
			line lc[32] = {
				{fals, fals, 0, "S07:01"},
				{fals, fals, 0, "BG: fadeout"},
				{fals, true, 0, "MAPLE                            Dime la verdad, {oui?            {Tu hiciste todo este lugar?"},
				{fals, true, 0, "SCOUT                            }Imposible! Aunque me habria     gustado conseguirlo por mi mismo."},
				{true, true, 0, "S07:02"},
				{true, true, 0, "..."},
				{true, true, 0, "S07:03"},
				{fals, true, 0, "SCOUT                            }MAPLE, CUIDADO!"},
				{true, true, 0, "S07:04"},
				{fals, true, 0, "MAPLE                            ... Scout, {te encuentras bien?"},
				{fals, true, 0, "RUFUS                            Ow. Aunque me golpee un poco la  espalda. Creo que estare bien."},
				{true, true, 0, "S07:05"},
				{fals, true, 0, "MAPLE                            {Que hace toda esta gasolina     aqui?"},
				{fals, true, 0, "SCOUT                            Por nuestro bien, mas te vale    tener cuidado con tus poderes."},
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
					{fals, true, 0, "MAPLE                            Que... {Que demonios estoy viendoahora mismo?"},
					{true, true, 0, "S07:07"},
					{true, true, 0, "BG: rain"},
					{true, true, 0, "SF: rufus"},
					{fals, true, 0, "RUFUS                            Ichabod Williams y Maple         Tremblay, }Que sorpresa!   Me    alegra verlos por aqui."},
					{fals, true, 0, "RUFUS                            Al fin hemos podido reunirnos    todos."},
					{true, true, 0, "S07:08"},
					{fals, true, 0, "SCOUT                            RUFUS QU-, {QUe ESTAS HACIENDO?"},
					{fals, true, 0, "MAPLE                            }DEJAME EN PAZ, IMBECIL!"},
					{fals, true, 0, "RUFUS                            Sera mejor que te ponga una      pulsera anti-magia para evitar   que te de una de esas...         Chispas de inspiracion"},
					{true, true, 0, "BG: fadeout"},
					{true, true, 0, "S07:14"},
					{fals, true, 0, "RUFUS                            Muy bien, ahora que tenemos a    todos los Tremblay reunidos en unmismo  lugar...                  }Podemos comenzar!"},
					{fals, fals, 0, "COM: Endscene"}};
				dialogue_page(lc);
			}

			{
				line lc[32] = {
					{true, true, 0, "BG: groovy"},
					{true, true, 0, "S07:09"},
					{fals, true, 0, "RUFUS                            En primer lugar, hagamos una     breve introduccion. Soy Monsieur Rufus Thibodeaux, y hoy sere su  profesor."},
					{fals, true, 0, "RUFUS                            Presten atencion.  Nadie parece  hacerme caso, asi que            haremos un examen al final       de la sesion."},
					{true, true, 0, "S07:10"},
					{fals, true, 0, "RUFUS                            Leccion numero uno. Repitan      conmigo, 'Rufus no es bajo. Solo tiene huesos peque[os.'"},
					{fals, true, 0, "MAPLE                            ..... {Estas bromeando?"},
					{fals, true, 0, "RUFUS                            Eso no se parece mucho a la fraseque tienes que decir ahora,      {no, Maple?"},
					{true, true, 0, "S07:11"},
					{fals, true, 0, "RUFUS                            Parece que todos estan fallado   esta leccion. Asi que pasemos a  la siguiente... Hablemos de la   flor Apres. Una compa[ia"},
					{fals, true, 0, "RUFUS                            me contrato para estudiarla. Al  igual que Ichabod... o 'Scout',  un chico nativo y conocido por   todos los de la isla."},
					{fals, true, 0, "RUFUS                            Las 'propiedades metafisicas' de las flor son bien padres, asi quea pesar de que las instrucciones decian"},
					{fals, true, 0, "RUFUS                            que no debia hacerlo. Un dia me  aburri y decidi darle unas       mordiditas. {Y saben lo que paso despues de eso?"},
					{true, true, 0, "S07:12"},
					{fals, true, 0, "RUFUS                            Me encontre viajando a traves delmultiverso. Explore todo tipo de mundos diferentes, algunos       similares a este"},
					{fals, true, 0, "RUFUS                            y otros completamente alejados deesta realidad. {Pero saben lo    que descubri en casi cada uno de ellos?"},
					{true, true, 0, "S07:13"},
					{fals, true, 0, "RUFUS                            Habia una extra[a tendencia de   mujeres muy  atractivas que      luchaban contra el mal."},
					{fals, true, 0, "RUFUS                            Junto a hombres extravagantes    que servian como burla o como    incompetentes villanos."},
					{fals, true, 0, "RUFUS                            Al final todos ellos eran        reemplazados por villanas mas    aptas e incomprendidas que eran malvadas porque"},
					{fals, true, 0, "RUFUS                            un hombre las hizo asi. {Quieren saber que es lo que pense de eso?"},
					{fals, true, 0, "MAPLE                            Aver,Aver, espera."},
					{true, true, 0, "S07:14"},
					{fals, true, 0, "MAPLE                            {De verdad me estas diciendo que te has vuelto malvado por el     simple hecho de que una flor     te dijo"},
					{fals, true, 0, "MAPLE                            que eres el 'chico malo'?"},
					{true, true, 0, "S07:16"},
					{fals, true, 0, "RUFUS                            Creo que con un ataque           preventivo, puedo mantener       intactos tanto mi imagen como mi libertad. Si."},
					{fals, true, 0, "RUFUS                            Desde mi punto de vista y        habiendo estudiado sus atributos,Maple parece ser el 'personaje   principal' y este fue mi mejor plan."},
					{fals, fals, 0, "COM: Endscene"}};
				dialogue_page(lc);
			}

			{
				line lc[32] = {
					{true, true, 0, "S07:15"},
					{fals, true, 0, "ENOKI                            Monsieur Rufus, {puedo ir al     ba[o?"},
					{true, true, 0, "S07:16"},
					{fals, true, 0, "RUFUS                            Podras ir despues de la leccion. Casi ya termina."},
					{true, true, 0, "S07:17"},
					{fals, true, 0, "RUFUS                            A ver, {por donde iba...?"},
					{true, true, 0, "BG: fadeout"},
					{true, true, 0, "S07:16"},
					{fals, true, 0, "AARON                            Rufus, tenemos que hablar."},
					{true, true, 0, "S07:18"},
					{fals, true, 0, "AARON                            En primer lugar. Me sorprende    que no supieras que mi esposa es maga. Y pues se le hace facil    salir de lugares apretados."},
					{fals, true, 0, "AARON                            Y en segundo lugar. Me da igual  lo que esa flor te hizo ver,     asustaste a todos mis amigos.    Chico malo."},
					{fals, true, 0, "AARON                            Eso es totalmente inaceptable.   No puedes secuestrar a la gente ymantenerla como rehenes."},
					{fals, true, 0, "AARON                            Sueltanos a todos y dejanos en   paz,      {c'est bon? {Lo captas o no?"},
					{fals, true, 0, "RUFUS                            Espera un momento, Aaron."},
					{fals, true, 0, "RUFUS                            Hay algo que deberias saber. Las puertas de esta habitacion estan totalmente selladas."},
					{fals, true, 0, "RUFUS                            Si una bomba estallara aya afueraapenas nos dariamos cuenta aqui  dentro. Pero el momento que      alguien pruebe esta flor,"},
					{fals, true, 0, "RUFUS                            abrire las puertas. Aqui les va  un desafio. Hay que tener una    pelea y si ustedes ganan, me ire de esta isla en paz."},
					{fals, true, 0, "RUFUS                            Si yo gano, me convertire en su  nuevo rey. Aunque de todos modos tienen que probar la flor. {Oui?"},
					{fals, true, 0, "RUFUS                            Una vez que vean todo lo que yo  vi, no diran que estoy loco."},
					{fals, true, 0, "RUFUS                            Ya veremos que ocurre..."},
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
					{fals, true, 0, "RUFUS                            Bueno, bueno, bueno..."},
					{fals, true, 0, "RUFUS                            }HA! }Parece que soy el ganador! }Es hora de la flor Apres!"},
					{fals, true, 0, "RUFUS                            Asi que... {Quien la probara?    {Aaron? {Que te parece si le das una probadita?"},
					{fals, true, 0, "MAPLE                            {Sabes que? Ni en tus sue[os,    pinche mocoso."},
					{true, true, 0, "S08:02"},
					{true, true, 0, "BG: rain"},
					{fals, true, 0, "RUFUS                            {A-a quien le dices mocoso?"},
					{fals, true, 0, "MAPLE                            Incluso tus peque[as piernas     roboticas se mantienen sobre las puntas de sus pies."},
					{true, true, 0, "S08:03"},
					{fals, true, 0, "MAPLE                            No se por que piensas que el     mundo es como tu sueno enfermo   que te dejo esa tal flor."},
					{fals, true, 0, "MAPLE                            Pero la vida es dificil, {sabes? Y ya bastante tenemos con        nuestros propios problemas. Me daigual  lo que viste en tus sue[os,"},
					{fals, true, 0, "MAPLE                            no hubieras venido a molestarnos en nuestra propia isla. Ni       siquiera sabiamos quien eras."},
					{fals, true, 0, "MAPLE                            Asi que volvere a amenazarte de  nuevo como amenazo a todos los   demas. Cualquier otra cosa y.."},
					{fals, true, 0, "RUFUS                            L-lo se, lo se, ya lo dijiste, mequemaras la cara."},
					{fals, true, 0, "RUFUS                            Aunque, uh, te cuidado con ese   fuego. Hay muchas cosas          inflamables aqui abajo."},
					{fals, true, 0, "MAPLE                            {CUIDADO? {Dices que tenga       cuidado despues de SECUESTRARNOS?Al final te lo has buscado, }tu  cara va a salir ardiendo!"},
					{true, true, 0, "S08:04"},
					{fals, true, 0, "CESAR                            Oye, {Maple?"},
					{true, true, 0, "S08:05"},
					{fals, true, 0, "MAPLE                            AHORA NO CESAR, }DEBO OCUPARME   DE ESTE PEQUE[O MEGALOMANO!"},
					{true, true, 0, "S08:06"},
					{fals, true, 0, "RUFUS                            N-No en serio, tu, er, uh...     Madre mia..."},
					{true, true, 0, "S08:07"},
					{fals, true, 0, "MAPLE                            }{QUE?!"},
					{true, true, 0, "BG: fadeout"},
					{fals, fals, 0, "COM: Endscene"}};
				dialogue_page(lc);
			}
			{
				line lc[32] = {
					{true, true, 0, "S09:01"},
					{true, true, 0, "BG: pools"},
					{fals, true, 0, "GUY                              Se siente bien aqui fuera."},
					{fals, true, 0, "DIANA                            Y que lo digas. Si navegar no    fuese tan caro lo haria todo     el tiempo."},
					{fals, true, 0, "GUY                              {Crees que vendran mas turistas  a la isla?"},
					{fals, true, 0, "DIANA                            Deberias relajarte un poquito    con todo el tema de tu           restaurante."},
					{fals, true, 0, "DIANA                            Aprende a tomar un descanso y    relajarte de vez en cuando, {oui?"},
					{fals, true, 0, "GUY                              Supongo que deberia. Pero la     cocina es como si fuera mi bebe, no puedo evitarlo."},
					{fals, true, 0, "DIANA                            {Y si algo le pasara? {Y si      un dia estallara de repente?"},
					{true, true, 0, "BG: fadeout"},
					{true, true, 0, "S09:02"},
					{true, true, 0, "..."},
					{true, true, 0, "SF: Boom"},
					{true, true, 0, "S09:03"},
					{true, true, 0, "......"},
					{true, true, 0, "S09:04"},
					{true, true, 0, "GUY                              ..."},
					{true, true, 0, "DIANA                            ..."},
					{fals, true, 0, "GUY                              Santo... Cielo..."},
					{fals, fals, 0, "COM: Endscene"}};
				dialogue_page(lc);
			}
			{
				line lc[32] = {
					{true, true, 0, "S09:05"},
					{fals, true, 0, "RUFUS                            Pero que..."},
					{fals, true, 0, "RUFUS                            ..."},
					{true, true, 0, "S09:06"},
					{fals, true, 0, "MAPLE                            Yo... Y-Yo..."},
					{fals, true, 0, "AARON                            Maple, Yo-"},
					{fals, true, 0, "MAPLE                            ...Yo-Estoy..."},
					{true, true, 0, "S09:08"},
					{fals, true, 0, "ENOKI                            }Maple, ven aqui!"},
					{fals, true, 0, "MAPLE                            ..."},
					{true, true, 0, "S09:09"},
					{true, true, 0, "MAPLE                            ..."},
					{fals, true, 0, "AARON                            Maple, tenemos que hablar.       Ahora mismo."},
					{true, true, 0, "S09:10"},
					{fals, true, 0, "ENOKI                            Maple, es-"},
					{fals, true, 0, "AARON                            Maria, te amo, pero Maple y yo   tenemos que hablar."},
					{true, true, 0, "S09:11"},
					{fals, true, 0, "ENOKI                            Maria..."},
					{fals, true, 0, "ENOKI                            O-kay, ire a ver como estan los  demas."},
					{fals, fals, 0, "COM: Endscene"}};
				dialogue_page(lc);
			}
			{
				line lc[32] = {
					{true, true, 0, "S09:12"},
					{fals, true, 0, "AARON                            Maple. Ya teniamos que haber     hablado sobre esto, y ya no puedoesperar    mas."},
					{true, true, 0, "S09:13"},
					{fals, true, 0, "AARON                            Creo que sabes de que se trata."},
					{fals, true, 0, "MAPLE                            N-no quisiera hablar ahorita."},
					{true, true, 0, "S09:14"},
					{true, true, 0, "BG: maple"},
					{fals, true, 0, "AARON                            Quiero disculparme contigo."},
					{true, true, 0, "S09:13"},
					{fals, true, 0, "AARON                            Me he estado quejando de ti a tu espaldas con los demas."},
					{fals, true, 0, "AARON                            Aunque al final has hecho un     monton de cosas que hacen que me sienta orgulloso de ser tu       hermano mayor."},
					{fals, true, 0, "AARON                            Tienes esa ira que esta todo el  tiempo dentro de ti, una ira que proyectas hacia todo lo que ves  mal de este mundo."},
					{fals, true, 0, "AARON                            La ira no es algo malo, pero     ahora entiendo que te ves        reflejada en todo aquello que te hace enojar."},
					{true, true, 0, "S09:14"},
					{fals, true, 0, "AARON                            Gracias por todo, agradezco que  me hayas defendido."},
					{fals, true, 0, "MAPLE                            Callate."},
					{true, true, 0, "S09:13"},
					{fals, true, 0, "AARON                            No me voy a callar."},
					{fals, true, 0, "AARON                            Tomate tu tiempo para calmarte,  pero tendras que aprender a      controlar tu ira. O no podre     seguir apoyandote."},
					{fals, true, 0, "MAPLE                            ...Oui."},
					{true, true, 0, "S09:15"},
					{fals, true, 0, "AARON                            Me alegra que lo entiendas.      Rufus, Creo que tambien tenemos  que hablar de algo."},
					{true, true, 0, "S09:16"},
					{true, true, 0, "BG: fadeout"},
					{fals, true, 0, "ENOKI                            A-Aar.. AARON, }UN MOMENTO!"},
					{fals, true, 0, "AARON                            Necesitamos abrir esas puertas."},
					{fals, true, 0, "RUFUS                            Oye, estoy seguro de que puedo   encontrar una forma de desactivarel seguro. Creo que no tienes por que-"},
					{fals, true, 0, "AARON                            Yo lo hare."},
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
					{true, true, 0, "N-No... No puedo perderte..."},
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
					{true, true, 0, "{A-Aaron?                        {Por que me miras de esa forma?"},
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
					{true, true, 0, "Di algo...                       Me estas asustando..."},
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
					{fals, true, 0, "AARON                            Pague la isla en efectivo.       Deberiamos tener lo suficiente   como para conseguir una casa   enLouisiana."},
					{fals, true, 0, "AARON                            De todas formas, un cajun nunca  encontrara un mejor hogar fuera  de Louisiana , {oui?"},
					{fals, true, 0, "AARON                            Creo que tengo suficiente dinero para pagarles a todos unos meses de renta hasta que puedan        volver a sus vidas normales."},
					{fals, true, 0, "AARON                            Quiero decir que para mi ha sido un orgullo ser su rey durante    este tiempo. Gracias a todos por estar ahi."},
					{true, true, 0, "S10:02"},
					{fals, true, 0, "OLIVIER                          Tambien queremos darte las       gracias. No se que haremos yo y  Eleanor, pero... Ya pensaremos   en algo."},
					{fals, true, 0, "OLIVIER                          Vinimos aqui porque no           teniamos recursos. Asi que       haberlos conocido fue una        bendicion."},
					{fals, true, 0, "CESAR                            Y no hay duda de que Enoki me    salvo el trasero."},
					{fals, true, 0, "RUFUS                            P-puedo ayudar si alguno me      necesita o le hace falta un lugardonde quedarse. Lamento mucho lo de su isla..."},
					{fals, true, 0, "RUFUS                            En realidad nunca quise causar   tantos problemas, solo estaba    aqui para hacer un poco de       antagonista, yo..."},
					{fals, true, 0, "RUFUS                            Oye, tengo cobijas y cosas asi   por si necesitan algo para pasar la noche."},
					{true, true, 0, "S10:01"},
					{fals, true, 0, "AARON                            ...Gracias, Rufus."},
					{fals, true, 0, "AARON                            Todos necesitaremos un tiempo    para proCESAR lo ocurrido. Aunqueno vi el barco de Diana en las   camaras de la isla."},
					{fals, true, 0, "AARON                            Todo el mundo parece estar bien. Y al fin y al cabo, eso es lo masimportante."},
					{fals, true, 0, "AARON                            Los quiero mucho a todos."},
					{fals, fals, 0, "COM: Endscene"}};
				dialogue_page(lc);
			}

			{
				line lc[32] = {
					{true, true, 0, "S10:04"},
					{true, true, 0, "BG: fadeout"},
					{fals, true, 0, "SCOUT                            Maple, {como te sientes?"},
					{fals, true, 0, "MAPLE                            ..."},
					{true, true, 0, "S10:03"},
					{fals, true, 0, "MAPLE                            ... No te atrevas a darme        lastima. {okay?"},
					{true, true, 0, "S10:04"},
					{fals, true, 0, "SCOUT                            S-si, esta bien, Es solo que...  Perdoname por-"},
					{true, true, 0, "S10:03"},
					{fals, true, 0, "MAPLE                            {Perdonarte de que?"},
					{fals, true, 0, "SCOUT                            Dejame terminar."},
					{fals, true, 0, "MAPLE                            Esta bien. Continua."},
					{fals, true, 0, "SCOUT                            Perdona por ser atrevido, pero   por favor, deja de culparte      tanto. Estoy de tu lado, {sabes?"},
					{fals, true, 0, "MAPLE                            Que, {me vas a invitar a salir   o algo?"},
					{true, true, 0, "S10:04"},
					{fals, true, 0, "SCOUT                            No, Y-yo... bueno, no, no iba    a... Mira, tan solo no me        gustaria perderte."},
					{fals, true, 0, "SCOUT                            No estamos enfadados contigo,    y... oye, tampoco me gustaria    echar a perder nuestra amistad"},
					{fals, true, 0, "SCOUT                            solo porque estes enojada, {ok?  Eres mas importante que la isla. Y yo..."},
					{fals, true, 0, "SCOUT                            Quiero que me prometas que no    iras a ningun lado ni haras nada estupido por lo que ha ocurrido."},
					{fals, true, 0, "MAPLE                            ..."},
					{true, true, 0, "S10:04"},
					{fals, true, 0, "MAPLE                            ... No lo hare, Scout. No tienes que preocuparte tanto por mi."},
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
					{fals, true, 0, "ENOKI                            }Hey, Maple! {Ya regresaste?"},
					{fals, true, 0, "MAPLE                            Si. La entrevista salio bien. El ejercito sera un enfado, pero... los beneficios estan bien."},
					{fals, true, 0, "AARON                            Se que te ira genial, Maple."},
					{fals, true, 0, "MAPLE                            {Eso piensas?"},
					{fals, true, 0, "AARON                            Apuesto a que seras la unica elfadel equipo. Y eso estara a tu    favor."},
					{fals, true, 0, "MAPLE                            Si, eso creo. He hablado con     Scout sobre esto. Dice que esta  feliz pero que me echara         de menos."},
					{fals, true, 0, "ENOKI                            Nosotros tambien te extra[aremos."},
					{true, true, 0, "S10:06"},
					{fals, true, 0, "ENOKI                            Bueno, Aaron y yo tambien        tenemos una noticia que darte."},
					{true, true, 0, "S10:07"},
					{fals, true, 0, "MAPLE                            Vaya, {que noticia?"},
					{true, true, 0, "S10:08"},
					{fals, true, 0, "ENOKI                            Parece que pronto... Uh...       Que pronto habra un nuevo        Tremblay entre nosotros."},
					{true, true, 0, "S10:10"},
					{fals, true, 0, "MAPLE                            Espera, {No me digas que-?"},
					{true, true, 0, "S10:09"},
					{fals, true, 0, "ENOKI                            }Aha!"},
					{true, true, 0, "S10:11"},
					{fals, true, 0, "MAPLE                            Estas... {EMBARAZADA?"},
					{fals, true, 0, "AARON                            Asi es, se[orita."},
					{true, true, 0, "S10:09"},
					{fals, true, 0, "MAPLE                            No puede ser, Voy...             Voy a ser tia. {Que clase de     persona saldra de una mezcla comoAaron y Enoki?"},
					{true, true, 0, "S10:12"},
					{fals, true, 0, "ENOKI                            El 2000 ha sido un a[o increible,}y estoy segura de que el 2001   sera aun mejor!"},
					{fals, true, 0, "AARON                            Sea cual sea la aventura que nos aguarde, me alegro de que estes ami lado para vivirla."},
					{fals, true, 0, "MAPLE                            }Feliz 2001, chicos!"},
					{fals, true, 0, "ENOKI                            }Happy 2001!"},
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
				{fals, fals, 0, "}Ay! }Bienvenidos! Ven a tomar   asiento y un te o un cafe o algo."},
				{fals, fals, 0, "Entonces, {que te parecio mi     juego? Si... no fue muy largo,   pero para ser completamente      honesto,"},
				{fals, fals, 0, "no estaba completamente seguro depoder manejarlo, jaja. Aunque    espero que lo hayas pasado bien."},
				{fals, fals, 0, "Ya que conseguiste todas las     llaves, }te dejare jugar a los   minijuegos que quieras!"},
				{fals, fals, 0, "Solo pasa por este archivo       guardado cada vez que quieras    probarlos."},
				{fals, fals, 0, "}Hasta la proxima vez!"},
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
	}

	return 0;
}

// Function to calculate the smallest multiple
int roundDown(int n)
{
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

		short int col[8] = {0};
		short int gol[8] = {0};
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
			roundUp(y_int) * room_width};

		int anti_close[4] = {
			roundUp(x_int + 6),
			roundDown(x_int - 6),
			roundUp(y_int + 6) * room_width,
			roundDown(y_int) * room_width};

		if (globals->collisions.size() > 0)
		{
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
				else
				{
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
				else
				{
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
				else
				{
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
				else
				{
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

			if (dist > 124 && teleport)
			{
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
				if (!canLeft)
					delta_y += newDown - newUp;
			}
			if (bn::keypad::right_held())
			{
				delta_x += (1 * canRite);
				if (!canRite)
					delta_y += newLeft - newRite;
			}
			if (bn::keypad::up_held())
			{
				delta_y += (-1 * canUp);
				if (!canUp)
					delta_x += newDown - newLeft;
			}
			if (bn::keypad::down_held())
			{
				delta_y += (1 * canDn);
				if (!canDn)
					delta_x += newUp - newRite;
			}
			if (delta_x > 1)
				delta_x = 1;
			if (delta_x < -1)
				delta_x = -1;
			if (delta_y > 1)
				delta_y = 1;
			if (delta_y < -1)
				delta_y = -1;

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

		if (!canLeft && !canRite)
		{
			x_int = last_x;
			canHorz = 1;
		}

		if (!canUp && !canDn)
		{
			y_int = last_y;
			canVert = 1;
		}

		close[0] = roundDown(x_int + 6);
		close[1] = roundUp(x_int - 6);
		close[2] = roundDown(y_int + 6) * room_width;
		close[3] = roundUp(y_int) * room_width;

		if (globals->collisions.size() > 0)
		{
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

		if (!canLeft && !canRite)
		{
			x_int = last_x;
		}

		if (!canUp && !canDn)
		{
			y_int = last_y;
		}
		entity.set_position(x_int, y_int);
		entity = entity_anim.sprite();

		if (canLeft || canRite)
		{
			last_x = x_int;
		}

		if (canUp || canDn)
		{
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

	void update()
	{
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
	moving_block(){};
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
void popup(int scene)
{

	// Check to see if you've seen it before
	if (!globals->current_save->popups[scene])
	{
		bn::core::update();
		globals->current_save->popups[scene] = true;
		bn::sprite_text_generator text_line(common::variable_8x16_sprite_font);
		bn::regular_bg_ptr background = bn::regular_bg_items::fun_background.create_bg(0, 0);
		bn::sprite_ptr a_button = bn::sprite_items::a_button.create_sprite(-80, -48, (globals->all_save.language * 2));

		int my_chari = globals->current_save->last_char_id;
		if (my_chari < 0 || my_chari > 7)
			my_chari = 0;

		auto dg_bg1 = bn::sprite_items::dialogue_bg_2.create_sprite(-64, 0);
		auto dg_bg2 = bn::sprite_items::dialogue_bg_2.create_sprite(64, 0);
		dg_bg1.set_scale(2, 0.01);
		dg_bg2.set_scale(2, 0.01);
		dg_bg1.set_blending_enabled(true);
		dg_bg2.set_blending_enabled(true);
		bn::music_items::multisong.play(0.5);
		bn::music::set_position(34); // twinkle

		char text[192] = {0};

		switch (globals->all_save.language) {
			case 0: {
				switch (scene)
				{
				case 0:
				{
					char txt1[192] = "You'll find things around the    island to build your Trembloon   count. If you get 100, you get   to progress to the next chapter! Bonne chance!";
					strncpy(text, txt1, 192);
					break;
				}
				case 1:
				{
					char txt1[192] = "Try to catch all the rabbits and toss them out of the garden as   soon as possible. Pick them up & throw them with the A button.    Bonne chance!";
					strncpy(text, txt1, 192);
					my_chari = 1;
					break;
				}
				case 2:
				{
					char txt1[192] = "Try to find the gem and avoid thebats. If you're touched, the gem moves to a new place. Shoot fire at the bats to earn bonus points.Bonne chance!";
					strncpy(text, txt1, 192);
					my_chari = 0;
					break;
				}
				case 3:
				{
					char txt1[192] = "Use the A button to chop the     wooden pegs. Make sure you don't swing out of line or miss any, oryou'll lose points!              Bonne chance!";
					strncpy(text, txt1, 192);
					my_chari = 2;
					break;
				}
				case 4:
				{
					char txt1[192] = "There are new villagers to the   northwest! There are new ways to earn Trembloons, but you'll have to figure out how yourself.      Bonne chance!";
					strncpy(text, txt1, 192);
					break;
				}
				case 5:
				{
					char txt1[192] = "Try to get the highest sequence  of button combinations in a row, and you can magically summon an  item! L and R are the triggers.  Bonne chance!";
					strncpy(text, txt1, 192);
					my_chari = 5;
					break;
				}
				case 6:
				{
					char txt1[192] = "Pilot the boat to avoid the      rocks! Use up to accelerate, leftand right to steer, and down to  stop the boat.                   Bonne chance!";
					strncpy(text, txt1, 192);
					my_chari = 6;
					break;
				}
				case 7:
				{
					char txt1[192] = "You can find the customer's orderin the upper right corner.       Remember to press R if you need  to peek at the cookbook.         Bonne chance!";
					strncpy(text, txt1, 192);
					my_chari = 7;
					break;
				}
				default:
				{
				}
				}
				break;
			}
			case 1: {
				break;
			}
			case 2: {
				switch (scene)
				{
				case 0:
				{
					char txt1[192] = "Alrededor de la isla encontraras cosas que aumentaran tu cifra de Trembloons. }Podras  avanzar al  siguiente capitulo si consigues  100! }Bonne chance!";
					strncpy(text, txt1, 192);
					break;
				}
				case 1:
				{
					char txt1[192] = "Intenta cazar a todos los conejosy lanzalos fuera del jardin tan  pronto como sea posible.         Agarralos y lanzalos pulsando el boton A. }Bonne chance!";
					strncpy(text, txt1, 192);
					my_chari = 1;
					break;
				}
				case 2:
				{
					char txt1[192] = "Encuentra la gema y evita a los  murcielagos. Si te tocan, la gemaaparecera en otro lugar. Lanza   fuego a los murcielagos para     conseguir puntos extra. }Bonne chance!";
					strncpy(text, txt1, 192);
					my_chari = 0;
					break;
				}
				case 3:
				{
					char txt1[192] = "Pulsa el boton A para cortar la  madera. Asegurate de no fallar o salirte de la linea, }o perderas tus puntos!     }Bonne chance!";
					strncpy(text, txt1, 192);
					my_chari = 2;
					break;
				}
				case 4:
				{
					char txt1[192] = "}Hay nuevos aldeanos al noroeste!Y por lo tanto tambien nuevas    formas de ganar Trembloons, pero eso tendras que descubrirlo tu. }Bonne chance!";
					strncpy(text, txt1, 192);
					break;
				}
				case 5:
				{
					char txt1[192] = "Intenta conseguir la mayor       secuencia de botones posible,    }tambien puedes invocar un       objeto magicamente! L y R son losgatillos. }Bonne chance!";
					strncpy(text, txt1, 192);
					my_chari = 5;
					break;
				}
				case 6:
				{
					char txt1[192] = "}Pilota el barco para evitar las rocas! Pulsa arriba para         acelerar, izquierda y derecha    para dirigirlo, y abajo para     parar el barco. }Bonne chance!";
					strncpy(text, txt1, 192);
					my_chari = 6;
					break;
				}
				case 7:
				{
					char txt1[192] = "Puedes ver el pedido del cliente en la esquina superior derecha.  Recuerda pulsar R si necesitas   consultar el libro de cocina.    }Bonne chance!";
					strncpy(text, txt1, 192);
					my_chari = 7;
					break;
				}
				default:
				{
				}
				}
				break;
			}
		}

		// Profile picture
		auto prof_pic = bn::sprite_items::save_tiles.create_sprite(0, 32, my_chari);

		// Fresh init
		bn::vector<bn::sprite_ptr, 32> text_sprite0;
		bn::vector<bn::sprite_ptr, 32> text_sprite2;
		bn::vector<bn::sprite_ptr, 32> text_sprite3;
		bn::vector<bn::sprite_ptr, 32> text_sprite4;
		bn::vector<bn::sprite_ptr, 32> text_sprite5;
		char line1[42] = {0};
		char line3[42] = {0};
		char line4[42] = {0};
		char line5[42] = {0};
		char line6[42] = {0};

		for (short int t = 0; t < 33; t++)
		{
			line1[t] = text[t];
		};
		for (short int t = 0; t < 33; t++)
		{
			line3[t] = text[t + 33];
		};
		for (short int t = 0; t < 33; t++)
		{
			line4[t] = text[t + 66];
		};
		for (short int t = 0; t < 33; t++)
		{
			line5[t] = text[t + 99];
		};
		for (short int t = 0; t < 32; t++)
		{
			line6[t] = text[t + 132];
		};

		text_line.generate(-108, 21 - 64, line1, text_sprite0);
		for (short int t = 0; t < text_sprite0.size(); t++)
		{
			text_sprite0.at(t).set_visible(false);
		}

		text_line.generate(-108, 33 - 64, line3, text_sprite2);
		for (short int t = 0; t < text_sprite2.size(); t++)
		{
			text_sprite2.at(t).set_visible(false);
		}

		text_line.generate(-108, 45 - 64, line4, text_sprite3);
		for (short int t = 0; t < text_sprite3.size(); t++)
		{
			text_sprite3.at(t).set_visible(false);
		}

		text_line.generate(-108, 57 - 64, line5, text_sprite4);
		for (short int t = 0; t < text_sprite4.size(); t++)
		{
			text_sprite4.at(t).set_visible(false);
		}

		text_line.generate(-108, 69 - 64, line6, text_sprite5);
		for (short int t = 0; t < text_sprite5.size(); t++)
		{
			text_sprite5.at(t).set_visible(false);
		}

		// Process visual effects
		short int ticker = 0;
		short int ticker_delay = 0;

		while (!bn::keypad::a_pressed())
		{
			background.set_position((background.x().integer() + 1) % 256, (background.y().integer() + 1) % 256);

			bn::fixed_t<12> new_level = dg_bg1.vertical_scale() + 0.05;
			if (new_level > 2)
				new_level = 2;
			dg_bg1.set_vertical_scale(new_level);
			dg_bg2.set_vertical_scale(new_level);
			prof_pic.set_scale(new_level / 2, new_level / 2);

			// Handle text ticker
			if (ticker < 160)
			{
				if (ticker_delay == 0)
				{
					short int ticked = ticker % 32;
					if (ticker >= 0 && ticker < 32)
					{
						if (text_sprite0.size() > ticked)
						{
							text_sprite0.at(ticked).set_visible(true);
							bn::sound_items::click.play();
						}
						else
						{
							ticker = 31;
						}
					}
					if (ticker >= 32 && ticker < 64)
					{
						if (text_sprite2.size() > ticked)
						{
							text_sprite2.at(ticked).set_visible(true);
							bn::sound_items::click.play();
						}
						else
						{
							ticker = 63;
						}
					}
					if (ticker >= 64 && ticker < 96)
					{
						if (text_sprite3.size() > ticked)
						{
							text_sprite3.at(ticked).set_visible(true);
							bn::sound_items::click.play();
						}
						else
						{
							ticker = 95;
						}
					}
					if (ticker >= 96 && ticker < 128)
					{
						if (text_sprite4.size() > ticked)
						{
							text_sprite4.at(ticked).set_visible(true);
							bn::sound_items::click.play();
						}
						else
						{
							ticker = 127;
						}
					}
					if (ticker >= 128 && ticker < 160)
					{
						if (text_sprite5.size() > ticked)
						{
							text_sprite5.at(ticked).set_visible(true);
							bn::sound_items::click.play();
						}
						else
						{
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
class hud
{
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

	hud()
	{
		r_wing.set_horizontal_flip(true);
		r_wing_2.set_horizontal_flip(true);
		l_wing_2.put_above();
		r_wing_2.put_above();
		orb.put_above();

		l_wing_2.set_scale(wing_scale, 0.01);
		r_wing_2.set_scale(wing_scale, 0.01);
	}

	void update(bn::fixed_t<12> new_value, int new_score)
	{
		bn::sprite_text_generator text_line(common::variable_8x16_sprite_font);
		score = new_score;
		wing_scale = new_value;
		if (wing_scale < 0.01)
			wing_scale = 0.01;
		if (wing_scale > 2)
			wing_scale = 2;

		rotation = (rotation + 1) % 360;

		short int q = -3;
		if (new_score > 9)
			q = -5;
		if (new_score > 99)
			q = -8;

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

		for (int t = 0; t < text_sprite0.size(); t++)
		{
			text_sprite0.at(t).put_above();
		}
	}
};

// Victory object
class victory
{
public:
	bn::vector<bn::sprite_ptr, 4> file1_spr;
	bn::vector<bn::sprite_ptr, 4> file2_spr;
	bn::sprite_ptr bg = bn::sprite_items::awards.create_sprite(80, -8, 0);
	bn::sprite_ptr tg = bn::sprite_items::awards.create_sprite(80, -40, 1);
	bn::sprite_ptr award = bn::sprite_items::awards.create_sprite(80, 24, 2);
	bn::sprite_ptr letter = bn::sprite_items::awards.create_sprite(80, 24, 3);
	bn::sprite_ptr a_button = bn::sprite_items::a_button.create_sprite(-80, -48, (globals->all_save.language * 2));

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

	victory(int l = 0, int charis = 0, int scores = 50, int xps = 250, int chap = 3)
	{
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

		bn::music_items::z05_victory.play(bn::fixed(50) / 100);
	}

	void update()
	{
		bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);

		// b_a.set_x(new_lc + 32);

		if (b_a.x().integer() < chap_go)
			b_a.set_x(b_a.x() + 1);

		if (music_counter < 224)
		{
			music_counter++;
		}
		else if (music_counter == 224)
		{
			bn::music_items::multisong.play(0.5);
			bn::music::set_position(36); // z08_award
			music_counter++;
		}

		switch (stage)
		{
		case 0:
		{
			bn::fixed_t<12> hs = bg.vertical_scale();
			if (hs < 1.9)
			{
				hs += 0.1;
				if (hs > 1.9)
				{
					stage = 1;
					hs = 2;
				}
				bg.set_vertical_scale(hs);
			}
			break;
		}
		case 1:
		{
			if (xp_render < xp)
			{
				xp_render += 3;
				if (xp_render > xp)
					xp_render = xp;
				bn::sound_items::click.play();
			}
			else
			{
				stage = 2;
			}

			tg.set_visible(true);
			file1_spr.clear();
			file2_spr.clear();
			file1_gen.generate(80 - 8, -48, bn::to_string<4>(score), file1_spr);
			file1_gen.generate(80 - 8, -18, bn::to_string<4>(xp_render), file2_spr);
			break;
		}
		case 2:
		{
			award.set_visible(true);
			letter.set_visible(true);

			bn::fixed_t<12> a = award.horizontal_scale();
			if (a > 1)
			{
				a -= 0.1;
			}
			else
			{
				a = 1;
				stage = 3;
				bn::sound_items::firehit.play();

				switch (chari)
				{
				case 0:
				{
					bn::sound_items::fireblast.play();
					if (level < 3)
						bn::sound_items::maple_alright_02.play();
					else
						bn::sound_items::maple_ugh_01.play();
					break;
				}
				case 1:
				{
					if (level < 3)
						bn::sound_items::enoki_hey.play();
					else
						bn::sound_items::enoki_aw.play();
					break;
				}
				case 2:
				{
					if (level < 3)
						bn::sound_items::aaron_yeah_02.play();
					else
						bn::sound_items::aaron_ugh_07.play();
					break;
				}
				default:
				{
					break;
				}
				}
			}
			award.set_scale(a, a);
			letter.set_scale(a, a);
			break;
		}
		case 3:
		{
			break;
		}
		default:
		{
		}
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
	const bn::sprite_item *environment = &bn::sprite_items::environment_stone;

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

	room(short int w, short int h, short int x, short int y)
	{
		width = w;
		height = h;
		start_x = x;
		start_y = y;

		chari.clear();
		primary_bg.set_camera(camera);
	}

	void configure(short int w, short int h, short int x, short int y)
	{
		width = w;
		height = h;
		start_x = x;
		start_y = y;
	}

	void place(int x, int y)
	{
		short int z = x + (y * width);
		if (z < globals->local_tileset.size() && z > -1)
		{
			if (globals->local_tileset.at(z) > 0 && globals->local_tileset.at(z) < 64)
			{
				bn::sprite_ptr s = environment->create_sprite(x * 32, y * 32, globals->local_tileset.at(z) - 1);
				s.set_camera(camera);

				// Set Palette
				if (environment == &bn::sprite_items::ocean_terrain && globals->current_save->checkpoint == 5)
				{
					s.set_palette(bn::sprite_items::underground_tiles.palette_item());
				}

				// Set Z order
				if (environment == &bn::sprite_items::ocean_terrain && globals->local_tileset.at(z) == 1)
				{
					s.set_z_order(1);
				}
				else if (environment == &bn::sprite_items::pools_tiles && globals->local_tileset.at(z) == 1)
				{
					s.set_z_order(1);
				}
				else
				{
					s.set_z_order(296);
				}
				if (tile_hop.size() < 88)
					tile_hop.push_back(s);
				if (ref_hop.size() < 88)
					ref_hop.push_back(globals->local_tileset.at(z) - 1);
			}
		}
	}

	void fix_camera()
	{
		if (camera.x().integer() < (3 * 32) + 16)
			camera.set_x((3 * 32) + 16);
		if (camera.x().integer() > (width * 32) - (5 * 32) + 16)
			camera.set_x((width * 32) - (5 * 32) + 16);
		if (camera.y().integer() < (2 * 32) + 16)
			camera.set_y((2 * 32) + 16);
		if (camera.y().integer() > (height * 32) - (4 * 32) + 16)
			camera.set_y((height * 32) - (4 * 32) + 16);
	}

	void init_render(int p_x = 0, int p_y = 0)
	{
		for (unsigned short int t = 0; t < chari.size(); t++)
		{
			chari.at(t).room_width = width;
		}

		short int f_x = p_x - 5;
		short int t_x = p_x + 6;
		short int f_y = p_y - 3;
		short int t_y = p_y + 5;
		if (f_x < 0)
			f_x = 0;
		if (t_x > width)
			t_x = width;
		if (f_y < 0)
			f_y = 0;
		if (t_y > height)
			t_y = height;
		for (int y2 = f_y; y2 < t_y; y2++)
		{
			for (int x2 = f_x; x2 < t_x; x2++)
			{
				place(x2, y2);
			}
		}

		// Handle camera work initially
		last_camera_x = camera.x().integer() / 32;
		last_camera_y = camera.y().integer() / 32;
		fix_camera();

		// Handle active character
		for (unsigned short int t = 0; t < chari.size(); t++)
		{
			if (chari.at(t).identity == globals->current_save->last_char_id)
			{
				follow_id = t;
				break;
			}
		}
	}

	void start_notif(unsigned short int type = 0)
	{
		if (type == 0)
		{
			a_notif = bn::sprite_items::a_button_2.create_sprite(follow_x, follow_y - 28, 0);
		}
		else if (type == 1)
		{
			a_notif = bn::sprite_items::l_button.create_sprite(follow_x, follow_y - 28, globals->all_save.language);
		}

		a_notif.set_camera(camera);
		a_notif.set_z_order(0);
		a_notif.set_visible(true);
	}

	void refresh_tiles(bn::fixed_t<12> x, bn::fixed_t<12> y)
	{
		tile_hop.clear();
		ref_hop.clear();
		short int p_x = x.integer();
		short int p_y = y.integer();

		short int f_x = p_x - 5;
		short int t_x = p_x + 6;
		short int f_y = p_y - 3;
		short int t_y = p_y + 5;
		if (f_x < 0)
			f_x = 0;
		if (t_x > width)
			t_x = width;
		if (f_y < 0)
			f_y = 0;
		if (t_y > height)
			t_y = height;
		for (int y2 = f_y; y2 < t_y; y2++)
		{
			for (int x2 = f_x; x2 < t_x; x2++)
			{
				place(x2, y2);
			}
		}

		// Update ocean tiles
		if (environment == &bn::sprite_items::ocean_terrain)
		{
			for (int t = 0; t < ref_hop.size(); t++)
			{
				if (ref_hop.at(t) == 25)
				{
					tile_hop.at(t).set_mosaic_enabled(true);
				}
			}
		}
	}

	void update_objects()
	{

		// Set up animation bit
		anim_ticker_ticker++;
		if (anim_ticker_ticker == 8)
		{

			anim_ticker_ticker = 0;
			anim_ticker++;
		}

		camera.set_position(chari.at(follow_id).entity.x(), chari.at(follow_id).entity.y());
		fix_camera();

		// bn::fixed_t<12> sin_v = abs(sin(anim_ticker / 3));
		// bn::sprites_mosaic::set_horizontal_stretch(sin_v);

		// set current_room.camera follow point
		follow_x = chari.at(follow_id).entity.x().integer();
		follow_y = chari.at(follow_id).entity.y().integer();

		unsigned short int cam_x = (camera.x().integer() + 16) / 32;
		unsigned short int cam_y = (camera.y().integer()) / 32;

		if (cam_x != last_camera_x || cam_y != last_camera_y)
		{
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
				if (p.size() > 2)
					p.erase(p.begin());
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
			else
			{
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
			for (short int t = 0; t < chari.size(); t++)
			{
				if (t != new_chari)
				{
					if (chari.at(t).can_follow)
						chari.at(t).role = 0;
					else
						chari.at(t).role = 2;
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
				if (my_follow_at == -1)
					my_follow_at = (t + 1) % chari.size();
				chari.at(t).update(chari.at(my_follow_at).entity.x().integer(), chari.at(my_follow_at).entity.y().integer());
			}
		}
	}
};

class xp_hud
{
public:
	bn::sprite_ptr l_side = bn::sprite_items::power_meter.create_sprite(76, 96, 0);
	bn::sprite_ptr m_side = bn::sprite_items::power_meter.create_sprite(92, 96, 1);
	bn::sprite_ptr r_side = bn::sprite_items::power_meter.create_sprite(108, 96, 2);
	bn::sprite_ptr pointer = bn::sprite_items::power_meter.create_sprite(76, 96, 3);
	int x_to = 76;
	int chap = 4;

	xp_hud()
	{
	}

	void update()
	{

		// Set up chapter
		if (globals->current_save->checkpoint < 15)
		{
			chap = 3;
			if (globals->current_save->xp > 300)
				globals->current_save->xp = 300;
		}
		if (globals->current_save->checkpoint < 9)
		{
			chap = 2;
			if (globals->current_save->xp > 200)
				globals->current_save->xp = 200;
		}
		if (globals->current_save->checkpoint < 6)
		{
			chap = 1;
			if (globals->current_save->xp > 100)
				globals->current_save->xp = 100;
		}
		if (globals->current_save->checkpoint == 0)
		{
			chap = 1;
			if (globals->current_save->xp > 50)
				globals->current_save->xp = 50;
		}
		x_to = 76 + (globals->current_save->xp / chap) * 0.32;

		// Configure X position
		if (x_to > pointer.x())
		{
			pointer.set_x(pointer.x() + 1);
		}
		else if (x_to < pointer.x())
		{
			pointer.set_x(x_to);
		}

		if (69 < pointer.y())
		{
			l_side.set_y(lerp(pointer.y(), 69, 0.3));
			m_side.set_y(lerp(pointer.y(), 69, 0.3));
			r_side.set_y(lerp(pointer.y(), 69, 0.3));
			pointer.set_y(lerp(pointer.y(), 69, 0.3));
		}
	}

	void acknowledge()
	{
		bn::sound_items::pop.play();
	}
};

dungeon_return dungeon(dungeon_return &dt)
{

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
			character default_chari(bn::sprite_items::maple_walking_spring, current_room.start_x, current_room.start_y, false, current_room.width);
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
		if (!bn::music::playing())
		{
			bn::music_items::new_castle.play(0.8);
		}

		current_room.configure(12, 6, 8, 3);
		const short int local_col[current_room.width * current_room.height] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
			1, 1, 2, 40, 3, 1, 1, 1, 0, 1, 1, 0,
			1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
			1, 36, 0, 0, 0, 0, 0, 0, 31, 1, 1, 0,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
		const short int local[current_room.width * current_room.height] = {
			4, 3, 8, 11, 13, 3, 3, 3, 8, 3, 5, 0,
			2, 18, 0, 0, 0, 18, 2, 9, 0, 9, 2, 0,
			2, 0, 0, 0, 0, 0, 2, 10, 0, 10, 2, 0,
			2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0,
			17, 0, 0, 0, 0, 0, 0, 0, 0, 18, 2, 0,
			7, 3, 3, 3, 3, 3, 3, 3, 16, 3, 6, 0};

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++)
		{
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
			7, 3, 14, 3, 12, 3, 3, 12, 3, 3, 12, 3, 13, 12, 3, 3, 12, 3, 14, 13, 6};
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
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++)
		{
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
			7, 3, 3, 14, 3, 3, 3, 3, 3, 3, 6};
		const short int local_col[current_room.width * current_room.height] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 0, 1, 1, 0, 0, 1, 1, 8, 1, 1,
			1, 0, 10, 10, 0, 0, 1, 1, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1,
			1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1,
			1, 1, 0, 34, 0, 4, 0, 0, 0, 33, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++)
		{
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
			7, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6};
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
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++)
		{
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

		// character enoki(bn::sprite_items::enoki_walking_pj, current_room, current_room.start_x - 0.9, current_room.start_y, false);
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
			bn::music_items::z12_overworld_night.play(0.8);
		}
		else if (globals->current_save->checkpoint < 12)
		{
			// z03_overworld
			bn::music_items::multisong.play(0.8);
			bn::music::set_position(14);
		}
		else if (globals->current_save->checkpoint < 14)
		{
			if (bn::music::playing())
				bn::music::stop();
			bn::music_items::fruit.play(0.8);
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
				1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

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
				26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 0, 0, 0};

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++)
			{
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
				1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

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
				26, 26, 26, 26, 26, 26, 26, 26, 53, 26, 26, 26, 26, 26, 26, 26, 26, 0, 0, 0};

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++)
			{
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
				1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

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
				26, 26, 26, 26, 26, 26, 26, 26, 53, 26, 26, 26, 26, 26, 26, 26, 26, 0, 0, 0};

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++)
			{
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
				1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

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
				26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 0, 0, 0};

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++)
			{
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
				1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

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
				26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 0, 0, 0};

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++)
			{
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
			else
			{
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
			else
			{
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
			else
			{
				current_room.chari.at(0).follow_id = 1;
			}
		}

		current_room.primary_bg = bn::regular_bg_items::grassy_knoll.create_bg(0, 0);
		current_room.environment = &bn::sprite_items::ocean_terrain;

		if (globals->current_save->checkpoint == 5)
			current_room.primary_bg.set_palette(bn::regular_bg_items::castle_floor.palette_item());
		current_room.primary_bg.set_camera(current_room.camera);

		/*
		if (globals->current_save->checkpoint < 11 && current_room.chari.at(0).identity == 2) {
			for (int t = 0; t < 2; t++) {
				anim_object fp;
				fp.entity_item = bn::sprite_items::ocean_terrain;
				fp.entity = fp.entity_item.create_sprite(0, 0, 56);
				fp.entity_anim = bn::create_sprite_animate_action_forever(fp.entity, 2, fp.entity_item.tiles_item(), 56, 56, 56, 56);
				fp.entity.set_visible(true);
				fp.entity.set_camera(current_room.camera);

				// Setup location
				int temp_z = 0;
				do {
					int new_tile = std_rnd(globals->local_tileset.size());
					temp_z = globals->local_tileset.at(new_tile);
				} while (temp_z < 1);

				BN_LOG(temp_z, " - ", (temp_z % 20) * 32, " - ", (temp_z / 20) * 32);
				fp.entity.set_position((temp_z % 20) * 32, (temp_z / 20) * 32);
				current_room.anim_objects.push_back(fp);
			}
		}
		*/
		break;
	}
	case 5:
	{
		bn::music_items::new_castle.play(0.8);

		current_room.configure(11, 5, 5, 3);
		const short int local_col[current_room.width * current_room.height] = {
			01, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			01, 1, 0, 0, 17, 0, 18, 0, 0, 0, 1,
			01, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1,
			01, 1, 16, 1, 1, 13, 0, 1, 0, 1, 1,
			01, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
		const short int local[current_room.width * current_room.height] = {
			1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 51,
			2, 7, 0, 0, 0, 0, 0, 0, 0, 0, 52,
			3, 8, 0, 0, 0, 0, 0, 0, 0, 0, 53,
			4, 9, 0, 0, 0, 0, 0, 0, 0, 0, 54,
			5, 10, 0, 0, 0, 0, 0, 0, 0, 0, 55};

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++)
		{
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
			bn::music_items::z09_scout_lab.play(0.8);
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
				1, 1, 1, 1, 1, 1, 1, 1, 1};
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
				1, 1, 1, 1, 1, 1, 1, 1, 1};

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++)
			{
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
				1, 1, 1, 1, 1, 1, 1, 1, 1};
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
				1, 1, 1, 1, 1, 1, 1, 1, 1};

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++)
			{
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
				1, 1, 1, 1, 1, 1, 1, 1, 1};
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
				1, 1, 1, 1, 1, 1, 1, 1, 1};

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++)
			{
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
			bn::music_items::z18_houses.play(0.8);
		}
		else
		{
			if (!bn::music::playing())
				bn::music_items::fruit.play(0.2);
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
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
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
				1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27};

			for (short int t = 0; t < current_room.width * current_room.height; t++)
			{
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
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
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
				1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27};

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++)
			{
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
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
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
				1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27};

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++)
			{
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
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
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
				1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27, 1, 27};

			globals->local_tileset.clear();
			globals->collisions.clear();
			current_room.environment = &bn::sprite_items::ocean_terrain;

			for (short int t = 0; t < current_room.width * current_room.height; t++)
			{
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
			else
			{
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
			else
			{
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
			else
			{
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
			// z17_ptit
			bn::music_items::multisong.play(0.8);
			bn::music::set_position(4);
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
				1, 1, 1, 1, 1, 1, 1};

			const short int local[current_room.width * current_room.height] = {
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0};

			for (short int t = 0; t < current_room.width * current_room.height; t++)
			{
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
				1, 1, 1, 1, 1, 1, 1};

			const short int local[current_room.width * current_room.height] = {
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0};

			globals->local_tileset.clear();
			globals->collisions.clear();
			for (short int t = 0; t < current_room.width * current_room.height; t++)
			{
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
		bn::music_items::v01.play(0.8);
		current_room.chari.at(0).entity.set_position(3 * 32, 5 * 32);

		current_room.configure(7, 7, 3, 5);
		const short int local_col[current_room.width * current_room.height] = {
			1, 1, 1, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 1, 1,
			1, 1, 0, 62, 0, 1, 1,
			1, 1, 0, 0, 0, 1, 1,
			1, 1, 0, 60, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1};

		const short int local[current_room.width * current_room.height] = {
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0};

		for (short int t = 0; t < current_room.width * current_room.height; t++)
		{
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
		// z04_underground
		bn::music_items::multisong.play(0.8);
		bn::music::set_position(30);
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
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

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
			2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2};

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++)
		{
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
			1, 1, 1, 1, 1, 1, 1};
		const short int local[current_room.width * current_room.height] = {
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0};

		for (short int t = 0; t < current_room.width * current_room.height; t++)
		{
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
		bn::music_items::z16_boat.play(0.8);
		current_room.chari.at(0).entity.set_position(3 * 32, 5 * 32);

		current_room.configure(7, 7, 3, 5);
		const short int local_col[current_room.width * current_room.height] = {
			1, 1, 1, 1, 1, 1, 1,
			1, 1, 0, 0, 1, 1, 1,
			1, 1, 0, 1, 0, 1, 1,
			1, 1, 0, 1, 0, 1, 1,
			1, 1, 0, 0, 70, 1, 1,
			1, 1, 1, 65, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1};

		const short int local[current_room.width * current_room.height] = {
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0};

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++)
		{
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
		bn::music_items::z18_houses.play(0.8);

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
			01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01};

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
			35, 37, 39, 1, 27, 1, 43, 3, 43, 12, 26, 26};

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++)
		{
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

	auto l_button = bn::sprite_items::l_button.create_sprite(-90, 14, globals->all_save.language);
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

				if (globals->all_save.language == 0)
				{
					switch (possible_action)
					{

					case 2:
					{
						line lc[10] = {
							{true, true, 00, "MAPLE                            Enoki, there's no window."},
							{true, true, 00, "ENOKI                            Uh-huh?"},
							{true, true, 00, "MAPLE                            What happens if someone tries-"},
							{true, true, 00, "MAPLE                            to break in?"},
							{true, true, 00, "ENOKI                            Aaron punches 'em."},
							{true, true, 00, "ENOKI                            In the face."},
							{true, true, 00, "MAPLE                            He's not here, though."},
							{true, true, 00, "ENOKI                            Then I'll punch 'em."},
							{true, true, 00, "MAPLE                            I.... Hmm. Alright, then."},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};

					case 3:
					{
						line l2[10] = {
							{true, true, 00, "You see a pot."},
							{true, true, 00, "You feel compelled to smash it."},
							{true, true, 00, "However, this is not possible."},
							{true, true, 00, "You feel strangely disappointed."},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(l2);
						break;
					};

					case 4:
					{
						line lc[19] = {
							{true, true, 00, "MAPLE                            Hey, let's head out. I don't want"},
							{true, true, 00, "MAPLE                            to wake him up."},
							{true, true, 00, "ENOKI                            I dunno, it doesn't matter,"},
							{true, true, 00, "ENOKI                            there's no way he'll wake up."},
							{true, true, 00, "ENOKI                            He likes the light on, too."},
							{true, true, 00, "MAPLE                            I thought you didn't have"},
							{true, true, 00, "MAPLE                            electricity..?"},
							{true, true, 00, "ENOKI                            Oh, we do- just that one plug."},
							{true, true, 00, "ENOKI                            It's a very important plug."},
							{true, true, 00, "MAPLE                            You sure you like this place?"},
							{true, true, 00, "ENOKI                            You gonna come here and insult"},
							{true, true, 00, "ENOKI                            my house?"},
							{true, true, 00, "MAPLE                            Well, when you put it THAT way..."},
							{true, true, 00, "ENOKI                            Uh huh, that's what I thought."},
							{true, true, 00, "MAPLE                            Je m'excuse."},
							{true, true, 00, "ENOKI                            Merci."},
							{true, true, 00, "MAPLE                            But when you both move in with me"},
							{true, true, 00, "MAPLE                            don't say I didn't warn y'all."},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};

					case 8:
					{
						line lc[9] = {
							{true, true, 00, "ENOKI                            Y'know, back when Del was my"},
							{true, true, 00, "ENOKI                            nanny, my parents gave her like"},
							{true, true, 00, "ENOKI                            three different rooms she could"},
							{true, true, 00, "ENOKI                            stay in. I don't think she ever"},
							{true, true, 00, "ENOKI                            slept anywhere but the tub."},
							{true, true, 00, "MAPLE                            That actually sounds pretty nice."},
							{true, true, 00, "ENOKI                            Yeah, I tried it but my skin"},
							{true, true, 00, "ENOKI                            didn't like it very much."},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};

					case 9:
					{
						line lc[9] = {
							{true, true, 00, "MAPLE                            Enoki, this one's locked."},
							{true, true, 00, "ENOKI                            Oh. Yeah, I think that's"},
							{true, true, 00, "ENOKI                            the kitchen. We don't know where"},
							{true, true, 00, "ENOKI                            the key is."},
							{true, true, 00, "MAPLE                            So how do you eat??"},
							{true, true, 00, "ENOKI                            We make most of our food over the"},
							{true, true, 00, "ENOKI                            big fire pit!"},
							{true, true, 00, "MAPLE                            You two, I *swear*...."},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};

					// M and E talking about A
					case 10:
					{
						line lc[20] = {
							{true, true, 00, "ENOKI                            Isn't he so cute when he"},
							{true, true, 00, "ENOKI                            sleeps like that? <3"},
							{true, true, 00, "MAPLE                            You've been married for, what,"},
							{true, true, 00, "MAPLE                            a few months now?"},
							{true, true, 00, "MAPLE                            Aren't you supposed to be at the"},
							{true, true, 00, "MAPLE                            stage where neither of you talk"},
							{true, true, 00, "MAPLE                            to each other at meals and both"},
							{true, true, 00, "MAPLE                            of you've gained ten pounds?"},
							{true, true, 00, "ENOKI                            Huh, I think I've lost weight."},
							{true, true, 00, "MAPLE                            I guess I don't get it."},
							{true, true, 00, "ENOKI                            Just cos you always get in"},
							{true, true, 00, "ENOKI                            fights with your ex-boyfriends"},
							{true, true, 00, "ENOKI                            doesn't mean every couple's like"},
							{true, true, 00, "ENOKI                            that, tu connais."},
							{true, true, 00, "ENOKI                            I mean, you've got this nasty"},
							{true, true, 00, "ENOKI                            habit of-"},
							{true, true, 00, "MAPLE                            You finish that sentence, and"},
							{true, true, 00, "MAPLE                            I'll burn your eyebrows off."},
							{true, true, 00, "ENOKI                            ......doing that."},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};

					// The bookshelf room
					case 11:
					{
						line lc[32] = {
							{true, true, 00, "ENOKI                            Nous sommes ici!"},
							{true, true, 00, "ENOKI                            The bookshelf room."},
							{true, true, 00, "MAPLE                            You weren't kidding about there"},
							{true, true, 00, "MAPLE                            literally being just a bookshelf"},
							{true, true, 00, "MAPLE                            room, were you?"},
							{true, true, 00, "ENOKI                            Bon, so I can't move it and Aaron"},
							{true, true, 00, "ENOKI                            can't either, so I was wondering,"},
							{true, true, 00, "ENOKI                            how about using that elf magic?"},
							{true, true, 00, "MAPLE                            Let me get this straight..."},
							{true, true, 00, "MAPLE                            You want me to *burn* a perfectly"},
							{true, true, 00, "MAPLE                            good bookshelf?"},
							{true, true, 00, "ENOKI                            Yeah! I wanna see if there's a"},
							{true, true, 00, "ENOKI                            secret passage behind it or"},
							{true, true, 00, "ENOKI                            somethin', y'know?"},
							{true, true, 00, "MAPLE                            I refuse. This is ridiculous."},
							{true, true, 00, "MAPLE                            These are perfectly good books."},
							{true, true, 00, "ENOKI                            Most are rotting away, so"},
							{true, true, 00, "ENOKI                            it's probably best that they get"},
							{true, true, 00, "ENOKI                            burned. I checked."},
							{true, true, 00, "MAPLE                            Are you sure?"},
							{true, true, 00, "ENOKI                            Absolutely."},
							{true, true, 00, "MAPLE                            Alright... I'll make a deal."},
							{true, true, 00, "MAPLE                            I'll burn this, but you need to"},
							{true, true, 00, "MAPLE                            save at least one book."}, // j'ai compris?
							{true, true, 00, "MAPLE                            J'ai compris? Oui?"},
							{true, true, 00, "ENOKI                            Oui!"},
							{true, true, 00, "ENOKI                            ....alright, I got my book."},
							{true, true, 00, "ENOKI                            Remember, use the 'R' trigger"},
							{true, true, 00, "ENOKI                            to send out a bolt of fire!"},
							{true, true, 00, "MAPLE                            ...What are you talking about??"},
							{true, true, 00, "ENOKI                            Huh? Oh, nothing"},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};

					// Shoot the bookshelf
					case 12:
					{
						line lc[32] = {
							{true, true, 00, "MAPLE                            A...."},
							{true, true, 00, "ENOKI                            Well, there's no passage."},
							{true, true, 00, "MAPLE                            You don't say."},
							{true, true, 00, "ENOKI                            That's weird."},
							{true, true, 00, "MAPLE                            Enoki... Look here."},
							{true, true, 00, "MAPLE                            I guess it doesn't make any sense"},
							{true, true, 00, "MAPLE                            to be angry, so I won't be, but.."},
							{true, true, 00, "MAPLE                            You need to stop being like this."},
							{true, true, 00, "MAPLE                            You and Aaron just spent all this"},
							{true, true, 00, "MAPLE                            money on a barely furnished"},
							{true, true, 00, "MAPLE                            castle without basic faculties"},
							{true, true, 00, "MAPLE                            for what? So you could play like"},
							{true, true, 00, "MAPLE                            you're a princess? While I'm over"},
							{true, true, 00, "MAPLE                            in Carolina, sacrificing the best"},
							{true, true, 00, "MAPLE                            parts of my life for an apartment"},
							{true, true, 00, "MAPLE                            with the bare essentials?"},
							{true, true, 00, "MAPLE                            Enoki... Please."},
							{true, true, 00, "MAPLE                            I don't want to be the bad guy."},
							{true, true, 00, "MAPLE                            I know you didn't really have a"},
							{true, true, 00, "MAPLE                            childhood or parents, I get it."},
							{true, true, 00, "MAPLE                            That's me too."},
							{true, true, 00, "MAPLE                            But you can't keep going on like"},
							{true, true, 00, "MAPLE                            this. Do you understand?"},
							{true, true, 00, "ENOKI                            I do understand."}, // j'ai compris?
							{true, true, 00, "MAPLE                            It's 5:00 in the morning, I'm"},
							{true, true, 00, "MAPLE                            going back to bed. I'll see y'all"},
							{true, true, 00, "MAPLE                            in the morning, oui?"},
							{true, true, 00, "ENOKI                            Oui.."},
							{true, true, 00, "MAPLE                            Hey, don't beat yourself up about"},
							{true, true, 00, "MAPLE                            it. S'il te plait.. Bonne nuit."},
							{true, true, 00, "ENOKI                            Bonne nuit.."},
							{true, true, 00, "COM: Endscene"}};
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

								{true, true, 00, "(Every single one of these are   Enoki's, aren't they?)"},
								{true, true, 00, "(Of course Aaron would pick up   around here.)"},
								{true, true, 00, "(They're so different... How on  earth are they not fighting-"},
								{true, true, 00, "-all the time? I don't get it.)"},
								{true, true, 00, "(If I had a boyfriend, I'd make  him pick up these clothes-"},
								{true, true, 00, "-immediately.)"},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}

						else if (me == 1)
						{
							line lc[32] = {

								{true, true, 00, "(If I knew Maple was coming so   soon I probably would'a cleaned"},
								{true, true, 00, "-these up a little sooner....)"},
								{true, true, 00, "(Maybe I can pick 'em up now and she won't notice.)"},
								{true, true, 00, "(Then again, maybe she already   saw it and is already judging.)"},
								{true, true, 00, "(..This one's cute enough, maybe I'll just leave it on the floor-"},
								{true, true, 00, "-and wear it tomorrow.)"},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}

						else if (me == 2)
						{
							line lc[32] = {

								{true, true, 00, "(Enoki wasn't this messy when we lived in the castle.)"},
								{true, true, 00, "(Maybe she thinks we're finally  moved in for good, so she-"},
								{true, true, 00, "-feels comfortable here.)"},
								{true, true, 00, "(I know it's probably too soon tocall, but Aaron Tremblay-"},
								{true, true, 00, "-you've done it. You've got your own place, and you've got"},
								{true, true, 00, "a wife to leave her clothes on   the floor.)"},
								{true, true, 00, "(I can't think of anything else  I could want, now.)"},
								{true, true, 00, "(Well.....                       I miss my car.)"},
								{true, true, 00, "(Maybe I'll talk to Scout about  putting in a racetrack.)"},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}

						else if (me == 3)
						{
							line lc[32] = {
								{true, true, 00, "(Yeah, I definitely need to not  be here.)"},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}

						else
						{
							line lc[32] = {
								{true, true, 00, "(These clothes have obviously    been here for a while.)"},
								{true, true, 00, "COM: Endscene"}};
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

									{true, true, 00, "(At least when they were living  in that castle, their bed was in-"},
									{true, true, 00, "-the center of the room. What's  this supposed to be?)"},
									{true, true, 00, "(Who's shoved up awkwardly in thecorner? Aaron probably.)"},
									{true, true, 00, "(I swear, that girl is going to  give him gray hairs ten years    early.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							if (me == 1)
							{
								line lc[32] = {

									{true, true, 00, "(I'm so glad I don't have'ta     sleep in the middle of the room.)"},
									{true, true, 00, "(Rolling over off the bed onto   that stone really really hurt.)"},
									{true, true, 00, "(Now I getta roll either into    the wall or into Aaron.)"},
									{true, true, 00, "(I'm so glad he doesn't seem to  mind that much.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							if (me == 2)
							{
								line lc[32] = {

									{true, true, 00, "(Maple isn't gonna be happy when she sees this room.)"},
									{true, true, 00, "(I remember when she used to be  so easy-going...)"},
									{true, true, 00, "(She's just so frustrating to be around these days.)"},
									{true, true, 00, "(Maybe she shouldn't have come.  Every time I try to do something-"},
									{true, true, 00, "-to help her out, she just spits all over me and pouts.)"},
									{true, true, 00, "(Maybe she'll get tired of       living here and just go home.)"},
									{true, true, 00, "(Maybe she's right. Maybe I'm    just living Enoki's fantasy.)"},
									{true, true, 00, "(But Enoki's the first bit of    happiness I've had in years.)"},
									{true, true, 00, "(Maybe we'll both change...      I hope something changes.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							if (me == 3)
							{
								line lc[32] = {

									{true, true, 00, "(I probably shouldn't be in here uninvited...)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
						}
						else if (globals->current_save->checkpoint < 10)
						{
							if (me == 0)
							{
								line lc[32] = {

									{true, true, 00, "(There's no way I'm going to everadmit it, but...)"},
									{true, true, 00, "(It's nice staying with them. I  keep forgetting how much I)"},
									{true, true, 00, "(miss staying with somebody.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							if (me == 1)
							{
								line lc[32] = {

									{true, true, 00, "(Y'know, I wish I could go back  in time and talk to little me.)"},
									{true, true, 00, "(She would NOT BELIEVE what this year's been like.)"},
									{true, true, 00, "(I.. don't think my parents know I'm here.)"},
									{true, true, 00, "(Where the heck do they think I  am I wonder, huh.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							if (me == 2)
							{
								line lc[32] = {

									{true, true, 00, "(I really, really need to get    Maple her own place.)"},
									{true, true, 00, "(I didn't figure she'd actually  pull her weight, but...)"},
									{true, true, 00, "(With all that spelunking, we've made enough to break even.)"},
									{true, true, 00, "(I'm surprised she hasn't really been asking for a new place.)"},
									{true, true, 00, "(Maybe she doesn't really like   staying by herself.)"},
									{true, true, 00, "(I really don't want to have to  make another house.)"},
									{true, true, 00, "(I'll talk to that Olivier guy   and see what he can do.)"},
									{true, true, 00, "(He seems handy enough.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							if (me == 3)
							{
								line lc[32] = {
									{true, true, 00, "(Yep, that's a room.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							if (me == 4)
							{
								line lc[32] = {
									{true, true, 00, "(Definitely like all the sunlightin here.)"},
									{true, true, 00, "(Could use a plant or two.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							if (me == 5)
							{
								line lc[32] = {
									{true, true, 00, "(This reminds me so much of Vee'sparents' house.)"},
									{true, true, 00, "(I hope they're trustworthy      people.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							if (me == 6)
							{
								line lc[32] = {
									{true, true, 00, "(Ok, I like these people.)"},
									{true, true, 00, "(They make me feel organized.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
						}
						else if (globals->current_save->checkpoint < 12)
						{
							if (me == 0)
							{
								line lc[32] = {
									{true, true, 00, "(Thank goodness, that new guy..  er.. guy is a cook.)"},
									{true, true, 00, "(Maybe gumbo every day won't be  as heavy when it's not mine.)"},
									{true, true, 00, "(Maybe he's got a good sense of  humor, too.)"},
									{true, true, 00, "(Ugh, what's wrong with me.. I'm getting excited to meet people?)"},
									{true, true, 00, "(What, am I sick? Am I becoming..personable? Gross.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							else if (me == 1)
							{
								line lc[32] = {

									{true, true, 00, "(Y'know, this room hasn't changedin a bit.)"},
									{true, true, 00, "(What if I moved the bed to the  other side of the room?)"},
									{true, true, 00, "(Hmm, then it'd be harder to hideclothes from guests.)"},
									{true, true, 00, "(I gotta pick those up.. eh...   later, later is good.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							else if (me == 2)
							{
								line lc[32] = {

									{true, true, 00, "(Well, there goes the last chancefor Maple to take the cabin.)"},
									{true, true, 00, "(As long as Enoki thinks its     sweet that Maple wants to stay,)"},
									{true, true, 00, "(This isn't going to be my house.What happened to her being so)"},
									{true, true, 00, "(independent and proud of it?    Ugh.. generosity leech.)"},
									{true, true, 00, "(And now Enoki's onto the fact   that I'm a bit upset.)"},
									{true, true, 00, "(Crap.. Now I'm sounding like    Maple myself.)"},
									{true, true, 00, "(Do all siblings sound like this?Heck if I'd know.)"},
									{true, true, 00, "(I don't have any friends.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							else if (me == 3)
							{
								line lc[32] = {
									{true, true, 00, "(Aaron's birthday is coming up.. plants could be a good gift.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							else if (me == 7)
							{
								line lc[32] = {
									{true, true, 00, "(Definitely like all the light   in here.)"},
									{true, true, 00, "(Could use a plant or two.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							else
							{
								line lc[32] = {
									{true, true, 00, "(It probably isn't my business tobe here.)"},
									{true, true, 00, "COM: Endscene"}};
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

									{true, true, 00, "MAPLE                            So, uh, what's the book?"},
									{true, true, 00, "AARON                            Oh, that's mine."},
									{true, true, 00, "AARON                            You know I'm not a fiction guy,"},
									{true, true, 00, "AARON                            But Enoki is stubborn."},
									{true, true, 00, "ENOKI                            You ever heard'a Yellow?"},
									{true, true, 00, "ENOKI                            It's kinda fun, I got Aaron into it."},
									{true, true, 00, "MAPLE                            ...does this have pictures?"},
									{true, true, 00, "MAPLE                            Do you still read picture books?"},
									{true, true, 00, "ENOKI                            It's got cigarettes in it though!"},
									{true, true, 00, "ENOKI                            That means its for kids AND      adults."},
									{true, true, 00, "MAPLE                            Huh, they make books like that?"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}

							if (me == 1)
							{
								line lc[32] = {

									{true, true, 00, "ENOKI                            Oh, oh Maple? You want juice?"},
									{true, true, 00, "MAPLE                            What kind of juice?"},
									{true, true, 00, "ENOKI                            It's a secret."},
									{true, true, 00, "MAPLE                            I'm not drinking mystery liquid."},
									{true, true, 00, "ENOKI                            ...."},
									{true, true, 00, "ENOKI                            Ok fine, it's...                 orange juice!           POISON.", 10},
									{true, true, 00, "MAPLE                            You don't think I would have"},
									{true, true, 00, "MAPLE                            found that out?"},
									{true, true, 00, "ENOKI                            Maybe?"},
									{true, true, 00, "MAPLE                            No. Merci."},
									{true, true, 00, "COM: Endscene"},
									{true, true, 00, "MAPLE                            ...Coming from you it might be."},
									{true, true, 00, "ENOKI                            Guess you gotta drink it find    out, huh?"},
									{true, true, 00, "MAPLE                            Yeah, I'm not that thirsty."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}

							if (me == 2)
							{
								line lc[32] = {

									{true, true, 00, "(We're kind of low on orange     juice.)"},
									{true, true, 00, "(I'll probably need to head to   town and sell some produce.)"},
									{true, true, 00, "(Selling one fruit to get        another fruit, heh.)"},
									{true, true, 00, "(If only potato juice tasted     a little better.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}

							if (me == 3)
							{
								line lc[32] = {

									{true, true, 00, "ENOKI                            EEEE! All my friends know"},
									{true, true, 00, "ENOKI                            Each other now!!"},
									{true, true, 00, "ENOKI                            We're like a proper group."},
									{true, true, 00, "MAPLE                            Whoa, I haven't decided if-"},
									{true, true, 00, "MAPLE                            I'm staying, chill out."},
									{true, true, 00, "SCOUT                            Anyone else showing up?"},
									{true, true, 00, "AARON                            I guess we'll wait and see."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
						}

						else if (globals->current_save->checkpoint < 10)
						{
							if (me < 3)
							{
								line lc[32] = {
									{true, true, 00, "MAPLE                            So, it looks like I've read 'em  all."},
									{true, true, 00, "AARON                            We haven't gone to town in a     while."},
									{true, true, 00, "MAPLE                            I wonder what's going on outside."},
									{true, true, 00, "ENOKI                            If anything was bad, you know"},
									{true, true, 00, "ENOKI                            Scout woulda' said something."},
									{true, true, 00, "ENOKI                            He's got that internet thing."},
									{true, true, 00, "MAPLE                            I wonder if I can get new books  that way."},
									{true, true, 00, "AARON                            That would sure be nice."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							else
							{
								line lc[32] = {
									{true, true, 00, "You see a bunch of books you've  never seen before."},
									{true, true, 00, "None look particularly           interesting... for now."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
						}
						else if (globals->current_save->checkpoint < 12)
						{
							if (me < 3)
							{
								line lc[32] = {
									{true, true, 00, "MAPLE                            I think we need a VCR."},
									{true, true, 00, "AARON                            You gonna buy one?"},
									{true, true, 00, "MAPLE                            Yes. And lots of tapes."},
									{true, true, 00, "ENOKI                            Ooo, can you get the new Time    Raider"},
									{true, true, 00, "ENOKI                            movie? I heard they made one!"},
									{true, true, 00, "MAPLE                            Just to spite you, I think I'll  get"},
									{true, true, 00, "MAPLE                            everything I can find BUT that."},
									{true, true, 00, "ENOKI                            Aw.. I was thinking that maybe"},
									{true, true, 00, "ENOKI                            y'know, since we all like it,"},
									{true, true, 00, "ENOKI                            ...have a kingdom movie night?"},
									{true, true, 00, "MAPLE                            Okay, MAYBE. MAYBE."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							else if (me == 7)
							{
								line lc[32] = {
									{true, true, 00, "You smile, thinking about their  inferior kitchen."},
									{true, true, 00, "Definitely gonna become regulars."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							else
							{
								line lc[32] = {
									{true, true, 00, "You see a bunch of books you've  never seen before."},
									{true, true, 00, "None look particularly           short interesting... for now."},
									{true, true, 00, "COM: Endscene"}};
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
								{true, true, 00, "AARON                            I need to check on the others."},
								{true, true, 00, "COM: Endscene"},
							};
							dialogue_page_lite(lc);
							break;
						}
						break;
					};
					case 21:
					{
						line lc[32] = {
							{true, true, 00, "ENOKI'S GARDEN                   You touch it, I kill you"},
							{true, true, 00, "COM: Endscene"},
						};
						dialogue_page_lite(lc);
						break;
					};
					case 22:
					{
						line lc[32] = {
							{true, true, 00, "WOOD CHOPPING SPOT               Where wood is chopped"},
							{true, true, 00, "COM: Endscene"}};
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
								{true, true, 00, "Hmmm... This seems like somethingfor Enoki."},
								{true, true, 00, "COM: Endscene"}};
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
								{true, true, 00, "Hmmm... This seems like somethingfor Aaron."},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
						break;
					};
					case 25:
					{
						line lc[32] = {
							{true, true, 00, "CAVE OF DANGEROUS BATS           Warning: Contains Bats"},
							{true, true, 00, "COM: Endscene"}};
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
								{true, true, 00, "I think Maple is the only one whocan go in safely."},
								{true, true, 00, "COM: Endscene"}};
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
									{true, true, 00, "MAPLE                            Plants, huh?"},
									{true, true, 00, "MAPLE                            Isn't there a garden up top?"},
									{true, true, 00, "SCOUT                            You see, I, er-"},
									{true, true, 00, "SCOUT                            It's not really about the plants."},
									{true, true, 00, "SCOUT                            I'm a dirt scientist."},
									{true, true, 00, "MAPLE                            Dirt scientist?"},
									{true, true, 00, "SCOUT                            There's a scientist for, uh.."},
									{true, true, 00, "SCOUT                            Well, everything."},
									{true, true, 00, "MAPLE                            Clearly."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 1)
							{
								line lc[32] = {
									{true, true, 00, "ENOKI                            I think THAT plant is the one."},
									{true, true, 00, "ENOKI                            That's my favorite."},
									{true, true, 00, "SCOUT                            You want a cutting?"},
									{true, true, 00, "ENOKI                            What is it?"},
									{true, true, 00, "SCOUT                            I... I don't know, actually."},
									{true, true, 00, "SCOUT                            I study dirt, not plants."},
									{true, true, 00, "ENOKI                            Maybe it's a mystery fruit!"},
									{true, true, 00, "SCOUT                            I.. guess it could be."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 2)
							{
								line lc[32] = {
									{true, true, 00, "AARON                            Any progress?"},
									{true, true, 00, "SCOUT                            Heck yeah!"},
									{true, true, 00, "SCOUT                            I've got something new."},
									{true, true, 00, "AARON                            What's it called?"},
									{true, true, 00, "SCOUT                            I call it 'Scout-Out'."},
									{true, true, 00, "SCOUT                            Guaranteed to get rid of weeds."},
									{true, true, 00, "AARON                            Dude, that's amazing!"},
									{true, true, 00, "SCOUT                            Only issue is, well..."},
									{true, true, 00, "SCOUT                            It gets rid of the plants, too."},
									{true, true, 00, "AARON                            Ah, bummer."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 3)
							{
								line lc[32] = {
									{true, true, 00, "(Oh man, oh man oh man oh man..)"},
									{true, true, 00, "(I need to get this new formula  figured out fast.)"},
									{true, true, 00, "(Maybe promising the investors   magic dirt was a bad idea.)"},
									{true, true, 00, "(Maybe I can just hide down here and they won't find me.)"},
									{true, true, 00, "(Probably should take my name offmy hatch, first.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
						}
						else if (globals->current_save->checkpoint < 10)
						{
							if (me == 0)
							{
								line lc[32] = {
									{true, true, 00, "MAPLE                            Same thing going on here?"},
									{true, true, 00, "SCOUT                            Yeah, yeah."},
									{true, true, 00, "MAPLE                            They still haven't talk to you"},
									{true, true, 00, "MAPLE                            about your results?"},
									{true, true, 00, "SCOUT                            Nah.. But I'm still getting a"},
									{true, true, 00, "SCOUT                            paycheck every week."},
									{true, true, 00, "MAPLE                            Hey, that's good."},
									{true, true, 00, "SCOUT                            Oh yeah."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 3)
							{
								line lc[32] = {
									{true, true, 00, "(Maple's been looking at these   plants every once in while..)"},
									{true, true, 00, "(At least she's got an opinion onthem.)"},
									{true, true, 00, "(I really, really need my boss tomessage me back about them.)"},
									{true, true, 00, "(I guess I shouldn't rock the    tree, the paycheck is solid.)"},
									{true, true, 00, "(I just want to make sure I'm    doing everything right.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else
							{
								line lc[32] = {
									{true, true, 00, "(Lots of unusual plants and dirt samples in jars.)"},
									{true, true, 00, "(You don't understand it... but  it's probably harmless.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
						}
						else if (globals->current_save->checkpoint < 12)
						{
							if (me == 0)
							{
								line lc[32] = {
									{true, true, 00, "SCOUT                            Hey, uh.. Maple?"},
									{true, true, 00, "SCOUT                            Can I ask you something?"},
									{true, true, 00, "MAPLE                            Yeah, what's up?"},
									{true, true, 00, "SCOUT                            Do.. you.. er- like.. tennis?"},
									{true, true, 00, "MAPLE                                                             I love tennis.     Ew, tennis.", 16},
									{true, true, 00, "MAPLE                            Why do you ask?"},
									{true, true, 00, "SCOUT                            Oh, nothing, nothing.. I was.."},
									{true, true, 00, "MAPLE                            You want to play tennis?"},
									{true, true, 00, "SCOUT                            I mean, I've kinda always wanted"},
									{true, true, 00, "SCOUT                            to a bit, but I don't have"},
									{true, true, 00, "SCOUT                            anywhere to play, you know?"},
									{true, true, 00, "MAPLE                            Well, you get the field, and"},
									{true, true, 00, "MAPLE                            I might show you a thing or two."},
									{true, true, 00, "SCOUT                            Aw, you mean it??"},
									{true, true, 00, "MAPLE                            Sure thing."},
									{true, true, 00, "SCOUT                            Merci!"},
									{true, true, 00, "COM: Endscene"},
									{true, true, 00, "SCOUT                            Oh.. Nevermind, then."},
									{true, true, 00, "MAPLE                            Whatever."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 2)
							{
								line lc[32] = {
									{true, true, 00, "AARON                            Ok, so, hear me out."},
									{true, true, 00, "AARON                            You've got that tool for making"},
									{true, true, 00, "AARON                            bunkers like this really easily"},
									{true, true, 00, "AARON                            right? So..."},
									{true, true, 00, "AARON                            Underground race track."},
									{true, true, 00, "SCOUT                            Oh dude, that'd be sick!"},
									{true, true, 00, "SCOUT                            I'll definitely look into that."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 3)
							{
								line lc[32] = {
									{true, true, 00, "(Well, it's time. They want my   samples.)"},
									{true, true, 00, "(Let's hope I don't get fired.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else
							{
								line lc[32] = {
									{true, true, 00, "(Lots of unusual plants and dirt samples in jars.)"},
									{true, true, 00, "(You don't understand it... but  it's probably harmless.)"},
									{true, true, 00, "COM: Endscene"}};
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
									{true, true, 00, "MAPLE                            Hey look, more nerd stuff."},
									{true, true, 00, "SCOUT                            Excusez-moi, mademoiselle!"},
									{true, true, 00, "SCOUT                            That's Time Raiders!"},
									{true, true, 00, "MAPLE                            Time... Raiders?"},
									{true, true, 00, "SCOUT                            Yeah! The adventures of"},
									{true, true, 00, "SCOUT                            Jahn-Jahn Gazebo and his"},
									{true, true, 00, "SCOUT                            sidekicks, Nexus and Ninjette!"},
									{true, true, 00, "MAPLE                            Everything about that sounds.."},
									{true, true, 00, "MAPLE                            You ever have a girlfriend?"},
									{true, true, 00, "SCOUT                            No, girls thought I was a nerd."},
									{true, true, 00, "MAPLE                            Girls still do, dude."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 1)
							{
								line lc[32] = {
									{true, true, 00, "ENOKI                            Ooh, is this Time Raiders??"},
									{true, true, 00, "SCOUT                            You know Time Raiders??."},
									{true, true, 00, "ENOKI                            'I've got it, Jahn-Jahn!'"},
									{true, true, 00, "SCOUT                            Finally, someone else!"},
									{true, true, 00, "ENOKI                            Yeah, Aaron introduced me."},
									{true, true, 00, "ENOKI                            I like the artwork."},
									{true, true, 00, "ENOKI                            Can I borrow this after you?"},
									{true, true, 00, "SCOUT                            Sure thing! I'm almost done."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 2)
							{
								line lc[32] = {
									{true, true, 00, "AARON                            Yo, Time Raiders?"},
									{true, true, 00, "SCOUT                            Heck yeah!"},
									{true, true, 00, "AARON                            Nice! You check out the latest?"},
									{true, true, 00, "SCOUT                            Oh no, not yet."},
									{true, true, 00, "SCOUT                            Something you'll learn about, er-"},
									{true, true, 00, "SCOUT                            'Island Life',"},
									{true, true, 00, "SCOUT                            Getting new things is hard."},
									{true, true, 00, "SCOUT                            I could just use my computer, but"},
									{true, true, 00, "SCOUT                            That kills the experience."},
									{true, true, 00, "AARON                            Definitely, definitely."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 3)
							{
								line lc[32] = {
									{true, true, 00, "(I've gotta finish this one so   I can get it to Enoki.)"},
									{true, true, 00, "(But that formula I promise...   I swear, I'm so close.)"},
									{true, true, 00, "(Maybe just a few more           all-nighters.)"},
									{true, true, 00, "(A few more and I'll finally haveit.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
						}
						else if (globals->current_save->checkpoint < 10)
						{

							if (me == 0)
							{
								line lc[32] = {
									{true, true, 00, "SCOUT                            Hey, you know, you like to read"},
									{true, true, 00, "SCOUT                            a lot, right?"},
									{true, true, 00, "MAPLE                            Sure thing."},
									{true, true, 00, "SCOUT                            Do you think that maybe I could"},
									{true, true, 00, "SCOUT                            borrow some of your books?"},
									{true, true, 00, "MAPLE                            You wouldn't like them."},
									{true, true, 00, "SCOUT                            I'm sure I could try."},
									{true, true, 00, "MAPLE                            Well, do you like                romance? mushy period pieces?", 14},
									{true, true, 00, "MAPLE                            Hot and steamy romance?"},
									{true, true, 00, "SCOUT                            I... do you have anything else?"},
									{true, true, 00, "MAPLE                            No, that's what I like."},
									{true, true, 00, "MAPLE                            What, it make you uncomfortable?"},
									{true, true, 00, "SCOUT                            ..Maybe a bit."},
									{true, true, 00, "MAPLE                            Yeah, stick to your comic books."},
									{true, true, 00, "COM: Endscene"},
									{true, true, 00, "SCOUT                            I mean.. I can learn to, I'm     sure they're not bad."},
									{true, true, 00, "MAPLE                            Oh, give me a break."},
									{true, true, 00, "COM: Endscene"},
								};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 1)
							{
								line lc[32] = {
									{true, true, 00, "SCOUT                            Hey, Enoki?"},
									{true, true, 00, "ENOKI                            Yuh-huh?"},
									{true, true, 00, "SCOUT                            Can we talk about Maple?"},
									{true, true, 00, "ENOKI                            Oooh, what about her?"},
									{true, true, 00, "ENOKI                            You LIKE her, don't you?"},
									{true, true, 00, "SCOUT                            What's not to like?"},
									{true, true, 00, "ENOKI                            We all already know, hehe."},
									{true, true, 00, "SCOUT                            Aw crap, it's obvious."},
									{true, true, 00, "ENOKI                            She's hard to get."},
									{true, true, 00, "ENOKI                            I tried to set her up once."},
									{true, true, 00, "SCOUT                            You did?"},
									{true, true, 00, "ENOKI                            They even dated for a bit."},
									{true, true, 00, "ENOKI                            He just got on her nerves."},
									{true, true, 00, "ENOKI                            You gotta be perfect for her."},
									{true, true, 00, "SCOUT                            And I'm not."},
									{true, true, 00, "ENOKI                            I don't know what perfect is."},
									{true, true, 00, "SCOUT                            Well, I can dream I guess."},
									{true, true, 00, "ENOKI                            But hey, don't change yourself."},
									{true, true, 00, "ENOKI                            Just be the best 'you'."},
									{true, true, 00, "SCOUT                            I guess you're right."},
									{true, true, 00, "ENOKI                            The right girl'll come in time."},
									{true, true, 00, "SCOUT                            Right. Merci, Enoki."},
									{true, true, 00, "ENOKI                            De rien!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 2)
							{
								line lc[32] = {
									{true, true, 00, "SCOUT                            Hey, bro, so, how'd you, er.."},
									{true, true, 00, "SCOUT                            How'd you first ask Enoki out?"},
									{true, true, 00, "AARON                            I just invited her to coffee."},
									{true, true, 00, "SCOUT                            Coffee, coffee, right.."},
									{true, true, 00, "SCOUT                            We don't uh, hmm.. No coffee.."},
									{true, true, 00, "AARON                            You want to ask Maple out?"},
									{true, true, 00, "SCOUT                            Well, I.. Yeah, I do."},
									{true, true, 00, "AARON                            I'd tell you to give up, but at"},
									{true, true, 00, "AARON                            the same time, you never know."},
									{true, true, 00, "AARON                            No one's good enough for her."},
									{true, true, 00, "SCOUT                            I figured it wasn't worth it."},
									{true, true, 00, "AARON                            Absolutely no pleasing her."},
									{true, true, 00, "AARON                            Trust me, I know."},
									{true, true, 00, "SCOUT                            What do you mean?"},
									{true, true, 00, "AARON                            Her type is those losers who"},
									{true, true, 00, "AARON                            they're way cooler than they"},
									{true, true, 00, "AARON                            are. Now, I'll give her some"},
									{true, true, 00, "AARON                            credit, though. She puts up"},
									{true, true, 00, "AARON                            with a lot of the other kind"},
									{true, true, 00, "AARON                            of loser, too. Just..."},
									{true, true, 00, "AARON                            Work on yourself. Maybe try"},
									{true, true, 00, "AARON                            to be a bit more confident and"},
									{true, true, 00, "AARON                            socially-aware, right?"},
									{true, true, 00, "SCOUT                            Right. That's a good start."},
									{true, true, 00, "AARON                            Good luck, man."},
									{true, true, 00, "SCOUT                            Merci."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 3)
							{
								line lc[32] = {
									{true, true, 00, "(Maybe if I can just get Maple toread a few copies,)"},
									{true, true, 00, "(We'll finally have something in common with her.)"},
									{true, true, 00, "(In my dreams.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 7)
							{
								line lc[32] = {
									{true, true, 00, "GUY                              You like Time Raiders?"},
									{true, true, 00, "SCOUT                            Yeah, a bit."},
									{true, true, 00, "GUY                              How often you get new ones?"},
									{true, true, 00, "SCOUT                            Diana ships in new ones weekly."},
									{true, true, 00, "GUY                              Ah okay, I didn't wanna move"},
									{true, true, 00, "GUY                              here and have to give it up."},
									{true, true, 00, "SCOUT                            There is a bit of a waiting"},
									{true, true, 00, "SCOUT                            list, though. You gotta go"},
									{true, true, 00, "SCOUT                            after Enoki, she likes em."},
									{true, true, 00, "GUY                              Nah, I'll just take em first."},
									{true, true, 00, "SCOUT                            Look, you take that up with her."},
									{true, true, 00, "GUY                              Will do."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else
							{
								line lc[32] = {
									{true, true, 00, "(Last month's comic books remain lying on the floor.)"},
									{true, true, 00, "(Slowly collecting dust.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
						}
						else if (globals->current_save->checkpoint < 12)
						{
							if (me == 0)
							{
								line lc[32] = {
									{true, true, 00, "SCOUT                            Hey, you know, you like to read"},
									{true, true, 00, "SCOUT                            a lot, right?"},
									{true, true, 00, "MAPLE                            Sure thing."},
									{true, true, 00, "SCOUT                            Do you think that maybe I could"},
									{true, true, 00, "SCOUT                            borrow some of your books?"},
									{true, true, 00, "MAPLE                            You wouldn't like them."},
									{true, true, 00, "SCOUT                            I'm sure I could try."},
									{true, true, 00, "MAPLE                            You like romance?"},
									{true, true, 00, "MAPLE                            Steamy romance?"},
									{true, true, 00, "SCOUT                            I... do you have anything else?"},
									{true, true, 00, "MAPLE                            No, that's what I like."},
									{true, true, 00, "MAPLE                            What, it make you uncomfortable?"},
									{true, true, 00, "SCOUT                            ..Maybe a bit."},
									{true, true, 00, "MAPLE                            Yeah, stick to your comic books."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 1)
							{
								line lc[32] = {
									{true, true, 00, "SCOUT                            Hey, Enoki?"},
									{true, true, 00, "ENOKI                            Yuh-huh?"},
									{true, true, 00, "SCOUT                            Can we talk about Maple?"},
									{true, true, 00, "ENOKI                            Oooh, what about her?"},
									{true, true, 00, "ENOKI                            You LIKE her, don't you?"},
									{true, true, 00, "SCOUT                            What's not to like?"},
									{true, true, 00, "ENOKI                            We all already know, hehe."},
									{true, true, 00, "SCOUT                            Aw crap, it's obvious."},
									{true, true, 00, "ENOKI                            She's hard to get."},
									{true, true, 00, "ENOKI                            I tried to set her up once."},
									{true, true, 00, "SCOUT                            You did?"},
									{true, true, 00, "ENOKI                            They even dated for a bit."},
									{true, true, 00, "ENOKI                            He just got on her nerves."},
									{true, true, 00, "ENOKI                            You gotta be perfect for her."},
									{true, true, 00, "SCOUT                            And I'm not."},
									{true, true, 00, "ENOKI                            I don't know what perfect is."},
									{true, true, 00, "SCOUT                            Well, I can dream I guess."},
									{true, true, 00, "ENOKI                            But hey, don't change yourself."},
									{true, true, 00, "ENOKI                            Just be the best 'you'."},
									{true, true, 00, "SCOUT                            I guess you're right."},
									{true, true, 00, "ENOKI                            The right girl'll come in time."},
									{true, true, 00, "SCOUT                            Right. Merci, Enoki."},
									{true, true, 00, "ENOKI                            De rien!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 2)
							{
								line lc[32] = {
									{true, true, 00, "SCOUT                            Hey, bro, so, how'd you, er.."},
									{true, true, 00, "SCOUT                            How'd you first ask Enoki out?"},
									{true, true, 00, "AARON                            I just invited her to coffee."},
									{true, true, 00, "SCOUT                            Coffee, coffee, right.."},
									{true, true, 00, "SCOUT                            We don't uh, hmm.. No coffee.."},
									{true, true, 00, "AARON                            You want to ask Maple out?"},
									{true, true, 00, "SCOUT                            Well, I.. Yeah, I do."},
									{true, true, 00, "AARON                            I'd tell you to give up, but at"},
									{true, true, 00, "AARON                            the same time, you never know."},
									{true, true, 00, "AARON                            No one's good enough for her."},
									{true, true, 00, "SCOUT                            I figured it wasn't worth it."},
									{true, true, 00, "AARON                            Absolutely no pleasing her."},
									{true, true, 00, "AARON                            Trust me, I know."},
									{true, true, 00, "SCOUT                            What do you mean?"},
									{true, true, 00, "AARON                            Her type is those losers who"},
									{true, true, 00, "AARON                            they're way cooler than they"},
									{true, true, 00, "AARON                            are. Now, I'll give her some"},
									{true, true, 00, "AARON                            credit, though. She puts up"},
									{true, true, 00, "AARON                            with a lot of the other kind"},
									{true, true, 00, "AARON                            of loser, too. Just..."},
									{true, true, 00, "AARON                            Work on yourself. Maybe try"},
									{true, true, 00, "AARON                            to be a bit more confident and"},
									{true, true, 00, "AARON                            socially-aware, right?"},
									{true, true, 00, "SCOUT                            Right. That's a good start."},
									{true, true, 00, "AARON                            Good luck, man."},
									{true, true, 00, "SCOUT                            Merci."},
									{true, true, 00, " "},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 3)
							{
								line lc[32] = {
									{true, true, 00, "(Maybe if I can just get Maple toread a few copies,)"},
									{true, true, 00, "(We'll finally have something in common with her.)"},
									{true, true, 00, "(In my dreams.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 7)
							{
								line lc[32] = {
									{true, true, 00, "GUY                              You like Time Raiders?"},
									{true, true, 00, "SCOUT                            Yeah, a bit."},
									{true, true, 00, "GUY                              How often you get new ones?"},
									{true, true, 00, "SCOUT                            Diana ships in new ones weekly."},
									{true, true, 00, "GUY                              Ah okay, I didn't wanna move"},
									{true, true, 00, "GUY                              here and have to give it up."},
									{true, true, 00, "SCOUT                            There is a bit of a waiting"},
									{true, true, 00, "SCOUT                            list, though. You gotta go"},
									{true, true, 00, "SCOUT                            after Enoki, she likes em."},
									{true, true, 00, "GUY                              Nah, I'll just take em first."},
									{true, true, 00, "SCOUT                            Look, you take that up with her."},
									{true, true, 00, "GUY                              Will do."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else
							{
								line lc[32] = {
									{true, true, 00, "(Last month's comic books remain lying on the floor.)"},
									{true, true, 00, "(Slowly collecting dust.)"},
									{true, true, 00, "COM: Endscene"}};
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
									{true, true, 00, "SCOUT                            Hey, please be careful about-"},
									{true, true, 00, "SCOUT                            my computer, it's expensive."},
									{true, true, 00, "MAPLE                            I'm not gonna touch it."},
									{true, true, 00, "MAPLE                            Although, now I want to.."},
									{true, true, 00, "SCOUT                            Wait!! Please-"},
									{true, true, 00, "MAPLE                            Dude, I'm not gonna touch it!"},
									{true, true, 00, "MAPLE                            You nerds and your toys.."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 1)
							{
								line lc[32] = {
									{true, true, 00, "ENOKI                            Hey Scout, you got a website?"},
									{true, true, 00, "SCOUT                            Yeah! It's not very good though."},
									{true, true, 00, "ENOKI                            May I see it?"},
									{true, true, 00, "SCOUT                            Not right now, it's... not done."},
									{true, true, 00, "ENOKI                            Ah, okay."},
									{true, true, 00, "ENOKI                            I wanna make a website."},
									{true, true, 00, "ENOKI                            It looks like a lot of fun."},
									{true, true, 00, "SCOUT                            It's definitely fun."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 2)
							{
								line lc[32] = {
									{true, true, 00, "AARON                            You hear about the millenium bug?"},
									{true, true, 00, "SCOUT                            Well of course."},
									{true, true, 00, "AARON                            Were you okay?"},
									{true, true, 00, "SCOUT                            Yeah, I was fine."},
									{true, true, 00, "SCOUT                            There was a weird bug in"},
									{true, true, 00, "SCOUT                            one program."},
									{true, true, 00, "SCOUT                            I had a shopping list program,"},
									{true, true, 00, "SCOUT                            It added tons of shoeshine to my"},
									{true, true, 00, "SCOUT                            my shopping list, which is now"},
									{true, true, 00, "SCOUT                            due on March 5th, 192000."},
									{true, true, 00, "AARON                            That's a little while to wait."},
									{true, true, 00, "SCOUT                            A glitchy date? I understand."},
									{true, true, 00, "SCOUT                            Extra items? That elludes me."},
									{true, true, 00, "SCOUT                            Bugs are just the weirdest thing."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 3)
							{
								line lc[32] = {
									{true, true, 00, "(I've graduated top of my class  with a 3.99 GPA.)"},
									{true, true, 00, "(I'm a real scientist, living    off a corporate grant.)"},
									{true, true, 00, "(I have a state of the art, whiz bang Castor 5000 computer.)"},
									{true, true, 00, "(And I can't use it, because I   forgot my password.)"},
									{true, true, 00, "(No wonder I can't sleep at      night.)"},
									{true, true, 00, "COM: Endscene"}};
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
									{true, true, 00, "(This looks really expensive...)"},
									{true, true, 00, "(I probably shouldn't touch.)"},
									{true, true, 00, "COM: Endscene"}};
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
									{true, true, 0, "MAPLE                            Oh! Bonjour, who are you?"},
									{true, true, 0, "SCOUT                            You must be Maple Tremblay?"},
									{true, true, 0, "SCOUT                            I'm Scout Williams."},
									{true, true, 0, "MAPLE                            Do you, uh, have this whole"},
									{true, true, 0, "MAPLE                            underground thing to yourself?"},
									{true, true, 0, "SCOUT                            Yeah, I, er- It's sort of top"},
									{true, true, 0, "SCOUT                            secret, but you're not the kind"},
									{true, true, 0, "SCOUT                            to share secrets, are you?"},
									{true, true, 0, "MAPLE                            I-"},
									{true, true, 0, "SCOUT                            So this company hired me to study"},
									{true, true, 0, "SCOUT                            soil and stuff on this island,"},
									{true, true, 0, "SCOUT                            and then they.. forgot about me."},
									{true, true, 0, "SCOUT                            They still send a paycheck though"},
									{true, true, 0, "SCOUT                            so I don't see a reason to leave."},
									{true, true, 0, "MAPLE                            Paid to do absolutely nothing?"},
									{true, true, 0, "SCOUT                            It gets so lonely up here though."},
									{true, true, 0, "SCOUT                            I'm glad your family showed up."},
									{true, true, 0, "SCOUT                            They were talkin' all this about"},
									{true, true, 0, "SCOUT                            a 'new country' or whatever, but"},
									{true, true, 0, "SCOUT                            they said I could be a Lord or a"},
									{true, true, 0, "SCOUT                            Duke or something."},
									{true, true, 0, "SCOUT                            I said as long as I got to be"},
									{true, true, 0, "SCOUT                            court magician, I wouldn't ask"},
									{true, true, 0, "SCOUT                            for anything else."},
									{true, true, 0, "MAPLE                            Yeah, you seem like the type."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 1)
							{
								line lc[32] = {
									{true, true, 0, "SCOUT                            Oh, hey Enoki! How's it going?"},
									{true, true, 0, "ENOKI                            Really good!! It's perfect"},
									{true, true, 0, "ENOKI                            outside today. Whatcha' workin'"},
									{true, true, 0, "ENOKI                            on?"},
									{true, true, 0, "SCOUT                            Right now? I've got this idea for"},
									{true, true, 0, "SCOUT                            this robot that's half-bat,"},
									{true, true, 0, "SCOUT                            half-fly swatter."},
									{true, true, 0, "SCOUT                            Bats like insects, right? So this"},
									{true, true, 0, "SCOUT                            is going to both eat and squash"},
									{true, true, 0, "SCOUT                            insects."},
									{true, true, 0, "ENOKI                            Are you calling it Smackula?"},
									{true, true, 0, "SCOUT                            I.. most certainly can."},
									{true, true, 0, "ENOKI                            By royal degree, I declare it"},
									{true, true, 0, "ENOKI                            hereby be referred to as the"},
									{true, true, 0, "ENOKI                            'Smackula'."},
									{true, true, 0, "ENOKI                            Or maybe the 'Smackchula', that"},
									{true, true, 0, "ENOKI                            way something finally rhymes"},
									{true, true, 0, "ENOKI                            with Spatula."},
									{true, true, 0, "SCOUT                            We're solving the world's true"},
									{true, true, 0, "SCOUT                            issues here."},
									{true, true, 0, "ENOKI                            Mm-hmm!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 2)
							{
								line lc[32] = {
									{true, true, 0, "SCOUT                            Oh, hey Aaron! How've you been?"},
									{true, true, 0, "AARON                            Good, I'm just really tired. I"},
									{true, true, 0, "AARON                            think I underestimated how much"},
									{true, true, 0, "AARON                            wood I'd be chopping."},
									{true, true, 0, "AARON                            I'm making boards, too. I plan on"},
									{true, true, 0, "AARON                            having some houses up and about a"},
									{true, true, 0, "AARON                            quarter of the woods levelled."},
									{true, true, 0, "SCOUT                            How many people are coming here,"},
									{true, true, 0, "SCOUT                            do you think?"},
									{true, true, 0, "AARON                            I don't know.. maybe eight? Nine?"},
									{true, true, 0, "AARON                            Do you know anyone who' want to"},
									{true, true, 0, "AARON                            live here, too?"},
									{true, true, 0, "SCOUT                            No, not really."},
									{true, true, 0, "AARON                            You still talking to that girl?"},
									{true, true, 0, "SCOUT                            Nah, I lied about her."},
									{true, true, 0, "SCOUT                            I'll be real with you, I don't"},
									{true, true, 0, "SCOUT                            really have friends outside of"},
									{true, true, 0, "SCOUT                            y'all."},
									{true, true, 0, "SCOUT                            But it's cool. I've got cable."},
									{true, true, 0, "AARON                            I'm gonna build those houses, and"},
									{true, true, 0, "AARON                            we'll get some more people here."},
									{true, true, 0, "SCOUT                            So, What are you gonna do when"},
									{true, true, 0, "SCOUT                            those people come?"},
									{true, true, 0, "AARON                            I... don't know to be honest."},
									{true, true, 0, "AARON                            Probably chop more wood."},
									{true, true, 0, "SCOUT                            Take it easy, alright?"},
									{true, true, 0, "AARON                            Got it. You too."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 3)
							{
								line lc[32] = {
									{true, true, 00, "(This green formula's been makingall the plants grow real big.)"},
									{true, true, 00, "(I wonder what would happen if   I had some...)"},
									{true, true, 00, "(Maybe I'll get super plant      powers...)"},
									{true, true, 00, "(Or maybe I'll just die.)"},
									{true, true, 00, "(Those plant powers better be    worth the risk.)"},
									{true, true, 00, "COM: Endscene"}};
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
									{true, true, 00, "SCOUT                            Careful!!"},
									{true, true, 00, "SCOUT                            Some of this stuff is"},
									{true, true, 00, "SCOUT                            SUPER SUPER toxic!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 4)
							{
								line lc[32] = {
									{true, true, 00, "SCOUT                            Bonjour! Are you Olivier?"},
									{true, true, 00, "OLIVIER                          Oui! And you're Scout?"},
									{true, true, 00, "SCOUT                            That I am! Welcome!"},
									{true, true, 00, "OLIVIER                          This whole place was amazing!"},
									{true, true, 00, "SCOUT                            I tried to be honest in the ad."},
									{true, true, 00, "OLIVIER                          So, are you a scientist?"},
									{true, true, 00, "SCOUT                            You could say that, yeah."},
									{true, true, 00, "SCOUT                            I do a little of everything."},
									{true, true, 00, "OLIVIER                          And you live underground?"},
									{true, true, 00, "SCOUT                            I've got this machine that can"},
									{true, true, 00, "SCOUT                            Drill bunkers really easy."},
									{true, true, 00, "SCOUT                            I could keep drilling if I"},
									{true, true, 00, "SCOUT                            really wanted to, you know."},
									{true, true, 00, "OLIVIER                          Awesome!! Hey, you coming to"},
									{true, true, 00, "OLIVIER                          the Tremblay's for dinner?"},
									{true, true, 00, "SCOUT                            Of course!"},
									{true, true, 00, "OLIVIER                          Alright, I'll see you then!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 5)
							{
								line lc[32] = {
									{true, true, 00, "ELEANOR                          Bonjour, monsieur!"},
									{true, true, 00, "SCOUT                            Bonjour! Are you Eleanor?"},
									{true, true, 00, "ELEANOR                          Oui! It's nice to meet you."},
									{true, true, 00, "ELEANOR                          This whole place was amazing!"},
									{true, true, 00, "SCOUT                            I tried to be honest in the ad."},
									{true, true, 00, "ELEANOR                          Are you a wizard?"},
									{true, true, 00, "SCOUT                            You could say that, yeah."},
									{true, true, 00, "SCOUT                            I do a little of everything."},
									{true, true, 00, "ELEANOR                          And you live underground?"},
									{true, true, 00, "SCOUT                            I've got this machine that can"},
									{true, true, 00, "SCOUT                            Drill bunkers really easy."},
									{true, true, 00, "SCOUT                            I could keep drilling if I"},
									{true, true, 00, "SCOUT                            really wanted to, you know."},
									{true, true, 00, "ELEANOR                          That's so fascinating!"},
									{true, true, 00, "SCOUT                            Aw, merci!"},
									{true, true, 00, "ELEANOR                          Tonight, will I see you at dinner?"},
									{true, true, 00, "SCOUT                            Of course!"},
									{true, true, 00, "ELEANOR                          Wonderful!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 6)
							{
								line lc[32] = {
									{true, true, 00, "DIANA                            Bonjour! Hey, are you Scout?"},
									{true, true, 00, "SCOUT                            Bonjour! Are you Diana?"},
									{true, true, 00, "DIANA                            Oui! Nice to finally meet 'ya!"},
									{true, true, 00, "DIANA                            Man, this place is SICK!"},
									{true, true, 00, "SCOUT                            I tried to be honest in the ad."},
									{true, true, 00, "DIANA                            Are you a scientist or something?"},
									{true, true, 00, "SCOUT                            You could say that, yeah."},
									{true, true, 00, "SCOUT                            I do a little of everything."},
									{true, true, 00, "DIANA                            And you live underground?"},
									{true, true, 00, "SCOUT                            I've got this machine that can"},
									{true, true, 00, "SCOUT                            Drill bunkers really easy."},
									{true, true, 00, "SCOUT                            I could keep drilling if I"},
									{true, true, 00, "SCOUT                            really wanted to, you know."},
									{true, true, 00, "DIANA                            Aw, that's so cool!"},
									{true, true, 00, "SCOUT                            Merci!"},
									{true, true, 00, "DIANA                            You coming to dinner?"},
									{true, true, 00, "SCOUT                            Of course!"},
									{true, true, 00, "DIANA                            Sweet!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else
							{
								line lc[32] = {
									{true, true, 00, "(I wish I could make something   that would make me happy.)"},
									{true, true, 00, "(All that school and everything, but here I am, and...)"},
									{true, true, 00, "(I dunno. I move on from one     thing to the next thing,)"},
									{true, true, 00, "(I can't go anywhere without     immediately wanting to jump.)"},
									{true, true, 00, "(I just wanna be happy where I amfor once.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
						}
						else if (globals->current_save->checkpoint < 12)
						{
							if (me < 7)
							{
								line lc[32] = {
									{true, true, 00, "SCOUT                            Careful!!"},
									{true, true, 00, "SCOUT                            Some of this stuff is"},
									{true, true, 00, "SCOUT                            SUPER SUPER toxic!"},
									{true, true, 00, "SCOUT                            Oh, well you already knew that."},
									{true, true, 00, "SCOUT                            At least I hope so."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else
							{
								line lc[32] = {
									{true, true, 00, "SCOUT                            Bonjour! You're Guy, right?"},
									{true, true, 00, "GUY                              Oui. So you're Scout?"},
									{true, true, 00, "SCOUT                            Bienvenu! You like your cabin?"},
									{true, true, 00, "GUY                              You weren't kidding about the"},
									{true, true, 00, "GUY                              kitchen, huh?"},
									{true, true, 00, "SCOUT                            Not a bit!"},
									{true, true, 00, "GUY                              There don't seem to be too many"},
									{true, true, 00, "GUY                              people here, and you know that"},
									{true, true, 00, "GUY                              I ain't gonna be making a ton of"},
									{true, true, 00, "GUY                              food without customers."},
									{true, true, 00, "GUY                              How soon it is gonna be before we"},
									{true, true, 00, "GUY                              get a ton of new people here?"},
									{true, true, 00, "SCOUT                            Oh, it shouldn't be too long."},
									{true, true, 00, "GUY                              And I can hold you to that?"},
									{true, true, 00, "SCOUT                            Sans doute."},
									{true, true, 00, "GUY                              Tres bien alors."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
						}
						else if (globals->current_save->checkpoint == 12)
						{
							globals->current_save->checkpoint = 13;
							line lc[32] = {
								{true, true, 00, "ENOKI                            Salut? Scout, you down here?    "},
								{true, true, 00, "SCOUT                            Yeah! We're here! Where's        Aaron?"},
								{true, true, 00, "ENOKI                            He's out trying to check on      the others."},
								{true, true, 00, "SCOUT                            Thank goodness. Hey, Maple-      are you feeling alright? You    "},
								{true, true, 00, "SCOUT                            look really tired."},
								{true, true, 00, "MAPLE                            You shut up about me being       tired, I've had ENOUGH of that  "},
								{true, true, 00, "MAPLE                            this morning."},
								{true, true, 00, "SCOUT                            Oh- Okay, sure."},
								{true, true, 00, "SCOUT                            Hey Enoki, what's it look        like up there?"},
								{true, true, 00, "ENOKI                            Fine, it's just... there's this  weird, loud noise."},
								{true, true, 00, "ENOKI                            Aaron got spooked and wanted us  to be safe."},
								{true, true, 00, "SCOUT                            I trust his intuition."},
								{true, true, 00, "COM: Endscene"}};
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
									{true, true, 00, "AARON                            What the heck is going           on outside?"},
									{true, true, 00, "SCOUT                            It's Rufus. I think he ate       something weird."},
									{true, true, 00, "ENOKI                            Hehe, I get like that after      some of Guy's cooking, too.     "},
									{true, true, 00, "SCOUT                            No, I'm being serious. It has to do with my research."},
									{true, true, 00, "AARON                            Oh, so we finally get to know    what the mysterious bunker      "},
									{true, true, 00, "AARON                            scientist has been doing for     the past few months?"},
									{true, true, 00, "SCOUT                            I'm a dirt scientist, but I'm    also something else..."},
									{true, true, 00, "SCOUT                            I'm a plant scientist."},
									{true, true, 00, "ENOKI                            Say it ain't so!"},
									{true, true, 00, "OLIVIER                          And you didn't tell me?"},
									{true, true, 00, "SCOUT                            No, it was confidential."},
									{true, true, 00, "SCOUT                            See, there's this... plant. It   grows natively to these"},
									{true, true, 00, "SCOUT                            islands, and many people         believe it to be magic. It      "},
									{true, true, 00, "SCOUT                            makes you see things."},
									{true, true, 00, "ENOKI                            Like mushrooms?"},
									{true, true, 00, "SCOUT                            Mushrooms make everyone see      different things. This flower   "},
									{true, true, 00, "SCOUT                            makes everyone see the SAME      thing. That's why we're"},
									{true, true, 00, "SCOUT                            studying it. It's not just a     trip, there's something going   "},
									{true, true, 00, "SCOUT                            on."},
									{true, true, 00, "SCOUT                            Everyone who takes one acts      differently, but it's not       "},
									{true, true, 00, "SCOUT                            because of a chemical            imbalance. It's as if what they "},
									{true, true, 00, "SCOUT                            see is so troubling, so          life-shattering, that they're   "},
									{true, true, 00, "SCOUT                            different people on the other    end."},
									{true, true, 00, "ELEANOR                          What do they see, then?"},
									{true, true, 00, "SCOUT                            Nobody knows. They never tell    anyone anything."},
									{true, true, 00, "SCOUT                            Everyone who takes it gets a     small blue ring around their    "},
									{true, true, 00, "SCOUT                            eyes. They don't seem to last    forever, but it's how you can   "},
									{true, true, 00, "SCOUT                            tell. I was looking at that      footage of Rufus, and sure      "},
									{true, true, 00, "SCOUT                            enough... blue ring."},
									{true, true, 00, "AARON                            And so he's decided to become    a supervillain or something?    "},
									{true, true, 00, "SCOUT                            I don't know. Rufus isn't        very.. big, you know? So maybe- "},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}

							if (true)
							{
								bn::sound_items::knock.play();
								line lc[32] = {
									{true, true, 00, "SCOUT                            Uhh.... I think something's at   the door."},
									{true, true, 00, "AARON                            I've got my ax."},
									{true, true, 00, "SCOUT                            Hey, I tell you guys what.       You know that bunker maker that "},
									{true, true, 00, "SCOUT                            I have?"},
									{true, true, 00, "AARON                            Yeah...?"},
									{true, true, 00, "SCOUT                            I'll tell y'all what. Why        don't we bunker our way away    "},
									{true, true, 00, "SCOUT                            from the island? I was already   planning on making a tunnel to  "},
									{true, true, 00, "SCOUT                            shore."},
									{true, true, 00, "SCOUT                            (I was hoping to save that one   for the Scout Expo, but, uh..)"},
									{true, true, 00, "SCOUT                            (I guess I don't really have an  option now do I.)"},
									{true, true, 00, "ELEANOR                          Is that safe?"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}

							if (true)
							{
								bn::sound_items::knock.play();
								bn::sound_items::boom.play();

								line lc[3] = {
									{true, true, 00, "SCOUT                            Actually let's just go."},
									{true, true, 00, "ENOKI                            Allons-y?"},
									{true, true, 00, "COM: Endscene"}};
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
							{true, true, 00, "You stare at the art.                                             It's cool.   Yeah I don't care.", 2},
							{true, true, 00, "And as such...."},
							{true, true, 00, "So the art stares unto you."},
							{true, true, 00, "Art is weird."},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};

					case 41:
					{
						line lc[5] = {
							{true, true, 00, "- MORE HOUSES THIS WAY -"},
							{true, true, 00, "COM: Endscene"}};
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
								{true, true, 00, "MAPLE                            Probably should go to Scout's."},
								{true, true, 00, "COM: Endscene"}};
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
							{true, true, 00, " - WISHING POND -                DOESN'T WORK BUT FEEL FREE TO USEIT IF YOU'RE DESPERATE"},
							{true, true, 00, "The rocks in the way don't even  let you get a great view."},
							{true, true, 00, "Maybe if you could see over the  rocks, you could throw a coin in to make a wish."},
							{true, true, 00, "This wasn't thought through very well."},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};

					case 45:
					{
						line lc[5] = {
							{true, true, 00, " - LE MAISON DE LANDRY -"},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};
					case 46:
					{
						line lc[5] = {
							{true, true, 00, " - DIANA -"},
							{true, true, 00, "Either refers to the house or    the person."},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};

					// Guy's house signage
					case 47:
					{
						if (globals->current_save->checkpoint < 10)
						{
							line lc[5] = {
								{true, true, 00, " - SOME RANDOM GUY'S HOUSE -"},
								{true, true, 00, "No one has moved in yet, you see."},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else
						{
							line lc[5] = {
								{true, true, 00, " - GUY'S HOUSE -"},
								{true, true, 00, "Someone named guy has moved in,  you see."},
								{true, true, 00, "COM: Endscene"}};
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
							{true, true, 00, "~ JARGINS NOIRS ~"},
							{true, true, 00, "COM: Endscene"}};
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
									{true, true, 00, "MAPLE                            Oh, hey. So you're Eleanor?"},
									{true, true, 00, "ELEANOR                          Oui! Enchante de faire votre     connaissance."},
									{true, true, 00, "MAPLE                            Egalement. You seem...           No offense,"},
									{true, true, 00, "MAPLE                            A little old-fashioned?"},
									{true, true, 00, "ELEANOR                          Oh, it's just what we're used to."},
									{true, true, 00, "ELEANOR                          It's so nice to be so far away"},
									{true, true, 00, "ELEANOR                          from the city again. I had       forgotten how"},
									{true, true, 00, "ELEANOR                          sentimental I was for the trees."},
									{true, true, 00, "MAPLE                            I see. And you're her husband,   j'suppose?"},
									{true, true, 00, "OLIVIER                          Oui, I'm Olivier."},
									{true, true, 00, "ELEANOR                          He doesn't always talk much, but he makes it count."},
									{true, true, 00, "ELEANOR                          I met him in a garden, and he    taught me how to read."},
									{true, true, 00, "OLIVIER                          She's more special, though. She  just about saved my life."},
									{true, true, 00, "MAPLE                            Oh, how so?"},
									{true, true, 00, "OLIVIER                          It's not important-"},
									{true, true, 00, "ELEANOR                          From my mother."},
									{true, true, 00, "MAPLE                            Ah, I know how that is, haha."},
									{true, true, 00, "ELEANOR                          You do? She was going to drain   all his blood for a ritual."},
									{true, true, 00, "MAPLE                            I... Hmm, well, alright then.    That's.. not what I expected."},
									{true, true, 00, "MAPLE                            Nice to meet y'all, I guess?"},
									{true, true, 00, "ELEANOR                          Bien sur! I'm baking your family a pie right now as our 'merci'."},
									{true, true, 00, "MAPLE                            C'est bon, just no, uh, weird    ingredients, haha."},
									{true, true, 00, "MAPLE                            (What was Scout thinking invitingthese weirdos?!)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 1:
							{
								line lc[32] = {
									{true, true, 00, "ENOKI                            Bienvenue, y'all!! Je suis Enoki!Ravie de vous-autres rencontrer!"},
									{true, true, 00, "ELEANOR                          Bonjour! Enchante de faire votre connaissance."},
									{true, true, 00, "OLIVIER                          Bonjour!"},
									{true, true, 00, "ELEANOR                          I'm Eleanor, and this is my      husband Olivier."},
									{true, true, 00, "ENOKI                            I love your dress!! Where did youget it from?"},
									{true, true, 00, "ELEANOR                          Oh! I made it myself. I love yourdress, too!"},
									{true, true, 00, "ENOKI                            That's soo cool!!"},
									{true, true, 00, "ENOKI                            We look like we're about the samesize, maybe we can trade someday!"},
									{true, true, 00, "OLIVIER                          So, Scout said that you and your husband are royalty?"},
									{true, true, 00, "ENOKI                            Oh yes! This is our little       kingdom, but we're not cruel."},
									{true, true, 00, "ENOKI                            I'm like the chillest queen      you'll ever meet."},
									{true, true, 00, "ENOKI                            You guys wanna be a duke and     duchess?"},
									{true, true, 00, "ELEANOR                          I.. no thank you, I don't think  I know what those are."},
									{true, true, 00, "OLIVIER                          Merci, en tout cas."},
									{true, true, 00, "ENOKI                            Bien sur! N'importe quand!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 2:
							{
								line lc[32] = {
									{true, true, 00, "AARON                            Bienvenu! Olivier and Eleanor,   I presume?"},
									{true, true, 00, "ELEANOR                          Oui oui!"},
									{true, true, 00, "OLIVIER                          So, I take it that you're 'king' of this island?"},
									{true, true, 00, "AARON                            Is that what Scout told you?     I suppose you could say that."},
									{true, true, 00, "AARON                            I never graduated high school,   so I'm not cut out for anything"},
									{true, true, 00, "AARON                            but work like this, but I didn't want to spend my life in a"},
									{true, true, 00, "AARON                            factory. So, my wife Enoki and I had the idea to spend our savings"},
									{true, true, 00, "AARON                            on some land and live off the    grid. The 'royalty' thing was"},
									{true, true, 00, "AARON                            her idea, and she was very cute  about it, so I had to say yes."},
									{true, true, 00, "AARON                            She's probably offered           aristocratic roles to y'all."},
									{true, true, 00, "OLIVIER                          Oh - Aaron, was it? Thank you forclearing out the area for the"},
									{true, true, 00, "OLIVIER                          greenhouse. I'll be able to grow all sorts of things to share."},
									{true, true, 00, "ELEANOR                          And I adore this cabin! In a goodway, it reminds me of home."},
									{true, true, 00, "ELEANOR                          Vee and I were so excited to hearabout this island."},
									{true, true, 00, "AARON                            Well, we're all very happy to    have you as well!"},
									{true, true, 00, "AARON                            If my little sister gives either of you a hard time,"},
									{true, true, 00, "AARON                            She doesn't mean anything by it, I promise."},
									{true, true, 00, "AARON                            Hop on by to trailer tonight,    we'll have some dinner ready."},
									{true, true, 00, "OLIVIER                          Encore une fois, je vous remerciesincerement."},
									{true, true, 00, "AARON                            We're family, now - please, 'tu' is plenty."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 3:
							{
								line lc[32] = {
									{true, true, 00, "SCOUT                            Hey, y'all! I'm Scout, from      online?"},
									{true, true, 00, "OLIVIER                          Ah! Enchante de faire votre      connaissance."},
									{true, true, 00, "ELEANOR                          Oh... But from your picture, I   thought that you..."},
									{true, true, 00, "SCOUT                            You thought that I what?"},
									{true, true, 00, "ELEANOR                          I thought you were a skeleton."},
									{true, true, 00, "SCOUT                            Oh- Well, that's just 'cuz I use the photo of a character I like."},
									{true, true, 00, "SCOUT                            There's this skeleton from a     comic named Seemore."},
									{true, true, 00, "SCOUT                            He's got magic powers and a- wellmaybe I should just let you"},
									{true, true, 00, "SCOUT                            read the comic, it's a ton of    fun."},
									{true, true, 00, "ELEANOR                          What's a comic?"},
									{true, true, 00, "SCOUT                            I... huh, I've never had to      answer that question before."},
									{true, true, 00, "SCOUT                            They're like books, but they've  got pictures, but-"},
									{true, true, 00, "ELEANOR                          Those sound so cool!"},
									{true, true, 00, "OLIVIER                          Eleanor was raised in a cult, so she doesn't know much about"},
									{true, true, 00, "OLIVIER                          the outside world. That's one of the reasons we wanted to move"},
									{true, true, 00, "OLIVIER                          here, so we could have a little  break from her extended family."},
									{true, true, 00, "SCOUT                            Oh.. Well, crap. Welcome to the  island, I guess."},
									{true, true, 00, "SCOUT                            Queen Enoki's got dibs on my     latest Time Raiders,"},
									{true, true, 00, "SCOUT                            But when she's done, I'll        definitely get you the copy."},
									{true, true, 00, "ELEANOR                          Merci!!"},
									{true, true, 00, "COM: Endscene"}};
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
									{true, true, 00, "OLIVIER                          Eleanor, why'd you turn the stoveon? Aren't we eating with"},
									{true, true, 00, "OLIVIER                          the Tremblays tonight?"},
									{true, true, 00, "ELEANOR                          Oh, yes yes, I just couldn't helpmyself."},
									{true, true, 00, "ELEANOR                          I haven't seen a stove like this since I was so little."},
									{true, true, 00, "ELEANOR                          I wanted to try and make some    toast."},
									{true, true, 00, "OLIVIER                          What do you think of this place?"},
									{true, true, 00, "OLIVIER                          There aren't many people, are yougoing to get lonely?"},
									{true, true, 00, "ELEANOR                          Well, are you going to be lonely?"},
									{true, true, 00, "OLIVIER                          I just wish my grandfather could see us, now."},
									{true, true, 00, "OLIVIER                          I think he'd be so proud of you."},
									{true, true, 00, "ELEANOR                          Maybe he can see us from heaven."},
									{true, true, 00, "ELEANOR                          Maybe mama has changed in heaven and thinks well of you, now."},
									{true, true, 00, "OLIVIER                          I don't suppose either of us can know, but I won't be lonely."},
									{true, true, 00, "OLIVIER                          I haven't really been lonely     since I got to know you."},
									{true, true, 00, "ELEANOR                          Vee, I hope that we don't ever   feel differently."},
									{true, true, 00, "ELEANOR                          I've seen how my parents became. I already feel older."},
									{true, true, 00, "ELEANOR                          I know that once we have our own enfants..."},
									{true, true, 00, "OLIVIER                          How is your sister doing?"},
									{true, true, 00, "ELEANOR                          She's always exhausted. She jokesabout gray hair, but I think"},
									{true, true, 00, "ELEANOR                          she really does have gray hairs. But she's different."},
									{true, true, 00, "ELEANOR                          The things she was so upset aboutare meaningless, now."},
									{true, true, 00, "OLIVIER                          Maybe it'll be the same with us. Let's just be patient."},
									{true, true, 00, "ELEANOR                          It'll be strange to have married friends our age. Do you think"},
									{true, true, 00, "ELEANOR                          Diana will be jealous?"},
									{true, true, 00, "OLIVIER                          I think she'll have a great time here. S'il te plait detends-toi!"},
									{true, true, 00, "ELEANOR                          Je suppose que tu as raison, Vee."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 6:
							{
								line lc[32] = {
									{true, true, 00, "DIANA                            Aw, super! I love it, it's so    cozy in here."},
									{true, true, 00, "DIANA                            I hope y'all don't mind me spend-ing ungodly amounts of time here."},
									{true, true, 00, "ELEANOR                          Of course not! As long as you    don't mind helping sometimes."},
									{true, true, 00, "OLIVIER                          Remember, living like this means that we're going to work hard."},
									{true, true, 00, "OLIVIER                          I'll probably be spending most ofmy time chopping wood, or"},
									{true, true, 00, "OLIVIER                          working out in the garden pullingweeds and watering."},
									{true, true, 00, "ELEANOR                          You said that you were interestedin working for the boat captain?"},
									{true, true, 00, "DIANA                            Oh, yes. I'll be going down to   the docks today, in fact."},
									{true, true, 00, "DIANA                            Maybe I'll be a proper boat      captain before too long!"},
									{true, true, 00, "ELEANOR                          I know you'll do great, Diana!"},
									{true, true, 00, "OLIVIER                          This isn't what you thought you'dbe doing at 22, huh?"},
									{true, true, 00, "DIANA                            Well, I guess I didn't know what I thought I'd be doing."},
									{true, true, 00, "DIANA                            Y'all didn't think you'd be      moving here, huh?"},
									{true, true, 00, "OLIVIER                          I supposed I'd probably still be working with plants, that's it."},
									{true, true, 00, "ELEANOR                          I'm still alive and so is Vee,   and that's all I could want."},
									{true, true, 00, "DIANA                            Yeah.. Please stay that way, why don't you two?"},
									{true, true, 00, "COM: Endscene"}};
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
									{true, true, 00, "MAPLE                            Salut, guys."},
									{true, true, 00, "ELEANOR                          Salut, Maple! Do you want some   stew? I baked some."},
									{true, true, 00, "MAPLE                            Oh, that sounds great! I'd love  some, your stew is amazing."},
									{true, true, 00, "OLIVIER                          Diana brought a new board game infrom inland, we were interested"},
									{true, true, 00, "OLIVIER                          in playing it tonight. Would you like to invite the others?"},
									{true, true, 00, "MAPLE                            But not me? Excuse you, haha."},
									{true, true, 00, "MAPLE                            Hey, um.. I'm sorry about last   week's board game."},
									{true, true, 00, "ELEANOR                          It's very fine, Maple. It's very easy to get angry in games."},
									{true, true, 00, "MAPLE                            Your cabin doesn't seem to smell like smoke anymore, though."},
									{true, true, 00, "ELEANOR                          Have you tried the new islander'sgumbo yet?"},
									{true, true, 00, "MAPLE                            Are you asking me if I feel      threatened by it? No, not yet."},
									{true, true, 00, "MAPLE                            There's nothing that adding more Tabasco can't fix."},
									{true, true, 00, "MAPLE                            Look, I know I don't see you guysall the time, but-"},
									{true, true, 00, "MAPLE                            Thanks for your ingredients.     Y'all are a godsend."},
									{true, true, 00, "OLIVIER                          Thank you for your work, too. I  will admit, it didn't make any"},
									{true, true, 00, "OLIVIER                          sense that this island would workon its own."},
									{true, true, 00, "OLIVIER                          It's almost like you have a good luck charm."},
									{true, true, 00, "MAPLE                            Yeah... Anything that Enoki wantsis something she gets."},
									{true, true, 00, "MAPLE                            It's only a matter of time beforeshe doesn't get something that"},
									{true, true, 00, "MAPLE                            she wants and she throws a fit,  though."},
									{true, true, 00, "OLIVIER                          I see. Well, if there's anything we can do for you, let us know."},
									{true, true, 00, "MAPLE                            Same for you both."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 1:
							{
								line lc[32] = {
									{true, true, 00, "ENOKI                            Salut!! How are you two today?"},
									{true, true, 00, "ELEANOR                          We're doing well! Would you like some stew?"},
									{true, true, 00, "ENOKI                            Don't mind if I 'dew', hehe."},
									{true, true, 00, "OLIVIER                          You coming to the game night     tonight?"},
									{true, true, 00, "ENOKI                            I wouldn't miss it for anything!"},
									{true, true, 00, "ELEANOR                          Have you met the new islander    yet?"},
									{true, true, 00, "ENOKI                            Don't tell Maple...."},
									{true, true, 00, "ENOKI                            -but I think his gumbo is better."},
									{true, true, 00, "ENOKI                            You can NOT tell Maple I said    that though."},
									{true, true, 00, "ELEANOR                          My lips are sealed."},
									{true, true, 00, "ENOKI                            Hey, you two have a sewing       machine in here?"},
									{true, true, 00, "ELEANOR                          Oui."},
									{true, true, 00, "ENOKI                            You said you make your own       clothes, oui? You, uh.."},
									{true, true, 00, "ENOKI                            Wouldn't mind giving me a lesson or two?"},
									{true, true, 00, "ELEANOR                          Pas du tout! I would love to     teach you anytime!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 2:
							{
								line lc[32] = {
									{true, true, 00, "AARON                            Salut! I heard that you wanted tohave a game night tonight?"},
									{true, true, 00, "ELEANOR                          Oui oui! Although, we would like to have it outside under a tree."},
									{true, true, 00, "ELEANOR                          I made a quilt that should be bigenough for all of us."},
									{true, true, 00, "AARON                            Outside just in case Maple gets..upset this time, oui?"},
									{true, true, 00, "OLIVIER                          Oui, haha."},
									{true, true, 00, "ELEANOR                          We made some stew if you want    some."},
									{true, true, 00, "AARON                            I already had some of Maple's    leftover gumbo, but merci!"},
									{true, true, 00, "AARON                            Speaking of, Guy has been pretty reserved, but he seems nice."},
									{true, true, 00, "AARON                            I'm just excited to have more    people on the island."},
									{true, true, 00, "OLIVIER                          We're becoming a proper little   village, aren't we?"},
									{true, true, 00, "AARON                            Yeah, yeah I guess so."},
									{true, true, 00, "OLIVIER                          Are you alright, Aaron? You look long in the face."},
									{true, true, 00, "AARON                            Yes, I'm just thinking. Maple andI aren't doing so well."},
									{true, true, 00, "OLIVIER                          What do you mean?"},
									{true, true, 00, "AARON                            Well, she doesn't want to move   out, but she needs to."},
									{true, true, 00, "OLIVIER                          Can't you just ask her to? Aren'tyou king or something?"},
									{true, true, 00, "AARON                            I can. Maybe I should. She's justlike this."},
									{true, true, 00, "AARON                            She goes back and forth between  being super independent, and"},
									{true, true, 00, "AARON                            then the next day, she's clingy."},
									{true, true, 00, "OLIVIER                          This sounds like something you   should take up with her, not us."},
									{true, true, 00, "AARON                            You're right, you're right."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 3:
							{
								line lc[32] = {
									{true, true, 00, "SCOUT                            Hey, y'all! Scout here."},
									{true, true, 00, "ELEANOR                          Salut! Would you like some stew?"},
									{true, true, 00, "SCOUT                            Merci, but I ate just.. uh.. holdon, the last time I ate.."},
									{true, true, 00, "SCOUT                            Holy cow, I haven't eaten yet.   I'd love some stew!"},
									{true, true, 00, "ELEANOR                          Hehe, of course."},
									{true, true, 00, "SCOUT                            You guys catch my Scout TV reportthis morning?"},
									{true, true, 00, "ELEANOR                          Oh, we don't have a television."},
									{true, true, 00, "SCOUT                            Right, right.. Forgot about that,I'm sorry."},
									{true, true, 00, "SCOUT                            Anyway, apparently my broadcast  was hacked."},
									{true, true, 00, "OLIVIER                          Hacked? By whom?"},
									{true, true, 00, "SCOUT                            No clue. The Tremblays aren't    worried about it, though."},
									{true, true, 00, "ELEANOR                          Will you be coming to our game   night tonight?"},
									{true, true, 00, "SCOUT                            I'll do my best, there's stuff I gotta do for work."},
									{true, true, 00, "SCOUT                            We'll see how that goes."},
									{true, true, 00, "OLIVIER                          Well, we'll save you a seat."},
									{true, true, 00, "SCOUT                            Merci!"},
									{true, true, 00, "ELEANOR                          De rien!"},
									{true, true, 00, "COM: Endscene"}};
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
									{true, true, 00, "OLIVIER                          So, your birthday is coming up ina week..."},
									{true, true, 00, "ELEANOR                          Oui?"},
									{true, true, 00, "OLIVIER                          I would surprise you, but I don'twant to disappoint you with-"},
									{true, true, 00, "ELEANOR                          ..."},
									{true, true, 00, "OLIVIER                          ...Do you want me to just        surprise you?"},
									{true, true, 00, "OLIVIER                          ..."},
									{true, true, 00, "OLIVIER                          Are you still thinking about thatceremony?"},
									{true, true, 00, "ELEANOR                          I'm never going to forget that   night, not ever."},
									{true, true, 00, "ELEANOR                          I can't decide if it's a good or a bad feeling."},
									{true, true, 00, "ELEANOR                          You gave me enough of a birthday gift for the rest of my life."},
									{true, true, 00, "OLIVIER                          But you wouldn't complain if I   got you a new sewing machine."},
									{true, true, 00, "ELEANOR                          ..."},
									{true, true, 00, "OLIVIER                          Not saying that it's what I'm    going to get for sure, but.."},
									{true, true, 00, "ELEANOR                          Don't you have some vegetables toprune? I need to get started"},
									{true, true, 00, "ELEANOR                          on canning for the winter."},
									{true, true, 00, "OLIVIER                          Right, right, just uh-...        Yeah, nevermind."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 6:
							{
								line lc[32] = {
									{true, true, 00, "DIANA                            Alright, guys, we have to talk."},
									{true, true, 00, "OLIVIER                          What's up?"},
									{true, true, 00, "DIANA                            Some dude hacked Scout's TV      program this morning."},
									{true, true, 00, "DIANA                            He was a Mons d'Plonj, I think?  He was threatening the island."},
									{true, true, 00, "ELEANOR                          O-Oh.. Oh no.. He wasn't with thewitches, was he?"},
									{true, true, 00, "ELEANOR                          Vee, have they found us?"},
									{true, true, 00, "DIANA                            No, he looked like some twerp.   Apparently Maple knows him?"},
									{true, true, 00, "DIANA                            The Tremblays aren't worried."},
									{true, true, 00, "ELEANOR                          Oh.. Thank goodness.."},
									{true, true, 00, "DIANA                            Have you met that new guy up     north, though? Cesar?"},
									{true, true, 00, "DIANA                            He seems shady, but Enoki trusts him. He has a shop or something."},
									{true, true, 00, "DIANA                            That new Guy.. er.. guy, he seemsfine. He makes good food."},
									{true, true, 00, "OLIVIER                          Hey, El, calm down, you're going to hyperventilate."},
									{true, true, 00, "ELEANOR                          I'm sorry.. I'm sorry.."},
									{true, true, 00, "DIANA                            Hey, Eleanor, it's going to be   okay. Wanna come to my place?"},
									{true, true, 00, "DIANA                            We can relax and eat snacks I    imported from inland."},
									{true, true, 00, "DIANA                            Yes, that sounds like fun.       Merci."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 7:
							{
								line lc[32] = {
									{true, true, 00, "ELEANOR                          Bonjour! You must be Guy."},
									{true, true, 00, "GUY                              Oui. The name's Guy. Guy Pizza."},
									{true, true, 00, "ELEANOR                          Guy... Pizza?"},
									{true, true, 00, "GUY                              It was funnier when I was a pizzaguy."},
									{true, true, 00, "OLIVIER                          Well, welcome to the island!"},
									{true, true, 00, "GUY                              Nice to meet y'all. I'm gonna go back and finish setting up."},
									{true, true, 00, "GUY                              I've always wanted a full-size   kitchen, and I'm gonna make good"},
									{true, true, 00, "GUY                              use of it, you'll see."},
									{true, true, 00, "ELEANOR                          We're having a game night tonightand we were wondering,"},
									{true, true, 00, "ELEANOR                          Would you like to join us?"},
									{true, true, 00, "GUY                              I would, but I'm too excited     about this kitchen."},
									{true, true, 00, "ELEANOR                          I.. see. I hope you have fun withyour kitchen."},
									{true, true, 00, "GUY                              Oh, I will. I will."},
									{true, true, 00, "COM: Endscene"}};
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
									{true, true, 00, "ELEANOR                          What's going on outside?"},
									{true, true, 00, "AARON                            I don't know, but follow me,     we're going to wait this out in "},
									{true, true, 00, "AARON                            Scout's bunker until we can get  things sorted."},
									{true, true, 00, "AARON                            Where's Diana?"},
									{true, true, 00, "OLIVIER                          She's out boating with Guy today and won't be back for hours."},
									{true, true, 00, "AARON                            Thank goodness. Follow me, I'll  get us out of here."},
									{true, true, 00, "COM: Endscene"}};
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
								{true, true, 00, "This is Eleanor's library."},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
						else if (me != 5)
						{
							line lc[32] = {
								{true, true, 00, "The door is locked."},
								{true, true, 00, "You decide that it's probably notyour business."},
								{true, true, 00, "COM: Endscene"}};
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
									{true, true, 00, "MAPLE                            Hey! So, you're Diana?"},
									{true, true, 00, "DIANA                            Hiya! Finally! Another redhead!"},
									{true, true, 00, "MAPLE                            Oh, I'm not a red head, I'm more of a honey-blonde."},
									{true, true, 00, "MAPLE                            I'm a wood elf, so it looks a bitorange sometimes."},
									{true, true, 00, "DIANA                            Oh, you are? Then.."},
									{true, true, 00, "MAPLE                            Why are my ears round?"},
									{true, true, 00, "DIANA                            I don't want to ask if you don't feel comfortable."},
									{true, true, 00, "MAPLE                            Oh, it's fine. They were clipped when I was a baby."},
									{true, true, 00, "MAPLE                            I'm Maple, by the way.           Maple Tremblay."},
									{true, true, 00, "DIANA                            Heureux de te rencontrer!"},
									{true, true, 00, "DIANA                            These cabins are so nice! You're,uh, older brother make em?"},
									{true, true, 00, "MAPLE                            Mostly. I go out and find gems inlocal caves sometimes."},
									{true, true, 00, "MAPLE                            We make enough to live pretty    well out here."},
									{true, true, 00, "DIANA                            Do you live in that trailer I sawmoving in?"},
									{true, true, 00, "MAPLE                            Yep. I'm on the couch."},
									{true, true, 00, "DIANA                            Do you not want a cabin? One of  them looks empty."},
									{true, true, 00, "MAPLE                            You see, Aaron and Enoki want to make a castle or something."},
									{true, true, 00, "MAPLE                            I'm gonna take over their trailerwhen that happens."},
									{true, true, 00, "DIANA                            So... is this place, like,       seriously a country?"},
									{true, true, 00, "MAPLE                            I mean.. if we act like it is,   then it is, isn't it?"},
									{true, true, 00, "DIANA                            Is it really that easy?"},
									{true, true, 00, "MAPLE                            Until we fight a war? We'll see. Nice to meet you."},
									{true, true, 00, "DIANA                            Yeah, nice to meet you too!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 1:
							{
								line lc[32] = {
									{true, true, 00, "ENOKI                            Hey!! Are you Diana?             I'm Enoki Tremblay!"},
									{true, true, 00, "DIANA                            Enchante de faire votre          connaissance!"},
									{true, true, 00, "ENOKI                            Is everything comfortable for youso far?"},
									{true, true, 00, "DIANA                            Dude, I'm still not sure if I'm  dreaming or not."},
									{true, true, 00, "DIANA                            This feels way too good to be    real, it's crazy."},
									{true, true, 00, "ENOKI                            I'm a pretty lucky gal, so when  I want something to happen, well,"},
									{true, true, 00, "ENOKI                            Things tend to turn out, and I   wanted this to turn out."},
									{true, true, 00, "ENOKI                            I heard you've got somethin' withCapt. Nicholas?"},
									{true, true, 00, "DIANA                            Yeah! He's looking for someone totake over this area."},
									{true, true, 00, "DIANA                            I'll eventually be ferrying      across Superieur."},
									{true, true, 00, "ENOKI                            Aw, fun!! You gotta take us in a ride sometime."},
									{true, true, 00, "ENOKI                            If you ever need us for anything,you let us know, alright?"},
									{true, true, 00, "DIANA                            D'accord!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 2:
							{
								line lc[32] = {
									{true, true, 00, "DIANA                            Bienvenu! You're Aaron Tremblay, oui?"},
									{true, true, 00, "AARON                            Bienvenu! How's the cabin workingfor you?"},
									{true, true, 00, "DIANA                            Oh, it's perfect!! It feels too  good to be true, honestly."},
									{true, true, 00, "DIANA                            I'm starting up my first boat    short introduction today."},
									{true, true, 00, "DIANA                            Do you know Capt. Nicholas well?"},
									{true, true, 00, "AARON                            I'll be honest, I spend most of  my time chopping wood."},
									{true, true, 00, "AARON                            But he seems like a very nice    person from what I know."},
									{true, true, 00, "AARON                            I won't stay long, I was just    stopping by to check in."},
									{true, true, 00, "AARON                            Just let me know if you need     anything, alright?"},
									{true, true, 00, "DIANA                            Absolutely! Thanks!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 3:
							{
								line lc[32] = {
									{true, true, 00, "SCOUT                            Hey! It's me, Scout. Just wanted to introduce myself."},
									{true, true, 00, "DIANA                            Ah! Nice to meet you! I'll admit I wasn't sure this was real."},
									{true, true, 00, "DIANA                            I'm glad I wasn't.. you know..   killed or something."},
									{true, true, 00, "SCOUT                            I'll admit, I'm actually a bit   new here, too-"},
									{true, true, 00, "SCOUT                            I moved over here from a nearby  island when I met the"},
									{true, true, 00, "SCOUT                            Trembalys and decided I'd jump   over here."},
									{true, true, 00, "SCOUT                            It wasn't exactly easy diggint a new bunker, but it was"},
									{true, true, 00, "SCOUT                            worth it. It's nicer over here."},
									{true, true, 00, "DIANA                            Well, you seem to be doing fine. You a scientist?"},
									{true, true, 00, "SCOUT                            Yeah, it's a little funny. This  company's got me here"},
									{true, true, 00, "SCOUT                            for some reason to do experimentsbut on an island? No clue why."},
									{true, true, 00, "DIANA                            You find out anything cool?"},
									{true, true, 00, "SCOUT                            I made this device that makes    bunkers real fast."},
									{true, true, 00, "SCOUT                            No idea what I'll use it for, butit's got potential."},
									{true, true, 00, "DIANA                            Hey, you feel like making me a   bunker sometime?"},
									{true, true, 00, "SCOUT                            Aw sure, I'd love to!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							// Fall-through to the next bit
							case 4:
							{
								line lc[32] = {
									{true, true, 00, "DIANA                            Hey, Vee! Fancy seeing you here  in my /new cabin/, huh?"},
									{true, true, 00, "OLIVIER                          It only took you about a day to  make it look just like your"},
									{true, true, 00, "OLIVIER                          place back home, didn't it?"},
									{true, true, 00, "DIANA                            If all things go well, this'll beout new 'back home', right?"},
									{true, true, 00, "OLIVIER                          It all depends if we can trust   these people."},
									{true, true, 00, "OLIVIER                          You've got something to defend   yourself on you, right?"},
									{true, true, 00, "DIANA                            Right, I have my flare gun on me."},
									{true, true, 00, "DIANA                            I really home I never have to useit, though."},
									{true, true, 00, "OLIVIER                          Me too. But they seem nice       enough."},
									{true, true, 00, "OLIVIER                          At least they're not going to tryand sacrifice us, hehe."},
									{true, true, 00, "DIANA                            Hehe, no kidding. If any of El's family shows up,"},
									{true, true, 00, "DIANA                            You're giving me a call, right?"},
									{true, true, 00, "OLIVIER                          Of course, of course."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 5:
							{
								line lc[32] = {
									{true, true, 00, "ELEANOR                          It looks just like your room at  home!"},
									{true, true, 00, "DIANA                            Yep, did you expect anything lessfrom me? Hehe."},
									{true, true, 00, "ELEANOR                          Well, I love it anyway. It's verycozy."},
									{true, true, 00, "ELEANOR                          If you need anything, please let me know,"},
									{true, true, 00, "ELEANOR                          I have set up my room, and we nowhave a crystal ball room!"},
									{true, true, 00, "ELEANOR                          I'm still working on my summoningskills, they're rusty."},
									{true, true, 00, "DIANA                            And you're absolutely sure that  using magic won't cause"},
									{true, true, 00, "DIANA                            Any.. er.. witches to find out   where we are?"},
									{true, true, 00, "ELEANOR                          I'm positive. I even think that  if this is good enough,"},
									{true, true, 00, "ELEANOR                          We can invite my family to come  by, I'd love to show them"},
									{true, true, 00, "ELEANOR                          this place. It seems peaceful."},
									{true, true, 00, "DIANA                            We'll see. We haven't exactly hada peaceful life until now."},
									{true, true, 00, "DIANA                            Hey, you seen those Tremblays yetor talked to them?"},
									{true, true, 00, "DIANA                            It feels like we've got one of   them for each of us."},
									{true, true, 00, "DIANA                            They have a redhead and a couple with the 'farmer' type"},
									{true, true, 00, "DIANA                            and that Enoki seems cute, but   you're the cuter one."},
									{true, true, 00, "ELEANOR                          Aw, Merci!"},
									{true, true, 00, "DIANA                            I can't help but be a little     suspicious, but I think"},
									{true, true, 00, "DIANA                            We're in for a good time."},
									{true, true, 00, "ELEANOR                          Me too."},
									{true, true, 00, "COM: Endscene"}};
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
									{true, true, 00, "MAPLE                            Diana! Hey!"},
									{true, true, 00, "DIANA                            Hey, Maple!                      How's it shakin', bacon?"},
									{true, true, 00, "MAPLE                            Not bad, just a little bored."},
									{true, true, 00, "DIANA                            Dude, you see that broadcast thismorning?"},
									{true, true, 00, "MAPLE                            With Rufus hijacking it? He's a  twerp, we're fine."},
									{true, true, 00, "MAPLE                            He probably thinks he's a super  villain or something."},
									{true, true, 00, "DIANA                            Boys like that just crack me up, seriously haha."},
									{true, true, 00, "MAPLE                            Talk about it. But let me know ifyou spot him."},
									{true, true, 00, "MAPLE                            Fried alligator's pretty tasty   this time of year."},
									{true, true, 00, "DIANA                            Will do."},
									{true, true, 00, "DIANA                            So what've you been up to lately?"},
									{true, true, 00, "MAPLE                            You seen Scout? Poor guy, he's   definitely got a crush on me."},
									{true, true, 00, "MAPLE                            It's kind of sweet right now, butI'm eventually going to have to"},
									{true, true, 00, "MAPLE                            let him know he's really not my  type."},
									{true, true, 00, "DIANA                            Girl, I don't envy you, haha.    So, what is your type?"},
									{true, true, 00, "MAPLE                            I want someone who makes me      excited and.. is loose, y'know?"},
									{true, true, 00, "MAPLE                            All these boys act like I'm a    goddess or something and it's"},
									{true, true, 00, "MAPLE                            kind of patronizing. I could makeem into a barbeque if I wanted."},
									{true, true, 00, "DIANA                            Maybe that's why they treat you  like that, they're scared, hehe."},
									{true, true, 00, "MAPLE                            I need to find another fire elf  somewhere, probably."},
									{true, true, 00, "DIANA                            There aren't very many this far  southeast."},
									{true, true, 00, "MAPLE                            Yeah, I'll keep looking then, I  guess, but it's a small island."},
									{true, true, 00, "DIANA                            That it is, haha. You care care  of yourself, Maple."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 1:
							{
								line lc[32] = {
									{true, true, 00, "ENOKI                            Hey, girl!"},
									{true, true, 00, "DIANA                            Enoki, ma cherie! You want some  snacks?"},
									{true, true, 00, "ENOKI                            I always want snacks."},
									{true, true, 00, "DIANA                            Haha, of course. So what's your  day been like?"},
									{true, true, 00, "ENOKI                            Good, good, but I'm a little     worried."},
									{true, true, 00, "DIANA                            Aw, how come?"},
									{true, true, 00, "ENOKI                            Well, it's about Aaron and Maple.They've been fighting."},
									{true, true, 00, "DIANA                            That's not good! Do tell."},
									{true, true, 00, "ENOKI                            Well, Aaron's always bottled up  how he feels about things,"},
									{true, true, 00, "ENOKI                            While Maple tells you to your    face and hurts feelings."},
									{true, true, 00, "DIANA                            That's not a good combination."},
									{true, true, 00, "ENOKI                            It always blows over, but it     makes me sad in the meantime."},
									{true, true, 00, "DIANA                            I don't have siblings, but that'sjust how it goes, right?"},
									{true, true, 00, "ENOKI                            You a lonely only too? Yeah, I   always wanted a little sister."},
									{true, true, 00, "DIANA                            Little bro for me. Less drama."},
									{true, true, 00, "ENOKI                            True, true."},
									{true, true, 00, "DIANA                            Keep me up to date, k?"},
									{true, true, 00, "ENOKI                            K."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 2:
							{
								line lc[32] = {
									{true, true, 00, "DIANA                            Hey, Aaron!                      What can I do you for?"},
									{true, true, 00, "AARON                            Nothing much, you know about the game night tonight?"},
									{true, true, 00, "DIANA                            Yeah! I'm definitely coming. Hey,you saw that broadcast?"},
									{true, true, 00, "AARON                            I talked to Maple, and she seems to have known the Plonj guy."},
									{true, true, 00, "AARON                            She's not worried about it."},
									{true, true, 00, "DIANA                            Oh, thank goodness.              See ya tonight?"},
									{true, true, 00, "AARON                            Sure thing!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 3:
							{
								line lc[32] = {
									{true, true, 00, "SCOUT                            Hey! It's me, Scout."},
									{true, true, 00, "DIANA                            Hey Scout! What're you on about?"},
									{true, true, 00, "SCOUT                            It looks like this month's Scout TV is a wrap."},
									{true, true, 00, "SCOUT                            Now I've just gotta worry about  the Scout Expo next month."},
									{true, true, 00, "DIANA                            You keep bringing that up, what  is that exactly?"},
									{true, true, 00, "SCOUT                            Oh, it's this thing where I take all my inventions and I"},
									{true, true, 00, "SCOUT                            show em off. I usually take a    video and put it on the"},
									{true, true, 00, "SCOUT                            world wide web, but now I've     actually got friends to show"},
									{true, true, 00, "SCOUT                            the stuff off to!"},
									{true, true, 00, "DIANA                            Aw, that sounds like fun! What'veyou got, for example?"},
									{true, true, 00, "SCOUT                            No spoilers! Gotta wait for the  expo, you know."},
									{true, true, 00, "DIANA                            Of course, of course.            That was a test."},
									{true, true, 00, "SCOUT                            ...ok, so I made this device-"},
									{true, true, 00, "DIANA                            No, you can't tell me, remember?"},
									{true, true, 00, "SCOUT                            But I- I... hmm... okay, fine.   This is hard."},
									{true, true, 00, "DIANA                            I figured it would be, hehe."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							// Fall-through to the next bit
							case 4:
							{
								line lc[32] = {
									{true, true, 00, "DIANA                            Hey, Vee! How'd you be?"},
									{true, true, 00, "OLIVIER                          Good, good."},
									{true, true, 00, "DIANA                            You're not here to ask if I can  host the game night here, right?"},
									{true, true, 00, "OLIVIER                          No, no! Goodness.. We're doing itoutside."},
									{true, true, 00, "OLIVIER                          If all goes well, we won't burn  down the island, haha."},
									{true, true, 00, "OLIVIER                          Is everyone doing well back on   shore?"},
									{true, true, 00, "DIANA                            Wonderful! My parents want to    come up and visit sometime."},
									{true, true, 00, "DIANA                            I need to clean up though.. maybeI pretend your place is mine."},
									{true, true, 00, "OLIVIER                          In your dreams, haha."},
									{true, true, 00, "OLIVIER                          I need to invite Eleanor and my  family up here sometime."},
									{true, true, 00, "DIANA                            Oh, they'd love this place."},
									{true, true, 00, "DIANA                            Hopefully nothing goes horribly  wrong."},
									{true, true, 00, "OLIVIER                          Of course, of course haha."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 5:
							{
								line lc[32] = {
									{true, true, 00, "ELEANOR                          Bonjour!"},
									{true, true, 00, "DIANA                            Salut, ma charie! Quoi de neuf?"},
									{true, true, 00, "ELEANOR                          Oh, is that sourdough I smell?"},
									{true, true, 00, "DIANA                            It shouldn't be, haha. I really  need to pick up my room..."},
									{true, true, 00, "DIANA                            How've you been lately? Any news?"},
									{true, true, 00, "ELEANOR                          Oh, nothing much. I've been      sewing a new quilt."},
									{true, true, 00, "DIANA                            Fancy. What are you making it    out of?"},
									{true, true, 00, "ELEANOR                          I took all of my clothes from my home village to the island."},
									{true, true, 00, "ELEANOR                          They're ready to retire, but I   can't bear to part from them."},
									{true, true, 00, "ELEANOR                          They're so much of who I am, so  I'm making a quilt."},
									{true, true, 00, "DIANA                            Aw, that's wonderful."},
									{true, true, 00, "DIANA                            You been making any art lately?"},
									{true, true, 00, "ELEANOR                          A bit, a bit! There are so many  pretty landscapes here."},
									{true, true, 00, "DIANA                            Oui. I could play guitar by the  ocean for the rest of my life."},
									{true, true, 00, "DIANA                            Well, I say ocean, I mean lake.  Same difference."},
									{true, true, 00, "DIANA                            Eleanor, I think I'm meant for   the sea."},
									{true, true, 00, "ELEANOR                          That sounds like a fun life."},
									{true, true, 00, "DIANA                            Arrrrrrrg, it's pirate time."},
									{true, true, 00, "DIANA                            But it'll be okay, I'll visit allthe time when I'm sailing!"},
									{true, true, 00, "ELEANOR                          S'il vous plait!"},
									{true, true, 00, "COM: Endscene"}};
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
									{true, true, 00, "DIANA                            Hey! Guy, was it? You that guy?"},
									{true, true, 00, "GUY                              Yeah, that's me. This your place?"},
									{true, true, 00, "DIANA                            You bet. It's not much. you like your place?"},
									{true, true, 00, "GUY                              Ever since I was a kid, it's beena dream to have my very own"},
									{true, true, 00, "GUY                              Industrial-sized kitchen that I  can roll out of bed to."},
									{true, true, 00, "DIANA                            That's a pretty hyper-specific   dream, but I get it."},
									{true, true, 00, "GUY                              You don't even have a kitchen, doyou?"},
									{true, true, 00, "DIANA                            I mean, I've got a stovetop and  a mini-fridge, haha."},
									{true, true, 00, "DIANA                            I do all the importing here, so  I eat pre-packaged a lot."},
									{true, true, 00, "GUY                              That's not super healthy y'know."},
									{true, true, 00, "DIANA                            Yeah, I'll worry about that laterwhen it matters."},
									{true, true, 00, "DIANA                            Everyone gets old and fat        someday, y'know."},
									{true, true, 00, "GUY                              Not me. I'll be old and thin."},
									{true, true, 00, "DIANA                            We'll catch up in fifty and see  how that's going, huh?"},
									{true, true, 00, "GUY                              You bet."},
									{true, true, 00, "DIANA                            We're having game night tonight, you coming?"},
									{true, true, 00, "GUY                              Nah, I'll be messing with my     kitchen tonight."},
									{true, true, 00, "DIANA                            Ah.. I see, I see. Fair enough."},
									{true, true, 00, "DIANA                            You do you, dude."},
									{true, true, 00, "GUY                              Will do."},
									{true, true, 00, "COM: Endscene"}};
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
								{true, true, 00, "OLIVIER                          O-Oh! Excuse me, ma'am. Where didyou come from?"},
								{true, true, 00, "GRAND-MERE CORINNE               This greenhouse is still quite   nice, was it moved?"},
								{true, true, 00, "OLIVIER                          Oh.. Well, I was told that it wastransported from inland."},
								{true, true, 00, "GRAND-MERE CORINNE               Well, you see, I once owned this greenhouse, young man."},
								{true, true, 00, "GRAND-MERE CORINNE               I don't see any point in having  ambiguity; I am a ghost."},
								{true, true, 00, "OLIVIER                          A ghost???"},
								{true, true, 00, "GRAND-MERE CORINNE               It seems I am doomed to haunt    this greenhouse forever."},
								{true, true, 00, "OLIVIER                          My apologize, that seems... it   seems like a terrible fate."},
								{true, true, 00, "GRAND-MERE CORINNE               Would you consider it horrible tospend an eternity here?"},
								{true, true, 00, "OLIVIER                          Now that I think about it.. I    suppose not."},
								{true, true, 00, "OLIVIER                          It's where I spend most of my    life anyway."},
								{true, true, 00, "GRAND-MERE CORINNE               I see you enjoy taking care of   these plants, son."},
								{true, true, 00, "GRAND-MERE CORINNE               Before I leave, I will remind youof one wisdom."},
								{true, true, 00, "GRAND-MERE CORINNE               Even if your care of these plantsseems meaningless,"},
								{true, true, 00, "GRAND-MERE CORINNE               Wonderful things come to the     diligent."},
								{true, true, 00, "GRAND-MERE CORINNE               It was very nice to meet you.    Until next time!"},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (globals->current_save->checkpoint < 12)
						{
							// corinne.set_blending_enabled(false);
							line lc[32] = {
								{true, true, 00, "OLIVIER                          Good afternoon, Grand-mere!"},
								{true, true, 00, "GRAND-MERE CORINNE               Good afternoon, Olivier. It's    nice to have visitors."},
								{true, true, 00, "OLIVIER                          How has your day been?"},
								{true, true, 00, "GRAND-MERE CORINNE               Oh, just as usual.. Eternal      unrest. A ghost's life."},
								{true, true, 00, "GRAND-MERE CORINNE               Or lack thereof, hehe."},
								{true, true, 00, "OLIVIER                          The afterlife seems rather dull."},
								{true, true, 00, "GRAND-MERE CORINNE               It doesn't have to be. Say.. can you tell me about that man?"},
								{true, true, 00, "OLIVIER                          Man?"},
								{true, true, 00, "GRAND-MERE CORINNE               Yes, the strapping boat captain. With the beard?"},
								{true, true, 00, "OLIVIER                          Oh, the captain? Do you.. like   him?"},
								{true, true, 00, "GRAND-MERE CORINNE               This sounds rather morbid, but   how many years do you suppose"},
								{true, true, 00, "GRAND-MERE CORINNE               he has left?"},
								{true, true, 00, "GRAND-MERE CORINNE               I wouldn't suppose he'd enjoy an afterlife here."},
								{true, true, 00, "OLIVIER                          That.. uh.. question may be      better asked to him."},
								{true, true, 00, "GRAND-MERE CORINNE               Of course, of course."},
								{true, true, 00, "COM: Endscene"}};
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
							{true, true, 00, "CESAR'S BIZAAR                   'WE ONLY HAVE TWO ITEMS,         DEAL WITH IT'"},
							{true, true, 00, "COM: Endscene"}};
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
								{true, true, 00, "MAPLE                            So... Guy, you, uh.. put tomatoesin your Jambalaya?"},
								{true, true, 00, "GUY                              Just as God intended."},
								{true, true, 00, "MAPLE                            Just as G- Just as God intended??"},
								{true, true, 00, "MAPLE                            ...You're kidding me, right?"},
								{true, true, 00, "GUY                              Let me guess, you're one-a those who likes her roux burnt."},
								{true, true, 00, "MAPLE                            Define 'burnt'."},
								{true, true, 00, "GUY                              Like so burnt, all the color's   gone and you can't taste it."},
								{true, true, 00, "MAPLE                            What do you mean 'can't' taste   it? Of course you can!"},
								{true, true, 00, "GUY                              Yeah, cuz you bury it in a pile  of random spices."},
								{true, true, 00, "MAPLE                            My spice choice is NOT random."},
								{true, true, 00, "GUY                              Now if you'll excuse me, I don't need to sweep the kitchen"},
								{true, true, 00, "GUY                              floor to make a good jambalaya."},
								{true, true, 00, "MAPLE                            You Creoles are psychotic."},
								{true, true, 00, "GUY                              Not like you Cajuns are, honey.  I tell you what. Gumbo contest."},
								{true, true, 00, "GUY                              You make some gumbo and we get   everyone else to judge. Deal?"},
								{true, true, 00, "MAPLE                            Deal.                            Easy."},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						case 1:
						{
							line lc[32] = {
								{true, true, 00, "ENOKI                            Ooooooo... I love your kitchen!! It's so big!"},
								{true, true, 00, "GUY                              Merci. I'm pretty keen on rollingout of bed to some cornbread."},
								{true, true, 00, "ENOKI                            I wish I could do that, hehe."},
								{true, true, 00, "GUY                              Say, uh.. That Maple belle, how'sher gumbo like compared to mine?"},
								{true, true, 00, "ENOKI                            Are you two in a competition?    Ooh, now I don't wanna choose."},
								{true, true, 00, "ENOKI                            I don't wanna on your bad side   right as soon as you moved in,"},
								{true, true, 00, "ENOKI                            But you gotta know that Maple andI are like best friends."},
								{true, true, 00, "GUY                              Maybe I can cook up something    that'll make you reconsider."},
								{true, true, 00, "ENOKI                            That'll be pretty tough. I don't like food /that/ much."},
								{true, true, 00, "GUY                              But... Ah, nevermind, have it    your own way, cheri."},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						case 2:
						{
							line lc[32] = {
								{true, true, 00, "AARON                            It smells so nice in here!"},
								{true, true, 00, "GUY                              Oui, as it ought to."},
								{true, true, 00, "AARON                            So, uh.. I heard that you moved  in because you want customers?"},
								{true, true, 00, "GUY                              Right."},
								{true, true, 00, "AARON                            Well, uh.. Obviously we're not a huge group of people here.."},
								{true, true, 00, "AARON                            And I'm obviously doing my best  to make this place a good home.."},
								{true, true, 00, "GUY                              Uh huh?"},
								{true, true, 00, "AARON                            I just, uh, hope you know that wearen't quite big enough to have"},
								{true, true, 00, "AARON                            Our own currency yet, and a few  of don't really keep cash.."},
								{true, true, 00, "GUY                              I charge five dollars per meal,  and I expect customers."},
								{true, true, 00, "AARON                            I'll tell you what. This cabin iswhat, ten thousand? Twenty?"},
								{true, true, 00, "AARON                            I can't do math in my head, I    never graduated high school."},
								{true, true, 00, "AARON                            Enoki can do crazy math in her   head, but she isn't here."},
								{true, true, 00, "AARON                            How about free food for all of usfor the rest of the year,"},
								{true, true, 00, "AARON                            And that'll pay for the food.    C'est bon?"},
								{true, true, 00, "GUY                              ...I'll think about it."},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						case 3:
						{
							line lc[32] = {
								{true, true, 00, "OLIVIER                          O-Oh! Excuse me, ma'am. Where didyou come from?"},
								{true, true, 00, "GRAND-MERE CORINNE               This greenhouse is still quite   nice, was it moved?"},
								{true, true, 00, "OLIVIER                          Oh.. Well, I was told that it wastransported from inland."},
								{true, true, 00, "GRAND-MERE CORINNE               Well, you see, I once owned this greenhouse, young man."},
								{true, true, 00, "GRAND-MERE CORINNE               I don't see any point in having  ambiguity; I am a ghost."},
								{true, true, 00, "OLIVIER                          A ghost???"},
								{true, true, 00, "GRAND-MERE CORINNE               It seems I am doomed to haunt    this greenhouse forever."},
								{true, true, 00, "OLIVIER                          My apologize, that seems... it   seems like a terrible fate."},
								{true, true, 00, "GRAND-MERE CORINNE               Would you consider it horrible tospend an eternity here?"},
								{true, true, 00, "OLIVIER                          Now that I think about it.. I    suppose not."},
								{true, true, 00, "OLIVIER                          It's where I spend most of my    life anyway."},
								{true, true, 00, "GRAND-MERE CORINNE               I see you enjoy taking care of   these plants, son."},
								{true, true, 00, "GRAND-MERE CORINNE               Before I leave, I will remind youof one wisdom."},
								{true, true, 00, "GRAND-MERE CORINNE               Even if your care of these plantsseems meaningless,"},
								{true, true, 00, "GRAND-MERE CORINNE               Wonderful things come to the     diligent."},
								{true, true, 00, "GRAND-MERE CORINNE               It was very nice to meet you.    Until next time!"},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						case 4:
						{
							line lc[32] = {
								{true, true, 00, "OLIVIER                          Bonjour!"},
								{true, true, 00, "GUY                              Oui. J'suppose you're the garden boy?"},
								{true, true, 00, "GUY                              You grow lots of celery, onions, and bell peppers?"},
								{true, true, 00, "OLIVIER                          Well of course!"},
								{true, true, 00, "GUY                              I'll tell you what. You continue to give me fresh supply,"},
								{true, true, 00, "GUY                              And I'll get you free gumbo."},
								{true, true, 00, "OLIVIER                          What about my wife?"},
								{true, true, 00, "GUY                              She the one with the Wendy's hairor the Wendy's outfit?"},
								{true, true, 00, "OLIVIER                          ...she's the one with the brown  hair."},
								{true, true, 00, "GUY                              Got it, Dave."},
								{true, true, 00, "OLIVIER                          ...Olivier. Olivier Landry."},
								{true, true, 00, "OLIVIER                          Isn't your name Guy?"},
								{true, true, 00, "GUY                              Correct."},
								{true, true, 00, "OLIVIER                          Don't you go by 'Guy Pizza'?"},
								{true, true, 00, "GUY                              It's more of a joke, but don't   tell no one, you hear?"},
								{true, true, 00, "OLIVIER                          I hear, I hear."},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						case 5:
						{
							line lc[32] = {
								{true, true, 00, "ELEANOR                          Bonjour! Comment allez-vous?"},
								{true, true, 00, "GUY                              C'est bon, how are you?"},
								{true, true, 00, "ELEANOR                          This place makes me pretty       hungry, it smells great!"},
								{true, true, 00, "GUY                              Oh yeah?"},
								{true, true, 00, "ELEANOR                          I prefer baking to cooking, but  this is a wonderful kitchen."},
								{true, true, 00, "GUY                              Yeah, what you make?"},
								{true, true, 00, "ELEANOR                          My favorite thing to make is key lime pie, but sometimes I"},
								{true, true, 00, "ELEANOR                          just need to make a lot of pecan praline. Do you like praline?"},
								{true, true, 00, "GUY                              Like praline?"},
								{true, true, 00, "GUY                              LIKE praline?"},
								{true, true, 00, "GUY                              Yeah, it's pretty good."},
								{true, true, 00, "GUY                              You get me some praline, and I'llget you free food, how's that?"},
								{true, true, 00, "ELEANOR                          It's a deal!"},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						case 6:
						{
							line lc[32] = {
								{true, true, 00, "DIANA                            Hey, there! Guy Pizza, is it?"},
								{true, true, 00, "GUY                              Guy Pizza, the one and only."},
								{true, true, 00, "DIANA                            I can see why, haha. You Italian?"},
								{true, true, 00, "GUY                              Nah, I'm from Donaldsonville.    New name, new life."},
								{true, true, 00, "DIANA                            And so you chose 'pizza'?"},
								{true, true, 00, "GUY                              People called me 'pizza guy' for ages, and my name's Guy..."},
								{true, true, 00, "GUY                              It was just natural. Plus, it    makes folks hungry."},
								{true, true, 00, "DIANA                            Yeah, for pizza. Do you make     pizza often?"},
								{true, true, 00, "GUY                              Not often, no."},
								{true, true, 00, "DIANA                            I guess it's not too late to     change your mind, you know."},
								{true, true, 00, "GUY                              You got any suggestions?"},
								{true, true, 00, "DIANA                            Guy... Mysterious. That sounds   mysterious."},
								{true, true, 00, "GUY                              I'm not a magician."},
								{true, true, 00, "DIANA                            You're also not a pizza."},
								{true, true, 00, "GUY                              Fair play."},
								{true, true, 00, "GUY                              I'll take your suggestion into   account, we'll just say that."},
								{true, true, 00, "COM: Endscene"}};
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
							{true, true, 00, "AARON                            Huh.. No one seems to be home."},
							{true, true, 00, "COM: Endscene"}};
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
				}

				if (globals->all_save.language == 2)
				{
					switch (possible_action)
					{

					case 2:
					{
						line lc[10] = {
							{fals, true, 0, "MAPLE                            Enoki, no hay ventana."},
							{fals, true, 0, "ENOKI                            {ah huh?"},
							{fals, true, 0, "MAPLE                            {Y que pasaria si alguien"},
							{fals, true, 0, "MAPLE                            intentara colarse?"},
							{fals, true, 0, "ENOKI                            Aaron le daria una paliza."},
							{fals, true, 0, "ENOKI                            En la pura cara."},
							{fals, true, 0, "MAPLE                            Pero el no esta aqui ahorita."},
							{fals, true, 0, "ENOKI                            Entonces sere yo quien le de la paliza."},
							{fals, true, 0, "MAPLE                            Eh.... Hmm. Esta bien, supongo."},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};

					case 3:
					{
						line l2[10] = {
							{true, true, 00, "Ves una vasija."},
							{true, true, 00, "Sientes que deberias destruirla."},
							{true, true, 00, "Pero no puedes hacer eso."},
							{true, true, 00, "Te invade una extra[a frustracion"},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(l2);
						break;
					};

					case 4:
					{
						line lc[19] = {
							{fals, true, 0, "MAPLE                            Mejor vamonos. No me gustaria"},
							{fals, true, 0, "MAPLE                            despertarlo."},
							{fals, true, 0, "ENOKI                            Nah, no pasa nada."},
							{fals, true, 0, "ENOKI                            Noy hay manera que se levante."},
							{fals, true, 0, "ENOKI                            Le gustan las luces encendidas   tambien."},
							{fals, true, 0, "MAPLE                            Pense que no tenias"},
							{fals, true, 0, "MAPLE                            electricidad..."},
							{fals, true, 0, "ENOKI                            Si tenemos, nada mas ese enchufe."},
							{fals, true, 0, "ENOKI                            Es un enchufe muy importante."},
							{fals, true, 0, "MAPLE                            {De verdad te gusta este lugar?"},
							{fals, true, 0, "ENOKI                            {Acaso vienes solo para"},
							{fals, true, 0, "ENOKI                            insultar mi casa?"},
							{fals, true, 0, "MAPLE                            No, QUe VA, en absoluto..."},
							{fals, true, 0, "ENOKI                            Uh huh, ya decia yo."},
							{fals, true, 0, "MAPLE                            Je m'excuse."},
							{fals, true, 0, "ENOKI                            Merci."},
							{fals, true, 0, "MAPLE                            Pero cuando te muevas conmigo."},
							{fals, true, 0, "MAPLE                            No me digas que no te lo adverti"},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};

					case 8:
					{
						line lc[9] = {
							{fals, true, 0, "ENOKI                            {Sabes? Cuando Del era mi"},
							{fals, true, 0, "ENOKI                            ni[era, mis padres le ofrecieron"},
							{fals, true, 0, "ENOKI                            tres habitaciones diferentes en"},
							{fals, true, 0, "ENOKI                            las que podia quedarse. Pero aun asi"},
							{fals, true, 0, "ENOKI                            Del siempre dormia en la tina delba[o."},
							{fals, true, 0, "MAPLE                            Pues no suena tan mal."},
							{fals, true, 0, "ENOKI                            Y yo lo intente pero a mi piel"},
							{fals, true, 0, "ENOKI                            no le gusto mucho."},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};

					case 9:
					{
						line lc[9] = {
							{fals, true, 0, "MAPLE                            Enoki, esta puerta tiene esta    cerrada."},
							{fals, true, 0, "ENOKI                            Oh esa, creo que eso es la"},
							{fals, true, 0, "ENOKI                            cocina. Pero no sabemos donde"},
							{fals, true, 0, "ENOKI                            podria estar la llave."},
							{fals, true, 0, "MAPLE                            {Y entonces como comen?"},
							{fals, true, 0, "ENOKI                            }Cocinamos todo en"},
							{fals, true, 0, "ENOKI                            una gran fogata!"},
							{fals, true, 0, "MAPLE                            }Ya ni la amuelan!"},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};

					// M and E talking about A
					case 10:
					{
						line lc[20] = {
							{fals, true, 0, "ENOKI                            {Que no se ve mono cuando"},
							{fals, true, 0, "ENOKI                            esta dormido? <3"},
							{fals, true, 0, "MAPLE                            {Que no tienen apenas unos meses"},
							{fals, true, 0, "MAPLE                            desde que se casaron?"},
							{fals, true, 0, "MAPLE                            {No deberian estar ya en esa"},
							{fals, true, 0, "MAPLE                            fase en la que ninguno se dirige"},
							{fals, true, 0, "MAPLE                            la palabra cuando comen juntos"},
							{fals, true, 0, "MAPLE                            y haber ganado unos 5 kilos de   peso?"},
							{fals, true, 0, "ENOKI                            Huh, Yo creo que he perdido peso."},
							{fals, true, 0, "MAPLE                            Creo que no lo entiendo."},
							{fals, true, 0, "ENOKI                            Solo porque siempre te"},
							{fals, true, 0, "ENOKI                            peleas con tus ex-novios no"},
							{fals, true, 0, "ENOKI                            significa que todas las parejas"},
							{fals, true, 0, "ENOKI                            tengan que ser asi, tu connais."},
							{fals, true, 0, "ENOKI                            A ver, es que siempre tienes ese"},
							{fals, true, 0, "ENOKI                            habito de-"},
							{fals, true, 0, "MAPLE                            Anda, termina esa frase y te voy a-"},
							{fals, true, 0, "MAPLE                            Te voy a quemar las cejas."},
							{fals, true, 0, "ENOKI                            ...hacer eso."},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};

					// The bookshelf room
					case 11:
					{
						line lc[32] = {
							{fals, true, 0, "ENOKI                            Nous sommes ici!"},
							{fals, true, 0, "ENOKI                            Y aqui esta el cuarto de las     repisas"},
							{fals, true, 0, "MAPLE                            Veo que no bromeabas con"},
							{fals, true, 0, "MAPLE                            eso de la biblioteca, y tampoco"},
							{fals, true, 0, "MAPLE                            con lo de las repisas..."},
							{fals, true, 0, "ENOKI                            Bon, ni yo ni Aaron hemos podido"},
							{fals, true, 0, "ENOKI                            moverla. {Puedes hacerme el"},
							{fals, true, 0, "ENOKI                            favor de usar tu magia de elfo?"},
							{fals, true, 0, "MAPLE                            A ver si lo capto..."},
							{fals, true, 0, "MAPLE                            {Quieres que *queme* una"},
							{fals, true, 0, "MAPLE                            esas repisas bien conservadas?"},
							{fals, true, 0, "ENOKI                            Quisiera saber si hay algun"},
							{fals, true, 0, "ENOKI                            pasadizo secreto detras de ella"},
							{fals, true, 0, "ENOKI                            o algo por el estilo, {sabes?"},
							{fals, true, 0, "MAPLE                            Me niego. Esto es ridiculo."},
							{fals, true, 0, "MAPLE                            Ademas esos libros se ven bien."},
							{fals, true, 0, "ENOKI                            Anda, ya los revise, la mayoria  ya"},
							{fals, true, 0, "ENOKI                            se estan pudriendo.. Estarian    mejor"},
							{fals, true, 0, "ENOKI                            que se quemen."},
							{fals, true, 0, "MAPLE                            {Estas segura de ello?"},
							{fals, true, 0, "ENOKI                            Completamente."},
							{fals, true, 0, "MAPLE                            Ok, hagamos un trato entonces."},
							{fals, true, 0, "MAPLE                            Quemare esto, pero debes escoger"},
							{fals, true, 0, "MAPLE                            al menos un libro. //j'ai        compris?"},
							{fals, true, 0, "MAPLE                            {J'ai compris? {Oui?"},
							{fals, true, 0, "ENOKI                            }Oui!"},
							{fals, true, 0, "ENOKI                            ... Vale, ya tengo un libro."},
							{fals, true, 0, "ENOKI                            Recuerda, }usa el gatillo 'R'"},
							{fals, true, 0, "ENOKI                            para lanzar una bola de fuego!"},
							{fals, true, 0, "MAPLE                            {...De que estas hablando?"},
							{fals, true, 0, "ENOKI                            {Huh? Oh, no es nada."},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};

					// Shoot the bookshelf
					case 12:
					{
						line lc[32] = {
							{fals, true, 0, "MAPLE                            ...."},
							{fals, true, 0, "ENOKI                            Bueno, pues no hay pasadizo."},
							{fals, true, 0, "MAPLE                            No me digas.."},
							{fals, true, 0, "ENOKI                            Que extra[o."},
							{fals, true, 0, "MAPLE                            A ver, Enoki..."},
							{fals, true, 0, "MAPLE                            Supongo que no tiene ningun"},
							{fals, true, 0, "MAPLE                            sentido enfadarse contigo, pero"},
							{fals, true, 0, "MAPLE                            deberias dejar de actuar asi."},
							{fals, true, 0, "MAPLE                            Tu y Aaron gastaron un"},
							{fals, true, 0, "MAPLE                            dineral en un castillo sin"},
							{fals, true, 0, "MAPLE                            amueblar ni necesidades basicas."},
							{fals, true, 0, "MAPLE                            {Para que? {Para que puedas jugar"},
							{fals, true, 0, "MAPLE                            a hacerte la princesa? Mientras"},
							{fals, true, 0, "MAPLE                            haces eso, yo sacrifico toda"},
							{fals, true, 0, "MAPLE                            mi vida personal manteniendo el"},
							{fals, true, 0, "MAPLE                            apartamento de Carolina con solo"},
							{fals, true, 0, "MAPLE                            lo esencial. Enoki... Por favor."},
							{fals, true, 0, "MAPLE                            No quiero parecer la mala aqui."},
							{fals, true, 0, "MAPLE                            Entiendo que no has tenido"},
							{fals, true, 0, "MAPLE                            una buena infancia"},
							{fals, true, 0, "MAPLE                            ni padres...Porque esa soy yo    tambien."},
							{fals, true, 0, "MAPLE                            Pero no puedes seguir portandote"},
							{fals, true, 0, "MAPLE                            de esta forma. {Lo entiendes?"},
							{fals, true, 0, "ENOKI                            Lo entiendo."},
							{fals, true, 0, "MAPLE                            Son las 5:00 de la ma[ana, voy"},
							{fals, true, 0, "MAPLE                            a volver a la cama. Te vere por"},
							{fals, true, 0, "MAPLE                            la ma[ana, {oui?"},
							{fals, true, 0, "ENOKI                            Oui..."},
							{fals, true, 0, "MAPLE                            No te apures pensando en"},
							{fals, true, 0, "MAPLE                            esto. S'il te plait, Bonne nuit."},
							{fals, true, 0, "ENOKI                            Bonne nuit..."},
							{true, true, 00, "COM: Endscene"}};
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
								{fals, true, 0, "(Todas y cada una de estas       prendas son de Enoki, {no?)"},
								{fals, true, 0, "(Claro que Aaron recogeria       todas las suyas.)"},
								{fals, true, 0, "(Son tan distintos... No entiendocomo lo hacen para"},
								{fals, true, 0, "no pelearse todo el tiempo.      No consigo comprenderlo.)"},
								{fals, true, 0, "(Si tuviera novio, le            obligaria a recoger toda su"},
								{fals, true, 0, "ropa inmediatamente.)"},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}

						else if (me == 1)
						{
							line lc[32] = {
								{fals, true, 0, "    (Si hubiera sabido que Maple iba a venir tan pronto, habria"},
								{fals, true, 0, "    comenzado a limpiar un poco  antes....)"},
								{fals, true, 0, "    (Tal vez no se de cuenta si  me pongo a recoger ahora)"},
								{fals, true, 0, "    (Aunque puede que ya lo aiga visto y ya me esta juzgando)"},
								{fals, true, 0, "    (...Este esta chido, quiza lodeje en el suelo y me lo ponga"},
								{fals, true, 0, "    ma[ana.)"},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}

						else if (me == 2)
						{
							line lc[32] = {
								{fals, true, 0, "(Enoki no era tan desordenada    cuando viviamos en el castillo.)"},
								{fals, true, 0, "(Puede que se empiece a sentir   mas relajada porque"},
								{fals, true, 0, "piensa que nos hemos movido de   forma definitiva.)"},
								{fals, true, 0, "(Aunque no la quiera regar, pero,Aaron Tremblay,"},
								{fals, true, 0, "lo e logrado. E conseguido un    hogar propio y una esposa"},
								{fals, true, 0, "que deja tu ropa tirada en el    piso.)"},
								{fals, true, 0, "(No podria pensar en querer algo mas en estos momentos.)"},
								{fals, true, 0, "(Bueno.....                      Extra[o mi carro.)"},
								{fals, true, 0, "(Tal vez le diga a Scout para    poner una pista de carreras.)"},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}

						else if (me == 3)
						{
							line lc[32] = {
								{fals, true, 0, "(Definitivamente no deveria estaraqui.)"},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}

						else
						{
							line lc[32] = {
								{true, true, 00, "(Esta ropa obviamente ha estado aqui por un tiempo.)"},
								{true, true, 00, "COM: Endscene"}};
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

									{fals, true, 0, "(Por lo menos cuando vivian      castillo, su cama estaba en"},
									{fals, true, 0, "medio del cuarto. {Y que se      supone que es esto?)"},
									{fals, true, 0, "({Quien se ha quedado en la      esquina? Probablemente Aaron.)"},
									{fals, true, 0, "(Ya ni la amuelan, esa chica le  va a dar canas verdes 10 a[os    antes.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							if (me == 1)
							{
								line lc[32] = {
									{fals, true, 0, "(Me alegra que no tenga que      dormir en medio del cuarto.)"},
									{fals, true, 0, "(Me dolia un monton cuando me    caia en el piso de piedra.)"},
									{fals, true, 0, "(Ahora podre moverme tranquila   hacia la pared o a Aaron.)"},
									{fals, true, 0, "(Me alegra mucho que a el no le  importe.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							if (me == 2)
							{
								line lc[32] = {
									{fals, true, 0, "(Maple no le agradara nada cuandovea el cuarto.)"},
									{fals, true, 0, "(Recuerdo cuando era buena       onda...)"},
									{fals, true, 0, "(Es muy estresante tenerla cerca estos dias.)"},
									{fals, true, 0, "(Mejor ni hubiera venido. Cada   vez que trato de"},
									{fals, true, 0, "ayudarla, lo unico que hace es   quejarse.)"},
									{fals, true, 0, "(Ojala se aburra de vivir aqui y se regrese a su casa.)"},
									{fals, true, 0, "(O quizas tenga razon y solo     estoy viviendo en la fantasia de Enoki.)"},
									{fals, true, 0, "(Pero Enoki ha sido la unica     felicidad que he tenido en a[os.)"},
									{fals, true, 0, "(Tal vez cambiemos de parecer... ojala y algo cambie.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							if (me == 3)
							{
								line lc[32] = {
									{fals, true, 0, "(No deveria estar aqui sin ser   invitado...)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
						}
						else if (globals->current_save->checkpoint < 10)
						{
							if (me == 0)
							{
								line lc[32] = {
									{fals, true, 0, "(La verdad no quisiera admitirlo,pero...)"},
									{fals, true, 0, "(Me gusta mucho estar con ellos. He olvidado lo genial)"},
									{fals, true, 0, "(que es estar con alguien.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							if (me == 1)
							{
								line lc[32] = {
									{fals, true, 0, "(Sabes, quisiera viajar al pasadopara poder hablar conmigo misma.)"},
									{fals, true, 0, "(Y la verdad, no me creeria todo lo que ha pasado este a[o.)"},
									{fals, true, 0, "(Y... no creo que mis padres     sepan que estoy aqui.)"},
									{fals, true, 0, "(Me pregunto donde creen que     estoy ahorita.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							if (me == 2)
							{
								line lc[32] = {
									{fals, true, 0, "(Ya necesito conseguirle a Maple su propio lugar.)"},
									{fals, true, 0, "(No pense que ella daria todo    para cumplir con su parte...)"},
									{fals, true, 0, "(Con toda esa espeleologia hemos podido cubrir los gastos.)"},
									{fals, true, 0, "(Me sorprende que ella no haya   preguntado por un lugar propio.)"},
									{fals, true, 0, "(O a lo mejor no le gusta estar  sola.)"},
									{fals, true, 0, "(Y la verdad no me agrada tener  que hacer otra casa.)"},
									{fals, true, 0, "(Platicare con Oliver, a ver que se puede hacer.)"},
									{fals, true, 0, "(Es todo un experto en el tema.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							if (me == 3)
							{
								line lc[32] = {
									{fals, true, 0, "(Si, eso es un cuarto.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							if (me == 4)
							{
								line lc[32] = {
									{fals, true, 0, "(Me agrada la luz natural de     aqui.)"},
									{fals, true, 0, "(Podria traer algunas plantas.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							if (me == 5)
							{
								line lc[32] = {
									{fals, true, 0, "(Esto me recuerda mucho a la casade los papas de Vee.)"},
									{fals, true, 0, "(Espero que sean personas        confiables.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							if (me == 6)
							{
								line lc[32] = {
									{fals, true, 0, "(Ok, me agradan estas personas.)"},
									{fals, true, 0, "(Me hacen sentir comoda.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
						}
						else if (globals->current_save->checkpoint < 12)
						{
							if (me == 0)
							{
								line lc[32] = {
									{fals, true, 0, "(Gracias a dios ese chico nuevo..ehh, bueno ese muchacho es       cocinero.)"},
									{fals, true, 0, "(Comer siempre Gumbo no seria tanmalo si alguien mas lo cocinara.)"},
									{fals, true, 0, "(Ojala y tambien sea buena onda.)"},
									{fals, true, 0, "(Ugh, no se que me pasa, pero    tengo ganas de conocer a nuevas  personas)"},
									{fals, true, 0, "(Me estare volviendo loca, Yo?   {Ganas de conocer?...)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							else if (me == 1)
							{
								line lc[32] = {
									{fals, true, 0, "(Este cuarto no ha cambiado para nada.)"},
									{fals, true, 0, "({Y si muevo la cama para el otrolado?)"},
									{fals, true, 0, "(No.. Mejor no, seria mas dificilesconder la ropa.)"},
									{fals, true, 0, "(Deberia recoger esos... eh...   ...mejor lo hago mas alrato.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							else if (me == 2)
							{
								line lc[32] = {
									{fals, true, 0, "(Bueno, pues ahi se fue la ultimaoportunidad de que Maple se fueraa la cabana.)"},
									{fals, true, 0, "(Mientras Enoki este contenta conque Maple este aqui.)"},
									{fals, true, 0, "(La casa dejara de ser mi hogar. No se que mosca le habra picado.)"},
									{fals, true, 0, "(Que paso con que le gusta ser   independiente? Es como mugre en  las u[as.)"},
									{fals, true, 0, "(Y Enoki parece que se esta dandocuenta que estoy molesto por     algo.)"},
									{fals, true, 0, "(Neta... ya estoy hablando igual que Maple.)"},
									{fals, true, 0, "({Acaso todos los hermanos son deesta manera?)"},
									{fals, true, 0, "(Con ganas de preguntarle a      alguien, pero ni amigos tengo.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							else if (me == 3)
							{
								line lc[32] = {
									{fals, true, 0, "(Ya mero es el cumplea[os de     Aaron... Una planta seria un buenregalo.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							else if (me == 7)
							{
								line lc[32] = {
									{fals, true, 0, "(Me encanta la luz del sol aqui.)"},
									{fals, true, 0, "(Podria poner algunas plantas.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							else
							{
								line lc[32] = {
									{fals, true, 0, "(Probablemente no deveria estar  espiando.)"},
									{true, true, 00, "COM: Endscene"}};
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
									{fals, true, 0, "MAPLE                            Oye, {Que es ese libro?"},
									{fals, true, 0, "AARON                            Oh, es mio."},
									{fals, true, 0, "AARON                            Ya sabes que no me va mucho la   ficcion,"},
									{fals, true, 0, "AARON                            Pero Enoki es un poco terca,     bueno a veces."},
									{fals, true, 0, "ENOKI                            {Has escuchado algo de Yellow?"},
									{fals, true, 0, "ENOKI                            Es bien padre, Aaron ya le       interesa por mi."},
									{fals, true, 0, "MAPLE                            ...{Tiene dibujos?"},
									{fals, true, 0, "MAPLE                            {Aun lees libros ilustrados?"},
									{fals, true, 0, "ENOKI                            }Este tiene cigarros!"},
									{fals, true, 0, "ENOKI                            Eso significa que es para ni[os yadultos."},
									{fals, true, 0, "MAPLE                            Neta, {de verdad hacen libros    asi?"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}

							if (me == 1)
							{
								line lc[32] = {
									{fals, true, 0, "ENOKI                            O, que onda Maple, {quieres jugo?"},
									{fals, true, 0, "MAPLE                            {De que tipo?"},
									{fals, true, 0, "ENOKI                            Es un secreto."},
									{fals, true, 0, "MAPLE                            No voy tomar cosas extra[as."},
									{fals, true, 0, "ENOKI                            ...."},
									{fals, true, 0, "ENOKI                            Anda, es jugo de naranja / VENENO", 10},
									{fals, true, 0, "MAPLE                            {Y no crees que me hubiera dado"},
									{fals, true, 0, "MAPLE                            cuenta?"},
									{fals, true, 0, "ENOKI                            {A lo mejor?"},
									{fals, true, 0, "MAPLE                            Paso. Merci."},
									{true, true, 0, "COM: Endscene"},
									{fals, true, 0, "MAPLE                            Viniendo de ti, me lo creeria."},
									{fals, true, 0, "ENOKI                            Podrias probarlo y luego         averiguar {no?."},
									{fals, true, 0, "MAPLE                            Gracias, pero no tengo ganas."},

									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}

							if (me == 2)
							{
								line lc[32] = {
									{fals, true, 0, "(Nos queda poco jugo de naranja.)"},
									{fals, true, 0, "(Lo mas seguro es que tenga que  ir al  pueblo a vender frutas.)"},
									{fals, true, 0, "(Vender una fruta para comprar   otra, heh.)"},
									{fals, true, 0, "(Si por lo menos el jugo de      patata estuviera un poco rico...)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}

							if (me == 3)
							{
								line lc[32] = {
									{fals, true, 0, "ENOKI                            }EEEE! }Ahora todos mis amigos"},
									{fals, true, 0, "ENOKI                            se conocen entre ellos!"},
									{fals, true, 0, "ENOKI                            }Ahora si que somos un grupo!"},
									{fals, true, 0, "MAPLE                            Woa, aun no me decido si-"},
									{fals, true, 0, "MAPLE                            Si me quedo aqui, calmate."},
									{fals, true, 0, "SCOUT                            {Va a venir alguien mas?"},
									{fals, true, 0, "AARON                            Tendremos que esperar y ver."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
						}

						else if (globals->current_save->checkpoint < 10)
						{
							if (me < 3)
							{
								line lc[32] = {
									{fals, true, 0, "MAPLE                            Creo que ya los lei todos."},
									{fals, true, 0, "AARON                            Hace rato que no vamos al pueblo."},
									{fals, true, 0, "MAPLE                            Me pregunto que estara pasando   fuera de aqui."},
									{fals, true, 0, "ENOKI                            Si algo hubiera pasado ya lo     sabriamos."},
									{fals, true, 0, "ENOKI                            Scout habria dicho algo."},
									{fals, true, 0, "ENOKI                            Siempre esta metido en internet."},
									{fals, true, 0, "MAPLE                            Podria pedirle que me compre unoslibros."},
									{fals, true, 0, "AARON                            Eso estaria super."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							else
							{
								line lc[32] = {
									{fals, true, 0, "Ves un monton de libros que      nunca antes habias visto."},
									{fals, true, 0, "Aunque ninguno de ellos parece   particularmente interesante...   Por ahora."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
						}
						else if (globals->current_save->checkpoint < 12)
						{
							if (me < 3)
							{
								line lc[32] = {
									{fals, true, 0, "MAPLE                            Creo que necesitamos un          videocasetera."},
									{fals, true, 0, "AARON                            {Compraras una?"},
									{fals, true, 0, "MAPLE                            Claro. Y un monton de            videocasets."},
									{fals, true, 0, "ENOKI                            Oooh, {Crees que me puedas       conseguir la ultima"},
									{fals, true, 0, "ENOKI                            pelicula de Time Raider? }Escucheque hay una nueva!"},
									{fals, true, 0, "MAPLE                            Solo por fastidiarte, comprare"},
									{fals, true, 0, "MAPLE                            todas las que vea EXCEPTO esa."},
									{fals, true, 0, "ENOKI                            Aw... Estaba pensando que quiza,"},
									{fals, true, 0, "ENOKI                            si a todos nos agrada la idea."},
									{fals, true, 0, "ENOKI                            ... {Tener una noche de          peliculas?"},
									{fals, true, 0, "MAPLE                            Okay, Okay alo mejor si."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							else if (me == 7)
							{
								line lc[32] = {
									{fals, true, 0, "Sonries, pensando que no saben   cocinar bien."},
									{fals, true, 0, "Definitivamente se convertiran   en clientes habituales."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}
							else
							{
								line lc[32] = {
									{fals, true, 0, "Ves un monton de libros que      nunca antes habias visto."},
									{fals, true, 0, "Aunque ninguno de ellos parece   particularmente interesante...   Por ahora."},
									{true, true, 00, "COM: Endscene"}};
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
								{fals, true, 0, "AARON                            Necesito ver como van los demas."},
								{true, true, 00, "COM: Endscene"},
							};
							dialogue_page_lite(lc);
							break;
						}
						break;
					};
					case 21:
					{
						line lc[32] = {
							{fals, true, 0, "JARDIN DE ENOKI                  Si tocas algo, acabare contigo."},
							{true, true, 00, "COM: Endscene"},
						};
						dialogue_page_lite(lc);
						break;
					};
					case 22:
					{
						line lc[32] = {
							{fals, true, 0, "EL LUGAR DE AARON                Donde se corta la le[a."},
							{true, true, 00, "COM: Endscene"}};
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
								{fals, true, 0, "Hmmm... Esta parece una tarea    adecuada para Enoki."},
								{true, true, 00, "COM: Endscene"}};
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
								{fals, true, 0, "Hmmm... Esta parece una tarea    adecuada para Aaron."},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
						break;
					};
					case 25:
					{
						line lc[32] = {
							{fals, true, 0, "CUEVA DE MURCIELAGOS PELIGROSOS  Advertencia: hay murcielagos."},
							{true, true, 00, "COM: Endscene"}};
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
								{fals, true, 0, "Creo que Maple es la unica que   puede entrar con seguridad."},
								{true, true, 00, "COM: Endscene"}};
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
									{fals, true, 0, "MAPLE                            {Plantas, eh?"},
									{fals, true, 0, "MAPLE                            {Que no hay un jardin arriva?"},
									{fals, true, 0, "SCOUT                            Veras, yo, ehm-"},
									{fals, true, 0, "SCOUT                            Realmente no es por las plantas"},
									{fals, true, 0, "SCOUT                            Yo estudio la tierra."},
									{fals, true, 0, "MAPLE                            {estudias la tierra?"},
									{fals, true, 0, "SCOUT                            Hay un estudio para cada..."},
									{fals, true, 0, "SCOUT                            Pues para cada cosa."},
									{fals, true, 0, "MAPLE                            Obvio."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 1)
							{
								line lc[32] = {
									{fals, true, 0, "ENOKI                            CREO que esa es la planta."},
									{fals, true, 0, "ENOKI                            Esa es mi favorita."},
									{fals, true, 0, "SCOUT                            {Quieres que la corte?"},
									{fals, true, 0, "ENOKI                            {Que tipo sera?"},
									{fals, true, 0, "SCOUT                            La verdad es que no lo se..."},
									{fals, true, 0, "SCOUT                            Estudio la tierra, no plantas."},
									{fals, true, 0, "ENOKI                            }Podria ser un fruto misterioso!"},
									{fals, true, 0, "SCOUT                            Puede que si."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 2)
							{
								line lc[32] = {
									{fals, true, 0, "AARON                            {Has hecho progresos?"},
									{fals, true, 0, "SCOUT                            }Claro que si!"},
									{fals, true, 0, "SCOUT                            He conseguido algo nuevo."},
									{fals, true, 0, "AARON                            {Como se llama?"},
									{fals, true, 0, "SCOUT                            Lo bautice como 'Scout-Out'."},
									{fals, true, 0, "SCOUT                            Puede quitar las malezas."},
									{fals, true, 0, "AARON                            }Eso es increible!"},
									{fals, true, 0, "SCOUT                            El unico problema es que..."},
									{fals, true, 0, "SCOUT                            Tambien lastima las demas        plantas."},
									{fals, true, 0, "AARON                            Esta ca[on..."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 3)
							{
								line lc[32] = {
									{fals, true, 0, "(}Dios mio, dios mio, dios mio.!)"},
									{fals, true, 0, "(Necesito figurar esa formula lo mas rapido posible.)"},
									{fals, true, 0, "(Tal vez no fue buena idea       prometer tierra magica a los     inversores.)"},
									{fals, true, 0, "(Tal vez si me escondo aqui abajono puedan encontrarme.)"},
									{fals, true, 0, "(Aunque primero deberia quitar   mi nombre de la ventanilla...)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
						}
						else if (globals->current_save->checkpoint < 10)
						{
							if (me == 0)
							{
								line lc[32] = {
									{fals, true, 0, "MAPLE                            {Lo mismo de siempre?"},
									{fals, true, 0, "SCOUT                            La verdad si."},
									{fals, true, 0, "MAPLE                            {Aun no han hablado contigo"},
									{fals, true, 0, "MAPLE                            sobre los resultados?"},
									{fals, true, 0, "SCOUT                            Aun no, pero sigo recibiendo"},
									{fals, true, 0, "SCOUT                            mi sueldo cada semana."},
									{fals, true, 0, "MAPLE                            Hey, eso es bueno."},
									{fals, true, 0, "SCOUT                            Pues si."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 3)
							{
								line lc[32] = {
									{fals, true, 0, "(Maple ha estado mirando las     plantas de vez en cuando...)"},
									{fals, true, 0, "(Al menos me dijo lo que opina   de ellas con sinceridad.)"},
									{fals, true, 0, "(Necesito urgentemente que mi    jefe responda a mis mensajes.)"},
									{fals, true, 0, "(Recibo un buen sueldo y no      deberia jugarmela demasiado.)"},
									{fals, true, 0, "(Tan solo he de asegurarme de    seguir los pasos correctos.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else
							{
								line lc[32] = {
									{fals, true, 0, "(Muchas muestras de tierra y     plantas inusuales metidas en     frascos.)"},
									{fals, true, 0, "(No lo entiendes, lo mas seguro  es que sea inofensivo.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
						}
						else if (globals->current_save->checkpoint < 12)
						{
							if (me == 0)
							{
								line lc[32] = {
									{fals, true, 0, "SCOUT                            Hey, uh... {Maple?"},
									{fals, true, 0, "SCOUT                            {Puedo hacerte una pregunta?"},
									{fals, true, 0, "MAPLE                            Claro, {que paso?"},
									{fals, true, 0, "SCOUT                            A... ti... {T-te gusta el tenis?"},
									{fals, true, 0, "MAPLE                            Amo el tenis  // Eww tennis.", 16},
									{fals, true, 0, "MAPLE                            {A que viene esa pregunta?"},
									{fals, true, 0, "SCOUT                            Oh, nada, nada... Solo me..."},
									{fals, true, 0, "MAPLE                            {Quieres jugar conmigo al tenis?"},
									{fals, true, 0, "SCOUT                            Siempre quise jugar tenis,"},
									{fals, true, 0, "SCOUT                            pero realmente no tengo con"},
									{fals, true, 0, "SCOUT                            quien jugar, {sabes?"},
									{fals, true, 0, "MAPLE                            Bueno, pues tu te encargas del   campo"},
									{fals, true, 0, "MAPLE                            y yo te podria ense[ar una a dos cositas."},
									{fals, true, 0, "SCOUT                            {L-lo estas diciendo en serio?"},
									{fals, true, 0, "MAPLE                            Claro."},
									{fals, true, 0, "SCOUT                            }Merci!"},
									{true, true, 0, "COM: Endscene"},
									{fals, true, 0, "SCOUT                            Oh, olvidalo, entonces."},
									{fals, true, 0, "MAPLE                            Me da."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 2)
							{
								line lc[32] = {
									{fals, true, 0, "AARON                            Okay, escuchame."},
									{fals, true, 0, "AARON                            Tienes esa herramienta para"},
									{fals, true, 0, "AARON                            hacer bunkers como este con"},
									{fals, true, 0, "AARON                            facilidad, {no? Podemos hacer-"},
									{fals, true, 0, "AARON                            }Una carrera subterranea!"},
									{fals, true, 0, "SCOUT                            Eso estaria padrisimo!"},
									{fals, true, 0, "SCOUT                            }Me encantaria intentarlo!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 3)
							{
								line lc[32] = {
									{fals, true, 0, "(Bueno, llego el momento. Quierenque les de mis muestras.)"},
									{fals, true, 0, "(Espero que no me corran.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else
							{
								line lc[32] = {
									{fals, true, 0, "(Muchas muestras de tierra y     plantas inusuales metidas en     frascos.)"},
									{fals, true, 0, "(No lo entiendes, lo mas seguro  es que sea inofensivo.)"},
									{true, true, 00, "COM: Endscene"}};
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
									{fals, true, 0, "MAPLE                            Oye mira, mas cosas raras."},
									{fals, true, 0, "SCOUT                            }Excusez-moi, mademoiselle!"},
									{fals, true, 0, "SCOUT                            }Son los Time Raiders!"},
									{fals, true, 0, "MAPLE                            {Time... Raiders?"},
									{fals, true, 0, "SCOUT                            }Si! }Las aventuras de"},
									{fals, true, 0, "SCOUT                            Jahn-Jahn Gazebo y sus"},
									{fals, true, 0, "SCOUT                            complices, Nexus y Ninjette!"},
									{fals, true, 0, "MAPLE                            Todo eso suena demasiado..."},
									{fals, true, 0, "MAPLE                            {Alguna vez has salido con       alguien?"},
									{fals, true, 0, "SCOUT                            No, las chicas me decian raro."},
									{fals, true, 0, "MAPLE                            Las chicas lo siguen diciendo."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 1)
							{
								line lc[32] = {
									{fals, true, 0, "ENOKI                            }Oh! {Son los Time Raiders?"},
									{fals, true, 0, "SCOUT                            {Conoces a los Time Raiders?"},
									{fals, true, 0, "ENOKI                            '}Lo consegui, Jahn-Jahn!'"},
									{fals, true, 0, "SCOUT                            }Al fin alguien mas!"},
									{fals, true, 0, "ENOKI                            Si, Aaron me lo ense[o."},
									{fals, true, 0, "ENOKI                            Me gusta el estilo de dibujo."},
									{fals, true, 0, "ENOKI                            {Me lo prestarias despues?"},
									{fals, true, 0, "SCOUT                            }Claro! Casi lo he terminado."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 2)
							{
								line lc[32] = {
									{fals, true, 0, "AARON                            Oye, {Esos no son los Time       Raiders?"},
									{fals, true, 0, "SCOUT                            }Si que si!"},
									{fals, true, 0, "AARON                            }Que chido! {Ya viste lo nuevo?"},
									{fals, true, 0, "SCOUT                            No, todavia no."},
									{fals, true, 0, "SCOUT                            Algo que aprenderas de tu nueva"},
									{fals, true, 0, "SCOUT                            'Vida Isle[a', es que conseguir"},
									{fals, true, 0, "SCOUT                            cosas nuevas puede ser dificil."},
									{fals, true, 0, "SCOUT                            Podria usar mi computadora,"},
									{fals, true, 0, "SCOUT                            pero no es la misma experiencia."},
									{fals, true, 0, "AARON                            Estoy totalmente de acuerdo."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 3)
							{
								line lc[32] = {
									{fals, true, 0, "(Debo terminar con esto para asi darselo a Enoki.)"},
									{fals, true, 0, "(Pero la formula que prometi...  Estoy muy cerca de lograrla.)"},
									{fals, true, 0, "(Tal vez pueda lograrlo si no    duermo unos dias.)"},
									{fals, true, 0, "(Un poco mas y al fin podre      tenerlo listo.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
						}
						else if (globals->current_save->checkpoint < 10)
						{

							if (me == 0)
							{
								line lc[32] = {
									{fals, true, 0, "SCOUT                            Oye, a ti te gusta"},
									{fals, true, 0, "SCOUT                            leer mucho, {verdad?"},
									{fals, true, 0, "MAPLE                            Claro."},
									{fals, true, 0, "SCOUT                            {Crees que podrias prestarme"},
									{fals, true, 0, "SCOUT                            algunos de tus libros?"},
									{fals, true, 0, "MAPLE                            No te gustarian."},
									{fals, true, 0, "SCOUT                            Al menos quisiera intentarlo."},
									{fals, true, 0, "MAPLE                            {Te gusta la literatura          romantica? O los de epoca?", 14},
									{fals, true, 0, "MAPLE                            {Las relaciones complicadas?"},
									{fals, true, 0, "SCOUT                            Ya veo... algo mas? O es todo?"},
									{fals, true, 0, "MAPLE                            No, eso es lo que me gusta."},
									{fals, true, 0, "MAPLE                            {Acaso te hace sentir incomodo?"},
									{fals, true, 0, "SCOUT                            ... Quiza un poco."},
									{fals, true, 0, "MAPLE                            Mejor sigue leyendo tus comics."},
									{true, true, 0, "COM: Endscene"},
									{fals, true, 0, "SCOUT                            Podrian empezar a gustarme."},
									{fals, true, 0, "MAPLE                            Por favor.."},
									{true, true, 00, "COM: Endscene"},
								};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 1)
							{
								line lc[32] = {
									{fals, true, 0, "SCOUT                            Oye, {Enoki?"},
									{fals, true, 0, "ENOKI                            {Si?"},
									{fals, true, 0, "SCOUT                            {Podemos hablar de Maple?"},
									{fals, true, 0, "ENOKI                            Oooh, {que ocurre con ella?"},
									{fals, true, 0, "ENOKI                            TE GUSTA Maple, {no es asi?"},
									{fals, true, 0, "SCOUT                            {Que dices de gustar?"},
									{fals, true, 0, "ENOKI                            Ya lo sabemos todos, jeje."},
									{fals, true, 0, "SCOUT                            Neta, {tan obvio es?."},
									{fals, true, 0, "ENOKI                            Pero ella es complicada."},
									{fals, true, 0, "ENOKI                            Una vez le presente a un chico."},
									{fals, true, 0, "SCOUT                            {Le presentaste a un chico?"},
									{fals, true, 0, "ENOKI                            Y salieron durante un tiempo."},
									{fals, true, 0, "ENOKI                            Aunque se harto y la dejo."},
									{fals, true, 0, "ENOKI                            Debes ser perfecto para ella."},
									{fals, true, 0, "SCOUT                            Y yo no lo soy."},
									{fals, true, 0, "ENOKI                            No se quien podria serlo."},
									{fals, true, 0, "SCOUT                            Bueno, un hombre puede so[ar."},
									{fals, true, 0, "ENOKI                            Pero no cambies."},
									{fals, true, 0, "ENOKI                            Solo se la mejor version de 'tu  mismo'."},
									{fals, true, 0, "SCOUT                            Supongo que tienes razon."},
									{fals, true, 0, "ENOKI                            Ya la chica correcta llegara."},
									{fals, true, 0, "SCOUT                            Esta bien. Merci, Enoki."},
									{fals, true, 0, "ENOKI                            }De rien!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 2)
							{
								line lc[32] = {
									{fals, true, 0, "SCOUT                            Oye y.. {Como le preguntaste"},
									{fals, true, 0, "SCOUT                            a Enoki si queria salir?"},
									{fals, true, 0, "AARON                            Solo le invite a tomar cafe."},
									{fals, true, 0, "SCOUT                            Cafe, cafe... okay."},
									{fals, true, 0, "SCOUT                            No tenemos, hmm... Cafe..."},
									{fals, true, 0, "AARON                            {Quieres invitar a Maple a salir?"},
									{fals, true, 0, "SCOUT                            Bueno, yo... Si, me gustaria."},
									{fals, true, 0, "AARON                            Te diria que no lo intentes, peroaya tu."},
									{fals, true, 0, "AARON                            Ningun chico es"},
									{fals, true, 0, "AARON                            bueno para ella."},
									{fals, true, 0, "SCOUT                            Quiza sea inutil intentarlo."},
									{fals, true, 0, "AARON                            Es imposible complacerla."},
									{fals, true, 0, "AARON                            Creeme, la conozco bien."},
									{fals, true, 0, "SCOUT                            {A que te refieres?"},
									{fals, true, 0, "AARON                            Su tipo son los que se creen"},
									{fals, true, 0, "AARON                            muy aca, como mejores de lo"},
									{fals, true, 0, "AARON                            que son. Aunque a decir"},
									{fals, true, 0, "AARON                            verdad. Tambien le he visto"},
									{fals, true, 0, "AARON                            salir con otro tipo de"},
									{fals, true, 0, "AARON                            bobos. {sabes? Quiza solo tengas"},
									{fals, true, 0, "AARON                            que esforzarte un poco en"},
									{fals, true, 0, "AARON                            tener algo mas de confianza"},
									{fals, true, 0, "AARON                            en ti mismo."},
									{fals, true, 0, "SCOUT                            Bueno, eso un buen comienzo."},
									{fals, true, 0, "AARON                            Buena suerte con ella."},
									{fals, true, 0, "SCOUT                            Merci."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 3)
							{
								line lc[32] = {
									{fals, true, 0, "(A lo mejor puedo convencer a    Maple de leer unos comics.)"},
									{fals, true, 0, "(Entonces asi podriamos tener    algo   en comun.)"},
									{fals, true, 0, "(...Pero eso no pasara ni en mil a[os.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 7)
							{
								line lc[32] = {
									{fals, true, 0, "GUY                              {Te gustan los Time Raiders?"},
									{fals, true, 0, "SCOUT                            Si, un poco."},
									{fals, true, 0, "GUY                              {Cada cuando consigues los       nuevos?"},
									{fals, true, 0, "SCOUT                            Diana los manda a traer cada     semana."},
									{fals, true, 0, "GUY                              Que bueno, pense que ya no los   podria"},
									{fals, true, 0, "GUY                              leer despues que me mude aqui."},
									{fals, true, 0, "SCOUT                            Aunque si que hay una lista largade espera."},
									{fals, true, 0, "SCOUT                            Tendras que esperar a que Enoki"},
									{fals, true, 0, "SCOUT                            los termine, a ella le gustan    tambien."},
									{fals, true, 0, "GUY                              Nah, yo los voy a agarrar        primero."},
									{fals, true, 0, "SCOUT                            Eyy, eso tomalo con ella."},
									{fals, true, 0, "GUY                              Eso hare."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else
							{
								line lc[32] = {
									{fals, true, 0, "(Los comics del mes pasado       siguen tirados en el suelo.)"},
									{fals, true, 0, "(Lentamente acumulando polvo.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
						}
						else if (globals->current_save->checkpoint < 12)
						{
							if (me == 0)
							{
								line lc[32] = {
									{true, true, 00, "SCOUT                            Hey, you know, you like to read"},
									{true, true, 00, "SCOUT                            a lot, right?"},
									{true, true, 00, "MAPLE                            Sure thing."},
									{true, true, 00, "SCOUT                            Do you think that maybe I could"},
									{true, true, 00, "SCOUT                            borrow some of your books?"},
									{true, true, 00, "MAPLE                            You wouldn't like them."},
									{true, true, 00, "SCOUT                            I'm sure I could try."},
									{true, true, 00, "MAPLE                            You like romance?"},
									{true, true, 00, "MAPLE                            Steamy romance?"},
									{true, true, 00, "SCOUT                            I... do you have anything else?"},
									{true, true, 00, "MAPLE                            No, that's what I like."},
									{true, true, 00, "MAPLE                            What, it make you uncomfortable?"},
									{true, true, 00, "SCOUT                            ..Maybe a bit."},
									{true, true, 00, "MAPLE                            Yeah, stick to your comic books."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 1)
							{
								line lc[32] = {
									{fals, true, 0, "SCOUT                            Oye, {Enoki?"},
									{fals, true, 0, "ENOKI                            {Si?"},
									{fals, true, 0, "SCOUT                            {Podemos hablar de Maple?"},
									{fals, true, 0, "ENOKI                            Oooh, {que ocurre con ella?"},
									{fals, true, 0, "ENOKI                            TE GUSTA Maple, {no es asi?"},
									{fals, true, 0, "SCOUT                            {Que dices de gustar?"},
									{fals, true, 0, "ENOKI                            Ya lo sabemos todos, jeje."},
									{fals, true, 0, "SCOUT                            Neta, {tan obvio es?."},
									{fals, true, 0, "ENOKI                            Pero ella es complicada."},
									{fals, true, 0, "ENOKI                            Una vez le presente a un chico."},
									{fals, true, 0, "SCOUT                            {Le presentaste a un chico?"},
									{fals, true, 0, "ENOKI                            Y salieron durante un tiempo."},
									{fals, true, 0, "ENOKI                            Aunque se harto y la dejo."},
									{fals, true, 0, "ENOKI                            Debes ser perfecto para ella."},
									{fals, true, 0, "SCOUT                            Y yo no lo soy."},
									{fals, true, 0, "ENOKI                            No se quien podria serlo."},
									{fals, true, 0, "SCOUT                            Bueno, un hombre puede so[ar."},
									{fals, true, 0, "ENOKI                            Pero no cambies."},
									{fals, true, 0, "ENOKI                            Solo se la mejor version de 'tu mismo'."},
									{fals, true, 0, "SCOUT                            Supongo que tienes razon."},
									{fals, true, 0, "ENOKI                            Ya la chica correcta llegara."},
									{fals, true, 0, "SCOUT                            Esta bien. Merci, Enoki."},
									{fals, true, 0, "ENOKI                            }De rien!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 2)
							{
								line lc[32] = {
									{fals, true, 0, "SCOUT                            Oye y.. {Como le preguntaste"},
									{fals, true, 0, "SCOUT                            a Enoki si queria salir?"},
									{fals, true, 0, "AARON                            Solo le invite a tomar cafe."},
									{fals, true, 0, "SCOUT                            Cafe, cafe... okay."},
									{fals, true, 0, "SCOUT                            No tenemos, hmm... Cafe..."},
									{fals, true, 0, "AARON                            {Quieres invitar a Maple a salir?"},
									{fals, true, 0, "SCOUT                            Bueno, yo... Si, me gustaria."},
									{fals, true, 0, "AARON                            Te diria que no lo intentes, pero aya tu."},
									{fals, true, 0, "AARON                            Ningun chico es"},
									{fals, true, 0, "AARON                            bueno para ella."},
									{fals, true, 0, "SCOUT                            Quiza sea inutil intentarlo."},
									{fals, true, 0, "AARON                            Es imposible complacerla."},
									{fals, true, 0, "AARON                            Creeme, la conozco bien."},
									{fals, true, 0, "SCOUT                            {A que te refieres?"},
									{fals, true, 0, "AARON                            Su tipo son los que se creen"},
									{fals, true, 0, "AARON                            muy aca, como mejores de lo"},
									{fals, true, 0, "AARON                            que son. Aunque a decir"},
									{fals, true, 0, "AARON                            verdad. Tambien le he visto"},
									{fals, true, 0, "AARON                            salir con otro tipo de"},
									{fals, true, 0, "AARON                            bobos. {sabes? Quiza solo tengas"},
									{fals, true, 0, "AARON                            que esforzarte un poco en"},
									{fals, true, 0, "AARON                            tener algo mas de confianza"},
									{fals, true, 0, "AARON                            en ti mismo."},
									{fals, true, 0, "SCOUT                            Bueno, eso un buen comienzo."},
									{fals, true, 0, "AARON                            Buena suerte con ella."},
									{fals, true, 0, "SCOUT                            Merci."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 3)
							{
								line lc[32] = {
									{fals, true, 0, "(A lo mejor puedo convencer a    Maple de leer unos comics.)"},
									{fals, true, 0, "(Entonces asi podriamos tener    algo en comun.)"},
									{fals, true, 0, "(...Pero eso no pasara ni en mil a[os.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 7)
							{
								line lc[32] = {
									{fals, true, 0, "GUY                              {Te gustan los Time Raiders?"},
									{fals, true, 0, "SCOUT                            Si, un poco."},
									{fals, true, 0, "GUY                              {Cada cuando consigues los nuevos?"},
									{fals, true, 0, "SCOUT                            Diana los manda a traer cada semana."},
									{fals, true, 0, "GUY                              Que bueno, pense que ya no los podria"},
									{fals, true, 0, "GUY                              leer despues que me mude aqui."},
									{fals, true, 0, "SCOUT                            Aunque si que hay una lista larga de espera."},
									{fals, true, 0, "SCOUT                            Tendras que esperar a que Enoki"},
									{fals, true, 0, "SCOUT                            los termine, a ella le gustan tambien."},
									{fals, true, 0, "GUY                              Nah, yo los voy a agarrar primero."},
									{fals, true, 0, "SCOUT                            Eyy, eso tomalo con ella."},
									{fals, true, 0, "GUY                              Eso hare."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else
							{
								line lc[32] = {
									{fals, true, 0, "(Los comics del mes pasado       siguen tirados en el suelo.)"},
									{fals, true, 0, "(Lentamente acumulando polvo.)"},
									{true, true, 00, "COM: Endscene"}};
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
									{fals, true, 0, "SCOUT                            Oye, ten mucho cuidado con"},
									{fals, true, 0, "SCOUT                            mi computadora, es cara."},
									{fals, true, 0, "MAPLE                            No la iba a tocar. Aunque"},
									{fals, true, 0, "MAPLE                            Ahora me da tentacion..."},
									{fals, true, 0, "SCOUT                            }No, para por favor!"},
									{fals, true, 0, "MAPLE                            }Calmate, no la iba a tocar!"},
									{fals, true, 0, "MAPLE                            Estos raros y sus juguetes..."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 1)
							{
								line lc[32] = {
									{fals, true, 0, "ENOKI                            Oye Scout, {tienes pagina web?"},
									{fals, true, 0, "SCOUT                            }Si! Pero no es tan buena."},
									{fals, true, 0, "ENOKI                            {Me dejas verla?"},
									{fals, true, 0, "SCOUT                            Ahorita no, esque... no la he    terminado."},
									{fals, true, 0, "ENOKI                            Chales, okay."},
									{fals, true, 0, "ENOKI                            Quisiera tener tambien una paginaweb."},
									{fals, true, 0, "ENOKI                            Se ve muy divertido."},
									{fals, true, 0, "SCOUT                            }Te aseguro que lo es!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 2)
							{
								line lc[32] = {
									{fals, true, 0, "AARON                            {Has oido hablar del efecto 2000?"},
									{fals, true, 0, "SCOUT                            Por supuesto."},
									{fals, true, 0, "AARON                            {A ti te ocurrio algo?"},
									{fals, true, 0, "SCOUT                            si, pero nada de lo ordinario."},
									{fals, true, 0, "SCOUT                            Hubo una falla bien  "},
									{fals, true, 0, "SCOUT                            rara en uno de los programas."},
									{fals, true, 0, "SCOUT                            Tenia un programa para organizar"},
									{fals, true, 0, "SCOUT                            compras y a[adio muchos"},
									{fals, true, 0, "SCOUT                            abrillantadores a la lista, y    serian para"},
									{fals, true, 0, "SCOUT                            la fecha 5 de Marzo, 192000."},
									{fals, true, 0, "AARON                            Es un poco la espera."},
									{fals, true, 0, "SCOUT                            Error en la fecha? entiendo."},
									{fals, true, 0, "SCOUT                            Pero extra cosas? Quisiera       evitar."},
									{fals, true, 0, "SCOUT                            Estas fallas son realmente       extra[as."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 3)
							{
								line lc[32] = {
									{fals, true, 0, "(Me gradue como el mejor de la   clase con un promedio de 3.98.)"},
									{fals, true, 0, "(Ahora soy un cientifico viviendode una donacion corporativa.)"},
									{fals, true, 0, "(Tengo un Computadora Castor 5000de ultima generacion.)"},
									{fals, true, 0, "(Que no puedo utilizar porque    olvide mi propia contrase[a.)"},
									{fals, true, 0, "(Me cuesta dormir por las        noches pensando en ello...)"},
									{true, true, 00, "COM: Endscene"}};
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
									{fals, true, 0, "(Esto parece muy caro...)"},
									{fals, true, 0, "(No deberia de tocarlo.)"},
									{true, true, 00, "COM: Endscene"}};
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
									{true, true, 0, "MAPLE                            }Oh! Bonjour, {quien eres?"},
                                    {true, true, 0, "SCOUT                            {Es usted Maple Tremblay?"},
                                    {true, true, 0, "SCOUT                            Me llamo Scout Williams."},
                                    {true, true, 0, "MAPLE                            Tu, ehm, {Estas viviendo en"},
                                    {true, true, 0, "MAPLE                            ese agujero bajo tierra?"},
                                    {true, true, 0, "SCOUT                            Si, yo... e- es un secreto."},
                                    {true, true, 0, "SCOUT                            No seras del tipo de personas"},
                                    {true, true, 0, "SCOUT                            que comparten secretos, {no?"},
                                    {true, true, 0, "MAPLE                            Yo-"},
                                    {true, true, 0, "SCOUT                            Una empresa me contrato para"},
                                    {true, true, 0, "SCOUT                            investigar el suelo de la isla,"},
                                    {true, true, 0, "SCOUT                            pero entonces... se olvidaron de mi."},
                                    {true, true, 0, "SCOUT                            Aunque todavia recibo mi paga."},
                                    {true, true, 0, "SCOUT                            Asi que no veo razon para irme."},
                                    {true, true, 0, "MAPLE                            {Te pagan por no hacer nada?"},
                                    {true, true, 0, "SCOUT                            Me siento un poco solo aqui."},
                                    {true, true, 0, "SCOUT                            Me alegra que hayas venido con"},
                                    {true, true, 0, "SCOUT                            tu familia, hablaban acerca de un"},
                                    {true, true, 0, "SCOUT                            'nuevo pais' o algo por el       estilo, pero"},
                                    {true, true, 0, "SCOUT                            dijeron que podia convertirme en "},
                                    {true, true, 0, "SCOUT                            Se[or, duque, o algo asi."},
                                    {true, true, 0, "SCOUT                            Yo les conteste que si me dejan  ser"},
                                    {true, true, 0, "SCOUT                            el mago de la corte, me sirve"},
                                    {true, true, 0, "SCOUT                            mas que ninguna otra cosa."},
                                    {true, true, 0, "MAPLE                            Si, definitivamente te pegaria   eso."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 1)
							{
								line lc[32] = {
									{true, true, 0, "SCOUT                            }Buenas, Enoki!"},
									{true, true, 0, "ENOKI                            }Hola, Scout!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 2)
							{
								line lc[32] = {
									{true, true, 0, "SCOUT                            }Buenas, Aaron!"},
									{true, true, 0, "AARON                            }Hola, Scout!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 3)
							{
								line lc[32] = {
									{fals, true, 0, "(Esta formula verde hace que las plantas crezcan enormes.)"},
									{fals, true, 0, "(Me pregunto que pasaria si la   usara yo...)"},
									{fals, true, 0, "(Tal vez podria tener poderes...)"},
									{fals, true, 0, "(O tal vez me muera.)"},
									{fals, true, 0, "(Pero definitivamente podria     valer la pena intentarlo...)"},
									{true, true, 00, "COM: Endscene"}};
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
									{fals, true, 0, "SCOUT                            }Cuidado!"},
									{fals, true, 0, "SCOUT                            }Muchas de estas cosas son"},
									{fals, true, 0, "SCOUT                            MORTALMENTE TOXICAS!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 4)
							{
								line lc[32] = {
									{fals, true, 0, "SCOUT                            }Bonjour! {Eres Olivier?"},
									{fals, true, 0, "OLIVIER                          }Oui! {Y tu eres Scout, no?"},
									{fals, true, 0, "SCOUT                            En efecto, soy yo. }Bienvenido!"},
									{fals, true, 0, "OLIVIER                          }Todo este lugar es increible!"},
									{fals, true, 0, "SCOUT                            He sido sincero en el anuncio."},
									{fals, true, 0, "OLIVIER                          {Eres un cientifico?"},
									{fals, true, 0, "SCOUT                            Podria decir que lo soy."},
									{fals, true, 0, "SCOUT                            Aunque hago un poco de todo."},
									{fals, true, 0, "OLIVIER                          {Y vives bajo tierra?"},
									{fals, true, 0, "SCOUT                            Tengo una maquina que excava"},
									{fals, true, 0, "SCOUT                            bunkers con mucha facilidad."},
									{fals, true, 0, "SCOUT                            Podria seguir excavando"},
									{fals, true, 0, "SCOUT                            todo lo que quisiera."},
									{fals, true, 0, "OLIVIER                          }Que padre! Oye, {vas a venir"},
									{fals, true, 0, "OLIVIER                          a cenar a la casa de Tremblay?"},
									{fals, true, 0, "SCOUT                            }Por supuesto!"},
									{fals, true, 0, "OLIVIER                          }Okay! Nos vemos ahi entonces."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 5)
							{
								line lc[32] = {
									{fals, true, 0, "ELEANOR                          }Bonjour, monsieur!"},
									{fals, true, 0, "SCOUT                            }Bonjour! {Eres Eleanor?"},
									{fals, true, 0, "ELEANOR                          }Oui! Encantada de conocerte."},
									{fals, true, 0, "ELEANOR                          }Este lugar esta padrisimo!"},
									{fals, true, 0, "SCOUT                            He sido sincero en el anuncio."},
									{fals, true, 0, "ELEANOR                          {Eres un mago?"},
									{fals, true, 0, "SCOUT                            Podria decir que lo soy."},
									{fals, true, 0, "SCOUT                            Aunque hago un poco de todo."},
									{fals, true, 0, "ELEANOR                          {Y vives bajo tierra?"},
									{fals, true, 0, "SCOUT                            Tengo una maquina que excava"},
									{fals, true, 0, "SCOUT                            bunkers con mucha facilidad."},
									{fals, true, 0, "SCOUT                            Podria seguir excavando"},
									{fals, true, 0, "SCOUT                            todo lo que quisiera."},
									{fals, true, 0, "ELEANOR                          }Que fascinante!"},
									{fals, true, 0, "SCOUT                            Aw, }merci!"},
									{fals, true, 0, "ELEANOR                          {Te veo luego en la cena?"},
									{fals, true, 0, "SCOUT                            }Claro!"},
									{fals, true, 0, "ELEANOR                          }Maravilloso!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else if (me == 6)
							{
								line lc[32] = {
									{fals, true, 0, "DIANA                            }Bonjour! Hola, {eres Scout?"},
									{fals, true, 0, "SCOUT                            }Bonjour! {eres Diana?"},
									{fals, true, 0, "DIANA                            }Oui! }Es un placer conocerte!"},
									{fals, true, 0, "DIANA                            Wow, este lugar es fascinante."},
									{fals, true, 0, "SCOUT                            He sido sincero en el anuncio."},
									{fals, true, 0, "DIANA                            {Eres cientifico o algo asi?"},
									{fals, true, 0, "SCOUT                            Podria decir que lo soy."},
									{fals, true, 0, "SCOUT                            Aunque hago un poco de todo."},
									{fals, true, 0, "DIANA                            {Y vives bajo tierra?"},
									{fals, true, 0, "SCOUT                            Tengo una maquina que excava"},
									{fals, true, 0, "SCOUT                            bunkers con suma facilidad."},
									{fals, true, 0, "SCOUT                            Podria seguir excavando"},
									{fals, true, 0, "SCOUT                            todo lo que quisiera."},
									{fals, true, 0, "DIANA                            }Que padre!"},
									{fals, true, 0, "SCOUT                            }Merci!"},
									{fals, true, 0, "DIANA                            {Vienes a cenar?"},
									{fals, true, 0, "SCOUT                            }Claro!"},
									{fals, true, 0, "DIANA                            }Genial!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else
							{
								line lc[32] = {
									{fals, true, 0, "(Ojala pudiera hacer algo que me hiciera feliz.)"},
									{fals, true, 0, "(Despues de pasar tanto tiempo   estudiando, aqui estoy...)"},
									{fals, true, 0, "(Y no se. Paso de una cosa a     otra.)"},
									{fals, true, 0, "(No puedo hacer algo sin querer  dejarlo a medias en el camino.)"},
									{fals, true, 0, "(Por esta vez, quisiera ser felizdonde estoy ahora.)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
						}
						else if (globals->current_save->checkpoint < 12)
						{
							if (me < 7)
							{
								line lc[32] = {
									{fals, true, 0, "SCOUT                            }Cuidado!"},
									{fals, true, 0, "SCOUT                            }Muchas de estas cosas son"},
									{fals, true, 0, "SCOUT                            MORTALMENTE TOXICAS!"},
									{fals, true, 0, "SCOUT                            Aunque bueno, tu ya sabias eso."},
									{fals, true, 0, "SCOUT                            O al menos, eso espero."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
							else
							{
								line lc[32] = {
									{fals, true, 0, "SCOUT                            }Bonjour! Eres Guy, {no es asi?"},
									{fals, true, 0, "GUY                              Oui. Y tu eres, Scout. {Cierto?"},
									{fals, true, 0, "SCOUT                            }Bienvenu! {Te gusta tu caba[a?"},
									{fals, true, 0, "GUY                              No bromeabas con eso que dijiste"},
									{fals, true, 0, "GUY                              acerca de la cocina, {eh?"},
									{fals, true, 0, "SCOUT                            }En absoluto!"},
									{fals, true, 0, "GUY                              Parece que no hay muchas personas"},
									{fals, true, 0, "GUY                              por aqui, y sabes que no voy"},
									{fals, true, 0, "GUY                              a poder cocinar mucha comida"},
									{fals, true, 0, "GUY                              si no tengo clientes."},
									{fals, true, 0, "GUY                              {Cuanto tiempo crees que va pasar"},
									{fals, true, 0, "GUY                              hasta que se llene esto de gente?"},
									{fals, true, 0, "SCOUT                            No deberia pasar tanto tiempo."},
									{fals, true, 0, "GUY                              {Y puedo confiar en eso?"},
									{fals, true, 0, "SCOUT                            Sans doute."},
									{fals, true, 0, "GUY                              Tres bien alors."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}
						}
						else if (globals->current_save->checkpoint == 12)
						{
							globals->current_save->checkpoint = 13;
							line lc[32] = {
								{fals, true, 0, "ENOKI                            {Salut? Scout, {estas aqui abajo?"},
								{fals, true, 0, "SCOUT                            }Si! }Estoy aqui! {Donde se ha   metido Aaron?"},
								{fals, true, 0, "ENOKI                            Ha salido para ver como estan    los demas."},
								{fals, true, 0, "SCOUT                            Menos mal. Hey, Maple. {Te       sientes bien?"},
								{fals, true, 0, "SCOUT                            Te vez cansada."},
								{fals, true, 0, "MAPLE                            {Que tal si cierras el pico?     {Como no voy a estarlo?"},
								{fals, true, 0, "MAPLE                            Despues de TODO lo que ha pasado esta ma[ana."},
								{fals, true, 0, "SCOUT                            Oh- Esta bien..."},
								{fals, true, 0, "SCOUT                            Hey Enoki, {como luce todo por   aqui?"},
								{fals, true, 0, "ENOKI                            Bien, es solo que... Hay un      ruido extra[o y fuerte."},
								{fals, true, 0, "ENOKI                            Aaron se asusto y quiso que nos  mantuvieramos a salvo."},
								{fals, true, 0, "SCOUT                            Confio en su intuicion."},
								{true, true, 00, "COM: Endscene"}};
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
									{fals, true, 0, "AARON                            {Que diablos esta pasando ahi    fuera?"},
									{fals, true, 0, "SCOUT                            Es Rufus. Creo que se comio algo raro."},
									{fals, true, 0, "ENOKI                            Jeje, tambien me pasa despues de comer la comida de Guy."},
									{fals, true, 0, "SCOUT                            No, puede ser algo serio. Tiene  que ver con mi investigacion."},
									{fals, true, 0, "AARON                            Oh, {asi que el cientifico va a  revelarnos lo que ha estado  "},
									{fals, true, 0, "AARON                            haciendo en ese misterioso bunkerdurante los ultimos meses?"},
									{fals, true, 0, "SCOUT                            Estudio la tierra...             y las plantas."},
									{fals, true, 0, "ENOKI                            }No me digas!"},
									{fals, true, 0, "OLIVIER                          {Y por que no me lo dijiste?"},
									{fals, true, 0, "SCOUT                            No podia, es confidencial."},
									{fals, true, 0, "SCOUT                            Veras, resulta que esta planta...crece nativamente en estas"},
									{fals, true, 0, "SCOUT                            islas, y muchas personas dicen   que es magica. Puede"},
									{fals, true, 0, "SCOUT                            hacerte tener visiones."},
									{fals, true, 0, "ENOKI                            {Como los hongos alucinogenos?"},
									{fals, true, 0, "SCOUT                            Los hongos hacen que las personastengan distintas visiones. Pero"},
									{fals, true, 0, "SCOUT                            esta flor hace que todos tengan  la misma. Por eso la estamos"},
									{fals, true, 0, "SCOUT                            investigando. No es nada mas el  viaje que ves, sino"},
									{fals, true, 0, "SCOUT                            es algo mas que pasa."},
									{fals, true, 0, "SCOUT                            Aunque todos vean lo mismo, cada uno reacciona diferente pero no es debido    "},
									{fals, true, 0, "SCOUT                            a un desequilibrio quimico.      Sus visiones son tan"},
									{fals, true, 0, "SCOUT                            preocupantes y devastadoras, que provocan que  "},
									{fals, true, 0, "SCOUT                            aquellos que la toman, regresen  como una persona diferente ."},
									{fals, true, 0, "ELEANOR                          {Y que es lo que ven?"},
									{fals, true, 0, "SCOUT                            No se sabe. Los afectados        prefieren guardar silencio."},
									{fals, true, 0, "SCOUT                            Las personas que la consumen     muestran una aureola de color azul en los"},
									{fals, true, 0, "SCOUT                            ojos. No parecen durar por       siempre, pero son notorios  "},
									{fals, true, 0, "SCOUT                            por un tiempo. Estuve mirando    las grabaciones de Rufus,    "},
									{fals, true, 0, "SCOUT                            y como suponia... padece los     efectos de las aureolas azules."},
									{fals, true, 0, "AARON                            {Entonces se ha convertido en    supervillano o algo asi?    "},
									{fals, true, 0, "SCOUT                            No lo se. Rufus no es muy...     grande, {sabes? Puede que-"},
									{fals, true, 0, "AARON                            Qu'est-ce qui se passe la-bas?"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}

							if (true)
							{
								bn::sound_items::knock.play();
								line lc[32] = {
									{fals, true, 0, "SCOUT                            Uhh.... Creo que hay algo en la  puerta."},
									{fals, true, 0, "AARON                            Tengo mi hacha."},
									{fals, true, 0, "SCOUT                            Oigan, les dire algo. {Saben     acerca de la excavadora"},
									{fals, true, 0, "SCOUT                            de bunkers que tengo?"},
									{fals, true, 0, "AARON                            {Si...?"},
									{fals, true, 0, "SCOUT                            Les dire que podemos hacer. {Y siexcavamos un tunel que nos"},
									{fals, true, 0, "SCOUT                            lleve fuera de la isla? De       todas formas ya planeaba hacer"},
									{fals, true, 0, "SCOUT                            uno hasta la orilla."},
									{fals, true, 0, "SCOUT                            (Queria guardarme esto para la   Scout Expo, pero, uh...)"},
									{fals, true, 0, "SCOUT                            (No es como si tuvieramos muchas opciones ahorita.)"},
									{fals, true, 0, "ELEANOR                          {Es seguro?"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
							}

							if (true)
							{
								bn::sound_items::knock.play();
								bn::sound_items::boom.play();

								line lc[3] = {
									{fals, true, 0, "SCOUT                            Saben ya vamonos."},
									{fals, true, 0, "ENOKI                            {Allons-y?"},
									{true, true, 00, "COM: Endscene"}};
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
							{fals, true, 0, "Observas la obra de arte.                                         Es bueno.       No me importa. ", 2},
							{fals, true, 0, "Y por lo tanto...."},
							{fals, true, 0, "La obra de arte te observa a ti."},
							{fals, true, 0, "El arte es extra[o."},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};

					case 41:
					{
						line lc[5] = {
							{fals, true, 0, "- MAS CASAS POR ESTE CAMINO -"},
							{true, true, 00, "COM: Endscene"}};
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
								{fals, true, 0, "MAPLE                            Tal vez deberia ir a lo de Scout."},
								{true, true, 00, "COM: Endscene"}};
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
							{fals, true, 0, " - LA PRESA DE LOS DESEOS -      NO FUNCIONA PERO LA PUEDES USAR  SI QUIERES"},
							{fals, true, 0, "Las rocas en el camino no te     dejan ver la vista asombrosa."},
							{fals, true, 0, "Si pudieras subir las rocas,     podrias lanzar una moneda para   pedir un deseo."},
							{fals, true, 0, "Se podria haber planeado mejor   lo de la presa."},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};

					case 45:
					{
						line lc[5] = {
							{true, true, 00, " - LE MAISON DE LANDRY -"},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};
					case 46:
					{
						line lc[5] = {
							{true, true, 00, " - DIANA -"},
							{fals, true, 0, "No sabria decir si ese es el     nombre de la due[a o de la casa."},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};

					// Guy's house signage
					case 47:
					{
						if (globals->current_save->checkpoint < 10)
						{
							line lc[5] = {
								{fals, true, 0, "- CASA DE ALGUIEN -"},
								{fals, true, 0, "Como puedes ver, por ahora esta  deshabitada."},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else
						{
							line lc[5] = {
								{fals, true, 0, "- CASA DE GUY -"},
								{true, true, 00, "COM: Endscene"}};
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
							{true, true, 00, "~ JARGINS NOIRS ~"},
							{true, true, 00, "COM: Endscene"}};
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
									{fals, true, 0, "MAPLE                            Oh, hey. {Eres Eleanor?"},
									{fals, true, 0, "ELEANOR                          }Oui! Enchante de faire votre    connaissance."},
									{fals, true, 0, "MAPLE                            Egalement. No querria ofenderte, pero pareces..."},
									{fals, true, 0, "MAPLE                            {Un poco anticuada?"},
									{fals, true, 0, "ELEANOR                          Oh, es a lo que acostumbramos."},
									{fals, true, 0, "ELEANOR                          Se siente genial volver a"},
									{fals, true, 0, "ELEANOR                          estar alejada de la gran ciudad. Olvide la"},
									{fals, true, 0, "ELEANOR                          nostalgia que tengo por los      arboles."},
									{fals, true, 0, "MAPLE                            Ya veo. Y tu eres su esposo,     {j'suppose?"},
									{fals, true, 0, "OLIVIER                          Oui, soy Olivier."},
									{fals, true, 0, "ELEANOR                          Aunque sea muy reservado, es     alguien muy atento."},
									{fals, true, 0, "ELEANOR                          Lo conoci en un jardin y me      ense[o a leer."},
									{fals, true, 0, "OLIVIER                          Ella es muy especial para mi.    Practicamente salvo mi vida."},
									{fals, true, 0, "MAPLE                            Oh, {como fue eso?"},
									{fals, true, 0, "OLIVIER                          No es algo importante-"},
									{fals, true, 0, "ELEANOR                          Por mi madre."},
									{fals, true, 0, "MAPLE                            Ah, ya tengo la idea, je."},
									{fals, true, 0, "ELEANOR                          {En serio? Iba a drenar toda su  sangre para un ritual."},
									{fals, true, 0, "MAPLE                            Yo... Hmm, bueno, vaya.          Eso... no era lo que esperaba."},
									{fals, true, 0, "MAPLE                            {Supongo? Encantada de           conocerlos,"},
									{fals, true, 0, "ELEANOR                          }Bien sur! Estoy horneando un paypara ustedes como 'merci'."},
									{fals, true, 0, "MAPLE                            C'est bon, nada mas sin          ingredientes raros. Jaja."},
									{fals, true, 0, "MAPLE                            (}{En que pensaba Scout invitandoa estos raritos?!)"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 1:
							{
								line lc[32] = {
									{fals, true, 0, "ENOKI                            }Sed bienvenue! }Je suis Enoki!  Ravie de vous autres rencontrer."},
									{fals, true, 0, "ELEANOR                          }Bonjour! Enchante de faire votreconnaissance."},
									{fals, true, 0, "OLIVIER                          }Bonjour!"},
									{fals, true, 0, "ELEANOR                          Soy Eleanor, y el es mi esposo   Olivier."},
									{fals, true, 0, "ENOKI                            }Tu vestido es hermoso!          {Donde lo compraste?"},
									{fals, true, 0, "ELEANOR                          }Oh! Yo lo hice. }Tambien  me    gusta mucho el tuyo!"},
									{fals, true, 0, "ENOKI                            }Que padre!"},
									{fals, true, 0, "ENOKI                            Creo que somos de la misma talla,}podriamos hacer cambios!"},
									{fals, true, 0, "OLIVIER                          Scout dijo que eres de la        realeza."},
									{fals, true, 0, "ENOKI                            }Oh, si! Este es nuestro peque[o reino, pero no somos despotas."},
									{fals, true, 0, "ENOKI                            Soy la reina mas tranquila y     amigable que hayas conocido."},
									{fals, true, 0, "ENOKI                            {Quisieran ser duque y duquesa?"},
									{fals, true, 0, "ELEANOR                          Yo... no, gracias. Ni siquiera selo que esos titulos significan."},
									{fals, true, 0, "OLIVIER                          Merci, en tout cas."},
									{fals, true, 0, "ENOKI                            }Bien sur! }N'importe quand!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 2:
							{
								line lc[32] = {
									{fals, true, 0, "AARON                            }Bienvenu! {Olivier y Eleanor,   verdad?"},
									{fals, true, 0, "ELEANOR                          }Oui oui!"},
									{fals, true, 0, "OLIVIER                          {Es usted el 'rey' de esta isla?"},
									{fals, true, 0, "AARON                            {Scout te dijo eso? Supongo que  podria decir que si lo soy."},
									{fals, true, 0, "AARON                            Nunca me gradue de la prepa, asi que no estoy hecho para otra"},
									{fals, true, 0, "AARON                            cosa que no sea el trabajo como  este, pero no queria pasar la"},
									{fals, true, 0, "AARON                            vida en una fabrica. Mi esposa,  Enoki, y yo, tuvimos la idea de"},
									{fals, true, 0, "AARON                            adquirir tierras para vivir como se nos plazca. Lo de la 'realeza'"},
									{fals, true, 0, "AARON                            fue idea suya. No pude evitar    decir que si."},
									{fals, true, 0, "AARON                            Seguramente ella ya les ofrecio  un rol de aristocrates."},
									{fals, true, 0, "OLIVIER                          Oh, Aaron, {no es asi? Gracias   hacer espacio para el"},
									{fals, true, 0, "OLIVIER                          invernadero. Ahora podre         compartir lo que plante ahi."},
									{fals, true, 0, "ELEANOR                          }Y me encanta esta caba[a! De    cierta manera me recuerda a casa."},
									{fals, true, 0, "ELEANOR                          Vee y yo estabamos emocionados deescuchar sobre la isla."},
									{fals, true, 0, "AARON                            }Pues a nosotros nos alegra muchoque hayan venido!"},
									{fals, true, 0, "AARON                            Si mi hermana peque[a los hace   pasar un mal rato..."},
									{fals, true, 0, "AARON                            Les prometo que ella es asi y    no lo hace a proposito."},
									{fals, true, 0, "AARON                            Pasen por el remolque por la     noche, tendre comida preparada."},
									{fals, true, 0, "OLIVIER                          Encore une fois, je vous remerciesincerement."},
									{fals, true, 0, "AARON                            Ahora somos una familia, esta es su casa."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 3:
							{
								line lc[32] = {
									{fals, true, 0, "SCOUT                            }Hola todos! Soy Scout,          {de internet?"},
									{fals, true, 0, "OLIVIER                          }Ah! Enchante de faire votre     connaissance."},
									{fals, true, 0, "ELEANOR                          Oh... Pero la foto que tienes en tu perfil, pense que tu eras..."},
									{fals, true, 0, "SCOUT                            {Que yo era que?"},
									{fals, true, 0, "ELEANOR                          Pense que eras un esqueleto."},
									{fals, true, 0, "SCOUT                            Oh, esa solo es una foto de un   personaje que me gusta."},
									{fals, true, 0, "SCOUT                            Es un esqueleto de un comic      llamado Seemore."},
									{fals, true, 0, "SCOUT                            Tiene poderes magicos, tal vez   pueda prestarte el comic."},
									{fals, true, 0, "SCOUT                            Te aseguro que es muy divertido  e interesante."},
									{fals, true, 0, "ELEANOR                          {Que es un comic?"},
									{fals, true, 0, "SCOUT                            Yo... Nunca pense que tendria    que responder a una pregunta"},
									{fals, true, 0, "SCOUT                            como esa. Son como los libros    pero tienen imagenes y-"},
									{fals, true, 0, "ELEANOR                          }Eso suena genial!"},
									{fals, true, 0, "OLIVIER                          Eleanor se crio en una secta,    por lo que no sabe mucho del"},
									{fals, true, 0, "OLIVIER                          mundo exterior. Esa es una de    las razones por las que quisimos"},
									{fals, true, 0, "OLIVIER                          mudarnos aqui, para descansar un poco de su familia.        "},
									{fals, true, 0, "SCOUT                            Dios mio. Bueno pues bienvenida ala isla."},
									{fals, true, 0, "SCOUT                            La reina Enoki sigue de leer el ultimo Time Raiders,"},
									{fals, true, 0, "SCOUT                            pero cuando termine de leerlo, telo prestare para que lo leas."},
									{fals, true, 0, "ELEANOR                          }}Merci!!"},
									{true, true, 00, "COM: Endscene"}};
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
									{fals, true, 0, "OLIVIER                          Eleanor, {por que prendiste la   estufa? {que no ibamos a comer con"},
									{fals, true, 0, "OLIVIER                          los Tremblay esta noche?"},
									{fals, true, 0, "ELEANOR                          Oh, si si, pero no pude evitarlo."},
									{fals, true, 0, "ELEANOR                          No he visto algo asi desde que   era muy peque[a."},
									{fals, true, 0, "ELEANOR                          Asi que queria hacer unas        tostadas."},
									{fals, true, 0, "OLIVIER                          {Que opinas de este lugar?"},
									{fals, true, 0, "OLIVIER                          No hay muchas personas, {no vas  a sentirte un poco sola?"},
									{fals, true, 0, "ELEANOR                          {Y tu? {Crees que vas a sentirte solo aqui?"},
									{fals, true, 0, "OLIVIER                          Me gustaria que mi abuelo nos    pudiera ver ahora."},
									{fals, true, 0, "OLIVIER                          Creo que el estaria muy orgullosode ti."},
									{fals, true, 0, "ELEANOR                          Puede que nos vea desde el cielo junto a mi madre."},
									{fals, true, 0, "ELEANOR                          Quiza ella ha cambiado alli y    ahora piense bien de ti."},
									{fals, true, 0, "OLIVIER                          Supongo que no lo podremos saber pero no estoy solo ahora."},
									{fals, true, 0, "OLIVIER                          No me he sentido solo desde que  tu estas conmigo."},
									{fals, true, 0, "ELEANOR                          Vee, espero que nunca dejemos de sentirnos asi."},
									{fals, true, 0, "ELEANOR                          He visto como son mis padres     ahora y siento que me hago"},
									{fals, true, 0, "ELEANOR                          mayor. Se que cuando tengamos    nuestros hijos..."},
									{fals, true, 0, "OLIVIER                          {Como esta tu hermana?"},
									{fals, true, 0, "ELEANOR                          Esta siempre cansada. Bromea     sobre sus canas, pero creo"},
									{fals, true, 0, "ELEANOR                          que le gusta tener el pelo       blanco. Es diferente a los demas."},
									{fals, true, 0, "ELEANOR                          Las cosas que le molestaban, ya  no tienen sentido."},
									{fals, true, 0, "OLIVIER                          A lo mejor va a pasar lo mismo   con nosotros. Haber que nos espera el futuro."},
									{fals, true, 0, "ELEANOR                          Sera extra[o tener amigos de     nuestra edad casados. {No crees que"},
									{fals, true, 0, "ELEANOR                          Diana podria ponerse celosa?"},
									{fals, true, 0, "OLIVIER                          Creo que ella se lo pasara bien  aqui. S'il te plait detends-toi!"},
									{fals, true, 0, "ELEANOR                          Je suppose que tu as raison, Vee."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 6:
							{
								line lc[32] = {
									{fals, true, 0, "DIANA                            Aw, }genial! Me encanta este     lugar, es muy acogedor."},
									{fals, true, 0, "DIANA                            Espero que no les importe que    quiera pasar mucho tiempo aqui."},
									{fals, true, 0, "ELEANOR                          }Por supuesto que no! Mientras   no te importe ayudarnos a veces."},
									{fals, true, 0, "OLIVIER                          Recuerda, vivir asi significa    que tendremos que trabajar duro."},
									{fals, true, 0, "OLIVIER                          Es probable que tenga que dedicarmucho tiempo a cortar le[a, o a"},
									{fals, true, 0, "OLIVIER                          trabajar en el jardin regando y  quitando las malas hierbas."},
									{fals, true, 0, "ELEANOR                          {No te interesaba trabajar       para el capitan del barco?"},
									{fals, true, 0, "DIANA                            Oh, si. De hecho hoy pasare por  el muelle."},
									{fals, true, 0, "DIANA                            }Sere capitana del barco antes   de que se den cuenta!"},
									{fals, true, 0, "ELEANOR                          }Se que podras con todo lo que   te propongas, Diana!"},
									{fals, true, 0, "OLIVIER                          Esto no es lo que pensabas que   harias a tus 22 a[os, {eh?"},
									{fals, true, 0, "DIANA                            Bueno, tampoco es como si supieraque hubiera hecho."},
									{fals, true, 0, "DIANA                            Mudarse a una isla es algo       inesperado para todos. {No?"},
									{fals, true, 0, "OLIVIER                          Yo pense que pasaria el resto de mi vida trabajando en el jardin."},
									{fals, true, 0, "ELEANOR                          Pues yo sigo viva y Vee esta con nosotros, no puedo pedir mas."},
									{fals, true, 0, "DIANA                            Si... Espero que las cosas sigan asi de bien por mucho tiempo."},
									{true, true, 00, "COM: Endscene"}};
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
									{fals, true, 0, "MAPLE                            Salut, chicos."},
									{fals, true, 0, "ELEANOR                          }Salut, Maple! {Quieres un poco  de guisado? Acaba de salir."},
									{fals, true, 0, "MAPLE                            }Eso suena muy bien! Claro que   quiero, tu guiso es fantastico."},
									{fals, true, 0, "OLIVIER                          Diana nos ha traido un juego de  mesa nuevo."},
									{fals, true, 0, "OLIVIER                          {Te gustaria invitar a los demas?"},
									{fals, true, 0, "MAPLE                            {Y ami que? Nah, no pasa nada,   haha."},
									{fals, true, 0, "MAPLE                            Hey, um... Siento mucho lo del   juego de mesa de la semana pasada."},
									{fals, true, 0, "ELEANOR                          No te preocupes, Maple. Es facil enojarse cuando estamos jugando."},
									{fals, true, 0, "MAPLE                            Aunque tu caba[a ya ha dejado de oler a humo."},
									{fals, true, 0, "ELEANOR                          {Has probado el nuevo gumbo      isle[o?"},
									{fals, true, 0, "MAPLE                            {Me preguntas que si me asusta?  Nah, no mucho."},
									{fals, true, 0, "MAPLE                            Sea como sea, no es nada que el  tabasco extra no pueda arreglar."},
									{fals, true, 0, "MAPLE                            Se que no los veo todo el        tiempo..."},
									{fals, true, 0, "MAPLE                            Pero les quiero dar las gracias  por los ingredientes. Son unos santos."},
									{fals, true, 0, "OLIVIER                          Gracias por tu duro trabajo.     No tenia todas mis esperanzas"},
									{fals, true, 0, "OLIVIER                          puestas en que todo esto de la   isla iba a funcionar."},
									{fals, true, 0, "OLIVIER                          Es casi como si tuvieras un      amuleto de la buena suerte."},
									{fals, true, 0, "MAPLE                            Si... Lo que Enoki quiera es lo  que conseguira."},
									{fals, true, 0, "MAPLE                            Es solo cuestion de tiempo que   algo le salga mal, no logre"},
									{fals, true, 0, "MAPLE                            lo que quiere y se ponga         berrinchuda, ya que."},
									{fals, true, 0, "OLIVIER                          Ya veo. Bueno, si necesitas algo dejanos saber."},
									{fals, true, 0, "MAPLE                            }Igual!."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 1:
							{
								line lc[32] = {
									{fals, true, 0, "ENOKI                            }}Salut!! {Como les va hoy?"},
									{fals, true, 0, "ELEANOR                          }Estamos muy bien! {Quieres      algo de guiso?"},
									{fals, true, 0, "ENOKI                            Mentiria si diria que no, jeje."},
									{fals, true, 0, "OLIVIER                          {Vendras a jugar esta noche?"},
									{fals, true, 0, "ENOKI                            }No me lo perderia por nada del  mundo!"},
									{fals, true, 0, "ELEANOR                          {Has conocido ya al nuevo isle[o?"},
									{fals, true, 0, "ENOKI                            No le digas nada a Maple..."},
									{fals, true, 0, "ENOKI                            pero creo que su gumbo es mejor  que el de ella."},
									{fals, true, 0, "ENOKI                            Prometeme que no le diras a      Maple."},
									{fals, true, 0, "ELEANOR                          Mis labios estan sellados."},
									{fals, true, 0, "ENOKI                            Oye, {Ustedes no tendran una     maquina de coser?"},
									{fals, true, 0, "ELEANOR                          Oui."},
									{fals, true, 0, "ENOKI                            Mencionaste que tu hacias tu     propia ropa, {oui? Tu, eh..."},
									{fals, true, 0, "ENOKI                            {No te importaria ense[arme a    hacer lo mismo que tu?"},
									{fals, true, 0, "ELEANOR                          Pas du tout! Seria un placer     para mi ense[arte lo que se."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 2:
							{
								line lc[32] = {
									{fals, true, 0, "AARON                            }Salut! Escuche algo de noche de juegos?."},
									{fals, true, 0, "ELEANOR                          }Oui! Nos gustaria organizarlo   afuera debajo de un arbol."},
									{fals, true, 0, "ELEANOR                          Hice una colcha suficientemente  grande para que todos quepan."},
									{fals, true, 0, "AARON                            {Sera afuera por si Maple se     enoja otra vez?"},
									{fals, true, 0, "OLIVIER                          Oui, jaja."},
									{fals, true, 0, "ELEANOR                          Tambien hicimos un guisado, por  si quieres comer un poco."},
									{fals, true, 0, "AARON                            Acabo de comer lo que sobro del  gumbo de Maple, }pero merci!"},
									{fals, true, 0, "AARON                            Hablando de comida. Aunque sea   timido, Guy es buena onda."},
									{fals, true, 0, "AARON                            Me encanta que mas personas      lleguen a la isla."},
									{fals, true, 0, "OLIVIER                          Poco a poco esto se convierte    en un autentico pueblo."},
									{fals, true, 0, "AARON                            Si, estaba pensando lo mismo."},
									{fals, true, 0, "OLIVIER                          {Te encuentras bien, Aaron? Te   ves palido."},
									{fals, true, 0, "AARON                            Si, Solo pensaba que Maple y yo  no nos llevamos bien."},
									{fals, true, 0, "OLIVIER                          {A que te refieres?"},
									{fals, true, 0, "AARON                            Ella no quiere mudarse, pero va  a tener que hacerlo."},
									{fals, true, 0, "OLIVIER                          {Y por que no hablas con ella?   {No eres el rey o algo asi?"},
									{fals, true, 0, "AARON                            Podria. Mas bien, deberia. Pero  es dificil lidiar con ella."},
									{fals, true, 0, "AARON                            Dice que esta bien, pero al dia  siguiente..."},
									{fals, true, 0, "AARON                            parece una garrapata."},
									{fals, true, 0, "OLIVIER                          Eso suena como algo que deberias hablar con ella, no nosotros."},
									{fals, true, 0, "AARON                            Es cierto, gracias."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 3:
							{
								line lc[32] = {
									{fals, true, 0, "SCOUT                            }Hola a todos! }Scout ha llegado!"},
									{fals, true, 0, "ELEANOR                          }Salut! {Quieres guisado?"},
									{fals, true, 0, "SCOUT                            Merci, pero comi hace... Espera. {Cuando fue la ultima vez?  "},
									{fals, true, 0, "SCOUT                            Cielos, no he comido en todo el  dia. }Claro que quiero guisado!"},
									{fals, true, 0, "ELEANOR                          Jeje, no hay problema, sirvete   lo que quieras."},
									{fals, true, 0, "SCOUT                            {Has visto el reporte de         Scout TV esta ma[ana?"},
									{fals, true, 0, "ELEANOR                          Oh, no tenemos una television."},
									{fals, true, 0, "SCOUT                            Es verdad... Lo lamento,         olvidalo."},
									{fals, true, 0, "SCOUT                            De todos modos mi transmision fuehackeada."},
									{fals, true, 0, "OLIVIER                          {Hackeada? {Por quien?"},
									{fals, true, 0, "SCOUT                            Ni idea. Los Tremblay no parecen muy preocupados de todas formas."},
									{fals, true, 0, "ELEANOR                          {Vas a venir a jugar con nosotrosesta noche?"},
									{fals, true, 0, "SCOUT                            Tratare de hacerlo, todavia tengocosas que hacer del trabajo."},
									{fals, true, 0, "SCOUT                            Les dejo saber luego si hire."},
									{fals, true, 0, "OLIVIER                          Sin problema, te guardaremos un  lugar por si vienes."},
									{fals, true, 0, "SCOUT                            }Merci!"},
									{fals, true, 0, "ELEANOR                          }De rien!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							// Fall-through to the next bit
							case 4:
							{
								line lc[32] = {
									{fals, true, 0, "..."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 5:
							{
								line lc[32] = {
									{fals, true, 0, "OLIVIER                          Asi que sera tu cumplea[os en unasemana..."},
									{fals, true, 0, "ELEANOR                          {Oui?"},
									{fals, true, 0, "OLIVIER                          Quisiera darte una sorpresa, perono quiero decepcionarte con-"},
									{fals, true, 0, "ELEANOR                          ..."},
									{fals, true, 0, "OLIVIER                          ... {Quieres que te de una       sorpresa?"},
									{fals, true, 0, "OLIVIER                          ..."},
									{fals, true, 0, "OLIVIER                          {Todavia piensas en la ceremonia?"},
									{fals, true, 0, "ELEANOR                          Esa fue una noche que no podre   olvidar jamas."},
									{fals, true, 0, "ELEANOR                          No sabria decirte si me sentiria bien o mal."},
									{fals, true, 0, "ELEANOR                          Ya me has dado todo lo que       quisiera por toda mi vida."},
									{fals, true, 0, "OLIVIER                          Pero no te quejarias si te comprouna nueva maquina de coser."},
									{fals, true, 0, "ELEANOR                          ..."},
									{fals, true, 0, "OLIVIER                          No es como si fuera algo que te  compraria...pero"},
									{fals, true, 0, "ELEANOR                          Acaso no tienes que arreglar las verduras? Necesito empezar"},
									{fals, true, 0, "ELEANOR                          a enlatarlas para el invierno."},
									{fals, true, 0, "OLIVIER                          Okay, Okay, es solo que-...      Bueno, no importa."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 6:
							{
								line lc[32] = {
									{fals, true, 0, "DIANA                            Chicos, tenemos que hablar."},
									{fals, true, 0, "OLIVIER                          {Que ocurre?"},
									{fals, true, 0, "DIANA                            Alguien ha hackeado el canal     de Scout esta ma[ana."},
									{fals, true, 0, "DIANA                            Creo que ha sido un Mons d'Plonj,es una amenaza para la isla."},
									{fals, true, 0, "ELEANOR                          O-Oh.. Oh no.. No tendra nada    que ver con las brujas, {no?"},
									{fals, true, 0, "ELEANOR                          Vee, {no, nos han encontrado,    verdad?"},
									{fals, true, 0, "DIANA                            No, solo parecia un imbecil.     {Parece que Maple lo conoce?"},
									{fals, true, 0, "DIANA                            Los Tremblay no estan            preocupados."},
									{fals, true, 0, "ELEANOR                          Oh... Menos mal..."},
									{fals, true, 0, "DIANA                            {Aunque conoces a ese tal CESAR? {El chico del norte?"},
									{fals, true, 0, "DIANA                            Aunque parece sospechoso, Enoki  confia en el. Tiene una"},
									{fals, true, 0, "DIANA                            tienda o algo asi. Y el otro     chico, Guy, cocina muy bien."},
									{fals, true, 0, "OLIVIER                          Hey, El, calmate, te va a dar un ataque."},
									{fals, true, 0, "ELEANOR                          Lo siento... Lo siento..."},
									{fals, true, 0, "DIANA                            Oye, Eleanor, todo va a estar    bien. {Quieres venir conmigo?"},
									{fals, true, 0, "DIANA                            Podemos relajarnos y comer los   snacks que importe."},
									{fals, true, 0, "DIANA                            Uuu, eso suena genial.           Merci."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 7:
							{
								line lc[32] = {
									{fals, true, 0, "ELEANOR                          }Bonjour! Tu debes ser Guy."},
									{fals, true, 0, "GUY                              Oui. Soy Guy. Guy Pizza."},
									{fals, true, 0, "ELEANOR                          {Guy... Pizza?"},
									{fals, true, 0, "GUY                              El nombre era mas chistoso cuandotrabajaba en la pizzeria."},
									{fals, true, 0, "OLIVIER                          Bueno, de todos modos,           }bienvenido a la isla!"},
									{fals, true, 0, "GUY                              Encantado de conocerlos. Bueno,  tengo que regresar para arreglar mis cosas."},
									{fals, true, 0, "GUY                              Siempre he querido una cocina    grande y voy a hacer"},
									{fals, true, 0, "GUY                              buen uso de ella, ya veras."},
									{fals, true, 0, "ELEANOR                          Vamos a jugar a un juego de mesa esta noche."},
									{fals, true, 0, "ELEANOR                          {Te gustaria venir con nosotros?"},
									{fals, true, 0, "GUY                              Me encantaria, pero ahorita estoymuy emocionado por la cosina."},
									{fals, true, 0, "ELEANOR                          Ya veo... Espero que te          diviertas con tu cocina."},
									{fals, true, 0, "GUY                              Oh, lo hare. Lo hare."},
									{true, true, 00, "COM: Endscene"}};
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
									{fals, true, 0, "ELEANOR                          {Que esta pasando aya fuera?"},
									{fals, true, 0, "AARON                            No lo se, pero sigueme, vamos al bunker de Scout a esperar"},
									{fals, true, 0, "AARON                            hasta que las cosas se calmen."},
									{fals, true, 0, "AARON                            {Donde esta Diana?"},
									{fals, true, 0, "OLIVIER                          Salio a navegar con Guy y no     regresaran hasta mas tarde."},
									{fals, true, 0, "AARON                            Gracias a Dios. Seguime, vamos a salir de aqui."},
									{true, true, 00, "COM: Endscene"}};
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
								{fals, true, 0, "    Esta es la biblioteca de     Eleanor."},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
						}
						else if (me != 5)
						{
							line lc[32] = {
								{fals, true, 0, "    La puerta esta cerrada."},
								{fals, true, 0, "    No deberias fisgonear en     los lugares de otras personas."},
								{true, true, 00, "COM: Endscene"}};
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
									{fals, true, 0, "MAPLE                            }Hey! {Eres Diana, verdad?"},
									{fals, true, 0, "DIANA                            }Hiya! }Al fin! }Otro pelirrojo!"},
									{fals, true, 0, "MAPLE                            Oh, mi pelo no es rojo, mas bien es rubio miel."},
									{fals, true, 0, "MAPLE                            Soy una elfa, asi que a veces se me pone algo anaranjado."},
									{fals, true, 0, "DIANA                            Oh, {lo eres? Entonces..."},
									{fals, true, 0, "MAPLE                            {Vas a preguntarme por que mis   orejas son redondeadas?"},
									{fals, true, 0, "DIANA                            Me daba cosa preguntarte, no     quisiera incomodarte."},
									{fals, true, 0, "MAPLE                            Esta bien. Fueron cortadas       cuando era un bebe."},
									{fals, true, 0, "MAPLE                            Mi nombre es Maple, por cierto.  Maple Tremblay."},
									{fals, true, 0, "DIANA                            }Heureux de te rencontrer!"},
									{fals, true, 0, "DIANA                            }Estas caba[as son maravillosas! {Las hace tu hermano mayor?"},
									{fals, true, 0, "MAPLE                            Mayormente si. Yo a veces salgo  a buscar piedras preciosas en las cuevas."},
									{fals, true, 0, "MAPLE                            Sacamos lo suficiente como para  vivir bien aqui."},
									{fals, true, 0, "DIANA                            {Vives en la casa rodante?"},
									{fals, true, 0, "MAPLE                            Si. Suelo quedarme en el sofa."},
									{fals, true, 0, "DIANA                            {Y no quieres una caba[a? Una de ellas parece estar vacia."},
									{fals, true, 0, "MAPLE                            Veras, Aaron y Enoki quieren     hacer un castillo."},
									{fals, true, 0, "MAPLE                            Asi que pienso quedarme con esta casa cuando eso ocurra."},
									{fals, true, 0, "DIANA                            Asi que... Este lugar, {es de    verdad un pais?"},
									{fals, true, 0, "MAPLE                            Si actuamos como que lo es,      entonces lo es. {No?"},
									{fals, true, 0, "DIANA                            {Es asi de facil crear un pais?"},
									{fals, true, 0, "MAPLE                            Hasta que tengamos que pelear unaguerra? Ya veremos, fue un placer conocerte."},
									{fals, true, 0, "DIANA                            Ehm, si, }tambien es un placer   conocerte!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 1:
							{
								line lc[32] = {
									{fals, true, 0, "ENOKI                            }Hey! {Eres Diana?               }Soy Enoki Tremblay!"},
									{fals, true, 0, "DIANA                            }Enchante de faire votre         connaissance!"},
									{fals, true, 0, "ENOKI                            {Esta todo bien para ti hasta    ahora?"},
									{fals, true, 0, "DIANA                            Es una locura, no sabria decir   siestoy so[ando o no."},
									{fals, true, 0, "DIANA                            Todo es como demasiado increible como para ser real."},
									{fals, true, 0, "ENOKI                            Soy una chica con suerte, asi    quecuando quiero algo..."},
									{fals, true, 0, "ENOKI                            Las cosas suelen salir bien, y   yo queria que esto funcionara."},
									{fals, true, 0, "ENOKI                            {Escuche que traes algo con el   capitan Nicholas?"},
									{fals, true, 0, "DIANA                            }Si! Esta buscando a alguien que se haga cargo de esta area."},
									{fals, true, 0, "DIANA                            Eventualmente, conducire el      barco por todo el Superieur."},
									{fals, true, 0, "ENOKI                            }Suena divertido! Nos tienes que dar una vuelta cuando pase eso."},
									{fals, true, 0, "ENOKI                            Si necesitas cualquier cosa no   dudes en decirnos."},
									{fals, true, 0, "DIANA                            }D'accord!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 2:
							{
								line lc[32] = {
									{fals, true, 0, "DIANA                            }Bienvenue! Eres Tremblay, {oui?"},
									{fals, true, 0, "AARON                            }Bienvenu! {Como te va con la    caba[a? {todo bien?"},
									{fals, true, 0, "DIANA                            }Es genial! Demasiado genial     como para ser real."},
									{fals, true, 0, "DIANA                            Hoy tendre mi primera leccion    conduciendo el barco."},
									{fals, true, 0, "DIANA                            {Conoces al capitan Nicholas?"},
									{fals, true, 0, "AARON                            La verdad es que pase la mayoria del tiempo cortando le[a."},
									{fals, true, 0, "AARON                            Pero parece ser buena persona porlo que tengo entendido."},
									{fals, true, 0, "AARON                            No me quedare mucho, solo pase   para ver como estabas."},
									{fals, true, 0, "AARON                            Dejame saber si necesitas algo,  {esta bien?"},
									{fals, true, 0, "DIANA                            }Por supuesto! }Muchas gracias!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 3:
							{
								line lc[32] = {
									{fals, true, 0, "SCOUT                            }Hey! Soy yo, Scout. Solo queria presentarme."},
									{fals, true, 0, "DIANA                            }Ah, encantada! Sigo sin estar   segura de que esto sea real..."},
									{fals, true, 0, "DIANA                            Me alegra no haber... Bueno...   Sido asesinada o algo asi."},
									{fals, true, 0, "SCOUT                            Admito que yo tambien tengo poco tiempo aqui."},
									{fals, true, 0, "SCOUT                            Me mude aqui desde una isla cercade aqui."},
									{fals, true, 0, "SCOUT                            Pero entonces conoci a los       Tremblay y decidi unirme."},
									{fals, true, 0, "SCOUT                            No fue tan facil abrir un nuevo  bunker, aunque valio la"},
									{fals, true, 0, "SCOUT                            pena. Me siento a gusto aqui."},
									{fals, true, 0, "DIANA                            Bueno, parece que te va bien.    {Eres cientifico?"},
									{fals, true, 0, "SCOUT                            Si, es curioso. Porque ademas    una compa[ia me envio aqui"},
									{fals, true, 0, "SCOUT                            para hacer algunos experimentos  en la isla. No se por que."},
									{fals, true, 0, "DIANA                            {Y encontraste lo que buscabas?"},
									{fals, true, 0, "SCOUT                            He creado este dispositivo que   hace los bunkers rapido."},
									{fals, true, 0, "SCOUT                            No se para que mas lo voy a usar,pero tiene potencial."},
									{fals, true, 0, "DIANA                            Hey, si te parece, {me harias    un bunker en cualquier momento?"},
									{fals, true, 0, "SCOUT                            }Claro, me encantaria!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							// Fall-through to the next bit
							case 4:
							{
								line lc[32] = {
									{fals, true, 0, "DIANA                            }Hey, Vee! }Me alegra verte en mi/nueva caba[a/!"},
									{fals, true, 0, "OLIVIER                          Solo te tomo como lo de un  dia  para hacerla lucir como"},
									{fals, true, 0, "OLIVIER                          tu vieja casa, {eh?"},
									{fals, true, 0, "DIANA                            Si todo va bien, esta caba[a     sera como mi antigua casa."},
									{fals, true, 0, "OLIVIER                          Todo dependera si podemos        confiar en estas personas."},
									{fals, true, 0, "OLIVIER                          Tienes algo para defenderte si   las cosas se voltean, {no?"},
									{fals, true, 0, "DIANA                            Si, llevo encima una pistola de  bengalas."},
									{fals, true, 0, "DIANA                            Aunque espero no tener que       utilizarla."},
									{fals, true, 0, "OLIVIER                          Espero que no sea neCESARio.     Parecen gente agradable."},
									{fals, true, 0, "OLIVIER                          O al menos parece que no tengan  interes en sacrificarnos."},
									{fals, true, 0, "DIANA                            Jeje, ya te digo. Si aparece     alguien de la familia de El,"},
									{fals, true, 0, "DIANA                            Llamame inmediatamente, okay?"},
									{fals, true, 0, "OLIVIER                          Claro, por supuesto."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 5:
							{
								line lc[32] = {
									{fals, true, 0, "ELEANOR                          }Se parece a tu viejo cuarto!"},
									{fals, true, 0, "DIANA                            Claro, {acaso esperabas otra cosade mi? Jeje."},
									{fals, true, 0, "ELEANOR                          Me encanta como la has dejado,   es muy acogedora."},
									{fals, true, 0, "ELEANOR                          Avisame si necesitas cualquier   cosa,"},
									{fals, true, 0, "ELEANOR                          Decore mi habitacion, y tenemos  otra preparada para la bola"},
									{fals, true, 0, "ELEANOR                          de cristal. Aun sigo practicando la invocacion."},
									{fals, true, 0, "DIANA                            {Y no crees que usar magia       podria causar que... ehm..."},
									{fals, true, 0, "DIANA                            las brujas sepan donde estas?"},
									{fals, true, 0, "ELEANOR                          Me mantengo positiva. Si esto    sale bien,"},
									{fals, true, 0, "ELEANOR                          podriamos incluso invitar a mi   familia. Me encantaria"},
									{fals, true, 0, "ELEANOR                          ense[arles este lugar. Es un     lugar relajante."},
									{fals, true, 0, "DIANA                            No es como que hayamos tenido unavida tranquila hasta ahora."},
									{fals, true, 0, "DIANA                            Por cierto, {Has hablado ya con  los Tremblay?"},
									{fals, true, 0, "DIANA                            Parece que podriamos llevarnos   bien con ellos."},
									{fals, true, 0, "DIANA                            Hay una chica pelirroja y una    pareja de... {granjeros?"},
									{fals, true, 0, "DIANA                            Esa tal Enoki es linda, }pero tu lo eres aun mas!"},
									{fals, true, 0, "ELEANOR                          Aw, }Merci!"},
									{fals, true, 0, "DIANA                            No puedo evitar sentirme un poco inquieta, pero creo que"},
									{fals, true, 0, "DIANA                            estaremos bien aqui."},
									{fals, true, 0, "ELEANOR                          Yo pienso lo mismo."},
									{true, true, 00, "COM: Endscene"}};
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
									{fals, true, 0, "MAPLE                            }Diana! }Hey!"},
									{fals, true, 0, "DIANA                            }Hey, Maple!                     {Que tal, corazon?"},
									{fals, true, 0, "MAPLE                            Bien, aunque un poco aburrida."},
									{fals, true, 0, "DIANA                            {Viste la transmision de esta    ma[ana?"},
									{fals, true, 0, "MAPLE                            {La que Rufus hackeo? Es un      idiota, estaremos bien."},
									{fals, true, 0, "MAPLE                            Igual ahora piensa que es un     super villano o algo asi."},
									{fals, true, 0, "DIANA                            Los chicos asi me hacen reir a   carcajadas, en serio. }Jajaja!"},
									{fals, true, 0, "MAPLE                            Dilo. Pero hazme saber si lo ves por ahi."},
									{fals, true, 0, "MAPLE                            El caiman frito es una delicia   durante esta epoca del a[o."},
									{fals, true, 0, "DIANA                            Lo hare."},
									{fals, true, 0, "DIANA                            {Que te cuentas?"},
									{fals, true, 0, "MAPLE                            {Has visto a Scout? Ese pobre    chico siente algo por mi."},
									{fals, true, 0, "MAPLE                            Es un chico dulce, pero tengo quedejarle claro que"},
									{fals, true, 0, "MAPLE                            no es mi tipo."},
									{fals, true, 0, "DIANA                            Chica, no envidio tu situacion,  jajaa. {Cual es tu tipo?"},
									{fals, true, 0, "MAPLE                            Me gustaria alguien alocado y    que me haga sentir emocion."},
									{fals, true, 0, "MAPLE                            Todos los chicos actuan como si  fuera una diosa y todo termina"},
									{fals, true, 0, "MAPLE                            siempre igual. Podria hacer una  barbacoa con ellos si quisiera."},
									{fals, true, 0, "DIANA                            Je, tal vez todos te traten asi  porque terminas asustandolos."},
									{fals, true, 0, "MAPLE                            Igual todo se solucionaria si    encontrara otro elfo de fuego."},
									{fals, true, 0, "DIANA                            Estamos bien lejos en el sureste,no vas a encontrarlos por aqui."},
									{fals, true, 0, "MAPLE                            Ya, seguire buscando pero, pues, esta isla es peque[a."},
									{fals, true, 0, "DIANA                            Buena suerte, jaja. Cuidate      mucho, Maple."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 1:
							{
								line lc[32] = {
									{fals, true, 0, "ENOKI                            }Hey, chica!"},
									{fals, true, 0, "DIANA                            Enoki, }ma cherie! {Quieres algo de snacks?"},
									{fals, true, 0, "ENOKI                            Siempre quiero snacks."},
									{fals, true, 0, "DIANA                            Jaja, asi me gusta. {Como te fue tu dia?"},
									{fals, true, 0, "ENOKI                            Bien, bien, aunque estoy un poco preocupada."},
									{fals, true, 0, "DIANA                            Aw, {y eso?"},
									{fals, true, 0, "ENOKI                            Bueno, Aaron y Maple se han      peleado hoy."},
									{fals, true, 0, "DIANA                            }Chin! {Y paso algo?"},
									{fals, true, 0, "ENOKI                            Bueno Aaron siempre reprime lo   que quiere decir."},
									{fals, true, 0, "ENOKI                            Y Maple lo dice todo a la cara   sin pensar en tus sentimientos."},
									{fals, true, 0, "DIANA                            Esa es una terrible combinacion."},
									{fals, true, 0, "ENOKI                            Ocurre todo el tiempo pero me    pone triste cada vez que pasa."},
									{fals, true, 0, "DIANA                            No tengo hermanos pero... {No es algo que siempre ocurre?"},
									{fals, true, 0, "ENOKI                            {Tu tambien eres hija unica? Me  habria gustado tener una hermana."},
									{fals, true, 0, "DIANA                            Tengo un hermano peque[o, aunque no solemos tener mucho drama."},
									{fals, true, 0, "ENOKI                            Entiendo, entiendo."},
									{fals, true, 0, "DIANA                            Mantenme al tanto, {si?"},
									{fals, true, 0, "ENOKI                            Okay."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 2:
							{
								line lc[32] = {
									{fals, true, 0, "DIANA                            }Hey, Aaron!                     {En que puedo ayudarte?"},
									{fals, true, 0, "AARON                            {Te has enterado de lo del juego de mesa esta noche, no?"},
									{fals, true, 0, "DIANA                            }Si! Alli estare. {Has visto la  transmision?"},
									{fals, true, 0, "AARON                            Hable con Maple, y parece conocera ese chico Plonj."},
									{fals, true, 0, "AARON                            A ella no le apura."},
									{fals, true, 0, "DIANA                            Oh, me alegra oir eso.           {Te veo en la noche?"},
									{fals, true, 0, "AARON                            }Por supuesto!"},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 3:
							{
								line lc[32] = {
									{fals, true, 0, "SCOUT                            }Hey! Soy yo, Scout."},
									{fals, true, 0, "DIANA                            }Hey Scout! {Que cuentas?"},
									{fals, true, 0, "SCOUT                            Parece que el Scout TV de este   mes ya se acabo."},
									{fals, true, 0, "SCOUT                            Ahora solo tengo que preocuparme por la proxima Scout Expo."},
									{fals, true, 0, "DIANA                            Hablas mucho de eso pero, {que esexactamente?"},
									{fals, true, 0, "SCOUT                            Oh, es un lugar en el que saco   mis nuevos inventos y"},
									{fals, true, 0, "SCOUT                            los ense[o. Normalmente lo grabo todo en video y lo subo"},
									{fals, true, 0, "SCOUT                            a internet, }pero ahora he       conseguido amigos a los que"},
									{fals, true, 0, "SCOUT                            se los puedo ense[ar!"},
									{fals, true, 0, "DIANA                            }Parece muy divertido! {Y que    tienes de ejemplo?"},
									{fals, true, 0, "SCOUT                            }No seas aguafiestas! Espera a laScout Expo y podras verlos."},
									{fals, true, 0, "DIANA                            Esta bien... Solo tenia          curiosidad."},
									{fals, true, 0, "SCOUT                            ... Bueno, pues he creado este   dispositivo-"},
									{fals, true, 0, "DIANA                            {Pero no acabas de decirme que metenia que esperar?"},
									{fals, true, 0, "SCOUT                            Pero Yo- Y... hmm... ya. Me      costara trabajo esperar tambien."},
									{fals, true, 0, "DIANA                            Jaja, sabria que te costaria     trabajo tambien."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							// Fall-through to the next bit
							case 4:
							{
								line lc[32] = {
									{fals, true, 0, "DIANA                            }Hey, Vee! {Como has andado?"},
									{fals, true, 0, "OLIVIER                          Bien, bien."},
									{fals, true, 0, "DIANA                            {Estoy organizando el juego de   esta noche, verdad?"},
									{fals, true, 0, "OLIVIER                          }Que va! En absoluto...          Vamos a jugar afuera."},
									{fals, true, 0, "OLIVIER                          Y si todo sale bien espero que laisla no se quede en llamas."},
									{fals, true, 0, "OLIVIER                          {Como estan todos por la orilla?"},
									{fals, true, 0, "DIANA                            }De maravilla! A mis padres les  gustaria venir alguna vez."},
									{fals, true, 0, "DIANA                            Aunque mi casa esta es un        desastre. {Me prestas la tuya?"},
									{fals, true, 0, "OLIVIER                          Sigue so[ando, jajaja."},
									{fals, true, 0, "OLIVIER                          Deberia invitar a Eleanor y a mi familia a venir algun dia."},
									{fals, true, 0, "DIANA                            Oh, les encantara este sitio."},
									{fals, true, 0, "DIANA                            Espero que nada salga mal."},
									{fals, true, 0, "OLIVIER                          Esperemos que no jajaja."},
									{true, true, 00, "COM: Endscene"}};
								dialogue_page_lite(lc);
								break;
							}

							case 5:
							{
								line lc[32] = {
									{fals, true, 0, "ELEANOR                          }Bonjour!"},
									{fals, true, 0, "DIANA                            }Salut, ma charie! {Quoi de neuf?"},
									{fals, true, 0, "ELEANOR                          Oh, {Que es ese olor? {Masa      fermentada?"},
									{fals, true, 0, "DIANA                            Que va, jeje. Aunque debo recogermi habitacion..."},
									{fals, true, 0, "DIANA                            {Como has estado?                {Alguna novedad?"},
									{fals, true, 0, "ELEANOR                          No mucho, he estado cosiendo una nueva colcha."},
									{fals, true, 0, "DIANA                            Fantastico. {De que la estas     haciendo?"},
									{fals, true, 0, "ELEANOR                          Traje toda la ropa de mi pueblo  natal a la isla."},
									{fals, true, 0, "ELEANOR                          Ya estan viejitas pero me da penadeshacerme de ella."},
									{fals, true, 0, "ELEANOR                          Han estado siempre conmigo asi   que hare una colcha con ellas."},
									{fals, true, 0, "DIANA                            Aw, te quedara genial."},
									{fals, true, 0, "DIANA                            {Has vuelto a dibujar?"},
									{fals, true, 0, "ELEANOR                          }Un poco! Hay muchos paisajes    bellos por aqui."},
									{fals, true, 0, "DIANA                            Podria tocar la guitarra junto aloceano el resto de mi vida."},
									{fals, true, 0, "DIANA                            Bueno, cuando digo oceano me     refiero tambien al lago."},
									{fals, true, 0, "DIANA                            Pero es lo mismo."},
									{fals, true, 0, "ELEANOR                          Eso suena como una vida          divertida."},
									{fals, true, 0, "DIANA                            Arrrrrrrg, }es la hora pirata!"},
									{fals, true, 0, "DIANA                            No te preocupes, pasare de visitaaunque siempre este navegando"},
									{fals, true, 0, "ELEANOR                          }S'il vous plait!"},
									{true, true, 00, "COM: Endscene"}};
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
									{fals, true, 0, "DIANA                            }Hey! {Eras Guy, no? Eres tu     verdad?"},
									{fals, true, 0, "GUY                              }Ese soy yo! {Este es tu casa?"},
									{fals, true, 0, "DIANA                            Es humilde pero es mi nuevo      hogar. {Te gusta?"},
									{fals, true, 0, "GUY                              Desde muy peque[o so[aba con     tener mi propia cocina de"},
									{fals, true, 0, "GUY                              tama[o industrial, haci me       levantaria todos los dias hacia ella."},
									{fals, true, 0, "DIANA                            Eso es un sue[o muy detallado,   pero lo entiendo."},
									{fals, true, 0, "GUY                              Ni siquiera tienes cocina,       {cierto?"},
									{fals, true, 0, "DIANA                            Tenemos un horno y una mini      nevera, jaja."},
									{fals, true, 0, "DIANA                            Traigo productos importados asi  que como mucha comida en lata"},
									{fals, true, 0, "GUY                              Sabes que la comida enlatada no  es muy saludable, {verdad?"},
									{fals, true, 0, "DIANA                            Si, bueno, ya tendre tiempo para preocuparme por esas cosas."},
									{fals, true, 0, "DIANA                            Todo el mundo engorda y envejece algun dia."},
									{fals, true, 0, "GUY                              Yo no. Sere un anciano sano y    delgado."},
									{fals, true, 0, "DIANA                            Ya veremos quien esta mejor      cuando lleguemos a los 50."},
									{fals, true, 0, "GUY                              Mas bien ya veras tu,            llegado el momento."},
									{fals, true, 0, "DIANA                            Vamos a jugar a un juego de mesa esta noche. {vas a venir?"},
									{fals, true, 0, "GUY                              Nah, estare ocupado con mi cocinatoda la noche."},
									{fals, true, 0, "DIANA                            Ah... ya, lo entiendo.           }Pasalo guay!"},
									{fals, true, 0, "DIANA                            Ya me diras que tal."},
									{fals, true, 0, "GUY                              }Claro!."},
									{true, true, 00, "COM: Endscene"}};
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
								{fals, true, 0, "OLIVIER                          }O-Oh! Disculpe, se[ora.         {De donde viene?"},
								{fals, true, 0, "GRAND-MERE CORINNE               Este invernadero es una          maravilla."},
								{fals, true, 0, "OLIVIER                          Oh, me dijeron que lo habian     traido de fuera."},
								{fals, true, 0, "GRAND-MERE CORINNE               Veras joven, este invernadero eramio antes."},
								{fals, true, 0, "GRAND-MERE CORINNE               Creo que no tiene sentido        ocultarlo, soy un fantasma."},
								{fals, true, 0, "OLIVIER                          {{{Un fantasma???"},
								{fals, true, 0, "GRAND-MERE CORINNE               Parece que estoy condenada a     estar en este invernadero por siempre."},
								{fals, true, 0, "OLIVIER                          Mis disculpas... Eso parece un   terrible destino..."},
								{fals, true, 0, "GRAND-MERE CORINNE               {Consideras que este es un lugar terrible para pasar una eternidad?"},
								{fals, true, 0, "OLIVIER                          Pensandolo bien... Supongo que   no esta tan mal."},
								{fals, true, 0, "OLIVIER                          El tiempo que he pasado aqui     ha sido agradable."},
								{fals, true, 0, "GRAND-MERE CORINNE               Veo que disfrutas cuidando estas plantas, joven."},
								{fals, true, 0, "GRAND-MERE CORINNE               Dejame decirte algo antes        de despedirme."},
								{fals, true, 0, "GRAND-MERE CORINNE               Aunque cuidar de las plantas     parece no tener sentido."},
								{fals, true, 0, "GRAND-MERE CORINNE               Las cosas buenas vienen a        aquellos que esperan."},
								{fals, true, 0, "GRAND-MERE CORINNE               Ha sido un placer conocerte.     }Cuidate mucho!"},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						else if (globals->current_save->checkpoint < 12)
						{
							// corinne.set_blending_enabled(false);
							line lc[32] = {
								{true, true, 00, "OLIVIER                          Good afternoon, Grand-mere!"},
								{true, true, 00, "GRAND-MERE CORINNE               Good afternoon, Olivier. It's    nice to have visitors."},
								{true, true, 00, "OLIVIER                          How has your day been?"},
								{true, true, 00, "GRAND-MERE CORINNE               Oh, just as usual.. Eternal      unrest. A ghost's life."},
								{true, true, 00, "GRAND-MERE CORINNE               Or lack thereof, hehe."},
								{true, true, 00, "OLIVIER                          The afterlife seems rather dull."},
								{true, true, 00, "GRAND-MERE CORINNE               It doesn't have to be. Say.. can you tell me about that man?"},
								{true, true, 00, "OLIVIER                          Man?"},
								{true, true, 00, "GRAND-MERE CORINNE               Yes, the strapping boat captain. With the beard?"},
								{true, true, 00, "OLIVIER                          Oh, the captain? Do you.. like   him?"},
								{true, true, 00, "GRAND-MERE CORINNE               This sounds rather morbid, but   how many years do you suppose"},
								{true, true, 00, "GRAND-MERE CORINNE               he has left?"},
								{true, true, 00, "GRAND-MERE CORINNE               I wouldn't suppose he'd enjoy an afterlife here."},
								{true, true, 00, "OLIVIER                          That.. uh.. question may be      better asked to him."},
								{true, true, 00, "GRAND-MERE CORINNE               Of course, of course."},
								{true, true, 00, "COM: Endscene"}};
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
							{fals, true, 0, "EL BIZAR DE CESAR                'SOLO TENEMOS DOS COSAS,         ARREGLATE CON ESO'"},
							{true, true, 00, "COM: Endscene"}};
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
								{fals, true, 0, "MAPLE                            Asi que... Guy, uhg...  {Le      pusiste jitomate en la Jambalaya?"},
								{fals, true, 0, "GUY                              Asi lo quiso Dios, nuestro se[or."},
								{fals, true, 0, "MAPLE                            {C-como que asi lo quiso Dios?"},
								{fals, true, 0, "MAPLE                            ... Me estas tomando el pelo,    {verdad?"},
								{fals, true, 0, "GUY                              {Tambien eres una de esas a las  que les gusta su roux quemada?"},
								{fals, true, 0, "MAPLE                            Explica 'quemada'."},
								{fals, true, 0, "GUY                              Tan quemado que pierde tanto el  color y no puedes saborearlo."},
								{fals, true, 0, "MAPLE                            {A que te refieres con eso del   sabor? }A mi me gusta asi!"},
								{fals, true, 0, "GUY                              Si, porque le pones un monton de especies al azar."},
								{fals, true, 0, "MAPLE                            Mi eleccion de especies NO son alazar."},
								{fals, true, 0, "GUY                              No tengo mas que decir, si me    disculpas, aver si barro"},
								{fals, true, 0, "GUY                              el piso para sazonar una buena   Jambajaya."},
								{fals, true, 0, "MAPLE                            Ustedes los Creoles son          psicopatas."},
								{fals, true, 0, "GUY                              No tanto como ustedes los Cajun, preciosa. Te digo algo."},
								{fals, true, 0, "GUY                              Una competencia de Gumbo, y les  dejamos la votacion a todos los demas. Trato?"},
								{fals, true, 0, "MAPLE                            Trato hecho. Facilisimo."},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						case 1:
						{
							line lc[32] = {
								{fals, true, 0, "ENOKI                            Ooooooh... }Me encanta tu        cocina!}Es bien grande!"},
								{fals, true, 0, "GUY                              Merci. Me encanta levantarme parahacer un pan de maiz."},
								{fals, true, 0, "ENOKI                            Me encantaria hacer eso tambien, jeje."},
								{fals, true, 0, "GUY                              Por cierto, uh. Esa tal Maple... {Que tal su Gumbo comparado con el mio?"},
								{fals, true, 0, "ENOKI                            {Estas compitiendo contra ella?  Si es asi, no quiero opinar."},
								{fals, true, 0, "ENOKI                            No quiero elegir lados, apenas temoviste aqui."},
								{fals, true, 0, "ENOKI                            Pero tienes que saber que Maple yyo somos mejores amigas."},
								{fals, true, 0, "GUY                              Tal vez te pueda cocinar algo    para que reconsideres."},
								{fals, true, 0, "ENOKI                            Lo veo complicado. A mi no me    gusta mucho /este/ la comida."},
								{fals, true, 0, "GUY                              Pero... Ah, que mas da.          Cuidate, cheri."},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						case 2:
						{
							line lc[32] = {
								{fals, true, 0, "AARON                            }Huele muy bien aqui!"},
								{fals, true, 0, "GUY                              Oui, como tiene que."},
								{fals, true, 0, "AARON                            Oye, {escuche que viniste aqui   en busca de clientes?"},
								{fals, true, 0, "GUY                              Eso es cierto."},
								{fals, true, 0, "AARON                            Bueno, eh... Como puedes         comprobar, no somos muchos por aqui."},
								{fals, true, 0, "AARON                            Y pues trato de que esta isla seaun buen hogar para todos."},
								{fals, true, 0, "GUY                              {A donde quieres llegar?"},
								{fals, true, 0, "AARON                            Solo espero que sepas que no     somos lo bastante grandes como"},
								{fals, true, 0, "AARON                            para tener nuestra propia moneda,algunos apenas tienen dinero."},
								{fals, true, 0, "GUY                              Solo cobro 5 dolares, es         accesible y espero clientes."},
								{fals, true, 0, "AARON                            {Sabes que? {Cuanto cuesta esta  caba[a? {10 o 20 mil dolares?"},
								{fals, true, 0, "AARON                            No se hacer calculos, nunca me   gradue en la prepa."},
								{fals, true, 0, "AARON                            Enoki no esta aqui pero ella sabehacer cuentas."},
								{fals, true, 0, "AARON                            {Que tal comida gratis para      todos? Por un a[o entero?"},
								{fals, true, 0, "AARON                            Entonces eso pagara por la       caba[a. {C'est bon?"},
								{fals, true, 0, "GUY                              ...Lo pensare."},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						case 3:
						{
							line lc[32] = {
								{true, true, 00, "OLIVIER                          O-Oh! Excuse me, ma'am. Where didyou come from?"},
								{true, true, 00, "GRAND-MERE CORINNE               This greenhouse is still quite   nice, was it moved?"},
								{true, true, 00, "OLIVIER                          Oh.. Well, I was told that it wastransported from inland."},
								{true, true, 00, "GRAND-MERE CORINNE               Well, you see, I once owned this greenhouse, young man."},
								{true, true, 00, "GRAND-MERE CORINNE               I don't see any point in having  ambiguity; I am a ghost."},
								{true, true, 00, "OLIVIER                          A ghost???"},
								{true, true, 00, "GRAND-MERE CORINNE               It seems I am doomed to haunt    this greenhouse forever."},
								{true, true, 00, "OLIVIER                          My apologize, that seems... it   seems like a terrible fate."},
								{true, true, 00, "GRAND-MERE CORINNE               Would you consider it horrible tospend an eternity here?"},
								{true, true, 00, "OLIVIER                          Now that I think about it.. I    suppose not."},
								{true, true, 00, "OLIVIER                          It's where I spend most of my    life anyway."},
								{true, true, 00, "GRAND-MERE CORINNE               I see you enjoy taking care of   these plants, son."},
								{true, true, 00, "GRAND-MERE CORINNE               Before I leave, I will remind youof one wisdom."},
								{true, true, 00, "GRAND-MERE CORINNE               Even if your care of these plantsseems meaningless,"},
								{true, true, 00, "GRAND-MERE CORINNE               Wonderful things come to the     diligent."},
								{true, true, 00, "GRAND-MERE CORINNE               It was very nice to meet you.    Until next time!"},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						case 4:
						{
							line lc[32] = {
								{fals, true, 0, "OLIVIER                          }Bonjour!"},
								{fals, true, 0, "GUY                              Oui. {J'suppose que eres el      jardinero?"},
								{fals, true, 0, "GUY                              {Cultivas apio, cebolla y chiles pimientos?"},
								{fals, true, 0, "OLIVIER                          }Por supuesto!"},
								{fals, true, 0, "GUY                              Te digo algo, si me surtes de    verduras frescas."},
								{fals, true, 0, "GUY                              Te cocinare Gumbo gratis."},
								{fals, true, 0, "OLIVIER                          {Y que hay de mi esposa?"},
								{fals, true, 0, "GUY                              {Es la que tiene el atuendo y el cabello de Wendy?"},
								{fals, true, 0, "OLIVIER                          ...Es la que tiene el pelo cafe."},
								{fals, true, 0, "GUY                              Sale, Dave."},
								{fals, true, 0, "OLIVIER                          ...Olivier. Olivier Landry."},
								{fals, true, 0, "OLIVIER                          {Que no te llamas Guy?"},
								{fals, true, 0, "GUY                              Correcto."},
								{fals, true, 0, "OLIVIER                          {Pero no era 'Guy Pizza'?"},
								{fals, true, 0, "GUY                              Eso era una broma, pero no se lo digas a nadie. {si?"},
								{fals, true, 0, "OLIVIER                          Entendido."},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						case 5:
						{
							line lc[32] = {
								{fals, true, 0, "ELEANOR                          }Bonjour! {Comment allez-vous?"},
								{fals, true, 0, "GUY                              C'est bon, {y tu como estas?"},
								{fals, true, 0, "ELEANOR                          Este lugar me hace tener mucha   hambre, }y huele genial!"},
								{fals, true, 0, "GUY                              {En serio?"},
								{fals, true, 0, "ELEANOR                          Me gusta mas hornear que cocinar,}pero esta cocina es estupenda!"},
								{fals, true, 0, "GUY                              {Que te gusta hacer en el horno?"},
								{fals, true, 0, "ELEANOR                          Lo que mas me gusta es el pay de limon, aunque necesito"},
								{fals, true, 0, "ELEANOR                          hacer un monton de praline de    nuez. {Te gusta el praline?"},
								{fals, true, 0, "GUY                              {Que si me gusta el praline?"},
								{fals, true, 0, "GUY                              {QUE SI ME GUSTA EL PRALINE?"},
								{fals, true, 0, "GUY                              Claro, es muy rico."},
								{fals, true, 0, "GUY                              Consigueme praline y te dare     comida gratis. {Te parece bien?"},
								{fals, true, 0, "ELEANOR                          }Trato hecho!"},
								{true, true, 00, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						}
						case 6:
						{
							line lc[32] = {
								{fals, true, 0, "DIANA                            }Hey! Tu nombre era Guy Pizza    si mal no recuerdo, {cierto?"},
								{fals, true, 0, "GUY                              Guy Pizza, el unico."},
								{fals, true, 0, "DIANA                            Puedo ver por que, jajaja.       {Eres italiano?"},
								{fals, true, 0, "GUY                              Nah, soy de Donaldsonville.      Nuevo nombre, nueva vida."},
								{fals, true, 0, "DIANA                            {Y por que ‘pizza'?"},
								{fals, true, 0, "GUY                              La gente lleva a[os llamandome   'pizza guy' y mi nombre es Guy."},
								{fals, true, 0, "GUY                              Ya me acostumbre. Ademas hago quele de hambre a la gente."},
								{fals, true, 0, "DIANA                            Claro, a cualquiera le gusta la  pizza. {Las haces a menudo?"},
								{fals, true, 0, "GUY                              La verdad, no a menudo."},
								{fals, true, 0, "DIANA                            Sabes? No es tarde para cambiar  de parecer."},
								{fals, true, 0, "GUY                              {Tienes alguna sugerencia?"},
								{fals, true, 0, "DIANA                            Guy... el Misterioso. Se escucha misterioso."},
								{fals, true, 0, "GUY                              Pero no soy un mago..."},
								{fals, true, 0, "DIANA                            Tampoco eres una pizza."},
								{fals, true, 0, "GUY                              Touche."},
								{fals, true, 0, "GUY                              Lo tendre en mente."},
								{true, true, 00, "COM: Endscene"}};
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
							{fals, true, 0, "AARON                            Parece que no hay nadie en casa."},
							{true, true, 00, "COM: Endscene"}};
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
				}

				globals->current_save->xp += 2;
				xphud.acknowledge();
			}
		}
		else
		{
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
		for (unsigned short int t = 0; t < anim_objects.size(); t++)
		{
			anim_objects.at(t).update();
			anim_objects.at(t).entity.set_camera(current_room.camera);
		}

		bn::core::update();

		// World-specific special events

		switch (dt.world_index)
		{
		case 1:
		{
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
		case 2:
		{
			for (int i = 0; i < current_room.p.size(); i++)
			{
				if (current_room.p.at(i).dur < 16)
				{
					short int my_x = current_room.p.at(i).fireball.x().integer() / 32;
					short int my_y = current_room.p.at(i).fireball.y().integer() / 32;
					if (my_x >= 2 && my_x <= 3 && my_y >= 2 && my_y <= 3)
					{
						current_room.p.at(i).dur = 16;
						// current_room.p.erase(current_room.p.begin() + i);

						anim_objects.at(0).entity_anim = bn::create_sprite_animate_action_forever(anim_objects.at(0).entity, 18, anim_objects.at(0).entity_item.tiles_item(), 2, 1, 00, 1);
						anim_objects.at(0).entity.set_horizontal_flip(!anim_objects.at(0).entity.horizontal_flip());
						break;

						// anim_objects.at(0).entity_anim.update();
					}
				}
			}
			break;
		}
		case 3:
		{
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

					line lc[32] = {
						{fals, true, 0, "MAPLE                            ...."},
						{fals, true, 0, "ENOKI                            Bueno, pues no hay pasadizo."},
						{fals, true, 0, "MAPLE                            No me digas.."},
						{fals, true, 0, "ENOKI                            Que extra[o."},
						{fals, true, 0, "MAPLE                            A ver, Enoki..."},
						{fals, true, 0, "MAPLE                            Supongo que no tiene ningun"},
						{fals, true, 0, "MAPLE                            sentido enfadarse contigo, pero"},
						{fals, true, 0, "MAPLE                            deberias dejar de actuar asi."},
						{fals, true, 0, "MAPLE                            Tu y Aaron gastaron un"},
						{fals, true, 0, "MAPLE                            dineral en un castillo sin"},
						{fals, true, 0, "MAPLE                            amueblar ni necesidades basicas."},
						{fals, true, 0, "MAPLE                            {Para que? {Para que puedas jugar"},
						{fals, true, 0, "MAPLE                            a hacerte la princesa? Mientras"},
						{fals, true, 0, "MAPLE                            haces eso, yo sacrifico toda"},
						{fals, true, 0, "MAPLE                            mi vida personal manteniendo el"},
						{fals, true, 0, "MAPLE                            apartamento de Carolina con solo"},
						{fals, true, 0, "MAPLE                            lo esencial. Enoki... Por favor."},
						{fals, true, 0, "MAPLE                            No quiero parecer la mala aqui."},
						{fals, true, 0, "MAPLE                            Entiendo que no has tenido"},
						{fals, true, 0, "MAPLE                            una buena infancia"},
						{fals, true, 0, "MAPLE                            ni padres...Porque esa soy yo tambien."},
						{fals, true, 0, "MAPLE                            Pero no puedes seguir portandote"},
						{fals, true, 0, "MAPLE                            de esta forma. {Lo entiendes?"},
						{fals, true, 0, "ENOKI                            Lo entiendo."},
						{fals, true, 0, "MAPLE                            Son las 5:00 de la ma[ana, voy"},
						{fals, true, 0, "MAPLE                            a volver a la cama. Te vere por"},
						{fals, true, 0, "MAPLE                            la ma[ana, {oui?"},
						{fals, true, 0, "ENOKI                            Oui..."},
						{fals, true, 0, "MAPLE                            No te apures pensando en"},
						{fals, true, 0, "MAPLE                            esto. S'il te plait, Bonne nuit."},
						{fals, true, 0, "ENOKI                            Bonne nuit..."},
						{true, true, 00, "COM: Endscene"}};
					dialogue_page_lite(lc);

					dt.world_index = -1;
					return dt;
				}
			}
			break;
		}
		case 11:
		{
			bn::sprite_ptr *corinne = &current_room.anim_objects.at(0).entity;

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
		default:
		{
		}
		}
	}
}

class after_effect
{
public:
	bn::sprite_ptr me = bn::sprite_items::underground_tiles.create_sprite(0, 0, 4);
	bool done = false;

	after_effect()
	{
		done = false;
	}

	void update()
	{
		if ((me.horizontal_scale() - 0.05) > 0)
		{
			me.set_scale(me.horizontal_scale() - 0.05, me.vertical_scale() - 0.05);
			me.put_below();
		}
		else
		{
			done = true;
		}
	}
};

dungeon_return rufus_dungeon(dungeon_return &dt)
{
	bn::vector<after_effect, 2> aes;

	if (dt.world_index == 2)
	{
		line lc[32] = {
			{true, true, 0, "S07:01"},
			{true, true, 0, "BG: fadeout"},
			{fals, true, 0, "MAPLE                            Dime la verdad, {oui?            {Tu hiciste todo este lugar?"},
			{fals, true, 0, "SCOUT                            }Imposible! Aunque me habria     gustado conseguirlo por mi mismo."},
			{true, true, 00, "S07:02"},
			{true, true, 00, "..."},
			{true, true, 00, "S07:03"},
			{fals, true, 0, "SCOUT                            }MAPLE, CUIDADO!"},
			{true, true, 00, "S07:04"},
			{fals, true, 0, "MAPLE                            ... Scout, {te encuentras bien?"},
			{fals, true, 0, "RUFUS                            Ow. Aunque me golpee un poco la  espalda. Creo que estare bien."},
			{true, true, 00, "S07:05"},
			{fals, true, 0, "MAPLE                            {Que hace toda esta gasolina aqui?"},
			{fals, true, 0, "SCOUT                            Por nuestro bien, mas te vale    tener cuidado con tus poderes."},
			{true, true, 0, "COM: Endscene"}};
		dialogue_page(lc);

		bn::music_items::z20_waves.play(0.8);
	}

	if (!bn::music::playing())
	{
		bn::music_items::z20_waves.play(0.8);
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
			0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1,
			0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 4, 1, 1,
			0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1,
			0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1,
			0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1,
			0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1,
			0, 0, 1, 1, 0, 1, 5, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1,
			1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1,
			1, 0, 6, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1,
			1, 0, 6, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
		const short int local[current_room.width * current_room.height] = {
			0, 0, 0, 0, 0, 0, 12, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 12, 0, 0, 12, 1, 1, 9, 1, 12,
			0, 0, 12, 12, 12, 12, 12, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 12, 0, 0, 12, 1, 4, 0, 1, 12,
			0, 0, 12, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 12, 0, 0, 12, 1, 0, 0, 1, 12,
			0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 12, 12, 12, 12, 1, 0, 1, 12, 12, 12, 12, 10, 0, 0, 1, 12,
			0, 0, 0, 1, 0, 0, 0, 1, 16, 1, 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 1, 11, 0, 0, 1, 12,
			0, 0, 0, 1, 0, 0, 0, 1, 5, 5, 5, 5, 5, 1, 1, 5, 1, 5, 5, 5, 1, 10, 12, 0, 1, 12,
			0, 0, 0, 1, 0, 5, 0, 1, 0, 0, 0, 5, 5, 5, 1, 5, 1, 5, 5, 5, 1, 1, 0, 0, 1, 12,
			0, 0, 0, 1, 0, 5, 0, 1, 0, 1, 1, 1, 5, 5, 1, 5, 1, 1, 5, 5, 0, 1, 0, 0, 1, 12,
			1, 1, 1, 1, 16, 1, 16, 1, 0, 1, 12, 1, 0, 16, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 10, 12,
			0, 0, 0, 5, 0, 1, 0, 5, 0, 1, 12, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 16, 0, 0, 1, 12,
			0, 0, 0, 5, 1, 1, 0, 5, 0, 1, 12, 1, 12, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 12, 1, 12,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 12, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 12};

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++)
		{
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
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
		const short int local[current_room.width * current_room.height] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 12, 1, 12, 0, 0, 0, 0, 0, 0, 0, 0, 12, 1, 12, 1, 1,
			1, 0, 12, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 12, 0, 1,
			1, 15, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 12, 1, 0, 1,
			1, 0, 1, 13, 1, 1, 6, 7, 8, 6, 7, 8, 6, 6, 7, 8, 0, 11,
			1, 0, 1, 14, 0, 0, 15, 5, 0, 0, 0, 1, 12, 0, 0, 16, 0, 10,
			1, 0, 1, 1, 1, 0, 1, 16, 0, 16, 0, 1, 0, 0, 0, 16, 0, 11,
			1, 0, 1, 5, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 16, 0, 10,
			1, 0, 1, 0, 5, 0, 1, 1, 5, 1, 1, 1, 16, 16, 16, 10, 0, 11,
			1, 0, 1, 0, 0, 5, 12, 1, 5, 0, 1, 0, 0, 0, 0, 11, 0, 10,
			1, 0, 1, 0, 5, 0, 1, 1, 14, 0, 1, 0, 0, 0, 0, 10, 15, 11,
			1, 15, 1, 1, 1, 15, 1, 1, 5, 5, 15, 0, 14, 0, 0, 11, 0, 10,
			1, 0, 0, 0, 0, 0, 10, 12, 1, 1, 1, 1, 0, 0, 0, 10, 13, 11,
			1, 0, 0, 16, 10, 0, 11, 0, 1, 0, 0, 1, 12, 0, 0, 11, 0, 10,
			1, 0, 0, 0, 11, 0, 10, 0, 0, 0, 16, 1, 1, 1, 1, 1, 0, 11,
			1, 0, 0, 0, 10, 2, 11, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 10,
			1, 0, 0, 0, 11, 0, 10, 12, 0, 0, 0, 0, 0, 12, 0, 1, 0, 11,
			1, 14, 0, 0, 0, 0, 10, 12, 0, 12, 12, 12, 0, 12, 0, 1, 0, 1,
			1, 0, 0, 0, 16, 0, 16, 0, 0, 0, 0, 0, 0, 0, 5, 1, 0, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1};

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++)
		{
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
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1};
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
			1, 6, 6, 6, 10, 6, 8, 6, 6, 6, 6, 7, 8, 6, 0, 6, 7, 8, 11};

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++)
		{
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
			0, 1, 1, 0, 1, 1};
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
			0, 1, 1, 0, 1, 1};

		globals->local_tileset.clear();
		globals->collisions.clear();
		for (short int t = 0; t < current_room.width * current_room.height; t++)
		{
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
		for (int t = 0; t < aes.size(); t++)
		{
			aes.at(t).update();
			if (aes.at(t).done)
			{
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

			if (current_room.p.at(t).fireball.visible())
			{
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

				if (globals->all_save.language == 0)
				{
					switch (possible_action)
					{
					case 2:
					{
						line lc[10] = {
							{true, true, 00, "MAPLE                            What the.."},
							{true, true, 00, "MAPLE                            What the heck is this?"},
							{true, true, 00, "SCOUT                            Maybe my bunker tool needs to be"},
							{true, true, 00, "SCOUT                            recalibrated."},
							{true, true, 00, "MAPLE                            Well, fix it. I don't want to die"},
							{true, true, 00, "MAPLE                            down here."},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};
					case 3:
					{
						line lc[32] = {
							{true, true, 00, "ELEANOR                          Vee, do we need to go any"},
							{true, true, 00, "ELEANOR                          further? I'm scared."},
							{true, true, 00, "OLIVIER                          I'll stay behind with my wife."},
							{true, true, 00, "OLIVIER                          We can protect ourselves. I'm   "},
							{true, true, 00, "OLIVIER                          sure we're far enough from"},
							{true, true, 00, "OLIVIER                          whatever was going on."},
							{true, true, 00, "AARON                            Alright.. If you say so. Fais"},
							{true, true, 00, "AARON                            attention, oui?"},
							{true, true, 00, "OLIVIER                          Oui."},
							{true, true, 00, "AARON                            Enoki, are you going to stay"},
							{true, true, 00, "AARON                            with them?"},
							{true, true, 00, "ENOKI                            Bad things happen to me"},
							{true, true, 00, "ENOKI                            whenever I'm too far away from  "},
							{true, true, 00, "ENOKI                            a Tremblay, so I'll say no."},
							{true, true, 00, "AARON                            Very well, then. So, it's"},
							{true, true, 00, "AARON                            you, Maple, and Scout.. oui?  "},
							{true, true, 00, "SCOUT                            Oui."},
							{true, true, 00, "SCOUT                            But maybe it should just be me."},
							{true, true, 00, "SCOUT                            I'm the 'scout', right?"},
							{true, true, 00, "MAPLE                            No, you're not going into there"},
							{true, true, 00, "MAPLE                            by yourself. I'm coming with."},
							{true, true, 00, "SCOUT                            Maybe Aaron and Enoki stay?"},
							{true, true, 00, "AARON                            ...Fine. You two go."},
							{true, true, 00, "MAPLE                            Allons-y. Into the tacky"},
							{true, true, 00, "MAPLE                            hallway."},
							{true, true, 00, "COM: Endscene"}};
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
							{true, true, 00, "OLIVIER                          Is that gasoline?"},
							{true, true, 00, "SCOUT                            It, uh.. seems like.."},
							{true, true, 00, "AARON                            Seems like what?"},
							{true, true, 00, "SCOUT                            It, er- someone might have"},
							{true, true, 00, "SCOUT                            already been here."},
							{true, true, 00, "MAPLE                            Oh I don't like that."},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};
					case 6:
					{
						if (current_room.chari.at(current_room.follow_id).identity != 3)
						{
							line lc[10] = {
								{true, true, 00, "SCOUT                            Hey, y'all don't worry,"},
								{true, true, 00, "SCOUT                            I can take care of this."},
								{true, true, 00, "COM: Endscene"}};
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
							{true, true, 00, "You wonder what fire might be    able to do to this button."},
							{true, true, 00, "COM: Endscene"}};
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
					default:
					{
					};
					}
				}
				else if (globals->all_save.language == 2)
				{

					switch (possible_action)
					{
					case 2:
					{
						line lc[10] = {
							{true, true, 00, "MAPLE                            What the.."},
							{true, true, 00, "MAPLE                            What the heck is this?"},
							{true, true, 00, "SCOUT                            Maybe my bunker tool needs to be"},
							{true, true, 00, "SCOUT                            recalibrated."},
							{true, true, 00, "MAPLE                            Well, fix it. I don't want to die"},
							{true, true, 00, "MAPLE                            down here."},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};
					case 3:
					{
						line lc[32] = {
							{true, true, 00, "ELEANOR                          Vee, do we need to go any"},
							{true, true, 00, "ELEANOR                          further? I'm scared."},
							{true, true, 00, "OLIVIER                          I'll stay behind with my wife."},
							{true, true, 00, "OLIVIER                          We can protect ourselves. I'm   "},
							{true, true, 00, "OLIVIER                          sure we're far enough from"},
							{true, true, 00, "OLIVIER                          whatever was going on."},
							{true, true, 00, "AARON                            Alright.. If you say so. Fais"},
							{true, true, 00, "AARON                            attention, oui?"},
							{true, true, 00, "OLIVIER                          Oui."},
							{true, true, 00, "AARON                            Enoki, are you going to stay"},
							{true, true, 00, "AARON                            with them?"},
							{true, true, 00, "ENOKI                            Bad things happen to me"},
							{true, true, 00, "ENOKI                            whenever I'm too far away from  "},
							{true, true, 00, "ENOKI                            a Tremblay, so I'll say no."},
							{true, true, 00, "AARON                            Very well, then. So, it's"},
							{true, true, 00, "AARON                            you, Maple, and Scout.. oui?  "},
							{true, true, 00, "SCOUT                            Oui."},
							{true, true, 00, "SCOUT                            But maybe it should just be me."},
							{true, true, 00, "SCOUT                            I'm the 'scout', right?"},
							{true, true, 00, "MAPLE                            No, you're not going into there"},
							{true, true, 00, "MAPLE                            by yourself. I'm coming with."},
							{true, true, 00, "SCOUT                            Maybe Aaron and Enoki stay?"},
							{true, true, 00, "AARON                            ...Fine. You two go."},
							{true, true, 00, "MAPLE                            Allons-y. Into the tacky"},
							{true, true, 00, "MAPLE                            hallway."},
							{true, true, 00, "COM: Endscene"}};
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
							{true, true, 00, "OLIVIER                          Is that gasoline?"},
							{true, true, 00, "SCOUT                            It, uh.. seems like.."},
							{true, true, 00, "AARON                            Seems like what?"},
							{true, true, 00, "SCOUT                            It, er- someone might have"},
							{true, true, 00, "SCOUT                            already been here."},
							{true, true, 00, "MAPLE                            Oh I don't like that."},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);
						break;
					};
					case 6:
					{
						if (current_room.chari.at(current_room.follow_id).identity != 3)
						{
							line lc[10] = {
								{true, true, 00, "SCOUT                            Hey, y'all don't worry,"},
								{true, true, 00, "SCOUT                            I can take care of this."},
								{true, true, 00, "COM: Endscene"}};
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
							{true, true, 00, "Te preguntas si el fuego podria  ser util."},
							{true, true, 00, "COM: Endscene"}};
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
					default:
					{
					};
					}
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
			button *bt = &buttons.at(gates.at(t).triggered_by);
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

void keyboard()
{
	bn::core::update();

	bn::string<16> string;
	bn::string<33> file2_str;
	bn::ostringstream ss(string);
	bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
	bn::sprite_text_generator file2_gen(common::variable_8x16_sprite_font);

	bn::vector<bn::sprite_ptr, 16> file1_spr;
	bn::vector<bn::sprite_ptr, 33> file2_spr;

	auto velvet = bn::regular_bg_items::velvet.create_bg(0, 0);
	auto ui = bn::regular_bg_items::keyboard_bg.create_bg(0, 0);
	auto sel = bn::sprite_items::selection.create_sprite(-100, -18);
	char basis[96] = "abcdefghijklmnopqrstuvwxyz     -'&  ABCDEFGHIJKLMNOPQRSTUVWXYZ     -'&  ";
	auto x_state = 0, y_state = 0, t = 0, height = -64;
	auto lower = true;
	ui.set_y(64);

	switch (globals->all_save.language)
	{
	case 0:
	{
		file2_str = "SELECT (Caps), START (Finish)";
		break;
	}
	case 1:
	{
		file2_str = "SELECT Majuscules, START Termine";
		break;
	}
	case 2:
	{
		file2_str = "SELECT (Mayus), START (Finalizar)";
		break;
	}
	}

	file2_gen.generate(-104, height * -1, file2_str, file2_spr);
	while (!bn::keypad::start_pressed())
	{

		if (bn::keypad::left_pressed())
		{
			if (((basis[x_state - 1 + (y_state * 12)] != ' ') || (y_state == 2)) && !(x_state == 7 && y_state == 2))
			{
				x_state--;
				if (x_state < 0)
					x_state = 11;
				sel.set_x(-100 + 18 * x_state);
			}
		}
		else if (bn::keypad::right_pressed())
		{
			if ((basis[x_state + 1 + (y_state * 12)] != ' ') || (x_state > 8))
			{
				x_state++;
				x_state = x_state % 12;
				sel.set_x(-100 + 18 * x_state);
			}
		}
		if (bn::keypad::up_pressed())
		{
			if (!(x_state > 1 && x_state < 7 && y_state == 0) || (x_state > 8))
			{
				y_state--;
				if (y_state < 0)
					y_state = 2;
				sel.set_y(-18 + 26 * y_state);
			}
		}
		else if (bn::keypad::down_pressed())
		{
			if ((basis[x_state + ((y_state + 1) * 12)] != ' ') || (x_state > 8))
			{
				y_state++;
				y_state = y_state % 3;
				sel.set_y(-18 + 26 * y_state);
			}
		}

		if (bn::keypad::a_pressed())
		{
			if (ss.size() < 16)
			{
				bn::sound_items::pop.play();
				file1_spr.clear();
				file2_spr.clear();
				unsigned short int plus = 0;
				if (!lower)
					plus = 36;
				ss << (basis[x_state + plus + (y_state * 12)]);
				file1_gen.generate(-104, height, ss.str().c_str(), file1_spr);
				file2_gen.generate(-104, height * -1, file2_str, file2_spr);
			}
			else
			{
				bn::sound_items::firehit.play();
			}
		}

		if (bn::keypad::b_pressed())
		{
			if (ss.size() > 0)
			{
				string.pop_back();
				file1_spr.clear();
				file2_spr.clear();
				file1_gen.generate(-104, height, string.c_str(), file1_spr);
				file2_gen.generate(-104, height * -1, file2_str, file2_spr);
				bn::sound_items::cnaut.play();
			}
			else
			{
				bn::sound_items::firehit.play();
			}
		}

		if (bn::keypad::select_pressed())
		{
			bn::sound_items::fireblast.play();
			file1_spr.clear();
			file2_spr.clear();
			lower = !lower;
			height = height * -1;
			if (!lower)
			{
				while (ui.y().integer() != 192)
				{ // 192, 204
					short int y = ui.y().integer() + 4;
					y = y % 256;
					ui.set_y(y);
					bn::core::update();
				}
			}
			else
			{
				while (ui.y().integer() != 64)
				{
					short int y = ui.y().integer() + 4;
					y = y % 256;
					ui.set_y(y);
					bn::core::update();
				}
			}
			file1_gen.generate(-104, height, string.c_str(), file1_spr);
			file2_gen.generate(-104, height * -1, file2_str, file2_spr);
			bn::sound_items::firehit.play();
		}

		// Scrolling background
		t = (t + 1) % 256;
		velvet.set_position(t, t);
		bn::core::update();
	}

	for (int tt = 0; tt < ss.size(); tt++)
		globals->current_save->island_name[tt] = string.at(tt);
}

void timer(int delay)
{
	for (short int t = 0; t < delay; t++)
	{
		bn::core::update();
	}
}

void intros(int t)
{

	flash_write();

	bn::fixed_t<12> glow = 1;

	auto header = bn::regular_bg_items::cinemint_studios.create_bg(0, 0);
	auto a_button = bn::sprite_items::a_button.create_sprite(-90, -50, (globals->all_save.language * 2));
	int intro_stage = 0;

	a_button.set_visible(false);

	switch (t)
	{
	case 0:
	{
		header = bn::regular_bg_items::tc_intro.create_bg(0, 0);
		break;
	}
	case 1:
	{
		header = bn::regular_bg_items::tc_1.create_bg(0, 0);
		break;
	}
	case 2:
	{
		header = bn::regular_bg_items::tc_2.create_bg(0, 0);
		break;
	}
	case 3:
	{
		header = bn::regular_bg_items::tc_3.create_bg(0, 0);
		break;
	}
	case 4:
	{
		header = bn::regular_bg_items::tc_4.create_bg(0, 0);
		break;
	}
	case 5:
	{
		header = bn::regular_bg_items::tc_5.create_bg(0, 0);
		break;
	}
	default:
	{
	}
	}

	header.set_mosaic_enabled(true);

	while (!bn::keypad::a_pressed())
	{
		if (intro_stage == 0)
		{
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

	// bn::regular_bg_ptr
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

	int flag_int = globals->all_save.language;
	auto flag = bn::sprite_items::flags.create_sprite(72, -48, flag_int);
	flag.set_visible(false);

	bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
	bn::vector<bn::sprite_ptr, 32> file1_spr;
	bn::string<32> buf1;

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
			bn::music_items::title.play(0.8);
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
			flag.set_visible(true);
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

		if (flag.visible())
		{
			if (bn::keypad::l_pressed())
			{
				flag_int--;
				if (flag_int < 0)
					flag_int = 2;
				flag = bn::sprite_items::flags.create_sprite(72, -48, flag_int);
				bn::sound_items::ui_sfx02.play();
			}
			else if (bn::keypad::r_pressed())
			{
				flag_int++;
				if (flag_int > 2)
					flag_int = 0;
				flag = bn::sprite_items::flags.create_sprite(72, -48, flag_int);
				bn::sound_items::ui_sfx02.play();
			}

			globals->all_save.language = flag_int;

			switch (flag_int)
			{
			case 0:
			{
				buf1 = "Press Start to Continue";
				file1_spr.clear();
				file1_gen.generate(-72, 52, buf1.c_str(), file1_spr);
				break;
			}
			case 1:
			{
				buf1 = "Appuyez sur Start pour continuer";
				file1_spr.clear();
				file1_gen.generate(-72 - 32, 52, buf1.c_str(), file1_spr);
				break;
			}
			case 2:
			{
				buf1 = "Pulsa Start para continuar";
				file1_spr.clear();
				file1_gen.generate(-72 - 24, 52, buf1.c_str(), file1_spr);
				break;
			}
			}
		}

		flag.set_y(lerp(flag.y(), -64, 0.2));

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

	if (DEVICE_TYPE == 0)
	{
		auto ui = bn::regular_bg_items::file_select_bg.create_bg(0, 0);
		auto arrow = bn::sprite_items::arrow.create_sprite(-98, -32);

		bn::sprite_text_generator file2_gen(common::variable_8x16_sprite_font);
		bn::sprite_text_generator file3_gen(common::variable_8x16_sprite_font);
		bn::sprite_text_generator file4_gen(common::variable_8x16_sprite_font);
		bn::sprite_text_generator file5_gen(common::variable_8x16_sprite_font);
		bn::vector<bn::sprite_ptr, 12> file2_spr;
		bn::vector<bn::sprite_ptr, 12> file3_spr;
		bn::vector<bn::sprite_ptr, 36> file4_spr;
		bn::vector<bn::sprite_ptr, 36> file5_spr;

		bn::string<12> buf2;
		bn::string<12> buf3;
		bn::string<36> buf4;
		bn::string<36> buf5;

		switch (globals->all_save.language)
		{
		case 0:
		{
			file4_gen.generate(-98, -64, "Press A to Continue", file4_spr);
			file5_gen.generate(-112, 64, "Hold L and R to Delete Save", file5_spr);
			break;
		}
		case 1:
		{
			file4_gen.generate(-98, -64, "Appuyez sur A pour continuer", file4_spr);
			file5_gen.generate(-112, 64, "Maintenez L&R pour supprimer le file", file5_spr);
			break;
		}
		case 2:
		{
			file4_gen.generate(-98, -64, "Pulsa A para continuar", file4_spr);
			file5_gen.generate(-112, 64, "Manten L y R para Eliminar Datos", file5_spr);
			break;
		}
		}

		file1_gen.generate(-72, -32, buf1.c_str(), file1_spr);

		if (globals->all_save.current_save[0].island_name[0] < 123 && globals->all_save.current_save[0].island_name[0] > 0)
		{
			bn::ostringstream ss1(buf1);
			for (short int t = 0; t < 16; t++)
			{
				if (globals->all_save.current_save[0].island_name[t] > 31 && globals->all_save.current_save[0].island_name[t] < 123)
				{
					ss1 << globals->all_save.current_save[0].island_name[t];
				}
			}
			if (globals->all_save.current_save[0].xp == -1)
				globals->all_save.current_save[0].xp = 0;
			ss1 << ": ";
			ss1 << (int)(globals->all_save.current_save[0].checkpoint * 6.6);
			ss1 << "%";
		}
		else
		{
			buf1 = "1: 0%";
		}

		if (globals->all_save.current_save[1].island_name[0] < 123 && globals->all_save.current_save[1].island_name[0] > 0)
		{
			bn::ostringstream ss1(buf2);
			for (short int t = 0; t < 16; t++)
			{
				if (globals->all_save.current_save[1].island_name[t] > 31 && globals->all_save.current_save[1].island_name[t] < 123)
				{
					ss1 << globals->all_save.current_save[1].island_name[t];
				}
			}
			if (globals->all_save.current_save[1].xp == -1)
				globals->all_save.current_save[1].xp = 0;
			ss1 << ": ";
			ss1 << (int)(globals->all_save.current_save[1].checkpoint * 6.6);
			ss1 << "%";
		}
		else
		{
			buf2 = "2: 0%";
		}

		if (globals->all_save.current_save[2].island_name[0] < 123 && globals->all_save.current_save[2].island_name[0] > 0)
		{
			bn::ostringstream ss1(buf3);
			for (short int t = 0; t < 16; t++)
			{
				if (globals->all_save.current_save[2].island_name[t] > 31 && globals->all_save.current_save[2].island_name[t] < 123)
				{
					ss1 << globals->all_save.current_save[2].island_name[t];
				}
			}
			if (globals->all_save.current_save[2].xp == -1)
				globals->all_save.current_save[2].xp = 0;
			ss1 << ": ";
			ss1 << (int)(globals->all_save.current_save[2].checkpoint * 6.6);
			ss1 << "%";
		}
		else
		{
			buf3 = "3: 0%";
		}

		file1_gen.generate(-72, -32, buf1.c_str(), file1_spr);
		file2_gen.generate(-72, 0, buf2.c_str(), file2_spr);
		file3_gen.generate(-72, 32, buf3.c_str(), file3_spr);

		auto file1_icon = bn::sprite_items::save_tiles.create_sprite(98, -34, 0);
		auto file2_icon = bn::sprite_items::save_tiles.create_sprite(98, -34 + 34, 0);
		auto file3_icon = bn::sprite_items::save_tiles.create_sprite(98, -34 + 68, 0);

		if (globals->all_save.current_save[0].last_char_id > -1 && globals->all_save.current_save[0].last_char_id < 7)
			file1_icon = bn::sprite_items::save_tiles.create_sprite(98, -34, globals->all_save.current_save[0].last_char_id);
		else
			file1_icon.set_visible(false);

		if (globals->all_save.current_save[1].last_char_id > -1 && globals->all_save.current_save[1].last_char_id < 7)
			file2_icon = bn::sprite_items::save_tiles.create_sprite(98, 0, globals->all_save.current_save[1].last_char_id);
		else
			file2_icon.set_visible(false);

		if (globals->all_save.current_save[2].last_char_id > -1 && globals->all_save.current_save[2].last_char_id < 7)
			file3_icon = bn::sprite_items::save_tiles.create_sprite(98, 34, globals->all_save.current_save[2].last_char_id);
		else
			file3_icon.set_visible(false);

		short int t = 0;
		short int c = 0;

		bn::music_items::multisong.play(0.8); // velvet

		while (!bn::keypad::a_pressed())
		{
			if (bn::keypad::l_held() && bn::keypad::r_held())
			{
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
		switch (c)
		{
		case 0:
		{
			file1_icon.set_visible(true);
			file2_icon.set_visible(false);
			file3_icon.set_visible(false);
			break;
		}
		case 1:
		{
			file1_icon.set_visible(false);
			file2_icon.set_visible(true);
			file3_icon.set_visible(false);
			break;
		}
		case 2:
		{
			file1_icon.set_visible(false);
			file2_icon.set_visible(false);
			file3_icon.set_visible(true);
			break;
		}
		default:
		{
		}
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
		for (int tt = 0; tt < 7; tt++)
		{
			globals->current_save->popups[tt] = false;
		}
	}

	// if saving doesn't work
	else
	{
		auto a_button = bn::sprite_items::a_button.create_sprite(90, -48, (globals->all_save.language * 2));

		short int t = 0;
		short int c = 0;

		bn::music_items::multisong.play(0.8); // velvet

		bn::vector<bn::sprite_ptr, 6> icons;
		auto t1 = bn::sprite_items::chapters.create_sprite(0, 0, 0);
		icons.push_back(t1);
		auto t2 = bn::sprite_items::chapters.create_sprite(150, 0, 1);
		icons.push_back(t2);
		auto t3 = bn::sprite_items::chapters.create_sprite(260, 0, 2);
		icons.push_back(t3);
		auto t4 = bn::sprite_items::chapters.create_sprite(370, 0, 3);
		icons.push_back(t4);
		auto t5 = bn::sprite_items::chapters.create_sprite(480, 0, 4);
		icons.push_back(t5);
		auto t6 = bn::sprite_items::chapters.create_sprite(590, 0, 5);
		icons.push_back(t6);

		while (!bn::keypad::a_pressed())
		{
			if (bn::keypad::l_held() && bn::keypad::r_held())
			{
				// flash_reset();
				globals->all_save.current_save[c].clear();
				bn::core::reset();
			}

			if (bn::keypad::left_pressed())
			{
				c--;
				bn::sound_items::click.play();
			}
			if (bn::keypad::right_pressed())
			{
				c++;
				bn::sound_items::click.play();
			}

			if (c > 5)
				c = 0;
			if (c < 0)
				c = 5;

			for (int t = 0; t < icons.size(); t++)
			{
				bn::fixed_t new_x = lerp(icons.at(t).x(), (t - c) * 100, 0.2);
				icons.at(t).set_x(new_x);
				if (t != c)
					icons.at(t).set_scale(1, 1);
			}
			icons.at(c).set_scale(1.5, 1.5);

			switch (c)
			{
			case 0:
			{
				file1_spr.clear();
				file1_gen.generate(-81, -72, "L'INTRODUCTION", file1_spr);
				break;
			}
			case 1:
			{
				file1_spr.clear();
				file1_gen.generate(-81, -72, "CHAPITRE 1", file1_spr);
				break;
			}
			case 2:
			{
				file1_spr.clear();
				file1_gen.generate(-81, -72, "CHAPITRE 2", file1_spr);
				break;
			}
			case 3:
			{
				file1_spr.clear();
				file1_gen.generate(-81, -72, "CHAPITRE 3", file1_spr);
				break;
			}
			case 4:
			{
				file1_spr.clear();
				file1_gen.generate(-81, -72, "CHAPITRE 4", file1_spr);
				break;
			}
			case 5:
			{
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

		for (int t = 0; t < icons.size(); t++)
		{
			if (t != c)
				icons.at(t).set_visible(false);
		}

		bn::sound_items::firehit.play();
		bn::music::stop();
		timer(64);

		globals->current_save->clear();

		switch (c)
		{
		case 1:
		{
			globals->current_save->xp = 0;
			globals->current_save->checkpoint = 1;
			break;
		}
		case 2:
		{
			globals->current_save->xp = 100;
			globals->current_save->checkpoint = 7;
			break;
		}
		case 3:
		{
			globals->current_save->xp = 200;
			globals->current_save->checkpoint = 9;
			break;
		}
		case 4:
		{
			globals->current_save->xp = 300;
			globals->current_save->checkpoint = 12;
			break;
		}
		case 5:
		{
			globals->current_save->xp = 300;
			globals->current_save->checkpoint = 14;
			break;
		}
		}

		// remove panels
		for (int tt = 0; tt < 7; tt++)
		{
			globals->current_save->popups[tt] = false;
		}
	}
}

void cutscenes(int c)
{
	if (c == 0)
	{
		bn::music_items::z01_maple_is_sad.play(0.8);
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

	switch (chari)
	{
	case 0:
	{
		victory_anim = bn::create_sprite_animate_action_forever(victory_spr, 5, bn::sprite_items::maple_victory_anim.tiles_item(),
																0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26);
		victory_anim2 = bn::create_sprite_animate_action_forever(victory_spr2, 5, bn::sprite_items::maple_victory_anim.tiles_item(),
																 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27);
		break;
	}
	case 2:
	{
		victory_anim = bn::create_sprite_animate_action_forever(victory_spr, 3, bn::sprite_items::aaron_victory_anim.tiles_item(),
																0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 30, 30, 30, 30, 30, 30, 30, 30);
		victory_anim2 = bn::create_sprite_animate_action_forever(victory_spr2, 3, bn::sprite_items::aaron_victory_anim.tiles_item(),
																 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 31, 31, 31, 31, 31, 31, 31, 31);
		break;
	}
	default:
	{
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
	case 0:
	{
		modifier = 0.13;
		break;
	}
	case 1:
	{ // Garden
		modifier = 0.035;
		break;
	}
	case 2:
	{
		modifier = 0.065;
		break;
	}
	default:
	{
		break;
	}
	}

	short int xp = globals->current_save->xp;
	if (xp == -1)
		xp = 0;

	bn::fixed_t<12> new_xp = xp + (modifier * score);

	if (globals->current_save->checkpoint < 15)
	{
		if (new_xp > 300)
			new_xp = 300;
	}
	else if (globals->current_save->checkpoint < 9)
	{
		if (new_xp > 200)
			new_xp = 200;
	}
	else
	{
		if (globals->current_save->checkpoint < 6)
		{
			if (new_xp > 100)
				new_xp = 100;
		}
		else if (new_xp > 50)
			new_xp = 50;
	}

	globals->current_save->xp = new_xp.integer(); // Add score to save total

	int grade = 3;
	bn::fixed_t<12> new_addition = (modifier * score);
	if (new_addition < 40)
		grade = 0;
	if (new_addition < 30)
		grade = 1;
	if (new_addition < 20)
		grade = 2;
	if (new_addition < 10)
		grade = 3;

	int chap = 4;
	if (globals->current_save->checkpoint < 11)
		chap = 3;
	if (globals->current_save->checkpoint < 9)
		chap = 2;
	if (globals->current_save->checkpoint < 5)
		chap = 1;

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

		switch (chari)
		{
		case 0:
		{
			victory_spr.set_palette(bn::sprite_items::maple_victory_anim.palette_item());
			victory_spr2.set_palette(bn::sprite_items::maple_victory_anim.palette_item());
			break;
		}
		case 2:
		{
			victory_spr.set_palette(bn::sprite_items::aaron_victory_anim.palette_item());
			victory_spr2.set_palette(bn::sprite_items::aaron_victory_anim.palette_item());
			break;
		}
		default:
		{
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

	bn::music_items::new_castle.play(bn::fixed(50) / 100);
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

		auto b_button = bn::sprite_items::b_button.create_sprite(90, -50, globals->all_save.language);
		b_button.set_visible(false);

		auto stump = bn::sprite_items::tree_stump.create_sprite(-32, 39, 0);

		bn::fixed_t<12> curs = 0;
		short int width = 16;
		short int calc_width = width * 4;
		short int max_chop = 4;
		short int hits = 1;
		bool left = false;
		short int wood_stage = 0;

		auto key = bn::sprite_items::magic_keys.create_sprite(-128, 0, 7);
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
			if (key.visible())
			{
				if (key.x() < 72)
				{
					key.set_position(key.x() + 0.75, 0);
				}
				else
				{
					key.set_visible(false);
				}
			}

			// Stage of the stump
			switch (wood_stage)
			{
			default:
			{
				stump = bn::sprite_items::tree_stump.create_sprite(-32, 38, 0);
				wood_stage += 1;
				break;
			}
			case 1:
			{
				stump.set_y(39);
				wood_stage += 1;
				break;
			}
			case 2:
			{
				if (bn::keypad::a_held())
				{
					stump = bn::sprite_items::tree_stump.create_sprite(-32, 39, 1);
					wood_stage += 1;
				}
				break;
			}
			case 3:
			{
				break;
			}
			case 4:
			{
				stump = bn::sprite_items::tree_stump.create_sprite(-32, 39, 2);
				wood_stage += 1;
				break;
			}
			case 5:
			{
				stump.set_y(stump.y() + 4);
				if (stump.y().integer() > 128)
					wood_stage += 1;
				break;
			}
			case 6:
			{
				stump = bn::sprite_items::tree_stump.create_sprite(-32, 38, 0);
				bn::sound_items::pop.play();
				wood_stage = 1;
			}
			}

			// Ready to go notif
			if (!can_have_sp && score > 100)
			{
				bn::sound_items::aaron_yeah_01.play();
				b_button.set_visible(true);
				can_have_sp = true;
			}

			if (bn::keypad::a_released())
			{
				sq1_sw = bn::create_sprite_animate_action_once(sq1_spr, 1, bn::sprite_items::aaron_axe_anim.tiles_item(), 26, 6, 8, 10);
				sq2_sw = bn::create_sprite_animate_action_once(sq2_spr, 1, bn::sprite_items::aaron_axe_anim.tiles_item(), 27, 7, 9, 11);
				sq3_sw = bn::create_sprite_animate_action_once(sq3_spr, 1, bn::sprite_items::aaron_axe_anim.tiles_item(), 38, 34, 36, 36);
				sq4_sw = bn::create_sprite_animate_action_once(sq4_spr, 1, bn::sprite_items::aaron_axe_anim.tiles_item(), 39, 35, 37, 37);
			}

			if (bn::keypad::a_held())
			{
				sq1_spr = sq1_sw.sprite();
				sq2_spr = sq2_sw.sprite();
				sq3_spr = sq3_sw.sprite();
				sq4_spr = sq4_sw.sprite();
				if (!sq1_sw.done())
				{
					sq1_sw.update();
					sq2_sw.update();
					sq3_sw.update();
					sq4_sw.update();
				}
			}
			else
			{
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
			if (wing < 0.01)
				wing = 0;
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
			{ // left
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
						if (chop.at(t).visible())
						{
							penalty = true;
							score = score / 2;
						}
					}

					if (penalty)
					{
						short int ugh = std_rnd(3);
						switch (ugh)
						{
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

					if (std_rnd(64) == 2 && globals->current_save->keys[0] != 1)
					{
						key.set_visible(true);
						key.set_position(-72, 0);
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
				if (key.visible() && std_abs(curs_loc.integer() - key.x().integer()) < 16)
				{
					bn::sound_items::cnaut.play();
					key.set_visible(false);
					bn::core::update();

					line lc[32] = {
						{true, true, 00, "You got a key!                   Unlock all the keys for a        a special surprise."},
						{true, true, 00, "COM: Endscene"}};
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

						if (t == max_chop - 1 && wood_stage < 4)
						{
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

	if (can_have_sp)
	{
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

		if (x_vector > 0)
		{
			sprite.set_horizontal_flip(true);
		}
		else
		{
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
		for (short int t = 0; t < current_room.width * current_room.height; t++)
		{
			globals->collisions.push_back(local_col[t]);
		}

		bn::vector<rabbit, 32> rabbits;
		auto max_rabbits = 32;

		bn::regular_bg_ptr garden_bg = bn::regular_bg_items::garden_bg.create_bg(0, 0);
		garden_bg.set_camera(current_room.camera);

		bool isHolding = false;

		globals->local_tileset.clear();
		globals->collisions.clear();

		if (bn::music::playing())
			bn::music::stop();
		bn::music_items::z10_enoki_theme.play(0.8);

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

		auto key = bn::sprite_items::magic_keys.create_sprite(-172, 0, 7);
		key.set_camera(current_room.camera);
		key.set_visible(false);

		current_room.init_render(0, 0);
		int ready = 0;
		while (playing)
		{
			if (!key.visible())
			{
				ready++;
				if (globals->current_save->keys[1] != 1 && ready == 1024)
				{
					ready = 0;
					key.set_visible(true);
				}
			}
			else
			{
				key.set_x(key.x() + 2);
				if (key.x() > 256)
				{
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

			if (isHolding)
			{
				enoki.entity.set_position(enoki_hold.x(), enoki_hold.y());
				enoki_hold.set_visible(true);
				enoki.entity.set_visible(false);

				if (bn::keypad::down_pressed())
					dir = 0;
				if (bn::keypad::left_pressed())
					dir = 2;
				if (bn::keypad::right_pressed())
					dir = 1;
				if (bn::keypad::up_pressed())
					dir = 3;

				if (dir != last_dir)
				{
					enoki_hold = bn::sprite_items::enoki_walking_spring.create_sprite(enoki_hold.x(), enoki_hold.y(), 12 + dir);
					enoki_hold.set_camera(current_room.camera);
					last_dir = dir;
				}
			}
			else
			{
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

				if (std_abs(enoki.entity.x().integer() - key.x().integer()) + std_abs(enoki.entity.y().integer() - key.y().integer()) < 32)
				{
					bn::sound_items::cnaut.play();
					key.set_visible(false);
					bn::core::update();

					line lc[32] = {
						{true, true, 00, "You got a key!                   Unlock all the keys for a        a special surprise."},
						{true, true, 00, "COM: Endscene"}};
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

		bn::music_items::z11_maple_theme.play(0.8);
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
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
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
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1};
		for (short int t = 0; t < current_room.width * current_room.height; t++)
		{
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

		if ((abx * -1) > abx)
			abx = abx * 1;
		if ((aby * -1) > aby)
			aby = aby * 1;

		bn::sprite_ptr treasure = bn::sprite_items::underground_tiles.create_sprite(abs(abx) * 32, abs(aby) * 32, 1);
		treasure.set_camera(current_room.camera);
		bn::string<8> score_text = bn::to_string<8>(score);

		auto key = bn::sprite_items::magic_keys.create_sprite(-172, 0, 7);
		key.set_camera(current_room.camera);
		key.set_visible(false);

		if (globals->current_save->keys[2] != 1)
		{
			while (globals->local_tileset.at(abz) > 0)
			{
				abx = std_abs(std_rnd(current_room.width - 6));
				aby = std_abs(std_rnd(current_room.height - 6));
				abz = std_abs(abx + (current_room.width * aby));
			}

			if ((abx * -1) > abx)
				abx = abx * 1;
			if ((aby * -1) > aby)
				aby = aby * 1;

			key.set_position(32 * abx, 32 * aby);
			key.set_visible(true);
		}

		current_room.a_notif.set_visible(false);
		while (!is_returned)
		{
			if (key.visible())
			{
				if (std_abs(maple.entity.x().integer() - key.x().integer()) + std_abs(maple.entity.y().integer() - key.y().integer()) < 32)
				{
					bn::sound_items::cnaut.play();
					key.set_visible(false);
					globals->rendered_windows.at(0).set_show_sprites(true);
					bn::core::update();

					line lc[32] = {
						{true, true, 00, "You got a key!                   Unlock all the keys for a        a special surprise."},
						{true, true, 00, "COM: Endscene"}};
					dialogue_page_lite(lc);

					globals->rendered_windows.at(0).set_show_sprites(false);
					globals->current_save->keys[2] = 1;
				}
			}

			score_text = bn::to_string<8>(score);
			file_spr.clear();
			file_gen.generate(0, -48, score_text, file_spr);
			current_room.a_notif.set_visible(false);

			if (abs((current_room.start_y * 32) - maple.entity.y().integer()) < 32 && abs((current_room.start_x * 32) - maple.entity.x().integer()) < 32)
			{
				current_room.start_notif(0);

				if (bn::keypad::a_pressed())
				{
					is_returned = true;
					globals->rendered_windows.at(0).set_show_sprites(true);
				}

				if (!treasure.visible())
				{
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
					if (std_rnd(2) == 1)
					{
						bn::sound_items::maple_ugh_01.play();
					}
					else
					{
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

	if (is_victory)
	{
		victory_page(0, score);
	}

	dungeon_return dt(1, 5, 4);
	return dt;
}

bool ball_breakout()
{
	bool leave = false;

	while (!leave)
	{

		bn::camera_ptr camera = bn::camera_ptr::create(30, 42);

		bn::vector<bn::sprite_ptr, 54> tiles;
		auto ball = bn::sprite_items::bb_sprites.create_sprite(32, 56, 6);
		ball.set_scale(1, 1);
		ball.set_camera(camera);
		auto paddle = bn::sprite_items::bb_sprites.create_sprite(32, 72);
		paddle.set_scale(2, 1);
		paddle.set_camera(camera);

		for (int x = 0; x < 9; x++)
		{
			for (int y = 0; y < 5; y++)
			{
				auto bb = bn::sprite_items::bb_sprites.create_sprite(x * 8, y * 8, y);
				bb.set_camera(camera);
				tiles.push_back(bb);
			}
		}

		short int d_x = 1;
		short int d_y = 1;

		while (ball.y() < 75 && !leave)
		{

			if (bn::keypad::b_pressed())
				leave = true;

			ball.set_position(ball.x() + d_x, ball.y() + d_y);

			if (ball.y() == 64 && (abs(ball.x() - paddle.x()) < 16))
			{
				d_y = -1;
				if (ball.x() > paddle.x())
				{
					d_x = 1;
				}
				else
				{
					d_x = -1;
				}
				if (abs(ball.x() - paddle.x()) > 8)
					d_x = d_x * 2;
				bn::sound_items::pop.play();
			}
			if (ball.y() < 1)
				d_y = 1;
			if (ball.x() > 63)
				d_x = d_x * -1;
			if (ball.x() < 1)
				d_x = d_x * -1;

			bool complete = true;
			for (short int t = 0; t < tiles.size(); t++)
			{
				if (tiles.at(t).visible())
				{
					complete = false;
					if (abs(tiles.at(t).x() - ball.x()) < 4)
					{
						if (abs(tiles.at(t).y().integer() - ball.y()) < 8)
						{
							d_y = 1;
							tiles.at(t).set_visible(false);
							bn::sound_items::firehit.play();
						}
					}
				}
			}

			if (complete)
				return true;

			if (bn::keypad::left_held() && paddle.x() > 8)
			{
				paddle.set_x(paddle.x() - 3);
			}

			if (bn::keypad::right_held() && paddle.x() < 63)
			{
				paddle.set_x(paddle.x() + 3);
			}

			bn::core::update();
		}

		bn::sound_items::squeak.play();
	}

	return false;
}

dungeon_return computer()
{
	bn::music::stop();

	auto pc_bg = bn::regular_bg_items::pc_background.create_bg(0, 0);
	auto pc_scout = bn::regular_bg_items::pc_scout.create_bg(0, 0);
	auto pc_cursor = bn::sprite_items::pc_cursor.create_sprite(0, 0, 1);
	auto b_button = bn::sprite_items::b_button.create_sprite(90, -50, globals->all_save.language);

	pc_bg.put_above();

	pc_scout.set_blending_enabled(true);
	bn::blending::set_transparency_alpha(0);
	bn::sound_items::pc_whir.play();

	short int ticks = 0;
	bn::fixed_t<12> alpha = 0;
	short int select = 0;
	while (!bn::keypad::b_pressed())
	{

		pc_cursor.set_position(
			pc_cursor.x().integer() + bn::keypad::right_held() - bn::keypad::left_held(),
			pc_cursor.y().integer() + bn::keypad::down_held() - bn::keypad::up_held());

		if (pc_cursor.x() < -30)
			pc_cursor.set_x(-30);
		if (pc_cursor.x() > 55)
			pc_cursor.set_x(55);
		if (pc_cursor.y() < -35)
			pc_cursor.set_y(-35);
		if (pc_cursor.y() > 30)
			pc_cursor.set_y(30);

		if (ticks > 64)
		{
			if (alpha < 1)
			{
				if (alpha == 0)
				{
					bn::sound_items::pc_boot.play();
				}
				bn::blending::set_transparency_alpha(alpha);
				alpha += 0.05;
			}
			else
			{
				bn::blending::set_transparency_alpha(bn::fixed(1));
			}
		}

		if (ticks == 108)
		{
			pc_cursor = bn::sprite_items::pc_cursor.create_sprite(0, 0, 0);
			pc_scout.set_blending_enabled(false);
			bn::blending::set_transparency_alpha(bn::fixed(0.5));
		}

		if (ticks > 108)
		{
			if (bn::keypad::a_pressed() && pc_cursor.visible())
			{
				if (pc_cursor.x().integer() < -14 && pc_cursor.y().integer() < 12)
				{
					if (pc_cursor.y().integer() < -9)
					{
						pc_scout = bn::regular_bg_items::pc_folder02.create_bg(0, 0);
						select = 2;
					}
					else
					{
						pc_scout = bn::regular_bg_items::pc_folder01.create_bg(0, 0);
						select = 1;
					}
				}
				else
				{
					if (pc_cursor.y() > -14 && pc_cursor.y() < 4)
					{

						// Trash Folder
						if (select == 2)
						{
							if (pc_cursor.x() > 14 && pc_cursor.x() < 33)
							{
								pc_scout = bn::regular_bg_items::pc_document.create_bg(0, 0);
								pc_bg.put_above();

								bn::core::update();
								b_button.set_visible(false);
								exec_dialogue(23);
								pc_scout = bn::regular_bg_items::pc_folder02.create_bg(0, 0);
								b_button.set_visible(true);
							}
							else if (pc_cursor.x() > 32 && pc_cursor.x() < 51)
							{
								pc_scout = bn::regular_bg_items::pc_document.create_bg(0, 0);
								pc_bg.put_above();

								bn::core::update();
								b_button.set_visible(false);
								exec_dialogue(24);
								pc_scout = bn::regular_bg_items::pc_folder02.create_bg(0, 0);
								b_button.set_visible(true);
							}
							else if (pc_cursor.x() > 50 && pc_cursor.x() < 70)
							{
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
						else if (select == 1)
						{
							if (pc_cursor.x() > 14 && pc_cursor.x() < 33)
							{
								bn::music_items::z19_digital.play(0.8);
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
								if (success)
									exec_dialogue(26);
							}
							else if (pc_cursor.x() > 32 && pc_cursor.x() < 51)
							{
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
					else
					{
						pc_scout = bn::regular_bg_items::pc_desktop.create_bg(0, 0);
						select = 0;
					}
				}
			}
		}

		if (ticks == 128)
		{
			pc_scout = bn::regular_bg_items::pc_desktop.create_bg(0, 0);
		}

		if (ticks < 256)
			ticks++;
		pc_bg.put_above();
		bn::core::update();
	}

	dungeon_return dt(4, 7, 6);
	return dt;
}

void victory_toutes(int emotion, int total)
{

	bn::core::update();

	int new_xp = globals->current_save->xp + (total / 10);

	if (globals->current_save->checkpoint < 15)
	{
		if (new_xp > 300)
			new_xp = 300;
	}
	else if (globals->current_save->checkpoint < 9)
	{
		if (new_xp > 200)
			new_xp = 200;
	}
	else
	{
		if (globals->current_save->checkpoint < 6)
		{
			if (new_xp > 100)
				new_xp = 100;
		}
		else if (new_xp > 50)
			new_xp = 50;
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

	auto b_button = bn::sprite_items::b_button.create_sprite(90, 0, globals->all_save.language);
	b_button.set_visible(false);

	int chap = 2;
	if (globals->current_save->checkpoint > 8)
		chap = 3;

	bool ready = false;
	victory v(emotion, 6, total, globals->current_save->xp, chap);
	while (!bn::keypad::a_pressed())
	{

		v.update();

		if (w < 36)
		{
			globals->rendered_windows.at(1).set_boundaries(-130, 116 - w - 12, 172, 116 + w - 12);
			w++;
		}

		if (food.y().integer() < -24)
		{
			food.set_y(food.y() + 1);
		}

		if (food.y().integer() == -24 && !ready)
		{
			ready = true;
			bn::sound_items::start.play();
			face = bn::sprite_items::toutes_spr.create_sprite(-80, -38, emotion);

			switch (emotion)
			{
			case 2:
			{
				buf = "You've got a.. sock.";
				file1_gen.generate(-112, 64, buf.c_str(), file1_spr);
				break;
			}
			case 1:
			{
				buf = "You've got.. mousse!";
				file1_gen.generate(-112, 64, buf.c_str(), file1_spr);
				break;
			}
			case 0:
			{
				buf = "You've got.. a twenty!";
				file1_gen.generate(-112, 64, buf.c_str(), file1_spr);
				break;
			}
			default:
			{
			}
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

dungeon_return crystal_ball()
{

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

		bn::music_items::z13_spooky.play(0.8);

		buttons.push_back(bn::sprite_items::magic_keys.create_sprite(96, 0, 0));
		buttons_n.push_back(0);

		auto b_button = bn::sprite_items::b_button.create_sprite(90, 50, globals->all_save.language);
		b_button.set_visible(true);

		for (short int t = 0; t < 4; t++)
		{
			short int nb = (std_rnd(7));
			short int wd = 16;

			if (buttons.size() > 0)
				wd = buttons.at(buttons.size() - 1).x().integer() + 36;

			buttons.push_back(bn::sprite_items::magic_keys.create_sprite(wd, 0 - pow(wd / 5, 2) / 5, nb));
			buttons_n.push_back(nb);
		}

		short int tick = 0;
		short int angle = 0;

		auto key = bn::sprite_items::magic_keys.create_sprite(0, 0, 7);
		key.set_visible(false);

		int ready = 0;
		int focus = -1;

		hud current_hud;
		while (!bn::keypad::b_pressed())
		{

			if (focus > -1)
			{
				key.set_visible(true);
				key.set_position(buttons.at(focus - 1).x(), buttons.at(focus - 1).y());
				key.put_above();
			}
			else
			{
				key.set_visible(false);
			}

			// Score hud
			bn::fixed_t<12> my_width = total + 1;
			if (my_width > 0)
			{
				my_width = (score + 1) / my_width;
			}
			else
			{
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
			if (tick == 10)
			{
				tick = 0;
				if (score > 0)
					score--;
			}

			if (total < score)
				total = score;

			short int s = 0;
			if (bn::keypad::a_pressed())
				s = 1;
			if (bn::keypad::r_pressed())
				s = 2;
			if (bn::keypad::l_pressed())
				s = 3;
			if (bn::keypad::up_pressed())
				s = 4;
			if (bn::keypad::left_pressed())
				s = 5;
			if (bn::keypad::right_pressed())
				s = 6;
			if (bn::keypad::down_pressed())
				s = 7;

			if (s > 0)
			{
				if (focus > -1)
				{
					focus--;
				}

				if (s - 1 == buttons_n.at(0))
				{
					bn::sound_items::ding.play();
					score += 5;

					if (focus == 0)
					{
						bn::sound_items::cnaut.play();
						key.set_visible(false);
						bn::core::update();

						line lc[32] = {
							{true, true, 00, "You got a key!                   Unlock all the keys for a        a special surprise."},
							{true, true, 00, "COM: Endscene"}};
						dialogue_page_lite(lc);

						globals->current_save->keys[3] = 1;

						ready = 0;
						focus = -1;
					}
				}
				else
				{
					bn::sound_items::firehit.play();
					score = 0;

					if (focus == 0)
					{
						ready = 0;
						focus = -1;
					}
				}

				buttons.erase(buttons.begin());
				buttons_n.erase(buttons_n.begin());

				short int nb = (std_rnd(7));
				short int wd = 16;

				if (buttons.size() > 0)
					wd = buttons.at(buttons.size() - 1).x().integer() + 36;

				buttons.push_back(bn::sprite_items::magic_keys.create_sprite(wd, 0 - pow(wd / 5, 2) / 5, nb));
				buttons_n.push_back(nb);

				if (globals->current_save->keys[3] != 1)
					ready++;
				if (ready > 42 && focus == -1)
					focus = buttons_n.size() - 1;
			}

			if (buttons.at(0).x() > 0)
			{
				for (short int t = 0; t < buttons.size(); t++)
				{
					short int nw = buttons.at(t).x().integer() - 4;
					buttons.at(t).set_position(nw, 0 - pow(nw / 5, 2) / 5);
				}
			}

			bn::core::update();
		}
	}

	short int emotion = 2;
	if (total > 100)
		emotion = 1;
	if (total > 200)
		emotion = 0;

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

struct rock
{
	bn::sprite_ptr entity = bn::sprite_items::avocado.create_sprite(0, -20, 5);
	bn::fixed_t<12> size = 0.01;
	bn::fixed_t<12> m_y = -48;
	short int speed = 0;
};

dungeon_return boat_game()
{

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

		if (bn::music::playing())
			bn::music::stop();
		bn::music_items::z21_pools.play(0.8);

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

		for (int t = 0; t < 4; t++)
		{
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
		for (short int t = 0; t < 8; t++)
		{
			rock r;
			rs[t] = r;
		}

		short int isMoving = 0;
		short int distance = 16;
		short int tick = 0;

		bool completed = false;
		bn::fixed_t<12> completed_size = 0.48;

		hud current_hud;
		while (completed_size > 0.02)
		{

			if (distance < 1)
				completed = true;
			if (distance < 0)
				distance = 0;
			if (total < score)
				total = score;

			if (!completed)
			{
				isMoving = !bn::keypad::down_held();
				if (bn::keypad::down_released())
					bn::sound_items::fireblast.play();
				if (bn::keypad::up_pressed())
					bn::sound_items::fireblast.play();
				if (bn::keypad::up_held())
					isMoving = 2;
			}
			else
			{
				isMoving = 0;
			}

			tick++;
			if (tick > 256)
			{
				tick = 0;
				distance -= isMoving;
			}

			for (short int t = 0; t < 8; t++)
			{

				if (abs(rs[t].entity.x() - boat.x()) < 24 && abs(rs[t].entity.y() - boat.y()) < 24)
				{
					rs[t].m_y += 96;
					bn::sound_items::firehit.play();
					score = score / 10;
				}

				if (rs[t].m_y > 128)
				{
					if (std_rnd(36 - (16 - (distance / 2))) == 1)
					{

						rs[t].size = 0.01;
						rs[t].entity.set_scale(rs[t].size);
						rs[t].entity.set_x((std_rnd(120)) - 60);
						rs[t].speed = rs[t].entity.x().integer() / 10;

						if (std_rnd(6 - (distance / 10)) == 1)
						{
							rs[t].entity.set_visible(false);
							rs[t].m_y = (0 - (std_rnd(1280)));
							rs[t].entity.set_y(rs[t].m_y);
						}
						else
						{
							score++;
							rs[t].entity.set_visible(true);
							rs[t].m_y = -48;
							rs[t].entity.put_above();
						}
					}
					else
					{
						rs[t].entity.set_y(rs[t].m_y);
						rs[t].m_y += 1;
					}
				}
				else
				{
					if (rs[t].size <= 0)
						rs[t].size = 0.01;
					rs[t].entity.set_scale(rs[t].size);
					rs[t].entity.set_y(rs[t].m_y);

					if (isMoving == 1)
					{
						rs[t].entity.set_x(rs[t].entity.x() + rs[t].speed);
						rs[t].m_y += 1;
						if (rs[t].size < 1)
						{
							rs[t].size += 0.01;
						}
					}
					else if (isMoving == 2)
					{
						rs[t].entity.set_x(rs[t].entity.x() + (rs[t].speed * 2));
						rs[t].m_y += 2;
						if (rs[t].size < 1)
						{
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
			if (isMoving == 0)
			{
				dir_z = bn::fixed::from_data(1); // 1
				wave.set_visible(false);
			}
			else if (isMoving == 2)
			{
				dir_z = bn::fixed::from_data(-196);
			}
			else
			{
				wave.set_visible(true);
			}

			wave_anim.update();
			wave = wave_anim.sprite();
			boat.put_above();

			// Intro animation
			{
				boat = bn::sprite_items::avocado.create_sprite(0, 48, 0);
				if (isMoving > 0)
				{
					if (bn::keypad::left_held())
					{
						x_offset += 0.01;
						dir_x += bn::fixed::from_data(8);
						boat = bn::sprite_items::avocado.create_sprite(0, 48, 2);

						for (short int t = 0; t < 8; t++)
						{
							rs[t].entity.set_x(rs[t].entity.x().integer() + 1);
						}
					}
					else if (bn::keypad::right_held())
					{
						x_offset -= 0.01;
						dir_x -= bn::fixed::from_data(8);
						boat = bn::sprite_items::avocado.create_sprite(0, 48, 1);

						for (short int t = 0; t < 8; t++)
						{
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

			for (short int t = 0; t < sky_ptr.size(); t++)
			{
				sky_ptr.at(t).put_above();
			}

			if (completed)
			{
				boat.set_y(boat.y().integer() - 64);
				wave.set_y(boat.y());
				for (short int t = 0; t < 8; t++)
				{
					rs[t].entity.set_visible(false);
				}
				if (completed_size <= 0)
					completed_size = 0.01;
				boat.set_scale(completed_size);
				wave.set_scale(completed_size);
				bn::fixed_t<12> new_completed_size = completed_size - 0.02;
				if (new_completed_size > 0)
				{
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

		if (globals->current_save->checkpoint < 15)
		{
			if (new_xp > 300)
				new_xp = 300;
		}
		else if (globals->current_save->checkpoint < 9)
		{
			if (new_xp > 200)
				new_xp = 200;
		}
		else
		{
			if (globals->current_save->checkpoint < 6)
			{
				if (new_xp > 100)
					new_xp = 100;
			}
			else if (new_xp > 50)
				new_xp = 50;
		}

		globals->current_save->xp = new_xp;

		bn::music::stop();
		buf = "'Well done! I'll take the";
		file1_gen.generate(-96, -12, buf.c_str(), file1_spr);
		bf3 = "boat on the way back.'";
		file3_gen.generate(-96, 0, bf3.c_str(), file3_spr);

		int grade = 0;
		if (total < 40)
			grade = 1;
		if (total < 30)
			grade = 2;
		if (total < 20)
			grade = 3;

		int chap = 4;
		if (globals->current_save->checkpoint < 11)
			chap = 3;
		if (globals->current_save->checkpoint < 9)
			chap = 2;
		if (globals->current_save->checkpoint < 5)
			chap = 1;

		victory v(grade, 7, total, globals->current_save->xp, chap);
		while (!bn::keypad::a_pressed())
		{
			auto docks = bn::regular_bg_items::bg_dock.create_bg(0, 0);
			v.update();

			bn::core::update();
		}
	}

	dungeon_return dt(9, 17, 4);
	return dt;
}

dungeon_return store()
{

	// Set up sprites
	auto bg = bn::regular_bg_items::cruz_01.create_bg(0, 0);
	short int item = -1;
	auto b_button = bn::sprite_items::b_button.create_sprite(90, -50, globals->all_save.language);
	auto item_hat = bn::sprite_items::funny_items.create_sprite(-80, 32, 0);
	auto item_bal = bn::sprite_items::funny_items.create_sprite(80, 32, 2);

	if (globals->current_save->hat_world > -1)
		item_hat = bn::sprite_items::funny_items.create_sprite(-80, 32, 2);

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
	while (!bn::keypad::b_pressed())
	{

		if (bn::keypad::a_pressed())
		{
			if (globals->current_save->hat_world == -1 && item == -1 && globals->current_save->xp >= 75)
			{
				bn::sound_items::ching.play();
				item_hat = bn::sprite_items::funny_items.create_sprite(-80, 32, 2);
				item_hat.set_scale(2, 2);
				globals->current_save->xp -= 75;
				globals->current_save->hat_char = globals->current_save->last_char_id;
				globals->current_save->hat_world = 14;

				b_button.set_visible(false);
				bn::core::update();

				line lc[32] = {
					{true, true, 00, "Merci!!                          I know you'll love it!"},
					{true, true, 00, "COM: Endscene"}};
				dialogue_page_lite(lc);

				xp_spr.clear();
				string = "";
				string_stream << "$";
				string_stream << globals->current_save->xp;
				file1_gen.generate(64, -48, string_stream.str().c_str(), xp_spr);

				b_button.set_visible(true);
			}
			else
			{
				bn::sound_items::firehit.play();
			}
		}

		if (bn::keypad::left_pressed() || bn::keypad::right_pressed())
		{
			bn::sound_items::pop.play();
			item = item * -1;
		}

		if (item == -1)
		{
			item_spr.clear();
			file2_gen.generate(-114, -58, "BANANA HAT", item_spr);
			desc_spr.clear();
			file3_gen.generate(-114, -70, "Price: $75", desc_spr);

			if (item_hat.y() > 32 - 8)
				item_hat.set_y(item_hat.y() - 1);
			if (item_bal.y() < 32)
				item_bal.set_y(item_bal.y() + 1);
		}
		else
		{
			item_spr.clear();
			file2_gen.generate(-114, -58, "COMING SOON ITEM", item_spr);
			desc_spr.clear();
			file3_gen.generate(-114, -70, "Price: N/A", desc_spr);

			if (item_bal.y() > 32 - 8)
				item_bal.set_y(item_bal.y() - 1);
			if (item_hat.y() < 32)
				item_hat.set_y(item_hat.y() + 1);
		}

		bn::core::update();
	}

	dungeon_return dt(3, 8, 14);
	return dt;
}

class ingredient
{
public:
	bn::sprite_ptr entity = bn::sprite_items::gumbo.create_sprite(0, 0, 0);
	short int type = 0;
};

dungeon_return kitchen()
{

	short int score = 0;

	bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
	bn::vector<bn::sprite_ptr, 32> file1_spr;

	bn::music_items::z25_funky.play(0.8);

	bn::string<32> buf1;

	// Cooking bit
	{
		auto tr_bg = bn::regular_bg_items::axe_game_bg.create_bg(0, 0);
		auto pc_bg = bn::regular_bg_items::bg_cooking_01.create_bg(8, 0);
		short int chari = 0;

		bn::sprite_ptr hand = bn::sprite_items::gumbo.create_sprite(0, 0, 14);

		hud current_hud;
		while (chari < 7)
		{

			short int je_veus_de = 8 + std_rnd(4);

			switch (chari)
			{
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
			default:
			{
			};
			}

			ingredient food[6];
			bn::sprite_ptr je_veus_de_food = bn::sprite_items::gumbo.create_sprite(40, -36, je_veus_de);

			food[0].entity = bn::sprite_items::gumbo.create_sprite(-42, -39 + 48, 13); // Knife
			food[1].entity = bn::sprite_items::gumbo.create_sprite(-10, -39 + 38, 0);
			food[2].entity = bn::sprite_items::gumbo.create_sprite(-10, -39 + 57, 1);
			food[3].entity = bn::sprite_items::gumbo.create_sprite(-10, -39 + 76, 4);

			food[4].entity = bn::sprite_items::gumbo.create_sprite(32, -39 + 38, 12); // Bowl
			food[5].entity = bn::sprite_items::gumbo.create_sprite(-78, -24, 5);	  // Spices

			for (short int t = 0; t < 5; t++)
			{
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
			while (!done)
			{
				current_level = ((6 - chari) * 0.325) + 0.01;
				current_hud.update(current_level, score);

				hand.put_above();

				if (blend_value < 0.05 && ready_freddy)
				{
					done = true;
				}

				if (food[4].type == je_veus_de && !ready)
				{

					switch (chari)
					{
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
					default:
					{
					};
					}

					ready = true;
					chari_mons = bn::sprite_items::gumbo_mons.create_sprite(104, -58, (chari * 2) + 1);
					chari_mons.put_below();
				}

				counter++;
				if (counter > 5)
				{
					if (score > 0)
						score--;
					counter = 0;
				}

				file1_spr.clear();
				file1_gen.generate(-112, 72, buf1.c_str(), file1_spr);
				buf1 = "";

				for (int t = 0; t < 6; t++)
				{
					if (food[t].entity.y() < -24 && t != sel)
					{
						food[t].entity.set_y(food[t].entity.y() + 2);
					}
					if (abs(food[t].entity.x() - hand.x()) + abs(food[t].entity.y() - hand.y()) < 16)
					{
						switch (globals->all_save.language)
						{
						case 0:
						{
							switch (t - 1)
							{
							case 0:
								buf1 = "Vegetables";
								break;
							case 1:
								buf1 = "Meat";
								break;
							case 2:
								buf1 = "Roux";
								break;
							case 3:
								switch (food[t].type)
								{
								case 1:
									buf1 = "Rice Bowl";
									break;
								case 8:
									buf1 = "Jambalaya";
									break;
								case 9:
									buf1 = "Gumbo";
									break;
								case 10:
									buf1 = "Gumbo + Rice";
									break;
								case 11:
									buf1 = "Ettoufee";
									break;
								default:
									buf1 = "Empty Bowl";
									break;
								}
								break;
							case 4:
								buf1 = "Spices";
								break;
							default:
							{
							};
							}
						}
						case 1:
						{
							break;
						}
						case 2:
						{
							switch (t - 1)
							{
							case 0:
								buf1 = "Vegetal";
								break;
							case 1:
								buf1 = "Carne";
								break;
							case 2:
								buf1 = "Roux";
								break;
							case 3:
								switch (food[t].type)
								{
								case 1:
									buf1 = "Arroz";
									break;
								case 8:
									buf1 = "Jambalaya";
									break;
								case 9:
									buf1 = "Gumbo";
									break;
								case 10:
									buf1 = "Gumbo + Rice";
									break;
								case 11:
									buf1 = "Ettoufee";
									break;
								default:
									buf1 = "Tazon Vacio";
									break;
								}
								break;
							case 4:
								buf1 = "Especias";
								break;
							default:
							{
							};
							}
						}
						}
					}
				}

				if (bn::keypad::a_pressed())
				{
					bn::sound_items::pop.play();

					for (short int t = 0; t < 6; t++)
					{
						if (abs(food[t].entity.x() - hand.x()) + abs(food[t].entity.y() - hand.y()) < 16)
						{
							sel = t;
						}
					}
				}

				if (sel > -1)
				{
					food[sel].entity.set_position(hand.x(), hand.y());
				}

				if (bn::keypad::a_released())
				{
					bn::sound_items::fireblast.play();

					if (sel == 0)
					{
						for (short int t = 1; t < 3; t++)
						{
							if (abs(food[t].entity.x() - hand.x()) + abs(food[t].entity.y() - hand.y()) < 16)
							{
								food[t].entity = bn::sprite_items::gumbo.create_sprite(food[t].entity.x(), food[t].entity.y(), t + 1);
								food[t].type = 1;
								score += 50;
							}
						}
					}
					else if ((sel > 0 && sel < 3 && food[sel].type == 1) || sel == 3)
					{
						if (abs(food[4].entity.x() - hand.x()) + abs(food[4].entity.y() - hand.y()) < 16)
						{
							switch (food[4].type)
							{
							case 1:
							{
								if (sel == 1)
								{
									food[4].type = 7;
									food[4].entity = bn::sprite_items::gumbo.create_sprite(food[4].entity.x(), food[4].entity.y(), 7);
									food[1].entity.set_visible(false);
									score += 50;
								}
								break;
							}
							case 7:
							{
								if (sel == 2)
								{
									food[4].type = 8;
									food[4].entity = bn::sprite_items::gumbo.create_sprite(food[4].entity.x(), food[4].entity.y(), 8);
									food[2].entity.set_visible(false);
									score += 50;
								}
								break;
							}
							case 8:
							{
								if (sel == 3)
								{
									food[4].type = 9;
									food[4].entity = bn::sprite_items::gumbo.create_sprite(food[4].entity.x(), food[4].entity.y(), 9);
									food[3].entity.set_y(food[3].entity.y().integer() + 16);
									score += 50;
								}
								break;
							}
							case 9:
							{
								if (sel == 3)
								{
									food[4].type = 11;
									food[4].entity = bn::sprite_items::gumbo.create_sprite(food[4].entity.x(), food[4].entity.y(), 11);
									food[3].entity.set_visible(false);
									score += 50;
								}
								break;
							}
							default:
							{
							};
							}
						}
					}
					else if (sel == 4)
					{
						if (abs(-105 - hand.x()) + abs(-30 - hand.y()) < 16)
						{
							if (food[4].type == 0)
							{
								food[4].type = 1;
								food[4].entity = bn::sprite_items::gumbo.create_sprite(food[4].entity.x(), food[4].entity.y(), 6);
								score += 50;
							}
							else if (food[4].type == 9)
							{
								food[4].type = 10;
								food[4].entity = bn::sprite_items::gumbo.create_sprite(food[4].entity.x(), food[4].entity.y(), 10);
								score += 50;
							}
						}
						else if (hand.x().integer() > 84 && hand.y().integer() < -33)
						{
							ready_freddy = true;
							if (food[4].type == je_veus_de)
							{
								score += 100;
								bn::sound_items::cnaut.play();
							}
							else
							{
								score = score / 2;
								bn::sound_items::firecrackle.play();
							}
						}
					}
					else if (sel == 5)
					{
						if (abs(food[4].entity.x() - hand.x()) + abs(food[4].entity.y() - hand.y()) < 16)
						{
							food[5].entity.set_visible(false);
							score += std_rnd(100);
						}
					}

					sel = -1;
				}

				if (bn::keypad::a_held())
				{
					hand = bn::sprite_items::gumbo.create_sprite(hand.x(), hand.y(), 15);
				}
				else
				{
					hand = bn::sprite_items::gumbo.create_sprite(hand.x(), hand.y(), 14);
				}

				if (bn::keypad::up_held())
				{
					if (hand.y().integer() > -80)
						hand.set_y(hand.y().integer() - 1);
				}

				if (bn::keypad::down_held())
				{
					if (hand.y().integer() < 80)
						hand.set_y(hand.y().integer() + 1);
				}

				if (bn::keypad::left_held())
				{
					if (hand.x().integer() > -120)
						hand.set_x(hand.x().integer() - 1);
				}

				if (bn::keypad::right_held())
				{
					if (hand.x().integer() < 120)
						hand.set_x(hand.x().integer() + 1);
				}

				if (bn::keypad::b_pressed())
				{
					chari = 7;
					done = true;
				}

				if (bn::keypad::r_pressed())
				{
					switch (globals->all_save.language)
					{
					case 0:
					{
						switch (je_veus_de)
						{
						case 8:
						{
							line lc[32] = {
								{fals, fals, 0, "JUMBALAYA                        Rice, Veg, Meat"},
								{fals, fals, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						};
						case 9:
						{
							line lc[32] = {
								{fals, fals, 0, "GUMBO                            Rice, Veg, Meat, Roux"},
								{fals, fals, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						};
						case 10:
						{
							line lc[32] = {
								{fals, fals, 0, "GUMBO, EXTRA RICE                Rice, Veg, Meat, Roux, Rice"},
								{fals, fals, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						};
						case 11:
						{
							line lc[32] = {
								{fals, fals, 0, "ETTOUFEE                         Rice, Veg, Meat, Roux, Roux"},
								{fals, fals, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						};
						default:
						{
						};
						break;
						}
						break;
					}
					case 2:
					{
						switch (je_veus_de)
						{
						case 8:
						{
							line lc[32] = {
								{fals, fals, 0, "JUMBALAYA                        Arroz, Veg, Carne"},
								{fals, fals, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						};
						case 9:
						{
							line lc[32] = {
								{fals, fals, 0, "GUMBO                            Arroz, Veg, Carne, Roux"},
								{fals, fals, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						};
						case 10:
						{
							line lc[32] = {
								{fals, fals, 0, "GUMBO, ARROZ ADICIONAL           Arroz, Veg, Carne, Roux, Arroz"},
								{fals, fals, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						};
						case 11:
						{
							line lc[32] = {
								{fals, fals, 0, "ETTOUFEE                         Arroz, Veg, Carne, Roux, Roux"},
								{fals, fals, 0, "COM: Endscene"}};
							dialogue_page_lite(lc);
							break;
						};
						default:
						{
						};
						break;
						}
						break;
					}
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

		if (globals->current_save->checkpoint < 15)
		{
			if (new_xp > 300)
				new_xp = 300;
		}
		else if (globals->current_save->checkpoint < 9)
		{
			if (new_xp > 200)
				new_xp = 200;
		}
		else
		{
			if (globals->current_save->checkpoint < 6)
			{
				if (new_xp > 100)
					new_xp = 100;
			}
			else if (new_xp > 50)
				new_xp = 50;
		}

		globals->current_save->xp = new_xp;

		victory v(0, 8, score, globals->current_save->xp, 3);
		while (!bn::keypad::a_pressed())
		{
			v.update();
			face_b_like.update();
			face_spr = face_b_like.sprite();
			bn::core::update();
		}
	}

	dungeon_return dt(4, 4, 13);
	return dt;
}

void final_battle()
{

	bn::camera_ptr camera = bn::camera_ptr::create(0, 0);

	auto bg_stage = bn::regular_bg_items::bg_stage.create_bg(0, 0);
	bg_stage.set_camera(camera);

	bn::music_items::z26_zip.play(bn::fixed(100) / 100);
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

	while (ax.x() > -72)
	{

		if (aaron_x < -128)
			aaron_x = -128;
		if (rufus_x > 128)
			rufus_x = 128;

		// controls
		if (bn::keypad::left_released() || bn::keypad::right_released())
		{
			aaron_change = true;
			aaron_action = 1;
		}

		if (bn::keypad::left_pressed())
		{
			aaron_change = true;
			aaron_action = 4;
		}
		if (bn::keypad::left_held())
		{
			aaron_x -= 4;
		}

		if (bn::keypad::right_pressed())
		{
			aaron_change = true;
			aaron_action = 0;
		}
		if (bn::keypad::right_held())
		{
			aaron_x += 4;
		}

		// handle random movement
		if (std_rnd(12) == 1)
		{
			short int old_logic = rufus_logic;
			rufus_logic = std_rnd(12);
			if (old_logic != rufus_logic)
			{
				if (rufus_x > 100)
					rufus_logic = 0;
				rufus_change = true;
			}
		}

		switch (rufus_logic)
		{
		case 1:
		{
			rufus_action = 1;
			break;
		};
		case 2:
		{
			rufus_action = 4;
			rufus_x += 1;
			break;
		};
		case 13:
		{
			rufus_action = 2;
			break;
		}
		case 14:
		{
			rufus_action = 3;
			break;
		}
		default:
		{
			rufus_action = 0;
			rufus_x -= 1;
			break;
		};
		}

		// Collision logic
		if (abs(rufus_x - aaron_x) < 24)
		{
			ax.set_x(ax.x() - 3);

			rufus_action = 2;
			rufus_change = true;
			aaron_action = 3;
			aaron_change = true;

			bn::sound_items::firehit.play();

			short int ugh = std_rnd(6);
			switch (ugh)
			{
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

		if (bn::keypad::a_pressed() && aaron_action != 3)
		{

			if (std_rnd(3) == 2)
			{
				bn::sound_items::firehit.play();

				if (abs(rufus_x - aaron_x) < 96)
				{
					rufus_action = 3;
					rufus_change = true;
					bn::sound_items::rufus_01.play();
					ax.set_x(ax.x() + 1);
				}

				aaron_action = 2;
				aaron_change = true;
			}
			else if (abs(rufus_x - aaron_x) < 96)
			{

				ax.set_x(ax.x() - 3);

				rufus_action = 2;
				rufus_change = true;
				aaron_action = 3;
				aaron_change = true;

				bn::sound_items::firehit.play();

				short int ugh = std_rnd(6);
				switch (ugh)
				{
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
		if (aaron_change)
		{
			aaron_change = false;
			switch (aaron_action)
			{
			case 0:
			{
				a_01_anim = bn::create_sprite_animate_action_forever(a_01, 1, bn::sprite_items::battle_aaron.tiles_item(), 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22);
				a_02_anim = bn::create_sprite_animate_action_forever(a_02, 1, bn::sprite_items::battle_aaron.tiles_item(), 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23);
				a_03_anim = bn::create_sprite_animate_action_forever(a_03, 1, bn::sprite_items::battle_aaron.tiles_item(), 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46);
				a_04_anim = bn::create_sprite_animate_action_forever(a_04, 1, bn::sprite_items::battle_aaron.tiles_item(), 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47);

				aaron_offset_x = 4;
				aaron_offset_y = 6;
				break;
			};
			case 1:
			{
				a_01_anim = bn::create_sprite_animate_action_forever(a_01, 1, bn::sprite_items::battle_aaron.tiles_item(), 48, 48, 50, 52, 54, 56, 56, 58, 60, 62, 64, 66);
				a_02_anim = bn::create_sprite_animate_action_forever(a_02, 1, bn::sprite_items::battle_aaron.tiles_item(), 49, 49, 51, 53, 55, 57, 57, 59, 61, 63, 65, 67);
				a_03_anim = bn::create_sprite_animate_action_forever(a_03, 1, bn::sprite_items::battle_aaron.tiles_item(), 70, 70, 72, 74, 76, 78, 78, 80, 82, 84, 86, 88);
				a_04_anim = bn::create_sprite_animate_action_forever(a_04, 1, bn::sprite_items::battle_aaron.tiles_item(), 71, 71, 73, 75, 77, 79, 79, 81, 83, 85, 87, 89);

				aaron_offset_x = 6;
				aaron_offset_y = 6;
				break;
			};
			case 2:
			{
				a_01_anim = bn::create_sprite_animate_action_forever(a_01, 1, bn::sprite_items::battle_aaron.tiles_item(), 92, 92, 94, 96, 98, 100, 100, 100, 100, 100, 100, 100);
				a_02_anim = bn::create_sprite_animate_action_forever(a_02, 1, bn::sprite_items::battle_aaron.tiles_item(), 93, 93, 95, 97, 99, 101, 101, 101, 101, 101, 101, 101);
				a_03_anim = bn::create_sprite_animate_action_forever(a_03, 1, bn::sprite_items::battle_aaron.tiles_item(), 104, 104, 106, 108, 110, 112, 112, 112, 112, 112, 112, 114);
				a_04_anim = bn::create_sprite_animate_action_forever(a_04, 1, bn::sprite_items::battle_aaron.tiles_item(), 105, 105, 107, 109, 111, 113, 113, 113, 113, 113, 113, 115);

				aaron_offset_x = 0;
				aaron_offset_y = 0;
				break;
			};
			case 3:
			{
				a_01_anim = bn::create_sprite_animate_action_forever(a_01, 1, bn::sprite_items::battle_aaron.tiles_item(), 116, 118, 120, 122, 124, 126, 126, 126, 126, 126, 126, 126);
				a_02_anim = bn::create_sprite_animate_action_forever(a_02, 1, bn::sprite_items::battle_aaron.tiles_item(), 117, 119, 121, 123, 125, 127, 127, 127, 127, 127, 127, 127);
				a_03_anim = bn::create_sprite_animate_action_forever(a_03, 1, bn::sprite_items::battle_aaron.tiles_item(), 128, 130, 132, 134, 136, 138, 138, 138, 138, 138, 138, 138);
				a_04_anim = bn::create_sprite_animate_action_forever(a_04, 1, bn::sprite_items::battle_aaron.tiles_item(), 129, 131, 133, 135, 137, 139, 139, 139, 139, 139, 139, 139);

				aaron_offset_x = 0;
				aaron_offset_y = 0;
				break;
			};
			case 4:
			{
				a_01_anim = bn::create_sprite_animate_action_forever(a_01, 1, bn::sprite_items::battle_aaron.tiles_item(), 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0);
				a_02_anim = bn::create_sprite_animate_action_forever(a_02, 1, bn::sprite_items::battle_aaron.tiles_item(), 23, 21, 19, 17, 15, 13, 11, 9, 7, 5, 3, 1);
				a_03_anim = bn::create_sprite_animate_action_forever(a_03, 1, bn::sprite_items::battle_aaron.tiles_item(), 46, 44, 42, 40, 38, 36, 34, 32, 30, 28, 26, 24);
				a_04_anim = bn::create_sprite_animate_action_forever(a_04, 1, bn::sprite_items::battle_aaron.tiles_item(), 47, 45, 43, 41, 39, 37, 35, 33, 31, 29, 27, 25);

				aaron_offset_x = 4;
				aaron_offset_y = 6;
				break;
			};
			default:
			{
			};
			}
		}

		if (rufus_change)
		{
			rufus_change = false;
			switch (rufus_action)
			{
			case 0:
			{
				r_01_anim = bn::create_sprite_animate_action_forever(r_01, 1, bn::sprite_items::battle_rufus.tiles_item(), 0, 2, 2, 4, 6, 8, 8, 10, 12, 14, 14, 16);
				r_02_anim = bn::create_sprite_animate_action_forever(r_02, 1, bn::sprite_items::battle_rufus.tiles_item(), 1, 3, 3, 5, 7, 9, 9, 11, 13, 15, 15, 17);
				r_03_anim = bn::create_sprite_animate_action_forever(r_03, 1, bn::sprite_items::battle_rufus.tiles_item(), 18, 20, 20, 22, 24, 26, 26, 28, 30, 32, 32, 34);
				r_04_anim = bn::create_sprite_animate_action_forever(r_04, 1, bn::sprite_items::battle_rufus.tiles_item(), 19, 21, 21, 23, 25, 27, 27, 29, 31, 33, 33, 35);
				break;
			};
			case 1:
			{
				r_01_anim = bn::create_sprite_animate_action_forever(r_01, 1, bn::sprite_items::battle_rufus.tiles_item(), 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58);
				r_02_anim = bn::create_sprite_animate_action_forever(r_02, 1, bn::sprite_items::battle_rufus.tiles_item(), 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59);
				r_03_anim = bn::create_sprite_animate_action_forever(r_03, 1, bn::sprite_items::battle_rufus.tiles_item(), 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82);
				r_04_anim = bn::create_sprite_animate_action_forever(r_04, 1, bn::sprite_items::battle_rufus.tiles_item(), 61, 63, 65, 67, 69, 71, 73, 75, 77, 79, 81, 83);
				break;
			};
			case 2:
			{
				r_01_anim = bn::create_sprite_animate_action_forever(r_01, 1, bn::sprite_items::battle_rufus.tiles_item(), 84, 86, 90, 92, 94, 96, 98, 100, 102, 102, 102, 102);
				r_02_anim = bn::create_sprite_animate_action_forever(r_02, 1, bn::sprite_items::battle_rufus.tiles_item(), 85, 87, 91, 93, 95, 97, 99, 101, 103, 103, 103, 103);
				r_03_anim = bn::create_sprite_animate_action_forever(r_03, 1, bn::sprite_items::battle_rufus.tiles_item(), 104, 106, 108, 110, 112, 114, 116, 118, 120, 120, 120, 120);
				r_04_anim = bn::create_sprite_animate_action_forever(r_04, 1, bn::sprite_items::battle_rufus.tiles_item(), 105, 107, 109, 111, 113, 115, 117, 119, 121, 121, 121, 121);
				break;
			};
			case 3:
			{
				r_01_anim = bn::create_sprite_animate_action_forever(r_01, 1, bn::sprite_items::battle_rufus.tiles_item(), 124, 126, 128, 130, 132, 134, 136, 138, 140, 140, 140, 140);
				r_02_anim = bn::create_sprite_animate_action_forever(r_02, 1, bn::sprite_items::battle_rufus.tiles_item(), 125, 127, 129, 131, 133, 135, 137, 139, 141, 141, 141, 141);
				r_03_anim = bn::create_sprite_animate_action_forever(r_03, 1, bn::sprite_items::battle_rufus.tiles_item(), 144, 146, 148, 150, 152, 154, 156, 158, 160, 160, 160, 160);
				r_04_anim = bn::create_sprite_animate_action_forever(r_04, 1, bn::sprite_items::battle_rufus.tiles_item(), 145, 147, 149, 151, 153, 155, 157, 159, 161, 161, 161, 161);
				break;
			};
			case 4:
			{
				r_01_anim = bn::create_sprite_animate_action_forever(r_01, 1, bn::sprite_items::battle_rufus.tiles_item(), 16, 14, 14, 12, 10, 8, 8, 6, 4, 2, 2, 0);
				r_02_anim = bn::create_sprite_animate_action_forever(r_02, 1, bn::sprite_items::battle_rufus.tiles_item(), 17, 15, 15, 13, 11, 9, 9, 7, 5, 3, 3, 1);
				r_03_anim = bn::create_sprite_animate_action_forever(r_03, 1, bn::sprite_items::battle_rufus.tiles_item(), 34, 32, 32, 30, 28, 26, 26, 24, 22, 20, 20, 18);
				r_04_anim = bn::create_sprite_animate_action_forever(r_04, 1, bn::sprite_items::battle_rufus.tiles_item(), 35, 33, 33, 31, 29, 27, 27, 25, 23, 21, 21, 19);
				break;
			};
			default:
			{
			}
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

		if (aaron_action == 2 || aaron_action == 3)
		{

			for (short int t = 1; t < 8; t++)
			{
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

			if (aaron_action == 2)
			{
				if (rufus_action == 3)
				{
					rufus_x += 32;
				}
			}
			else
			{
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

	if (globals->current_save->last_char_id < 0 || globals->current_save->last_char_id > 7)
		globals->current_save->last_char_id = 0;
	dt.spawn_x = x;
	dt.spawn_y = y;
	dt.world_index = world;

	// Execute until time to leave
	do
	{
		// March event
		if (globals->current_save->checkpoint == 4 && globals->current_save->xp > 99 && globals->current_save->last_char_id != 4)
		{
			globals->current_save->checkpoint = 5;
			break;
		}

		// June event
		if (globals->current_save->checkpoint == 8 && globals->current_save->xp > 199)
		{
			globals->current_save->checkpoint = 9;
			break;
		}

		// June event
		if (globals->current_save->checkpoint == 10 && globals->current_save->xp > 299)
		{
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
			case 4:
			{
				dt = computer();
				break;
			}
			case 5:
			{
				dt = crystal_ball();
				break;
			}
			case 6:
			{
				exec_dialogue(27);
				dt = boat_game();
				break;
			}
			case 7:
			{
				bn::blending::set_transparency_alpha(0);
				bn::music_items::z24_cruz.play(0.8);
				if (globals->current_save->hat_world == -1)
				{
					if (globals->current_save->last_char_id == 1)
					{
						exec_dialogue(31);
					}
					else
					{
						exec_dialogue(30);
					}
				}
				dt = store();
				break;
			}
			case 8:
			{
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

void credits()
{
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

			{"Scout desktop sketch by"},
			{"@yae.ruu (Instagram)"},
			{" - - - - "},

			{"based on characters"},
			{"from 'Vous Voila' by"},
			{"Ethan Hill"},

			{"created by"},
			{"Ethan Hill"},
			{" - - - - "},

			{" - - - - "},
			{"KICKSTARTER BACKERS"},
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

			{" - - - - "},
			{"SPECIAL THANKS:"},
			{" - - - - "},

			{"my friends and family"},
			{"r/cajunfrench"},
			{"LETU Game Design Club"},

			{"Thank you for playing!"},
			{"Merci d'avoir joue!"},
			{" - LA FIN - "},

			{" . . . . "},
			{" - - - - "}};

		buf1 = lc[0].text;
		buf2 = lc[1].text;
		buf3 = lc[2].text;

		file1_spr.clear();
		file1_gen.generate(-112, 96, buf1.c_str(), file1_spr);
		file2_gen.generate(-112, 96 + 14, buf2.c_str(), file2_spr);
		file3_gen.generate(-112, 96 + 28, buf3.c_str(), file3_spr);

		short int ending = 215;
		short int scroll_on = 0;
		while (reg < ending)
		{
			scroll_on += 1;
			scroll_on = scroll_on % 2;

			if (scroll_on == 0 && reg < ending - 1)
			{
				for (short int t = 0; t < file1_spr.size(); t++)
				{
					file1_spr.at(t).set_y(file1_spr.at(t).y() - 1);
				}
				if (file1_spr.at(0).y().integer() < -104 && reg < ending - 1)
				{
					buf1 = lc[reg].text;
					file1_spr.clear();
					file1_gen.generate(-112, 96, buf1.c_str(), file1_spr);
					reg++;
				}

				for (short int t = 0; t < file2_spr.size(); t++)
				{
					file2_spr.at(t).set_y(file2_spr.at(t).y() - 1);
				}
				if (file2_spr.at(0).y().integer() < -104 && reg < ending - 1)
				{
					buf2 = lc[reg].text;
					file2_spr.clear();
					file2_gen.generate(-112, 96, buf2.c_str(), file2_spr);
					reg++;
				}

				for (short int t = 0; t < file3_spr.size(); t++)
				{
					file3_spr.at(t).set_y(file3_spr.at(t).y() - 1);
				}
				if (file3_spr.at(0).y().integer() < -104 && reg < ending - 1)
				{
					buf3 = lc[reg].text;
					file3_spr.clear();
					file3_gen.generate(-112, 96, buf3.c_str(), file3_spr);
					reg++;
				}
			}

			bn::core::update();
		}
	}

	while (true)
	{
		bn::core::update();
	}
}

void handle_minigame()
{
	exec_dialogue(37);

	while (true)
	{
		int select = select_minigame();

		{
			switch (select)
			{
			case 0:
			{
				underground();
				break;
			}
			case 1:
			{
				rabbit_game();
				break;
			}
			case 2:
			{
				tree_cut();
				break;
			}
			case 3:
			{
				computer();
				break;
			}
			case 4:
			{
				crystal_ball();
				break;
			}
			case 5:
			{
				boat_game();
				break;
			}
			case 6:
			{
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
	case 0:
	{
		intros(0);

		exec_dialogue(0);
		exec_dialogue(1);
		exec_dialogue(2);
		exec_dialogue(3);

		bn::music_items::new_castle.play(0.8);
		bn::music_items::new_castle.play(0.8);

		core_gameplay(8, 3, 0, -1);
		cutscenes(0);
		exec_dialogue(13);
		cutscenes(1);
		exec_dialogue(14);
		if (DEVICE_TYPE == 0)
			keyboard();
		exec_dialogue(15);
		break;
	}

		// Spring
	case 1:
	{
		intros(1);
		exec_dialogue(16);
		globals->current_save->last_char_id = 0;
		core_gameplay(9, 16, 4, 5);
		break;
	}

		// Welcome message
	case 2:
	{
		bn::music_items::multisong.play(0.8); // velvet
		exec_dialogue(18);
		popup(0);
		break;
	}

		// Spawning into their house
	case 3:
	{
		core_gameplay(5, 3, 5, 4);
		break;
	}

		// Yes
	case 4:
	{
		core_gameplay(9, 6, 4, 7);
		break;
	}
	case 5:
	{
		// core_gameplay(5, 8, 4, 5);
		globals->current_save->checkpoint++;
		break;
	}
	case 6:
	{
		bn::music_items::multisong.play(0.8); // velvet
		exec_dialogue(17);
		exec_dialogue(19);
		exec_dialogue(20);
		break;

		// Summer - Diana, Eleanor, and Vee
	}
	case 7:
	{
		intros(2);
		exec_dialogue(21);
		popup(4);
		break;
	}
	case 8:
	{
		if (globals->current_save->last_char_id == 3)
		{
			core_gameplay(8, 10, 4, 0);
		}
		else if (globals->current_save->last_char_id < 3)
		{
			core_gameplay(9, 6, 4, 0);
		}
		else
		{
			core_gameplay(10, 6, 8, 0);
		}
		break;
	}

	case 9:
	{
		exec_dialogue(29);
		intros(3);
		exec_dialogue(28);
		break;
	}

	case 10:
	{
		if (globals->current_save->last_char_id == 3)
		{
			core_gameplay(8, 10, 4, 0);
		}
		else if (globals->current_save->last_char_id < 3)
		{
			core_gameplay(9, 6, 4, 0);
		}
		else
		{
			core_gameplay(10, 6, 8, 0);
		}
		break;
	}

	case 11:
	{
		globals->current_save->checkpoint = 10;
		break;
	}

	case 12:
	{
		{
			intros(4);
			if (bn::music::playing())
				bn::music::stop();
		}

		{
			exec_dialogue(32);
			globals->current_save->last_char_id = 2;
		}

		core_gameplay(9, 6, 4, 0);
		break;
	}

	case 13:
	{
		globals->current_save->checkpoint = 12;
		break;
	}

	case 14:
	{
		dungeon_return dt;
		dt.spawn_x = 1;		// 1;//3;//22;//1;
		dt.spawn_y = 9;		// 9;//62;//22;//9;
		dt.world_index = 0; // 0;//2;//1;//0;

		do
		{
			dt = rufus_dungeon(dt);
		} while (dt.world_index < 99);

		intros(5);
		exec_dialogue(34);
		final_battle();
		exec_dialogue(35);
		credits();
		break;
	}

	case 15:
	{

		bool keys_got = true;
		for (int t = 0; t < 4; t++)
		{
			if (globals->current_save->keys[t] != 1)
				keys_got = false;
		}

		if (keys_got)
		{
			handle_minigame();
		}
		else
		{
			intros(5);
			exec_dialogue(34);
			final_battle();
			exec_dialogue(35);
			credits();
		}
		break;
	}

	default:
	{
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
	// int f = flash_init(FLASH_SIZE_AUTO);

	// 'new' allows me to store this in the heap instead of the stack
	globals = new global_data();
	globals->current_save = new save_struct();

	/*
	dungeon_return dt;
	dt.spawn_x = 16;
	dt.spawn_y = 19;
	dt.world_index = 1;
	rufus_dungeon(dt);
	*/

	flash_read();
	startup();
	load_save();

	while (globals->current_save->checkpoint < 99)
	{
		globals->current_save->checkpoint = checkpoint(globals->current_save->checkpoint);
	}

	// Get to the end?
	bn::core::reset();
}