#include <stdio.h>
#include <string.h>

class Dialogue {
    public:
        class line {
            public:
                bool transition;
                bool left;
                int img = 0;
                std::string text;
        };
};