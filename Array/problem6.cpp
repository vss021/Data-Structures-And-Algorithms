/*
You are given an integer N. You need to convert all zeroes of N to 5.

Example 1:

Input:
N = 1004
Output: 1554
Explanation: There are two zeroes in 1004
on replacing all zeroes with "5", the new
number will be "1554".
Example 2:

Input:
N = 121
Output: 121
Explanation: Since there are no zeroes in
"121", the number remains as "121".
*/

#include <iostream>
#include <string>

class NumberConverter {
public:
    // Function to replace '0' with '5' using string conversion
    static int replaceZerosWithFivesString(int N) {
        std::string N_str = std::to_string(N);
        for (char &c : N_str) {
            if (c == '0') {
                c = '5';
            }
        }
        return std::stoi(N_str);
    }

    // Function to replace '0' with '5' using mathematics (O(1) space)
    static int replaceZerosWithFivesMath(int N) {
        int position = 1;
        int result = 0;
        while (N > 0) {
            int digit = N % 10;
            if (digit == 0) {
                result += 5 * position;
            } else {
                result += digit * position;
            }
            position *= 10;
            N /= 10;
        }
        return result;
    }
};

int main() {
    int N1 = 1004;
    int result1_string = NumberConverter::replaceZerosWithFivesString(N1);
    int result1_math = NumberConverter::replaceZerosWithFivesMath(N1);
    std::cout << "String Conversion Result: " << result1_string << std::endl;  // Output: 1554
    std::cout << "Mathematical Approach Result: " << result1_math << std::endl;  // Output: 1554

    int N2 = 121;
    int result2_string = NumberConverter::replaceZerosWithFivesString(N2);
    int result2_math = NumberConverter::replaceZerosWithFivesMath(N2);
    std::cout << "String Conversion Result: " << result2_string << std::endl;  // Output: 121
    std::cout << "Mathematical Approach Result: " << result2_math << std::endl;  // Output: 121

    return 0;
}
