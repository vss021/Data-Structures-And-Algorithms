#include <iostream>
#include <string>

using namespace std;
bool divisibleBy13(string &str) {
    int n = str.length();

    // If the number has less than three digits, check directly
    if (n < 3) {
        return (stoi(str) % 13 == 0);
    }

    int sum = 0;

    // Process groups of three digits from right to left
    for (int i = n - 1; i >= 2; i -= 3) {
        int thirdDigit = str[i] - '0';
        int secondDigit = str[i - 1] - '0';
        int firstDigit = str[i - 2] - '0';

        // Add the second digit and subtract the sum of the first and third digits multiplied by 3
        sum += secondDigit;
        sum -= (firstDigit + thirdDigit * 3);
    }

    // Handle the remaining digits (less than three)
    for (int i = 0; i < n % 3; i++) {
        sum += str[i] - '0';
    }

    // Check if the sum is divisible by 13
    return (sum % 13 == 0);
}

int main() {
    // Example usage
    string input;
    
    // Get user input
    cout << "Enter a large number as a string: ";
    cin >> input;

    // Check if the entered number is divisible by 13
    if (divisibleBy13(input)) {
        cout << "Yes, the number is divisible by 13." << endl;
    } else {
        cout << "No, the number is not divisible by 13." << endl;
    }

    return 0;
}
