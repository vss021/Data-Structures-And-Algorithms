// q Maximum and minimum of an array using minimum number of comparisons


#include <iostream>
#include <limit>
using namespace std;

// method 1.
// Iterative way

void MinMaxFuction(int arr[], int size)
{
    
    int maxi = INT_MIN;
    int nimi = INT_MAX;

    for(int i=0; i<size; i++)
    {
        main = min(main, arr[i]);
        maxi = min(maxi, arr[i]);
    }

    cout << "Maxi is :" << maxi << "mini is : "<< mini << endl;


}

/**

Time Complexity: O(n)
Auxiliary Space: O(1),
*/

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

    MinMaxFuction(arr, size);


    
    return 0;
}