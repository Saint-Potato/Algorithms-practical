#include<iostream>
using namespace std;


int L_partition(int *arr, int f, int l){  // Lomuto partition
    int pivot = arr[l]; // sets last element as pivot
    int i = f - 1;      // i keeps count of first sub array, i.e. elements smaller than pivot

    for(int j = f; j < l; j++){  // j traverses through array and tells which elements have been compared against pivot
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);    // if J-th element is smaller than pivot, it is swapped to last of first sub array, i.e. elements smaller than pivot and the sub array is extended
        }
    }

    swap(arr[i+1], arr[l]);   // pivot is swapped at end of first array, i.e. between 1st and 2nd sub array

    return i+1;                 // index of pivot is returned
}

int H_partition(int *arr, int f, int l){
    int x = arr[f];
    int i = f - 1;
    int j = l + 1;

    while(true){
        do{
            j--;
        }
        while(arr[j] > x);

        do{
            i++;
        }
        while(arr[i] < x);

        if(i < j){
            swap(arr[i], arr[j]);
        }
        else{
            swap(arr[j], arr[f]);
            return j;
        }
    }
}

void quickSort(int *arr, int f, int l){
    if(f >= l){                     // base condition 
        return;
    }

    int p = H_partition(arr, f, l);                      // partition into 2 sub arrays such that element of first sub array are smaller than all element of 2nd sub array

    quickSort(arr, f, p-1);                              // perform quickSort on first sub array
    quickSort(arr, p + 1, l);                              // perform quickSort on 2nd sub array
}

int main(){
    int arr[6] = {8, 4, 2, 9, 12, 1};
    quickSort(arr, 0, 5);
    for(int i = 0; i < 6; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
