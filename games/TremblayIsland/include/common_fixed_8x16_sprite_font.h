/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#ifndef COMMON_FIXED_8x16_SPRITE_FONT_H
#define COMMON_FIXED_8x16_SPRITE_FONT_H

#include "bn_sprite_font.h"
#include "bn_sprite_items_common_fixed_8x16_font.h"

namespace common
{

constexpr bn::string_view fixed_8x16_sprite_font_utf8_characters[] = {
    "Á", "É", "Í", "Ó", "Ú", "Ü", "Ñ", "á", "é", "í", "ó", "ú", "ü", "ñ", "¡", "¿"
};

constexpr bn::sprite_font fixed_8x16_sprite_font(
        bn::sprite_items::common_fixed_8x16_font, fixed_8x16_sprite_font_utf8_characters);

}

#endif
