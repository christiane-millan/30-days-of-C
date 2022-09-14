#include "binary.h"

int binary_search(int *arr, int beg, int end, int item){
    if( beg <= end){
        int mid = beg + (end - beg) / 2;
        if (*(arr + mid) == item)
            return mid;
        
        if (*(arr + mid) > item){
            return binary_search(arr, beg, mid - 1, item);
        }

        return binary_search(arr, mid + 1, end, item);
    } 
    return -1;  
}