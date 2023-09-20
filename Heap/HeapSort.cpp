#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i)
{
    int largest = i; // assume i'th index element is larget
    int left = 2*i; // left child node index
    int right = 2*i +1 ; // right child index


    // case 1 : if left child is greater then largest index's elemtn

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    // case 2: if right child is greater

    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    // case 3 : if largest index element is smaller then it's childs
    // then swap it

    if(largest != i){
        swap(arr[largest], arr[i]);
        // find the correct index of largest index value is next 
        maxHeapify(arr, n, largest);
    }


}

// min heap
void heapify(int arr[], int n, int i){

    int smalest = i;

    int left = 2*i+1;
    int right = 2*i+2;

    // case 1:
    if(left <= n && arr[smalest] > arr[left]){
        smalest = left;
    }
    // case 2:
    if(right <= n && arr[smalest] > arr[right]){
        smalest = right;
    }

    // case 3:
    if(smalest != i){
        swap (arr[smalest], arr[i]);
        heapify(arr, n, smalest);
    }else{
        return;
    }
}

void heapSort(int arr[], int n){
    int size = n;

    while(size > 1)
    {
        // step1:
        swap(arr[size], arr[1]);

        size--;

        // step2 call hepify
        maxHeapify(arr, size, 1);
    }
}

int main(){

    // int arr[6] = {-1, 84, 62, 76, 15, 34};
    int arr[5] = {54, 53, 55, 52, 50};

    heapSort(arr, 5);

    for(int i = 0; i<=5; i++){
        cout << arr[i]<< " ";
    }

    cout << endl;

    return 0;
}