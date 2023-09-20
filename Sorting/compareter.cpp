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

    Interval arr[] = {{1, 5}, {8, 10}, {3, 8}, {2, 9}};

    // sort as start time

    sort(arr, arr+4, compare);

    for(auto x : arr)
    {
        cout<< "start : " << x.st << "End time " << x.ed << endl;
    }


    return 0;
}
