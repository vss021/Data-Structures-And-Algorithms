/*
drow the following pattern
    * 
   * *
 * * * *
* * * * *
 * * * *
   * *
    * 
*/

#include <iostream>
using namespace std;
void patternHealper(int n)
{
    int i, j;
    // uper half
      for(i=n; i>=1; i--){
            
            for(j=1; j<=i; j++){
                  cout<<"  ";
            }
            for(j= 2*(n-i); j>=0; j--){
                  cout<<"* ";
            }
            for(j=1; j<=n; j++){
                  cout<<"  ";
            }
            
            cout<<endl;

      }

//  lower half
      for(i=1; i<=n; i++){
            
            for(j=0; j<=i; j++){
                  cout<<"  ";
            }
            for(j= 2*(n-i) -1; j>=1; j--){
                  cout<<"* ";
            }
            for(j=1; j<=n; j++){
                  cout<<"  ";
            }
            
            cout<<endl;
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