#include <stdio.h>

int main()
{
    int an_array[10] = {0}; // Initialize the whole thing to 0.
    int x, y, z;
    x = 11;
    y = 12;
    z = 13;

    //an_array[11] = 7; // Compiler error!
    an_array[x] = 0;  // No compiler error, but runtime error!

    return 0;
}