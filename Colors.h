#include <iostream>
using std::cout;

// Quick little struct to change console colors
struct Colors {
    inline void setRed() {
        cout << red;
    }

    inline void setGreen() {
        cout << green;
    }

    inline void setYellow() {
        cout << yellow;
    }

    inline void setNormal() {
        cout << normal;
    }

private:
    const char *red = "\033[31m";
    const char *green = "\033[32m";
    const char *yellow = "\033[33m";
    const char *normal = "\033[0m";
};