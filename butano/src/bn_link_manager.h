/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#ifndef BN_LINK_MANAGER_H
#define BN_LINK_MANAGER_H

#include "bn_optional_fwd.h"

namespace bn
{
    class link_state;
}

namespace bn::link_manager
{
    void init();

    void send(int data_to_send);

    [[nodiscard]] optional<link_state> receive();

    void deactivate();

    void enable();

    void disable();

    void commit();
}

#endif
