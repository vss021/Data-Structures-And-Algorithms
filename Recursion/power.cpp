#include <iostream>
using namespace std;

int power(int a, int b) {
    /*
    Time Complexity (TC):
The time complexity of the power function is logarithmic with respect to the exponent b.
 In each recursive call, the exponent b is halved (b / 2), resulting in a binary tree-like recursion. 
 The depth of the recursion tree is proportional to the number of bits required to represent b. Therefore, 
 the time complexity is O(log b), where b is the exponent.

Space Complexity (SP):
The space complexity of the power function is determined by the maximum depth of the recursion stack. 
Since at each level of recursion, the problem is divided into two smaller subproblems, 
the maximum depth of the recursion is O(log b), where b is the exponent. Additionally, 
the space complexity is also influenced by the space used for the function's local variables, 
which is constant for each level of recursion. 
Therefore, the space complexity is O(log b).
    */
    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    // Recursive call to calculate a^(b/2)
    int ans = power(a, b / 2);

    // If b is even, return ans * ans
    if (b % 2 == 0)
        return ans * ans;
    // If b is odd, return a * ans * ans
    else
        return a * ans * ans;
}

int main(){

    int a, b;
    cin>>a>>b;

   int ans = power(a, b);

    cout<< "ans is : "<< ans << endl;
    
} // namespace std;
