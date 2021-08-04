/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#ifndef BN_BG_PALETTES_TRANSPARENT_COLOR_HBE_HANDLER_H
#define BN_BG_PALETTES_TRANSPARENT_COLOR_HBE_HANDLER_H

#include "bn_any_fwd.h"
#include "bn_palettes_bank.h"
#include "bn_palettes_manager.h"
#include "../hw/include/bn_hw_palettes.h"

namespace bn
{

class bg_palettes_transparent_color_hbe_handler
{

public:
    static void setup_target(intptr_t, iany&)
    {
    }

    [[nodiscard]] static bool target_visible(intptr_t)
    {
        return true;
    }

    [[nodiscard]] static bool target_updated(intptr_t, iany&)
    {
        if(optional<palettes_bank::commit_data> commit_data =
                palettes_manager::bg_palettes_bank().retrieve_commit_data())
        {
            return commit_data->offset == 0;
        }

        return false;
    }

    [[nodiscard]] static uint16_t* output_register(intptr_t)
    {
        return hw::palettes::bg_transparent_color_register();
    }

    static void write_output_values(intptr_t, const iany&, const void* input_values_ptr, uint16_t* output_values_ptr)
    {
        palettes_manager::bg_palettes_bank().fill_hblank_effect_colors(
                    reinterpret_cast<const color*>(input_values_ptr), output_values_ptr);
    }

    static void show(intptr_t)
    {
    }

    static void cleanup(intptr_t)
    {
        palettes_manager::bg_palettes_bank().reload(0);
    }
};

}

#endif
