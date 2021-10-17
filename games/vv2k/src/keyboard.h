void keyboard() {
        bn::vector<char, 16> ss;
        bn::sprite_text_generator file1_gen(common::variable_8x16_sprite_font);
        bn::vector<bn::sprite_ptr, 16> file1_spr;
        auto velvet = bn::regular_bg_items::velvet.create_bg(0,0);
        auto ui = bn::regular_bg_items::keyboard_bg.create_bg(0,0);
        auto sel = bn::sprite_items::selection.create_sprite(-100, -18);
        char basis[96] = "abcdefghijklmnopqrstuvwxyz     -'&  ABCDEFGHIJKLMNOPQRSTUVWXYZ     -'&  ";
        auto x_state = 0, y_state = 0, t = 0, height = -64;
        auto lower = true;
        ui.set_y(64);

        while(!bn::keypad::start_pressed()) {

            if (bn::keypad::left_pressed()) {
                if ((basis[x_state - 1 + (y_state * 12)] != ' ') || (y_state == 2)) {
                    x_state--;
                    if (x_state < 0) x_state = 11;
                    sel.set_x(-100 + 18 * x_state);
                }
            } else if (bn::keypad::right_pressed()) {
                if ((basis[x_state + 1 + (y_state * 12)] != ' ') || (x_state > 8)) {
                    x_state++;
                    x_state = x_state % 12;
                    sel.set_x(-100 + 18 * x_state);
                }
            }
            if (bn::keypad::up_pressed()) {
                if (!(x_state > 1 && x_state < 7 && y_state == 0) || (x_state > 8)) {
                    y_state--;
                    if (y_state < 0) y_state = 2;
                    sel.set_y(-18 + 26 * y_state);
                }
            } else if (bn::keypad::down_pressed()) {
                if ((basis[x_state + ((y_state + 1) * 12)] != ' ') || (x_state > 8)) {
                    y_state++;
                    y_state = y_state % 3;
                    sel.set_y(-18 + 26 * y_state);
                }
            }

            if (bn::keypad::a_pressed()) {
                if (ss.size() < 16) {
                    bn::sound_items::pop.play();
                    file1_spr.clear();
                    int plus = 0;
                    if (!lower) plus = 36;
                    ss.push_back(basis[x_state + plus + (y_state * 12)]);
                    std::string s(ss.begin(), ss.end());
                    file1_gen.generate(-104, height, s.c_str(), file1_spr);
                } else {
                    bn::sound_items::firehit.play();
                }
            }

            if (bn::keypad::b_pressed()) {
                if (ss.size() > 0) {
                    ss.pop_back();
                    file1_spr.clear();
                    std::string s(ss.begin(), ss.end());
                    file1_gen.generate(-104, height, s.c_str(), file1_spr);
                    bn::sound_items::cnaut.play();
                } else {
                    bn::sound_items::firehit.play();
                }
            }

            if (bn::keypad::select_pressed()) {
                bn::sound_items::fireblast.play();
                file1_spr.clear();
                lower = !lower;
                height = height * -1;
                if (!lower) {
                    while(ui.y().integer() != 192) { //192, 204
                        int y = ui.y().integer() + 4;
                        y = y % 256;
                        ui.set_y(y);
                        bn::core::update();
                    }
                } else {
                    while(ui.y().integer() != 64) {
                        int y = ui.y().integer() + 4;
                        y = y % 256;
                        ui.set_y(y);
                        bn::core::update();
                    }
                }
                std::string s(ss.begin(), ss.end());
                file1_gen.generate(-104, height, s.c_str(), file1_spr);
                bn::sound_items::firehit.play();
            }
            
            // Scrolling background
            t = (t + 1) % 256;
            velvet.set_position(t,t);
            bn::core::update();
        }

        for (int tt = 0; tt < ss.size(); tt++) save::island_name.push_back(ss.at(tt));
}