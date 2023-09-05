/* leetcode
q =>  Product of Array Except Self

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf1(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        ans[0] = 1;

        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int right = 1;

        for (int i = n - 1; i >= 0; i--) {
            ans[i] = ans[i] * right;
            right *= nums[i];
        }

        return ans;
    }

     vector<int> productExceptSelf2(vector<int>& nums) {
        int n = nums.size();

        // Initialize left and right product arrays
        vector<int> leftProduct(n, 1);
        vector<int> rightProduct(n, 1);
        vector<int> result(n);

        // Calculate left products
        for (int i = 1; i < n; i++) {
            leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
        }

        // Calculate right products
        for (int i = n - 2; i >= 0; i--) {
            rightProduct[i] = rightProduct[i + 1] * nums[i + 1];
        }

        // Calculate the final result
        for (int i = 0; i < n; i++) {
            result[i] = leftProduct[i] * rightProduct[i];
        }

        return result;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Input vector
    vector<int> nums = {1, 2, 3, 4};

    // Calculate the product of elements except self
    vector<int> result = solution.productExceptSelf1(nums);
    vector<int> result = solution.productExceptSelf2(nums);

    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

