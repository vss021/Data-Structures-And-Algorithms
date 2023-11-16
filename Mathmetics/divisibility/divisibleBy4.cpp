#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool divisibleBy4(string str) {
        // Your Code Here

        int n = str.size();

        // Check if the string is empty
        if (n == 0) {
            return false;
        }

        // Check if the string has only one digit, and that digit is divisible by 4
        if (n == 1 && (str[0] - '0') % 4 == 0) {
            return true;
        }

        // Extract the last two digits from the string
        int last = str[n - 1] - '0';
        int prev = str[n - 2] - '0';

        // Combine the last two digits to form a two-digit number
        int digit = prev * 10 + last;

        // Check if the two-digit number is divisible by 4
        if (digit % 4 == 0) {
            return true;
        }

        // If not divisible by 4, return false
        return false;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Get user input
    cout << "Enter a number as a string: ";
    string user_input;
    cin >> user_input;

    // Check if the user input is divisible by 4 and print the result
    cout << "Is " << user_input << " divisible by 4? " << (solution.divisibleBy4(user_input) ? "Yes" : "No") << endl;

    return 0;
}
