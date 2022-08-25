#include <stdio.h>

int main()
{
    int an_array[10] = {0}; // Initialize the whole thing to 0.

    int type_size = sizeof(int);
    int array_size = sizeof(an_array);
    int element_num = array_size / type_size;

    printf("       sizeof(int) = %2d bytes\n", type_size);
    printf("  sizeof(an_array) = %2d bytes\n", array_size);
    printf("  an_array[] has %d elements\n\n", element_num);

    // Dynamically allocate array size via initialization.

    float length_array[] = {1.0, 2.0, 3.0, 4.0, 3.0, 2.0, 1.0};

    int float_size = sizeof(float);
    int array_size2 = sizeof(length_array);
    int element_num2 = array_size2 / float_size;

    printf("     sizeof(float) = %d bytes\n", float_size);
    printf("  sizeof(an_array) = %d bytes\n", array_size2);
    printf("  an_array has %d elements\n", element_num2);
}