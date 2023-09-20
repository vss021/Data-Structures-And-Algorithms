#include <iostream>
using namespace std;

/*
tc => O(logN) for insertion and deletion
sp = 
*/

class heap{
    public:

    int arr[100];
    int size = 0;

    heap(){
        arr[0] = -1;
        size = 0;
    }
    
    
    void insert(int val)
    {
        size = size+1;

        int index = size;

        arr[index] = val;

        while(index > 1){

            int parent = index/2;

            if(arr[parent] < arr[index]){

                swap(arr[parent], arr[index]);
                index = parent;

            }else{
                return ;
            }
        }
    }

    void print()
    {
        for(int i=1; i<=size; i++)
        {
            cout<< arr[i] << " ";
        }
        cout << endl;
    }

    /*
        Delete Node => Delete Root Node

                    -> Deleting root 
                        -> swap first and last Node
                                    or
                        -> arr[1]  = arr[size]
                    



    */

    void deleteFromHeap()
    {
        if(size == 0){
            cout << "heap is empty " << endl;
        }

        // step1. put last index into first index
        arr[1] = arr[size];
        // step2. remove last index
        size--;

        // step3:
        //      -> take root node to its correct position

        int i = 1;

        while(i<size)
        {

            int leftNodeIndex = 2*i;
            int rightNodeIndex = 2*i + 1;

            if(leftNodeIndex < size && arr[i] < arr[leftNodeIndex]){

                swap(arr[i], arr[leftNodeIndex]);

                i = leftNodeIndex; // update i to left index

            }
            else if(rightNodeIndex < size && arr[i] < arr[rightNodeIndex])
            {
                swap(arr[i], arr[rightNodeIndex]);
                i = rightNodeIndex;
            }
            else{
                return ;
            }
        }
        // 
    }
};
/*
heapify for max-Heap
tc => for every element we take 
        O(longN)
    so 
    total tc will we O(NlongN)

sp => O(N)
    in heapify we divided array into two part's
        
        -> after (n/2) index's elements are leaf node which are already follow heap proparty

        -> we traverse in arr from n/2 to 1 
                -> check it follow heap proparties or not 
*/

void maxHeapify(int arr[], int n, int i)
{
    int largest = i; // assume i'th index element is larget
    int left = 2*i; // left child node index
    int right = 2*i +1 ; // right child index


    // case 1 : if left child is greater then largest index's elemtn

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    // case 2: if right child is greater

    if(right < n && arr[largest] < arr[right]){
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

/*                : Note :  
    min heap follow 0 base indexing

        so 
            left node index will we 
               => n/2+1
            right node index will we 
               => n/2+2
*/

void minHeapify(int arr[], int n, int i)
{
    int smalest = i;
    int leftIndex = n/2+1;
    int rightIndex = n/2+2;
    // case 1 : left is smaller then 
    if(leftIndex < n && arr[smalest] > arr[leftIndex]){
        smalest = leftIndex;
    }
    // case 2
    if(rightIndex < n && arr[smalest] > rightIndex){
        smalest = rightIndex;
    }

    // case 3

    if(smalest != i){
        swap(arr[smalest], arr[i]);

        minHeapify(arr, n, smalest);
    }else{
        return ;
    }




}
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteFromHeap();
    
    h.print();
    h.deleteFromHeap();

    h.print();
    h.deleteFromHeap();

    h.print();
    h.deleteFromHeap();

    h.print();
    h.deleteFromHeap();

    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i> 0 ; i--)
    {
        maxHeapify(arr, n, i);
    }

    cout << "printing the array now " << endl;

    for(int i = 1; i<=5; i++){
        cout<< arr[i]<< " ";
    }
    cout << endl;

    for(int i = n/2; i>=0 ; i--)
    {
        minHeapify(arr, n, i);
    }

    cout << "printing the array now " << endl;

    for(int i = 0; i<=5; i++){
        cout<< arr[i]<< " ";
    }
    cout << endl;
    
    return 0;
}