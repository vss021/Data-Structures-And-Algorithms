#include <iostream>
using namespace std;
class Solution {
public:
    // Function to calculate the GCD using Euclidean algorithm for two numbers

    // iterative approach 
    /*
    In the worst case, the number of iterations is 
    log(min(a, b)) (logarithmic time complexity).
    space complexity is O(1)
    */
    int gcdUsingLoop(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Recursive approach
/*recursive approach has a space complexity & TC  
O(log(min(a, b))) due to the function call stack*/
    int gcdUsingRecursive(int a, int b)
    {
        // base case
        if(a == 0){
            return b;
        }
        return gcdUsingRecursive(a%b, a);
    }


    
};

int main() {
    Solution solution;
    int num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // Calculate and display the GCD
    int result1 = solution.gcdUsingLoop(num1, num2);
    int result2 = solution.gcdUsingRecursive(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " is: " << result1 << endl;
    cout << "GCD of " << num1 << " and " << num2 << " is: " << result2 << endl;

}
