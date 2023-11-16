// C++ program to find if a number is divisible by 
// 9 or not 

// Note -> ):...
// if sum of all digits is divided by 9 then number also will divided by 9.
#include<bits/stdc++.h> 
using namespace std; 

// Function to find that number divisible by 9 or not 
int check(string str) 
{ 
	// Compute sum of digits 
	int n = str.length(); 
	int digitSum = 0; 
	for (int i=0; i<n; i++) 
		digitSum += (str[i]-'0'); 

	// Check if sum of digits is divisible by 9. 
	return (digitSum % 9 == 0); 
} 

// Driver code 
int main() 
{ 
	string str = "99333"; 
	check(str)? cout << "Yes" : cout << "No "; 
	return 0; 
} 
