// leetcode 
// 349. Intersection of Two Arrays
/*
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order.


Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        set<int> st;

        // Insert elements from nums1 into the set
        for (auto x : nums1) {
            st.insert(x);
        }

        // Find the intersection by iterating through nums2
        for (int num : nums2) {
            if (st.count(num)) {
                ans.push_back(num);
                st.erase(num); // Remove the element from the set to avoid duplicates
            }
        }

        return ans;

        /*
        tc => O(N)
        sp => O(N) -> because i use extra space for  set data structure 
        */
    }
    vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
    {
        int i = 0, j = 0;
        vector<int> ans;
        while(i<n && j<m) {
        
        if(arr1[i]==arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j]) {
            i++;
        }
        else
        {
            j++;
        }
        
        }
        return ans;
        /*

        tc => O(N)
        sp => O(1)
        */
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> result = solution.intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
