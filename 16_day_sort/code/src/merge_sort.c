#include "merge_sort.h"

void merge_sort(int *arr, int beg, int end){
    if (beg < end){
        int mid = beg + (end - beg) / 2;

        merge_sort(arr, beg, mid);
        merge_sort(arr, mid + 1, end);

        merge(arr, beg, mid, end);
    }
}

void merge(int *arr, int left, int mid, int right){
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // create temp array 
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];   
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = left;
    while( i < n1 && j < n2 ){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[]
    while( j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}