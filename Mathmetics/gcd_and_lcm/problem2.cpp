/*
Given an array of numbers, find GCD of the array elements. In a previous post we find GCD of two number.

Examples:

Input  : arr[] = {1, 2, 3}
Output : 1

Input  : arr[] = {2, 4, 6, 8}
Output : 2
*/

#include <iostream>
#include <cmath>

class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long h(int N, int A[]) {
        long long product = A[0] % 1000000007;

        for (int i = 1; i < N; i++) {
            product = (product * (A[i] % 1000000007)) % 1000000007;
        }

        return product;
    }

    long long f(int N, int A[]) {
        long long ans = A[0] % 1000000007;

        for (int i = 1; i < N; i++) {
            ans = (gcd(ans, A[i]) % 1000000007);
        }

        return ans;
    }

    long long getVal(int N, int A[]) {
        long long hx = h(N, A) % 1000000007;
        long long fx = f(N, A) % 1000000007;

        // Using pow function from the <cmath> library to calculate hx^fx
        long long result = pow(hx, fx);

        return result % 1000000007;
    }
};

int main() {
    Solution solution;

    // Get input from the user
    int N;
    cout << "Enter the number of elements in the array: ";
    cin >> N;

    if (N <= 0) {
        cerr << "Error: Number of elements must be greater than 0." << endl;
        return 1; // Exit with an error code
    }

    int A[N];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Calculate and display the result
    long long result = solution.getVal(N, A);
    cout << "Result is: " << result << endl;

    return 0;
}
