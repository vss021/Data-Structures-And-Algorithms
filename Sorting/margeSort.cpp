#include <iostream>
using namespace std;

void mergTwoSortedArrays(int arr[], int start, int mid, int end)
{
    // finding the size 
    int sizeOfFirstArray = mid-start+1;
    int sizeOfSecondArray = end-mid;

// creating the two temp array
    int firstArray[sizeOfFirstArray];
    int secondArray[sizeOfSecondArray];

    // adding values in firstArray  and second Array form orignal array 
    for(int i=0; i<sizeOfFirstArray; i++)
    {
        firstArray[i] =arr[start+i];
    }
    for(int i=0; i<sizeOfFirstArray; i++)
    {
        secondArray[i] =arr[mid+1+i];
    }


    int index = start; 
    int i = 0;
    int j = 0;


    while(i<sizeOfFirstArray && j < sizeOfSecondArray)
    {

        if(firstArray[i]> secondArray[j])
        {
            arr[index++] = secondArray[j++];
        }
        else{
            arr[index++] = firstArray[i++];

        }
    }

// if first array is not empty but second array is empty then 
    while( i < sizeOfFirstArray){
        arr[index++] = firstArray[i++];
    }
// if Second array is not empty but first array is empty then 
    while( j < sizeOfFirstArray){
        arr[index++] = secondArray[j++];
    }


}


void mergeSort(int arr[], int start, int end)
{

    // condition
    if(start < end)
    {
        int mid = (start + end)/2;
        // left side

        mergeSort(arr, start, mid);

        // right side

        mergeSort(arr, mid+1, end);

        // merging two sorted array

        mergTwoSortedArrays(arr, start, mid, end);
    }
}

int main()
{

    int size;
    cout<< "Enter the size of array : " << endl; 
    cin>> size;

    int arr[size];

    cout<< "Array Element : "<<endl;

    for(int i=0; i<size; i++)
    {
        cin>> arr[i];
    }

    mergeSort(arr, 0, size-1);

    cout<< "sorted array is : " << endl;
    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
    }

    return 0;
}
