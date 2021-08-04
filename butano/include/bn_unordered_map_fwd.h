/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#ifndef BN_UNORDERED_MAP_FWD_H
#define BN_UNORDERED_MAP_FWD_H

/**
 * @file
 * bn::iunordered_map and bn::unordered_map declaration header file.
 *
 * @ingroup unordered_map
 */

#include "bn_functional.h"

namespace bn
{
    /**
     * @brief Base class of unordered_map.
     *
     * Can be used as a reference type for all unordered_map containers containing a specific type.
     *
     * @tparam Key Key type.
     * @tparam Value Value type.
     * @tparam KeyHash Functor used to calculate the hash of a given key.
     * @tparam KeyEqual Functor used for all key comparisons.
     *
     * @ingroup unordered_map
     */
    template<typename Key, typename Value, typename KeyHash = hash<Key>, typename KeyEqual = equal_to<Key>>
    class iunordered_map;

    /**
     * @brief Unordered map implementation that uses a fixed size buffer.
     *
     * @tparam Key Key type.
     * @tparam Value Value type.
     * @tparam MaxSize Maximum number of elements that can be stored.
     * @tparam KeyHash Functor used to calculate the hash of a given key.
     * @tparam KeyEqual Functor used for all key comparisons.
     *
     * @ingroup unordered_map
     */
    template<typename Key, typename Value, int MaxSize, typename KeyHash = hash<Key>, typename KeyEqual = equal_to<Key>>
    class unordered_map;
}

#endif
