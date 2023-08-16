/* calculate the total number of combinations of paths to reach the end position starting
 from the start position*/

#include <iostream>
using namespace std;

int CountPath(int start , int end){
    // if we reach to end position
    if(start == end){
        return 1;
    }
    // if trying to go after end potion 
    if(start > end){
        return 0;
    }
//  count of total combination

    int count = 0;
    
    for(int i=1; i<=end; i++){

        count += CountPath(start+i, end);
    }
    return count;
}

int main()
{
    int n;
    cout << "enter the n'th Number : "<< endl;
    cin>> n;

    cout<< "Ans is : " <<CountPath(0, n) << endl;
    return 0;
}