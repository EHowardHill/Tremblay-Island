/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#include "bn_window.h"

#include "bn_affine_bg_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_display_manager.h"

namespace bn
{

bool window::show_bg(const regular_bg_ptr& regular_bg) const
{
    auto bg_handle = const_cast<void*>(regular_bg.handle());
    return display_manager::show_bg_in_window(_id, bg_handle);
}

bool window::show_bg(const affine_bg_ptr& affine_bg) const
{
    auto bg_handle = const_cast<void*>(affine_bg.handle());
    return display_manager::show_bg_in_window(_id, bg_handle);
}

void window::set_show_bg(const regular_bg_ptr& regular_bg, bool show)
{
    auto bg_handle = const_cast<void*>(regular_bg.handle());
    display_manager::set_show_bg_in_window(_id, bg_handle, show);
}

void window::set_show_bg(const affine_bg_ptr& affine_bg, bool show)
{
    auto bg_handle = const_cast<void*>(affine_bg.handle());
    display_manager::set_show_bg_in_window(_id, bg_handle, show);
}

bool window::show_sprites() const
{
    return display_manager::show_sprites_in_window(_id);
}

void window::set_show_sprites(bool show)
{
    display_manager::set_show_sprites_in_window(_id, show);
}

bool window::show_blending() const
{
    return display_manager::show_blending_in_window(_id);
}

void window::set_show_blending(bool show)
{
    display_manager::set_show_blending_in_window(_id, show);
}

bool window::show_all() const
{
    return display_manager::show_all_in_window(_id);
}

void window::set_show_all()
{
    display_manager::set_show_all_in_window(_id);
}

bool window::show_nothing() const
{
    return display_manager::show_nothing_in_window(_id);
}

void window::set_show_nothing()
{
    display_manager::set_show_nothing_in_window(_id);
}

}
