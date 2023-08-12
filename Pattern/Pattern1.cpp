
/*
show this pattern
*
* *
* * *
* * * *
*/

#include <bits/stdc++.h>
using namespace std;


void patternHealper(int num)
{
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<=i; j++){
            cout<< "* ";
        }
        cout<< endl;
    }
}

int main()
{
    cout<< "Enter the Number : "<< endl;
    int Num;
    cin>> Num;

    patternHealper(Num);
    return 0;
}