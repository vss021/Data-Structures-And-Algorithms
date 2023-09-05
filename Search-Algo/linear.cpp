#include <iostream>

using namespace std;

void linearSearch(int size, int arr[], int key)
{

    for(int i=0; i<size; i++)
    {

        if(arr[i]==key){
            cout<< "Element is present at the index : "<< i+1 << endl;
            break;
        }
    }

    cout<< "Element is not present in the given Array !"<< endl;
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

    linearSearch(size, arr, el);

    
    return 0;
}

