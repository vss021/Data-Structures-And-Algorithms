// C++ Program to check if
// number is divisible by 12
#include <iostream>
using namespace std;

bool isDvisibleBy12(string num)
{
	// if number greater than 3
	if (num.length() >= 3) { 

		// find last digit
		int d1 = (int)num[num.length() - 1];

		// no is odd
		if (d1 % 2 != 0)
			return (0);

		// find second last digit
		int d2 = (int)num[num.length() - 2];

		// find sum of all digits
		int sum = 0;
		for (int i = 0; i < num.length(); i++)
			sum += num[i];		 
		
		return (sum % 3 == 0 && (d2 * 10 + d1) % 4 == 0);		 
	}
	
	else {
		
		// if number is less than
		// or equal to 100
		int number = stoi(num);
		return (number % 12 == 0);
	}
}

// Driver function
int main()
{
	string num = "12244824607284961224"; 
	if (isDvisibleBy12(num))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
