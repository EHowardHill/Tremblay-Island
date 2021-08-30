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

#include <bn_sprite_animate_actions.h>
#include <bn_sprite_builder.h>

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
#include <list>

#include "objects.h"

#include "bn_sprite_items_maple_walking.h"
#include "bn_sprite_items_enoki_walking_pj.h"

#include "bn_regular_bg_items_s0101.h"
#include "bn_regular_bg_items_s0102.h"
#include "bn_regular_bg_items_s0103.h"
#include "bn_regular_bg_items_s0104.h"
#include "bn_regular_bg_items_s0105.h"
#include "bn_regular_bg_items_s0106.h"
#include "bn_regular_bg_items_s0107.h"
#include "bn_regular_bg_items_s0108.h"
#include "bn_regular_bg_items_s0109.h"

#include "bn_sprite_items_environment_stone.h"
#include "bn_regular_bg_items_castle_floor.h"

#include "bn_regular_bg_items_cinemint_studios.h"

#include "bn_sprite_items_enoki.h"
#include "bn_sprite_items_maple01.h"
#include "bn_sprite_items_maple02.h"
#include "bn_sprite_items_maple03.h"
#include "bn_sprite_items_maple04.h"
#include "bn_sprite_items_maple05.h"
#include "bn_sprite_items_enoki01.h"
#include "bn_sprite_items_enoki02.h"
#include "bn_sprite_items_enoki03.h"
#include "bn_sprite_items_enoki04.h"
#include "bn_sprite_items_aaron01.h"
#include "bn_sprite_items_aaron02.h"
#include "bn_sprite_items_delphine01.h"
#include "bn_sprite_items_delphine02.h"

#include "bn_regular_bg_items_castle01.h"
#include "bn_regular_bg_items_castle02.h"
#include "bn_regular_bg_items_castle03.h"

#include "bn_log.h"

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

    void set_sprite(bn::sprite_ptr chari, int value) {
        switch(value) {
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
            default:
                break;
        }
    }

    void dialogue_page(Concepts::line n[64])
    {   
        bn::sprite_ptr chari_l = bn::sprite_items::maple01.create_sprite(-50, -17);
        bn::sprite_ptr chari_r = bn::sprite_items::maple01.create_sprite(50, -17);
        bn::regular_bg_ptr primary_bg = bn::regular_bg_items::ocean.create_bg(0, 0);
        bn::sprite_ptr a_button = bn::sprite_items::a_button.create_sprite(-90, -50);

        chari_l.set_scale(1);
        chari_l.set_visible(false);
        chari_r.set_scale(1);
        chari_r.set_visible(false);
        chari_r.set_horizontal_flip(true);

        int pos = 0;
        bool cont = true;
        while (cont) {

            // Set music
            if (strcmp(n[pos].text, "BG: 0") == 0) {
                int music_item_index = 0;
                int music_volume = 15;
                bn::music_items_info::span[music_item_index].first.play(bn::fixed(music_volume) / 100);
            
            } else if (strcmp(n[pos].text, "BG: 1") == 0) {
                int music_item_index = 1;
                int music_volume = 15;
                bn::music_items_info::span[music_item_index].first.play(bn::fixed(music_volume) / 100);

            } else if (strcmp(n[pos].text, "BG: 2") == 0) {
                int music_item_index = 2;
                int music_volume = 15;
                bn::music_items_info::span[music_item_index].first.play(bn::fixed(music_volume) / 100);

            } else if (strcmp(n[pos].text, "BG: fadeout") == 0) {
                if (bn::music::playing()) {
                    bn::music::set_volume(0);
                }

            // Set backgrounds
            } else if (strcmp(n[pos].text, "BG: Ocean") == 0) {
                primary_bg.set_item(bn::regular_bg_items::ocean);
            } else if (strcmp(n[pos].text, "BG: Forest") == 0) {
                primary_bg.set_item(bn::regular_bg_items::mountain);
            } else if (strcmp(n[pos].text, "S01:01") == 0) {
                primary_bg.set_item(bn::regular_bg_items::s0101);
            } else if (strcmp(n[pos].text, "S01:02") == 0) {
                primary_bg.set_item(bn::regular_bg_items::s0102);
            } else if (strcmp(n[pos].text, "S01:03") == 0) {
                primary_bg.set_item(bn::regular_bg_items::s0103);
            } else if (strcmp(n[pos].text, "S01:04") == 0) {
                primary_bg.set_item(bn::regular_bg_items::s0104);
            } else if (strcmp(n[pos].text, "S01:05") == 0) {
                primary_bg.set_item(bn::regular_bg_items::s0105);
            } else if (strcmp(n[pos].text, "S01:06") == 0) {
                primary_bg.set_item(bn::regular_bg_items::s0106);
            } else if (strcmp(n[pos].text, "S01:07") == 0) {
                primary_bg.set_item(bn::regular_bg_items::s0107);
            } else if (strcmp(n[pos].text, "S01:08") == 0) {
                primary_bg.set_item(bn::regular_bg_items::s0108);
            } else if (strcmp(n[pos].text, "S01:09") == 0) {
                primary_bg.set_item(bn::regular_bg_items::s0109);
            } else if (strcmp(n[pos].text, "S01:10") == 0) {
                primary_bg.set_item(bn::regular_bg_items::castle01);
            } else if (strcmp(n[pos].text, "S01:11") == 0) {
                primary_bg.set_item(bn::regular_bg_items::castle02);
            } else if (strcmp(n[pos].text, "S01:12") == 0) {
                primary_bg.set_item(bn::regular_bg_items::castle03);

            } else if (strcmp(n[pos].text, "COM: Endscene") == 0) {
                cont = false;
                text_sprite01.clear();
                text_sprite02.clear();
                text_sprite03.clear();
                text_sprite04.clear();
                text_sprite05.clear();
                text_sprite06.clear();

            // Handle sprite/dialogue
            } else {

                if (n[pos].img != 0) {
                    if (n[pos].left) {
                        if (n[pos].transition || n[pos].img == -1) {
                            chari_l.set_visible(false);
                        }

                        if (!chari_l.visible() && n[pos].img != -1) {
                            chari_r.set_blending_enabled(false);
                            chari_l.set_blending_enabled(true);
                            bn::blending::set_transparency_alpha(0);
                            chari_l.set_x(-50);
                            chari_l.set_visible(true);
                        }

                        set_sprite(chari_l, n[pos].img);
                    } else {
                        if (n[pos].transition || n[pos].img == -1) {
                            chari_r.set_visible(false);
                        }

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

                bn::sound_items::pop.play(0.5);

                char line1[33], line2[33], line3[33], line4[33], line5[33], line6[33];
                char txt[198] = "                                                                                                                                                                                                     ";
                strcpy(txt, n[pos].text);
                strncpy(line1, txt + (33 * 0), 33);
                strncpy(line2, txt + (33 * 1), 33);
                strncpy(line3, txt + (33 * 2), 33);
                strncpy(line4, txt + (33 * 3), 33);
                strncpy(line5, txt + (33 * 4), 33);
                strncpy(line6, txt + (33 * 5), 33);

                text_sprite01.clear();
                text_line01.generate(-108, 22, line1, text_sprite01);

                text_sprite02.clear();
                text_line02.generate(-108, 32, line2, text_sprite02);

                text_sprite03.clear();
                text_line03.generate(-108, 42, line3, text_sprite03);

                text_sprite04.clear();
                text_line04.generate(-108, 52, line4, text_sprite04);

                text_sprite05.clear();
                text_line05.generate(-108, 62, line5, text_sprite05);

                text_sprite06.clear();
                text_line06.generate(-108, 72, line6, text_sprite06);

                bn::core::update();

                while(!bn::keypad::a_pressed()) {
                    if (chari_l.visible() && chari_l.x().integer() < -40) {
                        chari_l.set_x(chari_l.x() + 1);
                    }

                    if (chari_r.visible() && chari_r.x().integer() > 40) {
                        chari_r.set_x(chari_r.x() - 1);
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

    // Function to calculate the smallest multiple
    int closestMultiple(int n, int x)
    {  
        if(x>n)
        return x;
    
        n = n + x/2;
        n = n - (n%x);
        return n;
    };

    void exec_dialogue(int x) {
        bool fals = false;
        int n = -1;

        switch (x) {
            case 0: {
                    Concepts::line lc[32] = {
                        {fals, true, 0, "BG: 1"},
                        {fals, true, 0, "S01:01"},
                        {fals, true, 0, ""},
                        {fals, true, 0, "                                 4:15 AM                          January 1st, 2000                                                 Providence of Nord Louisiane,    La République Laurentides"},
                        {fals, true, 0, "S01:02"},
                        {fals, true, 0, "                                 AHHHHG.                          I've been driving for hours.     My right foot's asleep, and the  left one isn't too far behind.   Where is it???"},        
                        {fals, true, 0, "S01:03"},
                        {fals, true, 0, "Look at that gumbo.              It has to be cold by now.                                         I can't believe they wanted me   to bring the food."},
                        {fals, true, 0, "S01:04"},
                        {fals, true, 0, "Y'know....                                                        If I don't see that castle in    fifteen minutes, I might just    head back."},
                        {fals, true, 0, "                                 At least the drive was nice,     I guess."},
                        {fals, true, 0, "S01:05"},
                        {fals, true, 0, "Okay, I give up. There's no way  that I'm gonna-"},
                        {fals, true, 0, "S01:06"},
                        {fals, true, 0, "                                                                  .....Oh."},
                        {fals, true, 0, "                                                                  I.. can't decide if I'm relieved or disappointed."},
                        {fals, true, 0, "BG: fadeout"},
                        {fals, true, 0, "S01:07"},
                        {fals, true, 0, "*Knock*                          *knock*                          *knock*"},
                        {fals, true, 0, "S01:08"},
                        {fals, true, 0, "                                                                  I wonder if they can even hear   me in there... This place looks  huge."},
                        {fals, true, 0, "                                                                                                                                    '.....coming!'"},
                        {fals, true, 0, "S01:09"},
                        {fals, true, 0, "BG: 0"},
                        {fals, true, 0, "                                                                  Hey, Maple!!                     C'mon in!"},
                        {fals, true, 0, "COM: Endscene"}
                    };

                    dialogue_page(lc);
                    break;
            }
            case 1: {
                Concepts::line lc[32] = {
                        {true, true, 0, "BG: Ocean"},
                        {true, fals, 1, "MAPLE                                                             Alright, so where do I plug this crock-pot in at? Are there any   plugs?"},
                        {fals, fals, 1, "MAPLE                                                             I take it that I'm late enough   y'all probably already ate       something else."},
                        {fals, true, 9, "ENOKI                                                             Well, we've got an outhouse,     but that's the only place with   electricity. And yeah, we got    some chicken."},
                        {fals, true, 8, "ENOKI                                                             We missed you earlier :("},
                        {fals, fals, 5, "MAPLE                                                             Well I'm finally here, now. So,  where is- Oh! Salut, Aaron."},
                       {true, true, 10, "AARON                                                             Bonsour! Or Bonjour more like, I guess, it's technically morning, isn't it? I'm just glad you got  here. Happy new millenium!"},
                        {fals, fals, 3, "MAPLE                                                             Happy new millenium! Y'all reallyare in the middle of nowhere, youknow that?"},
                       {true, true, 12, "DEL                                                               Maple! You're here! Happy 2000!"},
                        {fals, fals, 5, "MAPLE                                                             Delphine Thibodeaux!             My goodness it's been... what, a year? Salut!"},
                       {fals, true, 13, "DEL                                                               Hey, girl! Glad you're here -    Don't worry, we've been waiting  to break out the wine and        eclairs until you showed up."},
                       {fals, true, 12, "DEL                                                               We're all boring adults, though, so no promises about how late we would have stayed up for you."},
                        {true, true, 7, "ENOKI                                                             So Maple, what have you been up  to lately? Have we even talked   since the wedding?? I missed my  best friend :("},
                        {fals, fals, 2, "MAPLE                                                             Surely your husband's been       keeping you busy, I suppose."},
                       {true, true, 10, "AARON                                                             Well, we're obviously living in acastle now, so that's been an    adventure."},
                        {true, true, 7, "ENOKI                                                             I am a princess."},
                        {fals, fals, 2, "MAPLE                                                             It takes a little more than just a castle to be a princess."},
                        {fals, true, 8, "ENOKI                                                             I'm a duchess?"},
                        {fals, fals, 4, "MAPLE                                                             I- uhm...                        Hmm...                           You know what?                   It's too late for this."},
                        {fals, fals, 2, "MAPLE                                                             Anyway, I've been alright, I've  only got one semester left, then I'll be a school teacher.  Then? I don't know."},
                       {true, true, 10, "AARON                                                             Still trying this teacher thing, huh? Even though you've told me  a million times you'd rather be  anything but a teacher?"},
                       {fals, true, 11, "AARON                                                             Are there no degrees for people  who can shoot fire out of their  hands?"},
                        {fals, fals, 4, "MAPLE                                                             ...None I want, at least."},
                       {fals, true, 10, "AARON                                                             Well, a teacher with fire magic  sounds pretty cool to me."},
                        {true, true, 8, "ENOKI                                                             *yawn*                           Goodness, I'm sleepy. Hey, how   about we all go to bed and catch up in the morning?"},
                        {fals, true, 7, "ENOKI                                                             Hey Maple, you wanna have like   a sleepover? Like we can pretend we're college roommates again?"},
                        {fals, fals, 2, "MAPLE                                                             I mean... Sure, I guess."},
                        {fals, true, n, "ENOKI                                                             Goodnight, Del!                  Hey, Aaron, see ya tomorrow?     Bright 'n early?"},
                        {fals, true, 0, "AARON                                                             Sure thing, Noke-noke.                                            *kiss*"},
                        {fals, fals, 3, "MAPLE                                                             I am never going to get used to  that."},
                        {true, true, 9, "ENOKI                                                             Alright, grab your bag and I'll  show you where we're staying.    Allons-y!"},
                        {true, true, 0, "COM: Endscene"}
                    };
                    dialogue_page(lc);
                break;
            };

            case 2: {
                Concepts::line lc[32] = {
                    {true, true, 0, "BG: fadeout"},
                    {true, true, 0, "S01:11"},
                    {true, true, 0, "MAPLE                                                             Wow.. It's sort of chilly in     here, isn't it?"},
                    {true, true, 0, "ENOKI                                                             Well silly, why'd ya wear a tank top and shorts in the middle of  December? Can't ya just light a  fire?"},
                    {true, true, 0, "BG: 2"},
                    {true, true, 0, "S01:10"},
                    {true, true, 0, "MAPLE                                                             So, how long are you two going tostay here? You can't just stay   thirty miles from civilization   without electricity forever."},
                    {true, true, 0, "S01:11"},
                    {true, true, 0, "ENOKI                                                             We're happy, so we think a long  time."},
                    {true, true, 0, "MAPLE                                                             I mean, what does Aaron think of all this? The Aaron I remember   growing up would be a little more...responsible."},
                    {true, true, 0, "ENOKI                                                             I don't wanna sound rude but...  Aren't you guys used to growing  up in places like, er, in a car?"},
                    {true, true, 0, "MAPLE                                                             Enoki, we all know you're rich,  no need to flaunt it."},
                    {true, true, 0, "ENOKI                                                             But didn't you literally grow up in a car? I mean, compared to    that, a castle is pretty nice,   right?"},
                    {true, true, 0, "MAPLE                                                             It just seems.. rash. I don't    meanto take the fun out of it,   but I can't help but think this  was a really, really bad idea."},
                    {true, true, 0, "ENOKI                                                             Coming from the girl who got     embarrased of her grades freshmanyear and decided to just up and  run away from college."},
                    {true, true, 0, "S01:10"},
                    {true, true, 0, "MAPLE                                                             Oh come on, that was your idea   first."},
                    {true, true, 0, "S01:11"},
                    {true, true, 0, "ENOKI                                                             Hey, I'll take it!! '97... Yeah, that was one of the best years   of my life, easy."},
                    {true, true, 0, "ENOKI                                                             So, after college, you got any   plans for where you wanna live?"},
                    {true, true, 0, "MAPLE                                                             I'll figure something out."},
                    {true, true, 0, "ENOKI                                                             Aaron and I were chatting and,   y'know, there's a school not too far off you could teach at,      maybe you could.. y'know.."},
                    {true, true, 0, "MAPLE                                                             Absolutely NOT. I'll make sure   to get myself a real adult       apartment."},
                    {true, true, 0, "MAPLE                                                             When you get tired of this place,maybe you can move in with me."},
                    {true, true, 0, "S01:12"},
                    {true, true, 0, "ENOKI                                                             The kinda things you choose to befunny about Maple, it'll never   cease to amaze me."},
                    {true, true, 0, "S01:11"},
                    {true, true, 0, "ENOKI                                                             Hey- I'm feeling down and that's stupid! You wanna go on another  Maple and Enoki adventure like   old times??"},
                    {true, true, 0, "ENOKI                                                             Let's go explore the castle!!"},
                    {true, true, 0, "MAPLE                                                             Hold up, you bought this castle  and hadn't explored it all first?"},
                    {true, true, 0, "ENOKI                                                             Well duh, I'm taking my sweet    time with it -- it's a castle!    C'mon, let's explore!"},
                    {true, true, 0, "COM: Endscene"}
                };
                dialogue_page(lc);
                break;
            };

            case 3: {
                Concepts::line lc[2] = {
                    {true, true, 0, "ENOKI                                                             Let's go for the room with the   big bookshelf! I'm sure there's  some secrets in there!"},
                    {true, true, 0, "COM: Endscene"}
                };
                dialogue_page(lc);
                break;
            };
        }
    }

    class stone {
        public:
            bn::sprite_ptr entity = bn::sprite_items::environment_stone.create_sprite(300,300,0);
            void set(int x, int y, const bn::sprite_item sprite, int loc = 0) {
                entity = sprite.create_sprite(x,y,loc);
                //entity.set_x(x);
                //entity.set_y(y);
            };
    };

    void dungeon(int world = 0) {

        // Variables for walking
        int dir = 0;
        int e_dir = 0;
        int last_dir = -1;
        int last_e_dir = -1;
        bool done = false;
        bool e_done = false;
        bool e_is_walking = false;
        char top_x[6];
        char bot_y[6];
        int loc;
        const int w_size = 112;
        stone local_walls[w_size];
        int local_walls_p = 0;
        int width = 0;
        int height = 0;
        int start_x = 4;
        int start_y = 2;
        int local_tileset[256];

        // Camera setup
        bn::camera_ptr camera = bn::camera_ptr::create(start_x * 32, start_y * 32);
        bn::regular_bg_ptr primary_bg = bn::regular_bg_items::castle_floor.create_bg(0, 0);
        primary_bg.set_camera(camera);

        // World generation
        switch(world)
            case 0: {
                width = 9;
                height = 5;
                int local[256] = {
                    3,2,2,2,7,2,2,2,4,
                    1,0,0,0,0,0,0,0,1,
                    1,0,0,0,0,0,0,0,1,
                    1,0,0,0,0,0,0,0,1,
                    6,2,2,2,0,2,2,2,5
                    };
                for (int t = 0; t < width * height; t++) {
                    local_tileset[t] = local[t];
                }
                break;
            };

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int loc = local_tileset[(y*width)+x];
                if (local_walls_p < w_size && loc > -1) {
                    local_walls[local_walls_p].set(x * 32, y * 32, bn::sprite_items::environment_stone, loc);
                    local_walls[local_walls_p].entity.set_camera(camera);
                    local_walls_p++;
                }
            }
        }

        // Set up Maple and Noke-Noke
        bn::sprite_item maple = bn::sprite_items::maple_walking;
        bn::sprite_builder builder(maple);
        builder.set_camera(camera);
        builder.set_position(start_x * 32, start_y * 32);
        bn::sprite_cached_animate_action maple_anim = bn::create_sprite_cached_animate_action_forever(builder.release_build(), 8, maple.tiles_item(), 0, 1, 0, 2);

        bn::sprite_item enoki = bn::sprite_items::enoki_walking_pj;
        bn::sprite_builder e_builder(enoki);
        e_builder.set_camera(camera);
        e_builder.set_position((start_x * 32) - 15, (start_y * 32) - 15);
        bn::sprite_cached_animate_action enoki_anim = bn::create_sprite_cached_animate_action_forever(e_builder.release_build(), 8, enoki.tiles_item(), 0, 1, 0, 2);

        bn::sprite_ptr maple_ptr = maple_anim.sprite();
        bn::sprite_ptr enoki_ptr = enoki_anim.sprite();
        maple_ptr.set_camera(camera);
        enoki_ptr.set_camera(camera);

        while(true) {

            //camera.set_x(camera.x() + 1);

            loc = (
                ((maple_ptr.x().round_integer() / 32) + 5) +
                (((maple_ptr.y().round_integer() / 32) + 1) * 8) + 5
            );

            e_done = true;
            e_is_walking = false;
            if (maple_ptr.y() > enoki_ptr.y() + 24) {
                enoki_ptr.set_y(enoki_ptr.y() + 1);
                e_dir = 0;
                if (last_e_dir != e_dir) e_done = false;
                last_e_dir = e_dir;
                e_is_walking = true;
            } else if (maple_ptr.y() < enoki_ptr.y() - 24) {
                enoki_ptr.set_y(enoki_ptr.y() - 1);
                e_dir = 3;
                if (last_e_dir != e_dir) e_done = false;
                last_e_dir = e_dir;
                e_is_walking = true;
            }

            if (maple_ptr.x() > enoki_ptr.x() + 24) {
                enoki_ptr.set_x(enoki_ptr.x() + 1);
                e_dir = 1;
                if (last_e_dir != e_dir) e_done = false;
                last_e_dir = e_dir;
                e_is_walking = true;
            } else if (maple_ptr.x() < enoki_ptr.x() - 24) {
                enoki_ptr.set_x(enoki_ptr.x() - 1);
                e_dir = 2;
                if (last_e_dir != e_dir) e_done = false;
                last_e_dir = e_dir;
                e_is_walking = true;
            }

            e_builder.set_x(enoki_ptr.x());
            e_builder.set_y(enoki_ptr.y());

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

            if (last_dir != dir) {
                done = false;
                last_dir = dir;
            }

            // Control directional animation
            if (!done) {
                switch(dir) {
                    case 0:
                        maple_anim = bn::create_sprite_cached_animate_action_forever(builder.release_build(), 8, maple.tiles_item(), 1, 0, 2, 0);
                        break;
                    case 1:
                        maple_anim = bn::create_sprite_cached_animate_action_forever(builder.release_build(), 8, maple.tiles_item(), 4, 3, 5, 3);
                        break;
                    case 2:
                        maple_anim = bn::create_sprite_cached_animate_action_forever(builder.release_build(), 8, maple.tiles_item(), 7, 6, 8, 6);
                        break;
                    case 3:
                        maple_anim = bn::create_sprite_cached_animate_action_forever(builder.release_build(), 8, maple.tiles_item(), 10, 9, 11, 9);
                        break;
                }
                done = true;
            }
            if (!e_done) {
                switch(e_dir) {
                    case 0:
                        enoki_anim = bn::create_sprite_cached_animate_action_forever(e_builder.release_build(), 8, enoki.tiles_item(), 1, 0, 2, 0);
                        break;
                    case 1:
                        enoki_anim = bn::create_sprite_cached_animate_action_forever(e_builder.release_build(), 8, enoki.tiles_item(), 4, 3, 5, 3);
                        break;
                    case 2:
                        enoki_anim = bn::create_sprite_cached_animate_action_forever(e_builder.release_build(), 8, enoki.tiles_item(), 7, 6, 8, 6);
                        break;
                    case 3:
                        enoki_anim = bn::create_sprite_cached_animate_action_forever(e_builder.release_build(), 8, enoki.tiles_item(), 10, 9, 11, 9);
                        break;
                }
            }
            maple_ptr = maple_anim.sprite();
            enoki_ptr = enoki_anim.sprite();
            maple_ptr.set_camera(camera);
            enoki_ptr.set_camera(camera);

            // Collision detection
            int x_int = maple_ptr.x().integer();
            int y_int = maple_ptr.y().integer();
            int close[4] {
                ((x_int + 6 + 31) & (-32)) / 32,
                (x_int - 6) / 32,
                ((y_int + 31) & (-32)) / 32,
                y_int / 32
            };
            int col[4] = {
                local_tileset[close[0] - 1 + (close[2] * width)] > 0,
                local_tileset[close[0] - 1 + (close[3] * width)] > 0,
                local_tileset[close[1] + 1 + (close[2] * width)] > 0,
                local_tileset[close[1] + 1 + (close[3] * width)] > 0
            };

            // Key controls
            if (bn::keypad::left_held()) {
                if (!col[0]) {
                    maple_ptr.set_x(maple_ptr.x() - 1);
                }
            }
            if (bn::keypad::right_held()) {
                if (!col[2]) {
                    maple_ptr.set_x(maple_ptr.x() + 1);
                }
            }
            if (bn::keypad::up_held()) {
                if (!col[1]) {
                    maple_ptr.set_y(maple_ptr.y() - 1);

                }
            }
            if (bn::keypad::down_held()) {
                if (!col[0]) {
                    maple_ptr.set_y(maple_ptr.y() + 1);
                }
            }

            // Animate appropriate people
            if ((bn::keypad::down_held() || bn::keypad::up_held() || bn::keypad::left_held() || bn::keypad::right_held()) || (maple_anim.current_index() % 2 == 1)) {
                maple_anim.update();
            }
            if (e_is_walking || (enoki_anim.current_index() % 2 == 1)) {
                enoki_anim.update();
            }

            builder.set_x(maple_ptr.x());
            builder.set_y(maple_ptr.y());

            // Z-Order followers
            if (maple_ptr.y() > enoki_ptr.y()) {
                maple_ptr.put_above();
            } else {
                enoki_ptr.put_above();
            }

            // Camera follows primary player
            if (camera.x() > maple_ptr.x() + 30) {
                camera.set_x(camera.x() - 1);
            } else if (camera.x() < maple_ptr.x() - 30) {
                camera.set_x(camera.x() + 1);
            }
            if (camera.y() > maple_ptr.y() + 30) {
                camera.set_y(camera.y() - 1);
            } else if (camera.y() < maple_ptr.y() - 30) {
                camera.set_y(camera.y() + 1);
            }
            
            bn::core::update();
        }
    }

}

int main()
{
    bn::core::init();
    //exec_dialogue(0);
    //exec_dialogue(1);
    //exec_dialogue(2);
    //bn::core::update();

    dungeon();
}