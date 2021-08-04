/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#include "../include/bn_hw_log.h"

#if BN_CFG_LOG_ENABLED
    #include "bn_istring_base.h"

    #if BN_CFG_LOG_BACKEND == BN_LOG_BACKEND_NOCASHGBA
        #include "../include/bn_hw_tonc.h"
    #elif BN_CFG_LOG_BACKEND == BN_LOG_BACKEND_MGBA
        #include <cstring>
        #include "bn_algorithm.h"
    #else
    #endif

    namespace bn::hw
    {
        #if BN_CFG_LOG_BACKEND == BN_LOG_BACKEND_MGBA
            void log(const istring_base& message)
            {
                // https://github.com/mgba-emu/mgba/blob/master/opt/libgba/mgba.c

                volatile uint16_t& debug_enable_register = *reinterpret_cast<uint16_t*>(0x4FFF780);
                debug_enable_register = 0xC0DE;

                int max_characters_per_line = 256;
                const char* message_data = message.data();
                int characters_left = message.size();

                while(characters_left > 0)
                {
                    int characters_to_write = bn::min(characters_left, max_characters_per_line);
                    auto debug_string_register = reinterpret_cast<char*>(0x4FFF600);

                    for(int index = 0; index < characters_to_write; ++index)
                    {
                        debug_string_register[index] = message_data[index];
                    }

                    volatile uint16_t& debug_flags_register = *reinterpret_cast<uint16_t*>(0x4FFF700);
                    debug_flags_register = 2 | 0x100;

                    message_data += characters_to_write;
                    characters_left -= characters_to_write;
                }
            }
        #elif BN_CFG_LOG_BACKEND == BN_LOG_BACKEND_NOCASHGBA
            void log(const istring_base& message)
            {
                nocash_puts(message.data());
            }
        #elif BN_CFG_LOG_BACKEND == BN_LOG_BACKEND_VBA
            void log(const istring_base& message)
            {
                asm volatile
                (
                    "mov r0, %0;"
                    "swi 0xff;"
                    :
                    : "r" (message.data())
                    : "r0"
                );

                asm volatile
                (
                    "mov r0, %0;"
                    "swi 0xff;"
                    :
                    : "r" ("\n")
                    : "r0"
                );
            }
        #else
            static_assert(false, "Unknown log backend");
        #endif
    }
#endif
