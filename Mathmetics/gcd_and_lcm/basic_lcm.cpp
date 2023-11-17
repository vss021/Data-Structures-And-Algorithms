/*LCM is computed using the formula 
LCM(a, b) = (a * b) / GCD(a, b).
*/

#include <iostream>
using namespace std;
class Solution {
public:
    // Iterative function to calculate GCD using Euclidean algorithm
    // Time Complexity: O(log(min(a, b))), Space Complexity: O(1)
    int gcdIterative(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Recursive function to calculate GCD using Euclidean algorithm
    // Time Complexity: O(log(min(a, b))), Space Complexity: O(log(min(a, b)))
    int gcdRecursive(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcdRecursive(b, a % b);
    }

    // Function to calculate LCM using the formula: LCM(a, b) = (a * b) / GCD(a, b)
    // Time Complexity: O(log(min(a, b))), Space Complexity: O(1)
    int lcm(int a, int b) {
        return (a * b) / gcdIterative(a, b);
    }
};

int main() {
    Solution solution;

    // Get input from the user
    int num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // Calculate and display the GCD and LCM using the iterative approach
    int gcdResultIterative = solution.gcdIterative(num1, num2);
    int lcmResult = solution.lcm(num1, num2);

    cout << "GCD (Iterative) of " << num1 << " and " << num2 << " is: " << gcdResultIterative << endl;
    cout << "LCM of " << num1 << " and " << num2 << " is: " << lcmResult << endl;

    // Calculate and display the GCD using the recursive approach
    int gcdResultRecursive = solution.gcdRecursive(num1, num2);

    cout << "GCD (Recursive) of " << num1 << " and " << num2 << " is: " << gcdResultRecursive << endl;

    return 0;
}
