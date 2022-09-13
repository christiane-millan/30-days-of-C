#include "quick_sort.h"

void quick_sort(int *arr, int beg, int end){
    if (beg < end)
    {
        int pi = partition (arr, beg, end);
        quick_sort(arr, beg, pi - 1);
        quick_sort(arr, pi + 1, end);
    }
}

int partition( int *arr, int beg, int end){
    int pivot = *(arr +end);
    int i = (beg - 1);
    for (int  j = beg; j < end; j++)
    {
        if (*(arr + j) < pivot)
        {
            i++;
            swap((arr + i) , (arr + j));
        }
    }
    swap((arr + (i + 1)), (arr + end));
    return (i + 1);
}

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}