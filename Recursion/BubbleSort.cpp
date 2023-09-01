#include <iostream>
using namespace std;
void sortArray(int &arr, int n)
{
    if(n == 0|| n == 1)
    {
        return ;
    }

    // 1 case -largest element at the end

    for(int i=0; i<n-1; i++)
    {
        if(arr[i]> arr[i=1]){
            swap(arr[i], arr[i+1]);
        }
    }
    sortArray(arr, n-1);

}
int main(){

        int n;
        cout<< "Enter the size : " <<endl;
        cin>> n;
        int arr[n];
        cout<< "Enter the Elements : "<< endl;
        for(int i=0; i<n; i++)
        {
            cin>> arr[i];

        }
        cout<< "Function calls : "<< endl;
        
        sortArray(arr, n);

        cout<< "After the sorting "<< endl;

        for(int i =0; i<n; i++)
        {
            cout<< arr[i] << " ";
        } 
        cout<< endl;

    return 0;
    
} // namespace std;
