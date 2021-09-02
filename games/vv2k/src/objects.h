#include <sstream>

// Generic classes
class Concepts {
    public:
        class line {
            public:
                bool transition;
                bool left;
                int img = 0;
                char text[198];
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