#include <iostream>
using namespace std;

/*
Time Complexity (TC):
In the worst case, the factorial function will make a recursive call for each positive integer from n down to 1.
 This results in a total of n recursive calls. Each recursive call performs a constant amount of work (multiplication and comparison),
  so the time complexity is proportional to the number of recursive calls, which is O(n).

Space Complexity (SP):
The space complexity of the recursive factorial function is determined by the maximum depth of the function call stack. 
Each recursive call adds a new frame to the call stack, and the depth of the stack corresponds to the number of active recursive calls. 
In this case, the maximum depth of the stack is n, which means the space complexity is O(n).
 
 
factorial function both tc ans Sp  becomes => O(n),


*/

//Recursize Solution

int factorial(int n)
{
    if(n == 0) // base contioon
        return 1;

    return n * factorial(n-1);
}

/*Iterative Approach:
    this function we iteative n time so 
    tc => O(N);
    sp => O(1)
*/
int ntFactorial(int n)
{
    int ans = 1;

    for(int i=2; i<=n; i++){
        ans *= i;
    }

    return ans;
}

int main()
{
    int n;
    cout<< "Enter the number : " << endl;
    cin>>n;
    
    cout << factorial(n); << endl;
    return 0;

} // namespace name
