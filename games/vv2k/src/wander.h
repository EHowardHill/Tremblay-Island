#include <bn_sprite_builder.h>
#include <bn_sprite_animate_actions.h>

// UI elements
#include "bn_sprite_items_a_button_2.h"

// Characters
#include "bn_sprite_items_maple_walking.h"
#include "bn_sprite_items_enoki_walking_pj.h"
#include "bn_sprite_items_aaron_sleep.h"
#include "bn_sprite_items_del_sleep.h"

// Items
#include "bn_sprite_items_fireball.h"
#include "bn_sprite_items_fireplace_anim.h"

// Backgrounds
#include "bn_sprite_items_environment_stone.h"
#include "bn_regular_bg_items_castle_floor.h"

// Projectiles
class projectile {
    public:
    bn::sprite_item fireball_item = bn::sprite_items::fireball;
    bn::sprite_ptr fireball = fireball_item.create_sprite(0,0);
    bn::sprite_animate_action<4> fireball_anim = bn::create_sprite_animate_action_forever(fireball, 3, fireball_item.tiles_item(), 0, 1, 2, 3);
    bn::sprite_animate_action<4> fireball_anim_end = bn::create_sprite_animate_action_forever(fireball, 3, fireball_item.tiles_item(), 4, 5, 6, 7);
    int dir = 1;
    int dur = 0;
    bool active = false;
    void update() {
        dur++;
        if (dur < 16) {
            fireball_anim.update();
            fireball = fireball_anim.sprite();
            switch(dir) {
                case 0:
                    fireball.set_y(fireball.y() + 4);
                    break;
                case 1:
                    fireball.set_x(fireball.x() + 4);
                    break;
                case 2:
                    fireball.set_x(fireball.x() - 4);
                    break;
                case 3:
                    fireball.set_y(fireball.y() - 4);
                    break;
            };
        } else {
            if (dur < 23) {
                if (dur == 16) bn::sound_items::firehit.play();
                fireball = fireball_anim_end.sprite();
                fireball_anim_end.update();
            } else {
                fireball.set_visible(false);
            }
        }
    }
};

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
            if (!bn::keypad::l_held()) {
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
                if ((!col[0] && !col[1]) || (col[0] && !col[1] && col[2] && col[7])) {
                    entity.set_x(entity.x() - 1);
                }
            }
            if (bn::keypad::right_held()) {
                if (!col[2] || (col[0] && col[2] && !col[3] && col[7])) {
                    entity.set_x(entity.x() + 1);
                }
            }
            if (bn::keypad::up_held()) {
                if (
                    (!col[1] && 
                        (!col[3] || (!col[0] && col[2] && col[3] && col[4] && col[5])))
                    ||
                    (col[1] &&
                        (!col[2] && !col[3] && !col[4] && !col[5] && !col[6] && !col[7]))
                ) {
                    entity.set_y(entity.y() - 1);
                }
            }
            if (bn::keypad::down_held()) {
                if (
                    (!col[0] &&
                        (!col[2] || (col[2] && col[3] && col[4] && col[5])))
                    ||
                    (col[0] && col[1] && !col[2] &&
                        (col[4] || (!col[2] && !col[3] && !col[4])))
                ) {
                    entity.set_y(entity.y() + 1);
                }
            }

            // Move
            if ((bn::keypad::down_held() || bn::keypad::up_held() || bn::keypad::left_held() || bn::keypad::right_held()) || (entity_anim.current_index() % 2 == 1)) {
                entity_anim.update();
            } else {
                if (bn::keypad::r_pressed()) {
                    switch(dir) {
                        case 0:
                            entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 12, 0, 0, 0);
                            break;
                        case 1:
                            entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 13, 3, 3, 3);
                            break;
                        case 2:
                            entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 14, 6, 6, 6);
                            break;
                        case 3:
                            entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 15, 9, 9, 9);
                            break;
                    }
                    entity_anim.update();
                } else {
                    if (bn::keypad::r_released()) {
                        entity_anim.update();
                    }
                }
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

            BN_LOG(col[0],col[1],col[2],col[3]);

            // Follow player
            bool isXTravel = false;
            if (x < entity.x() - 24) {
                if ((!col[0]) || (col[0] && !col[1] && col[2])) {
                    isXTravel = true;
                    entity.set_x(entity.x() - 1);
                    dir = 2;
                    if (last_dir != dir) done = false;
                    last_dir = dir;
                    is_walking = true;
                }
            } else
            if (x > entity.x() + 24) {
                if (!col[2] || (col[0] && col[2] && !col[3])) {
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
                if ((!col[2] && !col[3]) || (!col[0] && (!col[2] || (col[2] && col[3] && col[4] && col[5])))) {
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

// Animated objects
class anim_object {
    public:
    int id = 0;
    bn::sprite_item entity_item = bn::sprite_items::aaron_sleep;
    bn::sprite_ptr entity = entity_item.create_sprite(0,0);
    bn::sprite_animate_action<4> entity_anim = bn::create_sprite_animate_action_forever(entity, 18, entity_item.tiles_item(), 0, 0, 0, 1);
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
        case 3: // Takin' a look out chari[1]'s window
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
        case 12: // dialogue about the whole eyebrow thing:
            exec_dialogue(10);
            break;
    };
    return dt;
}

dungeon_return dungeon(dungeon_return dt) {
    const int w_size = 96;
    stone local_walls[w_size];
    int local_walls_p = 0;
    room current_room;

    // Camera setup
    bn::camera_ptr camera = bn::camera_ptr::create(0,0);
    bn::regular_bg_ptr primary_bg = bn::regular_bg_items::castle_floor.create_bg(0, 0);
    primary_bg.set_camera(camera);
    bn::vector<anim_object,3> anim_objects;

    // World generation
    switch(dt.world_index) {
        case 0: {
            current_room.init(12, 6, 8, 3);
            int local[406] = {
                4,3,8,11,13,3,3,3,8,3,5,0,
                2,18,0,0,0,18,2,9,0,9,2,0,
                2,0,0,0,0,0,2,10,0,10,2,0,
                2,0,0,0,0,0,0,0,0,0,2,0,
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
                2,18,0,0,0,0,0,28,0,0,0,0,0,0,0,0,0,0,0,18,2,
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

            anim_object fp;
            fp.entity_item = bn::sprite_items::fireplace_anim;
            fp.entity = fp.entity_item.create_sprite(0,0);
            fp.entity_anim = bn::create_sprite_animate_action_forever(fp.entity, 2, fp.entity_item.tiles_item(), 0, 1, 0, 2);
            fp.entity.set_visible(false);
            fp.entity.set_camera(camera);
            fp.entity.set_position(304,176);
            anim_objects.push_back(fp);
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
            current_room.actions[4].set(2,3,12);

            anim_object aaron;
            aaron.entity.set_visible(true);
            aaron.entity.set_camera(camera);
            aaron.entity.set_position(64,48);
            anim_objects.push_back(aaron);

            anim_object del;
            del.id = 1;
            del.entity_item = bn::sprite_items::del_sleep;
            del.entity = del.entity_item.create_sprite(0,0);
            del.entity_anim = bn::create_sprite_animate_action_forever(del.entity, 20, del.entity_item.tiles_item(), 0, 1, 0, 0);
            del.entity.set_visible(true);
            del.entity.set_camera(camera);
            del.entity.set_position(256,48);
            anim_objects.push_back(del);
            break;
        }
    };

    // If different than default, reset
    if (dt.spawn_x > 0 && dt.spawn_y > 0 && dt.spawn_x < 999) {
        current_room.start_x = dt.spawn_x;
        current_room.start_y = dt.spawn_y;
        bn::sound_items::door.play();
    }

    // Camera init
    camera.set_position(current_room.start_x * 32, current_room.start_y * 32);

    // A header
    bn::sprite_ptr a_notif = bn::sprite_items::a_button_2.create_sprite(0, 0);
    a_notif.set_camera(camera);
    a_notif.set_visible(false);

    // Create initial characters
    character maple(bn::sprite_items::maple_walking, current_room, current_room.start_x, current_room.start_y, false);
    character enoki(bn::sprite_items::enoki_walking_pj, current_room, current_room.start_x - 1, current_room.start_y, false);
    int max_chari = 2;
    character chari[2] = {maple, enoki};

    for (int t = 0; t < 2; t++) {
        chari[t].entity.set_camera(camera);
    }

    chari[save::last_char_id].isMain = true;

    // Make a fireball!
    int p_index = 0;
    int p_size = 3;
    projectile p[3];
    for (int t = 0; t < 3; t++) {
        p[t].fireball.set_camera(camera);
        p[t].fireball.set_visible(false);
    }

    // GAMELOOP
    int update_counter = 0;
    bool firstThing = true;
    int flex = 84;
    int follow_x = 0;
    int follow_y = 0;
    int follow_dir = 0;
    int follow_id = 0;

    while(true) {

        // Animate NPCs
        for (int t = 0; t < anim_objects.size(); t++) {
            anim_objects.at(t).entity_anim.update();
            anim_objects.at(t).entity = anim_objects.at(t).entity_anim.sprite();
        }

        // Create projectiles
        if (bn::keypad::r_pressed()) {
            if (follow_id == 0) {
                bn::sound_items::fireblast.play();
                p[p_index].active = true;
                p[p_index].fireball.set_x(follow_x);
                p[p_index].fireball.set_y(follow_y);
                p[p_index].dir = chari[follow_id].dir;
                p[p_index].dur = 0;
                p[p_index].fireball.set_visible(true);
                p_index++;
                if (p_index >= p_size) p_index = 0;
            } else {
                bn::sound_items::squeak.play();
            }
        }

        // Update projectiles
        for (int t = 0; t < p_size; t++) {
            if (p[t].active) {
                if (p[t].dir == 3) p[t].fireball.put_above();
                p[t].update();
                if (p[t].dur < 16 && (
                    current_room.local_tileset[
                        (p[t].fireball.x().integer() / 32) +
                        ((p[t].fireball.y().integer() / 32) * current_room.width)] > 0
                    )) {
                    p[t].dur = 16;
                }
            }
        }

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
            bn::sound_items::cnaut.play();
            bn::blending::set_intensity_alpha(1);
            int new_chari = (follow_id + 1) % max_chari;
            save::last_char_id = new_chari;
            chari[follow_id].isMain = false;
            chari[follow_id].entity.set_blending_enabled(false);
            chari[new_chari].isMain = true;
            chari[new_chari].entity.set_blending_enabled(true);
        }

        // Character operations
        int base_y = chari[0].entity.y().integer();
        for (int t = 0; t < 2; t++) {

            // Set primary camera following X/Y coordinates
            if (chari[t].isMain) {
                chari[t].update();
                follow_x = chari[t].entity.x().integer();
                follow_y = chari[t].entity.y().integer();
                follow_dir = chari[t].dir;
                follow_id = t;
            }

            // Z-Order followers
            if (chari[t].entity.y() > chari[(t+1)%max_chari].entity.y()) {
                base_y = chari[t].entity.y().integer();
                chari[t].entity.put_above();
            }

            if (!chari[t].isMain) {
                chari[t].update(follow_x,follow_y);
            }
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

        // To run before everything else
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
                        int music_volume = 50;
                        bn::music_items_info::span[2].first.play(bn::fixed(music_volume) / 100);
                    }

                    break;
                }
            };
            firstThing = false;
        } else {

            // World-specific special events
            switch(dt.world_index) {
                case 1:
                    for (int i = 0; i < p_size; i++) {
                        if (p[i].active) {
                            int my_x = p[i].fireball.x().integer() / 32;
                            int my_y = p[i].fireball.y().integer() / 32;
                            if (my_x >= 8 && my_x <= 11 && my_y >= 4 && my_y <= 7) {
                                anim_objects.at(0).entity.set_visible(true);
                            }
                        }
                    }
                    break;
                case 2:
                    for (int i = 0; i < p_size; i++) {
                        if (p[i].active && p[i].dur < 16) {
                            int my_x = p[i].fireball.x().integer() / 32;
                            int my_y = p[i].fireball.y().integer() / 32;
                            if (my_x >= 2 && my_x <= 3 && my_y >= 2 && my_y <= 3) {
                                p[i].dur = 16;
                                anim_objects.at(0).entity_anim = bn::create_sprite_animate_action_forever(anim_objects.at(0).entity, 18, anim_objects.at(0).entity_item.tiles_item(), 2, 1, 0, 1);
                                anim_objects.at(0).entity.set_horizontal_flip(!anim_objects.at(0).entity.horizontal_flip());
                                anim_objects.at(0).entity_anim.update();
                            }
                        }
                    }
            }
        }
    }
}