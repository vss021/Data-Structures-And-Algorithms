#include <iostream>
using namespace std;


void heapifyForMaxHeap(int arr[], int n, int ind)
{

    int greatestNum = ind;
    
    // 1 base indexing that's whay it  
    int leftChild = 2*ind; 
    int rightChild = 2*ind+1;


    if(leftChild <= n && arr[leftChild] > arr[greatestNum] )
    {
        greatestNum = leftChild;
    }
    if(rightChild <= n && arr[rightChild] > arr[greatestNum])
    {
        greatestNum = rightChild;
    }


    // finaly replace 

    if(greatestNum != ind)
    {
        swap(arr[greatestNum], arr[ind]);

        // calls forther 
        heapifyForMaxHeap(arr, n, greatestNum);
    }
}

void heapifyForMinHeap(int arr[], int n, int i)
{

    int smalest = i;

    int left = 2*i;
    int right = 2*i+1;

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
        heapifyForMinHeap(arr, n, smalest);
    }else{
        return;
    }
    
}


void heapSort(int arr[], int n)
{
    int size = n;

    while(size>0)
    {

        // step 1
        swap(arr[size], arr[0]);

        size--;

        // heapifyForMaxHeap(arr, n, 1);
        heapifyForMinHeap(arr, n, 1);
    }
}




void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<< arr[i] << " ";
    }
}

int main()
{

    int n;
    cout << "Enter the Size of Array : "<< endl;
    cin >> n;

    int arr[n+1];

    cout << "Enter the element in  Array : "<< endl;
    arr[0] = -1;

    for(int i=1; i<=n; i++)
    {
        cin >> arr[i];
    }

    heapSort(arr, n);


    printArray(arr, n);

    return 0;
}