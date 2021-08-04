/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#ifndef BN_MATH_H
#define BN_MATH_H

/**
 * @file
 * Math functions header file.
 *
 * @ingroup math
 */

#include "bn_array.h"
#include "bn_fixed.h"
#include "bn_sin_lut.h"
#include "bn_reciprocal_lut.h"
#include "bn_rule_of_three_approximation.h"

/// @cond DO_NOT_DOCUMENT

namespace _bn
{
    template<typename Type>
    [[nodiscard]] constexpr Type newton_raphson_sqrt_impl(Type value, Type current_result, Type previous_result)
    {
        while(current_result != previous_result)
        {
            Type new_result = (current_result + (value / current_result)) / 2;
            previous_result = current_result;
            current_result = new_result;
        }

        return current_result;
    }

    template<>
    [[nodiscard]] constexpr bn::fixed newton_raphson_sqrt_impl(bn::fixed value, bn::fixed current_result,
                                                               bn::fixed previous_result)
    {
        while(current_result != previous_result)
        {
            bn::fixed new_result = (current_result + (value.safe_division(current_result))) / 2;
            previous_result = current_result;
            current_result = new_result;
        }

        return current_result;
    }

    [[nodiscard]] int sqrt_impl(int value);
}

/// @endcond


namespace bn
{
    /**
     * @brief Returns the absolute value of the given value.
     *
     * @ingroup math
     */
    template<typename Type>
    [[nodiscard]] constexpr Type abs(Type value)
    {
        return (value >= 0) ? value : -value;
    }

    /**
     * @brief Returns the absolute value of the given value.
     *
     * @ingroup math
     */
    template<typename Type>
    [[nodiscard]] constexpr Type abs(Type value)
    requires(is_unsigned_v<Type>)
    {
        return value;
    }

    /**
     * @brief Returns the integer square root of the given value.
     *
     * @ingroup math
     */
    [[nodiscard]] constexpr int sqrt(int value)
    {
        BN_ASSERT(value >= 0, "Invalid value: ", value);

        if(is_constant_evaluated())
        {
            return _bn::newton_raphson_sqrt_impl(value, value, 0);
        }
        else
        {
            return _bn::sqrt_impl(value);
        }
    }

    /**
     * @brief Returns the fixed point square root of the given value.
     *
     * See https://github.com/JoaoBaptMG/gba-modern/blob/master/source/math/fixedmath.hpp
     *
     * @ingroup math
     */
    template<int Precision>
    [[nodiscard]] constexpr fixed_t<(Precision + 1) / 2> sqrt(fixed_t<Precision> value)
    {
        if constexpr(Precision % 2)
        {
            return fixed_t<(Precision + 1) / 2>::from_data(sqrt(value.data() << 1));
        }
        else
        {
            return fixed_t<(Precision + 1) / 2>::from_data(sqrt(value.data()));
        }
    }

    /**
     * @brief Returns the square root of the given value using the Newton–Raphson method.
     *
     * See https://en.wikipedia.org/wiki/Newton%27s_method#Square_root
     *
     * @ingroup math
     */
    template<typename Type>
    [[nodiscard]] constexpr Type newton_raphson_sqrt(Type value)
    {
        BN_ASSERT(value >= 0, "Invalid value: ", value);

        return _bn::newton_raphson_sqrt_impl(value, value, Type(0));
    }

    /**
     * @brief Calculates the sine value of an angle.
     * @param angle Angle (2π = 1).
     * @return Sine value in the range [-1, 1].
     *
     * @ingroup math
     */
    [[nodiscard]] constexpr fixed sin(fixed_t<16> angle)
    {
        int lut_angle = angle.data();
        return fixed::from_data(calculate_sin_lut_value(lut_angle));
    }

    /**
     * @brief Calculates the sine value of an angle in degrees.
     * @param degrees_angle Angle in degrees.
     * @return Sine value in the range [-1, 1].
     *
     * @ingroup math
     */
    [[nodiscard]] constexpr fixed degrees_sin(fixed degrees_angle)
    {
        constexpr bn::rule_of_three_approximation rule_of_three(bn::fixed(360).data(), 65536);
        int lut_angle = rule_of_three.calculate(degrees_angle.data());
        return fixed::from_data(calculate_sin_lut_value(lut_angle));
    }

    /**
     * @brief Calculates the sine value of an angle using a LUT.
     * @param lut_angle Angle in the range [0, 2048].
     * @return Sine value in the range [-1, 1].
     *
     * @ingroup math
     */
    [[nodiscard]] constexpr fixed lut_sin(int lut_angle)
    {
        BN_ASSERT(lut_angle >= 0 && lut_angle < sin_lut_size,
                  "Angle must be in the range [0, ", sin_lut_size - 1, "]: ", lut_angle);

        if(is_constant_evaluated())
        {
            int sin_lut_value = calculate_sin_lut_value((lut_angle * 65536) / (sin_lut_size - 1));
            return fixed::from_data(sin_lut_value);
        }
        else
        {
            return fixed::from_data(sin_lut._data[lut_angle]);
        }
    }

    /**
     * @brief Calculates the sine value of an angle in degrees using a LUT.
     * @param degrees_angle Angle in degrees in the range [0, 360].
     * @return Sine value in the range [-1, 1].
     *
     * @ingroup math
     */
    [[nodiscard]] constexpr fixed degrees_lut_sin(fixed degrees_angle)
    {
        BN_ASSERT(degrees_angle >= 0 && degrees_angle <= 360,
                  "Angle must be in the range [0, 360]: ", degrees_angle);

        constexpr bn::rule_of_three_approximation rule_of_three(bn::fixed(360).data(), sin_lut_size - 1);
        int lut_angle = rule_of_three.calculate(degrees_angle.data());

        if(is_constant_evaluated())
        {
            int sin_lut_value = calculate_sin_lut_value((lut_angle * 65536) / (sin_lut_size - 1));
            return fixed::from_data(sin_lut_value);
        }
        else
        {
            return fixed::from_data(sin_lut._data[lut_angle]);
        }
    }

    /**
     * @brief Calculates the cosine value of an angle.
     * @param angle Angle (2π = 1).
     * @return Cosine value in the range [-1, 1].
     *
     * @ingroup math
     */
    [[nodiscard]] constexpr fixed cos(fixed_t<16> angle)
    {
        int lut_angle = angle.data() + 16384;
        return fixed::from_data(calculate_sin_lut_value(lut_angle));
    }

    /**
     * @brief Calculates the cosine value of an angle in degrees.
     * @param degrees_angle Angle in degrees.
     * @return Cosine value in the range [-1, 1].
     *
     * @ingroup math
     */
    [[nodiscard]] constexpr fixed degrees_cos(fixed degrees_angle)
    {
        constexpr bn::rule_of_three_approximation rule_of_three(bn::fixed(360).data(), 65536);
        int lut_angle = rule_of_three.calculate(degrees_angle.data()) + 16384;
        return fixed::from_data(calculate_sin_lut_value(lut_angle));
    }

    /**
     * @brief Calculates the cosine value of an angle using a LUT.
     * @param lut_angle Angle in the range [0, 2048].
     * @return Cosine value in the range [-1, 1].
     *
     * @ingroup math
     */
    [[nodiscard]] constexpr fixed lut_cos(int lut_angle)
    {
    BN_ASSERT(lut_angle >= 0 && lut_angle < sin_lut_size,
              "Angle must be in the range [0, ", sin_lut_size - 1, "]: ", lut_angle);

        lut_angle = (lut_angle + ((sin_lut_size - 1) / 4)) & (sin_lut_size - 2);

        if(is_constant_evaluated())
        {
            int sin_lut_value = calculate_sin_lut_value((lut_angle * 65536) / (sin_lut_size - 1));
            return fixed::from_data(sin_lut_value);
        }
        else
        {
            return fixed::from_data(sin_lut._data[lut_angle]);
        }
    }

    /**
     * @brief Calculates the cosine value of an angle in degrees using a LUT.
     * @param degrees_angle Angle in degrees in the range [0, 360].
     * @return Cosine value in the range [-1, 1].
     *
     * @ingroup math
     */
    [[nodiscard]] constexpr fixed degrees_lut_cos(fixed degrees_angle)
    {
        BN_ASSERT(degrees_angle >= 0 && degrees_angle <= 360,
                  "Angle must be in the range [0, 360]: ", degrees_angle);

        constexpr bn::rule_of_three_approximation rule_of_three(bn::fixed(360).data(), sin_lut_size - 1);
        int lut_angle = rule_of_three.calculate(degrees_angle.data());
        lut_angle = (lut_angle + ((sin_lut_size - 1) / 4)) & (sin_lut_size - 2);

        if(is_constant_evaluated())
        {
            int sin_lut_value = calculate_sin_lut_value((lut_angle * 65536) / (sin_lut_size - 1));
            return fixed::from_data(sin_lut_value);
        }
        else
        {
            return fixed::from_data(sin_lut._data[lut_angle]);
        }
    }

    /**
     * @brief Computes the arc tangent of y/x using the signs of arguments to determine the correct quadrant.
     * @param y Vertical value in the range [-32767, 32767].
     * @param x Horizontal value in the range [-32767, 32767].
     * @return Arc tangent of y/x in the range [-0.5, 0.5] (2π = 1).
     *
     * @ingroup math
     */
    [[nodiscard]] fixed_t<16> atan2(int y, int x);

    /**
     * @brief Computes the arc tangent of y/x using the signs of arguments to determine the correct quadrant.
     * @param y Vertical value in the range [-32767, 32767].
     * @param x Horizontal value in the range [-32767, 32767].
     * @return Arc tangent of y/x in degrees in the range [-180, 180].
     *
     * @ingroup math
     */
    [[nodiscard]] inline fixed degrees_atan2(int y, int x)
    {
        return fixed::from_data((atan2(y, x).data() * 360) / (1 << 4));
    }

    /**
     * @brief Calculates the reciprocal of a value using a LUT.
     * @param lut_value Value in the range [1, 1024].
     * @return Reciprocal of the given value (1 / value).
     *
     * @ingroup math
     */
    [[nodiscard]] constexpr fixed_t<20> lut_reciprocal(int lut_value)
    {
        BN_ASSERT(lut_value >= 1 && lut_value < reciprocal_lut_size,
                  "Value must be in the range [1, ", reciprocal_lut_size - 1, "]: ", lut_value);

        if(is_constant_evaluated())
        {
            return calculate_reciprocal_lut_value(lut_value);
        }
        else
        {
            return reciprocal_lut._data[lut_value];
        }
    }
}

#endif
