#include <iostream>
#include <string>

using namespace std;

bool divisibleBy6(string str) {
    int n = str.length();

    // Check if the last digit is even (divisibility by 2)
    if ((str[n - 1] - '0') % 2 != 0) {
        cout << "No" << endl;
        return false;
    }

    // Calculate the sum of digits
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += str[i] - '0';
    }

    // Check if the sum is divisible by 3
    if (sum % 3 == 0) {
        cout << "Yes" << endl;
        return true;
    }

    cout << "No" << endl;
    return false;
}

int main() {
    // Example usage
    string input;
    cout << "Enter a number as a string: ";
    cin >> input;

    // Check if the entered number is divisible by 6
    divisibleBy6(input);

    return 0;
}
