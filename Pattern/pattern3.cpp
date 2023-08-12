/*
drow the following pattern
    * 
   * *
 * * * *
* * * * *
*/

#include <iostream>
using namespace std;
void patternHealper(int n)
{
    for(int i=n; i>=0; i--)
    {
        // space printing
        for(int j=0; j<=i; j++){
            cout<< " ";
        }
        for(int j=i; j<=n; j++){
            cout<< "* ";
        }
        cout<< endl;
    }
}
int main()
{

    cout<< "Enter the Num : "<<endl;
    int n;
    cin>> n;
    patternHealper(n);

    return 0;
}