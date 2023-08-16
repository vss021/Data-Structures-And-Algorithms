#include <iostream>
using namespace std;

bool linearSearch(int *arr, int size, int key)
{
    if(size == 0){
        return false;
    }
    if(arr[0] == key)
    {
        return true;
    }

    return linearSearch(arr+1, size-1, key);
}

int getSum(int *arr, int size)
{
    // base case
    if(size == 0)
    {
        return 0;
    }

    if(size == 1)
    {
        return arr[0];
    }

    int remainingPart = getSum(arr+1, size-1);
    int getSum = arr[0]+ remainingPart;
    return getSum;
     
}
bool isSorted(int *arr, int size){


    if(size == 0 || size == 1)
    {
        // return true;
        return true;
    }
    if(arr[0]> arr[1])
    {
        return false;
    }
    else{
        bool ans = isSorted(arr + 1 , size-1);
        return ans;
    }
}
int main(){
    
    int arr[5] = {1, 2 , 30, 4, 5};

    bool ans = isSorted(arr, 5);

    if(ans){
        cout<< "array is sorted !" << endl;
    }else{
        cout<< "array is not sorted " << endl;
    }

    cout<< "sum is : "<< getSum(arr, 5)  << endl;
    if(linearSearch(arr, 5, 5)){
    cout << "5 is present  ! " << endl;
    }else{
        cout<< "NO "<< endl;
    }

} 
