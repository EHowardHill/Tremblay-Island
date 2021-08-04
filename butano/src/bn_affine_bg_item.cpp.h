/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#include "bn_affine_bg_item.h"

#include "bn_fixed.h"
#include "bn_optional.h"
#include "bn_affine_bg_ptr.h"
#include "bn_affine_bg_map_ptr.h"

namespace bn
{

affine_bg_item affine_bg_item::uncompress(
            span<tile> uncompressed_tiles_ref, span<color> uncompressed_colors_ref,
            affine_bg_map_cell& uncompressed_cells_ref, const size& uncompressed_dimensions) const
{
    affine_bg_item result = *this;
    result._tiles_item = _tiles_item.uncompress(uncompressed_tiles_ref);
    result._palette_item = _palette_item.uncompress(uncompressed_colors_ref);
    result._map_item = _map_item.uncompress(uncompressed_cells_ref, uncompressed_dimensions);
    return result;
}

affine_bg_ptr affine_bg_item::create_bg(fixed x, fixed y) const
{
    return affine_bg_ptr::create(x, y, *this);
}

affine_bg_ptr affine_bg_item::create_bg(const fixed_point& position) const
{
    return affine_bg_ptr::create(position, *this);
}

optional<affine_bg_ptr> affine_bg_item::create_bg_optional(fixed x, fixed y) const
{
    return affine_bg_ptr::create_optional(x, y, *this);
}

optional<affine_bg_ptr> affine_bg_item::create_bg_optional(const fixed_point& position) const
{
    return affine_bg_ptr::create_optional(position, *this);
}

optional<affine_bg_map_ptr> affine_bg_item::find_map() const
{
    return affine_bg_map_ptr::find(*this);
}

affine_bg_map_ptr affine_bg_item::create_map() const
{
    return affine_bg_map_ptr::create(*this);
}

affine_bg_map_ptr affine_bg_item::create_new_map() const
{
    return affine_bg_map_ptr::create_new(*this);
}

optional<affine_bg_map_ptr> affine_bg_item::create_map_optional() const
{
    return affine_bg_map_ptr::create_optional(*this);
}

optional<affine_bg_map_ptr> affine_bg_item::create_new_map_optional() const
{
    return affine_bg_map_ptr::create_new_optional(*this);
}

}
