/*
A quick solution to check if a number is divisible by 29 or not is to add 3 times of last digit to 
rest number and repeat this process until number comes 2 digit. The given number is divisible 
by 29 if the obtained two digit number is divisible by 29.
Number is 348, 
Three times of last digit + Rest of the number = 8*3 + 34 = 58
Since 58 is divisible by 29, 348 is also divisible by 29. 
*/
// to check divisibility by 29.
#include <iostream>
using namespace std;

// Returns true if n is divisible by 29
// else returns false.
bool isDivisible(long long int n)
{
	// add the lastdigit*3 to renaming 
	// number until number comes only
	// 2 digit
	while (n / 100) 
	{
		int last_digit = n % 10;
		n /= 10;
		n += last_digit * 3;
	}

	// return true if number is
	// divisible by 29 another
	return (n % 29 == 0);
}

// Driver Code
int main()
{
	long long int n = 348;
	if (isDivisible(n))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
