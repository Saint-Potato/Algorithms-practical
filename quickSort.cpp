#include<iostream>

int L_partition(int *arr, int f, int l){
    int pivot = arr[l]; // sets last element as pivot
    int i = f - 1;      // i keeps count of first sub array, i.e. elements smaller than pivot

    for(int j = f; j < l; j++){  // j traverses through array and tells which elements have been compared against pivot
        if(arr[j] < = pivot){
            i++;
            swap(arr[i], arr[j]);    // if J-th element is smaller than pivot, it is swapped to last of first sub array, i.e. elements smaller than pivot and the sub array is extended
        }
    }

    swap(arr[i+1], arr[l]);   // pivot is swapped at end of first array, i.e. between 1st and 2nd sub array

    return i+1;                 // index of pivot is returned
}

void quickSort(int *arr, int f, int l){
    if(f >= l){                     // base condition 
        return;
    }

    int p = L_partition(arr, f, l);                      // partition into 2 sub arrays such that element of first sub array are smaller than all element of 2nd sub array

    quickSort(arr, f, p-1);                              // perform quickSort on first sub array
    quickSort(arr, p+1, l);                              // perform quickSort on 2nd sub array
}