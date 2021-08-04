/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#include "bn_sprite_palette_item.h"

#include "bn_optional.h"
#include "bn_sprite_palette_ptr.h"
#include "../hw/include/bn_hw_uncompress.h"

namespace bn
{

sprite_palette_item sprite_palette_item::uncompress(span<color> uncompressed_colors_ref) const
{
    int source_colors_count = _colors_ref.size();
    BN_ASSERT(uncompressed_colors_ref.size() >= source_colors_count,
              "There's not enough space to store the uncompressed data: ",
              uncompressed_colors_ref.size(), " - ", source_colors_count);

    color* dest_colors_ptr = uncompressed_colors_ref.data();
    BN_ASSERT(aligned<alignof(int)>(dest_colors_ptr), "Destination colors are not aligned");

    sprite_palette_item result = *this;

    switch(_compression)
    {

    case compression_type::NONE:
        break;

    case compression_type::LZ77:
        hw::uncompress::lz77_wram(_colors_ref.data(), dest_colors_ptr);
        result._colors_ref = span<const color>(dest_colors_ptr, source_colors_count);
        result._compression = compression_type::NONE;
        break;

    case compression_type::RUN_LENGTH:
        hw::uncompress::rl_wram(_colors_ref.data(), dest_colors_ptr);
        result._colors_ref = span<const color>(dest_colors_ptr, source_colors_count);
        result._compression = compression_type::NONE;
        break;

    default:
        BN_ERROR("Unknown compression type: ", int(_compression));
        break;
    }

    return result;
}

optional<sprite_palette_ptr> sprite_palette_item::find_palette() const
{
    return sprite_palette_ptr::find(*this);
}

sprite_palette_ptr sprite_palette_item::create_palette() const
{
    return sprite_palette_ptr::create(*this);
}

sprite_palette_ptr sprite_palette_item::create_new_palette() const
{
    return sprite_palette_ptr::create_new(*this);
}

optional<sprite_palette_ptr> sprite_palette_item::create_palette_optional() const
{
    return sprite_palette_ptr::create_optional(*this);
}

optional<sprite_palette_ptr> sprite_palette_item::create_new_palette_optional() const
{
    return sprite_palette_ptr::create_new_optional(*this);
}

}
