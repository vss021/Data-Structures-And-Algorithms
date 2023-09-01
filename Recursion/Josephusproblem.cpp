#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to calculate the position of the last person standing in the Josephus problem.
    /*
    method 1.
    TC => o(n)
    sp => O(n+n) => one n is recursize n calls and another is n size of vector 
    */
    int solve(int n, int k, int index, vector<int> &v)
    {
        // Base case: If there is only one person left, return their position.
        if (v.size() == 1)
        {
            return v[0];
        }
        
        // Calculate the new 'index' where the next person will be eliminated.
        index = (index + k) % v.size();
        
        // Remove the person at the calculated 'index' from the vector.
        v.erase(v.begin() + index);
        
        // Recursively call 'solve' with the updated 'index' and vector.
        return solve(n, k, index, v);
    }
    int josephus(int n, int k)
    {
        // Create a vector 'v' to represent the circle of 'n' people.
        vector<int> v;
        
        // Populate the vector with values from 1 to 'n'.
        for (int i = 1; i <= n; i++)
        {
            v.push_back(i);
        }
        
        // Decrement 'k' by 1 to use 0-based indexing for elimination.
        k--;
        
        // Call the 'solve' function to find the position of the last person standing.
        return solve(n, k, 0, v);
    }


    int josephusOptimize(int n, int k)
    {
        if (n == 1)
        {
            return 1;
        }
        else
        {
            // Calculate the position of the last person standing in a circle of 'n' people.
            // The 'k' variable represents the elimination step.
            
            // Recursive call: Find the position in a circle with 'n-1' people after one person is eliminated.
            int position = josephusOptimize(n - 1, k);

            // Calculate the new position after eliminating every 'k'-th person.
            // The '-1' is because positions are 1-based but indices are 0-based.
            position = (position + k - 1) % n + 1;

            return position;
        }
    }
};

int main()
{
    Solution solution;

    int n, k;

    // Prompt the user for input.
    cout << "Enter the total number of people (n): ";
    cin >> n;

    cout << "Enter the elimination step (k): ";
    cin >> k;

    // Calculate the position of the last person standing.
    vector<int> v(n - 1);
    for (int i = 1; i <= n; i++) {
        v[i - 1] = i;
    }
    // int survivorPosition = solution.josephus(n, k-1, 0, v);
    int survivorPosition = solution.josephusOptimize(n, k);


    // Display the result.
    cout << "The last person standing is at position: " << survivorPosition << endl;

    return 0;
}
