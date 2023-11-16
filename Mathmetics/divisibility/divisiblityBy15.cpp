// CPP program to check if a large 
// number is divisible by 15 
#include <bits/stdc++.h> 

using namespace std; 

// function to check if a large number 
// is divisible by 15 
bool isDivisible(string s) 
{ 
	// length of string 
	int n = s.length(); 

	// check divisibility by 5 
	if (s[n - 1] != '5' and s[n - 1] != '0') 
		return false; 

	// Sum of digits 
	int sum = accumulate(begin(s), end(s), 0) - '0' * n; 

	// if divisible by 3 
	return (sum % 3 == 0); 
} 

// driver program 
int main() 
{ 
	string s = "15645746327462384723984023940239"; 
	isDivisible(s)? cout << "Yes\n": cout << "No\n"; 
	string s1 = "15645746327462384723984023940235"; 
	isDivisible(s1)? cout << "Yes\n": cout << "No\n"; 
	return 0; 
} 
