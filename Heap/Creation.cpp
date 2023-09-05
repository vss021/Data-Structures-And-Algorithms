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
    return 0;
}