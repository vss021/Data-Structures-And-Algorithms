/*
drow the following pattern
* * * * *
* * * *
* * *
* *
*
*/

#include <iostream>
using namespace std;

void patternHealper(int num)
{
    for(int i=num; i>= 0; i--)
    {
        for(int j = 0; j<= i; j++ )
        {
            cout<< "* ";
        }
        cout<< endl;

    }
}
int main()
{
    cout << "Enter the NUmber : "<< endl;
    int num;
    cin>> num;

    patternHealper(num);

    return 0;
}