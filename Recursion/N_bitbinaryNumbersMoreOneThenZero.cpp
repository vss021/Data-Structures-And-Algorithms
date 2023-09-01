/* Problem =>
Given a positive integer n, print all n-bit binary numbers having more 1’s than 0’s for any prefix of the number.
Input : n = 2
Output : 11 10

Input : n = 4
Output : 1111 1110 1101 1100 1011 1010
*/

#include <iostream>
#include <vector>
using namespace std;


void combinationOfOnes(int n, int cntOne, int cntZero, string outComes, 
vector<string>& result)
{

//  base case
    if( n == 0)
    {
        result.push_back(outComes);
        outComes = "";
        return;
    }

    // first we allways have 1 

    
    string str1 = outComes;
    str1 += '1';
    combinationOfOnes(n-1, cntOne+1, cntZero, str1, result);
    

    if(cntZero < cntOne)
    {
        string str2 = outComes;
        str2 += '0';
        combinationOfOnes(n-1, cntOne, cntZero+1, str2, result);
    }
}
int main()
{

    int num;
    cout << "Enter the Num : ";
    cin >> num;

    vector<string> result;
    string ot = "";
    combinationOfOnes(num, 0, 0, ot, result);

    for(auto it : result)
    {
        cout << it << " ";
    }
    


    return 0;
}



