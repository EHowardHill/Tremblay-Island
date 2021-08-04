/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#ifndef BN_CONFIG_ASSERT_H
#define BN_CONFIG_ASSERT_H

/**
 * @file
 * Asserts configuration header file.
 *
 * @ingroup assert
 */

#include "bn_common.h"

/**
 * @def BN_CFG_ASSERT_ENABLED
 *
 * Specifies if asserts must be enabled or not.
 *
 * @ingroup assert
 */
#ifndef BN_CFG_ASSERT_ENABLED
    #define BN_CFG_ASSERT_ENABLED true
#endif

/**
 * @def BN_CFG_ASSERT_BUFFER_SIZE
 *
 * Specifies the maximum size of the messages that can be displayed by an assert.
 *
 * @ingroup assert
 */
#ifndef BN_CFG_ASSERT_BUFFER_SIZE
    #define BN_CFG_ASSERT_BUFFER_SIZE 512
#endif

#endif
