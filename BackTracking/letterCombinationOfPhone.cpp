#include <iostream>
#include <vector>
#include <string>

/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.


 Example 1:
    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:

    Input: digits = ""
    Output: []

Example 3:

    Input: digits = "2"
    Output: ["a","b","c"]

*/
using namespace std;

class Solution {
public:

    void makeCombinationsOfDigits(int index, string digits, string currCombo, vector<string>& letters, vector<string>& result) {
        // Base case: If we have processed all digits, add the current combination to the result.
        if (index == digits.size()) {
            result.push_back(currCombo);
            return;
        }

        // Get the letters corresponding to the current digit.
        for (auto str : letters[digits[index] - '0']) {
            // Add the current letter to the current combination.
            currCombo.push_back(str);

            // Recursively generate combinations for the remaining digits.
            makeCombinationsOfDigits(index + 1, digits, currCombo, letters, result);

            // Backtracking: Remove the last added letter to try the next one.
            currCombo.pop_back();
        }
    }



    vector<string> letterCombinations(string digits) {
        // Implement your logic for generating letter combinations here.

        vector<string> letters = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> result;
        string currCombo = "";
        int index = 0;
        makeCombinationsOfDigits(index, digits, currCombo, letters, result);


        return result;

        
    }
};


int main() {
    Solution solution;
    string digits;

    cout << "Enter a string of digits: ";
    cin >> digits;

    vector<string> combinations = solution.letterCombinations(digits);

    cout << "Letter Combinations for " << digits << " are:" << endl;
    for (string& combination : combinations) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}
