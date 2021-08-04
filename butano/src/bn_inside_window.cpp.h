/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#include "bn_inside_window.h"

#include "bn_display_manager.h"

namespace bn
{

bool inside_window::visible() const
{
    return display_manager::inside_window_enabled(id());
}

void inside_window::set_visible(bool visible)
{
    return display_manager::set_inside_window_enabled(id(), visible);
}

}
