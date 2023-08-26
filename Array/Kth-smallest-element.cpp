// Q => Kth smallest element

// two approach
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
    // QuickSelect algorithm with randomized pivot
    /*
    Advantages: 
    This algorithm has an average-case time complexity of O(n) and is efficient for 
    finding the k'th smallest element when k is relatively small compared to n. It has a small constant factor.

    Disadvantages: 
    In the worst case, it can degrade to O(n^2), but this is rare with randomized pivot selection.
    */
    int quickSelect(vector<int>& nums, int k) {
        if (k < 1 || k > nums.size()) {
            throw out_of_range("k is out of range");
        }
        return quickSelectRecursive(nums, 0, nums.size() - 1, k - 1);
    }

    // Min-Heap approach

    /*
    Advantages:
     This algorithm guarantees O(n * log(k)) time complexity and works well when k is small compared to n.

    Disadvantages: 
    It requires extra space for the heap, and it might not be the most efficient choice if 
    k is close to n.
    */
    int minHeapKthSmallest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i < k; i++) {
            minHeap.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] < minHeap.top()) {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }

private:
    // Helper function for QuickSelect
    int quickSelectRecursive(vector<int>& nums, int low, int high, int k) {
        if (low < high) {
            int pivotIndex = partition(nums, low, high);

            if (pivotIndex == k) {
                return nums[pivotIndex];
            } else if (pivotIndex < k) {
                return quickSelectRecursive(nums, pivotIndex + 1, high, k);
            } else {
                return quickSelectRecursive(nums, low, pivotIndex - 1, k);
            }
        }
        return nums[low];
    }

    // Helper function to partition the array
    int partition(vector<int>& nums, int low, int high) {
        srand(time(0));
        int randomIndex = low + rand() % (high - low + 1);
        swap(nums[randomIndex], nums[high]);

        int pivot = nums[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (nums[j] <= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }

        swap(nums[i + 1], nums[high]);
        return i + 1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {12, 3, 1, 2, 5, 7, 4, 19};
    int k = 3; // Find the 3rd smallest element

    int quickSelectResult = solution.quickSelect(nums, k);
    int minHeapResult = solution.minHeapKthSmallest(nums, k);

    cout << "Using QuickSelect: The " << k << "th smallest element is: " << quickSelectResult << endl;
    cout << "Using Min-Heap: The " << k << "th smallest element is: " << minHeapResult << endl;

    return 0;
}



