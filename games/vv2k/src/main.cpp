#include <string.h>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <list>

#include "bn_core.h"
#include "bn_log.h"

#include "bn_music.h"
#include "bn_keypad.h"
#include "bn_display.h"

#include "bn_sound_items.h"
#include "bn_music_items_info.h"

#include "common_info.h"

#include "objects.h"
#include "save.h"
#include "dialogue.h"
#include "scripts.h"
#include "wander.h"

int main()
{
    bn::core::init();
    //exec_dialogue(0);
    //exec_dialogue(1);
    //exec_dialogue(2);

    dungeon_return dt(0,0,0);
    dt.spawn_x = 0;
    dt.spawn_y = 0;
    dt.world_index = 0;
    while(true) {
        dungeon_return dt = dungeon(dt);
    }
}