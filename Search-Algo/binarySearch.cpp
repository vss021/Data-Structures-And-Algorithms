#include <iostream>

using namespace std;

void bimarySearch(int st, int end, int arr[], int key)
{

    int mid = st +(end-st)/2;

    while(st <= end)
    {
        if(arr[mid] == key){
            cout<< "Element is in the index : " << mid+1 << endl;
            break;
        }
        else if(arr[mid] > key){
            end = mid-1;
        }
        else{
            st = mid+1;
        }
        mid = st +(end-st)/2;
    }
    cout<< "Element is not present in the Array: "  << endl;
}
int main(){
    
    int size;
    cout<< "Enter the size : "<< endl;
    cin>> size; 

    int arr[size];

    cout<< "Enter the Array Element  : "<< endl;
    for(int i=0; i<size; i++)
    {
        cin>> arr[i];
    }

    cout << "Enter the Elment for Search :" << endl;
    int el;
    cin>>el;

    bimarySearch(0, size-1, arr, el);

    
    return 0;
}

