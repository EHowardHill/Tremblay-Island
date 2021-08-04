/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#ifndef BN_DISPLAY_H
#define BN_DISPLAY_H

/**
 * @file
 * bn::display header file.
 *
 * @ingroup display
 */

#include "../hw/include/bn_hw_display_constants.h"

/**
 * @brief Display related functions.
 *
 * @ingroup display
 */
namespace bn::display
{
    /**
     * @brief Returns the screen width in pixels (240).
     */
    [[nodiscard]] constexpr int width()
    {
        return hw::display::width();
    }

    /**
     * @brief Returns the screen height in pixels (160).
     */
    [[nodiscard]] constexpr int height()
    {
        return hw::display::height();
    }
}

#endif
