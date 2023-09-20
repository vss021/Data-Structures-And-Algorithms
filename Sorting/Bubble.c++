// Impliment the Bubble sort

/**
for i comare whole array next to then 
    => if next element comes smaller then it swap every time
    => multiple swapping is allow
*/

#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int size, int array[])
{
    cout<< "array is : " << endl;

    for(int i=0; i<size; i++)
    {
        cout<< array[i] << " ";
    }
}

void Bubble(int size, int array[])
{

    for(int i=0; i<size-1; i++)
    {

        for(int j=0; j<size-1-i; j++)
        {
            if(array[j+1]<array[j]){

                swap(&array[j+1], &array[j]);
                
            }
        }
    }
    printArray(size, array);
}
int main()
{
    int size;
    cout<< "Enter the size of Array : " << endl;
    cin >> size;

    int array[size];

    for(int i=0; i<size; i++)
    {
        cin>> array[i];
    }
    Bubble(size, array);


    return 0;
}