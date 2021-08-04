/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#ifndef BN_TIMER_H
#define BN_TIMER_H

/**
 * @file
 * bn::timer header file.
 *
 * @ingroup timer
 */

#include "bn_common.h"

namespace bn
{

/**
 * @brief Provides a way to calculate elapsed times.
 *
 * One timer tick is equivalent to 64 CPU clock cycles.
 *
 * @ingroup timer
 */
class timer
{

public:
    /**
     * @brief Constructor.
     */
    timer();

    /**
     * @brief Returns the number of ticks since this timer was built or restarted.
     */
    [[nodiscard]] int elapsed_ticks() const;

    /**
     * @brief Restarts the timer's internal state.
     *
     * Equivalent to:
     * @code{.cpp}
     * *this = timer();
     * @endcode
     */
    void restart();

private:
    unsigned _last_ticks;
};

}

#endif
