//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	/*
	A number is divisible by 11 if difference of following two is divisible by 11. 

    Sum of digits at odd places.
    Sum of digits at even places.
	*/
	int divisibleBy11 (string S)
	{
	    // Your Code Here
	    int odd = 0, even = 0;
        for (int i = 0; i < S.size(); i++)
        {
            if (i % 2) odd += (S[i] - '0');
            else even += (S[i] - '0');
        }
       return (odd - even) % 11 == 0;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.divisibleBy11 (s) << endl;
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends