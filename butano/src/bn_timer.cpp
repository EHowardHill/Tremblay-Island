/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#include "bn_timer.h"

#include "bn_limits.h"
#include "../hw/include/bn_hw_timer.h"

namespace bn
{

timer::timer() :
    _last_ticks(hw::timer::ticks())
{
}

int timer::elapsed_ticks() const
{
    unsigned ticks = hw::timer::ticks();

    if(ticks < _last_ticks) [[unlikely]]
    {
        uint64_t overflow_result = ticks;
        overflow_result += numeric_limits<unsigned>::max();
        overflow_result -= _last_ticks;
        return int(overflow_result);
    }

    return int(ticks - _last_ticks);
}

void timer::restart()
{
    _last_ticks = hw::timer::ticks();
}

}
