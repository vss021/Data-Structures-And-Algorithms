// Q. Write a program to reverse an array or string??

#include <iostream>
using namespace std;

// method 1.
// Iterative way

void IterativeFunctions(int arr[], int size)
{
    // iterat Solution

    for(int i=size-1; i>=0; i--)
    {
        cout << arr[i] << " ";
    }
}

void RecursiveFunction(int arr[], int size)
{

    // base case 
    if(size == 0){
        cout<< arr[0]<< " ";
        return;
    }

    cout<< arr[size]<< " ";
    RecursiveFunction(arr, size-1);

}
/**

Time Complexity: O(n)
Auxiliary Space: O(n), due to recursive call stack
*/
void reverseFunctions(int arr[], int size)
{
    cout<< "Iterative Solution" << endl;
    IterativeFunctions(arr, size);
    cout<< " \n Recursize Solution" << endl;
    RecursiveFunction(arr, size-1);

}

int main(){

    int size;
    cout << " Enter size of array " << endl;
    cin >> size;

    int arr[size];
    cout << " Enter lements in array : " << endl;
    for(int i=0; i<size; i++)
    {
        cin >> arr[i];
    }

    reverseFunctions(arr, size);


    
    return 0;
}