#include <iostream>
using namespace std;

    int partition (int arr[], int start, int end)
    {
       int pivot = arr[start];
       
       int count = 0; // counter to count the element which are smaller than pivot
       
       // <= cause we are going to check upto last element and start+1 
       //because we dont want to consider the first element again
       for(int i = start + 1 ; i <= end ; i++) 
       {
           if(arr[i] <= pivot)
           {
               count++;
           }
       }
       
       
       int pivotindex = start + count; // the index at which we are going to place the pivot
       
       swap(arr[pivotindex] , arr[start]); // as pivot is always our first element
       
       // balancing the left and right elemens of the pivot
       
       int i = start;

       
       int j = end;
       
       // equal sign because there may be chances that there are elements which are equal to our pivot
       //but obviously there are not elements greater than pivot on right side as we have
       //manipulate in earlier condition
       while(i < pivotindex && j > pivotindex)
       {
           while(arr[i] <= arr[pivotindex]) 
           {
               i++;
           }
           
           while(arr[j] > arr[pivotindex])
           {
               j--;
           }
           
           if(i < pivotindex && j > pivotindex)
           {
               swap(arr[i++] , arr[j--]); // we increment this because the ith and jthindx are now swapped
           }
       }
       
       return pivotindex;
    }

    void quickSort(int arr[], int start, int end)
    {
        if(start >= end)
        {
            return;
        }
        
        // this value will give us the index at which our pivot is placed
        int pivotindex = partition(arr,start,end);
        
        // sort the left part of the pivot
        quickSort(arr,start,pivotindex-1);
        // p-1 because we wnat sort the left part of the pivot
        
        // sorting the right part of the pivot
        quickSort(arr,pivotindex+1,end);
        
        
        
    }

int main()
{
    int size;
    cout<< "Enter the size : "<< endl;
    cin>> size; 

    int arr[size];

    cout<< "Enter the Array Element  : "<< endl;
    for(int i=0; i<size; i++)
    {
        cin>> arr[i];
    }

    // int arr[5] = {10, 5, 4, 25, 1};
    quickSort(arr, 0, size); 
    

    for(int i=0; i<size; i++)
    {
        cout<< arr[i] << " ";
    }
    cout<< endl;

    

}