#include<iostream>
#include<cmath>

using namespace std;

int Left(int i){
    return 2*i;
}

int Right(int i){
    return 2*i+1;
}

void Heapify(int* arr,int size, int i){

    int largest = i;
    int l = Left(i);
    int r = Right(i);

    if(l <= size && arr[l] > arr[largest]){
        largest = l;
    }

    if(r <= size && arr[r] > arr[largest]){
        largest = r;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        Heapify(arr, size, largest);
    }

}

void BuildMaxHeap(int* arr, int size){
    for(int i = 1; i < floor(size-1, 2)){
        Heapify(int* arr, int i);
    }
}

void HeapSort(int *arr, int size){
    int heapSize = size;
    for(int i = 1; i < size; i++){
        swap(arr[1], A[heapSize]);
        heapSize--;
        Heapify(int* arr, int size, 1);
    }
}

int main(){

    return 0;
}
