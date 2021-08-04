/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#ifndef BN_AFFINE_BG_ITEM_H
#define BN_AFFINE_BG_ITEM_H

/**
 * @file
 * bn::affine_bg_item header file.
 *
 * @ingroup affine_bg
 * @ingroup tool
 */

#include "bn_fixed_fwd.h"
#include "bn_bg_palette_item.h"
#include "bn_affine_bg_map_item.h"
#include "bn_affine_bg_tiles_item.h"

namespace bn
{

class fixed_point;
class affine_bg_ptr;

/**
 * @brief Contains the required information to generate affine backgrounds and their maps.
 *
 * The assets conversion tools generate an object of this type in the build folder for each *.bmp file
 * with `affine_bg` type.
 *
 * Tiles, colors and map cells are not copied but referenced,
 * so they should outlive the affine_bg_item to avoid dangling references.
 *
 * @ingroup affine_bg
 * @ingroup tool
 */
class affine_bg_item
{

public:
    /**
     * @brief Constructor.
     * @param tiles_ref Reference to affine background tiles.
     *
     * The tiles are not copied but referenced,
     * so they should outlive the affine_bg_item to avoid dangling references.
     *
     * @param colors_ref Reference to an array of multiples of 16 colors.
     *
     * The colors are not copied but referenced,
     * so they should outlive the affine_bg_item to avoid dangling references.
     *
     * @param map_cells_ref affine background map cells to reference.
     *
     * The map cells are not copied but referenced,
     * so they should outlive the affine_bg_item to avoid dangling references.
     *
     * @param map_dimensions Size in map cells of the referenced map cells.
     */
    constexpr affine_bg_item(const span<const tile>& tiles_ref, const span<const color>& colors_ref,
                             const affine_bg_map_cell& map_cells_ref, const size& map_dimensions) :
        _tiles_item(tiles_ref),
        _palette_item(colors_ref, bpp_mode::BPP_8),
        _map_item(map_cells_ref, map_dimensions)
    {
    }

    /**
     * @brief Constructor.
     * @param tiles_item It creates the tiles of the output affine backgrounds.
     * @param palette_item It creates the color palette of the output affine backgrounds.
     * @param map_item It creates the map of the output affine backgrounds.
     */
    constexpr affine_bg_item(const affine_bg_tiles_item& tiles_item, const bg_palette_item& palette_item,
                             const affine_bg_map_item& map_item) :
        _tiles_item(tiles_item),
        _palette_item(palette_item),
        _map_item(map_item)
    {
        BN_ASSERT(palette_item.bpp() == bpp_mode::BPP_8, "BPP_4 palettes are not supported");
    }

    /**
     * @brief Returns the item used to create the tiles of the output affine backgrounds.
     */
    [[nodiscard]] constexpr const affine_bg_tiles_item& tiles_item() const
    {
        return _tiles_item;
    }

    /**
     * @brief Returns the item used to create the color palette of the output affine backgrounds.
     */
    [[nodiscard]] constexpr const bg_palette_item& palette_item() const
    {
        return _palette_item;
    }

    /**
     * @brief Returns the item used to create the map of the output affine backgrounds.
     */
    [[nodiscard]] constexpr const affine_bg_map_item& map_item() const
    {
        return _map_item;
    }

    /**
     * @brief Indicates if backgrounds generated with this item are big or not.
     *
     * Big backgrounds are slower CPU wise and don't support wrapping
     * (they can't be moved beyond their boundaries), but can have any width or height multiple of 256 pixels.
     */
    [[nodiscard]] constexpr bool big() const
    {
        return _map_item.big();
    }

    /**
     * @brief Uncompresses the stored data in the tiles referenced by uncompressed_tiles_ref,
     * the colors referenced by uncompressed_colors_ref and the map cells referenced by uncompressed_cells_ref.
     *
     * If the source and destination tiles, colors or map cells overlap, the behavior is undefined.
     *
     * @param uncompressed_tiles_ref Destination of the uncompressed tiles.
     * @param uncompressed_colors_ref Destination of the uncompressed colors.
     * @param uncompressed_cells_ref Destination of the uncompressed map cells.
     * @param uncompressed_dimensions Size in map cells of the destination data.
     * @return An affine_bg_item pointing to the uncompressed tiles, colors and map cells.
     */
    [[nodiscard]] affine_bg_item uncompress(
            span<tile> uncompressed_tiles_ref, span<color> uncompressed_colors_ref,
            affine_bg_map_cell& uncompressed_cells_ref, const size& uncompressed_dimensions) const;

    /**
     * @brief Creates an affine_bg_ptr using the information contained in this item.
     * @param x Horizontal position of the affine background.
     * @param y Vertical position of the affine background.
     * @return The requested affine_bg_ptr.
     */
    [[nodiscard]] affine_bg_ptr create_bg(fixed x, fixed y) const;

    /**
     * @brief Creates an affine_bg_ptr using the information contained in this item.
     * @param position Position of the affine background.
     * @return The requested affine_bg_ptr.
     */
    [[nodiscard]] affine_bg_ptr create_bg(const fixed_point& position) const;

    /**
     * @brief Creates an affine_bg_ptr using the information contained in this item.
     * @param x Horizontal position of the affine background.
     * @param y Vertical position of the affine background.
     * @return The requested affine_bg_ptr if it could be allocated; bn::nullopt otherwise.
     */
    [[nodiscard]] optional<affine_bg_ptr> create_bg_optional(fixed x, fixed y) const;

    /**
     * @brief Creates an affine_bg_ptr using the information contained in this item.
     * @param position Position of the affine background.
     * @return The requested affine_bg_ptr if it could be allocated; bn::nullopt otherwise.
     */
    [[nodiscard]] optional<affine_bg_ptr> create_bg_optional(const fixed_point& position) const;

    /**
     * @brief Searches for an affine_bg_map_ptr which references the information provided by this item.
     * @return affine_bg_map_ptr which references the information provided by this item if it has been found;
     * bn::nullopt otherwise.
     */
    [[nodiscard]] optional<affine_bg_map_ptr> find_map() const;

    /**
     * @brief Searches for an affine_bg_map_ptr which references the information provided by this item.
     * If it is not found, it creates an affine_bg_map_ptr which references it.
     *
     * The map cells are not copied but referenced,
     * so they should outlive the affine_bg_map_ptr to avoid dangling references.
     *
     * @return affine_bg_map_ptr which references the information provided by this item if it has been found;
     * otherwise it returns an affine_bg_map_ptr which references it.
     */
    [[nodiscard]] affine_bg_map_ptr create_map() const;

    /**
     * @brief Creates an affine_bg_map_ptr which references the information provided by this item.
     *
     * The map system does not support multiple affine_bg_map_ptr items referencing to the same map cells.
     * If you are not sure if the information provided by this item is already referenced or not,
     * you should use the create_map method instead.
     *
     * The map cells are not copied but referenced,
     * so they should outlive the affine_bg_map_ptr to avoid dangling references.
     *
     * @return affine_bg_map_ptr which references the information provided by this item.
     */
    [[nodiscard]] affine_bg_map_ptr create_new_map() const;

    /**
     * @brief Searches for an affine_bg_map_ptr which references the information provided by this item.
     * If it is not found, it creates an affine_bg_map_ptr which references it.
     *
     * The map cells are not copied but referenced,
     * so they should outlive the affine_bg_map_ptr to avoid dangling references.
     *
     * @return affine_bg_map_ptr which references the information provided by this item if it has been found;
     * otherwise it returns an affine_bg_map_ptr which references it if it could be allocated;
     * bn::nullopt otherwise.
     */
    [[nodiscard]] optional<affine_bg_map_ptr> create_map_optional() const;

    /**
     * @brief Creates an affine_bg_map_ptr which references the information provided by this item.
     *
     * The map system does not support multiple affine_bg_map_ptr items referencing to the same map cells.
     * If you are not sure if the information provided by this item is already referenced or not,
     * you should use the create_map_optional method instead.
     *
     * The map cells are not copied but referenced,
     * so they should outlive the affine_bg_map_ptr to avoid dangling references.
     *
     * @return affine_bg_map_ptr which references the information provided by this item
     * if the affine_bg_map_ptr can be allocated; bn::nullopt otherwise.
     */
    [[nodiscard]] optional<affine_bg_map_ptr> create_new_map_optional() const;

    /**
     * @brief Default equal operator.
     */
    [[nodiscard]] constexpr friend bool operator==(const affine_bg_item& a, const affine_bg_item& b) = default;

private:
    affine_bg_tiles_item _tiles_item;
    bg_palette_item _palette_item;
    affine_bg_map_item _map_item;
};

}

#endif

