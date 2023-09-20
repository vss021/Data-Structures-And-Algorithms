#include <iostream>
using namespace std;

int main()
{ 
    // dynamic allocation
    cout<<"Enter the row and colloms : "<<endl;
    int row, col;
    cin>>row>>col;

    // 2d- array
    int **arr = new int*[row];
    
    for(int i=0; i<row; i++){
        arr[i] = new int[col];
    }

    // taking input
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin>>arr[i][j];
        }
    }

    // 
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
        cout<< arr[i][j]<< "\t";
        }
        cout<< endl;
    }

    for(int i=0; i<row; i++){
        delete []arr[i];
    }
    delete []arr; 

    cout << *arr[0] << endl;

    
} // namespace std;

