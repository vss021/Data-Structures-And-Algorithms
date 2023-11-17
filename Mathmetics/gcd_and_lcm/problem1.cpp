/*
Given an array A[ ] of N numbers, your task is to find LCM of it modulo 1000000007

Example 1:

Input:
N = 4
A = {1 , 2 , 8 , 3}
Output:
24
Explanation:
LCM of the given array is 24.
24 % 1000000007 = 24
Example 2:

Input:
N = 2
A = {1 , 8}
Output:
8
Explanation:
LCM of the given array is 8.
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to calculate LCM of an array of numbers

    int gcdFind(long long a, long long b)
    {
       while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int lcmOfArray(int N , int A[]) {
        // code here
        
        long long ans = A[0];
        
        for(int i=1; i<N; i++)
        {
            long long b = A[i];
            ans = (((ans*b)/gcdFind(ans, b) ) %1000000007);
            
        }
        
        return ans;
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

    // Calculate and display the LCM of the array
    int result = solution.lcmOfArray(N, A);

    if (result != -1) {
        cout << "LCM of the array is: " << result << endl;
    }

    return 0;
}
