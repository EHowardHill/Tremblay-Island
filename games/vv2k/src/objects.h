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
int closestMultiple(int n, int x)
{  
    if(x>n)
    return x;

    n = n + x/2;
    n = n - (n%x);
    return n;
};

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
};