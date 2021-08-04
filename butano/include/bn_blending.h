/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#ifndef BN_BLENDING_H
#define BN_BLENDING_H

/**
 * @file
 * bn::blending header file.
 *
 * @ingroup blending
 */

#include "bn_fixed_fwd.h"

namespace bn
{
    class blending_fade_alpha;
    class blending_transparency_attributes;
}

/**
 * @brief Blending related functions.
 *
 * @ingroup blending
 */
namespace bn::blending
{
    /**
     * @brief Available fade colors.
     */
    enum class fade_color_type : uint8_t
    {
        BLACK, //!< Black fade color.
        WHITE //!< White fade color.
    };

    /**
     * @brief Returns the weight of the transparency blending,
     * with 0 being fully transparent and 1 being fully visible.
     */
    [[nodiscard]] fixed transparency_alpha();

    /**
     * @brief Sets the weight of the transparency blending,
     * with 0 being fully transparent and 1 being fully visible.
     *
     * Keep in mind that transparency and fade blendings can't be enabled at the same time.
     *
     * @param transparency_alpha Transparency weight in the range [0..1].
     */
    void set_transparency_alpha(fixed transparency_alpha);

    /**
     * @brief Returns the weight of the intensity blending, with 0 being disabled and 1 being fully applied.
     */
    [[nodiscard]] fixed intensity_alpha();

    /**
     * @brief Sets the weight of the intensity blending, with 0 being disabled and 1 being fully applied.
     *
     * Keep in mind that intensity and fade blendings can't be enabled at the same time.
     *
     * @param intensity_alpha Intensity weight in the range [0..1].
     */
    void set_intensity_alpha(fixed intensity_alpha);

    /**
     * @brief Returns the attributes to commit to the GBA transparency and intensity blending register.
     */
    [[nodiscard]] blending_transparency_attributes transparency_attributes();

    /**
     * @brief Sets the attributes to commit to the GBA transparency and intensity blending register.
     */
    void set_transparency_attributes(blending_transparency_attributes transparency_attributes);

    /**
     * @brief Returns the color used for fade blending.
     */
    [[nodiscard]] fade_color_type fade_color();

    /**
     * @brief Sets the color used for fade blending.
     */
    void set_fade_color(fade_color_type fade_color);

    /**
     * @brief Returns the weight of the fade blending, with 0 being disabled and 1 being fully applied.
     */
    [[nodiscard]] fixed fade_alpha();

    /**
     * @brief Sets the weight of the fade blending, with 0 being disabled and 1 being fully applied.
     *
     * Keep in mind that fade blending and other blendings can't be enabled at the same time.
     *
     * @param fade_alpha Fade weight in the range [0..1].
     */
    void set_fade_alpha(fixed fade_alpha);

    /**
     * @brief Sets the weight of the fade blending, with 0 being disabled and 1 being fully applied.
     *
     * Keep in mind that fade blending and other blendings can't be enabled at the same time.
     *
     * @param fade_alpha blending_fade_alpha to set.
     */
    void set_fade_alpha(blending_fade_alpha fade_alpha);
}

#endif
