#include <sstream>
#include <bn_blending.h>
#include <bn_regular_bg_ptr.h>

#include <bn_sprite_builder.h>
#include <bn_sprite_animate_actions.h>

// UI elements
#include "bn_sprite_items_a_button_2.h"

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
#include "bn_regular_bg_items_bg_explosion.h"
#include "bn_regular_bg_items_bg_skeleton.h"

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

// Generic classes
class line {
    public:
        bool transition;
        bool left;
        int img = 0;
        char text[192] = {0};
};

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
    if (n/10 == 0)
        return 1;
    return 1 + countDigit(n / 10);
}

class save_struct {
    public:
        int last_char_id = 0;
        int checkpoint = 0;
        char island_name[16] = {0};
        int spawn_x = 0;
        int spawn_y = 0;
        int world_index = 0;
        int xp = 0;

        int hat_x = 0;
        int hat_y = 0;
        int hat_world = 0;
        int hat_char = 0;

        int gems = 0;
};

class save_all_struct {
    public:
        save_struct so[3];
};

void deep_copy(std::vector<int> &a, std::vector<int> &b) {
    b.clear();
    for (auto &c : a) {
        b.push_back(c);
    }
}

template<typename C, typename T>
bool contains(C&& c, T e) { 
    return std::find(std::begin(c), std::end(c), e) != std::end(c);
};

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

// Dungeon return type
class dungeon_return
{
public:
    int spawn_x = 0;
    int spawn_y = 0;
    int world_index = 0;
};

// Custom character class
class character
{
public:
    int identity = 0;
    int dir = 0;
    int last_dir = 0;
    int follow_id = -1;
    bool done = false;
    bool is_walking = false;
    bool event = false;
    bool can_follow = true;
    bool is_npc = false;

    int last_x, last_y;
    std::vector<int>* collisions;
    int room_width = 0;

    bn::sprite_item entity_item = bn::sprite_items::maple_walking;
    bn::sprite_ptr entity = entity_item.create_sprite(0, 0);
    bn::sprite_animate_action<4> entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 00, 1, 00, 2);

    int role = 0;
    // 0 = follower
    // 1 = main
    // 2 = independent

    int collideFrom = 1;

    character(const bn::sprite_item sprite, float x = 0, float y = 0, int main = 0, int room_width = 0)
    {
        entity = sprite.create_sprite(x * 32, y * 32);
        entity.set_visible(true);
        entity_item = sprite;
        entity_anim = bn::create_sprite_animate_action_forever(entity, 8, entity_item.tiles_item(), 00, 1, 00, 2);
        role = main;
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
            roundDown(y_int + 6) * room_width,
            roundUp(y_int) * room_width};

        int col[8] = {
            collisions->at(close[0] + close[2]) == 1,
            collisions->at(close[0] + close[3]) == 1,
            collisions->at(close[1] + close[2]) == 1,
            collisions->at(close[1] + close[3]) == 1,
            collisions->at(close[0] + close[2]) == 1,
            collisions->at(close[1] + close[2]) == 1,
            collisions->at(close[0] + close[3]) == 1,
            collisions->at(close[1] + close[3]) == 1};

        bool canLeft = !(((col[4] && col[5]) ^ col[0]) || ((col[6] && col[7]) ^ col[1]));
        bool canRite = !(((col[4] && col[5]) ^ col[2]) || ((col[6] && col[7]) ^ col[3]));
        bool canUp = !(((col[0] && col[1]) ^ col[4]) || ((col[2] && col[3]) ^ col[5]));
        bool canDn = !(((col[0] && col[1]) ^ col[6]) || ((col[2] && col[3]) ^ col[7]));

        if (canLeft || canRite)
        {
            last_x = entity.x().integer();
        }

        if (canUp || canDn)
        {
            last_y = entity.y().integer();
        }

        // If following...
        if (role == 0)
        {

            // Collision detection
            done = true;
            is_walking = false;

            // Follow player
            int dist = abs(x - entity.x().integer()) + abs(y - entity.y().integer());

            bool isXTravel = false;
            if (x < entity.x() - 24 || (x < entity.x() && dist > 72))
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
            else if (x > entity.x() + 24 || (x > entity.x() && dist > 72))
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
            if (y < entity.y() - 24 || (y < entity.y() && dist > 72))
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
            else if (y > entity.y() + 24 || (y > entity.y() && dist > 72))
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
        if (!canLeft && !canRite)
            entity.set_x(last_x);
        if (!canUp && !canDn)
            entity.set_y(last_y);
        entity = entity_anim.sprite();
        //entity.set_camera(current_room.camera);
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

// Bats and flying bits
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
    int room_width = 0;
    std::vector<int>* local_tileset;

    creepy_crawly() {}

    void update()
    {
        int flap = std::rand() % 2;
        if (flap == 0)
        {
            sprite_anim.update();
            sprite = sprite_anim.sprite();
        }

        int mx = sprite.x().integer() / 32;
        int my = sprite.y().integer() / 32;
        int mz = mx + (my * room_width);

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
                if (&local_tileset[mz + 1] == 0)
                {
                    to_x = mx + 1;
                    to_y = my;
                }
                break;
            case 1:
                if (&local_tileset[mz + room_width] == 0)
                {
                    to_y = my + 1;
                    to_x = mx;
                }
                break;
            case 2:
                if (&local_tileset[mz - 1] == 0)
                {
                    to_x = mx - 1;
                    to_y = my;
                }
                break;
            case 3:
                if (&local_tileset[mz - room_width] == 0)
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

class moving_block
{
public:
    bn::sprite_ptr entity = bn::sprite_items::underground_tiles.create_sprite(0, 0, 15);
    bool is_moving = true;
    int moving_x = 0;
    int moving_y = 0;
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
    int x = 0;
    int y = 0;
};

class button
{
public:
    bool toggled = false;
    bool short_toggle = false;
    int x = 0;
    int y = 0;
};

class gate
{
public:
    int triggered_by = 0;
    int x = 0;
    int y = 0;
};

// Room setup object
class room
{
public:
    int width = 29;
    int height = 14;
    int start_x = 8;
    int start_y = 3;

    int follow_x = 0;
    int follow_y = 0;
    int follow_id = 0;

    // Tiled environment
    std::vector<int> local_tileset = {0};
    std::vector<int> collisions = {0};
    bn::vector<bn::sprite_ptr, 35> tile_hopper;
    bn::sprite_ptr* tile_ref[35] = {NULL};

    // Cam + characters
    bn::camera_ptr camera = bn::camera_ptr::create(0,0);
    bn::vector<character, 7> chari;
    bn::vector<anim_object, 7> anim_objects;

    // Misc environment
    bn::regular_bg_ptr primary_bg = bn::regular_bg_items::velvet.create_bg(0, 0);
    bn::sprite_ptr a_notif = bn::sprite_items::a_button_2.create_sprite(0, 0);

    // Make a fireball!
    int p_index = 0;
    bn::vector<projectile, 3> p;

    room(int w, int h, int x, int y) {
        width = w;
        height = h;
        start_x = x;
        start_y = y;

        primary_bg.set_camera(camera);
        a_notif.set_camera(camera);
        a_notif.set_visible(false);

        for (int t = 0; t < 3; t++)
        {
            p.at(t).fireball.set_camera(camera);
            p.at(t).fireball.set_visible(false);
        }
    }

    void configure(int w, int h, int x, int y) {
        width = w;
        height = h;
        start_x = x;
        start_y = y;
    }

    int tile_at_z(int x, int y) {
        return local_tileset.at(x + (y * width));
    }

    int col_at_z(int x, int y) {
        return collisions.at(x + (y * width));
    }

    void place(int x, int y, int tile_loc) {
        int z = x + (y * width);
        if (local_tileset.at(z) > 0) {
            bn::sprite_ptr s = bn::sprite_items::environment_stone.create_sprite(x * 32, y * 32, local_tileset.at(z));
            s.set_camera(camera);
            tile_hopper.push_back(s);
            tile_ref[tile_loc] = &s;
        }
    }

    void init_render(int p_x, int p_y) {
        int f_x = p_x - 4;
        int t_x = p_x + 4;
        int f_y = p_y - 4;
        int t_y = p_y + 4;
        if (f_x < 0) f_x = 0;
        if (t_x > width) t_x = width;
        if (f_y < 0) f_y = 0;
        if (t_y > width) t_y = width;

        int tile_loc = 0;
        for (int y = f_y; y < t_y; y++) {
            for (int x = f_x; x < f_x; x++) {
                place(x, y, tile_loc);
                tile_loc++;
            }
        }
    }

    void update_objects() {

        // set current_room.camera follow point
        follow_x = chari.at(follow_id).entity.x().integer();
        follow_y = chari.at(follow_id).entity.y().integer();

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
                p.at(p_index).active = true;
                p.at(p_index).fireball.set_x(follow_x);
                p.at(p_index).fireball.set_y(follow_y);
                p.at(p_index).dir = chari.at(follow_id).dir;
                p.at(p_index).dur = 0;
                p.at(p_index).fireball.set_visible(true);
                p_index++;
                if (p_index >= p.size())
                    p_index = 0;
            }
            else if (chari.at(follow_id).identity == 4)
            {
                bn::sound_items::firecrackle.play();

                /*
                if (so->checkpoint == 8 && so->xp < 201)
                {
                    so->xp++;
                }
                else if (so->checkpoint == 10 && so->xp < 301)
                {
                    so->xp++;
                }
                */
            }
            else
            {
                bn::sound_items::squeak.play();
            }
        }

        // Update projectiles
        for (int t = 0; t < p.size(); t++)
        {
            if (p.at(t).active)
            {
                p.at(t).fireball.set_z_order(1);
                p.at(t).update();
            }
        }

        // Swap characters
        if (bn::keypad::b_pressed())
        {
            bn::sound_items::cnaut.play();
            bn::blending::set_intensity_alpha(1);
            int new_chari = (follow_id + 1) % chari.size();

            chari.at(follow_id).entity.set_blending_enabled(false);
            for (int t = 0; t < chari.size(); t++) {
                if (t != new_chari) {
                    if (chari.at(t).can_follow) chari.at(t).role = 0;
                    else chari.at(t).role = 2;
                }
            }
            chari.at(new_chari).entity.set_blending_enabled(true);
            chari.at(new_chari).role = 1;
            //so->last_char_id = chari.at(new_chari).identity;
        }

        // Character operations
        for (int t = 0; t < chari.size(); t++)
        {
            // Set primary camera following X/Y coordinates
            chari.at(t).entity.set_z_order(200 - (chari.at(t).entity.y().integer() - camera.y().integer()));

            if (chari.at(t).role == 1)
            {
                chari.at(t).update();
                follow_id = t;
            }
            else if (chari.at(t).role == 0)
            {
                int my_follow_at = chari.at(t).follow_id;
                if (my_follow_at == -1) my_follow_at = (t + 1) % chari.size();
                chari.at(t).update(chari.at(my_follow_at).entity.x().integer(), chari.at(my_follow_at).entity.y().integer());
            }
        }

        // camera follows primary player
        if (width > 7) {
            if (camera.x() > follow_x + 30) camera.set_x(camera.x() - 1);
            else if (camera.x() < follow_x - 30) camera.set_x(camera.x() + 1);

            // camera adjustment
            if (camera.x().integer() > (width * 32) - 172) camera.set_x((width * 32) - 172);
            else if (camera.x().integer() < 106) camera.set_x(106);
        }
        else camera.set_x(3 * 32);

        // Camera follows player
        if (camera.y() > follow_y + 30) camera.set_y(camera.y() - 1);
        else if (camera.y() < follow_y - 30) camera.set_y(camera.y() + 1);
        if (camera.y().integer() > (height * 32) - 96) camera.set_y((height * 32) - 96);
        else if (camera.y().integer() < 64) camera.set_y(64);

        // Regularly update the tileset based on new camera coordinates
        int f_x_a = camera.x().integer() / 32;
        int f_y_a = camera.y().integer() / 32;
        int min_y = f_y_a - 4;
        if (min_y < 0)
            min_y = 0;
        int min_x = f_x_a - 4;
        if (min_x < 0)
            min_x = 0;
        int max_y = f_y_a + 7;
        if (max_y > height)
            max_y = height;
        int max_x = f_x_a + 7;
        if (max_x > width)
            max_x = width;



        a_notif.put_above();
    }
};
