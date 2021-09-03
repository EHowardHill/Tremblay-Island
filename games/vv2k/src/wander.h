#include <bn_sprite_builder.h>
#include <bn_sprite_animate_actions.h>

// UI elements
#include "bn_sprite_items_a_button_2.h"

// Character / backgrounds
#include "bn_sprite_items_maple_walking.h"
#include "bn_sprite_items_enoki_walking_pj.h"
#include "bn_sprite_items_environment_stone.h"
#include "bn_regular_bg_items_castle_floor.h"

// Individual tiles
class stone {
    public:
        bn::sprite_ptr entity = bn::sprite_items::environment_stone.create_sprite(300,300,0);
        void set(int x, int y, const bn::sprite_item sprite, int loc = 0) {
            entity = sprite.create_sprite(x,y,loc);
        };
};

// Handles pairs of tile/action pairs
class action {
    public:
        int x = 0;
        int y = 0;
        int action = 0;
        void set(int xx, int yy, int a) {
            x = xx;
            y = yy;
            action = a;
        }
};

// Dungeon return type
class dungeon_return {
    public:
    int spawn_x = 0;
    int spawn_y = 0;
    int world_index = 0;
    dungeon_return(int x, int y, int i) {
        spawn_x = x;
        spawn_y = y;
        world_index = i;
    }
};

// Room setup object
class room {
    public:
    int width = 29;
    int height = 14;
    int start_x = 8;
    int start_y = 3;
    int local_tileset[406];
    action actions[16];

    void init(int w, int h, int x, int y) {
        width = w;
        height = h;
        start_x = x;
        start_y = y;
    }
};

// Custom character class
class character {
    public:
    int dir = 0;
    int last_dir = 0;
    bool done = false;
    bool is_walking = false;
    bn::sprite_item entity_item = bn::sprite_items::maple_walking;
    bn::sprite_ptr entity = entity_item.create_sprite(0,0);
    bn::sprite_animate_action<4> entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 0, 1, 0, 2);
    bool isMain = false;
    room* current_room;

    character(const bn::sprite_item sprite, room new_room, int x = 0, int y = 0, bool main = false) {
        entity = sprite.create_sprite(x * 32, y * 32);
        entity.set_visible(true);
        entity_item = sprite;
        entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 0, 1, 0, 2);
        isMain = main;
        current_room = &new_room;
    }

    // Get position on board
    int get_loc() {
        return ((entity.x().round_integer() / 32) + 5) + (((entity.y().round_integer() / 32) + 1) * 8) + 5;
    }

    // Run this regularly!
    void update(int x = 0, int y = 0) {

        // If main character....
        if (isMain) {

            if (entity.blending_enabled()) {
                if (bn::blending::intensity_alpha() > 0.2) {
                    bn::blending::set_intensity_alpha(bn::blending::intensity_alpha() - 0.02);
                } else {
                    entity.set_blending_enabled(false);
                }
            }

            // Keyboard controls
            if (bn::keypad::up_released() || bn::keypad::down_released() || bn::keypad::left_released() || bn::keypad::right_released()) {
                if (bn::keypad::down_held()) {
                    dir = 0;
                } else if (bn::keypad::right_held()) {
                    dir = 1;
                } else if (bn::keypad::left_held()) {
                    dir = 2;
                } else if (bn::keypad::up_held()) {
                    dir = 3;
                }
            } else {
                if (bn::keypad::down_pressed()) {
                    dir = 0;
                } else if (bn::keypad::right_pressed()) {
                    dir = 1;
                } else if (bn::keypad::left_pressed()) {
                    dir = 2;
                } else if (bn::keypad::up_pressed()) {
                    dir = 3;
                }
            }

            // Manage the previously handled value
            if (last_dir != dir) {
                done = false;
                last_dir = dir;
            }

            // Control directional animation
            if (!done) {
                switch(dir) {
                    case 0:
                        entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 1, 0, 2, 0);
                        break;
                    case 1:
                        entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 4, 3, 5, 3);
                        break;
                    case 2:
                        entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 7, 6, 8, 6);
                        break;
                    case 3:
                        entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 10, 9, 11, 9);
                        break;
                }
                done = true;
            }

            // Collision detection
            int x_int = entity.x().integer();
            int y_int = entity.y().integer();
            int close[4] {
                ((x_int + 6 + 31) & (-32)) / 32,
                (x_int - 6) / 32,
                ((y_int + 31) & (-32)) / 32,
                (y_int + 12) / 32
            };
            int col[8] = {
                current_room->local_tileset[close[0] - 1 + (close[2] * current_room->width)] > 1,
                current_room->local_tileset[close[0] - 1 + (close[3] * current_room->width)] > 1,
                current_room->local_tileset[close[1] + 1 + (close[2] * current_room->width)] > 1,
                current_room->local_tileset[close[1] + 1 + (close[3] * current_room->width)] > 1,
                current_room->local_tileset[close[0] + ((close[2] - 1) * current_room->width)] > 1,
                current_room->local_tileset[close[0] + ((close[3] - 1) * current_room->width)] > 1,
                current_room->local_tileset[close[1] + ((close[2] + 1) * current_room->width)] > 1,
                current_room->local_tileset[close[1] + ((close[3] + 1) * current_room->width)] > 1
            };

            // Key controls
            if (bn::keypad::left_held()) {
                if (!col[0] || (col[0] && !col[1] && col[2] && col[7])) {
                    entity.set_x(entity.x() - 1);
                }
            }
            if (bn::keypad::right_held()) {
                if (!col[2] || (col[0] && col[2] && !col[3] && col[7])) {
                    entity.set_x(entity.x() + 1);
                }
            }
            if (bn::keypad::up_held()) {
                if (!col[1] && !col[3]) {
                    entity.set_y(entity.y() - 1);

                }
            }
            if (bn::keypad::down_held()) {
                if (!col[0] && (!col[2] || (col[2] && col[3] && col[4] && col[5]))) {
                    entity.set_y(entity.y() + 1);
                }
            }

            // Move
            if ((bn::keypad::down_held() || bn::keypad::up_held() || bn::keypad::left_held() || bn::keypad::right_held()) || (entity_anim.current_index() % 2 == 1)) {
                entity_anim.update();
            }
        }

        // If following...
        else {

            // Collision detection
            done = true;
            is_walking = false;
            int x_int = entity.x().integer();
            int y_int = entity.y().integer();
            int close[4];
            int col[8];
            close[0] = ((x_int + 6 + 31) & (-32)) / 32;
            close[1] = (x_int - 6) / 32;
            close[2] = ((y_int + 31) & (-32)) / 32;
            close[3] = y_int / 32;
            col[0] = current_room->local_tileset[close[0] - 1 + (close[2] * current_room->width)] > 1;
            col[1] = current_room->local_tileset[close[0] - 1 + (close[3] * current_room->width)] > 1;
            col[2] = current_room->local_tileset[close[1] + 1 + (close[2] * current_room->width)] > 1;
            col[3] = current_room->local_tileset[close[1] + 1 + (close[3] * current_room->width)] > 1;
            col[4] = current_room->local_tileset[close[0] + ((close[2] - 1) * current_room->width)] > 1;
            col[5] = current_room->local_tileset[close[0] + ((close[3] - 1) * current_room->width)] > 1;
            col[6] = current_room->local_tileset[close[1] + ((close[2] + 1) * current_room->width)] > 1;
            col[7] = current_room->local_tileset[close[1] + ((close[3] + 1) * current_room->width)] > 1;

            // Follow player
            bool isXTravel = false;
            if (x < entity.x() - 24) {
                if (!col[0] || (col[0] && !col[1] && col[2] && col[7])) {
                    isXTravel = true;
                    entity.set_x(entity.x() - 1);
                    dir = 2;
                    if (last_dir != dir) done = false;
                    last_dir = dir;
                    is_walking = true;
                }
            } else
            if (x > entity.x() + 24) {
                if (!col[2] || (col[0] && col[2] && !col[3] && col[7])) {
                    isXTravel = true;
                    entity.set_x(entity.x() + 1);
                    dir = 1;
                    if (last_dir != dir) done = false;
                    last_dir = dir;
                    is_walking = true;
                }
            }
            if (y < entity.y() - 24) {
                if (!col[1] && !col[3]) {
                    entity.set_y(entity.y() - 1);
                    if (!isXTravel) {
                        dir = 3;
                        if (last_dir != dir) done = false;
                        last_dir = dir;
                        is_walking = true;
                    }
                }
            } else
            if (y > entity.y() + 24) {
                if (!col[0] && (!col[2] || (col[2] && col[3] && col[4] && col[5]))) {
                    entity.set_y(entity.y() + 1);
                    if (!isXTravel) {
                        dir = 0;
                        if (last_dir != dir) done = false;
                        last_dir = dir;
                        is_walking = true;
                    }
                }
            }
        
            // Animate
            if (!done) {
                switch(dir) {
                    case 0:
                        entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 1, 0, 2, 0);
                        break;
                    case 1:
                        entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 4, 3, 5, 3);
                        break;
                    case 2:
                        entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 7, 6, 8, 6);
                        break;
                    case 3:
                        entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 10, 9, 11, 9);
                        break;
                }
            }

            // Walk
            if (is_walking || (entity_anim.current_index() % 2 == 1)) {
                entity_anim.update();
            }
        }

        // Handle update
        entity = entity_anim.sprite();
        //entity.set_camera(camera);
    }
};

// Actual action... things
dungeon_return do_action(int act) {
    dungeon_return dt(0,0,0);
    switch(act) {
        case 1: // Go to hall from guest bedroom
            dt.spawn_x = 18;
            dt.spawn_y = 1;
            dt.world_index = 1;
            break;
        case 2: // Go to Aaron's castle room
            dt.spawn_x = 9;
            dt.spawn_y = 6;
            dt.world_index = 2;
            break;
        case 3: // Takin' a look out Enoki's window
            exec_dialogue(5);
            break;
        case 4: // Observing le fine art
            exec_dialogue(4);
            break;
        case 5: // Observing le fine pot
            exec_dialogue(6);
            break;

        case 6: // Lamp talk
            exec_dialogue(7);
            break;
        case 7:
            exec_dialogue(8); // sees Del
            break;
        case 8: // Go to castle chamber from Aaron's room
            dt.spawn_x = 3;
            dt.spawn_y = 1;
            dt.world_index = 1;
            break;
        case 9: // Go to guest room
            dt.spawn_x = 1;
            dt.spawn_y = 4;
            dt.world_index = 0;
            break;
        case 10: // go to guest room from chamber
            dt.spawn_x = 8;
            dt.spawn_y = 4;
            dt.world_index = 0;
            break;
        case 11: // go to aaron's room from chamber
            dt.spawn_x = 3;
            dt.spawn_y = 6;
            dt.world_index = 2;
            break;
    };
    return dt;
}

dungeon_return dungeon(dungeon_return dt) {
    BN_LOG(dt.spawn_x, ", ", dt.spawn_y, ", ", dt.world_index);
    const int w_size = 104;
    stone local_walls[w_size];
    int local_walls_p = 0;
    room current_room;

    // Camera setup
    bn::camera_ptr camera = bn::camera_ptr::create(0,0);
    bn::regular_bg_ptr primary_bg = bn::regular_bg_items::castle_floor.create_bg(0, 0);
    primary_bg.set_camera(camera);

    // World generation
    switch(dt.world_index) {
        case 0: {
            current_room.init(12, 6, 8, 3);
            int local[406] = {
                4,3,8,11,13,3,3,3,8,3,5,0,
                2,18,0,0,0,18,2,9,0,9,2,0,
                2,0,0,0,0,0,2,10,0,10,2,0,
                2,3,3,2,0,0,2,0,0,0,2,0,
                17,0,0,0,0,0,0,0,0,18,2,0,
                7,3,3,3,3,3,3,3,16,3,6,0
                };
            current_room.actions[1].set(8,4,1);  // door 1
            current_room.actions[2].set(1,4,2);  // door 2
            current_room.actions[3].set(2,1,3);  // night sky
            current_room.actions[4].set(3,1,4);  // painting
            current_room.actions[5].set(4,1,5);  // pot
            current_room.actions[6].set(1,2,5);  // pot
            for (int t = 0; t < current_room.width * current_room.height; t++) {
                current_room.local_tileset[t] = local[t];
            }
            break;
        }
        case 1: {
            current_room.init(21,12,18,1);
            int local[406] = {
                4,3,3,16,12,3,13,12,3,8,12,8,3,12,3,3,12,13,16,3,5,
                2,18,0,0,0,0,0,26,0,0,0,0,0,0,0,0,0,0,0,18,2,
                2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
                12,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
                12,1,1,1,1,0,0,0,0,25,25,0,0,0,0,0,0,0,0,0,2,
                12,1,1,1,1,1,1,0,0,21,23,0,0,0,0,1,1,1,1,1,17,
                12,1,1,1,1,1,0,0,25,22,24,25,0,0,1,1,1,1,1,1,17,
                12,1,1,1,1,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,2,
                12,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
                2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
                2,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,2,
                7,3,14,3,12,3,3,12,3,3,12,3,13,12,3,3,12,3,14,13,6
            };
            for (int t = 0; t < current_room.width * current_room.height; t++) {
                current_room.local_tileset[t] = local[t];
            }
            current_room.actions[0].set(18,1,10);
            current_room.actions[1].set(3,1,11);
            break;
        }
        case 2: {
            current_room.init(11,8,9,6);
            int local[406] = {
                4,11,8,12,8,3,3,3,3,3,5,
                2,18,9,9,26,27,2,0,0,0,2,
                2,0,10,10,0,0,2,19,1,20,2,
                2,0,0,0,0,0,2,3,0,0,2,
                2,0,1,1,1,0,2,0,0,18,2,
                2,0,1,1,1,0,2,0,3,3,12,
                2,18,0,0,0,0,0,0,0,0,17,
                7,3,3,14,3,3,3,3,3,3,6
            };
            for (int t = 0; t < current_room.width * current_room.height; t++) {
                current_room.local_tileset[t] = local[t];
            }
            current_room.actions[0].set(9,6,9);
            current_room.actions[1].set(3,6,8);
            current_room.actions[2].set(4,2,6);
            current_room.actions[3].set(8,2,7);
            break;
        }
    };

    // If different than default, reset
    if (dt.spawn_x > 0 && dt.spawn_y > 0 && dt.spawn_x < 999) {
        current_room.start_x = dt.spawn_x;
        current_room.start_y = dt.spawn_y;
    }

    // Camera init
    camera.set_position(current_room.start_x * 32, current_room.start_y * 32);

    // A header
    bn::sprite_ptr a_notif = bn::sprite_items::a_button_2.create_sprite(0, 0);
    a_notif.set_camera(camera);
    a_notif.set_visible(false);

    // Initial line of dialogue
    //bn::core::update();
    //exec_dialogue(3);
    bn::core::update();

    // Create initial characters
    character maple(bn::sprite_items::maple_walking, current_room, current_room.start_x, current_room.start_y, false);
    maple.entity.set_camera(camera);
    character enoki(bn::sprite_items::enoki_walking_pj, current_room, current_room.start_x - 1, current_room.start_y, false);
    enoki.entity.set_camera(camera);

    switch(save::last_char_id) {
        case 0:
            maple.isMain = true;
            break;
        case 1:
            enoki.isMain = true;
    }

    // GAMELOOP
    int update_counter = 0;
    bool firstThing = true;
    int flex = 84;
    int follow_x = 0;
    int follow_y = 0;
    while(true) {

        // Control actions
        a_notif.set_visible(false);
        for (int t = 0; t < 16; t++) {
            if ((((follow_x - 16) / 32) + 1 == current_room.actions[t].x) && (((follow_y - 16) / 32) + 1 == current_room.actions[t].y)) {
                a_notif.set_visible(true);
                a_notif.put_above();
                a_notif.set_x(follow_x);
                a_notif.set_y(follow_y - 28);
                if (bn::keypad::a_pressed()) {
                    
                    // Clear out extra sprites
                    for (int t = local_walls_p; t < w_size; t++) {
                        //local_walls[t].entity.~sprite_ptr();
                    }

                    // Start action
                    bn::core::update();
                    a_notif.set_visible(false);
                    dungeon_return dt2 = do_action(current_room.actions[t].action);
                    if (dt2.spawn_x + dt2.spawn_y > 0) {
                        return dt2;
                    }
                }
            }
        }

        // Swap characters
        if (bn::keypad::b_pressed()) {
            bn::sound_items::pop.play();
            bn::blending::set_intensity_alpha(1);
            if (maple.isMain) {
                save::last_char_id = 1;
                maple.isMain = false;
                enoki.isMain = true;
                enoki.entity.set_blending_enabled(true);
                maple.entity.set_blending_enabled(false);
            } else {
                save::last_char_id = 0;
                maple.isMain = true;
                enoki.isMain = false;
                maple.entity.set_blending_enabled(true);
                enoki.entity.set_blending_enabled(false);
            }
        }

        // Set primary camera following X/Y coordinates
        if (maple.isMain) {
            maple.update();
            follow_x = maple.entity.x().integer();
            follow_y = maple.entity.y().integer();
        } else {
            maple.update(enoki.entity.x().integer(), enoki.entity.y().integer());
        }
        if (enoki.isMain) {
            enoki.update();
            follow_x = enoki.entity.x().integer();
            follow_y = enoki.entity.y().integer();
        } else {
            enoki.update(maple.entity.x().integer(), maple.entity.y().integer());
        }

        // Z-Order followers
        if (maple.entity.y() > enoki.entity.y()) {
            maple.entity.put_above();
        } else {
            enoki.entity.put_above();
        }

        // Camera follows primary player
        if (camera.x() > follow_x + 30) {
            camera.set_x(camera.x() - 1);
        } else if (camera.x() < follow_x - 30) {
            camera.set_x(camera.x() + 1);
        }
        if (camera.y() > follow_y + 30) {
            camera.set_y(camera.y() - 1);
        } else if (camera.y() < follow_y - 30) {
            camera.set_y(camera.y() + 1);
        }

        // Camera adjustment
        if (camera.x().integer() > (current_room.width * 32) - (flex * 2) + 16) {
            camera.set_x((current_room.width * 32) - (flex * 2) + 16);
        } else if (camera.x().integer() < flex + 32) {
            camera.set_x(flex + 32);
        }
        if (camera.y().integer() > (current_room.height * 32) - (flex * 2) + 64) {
            camera.set_y((current_room.height * 32) - (flex * 2) + 64);
        } else if (camera.y().integer() < flex - 8) {
            camera.set_y(flex - 8);
        }

        // Regularly update the tileset based on new camera coordinates
        if (update_counter == 0) {
            update_counter = 0;
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

        bn::core::update();

        if (firstThing) {
            // After world load
            switch(dt.world_index) {
                case 0: {
                    if (save::checkpoint == 0) {
                        bn::sound_items::shortclip.play();
                        exec_dialogue(3);
                        save::checkpoint = 1;
                    }

                    if (!bn::music::playing()) {
                        int music_volume = 25;
                        bn::music_items_info::span[2].first.play(bn::fixed(music_volume) / 100);
                    }

                    break;
                }
            };
            firstThing = false;
        }
    }
}