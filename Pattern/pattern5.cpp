/*
drow the following pattern
*
* *
* * *
* * * * *
* * *
* *
*
*
*/

#include <iostream>
using namespace std;

void patternHealper(int n)
{

        // upper half
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            cout<<"* ";
        }
        cout<< endl;

    }
    // lower half
    for(int i=n-1; i>=0; i--)
    {
        for(int j=i; j>0; j--)
        {
            cout<<"* ";
        }
        cout<< endl;

    }
}
int main()
{

    cout<< "Enter the Number :" << endl;
    int n;
    cin>> n;

    patternHealper(n);

    return 0;
}