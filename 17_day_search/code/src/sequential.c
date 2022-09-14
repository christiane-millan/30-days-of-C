#include "sequential.h"

int sequential_search(int *arr, int size, int item){
    int i;
    for (i = 0; i < size; i++)
    {
        if (*(arr + i) == item)
        {   
            return i;
        }
    }
    return -1;
}