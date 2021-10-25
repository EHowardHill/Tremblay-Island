#include <sstream>

// Generic classes
class Concepts {
    public:
        class line {
            public:
                bool transition;
                bool left;
                int img = 0;
                char text[192];
        };
};

// Function to calculate the smallest multiple
int roundDown(int n) {
    return n >> 5;
}

int roundUp(int n) 
{
    return roundDown(n + 31);
}

int countDigit(int n)
{
    if (n/10 == 0)
        return 1;
    return 1 + countDigit(n / 10);
}

struct save_struct {
    int last_char_id = 0;
    int checkpoint = 0;
    char island_name[16] = {0};
    int level_data[10] = {0};
    int spawn_x = 0;
    int spawn_y = 0;
    int world_index = 0;

    int spring_housewarming = 0;
};

template<typename C, typename T>
bool contains(C&& c, T e) { 
    return std::find(std::begin(c), std::end(c), e) != std::end(c);
};