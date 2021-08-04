/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#include "bn_bgs_manager.h"

#include "bn_math.h"
#include "bn_pool.h"
#include "bn_vector.h"
#include "bn_display.h"
#include "bn_sort_key.h"
#include "bn_config_bgs.h"
#include "bn_display_manager.h"
#include "bn_bg_blocks_manager.h"
#include "bn_affine_bg_mat_attributes.h"
#include "../hw/include/bn_hw_bgs.h"

#include "bn_bgs.cpp.h"
#include "bn_affine_bg_ptr.cpp.h"
#include "bn_affine_bg_item.cpp.h"
#include "bn_affine_bg_builder.cpp.h"
#include "bn_affine_bg_attributes.cpp.h"
#include "bn_regular_bg_ptr.cpp.h"
#include "bn_regular_bg_item.cpp.h"
#include "bn_regular_bg_builder.cpp.h"
#include "bn_regular_bg_attributes.cpp.h"

namespace bn::bgs_manager
{

namespace
{
    static_assert(BN_CFG_BGS_MAX_ITEMS > 0);

    class item_type
    {

    public:
        fixed_point position;
        affine_bg_mat_attributes affine_mat_attributes;
        point hw_position;
        size half_dimensions;
        unsigned usages = 1;
        sort_key bg_sort_key;
        hw::bgs::handle handle;
        optional<regular_bg_map_ptr> regular_map;
        optional<affine_bg_map_ptr> affine_map;
        optional<camera_ptr> camera;
        uint16_t old_big_map_x = 0;
        uint16_t old_big_map_y = 0;
        int8_t handles_index = -1;
        bool blending_enabled: 1;
        bool visible: 1;
        bool update: 1;
        bool big_map: 1;
        bool commit_big_map: 1;
        bool full_commit_big_map: 1;

        item_type(regular_bg_builder&& builder, regular_bg_map_ptr&& _regular_map) :
            position(builder.position()),
            bg_sort_key(builder.priority(), builder.z_order()),
            regular_map(move(_regular_map)),
            camera(builder.release_camera()),
            blending_enabled(builder.blending_enabled()),
            visible(builder.visible()),
            update(true)
        {
            hw::bgs::setup_regular(builder, handle);
            update_regular_map();
        }

        item_type(affine_bg_builder&& builder, affine_bg_map_ptr&& _affine_map) :
            position(builder.position()),
            affine_mat_attributes((builder.camera() ? position - builder.camera()->position() : position),
                                  _affine_map.dimensions() * 4, builder.pivot_position(), builder.mat_attributes()),
            bg_sort_key(builder.priority(), builder.z_order()),
            affine_map(move(_affine_map)),
            camera(builder.release_camera()),
            blending_enabled(builder.blending_enabled()),
            visible(builder.visible()),
            update(true)
        {
            hw::bgs::setup_affine(builder, handle);
            update_affine_map(true);
        }

        void update_regular_map()
        {
            const regular_bg_map_ptr& map_ref = *regular_map;
            hw::bgs::handle new_handle = handle;
            hw::bgs::set_tiles_cbb(map_ref.tiles().cbb(), new_handle);
            hw::bgs::set_map_sbb(map_ref.id(), new_handle);
            hw::bgs::set_bpp(map_ref.bpp(), new_handle);

            size map_dimensions = map_ref.dimensions();
            int map_width = map_dimensions.width();
            int map_height = map_dimensions.height();
            int map_size = 0;
            big_map = true;

            if(map_width == 32 || map_width == 64)
            {
                if(map_height == 32 || map_height == 64)
                {
                    big_map = false;

                    if(map_width == 64)
                    {
                        ++map_size;
                    }

                    if(map_height == 64)
                    {
                        map_size += 2;
                    }
                }
            }

            commit_big_map = big_map;
            full_commit_big_map = big_map;

            hw::bgs::set_map_dimensions(map_size, new_handle);
            handle = new_handle;
            half_dimensions = map_dimensions * 4;
            update_regular_hw_position();
        }

        void update_affine_map(bool force_affine_mat_attributes_update)
        {
            const affine_bg_map_ptr& map_ref = *affine_map;
            hw::bgs::handle new_handle = handle;
            hw::bgs::set_tiles_cbb(map_ref.tiles().cbb(), new_handle);
            hw::bgs::set_map_sbb(map_ref.id(), new_handle);

            size map_dimensions = map_ref.dimensions();
            int map_width = map_dimensions.width();
            int map_size;
            big_map = false;

            if(map_width == map_dimensions.height())
            {
                switch(map_width)
                {

                case 16:
                    map_size = 0;
                    break;

                case 32:
                    map_size = 1;
                    break;

                case 64:
                    map_size = 2;
                    break;

                case 128:
                    map_size = 3;
                    break;

                default:
                    map_size = 1;
                    big_map = true;
                }
            }
            else
            {
                map_size = 1;
                big_map = true;
            }

            commit_big_map = big_map;
            full_commit_big_map = big_map;

            hw::bgs::set_map_dimensions(map_size, new_handle);
            handle = new_handle;
            half_dimensions = map_dimensions * 4;

            if(force_affine_mat_attributes_update)
            {
                update_affine_mat_attributes();
            }
            else
            {
                fixed_size fixed_half_dimensions = half_dimensions;

                if(fixed_half_dimensions != affine_mat_attributes.half_dimensions())
                {
                    affine_mat_attributes.set_half_dimensions(fixed_half_dimensions);
                    update_affine_mat_attributes();
                }
            }
        }

        void update_regular_hw_position()
        {
            int real_x = position.x().right_shift_integer();
            int real_y = position.y().right_shift_integer();

            if(camera)
            {
                const fixed_point& camera_position = camera->position();
                real_x -= camera_position.x().right_shift_integer();
                real_y -= camera_position.y().right_shift_integer();
            }

            int hw_x = -real_x - (display::width() / 2) + half_dimensions.width();
            hw_position.set_x(hw_x);
            commit_regular_hw_x();

            int hw_y = -real_y - (display::height() / 2) + half_dimensions.height();
            hw_position.set_y(hw_y);
            commit_regular_hw_y();
        }

        void update_affine_mat_attributes()
        {
            hw::bgs::set_affine_mat_attributes(affine_mat_attributes.mat_attributes(), handle);
            update_affine_hw_x();
            update_affine_hw_y();
        }

        void update_affine_camera()
        {
            if(camera)
            {
                affine_mat_attributes.set_position(position - camera->position());
            }
            else
            {
                affine_mat_attributes.set_position(position);
            }

            update_affine_hw_x();
            update_affine_hw_y();
        }

        void commit_regular_hw_x()
        {
            int x = hw_position.x();
            hw::bgs::set_regular_x(x, handle);

            if(big_map)
            {
                BN_ASSERT(x >= 0 && x <= (half_dimensions.width() * 2) - display::width(),
                          "Regular BGs with big maps\ndon't allow horizontal wrapping: ",
                          x, " - ", (half_dimensions.width() * 2) - display::width());

                commit_big_map = true;
            }
        }

        void commit_regular_hw_y()
        {
            int y = hw_position.y();
            hw::bgs::set_regular_y(y, handle);

            if(big_map)
            {
                BN_ASSERT(y >= 0 && y <= (half_dimensions.height() * 2) - display::height(),
                          "Regular BGs with big maps\ndon't allow vertical wrapping: ",
                          y, " - ", (half_dimensions.height() * 2) - display::height());

                commit_big_map = true;
            }
        }

        [[nodiscard]] point affine_map_position() const
        {
            int map_x2 = (half_dimensions.width() - (bn::display::width() / 2) -
                          affine_mat_attributes.x().right_shift_integer() +
                          affine_mat_attributes.pivot_x().right_shift_integer()) >> 3;

            int map_y2 = (half_dimensions.height() - (bn::display::height() / 2) -
                          affine_mat_attributes.y().right_shift_integer() +
                          affine_mat_attributes.pivot_y().right_shift_integer()) >> 3;

            return point(map_x2, map_y2);
        }

        void update_affine_hw_x()
        {
            int dx = affine_mat_attributes.dx_register_value();
            hw_position.set_x(dx);
            hw::bgs::set_affine_x(dx, handle);

            if(big_map)
            {
                BN_ASSERT(affine_map_position().x() >= 0 &&
                          affine_map_position().x() <= (half_dimensions.width() / 4) - (display::width() / 8),
                          "Affine BGs with big maps\ndon't allow horizontal wrapping: ",
                          affine_map_position().x(), " - ", (half_dimensions.width() / 4) - (display::width() / 8));

                commit_big_map = true;
            }
        }

        void update_affine_hw_y()
        {
            int dy = affine_mat_attributes.dy_register_value();
            hw_position.set_y(dy);
            hw::bgs::set_affine_y(dy, handle);

            if(big_map)
            {
                BN_ASSERT(affine_map_position().y() >= 0 &&
                          affine_map_position().y() <= (half_dimensions.height() / 4) - (display::height() / 8),
                          "Affine BGs with big maps\ndon't allow vertical wrapping: ",
                          affine_map_position().y(), " - ", (half_dimensions.height() / 4) - (display::height() / 8));

                commit_big_map = true;
            }
        }
    };


    class affine_mat_registers
    {

    public:
        explicit affine_mat_registers(const affine_bg_mat_attributes& affine_mat_attributes) :
            _pa(affine_mat_attributes.pa_register_value()),
            _pb(affine_mat_attributes.pb_register_value()),
            _pc(affine_mat_attributes.pc_register_value()),
            _pd(affine_mat_attributes.pd_register_value())
        {
        }

        [[nodiscard]] friend bool operator==(const affine_mat_registers& a, const affine_mat_registers& b) = default;

    private:
        int _pa;
        int _pb;
        int _pc;
        int _pd;
    };


    class static_data
    {

    public:
        pool<item_type, BN_CFG_BGS_MAX_ITEMS> items_pool;
        vector<item_type*, BN_CFG_BGS_MAX_ITEMS> items_vector;
        hw::bgs::handle handles[hw::bgs::count()];
        bool rebuild_handles = false;
        bool commit = false;
    };

    BN_DATA_EWRAM static_data data;


    [[nodiscard]] bool _check_unique_regular_big_map(item_type& item)
    {
        if(item.big_map)
        {
            for(item_type* other_item : data.items_vector)
            {
                if(other_item != &item && other_item->regular_map == item.regular_map)
                {
                    return false;
                }
            }
        }

        return true;
    }

    [[nodiscard]] bool _check_unique_affine_big_map(item_type& item)
    {
        if(item.big_map)
        {
            for(item_type* other_item : data.items_vector)
            {
                if(other_item != &item && other_item->affine_map == item.affine_map)
                {
                    return false;
                }
            }
        }

        return true;
    }

    void _insert_item(item_type& new_item)
    {
        sort_key bg_sort_key = new_item.bg_sort_key;
        bool affine_new_item = new_item.affine_map.has_value();

        if(new_item.visible)
        {
            data.rebuild_handles = true;
        }

        for(auto it = data.items_vector.begin(), end = data.items_vector.end(); it != end; ++it)
        {
            const item_type* item = *it;

            if((affine_new_item && ! item->affine_map) || bg_sort_key > item->bg_sort_key)
            {
                data.items_vector.insert(it, &new_item);
                return;
            }
        }

        data.items_vector.push_back(&new_item);
    }

    void _update_item(const item_type& item)
    {
        if(! data.rebuild_handles && item.visible)
        {
            data.handles[item.handles_index] = item.handle;
            data.commit = true;
        }
    }
}

int used_count()
{
    return data.items_vector.size();
}

int available_count()
{
    return data.items_vector.available();
}

id_type create(regular_bg_builder&& builder)
{
    BN_ASSERT(! data.items_vector.full(), "No more available BGs");

    regular_bg_map_ptr map = builder.release_map();
    item_type& item = data.items_pool.create(move(builder), move(map));
    BN_ASSERT(_check_unique_regular_big_map(item), "Two or more regular BGs have the same big map");

    _insert_item(item);
    display_manager::set_show_bg_in_all_windows(&item, true);
    return &item;
}

id_type create(affine_bg_builder&& builder)
{
    BN_ASSERT(! data.items_vector.full(), "No more available BGs");

    affine_bg_map_ptr map = builder.release_map();
    item_type& item = data.items_pool.create(move(builder), move(map));
    BN_ASSERT(_check_unique_affine_big_map(item), "Two or more affine BGs have the same big map");

    _insert_item(item);
    display_manager::set_show_bg_in_all_windows(&item, true);
    return &item;
}

id_type create_optional(regular_bg_builder&& builder)
{
    if(data.items_vector.full())
    {
        return nullptr;
    }

    optional<regular_bg_map_ptr> map = builder.release_map_optional();

    if(! map)
    {
        return nullptr;
    }

    item_type& item = data.items_pool.create(move(builder), move(*map));
    BN_ASSERT(_check_unique_regular_big_map(item), "Two or more regular BGs have the same big map");

    _insert_item(item);
    display_manager::set_show_bg_in_all_windows(&item, true);
    return &item;
}

id_type create_optional(affine_bg_builder&& builder)
{
    if(data.items_vector.full())
    {
        return nullptr;
    }

    optional<affine_bg_map_ptr> map = builder.release_map_optional();

    if(! map)
    {
        return nullptr;
    }

    item_type& item = data.items_pool.create(move(builder), move(*map));
    BN_ASSERT(_check_unique_affine_big_map(item), "Two or more affine BGs have the same big map");

    _insert_item(item);
    display_manager::set_show_bg_in_all_windows(&item, true);
    return &item;
}

void increase_usages(id_type id)
{
    auto item = static_cast<item_type*>(id);
    ++item->usages;
}

void decrease_usages(id_type id)
{
    auto item = static_cast<item_type*>(id);
    --item->usages;

    if(! item->usages)
    {
        if(! data.rebuild_handles && item->visible)
        {
            if(item->regular_map && item == data.items_vector.back())
            {
                display_manager::set_bg_enabled(item->handles_index, false);
            }
            else
            {
                data.rebuild_handles = true;
            }
        }

        display_manager::set_show_bg_in_all_windows(item, false);
        erase(data.items_vector, item);
        data.items_pool.destroy(*item);
    }
}

optional<int> hw_id(id_type id)
{
    auto item = static_cast<const item_type*>(id);
    int handles_index = item->handles_index;
    optional<int> result;

    if(handles_index >= 0)
    {
        result = handles_index;
    }

    return result;
}

size dimensions(id_type id)
{
    auto item = static_cast<const item_type*>(id);
    return item->half_dimensions * 2;
}

bool big(id_type id)
{
    auto item = static_cast<const item_type*>(id);
    return item->big_map;
}

const regular_bg_map_ptr& regular_map(id_type id)
{
    auto item = static_cast<const item_type*>(id);
    return *item->regular_map;
}

const affine_bg_map_ptr& affine_map(id_type id)
{
    auto item = static_cast<const item_type*>(id);
    return *item->affine_map;
}

void set_regular_map(id_type id, const regular_bg_map_ptr& map)
{
    auto item = static_cast<item_type*>(id);

    if(map != item->regular_map)
    {
        item->regular_map = map;
        item->update_regular_map();
        BN_ASSERT(_check_unique_regular_big_map(*item), "Two or more regular BGs have the same big map");

        _update_item(*item);
    }
}

void set_affine_map(id_type id, const affine_bg_map_ptr& map)
{
    auto item = static_cast<item_type*>(id);

    if(map != item->affine_map)
    {
        item->affine_map = map;
        item->update_affine_map(false);
        BN_ASSERT(_check_unique_affine_big_map(*item), "Two or more affine BGs have the same big map");

        _update_item(*item);
    }
}

void set_regular_map(id_type id, regular_bg_map_ptr&& map)
{
    auto item = static_cast<item_type*>(id);

    if(map != item->regular_map)
    {
        item->regular_map = move(map);
        item->update_regular_map();
        BN_ASSERT(_check_unique_regular_big_map(*item), "Two or more regular BGs have the same big map");

        _update_item(*item);
    }
}

void set_affine_map(id_type id, affine_bg_map_ptr&& map)
{
    auto item = static_cast<item_type*>(id);

    if(map != item->affine_map)
    {
        item->affine_map = move(map);
        item->update_affine_map(false);
        BN_ASSERT(_check_unique_affine_big_map(*item), "Two or more affine BGs have the same big map");

        _update_item(*item);
    }
}

void remove_regular_map(id_type id)
{
    auto item = static_cast<item_type*>(id);
    item->regular_map.reset();
}

void remove_affine_map(id_type id)
{
    auto item = static_cast<item_type*>(id);
    item->affine_map.reset();
}

const fixed_point& position(id_type id)
{
    auto item = static_cast<const item_type*>(id);
    return item->position;
}

const point& hw_position(id_type id)
{
    auto item = static_cast<const item_type*>(id);
    return item->hw_position;
}

void set_regular_x(id_type id, fixed x)
{
    auto item = static_cast<item_type*>(id);
    fixed old_x = item->position.x();
    item->position.set_x(x);

    int old_integer_x = old_x.right_shift_integer();
    int new_integer_x = x.right_shift_integer();
    int diff = new_integer_x - old_integer_x;

    if(diff)
    {
        item->hw_position.set_x(item->hw_position.x() - diff);
        item->commit_regular_hw_x();
        _update_item(*item);
    }
}

void set_affine_x(id_type id, fixed x)
{
    auto item = static_cast<item_type*>(id);
    fixed old_x = item->position.x();
    item->position.set_x(x);

    if(old_x.right_shift_integer() != x.right_shift_integer())
    {
        if(item->camera)
        {
            x -= item->camera->x();
        }

        item->affine_mat_attributes.set_x(x);
        item->update_affine_hw_x();
        _update_item(*item);
    }
}

void set_regular_y(id_type id, fixed y)
{
    auto item = static_cast<item_type*>(id);
    fixed old_y = item->position.y();
    item->position.set_y(y);

    int old_integer_y = old_y.right_shift_integer();
    int new_integer_y = y.right_shift_integer();
    int diff = new_integer_y - old_integer_y;

    if(diff)
    {
        item->hw_position.set_y(item->hw_position.y() - diff);
        item->commit_regular_hw_y();
        _update_item(*item);
    }
}

void set_affine_y(id_type id, fixed y)
{
    auto item = static_cast<item_type*>(id);
    fixed old_y = item->position.y();
    item->position.set_y(y);

    if(old_y.right_shift_integer() != y.right_shift_integer())
    {
        if(item->camera)
        {
            y -= item->camera->y();
        }

        item->affine_mat_attributes.set_y(y);
        item->update_affine_hw_y();
        _update_item(*item);
    }
}

void set_regular_position(id_type id, const fixed_point& position)
{
    auto item = static_cast<item_type*>(id);
    fixed_point old_position = item->position;
    item->position = position;

    point old_integer_position(old_position.x().right_shift_integer(), old_position.y().right_shift_integer());
    point new_integer_position(position.x().right_shift_integer(), position.y().right_shift_integer());
    point diff = new_integer_position - old_integer_position;

    if(diff != point())
    {
        item->hw_position -= diff;
        item->commit_regular_hw_x();
        item->commit_regular_hw_y();
        _update_item(*item);
    }
}

void set_affine_position(id_type id, const fixed_point& position)
{
    auto item = static_cast<item_type*>(id);
    fixed_point old_position = item->position;
    item->position = position;

    point old_integer_position(old_position.x().right_shift_integer(), old_position.y().right_shift_integer());
    point new_integer_position(position.x().right_shift_integer(), position.y().right_shift_integer());

    if(old_integer_position != new_integer_position)
    {
        if(item->camera)
        {
            item->affine_mat_attributes.set_position(position - item->camera->position());
        }
        else
        {
            item->affine_mat_attributes.set_position(position);
        }

        item->update_affine_hw_x();
        item->update_affine_hw_y();
        _update_item(*item);
    }
}

fixed rotation_angle(id_type id)
{
    auto item = static_cast<item_type*>(id);
    return item->affine_mat_attributes.rotation_angle();
}

void set_rotation_angle(id_type id, fixed rotation_angle)
{
    auto item = static_cast<item_type*>(id);

    if(rotation_angle != item->affine_mat_attributes.rotation_angle())
    {
        affine_mat_registers old_registers(item->affine_mat_attributes);
        item->affine_mat_attributes.set_rotation_angle(rotation_angle);

        if(affine_mat_registers(item->affine_mat_attributes) != old_registers)
        {
            item->update_affine_mat_attributes();
            _update_item(*item);
        }
    }
}

fixed horizontal_scale(id_type id)
{
    auto item = static_cast<item_type*>(id);
    return item->affine_mat_attributes.horizontal_scale();
}

void set_horizontal_scale(id_type id, fixed horizontal_scale)
{
    auto item = static_cast<item_type*>(id);

    if(horizontal_scale != item->affine_mat_attributes.horizontal_scale())
    {
        affine_mat_registers old_registers(item->affine_mat_attributes);
        item->affine_mat_attributes.set_horizontal_scale(horizontal_scale);

        if(affine_mat_registers(item->affine_mat_attributes) != old_registers)
        {
            item->update_affine_mat_attributes();
            _update_item(*item);
        }
    }
}

fixed vertical_scale(id_type id)
{
    auto item = static_cast<item_type*>(id);
    return item->affine_mat_attributes.vertical_scale();
}

void set_vertical_scale(id_type id, fixed vertical_scale)
{
    auto item = static_cast<item_type*>(id);

    if(vertical_scale != item->affine_mat_attributes.vertical_scale())
    {
        affine_mat_registers old_registers(item->affine_mat_attributes);
        item->affine_mat_attributes.set_vertical_scale(vertical_scale);

        if(affine_mat_registers(item->affine_mat_attributes) != old_registers)
        {
            item->update_affine_mat_attributes();
            _update_item(*item);
        }
    }
}

void set_scale(id_type id, fixed scale)
{
    auto item = static_cast<item_type*>(id);

    if(scale != item->affine_mat_attributes.horizontal_scale() ||
            scale != item->affine_mat_attributes.vertical_scale())
    {
        affine_mat_registers old_registers(item->affine_mat_attributes);
        item->affine_mat_attributes.set_scale(scale);

        if(affine_mat_registers(item->affine_mat_attributes) != old_registers)
        {
            item->update_affine_mat_attributes();
            _update_item(*item);
        }
    }
}

void set_scale(id_type id, fixed horizontal_scale, fixed vertical_scale)
{
    auto item = static_cast<item_type*>(id);

    if(horizontal_scale != item->affine_mat_attributes.horizontal_scale() ||
            vertical_scale != item->affine_mat_attributes.vertical_scale())
    {
        affine_mat_registers old_registers(item->affine_mat_attributes);
        item->affine_mat_attributes.set_scale(horizontal_scale, vertical_scale);

        if(affine_mat_registers(item->affine_mat_attributes) != old_registers)
        {
            item->update_affine_mat_attributes();
            _update_item(*item);
        }
    }
}

fixed horizontal_shear(id_type id)
{
    auto item = static_cast<item_type*>(id);
    return item->affine_mat_attributes.horizontal_shear();
}

void set_horizontal_shear(id_type id, fixed horizontal_shear)
{
    auto item = static_cast<item_type*>(id);

    if(horizontal_shear != item->affine_mat_attributes.horizontal_shear())
    {
        affine_mat_registers old_registers(item->affine_mat_attributes);
        item->affine_mat_attributes.set_horizontal_shear(horizontal_shear);

        if(affine_mat_registers(item->affine_mat_attributes) != old_registers)
        {
            item->update_affine_mat_attributes();
            _update_item(*item);
        }
    }
}

fixed vertical_shear(id_type id)
{
    auto item = static_cast<item_type*>(id);
    return item->affine_mat_attributes.vertical_shear();
}

void set_vertical_shear(id_type id, fixed vertical_shear)
{
    auto item = static_cast<item_type*>(id);

    if(vertical_shear != item->affine_mat_attributes.vertical_shear())
    {
        affine_mat_registers old_registers(item->affine_mat_attributes);
        item->affine_mat_attributes.set_vertical_shear(vertical_shear);

        if(affine_mat_registers(item->affine_mat_attributes) != old_registers)
        {
            item->update_affine_mat_attributes();
            _update_item(*item);
        }
    }
}

void set_shear(id_type id, fixed shear)
{
    auto item = static_cast<item_type*>(id);

    if(shear != item->affine_mat_attributes.horizontal_shear() ||
            shear != item->affine_mat_attributes.vertical_shear())
    {
        affine_mat_registers old_registers(item->affine_mat_attributes);
        item->affine_mat_attributes.set_shear(shear);

        if(affine_mat_registers(item->affine_mat_attributes) != old_registers)
        {
            item->update_affine_mat_attributes();
            _update_item(*item);
        }
    }
}

void set_shear(id_type id, fixed horizontal_shear, fixed vertical_shear)
{
    auto item = static_cast<item_type*>(id);

    if(horizontal_shear != item->affine_mat_attributes.horizontal_shear() ||
            vertical_shear != item->affine_mat_attributes.vertical_shear())
    {
        affine_mat_registers old_registers(item->affine_mat_attributes);
        item->affine_mat_attributes.set_shear(horizontal_shear, vertical_shear);

        if(affine_mat_registers(item->affine_mat_attributes) != old_registers)
        {
            item->update_affine_mat_attributes();
            _update_item(*item);
        }
    }
}

bool horizontal_flip(id_type id)
{
    auto item = static_cast<item_type*>(id);
    return item->affine_mat_attributes.horizontal_flip();
}

void set_horizontal_flip(id_type id, bool horizontal_flip)
{
    auto item = static_cast<item_type*>(id);

    if(horizontal_flip != item->affine_mat_attributes.horizontal_flip())
    {
        item->affine_mat_attributes.set_horizontal_flip(horizontal_flip);
        item->update_affine_mat_attributes();
        _update_item(*item);
    }
}

bool vertical_flip(id_type id)
{
    auto item = static_cast<item_type*>(id);
    return item->affine_mat_attributes.vertical_flip();
}

void set_vertical_flip(id_type id, bool vertical_flip)
{
    auto item = static_cast<item_type*>(id);

    if(vertical_flip != item->affine_mat_attributes.vertical_flip())
    {
        affine_mat_registers old_registers(item->affine_mat_attributes);
        item->affine_mat_attributes.set_vertical_flip(vertical_flip);
        item->update_affine_mat_attributes();
        _update_item(*item);
    }
}

const fixed_point& pivot_position(id_type id)
{
    auto item = static_cast<item_type*>(id);
    return item->affine_mat_attributes.pivot_position();
}

void set_pivot_x(id_type id, fixed pivot_x)
{
    auto item = static_cast<item_type*>(id);

    if(pivot_x != item->affine_mat_attributes.pivot_x())
    {
        item->affine_mat_attributes.set_pivot_x(pivot_x);
        item->update_affine_hw_x();
        _update_item(*item);
    }
}

void set_pivot_y(id_type id, fixed pivot_y)
{
    auto item = static_cast<item_type*>(id);

    if(pivot_y != item->affine_mat_attributes.pivot_y())
    {
        item->affine_mat_attributes.set_pivot_y(pivot_y);
        item->update_affine_hw_y();
        _update_item(*item);
    }
}

void set_pivot_position(id_type id, const fixed_point& pivot_position)
{
    auto item = static_cast<item_type*>(id);

    if(pivot_position != item->affine_mat_attributes.pivot_position())
    {
        item->affine_mat_attributes.set_pivot_position(pivot_position);
        item->update_affine_hw_x();
        item->update_affine_hw_y();
        _update_item(*item);
    }
}

const affine_bg_mat_attributes& mat_attributes(id_type id)
{
    auto item = static_cast<item_type*>(id);
    return item->affine_mat_attributes;
}

void set_mat_attributes(id_type id, const affine_mat_attributes& mat_attributes)
{
    auto item = static_cast<item_type*>(id);

    if(mat_attributes != item->affine_mat_attributes.mat_attributes())
    {
        affine_mat_registers old_registers(item->affine_mat_attributes);
        item->affine_mat_attributes.set_mat_attributes(mat_attributes);

        if(affine_mat_registers(item->affine_mat_attributes) != old_registers)
        {
            item->update_affine_mat_attributes();
            _update_item(*item);
        }
    }
}

int priority(id_type id)
{
    auto item = static_cast<const item_type*>(id);
    return item->bg_sort_key.priority();
}

void set_priority(id_type id, int priority)
{
    auto item = static_cast<item_type*>(id);

    if(item->bg_sort_key.priority() != priority)
    {
        BN_ASSERT(priority >= 0 && priority <= bgs::max_priority(), "Invalid priority: ", priority);

        item->bg_sort_key.set_priority(priority);
        hw::bgs::set_priority(priority, item->handle);
        erase(data.items_vector, item);
        _insert_item(*item);
    }
}

int z_order(id_type id)
{
    auto item = static_cast<const item_type*>(id);
    return item->bg_sort_key.z_order();
}

void set_z_order(id_type id, int z_order)
{
    auto item = static_cast<item_type*>(id);

    if(item->bg_sort_key.z_order() != z_order)
    {
        BN_ASSERT(z_order >= bgs::min_z_order() && z_order <= bgs::max_z_order(), "Invalid z order: ", z_order);

        item->bg_sort_key.set_z_order(z_order);
        erase(data.items_vector, item);
        _insert_item(*item);
    }
}

void put_above(id_type id)
{
    auto item = static_cast<item_type*>(id);
    sort_key this_sort_key = item->bg_sort_key;
    bool order_modified = false;

    for(int index = 0, limit = data.items_vector.size() - 1; index < limit; ++index)
    {
        item_type*& current_item_ptr = data.items_vector[index];

        if(current_item_ptr == item)
        {
            item_type*& next_item_ptr = data.items_vector[index + 1];

            if(next_item_ptr->bg_sort_key == this_sort_key)
            {
                swap(current_item_ptr, next_item_ptr);
                order_modified = true;
            }
            else
            {
                break;
            }
        }
    }

    if(order_modified && item->visible)
    {
        data.rebuild_handles = true;
    }
}

void put_below(id_type id)
{
    auto item = static_cast<item_type*>(id);
    sort_key this_sort_key = item->bg_sort_key;
    bool order_modified = false;

    for(int index = data.items_vector.size() - 1; index > 0; --index)
    {
        item_type*& current_item_ptr = data.items_vector[index];

        if(current_item_ptr == item)
        {
            item_type*& previous_item_ptr = data.items_vector[index - 1];

            if(previous_item_ptr->bg_sort_key == this_sort_key)
            {
                swap(current_item_ptr, previous_item_ptr);
                order_modified = true;
            }
            else
            {
                break;
            }
        }
    }

    if(order_modified && item->visible)
    {
        data.rebuild_handles = true;
    }
}

bool wrapping_enabled(id_type id)
{
    auto item = static_cast<const item_type*>(id);
    return hw::bgs::wrapping_enabled(item->handle);
}

void set_wrapping_enabled(id_type id, bool wrapping_enabled)
{
    auto item = static_cast<item_type*>(id);
    hw::bgs::set_wrapping_enabled(wrapping_enabled, item->handle);
    _update_item(*item);
}

bool mosaic_enabled(id_type id)
{
    auto item = static_cast<const item_type*>(id);
    return hw::bgs::mosaic_enabled(item->handle);
}

void set_mosaic_enabled(id_type id, bool mosaic_enabled)
{
    auto item = static_cast<item_type*>(id);
    hw::bgs::set_mosaic_enabled(mosaic_enabled, item->handle);
    _update_item(*item);
}

regular_bg_attributes regular_attributes(id_type id)
{
    return regular_bg_attributes(regular_map(id), priority(id), mosaic_enabled(id));
}

affine_bg_attributes affine_attributes(id_type id)
{
    return affine_bg_attributes(affine_map(id), priority(id), wrapping_enabled(id), mosaic_enabled(id));
}

void set_regular_attributes(id_type id, const regular_bg_attributes& attributes)
{
    set_regular_map(id, attributes.map());
    set_priority(id, attributes.priority());
    set_mosaic_enabled(id, attributes.mosaic_enabled());
}

void set_affine_attributes(id_type id, const affine_bg_attributes& attributes)
{
    set_affine_map(id, attributes.map());
    set_priority(id, attributes.priority());
    set_wrapping_enabled(id, attributes.wrapping_enabled());
    set_mosaic_enabled(id, attributes.mosaic_enabled());
}

bool blending_enabled(id_type id)
{
    auto item = static_cast<const item_type*>(id);
    return item->blending_enabled;
}

void set_blending_enabled(id_type id, bool blending_enabled)
{
    auto item = static_cast<item_type*>(id);
    item->blending_enabled = blending_enabled;

    if(! data.rebuild_handles && item->visible)
    {
        display_manager::set_blending_bg_enabled(item->handles_index, blending_enabled);
    }
}

bool visible(id_type id)
{
    auto item = static_cast<const item_type*>(id);
    return item->visible;
}

void set_visible(id_type id, bool visible)
{
    auto item = static_cast<item_type*>(id);

    if(visible != item->visible)
    {
        item->visible = visible;
        data.rebuild_handles = true;
    }
}

const optional<camera_ptr>& camera(id_type id)
{
    auto item = static_cast<const item_type*>(id);
    return item->camera;
}

void set_camera(id_type id, camera_ptr&& camera)
{
    auto item = static_cast<item_type*>(id);

    if(camera != item->camera)
    {
        item->camera = move(camera);

        if(item->regular_map)
        {
            item->update_regular_hw_position();
        }
        else
        {
            item->update_affine_camera();
        }

        _update_item(*item);
    }
}

void remove_camera(id_type id)
{
    auto item = static_cast<item_type*>(id);

    if(item->camera)
    {
        item->camera.reset();

        if(item->regular_map)
        {
            item->update_regular_hw_position();
        }
        else
        {
            item->update_affine_camera();
        }

        _update_item(*item);
    }
}

void update_cameras()
{
    for(item_type* item : data.items_vector)
    {
        if(item->camera)
        {
            if(item->regular_map)
            {
                item->update_regular_hw_position();
            }
            else
            {
                item->update_affine_camera();
            }

            _update_item(*item);
        }
    }
}

void update_regular_map_tiles_cbb(int map_id, int tiles_cbb)
{
    for(item_type* item : data.items_vector)
    {
        if(item->regular_map->id() == map_id)
        {
            hw::bgs::set_tiles_cbb(tiles_cbb, item->handle);
            _update_item(*item);
        }
    }
}

void update_affine_map_tiles_cbb(int map_id, int tiles_cbb)
{
    for(item_type* item : data.items_vector)
    {
        if(item->affine_map->id() == map_id)
        {
            hw::bgs::set_tiles_cbb(tiles_cbb, item->handle);
            _update_item(*item);
        }
    }
}

void update_regular_map_palette_bpp(int map_id, bpp_mode bpp)
{
    for(item_type* item : data.items_vector)
    {
        if(item->regular_map->id() == map_id)
        {
            hw::bgs::set_bpp(bpp, item->handle);
            _update_item(*item);
        }
    }
}

void reload()
{
    data.commit = true;
}

void fill_hblank_effect_regular_positions(int base_position, const fixed* positions_ptr, uint16_t* dest_ptr)
{
    if(base_position == 0)
    {
        for(int index = 0, limit = display::height(); index < limit; ++index)
        {
            dest_ptr[index] = uint16_t(positions_ptr[index].right_shift_integer());
        }
    }
    else
    {
        for(int index = 0, limit = display::height(); index < limit; ++index)
        {
            dest_ptr[index] = uint16_t(base_position + positions_ptr[index].right_shift_integer());
        }
    }
}

void fill_hblank_effect_pivot_horizontal_positions(id_type id, const fixed* positions_ptr, unsigned* dest_ptr)
{
    constexpr int right_shift = fixed::precision() - hw::bgs::affine_precision;

    auto item = static_cast<item_type*>(id);
    int base_dx = item->affine_mat_attributes.dx_register_value();
    int pb = item->affine_mat_attributes.pb_register_value();


    for(int index = 0, limit = display::height(); index < limit; ++index)
    {
        int result = base_dx + (positions_ptr[index].data() >> right_shift);
        dest_ptr[index] = unsigned(result);
        base_dx += pb;
    }
}

void fill_hblank_effect_pivot_vertical_positions(id_type id, const fixed* positions_ptr, unsigned* dest_ptr)
{
    constexpr int right_shift = fixed::precision() - hw::bgs::affine_precision;

    auto item = static_cast<item_type*>(id);
    int base_dy = item->affine_mat_attributes.dy_register_value();
    int pd = item->affine_mat_attributes.pd_register_value();

    for(int index = 0, limit = display::height(); index < limit; ++index)
    {
        int result = base_dy + (positions_ptr[index].data() >> right_shift);
        dest_ptr[index] = unsigned(result);
        base_dy += pd;
    }
}

void fill_hblank_effect_regular_attributes(id_type id, const regular_bg_attributes* attributes_ptr, uint16_t* dest_ptr)
{
    auto item = static_cast<item_type*>(id);
    [[maybe_unused]] bn::size current_dimensions = item->regular_map->dimensions();
    uint16_t bg_cnt = item->handle.cnt;

    for(int index = 0, limit = display::height(); index < limit; ++index)
    {
        const regular_bg_attributes& attributes = attributes_ptr[index];
        const regular_bg_map_ptr& attributes_map = attributes.map();
        BN_ASSERT(current_dimensions == attributes_map.dimensions(), "Map dimensions mismatch");

        uint16_t dest_cnt = bg_cnt;
        hw::bgs::set_tiles_cbb(attributes_map.tiles().cbb(), dest_cnt);
        hw::bgs::set_map_sbb(attributes_map.id(), dest_cnt);
        hw::bgs::set_bpp(attributes_map.bpp(), dest_cnt);
        hw::bgs::set_priority(attributes.priority(), dest_cnt);
        hw::bgs::set_mosaic_enabled(attributes.mosaic_enabled(), dest_cnt);
        dest_ptr[index] = dest_cnt;
    }
}

void fill_hblank_effect_affine_attributes(id_type id, const affine_bg_attributes* attributes_ptr, uint16_t* dest_ptr)
{
    auto item = static_cast<item_type*>(id);
    [[maybe_unused]] bn::size current_dimensions = item->affine_map->dimensions();
    uint16_t bg_cnt = item->handle.cnt;

    for(int index = 0, limit = display::height(); index < limit; ++index)
    {
        const affine_bg_attributes& attributes = attributes_ptr[index];
        const affine_bg_map_ptr& attributes_map = attributes.map();
        BN_ASSERT(current_dimensions == attributes_map.dimensions(), "Map dimensions mismatch");

        uint16_t dest_cnt = bg_cnt;
        hw::bgs::set_tiles_cbb(attributes_map.tiles().cbb(), dest_cnt);
        hw::bgs::set_map_sbb(attributes_map.id(), dest_cnt);
        hw::bgs::set_priority(attributes.priority(), dest_cnt);
        hw::bgs::set_wrapping_enabled(attributes.wrapping_enabled(), dest_cnt);
        hw::bgs::set_mosaic_enabled(attributes.mosaic_enabled(), dest_cnt);
        dest_ptr[index] = dest_cnt;
    }
}

void update()
{
    if(data.rebuild_handles)
    {
        int affine_bgs_count = 0;
        data.rebuild_handles = false;
        data.commit = true;

        for(item_type* item : data.items_vector)
        {
            if(item->affine_map && item->visible)
            {
                ++affine_bgs_count;
            }
        }

        BN_ASSERT(affine_bgs_count <= hw::bgs::affine_count(), "Too much affine BGs on screen");

        int regular_id;
        int affine_id;
        display_manager::set_mode(affine_bgs_count);
        display_manager::disable_all_bgs();
        display_manager::update_windows_visible_bgs();

        switch(affine_bgs_count)
        {

        case 0:
            regular_id = hw::bgs::count() - 1;
            affine_id = -1;
            break;

        case 1:
            regular_id = hw::bgs::count() - 3;
            affine_id = hw::bgs::count() - 2;
            break;

        default:
            regular_id = -1;
            affine_id = hw::bgs::count() - 1;
            break;
        }

        for(item_type* item : data.items_vector)
        {
            if(item->visible)
            {
                int id;

                if(item->affine_map)
                {
                    id = affine_id;
                    --affine_id;
                }
                else
                {
                    BN_ASSERT(regular_id >= 0, "Too much regular BGs on screen");

                    id = regular_id;
                    --regular_id;
                }

                item->handles_index = int8_t(id);
                data.handles[id] = item->handle;
                display_manager::set_bg_enabled(id, true);
                display_manager::set_blending_bg_enabled(id, item->blending_enabled);
            }
            else
            {
                item->handles_index = -1;
            }
        }
    }
}

void commit()
{
    if(data.commit)
    {
        hw::bgs::commit(data.handles);
        data.commit = false;
    }
}

void commit_big_maps()
{
    for(item_type* item : data.items_vector)
    {
        if(item->big_map)
        {
            bool is_regular = item->regular_map.has_value();
            int old_map_x = item->old_big_map_x;
            int old_map_y = item->old_big_map_y;
            int new_map_x;
            int new_map_y;

            if(is_regular)
            {
                new_map_x = item->hw_position.x() >> 3;
                new_map_y = item->hw_position.y() >> 3;
            }
            else
            {
                point affine_map_position = item->affine_map_position();
                new_map_x = affine_map_position.x();
                new_map_y = affine_map_position.y();

                if(new_map_x % 2)
                {
                    --new_map_x;
                }
            }

            new_map_x = min(new_map_x, (item->half_dimensions.width() / 4) - 32);
            new_map_y = min(new_map_y, (item->half_dimensions.height() / 4) - 22);

            int map_handle = is_regular ? item->regular_map->handle() : item->affine_map->handle();
            bool full_commit_big_map = item->full_commit_big_map || bg_blocks_manager::must_commit(map_handle);
            bool commit_big_map = full_commit_big_map;

            if(! commit_big_map && item->commit_big_map && item->visible)
            {
                commit_big_map = old_map_x != new_map_x || old_map_y != new_map_y;
            }

            if(commit_big_map)
            {
                item->old_big_map_x = uint16_t(new_map_x);
                item->old_big_map_y = uint16_t(new_map_y);
                item->commit_big_map = false;
                item->full_commit_big_map = false;

                if(full_commit_big_map || bn::abs(new_map_x - old_map_x) > 8 || bn::abs(new_map_y - old_map_y) > 8)
                {
                    if(is_regular)
                    {
                        bg_blocks_manager::set_regular_map_position(map_handle, new_map_x, new_map_y);
                    }
                    else
                    {
                        bg_blocks_manager::set_affine_map_position(map_handle, new_map_x, new_map_y);
                    }
                }
                else
                {
                    if(is_regular)
                    {
                        while(new_map_x < old_map_x)
                        {
                            --old_map_x;
                            bg_blocks_manager::update_regular_map_col(map_handle, old_map_x, new_map_y);
                        }

                        while(new_map_x > old_map_x)
                        {
                            ++old_map_x;
                            bg_blocks_manager::update_regular_map_col(map_handle, old_map_x + 31, new_map_y);
                        }

                        while(new_map_y < old_map_y)
                        {
                            --old_map_y;
                            bg_blocks_manager::update_regular_map_row(map_handle, new_map_x, old_map_y);
                        }

                        while(new_map_y > old_map_y)
                        {
                            ++old_map_y;
                            bg_blocks_manager::update_regular_map_row(map_handle, new_map_x, old_map_y + 21);
                        }
                    }
                    else
                    {
                        while(new_map_x < old_map_x)
                        {
                            --old_map_x;
                            bg_blocks_manager::update_affine_map_col(map_handle, old_map_x, new_map_y);
                        }

                        while(new_map_x > old_map_x)
                        {
                            ++old_map_x;
                            bg_blocks_manager::update_affine_map_col(map_handle, old_map_x + 31, new_map_y);
                        }

                        while(new_map_y < old_map_y)
                        {
                            --old_map_y;
                            bg_blocks_manager::update_affine_map_row(map_handle, new_map_x, old_map_y);
                        }

                        while(new_map_y > old_map_y)
                        {
                            ++old_map_y;
                            bg_blocks_manager::update_affine_map_row(map_handle, new_map_x, old_map_y + 21);
                        }
                    }
                }
            }
        }
    }
}

void stop()
{
    data.rebuild_handles = false;
    data.commit = false;
    hw::bgs::stop();
}

}
