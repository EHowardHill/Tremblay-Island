/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#ifndef BN_HDMA_MANAGER_H
#define BN_HDMA_MANAGER_H

#include "bn_common.h"

namespace bn::hdma_manager
{
    void enable();

    void disable();

    void force_stop();

    [[nodiscard]] bool low_priority_running();

    void low_priority_start(const uint16_t& source_ref, int elements, uint16_t& destination_ref);

    void low_priority_stop();

    [[nodiscard]] bool high_priority_running();

    void high_priority_start(const uint16_t& source_ref, int elements, uint16_t& destination_ref);

    void high_priority_stop();

    void update();

    void commit();
}

#endif
