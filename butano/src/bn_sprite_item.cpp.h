/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#include "bn_sprite_item.h"

#include "bn_fixed.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed_point.h"

namespace bn
{

sprite_item sprite_item::uncompress(span<tile> uncompressed_tiles_ref, span<color> uncompressed_colors_ref) const
{
    sprite_item result = *this;
    result._tiles_item = _tiles_item.uncompress(uncompressed_tiles_ref);
    result._palette_item = _palette_item.uncompress(uncompressed_colors_ref);
    return result;
}

sprite_ptr sprite_item::create_sprite(fixed x, fixed y) const
{
    return sprite_ptr::create(x, y, *this);
}

sprite_ptr sprite_item::create_sprite(fixed x, fixed y, int graphics_index) const
{
    return sprite_ptr::create(x, y, *this, graphics_index);
}

sprite_ptr sprite_item::create_sprite(const fixed_point& position) const
{
    return sprite_ptr::create(position, *this);
}

sprite_ptr sprite_item::create_sprite(const fixed_point& position, int graphics_index) const
{
    return sprite_ptr::create(position, *this, graphics_index);
}

optional<sprite_ptr> sprite_item::create_sprite_optional(fixed x, fixed y) const
{
    return sprite_ptr::create_optional(x, y, *this);
}

optional<sprite_ptr> sprite_item::create_sprite_optional(fixed x, fixed y, int graphics_index) const
{
    return sprite_ptr::create_optional(x, y, *this, graphics_index);
}

optional<sprite_ptr> sprite_item::create_sprite_optional(const fixed_point& position) const
{
    return sprite_ptr::create_optional(position, *this);
}

optional<sprite_ptr> sprite_item::create_sprite_optional(const fixed_point& position, int graphics_index) const
{
    return sprite_ptr::create_optional(position, *this, graphics_index);
}

}
