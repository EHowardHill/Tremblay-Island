#include <bn_sprite_builder.h>
#include <bn_sprite_animate_actions.h>

// UI elements
#include "bn_sprite_items_a_button_2.h"

// Characters
#include "bn_sprite_items_maple_walking.h"
#include "bn_sprite_items_maple_walking_spring.h"
#include "bn_sprite_items_enoki_walking_pj.h"
#include "bn_sprite_items_enoki_walking_spring.h"
#include "bn_sprite_items_aaron_sleep.h"
#include "bn_sprite_items_aaron_walking_spring.h"
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

// Backgrounds
#include "bn_sprite_items_environment_stone.h"
#include "bn_sprite_items_trailer_home.h"
#include "bn_sprite_items_pools_tiles.h"
#include "bn_regular_bg_items_castle_floor.h"
#include "bn_regular_bg_items_bg_landry_cottage.h"
#include "bn_regular_bg_items_bg_diana_room.h"
#include "bn_regular_bg_items_greenhouse_bg_01.h"
#include "bn_regular_bg_items_greenhouse_bg_02.h"
#include "bn_regular_bg_items_bg_library.h"
#include "bn_regular_bg_items_bg_guy_house.h"

#include "bn_sprite_items_ocean_terrain.h"
#include "bn_regular_bg_items_grassy_knoll.h"
#include "bn_sprite_items_water_animation.h"
#include "bn_sprite_items_scout_lab.h"
#include "bn_sprite_items_corinne.h"
#include "bn_sprite_items_diana_uke.h"

#include "bn_regular_bg_items_dialogue_bg.h"

#include "bn_sprite_items_funny_items.h"

// Projectiles
class projectile
{
public:
    bn::sprite_item fireball_item = bn::sprite_items::fireball;
    bn::sprite_ptr fireball = fireball_item.create_sprite(0, 0);
    bn::sprite_animate_action<4> fireball_anim = bn::create_sprite_animate_action_forever(fireball, 3, fireball_item.tiles_item(), 00, 1, 2, 3);
    bn::sprite_animate_action<4> fireball_anim_end = bn::create_sprite_animate_action_forever(fireball, 3, fireball_item.tiles_item(), 4, 5, 6, 7);
    int dir = 1, dur = 0;
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

// Individual tiles
class stone
{
public:
    bn::sprite_ptr entity = bn::sprite_items::environment_stone.create_sprite(300, 300, 0);
    void set(int x, int y, const bn::sprite_item sprite, int loc = 0)
    {
        entity = sprite.create_sprite(x, y, loc);
    };
};

// Dungeon return type
class dungeon_return
{
public:
    int spawn_x = 0;
    int spawn_y = 0;
    int world_index = 0;
};

// Room setup object
class room
{
public:
    int width = 29;
    int height = 14;
    int start_x = 8;
    int start_y = 3;
    std::vector<int> local_tileset = {0};
    std::vector<int> collisions = {0};

    void init(int w, int h, int x, int y)
    {
        width = w;
        height = h;
        start_x = x;
        start_y = y;
    }
};

// Custom character class
class character
{
public:
    int identity = 0;
    int dir = 0;
    int last_dir = 0;
    bool done = false;
    bool is_walking = false;
    bool event = false;
    bn::sprite_item entity_item = bn::sprite_items::maple_walking;
    bn::sprite_ptr entity = entity_item.create_sprite(0, 0);
    bn::sprite_animate_action<4> entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 00, 1, 00, 2);

    int role = 0;
    // 0 = follower
    // 1 = main
    // 2 = independent

    int collideFrom = 1;
    room *current_room;

    character(const bn::sprite_item sprite, room &new_room, float x = 00, float y = 00, int main = 0)
    {
        entity = sprite.create_sprite(x * 32, y * 32);
        entity.set_visible(true);
        entity_item = sprite;
        entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 00, 1, 00, 2);
        role = main;
        current_room = &new_room;
    }

    // Get position on board
    int get_loc()
    {
        return ((entity.x().round_integer() / 32) + 5) + (((entity.y().round_integer() / 32) + 1) * 8) + 5;
    }

    // Run this regularly!
    void update(int x = 00, int y = 0)
    {

        // Collision detection
        int x_int = entity.x().integer();
        int y_int = entity.y().integer();
        int close[4] = {
            roundDown(x_int + 6),
            roundUp(x_int - 6),
            roundDown(y_int + 6) * current_room->width,
            roundUp(y_int) * current_room->width};

        int col[8] = {
            current_room->collisions[close[0] + close[2]] == 1,
            current_room->collisions[close[0] + close[3]] == 1,

            current_room->collisions[close[1] + close[2]] == 1,
            current_room->collisions[close[1] + close[3]] == 1,

            current_room->collisions[close[0] + close[2]] == 1,
            current_room->collisions[close[1] + close[2]] == 1,

            current_room->collisions[close[0] + close[3]] == 1,
            current_room->collisions[close[1] + close[3]] == 1};

        bool canLeft = !(((col[4] && col[5]) ^ col[0]) || ((col[6] && col[7]) ^ col[1]));
        bool canRite = !(((col[4] && col[5]) ^ col[2]) || ((col[6] && col[7]) ^ col[3]));
        bool canUp = !(((col[0] && col[1]) ^ col[4]) || ((col[2] && col[3]) ^ col[5]));
        bool canDn = !(((col[0] && col[1]) ^ col[6]) || ((col[2] && col[3]) ^ col[7]));

        // If following...
        if (role == 0)
        {

            // Collision detection
            done = true;
            is_walking = false;

            // Follow player
            bool isXTravel = false;
            if (x < entity.x() - 24)
            {
                if (canLeft)
                {
                    isXTravel = true;
                    entity.set_x(entity.x() - 1);
                    dir = 2;
                    if (last_dir != dir)
                        done = false;
                    last_dir = dir;
                    is_walking = true;
                }
            }
            else if (x > entity.x() + 24)
            {
                if (canRite)
                {
                    isXTravel = true;
                    entity.set_x(entity.x() + 1);
                    dir = 1;
                    if (last_dir != dir)
                        done = false;
                    last_dir = dir;
                    is_walking = true;
                }
            }
            if (y < entity.y() - 24)
            {
                if (canUp)
                {
                    entity.set_y(entity.y() - 1);
                    if (!isXTravel)
                    {
                        dir = 3;
                        if (last_dir != dir)
                            done = false;
                        last_dir = dir;
                        is_walking = true;
                    }
                }
            }
            else if (y > entity.y() + 24)
            {
                if (canDn)
                {
                    entity.set_y(entity.y() + 1);
                    if (!isXTravel)
                    {
                        dir = 0;
                        if (last_dir != dir)
                            done = false;
                        last_dir = dir;
                        is_walking = true;
                    }
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
                if (event) done = false;
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

            // Key controls
            if (bn::keypad::left_held())
            {
                entity.set_x(entity.x() + (-1 * canLeft));
            }
            if (bn::keypad::right_held())
            {
                entity.set_x(entity.x() + (1 * canRite));
            }
            if (bn::keypad::up_held())
            {
                entity.set_y(entity.y() + (-1 * canUp));
            }
            if (bn::keypad::down_held())
            {
                entity.set_y(entity.y() + (1 * canDn));
            }

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

        if (event) {
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
        entity = entity_anim.sprite();
        //entity.set_camera(camera);
    }
};

// Animated objects
class anim_object
{
public:
    int id = 0;
    bn::sprite_item entity_item = bn::sprite_items::aaron_sleep;
    bn::sprite_ptr entity = entity_item.create_sprite(0, 0);
    bn::sprite_animate_action<4> entity_anim = bn::create_sprite_animate_action_forever(entity, 18, entity_item.tiles_item(), 00, 00, 00, 1);
};

dungeon_return dungeon(dungeon_return &dt, save_struct *so, bool door_noise = true)
{



    if (so->checkpoint > 1) {
        if (bn::music::playing())
            bn::music::stop();
    }

    // Constants
    const int w_size = 96;
    stone local_walls[w_size];
    int local_walls_p = 0;
    static room current_room;

    // If different than default, reset
    if (dt.spawn_x > 0 && dt.spawn_y > 0)
    {
        current_room.start_x = dt.spawn_x;
        current_room.start_y = dt.spawn_y;
    }

    // Camera setup
    int sx = current_room.start_x * 32;
    int sy = current_room.start_y * 32;

    bn::camera_ptr camera = bn::camera_ptr::create(sx, sy);
    bn::regular_bg_ptr primary_bg = bn::regular_bg_items::velvet.create_bg(0, 0);
    primary_bg.set_camera(camera);
    bn::vector<anim_object, 3> anim_objects;

    // Create initial characters
    bn::vector<character, 4> chari;
    switch (so->last_char_id)
    {
        default:
        {
            if (dt.world_index < 4) {
            character default_chari(bn::sprite_items::maple_walking, current_room, current_room.start_x, current_room.start_y, false);
            default_chari.entity.set_camera(camera);
            default_chari.entity.set_position(sx, sy);
            default_chari.role = 1;
            default_chari.identity = 0;
            chari.push_back(default_chari);
            break;
            } else {
                character default_chari(bn::sprite_items::maple_walking_spring, current_room, current_room.start_x, current_room.start_y, false);
                default_chari.entity.set_camera(camera);
                default_chari.entity.set_position(sx, sy);
                default_chari.role = 1;
                default_chari.identity = 0;
                chari.push_back(default_chari);
                break;
            }
        }
        case 0:
        {
            if (dt.world_index < 4) {
                character default_chari(bn::sprite_items::maple_walking, current_room, current_room.start_x, current_room.start_y, false);
                default_chari.entity.set_camera(camera);
                default_chari.entity.set_position(sx, sy);
                default_chari.role = 1;
                default_chari.identity = 0;
                chari.push_back(default_chari);
                break;
            } else {
                character default_chari(bn::sprite_items::maple_walking_spring, current_room, current_room.start_x, current_room.start_y, false);
                default_chari.entity.set_camera(camera);
                default_chari.entity.set_position(sx, sy);
                default_chari.role = 1;
                default_chari.identity = 0;
                chari.push_back(default_chari);
                break;
            }
        }
        case 1:
        {
            if (so->checkpoint < 1) {
                character default_chari(bn::sprite_items::enoki_walking_pj, current_room, current_room.start_x, current_room.start_y, false);
                default_chari.entity.set_camera(camera);
                default_chari.entity.set_position(sx, sy);
                default_chari.role = 1;
                default_chari.identity = 1;
                chari.push_back(default_chari);
                break;
            } else {
                character default_chari(bn::sprite_items::enoki_walking_spring, current_room, current_room.start_x, current_room.start_y, false);
                default_chari.entity.set_camera(camera);
                default_chari.entity.set_position(sx, sy);
                default_chari.role = 1;
                default_chari.identity = 1;
                chari.push_back(default_chari);
                break;
            }
        }
        case 2:
        {
            character default_chari(bn::sprite_items::aaron_walking_spring, current_room, current_room.start_x, current_room.start_y, false);
            default_chari.entity.set_camera(camera);
            default_chari.entity.set_position(sx, sy);
            default_chari.role = 1;
            default_chari.identity = 2;
            chari.push_back(default_chari);
            break;
        }
        case 3:
        {
            character default_chari(bn::sprite_items::scout_walking_spring, current_room, current_room.start_x, current_room.start_y, false);
            default_chari.entity.set_camera(camera);
            default_chari.entity.set_position(sx, sy);
            default_chari.role = 1;
            default_chari.identity = 3;
            chari.push_back(default_chari);
            break;
        }
        case 4:
        {
            character default_chari(bn::sprite_items::vee_walking_spring, current_room, current_room.start_x, current_room.start_y, false);
            default_chari.entity.set_camera(camera);
            default_chari.entity.set_position(sx, sy);
            default_chari.role = 1;
            default_chari.identity = 4;
            chari.push_back(default_chari);
            break;
        }
        case 5:
        {
            character default_chari(bn::sprite_items::eleanor_walking_spring, current_room, current_room.start_x, current_room.start_y, false);
            default_chari.entity.set_camera(camera);
            default_chari.entity.set_position(sx, sy);
            default_chari.role = 1;
            default_chari.identity = 5;
            chari.push_back(default_chari);
            break;
        }
        case 6:
        {
            character default_chari(bn::sprite_items::diana_walking_spring, current_room, current_room.start_x, current_room.start_y, false);
            default_chari.entity.set_camera(camera);
            default_chari.entity.set_position(sx, sy);
            default_chari.role = 1;
            default_chari.identity = 6;
            chari.push_back(default_chari);
            break;
        }
        case 7:
        {
            character default_chari(bn::sprite_items::guy_walking_spring, current_room, current_room.start_x, current_room.start_y, false);
            default_chari.entity.set_camera(camera);
            default_chari.entity.set_position(sx, sy);
            default_chari.role = 1;
            default_chari.identity = 7;
            chari.push_back(default_chari);
            break;
        }
    }

    // World generation
    switch (dt.world_index)
    {
        case 0:
        {
            current_room.init(12, 6, 8, 3);
            std::vector<int> local_col{
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                1, 1, 2, 40, 3, 1, 1, 1, 0, 1, 1, 0,
                1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0,
                1, 0, 0, 0, 0, 0, 0, 0, 39, 0, 1, 0,
                1, 36, 0, 0, 0, 0, 0, 0, 31, 1, 1, 0,
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
            std::vector<int> local{
                4, 3, 8, 11, 13, 3, 3, 3, 8, 3, 5, 0,
                2, 18, 0, 0, 0, 18, 2, 9, 0, 9, 2, 0,
                2, 0, 0, 0, 0, 0, 2, 10, 0, 10, 2, 0,
                2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0,
                17, 0, 0, 0, 0, 0, 0, 0, 0, 18, 2, 0,
                7, 3, 3, 3, 3, 3, 3, 3, 16, 3, 6, 0};
            deep_copy(local, current_room.local_tileset);
            deep_copy(local_col, current_room.collisions);

            if (so->last_char_id == 1)
            {
                character maple(bn::sprite_items::maple_walking, current_room, 8, 3, false);
                maple.entity.set_position((current_room.start_x + 1) * 32, current_room.start_y * 32);
                maple.entity.set_camera(camera);
                maple.role = 0;
                maple.identity = 0;
                chari.push_back(maple);
            }

            if (so->last_char_id < 1)
            {
                character enoki(bn::sprite_items::enoki_walking_pj, current_room, 8, 3, false);
                enoki.entity.set_position((current_room.start_x + 1) * 32, current_room.start_y * 32);
                enoki.entity.set_camera(camera);
                enoki.role = 0;
                enoki.identity = 1;
                chari.push_back(enoki);
            }
            
            primary_bg = bn::regular_bg_items::castle_floor.create_bg(0, 0);
            primary_bg.set_camera(camera);
            break;
        }
        case 1:
        {
            current_room.init(21, 12, 18, 1);
            std::vector<int> local{
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
            std::vector<int> local_col{
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 0, 35, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 1, 1,
                1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                1, 1, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 1, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
            };
            deep_copy(local, current_room.local_tileset);
            deep_copy(local_col, current_room.collisions);

            if (so->last_char_id == 1)
            {
                character maple(bn::sprite_items::maple_walking, current_room, 8, 3, false);
                maple.entity.set_position(chari.at(0).entity.x(), chari.at(0).entity.y());
                maple.entity.set_camera(camera);
                maple.role = 0;
                maple.identity = 0;
                chari.push_back(maple);
            }

            if (so->last_char_id < 1)
            {
                character enoki(bn::sprite_items::enoki_walking_pj, current_room, 8, 3, false);
                enoki.entity.set_position(chari.at(0).entity.x(), chari.at(0).entity.y());
                enoki.entity.set_camera(camera);
                enoki.role = 0;
                enoki.identity = 1;
                chari.push_back(enoki);
            }

            anim_object fp;
            fp.entity_item = bn::sprite_items::fireplace_anim;
            fp.entity = fp.entity_item.create_sprite(0, 0);
            fp.entity_anim = bn::create_sprite_animate_action_forever(fp.entity, 2, fp.entity_item.tiles_item(), 00, 1, 00, 2);
            fp.entity.set_visible(false);
            fp.entity.set_camera(camera);
            fp.entity.set_position(304, 176);
            anim_objects.push_back(fp);

            primary_bg = bn::regular_bg_items::castle_floor.create_bg(0, 0);
            primary_bg.set_camera(camera);
            break;
        }
        case 2:
        {
            current_room.init(11, 8, 9, 6);
            std::vector<int> local {
                4, 11, 8, 12, 8, 3, 3, 3, 3, 3, 5,
                2, 18, 9, 9, 26, 27, 2, 0, 0, 0, 2,
                2, 0, 10, 10, 0, 0, 2, 19, 1, 20, 2,
                2, 0, 0, 0, 0, 0, 2, 3, 0, 0, 2,
                2, 0, 1, 1, 1, 0, 2, 0, 0, 18, 2,
                2, 0, 1, 1, 1, 0, 2, 0, 0, 3, 12,
                2, 18, 0, 0, 0, 0, 0, 0, 0, 0, 17,
                7, 3, 3, 14, 3, 3, 3, 3, 3, 3, 6};
            std::vector<int> local_col {
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 0, 1, 1, 0, 0, 1, 1, 8, 1, 1,
                1, 0, 10, 10, 0, 0, 1, 1, 0, 0, 1,
                1, 0, 0, 0, 0, 0,   1, 0, 0, 1, 1,
                1, 0, 0, 0, 0, 0,   1, 0, 0, 1, 1,
                1, 1, 0, 34, 0, 4, 0, 0, 0, 33, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
            };
            deep_copy(local, current_room.local_tileset);
            deep_copy(local_col, current_room.collisions);

            if (so->last_char_id == 1)
            {
                character maple(bn::sprite_items::maple_walking, current_room, 8, 3, false);
                maple.entity.set_position(chari.at(0).entity.x(), chari.at(0).entity.y());
                maple.entity.set_camera(camera);
                maple.role = 0;
                maple.identity = 0;
                chari.push_back(maple);
            }

            if (so->last_char_id < 1)
            {
                character enoki(bn::sprite_items::enoki_walking_pj, current_room, 8, 3, false);
                enoki.entity.set_position(chari.at(0).entity.x(), chari.at(0).entity.y());
                enoki.entity.set_camera(camera);
                enoki.role = 0;
                enoki.identity = 1;
                chari.push_back(enoki);
            }

            anim_object aaron;
            aaron.entity.set_visible(true);
            aaron.entity.set_camera(camera);
            aaron.entity.set_position(64, 48);
            anim_objects.push_back(aaron);

            anim_object del;
            del.id = 1;
            del.entity_item = bn::sprite_items::del_sleep;
            del.entity = del.entity_item.create_sprite(0, 0);
            del.entity_anim = bn::create_sprite_animate_action_forever(del.entity, 20, del.entity_item.tiles_item(), 00, 1, 00, 0);
            del.entity.set_visible(true);
            del.entity.set_camera(camera);
            del.entity.set_position(256, 48);
            anim_objects.push_back(del);

            primary_bg = bn::regular_bg_items::castle_floor.create_bg(0, 0);
            primary_bg.set_camera(camera);
            break;
        }
        case 3:
        {
            current_room.init(24, 12, 22, 1);
            std::vector<int> local{
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
            std::vector<int> local_col {
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
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
            };
            deep_copy(local, current_room.local_tileset);
            deep_copy(local_col, current_room.collisions);

            if (so->last_char_id == 1)
            {
                character maple(bn::sprite_items::maple_walking, current_room, 8, 3, false);
                maple.entity.set_position(22 * 32, 1 * 32);
                maple.entity.set_camera(camera);
                maple.role = 0;
                maple.identity = 0;
                chari.push_back(maple);
            }

            if (so->last_char_id < 1)
            {
                character enoki(bn::sprite_items::enoki_walking_pj, current_room, 8, 3, false);
                enoki.entity.set_position(22 * 32, 1 * 32);
                enoki.entity.set_camera(camera);
                enoki.role = 0;
                enoki.identity = 1;
                chari.push_back(enoki);
            }

            anim_object fp;
            fp.entity_item = bn::sprite_items::bookshelf;
            fp.entity = fp.entity_item.create_sprite(0, 0);
            fp.entity_anim = bn::create_sprite_animate_action_forever(fp.entity, 2, fp.entity_item.tiles_item(), 00, 00, 00, 0);
            fp.entity.set_visible(true);
            fp.entity.set_camera(camera);
            fp.entity.set_position(144, 16);
            anim_objects.push_back(fp);

            //character enoki(bn::sprite_items::enoki_walking_pj, current_room, current_room.start_x - 0.9, current_room.start_y, false);
            /*
                if (current_room.local_tileset.at((current_room.start_x - 1) + (current_room.start_y * current_room.width)] > 0) {
                    enoki.entity.set_position(4 + current_room.start_x * 32, current_room.start_y * 32);
                    maple.entity.set_position(-4 + current_room.start_x * 32, (current_room.start_y * 32));
                }
                */

            for (int t = 0; t < 2; t++)
            {
                chari.at(t).entity.set_camera(camera);
            }

            primary_bg = bn::regular_bg_items::castle_floor.create_bg(0, 0);
            primary_bg.set_camera(camera);
            break;
        }
        case 4:
        {
            if (so->checkpoint == 5) {
                bn::music_items_info::span[21].first.play(bn::fixed(80) / 100);
            } else {
                bn::music_items_info::span[11].first.play(bn::fixed(80) / 100);
            }
            
            current_room.init(20, 20, 9, 17);

            if (so->checkpoint < 7) {
                std::vector<int> local_col{
                    00, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
                    00, 1, 1, 1, 0, 0, 0, 0, 22, 24, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0,
                    00, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    00, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0,
                    00, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0,
                    00, 26, 25, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0,
                    00, 1, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    00, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    00, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    01, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    01, 23, 21, 0, 0, 0, 0, 1, 20, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
                    01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    01, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    01, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,
                    01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0,
                    01, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0,
                    01, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0,
                    01, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                    00, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

                std::vector<int> local{
                    39,1,27,27,39,27,27,27,44,0,27,27,27,27,27,42,43,42,12,13,
                    1,27,0,0,0,0,0,0,0,0,0,0,0,0,0,43,3,43,11,26,
                    39,1,0,0,0,0,0,0,0,0,0,0,1,0,0,5,2,3,12,26,
                    38,27,0,0,0,15,18,18,18,18,18,18,18,23,0,4,3,2,11,26,
                    39,47,44,0,1,16,19,19,19,19,19,19,19,24,1,5,2,3,12,26,
                    38,0,0,0,27,17,20,21,20,22,20,21,20,25,27,4,3,2,11,26,
                    39,1,0,0,0,0,0,0,0,3,0,0,0,0,0,4,2,3,12,26,
                    38,27,1,0,0,0,0,0,0,2,0,0,0,0,0,5,3,2,11,26,
                    39,1,27,0,0,0,0,0,40,3,42,0,0,0,0,4,2,3,12,26,
                    0,27,44,0,0,0,0,1,41,2,43,1,0,14,7,6,3,2,11,26,
                    0,0,0,0,0,0,0,27,2,3,3,27,0,4,2,3,2,3,12,26,
                    38,0,1,0,0,0,0,0,2,2,3,0,0,5,3,2,3,2,11,26,
                    39,1,27,0,0,0,0,14,42,3,42,8,7,6,2,3,2,3,12,26,
                    38,27,0,0,0,0,14,6,43,2,43,2,3,2,3,2,3,46,45,26,
                    39,0,0,0,0,0,5,2,3,3,2,3,2,46,9,10,9,45,13,26,
                    42,7,8,7,8,7,6,3,3,2,3,2,46,45,13,26,26,26,26,26,
                    43,2,3,2,3,2,3,46,42,3,42,10,45,26,26,26,26,26,26,26,
                    42,10,9,10,9,10,9,45,43,2,43,26,26,26,26,26,26,26,0,0,
                    43,26,26,26,13,26,26,26,26,10,26,26,26,26,26,26,26,0,0,0,
                    26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,0,0,0};

                deep_copy(local, current_room.local_tileset);
                deep_copy(local_col, current_room.collisions);

            } else if (so->checkpoint < 9) {
                std::vector<int> local_col{
                    01, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
                    01,42,41, 0, 0, 0, 0, 0, 22, 24, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0,
                    01, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    00, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0,
                    00, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0,
                    00, 26, 25, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0,
                    00, 1, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    00, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    00, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    01, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    01, 23, 21, 0, 0, 0, 0, 1, 20, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
                    01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    01, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    01, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,
                    01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0,
                    01, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0,
                    01, 0, 0, 0, 0, 0, 0, 1, 1, 61, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0,
                    01, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                    00, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

                std::vector<int> local{
                    39,27,44,27,27,27,27,27,44,0,27,27,27,27,27,42,43,42,12,13,
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,43,3,43,11,26,
                    1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,5,2,3,12,26,
                    27,27,0,0,0,15,18,18,18,18,18,18,18,23,0,4,3,2,11,26,
                    39,47,44,0,1,16,19,19,19,19,19,19,19,24,1,5,2,3,12,26,
                    38,0,0,0,27,17,20,21,20,22,20,21,20,25,27,4,3,2,11,26,
                    39,1,0,0,0,0,0,0,0,3,0,0,0,0,0,4,2,3,12,26,
                    38,27,1,0,0,0,0,0,0,2,0,0,0,0,0,5,3,2,11,26,
                    39,1,27,0,0,0,0,0,40,3,42,0,0,0,0,4,2,3,12,26,
                    0,27,44,0,0,0,0,1,41,2,43,1,0,14,7,6,3,2,11,26,
                    0,0,0,0,0,0,0,27,2,3,3,27,0,4,2,3,2,3,12,26,
                    38,0,1,0,0,0,0,0,2,2,3,0,0,5,3,2,3,2,11,26,
                    39,1,27,0,0,0,0,14,42,3,42,8,7,6,2,3,2,3,12,26,
                    38,27,0,0,0,0,14,6,43,2,43,2,3,2,3,2,3,46,45,26,
                    39,0,0,0,0,0,5,2,3,3,2,3,2,46,9,10,9,45,13,26,
                    42,7,8,7,8,7,6,3,3,2,3,2,46,45,13,26,26,26,26,26,
                    43,2,3,2,3,2,3,46,42,3,42,10,45,26,26,26,26,26,26,26,
                    42,10,9,10,9,10,9,45,43,2,43,26,26,26,26,26,26,26,0,0,
                    43,26,26,26,13,26,26,26,52,10,26,26,26,26,26,26,26,0,0,0,
                    26,26,26,26,26,26,26,26,53,26,26,26,26,26,26,26,26,0,0,0};

                deep_copy(local, current_room.local_tileset);
                deep_copy(local_col, current_room.collisions);
            } else if (so->checkpoint < 11) {
                std::vector<int> local_col{
                    01, 1, 1, 1, 1, 1, 1, 1, 1,   1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
                    01,42,41, 0, 0, 0, 0, 0, 22, 24, 0, 0, 0, 0, 0, 1, 66, 1, 1, 0,
                    01, 1, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    00, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0,
                    00, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0,
                    00, 26, 25, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0,
                    00, 1, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    00, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    00, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    01, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    01, 23, 21, 0, 0, 0, 0, 1, 20, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
                    01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    01, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    01, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                    01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,
                    01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0,
                    01, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0,
                    01, 0, 0, 0, 0, 0, 0, 1, 1, 61, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0,
                    01, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                    00, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

                std::vector<int> local{
                    39,44,27,27,39,27,27,27,44,0,27,27,27,27,27,42,2,42,12,13,
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,43,3,43,11,26,
                    39,1,0,0,0,0,0,0,0,0,0,0,1,0,0,5,2,3,12,26,
                    38,27,0,0,0,15,18,18,18,18,18,18,18,23,0,4,3,2,11,26,
                    39,47,44,0,1,16,19,19,19,19,19,19,19,24,1,5,2,3,12,26,
                    38,0,0,0,27,17,20,21,20,22,20,21,20,25,27,4,3,2,11,26,
                    39,1,0,0,0,0,0,0,0,3,0,0,0,0,0,4,2,3,12,26,
                    38,27,1,0,0,0,0,0,0,2,0,0,0,0,0,5,3,2,11,26,
                    39,1,27,0,0,0,0,0,40,3,42,0,0,0,0,4,2,3,12,26,
                    0,27,44,0,0,0,0,1,41,2,43,1,0,14,7,6,3,2,11,26,
                    0,0,0,0,0,0,0,27,2,3,3,27,0,4,2,3,2,3,12,26,
                    38,0,1,0,0,0,0,0,2,2,3,0,0,5,3,2,3,2,11,26,
                    39,1,27,0,0,0,0,14,42,3,42,8,7,6,2,3,2,3,12,26,
                    38,27,0,0,0,0,14,6,43,2,43,2,3,2,3,2,3,46,45,26,
                    39,0,0,0,0,0,5,2,3,3,2,3,2,46,9,10,9,45,13,26,
                    42,7,8,7,8,7,6,3,3,2,3,2,46,45,13,26,26,26,26,26,
                    43,2,3,2,3,2,3,46,42,3,42,10,45,26,26,26,26,26,26,26,
                    42,10,9,10,9,10,9,45,43,2,43,26,26,26,26,26,26,26,26,0,
                    43,26,26,26,13,26,26,26,52,10,26,26,26,26,26,26,26,26,26,0,
                    26,26,26,26,26,26,26,26,53,26,26,26,26,26,26,26,26,0,0,0};

                deep_copy(local, current_room.local_tileset);
                deep_copy(local_col, current_room.collisions);
            }

            primary_bg = bn::regular_bg_items::grassy_knoll.create_bg(0, 0);

            if (so->checkpoint == 5) primary_bg.set_palette(bn::regular_bg_items::castle_floor.palette_item());
            primary_bg.set_camera(camera);
            break;
        }
        case 5:
        {
            bn::music_items_info::span[2].first.play(bn::fixed(80) / 100);

            current_room.init(11, 5, 5, 3);
            std::vector<int> local_col{
                01, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                01, 1, 0, 0, 17, 0, 18, 0, 0, 0, 1,
                01, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1,
                01, 1, 16, 1, 1, 13, 0, 1, 0, 1, 1,
                01, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
            std::vector<int> local{
                1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 51,
                2, 7, 0, 0, 0, 0, 0, 0, 0, 0, 52,
                3, 8, 0, 0, 0, 0, 0, 0, 0, 0, 53,
                4, 9, 0, 0, 0, 0, 0, 0, 0, 0, 54,
                5, 10, 0, 0, 0, 0, 0, 0, 0, 0, 55};
            deep_copy(local, current_room.local_tileset);
            deep_copy(local_col, current_room.collisions);

            primary_bg = bn::regular_bg_items::bg_trailer_home.create_bg(0, 0);
            primary_bg.set_camera(camera);

            if (so->last_char_id != 0)
            {
                character maple(bn::sprite_items::maple_walking_spring, current_room, 5, 1, false);
                maple.entity.set_position(5 * 32, 1 * 32);
                maple.entity.set_camera(camera);
                maple.role = 2;
                maple.identity = 0;
                chari.push_back(maple);
            }

            if (so->last_char_id != 1)
            {
                character enoki(bn::sprite_items::enoki_walking_spring, current_room, 6, 2, false);
                enoki.entity.set_position(6 * 32, 2 * 32);
                enoki.entity.set_camera(camera);
                enoki.role = 2;
                enoki.identity = 1;
                chari.push_back(enoki);
            }

            if (so->last_char_id != 2)
            {
                character aaron(bn::sprite_items::aaron_walking_spring, current_room, 4, 1, false);
                aaron.entity.set_position(4 * 32, 1 * 32);
                aaron.entity.set_camera(camera);
                aaron.role = 2;
                aaron.identity = 2;
                chari.push_back(aaron);
            }

            break;
        }
        case 6:
        {
            bn::music_items_info::span[17].first.play(bn::fixed(80) / 100);
            current_room.init(9, 11, 7, 3);
            std::vector<int> local{
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
            std::vector<int> local_col{
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
            deep_copy(local, current_room.local_tileset);
            deep_copy(local_col, current_room.collisions);

            if (so->last_char_id != 3)
            {
                character scout(bn::sprite_items::scout_walking_spring, current_room, 4, 8, false);
                scout.entity.set_position(4 * 32, 8 * 32);
                scout.entity.set_camera(camera);
                scout.role = 2;
                scout.identity = 3;
                chari.push_back(scout);
            }

            primary_bg = bn::regular_bg_items::velvet.create_bg(0, 0);
            primary_bg.set_camera(camera);
            break;
        }
        case 8:
        {
            bn::music_items_info::span[27].first.play(bn::fixed(80) / 100);

            current_room.init(20, 20, 9, 17);
            std::vector<int> local_col{
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                1,0,0,0,0,0,0,0,0,54,52,0,0,0,0,0,0,0,43,1,
                1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,
                1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,
                1,1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,0,1,1,
                1,1,0,1,1,1,1,1,1,0,0,0,1,1,1,1,0,0,1,1,
                1,1,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,0,1,1,
                1,1,0,0,0,1,48,0,0,0,0,0,1,1,1,1,44,0,1,1,
                1,1,0,0,0,45,0,0,0,0,0,0,1,1,1,1,0,0,1,1,
                1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
                1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,
                1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
                1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,
                1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,
                1,1,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,1,1,
                1,1,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,1,1,
                1,1,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,1,1,
                1,1,0,46,0,0,50,0,0,0,0,0,0,64,0,0,47,0,1,1,
                1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

            std::vector<int> local{
                35,35,35,35,35,35,35,35,35,44,0,35,35,35,35,35,35,39,27,27,
                1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,8,8,
                27,1,0,0,28,28,33,28,28,0,14,8,7,7,7,7,7,6,42,1,
                1,27,0,0,29,29,48,29,29,0,4,0,0,0,0,0,0,4,1,27,
                27,1,0,0,30,30,49,30,30,0,5,0,42,42,42,42,0,4,27,1,
                1,27,0,1,31,31,50,31,31,0,4,0,43,10,9,43,0,4,1,27,
                27,1,0,27,32,32,51,32,32,0,5,0,42,26,26,42,44,4,27,1,
                1,27,0,0,0,44,0,0,0,0,4,0,43,26,26,43,0,4,1,27,
                27,1,0,0,0,0,0,0,0,0,5,0,43,43,43,43,0,4,27,1,
                1,27,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,4,1,27,
                27,1,0,0,0,0,0,0,0,0,42,7,7,7,7,7,7,6,27,1,
                1,27,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,27,
                27,1,0,0,28,28,33,28,28,0,0,28,28,33,28,28,0,0,27,1,
                1,27,0,0,29,29,48,29,29,0,0,29,29,48,29,29,0,0,1,27,
                27,1,0,1,30,30,49,30,30,0,0,30,30,49,30,30,1,0,27,1,
                1,27,0,27,31,31,50,31,31,0,0,31,31,50,31,31,27,0,1,27,
                27,1,0,44,32,32,51,32,32,0,0,32,32,51,32,32,44,0,27,1,
                1,27,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,27,
                27,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,27,1,
                1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27};

            deep_copy(local, current_room.local_tileset);
            deep_copy(local_col, current_room.collisions);

            primary_bg = bn::regular_bg_items::grassy_knoll.create_bg(0, 0);

            if (so->checkpoint == 5) primary_bg.set_palette(bn::regular_bg_items::castle_floor.palette_item());
            primary_bg.set_camera(camera);
            break;
        }
        case 9:
        {
            bn::music_items_info::span[26].first.play(bn::fixed(80) / 100);
            chari.at(0).entity.set_position(3 * 32,5 * 32);

            current_room.init(7, 7, 3, 5);
            std::vector<int> local_col{
                1,1,1,1,1,1,1,
                1,1,1,57,0,1,1,
                1,1,1,0,0,1,1,
                1,1,1,0,0,0,1,
                1,1,1,55,0,0,1,
                1,1,1,49,1,1,1,
                1,1,1,1,1,1,1};

            std::vector<int> local{
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0};;

            deep_copy(local, current_room.local_tileset);
            deep_copy(local_col, current_room.collisions);

            if (so->last_char_id != 4)
            {
                character vee(bn::sprite_items::vee_walking_spring, current_room, 3, 2, false);
                vee.entity.set_position(3 * 32, 2 * 32);
                vee.entity.set_camera(camera);
                vee.role = 2;
                vee.identity = 4;
                chari.push_back(vee);
            }

            if (so->last_char_id != 5)
            {
                character eleanor(bn::sprite_items::eleanor_walking_spring, current_room, 4, 4, false);
                eleanor.entity.set_position(4 * 32, 4 * 32);
                eleanor.entity.set_camera(camera);
                eleanor.role = 2;
                eleanor.identity = 5;
                chari.push_back(eleanor);
            }

            primary_bg = bn::regular_bg_items::bg_landry_cottage.create_bg(0, 0);
            primary_bg.set_camera(camera);
            break;
        }
        case 10:
        {
            bn::music_items_info::span[5].first.play(bn::fixed(80) / 100);
            chari.at(0).entity.set_position(3 * 32,5 * 32);

            current_room.init(7, 7, 3, 5);
            std::vector<int> local_col{
                1,1,1,1,1,1,1,
                1,1,0,0,0,1,1,
                1,1,0,0,0,1,1,
                1,1,0,62,0,1,1,
                1,1,0,0,0,1,1,
                1,1,0,60,1,1,1,
                1,1,1,1,1,1,1};

            std::vector<int> local{
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0};;

            deep_copy(local, current_room.local_tileset);
            deep_copy(local_col, current_room.collisions);

            if (so->last_char_id != 6)
            {
                character vee(bn::sprite_items::diana_walking_spring, current_room, 3, 2, false);
                vee.entity.set_position(3 * 32, 2 * 32);
                vee.entity.set_camera(camera);
                vee.role = 2;
                vee.identity = 6;
                chari.push_back(vee);
            }

            primary_bg = bn::regular_bg_items::bg_diana_room.create_bg(0, 0);
            primary_bg.set_camera(camera);
            break;
        }
        case 11:
        {
            bn::music_items_info::span[12].first.play(bn::fixed(80) / 100);
            chari.at(0).entity.set_position(15 * 32,22 * 32);

            current_room.init(24, 24, 15, 22);
            std::vector<int> local_col{
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1,
                1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1,
                1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1,
                1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1,
                1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1,
                1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1,
                1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1,
                1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1,
                1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1,
                1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1,
                1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1,
                1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1,
                1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1,
                1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1,
                1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,
                1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,1,1,0,1,
                1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,1,1,0,1,
                1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,1,1,0,1,
                1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,53,0,0,0,0,0,0,0,1,
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
            };

            std::vector<int> local{
                2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                2,3,0,0,0,3,0,0,0,3,0,0,0,3,0,3,0,0,0,0,0,0,0,2,
                2,4,0,1,0,4,0,1,0,4,0,1,0,11,0,3,20,24,24,24,24,24,0,2,
                2,5,0,0,0,5,0,0,0,5,0,0,0,12,0,3,21,28,30,28,30,25,0,2,
                2,6,0,0,0,6,0,0,0,6,0,0,0,13,0,3,20,29,31,29,31,22,0,2,
                2,7,0,0,0,7,0,0,0,7,0,0,0,14,0,3,21,28,30,28,30,23,0,2,
                2,8,0,0,0,8,0,0,0,8,0,0,0,15,0,3,20,29,31,29,31,22,0,2,
                2,9,0,1,0,9,0,1,0,9,0,1,0,16,0,3,21,26,26,26,26,26,0,2,
                2,10,0,0,0,10,0,0,0,10,0,0,0,17,0,3,2,27,27,27,27,27,0,2,
                2,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,
                2,5,0,0,0,12,0,0,0,5,0,0,0,12,0,3,20,24,24,24,24,24,0,2,
                2,6,0,1,0,13,0,1,0,6,0,1,0,13,0,3,21,28,30,28,30,25,0,2,
                2,7,0,0,0,14,0,0,0,7,0,0,0,14,0,3,20,29,31,29,31,22,0,2,
                2,8,0,0,0,15,0,0,0,8,0,0,0,15,0,3,21,28,30,28,30,23,0,2,
                2,9,0,0,0,16,0,0,0,9,0,0,0,16,0,3,20,29,31,29,31,22,0,2,
                2,10,0,1,0,17,0,1,0,10,0,1,0,17,0,3,21,26,26,26,26,26,0,2,
                2,11,0,0,0,11,0,0,0,4,0,0,0,11,0,3,2,27,27,27,27,27,2,2,
                2,12,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,
                2,13,0,0,0,13,0,0,0,6,0,0,0,13,0,3,0,0,0,0,0,0,0,2,
                2,14,0,1,0,14,0,1,0,7,0,1,0,14,0,3,0,4,0,7,11,15,0,2,
                2,15,0,0,0,15,0,0,0,8,0,0,0,15,0,3,0,5,0,8,12,16,0,2,
                2,16,0,1,0,16,0,1,0,9,0,1,0,16,0,3,0,6,0,9,10,17,0,2,
                2,3,0,0,0,3,0,0,0,3,0,0,0,3,0,3,0,0,0,0,0,0,0,2,
                2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2
            };

            deep_copy(local, current_room.local_tileset);
            deep_copy(local_col, current_room.collisions);

            if (so->last_char_id != 4)
            {
                character vee(bn::sprite_items::vee_walking_spring, current_room, 3, 2, false);
                vee.entity.set_position(14 * 32, 20 * 32);
                vee.entity.set_camera(camera);
                vee.role = 2;
                vee.identity = 4;
                chari.push_back(vee);
            }

            primary_bg = bn::regular_bg_items::greenhouse_bg_01.create_bg(0, 0);
            primary_bg.set_camera(camera);
            break;
        }
        case 12:
        {
            if (bn::music::playing()) bn::music::stop();

            current_room.init(7, 7, 3, 5);
            std::vector<int> local_col{
                1,1,1,1,1,1,1,
                1,0,59,0,0,0,1,
                1,0,1,1,1,0,1,
                1,0,1,1,1,0,1,
                1,0,1,1,1,0,1,
                1,0,0,58,0,0,1,
                1,1,1,1,1,1,1};

            std::vector<int> local{
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0};;

            deep_copy(local, current_room.local_tileset);
            deep_copy(local_col, current_room.collisions);

            primary_bg = bn::regular_bg_items::bg_library.create_bg(0, 0);
            primary_bg.set_camera(camera);
            break;
        }
        case 13:
        {
            bn::music_items_info::span[25].first.play(bn::fixed(80) / 100);
            chari.at(0).entity.set_position(3 * 32,5 * 32);

            current_room.init(7, 7, 3, 5);
            std::vector<int> local_col{
                1,1,1,1,1,1,1,
                1,1,0,0,1,1,1,
                1,1,0,1,0,1,1,
                1,1,0,1,0,1,1,
                1,1,0,0,0,1,1,
                1,1,1,65,1,1,1,
                1,1,1,1,1,1,1};

            std::vector<int> local{
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0};;

            deep_copy(local, current_room.local_tileset);
            deep_copy(local_col, current_room.collisions);

            if (so->last_char_id != 7)
            {
                character guy(bn::sprite_items::guy_walking_spring, current_room, 2, 2, false);
                guy.entity.set_position(2 * 32, 2 * 32);
                guy.entity.set_camera(camera);
                guy.role = 2;
                guy.identity = 7;
                chari.push_back(guy);
            }

            primary_bg = bn::regular_bg_items::bg_guy_house.create_bg(0, 0);
            primary_bg.set_camera(camera);
            break;
        }
        case 14: {
            bn::music_items_info::span[27].first.play(bn::fixed(80) / 100);
            
            current_room.init(12, 20, 7, 18);

            std::vector<int> local_col{
                01,01,01,01,01,01,01,01,01,01,01,01,
                01,01,01,01,01,01,01,01,01,01,01,01,
                01,01,01,01,01,00,00,00,01,01,01,01,
                01,01,01,00,00,00,00,00,00,01,01,01,
                01,01,01,01,01,01,00,00,00,01,01,01,
                01,01,01,01,01,01,00,00,00,01,01,01,
                01,01,01,01,01,01,00,00,00,01,01,01,
                01,01,01,01,01,00,00,00,00,01,01,01,
                01,01,01,68,00,00,00,01,00,01,01,01,
                01,01,69,00,00,00,00,00,00,01,01,01,
                01,01,00,00,00,00,00,00,00,01,01,01,
                01,01,00,00,00,00,00,00,00,01,01,01,
                01,01,00,00,00,00,00,00,00,01,01,01,
                01,01,00,00,00,00,00,00,00,01,01,01,
                01,01,00,00,00,00,00,00,00,01,01,01,
                01,01,00,00,00,00,00,00,00,01,01,01,
                01,01,00,00,00,00,00,00,00,01,01,01,
                01,01,00,01,00,00,00,00,00,01,01,01,
                01,01,01,00,01,00,01,67,01,01,01,01,
                01,01,01,01,01,01,01,01,01,01,01,01};

            std::vector<int> local{
                34,34,34,34,37,34,34,34,39,42,26,26,
                35,35,35,35,34,35,35,39,42,43,26,26,
                34,34,38,47,39,0,0,0,43,11,13,26,
                35,35,39,0,1,0,0,0,5,12,26,26,
                34,38,48,48,48,1,0,0,4,11,26,26,
                35,39,49,49,49,27,0,0,5,12,26,26,
                34,38,50,54,50,41,0,0,4,11,26,26,
                35,39,51,51,51,0,0,1,5,12,26,26,
                34,38,44,0,0,0,0,27,4,11,26,26,
                35,39,0,0,0,0,0,0,5,12,26,26,
                34,38,0,0,0,0,0,0,4,11,26,13,
                35,39,0,2,0,0,0,14,6,12,26,26,
                34,38,0,0,0,0,0,4,2,11,26,26,
                35,39,0,0,0,3,0,5,3,12,26,26,
                34,38,0,0,0,0,0,4,2,11,26,26,
                35,39,0,0,0,0,0,5,3,12,26,26,
                34,38,0,1,0,0,0,5,2,11,26,26,
                35,39,0,27,0,0,14,6,3,12,13,26,
                34,36,38,0,1,0,42,2,42,11,26,26,
                35,37,39,1,27,1,43,3,43,12,26,26};

            deep_copy(local, current_room.local_tileset);
            deep_copy(local_col, current_room.collisions);

            primary_bg = bn::regular_bg_items::grassy_knoll.create_bg(0, 0);
            primary_bg.set_camera(camera);
            break;
        }
        default:
        {
            break;
        }
    };

    // A header
    bn::sprite_ptr a_notif = bn::sprite_items::a_button_2.create_sprite(0, 0);
    a_notif.set_camera(camera);
    a_notif.set_visible(false);

    // Make a fireball!
    int p_index = 0;
    int p_size = 3;
    projectile p[3];
    for (int t = 0; t < 3; t++)
    {
        p[t].fireball.set_camera(camera);
        p[t].fireball.set_visible(false);
    }

    // GAMELOOP
    int update_counter = 0;
    bool firstThing = true;
    int flex = 84;
    int follow_x = 0;
    int follow_y = 0;
    int follow_id = 0;

    int anim8 = 0;

    // corinne be like
    auto corinne = bn::sprite_items::corinne.create_sprite(0,0);
    corinne.set_camera(camera);
    corinne.set_visible(false);

    // funny hat be like
    auto hat = bn::sprite_items::funny_items.create_sprite(0,0,0);
    hat.set_camera(camera);
    hat.set_visible(false);
    bool active_hat = false;
    for (int t = 0; t < chari.size(); t++) {
        if (so->hat_char == chari.at(t).identity) active_hat = true;
    }
    if (so->hat_world == dt.world_index) active_hat = true;
    if (active_hat) hat.set_visible(true);

    auto l_button = bn::sprite_items::l_button.create_sprite(-90,14);
    l_button.set_visible(false);

    bn::blending::set_transparency_alpha(bn::fixed(1));

    while (true)
    {
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

        // Animate NPCs
        for (int t = 0; t < anim_objects.size(); t++)
        {
            anim_objects.at(t).entity_anim.update();
            anim_objects.at(t).entity = anim_objects.at(t).entity_anim.sprite();
        }

        // Create projectiles
        if (bn::keypad::r_pressed())
        {
            chari.at(follow_id).event = true;
            if (chari.at(follow_id).identity == 0)
            {
                bn::sound_items::fireblast.play();
                p[p_index].active = true;
                p[p_index].fireball.set_x(follow_x);
                p[p_index].fireball.set_y(follow_y);
                p[p_index].dir = chari.at(follow_id).dir;
                p[p_index].dur = 0;
                p[p_index].fireball.set_visible(true);
                p_index++;
                if (p_index >= p_size)
                    p_index = 0;
            }
            else if (chari.at(follow_id).identity == 4) {
                bn::sound_items::firecrackle.play();

                if (so->checkpoint == 8 && so->xp < 201) {
                    so->xp++;
                } else if (so->checkpoint == 10 && so->xp < 301) {
                    so->xp++;
                }
                
            } else
            {
                bn::sound_items::squeak.play();
            }
        }

        // Update projectiles
        for (int t = 0; t < p_size; t++)
        {
            if (p[t].active)
            {
                p[t].fireball.set_z_order(1);
                p[t].update();
                /*
                if (p[t].dur < 16 && (current_room.collisions.at(
                                          (p[t].fireball.x().integer() / 32) +
                                          ((p[t].fireball.y().integer() / 32) * current_room.width)) > 0))
                {
                    p[t].dur = 16;
                }
                */
            }
        }

        // Control actions
        a_notif.set_visible(false);
        int possible_action = current_room.collisions.at(((follow_x + 16) / 32) + (((follow_y + 16) / 32) * current_room.width));
        if (possible_action > 1)
        {
            a_notif.set_visible(true);
            a_notif = bn::sprite_items::a_button_2.create_sprite(follow_x, follow_y - 28, 0);
            a_notif.set_camera(camera);
            //a_notif.set_x(follow_x);
            //a_notif.set_y(follow_y - 28);

            if (bn::keypad::a_pressed())
            {

                // Start action
                a_notif.set_visible(false);
                bn::core::update();

                int me = chari.at(follow_id).identity;

                switch (possible_action)
                {

                case 2:
                {
                    line lc[10] = {
                        {true, true, 00, "                                                                  MAPLE                            Enoki, there's no window."},
                        {true, true, 00, "                                                                  ENOKI                            Uh-huh?"},
                        {true, true, 00, "                                                                  MAPLE                            What happens if someone tries-"},
                        {true, true, 00, "                                                                  MAPLE                            to break in?"},
                        {true, true, 00, "                                                                  ENOKI                            Aaron punches 'em."},
                        {true, true, 00, "                                                                  ENOKI                            In the face."},
                        {true, true, 00, "                                                                  MAPLE                            He's not here, though."},
                        {true, true, 00, "                                                                  ENOKI                            Then I'll punch 'em."},
                        {true, true, 00, "                                                                  MAPLE                            I.... Hmm. Alright, then."},
                        {true, true, 00, "COM: Endscene"}};
                    dialogue_page_lite(lc);
                    break;
                };

                case 3:
                {
                    line l2[10] = {
                        {true, true, 00, "                                                                  You see a pot."},
                        {true, true, 00, "                                                                  You feel compelled to smash it."},
                        {true, true, 00, "                                                                  However, this is not possible."},
                        {true, true, 00, "                                                                  You feel strangely disappointed."},
                        {true, true, 00, "COM: Endscene"}};
                    dialogue_page_lite(l2);
                    break;
                };

                case 4:
                {
                    line lc[19] = {
                        {true, true, 00, "                                                                  MAPLE                            Hey, let's head out. I don't want"},
                        {true, true, 00, "                                                                  MAPLE                            to wake him up."},
                        {true, true, 00, "                                                                  ENOKI                            I dunno, it doesn't matter,"},
                        {true, true, 00, "                                                                  ENOKI                            there's no way he'll wake up."},
                        {true, true, 00, "                                                                  ENOKI                            He likes the light on, too."},
                        {true, true, 00, "                                                                  MAPLE                            I thought you didn't have"},
                        {true, true, 00, "                                                                  MAPLE                            electricity..?"},
                        {true, true, 00, "                                                                  ENOKI                            Oh, we do- just that one plug."},
                        {true, true, 00, "                                                                  ENOKI                            It's a very important plug."},
                        {true, true, 00, "                                                                  MAPLE                            You sure you like this place?"},
                        {true, true, 00, "                                                                  ENOKI                            You gonna come here and insult"},
                        {true, true, 00, "                                                                  ENOKI                            my house?"},
                        {true, true, 00, "                                                                  MAPLE                            Well, when you put it THAT way..."},
                        {true, true, 00, "                                                                  ENOKI                            Uh huh, that's what I thought."},
                        {true, true, 00, "                                                                  MAPLE                            Je m'excuse."},
                        {true, true, 00, "                                                                  ENOKI                            Merci."},
                        {true, true, 00, "                                                                  MAPLE                            But when you both move in with me"},
                        {true, true, 00, "                                                                  MAPLE                            don't say I didn't warn y'all."},
                        {true, true, 00, "COM: Endscene"}};
                    dialogue_page_lite(lc);
                    break;
                };

                case 8:
                {
                    line lc[9] = {
                        {true, true, 00, "                                                                  ENOKI                            Y'know, back when Del was my"},
                        {true, true, 00, "                                                                  ENOKI                            nanny, my parents gave her like"},
                        {true, true, 00, "                                                                  ENOKI                            three different rooms she could"},
                        {true, true, 00, "                                                                  ENOKI                            stay in. I don't think she ever"},
                        {true, true, 00, "                                                                  ENOKI                            slept anywhere but the tub."},
                        {true, true, 00, "                                                                  MAPLE                            That actually sounds pretty nice."},
                        {true, true, 00, "                                                                  ENOKI                            Yeah, I tried it but my skin"},
                        {true, true, 00, "                                                                  ENOKI                            didn't like it very much."},
                        {true, true, 00, "COM: Endscene"}};
                    dialogue_page_lite(lc);
                    break;
                };

                case 9:
                {
                    line lc[9] = {
                        {true, true, 00, "                                                                  MAPLE                            Enoki, this one's locked."},
                        {true, true, 00, "                                                                  ENOKI                            Oh. Yeah, I think that's"},
                        {true, true, 00, "                                                                  ENOKI                            the kitchen. We don't know where"},
                        {true, true, 00, "                                                                  ENOKI                            the key is."},
                        {true, true, 00, "                                                                  MAPLE                            So how do you eat??"},
                        {true, true, 00, "                                                                  ENOKI                            We make most of our food over the"},
                        {true, true, 00, "                                                                  ENOKI                            big fire pit!"},
                        {true, true, 00, "                                                                  MAPLE                            You two, I *swear*...."},
                        {true, true, 00, "COM: Endscene"}};
                    dialogue_page_lite(lc);
                    break;
                };

                case 10:
                {
                    line lc[20] = {
                        {true, true, 00, "                                                                  ENOKI                            Isn't he so cute when he"},
                        {true, true, 00, "                                                                  ENOKI                            sleeps like that? <3"},
                        {true, true, 00, "                                                                  MAPLE                            You've been married for, what,"},
                        {true, true, 00, "                                                                  MAPLE                            a few months now?"},
                        {true, true, 00, "                                                                  MAPLE                            Aren't you supposed to be at the"},
                        {true, true, 00, "                                                                  MAPLE                            stage where neither of you talk"},
                        {true, true, 00, "                                                                  MAPLE                            to each other at meals and both"},
                        {true, true, 00, "                                                                  MAPLE                            of you've gained ten pounds?"},
                        {true, true, 00, "                                                                  ENOKI                            Huh, I think I've lost weight."},
                        {true, true, 00, "                                                                  MAPLE                            I guess I don't get it."},
                        {true, true, 00, "                                                                  ENOKI                            Just cos you always get in"},
                        {true, true, 00, "                                                                  ENOKI                            fights with your ex-boyfriends"},
                        {true, true, 00, "                                                                  ENOKI                            doesn't mean every couple's like"},
                        {true, true, 00, "                                                                  ENOKI                            that, tu sais."},
                        {true, true, 00, "                                                                  ENOKI                            I mean, you've got this nasty"},
                        {true, true, 00, "                                                                  ENOKI                            habit of-"},
                        {true, true, 00, "                                                                  MAPLE                            You finish that sentence, and"},
                        {true, true, 00, "                                                                  MAPLE                            I'll burn your eyebrows off."},
                        {true, true, 00, "                                                                  ENOKI                            ......doing that."},
                        {true, true, 00, "COM: Endscene"}};
                    dialogue_page_lite(lc);
                    break;
                };

                case 11:
                {
                    line lc[32] = {
                        {true, true, 00, "                                                                  ENOKI                            Nous sommes ici!"},
                        {true, true, 00, "                                                                  ENOKI                            The bookshelf room."},
                        {true, true, 00, "                                                                  MAPLE                            You weren't kidding about there"},
                        {true, true, 00, "                                                                  MAPLE                            literally being just a bookshelf"},
                        {true, true, 00, "                                                                  MAPLE                            room, were you?"},
                        {true, true, 00, "                                                                  ENOKI                            Bon, so I can't move it and Aaron"},
                        {true, true, 00, "                                                                  ENOKI                            can't either, so I was wondering,"},
                        {true, true, 00, "                                                                  ENOKI                            how about using that elf magic?"},
                        {true, true, 00, "                                                                  MAPLE                            Let me get this straight..."},
                        {true, true, 00, "                                                                  MAPLE                            You want me to *burn* a perfectly"},
                        {true, true, 00, "                                                                  MAPLE                            good bookshelf?"},
                        {true, true, 00, "                                                                  ENOKI                            Yeah! I wanna see if there's a"},
                        {true, true, 00, "                                                                  ENOKI                            secret passage behind it or"},
                        {true, true, 00, "                                                                  ENOKI                            somethin', y'know?"},
                        {true, true, 00, "                                                                  MAPLE                            I refuse. This is rediculous."},
                        {true, true, 00, "                                                                  MAPLE                            These are perfectly good books."},
                        {true, true, 00, "                                                                  ENOKI                            Most are rotting away, so"},
                        {true, true, 00, "                                                                  ENOKI                            it's probably best that they get"},
                        {true, true, 00, "                                                                  ENOKI                            burned. I checked."},
                        {true, true, 00, "                                                                  MAPLE                            Are you sure?"},
                        {true, true, 00, "                                                                  ENOKI                            Absolutely."},
                        {true, true, 00, "                                                                  MAPLE                            Alright... I'll make a deal."},
                        {true, true, 00, "                                                                  MAPLE                            I'll burn this, but you need to"},
                        {true, true, 00, "                                                                  MAPLE                            save at least one book."}, //j'ai compris?
                        {true, true, 00, "                                                                  MAPLE                            J'ai compris? Oui?"},
                        {true, true, 00, "                                                                  ENOKI                            Oui!"},
                        {true, true, 00, "                                                                  ENOKI                            ....alright, I got my book."},
                        {true, true, 00, "                                                                  ENOKI                            Remember, use the 'R' trigger"},
                        {true, true, 00, "                                                                  ENOKI                            to send out a bolt of fire!"},
                        {true, true, 00, "                                                                  MAPLE                            ...What are you talking about??"},
                        {true, true, 00, "                                                                  ENOKI                            Huh? Oh, nothing"},
                        {true, true, 00, "COM: Endscene"}};
                    dialogue_page_lite(lc);
                    break;
                };

                case 12:
                {
                    line lc[32] = {
                        {true, true, 00, "                                                                  MAPLE                            ...."},
                        {true, true, 00, "                                                                  ENOKI                            Well, there's no passage."},
                        {true, true, 00, "                                                                  MAPLE                            You don't say."},
                        {true, true, 00, "                                                                  ENOKI                            That's weird."},
                        {true, true, 00, "                                                                  MAPLE                            Enoki... Look here."},
                        {true, true, 00, "                                                                  MAPLE                            I guess it doesn't make any sense"},
                        {true, true, 00, "                                                                  MAPLE                            to be angry, so I won't be, but.."},
                        {true, true, 00, "                                                                  MAPLE                            You need to stop being like this."},
                        {true, true, 00, "                                                                  MAPLE                            You and Aaron just spent all this"},
                        {true, true, 00, "                                                                  MAPLE                            money on a barely furnished"},
                        {true, true, 00, "                                                                  MAPLE                            castle without basic faculties"},
                        {true, true, 00, "                                                                  MAPLE                            for what? So you could play like"},
                        {true, true, 00, "                                                                  MAPLE                            you're a princess? While I'm over"},
                        {true, true, 00, "                                                                  MAPLE                            in Carolina, sacrificing the best"},
                        {true, true, 00, "                                                                  MAPLE                            parts of my life for an apartment"},
                        {true, true, 00, "                                                                  MAPLE                            with the bare essentials?"},
                        {true, true, 00, "                                                                  MAPLE                            Enoki... Please."},
                        {true, true, 00, "                                                                  MAPLE                            I don't want to be the bad guy."},
                        {true, true, 00, "                                                                  MAPLE                            I know you didn't really have a"},
                        {true, true, 00, "                                                                  MAPLE                            childhood or parents, I get it."},
                        {true, true, 00, "                                                                  MAPLE                            That's me too."},
                        {true, true, 00, "                                                                  MAPLE                            But you can't keep going on like"},
                        {true, true, 00, "                                                                  MAPLE                            this. Do you understand?"},
                        {true, true, 00, "                                                                  ENOKI                            I do understand."}, //j'ai compris?
                        {true, true, 00, "                                                                  MAPLE                            It's 5:00 in the morning, I'm"},
                        {true, true, 00, "                                                                  MAPLE                            going back to bed. I'll see y'all"},
                        {true, true, 00, "                                                                  MAPLE                            in the morning, oui?"},
                        {true, true, 00, "                                                                  ENOKI                            Oui.."},
                        {true, true, 00, "                                                                  MAPLE                            Hey, don't beat yourself up about"},
                        {true, true, 00, "                                                                  MAPLE                            it. S'il te plait.. Bonne nuit."},
                        {true, true, 00, "                                                                  ENOKI                            Bonne nuit.."},
                        {true, true, 00, "COM: Endscene"}};
                    dialogue_page_lite(lc);
                    break;
                };

                case 13:
                {
                    dt.spawn_x = 9;
                    dt.spawn_y = 6;
                    dt.world_index = 4;
                    bn::sound_items::door.play(); return dt;
                    break;
                };

                case 14:
                {
                    if (so->checkpoint > 3 || so->last_char_id == 0) {
                        dt.spawn_x = 5;
                        dt.spawn_y = 3;
                        dt.world_index = 5;
                        bn::sound_items::door.play(); return dt;
                    }
                    break;
                };

                case 16:
                {
                    if (me == 0)
                    {
                        line lc[32] = {

                            {true, true, 00, "                                                                  (Every single one of these are   Enoki's, aren't they?)"},
                            {true, true, 00, "                                                                  (Of course Aaron would pick up   around here.)"},
                            {true, true, 00, "                                                                  (They're so different... How on  earth are they not fighting-"},
                            {true, true, 00, "                                                                  -all the time? I don't get it.)"},
                            {true, true, 00, "                                                                  (If I had a boyfriend, I'd make  him pick up these clothes-"},
                            {true, true, 00, "                                                                  -immediately.)"},
                            {true, true, 00, "COM: Endscene"}};
                        dialogue_page_lite(lc);
                    }

                    if (me == 1)
                    {
                        line lc[32] = {

                            {true, true, 00, "                                                                  (If I knew Maple was coming so   soon I probably would'a cleaned"},
                            {true, true, 00, "                                                                  -these up a little sooner....)"},
                            {true, true, 00, "                                                                  (Maybe I can pick 'em up now and she won't notice.)"},
                            {true, true, 00, "                                                                  (Then again, maybe she already   saw it and is already judging.)"},
                            {true, true, 00, "                                                                  (..This one's cute enough, maybe I'll just leave it on the floor-"},
                            {true, true, 00, "                                                                  -and wear it tomorrow.)"},
                            {true, true, 00, "COM: Endscene"}};
                        dialogue_page_lite(lc);
                    }

                    if (me == 2)
                    {
                        line lc[32] = {

                            {true, true, 00, "                                                                  (Enoki wasn't this messy when we lived in the castle.)"},
                            {true, true, 00, "                                                                  (Maybe she thinks we're finally  moved in for good, so she-"},
                            {true, true, 00, "                                                                  -feels comfortable here.)"},
                            {true, true, 00, "                                                                  (I know it's probably too soon tocall, but Aaron Tremblay-"},
                            {true, true, 00, "                                                                  -you've done it. You've got your own place, and you've got yourself-"},
                            {true, true, 00, "                                                                  -a wife to leave her clothes on  the floor.)"},
                            {true, true, 00, "                                                                  (I can't think of anything else  I could want, now.)"},
                            {true, true, 00, "                                                                  (Well.....                       I miss my car.)"},
                            {true, true, 00, "                                                                  (Maybe I'll talk to Scout about  putting in a racetrack.)"},
                            {true, true, 00, "COM: Endscene"}};
                        dialogue_page_lite(lc);
                    }

                    if (me == 3)
                    {
                        line lc[32] = {
                            {true, true, 00, "                                                                  (Yeah, I definitely need to not  be here.)"},
                            {true, true, 00, "COM: Endscene"}};
                        dialogue_page_lite(lc);
                    }

                    break;
                };

                case 17:
                {

                    if (so->checkpoint < 7) {
                        if (me == 0)
                        {
                            line lc[32] = {

                                {true, true, 00, "                                                                  (At least when they were living  in that castle, their bed was in-"},
                                {true, true, 00, "                                                                  -the center of the room. What's  this supposed to be?)"},
                                {true, true, 00, "                                                                  (Who's shoved up awkwardly in thecorner? Aaron probably.)"},
                                {true, true, 00, "                                                                  (I swear, that girl is going to  give him grey hairs ten years    early.)"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                        }

                        if (me == 1)
                        {
                            line lc[32] = {

                                {true, true, 00, "                                                                  (I'm so glad I don't have'ta     sleep in the middle of the room.)"},
                                {true, true, 00, "                                                                  (Rolling over off the bed onto   that stone really really hurt.)"},
                                {true, true, 00, "                                                                  (Now I getta roll either into    the wall or into Aaron.)"},
                                {true, true, 00, "                                                                  (I'm so glad he doesn't seem to  mind that much.)"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                        }

                        if (me == 2)
                        {
                            line lc[32] = {

                                {true, true, 00, "                                                                  (Maple isn't gonna be happy when she sees this room.)"},
                                {true, true, 00, "                                                                  (I remember when she used to be  so easy-going...)"},
                                {true, true, 00, "                                                                  (She's just so frustrating to be around these days.)"},
                                {true, true, 00, "                                                                  (Maybe she shouldn't have come.  Every time I try to do something-"},
                                {true, true, 00, "                                                                  -to help her out, she just spits all over me and pouts.)"},
                                {true, true, 00, "                                                                  (Maybe she'll get tired of       living here and just go home.)"},
                                {true, true, 00, "                                                                  (Maybe she's right. Maybe I'm    just living Enoki's fantasy.)"},
                                {true, true, 00, "                                                                  (But Enoki's the first bit of    happiness I've had in years.)"},
                                {true, true, 00, "                                                                  (Maybe we'll both change...      I hope something changes.)"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                        }

                        if (me == 3)
                        {
                            line lc[32] = {

                                {true, true, 00, "                                                                  (I probably shouldn't be in here uninvited...)"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                        }
                    }

                    else {
                        if (me == 0)
                        {
                            line lc[32] = {

                                {true, true, 00, "                                                                  (There's no way I'm going to everadmit it, but...)"},
                                {true, true, 00, "                                                                  (It's nice staying with them. I  keep forgetting how much I)"},
                                {true, true, 00, "                                                                  (miss staying with somebody.)"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                        }

                        if (me == 1)
                        {
                            line lc[32] = {

                                {true, true, 00, "                                                                  (Y'know, I wish I could go back  in time and talk to little me.)"},
                                {true, true, 00, "                                                                  (She would NOT BELIEVE what this year's been like.)"},
                                {true, true, 00, "                                                                  (I.. don't think my parents know I'm here.)"},
                                {true, true, 00, "                                                                  (Where the heck do the think I amI wonder, huh.)"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                        }

                        if (me == 2)
                        {
                            line lc[32] = {

                                {true, true, 00, "                                                                  (I really, really need to get    Maple her own place.)"},
                                {true, true, 00, "                                                                  (I didn't figure she'd actually  pull her weight, but...)"},
                                {true, true, 00, "                                                                  (With all that spelunking, we've made enough to break even.)"},
                                {true, true, 00, "                                                                  (I'm surprised she hasn't really been asking for a new place.)"},
                                {true, true, 00, "                                                                  (Maybe she doesn't really like   staying by herself.)"},
                                {true, true, 00, "                                                                  (I really don't want to have to  make another house.)"},
                                {true, true, 00, "                                                                  (I'll talk to that Olivier guy   and see what he can do.)"},
                                {true, true, 00, "                                                                  (He seems handy enough.)"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                        }

                        if (me == 3)
                        {
                            line lc[32] = {
                                {true, true, 00, "                                                                  (Yep, that's a room.)"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                        }

                        if (me == 4) {
                            line lc[32] = {
                                {true, true, 00, "                                                                  (Definitely like all the sunlightin here.)"},
                                {true, true, 00, "                                                                  (Could use a plant or two.)"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                        }

                        if (me == 5) {
                            line lc[32] = {
                                {true, true, 00, "                                                                  (This reminds me so much of Vee'sparents' house.)"},
                                {true, true, 00, "                                                                  (I hope they're trustworthy      people.)"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                        }

                        if (me == 6) {
                            line lc[32] = {
                                {true, true, 00, "                                                                  (Ok, I like these people.)"},
                                {true, true, 00, "                                                                  (They make me feel organized.)"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                        }
                    }

                    break;
                };

                case 18:
                {

                    if (so->checkpoint < 7) {
                        if (me == 0)
                        {
                            line lc[32] = {

                                {true, true, 00, "                                                                  MAPLE                            So, uh, what's the book?"},
                                {true, true, 00, "                                                                  AARON                            Oh, that's mine."},
                                {true, true, 00, "                                                                  AARON                            You know I'm not a fiction guy,"},
                                {true, true, 00, "                                                                  AARON                            But Enoki is stubborn."},
                                {true, true, 00, "                                                                  ENOKI                            You ever heard'a Yellow?"},
                                {true, true, 00, "                                                                  ENOKI                            It's kinda fun, I got Aaron into it."},
                                {true, true, 00, "                                                                  MAPLE                            ...does this have pictures?"},
                                {true, true, 00, "                                                                  MAPLE                            Do you still read picture books?"},
                                {true, true, 00, "                                                                  ENOKI                            It's got cigarettes in it though!"},
                                {true, true, 00, "                                                                  ENOKI                            That means its for kids AND      adults."},
                                {true, true, 00, "                                                                  MAPLE                            Huh, they make books like that?"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                        }

                        if (me == 1)
                        {
                            line lc[32] = {

                                {true, true, 00, "                                                                  ENOKI                            Oh, oh Maple? You want juice?"},
                                {true, true, 00, "                                                                  MAPLE                            What kind of juice?"},
                                {true, true, 00, "                                                                  ENOKI                            It's a secret."},
                                {true, true, 00, "                                                                  MAPLE                            I'm not drinking mystery liquid."},
                                {true, true, 00, "                                                                  ENOKI                            ...."},
                                {true, true, 00, "                                                                  ENOKI                            Ok fine, it's orange juice."},
                                {true, true, 00, "                                                                  MAPLE                            You don't think I would have"},
                                {true, true, 00, "                                                                  MAPLE                            found that out?"},
                                {true, true, 00, "                                                                  ENOKI                            Maybe?"},
                                {true, true, 00, "                                                                  MAPLE                            No. Merci."},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                        }

                        if (me == 2)
                        {
                            line lc[32] = {

                                {true, true, 00, "                                                                  (We're kind of low on orange     juice.)"},
                                {true, true, 00, "                                                                  (I'll probably need to head to   town and sell some produce.)"},
                                {true, true, 00, "                                                                  (Selling one fruit to get        another fruit, heh.)"},
                                {true, true, 00, "                                                                  (If only cucumber juice tasted   a little better.)"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                        }

                        if (me == 3)
                        {
                            line lc[32] = {

                                {true, true, 00, "                                                                  ENOKI                            EEEE! All my friends know"},
                                {true, true, 00, "                                                                  ENOKI                            Each other now!!"},
                                {true, true, 00, "                                                                  ENOKI                            We're like a proper group."},
                                {true, true, 00, "                                                                  MAPLE                            Whoa, I haven't decided if-"},
                                {true, true, 00, "                                                                  MAPLE                            I'm staying, chill out."},
                                {true, true, 00, "                                                                  SCOUT                            Anyone else showing up?"},
                                {true, true, 00, "                                                                  AARON                            I guess we'll wait and see."},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                        }

                    }

                    else {
                    if (me < 3)
                        {
                            line lc[32] = {
                                {true, true, 00, "                                                                  MAPLE                            So, it looks like I've read 'em all."},
                                {true, true, 00, "                                                                  AARON                            We haven't gone to town in a while."},
                                {true, true, 00, "                                                                  MAPLE                            I wonder what's going on outside."},
                                {true, true, 00, "                                                                  ENOKI                            If anything was bad, you know"},
                                {true, true, 00, "                                                                  ENOKI                            Scout woulda' said something."},
                                {true, true, 00, "                                                                  ENOKI                            He's got that internet thing."},
                                {true, true, 00, "                                                                  MAPLE                            I wonder if I can get new books that way."},
                                {true, true, 00, "                                                                  AARON                            That would sure be nice."},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                        } else {
                            line lc[32] = {
                                {true, true, 00, "                                                                  You see a bunch of books you've  never seen before."},
                                {true, true, 00, "                                                                  None look particularly           interesting... for now."},
                                {true, true, 00, "COM: Endscene"}
                                };
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
                    bn::sound_items::door.play(); return dt;
                    break;
                };

                case 20:
                {
                    dt.spawn_x = 7;
                    dt.spawn_y = 3;
                    dt.world_index = 6;
                    bn::sound_items::door.play(); return dt;
                    break;
                };

                case 21:
                {
                    line lc[32] = {
                        {true, true, 00, "                                                                  ENOKI'S GARDEN                   You touch it, I kill you"},
                        {true, true, 00, "COM: Endscene"},
                    };
                    dialogue_page_lite(lc);
                    break;
                };

                case 22:
                {
                    line lc[32] = {
                        {true, true, 00, "                                                                  WOOD CHOPPING SPOT               Where wood is chopped"},
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
                            {true, true, 00, "                                                                  Hmmm... This seems like somethingfor Enoki."},
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
                        bn::sound_items::door.play(); return dt;
                    }
                    else
                    {
                        line lc[32] = {
                            {true, true, 00, "                                                                  Hmmm... This seems like somethingfor Aaron."},
                            {true, true, 00, "COM: Endscene"}};
                        dialogue_page_lite(lc);
                    }
                    break;
                };

                case 25:
                {
                    line lc[32] = {
                        {true, true, 00, "                                                                  CAVE OF DANGEROUS BATS           Warning: Contains Bats"},
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
                        bn::sound_items::door.play(); return dt;
                    }
                    else
                    {
                        line lc[32] = {
                            {true, true, 00, "                                                                  I think Maple is the only one whocan go in safely."},
                            {true, true, 00, "COM: Endscene"}};
                        dialogue_page_lite(lc);
                    }
                    break;
                };

                case 27:
                {
                    if (so->checkpoint < 7) {
                        if (me == 0)
                        {
                            line lc[32] = {
                                {true, true, 00, "                                                                  MAPLE                            Plants, huh?"},
                                {true, true, 00, "                                                                  MAPLE                            Isn't there a garden up top?"},
                                {true, true, 00, "                                                                  SCOUT                            You see, I, er-"},
                                {true, true, 00, "                                                                  SCOUT                            It's not really about the plants."},
                                {true, true, 00, "                                                                  SCOUT                            I'm a dirt scientist."},
                                {true, true, 00, "                                                                  MAPLE                            Dirt scientist?"},
                                {true, true, 00, "                                                                  SCOUT                            There's a scientist for, uh.."},
                                {true, true, 00, "                                                                  SCOUT                            Well, everything."},
                                {true, true, 00, "                                                                  MAPLE                            Clearly."},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }
                        else if (me == 1)
                        {
                            line lc[32] = {
                                {true, true, 00, "                                                                  ENOKI                            I think THAT plant is the one."},
                                {true, true, 00, "                                                                  ENOKI                            That's my favorite."},
                                {true, true, 00, "                                                                  SCOUT                            You want a cutting?"},
                                {true, true, 00, "                                                                  ENOKI                            What is it?"},
                                {true, true, 00, "                                                                  SCOUT                            I... I don't know, actually."},
                                {true, true, 00, "                                                                  SCOUT                            I study dirt, not plants."},
                                {true, true, 00, "                                                                  ENOKI                            Maybe it's a mystery fruit!"},
                                {true, true, 00, "                                                                  SCOUT                            I.. guess it could be."},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }
                        else if (me == 2)
                        {
                            line lc[32] = {
                                {true, true, 00, "                                                                  AARON                            Any progress?"},
                                {true, true, 00, "                                                                  SCOUT                            Heck yeah!"},
                                {true, true, 00, "                                                                  SCOUT                            I've got something new."},
                                {true, true, 00, "                                                                  AARON                            What's it called?"},
                                {true, true, 00, "                                                                  SCOUT                            I call it 'Scout-Out'."},
                                {true, true, 00, "                                                                  SCOUT                            Guaranteed to get rid of weeds."},
                                {true, true, 00, "                                                                  AARON                            Dude, that's amazing!"},
                                {true, true, 00, "                                                                  SCOUT                            Only issue is, well..."},
                                {true, true, 00, "                                                                  SCOUT                            It gets rid of the plants, too."},
                                {true, true, 00, "                                                                  AARON                            Ah, bummer."},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }
                        else if (me == 3)
                        {
                            line lc[32] = {
                                {true, true, 00, "                                                                  (Oh man, oh man oh man oh man..)"},
                                {true, true, 00, "                                                                  (I need to get this new formula  figured out fast.)"},
                                {true, true, 00, "                                                                  (Maybe promising the investors   magic dirt was a bad idea.)"},
                                {true, true, 00, "                                                                  (Maybe I can just hide down here and they won't find me.)"},
                                {true, true, 00, "                                                                  (Probably should take my name offmy hatch, first.)"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }
                    } else if (so->checkpoint < 10) {
                        if (me == 0)
                        {
                            line lc[32] = {
                                {true, true, 00, "                                                                  MAPLE                            Same thing going on here?"},
                                {true, true, 00, "                                                                  SCOUT                            Yeah, yeah."},
                                {true, true, 00, "                                                                  MAPLE                            They still haven't talk to you"},
                                {true, true, 00, "                                                                  MAPLE                            about your results?"},
                                {true, true, 00, "                                                                  SCOUT                            Nah.. But I'm still getting a"},
                                {true, true, 00, "                                                                  SCOUT                            paycheck every week."},
                                {true, true, 00, "                                                                  MAPLE                            Hey, that's good."},
                                {true, true, 00, "                                                                  SCOUT                            Oh yeah."},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }
                        else if (me == 3)
                        {
                            line lc[32] = {
                                {true, true, 00, "                                                                  (Maple's been looking at these   plants every once in while..)"},
                                {true, true, 00, "                                                                  (At least she's got an opinion onthem.)"},
                                {true, true, 00, "                                                                  (I really, really need my boss tomessage me back about them.)"},
                                {true, true, 00, "                                                                  (I guess I shouldn't rock the    tree, the paycheck is solid.)"},
                                {true, true, 00, "                                                                  (I just want to make sure I'm    doing everything right.)"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        } else {
                            line lc[32] = {
                                {true, true, 00, "                                                                  (Lots of unusual plants and dirt samples in jars.)"},
                                {true, true, 00, "                                                                  (You don't understand it... but  it's probably harmless.)"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }
                    }

                    break;
                };

                case 28:
                {
                    if (so->checkpoint < 7) {
                    if (me == 0)
                    {
                        line lc[32] = {
                            {true, true, 00, "                                                                  MAPLE                            Hey look, more nerd stuff."},
                            {true, true, 00, "                                                                  SCOUT                            Excusez-moi, mademoiselle!"},
                            {true, true, 00, "                                                                  SCOUT                            That's Time Raiders!"},
                            {true, true, 00, "                                                                  MAPLE                            Time... Raiders?"},
                            {true, true, 00, "                                                                  SCOUT                            Yeah! The adventures of"},
                            {true, true, 00, "                                                                  SCOUT                            Jahn-Jahn Gazebo and his"},
                            {true, true, 00, "                                                                  SCOUT                            sidekicks, Nexus and Ninjette!"},
                            {true, true, 00, "                                                                  MAPLE                            Everything about that sounds.."},
                            {true, true, 00, "                                                                  MAPLE                            You ever have a girlfriend?"},
                            {true, true, 00, "                                                                  SCOUT                            No, girls thought I was a nerd."},
                            {true, true, 00, "                                                                  MAPLE                            Girls still do, dude."},
                            {true, true, 00, "COM: Endscene"}};
                        dialogue_page_lite(lc);
                        break;
                    }
                    else if (me == 1)
                        {
                            line lc[32] = {
                                {true, true, 00, "                                                                  ENOKI                            Ooh, is this Time Raiders??"},
                                {true, true, 00, "                                                                  SCOUT                            You know Time Raiders??."},
                                {true, true, 00, "                                                                  ENOKI                            'I've got it, Jahn-Jahn!'"},
                                {true, true, 00, "                                                                  SCOUT                            Finally, someone else!"},
                                {true, true, 00, "                                                                  ENOKI                            Yeah, Aaron introduced me."},
                                {true, true, 00, "                                                                  ENOKI                            I like the artwork."},
                                {true, true, 00, "                                                                  ENOKI                            Can I borrow this after you?"},
                                {true, true, 00, "                                                                  SCOUT                            Sure thing! I'm almost done."},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }
                    else if (me == 2)
                    {
                        line lc[32] = {
                            {true, true, 00, "                                                                  AARON                            Yo, Time Raiders?"},
                            {true, true, 00, "                                                                  SCOUT                            Heck yeah!"},
                            {true, true, 00, "                                                                  AARON                            Nice! You check out the latest?"},
                            {true, true, 00, "                                                                  SCOUT                            Oh no, not yet."},
                            {true, true, 00, "                                                                  SCOUT                            Something you'll learn about, er-"},
                            {true, true, 00, "                                                                  SCOUT                            'Island Life',"},
                            {true, true, 00, "                                                                  SCOUT                            Getting new things is hard."},
                            {true, true, 00, "                                                                  SCOUT                            I could just use my computer, but"},
                            {true, true, 00, "                                                                  SCOUT                            That kills the experience."},
                            {true, true, 00, "                                                                  AARON                            Definitely, definitely."},
                            {true, true, 00, "COM: Endscene"}};
                        dialogue_page_lite(lc);
                        break;
                    }
                    else if (me == 3)
                    {
                        line lc[32] = {
                            {true, true, 00, "                                                                  (I've gotta finish this one so   I can get it to Enoki.)"},
                            {true, true, 00, "                                                                  (But that formula I promise...   I swear, I'm so close.)"},
                            {true, true, 00, "                                                                  (Maybe just a few more           all-nighters.)"},
                            {true, true, 00, "                                                                  (A few more and I'll finally haveit.)"},
                            {true, true, 00, "COM: Endscene"}};
                        dialogue_page_lite(lc);
                        break;
                    }
                    
                    } else if (so->checkpoint < 10) {

                        if (me == 0)
                        {
                            line lc[32] = {
                                {true, true, 00, "                                                                  SCOUT                            Hey, you know, you like to read"},
                                {true, true, 00, "                                                                  SCOUT                            a lot, right?"},
                                {true, true, 00, "                                                                  MAPLE                            Sure thing."},
                                {true, true, 00, "                                                                  SCOUT                            Do you think that maybe I could"},
                                {true, true, 00, "                                                                  SCOUT                            borrow some of your books?"},
                                {true, true, 00, "                                                                  MAPLE                            You wouldn't like them."},
                                {true, true, 00, "                                                                  SCOUT                            I'm sure I could try."},
                                {true, true, 00, "                                                                  MAPLE                            You like romance?"},
                                {true, true, 00, "                                                                  MAPLE                            Steamy romance?"},
                                {true, true, 00, "                                                                  SCOUT                            I... do you have anything else?"},
                                {true, true, 00, "                                                                  MAPLE                            No, that's what I like."},
                                {true, true, 00, "                                                                  MAPLE                            What, it make you uncomfortable?"},
                                {true, true, 00, "                                                                  SCOUT                            ..Maybe a bit."},
                                {true, true, 00, "                                                                  MAPLE                            Yeah, stick to your comic books."},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }
                        else if (me == 1)
                            {
                                line lc[32] = {
                                    {true, true, 00, "                                                                  SCOUT                            Hey, Enoki?"},
                                    {true, true, 00, "                                                                  ENOKI                            Yuh-huh?"},
                                    {true, true, 00, "                                                                  SCOUT                            Can we talk about Maple?"},
                                    {true, true, 00, "                                                                  ENOKI                            Oooh, what about her?"},
                                    {true, true, 00, "                                                                  ENOKI                            You LIKE her, don't you?"},
                                    {true, true, 00, "                                                                  SCOUT                            What's not to like?"},
                                    {true, true, 00, "                                                                  ENOKI                            We all already know, hehe."},
                                    {true, true, 00, "                                                                  SCOUT                            Aw crap, it's obvious."},
                                    {true, true, 00, "                                                                  ENOKI                            She's hard to get."},
                                    {true, true, 00, "                                                                  ENOKI                            I tried to set her up once."},
                                    {true, true, 00, "                                                                  SCOUT                            You did?"},
                                    {true, true, 00, "                                                                  ENOKI                            They even dated for a bit."},
                                    {true, true, 00, "                                                                  ENOKI                            He just got on her nerves."},
                                    {true, true, 00, "                                                                  ENOKI                            You gotta be perfect for her."},
                                    {true, true, 00, "                                                                  SCOUT                            And I'm not."},
                                    {true, true, 00, "                                                                  ENOKI                            I don't know what perfect is."},
                                    {true, true, 00, "                                                                  SCOUT                            Well, I can dream I guess."},
                                    {true, true, 00, "                                                                  ENOKI                            But hey, don't change yourself."},
                                    {true, true, 00, "                                                                  ENOKI                            Just be the best 'you'."},
                                    {true, true, 00, "                                                                  SCOUT                            I guess you're right."},
                                    {true, true, 00, "                                                                  ENOKI                            The right girl'll come in time."},
                                    {true, true, 00, "                                                                  SCOUT                            Right. Merci, Enoki."},
                                    {true, true, 00, "                                                                  ENOKI                            De rien!"},
                                    {true, true, 00, "COM: Endscene"}};
                                dialogue_page_lite(lc);
                                break;
                            }
                        else if (me == 2)
                        {
                            line lc[32] = {
                                {true, true, 00, "                                                                  SCOUT                            Hey, bro, so, how'd you, er.."},
                                {true, true, 00, "                                                                  SCOUT                            How'd you first ask Enoki out?"},
                                {true, true, 00, "                                                                  AARON                            I just invited her to coffee."},
                                {true, true, 00, "                                                                  SCOUT                            Coffee, coffee, right.."},
                                {true, true, 00, "                                                                  SCOUT                            We don't uh, hmm.. No coffee.."},
                                {true, true, 00, "                                                                  AARON                            You want to ask Maple out?"},
                                {true, true, 00, "                                                                  SCOUT                            Well, I.. Yeah, I do."},
                                {true, true, 00, "                                                                  AARON                            I'd tell you to give up, but at"},
                                {true, true, 00, "                                                                  AARON                            the same time, you never know."},
                                {true, true, 00, "                                                                  AARON                            No one's good enough for her."},
                                {true, true, 00, "                                                                  SCOUT                            I figured it wasn't worth it."},
                                {true, true, 00, "                                                                  AARON                            Absolutely no pleasing her."},
                                {true, true, 00, "                                                                  AARON                            Trust me, I know."},
                                {true, true, 00, "                                                                  SCOUT                            What do you mean?"},
                                {true, true, 00, "                                                                  AARON                            Her type is those losers who"},
                                {true, true, 00, "                                                                  AARON                            they're way cooler than they"},
                                {true, true, 00, "                                                                  AARON                            are. Now, I'll give her some"},
                                {true, true, 00, "                                                                  AARON                            credit, though. She puts up"},
                                {true, true, 00, "                                                                  AARON                            with a lot of the other kind"},
                                {true, true, 00, "                                                                  AARON                            of loser, too. Just..."},
                                {true, true, 00, "                                                                  AARON                            Work on yourself. Maybe try"},
                                {true, true, 00, "                                                                  AARON                            to be a bit more confident and"},
                                {true, true, 00, "                                                                  AARON                            socially-aware, right?"},
                                {true, true, 00, "                                                                  SCOUT                            Right. That's a good start."},
                                {true, true, 00, "                                                                  AARON                            Good luck, man."},
                                {true, true, 00, "                                                                  SCOUT                            Merci."},
                                {true, true, 00, " "}
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }
                        else if (me == 3)
                        {
                            line lc[32] = {
                                {true, true, 00, "                                                                  (Maybe if I can just get Maple toread a few copies,)"},
                                {true, true, 00, "                                                                  (We'll finally have something in common with her.)"},
                                {true, true, 00, "                                                                  (In my dreams.)"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }
                        else if (me == 7)
                        {
                            line lc[32] = {
                                {true, true, 00, "                                                                  GUY                              You like Time Raiders?"},
                                {true, true, 00, "                                                                  SCOUT                            Yeah, a bit."},
                                {true, true, 00, "                                                                  GUY                              How often you get new ones?"},
                                {true, true, 00, "                                                                  SCOUT                            Diana ships in new ones weekly."},
                                {true, true, 00, "                                                                  GUY                              Ah okay, I didn't wanna move"},
                                {true, true, 00, "                                                                  GUY                              here and have to give it up."},
                                {true, true, 00, "                                                                  SCOUT                            There is a bit of a waiting"},
                                {true, true, 00, "                                                                  SCOUT                            list, though. You gotta go"},
                                {true, true, 00, "                                                                  SCOUT                            after Enoki, she likes em."},
                                {true, true, 00, "                                                                  GUY                              Nah, I'll just take em first."},
                                {true, true, 00, "                                                                  SCOUT                            Look, you take that up with her."},
                                {true, true, 00, "                                                                  GUY                              Will do."},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }
                        else
                        {
                            line lc[32] = {
                                {true, true, 00, "                                                                  (Last month's comic books remain lying on the floor.)"},
                                {true, true, 00, "                                                                  (Slowly collecting dust.)"}
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }
                    }
                    break;
                };

                case 29:
                {
                    if (so->checkpoint < 7) {
                        if (me == 0)
                        {
                            line lc[32] = {
                                {true, true, 00, "                                                                  SCOUT                            Hey, please be careful about-"},
                                {true, true, 00, "                                                                  SCOUT                            my computer, it's expensive."},
                                {true, true, 00, "                                                                  MAPLE                            I'm not gonna touch it."},
                                {true, true, 00, "                                                                  MAPLE                            Although, now I want to.."},
                                {true, true, 00, "                                                                  SCOUT                            Wait!! Please-"},
                                {true, true, 00, "                                                                  MAPLE                            Dude, I'm not gonna touch it!"},
                                {true, true, 00, "                                                                  MAPLE                            You nerds and your toys.."},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }
                        else if (me == 1)
                            {
                                line lc[32] = {
                                    {true, true, 00, "                                                                  ENOKI                            Hey Scout, you got a website?"},
                                    {true, true, 00, "                                                                  SCOUT                            Yeah! It's not very good though."},
                                    {true, true, 00, "                                                                  ENOKI                            May I see it?"},
                                    {true, true, 00, "                                                                  SCOUT                            Not right now, it's... not done."},
                                    {true, true, 00, "                                                                  ENOKI                            Ah, okay."},
                                    {true, true, 00, "                                                                  ENOKI                            I wanna make a website."},
                                    {true, true, 00, "                                                                  ENOKI                            It looks like a lot of fun."},
                                    {true, true, 00, "                                                                  SCOUT                            It's definitely fun."},
                                    {true, true, 00, "COM: Endscene"}};
                                dialogue_page_lite(lc);
                                break;
                            }
                        else if (me == 2)
                        {
                            line lc[32] = {
                                {true, true, 00, "                                                                  AARON                            You hear about the millenium bug?"},
                                {true, true, 00, "                                                                  SCOUT                            Well of course."},
                                {true, true, 00, "                                                                  AARON                            Were you okay?"},
                                {true, true, 00, "                                                                  SCOUT                            Yeah, I was fine."},
                                {true, true, 00, "                                                                  SCOUT                            There was a weird bug in"},
                                {true, true, 00, "                                                                  SCOUT                            one program."},
                                {true, true, 00, "                                                                  SCOUT                            I had a shopping list program,"},
                                {true, true, 00, "                                                                  SCOUT                            It added tons of shoeshine to my"},
                                {true, true, 00, "                                                                  SCOUT                            my shopping list, which is now"},
                                {true, true, 00, "                                                                  SCOUT                            due on March 5th, 192000."},
                                {true, true, 00, "                                                                  AARON                            That's a little while to wait."},
                                {true, true, 00, "                                                                  SCOUT                            A glitchy date? I understand."},
                                {true, true, 00, "                                                                  SCOUT                            Extra items? That elludes me."},
                                {true, true, 00, "                                                                  SCOUT                            Bugs are just the weirdest thing."},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }
                        else if (me == 3)
                        {
                            line lc[32] = {
                                {true, true, 00, "                                                                  (I've graduated top of my class  with a 3.99 GPA.)"},
                                {true, true, 00, "                                                                  (I'm a real scientist, living    off a corproate grant.)"},
                                {true, true, 00, "                                                                  (I have a state of the art, whiz bang Castor 5000 computer.)"},
                                {true, true, 00, "                                                                  (And I can't use it, because I   forgot my password.)"},
                                {true, true, 00, "                                                                  (No wonder I can't sleep at      night.)"},
                                {true, true, 00, "COM: Endscene"}
                            };
                            dialogue_page_lite(lc);
                        }
                    } else {
                        if (me == 3)
                        {
                            dt.spawn_x = 4;
                            dt.spawn_y = 0;
                            dt.world_index = 99;
                            return dt;
                        } else {
                            line lc[32] = {
                                {true, true, 00, "                                                                  (This looks really expensive...)"},
                                {true, true, 00, "                                                                  (I probably shouldn't touch.)"},
                                {true, true, 00, "COM: Endscene"}
                            };
                        }
                    }
                    break;
                };

                case 30:
                {
                    if (so->checkpoint < 7) {
                        if (me == 0)
                        {
                            line lc[32] = {
                                {true, true, 0, "                                                                  MAPLE                            Oh! Bonjour, who are you?"},
                                {true, true, 0, "                                                                  SCOUT                            You must be Maple Tremblay?"},
                                {true, true, 0, "                                                                  SCOUT                            I'm Scout Williams."},
                                {true, true, 0, "                                                                  MAPLE                            Do you, uh, have this whole"},
                                {true, true, 0, "                                                                  MAPLE                            underground thing to yourself?"},
                                {true, true, 0, "                                                                  SCOUT                            Yeah, I, er- It's sort of top"},
                                {true, true, 0, "                                                                  SCOUT                            secret, but you're not the kind"},
                                {true, true, 0, "                                                                  SCOUT                            to share secrets, are you?"},
                                {true, true, 0, "                                                                  MAPLE                            I-"},
                                {true, true, 0, "                                                                  SCOUT                            So this company hired me to study"},
                                {true, true, 0, "                                                                  SCOUT                            soil and stuff on this island,"},
                                {true, true, 0, "                                                                  SCOUT                            and then they.. forgot about me."},
                                {true, true, 0, "                                                                  SCOUT                            They still send a paycheck though"},
                                {true, true, 0, "                                                                  SCOUT                            so I don't see a reason to leave."},
                                {true, true, 0, "                                                                  MAPLE                            Paid to do absolutely nothing?"},
                                {true, true, 0, "                                                                  SCOUT                            It gets so lonely up here though."},
                                {true, true, 0, "                                                                  SCOUT                            I'm glad your family showed up."},
                                {true, true, 0, "                                                                  SCOUT                            They were talkin' all this about"},
                                {true, true, 0, "                                                                  SCOUT                            a 'new country' or whatever, but"},
                                {true, true, 0, "                                                                  SCOUT                            they said I could be a Lord or a"},
                                {true, true, 0, "                                                                  SCOUT                            Duke or something."},
                                {true, true, 0, "                                                                  SCOUT                            I said as long as I got to be"},
                                {true, true, 0, "                                                                  SCOUT                            court magician, I wouldn't ask"},
                                {true, true, 0, "                                                                  SCOUT                            for anything else."},
                                {true, true, 0, "                                                                  MAPLE                            Yeah, you seem like the type."},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }
                        if (me == 1)
                        {
                                line lc[32] = {
                                    {true, true, 0, "                                                                  SCOUT                            Oh, hey Enoki! How's it going?"},
                                    {true, true, 0, "                                                                  ENOKI                            Really good!! It's perfect"},
                                    {true, true, 0, "                                                                  ENOKI                            outside today. Whatcha' workin'"},
                                    {true, true, 0, "                                                                  ENOKI                            on?"},
                                    {true, true, 0, "                                                                  SCOUT                            Right now? I've got this idea for"},
                                    {true, true, 0, "                                                                  SCOUT                            this robot that's half-bat,"},
                                    {true, true, 0, "                                                                  SCOUT                            half-fly swatter."},
                                    {true, true, 0, "                                                                  SCOUT                            Bats like insects, right? So this"},
                                    {true, true, 0, "                                                                  SCOUT                            is going to both eat and squash"},
                                    {true, true, 0, "                                                                  SCOUT                            insects."},
                                    {true, true, 0, "                                                                  ENOKI                            Are you calling it Smackula?"},
                                    {true, true, 0, "                                                                  SCOUT                            I.. most certainly can."},
                                    {true, true, 0, "                                                                  ENOKI                            By royal degree, I declare it"},
                                    {true, true, 0, "                                                                  ENOKI                            hereby be referred to as the"},
                                    {true, true, 0, "                                                                  ENOKI                            'Smackula'."},
                                    {true, true, 0, "                                                                  ENOKI                            Or maybe the 'Smackchula', that"},
                                    {true, true, 0, "                                                                  ENOKI                            way something finally rhymes"},
                                    {true, true, 0, "                                                                  ENOKI                            with Spatula."},
                                    {true, true, 0, "                                                                  SCOUT                            We're solving the world's true"},
                                    {true, true, 0, "                                                                  SCOUT                            issues here."},
                                    {true, true, 0, "                                                                  ENOKI                            Mm-hmm!"},
                                    {true, true, 00, "COM: Endscene"}};
                                dialogue_page_lite(lc);
                                break;
                            }
                        if (me == 2)
                        {
                            line lc[32] = {
                                {true, true, 0, "                                                                  SCOUT                            Oh, hey Aaron! How've you been?"},
                                {true, true, 0, "                                                                  AARON                            Good, I'm just really tired. I"},
                                {true, true, 0, "                                                                  AARON                            think I underestimated how much"},
                                {true, true, 0, "                                                                  AARON                            wood I'd be chopping."},
                                {true, true, 0, "                                                                  AARON                            I'm making boards, too. I plan on"},
                                {true, true, 0, "                                                                  AARON                            having some houses up and about a"},
                                {true, true, 0, "                                                                  AARON                            quarter of the woods levelled."},
                                {true, true, 0, "                                                                  SCOUT                            How many people are coming here,"},
                                {true, true, 0, "                                                                  SCOUT                            do you think?"},
                                {true, true, 0, "                                                                  AARON                            I don't know.. maybe eight? Nine?"},
                                {true, true, 0, "                                                                  AARON                            Do you know anyone who' want to"},
                                {true, true, 0, "                                                                  AARON                            live here, too?"},
                                {true, true, 0, "                                                                  SCOUT                            No, not really."},
                                {true, true, 0, "                                                                  AARON                            You still talking to that girl?"},
                                {true, true, 0, "                                                                  SCOUT                            Nah, I lied about her."},
                                {true, true, 0, "                                                                  SCOUT                            I'll be real with you, I don't"},
                                {true, true, 0, "                                                                  SCOUT                            really have friends outside of"},
                                {true, true, 0, "                                                                  SCOUT                            y'all."},
                                {true, true, 0, "                                                                  SCOUT                            But it's cool. I've got cable."},
                                {true, true, 0, "                                                                  AARON                            I'm gonna build those houses, and"},
                                {true, true, 0, "                                                                  AARON                            we'll get some more people here."},
                                {true, true, 0, "                                                                  SCOUT                            So, What are you gonna do when"},
                                {true, true, 0, "                                                                  SCOUT                            those people come?"},
                                {true, true, 0, "                                                                  AARON                            I... don't know to be honest."},
                                {true, true, 0, "                                                                  AARON                            Probably chop more wood."},
                                {true, true, 0, "                                                                  SCOUT                            Take it easy, alright?"},
                                {true, true, 0, "                                                                  AARON                            Got it. You too."},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }
                        if (me == 3)
                        {
                            line lc[32] = {
                                {true, true, 00, "                                                                  (This green formula's been makingall the plants grow real big.)"},
                                {true, true, 00, "                                                                  (I wonder what would happen if   I had some...)"},
                                {true, true, 00, "                                                                  (Maybe I'll get super plant      powers...)"},
                                {true, true, 00, "                                                                  (Or maybe I'll just die.)"},
                                {true, true, 00, "                                                                  (Those plant powers better be    worth the risk.)"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }
                        break;
                    } else if (so->checkpoint < 10) {
                        if (me < 3) {
                            line lc[32] = {
                                {true, true, 00, "                                                                  SCOUT                            Careful!!"},
                                {true, true, 00, "                                                                  SCOUT                            Some of this stuff is"},
                                {true, true, 00, "                                                                  SCOUT                            SUPER SUPER toxic!"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        } else if (me == 4) {
                            line lc[32] = {
                                {true, true, 00, "                                                                  SCOUT                            Bonjour! Are you Olivier?"},
                                {true, true, 00, "                                                                  OLIVIER                          Oui! And you're Scout?"},
                                {true, true, 00, "                                                                  SCOUT                            That I am! Welcome!"},
                                {true, true, 00, "                                                                  OLIVIER                          This whole place was amazing!"},
                                {true, true, 00, "                                                                  SCOUT                            I tried to be honest in the ad."},
                                {true, true, 00, "                                                                  OLIVIER                          So, are you a scientist?"},
                                {true, true, 00, "                                                                  SCOUT                            You could say that, yeah."},
                                {true, true, 00, "                                                                  SCOUT                            I do a little of everything."},
                                {true, true, 00, "                                                                  OLIVIER                          And you live underground?"},
                                {true, true, 00, "                                                                  SCOUT                            I've got this machine that can"},
                                {true, true, 00, "                                                                  SCOUT                            Drill bunkers really easy."},
                                {true, true, 00, "                                                                  SCOUT                            I could keep drilling if I"},
                                {true, true, 00, "                                                                  SCOUT                            really wanted to, you know."},
                                {true, true, 00, "                                                                  OLIVIER                          Awesome!! Hey, you coming to"},
                                {true, true, 00, "                                                                  OLIVIER                          the Tremblay's for dinner?"},
                                {true, true, 00, "                                                                  SCOUT                            Of course!"},
                                {true, true, 00, "                                                                  OLIVIER                          Alright, I'll see you then!"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        } else if (me == 5) {
                            line lc[32] = {
                                {true, true, 00, "                                                                  ELEANOR                          Bonjour, monsieur!"},
                                {true, true, 00, "                                                                  SCOUT                            Bonjour! Are you Eleanor?"},
                                {true, true, 00, "                                                                  ELEANOR                          Oui! It's nice to meet you."},
                                {true, true, 00, "                                                                  ELEANOR                          This whole place was amazing!"},
                                {true, true, 00, "                                                                  SCOUT                            I tried to be honest in the ad."},
                                {true, true, 00, "                                                                  ELEANOR                          Are you a wizard?"},
                                {true, true, 00, "                                                                  SCOUT                            You could say that, yeah."},
                                {true, true, 00, "                                                                  SCOUT                            I do a little of everything."},
                                {true, true, 00, "                                                                  ELEANOR                          And you live underground?"},
                                {true, true, 00, "                                                                  SCOUT                            I've got this machine that can"},
                                {true, true, 00, "                                                                  SCOUT                            Drill bunkers really easy."},
                                {true, true, 00, "                                                                  SCOUT                            I could keep drilling if I"},
                                {true, true, 00, "                                                                  SCOUT                            really wanted to, you know."},
                                {true, true, 00, "                                                                  ELEANOR                          That's so fascinating!"},
                                {true, true, 00, "                                                                  SCOUT                            Aw, merci!"},
                                {true, true, 00, "                                                                  ELEANOR                          Tonight, will I see you at dinner?"},
                                {true, true, 00, "                                                                  SCOUT                            Of course!"},
                                {true, true, 00, "                                                                  ELEANOR                          Wonderful!"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        } else if (me == 6) {
                            line lc[32] = {
                                {true, true, 00, "                                                                  DIANA                            Bonjour! Hey, are you Scout?"},
                                {true, true, 00, "                                                                  SCOUT                            Bonjour! Are you Diana?"},
                                {true, true, 00, "                                                                  DIANA                            Oui! Nice to finally meet 'ya!"},
                                {true, true, 00, "                                                                  DIANA                            Man, this place is SICK!"},
                                {true, true, 00, "                                                                  SCOUT                            I tried to be honest in the ad."},
                                {true, true, 00, "                                                                  DIANA                            Are you a scientist or something?"},
                                {true, true, 00, "                                                                  SCOUT                            You could say that, yeah."},
                                {true, true, 00, "                                                                  SCOUT                            I do a little of everything."},
                                {true, true, 00, "                                                                  DIANA                            And you live underground?"},
                                {true, true, 00, "                                                                  SCOUT                            I've got this machine that can"},
                                {true, true, 00, "                                                                  SCOUT                            Drill bunkers really easy."},
                                {true, true, 00, "                                                                  SCOUT                            I could keep drilling if I"},
                                {true, true, 00, "                                                                  SCOUT                            really wanted to, you know."},
                                {true, true, 00, "                                                                  DIANA                            Aw, that's so cool!"},
                                {true, true, 00, "                                                                  SCOUT                            Merci!"},
                                {true, true, 00, "                                                                  DIANA                            You coming to dinner?"},
                                {true, true, 00, "                                                                  SCOUT                            Of course!"},
                                {true, true, 00, "                                                                  DIANA                            Sweet!"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        } else {
                            line lc[32] = {
                                {true, true, 00, "                                                                  (I wish I could make something   that would make me happy.)"},
                                {true, true, 00, "                                                                  (All that school and everything, but here I am, and...)"},
                                {true, true, 00, "                                                                  (I dunno. I move on from one     thing to the next thing,)"},
                                {true, true, 00, "                                                                  (I can't go anywhere without     immediately wanting to jump.)"},
                                {true, true, 00, "                                                                  (I just wanna be happy where I amfor once.)"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }
                    }
                    } else if (so->checkpoint < 12) {
                        if (me < 7) {
                            line lc[32] = {
                                {true, true, 00, "                                                                  SCOUT                            Careful!!"},
                                {true, true, 00, "                                                                  SCOUT                            Some of this stuff is"},
                                {true, true, 00, "                                                                  SCOUT                            SUPER SUPER toxic!"},
                                {true, true, 00, "                                                                  SCOUT                            Oh, well you already knew that."},
                                {true, true, 00, "                                                                  SCOUT                            At least I hope so."},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        } else {
                            line lc[32] = {
                                {true, true, 00, "                                                                  SCOUT                            Bonjour! You're Guy, right?"},
                                {true, true, 00, "                                                                  GUY                              Oui. So you're Scout?"},
                                {true, true, 00, "                                                                  SCOUT                            Bienvenu! You like your cabin?"},
                                {true, true, 00, "                                                                  GUY                              You weren't kidding about the"},
                                {true, true, 00, "                                                                  GUY                              kitchen, huh?"},
                                {true, true, 00, "                                                                  SCOUT                            Not a bit!"},
                                {true, true, 00, "                                                                  GUY                              There don't seem to be too many"},
                                {true, true, 00, "                                                                  GUY                              people here, and you know that"},
                                {true, true, 00, "                                                                  GUY                              I ain't gonna be making a ton of"},
                                {true, true, 00, "                                                                  GUY                              food without customers."},
                                {true, true, 00, "                                                                  GUY                              How soon it is gonna be before we"},
                                {true, true, 00, "                                                                  GUY                              get a ton of new people here?"},
                                {true, true, 00, "                                                                  SCOUT                            Oh, it shouldn't be too long."},
                                {true, true, 00, "                                                                  GUY                              And I can hold you to that?"},
                                {true, true, 00, "                                                                  SCOUT                            Sans doute."},
                                {true, true, 00, "                                                                  GUY                              Tres bien alors."},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }
                    
                    } else {

                    }
                };

                case 31: {
                    dt.spawn_x = 18;
                    dt.spawn_y = 1;
                    dt.world_index = 1;
                    bn::sound_items::door.play(); return dt;
                };

                case 32: {
                    dt.spawn_x = 8;
                    dt.spawn_y = 4;
                    dt.world_index = 0;
                    bn::sound_items::door.play(); return dt;
                };

                case 33: {
                    dt.spawn_x = 1;
                    dt.spawn_y = 4;
                    dt.world_index = 0;
                    bn::sound_items::door.play(); return dt;
                };

                case 34: {
                    dt.spawn_x = 2;
                    dt.spawn_y = 1;
                    dt.world_index = 1;
                    bn::sound_items::door.play(); return dt;
                };

                case 35: {
                    dt.spawn_x = 3;
                    dt.spawn_y = 6;
                    dt.world_index = 2;
                    bn::sound_items::door.play(); return dt;
                };

                case 36: {
                    dt.spawn_x = 9;
                    dt.spawn_y = 6;
                    dt.world_index = 2;
                    bn::sound_items::door.play(); return dt;
                };

                case 37: {
                    dt.spawn_x = 22;
                    dt.spawn_y = 1;
                    dt.world_index = 3;
                    bn::sound_items::door.play(); return dt;
                };

                case 38: {
                    dt.spawn_x = 2;
                    dt.spawn_y = 11;
                    dt.world_index = 1;
                    bn::sound_items::door.play(); return dt;
                };

                // 39

                case 40:
                {
                    line lc[5] = {
                        {true, true, 00, "                                                                  You stare at the art."},
                        {true, true, 00, "                                                                  And as such...."},
                        {true, true, 00, "                                                                  So the art stares unto you."},
                        {true, true, 00, "                                                                  Art is weird."},
                        {true, true, 00, "COM: Endscene"}};
                    dialogue_page_lite(lc);
                    break;
                };

                case 41: {
                    line lc[5] = {
                        {true, true, 00, "                                                                  - MORE HOUSES THIS WAY -"},
                        {true, true, 00, "COM: Endscene"}};
                    dialogue_page_lite(lc);
                    break;
                };

                case 42: {
                    dt.spawn_x = 18;
                    dt.spawn_y = 1;
                    dt.world_index = 8;
                    return dt;
                };

                case 43: {
                    dt.spawn_x = 1;
                    dt.spawn_y = 1;
                    dt.world_index = 4;
                    return dt;
                };

                case 44: {
                    line lc[5] = {
                        {true, true, 00, "                                                                   - WISHING POND -                DOESN'T WORK BUT FEEL FREE TO USEIT IF YOU'RE DESPERATE"},
                        {true, true, 00, "                                                                  The rocks in the way don't even  let you get a great view."},
                        {true, true, 00, "                                                                  Maybe if you could see over the  rocks, you could throw a coin in to make a wish."},
                        {true, true, 00, "                                                                  This wasn't thought through very well."},
                        {true, true, 00, "COM: Endscene"}};
                    dialogue_page_lite(lc);
                    break;
                };

                case 45: {
                    line lc[5] = {
                        {true, true, 00, "                                                                   - LE MAISON DE LANDRY -"},
                        {true, true, 00, "COM: Endscene"}};
                    dialogue_page_lite(lc);
                    break;
                };

                case 46: {
                    line lc[5] = {
                        {true, true, 00, "                                                                   - DIANA -"},
                        {true, true, 00, "                                                                  Either refers to the house or    the person."},
                        {true, true, 00, "COM: Endscene"}};
                    dialogue_page_lite(lc);
                    break;
                };

                case 47: {
                    line lc[5] = {
                        {true, true, 00, "                                                                   - SOME RANDOM GUY'S HOUSE -"},
                        {true, true, 00, "                                                                  No one has moved in yet, you see."},
                        {true, true, 00, "COM: Endscene"}};
                    dialogue_page_lite(lc);
                    break;
                };

                case 48: {
                    dt.spawn_x = 3;
                    dt.spawn_y = 5;
                    dt.world_index = 9;
                    return dt;
                };

                case 49: {
                    dt.spawn_x = 6;
                    dt.spawn_y = 7;
                    dt.world_index = 8;
                    return dt;
                };

                case 50: {
                    dt.spawn_x = 3;
                    dt.spawn_y = 5;
                    dt.world_index = 10;
                    return dt;
                };

                case 51: {
                    dt.spawn_x = 6;
                    dt.spawn_y = 17;
                    dt.world_index = 8;
                    return dt;
                };

                case 52: {
                    dt.spawn_x = 15;
                    dt.spawn_y = 22;
                    dt.world_index = 11;
                    return dt;
                };

                case 53: {
                    dt.spawn_x = 10;
                    dt.spawn_y = 1;
                    dt.world_index = 8;
                    return dt;
                    break;
                };

                case 54: {
                    line lc[32] = {
                        {true, true, 00, "                                                                  ~ JARGINS NOIRS ~"},
                        {true, true, 00, "COM: Endscene"}};
                    dialogue_page_lite(lc);
                    break;
                }

                case 55: {
                    switch (me) {
                        default: {
                            break;
                        }

                        case 0: {
                            line lc[32] = {
                                {true, true, 00, "                                                                  MAPLE                            Oh, hey. So you're Eleanor?"},
                                {true, true, 00, "                                                                  ELEANOR                          Oui! Enchanté de faire votre     connaissance."},
                                {true, true, 00, "                                                                  MAPLE                            Également. You seem...           No offense,"},
                                {true, true, 00, "                                                                  MAPLE                            A little old-fashioned?"},
                                {true, true, 00, "                                                                  ELEANOR                          Oh, it's just what we're used to."},
                                {true, true, 00, "                                                                  ELEANOR                          It's so nice to be so far away"},
                                {true, true, 00, "                                                                  ELEANOR                          from the city again. I had       forgotten how"},
                                {true, true, 00, "                                                                  ELEANOR                          sentimental I was for the trees."},
                                {true, true, 00, "                                                                  MAPLE                            I see. And you're her husband,   j'suppose?"},
                                {true, true, 00, "                                                                  OLIVIER                          Oui, I'm Olivier."},
                                {true, true, 00, "                                                                  ELEANOR                          He doesn't always talk much, but he makes it count."},
                                {true, true, 00, "                                                                  ELEANOR                          I met him in a garden, and he    taught me how to read."},
                                {true, true, 00, "                                                                  OLIVIER                          She's more special, though. She  just about saved my life."},
                                {true, true, 00, "                                                                  MAPLE                            Oh, how so?"},
                                {true, true, 00, "                                                                  OLIVIER                          It's not important-"},
                                {true, true, 00, "                                                                  ELEANOR                          From my mother."},
                                {true, true, 00, "                                                                  MAPLE                            Ah, I know how that is, haha."},
                                {true, true, 00, "                                                                  ELEANOR                          You do? She was going to drain   all his blood for a ritual."},
                                {true, true, 00, "                                                                  MAPLE                            I... Hmm, well, alright then.    That's.. not what I expected."},
                                {true, true, 00, "                                                                  MAPLE                            Nice to meet y'all, I guess?"},
                                {true, true, 00, "                                                                  ELEANOR                          Bien sûr! I'm baking your family a pie right now as our 'merci'."},
                                {true, true, 00, "                                                                  MAPLE                            C'est bon, just no, uh, weird    ingredients, haha."},
                                {true, true, 00, "                                                                  MAPLE                            (What was Scout thinking invitingthese weirdos??)"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }

                        case 1: {
                            line lc[32] = {
                            {true, true, 00, "                                                                  ENOKI                            Bienvenue, y'all!! Je suis Enoki!Ravie de vous-autres rencontrer!"},
                            {true, true, 00, "                                                                  ELEANOR                          Bonjour! Enchanté de faire votre connaissance."},
                            {true, true, 00, "                                                                  OLIVIER                          Bonjour!"},
                            {true, true, 00, "                                                                  ELEANOR                          I'm Eleanor, and this is my      husband Olivier."},
                            {true, true, 00, "                                                                  ENOKI                            I love your dress!! Where did youget it from?"},
                            {true, true, 00, "                                                                  ELEANOR                          Oh! I made it myself. I love yourdress, too!"},
                            {true, true, 00, "                                                                  ENOKI                            That's soo cool!!"},
                            {true, true, 00, "                                                                  ENOKI                            We look like we're about the samesize, maybe we can trade someday!"},
                            {true, true, 00, "                                                                  OLIVIER                          So, Scout said that you and your husband are royalty?"},
                            {true, true, 00, "                                                                  ENOKI                            Oh yes! This is our little       kingdom, but we're not cruel."},
                            {true, true, 00, "                                                                  ENOKI                            I'm like the chillest queen      you'll ever meet."},
                            {true, true, 00, "                                                                  ENOKI                            You guys wanna be a duke and     duchess?"},
                            {true, true, 00, "                                                                  ELEANOR                          I.. no thank you, I don't think  I know what those are."},
                            {true, true, 00, "                                                                  OLIVIER                          Merci, en tout cas."},
                            {true, true, 00, "                                                                  ENOKI                            Bien sûr! N'importe quand!"},
                            {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }

                        case 2: {
                            line lc[32] = {
                            {true, true, 00, "                                                                  AARON                            Bienvenu! Olivier and Eleanor,   I presume?"},
                            {true, true, 00, "                                                                  ELEANOR                          Oui oui!"},
                            {true, true, 00, "                                                                  OLIVIER                          So, I take it that you're 'king' of this island?"},
                            {true, true, 00, "                                                                  AARON                            Is that what Scout told you?     I suppose you could say that."},
                            {true, true, 00, "                                                                  AARON                            I never graduated high school,   so I'm not cut out for anything"},
                            {true, true, 00, "                                                                  AARON                            but work like this, but I didn't want to spend my life in a"},
                            {true, true, 00, "                                                                  AARON                            factory. So, my wife Enoki and I had the idea to spend our savings"},
                            {true, true, 00, "                                                                  AARON                            on some land and live off the    grid. The 'royalty' thing was"},
                            {true, true, 00, "                                                                  AARON                            her idea, and she was very cute  about it, so I had to say yes."},
                            {true, true, 00, "                                                                  AARON                            She's probably offered           aristocratic roles to y'all."},
                            {true, true, 00, "                                                                  OLIVIER                          Oh - Aaron, was it? Thank you forclearing out the area for the"},
                            {true, true, 00, "                                                                  OLIVIER                          greenhouse. I'll be able to grow all sorts of things to share."},
                            {true, true, 00, "                                                                  ELEANOR                          And I adore this cabin! In a goodway, it reminds me of home."},
                            {true, true, 00, "                                                                  ELEANOR                          Vee and I were so excited to hearabout this island."},
                            {true, true, 00, "                                                                  AARON                            Well, we're all very happy to    have you as well!"},
                            {true, true, 00, "                                                                  AARON                            If my little sister gives either of you a hard time,"},
                            {true, true, 00, "                                                                  AARON                            She doesn't mean anything by it, I promise."},
                            {true, true, 00, "                                                                  AARON                            Hop on by to trailer tonight,    we'll have some dinner ready."},
                            {true, true, 00, "                                                                  OLIVIER                          Encore une fois, je vous remerciesincerement."},
                            {true, true, 00, "                                                                  AARON                            We're family, now - please, 'tu' is plenty."},
                            {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }

                        case 3: {
                            line lc[32] = {
                            {true, true, 00, "                                                                  SCOUT                            Hey, y'all! I'm Scout, from      online?"},
                            {true, true, 00, "                                                                  OLIVIER                          Ah! Enchanté de faire votre      connaissance."},
                            {true, true, 00, "                                                                  ELEANOR                          Oh... But from your picture, I   thought that you..."},
                            {true, true, 00, "                                                                  SCOUT                            You thought that I what?"},
                            {true, true, 00, "                                                                  ELEANOR                          I thought you were a skeleton."},
                            {true, true, 00, "                                                                  SCOUT                            Oh- Well, that's just 'cuz I use the photo of a character I like."},
                            {true, true, 00, "                                                                  SCOUT                            There's this skeleton from a     comic named Seemore."},
                            {true, true, 00, "                                                                  SCOUT                            He's got magic powers and a- wellmaybe I should just let you"},
                            {true, true, 00, "                                                                  SCOUT                            read the comic, it's a ton of    fun."},
                            {true, true, 00, "                                                                  ELEANOR                          What's a comic?"},
                            {true, true, 00, "                                                                  SCOUT                            I... huh, I've never had to      answer that question before."},
                            {true, true, 00, "                                                                  SCOUT                            They're like books, but they've  got pictures, but-"},
                            {true, true, 00, "                                                                  ELEANOR                          Those sound so cool!"},
                            {true, true, 00, "                                                                  OLIVIER                          Eleanor was raised in a cult, so she doesn't know much about"},
                            {true, true, 00, "                                                                  OLIVIER                          the outside world. That's one of the reasons we wanted to move"},
                            {true, true, 00, "                                                                  OLIVIER                          here, so we could have a little  break from her extended family."},
                            {true, true, 00, "                                                                  SCOUT                            Oh.. Well, crap. Welcome to the  island, I guess."},
                            {true, true, 00, "                                                                  SCOUT                            Queen Enoki's got dibs on my     latest Time Raiders,"},
                            {true, true, 00, "                                                                  SCOUT                            But when she's done, I'll        definitely get you the copy."},
                            {true, true, 00, "                                                                  ELEANOR                          Merci!!"},
                            {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }

                        // Fall-through to the next bit
                        case 4: {
                        }

                        case 5: {
                            line lc[32] = {
                            {true, true, 00, "                                                                  OLIVIER                          Eleanor, why'd you turn the stoveon? Aren't we eating with"},
                            {true, true, 00, "                                                                  OLIVIER                          the Tremblays tonight?"},
                            {true, true, 00, "                                                                  ELEANOR                          Oh, yes yes, I just couldn't helpmyself."},
                            {true, true, 00, "                                                                  ELEANOR                          I haven't seen a stove like this since I was so little."},
                            {true, true, 00, "                                                                  ELEANOR                          I wanted to try and make some    toast."},
                            {true, true, 00, "                                                                  OLIVIER                          What do you think of this place?"},
                            {true, true, 00, "                                                                  OLIVIER                          There aren't many people, are yougoing to get lonely?"},
                            {true, true, 00, "                                                                  ELEANOR                          Well, are you going to be lonely?"},
                            {true, true, 00, "                                                                  OLIVIER                          I just wish my grandfather could see us, now."},
                            {true, true, 00, "                                                                  OLIVIER                          I think he'd be so proud of you."},
                            {true, true, 00, "                                                                  ELEANOR                          Maybe he can see us from heaven."},
                            {true, true, 00, "                                                                  ELEANOR                          Maybe mama has changed in heaven and thinks well of you, now."},
                            {true, true, 00, "                                                                  OLIVIER                          I don't suppose either of us can know, but I won't be lonely."},
                            {true, true, 00, "                                                                  OLIVIER                          I haven't really been lonely     since I got to know you."},
                            {true, true, 00, "                                                                  ELEANOR                          Vee, I hope that we don't ever   feel differently."},
                            {true, true, 00, "                                                                  ELEANOR                          I've seen how my parents became. I already feel older."},
                            {true, true, 00, "                                                                  ELEANOR                          I know that once we have our own enfants..."},
                            {true, true, 00, "                                                                  OLIVIER                          How is your sister doing?"},
                            {true, true, 00, "                                                                  ELEANOR                          She's always exhausted. She jokesabout grey hair, but I think"},
                            {true, true, 00, "                                                                  ELEANOR                          she really does have grey hairs. But she's different."},
                            {true, true, 00, "                                                                  ELEANOR                          The things she was so upset aboutare meaningless, now."},
                            {true, true, 00, "                                                                  OLIVIER                          Maybe it'll be the same with us. Let's just be patient."},
                            {true, true, 00, "                                                                  ELEANOR                          It'll be strange to have married friends our age. Do you think"},
                            {true, true, 00, "                                                                  ELEANOR                          Diana will be jealous?"},
                            {true, true, 00, "                                                                  OLIVIER                          I think she'll have a great time here. S'il te plait détends-toi!"},
                            {true, true, 00, "                                                                  ELEANOR                          Je suppose que tu as raison, Vee."},
                            {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }

                        case 6: {
                            line lc[32] = {
                            {true, true, 00, "                                                                  DIANA                            Aw, super! I love it, it's so    cozy in here."},
                            {true, true, 00, "                                                                  DIANA                            I hope y'all don't mind me spend-ing ungodly amounts of time here."},
                            {true, true, 00, "                                                                  ELEANOR                          Of course not! As long as you    don't mind helping sometimes."},
                            {true, true, 00, "                                                                  OLIVIER                          Remember, living like this means that we're going to work hard."},
                            {true, true, 00, "                                                                  OLIVIER                          I'll probably be spending most ofmy time chopping wood, or"},
                            {true, true, 00, "                                                                  OLIVIER                          working out in the garden pullingweeds and watering."},
                            {true, true, 00, "                                                                  ELEANOR                          You said that you were interestedin working for the boat captain?"},
                            {true, true, 00, "                                                                  DIANA                            Oh, yes. I'll be going down to   the docks today, in fact."},
                            {true, true, 00, "                                                                  DIANA                            Maybe I'll be a proper boat      captain before too long!"},
                            {true, true, 00, "                                                                  ELEANOR                          I know you'll do great, Diana!"},
                            {true, true, 00, "                                                                  OLIVIER                          This isn't what you thought you'dbe doing at 22, huh?"},
                            {true, true, 00, "                                                                  DIANA                            Well, I guess I didn't know what I thought I'd be doing."},
                            {true, true, 00, "                                                                  DIANA                            Y'all didn't think you'd be      moving here, huh?"},
                            {true, true, 00, "                                                                  OLIVIER                          I supposed I'd probably still be working with plants, that's it."},
                            {true, true, 00, "                                                                  ELEANOR                          I'm still alive and so is Vee,   and that's all I could want."},
                            {true, true, 00, "                                                                  DIANA                            Yeah.. Please stay that way, why don't you two?"},
                            {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }
                    }
                    break;
                }
           
                case 57: {
                    if (me == 4) {
                        line lc[32] = {
                            {true, true, 00, "                                                                  This is Eleanor's library."},
                            {true, true, 00, "COM: Endscene"}};
                        dialogue_page_lite(lc);
                    } else if (me != 5) {
                        line lc[32] = {
                            {true, true, 00, "                                                                  The door is locked."},
                            {true, true, 00, "                                                                  You decide that it's probably notyour business."},
                            {true, true, 00, "COM: Endscene"}};
                        dialogue_page_lite(lc);
                    } else {
                        dt.spawn_x = 3;
                        dt.spawn_y = 5;
                        dt.world_index = 12;
                        return dt;   
                    }
                    break;
                };

                case 58: {
                    dt.spawn_x = 4;
                    dt.spawn_y = 1;
                    dt.world_index = 9;
                    return dt;
                    break;
                };

                case 59: {
                    dt.spawn_x = 5;
                    dt.spawn_y = 0;
                    dt.world_index = 99;
                    return dt;
                    break;
                };
            
                case 60: {
                    dt.spawn_x = 6;
                    dt.spawn_y = 17;
                    dt.world_index = 8;
                    return dt;
                    break;
                };

                case 61: {
                    if (chari.at(follow_id).identity == 6) {
                        dt.spawn_x = 6;
                        dt.spawn_y = 0;
                        dt.world_index = 99;
                        return dt;
                        break;
                    }
                    break;
                };

                case 62: {
                    switch (me) {
                        default: {
                            break;
                        }

                        case 0: {
                            line lc[32] = {
                                {true, true, 00, "                                                                  MAPLE                            Hey! So, you're Diana?"},
                                {true, true, 00, "                                                                  DIANA                            Hiya! Finally! Another redhead!"},
                                {true, true, 00, "                                                                  MAPLE                            Oh, I'm not a red head, I'm more of a honey-blonde."},
                                {true, true, 00, "                                                                  MAPLE                            I'm a wood elf, so it looks a bitorange sometimes."},
                                {true, true, 00, "                                                                  DIANA                            Oh, you are? Then.."},
                                {true, true, 00, "                                                                  MAPLE                            Why are my ears round?"},
                                {true, true, 00, "                                                                  DIANA                            I don't want to ask if you don't feel comfortable."},
                                {true, true, 00, "                                                                  MAPLE                            Oh, it's fine. They were clipped when I was a baby."},
                                {true, true, 00, "                                                                  MAPLE                            I'm Maple, by the way.           Maple Tremblay."},
                                {true, true, 00, "                                                                  DIANA                            Heureux de te rencontrer!"},
                                {true, true, 00, "                                                                  DIANA                            These cabins are so nice! You're,uh, older brother make em?"},
                                {true, true, 00, "                                                                  MAPLE                            Mostly. I go out and find gems inlocal caves sometimes."},
                                {true, true, 00, "                                                                  MAPLE                            We make enough to live pretty    well out here."},
                                {true, true, 00, "                                                                  DIANA                            Do you live in that trailer I sawmoving in?"},
                                {true, true, 00, "                                                                  MAPLE                            Yep. I'm on the couch."},
                                {true, true, 00, "                                                                  DIANA                            Do you not want a cabin? One of  them looks empty."},
                                {true, true, 00, "                                                                  MAPLE                            You see, Aaron and Enoki want to make a castle or something."},
                                {true, true, 00, "                                                                  MAPLE                            I'm gonna take over their trailerwhen that happens."},
                                {true, true, 00, "                                                                  DIANA                            So... is this place, like,       seriously a country?"},
                                {true, true, 00, "                                                                  MAPLE                            I mean.. if we act like it is,   then it is, isn't it?"},
                                {true, true, 00, "                                                                  DIANA                            Is it really that easy?"},
                                {true, true, 00, "                                                                  MAPLE                            Until we fight a war? We'll see. Nice to meet you."},
                                {true, true, 00, "                                                                  DIANA                            Yeah, nice to meet you too!"},
                                {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }

                        case 1: {
                            line lc[32] = {
                            {true, true, 00, "                                                                  ENOKI                            Hey!! Are you Diana?             I'm Enoki Tremblay!"},
                            {true, true, 00, "                                                                  DIANA                            Enchanté de faire votre          connaissance!"},
                            {true, true, 00, "                                                                  ENOKI                            Is everything comfortable for youso far?"},
                            {true, true, 00, "                                                                  DIANA                            Dude, I'm still not sure if I'm  dreaming or not."},
                            {true, true, 00, "                                                                  DIANA                            This feels way too good to be    real, it's crazy."},
                            {true, true, 00, "                                                                  ENOKI                            I'm a pretty lucky gal, so when  I want something to happen, well,"},
                            {true, true, 00, "                                                                  ENOKI                            Things tend to turn out, and I   wanted this to turn out."},
                            {true, true, 00, "                                                                  ENOKI                            I heard you've got somethin' withCapt. Nicholas?"},
                            {true, true, 00, "                                                                  DIANA                            Yeah! He's looking for someone totake over this area."},
                            {true, true, 00, "                                                                  DIANA                            I'll eventually be ferrying      across Supérieur."},
                            {true, true, 00, "                                                                  ENOKI                            Aw, fun!! You gotta take us in a ride sometime."},
                            {true, true, 00, "                                                                  ENOKI                            If you ever need us for anything,you let us know, alright?"},
                            {true, true, 00, "                                                                  DIANA                            D'accord!"},
                            {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }

                        case 2: {
                            line lc[32] = {
                            {true, true, 00, "                                                                  DIANA                            Bienvenu! You're Aaron Tremblay, oui?"},
                            {true, true, 00, "                                                                  AARON                            Bienvenu! How's the cabin workingfor you?"},
                            {true, true, 00, "                                                                  DIANA                            Oh, it's perfect!! It feels too  good to be true, honestly."},
                            {true, true, 00, "                                                                  DIANA                            I'm starting up my first boat    introduction today."},
                            {true, true, 00, "                                                                  DIANA                            Do you know Capt. Nicholas well?"},
                            {true, true, 00, "                                                                  AARON                            I'll be honest, I spend most of  my time chopping wood."},
                            {true, true, 00, "                                                                  AARON                            But he seems like a very nice    person from what I know."},
                            {true, true, 00, "                                                                  AARON                            I won't stay long, I was just    stopping by to check in."},
                            {true, true, 00, "                                                                  AARON                            Just let me know if you need     anything, alright?"},
                            {true, true, 00, "                                                                  DIANA                            Absolutely! Thanks!"},
                            {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }

                        case 3: {
                            line lc[32] = {
                            {true, true, 00, "                                                                  SCOUT                            Hey! It's me, Scout. Just wanted to introduce myself."},
                            {true, true, 00, "                                                                  DIANA                            Ah! Nice to meet you! I'll admit I wasn't sure this was real."},
                            {true, true, 00, "                                                                  DIANA                            I'm glad I wasn't.. you know..   killed or something."},
                            {true, true, 00, "                                                                  SCOUT                            I'll admit, I'm actually a bit   new here, too-"},
                            {true, true, 00, "                                                                  SCOUT                            I moved over here from a nearby  island when I met the"},
                            {true, true, 00, "                                                                  SCOUT                            Trembalys and decided I'd jump   over here."},
                            {true, true, 00, "                                                                  SCOUT                            It wasn't exactly easy diggint a new bunker, but it was"},
                            {true, true, 00, "                                                                  SCOUT                            worth it. It's nicer over here."},
                            {true, true, 00, "                                                                  DIANA                            Well, you seem to be doing fine. You a scientist?"},
                            {true, true, 00, "                                                                  SCOUT                            Yeah, it's a little funny. This  company's got me here"},
                            {true, true, 00, "                                                                  SCOUT                            for some reason to do experimentsbut on an island? No clue why."},
                            {true, true, 00, "                                                                  DIANA                            You find out anything cool?"},
                            {true, true, 00, "                                                                  SCOUT                            I made this device that makes    bunkers real fast."},
                            {true, true, 00, "                                                                  SCOUT                            No idea what I'll use it for, butit's got potential."},
                            {true, true, 00, "                                                                  DIANA                            Hey, you feel like making me a   bunker sometime?"},
                            {true, true, 00, "                                                                  SCOUT                            Aw sure, I'd love to!"},
                            {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }

                        // Fall-through to the next bit
                        case 4: {
                            line lc[32] = {
                            {true, true, 00, "                                                                  DIANA                            Hey, Vee! Fancy seeing you here  in my /new cabin/, huh?"},
                            {true, true, 00, "                                                                  OLIVIER                          It only took you about a day to  make it look just like your"},
                            {true, true, 00, "                                                                  OLIVIER                          place back home, didn't it?"},
                            {true, true, 00, "                                                                  DIANA                            If all things go well, this'll beout new 'back home', right?"},
                            {true, true, 00, "                                                                  OLIVIER                          It all depends if we can trust   these people."},
                            {true, true, 00, "                                                                  OLIVIER                          You've got something to defend   yourself on you, right?"},
                            {true, true, 00, "                                                                  DIANA                            Right, I have my flare gun on me."},
                            {true, true, 00, "                                                                  DIANA                            I really home I never have to useit, though."},
                            {true, true, 00, "                                                                  OLIVIER                          Me too. But they seem nice       enough."},
                            {true, true, 00, "                                                                  OLIVIER                          At least they're not going to tryand sacrifice us, hehe."},
                            {true, true, 00, "                                                                  DIANA                            Hehe, no kidding. If any of El's family shows up,"},
                            {true, true, 00, "                                                                  DIANA                            You're giving me a call, right?"},
                            {true, true, 00, "                                                                  OLIVIER                          Of course, of course."},
                            {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }

                        case 5: {
                            line lc[32] = {
                            {true, true, 00, "                                                                  ELEANOR                          It looks just like your room at  home!"},
                            {true, true, 00, "                                                                  DIANA                            Yep, did you expect anything lessfrom me? Hehe."},
                            {true, true, 00, "                                                                  ELEANOR                          Well, I love it anyway. It's verycozy."},
                            {true, true, 00, "                                                                  ELEANOR                          If you need anything, please let me know,"},
                            {true, true, 00, "                                                                  ELEANOR                          I have set up my room, and we nowhave a crystal ball room!"},
                            {true, true, 00, "                                                                  ELEANOR                          I'm still working on my summoningskills, they're rusty."},
                            {true, true, 00, "                                                                  DIANA                            And you're absolutely sure that  using magic won't cause"},
                            {true, true, 00, "                                                                  DIANA                            Any.. er.. witches to find out   where we are?"},
                            {true, true, 00, "                                                                  ELEANOR                          I'm positive. I even think that  if this is good enough,"},
                            {true, true, 00, "                                                                  ELEANOR                          We can invite my family to come  by, I'd love to show them"},
                            {true, true, 00, "                                                                  ELEANOR                          this place. It seems peaceful."},
                            {true, true, 00, "                                                                  DIANA                            We'll see. We haven't exactly hada peaceful life until now."},
                            {true, true, 00, "                                                                  DIANA                            Hey, you seen those Tremblays yetor talked to them?"},
                            {true, true, 00, "                                                                  DIANA                            It feels like we've got one of   them for each of us."},
                            {true, true, 00, "                                                                  DIANA                            They have a redhead and a couple with the 'farmer' type"},
                            {true, true, 00, "                                                                  DIANA                            and that Enoki seems cute, but   you're the cuter one."},
                            {true, true, 00, "                                                                  ELEANOR                          Aw, Merci!"},
                            {true, true, 00, "                                                                  DIANA                            I can't help but be a little     suspicious, but I think"},
                            {true, true, 00, "                                                                  DIANA                            We're in for a good time."},
                            {true, true, 00, "                                                                  ELEANOR                          Me too."},
                            {true, true, 00, "COM: Endscene"}};
                            dialogue_page_lite(lc);
                            break;
                        }

                        case 6: {
                            auto b_button = bn::sprite_items::b_button.create_sprite(90,-50);
                            auto uke_anim = bn::create_sprite_animate_action_forever(chari.at(follow_id).entity, 12, bn::sprite_items::diana_uke.tiles_item(), 0, 1, 2, 3);
                            bn::music::stop();
                            bn::music_items_info::span[32].first.play(bn::fixed(80) / 100);

                            while(!bn::keypad::b_pressed()) {
                                bn::core::update();

                                uke_anim.update();
                                chari.at(follow_id).entity = uke_anim.sprite();
                            }

                            bn::music::stop();
                            bn::music_items_info::span[5].first.play(bn::fixed(80) / 100);
                        }
                    }
                    break;
                }

                case 63: {
                    corinne.set_blending_enabled(false);
                    line lc[32] = {
                    {true, true, 00, "                                                                  OLIVIER                          O-Oh! Excuse me, ma'am. Where didyou come from?"},
                    {true, true, 00, "                                                                  GRAND-MERE CORINNE               This greenhouse is still quite   nice, was it moved?"},
                    {true, true, 00, "                                                                  OLIVIER                          Oh.. Well, I was told that it wastransported from inland."},
                    {true, true, 00, "                                                                  GRAND-MERE CORINNE               Well, you see, I once owned this greenhouse, young man."},
                    {true, true, 00, "                                                                  GRAND-MERE CORINNE               I don't see any point in having  ambiguity; I am a ghost."},
                    {true, true, 00, "                                                                  OLIVIER                          A ghost???"},
                    {true, true, 00, "                                                                  GRAND-MERE CORINNE               It seems I am doomed to haunt    this greenhouse forever."},
                    {true, true, 00, "                                                                  OLIVIER                          My apologize, that seems... it   seems like a terrible fate."},
                    {true, true, 00, "                                                                  GRAND-MERE CORINNE               Would you consider it horrible tospend an eternity here?"},
                    {true, true, 00, "                                                                  OLIVIER                          Now that I think about it.. I    suppose not."},
                    {true, true, 00, "                                                                  OLIVIER                          It's where I spend most of my    life anyway."},
                    {true, true, 00, "                                                                  GRAND-MERE CORINNE               I see you enjoy taking care of   these plants, son."},
                    {true, true, 00, "                                                                  GRAND-MERE CORINNE               Before I leave, I will remind youof one wisdom."},
                    {true, true, 00, "                                                                  GRAND-MERE CORINNE               Even if your care of these plantsseems meaningless,"},
                    {true, true, 00, "                                                                  GRAND-MERE CORINNE               Wonderful things come to the     diligent."},
                    {true, true, 00, "                                                                  GRAND-MERE CORINNE               It was very nice to meet you.    Until next time!"},
                    {true, true, 00, "COM: Endscene"}};
                    dialogue_page_lite(lc);
                    corinne.set_visible(false);
                    break;
                }

                // Guy's house

                case 64: {
                    dt.spawn_x = 3;
                    dt.spawn_y = 5;
                    dt.world_index = 13;
                    return dt;
                };

                case 65: {
                    dt.spawn_x = 13;
                    dt.spawn_y = 17;
                    dt.world_index = 8;
                    return dt;
                };

                // Northern Area

                case 66: {
                    dt.spawn_x = 7;
                    dt.spawn_y = 18;
                    dt.world_index = 14;
                    return dt;
                }

                case 67: {
                    dt.spawn_x = 16;
                    dt.spawn_y = 1;
                    dt.world_index = 4;
                    return dt;
                }

                case 68: {
                    dt.spawn_x = 7;
                    dt.spawn_y = 0;
                    dt.world_index = 99;
                    return dt;
                }

                case 69: {
                    line lc[32] = {
                    {true, true, 00, "                                                                  CESAR'S BIZAAR                   'WE ONLY HAVE TWO ITEMS,         DEAL WITH IT'"},
                    {true, true, 00, "COM: Endscene"}};
                    dialogue_page_lite(lc);
                    corinne.set_visible(false);
                    break;
                }
            }
        }

        }

        // Hat logic
        if (active_hat) {
            if (so->hat_char > -1) {
                int my_id = 0;
                for (int i = 0; i < chari.size(); i++) {
                    if (chari.at(i).identity == so->hat_char) my_id = i;
                }

                hat.set_position(chari.at(my_id).entity.x().integer(), chari.at(my_id).entity.y().integer() - 22);
                l_button.set_visible(true);

                if (bn::keypad::l_pressed()) {
                    bn::sound_items::pop.play();
                    so->hat_x = chari.at(my_id).entity.x().integer();
                    so->hat_y = chari.at(my_id).entity.y().integer() + 1;
                    so->hat_world = dt.world_index;
                    so->hat_char = -1;
                    l_button.set_visible(false);
                }
            } else {
                hat.set_position(so->hat_x, so->hat_y);

                if (so->hat_y > chari.at(follow_id).entity.y()) {
                    hat.put_above();
                } else {
                    hat.put_below();
                }

                if (abs(so->hat_x - chari.at(follow_id).entity.x().integer()) + abs(so->hat_y - chari.at(follow_id).entity.y().integer()) < 32) {
                    a_notif = bn::sprite_items::a_button_2.create_sprite(so->hat_x, so->hat_y - 28, 1);
                    a_notif.set_camera(camera);
                    a_notif.set_visible(true);
                }

                if (bn::keypad::l_pressed()) {
                    bn::sound_items::squeak.play();
                    so->hat_char = chari.at(follow_id).identity;
                }
            }
        }

        // Swap characters
        if (bn::keypad::b_pressed())
        {
            bn::sound_items::cnaut.play();
            bn::blending::set_intensity_alpha(1);
            int new_chari = (follow_id + 1) % chari.size();
            int old_role = chari.at(new_chari).role;
            chari.at(new_chari).role = 1;
            chari.at(new_chari).entity.set_blending_enabled(true);
            chari.at(follow_id).role = old_role;
            chari.at(follow_id).entity.set_blending_enabled(false);

            so->last_char_id = chari.at(new_chari).identity;
        }

        // Character operations
        for (int t = 0; t < chari.size(); t++)
        {

            // Set primary camera following X/Y coordinates

            if (chari.at(t).role == 1)
            {
                chari.at(t).update();
                follow_x = chari.at(t).entity.x().integer();
                follow_y = chari.at(t).entity.y().integer();
                follow_id = t;
            }
            else
            {
                chari.at(t).update(follow_x, follow_y);
            }

            // Z-Order followers
            if (chari.at(t).entity.y() < chari.at(follow_id).entity.y()) {
                chari.at(t).entity.set_z_order(3);
            } else {
                chari.at(t).entity.set_z_order(1);
            }
        }

        chari.at(follow_id).entity.set_z_order(2);

        // Camera follows primary player
        if (current_room.width > 7) {
            if (camera.x() > follow_x + 30)
            {
                camera.set_x(camera.x() - 1);
            }
            else if (camera.x() < follow_x - 30)
            {
                camera.set_x(camera.x() + 1);
            }

            // Camera adjustment
            if (camera.x().integer() > (current_room.width * 32) - 172)
            {
                camera.set_x((current_room.width * 32) - 172);
            }
            else if (camera.x().integer() < 106)
            {
                camera.set_x(106);
            }
        } else {
            camera.set_x(3 * 32);
        }

        if (camera.y() > follow_y + 30)
        {
            camera.set_y(camera.y() - 1);
        }
        else if (camera.y() < follow_y - 30)
        {
            camera.set_y(camera.y() + 1);
        }

        if (camera.y().integer() > (current_room.height * 32) - 96)
        {
            camera.set_y((current_room.height * 32) - 96);
        }
        else if (camera.y().integer() < 64)
        {
            camera.set_y(64);
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
                    int loc = current_room.local_tileset.at((current_room.width * y) + x);
                    if (local_walls_p < w_size && loc > 0)
                    {

                        if (dt.world_index < 4)
                        {
                            local_walls[local_walls_p].entity = bn::sprite_items::environment_stone.create_sprite(x * 32, y * 32, loc - 1);
                            local_walls[local_walls_p].entity.set_z_order(4);
                        }
                        else if (dt.world_index == 4 || dt.world_index == 7 || dt.world_index == 8 || dt.world_index == 14)
                        {
                            if (loc == 26)
                            {
                                local_walls[local_walls_p].entity = bn::sprite_items::water_animation.create_sprite(x * 32, y * 32, anim8);
                                anim8++;
                                anim8 = anim8 % 8;
                                local_walls[local_walls_p].entity.set_z_order(4);
                            }
                            else
                            {
                                local_walls[local_walls_p].entity = bn::sprite_items::ocean_terrain.create_sprite(x * 32, y * 32, loc - 1);
                                if (loc == 1)
                                {
                                    local_walls[local_walls_p].entity.set_z_order(0);
                                }
                                else
                                {
                                    local_walls[local_walls_p].entity.set_z_order(4);
                                }
                            }

                            if (so->checkpoint == 5) {
                                local_walls[local_walls_p].entity.set_palette(bn::sprite_items::environment_stone.palette_item());
                            }
                        }
                        else if (dt.world_index == 5)
                        {
                            local_walls[local_walls_p].entity = bn::sprite_items::trailer_home.create_sprite(x * 32, y * 32, loc - 1);
                            local_walls[local_walls_p].entity.set_z_order(4);
                        }
                        else if (dt.world_index == 6)
                        {
                            if (loc < 15) {
                            local_walls[local_walls_p].entity = bn::sprite_items::scout_lab.create_sprite(x * 32, y * 32, loc - 1);
                            local_walls[local_walls_p].entity.set_z_order(4);
                            }
                        }
                        else if (dt.world_index == 11)
                        {
                            
                            local_walls[local_walls_p].entity = bn::sprite_items::pools_tiles.create_sprite(x * 32, y * 32, loc - 1);
                            if (loc > 1) {
                                local_walls[local_walls_p].entity.set_z_order(4);
                            } else {
                                local_walls[local_walls_p].entity.set_z_order(0);
                            }
                        }

                        local_walls[local_walls_p].entity.set_camera(camera);
                        local_walls_p++;
                    }
                }
            }
        }
        update_counter++;
        if (update_counter > 16)
            update_counter = 0;

        hat.put_above();
        a_notif.put_above();
        l_button.put_above();
        bn::core::update();

        // World-specific special events

        switch (dt.world_index)
        {
        case 1:
            for (int i = 0; i < p_size; i++)
            {
                if (p[i].active)
                {
                    int my_x = p[i].fireball.x().integer() / 32;
                    int my_y = p[i].fireball.y().integer() / 32;
                    if (my_x >= 8 && my_x <= 11 && my_y >= 4 && my_y <= 7)
                    {
                        anim_objects.at(0).entity.set_visible(true);
                    }
                }
            }
            break;
        case 2:
            for (int i = 0; i < p_size; i++)
            {
                if (p[i].active && p[i].dur < 16)
                {
                    int my_x = p[i].fireball.x().integer() / 32;
                    int my_y = p[i].fireball.y().integer() / 32;
                    if (my_x >= 2 && my_x <= 3 && my_y >= 2 && my_y <= 3)
                    {
                        p[i].dur = 16;
                        anim_objects.at(0).entity_anim = bn::create_sprite_animate_action_forever(anim_objects.at(0).entity, 18, anim_objects.at(0).entity_item.tiles_item(), 2, 1, 00, 1);
                        anim_objects.at(0).entity.set_horizontal_flip(!anim_objects.at(0).entity.horizontal_flip());
                        anim_objects.at(0).entity_anim.update();
                    }
                }
            }
            break;
        case 3:
            //(144,16);
            for (int i = 0; i < p_size; i++)
            {
                int my_x = p[i].fireball.x().integer() / 32;
                int my_y = p[i].fireball.y().integer() / 32;
                if (my_x >= 4 && my_x <= 5 && my_y >= 0 && my_y <= 1)
                {
                    p[i].dur = 16;
                    bn::sound_items::firecrackle.play();
                    anim_objects.at(0).entity_anim = bn::create_sprite_animate_action_forever(anim_objects.at(0).entity, 18, anim_objects.at(0).entity_item.tiles_item(), 1, 1, 1, 1);
                    anim_objects.at(0).entity_anim.update();
                    a_notif.set_visible(false);

                    if (bn::music::playing()) bn::music::stop();
                    for (int t = 0; t < 128; t++)
                    {
                        chari.at(0).update();
                        p[i].update();
                        bn::core::update();
                    }
                    projectile pro[3];
                    for (int t = 0; t < p_size; t++)
                    {
                        pro[t].fireball.set_visible(false);
                    }

                    line lc[32] = {
                        {true, true, 00, "                                                                  MAPLE                            ...."},
                        {true, true, 00, "                                                                  ENOKI                            Well, there's no passage."},
                        {true, true, 00, "                                                                  MAPLE                            You don't say."},
                        {true, true, 00, "                                                                  ENOKI                            That's weird."},
                        {true, true, 00, "                                                                  MAPLE                            Enoki... Look here."},
                        {true, true, 00, "                                                                  MAPLE                            I guess it doesn't make any sense"},
                        {true, true, 00, "                                                                  MAPLE                            to be angry, so I won't be, but.."},
                        {true, true, 00, "                                                                  MAPLE                            You need to stop being like this."},
                        {true, true, 00, "                                                                  MAPLE                            You and Aaron just spent all this"},
                        {true, true, 00, "                                                                  MAPLE                            money on a barely furnished"},
                        {true, true, 00, "                                                                  MAPLE                            castle without basic faculties"},
                        {true, true, 00, "                                                                  MAPLE                            for what? So you could play like"},
                        {true, true, 00, "                                                                  MAPLE                            you're a princess? While I'm over"},
                        {true, true, 00, "                                                                  MAPLE                            in Carolina, sacrificing the best"},
                        {true, true, 00, "                                                                  MAPLE                            parts of my life for an apartment"},
                        {true, true, 00, "                                                                  MAPLE                            with the bare essentials?"},
                        {true, true, 00, "                                                                  MAPLE                            Enoki... Please."},
                        {true, true, 00, "                                                                  MAPLE                            I don't want to be the bad guy."},
                        {true, true, 00, "                                                                  MAPLE                            I know you didn't really have a"},
                        {true, true, 00, "                                                                  MAPLE                            childhood or parents, I get it."},
                        {true, true, 00, "                                                                  MAPLE                            That's me too."},
                        {true, true, 00, "                                                                  MAPLE                            But you can't keep going on like"},
                        {true, true, 00, "                                                                  MAPLE                            this. Do you understand?"},
                        {true, true, 00, "                                                                  ENOKI                            I do understand."}, //j'ai compris?
                        {true, true, 00, "                                                                  MAPLE                            It's 5:00 in the morning, I'm"},
                        {true, true, 00, "                                                                  MAPLE                            going back to bed. I'll see y'all"},
                        {true, true, 00, "                                                                  MAPLE                            in the morning, oui?"},
                        {true, true, 00, "                                                                  ENOKI                            Oui.."},
                        {true, true, 00, "                                                                  MAPLE                            Hey, don't beat yourself up about"},
                        {true, true, 00, "                                                                  MAPLE                            it. S'il te plait.. Bonne nuit."},
                        {true, true, 00, "                                                                  ENOKI                            Bonne nuit.."},
                        {true, true, 00, "COM: Endscene"}};
                    dialogue_page_lite(lc);

                    dt.world_index = -1;
                    return dt;
                }
            }
            break;
        case 11: {

            if (corinne.visible()) {
                if (abs(chari.at(follow_id).entity.x().integer() - corinne.x().integer()) + abs(chari.at(follow_id).entity.y().integer() - corinne.y().integer()) < 48) {
                    corinne.set_blending_enabled(true);
                    bn::blending::set_transparency_alpha(0.5);
                } else {
                    corinne.set_blending_enabled(false);
                }
            }

            if (chari.at(follow_id).identity == 4 && bn::keypad::r_pressed() && corinne.visible() == false) {

                corinne.set_visible(true);
                corinne.set_x(chari.at(follow_id).entity.x());
                bn::sound_items::pop.play();

                if (chari.at(follow_id).entity.y() < (current_room.height * 32) / 2) {
                    corinne.set_y(chari.at(follow_id).entity.y() + 192);
                } else {
                    corinne.set_y(chari.at(follow_id).entity.y() - 192);
                }

                int s_x = (corinne.x().integer() + 16) / 32;
                int s_y = (corinne.y().integer() + 16) / 32;
                corinne.set_position(s_x * 32, s_y * 32);

                if (current_room.collisions.at(s_x + (current_room.width * (s_y + 1))) == 0) {
                    current_room.collisions.at(s_x + (current_room.width * (s_y + 1))) = 63;
                } else if (current_room.collisions.at(s_x + (current_room.width * (s_y - 1))) == 0) {
                    current_room.collisions.at(s_x + (current_room.width * (s_y - 1))) = 63;
                } else if (current_room.collisions.at(s_x + (current_room.width * s_y) - 1) == 0) {
                    current_room.collisions.at(s_x + (current_room.width * s_y) - 1) = 63;
                } else if (current_room.collisions.at(s_x + (current_room.width * s_y) + 1) == 0) {
                    current_room.collisions.at(s_x + (current_room.width * s_y) + 1) = 63;
                }
            }

            break;
        }

        default:
            {
            }
        }
    }
}