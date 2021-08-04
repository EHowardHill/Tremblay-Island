/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#ifndef BN_BG_TILES_H
#define BN_BG_TILES_H

/**
 * @file
 * bn::bg_tiles header file.
 *
 * @ingroup bg
 * @ingroup tile
 */

#include "bn_config_log.h"
#include "bn_config_doxygen.h"

/**
 * @brief Background tiles related functions.
 *
 * @ingroup bg
 * @ingroup tile
 */
namespace bn::bg_tiles
{
    /**
     * @brief Returns the number of used background tiles managed with bg_tiles_ptr objects.
     */
    [[nodiscard]] int used_tiles_count();

    /**
     * @brief Returns the number of available background tiles that can be managed with bg_tiles_ptr objects.
     */
    [[nodiscard]] int available_tiles_count();

    /**
     * @brief Returns the number of used background tile sets created with bg_tiles_ptr static constructors.
     */
    [[nodiscard]] int used_blocks_count();

    /**
     * @brief Returns the number of available background tile sets
     * that can be created with bg_tiles_ptr static constructors.
     */
    [[nodiscard]] int available_blocks_count();

    #if BN_CFG_LOG_ENABLED || BN_DOXYGEN
        /**
         * @brief Logs the current status of the background blocks manager.
         */
        void log_status();
    #endif
}

#endif
