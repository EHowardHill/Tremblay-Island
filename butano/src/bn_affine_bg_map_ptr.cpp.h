/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#include "bn_affine_bg_map_ptr.h"

#include "bn_optional.h"
#include "bn_bg_palette_ptr.h"
#include "bn_affine_bg_item.h"
#include "bn_bg_blocks_manager.h"
#include "bn_affine_bg_tiles_ptr.h"

namespace bn
{

optional<affine_bg_map_ptr> affine_bg_map_ptr::find(
        const affine_bg_map_item& map_item, const affine_bg_tiles_ptr& tiles, const bg_palette_ptr& palette)
{
    int handle = bg_blocks_manager::find_affine_map(map_item, tiles, palette);
    optional<affine_bg_map_ptr> result;

    if(handle >= 0)
    {
        result = affine_bg_map_ptr(handle);
    }

    return result;
}

optional<affine_bg_map_ptr> affine_bg_map_ptr::find(const affine_bg_item& item)
{
    optional<affine_bg_map_ptr> result;

    if(optional<affine_bg_tiles_ptr> tiles = affine_bg_tiles_ptr::find(item.tiles_item()))
    {
        if(optional<bg_palette_ptr> palette = bg_palette_ptr::find(item.palette_item()))
        {
            result = find(item.map_item(), *tiles, *palette);
        }
    }

    return result;
}

affine_bg_map_ptr affine_bg_map_ptr::create(
        const affine_bg_map_item& map_item, affine_bg_tiles_ptr tiles, bg_palette_ptr palette)
{
    int handle = bg_blocks_manager::create_affine_map(map_item, move(tiles), move(palette), false);
    return affine_bg_map_ptr(handle);
}

affine_bg_map_ptr affine_bg_map_ptr::create(const affine_bg_item& item)
{
    int handle = bg_blocks_manager::create_affine_map(
                item.map_item(), item.tiles_item().create_tiles(), item.palette_item().create_palette(), false);
    return affine_bg_map_ptr(handle);
}

affine_bg_map_ptr affine_bg_map_ptr::create_new(
        const affine_bg_map_item& map_item, affine_bg_tiles_ptr tiles, bg_palette_ptr palette)
{
    int handle = bg_blocks_manager::create_new_affine_map(map_item, move(tiles), move(palette), false);
    return affine_bg_map_ptr(handle);
}

affine_bg_map_ptr affine_bg_map_ptr::create_new(const affine_bg_item& item)
{
    const affine_bg_map_item& map_item = item.map_item();
    int handle = bg_blocks_manager::create_new_affine_map(map_item, item.tiles_item().create_tiles(),
                                                          item.palette_item().create_palette(), false);
    return affine_bg_map_ptr(handle);
}

affine_bg_map_ptr affine_bg_map_ptr::allocate(
        const size& dimensions, affine_bg_tiles_ptr tiles, bg_palette_ptr palette)
{
    int handle = bg_blocks_manager::allocate_affine_map(dimensions, move(tiles), move(palette), false);
    return affine_bg_map_ptr(handle);
}

optional<affine_bg_map_ptr> affine_bg_map_ptr::create_optional(
        const affine_bg_map_item& map_item, affine_bg_tiles_ptr tiles, bg_palette_ptr palette)
{
    int handle = bg_blocks_manager::create_affine_map(map_item, move(tiles), move(palette), true);
    optional<affine_bg_map_ptr> result;

    if(handle >= 0)
    {
        result = affine_bg_map_ptr(handle);
    }

    return result;
}

optional<affine_bg_map_ptr> affine_bg_map_ptr::create_optional(const affine_bg_item& item)
{
    optional<affine_bg_map_ptr> result;

    if(optional<affine_bg_tiles_ptr> tiles = item.tiles_item().create_tiles_optional())
    {
        if(optional<bg_palette_ptr> palette = item.palette_item().create_palette_optional())
        {
            int handle = bg_blocks_manager::create_affine_map(item.map_item(), move(*tiles), move(*palette), true);

            if(handle >= 0)
            {
                result = affine_bg_map_ptr(handle);
            }
        }
    }

    return result;
}

optional<affine_bg_map_ptr> affine_bg_map_ptr::create_new_optional(
        const affine_bg_map_item& map_item, affine_bg_tiles_ptr tiles, bg_palette_ptr palette)
{
    int handle = bg_blocks_manager::create_new_affine_map(map_item, move(tiles), move(palette), true);
    optional<affine_bg_map_ptr> result;

    if(handle >= 0)
    {
        result = affine_bg_map_ptr(handle);
    }

    return result;
}

optional<affine_bg_map_ptr> affine_bg_map_ptr::create_new_optional(const affine_bg_item& item)
{
    optional<affine_bg_map_ptr> result;

    if(optional<affine_bg_tiles_ptr> tiles = item.tiles_item().create_tiles_optional())
    {
        if(optional<bg_palette_ptr> palette = item.palette_item().create_palette_optional())
        {
            int handle = bg_blocks_manager::create_new_affine_map(item.map_item(), move(*tiles), move(*palette), true);

            if(handle >= 0)
            {
                result = affine_bg_map_ptr(handle);
            }
        }
    }

    return result;
}

optional<affine_bg_map_ptr> affine_bg_map_ptr::allocate_optional(
        const size& dimensions, affine_bg_tiles_ptr tiles, bg_palette_ptr palette)
{
    int handle = bg_blocks_manager::allocate_affine_map(dimensions, move(tiles), move(palette), true);
    optional<affine_bg_map_ptr> result;

    if(handle >= 0)
    {
        result = affine_bg_map_ptr(handle);
    }

    return result;
}

affine_bg_map_ptr::affine_bg_map_ptr(const affine_bg_map_ptr& other) :
    affine_bg_map_ptr(other._handle)
{
    bg_blocks_manager::increase_usages(_handle);
}

affine_bg_map_ptr& affine_bg_map_ptr::operator=(const affine_bg_map_ptr& other)
{
    if(_handle != other._handle)
    {
        if(_handle >= 0)
        {
            bg_blocks_manager::decrease_usages(_handle);
        }

        _handle = other._handle;
        bg_blocks_manager::increase_usages(_handle);
    }

    return *this;
}

int affine_bg_map_ptr::id() const
{
    return bg_blocks_manager::hw_id(_handle);
}

size affine_bg_map_ptr::dimensions() const
{
    return bg_blocks_manager::map_dimensions(_handle);
}

bool affine_bg_map_ptr::big() const
{
    return bg_blocks_manager::affine_big_map(_handle);
}

int affine_bg_map_ptr::tiles_offset() const
{
    return bg_blocks_manager::affine_tiles_offset(_handle);
}

compression_type affine_bg_map_ptr::compression() const
{
    return bg_blocks_manager::compression(_handle);
}

optional<span<const affine_bg_map_cell>> affine_bg_map_ptr::cells_ref() const
{
    return bg_blocks_manager::affine_map_cells_ref(_handle);
}

void affine_bg_map_ptr::set_cells_ref(const affine_bg_map_item& map_item)
{
    bg_blocks_manager::set_affine_map_cells_ref(_handle, map_item);
}

void affine_bg_map_ptr::reload_cells_ref()
{
    bg_blocks_manager::reload(_handle);
}

const affine_bg_tiles_ptr& affine_bg_map_ptr::tiles() const
{
    return bg_blocks_manager::affine_map_tiles(_handle);
}

void affine_bg_map_ptr::set_tiles(const affine_bg_tiles_ptr& tiles)
{
    bg_blocks_manager::set_affine_map_tiles(_handle, affine_bg_tiles_ptr(tiles));
}

void affine_bg_map_ptr::set_tiles(affine_bg_tiles_ptr&& tiles)
{
    bg_blocks_manager::set_affine_map_tiles(_handle, move(tiles));
}

void affine_bg_map_ptr::set_tiles(const affine_bg_tiles_item& tiles_item)
{
    if(optional<affine_bg_tiles_ptr> tiles = tiles_item.find_tiles())
    {
        bg_blocks_manager::set_affine_map_tiles(_handle, move(*tiles));
    }
    else
    {
        bg_blocks_manager::remove_affine_map_tiles(_handle);
        bg_blocks_manager::set_affine_map_tiles(_handle, tiles_item.create_new_tiles());
    }
}

const bg_palette_ptr& affine_bg_map_ptr::palette() const
{
    return bg_blocks_manager::map_palette(_handle);
}

void affine_bg_map_ptr::set_palette(const bg_palette_ptr& palette)
{
    bg_blocks_manager::set_affine_map_palette(_handle, bg_palette_ptr(palette));
}

void affine_bg_map_ptr::set_palette(bg_palette_ptr&& palette)
{
    bg_blocks_manager::set_affine_map_palette(_handle, move(palette));
}

void affine_bg_map_ptr::set_palette(const bg_palette_item& palette_item)
{
    bg_blocks_manager::set_affine_map_palette(_handle, palette_item.create_palette());
}

optional<span<affine_bg_map_cell>> affine_bg_map_ptr::vram()
{
    return bg_blocks_manager::affine_map_vram(_handle);
}

void affine_bg_map_ptr::_destroy()
{
    bg_blocks_manager::decrease_usages(_handle);
}

}
