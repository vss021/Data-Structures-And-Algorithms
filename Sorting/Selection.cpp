// Impliment the Selection sort

#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
selection sort
    => for i traverse next n-i 
        => check if next one is smaller the i'th element then store it to variable
        => swap the variable when second inner loop exit

        in selection sort there is only one swapping or each element
        
*/

void printArray(int size, int array[]){
    cout<< "Result : " << endl;
    for(int i=0; i<size; i++)
    {
        cout<< array[i] << " ";
    }
}

void selection(int size, int array[])
{

    for(int i=0; i<size-1; i++)
    {
        int index = i;
        for(int j=i+1; j<size; j++)
        {

            if(array[j] < array[index]) index = j;
        }

        if(index != i){
            // swap values
            swap(&array[i], &array[index]);
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
    selection(size, array);



    return 0;
}