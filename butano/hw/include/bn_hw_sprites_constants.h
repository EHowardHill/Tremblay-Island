/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#ifndef BN_HW_SPRITES_CONSTANTS_H
#define BN_HW_SPRITES_CONSTANTS_H

#include "bn_common.h"

namespace bn::hw::sprites
{
    [[nodiscard]] constexpr int count()
    {
        return 128;
    }

    [[nodiscard]] constexpr int min_bg_priority()
    {
        return 0;
    }

    [[nodiscard]] constexpr int max_bg_priority()
    {
        return 3;
    }
}

#endif
