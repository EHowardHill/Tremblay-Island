/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#ifndef BN_HW_BGS_H
#define BN_HW_BGS_H

#include "bn_affine_bg_builder.h"
#include "bn_regular_bg_builder.h"
#include "bn_hw_tonc.h"

namespace bn::hw::bgs
{
    constexpr int affine_precision = 8;

    using affine_attributes = BG_AFFINE;

    class handle
    {

    public:
        affine_attributes affine;
        uint16_t cnt = 0;
        uint16_t hofs = 0;
        uint16_t vofs = 0;

        handle()
        {
            affine.pa = 256;
            affine.pb = 0;
            affine.pc = 0;
            affine.pd = 256;
            affine.dx = 0;
            affine.dy = 0;
        }
    };

    [[nodiscard]] constexpr int count()
    {
        return 4;
    }

    [[nodiscard]] constexpr int affine_count()
    {
        return 2;
    }

    inline void setup_regular(const regular_bg_builder& builder, handle& bg)
    {
        bg.cnt = uint16_t(BG_PRIO(builder.priority()) | (builder.mosaic_enabled() << 6));
    }

    inline void setup_affine(const affine_bg_builder& builder, handle& bg)
    {
        bg.cnt = uint16_t(BG_PRIO(builder.priority()) | (builder.mosaic_enabled() << 6) |
                          (builder.wrapping_enabled() << 13) | BG_8BPP);
    }

    inline void set_tiles_cbb(int tiles_cbb, uint16_t& bg_cnt)
    {
        BFN_SET(bg_cnt, tiles_cbb, BG_CBB);
    }

    inline void set_tiles_cbb(int tiles_cbb, handle& bg)
    {
        set_tiles_cbb(tiles_cbb, bg.cnt);
    }

    inline void set_map_sbb(int map_sbb, uint16_t& bg_cnt)
    {
        BFN_SET(bg_cnt, map_sbb, BG_SBB);
    }

    inline void set_map_sbb(int map_sbb, handle& bg)
    {
        set_map_sbb(map_sbb, bg.cnt);
    }

    inline void set_map_dimensions(int size, handle& bg)
    {
        BFN_SET(bg.cnt, size, BG_SIZE);
    }

    [[nodiscard]] inline bpp_mode bpp(const handle& bg)
    {
        return (bg.cnt & BG_8BPP) ? bpp_mode::BPP_8 : bpp_mode::BPP_4;
    }

    inline void set_bpp(bpp_mode bpp, uint16_t& bg_cnt)
    {
        if(bpp == bpp_mode::BPP_8)
        {
            bg_cnt |= BG_8BPP;
        }
        else
        {
            bg_cnt &= ~BG_8BPP;
        }
    }

    inline void set_bpp(bpp_mode bpp, handle& bg)
    {
        set_bpp(bpp, bg.cnt);
    }

    inline void set_regular_x(int x, handle& bg)
    {
        bg.hofs = uint16_t(x);
    }

    inline void set_affine_x(int x, handle& bg)
    {
        bg.affine.dx = x;
    }

    inline void set_regular_y(int y, handle& bg)
    {
        bg.vofs = uint16_t(y);
    }

    inline void set_affine_y(int y, handle& bg)
    {
        bg.affine.dy = y;
    }

    inline void set_affine_mat_attributes(const affine_mat_attributes& mat_attributes, handle& bg)
    {
        bg.affine.pa = int16_t(mat_attributes.pa_register_value());
        bg.affine.pb = int16_t(mat_attributes.pb_register_value());
        bg.affine.pc = int16_t(mat_attributes.pc_register_value());
        bg.affine.pd = int16_t(mat_attributes.pd_register_value());
    }

    inline void set_priority(int priority, uint16_t& bg_cnt)
    {
        BFN_SET(bg_cnt, priority, BG_PRIO);
    }

    inline void set_priority(int priority, handle& bg)
    {
        set_priority(priority, bg.cnt);
    }

    [[nodiscard]] inline bool wrapping_enabled(const handle& bg)
    {
        return bg.cnt & BG_WRAP;
    }

    inline void set_wrapping_enabled(bool wrapping_enabled, uint16_t& bg_cnt)
    {
        if(wrapping_enabled)
        {
            bg_cnt |= BG_WRAP;
        }
        else
        {
            bg_cnt &= ~BG_WRAP;
        }
    }

    inline void set_wrapping_enabled(bool wrapping_enabled, handle& bg)
    {
        set_wrapping_enabled(wrapping_enabled, bg.cnt);
    }

    [[nodiscard]] inline bool mosaic_enabled(const handle& bg)
    {
        return bg.cnt & BG_MOSAIC;
    }

    inline void set_mosaic_enabled(bool mosaic_enabled, uint16_t& bg_cnt)
    {
        if(mosaic_enabled)
        {
            bg_cnt |= BG_MOSAIC;
        }
        else
        {
            bg_cnt &= ~BG_MOSAIC;
        }
    }

    inline void set_mosaic_enabled(bool mosaic_enabled, handle& bg)
    {
        set_mosaic_enabled(mosaic_enabled, bg.cnt);
    }

    inline void commit(const handle* bgs_ptr)
    {
        const handle& bg0 = bgs_ptr[0];
        REG_BG0CNT = bg0.cnt;
        REG_BG0HOFS = bg0.hofs;
        REG_BG0VOFS = bg0.vofs;

        const handle& bg1 = bgs_ptr[1];
        REG_BG1CNT = bg1.cnt;
        REG_BG1HOFS = bg1.hofs;
        REG_BG1VOFS = bg1.vofs;

        const handle& bg2 = bgs_ptr[2];
        REG_BG2CNT = bg2.cnt;
        REG_BG2HOFS = bg2.hofs;
        REG_BG2VOFS = bg2.vofs;
        REG_BG_AFFINE[2] = bg2.affine;

        const handle& bg3 = bgs_ptr[3];
        REG_BG3CNT = bg3.cnt;
        REG_BG3HOFS = bg3.hofs;
        REG_BG3VOFS = bg3.vofs;
        REG_BG_AFFINE[3] = bg3.affine;
    }

    inline void stop()
    {
        REG_BG_AFFINE[2] = handle().affine;
    }

    [[nodiscard]] inline uint16_t* regular_horizontal_position_register(int id)
    {
        return reinterpret_cast<uint16_t*>(REG_BASE + 0x0010 + (0x0004 * id));
    }

    [[nodiscard]] inline uint16_t* regular_vertical_position_register(int id)
    {
        return reinterpret_cast<uint16_t*>(REG_BASE + 0x0012 + (0x0004 * id));
    }

    [[nodiscard]] inline affine_attributes* affine_mat_register(int id)
    {
        return &REG_BG_AFFINE[id];
    }

    [[nodiscard]] inline uint16_t* attributes_register(int id)
    {
        return reinterpret_cast<uint16_t*>(REG_BASE + 0x0008 + (0x0002 * id));
    }
}

#endif
