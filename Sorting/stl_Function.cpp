#include <iostream>
#include <algorithm>

using namespace std;

struct Interval{
    int st;
    int ed;
};

bool compare(Interval i1, Interval i2){
    return  i1.ed < i2.ed;
}

int main()
{

    // Interval arr[] = {{1, 5}, {8, 10}, {3, 8}, {2, 9}};
    int arr[] = {1, 8, 6, 5, 3, 4};

    // sort as start time

    // sort(arr, arr+4, compare);
    sort(arr, arr+6);

    // for(auto x : arr)
    // {
    //     cout<< "start : " << x.st << "End time " << x.ed << endl;
    // }

    cout<< "Binary_search" << endl;

    // this will return the true (1) for present ot 0 (false) for not present
    cout<< binary_search(arr, arr+6, 3) << endl;
    /*
    // if we need to index of the element
    // then we use
    // lower_bound function
    // 
        lower_bound(arr, arr+6, 8)
        this mean arr index till 6 we need to find the 8 elemtn
        it simpaly return the pointer(lovcation) of the 8 element

        if we write the 

        lower_bound(arr, arr+6, 4) -arr ,

        then it will give the index of element 


        */

        cout << " index of 4 elemtn :" << lower_bound(arr, arr+6, 4)-arr << endl;

        //=>  element is not present in the array then it will give the next nearest element 
        // => if the array contain the repeted element then it give the first element index


        // upper bound

        cout<< "upper 4 bound" << upper_bound(arr, arr+6, 4) -arr << endl;

        cout << "gcd " << endl;

        cout<< __gcd(10, 4) << endl;

        // power

    return 0;
}
